#pragma once
#import <UIKit/UIKit.h>
@protocol YTLOverlayPlayer <NSObject>
- (void)seekToTime:(double)time;
@end
@protocol YTLOverlayScrubber <NSObject>
- (void)fineScrubberDidStartSeeking;
- (void)fineScrubberDidSeekToTime:(double)time;
- (void)fineScrubberDidEndSeekingWithSeekSource:(NSInteger)source;
- (UILabel *)currentTimeLabel;
@end
@protocol YTLOverlayBarController <NSObject>
- (id<YTLOverlayScrubber>)playerBar;
@end
@protocol YTLOverlayIdentifier <NSObject>
- (NSString *)overlayIdentifier;
@end
@protocol YTLOverlayVolume <NSObject>
- (float)systemVolume;
@end
@protocol YTLOverlayAssetLoader <NSObject>
- (instancetype)initWithBundle:(NSBundle *)bundle;
- (UIImage *)imageNamed:(NSString *)name;
@end
@interface YTInlineMutedPlaybackPlayerOverlayView:UIView
- (NSInteger)audioControlUIStyle;
- (NSInteger)scrubbingUIStyle;
- (void)updateAudioControlUIStyle:(NSInteger)style;
- (void)resetWithAudioControlUIStyle:(NSInteger)style;
- (void)setAudioControlUIStyle:(NSInteger)style;
@end
@interface YTInlineMutedPlaybackPlayerOverlayViewController:UIViewController<UIGestureRecognizerDelegate>
- (NSInteger)scrubbingUIStyle;
- (void)setPaidContentWithPlayerData:(id)data;
- (BOOL)gestureRecognizerShouldBegin:(UIPanGestureRecognizer *)gesture;
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)other;
- (double)totalTime;
- (double)mediaTime;
- (void)handleHorizontalPan:(UIPanGestureRecognizer *)gesture;
@end
@interface YTInlineMutedPlaybackAudioIconViewController:UIViewController
- (id)parentResponder;
- (void)handleYTLIconTap:(id)sender;
@end
@interface YTInlineMutedPlaybackAudioIconViewController (YTLPlayerOverlayRecovered)
@property(nonatomic,strong) UIButton *ytlButton;
@property(nonatomic,strong) UIView *ytlIcon;
@end
@interface YTInlineMutedPlaybackAudioIconView:UIView
- (void)updateColors;
- (YTInlineMutedPlaybackAudioIconViewController *)_viewControllerForAncestor;
- (BOOL)goo_shouldRelayoutSubviewsForRTL;
@end
@interface YTMainAppVideoPlayerOverlayView:UIView
- (void)setBackgroundVisible:(BOOL)visible isGradientBackground:(BOOL)gradient;
- (id)autonavPreviewView;
- (BOOL)isWatermarkEnabled;
- (id)featuredChannelWatermarkImageView;
- (void)setSeekAnywherePanGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (id)delegate;
- (void)speedmasterYtLite:(UILongPressGestureRecognizer *)recognizer;
@end
@interface YTMainAppVideoPlayerOverlayViewController:UIViewController<UIGestureRecognizerDelegate>
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture;
- (BOOL)shouldShowAutonavEndscreen;
- (void)setFeaturedChannelWatermarkImageView:(id)view;
- (void)setPaidContentWithPlayerData:(id)data;
- (void)playerOverlayProvider:(id)provider didInsertPlayerOverlay:(id<YTLOverlayIdentifier>)overlay;
- (NSString *)selectedVarispeedLabelText;
- (BOOL)allowDoubleTapToSeekGestureRecognizer;
- (BOOL)allowTwoFingerDoubleTapGestureRecognizer;
- (void)didPressPause:(id)sender;
- (void)setLoopMode:(NSInteger)mode;
- (double)currentPlaybackRate;
- (double)mediaTime;
- (double)maximumSeekableTime;
- (NSString *)videoID;
- (void)didTogglePlayPause;
- (id<YTLOverlayBarController>)playerBarController;
- (void)handleTwoFingerTap:(UITapGestureRecognizer *)gesture;
- (void)handleHorizontalPan:(UIPanGestureRecognizer *)gesture;
- (void)handleFingerPan:(UIPanGestureRecognizer *)gesture;
@end
FOUNDATION_EXPORT void YTLInstallPlayerOverlayHooks(void);

FOUNDATION_EXPORT BOOL canRememberLoopMode;
