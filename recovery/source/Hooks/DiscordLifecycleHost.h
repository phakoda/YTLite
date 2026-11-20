#pragma once
#import <UIKit/UIKit.h>
#include <stdint.h>

// These arguments are forwarded unchanged in x2. Host metadata is absent from
// the tweak image; preserve the complete integral slot instead of narrowing it.
typedef uintptr_t YTLDiscordForwardedInteger;
@protocol YTLDiscordPlaybackTime <NSObject>
- (double)time;
@end
@interface YTPlayerViewController : UIViewController
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data;
- (void)seekToTime:(double)time;
- (void)seekToTime:(double)time seekSource:(YTLDiscordForwardedInteger)source;
- (void)seekToTime:(double)time toleranceBefore:(double)before toleranceAfter:(double)after seekSource:(YTLDiscordForwardedInteger)source;
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time;
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id<YTLDiscordPlaybackTime>)time;
@end
@interface YTWatchPlaybackController : NSObject
- (void)playbackControllerDidPlay;
- (void)playbackControllerDidPause;
- (void)playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:(YTLDiscordForwardedInteger)transition;
- (void)clearPlaybackController;
@end
@interface YTMainAppControlsOverlayView : UIView
- (UIViewController *)_viewControllerForAncestor;
- (void)handleYTLDiscordTap:(UIButton *)sender;
@end

FOUNDATION_EXPORT void YTLInstallDiscordLifecycleHooks(void);
