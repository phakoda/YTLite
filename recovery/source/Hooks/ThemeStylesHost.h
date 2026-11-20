#pragma once
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
@interface UIView (YTLThemeHost)
- (UIViewController *)_viewControllerForAncestor;
- (BOOL)_mapkit_isDarkModeEnabled;
@end
@interface UIImage (YTLThemeHost)
- (UIImage *)_flatImageWithColor:(UIColor *)color;
@end
@interface NSParagraphStyle (YTLThemeHost)
+ (NSWritingDirection)_defaultWritingDirection;
@end
@interface YTColor : NSObject
+ (UIColor *)blackPure;
+ (UIColor *)black0;
+ (UIColor *)black1;
+ (UIColor *)black2;
+ (UIColor *)black3;
+ (UIColor *)black4;
+ (UIColor *)bgColorForPageStyle:(long long)style;
@end
@interface GOODimmingBackgroundView : UIView @end
@interface UIKeyboard : UIView
+ (instancetype)activeKeyboard;
- (void)displayLayer:(CALayer *)layer;
@end
@interface UIPredictionViewController : UIViewController
- (id)_currentTextSuggestions;
@end
@interface UIKeyboardDockView : UIView @end
@interface UIKBVisualEffectView : UIView
- (void)setBackgroundEffects:(NSArray *)effects;
@end
@interface YTUIResources : NSObject
+ (UIImage *)youtubePremiumLogoWithPageStyle:(long long)style;
+ (UIImage *)youtubeLogoWithPageStyle:(long long)style;
@end
@protocol YTLThemeNode <NSObject>
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,readonly) NSArray<id<YTLThemeNode>> *yogaChildren;
@property(nonatomic,readonly) UIViewController *closestViewController;
@property(nonatomic,readonly) CALayer *layer;
@property(nonatomic,readonly) NSString *copiedComment;
@property(nonatomic,readonly) NSURL *copiedURL;
@property(nonatomic,readonly) NSURL *URL;
@end
@interface _ASDisplayView : UIView
@property(nonatomic,strong) id<YTLThemeNode> keepalive_node;
- (void)savePFP:(UILongPressGestureRecognizer *)sender;
- (void)postManager:(UILongPressGestureRecognizer *)sender;
- (void)commentManager:(UILongPressGestureRecognizer *)sender;
@end
@interface YTActionSheetAction : NSObject
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)image style:(NSInteger)style handler:(void (^)(void))handler;
+ (instancetype)actionWithTitle:(NSString *)title titleColor:(UIColor *)titleColor iconImage:(UIImage *)image iconColor:(UIColor *)iconColor disableAutomaticButtonColor:(BOOL)disable accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
@end
@interface YTDefaultSheetController : NSObject
+ (instancetype)sheetControllerWithParentResponder:(UIResponder *)responder;
@property(nonatomic,strong) UIView *sourceView;
- (void)addAction:(YTActionSheetAction *)action;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface YTDefaultTypeStyle : NSObject
- (UIFont *)ytSansFontOfSize:(CGFloat)size weight:(CGFloat)weight;
@end
@interface YTLThemeTouchFeedbackView : UIView
- (void)setCustomTouchFeedbackColor:(UIColor *)color;
@end
@interface UIButton (YTLThemeTouch)
- (YTLThemeTouchFeedbackView *)touchFeedbackView;
@end
@interface YCHLiveChatView : UIView
@property(nonatomic,readonly) UIView *lightweightInteractivityView;
- (void)didTapYtlButton:(id)sender;
@end
@interface YTLivePlayerViewController : UIViewController
@property(nonatomic,readonly) NSString *activeVideoID;
@end
FOUNDATION_EXPORT void YTLInstallThemeStylesHooks(void);
