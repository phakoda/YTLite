#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Downloads/YTPDownloader.h"
#import <objc/runtime.h>
#include <limits.h>

static NSUInteger downloaderNewCalls;
@interface YTPDownloader (HelperStartProbe)
+ (instancetype)newForHelperStartProbe;
@end
@implementation YTPDownloader (HelperStartProbe)
+ (instancetype)newForHelperStartProbe { downloaderNewCalls++;return [[self alloc] init]; }
@end

@interface HelperStartToast : NSObject
@property(copy) NSString *route;
@property(copy) NSString *text;
@property(copy) dispatch_block_t stop;
@end
@implementation HelperStartToast
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)stop stopCompletion:(dispatch_block_t)completion {
    PCheck(progress==0 && !signbit(progress) && stop && completion!=nil,@"download start shows zero progress and a stop callback");
    self.route=@"show";self.text=text;self.stop=completion;
}
- (void)updateText:(NSString *)text progress:(float)progress animated:(BOOL)animated {
    PCheck(progress==0 && !signbit(progress) && !animated,@"audio phase resets zero progress without animation");
    self.route=@"update";self.text=text;
}
@end

static YTLHelper *startingHelper;
static HelperStartToast *replacementToast;
static BOOL mutateLocalization;
static IMP originalLocalization;
static IMP originalTransport;
static BOOL delegateReadyAtTransportStart;
static void StartTransport(YTPDownloader *receiver,SEL selector,NSURL *url,NSString *name,NSString *identifier,unsigned long long size) {
    delegateReadyAtTransportStart=receiver.delegate==startingHelper;
    ((void(*)(id,SEL,id,id,id,unsigned long long))originalTransport)(receiver,selector,url,name,identifier,size);
}
static id StartLocalized(id receiver,SEL selector,NSString *key,NSString *value,NSString *table) {
    if(mutateLocalization && [key isEqual:@"DownloadingAudio"]) {
        PSet(startingHelper,@"_isAudioOnly",@(![PGet(startingHelper,@"_isAudioOnly") boolValue]));
        PSet(startingHelper,@"_toastView",replacementToast);
    }
    return ((id(*)(id,SEL,id,id,id))originalLocalization)(receiver,selector,key,value,table);
}
static NSURL *StartURL(NSString *name) {
    return [NSURL URLWithString:[@"https://fixture.invalid/" stringByAppendingString:name]];
}
static unsigned long long StartDurationOracle(unsigned long long value) {
    double converted,seconds,divisor=1000.0;unsigned long long result;
    __asm__("ucvtf %d0, %3\n\tfdiv %d1, %d0, %d4\n\tfcvtpu %2, %d1"
        : "=&w"(converted),"=&w"(seconds),"=r"(result) : "r"(value),"w"(divisor));
    return result;
}
static void SeedStartHelper(YTLHelper *helper,HelperStartToast *toast) {
    PSet(helper,@"_toastView",toast);PSet(helper,@"_audioUrl",StartURL(@"seed-audio"));
    PSet(helper,@"_videoID",@"seed-id");PSet(helper,@"_title",@"seed-title");
    PSet(helper,@"_audioSize",@73);PSet(helper,@"_duration",@17);
    PSet(helper,@"_isAudioOnly",@NO);PSet(helper,@"_isVideoDownloaded",@NO);
    downloaderNewCalls=0;delegateReadyAtTransportStart=NO;[PresentationDownloads removeAllObjects];
}
static void CheckStopUsesLiveDownloader(HelperStartToast *toast) {
    PCheck(toast.stop!=nil,@"start callback available after method return");
    id first=PGet(startingHelper,@"_downloader");
    id next=[[YTPDownloader alloc] init];PSet(startingHelper,@"_downloader",next);
    NSUInteger before=PresentationEventsOfKind(@"download.cancel").count;
    toast.stop();
    NSArray *events=PresentationEventsOfKind(@"download.cancel");
    PCheck(events.count==before+1 && events.lastObject[@"value"]==next && first!=next,
        @"stop callback reads current downloader rather than captured original");
    PSet(startingHelper,@"_downloader",nil);toast.stop();
    PCheck(PresentationEventsOfKind(@"download.cancel").count==before+1,@"nil current downloader receives no cancellation");
    toast.stop=nil;
}

void PRunHelperStart(void) {
    NSUInteger before=PresentationAssertions;
    Method inheritedNew=class_getClassMethod(YTPDownloader.class,@selector(new));
    IMP oldNew=method_getImplementation(inheritedNew);
    class_addMethod(object_getClass(YTPDownloader.class),@selector(new),oldNew,method_getTypeEncoding(inheritedNew));
    Method newMethod=class_getClassMethod(YTPDownloader.class,@selector(new));
    method_setImplementation(newMethod,method_getImplementation(class_getClassMethod(YTPDownloader.class,@selector(newForHelperStartProbe))));
    Method localize=class_getInstanceMethod(NSBundle.class,@selector(localizedStringForKey:value:table:));
    originalLocalization=method_setImplementation(localize,(IMP)StartLocalized);
    Method transport=class_getInstanceMethod(YTPDownloader.class,@selector(downloadFileWithURL:fileName:videoID:fileSize:));
    originalTransport=method_setImplementation(transport,(IMP)StartTransport);
    @try {
        startingHelper=[YTLHelper new];replacementToast=[HelperStartToast new];
        for(NSUInteger standalone=0;standalone<2;standalone++) {
            HelperStartToast *toast=[HelperStartToast new];SeedStartHelper(startingHelper,toast);
            replacementToast.route=nil;mutateLocalization=YES;
            [startingHelper downloadAudioWithUrl:standalone ? StartURL(@"audio") : nil
                fileName:standalone ? @"title" : nil videoID:standalone ? @"audio-id" : nil
                audioSize:standalone ? 81 : 0 duration:standalone ? 1001 : 0];
            mutateLocalization=NO;
            PEqual(toast.route,standalone ? @"show" : @"update",@"audio branch uses phase read before localization");
            PCheck(replacementToast.route==nil,@"audio sends message to toast read before localization");
            PCheck(downloaderNewCalls==0 && delegateReadyAtTransportStart,@"audio creates alloc/init downloader and sets delegate before transport");
            if(standalone)CheckStopUsesLiveDownloader(toast);
        }
        for(NSUInteger mask=0;mask<32;mask++) {
            HelperStartToast *toast=[HelperStartToast new];SeedStartHelper(startingHelper,toast);
            NSURL *url=(mask&1) ? StartURL(@"incoming-audio") : nil;
            NSString *name=(mask&2) ? @"A/udio?" : nil,*identifier=(mask&4) ? @"incoming-id" : nil;
            [startingHelper downloadAudioWithUrl:url fileName:name videoID:identifier
                audioSize:(mask&8) ? 513 : 0 duration:(mask&16) ? 1001 : 0];
            BOOL fresh=mask==31;
            NSDictionary *download=PresentationDownloads.lastObject;
            PCheck(PresentationDownloads.count==1 && downloaderNewCalls==0,@"every audio argument combination starts one alloc/init downloader");
            PEqual(download[@"url"],fresh ? url : StartURL(@"seed-audio"),@"audio uses incoming state only when all five arguments are present");
            PEqual(download[@"videoID"],fresh ? identifier : @"seed-id",@"audio ID state selection");
            PEqual(download[@"name"],fresh ? @"incoming-id_a.m4a" : @"seed-id_a.m4a",@"audio filename format");
            PEqual(download[@"size"],fresh ? @513 : @73,@"audio byte count selection");
            PEqual(PGet(startingHelper,@"_title"),fresh ? @"Audio" : @"seed-title",@"audio title sanitization and sentinel preservation");
            PEqual(PGet(startingHelper,@"_duration"),fresh ? @2 : @17,@"audio duration conversion and sentinel preservation");
            PCheck([PGet(startingHelper,@"_isVideoDownloaded") boolValue] && [PGet(startingHelper,@"_isAudioOnly") boolValue]==fresh,@"audio start sets phase flags");
            PCheck(delegateReadyAtTransportStart && [(YTPDownloader *)download[@"downloader"] delegate]==startingHelper,@"downloader delegate set before transport starts");
            PEqual(toast.route,fresh ? @"show" : @"update",@"audio start selects original toast method");
            toast.stop=nil;
        }
        unsigned long long durations[]={0,1,999,1000,1001,9007199254740991ULL,9007199254740992ULL,
            9007199254740993ULL,ULLONG_MAX-2048,ULLONG_MAX-1,ULLONG_MAX};
        for(NSUInteger i=0;i<sizeof(durations)/sizeof(*durations);i++) {
            HelperStartToast *toast=[HelperStartToast new];SeedStartHelper(startingHelper,toast);
            NSURL *video=StartURL(@"video"),*audio=StartURL(@"audio"),*captions=StartURL(@"captions");
            [startingHelper downloadVideoWithUrl:video audioUrl:audio fileName:@"V/ideo?" format:@"mp4"
                videoID:@"video-id" videoSize:ULLONG_MAX audioSize:8193 duration:durations[i] captions:captions];
            NSDictionary *download=PresentationDownloads.lastObject;
            PCheck(PresentationDownloads.count==1 && downloaderNewCalls==0 && delegateReadyAtTransportStart,@"video starts one alloc/init downloader with delegate already set");
            PCheck(download[@"url"]==video && [download[@"size"] unsignedLongLongValue]==ULLONG_MAX,@"video forwards original URL and unsigned byte count");
            PEqual(download[@"name"],@"video-id_v.mp4",@"video filename format");
            PEqual(PGet(startingHelper,@"_title"),@"Video",@"video title sanitization");
            PCheck(PGet(startingHelper,@"_audioUrl")==audio && PGet(startingHelper,@"_captionsUrl")==captions,@"video preserves audio and caption identity");
            PEqual(PGet(startingHelper,@"_format"),@"mp4",@"video format state");
            PEqual(PGet(startingHelper,@"_audioSize"),@8193,@"video preserves audio byte count");
            PCheck([PGet(startingHelper,@"_duration") unsignedLongLongValue]==StartDurationOracle(durations[i]),@"video duration matches original unsigned floating-point conversion");
            PCheck(![PGet(startingHelper,@"_isAudioOnly") boolValue] && ![PGet(startingHelper,@"_isVideoDownloaded") boolValue],@"video clears both phase flags");
            PEqual(toast.text,@"DownloadingVideo",@"video progress label");
            if(i==0)CheckStopUsesLiveDownloader(toast);
            toast.stop=nil;
        }
    } @finally {
        mutateLocalization=NO;method_setImplementation(localize,originalLocalization);method_setImplementation(newMethod,oldNew);
        method_setImplementation(transport,originalTransport);
        startingHelper=nil;replacementToast=nil;[PresentationDownloads removeAllObjects];
    }
    printf("PASS Helper_first_package_start: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
