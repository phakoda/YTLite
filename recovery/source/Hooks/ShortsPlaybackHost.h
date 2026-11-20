#pragma once
#import <UIKit/UIKit.h>
#include <stdint.h>

// Host metadata for these forwarded parameters is absent. The original hooks
// preserve the full x2/x3 slots; do not narrow them or add ARC object ownership.
typedef uintptr_t YTLShortsForwardedArgument;
@protocol YTLShortsSelectableFormat <NSObject>
- (int)singleDimensionResolution;
- (NSString *)qualityLabel;
@end
@protocol YTLShortsQualityController <NSObject>
- (id)valueForKey:(NSString *)key;
@end
@protocol YTLShortsConstraint <NSObject>
- (instancetype)init;
- (instancetype)initWithVideoQualitySetting:(int)setting formatSelectionReason:(NSInteger)reason qualityLabel:(NSString *)label;
@end
@interface YTReelPlayerViewController : UIViewController
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLShortsForwardedArgument)transition;
- (void)maybeLoopPlayback;
- (void)playbackControllerDidActivateVideo:(YTLShortsForwardedArgument)controller withPlayerResponse:(YTLShortsForwardedArgument)response;
- (void)autoQuality;
- (void)pause;
- (void)reelContentViewRequestsAdvanceToNextVideo:(id)sender;
- (id)parentResponder;
- (id<YTLShortsQualityController>)videoQualityController;
- (void)videoQualitySwitchController:(id)controller didSelectFormatConstraint:(id)constraint forSelectableVideoFormats:(NSArray *)formats;
- (BOOL)shouldEnablePlayerBar;
- (BOOL)shouldAlwaysEnablePlayerBar;
- (BOOL)shouldEnablePlayerBarOnlyOnPause;
@end
@interface YTReelPlayerViewControllerSub : UIViewController
- (BOOL)shouldEnablePlayerBar;
- (BOOL)shouldAlwaysEnablePlayerBar;
- (BOOL)shouldEnablePlayerBarOnlyOnPause;
@end
@interface YTShortsPlayerViewController : YTReelPlayerViewController
- (BOOL)shouldAlwaysEnablePlayerBar;
- (BOOL)shouldEnablePlayerBarOnlyOnPause;
@end
FOUNDATION_EXPORT void YTLInstallShortsPlaybackHooks(void);
