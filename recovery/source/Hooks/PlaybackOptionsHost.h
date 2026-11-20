#pragma once
#import <UIKit/UIKit.h>
FOUNDATION_EXPORT void YTLInstallPlaybackOptionsHooks(void);
@protocol YTLPlaybackOptionsControls <NSObject>
- (BOOL)isOverlayVisible;
- (UIView *)ytlButtons;
- (UIView *)speedControls;
@end
@protocol YTLPlaybackOptionsOverlay <NSObject>
- (id<YTLPlaybackOptionsControls>)controlsOverlayView;
@end
@protocol YTLPlaybackOptionsNode <NSObject>
- (NSArray<id<YTLPlaybackOptionsNode>> *)subnodes;
- (NSURL *)URL;
@end
@interface UIView (YTLPlaybackOptionsNode)
- (id<YTLPlaybackOptionsNode>)keepalive_node;
@end
@protocol YTLPlaybackOptionsDrawParameters <NSObject>
- (CGRect)drawRect;
@end
@protocol YTLPlaybackOptionsIcon <NSObject>
- (unsigned int)iconType;
@end
@protocol YTLPlaybackOptionsRenderer <NSObject>
- (id<YTLPlaybackOptionsIcon>)icon;
@end
@protocol YTLPlaybackOptionsAction <NSObject>
- (UIImage *)iconImage;
- (UIButton *)button;
@end
@interface YTVideoQualitySwitchRedesignedController:NSObject
- (instancetype)initWithServiceRegistryScope:(id)scope parentResponder:(id)parent;
- (NSArray *)addRestrictedFormats:(NSArray *)formats;
@end
@interface YTVideoQualitySwitchOriginalController:NSObject
- (YTVideoQualitySwitchRedesignedController *)redesignedController;
- (void)setRedesignedController:(YTVideoQualitySwitchRedesignedController *)controller;
- (void)setUserSelectableFormats:(NSArray *)formats;
@end
@interface YTWatchNextResultsViewController:NSObject
- (void)setVisibleSections:(NSUInteger)sections;
@end
@interface YTFullscreenEngagementOverlayView:UIView
- (void)setExpanded:(BOOL)expanded;
@end
@interface YTPlaylistVideoCell:NSObject
- (void)setCanReorder:(BOOL)value;
@end
@interface YTVideoFreeZoomOverlayController:NSObject
- (double)videoZoomFactor;
- (void)freeZoomViewDidZoom:(double)zoom isTwoFingerZoom:(BOOL)twoFinger;
@end
@interface YTWatchCinematicContainerController:NSObject
- (BOOL)isCinematicLightingAvailable;
@end
@interface YTCreatorEndscreenView:UIView @end
@interface YTFullscreenActionsView:UIView
- (BOOL)enabled;
- (void)setEnabled:(BOOL)value;
@end
@interface YTFullscreenEngagementOverlayController:NSObject
- (void)setRelatedVideosVisible:(BOOL)value;
@end
@interface YTAnnotationsViewController:NSObject
- (void)loadFeaturedChannelWatermark;
@end
@interface YTWatchFloatingMiniplayerViewController:NSObject
- (void)updateMiniBarPlayerStateFromRenderer;
@end
@interface YTPlaybackConfig:NSObject
- (void)setStartPlayback:(BOOL)value;
@end
@interface YTPlayabilityResolutionUserActionUIController:NSObject
- (void)showConfirmAlert;
- (void)confirmAlertDidPressConfirm;
@end
@interface YTSegmentableInlinePlayerBarView:UIView
- (void)setEnableSnapToChapter:(BOOL)value;
@end
@interface YTBrandGradientImageProcessor:NSObject
- (void)willDrawInContext:(CGContextRef)context drawParameters:(id<YTLPlaybackOptionsDrawParameters>)parameters;
@end
@interface YTVerticalPanGestureRecognier:NSObject
- (UIView *)verticalPanGestureRecognizerDelegate;
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture;
@end
@interface YTExitFullscreenController:NSObject
- (UIGestureRecognizer *)fullscreenExitGestureRecognizer;
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture;
@end
@interface YTMenuItemVisibilityHandler:NSObject
- (BOOL)shouldShowServiceItemRenderer:(id<YTLPlaybackOptionsRenderer>)renderer;
@end
@interface YTDefaultSheetController:NSObject
- (void)addAction:(id<YTLPlaybackOptionsAction>)action;
@end
@interface YTYouThereController:NSObject
- (BOOL)shouldShowYouTherePrompt;
@end
@interface YTSpeedmasterController:NSObject
- (void)speedmasterDidLongPressWithRecognizer:(UILongPressGestureRecognizer *)gesture;
@end
@interface YTHUDMessageView:UIView
- (instancetype)initWithMessage:(id)message dismissHandler:(id)handler;
@end
