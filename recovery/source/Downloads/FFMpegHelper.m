#import "FFMpegHelper.h"
#import "DownloadsHost.h"
#import "../Presentation/ToastView.h"
#import <limits.h>
// recovery/classes/FFMpegHelper.c plus anonymous invokes, detailed in PROVENANCE.md.
@protocol YTPDownloadsToast <NSObject>
- (void)showToast:(NSString *)text;
- (void)hide;
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)withStop stopCompletion:(void (^)(void))completion;
- (void)updateText:(NSString *)text progress:(float)progress;
@end
static id<YTPDownloadsToast> YTPDownloadsNewToast(void) {
    return (id<YTPDownloadsToast>)[[ToastView alloc] init];
}
static int YTPFFMpegPercentage(double progress) {
    // First-package FCVTZS saturates positive infinity when duration is zero.
    // With positive int32 time and nonzero int64 duration, scaled is in range.
    double scaled = progress * 100.0;
    return scaled >= (double)INT_MAX ? INT_MAX : (int)scaled;
}
@implementation FFMpegHelper
// 0x1f4150, invoke 0x1f4204.
+ (instancetype)sharedInstance {
    static FFMpegHelper *instance;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [[self alloc] init]; });
    return instance;
}
// 0x1f4248
- (instancetype)init {
    if ((self = [super init])) {
        _ffmpegQueue = dispatch_queue_create("com.dvntm.ffmpeg.serialqueue", DISPATCH_QUEUE_SERIAL);
        _isProcessing = NO;
    }
    return self;
}
// First package 0x1f3e30 / invoke 0x1f3ed0. Statistics and UI update move to main.
- (void)statisticsCallback:(Statistics *)statistics {
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_statistics = statistics;
        [self updateProgressDialog];
    });
}
// First package 0x1f3f20; setup/callback evidence in FFMpegHelper.construction.provenance.md.
- (void)mergeVideo:(NSURL *)videoURL withAudio:(NSURL *)audioURL captions:(NSURL *)captionsURL
          duration:(long long)duration completion:(void (^)(NSURL *, NSError *))completion {
    id<YTPDownloadsToast> waitingToast = YTPDownloadsNewToast();
    if (_isProcessing) {
        dispatch_async(dispatch_get_main_queue(), ^{ [waitingToast showToast:YTPDownloadsLocalized(@"WaitsForConversion")]; });
    }
    dispatch_async(_ffmpegQueue, ^{
        self->_isProcessing = YES;
        self->_duration = duration;
        self->_statistics = nil;
        [MobileFFmpegConfig resetStatistics];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self setActive];
            [waitingToast hide];
            self->_toastView = (ToastView *)YTPDownloadsNewToast();
            [(id<YTPDownloadsToast>)self->_toastView showProgressWithText:YTPDownloadsLocalized(@"Converting")
                progress:0.0f withStop:YES stopCompletion:^{ [MobileFFmpeg cancel]; }];
        });
        NSURL *directory = [videoURL URLByDeletingLastPathComponent];
        NSURL *outputURL = [directory URLByAppendingPathComponent:@"output.mp4"];
        NSURL *webpURL = [directory URLByAppendingPathComponent:@"thumbnail.webp"];
        NSURL *jpegURL = [directory URLByAppendingPathComponent:@"thumbnail.jpg"];
        [[NSFileManager defaultManager] removeItemAtURL:jpegURL error:nil];
        [[NSFileManager defaultManager] removeItemAtURL:outputURL error:nil];
        if ([[NSFileManager defaultManager] fileExistsAtPath:webpURL.path]) {
            [MobileFFmpeg execute:[NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -q:v 1 %@", webpURL, jpegURL]];
        }
        NSString *command = [self getCommandWithVideoURL:videoURL audioURL:audioURL captionsURL:captionsURL
                                           thumbnailURL:jpegURL duration:duration outputURL:outputURL];
        [MobileFFmpegConfig setLogDelegate:self];
        // The binary dispatches execution away from its serial preparation queue.
        // Do not replace this with synchronous execution/semaphores: that changes concurrency.
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            int result = [MobileFFmpeg execute:command];
            dispatch_async(dispatch_get_main_queue(), ^{
                [(id<YTPDownloadsToast>)self->_toastView hide];
                self->_isProcessing = NO;
                if (result == RETURN_CODE_SUCCESS) {
                    completion(outputURL, nil);
                } else {
                    NSString *key;
                    if (result == RETURN_CODE_CANCEL) {
                        key = @"Cancelled";
                    } else {
                        [self getCleanLog:[MobileFFmpegConfig getLastCommandOutput]];
                        key = @"Error.Clipboard";
                    }
                    completion(nil, [NSError errorWithDomain:@"ErrDomain" code:0
                         userInfo:@{NSLocalizedDescriptionKey: YTPDownloadsLocalized(key)}]);
                }
            });
        });
    });
}
// First package 0x1f56b4. URL interpolation, argument order,
// stream maps, and unquoted command strings are retained exactly.
- (NSString *)getCommandWithVideoURL:(NSURL *)videoURL audioURL:(NSURL *)audioURL
                       captionsURL:(NSURL *)captionsURL thumbnailURL:(NSURL *)thumbnailURL
                          duration:(long long)duration outputURL:(NSURL *)outputURL {
    BOOL captions = [[NSFileManager defaultManager] fileExistsAtPath:captionsURL.path];
    BOOL thumbnail = [[NSFileManager defaultManager] fileExistsAtPath:thumbnailURL.path];
    if (captions && thumbnail) {
        return [NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -i %@ -i %@ -i %@ -to %ld -map 0 -map 1 -map 2 -map 3 -c:v copy -c:a copy -c:s mov_text -metadata:s:s:0 language=%@ -disposition:3 attached_pic %@",
            videoURL, audioURL, captionsURL, thumbnailURL, (long)duration, [self codeForCaps:captionsURL], outputURL];
    }
    if (captions) {
        return [NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -i %@ -i %@ -to %ld -c:v copy -c:a copy -c:s mov_text -metadata:s:s:0 language=%@ %@",
            videoURL, audioURL, captionsURL, (long)duration, [self codeForCaps:captionsURL], outputURL];
    }
    if (thumbnail) {
        return [NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -i %@ -i %@ -to %ld -map 0 -map 1 -map 2 -c:v copy -c:a copy -disposition:2 attached_pic %@",
            videoURL, audioURL, thumbnailURL, (long)duration, outputURL];
    }
    return [NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -i %@ -to %ld -c:v copy -c:a copy %@",
        videoURL, audioURL, (long)duration, outputURL];
}
// First package 0x1f7644; setup/callback evidence in FFMpegHelper.construction.provenance.md.
- (void)cutAudio:(NSURL *)audioURL duration:(long long)duration completion:(void (^)(NSURL *, NSError *))completion {
    id<YTPDownloadsToast> waitingToast = YTPDownloadsNewToast();
    if (_isProcessing) {
        dispatch_async(dispatch_get_main_queue(), ^{ [waitingToast showToast:YTPDownloadsLocalized(@"WaitsForConversion")]; });
    }
    dispatch_async(_ffmpegQueue, ^{
        self->_isProcessing = YES;
        self->_duration = duration;
        self->_statistics = nil;
        [MobileFFmpegConfig resetStatistics];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self setActive];
            [waitingToast hide];
            self->_toastView = (ToastView *)YTPDownloadsNewToast();
            [(id<YTPDownloadsToast>)self->_toastView showProgressWithText:YTPDownloadsLocalized(@"Converting")
                progress:0.0f withStop:YES stopCompletion:^{ [MobileFFmpeg cancel]; }];
        });
        NSURL *outputURL = [[audioURL URLByDeletingLastPathComponent] URLByAppendingPathComponent:@"output.m4a"];
        [[NSFileManager defaultManager] removeItemAtURL:outputURL error:nil];
        [MobileFFmpegConfig setLogDelegate:self];
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            int result = [MobileFFmpeg execute:[NSString stringWithFormat:@"-hide_banner -loglevel error -i %@ -to %ld -c copy %@",
                audioURL, (long)duration, outputURL]];
            dispatch_async(dispatch_get_main_queue(), ^{
                [(id<YTPDownloadsToast>)self->_toastView hide];
                self->_isProcessing = NO;
                if (result == RETURN_CODE_SUCCESS) {
                    completion(outputURL, nil);
                } else {
                    NSString *key;
                    if (result == RETURN_CODE_CANCEL) {
                        key = @"Cancelled";
                    } else {
                        [self getCleanLog:[MobileFFmpegConfig getLastCommandOutput]];
                        key = @"Error.Clipboard";
                    }
                    completion(nil, [NSError errorWithDomain:@"ErrDomain" code:0
                        userInfo:@{NSLocalizedDescriptionKey: YTPDownloadsLocalized(key)}]);
                }
            });
        });
    });
}
// First package 0x1f8a60..0x1f8a7c has no application operation beyond its omitted trap.
- (void)logCallback:(long long)executionId :(int)level :(NSString *)message {
    (void)executionId; (void)level; (void)message;
}
// First package 0x1f8a7c. See FFMpegHelper.log.provenance.md.
- (void)getCleanLog:(NSString *)log {
    NSArray *lines = [log componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]];
    NSMutableArray *filtered = [NSMutableArray array];
    NSString *previous = nil;
    for (NSString *line in lines) {
        if (![line isEqualToString:@""] && ![line isEqualToString:previous]) {
            [filtered addObject:line];
            previous = line;
        }
    }
    NSString *clean = [[filtered componentsJoinedByString:@"\n"]
        stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    while ([clean hasSuffix:@"."]) {
        clean = [[clean substringToIndex:clean.length - 1]
            stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    }
    [UIPasteboard generalPasteboard].string = clean;
}
// First package 0x1f9184.
- (void)setActive {
    [MobileFFmpegConfig setLogDelegate:self];
    [MobileFFmpegConfig setStatisticsDelegate:self];
}
// First package 0x1f91e4. See FFMpegHelper.progress.provenance.md.
- (void)updateProgressDialog {
    if (!_statistics) return;
    int time = [(id<YTPDownloadsStatistics>)_statistics getTime];
    if (time > 0) {
        double progress = ((double)time / 1000.0) / (double)_duration;
        [(id<YTPDownloadsToast>)_toastView updateText:
            [NSString stringWithFormat:@"%@: %d%%", YTPDownloadsLocalized(@"Converting"), YTPFFMpegPercentage(progress)]
            progress:(float)progress];
    }
}
// First package 0x1f9574. See FFMpegHelper.command.provenance.md.
- (NSString *)codeForCaps:(NSURL *)url {
    if (!url) return nil;
    NSString *code = [[url lastPathComponent] stringByDeletingPathExtension];
    id const keys[] = {
        @"af", @"am", @"ar", @"az", @"be", @"bg", @"bn", @"bs",
        @"ca", @"cs", @"da", @"de", @"el", @"en", @"en-GB", @"es",
        @"es-419", @"et", @"eu", @"fa", @"fi", @"fil", @"fr", @"fr-CA",
        @"gl", @"gu", @"he", @"hi", @"hr", @"hu", @"hy", @"id",
        @"is", @"it", @"ja", @"ka", @"kk", @"km", @"kn", @"ko",
        @"ky", @"lo", @"lt", @"lv", @"mk", @"ml", @"mn", @"mr",
        @"ms", @"my", @"ne", @"nl", @"no", @"pa", @"pl", @"pt",
        @"ro", @"ru", @"si", @"sk", @"sl", @"sq", @"sr", @"sr-Latn",
        @"sv", @"sw", @"ta", @"te", @"th", @"tr", @"uk", @"uz",
        @"vi", @"xh", @"yi", @"zu", @"zh-Hans", @"zh-Hant", @"zh-Hant-HK", @"zh-Hant-TW"
    };
    id const values[] = {
        @"afr", @"amh", @"ara", @"aze", @"bel", @"bul", @"ben", @"bos",
        @"cat", @"ces", @"dan", @"deu", @"ell", @"eng", @"eng", @"spa",
        @"spa", @"est", @"eus", @"fas", @"fin", @"fil", @"fra", @"fra",
        @"glg", @"guj", @"heb", @"hin", @"hrv", @"hun", @"hye", @"ind",
        @"isl", @"ita", @"jpn", @"kat", @"kaz", @"khm", @"kan", @"kor",
        @"kir", @"lao", @"lit", @"lav", @"mkd", @"mal", @"mon", @"mar",
        @"msa", @"mya", @"nep", @"nld", @"nor", @"pan", @"pol", @"por",
        @"ron", @"rus", @"sin", @"slk", @"slv", @"sqi", @"srp", @"srp",
        @"swe", @"swa", @"tam", @"tel", @"tha", @"tur", @"ukr", @"uzb",
        @"vie", @"xho", @"yid", @"zul", @"zho", @"zho", @"zho", @"zho"
    };
    // Preserve the first package's per-call factory, including nil results.
    NSDictionary *codes = [NSDictionary dictionaryWithObjects:values forKeys:keys
        count:sizeof(keys) / sizeof(keys[0])];
    return codes[code] ?: code;
}
// ARC supplies .cxx_destruct 0x1fcd44, retaining the actual queue/statistics/toast objects.
@end
