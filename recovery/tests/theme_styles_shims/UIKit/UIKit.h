#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
typedef struct { CGFloat top,left,bottom,right; } UIEdgeInsets;
typedef NSInteger NSWritingDirection;
enum { NSWritingDirectionLeftToRight=0, UIUserInterfaceStyleDark=2, UIGestureRecognizerStateBegan=1, UIModalPresentationFormSheet=2 };
static const CGFloat UIFontWeightBold=0.4;
static NSString *const NSFontAttributeName=@"font", *const NSForegroundColorAttributeName=@"color";
@class UIViewController,UIColor,UIImage,UIFont,UITraitCollection,UIWindow,NSLayoutAnchor,NSLayoutConstraint;
@protocol UIScrollViewDelegate @end
@interface UIResponder : NSObject @end
@interface NSLayoutConstraint : NSObject
@property BOOL active;
@property CGFloat constant;
@end
@interface NSLayoutAnchor : NSObject
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)constant;
@end
@interface UIView : UIResponder
@property(nonatomic,strong) UIViewController *ancestor;
@property(nonatomic,strong) UIView *superview;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,copy) NSString *accessibilityIdentifier,*fixtureDescription;
@property CGFloat alpha;
@property NSInteger tag;
@property(nonatomic,strong) NSMutableArray *subviews,*gestureRecognizers;
@property(nonatomic,readonly) NSLayoutAnchor *centerXAnchor,*topAnchor,*widthAnchor,*heightAnchor;
- (void)layoutSubviews;
- (void)didMoveToWindow;
- (void)removeFromSuperview;
- (void)addSubview:(UIView *)view;
- (UIView *)viewWithTag:(NSInteger)tag;
- (void)addGestureRecognizer:(id)gesture;
@end
@interface UITraitCollection : NSObject
@property NSInteger userInterfaceStyle;
@end
@interface UIColor : NSObject<NSSecureCoding>
@property CGFloat white,alpha;
@property BOOL gray;
@property(nonatomic,copy) NSString *name;
@property(nonatomic,copy) UIColor *(^provider)(UITraitCollection *);
@property(nonatomic,readonly) CGColorRef CGColor;
+ (instancetype)blackColor;
+ (instancetype)whiteColor;
+ (instancetype)clearColor;
+ (instancetype)labelColor;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
- (BOOL)getWhite:(CGFloat *)white alpha:(CGFloat *)alpha;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *fixtureDescription;
@property(nonatomic,strong) UIColor *tint;
+ (instancetype)imageWithData:(NSData *)data;
@end
@interface UIImageView : UIView
@property(nonatomic,strong) UIImage *image;
@end
@interface UIFont : NSObject @end
@interface UINavigationBar : UIView
@property(nonatomic,copy) NSDictionary *titleTextAttributes;
@end
@interface UIViewController : UIResponder
@property(nonatomic,strong) UIView *view;
@property(nonatomic,strong) UIViewController *parentViewController,*presented;
@property(nonatomic,strong) UITraitCollection *traitCollection;
@property NSInteger modalPresentationStyle;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UINavigationController : UIViewController
@property(nonatomic,strong) UIViewController *root;
@property(nonatomic,strong) UINavigationBar *navigationBar;
- (instancetype)initWithRootViewController:(UIViewController *)controller;
@end
@interface UITableViewController : UIViewController @end
@interface UIWindow : UIView
@property(nonatomic,strong) UIViewController *rootViewController;
@end
@protocol UIApplicationDelegate
@property(nonatomic,strong) UIWindow *window;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) id<UIApplicationDelegate> delegate;
+ (instancetype)sharedApplication;
- (BOOL)canOpenURL:(NSURL *)url;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@interface UIPasteboard : NSObject
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,copy) NSString *string;
+ (instancetype)generalPasteboard;
@end
@interface UIGestureRecognizer : NSObject
@property NSInteger state;
@end
@interface UILongPressGestureRecognizer : UIGestureRecognizer
@property CGFloat minimumPressDuration;
@property(nonatomic,strong) id target;
@property SEL action;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
@end
@interface UIInputView : UIView @end
@interface UIButton : UIView @end
@interface UILabel : UIView @end
@interface UIScrollView : UIView @end
@interface UIVisualEffectView : UIView @end
@interface UIProgressView : UIView @end
@interface UIStackView : UIView @end
@interface UIActivityIndicatorView : UIView @end
@interface UITableView : UIView @end
@interface UITextView : UIView @end
@interface NSParagraphStyle : NSObject
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString *)language;
@end
@class UIPanGestureRecognizer,UITapGestureRecognizer;
FOUNDATION_EXPORT void UIImageWriteToSavedPhotosAlbum(UIImage *,id,SEL,void *);
@class UIWindowScene, UIEvent;
