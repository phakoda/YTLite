#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Helpers/HelpersHost.h"
#import <objc/runtime.h>
#undef dispatch_time

// Instrument only the synthetic UIKit boundary. The complete production helper
// is compiled by verify_presentation_runtime.py without source substitution.
static BOOL mediaProbeEnabled, mediaNilPopover;
static NSUInteger mediaPopoverReads, mediaBoundsReads;
static NSMutableArray<NSString *> *mediaTrace;
static NSArray<UIPopoverPresentationController *> *mediaPopovers;
static IMP mediaOriginalPopover, mediaOriginalBounds;
static id MediaPopover(id receiver, SEL selector) {
    if (!mediaProbeEnabled) return ((id(*)(id,SEL))mediaOriginalPopover)(receiver,selector);
    [mediaTrace addObject:@"popover"];
    NSUInteger index=mediaPopoverReads++;
    return mediaNilPopover ? nil : mediaPopovers[MIN(index,3)];
}
static CGRect MediaBounds(id receiver, SEL selector) {
    if (!mediaProbeEnabled) return ((CGRect(*)(id,SEL))mediaOriginalBounds)(receiver,selector);
    [mediaTrace addObject:@"bounds"];
    return mediaBoundsReads++ == 0 ? CGRectMake(0,0,200,300) : CGRectMake(0,0,900,700);
}
static void MediaOnWorker(dispatch_block_t block) {
    dispatch_semaphore_t done=dispatch_semaphore_create(0);
    NSThread *thread=[[NSThread alloc] initWithBlock:^{
        @autoreleasepool { block(); }
        dispatch_semaphore_signal(done);
    }];
    [thread start];
    PCheck(dispatch_semaphore_wait(done,dispatch_time(DISPATCH_TIME_NOW,5*NSEC_PER_SEC))==0,
           @"helper worker returns synchronously");
}
@interface HelperMediaCleanupProbe : YTLHelper
@property(nonatomic) NSUInteger cleanupCalls;
@property(nonatomic) BOOL cleanupOnMain;
@end
@implementation HelperMediaCleanupProbe
- (void)cleanup { self.cleanupCalls++;self.cleanupOnMain=NSThread.isMainThread; }
@end
@interface HelperMediaActionProbe : YTLHelper
@property(nonatomic,strong) NSMutableArray *calls;
@end
@implementation HelperMediaActionProbe
- (void)saveMedia:(NSURL *)url { [self.calls addObject:@[@"save",url ?: NSNull.null]]; }
- (void)shareMedia:(NSURL *)url { [self.calls addObject:@[@"share",url ?: NSNull.null]]; }
@end

void PRunHelperMedia(void) {
    NSUInteger start=PresentationAssertions;
    UIViewController *presenter=UIApplication.sharedApplication.delegate.window.rootViewController;
    UIView *sourceView=presenter.view;
    HelperMediaCleanupProbe *helper=[HelperMediaCleanupProbe new];PSettle();
    NSURL *url=[NSURL fileURLWithPath:@"/fixture-only/share.mp4"];
    Method popover=class_getInstanceMethod(UIViewController.class,@selector(popoverPresentationController));
    Method bounds=class_getInstanceMethod(UIScreen.class,@selector(bounds));
    mediaOriginalPopover=method_setImplementation(popover,(IMP)MediaPopover);
    mediaOriginalBounds=method_setImplementation(bounds,(IMP)MediaBounds);
    mediaTrace=[NSMutableArray new];mediaPopovers=@[[UIPopoverPresentationController new],
        [UIPopoverPresentationController new],[UIPopoverPresentationController new],
        [UIPopoverPresentationController new]];
    mediaProbeEnabled=YES;mediaNilPopover=NO;mediaPopoverReads=mediaBoundsReads=0;
    [helper shareMedia:url];
    mediaProbeEnabled=NO;
    PEqual(mediaTrace,(@[@"popover",@"popover",@"bounds",@"bounds",@"popover",@"popover"]),
           @"original share getter sequence");
    PCheck(mediaPopovers[1].sourceView==sourceView,@"second popover receives source view");
    PNear(mediaPopovers[2].sourceRect.origin.x,100,@"share uses first screen width");
    PNear(mediaPopovers[2].sourceRect.origin.y,700,@"share uses second screen height");
    PCheck(mediaPopovers[3].permittedArrowDirections==UIPopoverArrowDirectionAny,
           @"fourth popover receives arrow directions");
    UIActivityViewController *activity=(id)presenter.presentedViewController;
    PEqual(activity.fixtureItems,@[url],@"share forwards one original URL");
    PEqual(activity.excludedActivityTypes,(@[UIActivityTypeAssignToContact,UIActivityTypePrint]),
           @"share preserves excluded activity order");
    activity.completionWithItemsHandler(nil,NO,nil,nil);
    PCheck(helper.cleanupCalls==1&&helper.cleanupOnMain,@"cancel completion directly invokes cleanup");
    MediaOnWorker(^{ activity.completionWithItemsHandler(nil,YES,nil,nil); });
    PCheck(helper.cleanupCalls==2&&!helper.cleanupOnMain,@"success completion preserves caller thread");
    activity.completionWithItemsHandler=nil;presenter.presentedViewController=nil;activity=nil;
    [mediaTrace removeAllObjects];mediaNilPopover=YES;mediaPopoverReads=mediaBoundsReads=0;
    mediaProbeEnabled=YES;[helper shareMedia:url];mediaProbeEnabled=NO;
    PEqual(mediaTrace,@[@"popover"],@"absent popover skips geometry lookups");
    activity=(id)presenter.presentedViewController;activity.completionWithItemsHandler=nil;
    presenter.presentedViewController=nil;activity=nil;
    method_setImplementation(popover,mediaOriginalPopover);method_setImplementation(bounds,mediaOriginalBounds);
    mediaPopovers=nil;mediaTrace=nil;

    NSUInteger pending=PresentationMainQueue.count;
    __block BOOL synchronous=NO,workerWasMain=YES;
    MediaOnWorker(^{
        workerWasMain=NSThread.isMainThread;[helper shareMedia:url];
        synchronous=presenter.presentedViewController!=nil;
    });
    PCheck(!workerWasMain&&synchronous,@"share presents before returning on caller's worker thread");
    PCheck(PresentationMainQueue.count==pending,@"share adds no main-queue hop");
    activity=(id)presenter.presentedViewController;activity.completionWithItemsHandler=nil;
    presenter.presentedViewController=nil;activity=nil;
    BOOL threw=NO;
    @try { [helper shareMedia:nil]; } @catch(NSException *exception) {
        threw=[exception.name isEqual:NSInvalidArgumentException];
    }
    PCheck(threw,@"nil share retains original one-element NSArray exception");

    HelperMediaActionProbe *actions=[HelperMediaActionProbe new];actions.calls=[NSMutableArray new];PSettle();
    NSUInteger sheets=PresentationEventsOfKind(@"host.sheet").count;
    MediaOnWorker(^{ [actions askForAction:nil]; });
    PCheck(PresentationEventsOfKind(@"host.sheet").count==sheets+1,@"nil action URL still presents sheet synchronously");
    NSDictionary *record=PLast(@"host.sheet");id sheet=record[@"sheet"];
    PCheck(record[@"presenter"]==presenter,@"action sheet uses delegate window root");
    PCheck(PGet(sheet,@"fixtureSource")==sourceView,@"action sheet anchors to root pivot view");
    NSArray *buttons=PGet(sheet,@"fixtureActions");
    PCheck(buttons.count==2,@"action sheet installs both original actions");
    for(id button in buttons) { dispatch_block_t handler=PGet(button,@"fixtureHandler");handler(); }
    PEqual(actions.calls,(@[@[@"save",NSNull.null],@[@"share",NSNull.null]]),@"actions retain and forward nil URL");
    [PresentationEvents removeAllObjects];record=nil;sheet=nil;buttons=nil;actions=nil;

    NSUInteger transactions=PresentationPhotoChanges.count;
    [helper saveMedia:nil];
    PCheck(PresentationPhotoChanges.count==transactions+1,@"nil save URL reaches original Photos boundary");
    // The URL is intentionally nil. Do not execute this synthetic transaction.
    [PresentationPhotoChanges removeLastObject];PClearToasts();
    fprintf(stdout,"PASS Helper_media_presentation_fidelity: %lu assertions\n",(unsigned long)(PresentationAssertions-start));
}
