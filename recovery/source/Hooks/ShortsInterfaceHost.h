#pragma once
#import <UIKit/UIKit.h>
#include <stdint.h>
FOUNDATION_EXPORT BOOL isOverlayShown;
FOUNDATION_EXPORT void YTLInstallShortsInterfaceHooks(void);
@protocol YTLShortsNode <NSObject>
- (NSArray<id<YTLShortsNode>> *)yogaChildren;
- (id<YTLShortsNode>)controller;
- (NSString *)key;
@end
@protocol YTLShortsPresentation <NSObject>
- (int)type;
@end
@protocol YTLShortsModel <NSObject>
- (int)videoType;
- (id<YTLShortsPresentation>)presentation;
- (BOOL)livePreviewVideo;
- (BOOL)liveVideo;
- (BOOL)isLivePreviewVideo;
- (BOOL)isLiveVideo;
@end
@protocol YTLShortsPlayerProvider <NSObject>
- (id)player;
@end
@protocol YTLShortsIcon <NSObject>
- (unsigned int)iconType;
@end
@protocol YTLShortsButtonRenderer <NSObject>
- (id<YTLShortsIcon>)icon;
@end
@interface YTQTMButton : UIButton
- (id<YTLShortsButtonRenderer>)buttonRenderer;
- (id)touchFeedbackView;
@end
@interface NSObject (YTLShortsInterfaceMessages)
- (id)parentResponder;
- (void)setCustomTouchFeedbackColor:(UIColor *)color;
- (void)showPivotBar;
- (void)hidePivotBar;
@end
@interface YTAssetLoader : NSObject
- (instancetype)initWithBundle:(NSBundle *)bundle;
- (UIImage *)imageNamed:(NSString *)name;
@end
@interface YTReelWatchPlaybackOverlayViewSub : UIView
- (void)didTapYtlButton:(id)sender;
@end
@interface YTReelWatchPlaybackOverlayView : UIView
- (void)setActionBarElementRenderer:(uintptr_t)renderer;
- (void)setReelLikeButton:(UIView *)button;
- (void)didTapYtlButton:(id)sender;
@end
@interface YTInlineMutedPlaybackShortsPlayerOverlayView : UIView
- (void)didTapYtlButton:(id)sender;
@end
@interface YTReelContentModel : NSObject
+ (id)makeContentModelForEntry:(uintptr_t)entry;
@end
@interface YTReelDataSource : NSObject
- (id)makeContentModelForEntry:(uintptr_t)entry;
@end
@interface YTReelInfinitePlaybackDataSource : NSObject
- (id)makeContentModelForEntry:(uintptr_t)entry;
- (NSArray *)reels;
@end
@interface YTShortsStartupCoordinator : NSObject
- (id)evaluateResumeToShorts;
@end
@interface YTReelHeaderView : UIView
- (void)setTitleLabelVisible:(BOOL)visible animated:(BOOL)animated;
- (void)addView:(UIView *)view toStackView:(id)stack withSize:(CGSize)size;
@end
@interface YTReelWatchHeaderView : UIView
- (void)setChannelBarElementRenderer:(id)value;
- (void)setHeaderRenderer:(id)value;
- (void)setShortsVideoTitleElementRenderer:(id)value;
- (void)setSoundMetadataElementRenderer:(id)value;
- (void)setActionElement:(id)value;
- (void)setBadgeRenderer:(id)value;
- (void)setMultiFormatLinkElementRenderer:(id)value;
@end
@interface YTReelContentView : UIView
- (void)setPlaybackView:(uintptr_t)view;
- (UIView *)playbackOverlay;
- (id<YTLShortsPlayerProvider>)delegate;
- (void)reelSpeedmaster:(UILongPressGestureRecognizer *)gesture;
- (void)turnShortsOnlyModeOff:(UILongPressGestureRecognizer *)gesture;
@end
@interface YTReelWatchRootViewController : UIViewController
@end
