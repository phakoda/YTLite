#pragma once
#import <Foundation/Foundation.h>
@class SBPlaybackController;

// Only message contracts used by this module. The host owns both classes.
@interface YTPlayerViewController : NSObject
- (BOOL)isPlayingAd;
- (id)parentViewController;
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data;
- (void)singleVideo:(id)video currentVideoTimeDidChange:(id)time;
- (void)potentiallyMutatedSingleVideo:(id)video currentVideoTimeDidChange:(id)time;
@property(nonatomic, retain) SBPlaybackController *sbPlaybackController;
@end
@interface YTWatchViewController : NSObject
@end

#ifdef __cplusplus
extern "C" {
#endif
void YTLInstallSponsorPlaybackHooks(void);
#ifdef __cplusplus
}
#endif
