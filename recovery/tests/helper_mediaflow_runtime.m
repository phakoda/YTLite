#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Helpers/HelpersHost.h"
#import <Photos/Photos.h>
#import <objc/runtime.h>

static NSMutableArray *mediaFlowEvents;
static __weak YTLHelper *mediaFlowHelper;
static __weak NSURL *mediaFlowURL;
static PHPhotoLibrary *mediaFlowLibrary;
static PHAssetCreationRequest *mediaFlowRequest;
static dispatch_block_t mediaFlowChanges;
static void (^mediaFlowCompletion)(BOOL,NSError *);
static IMP mediaFlowOldBundle,mediaFlowOldLocalized;

@interface HelperFirstMediaProbe : YTLHelper @end
@implementation HelperFirstMediaProbe
- (void)cleanup {
    PCheck(self==mediaFlowHelper,@"Photos success cleans up the captured helper");
    [mediaFlowEvents addObject:@"cleanup"];
}
- (void)shareMedia:(NSURL *)url {
    PCheck(self==mediaFlowHelper && url==mediaFlowURL,@"media sharing receives the captured URL and helper");
    [mediaFlowEvents addObject:@"share"];
}
@end
@interface HelperFirstActionProbe : HelperFirstMediaProbe @end
@implementation HelperFirstActionProbe
- (void)saveMedia:(NSURL *)url {
    PCheck(self==mediaFlowHelper && url==mediaFlowURL,@"save action receives the captured URL and helper");
    [mediaFlowEvents addObject:@"save"];
}
@end
static id MediaFlowLibrary(id receiver,SEL selector) {
    (void)receiver;(void)selector;[mediaFlowEvents addObject:@"library"];return mediaFlowLibrary;
}
static void MediaFlowChanges(id receiver,SEL selector,dispatch_block_t changes,void (^completion)(BOOL,NSError *)) {
    (void)selector;[mediaFlowEvents addObject:@"transaction"];
    PCheck(receiver==mediaFlowLibrary && changes!=nil && completion!=nil,@"save submits both callbacks to the selected Photos library");
    mediaFlowChanges=[changes copy];mediaFlowCompletion=[completion copy];
}
static id MediaFlowRequest(id receiver,SEL selector) {
    (void)receiver;(void)selector;[mediaFlowEvents addObject:@"request"];return mediaFlowRequest;
}
static void MediaFlowResource(id receiver,SEL selector,PHAssetResourceType type,NSURL *url,PHAssetResourceCreationOptions *options) {
    (void)selector;[mediaFlowEvents addObject:@"resource"];
    PCheck(receiver==mediaFlowRequest && type==2 && url==mediaFlowURL && options==nil,
        @"Photos changes forward video resource type, captured URL and nil options without a fallback");
}
static id MediaFlowBundle(id receiver,SEL selector) {
    [mediaFlowEvents addObject:@"bundle"];return ((id(*)(id,SEL))mediaFlowOldBundle)(receiver,selector);
}
static id MediaFlowLocalized(id receiver,SEL selector,NSString *key,NSString *value,NSString *table) {
    [mediaFlowEvents addObject:@"localized"];
    PCheck([key isEqual:@"Saved"] && value==nil && table==nil,@"Photos success uses the original Saved localization arguments");
    return ((id(*)(id,SEL,id,id,id))mediaFlowOldLocalized)(receiver,selector,key,value,table);
}
static void MediaFlowToast(id receiver,SEL selector,NSString *text,BOOL success) {
    (void)receiver;(void)selector;[mediaFlowEvents addObject:@"toast"];
    PCheck([text isEqual:@"Saved"] && success,@"Photos success forwards saved feedback after cleanup and localization");
}
static NSArray *MediaFlowResult(BOOL success) {
    return success ? @[@"cleanup",@"bundle",@"localized",@"toast"] : @[@"share"];
}

static void TestPhotoRouting(void) {
    HelperFirstMediaProbe *helper=[HelperFirstMediaProbe new];PSettle();mediaFlowHelper=helper;
    PHPhotoLibrary *library=[PHPhotoLibrary new];PHAssetCreationRequest *request=[PHAssetCreationRequest new];
    for(NSUInteger mode=0;mode<11;mode++) {
        BOOL success=mode!=0 && mode!=2 && mode!=4;
        NSError *error=(mode==2 || mode==3 || mode==4) ? [NSError errorWithDomain:@"fixture.photos" code:7 userInfo:nil] : nil;
        NSString *name=mode==8 ? @"video.M4A" : mode==9 ? @"audio.m4a" : mode==10 ? @"no-extension" : @"video.mp4";
        NSURL *url=(mode==4 || mode==5) ? nil : [NSURL fileURLWithPath:[@"/fixture-only/" stringByAppendingString:name]];
        mediaFlowURL=url;mediaFlowLibrary=mode==7 ? nil : library;mediaFlowRequest=mode==6 ? nil : request;
        mediaFlowChanges=nil;mediaFlowCompletion=nil;[mediaFlowEvents removeAllObjects];
        NSUInteger queued=PresentationMainQueue.count;
        [helper saveMedia:url];
        if(mode==9) {
            PEqual(mediaFlowEvents,@[@"share"],@"only the exact lowercase m4a extension takes the direct share branch");
            PCheck(mediaFlowChanges==nil && mediaFlowCompletion==nil,@"audio sharing creates no Photos callbacks");
        } else if(mode==7) {
            PEqual(mediaFlowEvents,@[@"library"],@"nil library does not create a replacement transaction or share fallback");
            PCheck(mediaFlowChanges==nil && mediaFlowCompletion==nil,@"nil library consumes no callbacks");
        } else {
            PEqual(mediaFlowEvents,(@[@"library",@"transaction"]),@"non-audio and nil URLs reach Photos without executing its callbacks inline");
            [mediaFlowEvents removeAllObjects];mediaFlowChanges();mediaFlowChanges=nil;
            PEqual(mediaFlowEvents,mode==6 ? @[@"request"] : @[@"request",@"resource"],
                @"changes obtain one creation request and forward nil results through Objective-C messaging");
            [mediaFlowEvents removeAllObjects];
            mediaFlowCompletion(success,error);mediaFlowCompletion=nil;
            PCheck(mediaFlowEvents.count==0 && PresentationMainQueue.count==queued+1,@"Photos completion defers all result handling to one main-queue callback");
            PSettle();
            PEqual(mediaFlowEvents,MediaFlowResult(success),@"Photos success flag alone selects cleanup/feedback or sharing, independently of NSError");
        }
        PCheck(PresentationMainQueue.count==queued,@"each save case leaves the synthetic main queue balanced");
    }
    mediaFlowHelper=nil;mediaFlowURL=nil;mediaFlowLibrary=library;mediaFlowRequest=request;
}

static void TestPhotoCaptureLifetime(void) {
    for(NSUInteger success=0;success<2;success++) {
        __weak YTLHelper *weakHelper;
        __weak NSURL *weakURL;
        __weak NSError *weakError;
        [mediaFlowEvents removeAllObjects];
        @autoreleasepool {
            HelperFirstMediaProbe *helper=[HelperFirstMediaProbe new];PSettle();
            NSURL *url=[[NSURL alloc] initFileURLWithPath:@"/fixture-only/captured.mp4"];
            weakHelper=helper;weakURL=url;mediaFlowHelper=helper;mediaFlowURL=url;
            [helper saveMedia:url];
        }
        PCheck(weakHelper!=nil && weakURL!=nil,@"copied Photos callbacks retain helper and URL after save returns");
        mediaFlowChanges=nil;[mediaFlowEvents removeAllObjects];
        @autoreleasepool {
            NSError *error=[[NSError alloc] initWithDomain:@"fixture.ignored.photos.error" code:11 userInfo:nil];
            weakError=error;mediaFlowCompletion(success!=0,error);mediaFlowCompletion=nil;
        }
        PCheck(weakError==nil,@"queued Photos result does not retain the ignored NSError");
        PCheck(weakHelper!=nil && weakURL!=nil,@"queued main callback retains helper and URL after outer Photos callback is released");
        PSettle();
        PEqual(mediaFlowEvents,MediaFlowResult(success!=0),@"queued callback still reaches the captured helper after external owners are gone");
        PCheck(weakHelper==nil && weakURL==nil,@"releasing completed callbacks ends helper and URL ownership");
    }
    mediaFlowHelper=nil;mediaFlowURL=nil;
}

static void TestActionCaptureLifetime(void) {
    for(NSUInteger nilURL=0;nilURL<2;nilURL++) {
        __weak YTLHelper *weakHelper;
        __weak NSURL *weakURL;
        NSMutableArray<dispatch_block_t> *handlers=[NSMutableArray new];
        [mediaFlowEvents removeAllObjects];
        @autoreleasepool {
            HelperFirstActionProbe *helper=[HelperFirstActionProbe new];PSettle();
            NSURL *url=nilURL ? nil : [[NSURL alloc] initFileURLWithPath:@"/fixture-only/action-capture.mp4"];
            mediaFlowHelper=helper;mediaFlowURL=url;weakHelper=helper;weakURL=url;
            [helper askForAction:url];
            NSArray *actions=PGet(PLast(@"host.sheet")[@"sheet"],@"fixtureActions");
            PCheck(actions.count==2,@"action sheet constructs the original pair of actions");
            PEqual(PGet(actions[0],@"fixtureTitle"),@"SaveToPhotos",@"first action uses the original save title");
            PEqual(PGet(actions[1],@"fixtureTitle"),@"Share",@"second action uses the original share title");
            for(id action in actions)[handlers addObject:[PGet(action,@"fixtureHandler") copy]];
            PresentationResetEvents();
        }
        PCheck(weakHelper!=nil && (nilURL || weakURL!=nil),@"copied action callbacks retain helper and nonnil URL after sheet owners are released");
        for(NSUInteger index=0;index<2;index++) {
            @autoreleasepool {
                dispatch_block_t callback=handlers.firstObject;
                [handlers removeObjectAtIndex:0];callback();
            }
            if(index==0)PCheck(weakHelper!=nil && (nilURL || weakURL!=nil),@"second action independently owns helper and URL after the first callback is released");
        }
        PEqual(mediaFlowEvents,(@[@"save",@"share"]),@"action callbacks preserve their original save/share routing");
        PCheck(weakHelper==nil && weakURL==nil,@"releasing both action callbacks ends their helper and URL ownership");
    }
    mediaFlowHelper=nil;mediaFlowURL=nil;
}

void PRunHelperMediaFlow(void) {
    NSUInteger before=PresentationAssertions;mediaFlowEvents=[NSMutableArray new];
    Method library=class_getClassMethod(PHPhotoLibrary.class,@selector(sharedPhotoLibrary));
    Method changes=class_getInstanceMethod(PHPhotoLibrary.class,@selector(performChanges:completionHandler:));
    Method request=class_getClassMethod(PHAssetCreationRequest.class,@selector(creationRequestForAsset));
    Method resource=class_getInstanceMethod(PHAssetCreationRequest.class,@selector(addResourceWithType:fileURL:options:));
    Method bundle=class_getClassMethod(NSBundle.class,NSSelectorFromString(@"ytl_defaultBundle"));
    Method localized=class_getInstanceMethod(NSBundle.class,@selector(localizedStringForKey:value:table:));
    Method toast=class_getClassMethod(ToastManager.class,@selector(showMessageWithText:isSuccess:));
    IMP oldLibrary=method_setImplementation(library,(IMP)MediaFlowLibrary);
    IMP oldChanges=method_setImplementation(changes,(IMP)MediaFlowChanges);
    IMP oldRequest=method_setImplementation(request,(IMP)MediaFlowRequest);
    IMP oldResource=method_setImplementation(resource,(IMP)MediaFlowResource);
    mediaFlowOldBundle=method_setImplementation(bundle,(IMP)MediaFlowBundle);
    mediaFlowOldLocalized=method_setImplementation(localized,(IMP)MediaFlowLocalized);
    IMP oldToast=method_setImplementation(toast,(IMP)MediaFlowToast);
    @try { TestPhotoRouting();TestPhotoCaptureLifetime(); }
    @finally {
        method_setImplementation(library,oldLibrary);method_setImplementation(changes,oldChanges);
        method_setImplementation(request,oldRequest);method_setImplementation(resource,oldResource);
        method_setImplementation(bundle,mediaFlowOldBundle);method_setImplementation(localized,mediaFlowOldLocalized);
        method_setImplementation(toast,oldToast);
        mediaFlowChanges=nil;mediaFlowCompletion=nil;mediaFlowLibrary=nil;mediaFlowRequest=nil;
        mediaFlowHelper=nil;mediaFlowURL=nil;
    }
    TestActionCaptureLifetime();mediaFlowEvents=nil;
    printf("PASS Helper_first_package_mediaflow: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
