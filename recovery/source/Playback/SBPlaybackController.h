#pragma once
#import <Foundation/Foundation.h>
@class YTPlayerViewController, SBSegment;

@interface SBPlaybackController : NSObject {
@private
    __weak YTPlayerViewController *_player;
    NSString *_videoID;
    NSMutableSet<NSString *> *_skippedUUIDs;
}
- (instancetype)initWithPlayer:(YTPlayerViewController *)player;
- (void)requestSbSegments;
- (BOOL)shouldCheckSponsorBlock;
- (void)skipSegmentIfNeeded;
- (BOOL)segmentMeetsMinimumDuration:(SBSegment *)segment;
- (void)handleSkipSegment:(SBSegment *)segment;
- (void)handleHighlightSegment:(SBSegment *)segment;
- (void)seekToTime:(double)time forSegment:(SBSegment *)segment
         undoTime:(double)undoTime attempts:(int)attempts;
- (void)showSkippedToast:(SBSegment *)segment undoTime:(double)undoTime;
- (void)showSkipPromptToast:(SBSegment *)segment timeBeforeSkip:(double)time target:(double)target;
- (void)playSkipAudioIfNeeded;
@end
