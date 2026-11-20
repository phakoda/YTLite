#import "DownloadMenuHelper.h"
#import "DownloadsMenuHost.h"
#import "YTPMedia.h"
#import "../Subtitles/SRTParser.h"
#import <AVKit/AVKit.h>
#import <math.h>
#import <objc/runtime.h>
// Provenance: original class addresses and block invokes are recorded below.
// All helper functions are C-local so the class's 26-method runtime surface is exact.
typedef id<YTPDownloadsNode> YTPNode;
static YTPNode YTPMenuResponse(YTPNode player) {
    if ([player respondsToSelector:@selector(playerResponse)]) return [player playerResponse];
    if ([player respondsToSelector:@selector(contentPlayerResponse)]) return [player contentPlayerResponse];
    return nil;
}
static Class<YTPDownloadsSheet> YTPMenuSheets(void) { return (Class)NSClassFromString(@"YTDefaultSheetController"); }
static Class<YTPDownloadsSheet> YTPMenuCachedSheets(void) {
    // First package shared sheet cache at 0x1227020; retry unresolved classes.
    static Class sheetClass;
    if (!sheetClass) sheetClass = objc_getClass("YTDefaultSheetController");
    return sheetClass;
}
static Class<YTPDownloadsAction> YTPMenuActions(void) {
    // First package shared cache at 0x1227030; failed lookups are retried.
    static Class actionClass;
    if (!actionClass) actionClass = objc_getClass("YTActionSheetAction");
    return actionClass;
}
static id<YTPDownloadsMenuToast> YTPMenuToast(void) { return (id)[[NSClassFromString(@"ToastView") alloc] init]; }
static UIViewController *YTPMenuToastRoot(void) { return [[(Class<YTPDownloadsMenuToast>)NSClassFromString(@"ToastView") toastWindow] rootViewController]; }
static UIViewController *YTPMenuAppRoot(void) { return [[(id<YTPDownloadsApplicationDelegate>)[UIApplication sharedApplication].delegate window] rootViewController]; }
static void YTPMenuPresent(id<YTPDownloadsSheet> sheet, id sender) {
    [sheet setSourceView:sender];
    [sheet presentFromViewController:YTPMenuToastRoot() animated:YES completion:nil];
}
static void YTPMenuError(NSString *text) { [YTPMenuToast() showMessageWithText:text isSuccess:NO]; }
static void YTPMenuLocalizedError(NSString *key) { [YTPMenuToast() showMessageWithText:YTPDownloadsLocalized(key) isSuccess:NO]; }
static void YTPMenuLegacyToast(NSString *key) {
    // First package shared legacy-toast cache at 0x1227038; no init is sent.
    static Class toastClass;
    if (!toastClass) toastClass = objc_getClass("YTToastController");
    [(id<YTPDownloadsLegacyToast>)[toastClass alloc] showMessage:YTPDownloadsLocalized(key)];
}
static void YTPMenuCopy(NSString *value) {
    [UIPasteboard generalPasteboard].string = value;
    YTPMenuLegacyToast(@"Copied");
}
static NSString *YTPMenuShorten(NSString *value, NSUInteger length) {
    return value.length > length ? [[value substringToIndex:length] stringByAppendingString:@"…"] : value;
}
static NSString *YTPMenuName(NSString *author, NSString *title) { return [NSString stringWithFormat:@"%@ - %@", author, title]; }
static NSURL *YTPMenuURL(YTPNode format) { return [NSURL URLWithString:[format URL]]; }
static NSComparisonResult YTPMenuSizeOrder(YTPNode a, YTPNode b) {
    // First-package callbacks 0x1032cc / 0x103990: signed compare; ties return +1.
    return (long long)[a contentLength] > (long long)[b contentLength] ? NSOrderedAscending : NSOrderedDescending;
}
static UIImage *YTPMenuCachedChevron(void) {
    // First package shared UI-resource class cache at 0x1227028.
    static Class resourcesClass;
    if (!resourcesClass) resourcesClass = objc_getClass("YTUIResources");
    UIImage *image = [(Class<YTPDownloadsResources>)resourcesClass chevronRightImage];
    [image setFlipsForRightToLeftLayoutDirection:YES];
    return image;
}
static id<YTPDownloadsAction> YTPMenuSubmenu(NSString *key, NSString *icon, UIImage *chevron, void (^handler)(void)) {
    return [YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(key) iconImage:[YTPMedia imageWithName:icon]
                        secondaryIconImage:chevron accessibilityIdentifier:nil handler:handler];
}
static void YTPMenuAudio(id<YTPDownloadsAppRoot> root, YTPNode format, NSString *author, NSString *title, NSString *videoID) {
    [[root helper] downloadAudioWithUrl:YTPMenuURL(format) fileName:YTPMenuName(author, title) videoID:videoID
                             audioSize:[format contentLength] duration:[format approxDurationMs]];
}
static BOOL YTPMenuOriginalCaption(YTPNode track) {
    return ![[track VSSID] hasPrefix:@"t."] && ![[track VSSID] hasPrefix:@"a."] && ![[track VSSID] hasPrefix:@"ta."];
}
@implementation DownloadMenuHelper
// First package 0x102a00. See DownloadMenuHelper.formats.provenance.md.
- (NSArray *)getVideoFormatsArray:(id)player isShorts:(BOOL)shorts {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return nil;
    NSArray *formats = [[[response playerData] streamingData] adaptiveFormatsArray];
    NSMutableArray *result = [NSMutableArray array], *mp4 = [NSMutableArray array], *fallback = [NSMutableArray array];
    for (YTPNode format in formats) {
        long long resolution = [self getResoForQuality:[format qualityLabel]];
        BOOL isMP4 = [[format mimeType] hasPrefix:@"video/mp4"];
        BOOL isWebM = [[format mimeType] hasPrefix:@"video/webm"];
        if (isMP4 && resolution >= 144 && resolution <= 1080) { [result addObject:format]; [mp4 addObject:format]; }
        else if (isWebM && resolution > 1080 && !shorts) [result addObject:format];
        else if (isWebM && resolution >= 144 && resolution <= 1080) [fallback addObject:format];
    }
    if (!mp4.count && !shorts) [result addObjectsFromArray:fallback];
    [result sortUsingComparator:^NSComparisonResult(id a, id b) { return YTPMenuSizeOrder(a, b); }];
    return [result copy];
}
// First package 0x103338 / comparator 0x103990.
- (NSArray *)getAudioFormatsArray:(id)player {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return nil;
    NSArray *formats = [[[response playerData] streamingData] adaptiveFormatsArray];
    NSMutableArray *result = [NSMutableArray array];
    for (YTPNode format in formats) {
        if ([[format mimeType] hasPrefix:@"audio/mp4"]) [result addObject:format];
    }
    [result sortUsingComparator:^NSComparisonResult(id a, id b) { return YTPMenuSizeOrder(a, b); }];
    return [result copy];
}
// First package 0x1039fc. preferDrc return value is discarded at 0x1041b0.
- (id)getBestAudioFormat:(NSArray *)formats playerVC:(id)player {
    for (YTPNode format in formats) {
        if ([[format mimeType] hasPrefix:@"audio/mp4"] && ([format itag] == 140 || [format itag] == 139)) {
            // Both itags use equivalent track/default checks: 0x103fc4 and 0x1040b4.
            if ([format audioTrack] && [[format audioTrack] audioIsDefault]) return format;
            if ([format isDrc]) (void)ytpBool(@"preferDrc");
            return format;
        }
    }
    return [[[(YTPNode)player activeVideo] selectedAudioFormat] formatStream];
}
// First package 0x104218. itag is called but not used as a filter.
- (id)getDefaultAudioTrack:(NSArray *)formats {
    for (YTPNode format in formats) {
        if ([[format audioTrack] audioIsDefault]) { (void)[format itag]; return format; }
    }
    return nil;
}
// First package 0x10451c: en.4 prefix and an ignored itag call.
- (id)getEnglishAudioTrack:(NSArray *)formats {
    for (YTPNode format in formats) {
        if ([[[format audioTrack] id_p] hasPrefix:@"en.4"]) { (void)[format itag]; return format; }
    }
    return nil;
}
// First package 0x104924. See DownloadMenuHelper.parsers.provenance.md.
- (NSString *)detailForMimeType:(NSString *)mimeType {
    NSRange separator = [mimeType rangeOfString:@"/"];
    NSString *container = nil;
    if (separator.location != NSNotFound)
        container = [[[mimeType substringFromIndex:NSMaxRange(separator)] componentsSeparatedByString:@";"] firstObject];
    NSRange codecs = [mimeType rangeOfString:@"codecs=\""];
    if (codecs.location == NSNotFound) return nil;
    NSString *codec = [[[[[mimeType substringFromIndex:NSMaxRange(codecs)] componentsSeparatedByString:@"\""] firstObject]
                         componentsSeparatedByString:@"."] firstObject];
    return container && codec ? [NSString stringWithFormat:@"%@ • %@", container, codec] : nil;
}
// First package 0x104e10: literal p split, index zero, then signed integerValue.
- (long long)getResoForQuality:(NSString *)quality {
    return [[quality componentsSeparatedByString:@"p"][0] integerValue];
}
// First package 0x104f2c; invokes 0x1058dc and 0x106030. Strong byref selections.
- (void)downloadVideoWithFormat:(id)video withAudioFormats:(NSArray *)formats fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID playerVC:(id)player sender:(id)sender {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    __block YTPNode selected = nil;
    __block NSString *errorText = nil;
    void (^proceed)(void) = ^{
        if (errorText) { YTPMenuError(errorText); return; }
        if (ytpBool(@"downloadWithCaps") && [self hasCaptions:player]) {
            NSString *title = [[[response playerData] videoDetails] title];
            NSString *author = [[[response playerData] videoDetails] author];
            [self downloadVideoWithFormat:video audioFormat:selected fileName:YTPMenuName(author, title)
                                extension:[extension lowercaseString] videoID:videoID playerVC:player sender:sender];
        } else {
            [self downloadVideoWithUrl:YTPMenuURL(video) audioUrl:YTPMenuURL(selected) fileName:name extension:extension
                              videoID:videoID videoSize:[(YTPNode)video contentLength] audioSize:[selected contentLength]
                             duration:[(YTPNode)video approxDurationMs] captions:nil playerVC:player];
        }
    };
    long long index = ytpInt(@"ytlAudioIndex");
    if (index == 0) { selected = [self getDefaultAudioTrack:formats]; proceed(); }
    else if (index == 1) { selected = [self getBestAudioFormat:formats playerVC:player]; proceed(); }
    else if (index == 2) {
        selected = [self getEnglishAudioTrack:formats];
        if (!selected) errorText = YTPDownloadsLocalized(@"EnglishNotFound");
        proceed();
    } else if (index == 3) {
        [self showAudioTrackSelector:formats sender:sender playerVC:player completion:^(id format) {
            if (format) selected = format;
            proceed();
        }];
    }
}
// First package 0x10618c / invoke 0x10631c: nil captions do not start downloading.
- (void)downloadVideoWithFormat:(id)video audioFormat:(id)audio fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID playerVC:(id)player sender:(id)sender {
    [self getCaptionsUrlSheet:player sender:sender completion:^(NSURL *url) {
        if (url) [self downloadVideoWithUrl:YTPMenuURL(video) audioUrl:YTPMenuURL(audio) fileName:name extension:extension videoID:videoID
            videoSize:[(YTPNode)video contentLength] audioSize:[(YTPNode)audio contentLength]
            duration:[(YTPNode)video approxDurationMs] captions:url playerVC:player];
    }];
}
// 0x106c80. Install a fresh helper on the actual application root, not on the toast root.
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions playerVC:(id)player {
    id<YTPDownloadsAppRoot> root = (id)YTPMenuAppRoot();
    [root setHelper:(id)[[NSClassFromString(@"YTLHelper") alloc] init]];
    [[root helper] downloadVideoWithUrl:videoURL audioUrl:audioURL fileName:name format:extension videoID:videoID
                             videoSize:videoSize audioSize:audioSize duration:duration captions:captions];
    if (player && ytpBool(@"embedThumbnails")) [self getThumbnail:player];
}
// First package 0x1069c0 / background invoke 0x106b94.
- (void)getThumbnail:(id)player {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSString *videoID = [response videoID];
        YTPNode thumbnail = [[[[response playerData] videoDetails] thumbnail] thumbnailsArray].lastObject;
        NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:[thumbnail URL]]];
        if (!data) return;
        NSString *temporary = NSTemporaryDirectory();
        BOOL directory = NO;
        if (![[NSFileManager defaultManager] fileExistsAtPath:temporary isDirectory:&directory] || !directory) {
            NSError *error = nil;
            [[NSFileManager defaultManager] createDirectoryAtPath:temporary withIntermediateDirectories:YES attributes:nil error:&error];
            if (error) NSLog(@"Error creating temporary directory: %@", error.localizedDescription);
        }
        NSURL *destination = [NSURL fileURLWithPath:[temporary stringByAppendingPathComponent:
            [NSString stringWithFormat:@"%@/thumbnail.webp", videoID]]];
        [data writeToURL:destination atomically:YES];
    });
}
// First package 0x107364. Keep the controller alive through the synchronous callback.
- (void)checkSpaceAvailabilityForMedia:(long long)size completion:(void (^)(BOOL, NSString *))completion {
    static Class storageClass;
    if (!storageClass) storageClass = objc_getClass("YTAutoOfflineController");
    __attribute__((objc_precise_lifetime)) id<YTPDownloadsStorage> controller = [[storageClass alloc] init];
    long long free = [controller freeDeviceStorageBytes];
    long long twice = (long long)((unsigned long long)size * 2);
    NSString *freeText = [NSByteCountFormatter stringFromByteCount:free countStyle:NSByteCountFormatterCountStyleFile];
    NSString *neededText = [NSByteCountFormatter stringFromByteCount:(long long)((unsigned long long)twice - (unsigned long long)free) countStyle:NSByteCountFormatterCountStyleFile];
    completion(twice < free, twice < free ? nil : [NSString stringWithFormat:YTPDownloadsLocalized(@"Error.NoSpace"), neededText, freeText]);
}
// First package 0x107844; comparator 0x108b60 and selection callback 0x108c48.
- (void)showAudioTrackSelector:(NSArray *)formats sender:(id)sender playerVC:(id)player completion:(void (^)(id))completion {
    (void)player;
    NSMutableArray *filtered = [NSMutableArray array];
    for (YTPNode format in formats) if ([format itag] == 140 && ![format isDrc]) [filtered addObject:format];
    if (!filtered.count) for (YTPNode format in formats) if ([format itag] == 140 && [format isDrc]) [filtered addObject:format];
    [filtered sortUsingComparator:^NSComparisonResult(YTPNode a, YTPNode b) { return [[[a audioTrack] displayName] compare:[[b audioTrack] displayName]]; }];
    NSMutableArray *actions = [NSMutableArray array];
    for (YTPNode format in filtered) {
        Class<YTPDownloadsAction> actionClass = YTPMenuActions();
        [actions addObject:[actionClass actionWithTitle:[[format audioTrack] displayName]
            iconImage:[YTPMedia imageWithName:@"localization"] style:0 handler:^{ completion(format); }]];
    }
    id<YTPDownloadsSheet> sheet = [YTPMenuSheets() sheetControllerWithMessage:YTPDownloadsLocalized(@"SelectAudioTrack") subMessage:nil delegate:nil parentResponder:nil];
    for (id action in actions) [sheet addAction:action];
    YTPMenuPresent(sheet, sender);
}
// 0x109374: nil VSSID is treated like a manual caption (nil responds NO to all prefixes).
- (BOOL)hasCaptions:(id)player {
    NSArray *tracks = [[(YTPNode)player activeVideo] availableCaptionTracks];
    if (ytpBool(@"addAutoCaps")) return tracks.count != 0;
    for (YTPNode track in tracks) if (YTPMenuOriginalCaption(track)) return YES;
    return NO;
}
// 0x10b9a4. Auto-enabled returns the input object itself, including nil.
- (NSArray *)captionsForDownloading:(NSArray *)tracks {
    NSMutableArray *filtered = [NSMutableArray array];
    for (YTPNode track in tracks) if (YTPMenuOriginalCaption(track)) [filtered addObject:track];
    if (ytpBool(@"addAutoCaps")) return tracks;
    return filtered.count ? filtered : nil;
}
// 0x10c14c.
- (NSString *)titleForCaption:(id)caption {
    YTPNode track = caption;
    if ([[track VSSID] hasPrefix:@"t."]) return [NSString stringWithFormat:@"%@ (%@)", [track displayName], YTPDownloadsLocalized(@"Translated")];
    if ([[track VSSID] hasPrefix:@"ta."]) return [NSString stringWithFormat:@"%@ (%@)", [track displayName], YTPDownloadsLocalized(@"TranslatedAutoGen")];
    return [track displayName];
}
// First package 0x1093ec / invokes 0x109d8c, 0x10a078. Transcripts use all tracks.
- (void)showTranscriptSheet:(id)player withSender:(id)sender {
    NSArray *tracks = [[(YTPNode)player activeVideo] availableCaptionTracks];
    id<YTPDownloadsSheet> sheet = [YTPMenuSheets() sheetControllerWithMessage:YTPDownloadsLocalized(@"SelectCaption") subMessage:nil delegate:nil parentResponder:nil];
    for (YTPNode track in tracks) {
        Class<YTPDownloadsAction> actionClass = (Class)NSClassFromString(@"YTActionSheetAction");
        [sheet addAction:[actionClass actionWithTitle:[self titleForCaption:track] iconImage:[YTPMedia imageWithName:@"captions"] style:0 handler:^{
            id<YTPDownloadsMenuToast> toast = YTPMenuToast();
            [toast showToast:YTPDownloadsLocalized(@"ParsingTranscript")];
            [[[SRTParser alloc] init] parseTranscriptFromURL:(NSURL *)[track URL] completion:^(NSString *text, NSError *error) {
                if (error) [toast showMessageWithText:error.localizedDescription isSuccess:NO];
                else {
                    [UIPasteboard generalPasteboard].string = text;
                    [toast showMessageWithText:YTPDownloadsLocalized(@"Copied") isSuccess:YES];
                }
            }];
        }]];
    }
    YTPMenuPresent(sheet, sender);
}
// First package 0x10a2d4 / invokes 0x10ae84, 0x10b19c.
- (void)showCaptionsSheet:(id)player withSender:(id)sender {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    NSString *videoID = [response videoID];
    NSArray *tracks = [self captionsForDownloading:[[(YTPNode)player activeVideo] availableCaptionTracks]];
    id<YTPDownloadsSheet> sheet = [YTPMenuSheets() sheetControllerWithMessage:YTPDownloadsLocalized(@"SelectCaption") subMessage:nil delegate:nil parentResponder:nil];
    for (YTPNode track in tracks) {
        Class<YTPDownloadsAction> actionClass = (Class)NSClassFromString(@"YTActionSheetAction");
        [sheet addAction:[actionClass actionWithTitle:[self titleForCaption:track] iconImage:[YTPMedia imageWithName:@"captions"] style:0 handler:^{
            id<YTPDownloadsMenuToast> toast = YTPMenuToast();
            [toast showToast:YTPDownloadsLocalized(@"ParsingCaptions")];
            [[[SRTParser alloc] init] parseXMLFromURL:(NSURL *)[track URL] forLanguage:[track languageCode] videoID:videoID completion:^(NSURL *url, NSError *error) {
                if (error) [toast showMessageWithText:error.localizedDescription isSuccess:NO];
                else { [toast hide]; [self shareSRT:url sourceView:sender]; }
            }];
        }]];
    }
    YTPMenuPresent(sheet, sender);
}
// First package 0x10c030 / invokes 0x10cc08, 0x10cf20. Only a nonnil URL resumes.
- (void)getCaptionsUrlSheet:(id)player sender:(id)sender completion:(void (^)(NSURL *))completion {
    YTPNode response = YTPMenuResponse(player);
    if (!response) { completion(nil); return; }
    NSString *videoID = [response videoID];
    NSArray *tracks = [self captionsForDownloading:[[(YTPNode)player activeVideo] availableCaptionTracks]];
    id<YTPDownloadsSheet> sheet = [YTPMenuSheets() sheetControllerWithMessage:YTPDownloadsLocalized(@"SelectCaption") subMessage:nil delegate:nil parentResponder:nil];
    for (YTPNode track in tracks) {
        Class<YTPDownloadsAction> actionClass = (Class)NSClassFromString(@"YTActionSheetAction");
        [sheet addAction:[actionClass actionWithTitle:[self titleForCaption:track] iconImage:[YTPMedia imageWithName:@"captions"] style:0 handler:^{
            id<YTPDownloadsMenuToast> toast = YTPMenuToast();
            [toast showToast:YTPDownloadsLocalized(@"ParsingCaptions")];
            [[[SRTParser alloc] init] parseXMLFromURL:(NSURL *)[track URL] forLanguage:[track languageCode] videoID:videoID completion:^(NSURL *url, NSError *error) {
                if (url) { [toast hide]; completion(url); }
                else [toast showMessageWithText:error ? error.localizedDescription : @"Error. Parser didn't returned any links" isSuccess:NO];
            }];
        }]];
    }
    YTPMenuPresent(sheet, sender);
}
// First package 0x10d350 / main-queue invoke 0x10d40c.
- (void)shareSRT:(NSURL *)url sourceView:(UIView *)sourceView {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIActivityViewController *controller = [[UIActivityViewController alloc] initWithActivityItems:@[url] applicationActivities:nil];
        controller.excludedActivityTypes = @[UIActivityTypeAssignToContact, UIActivityTypePrint];
        UIViewController *presenter = [(Class<YTPDownloadsResources>)NSClassFromString(@"YTUIUtils") topViewControllerForPresenting];
        if (controller.popoverPresentationController) {
            controller.popoverPresentationController.sourceView = sourceView;
            CGFloat width = sourceView.bounds.size.width;
            controller.popoverPresentationController.sourceRect = CGRectMake(width - 5, 0, 1, 1);
            controller.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionUp;
        }
        [presenter presentViewController:controller animated:YES completion:nil];
    });
}
// First package 0xfd1d4 / invokes 0xfe1f0, 0xfe238, 0xfe3e0.
- (void)showImagesSheet:(id)player withSender:(id)sender {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    YTPNode thumbnail = [[[[response playerData] videoDetails] thumbnail] thumbnailsArray].lastObject;
    NSURL *url = [NSURL URLWithString:[thumbnail URL]];
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithParentResponder:nil];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"DownloadThumbnail") iconImage:[YTPMedia imageWithName:@"image"] style:0 handler:^{
        [(Class<YTPDownloadsPipeline>)NSClassFromString(@"YTLHelper") downloadImageFromURL:url download:YES];
    }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"ShowThumbnail") iconImage:[YTPMedia imageWithName:@"show_image"] style:0 handler:^{
        UIViewController<YTPDownloadsImageViewer> *viewer = [[NSClassFromString(@"DVNImageViewController") alloc] init];
        [viewer setFullImage:[UIImage imageWithData:[NSData dataWithContentsOfURL:url]]];
        UINavigationController *navigation = [[UINavigationController alloc] initWithRootViewController:viewer];
        navigation.modalPresentationStyle = UIModalPresentationFormSheet;
        [YTPMenuAppRoot() presentViewController:navigation animated:YES completion:nil];
    }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyThumbnail") iconImage:[YTPMedia imageWithName:@"image_library"] style:0 handler:^{
        [(Class<YTPDownloadsPipeline>)NSClassFromString(@"YTLHelper") downloadImageFromURL:url download:NO];
    }]];
    YTPMenuPresent(sheet, sender);
}
// First package 0xfe428; copy invokes 0xffa64, 0xffd88, 0x1000cc, 0x10040c; transcript 0x100a34.
- (void)showInformationSheet:(id)player withSender:(id)sender {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    NSString *title = [[[response playerData] videoDetails] title];
    NSString *author = [[[response playerData] videoDetails] author];
    NSString *description = [[[response playerData] videoDetails] shortDescription];
    BOOL hasDescription = [[[response playerData] videoDetails] hasShortDescription];
    author = YTPMenuShorten(author, 30);
    title = YTPMenuShorten(title, 200);
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithParentResponder:nil];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyChannelName") iconImage:[YTPMedia imageWithName:@"copy"] style:0 handler:^{ YTPMenuCopy(author); }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyTitle") iconImage:[YTPMedia imageWithName:@"copy"] style:0 handler:^{ YTPMenuCopy(title); }]];
    if (hasDescription) [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyDescription") iconImage:[YTPMedia imageWithName:@"copy"] style:0 handler:^{ YTPMenuCopy(description); }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyTimestampedLink") iconImage:[YTPMedia imageWithName:@"copy"] style:0 handler:^{
        long timestamp = (long)llround([(YTPNode)player contentVideoMediaTime]);
        YTPMenuCopy([NSString stringWithFormat:@"https://www.youtube.com/watch?v=%@&t=%lds", [(YTPNode)player contentVideoID], timestamp]);
    }]];
    if ([[[(YTPNode)player activeVideo] availableCaptionTracks] count] != 0) [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"CopyTranscript") iconImage:[YTPMedia imageWithName:@"copy"] style:0 handler:^{ [self showTranscriptSheet:player withSender:sender]; }]];
    YTPMenuPresent(sheet, sender);
}
// First package 0x100a74; system 0x1018c8/0x1019d4, Infuse 0x1019e4/0x101da8, VLC 0x1021b0/0x102610.
- (void)showExtPlayerSheet:(id)player withSender:(id)sender {
    NSURL *url = [[[[[[(YTPNode)player activeVideo] videoData] playbackData] video] streamingData] HLSMasterPlaylistURL];
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithParentResponder:nil];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"PlayInSystemPlayer") iconImage:[YTPMedia imageWithName:@"player"] style:0 handler:^{
        AVPlayer *video = [AVPlayer playerWithURL:url];
        AVPlayerViewController *controller = [[AVPlayerViewController alloc] init];
        controller.player = video;
        [(YTPNode)player pause];
        [(YTPNode)player presentViewController:controller animated:YES completion:^{ [video play]; }];
    }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"PlayInInfuse")
        iconImage:[UIImage imageNamed:@"infuse" inBundle:[NSBundle ytl_defaultBundle] compatibleWithTraitCollection:nil]
        style:0 handler:^{
            NSString *external = [NSString stringWithFormat:@"infuse://x-callback-url/play?url=%@", url];
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:external] options:@{} completionHandler:^(BOOL success) {
                if (success) [(YTPNode)player pause]; else YTPMenuLegacyToast(@"PlayerNotFound");
            }];
        }]];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"PlayInVLC")
        iconImage:[UIImage imageNamed:@"vlc" inBundle:[NSBundle ytl_defaultBundle] compatibleWithTraitCollection:nil]
        style:0 handler:^{
            NSString *external = [NSString stringWithFormat:@"vlc-x-callback://x-callback-url/stream?url=%@", url];
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:external] options:@{} completionHandler:^(BOOL success) {
                if (success) [(YTPNode)player pause]; else YTPMenuLegacyToast(@"PlayerNotFound");
            }];
        }]];
    YTPMenuPresent(sheet, sender);
}
// First package 0xfb194 / action 0xfc744, storage callback 0xfcaac.
- (void)showVideoSheet:(id)player withSender:(id)sender {
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    NSString *videoID = [response videoID];
    NSString *author = [[[response playerData] videoDetails] author];
    NSString *title = [[[response playerData] videoDetails] title];
    author = YTPMenuShorten(author, 30);
    title = YTPMenuShorten(title, 200);
    NSArray *videos = [self getVideoFormatsArray:player isShorts:NO], *audioFormats = [self getAudioFormatsArray:player];
    YTPNode best = [self getBestAudioFormat:audioFormats playerVC:player];
    BOOL hasTrack = [[[(YTPNode)player activeVideo] selectedAudioFormat] audioTrack] != nil;
    NSMutableArray *actions = [NSMutableArray array];
    for (YTPNode video in videos) {
        NSString *extension = [[video mimeType] hasPrefix:@"video/mp4"] ? @"mp4" : @"webM";
        NSString *detail = [self detailForMimeType:[video mimeType]] ?: extension;
        NSString *quality = [video qualityLabel];
        unsigned long long size = [video contentLength] + [best contentLength];
        NSString *sizeText = [NSByteCountFormatter stringFromByteCount:(long long)size countStyle:NSByteCountFormatterCountStyleFile];
        id<YTPDownloadsAction> action = [YTPMenuActions() actionWithTitle:[NSString stringWithFormat:@"%@ %@", quality, detail] currentValue:sizeText iconImage:[YTPMedia imageWithName:@"player"] accessibilityIdentifier:nil handler:^{
            if (![video hasContentLength]) { YTPMenuLocalizedError(@"Error.TryLater"); return; }
            [self checkSpaceAvailabilityForMedia:(long long)size completion:^(BOOL available, NSString *message) {
                if (!available) { YTPMenuError(message); return; }
                if (hasTrack) [self downloadVideoWithFormat:video withAudioFormats:audioFormats fileName:YTPMenuName(author, title) extension:extension.lowercaseString videoID:videoID playerVC:player sender:sender];
                else if (ytpBool(@"downloadWithCaps") && [self hasCaptions:player]) {
                    [self downloadVideoWithFormat:video audioFormat:best fileName:YTPMenuName(author, title) extension:extension.lowercaseString videoID:videoID playerVC:player sender:sender];
                } else [self downloadVideoWithUrl:YTPMenuURL(video) audioUrl:YTPMenuURL(best) fileName:YTPMenuName(author, title) extension:extension.lowercaseString videoID:videoID videoSize:[video contentLength] audioSize:[best contentLength] duration:[video approxDurationMs] captions:nil playerVC:player];
            }];
        }];
        NSMutableAttributedString *label = [[action button].currentAttributedTitle mutableCopy];
        NSRange range = [label.string rangeOfString:detail options:NSCaseInsensitiveSearch];
        if (range.location != NSNotFound) [label setAttributes:@{NSForegroundColorAttributeName:[UIColor redColor], NSFontAttributeName:[UIFont systemFontOfSize:10], NSBaselineOffsetAttributeName:@5} range:range];
        [[action button] setAttributedTitle:label forState:UIControlStateNormal];
        [actions addObject:action];
    }
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithParentResponder:nil];
    for (id action in actions) [sheet addAction:action];
    YTPMenuPresent(sheet, sender);
}
// The two class entrypoints follow below; they use the same genuine host sheet contracts.

// First package 0xf53fc / download 0xf72b8, storage 0xf7404, open 0xf796c, toggle 0xf7a5c.
+ (void)showDownloadSheetShorts:(id)player withSender:(id)sender {
    DownloadMenuHelper *helper = [[DownloadMenuHelper alloc] init];
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    NSString *videoID = [response videoID];
    NSString *title = [[[response playerData] videoDetails] title];
    NSString *author = [[[response playerData] videoDetails] author];
    author = YTPMenuShorten(author, 30);
    title = YTPMenuShorten(title, 200);
    NSArray *videos = [helper getVideoFormatsArray:player isShorts:YES];
    NSArray *audioFormats = [helper getAudioFormatsArray:player];
    // Original objectAtIndexedSubscript:0 deliberately preserves the empty-array exception.
    YTPNode video = [videos objectAtIndexedSubscript:0];
    YTPNode best = [helper getBestAudioFormat:audioFormats playerVC:player];
    BOOL hasTrack = [[[(YTPNode)player activeVideo] selectedAudioFormat] audioTrack] != nil;
    long long size = (long long)[video contentLength];
    NSString *sizeText = [NSByteCountFormatter stringFromByteCount:size countStyle:NSByteCountFormatterCountStyleFile];
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithMessage:author subMessage:title delegate:nil parentResponder:nil];
    [(id<YTPDownloadsSheetHeader>)[sheet valueForKey:@"_headerView"] showHeaderDivider];
    UIImage *chevron = YTPMenuCachedChevron();
    if (![[response playerData] isLivePlayback]) {
        [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"DownloadVideo") currentValue:sizeText iconImage:[YTPMedia imageWithName:@"FEshorts"] accessibilityIdentifier:nil handler:^{
            [helper checkSpaceAvailabilityForMedia:size completion:^(BOOL available, NSString *message) {
                if (!available) { YTPMenuError(message); return; }
                if (hasTrack) [helper downloadVideoWithFormat:video withAudioFormats:audioFormats fileName:YTPMenuName(author, title) extension:@"mp4" videoID:videoID playerVC:player sender:sender];
                else [helper downloadVideoWithUrl:YTPMenuURL(video) audioUrl:YTPMenuURL(best) fileName:YTPMenuName(author, title) extension:@"mp4" videoID:videoID videoSize:[video contentLength] audioSize:[best contentLength] duration:[video approxDurationMs] captions:nil playerVC:nil];
            }];
        }]];
    }
    [sheet addAction:YTPMenuSubmenu(@"SaveImage", @"image", chevron, ^{ [helper showImagesSheet:player withSender:sender]; })];
    [sheet addAction:YTPMenuSubmenu(@"CopyInformation", @"copy", chevron, ^{ [helper showInformationSheet:player withSender:sender]; })];
    [sheet addAction:YTPMenuSubmenu(@"OpenAsRegularVideo", @"youtube_logo", chevron, ^{
        if ([(YTPNode)player contentVideoID]) [(Class<YTPDownloadsPlayerHelper>)NSClassFromString(@"YTPPlayerHelper") openVideoWithID:[(YTPNode)player contentVideoID] viewController:player];
    })];
    [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"AutoSkipShorts") iconImage:[YTPMedia imageWithName:@"fast_forward"]
        secondaryIconImage:[YTPMedia imageWithName:ytpInt(@"shortsPlaybackIndex") == 1 ? @"box_checkmark" : @"box_empty"] accessibilityIdentifier:nil handler:^{
        long long newValue = ytpInt(@"shortsPlaybackIndex") != 1;
        [[(Class<YTPDownloadsMutablePreferences>)NSClassFromString(@"YTLUserDefaults") standardUserDefaults] setInteger:newValue forKey:@"shortsPlaybackIndex"];
    }]];
    YTPMenuPresent(sheet, sender);
}
// First package 0xf7c6c; construction and audio provenance are recorded separately.
+ (void)showDownloadSheet:(id)player withSender:(id)sender {
    DownloadMenuHelper *helper = [[DownloadMenuHelper alloc] init];
    YTPNode response = YTPMenuResponse(player);
    if (!response) return;
    NSString *videoID = [response videoID];
    NSString *title = [[[response playerData] videoDetails] title];
    NSString *author = [[[response playerData] videoDetails] author];
    author = YTPMenuShorten(author, 30);
    title = YTPMenuShorten(title, 200);
    NSArray *audioFormats = [helper getAudioFormatsArray:player];
    YTPNode best = [helper getBestAudioFormat:audioFormats playerVC:player];
    BOOL hasTrack = [[[(YTPNode)player activeVideo] selectedAudioFormat] audioTrack] != nil;
    id<YTPDownloadsSheet> sheet = [YTPMenuCachedSheets() sheetControllerWithMessage:author subMessage:title delegate:nil parentResponder:nil];
    [(id<YTPDownloadsSheetHeader>)[sheet valueForKey:@"_headerView"] showHeaderDivider];
    UIImage *chevron = YTPMenuCachedChevron();
    if (![[response playerData] isLivePlayback]) [sheet addAction:YTPMenuSubmenu(@"DownloadVideo", @"player", chevron, ^{ [helper showVideoSheet:player withSender:sender]; })];
    [sheet addAction:YTPMenuSubmenu(@"SaveImage", @"image", chevron, ^{ [helper showImagesSheet:player withSender:sender]; })];
    [sheet addAction:YTPMenuSubmenu(@"CopyInformation", @"copy", chevron, ^{ [helper showInformationSheet:player withSender:sender]; })];
    if ([helper hasCaptions:player]) [sheet addAction:YTPMenuSubmenu(@"DownloadCaptions", @"captions", chevron, ^{ [helper showCaptionsSheet:player withSender:sender]; })];
    [sheet addAction:YTPMenuSubmenu(@"PlayInExternalPlayer", @"play_circle", chevron, ^{ [helper showExtPlayerSheet:player withSender:sender]; })];
    if (![[response playerData] isLivePlayback]) {
        NSString *sizeText = [NSByteCountFormatter stringFromByteCount:(long long)[best contentLength] countStyle:NSByteCountFormatterCountStyleFile];
        [sheet addAction:[YTPMenuActions() actionWithTitle:YTPDownloadsLocalized(@"DownloadAudio") currentValue:sizeText iconImage:[YTPMedia imageWithName:@"music"] accessibilityIdentifier:nil handler:^{
            if (![best hasContentLength]) { YTPMenuLocalizedError(@"Error.TryLater"); return; }
            [helper checkSpaceAvailabilityForMedia:(long long)[best contentLength] completion:^(BOOL available, NSString *message) {
                if (!available) { YTPMenuError(message); return; }
                id<YTPDownloadsAppRoot> root = (id)YTPMenuAppRoot();
                [root setHelper:(id)[[NSClassFromString(@"YTLHelper") alloc] init]];
                if (!hasTrack) { YTPMenuAudio(root, best, author, title, videoID); return; }
                // Four independent preference reads in 0xfa840; do not collapse to a cached switch.
                if (ytpInt(@"ytlAudioIndex") == 0) {
                    YTPNode format = [helper getDefaultAudioTrack:audioFormats];
                    if (format) YTPMenuAudio(root, format, author, title, videoID);
                }
                if (ytpInt(@"ytlAudioIndex") == 1) YTPMenuAudio(root, best, author, title, videoID);
                if (ytpInt(@"ytlAudioIndex") == 2) {
                    YTPNode format = [helper getEnglishAudioTrack:audioFormats];
                    if (format) YTPMenuAudio(root, format, author, title, videoID); else YTPMenuLocalizedError(@"EnglishNotFound");
                }
                if (ytpInt(@"ytlAudioIndex") == 3) {
                    [helper showAudioTrackSelector:audioFormats sender:sender playerVC:player completion:^(id format) {
                        if (format) YTPMenuAudio(root, format, author, title, videoID);
                    }];
                }
            }];
        }]];
    }
    YTPMenuPresent(sheet, sender);
}
@end
