#import "YTPSleepTimer.h"
#import "SleepTimerHost.h"
#import "../Controls/ControlsNumbers.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import "../../../Utils/NSString+YTLite.h"
#import <objc/runtime.h>

static NSDateComponentsFormatter *YTLSleepFormatter(NSDateComponentsFormatterUnitsStyle style) {
    NSDateComponentsFormatter *formatter = [NSDateComponentsFormatter new];
    formatter.unitsStyle = style;
    formatter.allowedUnits = NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond;
    formatter.maximumUnitCount = 2;
    formatter.zeroFormattingBehavior = NSDateComponentsFormatterZeroFormattingBehaviorDropAll;
    return formatter;
}
static id YTLSleepAction(NSString *title, NSString *subtitle, void (^handler)(id)) {
    return [(Class<YTLSleepAction>)NSClassFromString(@"YTActionSheetAction") actionWithTitle:title subtitle:subtitle iconImage:nil handler:handler];
}
@implementation YTPSleepTimer
// 0x211404 / 0x2114b8.
+ (instancetype)sharedTimer {
    static YTPSleepTimer *timer;
    static dispatch_once_t once;
    // The original uses objc_alloc_init on the receiver, bypassing +new.
    dispatch_once(&once, ^{ timer = [[self alloc] init]; });
    return timer;
}
// 0x2114fc / 0x2117cc.
- (dispatch_queue_t)timerQueue {
    if (!_timerQueue) _timerQueue = dispatch_queue_create("com.dvn.ytpsleeptimer.queue", DISPATCH_QUEUE_SERIAL);
    return _timerQueue;
}
- (BOOL)isRunning { return _timer && !dispatch_source_testcancel(_timer); }
// 0x211844, actions 0x212b78/0x212bb0/0x212bf0/0x212c28.
- (void)showOptions:(UIView *)source {
    if (!source) {
        id<YTLSleepNode> root = YTLSleepRoot();
        if ([root respondsToSelector:@selector(pivotBarViewController)]) source = [root pivotBarViewController].view;
    }
    id<YTLSleepSheet> sheet = [(Class<YTLSleepSheet>)NSClassFromString(@"YTDefaultSheetController")
        sheetControllerWithMessage:nil subMessage:nil delegate:nil parentResponder:nil];
    if ([self isRunning]) [sheet addAction:YTLSleepAction([@"SleepTimer.TurnOff" ytl_localized], nil, ^(id action) { [self cancel]; })];
    NSDateComponentsFormatter *formatter = YTLSleepFormatter(NSDateComponentsFormatterUnitsStyleFull);
    for (NSNumber *minutes in @[@10, @15, @20, @30, @45, @60]) {
        double seconds = minutes.integerValue * 60.0;
        [sheet addAction:YTLSleepAction([formatter stringFromTimeInterval:seconds], nil, ^(id action) { [self startForSeconds:seconds]; })];
    }
    if ([self getPlayerIfAvailable]) [sheet addAction:YTLSleepAction([@"SleepTimer.EndOfVideo" ytl_localized],
        [formatter stringFromTimeInterval:[self remainingSecondsForCurrentVideo]], ^(id action) { [self startForEndOfVideo]; })];
    [sheet addAction:YTLSleepAction([@"SleepTimer.EndAt" ytl_localized], [@"SleepTimer.SelectTime" ytl_localized], ^(id action) { [self showTimeSelector]; })];
    [sheet setSourceView:source];
    UIWindow *window = [(Class<YTLSleepToastWindow>)NSClassFromString(@"ToastView") toastWindow];
    [sheet presentFromViewController:window.rootViewController animated:YES completion:nil];
}
// 0x212c38 / callback 0x213194.
- (void)showTimeSelector {
    UIDatePicker *picker = [[UIDatePicker alloc] initWithFrame:CGRectMake(0, 0, 270, 160)];
    picker.datePickerMode = UIDatePickerModeTime;
    picker.preferredDatePickerStyle = UIDatePickerStyleWheels;
    picker.locale = NSLocale.currentLocale;
    id<YTLSleepAlert> alert = [(Class<YTLSleepAlert>)NSClassFromString(@"YTAlertView") confirmationDialogWithAction:^{
        [self startForSeconds:[self secondsForDate:picker.date]];
    } actionTitle:[@"SleepTimer.Start" ytl_localized]];
    [alert setTitle:[@"SleepTimer.SelectTime" ytl_localized]];
    [alert setCustomContentView:picker];
    [alert show];
}
// 0x21320c / 0x213300. Both modes use style zero (both bars).
- (void)startForSeconds:(double)seconds {
    if (!(seconds > 0.0)) return;
    [self cancel]; _mode = 1; _timerStyle = 0;
    _endTimestamp = NSDate.date.timeIntervalSince1970 + seconds;
    [self startTimer];
}
- (void)startForEndOfVideo {
    if (![self getPlayerIfAvailable]) return;
    [self cancel]; _mode = 2; _timerStyle = 0;
    [self startTimer];
}
// 0x2133d4 and blocks 0x213554..0x213ab0.
- (void)startTimer {
    double initial = [self remainingSeconds];
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showSlimBarWithTitle:[self formattedTime:initial] image:[NSBundle.ytl_defaultBundle imageWithName:@"moon"]
            color:[UIColor colorWithRed:0.22 green:0.17 blue:0.45 alpha:1.0] style:self->_timerStyle];
    });
    _timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, [self timerQueue]);
    dispatch_source_set_timer(_timer, dispatch_time(DISPATCH_TIME_NOW, 0), NSEC_PER_SEC, NSEC_PER_SEC / 10);
    __weak YTPSleepTimer *weakSelf = self;
    dispatch_source_set_event_handler(_timer, ^{
        YTPSleepTimer *timer = weakSelf;
        if (!timer) return;
        if (timer->_mode == 2 && ![timer getPlayerIfAvailable]) {
            dispatch_async(dispatch_get_main_queue(), ^{ [timer cancel]; });
            return;
        }
        double remaining = [timer remainingSeconds];
        dispatch_async(dispatch_get_main_queue(), ^{
            if (timer->_timer) [timer updateSlimBarTitle:[timer formattedTime:(double)YTLControlsInt64(remaining)] style:timer->_timerStyle];
        });
        if (remaining <= 10.0) dispatch_async(dispatch_get_main_queue(), ^{ [timer stopWithFadeIfNeeded:remaining]; });
    });
    dispatch_resume(_timer);
}
// 0x213ac8: the short/immediate cutoff is 1.2 seconds, not one second.
- (void)stopWithFadeIfNeeded:(double)remaining {
    if (_didStartFade) return;
    _didStartFade = YES;
    if (!(remaining > 1.2)) [self stop];
    else if (remaining < 5.0) [self stopWithFadeDuration:1.0 stopAfter:1.0];
    else [self stopWithFadeDuration:5.0 stopAfter:remaining - 1.0];
}
// 0x213c18, callbacks 0x213e40/0x213f44. Eleven volume steps, including 1 and 0.
- (void)stopWithFadeDuration:(double)duration stopAfter:(double)delay {
    id<YTLSleepNode> player = [self getPlayerIfAvailable];
    if (!player) { [self stop]; return; }
    [player setVolume:1.0f];
    for (NSInteger step = 0; step <= 10; step++) {
        double volume = 1.0 - (double)step / 10.0;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, YTLControlsInt64((duration / 10.0) * step * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            if (self->_timer) [(id<YTLSleepNode>)[self getPlayerIfAvailable] setVolume:(float)volume];
        });
    }
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, YTLControlsInt64(delay * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (self->_timer) [self stop];
    });
}
// 0x213fd0..0x21409c.
- (void)stop { [self hideSlimBarWithStyle:0]; }
- (void)cancel { [self finishTimerAndCleanup]; }
- (void)cancelIfPlayerClosed { if (_mode == 2) [self cancel]; }
- (double)remainingSeconds {
    if (_mode == 1) return _endTimestamp - NSDate.date.timeIntervalSince1970;
    if (_mode == 2) return [self remainingSecondsForCurrentVideo];
    return 0.0;
}
// 0x214200; the unresolved decompiler tail is checked against 0x214298..0x2143d4.
- (double)remainingSecondsForCurrentVideo {
    id<YTLSleepNode> player = [self getPlayerIfAvailable];
    if (!player) return 0.0;
    double total = [player currentVideoTotalMediaTime], current = [player currentVideoMediaTime];
    if (!isfinite(total) || !isfinite(current) || total <= 0.0) return 0.0;
    double rate = [(Class<YTLSleepSpeed>)NSClassFromString(@"YTPSpeedMaster") playbackRateForPlayer:player];
    if (!isfinite(rate) || rate <= 0.0) rate = 1.0;
    return fmax(total - current, 0.0) / rate;
}
// 0x2143f8: elapsed targets add exactly 86400 seconds, including across DST.
- (double)secondsForDate:(NSDate *)date {
    NSCalendar *calendar = NSCalendar.currentCalendar;
    NSDate *now = NSDate.date;
    NSDateComponents *time = [calendar components:NSCalendarUnitHour | NSCalendarUnitMinute fromDate:date];
    NSDateComponents *day = [calendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:now];
    day.hour = time.hour; day.minute = time.minute; day.second = 0;
    NSDate *target = [calendar dateFromComponents:day];
    if ([target timeIntervalSinceDate:now] <= 0.0) target = [target dateByAddingTimeInterval:86400.0];
    return [target timeIntervalSinceDate:now];
}
// 0x21462c / singleton formatter 0x2146cc.
- (NSString *)formattedTime:(double)seconds {
    static NSDateComponentsFormatter *formatter;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ formatter = YTLSleepFormatter(NSDateComponentsFormatterUnitsStyleShort); });
    return [formatter stringFromTimeInterval:seconds];
}
// Host traversal methods 0x214758..0x2151c8.
- (id)getPlayerIfAvailable { return [[[[YTLSleepAppRoot() appView] watchLayerView] _viewControllerForAncestor] playerViewController]; }
- (id)globalSlimBar { return [[YTLSleepAppRoot() appView] slimStatusBarView]; }
- (id)playerSlimBar { return [[[[YTLSleepAppRoot() appView] watchLayerView] watchCollectionView] slimStatusBarView]; }
- (void)globalSlimBarVisibilityChange {
    id<YTLSleepNode> root = YTLSleepRoot();
    if ([root respondsToSelector:@selector(slimStatusBarDisplayStatusDidChange)]) [root slimStatusBarDisplayStatusDidChange];
}
- (void)playerSlimBarVisibilityChange {
    id<YTLSleepNode> watch = [[[YTLSleepAppRoot() appView] watchLayerView] watchViewController];
    if ([watch respondsToSelector:@selector(slimStatusBarDisplayStatusDidChange)]) [watch slimStatusBarDisplayStatusDidChange];
}
// 0x215554 / 0x21558c: style one uses player only; other styles include both.
- (id)slimBarForStyle:(NSUInteger)style { return style == 1 ? [self playerSlimBar] : [self globalSlimBar]; }
- (NSArray *)barsForStyle:(NSUInteger)style {
    NSMutableArray *bars = [NSMutableArray array];
    id player = [self playerSlimBar], global = [self globalSlimBar];
    if (player) [bars addObject:player];
    if (style != 1 && global) [bars addObject:global];
    return bars;
}
// 0x215718 / 0x2159b8.
- (NSAttributedString *)attributedTitle:(NSString *)title image:(UIImage *)image {
    if (!image) return [[NSAttributedString alloc] initWithString:title ?: @""];
    NSMutableAttributedString *text = [NSMutableAttributedString new];
    NSTextAttachment *attachment = [NSTextAttachment new]; attachment.image = image;
    attachment.bounds = CGRectMake(0, -2, 14, 14);
    [text appendAttributedString:[NSAttributedString attributedStringWithAttachment:attachment]];
    [text appendAttributedString:[[NSAttributedString alloc] initWithString:@" "]];
    [text appendAttributedString:[[NSAttributedString alloc] initWithString:title ?: @""]];
    return text;
}
- (void)applyTitle:(NSString *)title image:(UIImage *)image color:(UIColor *)color toBar:(id<YTLSleepNode>)bar {
    if (!bar) return;
    bar.statusLabel.attributedText = [self attributedTitle:title image:image];
    [bar setBackgroundColor:color]; [bar setDisplayed:YES]; [bar setDismissing:NO];
    _icon = image;
}
// 0x215b20 / 0x215fe8. The original always allocates a new recognizer and clears
// the private ivar during cleanup; it does not remove old recognizers from view.
- (void)attachTapHandlerToBar:(UIView *)bar {
    if (!bar || !class_getInstanceVariable(bar.class, "_tapGestureRecognizer")) return;
    [bar valueForKey:@"_tapGestureRecognizer"];
    UITapGestureRecognizer *tap = [UITapGestureRecognizer new];
    tap.numberOfTapsRequired = 1; bar.userInteractionEnabled = YES;
    [bar addGestureRecognizer:tap]; [bar setValue:tap forKey:@"_tapGestureRecognizer"];
    [tap removeTarget:self action:@selector(onSlimBarTap:)];
    [tap addTarget:self action:@selector(onSlimBarTap:)];
}
- (void)removeTapHandlerOnBar:(UIView *)bar {
    if (bar && class_getInstanceVariable(bar.class, "_tapGestureRecognizer")) [bar setValue:nil forKey:@"_tapGestureRecognizer"];
}
// 0x2163fc / 0x216d18 / 0x216d50.
- (void)onSlimBarTap:(UITapGestureRecognizer *)gesture {
    if (gesture.state != UIGestureRecognizerStateEnded) return;
    id<YTLSleepAlert> alert = [(Class<YTLSleepAlert>)NSClassFromString(@"YTAlertView") dialog];
    [alert setTitle:[@"SleepTimer" ytl_localized]]; [alert setSubtitle:[@"SleepTimer.Message" ytl_localized]];
    [alert addTitle:[@"SleepTimer.TurnOff" ytl_localized] withAction:^{ [self cancel]; }];
    [alert addTitle:[@"SleepTimer.SelectNewTime" ytl_localized] withAction:^{ [self showOptions:nil]; }];
    [alert addTitle:[@"SleepTimer.Dismiss" ytl_localized] withAction:nil]; [alert show];
}
// 0x216d8c..0x217198.
- (void)slimBarVisibilityChange:(NSUInteger)style {
    if (style != 1) [self globalSlimBarVisibilityChange];
    [self playerSlimBarVisibilityChange];
}
- (void)showSlimBarWithTitle:(NSString *)title image:(UIImage *)image color:(UIColor *)color style:(NSUInteger)style {
    [self cleanup];
    if (!color) color = [UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:1.0];
    for (id bar in [self barsForStyle:style]) {
        [self applyTitle:title image:image color:color toBar:bar]; [self attachTapHandlerToBar:bar];
    }
    [self slimBarVisibilityChange:style];
}
- (void)updateSlimBarTitle:(NSString *)title style:(NSUInteger)style {
    for (id<YTLSleepNode> bar in [self barsForStyle:style]) {
        bar.statusLabel.attributedText = [self attributedTitle:title image:_icon]; [bar.statusLabel sizeToFit];
    }
    [self slimBarVisibilityChange:style];
}
// 0x217570. With no bars the binary returns without stopping or pausing.
- (void)hideSlimBarWithStyle:(NSUInteger)style {
    NSArray *bars = [self barsForStyle:style];
    if (!bars.count) return;
    for (id<YTLSleepNode> bar in bars) { [bar setDisplayed:NO]; [bar setDismissing:YES]; }
    [self slimBarVisibilityChange:style]; [self finishTimerAndCleanup];
    if ([self pausePlayback]) {
        id<YTLSleepAlert> alert = [(Class<YTLSleepAlert>)NSClassFromString(@"YTAlertView") infoDialog];
        [alert setTitle:[@"SleepTimer" ytl_localized]]; [alert setSubtitle:[@"SleepTimer.StopMessage" ytl_localized]]; [alert show];
    }
}
// 0x217cfc / 0x218070 / 0x2181a8.
- (BOOL)pausePlayback {
    id<YTLSleepNode> player = [[YTLSleepAppRoot() appView] delegate];
    if (![player respondsToSelector:@selector(pausePlayback)]) return NO;
    [player pausePlayback]; return YES;
}
- (void)finishTimerAndCleanup {
    _mode = 0; _didStartFade = NO;
    if (_timer) { dispatch_source_t timer = _timer; _timer = nil; dispatch_source_cancel(timer); }
    dispatch_async(dispatch_get_main_queue(), ^{ [self cleanup]; });
}
- (void)cleanup {
    id<YTLSleepNode> global = [self globalSlimBar], player = [self playerSlimBar];
    if (global) { [global setDisplayed:NO]; [global setDismissing:YES]; [self globalSlimBarVisibilityChange]; [self removeTapHandlerOnBar:(id)global]; }
    if (player) { [player setDisplayed:NO]; [player setDismissing:YES]; [self playerSlimBarVisibilityChange]; [self removeTapHandlerOnBar:(id)player]; }
    [(id<YTLSleepNode>)[self getPlayerIfAvailable] setVolume:1.0f];
}
@end
