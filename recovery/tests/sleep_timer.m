#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../source/SleepTimer/SleepTimerHost.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "../../Utils/NSString+YTLite.h"
#import <objc/runtime.h>
#import <math.h>

static NSMutableArray *queued, *delayed, *delays;
static dispatch_block_t tick;
static double rate = 1.0;
static NSDate *now;
static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { NSLog(@"FAIL line %d: %s", __LINE__, #__VA_ARGS__); exit(1); } } while (0)
void YTLSleepTestAsync(dispatch_queue_t queue, dispatch_block_t block) { CHECK(queue == dispatch_get_main_queue()); [queued addObject:[block copy]]; }
void YTLSleepTestAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block) { CHECK(queue == dispatch_get_main_queue()); [delays addObject:@(when)]; [delayed addObject:[block copy]]; }
void YTLSleepTestSetTimer(dispatch_source_t timer, dispatch_time_t start, uint64_t interval, uint64_t leeway) {
    CHECK(timer != nil && start == 0 && interval == 1000000000 && leeway == 100000000);
}
void YTLSleepTestSetHandler(dispatch_source_t timer, dispatch_block_t block) { CHECK(timer != nil); tick = block; }
dispatch_time_t YTLSleepTestTime(dispatch_time_t base, int64_t delta) { CHECK(base == DISPATCH_TIME_NOW); return (dispatch_time_t)delta; }
static void drain(void) { while (queued.count) { dispatch_block_t block = queued.firstObject; [queued removeObjectAtIndex:0]; block(); } }
static NSDate *fixedDate(id object, SEL selector) { return now; }
@implementation UIImage @end
@implementation UIColor
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a { UIColor *color = [self new]; color.components = @[@(r),@(g),@(b),@(a)]; return color; }
@end
@implementation UIView
- (instancetype)initWithFrame:(CGRect)frame { if ((self = [super init])) _frame = frame; return self; }
- (void)addGestureRecognizer:(UIGestureRecognizer *)gesture { if (!_gestures) _gestures = [NSMutableArray array]; [_gestures addObject:gesture]; }
@end
@implementation UILabel
- (void)sizeToFit { self.fits++; }
@end
@implementation UIViewController @end
@implementation UIWindow @end
@implementation UIApplication
+ (instancetype)sharedApplication { static UIApplication *app; if (!app) app = [self new]; return app; }
@end
@implementation UIGestureRecognizer
- (void)removeTarget:(id)target action:(SEL)action { if (self.target == target && self.action == action) { self.target = nil; self.action = NULL; } }
- (void)addTarget:(id)target action:(SEL)action { self.target = target; self.action = action; }
@end
@implementation UITapGestureRecognizer @end
@implementation UIDatePicker @end
@implementation NSTextAttachment @end
@implementation NSAttributedString (SleepTestAttachment)
+ (instancetype)attributedStringWithAttachment:(NSTextAttachment *)attachment {
    return [[self alloc] initWithString:@"\uFFFC" attributes:@{@"attachment": attachment}];
}
@end
@implementation NSString (SleepTestLocalization)
- (NSString *)ytl_localized { return self; }
@end
@implementation NSBundle (SleepTestImages)
+ (NSBundle *)ytl_defaultBundle { return NSBundle.mainBundle; }
- (UIImage *)imageWithName:(NSString *)name { CHECK([name isEqual:@"moon"]); return [UIImage new]; }
@end
@interface SleepNode : UIView
@property(nonatomic, strong) id responderRoot, appView, delegate, watchLayerView, watchCollectionView, watchViewController, playerViewController, slimStatusBarView, ancestor;
@property(nonatomic, strong) UIViewController *pivotBarViewController;
@property(nonatomic) double currentVideoTotalMediaTime, currentVideoMediaTime;
@property(nonatomic) float volume;
@property(nonatomic) NSUInteger paused, changed;
@property(nonatomic, strong) NSMutableArray *volumes;
@end
@implementation SleepNode
- (id)_viewControllerForAncestor { return self.ancestor; }
- (void)setVolume:(float)value { _volume = value; if (!_volumes) _volumes = [NSMutableArray array]; [_volumes addObject:@(value)]; }
- (void)pausePlayback { self.paused++; }
- (void)slimStatusBarDisplayStatusDidChange { self.changed++; }
@end
@interface YTAppViewControllerFixture : SleepNode @end
@implementation YTAppViewControllerFixture @end
@interface SleepBar : UIView
@property(nonatomic, strong) UITapGestureRecognizer *tapGestureRecognizer;
@property(nonatomic, strong) UILabel *statusLabel;
@property(nonatomic, strong) UIColor *backgroundColor;
@property(nonatomic) BOOL displayed, dismissing;
@end
@implementation SleepBar @end
@interface YTPSpeedMaster : NSObject @end
@implementation YTPSpeedMaster
+ (double)playbackRateForPlayer:(id)player { CHECK(player != nil); return rate; }
@end
static id lastAlert, lastSheet;
@interface YTAlertView : NSObject
@property(nonatomic, copy) NSString *title, *subtitle;
@property(nonatomic, strong) UIView *customContentView;
@property(nonatomic, strong) NSMutableArray *titles, *actions;
@property(nonatomic, copy) dispatch_block_t confirmation;
@property(nonatomic) BOOL shown;
@end
@implementation YTAlertView
+ (instancetype)dialog { YTAlertView *alert = [self new]; alert.titles = [NSMutableArray array]; alert.actions = [NSMutableArray array]; lastAlert = alert; return alert; }
+ (instancetype)infoDialog { return [self dialog]; }
+ (instancetype)confirmationDialogWithAction:(dispatch_block_t)action actionTitle:(NSString *)title {
    CHECK([title isEqual:@"SleepTimer.Start"]); YTAlertView *alert = [self dialog]; alert.confirmation = action; return alert;
}
- (void)addTitle:(NSString *)title withAction:(dispatch_block_t)action { [self.titles addObject:title]; [self.actions addObject:action ? [action copy] : NSNull.null]; }
- (void)show { self.shown = YES; }
@end
@interface YTActionSheetAction : NSObject
@property(nonatomic, copy) NSString *title, *subtitle;
@property(nonatomic, copy) void (^handler)(id);
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)title subtitle:(NSString *)subtitle iconImage:(UIImage *)image handler:(void (^)(id))handler {
    CHECK(image == nil); YTActionSheetAction *action = [self new]; action.title = title; action.subtitle = subtitle; action.handler = handler; return action;
}
@end
@interface YTDefaultSheetController : NSObject
@property(nonatomic, strong) NSMutableArray<YTActionSheetAction *> *actions;
@property(nonatomic, strong) UIView *sourceView;
@property(nonatomic, strong) UIViewController *presenter;
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent {
    CHECK(!message && !subMessage && !delegate && !parent); YTDefaultSheetController *sheet = [self new]; sheet.actions = [NSMutableArray array]; lastSheet = sheet; return sheet;
}
- (void)addAction:(id)action { [self.actions addObject:action]; }
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion { CHECK(animated && !completion); self.presenter = controller; }
@end
@interface ToastView : NSObject @end
@implementation ToastView
+ (UIWindow *)toastWindow { static UIWindow *window; if (!window) { window = [UIWindow new]; window.rootViewController = [UIViewController new]; } return window; }
@end
@interface RecordingTimer : YTPSleepTimer
@property(nonatomic) double fadeDuration, stopDelay;
@property(nonatomic) NSUInteger fadeCalls, stopCalls;
@end
@implementation RecordingTimer
- (void)stopWithFadeDuration:(double)duration stopAfter:(double)delay { self.fadeDuration = duration; self.stopDelay = delay; self.fadeCalls++; }
- (void)stop { self.stopCalls++; }
@end
// Original once block 0x2114b8 invokes alloc/init on its captured receiver.
static NSUInteger factoryNewCalls,factoryInitCalls;
@interface FactorySleepTimer : YTPSleepTimer @end
@implementation FactorySleepTimer
+ (instancetype)new { factoryNewCalls++; return [super new]; }
- (instancetype)init { factoryInitCalls++; return [super init]; }
@end
@interface OtherFactorySleepTimer : YTPSleepTimer @end
@implementation OtherFactorySleepTimer @end
int main(void) { @autoreleasepool {
    queued = [NSMutableArray array]; delayed = [NSMutableArray array]; delays = [NSMutableArray array];
    now = [NSDate dateWithTimeIntervalSince1970:1704112496]; // 2024-01-01 12:34:56 UTC.
    [NSTimeZone setDefaultTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    Method dateMethod = class_getClassMethod(NSDate.class, @selector(date)); IMP oldDate = method_setImplementation(dateMethod, (IMP)fixedDate);
    YTPSleepTimer *timer = FactorySleepTimer.sharedTimer;
    CHECK(object_getClass(timer) == FactorySleepTimer.class);
    CHECK(factoryNewCalls == 0 && factoryInitCalls == 1);
    CHECK(OtherFactorySleepTimer.sharedTimer == timer);
    CHECK(timer == YTPSleepTimer.sharedTimer && !timer.isRunning && timer.remainingSeconds == 0);
    CHECK(timer.timerQueue == timer.timerQueue && !strcmp(dispatch_queue_get_label(timer.timerQueue), "com.dvn.ytpsleeptimer.queue"));
    SleepNode *delegate = [SleepNode new], *app = [SleepNode new], *watch = [SleepNode new], *player = [SleepNode new], *collection = [SleepNode new], *watchVC = [SleepNode new];
    YTAppViewControllerFixture *root = [YTAppViewControllerFixture new];
    UIApplication.sharedApplication.delegate = delegate; delegate.responderRoot = root; root.appView = app;
    app.watchLayerView = watch; app.delegate = player; watch.ancestor = watchVC; watchVC.playerViewController = player;
    watch.watchViewController = watchVC; watch.watchCollectionView = collection;
    root.pivotBarViewController = [UIViewController new]; root.pivotBarViewController.view = [UIView new];
    SleepBar *global = [SleepBar new], *local = [SleepBar new]; global.statusLabel = [UILabel new]; local.statusLabel = [UILabel new];
    app.slimStatusBarView = global; collection.slimStatusBarView = local;
    CHECK([timer getPlayerIfAvailable] == player && [timer globalSlimBar] == global && [timer playerSlimBar] == local);
    CHECK([[timer barsForStyle:0] isEqual:@[local,global]] && [[timer barsForStyle:1] isEqual:@[local]]);
    CHECK([timer slimBarForStyle:0] == global && [timer slimBarForStyle:1] == local);
    player.currentVideoTotalMediaTime = 120; player.currentVideoMediaTime = 20; rate = 2;
    CHECK(timer.remainingSecondsForCurrentVideo == 50);
    for (NSNumber *invalid in @[@0, @(-1), @(NAN), @(INFINITY), @(-INFINITY)]) { rate = invalid.doubleValue; CHECK(timer.remainingSecondsForCurrentVideo == 100); }
    rate = 0.5; CHECK(timer.remainingSecondsForCurrentVideo == 200);
    player.currentVideoMediaTime = 150; CHECK(timer.remainingSecondsForCurrentVideo == 0);
    for (NSNumber *invalid in @[@0, @(-1), @(NAN), @(INFINITY)]) { player.currentVideoTotalMediaTime = invalid.doubleValue; CHECK(timer.remainingSecondsForCurrentVideo == 0); }
    player.currentVideoTotalMediaTime = 120; player.currentVideoMediaTime = NAN; CHECK(timer.remainingSecondsForCurrentVideo == 0);
    player.currentVideoMediaTime = 20; rate = 1;
    [timer startForSeconds:0]; [timer startForSeconds:-10]; [timer startForSeconds:NAN]; CHECK(!timer.isRunning);
    [timer startForSeconds:100]; CHECK(timer.isRunning && timer.remainingSeconds == 100); drain();
    CHECK(global.displayed && local.displayed && !global.dismissing && !local.dismissing);
    CHECK([global.backgroundColor.components isEqual:@[@0.22,@0.17,@0.45,@1]]);
    CHECK(global.tapGestureRecognizer.numberOfTapsRequired == 1 && global.tapGestureRecognizer.target == timer);
    CHECK(root.changed > 0 && watchVC.changed > 0 && player.volume == 1);
    CHECK([global.statusLabel.attributedText.string hasPrefix:@"\uFFFC "]);
    NSTextAttachment *attachment = [global.statusLabel.attributedText attribute:@"attachment" atIndex:0 effectiveRange:NULL];
    CHECK(CGRectEqualToRect(attachment.bounds, CGRectMake(0,-2,14,14)));
    now = [now dateByAddingTimeInterval:1.25]; tick(); drain();
    CHECK(local.statusLabel.fits == 1 && [local.statusLabel.attributedText.string hasSuffix:[timer formattedTime:98]]);
    [timer cancelIfPlayerClosed]; CHECK(timer.isRunning); // Fixed deadline survives closing playback.
    [timer cancel]; CHECK(!timer.isRunning && timer.remainingSeconds == 0); drain(); CHECK(!global.displayed && !global.tapGestureRecognizer && player.paused == 0);
    // End-of-video countdown follows current playback time/rate and cancels on close.
    [timer startForEndOfVideo]; CHECK(timer.isRunning && timer.remainingSeconds == 100); drain();
    rate = 2; CHECK(timer.remainingSeconds == 50);
    watchVC.playerViewController = nil; tick(); drain(); CHECK(!timer.isRunning);
    [timer startForEndOfVideo]; CHECK(!timer.isRunning); watchVC.playerViewController = player;
    [timer startForEndOfVideo]; drain(); [timer cancelIfPlayerClosed]; CHECK(!timer.isRunning); drain();
    for (NSNumber *remaining in @[@(-1), @0, @1.2, @(NAN), @1.21, @4.99, @5, @10]) {
        RecordingTimer *probe = [RecordingTimer new]; double value = remaining.doubleValue;
        [probe stopWithFadeIfNeeded:value]; [probe stopWithFadeIfNeeded:value];
        if (!(value > 1.2)) CHECK(probe.stopCalls == 1 && probe.fadeCalls == 0);
        else if (value < 5) CHECK(probe.fadeCalls == 1 && probe.fadeDuration == 1 && probe.stopDelay == 1);
        else CHECK(probe.fadeCalls == 1 && probe.fadeDuration == 5 && probe.stopDelay == value-1);
    }
    rate = 1; [timer startForSeconds:100]; drain();
    [timer stopWithFadeDuration:5 stopAfter:9]; CHECK(delayed.count == 12 && delays.count == 12);
    for (NSUInteger index=0; index<11; index++) {
        CHECK(fabs([delays[index] doubleValue] - (5.0/10.0)*index*1e9) < 1);
        ((dispatch_block_t)delayed[index])(); CHECK(fabs(player.volume-(1.0-(double)index/10.0)) < 1e-6);
    }
    CHECK([delays.lastObject unsignedLongLongValue] == 9000000000);
    ((dispatch_block_t)delayed.lastObject)(); CHECK(!timer.isRunning && player.paused == 1);
    CHECK([((YTAlertView *)lastAlert).subtitle isEqual:@"SleepTimer.StopMessage"]); drain(); CHECK(player.volume == 1);
    NSUInteger volumeCount = player.volumes.count; ((dispatch_block_t)delayed[5])(); CHECK(player.volumes.count == volumeCount);
    // Preserve original no-bars early return; cancel remains available.
    app.slimStatusBarView = nil; collection.slimStatusBarView = nil;
    [timer startForSeconds:100]; drain(); [timer stop]; CHECK(timer.isRunning && player.paused == 1); [timer cancel]; drain();
    app.slimStatusBarView = global; collection.slimStatusBarView = local;
    [timer showOptions:nil]; YTDefaultSheetController *sheet = lastSheet;
    CHECK(sheet.actions.count == 8 && sheet.sourceView == root.pivotBarViewController.view && sheet.presenter == [ToastView toastWindow].rootViewController);
    sheet.actions.firstObject.handler(nil); CHECK(timer.isRunning && timer.remainingSeconds == 600); drain();
    [timer showOptions:global]; sheet = lastSheet; CHECK(sheet.actions.count == 9 && [sheet.actions.firstObject.title isEqual:@"SleepTimer.TurnOff"]);
    sheet.actions.firstObject.handler(nil); drain(); CHECK(!timer.isRunning);
    UITapGestureRecognizer *tap = [UITapGestureRecognizer new]; tap.state = UIGestureRecognizerStateEnded;
    [timer onSlimBarTap:tap]; YTAlertView *alert = lastAlert; CHECK(alert.shown && alert.actions.count == 3 && alert.actions.lastObject == NSNull.null);
    ((dispatch_block_t)alert.actions[1])(); CHECK(lastSheet != sheet);
    [timer showTimeSelector]; alert = lastAlert; UIDatePicker *datePicker = (id)alert.customContentView;
    CHECK(CGRectEqualToRect(datePicker.frame, CGRectMake(0,0,270,160)) && datePicker.preferredDatePickerStyle == UIDatePickerStyleWheels && datePicker.datePickerMode == UIDatePickerModeTime);
    now = [NSDate dateWithTimeIntervalSince1970:1704112496];
    datePicker.date = [NSDate dateWithTimeIntervalSince1970:1704114000]; // 13:00 UTC.
    CHECK([timer secondsForDate:datePicker.date] == 1504);
    CHECK([timer secondsForDate:now] == 86344);
    alert.confirmation(); CHECK(timer.remainingSeconds == 1504); drain(); [timer cancel]; drain();
    // Non-YouTube responder roots do not expose player/bars/pause.
    delegate.responderRoot = [SleepNode new]; CHECK(![timer getPlayerIfAvailable] && ![timer globalSlimBar] && ![timer playerSlimBar] && ![timer pausePlayback]);
    method_setImplementation(dateMethod, oldDate);
    NSLog(@"PASS: %lu sleep timer assertions, captured scheduling, real dispatch source cancellation, host UI contracts", (unsigned long)checks);
} return 0; }
