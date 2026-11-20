#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Helpers/HelpersHost.h"
#import "../source/Helpers/HelpersTransforms.h"
#import "../source/Presentation/ToastWindow.h"
#include <limits.h>
#import <objc/runtime.h>

static NSURL *Remote(NSString *name) { return [NSURL URLWithString:[@"https://fixture.invalid/" stringByAppendingString:name]]; }
static ToastView *HelperToast(YTLHelper *helper) { return PGet(helper,@"_toastView"); }
static NSString *NewestToastText(void) { return [PGet([ToastManager sharedManager].toasts.lastObject,@"_toastLabel") text]; }
static UIActivityViewController *CurrentActivity(void) { return (id)UIApplication.sharedApplication.delegate.window.rootViewController.presentedViewController; }
static void CompleteConversion(NSURL *result,NSError *error) {
    PCheck(PresentationConversions.count>0,@"pending conversion callback");
    NSDictionary *record=PresentationConversions.firstObject;
    void (^completion)(NSURL *,NSError *)=record[@"completion"];
    [PresentationConversions removeObjectAtIndex:0];completion(result,error);PSettle();
}
static void CompletePhoto(BOOL success,NSError *error) {
    PCheck(PresentationPhotoChanges.count>0,@"pending Photos transaction");
    NSDictionary *transaction=PresentationPhotoChanges.firstObject;
    [PresentationPhotoChanges removeObjectAtIndex:0];
    dispatch_block_t changes=transaction[@"changes"];changes();
    void (^completion)(BOOL,NSError *)=transaction[@"completion"];completion(success,error);
}
static void FinishActivity(BOOL completed) {
    UIActivityViewController *activity=CurrentActivity();
    PCheck([activity isKindOfClass:UIActivityViewController.class],@"activity presentation exists");
    PCheck(activity.completionWithItemsHandler!=nil,@"share installs cleanup callback");
    activity.completionWithItemsHandler(nil,completed,nil,nil);activity.completionWithItemsHandler=nil;
    UIApplication.sharedApplication.delegate.window.rootViewController.presentedViewController=nil;
    PSettle();
}
static YTLHelper *BeginAudio(NSString *identifier,NSString *title,unsigned long long duration) {
    YTLHelper *helper=[YTLHelper new];
    [helper downloadAudioWithUrl:Remote(@"audio") fileName:title videoID:identifier audioSize:2048 duration:duration];PSettle();return helper;
}
static YTLHelper *BeginVideo(NSString *identifier,NSInteger mode) {
    PresentationPostDownloadIndex=mode;
    YTLHelper *helper=[YTLHelper new];
    [helper downloadVideoWithUrl:Remote(@"video") audioUrl:Remote(@"audio") fileName:@"V/ideo" format:@"mp4"
        videoID:identifier videoSize:8192 audioSize:2048 duration:12501 captions:Remote(@"captions")];PSettle();return helper;
}
static void SendVideoAndAudio(YTLHelper *helper,NSString *identifier) {
    NSURL *video=PFile([identifier stringByAppendingFormat:@"/%@_v.mp4",identifier]);
    NSURL *audio=PFile([identifier stringByAppendingFormat:@"/%@_a.m4a",identifier]);
    PWrite(video,@"SYNTHETIC VIDEO TRANSPORT BYTES -- NOT REAL MEDIA");
    [helper downloadDidFinish:video fileName:video.lastPathComponent];PSettle();
    NSDictionary *second=PresentationDownloads.lastObject;
    PEqual(second[@"name"],[identifier stringByAppendingString:@"_a.m4a"],@"video finishes by starting audio phase");
    PEqual(second[@"url"],Remote(@"audio"),@"audio URL survives sentinel phase call");
    PEqual(second[@"size"],@2048,@"audio size survives sentinel phase call");
    PWrite(audio,@"SYNTHETIC AUDIO TRANSPORT BYTES -- NOT REAL MEDIA");
    [helper downloadDidFinish:audio fileName:audio.lastPathComponent];PSettle();
    NSDictionary *conversion=PresentationConversions.lastObject;
    PEqual(conversion[@"operation"],@"merge",@"both phases invoke merge rather than audio cut");
    PEqual(conversion[@"video"],video,@"merge original video URL");PEqual(conversion[@"audio"],audio,@"merge downloaded audio URL");
    PEqual(conversion[@"captions"],Remote(@"captions"),@"caption URL forwarded unchanged");
    PEqual(conversion[@"duration"],@13,@"ceiling milliseconds to merge seconds");
}

static void TestTransformsAndFactories(void) {
    NSCharacterSet *illegal=[NSCharacterSet characterSetWithCharactersInString:@"/\\?*|\"<>"];
    PEqual(YTLDownloadSanitizedTitle(@"A/B\\C?*|\"<>:Title",illegal),@"ABC:Title",@"invalid title characters removed, not replaced");
    for(unsigned long long value=0;value<=20000;value+=137)
        PCheck(YTLDownloadDurationSeconds(value)==value/1000+(value%1000!=0),@"duration ceiling grid");
    PCheck(YTLDownloadDurationSeconds(1000)==1&&YTLDownloadDurationSeconds(1001)==2,@"duration second boundary");
    for(NSString *component in @[@"",@".",@"..",@"a/b",@"a\\b"])PCheck(!YTLIsSinglePathComponent(component),@"invalid path component rejected");
    for(NSString *component in @[@"abc-_123",@"é",@"a.b",@"colon:title"])PCheck(YTLIsSinglePathComponent(component),@"ordinary path components retained");
    PCheck(YTLDownloadDirectory(@"../escape")==nil,@"download directory containment");
    PEqual(YTLDownloadImageURL(Remote(@"image=w400-h200-c-fcrop64=1")).absoluteString,
        @"https://fixture.invalid/image=w400-h200-nd-v1",@"image crop suffix transformation");
    NSURL *uncropped=Remote(@"original.png?x=1");PCheck(YTLDownloadImageURL(uncropped)==uncropped,@"uncropped URL identity");

    YTLHelper *helper=[YTLHelper new];
    UIImage *image=[UIImage systemImageNamed:@"fixture"];
    UIImage *resized=[helper resizeImage:image toSize:37.5];PNear(resized.size.width,37.5,@"instance resize width");PNear(resized.size.height,37.5,@"instance resize height");
    PCheck(resized.fixtureDrawing[@"layer"]!=nil,@"instance renderer draws a composed layer");
    UIImage *classResized=[YTLHelper resizeImage:image toSize:18];PNear(classResized.size.width,18,@"class resize width");
    UIImage *asset=[helper imageNamed:@"save_photos"];PNear(asset.size.width,24,@"helper action asset width");
    PCheck(asset.renderingMode==UIImageRenderingModeAlwaysTemplate,@"helper action asset template mode");
    PEqual([YTLHelper YTImageNamed:@"host.asset"].fixtureName,@"host.asset",@"YouTube asset loader name");
    PEqual([YTLHelper YTLImageNamed:@"tweak.asset"].fixtureName,@"tweak.asset",@"tweak asset loader name");
    CALayer *layer=[CALayer layer];layer.frame=CGRectMake(10,20,32,16);__block BOOL called=NO;
    [YTLHelper genImageFromLayer:layer backgroundColor:UIColor.whiteColor completionHandler:^(UIImage *result){
        called=YES;PNear(result.size.width,32,@"layer image width");PNear(result.size.height,16,@"layer image height");
        PCheck(result.fixtureDrawing[@"layer"]!=nil,@"layer callback follows render");
    }];PCheck(called,@"layer image callback is synchronous");
    for(NSNumber *flags in @[@0,@2,@4,@6,@0x40000,@0x40002,@0x10002]) {
        PresentationReachabilityFlags=flags.unsignedIntValue;PresentationReachabilitySucceeded=YES;
        PCheck([YTLHelper isConnectedToWiFi]==((flags.unsignedIntValue&0x40002)==2),@"WiFi flags retain original bitmask contract");
    }
    PresentationReachabilitySucceeded=NO;PCheck(![YTLHelper isConnectedToWiFi],@"reachability read error");
    PresentationReachabilitySucceeded=YES;PresentationReachabilityCreated=NO;PCheck(![YTLHelper isConnectedToWiFi],@"reachability creation error");PresentationReachabilityCreated=YES;
    NSData *address=(id)PLast(@"reachability.address");const unsigned char *bytes=address.bytes;
    PCheck(address.length==16&&bytes[0]==16&&bytes[1]==2,@"zero IPv4 socket address ABI");

    UIButton *button=[YTLHelper createYTQTMButton:nil accessibilityLabel:@"Accessible" buttonLabel:@"Label" icon:nil selector:NULL];
    PEqual(button.accessibilityLabel,@"Accessible",@"host button accessibility label");PEqual(button.fixtureTitle,@"Label",@"nil icon uses title");
    PCheck(button.titleLabel.adjustsFontSizeToFitWidth,@"text button shrinking");
    NSArray *constants=[button.fixtureConstraints valueForKey:@"constant"];PEqual(constants,(@[@40,@40]),@"host button default dimensions");
    button=[YTLHelper createYTQTMButton:nil accessibilityLabel:@"Image" buttonLabel:@"unused" icon:image size:CGSizeMake(30,45) selector:NULL];
    PCheck(button.fixtureImage==image&&button.fixtureTitle==nil,@"host button image branch");
    PEqual([button.fixtureConstraints valueForKey:@"constant"],(@[@30,@45]),@"host button explicit dimensions");
    YTQTMButton *overlay=(id)[YTLHelper createOverlayButton:nil accessibilityLabel:@"Overlay" buttonLabel:nil icon:image selector:NULL];
    PCheck(overlay.fixtureImage.renderingMode==UIImageRenderingModeAlwaysTemplate,@"overlay template image");
    PEqual([overlay.fixtureConstraints valueForKey:@"constant"],(@[@24,@36]),@"overlay dimensions");
    PCheck(overlay.touchFeedbackView.forceCircularTouchFeedback,@"overlay circular feedback");
    PNear(overlay.touchFeedbackView.touchFeedbackInsets.left,-6,@"overlay expanded feedback leading");
    PNear(overlay.touchFeedbackView.touchFeedbackInsets.right,-6,@"overlay expanded feedback trailing");
}

static void TestAudioPipeline(void) {
    PresentationPostDownloadIndex=0;
    YTLHelper *helper=BeginAudio(@"audio-fixture",@"A/B\\C?*|\"<>:Title",12501);
    NSDictionary *request=PresentationDownloads.lastObject;
    PEqual(request[@"name"],@"audio-fixture_a.m4a",@"audio request name uses video ID");
    PEqual(request[@"videoID"],@"audio-fixture",@"audio request directory ID");PEqual(request[@"size"],@2048,@"unsigned audio file size");
    PCheck(PGet(request[@"downloader"],@"delegate")==helper,@"downloader delegate identity");
    PEqual(PGet(helper,@"_title"),@"ABC:Title",@"orchestration applies actual title transformation");
    PCheck([PGet(helper,@"_isAudioOnly") boolValue]&&[PGet(helper,@"_isVideoDownloaded") boolValue],@"audio-only state starts final phase");
    [helper downloadProgress:.126f];PEqual([PGet(HelperToast(helper),@"_toastLabel") text],@"DownloadingAudio: 13%",@"transport progress label contract");
    PNear([(UIProgressView *)PGet(HelperToast(helper),@"_toastProgress") progress],.126,@"transport progress scalar unchanged");
    NSURL *audio=PFile(@"audio-fixture/audio-fixture_a.m4a");PWrite(audio,@"SYNTHETIC AUDIO INPUT");
    [helper downloadDidFinish:audio fileName:@"unused"];PSettle();
    PEqual(PresentationConversions.lastObject[@"operation"],@"cut",@"audio completion cuts audio");
    PEqual(PresentationConversions.lastObject[@"audio"],audio,@"audio completion URL forwarding");
    PEqual(PresentationConversions.lastObject[@"duration"],@13,@"audio duration ceil");
    NSURL *converted=PFile(@"audio-fixture/converted.bin");PWrite(converted,@"SYNTHETIC CONVERTER OUTPUT");
    CompleteConversion(converted,nil);
    NSURL *destination=PFile(@"audio-fixture/ABC:Title.m4a");PCheck(PExists(destination)&&!PExists(converted),@"converted audio atomically moved to sanitized final URL");
    PCheck(!PExists(audio),@"audio intermediate removed");
    UIActivityViewController *activity=CurrentActivity();PEqual(activity.fixtureItems,@[destination],@"audio always shares regardless video-save preference");
    PEqual(activity.excludedActivityTypes,(@[UIActivityTypeAssignToContact,UIActivityTypePrint]),@"audio share exclusions");
    PNear(activity.popoverPresentationController.sourceRect.origin.x,195,@"activity anchor horizontal center");
    PNear(activity.popoverPresentationController.sourceRect.origin.y,844,@"activity anchor bottom");
    PCheck(activity.popoverPresentationController.permittedArrowDirections==UIPopoverArrowDirectionAny,@"activity popover arrow contract");
    FinishActivity(NO);PCheck(!PExists(destination),@"cancelled activity still cleans operation directory");
    PClearToasts();
}

static void TestVideoRouting(void) {
    for(NSInteger mode=0;mode<3;mode++) {
        NSString *identifier=[NSString stringWithFormat:@"video-%ld",(long)mode];
        YTLHelper *helper=BeginVideo(identifier,mode);
        NSDictionary *first=PresentationDownloads.lastObject;
        PEqual(first[@"name"],[identifier stringByAppendingString:@"_v.mp4"],@"video transport filename");
        PEqual(first[@"size"],@8192,@"video size forwarding");PCheck(![PGet(helper,@"_isVideoDownloaded") boolValue],@"video phase initially pending");
        [helper downloadProgress:.5f];PEqual([PGet(HelperToast(helper),@"_toastLabel") text],@"DownloadingVideo: 50%",@"video progress phase label");
        SendVideoAndAudio(helper,identifier);
        NSURL *converted=PFile([identifier stringByAppendingString:@"/converted.bin"]);PWrite(converted,@"SYNTHETIC MERGED OUTPUT");
        CompleteConversion(converted,nil);
        NSURL *final=PFile([identifier stringByAppendingString:@"/Video.mp4"]);PCheck(PExists(final),@"merged output renamed with requested container");
        if(mode==0) {
            PCheck(PresentationPhotoChanges.count==1,@"Save route schedules one Photos change");
            CompletePhoto(YES,nil);PCheck(PExists(final),@"Photos callback marshals cleanup to main queue");
            PSettle();PEqual(PLast(@"photos.resource")[@"type"],@2,@"saved video Photos resource kind");
            PEqual(PLast(@"photos.resource")[@"url"],final,@"Photos receives actual output URL");
            PCheck(!PExists(final),@"Photos success cleans output directory");PEqual(NewestToastText(),@"Saved",@"Photos success feedback");
        } else if(mode==1) {
            PEqual(CurrentActivity().fixtureItems,@[final],@"Share route presents output");FinishActivity(YES);PCheck(!PExists(final),@"shared video cleanup");
        } else {
            NSDictionary *event=PLast(@"host.sheet");id sheet=event[@"sheet"];
            PEqual(PGet(sheet,@"fixtureMessage"),@"DownloadCompleted",@"Ask route message");
            NSArray *actions=PGet(sheet,@"fixtureActions");PCheck(actions.count==2,@"Ask route two real actions");
            PEqual([actions valueForKey:@"fixtureTitle"],(@[@"SaveToPhotos",@"Share"]),@"Ask route order");
            PCheck(PGet(sheet,@"fixtureSource")==UIApplication.sharedApplication.delegate.window.rootViewController.view,@"Ask route pivot source view");
            dispatch_block_t share=PGet(actions[1],@"fixtureHandler");share();PSettle();
            PEqual(CurrentActivity().fixtureItems,@[final],@"Ask share block forwards captured output URL");FinishActivity(NO);
        }
        PClearToasts();
    }
    // A failed Photos import must preserve the completed output for sharing.
    YTLHelper *helper=BeginVideo(@"photo-failure",0);SendVideoAndAudio(helper,@"photo-failure");
    NSURL *result=PFile(@"photo-failure/converted.bin");PWrite(result,@"SYNTHETIC MERGED OUTPUT");CompleteConversion(result,nil);
    NSError *denied=[NSError errorWithDomain:@"fixture.photos" code:1 userInfo:@{NSLocalizedDescriptionKey:@"fixture denial"}];
    CompletePhoto(NO,denied);PSettle();NSURL *final=PFile(@"photo-failure/Video.mp4");
    PCheck(PExists(final),@"Photos failure does not destroy user-shareable output");PEqual(CurrentActivity().fixtureItems,@[final],@"Photos failure falls back to share");FinishActivity(YES);
    // Exercise the other Ask action without invoking any real photo library.
    helper=BeginVideo(@"ask-save",99);SendVideoAndAudio(helper,@"ask-save");result=PFile(@"ask-save/converted.bin");PWrite(result,@"SYNTHETIC MERGED OUTPUT");CompleteConversion(result,nil);
    NSArray *actions=PGet(PLast(@"host.sheet")[@"sheet"],@"fixtureActions");dispatch_block_t save=PGet(actions[0],@"fixtureHandler");save();
    PCheck(PresentationPhotoChanges.count==1,@"unknown preference uses Ask, save block schedules Photos");CompletePhoto(YES,nil);PSettle();
    PClearToasts();
}

static void TestFailuresAndOwnership(void) {
    YTLHelper *helper=BeginAudio(@"conversion-error",@"Audio",1000);
    NSURL *input=PFile(@"conversion-error/conversion-error_a.m4a");PWrite(input,@"SYNTHETIC INPUT");[helper downloadDidFinish:input fileName:@"x"];
    NSURL *partial=PFile(@"conversion-error/partial.bin");PWrite(partial,@"SYNTHETIC PARTIAL OUTPUT");
    NSError *error=[NSError errorWithDomain:@"fixture.converter" code:9 userInfo:@{NSLocalizedDescriptionKey:@"Fixture conversion failed"}];
    CompleteConversion(partial,error);PCheck(!PExists(partial),@"converter error removes partial returned output");
    PCheck(PExists(input),@"converter error retains download input per original callback");PEqual(NewestToastText(),@"Fixture conversion failed",@"converter error toast");
    [helper cleanup];PClearToasts();
    helper=BeginAudio(@"move-error",@"Audio",1000);input=PFile(@"move-error/move-error_a.m4a");PWrite(input,@"SYNTHETIC INPUT");[helper downloadDidFinish:input fileName:@"x"];
    CompleteConversion(PFile(@"move-error/nonexistent.bin"),nil);PEqual(NewestToastText(),@"Error.PathIssue",@"move error feedback");
    PCheck(!PExists(input),@"move-failure branch still releases intermediate input");[helper cleanup];PClearToasts();
    helper=[YTLHelper new];
    [helper downloadDidFailureWithError:nil];PCheck([ToastManager sharedManager].toasts.count==0,@"nil transport error ignored");
    [helper downloadDidFailureWithError:[NSError errorWithDomain:NSURLErrorDomain code:NSURLErrorCancelled userInfo:nil]];PSettle();
    PCheck([ToastManager sharedManager].toasts.count==0,@"cancelled transport does not show failure");
    [helper downloadDidFailureWithError:error];PSettle();PEqual(NewestToastText(),@"Fixture conversion failed",@"transport error callback shows localized description");PClearToasts();
    NSUInteger requests=PresentationDownloads.count;
    [helper downloadVideoWithUrl:Remote(@"video") audioUrl:Remote(@"audio") fileName:@"Title" format:@"../mp4" videoID:@"../escape"
        videoSize:1 audioSize:1 duration:1000 captions:nil];PSettle();
    PCheck(PresentationDownloads.count==requests,@"invalid directory/extension never reaches transport");PEqual(NewestToastText(),@"Error.PathIssue",@"invalid path error contract");PClearToasts();
    YTLHelper *videoCancel=BeginVideo(@"cancel-video",0);
    [HelperToast(videoCancel) cancelButtonTapped];PSettle();
    PCheck(PresentationEventsOfKind(@"download.cancel").count==1,@"first-phase video stop callback cancels transport");
    PCheck(HelperToast(videoCancel).superview==nil,@"first-phase stop dismisses progress UI");PClearToasts();
    YTLHelper *audioSave=[YTLHelper new];PSet(audioSave,@"_videoID",@"save-audio");
    NSURL *audioFile=PFile(@"save-audio/Audio.m4a");PWrite(audioFile,@"SYNTHETIC AUDIO SHARE FIXTURE");
    [audioSave saveMedia:audioFile];PSettle();
    PCheck(PresentationPhotoChanges.count==0,@"saveMedia never submits an audio file to Photos");
    PEqual(CurrentActivity().fixtureItems,@[audioFile],@"saveMedia redirects audio to share");FinishActivity(NO);PClearToasts();
    __weak YTLHelper *weakHelper;
    ToastView *operationToast;
    @autoreleasepool {
        YTLHelper *operation=BeginAudio(@"operation-owner",@"Audio",1000);weakHelper=operation;operationToast=HelperToast(operation);
    }
    PCheck(weakHelper!=nil,@"copied stop callback retains operation across root-helper replacement");
    [operationToast cancelButtonTapped];PSettle();
    PCheck(PresentationEventsOfKind(@"download.cancel").count==1,@"stop button cancels real delegate boundary exactly once");
    PCheck(operationToast.completion!=nil,@"original stop cleanup preserves operation callback");
    PCheck(weakHelper!=nil,@"preserved callback continues to own operation");
    // Fixture teardown only: production cleanup at 0x1bfcdc does not clear this.
    operationToast.completion=nil;
    PCheck(weakHelper==nil,@"explicit fixture callback release ends operation ownership");
    PClearToasts();
}

static void TestImageCallbacks(void) {
    NSData *data=[@"SYNTHETIC IMAGE NETWORK BYTES" dataUsingEncoding:NSUTF8StringEncoding];
    [YTLHelper downloadImageFromURL:Remote(@"cover=c-fcrop64=1") download:NO];
    PCheck(PresentationLastNetworkTask.fixtureResumed,@"image task starts");
    PEqual(PresentationLastNetworkTask.fixtureURL.absoluteString,@"https://fixture.invalid/cover=nd-v1",@"download method applies crop rewrite");
    PresentationLastNetworkTask.fixtureCompletion(data,nil,nil);PCheck(UIPasteboard.generalPasteboard.image.fixtureData!=data,@"copy completion marshals UI to main queue");
    PSettle();PEqual(UIPasteboard.generalPasteboard.image.fixtureData,data,@"download:NO copies decoded image to pasteboard");PEqual(NewestToastText(),@"Copied",@"image copy feedback");PClearToasts();
    [YTLHelper downloadImageFromURL:Remote(@"image.png") download:YES];PresentationLastNetworkTask.fixtureCompletion(data,nil,nil);
    PCheck(PresentationPhotoChanges.count==1,@"download:YES schedules Photos transaction");CompletePhoto(YES,nil);PSettle();
    PEqual(PLast(@"photos.resource")[@"type"],@1,@"photo resource type");PEqual(PLast(@"photos.resource")[@"data"],data,@"photo path preserves original raw bytes");
    PEqual(NewestToastText(),@"Saved",@"saved image feedback");PClearToasts();
    NSError *error=[NSError errorWithDomain:@"fixture.network" code:7 userInfo:@{NSLocalizedDescriptionKey:@"No fixture data"}];
    [YTLHelper downloadImageFromURL:Remote(@"error") download:NO];PresentationLastNetworkTask.fixtureCompletion(nil,nil,error);PSettle();
    PEqual(NewestToastText(),@"Error: No fixture data",@"image transport failure text");PClearToasts();
    [YTLHelper downloadImageFromURL:Remote(@"denied") download:YES];PresentationLastNetworkTask.fixtureCompletion(data,nil,nil);
    CompletePhoto(NO,error);PSettle();PEqual(NewestToastText(),@"Error: No fixture data",@"image Photos error feedback");PClearToasts();
    [YTLHelper downloadImageFromURL:nil download:YES];
    PCheck(PresentationLastNetworkTask.fixtureURL==nil&&PresentationLastNetworkTask.fixtureResumed,@"nil image URL reaches synthetic session boundary");
    PresentationLastNetworkTask=nil;PClearToasts();
}

@interface HelperProgressProbe : NSObject
@property(copy) NSString *text;
@property float value;
@property(copy) NSString *route;
@property BOOL animated;
@end
@implementation HelperProgressProbe
- (void)updateText:(NSString *)text progress:(float)value {
    self.text=text;self.value=value;self.route=@"update";self.animated=YES;
}
- (void)updateText:(NSString *)text progress:(float)value animated:(BOOL)animated {
    self.text=text;self.value=value;self.route=@"update:animated:";self.animated=animated;
}
- (void)showProgressWithText:(NSString *)text progress:(float)value withStop:(BOOL)stop stopCompletion:(dispatch_block_t)completion {
    self.text=text;self.value=value;self.route=@"show";
    PCheck(stop && completion!=nil,@"audio-only progress retains stop option");
}
@end

static double FirstPackageProgressPercent(float value) {
    // Independent native oracle for the first package's FMUL S / FCVT D pair.
    // This newly compiled fixture executes no original dylib instructions.
    double result;
    float hundred=100.0f;
    __asm__("fmul %s0, %s1, %s2\n\tfcvt %d0, %s0" : "=w"(result) : "w"(value),"w"(hundred));
    return result;
}

static void TestFirstPackageProgress(void) {
    NSUInteger before=PresentationAssertions;
    YTLHelper *helper=[YTLHelper new];PSettle();
    HelperProgressProbe *probe=[HelperProgressProbe new];PSet(helper,@"_toastView",probe);
    for(NSUInteger phase=0;phase<2;phase++) {
        PSet(helper,@"_isVideoDownloaded",@(phase));
        NSString *prefix=phase ? @"DownloadingAudio" : @"DownloadingVideo";
        for(NSUInteger percent=0;percent<100;percent++) {
            float center=(float)((percent+0.5)/100.0);
            float values[]={nextafterf(center,-INFINITY),center,nextafterf(center,INFINITY)};
            for(NSUInteger i=0;i<3;i++) {
                [helper downloadProgress:values[i]];
                NSString *expected=[NSString stringWithFormat:@"%@: %.0f%%",prefix,FirstPackageProgressPercent(values[i])];
                PEqual(probe.text,expected,@"first-package single-precision percentage rounding");
                PCheck(probe.value==values[i] && [probe.route isEqual:@"update"],@"ordinary progress forwards original float and selector");
            }
        }
        float edges[]={-0.0f,-1.0f,2.0f,INFINITY,-INFINITY,NAN};
        for(NSUInteger i=0;i<sizeof(edges)/sizeof(*edges);i++) {
            [helper downloadProgress:edges[i]];
            PEqual(probe.text,[NSString stringWithFormat:@"%@: %.0f%%",prefix,FirstPackageProgressPercent(edges[i])],@"progress formatting edge values");
            PCheck(isnan(edges[i]) ? isnan(probe.value) : probe.value==edges[i] && signbit(probe.value)==signbit(edges[i]),@"progress value preserved at toast boundary");
        }
    }
    PSet(helper,@"_audioUrl",Remote(@"progress-audio"));PSet(helper,@"_videoID",@"progress-fixture");
    PSet(helper,@"_isAudioOnly",@NO);PSet(helper,@"_audioSize",@2048);
    [helper downloadAudioWithUrl:nil fileName:nil videoID:nil audioSize:0 duration:0];
    PEqual(probe.text,@"DownloadingAudio",@"second-phase audio label");
    PCheck([probe.route isEqual:@"update:animated:"] && !probe.animated && probe.value==0,@"audio phase resets progress without animation");
    [helper downloadAudioWithUrl:Remote(@"progress-audio") fileName:@"Audio" videoID:@"progress-fixture" audioSize:2048 duration:1000];
    PCheck([probe.route isEqual:@"show"] && probe.value==0,@"standalone audio displays new stoppable progress");
    [PresentationDownloads removeAllObjects];PClearToasts();
    printf("PASS Helper_first_package_progress: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}

static NSMutableArray<NSDictionary *> *conversionFileEvents;
static BOOL conversionMoveFails;
static id conversionFileManager;
static __weak YTLHelper *conversionHelper;
static BOOL conversionChangedID;
static NSUInteger conversionManagerReads;
@interface HelperConversionFiles : NSObject @end
@implementation HelperConversionFiles
- (BOOL)removeItemAtURL:(NSURL *)url error:(NSError **)error {
    [conversionFileEvents addObject:@{@"operation":@"remove",@"url":url}];
    if(!conversionChangedID && ([url.path containsString:@"/conversion-current/"] ||
                              [url.path containsString:@"/conversion-after-share/"])) {
        conversionChangedID=YES;PSet(conversionHelper,@"_videoID",@"conversion-after-remove");
    }
    return YES;
}
- (BOOL)moveItemAtURL:(NSURL *)source toURL:(NSURL *)destination error:(NSError **)error {
    [conversionFileEvents addObject:@{@"operation":@"move",@"source":source,@"url":destination}];
    if(conversionMoveFails && error)*error=[NSError errorWithDomain:@"fixture.move" code:1 userInfo:nil];
    return !conversionMoveFails;
}
@end
static id ConversionDefaultManager(id receiver,SEL selector) {
    (void)receiver;(void)selector;conversionManagerReads++;return conversionFileManager;
}

@interface HelperConversionProbe : YTLHelper
@property(copy) NSString *nextID;
@property(strong) NSURL *seenDestination;
@end
@implementation HelperConversionProbe
- (void)shareMedia:(NSURL *)url {
    self.seenDestination=url;
    if(self.nextID)PSet(self,@"_videoID",self.nextID);
}
@end
@interface HelperConversionToast : NSObject @end
@implementation HelperConversionToast
- (void)hide {}
@end

static void TestFirstPackageConversion(void) {
    NSUInteger before=PresentationAssertions;
    conversionFileManager=[HelperConversionFiles new];conversionFileEvents=[NSMutableArray new];
    for(NSUInteger audioOnly=0;audioOnly<2;audioOnly++) {
        for(NSUInteger outcome=0;outcome<3;outcome++) {
            HelperConversionProbe *helper=[HelperConversionProbe new];PSettle();
            PSet(helper,@"_toastView",[HelperConversionToast new]);
            PSet(helper,@"_videoID",@"conversion-original");PSet(helper,@"_title",@"Title");
            PSet(helper,@"_format",@"mp4");PSet(helper,@"_isVideoDownloaded",@YES);
            PSet(helper,@"_isAudioOnly",@(audioOnly));PSet(helper,@"_duration",@12);
            PSet(helper,@"_videoUrl",Remote(@"synthetic-video"));
            PresentationPostDownloadIndex=1;conversionMoveFails=outcome==1;
            Method method=class_getClassMethod(NSFileManager.class,@selector(defaultManager));
            IMP original=method_setImplementation(method,(IMP)ConversionDefaultManager);
            @try {
                [helper downloadDidFinish:[NSURL fileURLWithPath:@"/fixture/downloaded.m4a"] fileName:@"unused"];
                PCheck(PresentationConversions.count==1,@"one conversion callback scheduled");
                NSDictionary *record=PresentationConversions.lastObject;
                PEqual(record[@"operation"],audioOnly ? @"cut" : @"merge",@"conversion choice remains tied to scheduled phase");
                void (^completion)(NSURL *,NSError *)=record[@"completion"];
                [PresentationConversions removeAllObjects];[conversionFileEvents removeAllObjects];
                conversionHelper=helper;conversionChangedID=NO;conversionManagerReads=0;
                PSet(helper,@"_videoID",@"conversion-current");helper.nextID=@"conversion-after-share";
                NSURL *result=[NSURL fileURLWithPath:@"/fixture/converted.bin"];
                NSError *error=outcome==2 ? [NSError errorWithDomain:@"fixture.conversion" code:9 userInfo:nil] : nil;
                completion(result,error);
                if(outcome==2) {
                    PCheck(conversionFileEvents.count==1,@"converter error removes only partial output");
                    PEqual(conversionFileEvents[0][@"url"],result,@"converter error output identity");
                    PCheck(helper.seenDestination==nil,@"converter error never routes media");
                    PCheck(conversionManagerReads==1 && !conversionChangedID,@"error path has one file-manager lookup and no sidecar cleanup");
                } else {
                    NSArray *suffixes=audioOnly ? @[@"_a.m4a",@"_a.ytpmap"] : @[@"_v.mp4",@"_a.m4a",@"_a.ytpmap",@"_a.ytpmap"];
                    PCheck(conversionFileEvents.count==suffixes.count+1,@"move precedes each original cleanup call");
                    NSDictionary *move=conversionFileEvents[0];
                    NSString *destination=[@"conversion-original/Title" stringByAppendingString:audioOnly ? @".m4a" : @".mp4"];
                    PEqual(move[@"operation"],@"move",@"conversion first moves output");
                    PCheck([[move[@"url"] path] hasSuffix:destination],@"destination remains captured before helper state changes");
                    NSString *identifier=outcome==0 ? @"conversion-after-share" : @"conversion-current";
                    for(NSUInteger i=0;i<suffixes.count;i++) {
                        NSString *path=[NSString stringWithFormat:@"%@/%@%@",identifier,identifier,suffixes[i]];
                        PCheck([[conversionFileEvents[i+1][@"url"] path] hasSuffix:path],@"cleanup reads helper state after media routing");
                    }
                    PCheck((helper.seenDestination!=nil)==(outcome==0),@"move failure skips media routing");
                    PCheck(conversionChangedID,@"file removal mutation was observed after URLs were constructed");
                    PCheck(conversionManagerReads==suffixes.count+1,@"each cleanup removal gets a fresh default manager");
                }
            } @finally { method_setImplementation(method,original); }
            PClearToasts();
        }
    }
    conversionFileManager=nil;conversionFileEvents=nil;
    printf("PASS Helper_first_package_conversion: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}

void PRunHelpers(void) {
    extern void PRunHelperState(void);
    PRunHelperState();
    extern void PRunHelperImageFeedback(void);
    PRunHelperImageFeedback();
    extern void PRunHelperMediaFlow(void);
    PRunHelperMediaFlow();
    extern void PRunHelperAssets(void);
    PRunHelperAssets();
    extern void PRunHelperOrdering(void);
    PRunHelperOrdering();
    extern void PRunHelperConversionPaths(void);
    PRunHelperConversionPaths();
    extern void PRunHelperFinish(void);
    PRunHelperFinish();
    extern void PRunHelperStart(void);
    PRunHelperStart();
    extern void PRunHelperTerminal(void);
    PRunHelperTerminal();
    extern void PRunHelperInit(void);
    PRunHelperInit();
    extern void PRunHelperButtons(void);
    PRunHelperButtons();
    TestFirstPackageConversion();
    TestFirstPackageProgress();
    extern void PRunHelperImage(void);
    PRunHelperImage();
    extern void PRunHelperRendering(void);
    PRunHelperRendering();
    extern void PRunHelperMedia(void);
    PRunHelperMedia();
    TestTransformsAndFactories();PClearToasts();
    TestAudioPipeline();TestVideoRouting();TestFailuresAndOwnership();TestImageCallbacks();
    PCheck(PresentationConversions.count==0,@"all converter callbacks consumed");
    PCheck(PresentationPhotoChanges.count==0,@"all Photos callbacks consumed");
}
