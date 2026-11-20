#pragma once
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

// Narrow declarations for existing YouTube runtime classes; no host implementation.
@interface UIView (YTLPlayerBarsAncestor)
- (UIViewController *)_viewControllerForAncestor;
@end
@interface UIViewController (YTLPlayerBarsResponder)
- (id)parentResponder;
@end
@interface UIImage (YTLPlayerBarsFlatImage)
- (UIImage *)_flatImageWithColor:(UIColor *)color;
@end
@interface YTInlinePlayerBarContainerView : UIView
@property(nonatomic,strong) UILabel *durationLabel;
@property(nonatomic,strong) NSString *sbTimeString,*endTimeString;
- (void)setPeekableViewVisible:(BOOL)visible;
- (void)setPlayerBarAlpha:(CGFloat)alpha;
- (UIColor *)quietProgressBarColor;
- (void)didPressScrubber:(UIGestureRecognizer *)recognizer;
- (CGFloat)scrubRangeForScrubX:(CGFloat)x;
@end
@interface YTPlayerBarRectangleDecorationView : UIView
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient;
- (void)applyGradientForRect:(CGRect)rect;
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color;
- (BOOL)isStateActive;
@end
@interface YTPlayerBarProgressDecorationView : UIView
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient;
- (void)applyGradientForRect:(CGRect)rect;
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color;
- (BOOL)isStateActive;
@end
@interface YTPlayerBarScrubberDotDecorationView : UIView
- (UIView *)scrubberDot;
@end
@interface YTPlayerBarScrubberDotDecorationViewV1 : UIView
- (UIView *)scrubberDot;
@end
@interface YTModularPlayerBarView : UIView @end
@interface YTProgressView : UIView
// Untouched scalar forwarding in both packaged callbacks; see provenance for the host type limitation.
- (void)setProgress:(double)progress;
- (void)setProgressBarColor:(UIColor *)color;
@end
@interface YTInlineMutedPlaybackScrubberView : UIView
- (void)setMediaTime:(double)time;
- (void)addGradient;
- (BOOL)segmentablePlayerBarEnabled;
- (id)segmentablePlayerBar;
@end
@interface YTInlineMutedPlaybackScrubbingSlider : UISlider
- (UIImage *)currentMinimumTrackImage;
@end
@protocol YTLPlayerBarsPlayer
- (double)currentVideoTotalMediaTime;
- (void)seekToTime:(double)time;
@end

FOUNDATION_EXPORT void YTLInstallPlayerBarsSponsorHooks(void);
FOUNDATION_EXPORT void YTLInstallPlayerBarsAppearanceHooks(void);
