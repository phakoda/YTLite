#import "YTPSpeedMaster.h"
#import "PlaybackPreferences.h"
#import "ControlsHost.h"
#import "ControlsNumbers.h"
#import "../Presentation/PlayerToast.h"
#import "../Presentation/ToastView.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSString+YTLite.h"
#include <float.h>

// Raw packaged double at 0x11ce3e0; also used before any deferred setter.
static double pendingRate = 1.0;
static double YTLReadPlayerRate(id<YTLControlsNode> player) {
    id<YTLControlsNode> video = [player activeVideo];
    return [video respondsToSelector:@selector(playbackRate)]
        ? (double)[video playbackRate] : (double)[[video activePlaybackRateModel] activeRate];
}
static void YTLNotifyRate(double rate) {
    [[NSNotificationCenter defaultCenter] postNotificationName:@"YTPSpeedDidChange" object:@(rate)];
}
static void YTLInstallRateModel(id<YTLControlsNode> video, double rate) {
    Class<YTLControlsRateModel> factory = (Class<YTLControlsRateModel>)NSClassFromString(@"YTActivePlaybackRateModel");
    [video setActivePlaybackRateModel:[[factory alloc] initWithRate:(float)rate]];
}
static NSInteger YTLClampRateIndex(NSInteger base, double delta, NSUInteger count) {
    // The original integer ADD wraps before its signed comparisons.
    NSInteger index = (NSInteger)((uint64_t)base + (uint64_t)YTLControlsInt64(delta));
    NSInteger last = (NSInteger)count - 1;
    if (index > last) index = last;
    return index < 0 ? 0 : index;
}

@implementation YTPSpeedMaster
// 0x223868 and singleton block 0x22391c.
+ (instancetype)sharedMaster {
    static YTPSpeedMaster *master;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ master = [[self alloc] init]; });
    return master;
}
// 0x2250cc. FRINTA at 0x2251c0 rounds accumulated steps to two decimals.
- (NSArray *)speedArray {
    if (_speedIndex == 2) return @[@0.25, @0.5, @0.75, @1.0, @1.25, @1.5, @1.75, @2.0, @3.0, @4.0, @5.0];
    NSMutableArray *rates = [NSMutableArray array];
    for (double rate = 0.25; rate <= 10.001; rate += 0.05)
        [rates addObject:@(round(rate * 100.0) / 100.0)];
    return rates;
}
// 0x22545c. Original values are narrowed through floatValue; ties keep first.
- (NSInteger)nearestIndexForRate:(double)rate {
    NSInteger nearest = 2;
    double distance = DBL_MAX;
    for (NSUInteger index = 0; index < _speedArray.count; index++) {
        double candidate = fabs((double)[_speedArray[index] floatValue] - rate);
        if (candidate < distance) { nearest = (NSInteger)index; distance = candidate; }
    }
    return nearest;
}
// 0x225900 / 0x225a20: instance operations use the gesture's overlay owner.
- (double)currentPlaybackRate {
    return YTLReadPlayerRate([(id<YTLControlsNode>)_controller parentViewController]);
}
- (void)setPlaybackRate:(double)rate {
    @synchronized (self) {
        id<YTLControlsNode> video = [[(id<YTLControlsNode>)_controller parentViewController] activeVideo];
        if ([video respondsToSelector:@selector(playbackRate)]) [video setPlaybackRate:(float)rate];
        else YTLInstallRateModel(video, rate);
        YTLNotifyRate(rate);
    }
}
// 0x2255cc / 0x225f20 / 0x22608c. The two nil-player defaults differ.
+ (id)getPlayerIfAvailable { return YTLControlsPlayer(); }
+ (double)currentPlaybackRate {
    id player = [self getPlayerIfAvailable];
    return player ? YTLReadPlayerRate(player) : 1.0;
}
+ (double)playbackRateForPlayer:(id)player {
    return YTLReadPlayerRate(player ?: [self getPlayerIfAvailable]);
}
// 0x226204 / 0x2265dc. The pending value is class-global, not per player.
+ (void)setPlaybackRate:(double)rate forPlayer:(id)player {
    id<YTLControlsNode> target = player ?: [self getPlayerIfAvailable];
    if (!target) return;
    YTLRememberPlaybackRate([YTLUserDefaults standardUserDefaults], rate);
    id<YTLControlsNode> video = [target activeVideo];
    if ([video respondsToSelector:@selector(playbackRate)]) {
        [video setPlaybackRate:(float)rate];
        YTLNotifyRate(rate);
    } else {
        pendingRate = rate;
        [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(_applyPendingRateForPlayer:) object:target];
        [self performSelector:@selector(_applyPendingRateForPlayer:) withObject:target afterDelay:0.05];
    }
}
+ (void)_applyPendingRateForPlayer:(id)player {
    double rate = pendingRate;
    YTLInstallRateModel([(id<YTLControlsNode>)player activeVideo], rate);
    YTLNotifyRate(rate);
}
// 0x223960, continuations verified in analysis-v3. The local fork intentionally
// omits the original anti-tamper exception when another view hides the toast;
// that presentation condition must not crash an otherwise legitimate gesture.
- (void)manageSpeedMaster:(UILongPressGestureRecognizer *)gesture playerOverlayVC:(id)controller {
    _controller = controller;
    _speedIndex = [YTLUserDefaults integerForKey:@"speedIndex"];
    _speedArray = [self speedArray];
    _minRate = 0.25;
    _maxRate = _speedIndex == 2 ? 5.0 : 10.0;
    _rateStep = 0.05;
    NSString *title = [@"Toast.PlaybackSpeed" ytl_localized];
    double preferred = [YTLUserDefaults floatForKey:@"playbackRate"];
    if (gesture.state == UIGestureRecognizerStateBegan) {
        _startLocation = [gesture locationInView:gesture.view];
        _rateBeforeSpeedmaster = [self currentPlaybackRate];
        _gestureBaseIndex = [self nearestIndexForRate:preferred];
        _gestureBaseRate = preferred;
        [self setPlaybackRate:preferred];
        [[PlayerToast sharedToast] showPlayerToastWithText:title value:preferred style:1
            isCompact:[YTLUserDefaults boolForKey:@"compactToast"]];
        return;
    }
    if (gesture.state == UIGestureRecognizerStateChanged && [YTLUserDefaults boolForKey:@"adjustByFinger"]) {
        double delta = _startLocation.y - [gesture locationInView:gesture.view].y;
        if (_speedIndex == 2) {
            NSInteger index = YTLClampRateIndex(_gestureBaseIndex, round(delta * (delta > 0.0 ? 0.02 : 0.06)), _speedArray.count);
            [self setPlaybackRate:(double)[_speedArray[(NSUInteger)index] floatValue]];
        } else {
            double rate = fma(delta, fabs(delta) < 40.0 ? 0.01 : 0.05, _gestureBaseRate);
            rate = _maxRate < rate ? _maxRate : rate;
            rate = _minRate < rate ? rate : _minRate;
            [self setPlaybackRate:_rateStep * round(rate / _rateStep)];
        }
        [[PlayerToast sharedToast] updateToastText:title value:[self currentPlaybackRate]];
        return;
    }
    // Preserve the second state/preference evaluation found at 0x2245xx.
    if (gesture.state == UIGestureRecognizerStateChanged && [YTLUserDefaults boolForKey:@"adjustByFinger"]) {
        double delta = (_startLocation.y - [gesture locationInView:gesture.view].y) / 30.0;
        NSInteger index = YTLClampRateIndex(_gestureBaseIndex, delta, _speedArray.count);
        double rate = (double)[_speedArray[(NSUInteger)index] floatValue];
        [self setPlaybackRate:rate];
        [[PlayerToast sharedToast] updateToastText:title value:rate];
        return;
    }
    if (gesture.state != UIGestureRecognizerStateEnded) return;
    if (![YTLUserDefaults boolForKey:@"preserveSpeed"]) {
        [self setPlaybackRate:_rateBeforeSpeedmaster];
        [[PlayerToast sharedToast] updateToastText:title value:_rateBeforeSpeedmaster];
    } else {
        YTLRememberPlaybackRate([YTLUserDefaults standardUserDefaults], [self currentPlaybackRate]);
        NSString *rateText = [NSString stringWithFormat:@"%@×", @((float)[self currentPlaybackRate])];
        NSString *message = [NSString stringWithFormat:[@"SpeedPreserved" ytl_localized], rateText];
        [[ToastView new] showProgressiveToastWithText:message duration:5.0
            actionTitle:[@"ResetSpeed" ytl_localized] actionCompletion:^{
                [self setPlaybackRate:self->_rateBeforeSpeedmaster];
                YTLRememberPlaybackRate([YTLUserDefaults standardUserDefaults], self->_rateBeforeSpeedmaster);
            }];
    }
    [[PlayerToast sharedToast] hideToast];
}
@end
