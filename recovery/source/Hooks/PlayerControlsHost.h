#pragma once
#import <UIKit/UIKit.h>
@protocol YTLControlsVideo <NSObject>
- (BOOL)isMuted;
- (void)setMuted:(BOOL)muted;
@end
@protocol YTLControlsVideoDetails <NSObject>
- (NSString *)channelId;
- (NSString *)author;
- (NSString *)title;
@end
@protocol YTLControlsPlayerData <NSObject>
- (id<YTLControlsVideoDetails>)videoDetails;
@end
@protocol YTLControlsResponse <NSObject>
- (id<YTLControlsPlayerData>)playerData;
@end
@protocol YTLControlsPlayer <NSObject>
- (id<YTLControlsVideo>)activeVideo;
- (id<YTLControlsResponse>)playerResponse;
- (id<YTLControlsResponse>)contentPlayerResponse;
- (void)pause;
- (void)play;
@end
@protocol YTLControlsLock <NSObject>
- (void)setLockModeActive:(BOOL)active;
@end
@protocol YTLControlsController <NSObject>
- (UIViewController<YTLControlsPlayer> *)parentViewController;
- (void)resetAutoHideTimer;
- (void)setPlaybackRate:(double)rate;
- (id<YTLControlsLock>)lockModeStateEntityController;
- (void)lockModeDidRequestShowFullscreen;
- (BOOL)isFullscreen;
- (NSInteger)statusBarOrientation;
@end
@protocol YTLControlsSheetHeader <NSObject>
- (void)showHeaderDivider;
@end
@protocol YTLControlsImage <NSObject>
- (void)setFlipsForRightToLeftLayoutDirection:(BOOL)flips;
@end
@protocol YTLControlsSheet <NSObject>
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)responder;
- (void)addAction:(id)action;
- (void)setSourceView:(UIView *)view;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
@class YTActionSheetAction;
typedef void (^YTLControlsActionHandler)(YTActionSheetAction *action);
@protocol YTLControlsAction <NSObject>
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(YTLControlsActionHandler)handler;
@end
@protocol YTLControlsResources <NSObject>
+ (id<YTLControlsImage>)chevronRightImage;
@end
@interface YTMainAppControlsOverlayView : UIView
- (instancetype)initWithDelegate:(id)delegate;
- (id<YTLControlsController>)eventsDelegate;
- (UIViewController<YTLControlsController> *)_viewControllerForAncestor;
- (UIView *)titleView;
- (UIView *)topControlsAccessibilityContainerView;
- (void)setAutoplaySwitchButtonRenderer:(id)renderer;
- (void)setClosedCaptionsOrSubtitlesButtonAvailable:(BOOL)available;
- (void)setOverlayVisible:(BOOL)visible;
- (id)playbackRouteButton;
@end
@interface YTMainAppControlsOverlayView (YTLPlayerControlsRecovered)
@property(nonatomic, strong) UIStackView *speedControls;
@property(nonatomic, strong) UIStackView *ytlButtons;
@property(nonatomic, strong) UIButton *speedMinus;
@property(nonatomic, strong) UIButton *speedPlus;
@property(nonatomic, strong) UIButton *speedValue;
@property(nonatomic, strong) UIButton *ytlButton;
@property(nonatomic, strong) UIButton *ytlMuteButton;
@property(nonatomic, strong) UIButton *ytlLockButton;
@property(nonatomic, strong) UIButton *ytlSleepButton;
@property(nonatomic, strong) UIButton *ytlDiscordButton;
@property(nonatomic, strong) UIButton *ytlSbButton;
@property(nonatomic, strong) NSLayoutConstraint *ytlButtonsTopAnchor;
@property(nonatomic, strong) NSLayoutConstraint *ytlButtonsTrailingAnchor;
@property(nonatomic, strong) NSLayoutConstraint *ytlButtonsFSTopAnchor;
@property(nonatomic, strong) NSLayoutConstraint *ytlButtonsFSTrailingAnchor;
- (void)speedValueMinus:(id)sender;
- (void)speedValuePlus:(id)sender;
- (void)resetSpeedValue:(id)sender;
- (void)speedDidChange:(id)sender;
- (void)showSpeedControl:(id)sender;
- (void)handleYTLIconTap:(id)sender;
- (void)handleYTLMuteTap:(id)sender;
- (void)handleYTLLockTap:(id)sender;
- (void)handleYTLSleepTap:(id)sender;
- (void)handleYTLSbTap:(id)sender;
- (void)handleYTLDiscordTap:(id)sender;
@end
FOUNDATION_EXPORT void YTLInstallPlayerControlsHooks(void);
