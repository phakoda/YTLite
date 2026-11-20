#pragma once
#import <UIKit/UIKit.h>

@interface YTPSleepTimer : NSObject {
    dispatch_source_t _timer;
    dispatch_queue_t _timerQueue;
    UIImage *_icon;
    NSUInteger _mode;
    NSUInteger _timerStyle;
    BOOL _didStartFade;
    double _endTimestamp;
}
+ (instancetype)sharedTimer;
- (dispatch_queue_t)timerQueue;
- (BOOL)isRunning;
- (void)showOptions:(UIView *)source;
- (void)showTimeSelector;
- (void)startForSeconds:(double)seconds;
- (void)startForEndOfVideo;
- (void)startTimer;
- (void)stopWithFadeIfNeeded:(double)remaining;
- (void)stopWithFadeDuration:(double)duration stopAfter:(double)delay;
- (void)stop;
- (void)cancel;
- (void)cancelIfPlayerClosed;
- (double)remainingSeconds;
- (double)remainingSecondsForCurrentVideo;
- (double)secondsForDate:(NSDate *)date;
- (NSString *)formattedTime:(double)seconds;
- (id)getPlayerIfAvailable;
- (id)globalSlimBar;
- (id)playerSlimBar;
- (void)globalSlimBarVisibilityChange;
- (void)playerSlimBarVisibilityChange;
- (id)slimBarForStyle:(NSUInteger)style;
- (NSArray *)barsForStyle:(NSUInteger)style;
- (NSAttributedString *)attributedTitle:(NSString *)title image:(UIImage *)image;
- (void)applyTitle:(NSString *)title image:(UIImage *)image color:(UIColor *)color toBar:(id)bar;
- (void)attachTapHandlerToBar:(UIView *)bar;
- (void)removeTapHandlerOnBar:(UIView *)bar;
- (void)onSlimBarTap:(UITapGestureRecognizer *)gesture;
- (void)slimBarVisibilityChange:(NSUInteger)style;
- (void)showSlimBarWithTitle:(NSString *)title image:(UIImage *)image color:(UIColor *)color style:(NSUInteger)style;
- (void)updateSlimBarTitle:(NSString *)title style:(NSUInteger)style;
- (void)hideSlimBarWithStyle:(NSUInteger)style;
- (BOOL)pausePlayback;
- (void)finishTimerAndCleanup;
- (void)cleanup;
@end
