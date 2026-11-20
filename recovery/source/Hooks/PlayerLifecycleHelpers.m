#import "PlayerLifecycleHelpers.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Controls/YTPSpeedMaster.h"
#import <objc/runtime.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

BOOL canRememberLoopMode;
@protocol YTLPlayerEndTimeBar <NSObject>
- (UILabel *)durationLabel;
- (void)setEndTimeString:(NSString *)value;
@end
@protocol YTLPlayerEndTimeOverlay <NSObject>
- (id<YTLPlayerEndTimeBar>)playerBar;
@end
@protocol YTLPlayerEndTimeView <NSObject>
- (id)overlayView;
@end
// Match ARM64 FCVTAS for finite, out-of-range and NaN inputs without C cast UB.
static int64_t PlayerRoundedTime(double time) {
    if (isnan(time)) return 0;
    if (time >= 0x1p63) return INT64_MAX;
    if (time <= -0x1p63) return INT64_MIN;
    return (int64_t)round(time);
}
void addEndTime(YTPlayerViewController *player, id<YTLPlayerVideo> video, id<YTLPlayerTime> time) {
    if (!ytpBool(@"videoEndTime")) return;
    double rate = [YTPSpeedMaster playbackRateForPlayer:player];
    uint64_t difference = (uint64_t)PlayerRoundedTime(video.totalMediaTime) - (uint64_t)PlayerRoundedTime(time.time);
    int64_t signedDifference;
    memcpy(&signedDifference, &difference, sizeof signedDifference);
    NSDate *date = [NSDate dateWithTimeIntervalSinceNow:(double)signedDifference / rate];
    NSDateFormatter *formatter = [NSDateFormatter new];
    formatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
    formatter.dateFormat = ytpBool(@"24hrFormat") ? @"HH:mm" : @"h:mm a";
    NSString *end = [formatter stringFromDate:date];
    id<YTLPlayerEndTimeView> view = (id)player.view;
    if (![view.overlayView isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayView")]) return;
    id<YTLPlayerEndTimeOverlay> overlay = view.overlayView;
    UILabel *label = overlay.playerBar.durationLabel;
    [overlay.playerBar setEndTimeString:end];
    if (![label.text containsString:end]) {
        label.text = [label.text stringByAppendingString:[NSString stringWithFormat:@" • %@", end]];
        [label sizeToFit];
    }
}
void autoSkipShortsLegacy(YTPlayerViewController *player, id<YTLPlayerVideo> video, id<YTLPlayerTime> time) {
    if (ytpInt(@"shortsPlaybackIndex") != 1) return;
    if (!(floor(time.time) >= floor(video.totalMediaTime))) return;
    if (![player.parentViewController isKindOfClass:NSClassFromString(@"YTShortsPlayerViewController")]) return;
    UIViewController *shorts = player.parentViewController;
    if ([shorts respondsToSelector:@selector(maybeLoopPlayback)] || ![shorts respondsToSelector:@selector(reelContentViewRequestsAdvanceToNextVideo:)]) return;
    if (class_getInstanceVariable(shorts.class, "_isEngagementPanelVisible") && [[shorts valueForKey:@"_isEngagementPanelVisible"] boolValue]) return;
    // The packaged code uses performSelector: with this one-argument selector.
    [shorts performSelector:@selector(reelContentViewRequestsAdvanceToNextVideo:)];
}
