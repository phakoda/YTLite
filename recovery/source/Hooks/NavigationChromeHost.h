#pragma once
#import <UIKit/UIKit.h>
#include <stdint.h>
FOUNDATION_EXPORT BOOL isTabSelected;
FOUNDATION_EXPORT BOOL isOverlayShown;
FOUNDATION_EXPORT void YTLInstallNavigationChromeEarlyHooks(void);
FOUNDATION_EXPORT void YTLInstallNavigationChromeHooks(void);
FOUNDATION_EXPORT void YTLInstallNavigationChromeRendererHook(void);
@protocol YTLNavigationIcon <NSObject>
- (unsigned int)iconType;
@end
@protocol YTLNavigationRenderer <NSObject>
- (id<YTLNavigationIcon>)icon;
@end
@protocol YTLNavigationAncestor <NSObject>
- (id)renderer;
@end
@interface YTQTMButton:UIButton
- (void)setSizeWithPaddingAndInsets:(BOOL)value;
@end
@interface YTDefaultTypeStyle:NSObject
- (UIFont *)ytSansFontOfSize:(CGFloat)size weight:(CGFloat)weight;
@end
@interface NSObject (YTLNavigationMessages)
- (void)hidePivotBar;
@end
@interface YTHeaderView:UIView
- (BOOL)stickyNavHeaderEnabled;
- (BOOL)clipsToStatusArea;
@end
@interface YTChipCloudCell:NSObject
- (id)framesForChipViewsWithWidth:(double)width;
@end
@interface YTMySubsFilterHeaderView:UIView
- (void)setChipFilterView:(id)view;
@end
@interface YTHeaderContentComboView:UIView
- (void)enableSubheaderBarWithView:(id)view;
- (void)setFeedHeaderScrollMode:(int)mode;
@end
@interface YTIPivotBarRenderer:NSObject
- (int)backgroundStyle;
@end
@interface YTPivotBarViewController:UIViewController
- (void)resetViewControllersCache;
- (void)resetViewControllersCacheForPivotIdentifiers:(NSArray *)identifiers;
- (void)selectItemWithPivotIdentifier:(NSString *)identifier;
- (BOOL)isFrostedPivotBarPermitted;
- (id)renderer;
@end
@interface YTPivotBarView:UIView<UIContextMenuInteractionDelegate>
- (UIView *)itemView1;
@end
@interface YTWatchMiniBarViewController:UIViewController
- (void)updateMiniBarPlayerStateFromRenderer;
@end
@interface YTPlaylistMiniBarView:UIView @end
@interface YTPivotBarItemView:UIView
- (YTQTMButton *)navigationButton;
- (id<YTLNavigationAncestor>)_viewControllerForAncestor;
- (id<YTLNavigationRenderer>)renderer;
- (void)setRenderer:(uintptr_t)renderer;
- (UIView *)indicatorDot;
@end
@interface YTAppViewController:UIViewController
- (void)showPivotBar;
@end
