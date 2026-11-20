#pragma once
#import <UIKit/UIKit.h>
@class YTMainAppVideoPlayerOverlayViewController;

@interface YTPSpeedMaster : NSObject {
    NSArray *_speedArray;
    NSInteger _speedIndex;
    double _minRate;
    double _maxRate;
    double _rateStep;
    double _rateBeforeSpeedmaster;
    CGPoint _startLocation;
    double _gestureBaseRate;
    NSInteger _gestureBaseIndex;
    YTMainAppVideoPlayerOverlayViewController *_controller;
}
+ (instancetype)sharedMaster;
- (void)manageSpeedMaster:(UILongPressGestureRecognizer *)gesture playerOverlayVC:(id)controller;
- (NSArray *)speedArray;
- (NSInteger)nearestIndexForRate:(double)rate;
- (double)currentPlaybackRate;
- (void)setPlaybackRate:(double)rate;
+ (id)getPlayerIfAvailable;
+ (double)currentPlaybackRate;
+ (double)playbackRateForPlayer:(id)player;
+ (void)setPlaybackRate:(double)rate forPlayer:(id)player;
+ (void)_applyPendingRateForPlayer:(id)player;
@end
