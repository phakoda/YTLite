#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>

// macOS Foundation may load CoreAutoLayout; keep fixture class names distinct.
#define NSLayoutAnchor PresentationFixtureLayoutAnchor
#define NSLayoutConstraint PresentationFixtureLayoutConstraint

typedef struct { CGFloat top,left,bottom,right; } UIEdgeInsets;
static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat t,CGFloat l,CGFloat b,CGFloat r) { return (UIEdgeInsets){t,l,b,r}; }
static const UIEdgeInsets UIEdgeInsetsZero = {0,0,0,0};
typedef CGFloat UIFontWeight;
typedef float UILayoutPriority;
typedef CGFloat UIWindowLevel;
typedef NSString *UIActivityType;
typedef CGFloat UIScrollViewDecelerationRate;
typedef NS_ENUM(NSInteger,NSTextAlignment) { NSTextAlignmentLeft,NSTextAlignmentCenter,NSTextAlignmentRight,NSTextAlignmentJustified,NSTextAlignmentNatural };
typedef NS_ENUM(NSInteger,UIViewContentMode) { UIViewContentModeScaleToFill,UIViewContentModeScaleAspectFit,UIViewContentModeScaleAspectFill,UIViewContentModeRedraw,UIViewContentModeCenter };
typedef NS_ENUM(NSInteger,UILayoutConstraintAxis) { UILayoutConstraintAxisHorizontal,UILayoutConstraintAxisVertical };
typedef NS_ENUM(NSInteger,UIButtonType) { UIButtonTypeCustom,UIButtonTypeSystem };
typedef NS_ENUM(NSInteger,UIUserInterfaceIdiom) { UIUserInterfaceIdiomUnspecified=-1,UIUserInterfaceIdiomPhone,UIUserInterfaceIdiomPad };
typedef NS_ENUM(NSInteger,UIImageRenderingMode) { UIImageRenderingModeAutomatic,UIImageRenderingModeAlwaysOriginal,UIImageRenderingModeAlwaysTemplate };
typedef NS_ENUM(NSInteger,UIBlurEffectStyle) { UIBlurEffectStyleExtraLight,UIBlurEffectStyleLight,UIBlurEffectStyleDark };
typedef NS_ENUM(NSInteger,UIActivityIndicatorViewStyle) { UIActivityIndicatorViewStyleMedium=100 };
typedef NS_ENUM(NSInteger,UIProgressViewStyle) { UIProgressViewStyleDefault,UIProgressViewStyleBar };
typedef NS_ENUM(NSInteger,UIStackViewDistribution) { UIStackViewDistributionFill };
typedef NS_ENUM(NSInteger,UIStackViewAlignment) { UIStackViewAlignmentFill,UIStackViewAlignmentLeading,UIStackViewAlignmentTop=1,UIStackViewAlignmentFirstBaseline,UIStackViewAlignmentCenter };
typedef NS_ENUM(NSInteger,UIImpactFeedbackStyle) { UIImpactFeedbackStyleLight,UIImpactFeedbackStyleMedium,UIImpactFeedbackStyleHeavy };
typedef NS_ENUM(NSInteger,UIBarMetrics) { UIBarMetricsDefault };
typedef NS_ENUM(NSInteger,UIGestureRecognizerState) { UIGestureRecognizerStatePossible,UIGestureRecognizerStateBegan,UIGestureRecognizerStateChanged,UIGestureRecognizerStateEnded,UIGestureRecognizerStateCancelled,UIGestureRecognizerStateFailed };
typedef NS_ENUM(NSInteger,UIInterfaceOrientation) { UIInterfaceOrientationUnknown,UIInterfaceOrientationPortrait,UIInterfaceOrientationPortraitUpsideDown,UIInterfaceOrientationLandscapeLeft,UIInterfaceOrientationLandscapeRight };
typedef NS_ENUM(NSInteger,UISceneActivationState) { UISceneActivationStateUnattached=-1,UISceneActivationStateForegroundActive,UISceneActivationStateForegroundInactive,UISceneActivationStateBackground };
typedef NS_ENUM(NSInteger,UIModalPresentationStyle) { UIModalPresentationFullScreen,UIModalPresentationPageSheet,UIModalPresentationFormSheet,UIModalPresentationCurrentContext,UIModalPresentationCustom };
typedef NS_OPTIONS(NSUInteger,UIControlState) { UIControlStateNormal=0,UIControlStateHighlighted=1 };
typedef NS_OPTIONS(NSUInteger,UIControlEvents) { UIControlEventTouchUpInside=1UL<<6 };
typedef NS_OPTIONS(NSUInteger,UIViewAutoresizing) { UIViewAutoresizingNone=0,UIViewAutoresizingFlexibleWidth=2,UIViewAutoresizingFlexibleHeight=16 };
typedef NS_OPTIONS(NSUInteger,UIViewAnimationOptions) { UIViewAnimationOptionCurveEaseIn=1UL<<16,UIViewAnimationOptionCurveEaseOut=2UL<<16 };
typedef NS_OPTIONS(NSUInteger,UIPopoverArrowDirection) { UIPopoverArrowDirectionAny=15 };
static inline BOOL UIInterfaceOrientationIsLandscape(UIInterfaceOrientation o) { return o==3 || o==4; }
FOUNDATION_EXPORT const UIFontWeight UIFontWeightRegular,UIFontWeightBold;
FOUNDATION_EXPORT const UILayoutPriority UILayoutPriorityRequired;
FOUNDATION_EXPORT const UIWindowLevel UIWindowLevelAlert;
FOUNDATION_EXPORT const UIScrollViewDecelerationRate UIScrollViewDecelerationRateNormal;
FOUNDATION_EXPORT UIActivityType const UIActivityTypeAssignToContact,UIActivityTypePrint;
FOUNDATION_EXPORT NSString *const UIKeyboardWillShowNotification,*const UIKeyboardWillHideNotification,*const UIKeyboardFrameEndUserInfoKey;

@class UIView,UIViewController,UINavigationController,UIWindow,UIWindowScene,UILayoutGuide,NSLayoutAnchor,NSLayoutConstraint,UIAction,UIMenu,UIGestureRecognizer,UIPresentationController,UISheetPresentationController,UIPopoverPresentationController;
@interface UIFont : NSObject
@property(nonatomic) CGFloat pointSize;
@property(nonatomic) UIFontWeight fixtureWeight;
@property(nonatomic) BOOL fixtureMonospaced;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
+ (instancetype)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
@end
@interface UIColor : NSObject {
    CGColorRef _fixtureColor;
}
@property(nonatomic, strong) NSData *fixtureComponents;
@property(nonatomic, readonly) CGColorRef CGColor;
+ (instancetype)whiteColor; + (instancetype)blackColor; + (instancetype)clearColor;
+ (instancetype)labelColor; + (instancetype)secondaryLabelColor;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
@end
@interface NSLayoutConstraint : NSObject
@property(nonatomic) BOOL active;
@property(nonatomic) CGFloat constant;
@property(nonatomic) NSInteger fixtureRelation;
@property(nonatomic, strong) NSLayoutAnchor *firstAnchor,*secondAnchor;
+ (void)activateConstraints:(NSArray<NSLayoutConstraint *> *)constraints;
+ (void)deactivateConstraints:(NSArray<NSLayoutConstraint *> *)constraints;
@end
@interface NSLayoutAnchor : NSObject
@property(nonatomic, weak) id owner;
@property(nonatomic, copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)constant;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)constant;
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToConstant:(CGFloat)constant;
@end
#define PRESENTATION_ANCHOR_PROPERTIES \
@property(nonatomic,readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*centerXAnchor,*centerYAnchor,*widthAnchor,*heightAnchor;
@interface UILayoutGuide : NSObject
@property(nonatomic, weak) UIView *owningView;
PRESENTATION_ANCHOR_PROPERTIES
@end
@interface UIEvent : NSObject @end
@interface UIView : NSObject
@property(nonatomic) CGRect frame,bounds;
@property(nonatomic) CGPoint center;
@property(nonatomic) CGFloat alpha;
@property(nonatomic) CGAffineTransform transform;
@property(nonatomic) BOOL clipsToBounds,userInteractionEnabled,translatesAutoresizingMaskIntoConstraints;
@property(nonatomic,getter=isHidden) BOOL hidden;
@property(nonatomic) UIViewAutoresizing autoresizingMask;
@property(nonatomic) UIViewContentMode contentMode;
@property(nonatomic) UIEdgeInsets safeAreaInsets;
@property(nonatomic, strong) CALayer *layer;
@property(nonatomic, strong) UIColor *backgroundColor,*tintColor;
@property(nonatomic, weak) UIView *superview;
@property(nonatomic, weak) UIViewController *fixtureController;
@property(nonatomic, readonly) NSArray<UIView *> *subviews;
@property(nonatomic, readonly) NSArray<UIGestureRecognizer *> *gestureRecognizers;
@property(nonatomic, readonly) UILayoutGuide *safeAreaLayoutGuide;
@property(nonatomic, strong) NSMutableArray<NSLayoutConstraint *> *fixtureConstraints;
@property(nonatomic, strong) NSMutableDictionary<NSNumber *,NSNumber *> *fixtureHugging,*fixtureCompression;
@property(nonatomic) NSUInteger fixtureLayouts;
PRESENTATION_ANCHOR_PROPERTIES
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
- (void)removeFromSuperview;
- (void)bringSubviewToFront:(UIView *)view;
- (void)sendSubviewToBack:(UIView *)view;
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (void)removeGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (void)setContentHuggingPriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (void)setContentCompressionResistancePriority:(UILayoutPriority)priority forAxis:(UILayoutConstraintAxis)axis;
- (void)layoutIfNeeded;
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event;
- (CGRect)convertRect:(CGRect)rect fromView:(UIView *)view;
- (UIViewController *)_viewControllerForAncestor;
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay
    usingSpringWithDamping:(CGFloat)damping initialSpringVelocity:(CGFloat)velocity
                  options:(UIViewAnimationOptions)options animations:(dispatch_block_t)animations
               completion:(void (^)(BOOL))completion;
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay
                  options:(UIViewAnimationOptions)options animations:(dispatch_block_t)animations
               completion:(void (^)(BOOL))completion;
+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration
                  options:(UIViewAnimationOptions)options animations:(dispatch_block_t)animations
               completion:(void (^)(BOOL))completion;
@end
@interface UILabel : UIView
@property(nonatomic, copy) NSString *text;
@property(nonatomic, strong) UIFont *font;
@property(nonatomic, strong) UIColor *textColor;
@property(nonatomic) NSInteger numberOfLines;
@property(nonatomic) NSTextAlignment textAlignment;
@property(nonatomic) BOOL adjustsFontSizeToFitWidth;
@end
@interface UIImage : NSObject
@property(nonatomic, copy) NSString *fixtureName;
@property(nonatomic, strong) NSData *fixtureData;
@property(nonatomic, strong) NSDictionary *fixtureDrawing;
@property(nonatomic) CGSize size;
@property(nonatomic) UIImageRenderingMode renderingMode;
+ (instancetype)systemImageNamed:(NSString *)name;
+ (instancetype)imageWithData:(NSData *)data;
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(id)traits;
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode;
@end
@interface UIImageView : UIView
@property(nonatomic, strong) UIImage *image;
- (instancetype)initWithImage:(UIImage *)image;
@end
@interface UIControl : UIView
@property(nonatomic, copy) NSString *accessibilityLabel;
@property(nonatomic, strong) NSMutableArray *fixtureTargets,*fixtureActions;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events;
- (void)addAction:(UIAction *)action forControlEvents:(UIControlEvents)events;
- (void)sendActionsForControlEvents:(UIControlEvents)events;
@end
@interface UIButton : UIControl
@property(nonatomic,getter=isHighlighted) BOOL highlighted;
@property(nonatomic, strong) UILabel *titleLabel;
@property(nonatomic, strong) UIMenu *menu;
@property(nonatomic) BOOL showsMenuAsPrimaryAction;
@property(nonatomic) UIEdgeInsets contentEdgeInsets;
@property(nonatomic, strong) UIImage *fixtureImage;
@property(nonatomic, copy) NSString *fixtureTitle;
@property(nonatomic, strong) NSMutableDictionary<NSNumber *,UIColor *> *fixtureTitleColors;
+ (instancetype)buttonWithType:(UIButtonType)type;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
@end
@interface UIBlurEffect : NSObject
@property(nonatomic) UIBlurEffectStyle fixtureStyle;
+ (instancetype)effectWithStyle:(UIBlurEffectStyle)style;
@end
@interface UIVisualEffectView : UIView
@property(nonatomic, strong) UIBlurEffect *effect;
@property(nonatomic, strong) UIView *contentView;
- (instancetype)initWithEffect:(UIBlurEffect *)effect;
@end
@interface UIProgressView : UIView
@property(nonatomic) float progress;
@property(nonatomic) BOOL fixtureAnimated;
@property(nonatomic, strong) UIColor *progressTintColor,*trackTintColor;
- (instancetype)initWithProgressViewStyle:(UIProgressViewStyle)style;
- (void)setProgress:(float)progress animated:(BOOL)animated;
@end
@interface UIActivityIndicatorView : UIView
@property(nonatomic, strong) UIColor *color;
@property(nonatomic) BOOL fixtureAnimating;
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style;
- (void)startAnimating; - (void)stopAnimating;
@end
@interface UIStackView : UIView
@property(nonatomic) UILayoutConstraintAxis axis;
@property(nonatomic) UIStackViewDistribution distribution;
@property(nonatomic) UIStackViewAlignment alignment;
@property(nonatomic) CGFloat spacing;
@property(nonatomic, readonly) NSArray<UIView *> *arrangedSubviews;
- (instancetype)initWithArrangedSubviews:(NSArray<UIView *> *)views;
- (void)addArrangedSubview:(UIView *)view;
- (void)removeArrangedSubview:(UIView *)view;
@end
@interface UIGestureRecognizer : NSObject
@property(nonatomic, weak) id fixtureTarget;
@property(nonatomic) SEL fixtureAction;
@property(nonatomic, weak) UIView *view;
@property(nonatomic) UIGestureRecognizerState state;
@property(nonatomic) CGPoint fixtureLocation;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
- (CGPoint)locationInView:(UIView *)view;
@end
@interface UITapGestureRecognizer : UIGestureRecognizer
@property(nonatomic) NSUInteger numberOfTapsRequired;
@end
@interface UIPanGestureRecognizer : UIGestureRecognizer
@property(nonatomic) CGPoint fixtureTranslation;
- (CGPoint)translationInView:(UIView *)view;
@end
@interface UILongPressGestureRecognizer : UIGestureRecognizer
@property(nonatomic) NSTimeInterval minimumPressDuration;
@end
@interface UIAction : NSObject
@property(nonatomic, copy) NSString *title;
@property(nonatomic, strong) UIImage *image;
@property(nonatomic, copy) void (^fixtureHandler)(UIAction *);
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier
                       handler:(void (^)(UIAction *))handler;
+ (instancetype)actionWithHandler:(void (^)(UIAction *))handler;
@end
@interface UIMenu : NSObject
@property(nonatomic, copy) NSString *title;
@property(nonatomic, strong) NSArray<UIAction *> *children;
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children;
@end
@interface UIBarButtonItem : NSObject
@property(nonatomic, strong) UIView *customView;
- (instancetype)initWithCustomView:(UIView *)view;
@end
@interface UINavigationItem : NSObject
@property(nonatomic, strong) UIBarButtonItem *leftBarButtonItem,*rightBarButtonItem;
@end
@interface UINavigationBar : UIView
@property(nonatomic) BOOL translucent;
@property(nonatomic, strong) UIImage *shadowImage,*fixtureBackgroundImage;
- (void)setBackgroundImage:(UIImage *)image forBarMetrics:(UIBarMetrics)metrics;
@end
@protocol UIViewControllerTransitionCoordinatorContext <NSObject>
@property(nonatomic,readonly,getter=isCancelled) BOOL cancelled;
@end
@protocol UIViewControllerTransitionCoordinator <NSObject>
- (BOOL)animateAlongsideTransition:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))animation
                       completion:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))completion;
@end
@protocol UIViewControllerTransitioningDelegate <NSObject>
@optional
- (UIPresentationController *)presentationControllerForPresentedViewController:(UIViewController *)presented
                                                    presentingViewController:(UIViewController *)presenting
                                                        sourceViewController:(UIViewController *)source;
@end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIView *view;
@property(nonatomic, strong) UINavigationItem *navigationItem;
@property(nonatomic, weak) UINavigationController *navigationController;
@property(nonatomic, strong) NSArray<UIViewController *> *childViewControllers;
@property(nonatomic, strong) UIViewController *presentedViewController;
@property(nonatomic, weak) UIViewController *presentingViewController;
@property(nonatomic, weak) id<UIViewControllerTransitioningDelegate> transitioningDelegate;
@property(nonatomic, strong) id<UIViewControllerTransitionCoordinator> transitionCoordinator;
@property(nonatomic, strong) UIPresentationController *presentationController;
@property(nonatomic, strong) UISheetPresentationController *sheetPresentationController;
@property(nonatomic, strong) UIPopoverPresentationController *popoverPresentationController;
@property(nonatomic) UIModalPresentationStyle modalPresentationStyle;
@property(nonatomic) CGSize preferredContentSize;
@property(nonatomic) NSUInteger fixtureDismissals,fixturePresentations,fixtureViewDidLoad,fixtureLayouts;
- (void)loadView; - (void)viewDidLoad; - (void)viewDidLayoutSubviews;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
@interface UINavigationController : UIViewController
@property(nonatomic, strong) UINavigationBar *navigationBar;
- (instancetype)initWithRootViewController:(UIViewController *)root;
@end
@protocol UIScrollViewDelegate <NSObject> @end
@interface UIScrollView : UIView
@property(nonatomic, weak) id<UIScrollViewDelegate> delegate;
@property(nonatomic) CGFloat minimumZoomScale,maximumZoomScale,zoomScale;
@property(nonatomic) BOOL showsHorizontalScrollIndicator,showsVerticalScrollIndicator;
@property(nonatomic) UIScrollViewDecelerationRate decelerationRate;
@property(nonatomic) CGSize contentSize;
@property(nonatomic) CGPoint contentOffset;
@property(nonatomic) UIEdgeInsets contentInset;
@property(nonatomic) CGRect fixtureZoomRect;
@property(nonatomic) BOOL fixtureZoomAnimated;
- (void)setZoomScale:(CGFloat)scale animated:(BOOL)animated;
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;
@end
@interface UIPresentationController : NSObject
@property(nonatomic, strong) UIViewController *presentedViewController;
@property(nonatomic, weak) UIViewController *presentingViewController;
@property(nonatomic, strong) UIView *containerView;
@property(nonatomic, readonly) UIView *presentedView;
@property(nonatomic) NSUInteger fixtureLayoutCalls;
- (instancetype)initWithPresentedViewController:(UIViewController *)presented presentingViewController:(UIViewController *)presenting;
- (CGRect)frameOfPresentedViewInContainerView;
- (void)containerViewWillLayoutSubviews;
- (void)presentationTransitionWillBegin;
- (void)dismissalTransitionWillBegin;
@end
@interface UISheetPresentationControllerDetent : NSObject
@property(nonatomic, copy) NSString *identifier;
@property(nonatomic) CGFloat fixtureHeight;
+ (instancetype)_detentWithIdentifier:(NSString *)identifier constant:(CGFloat)height;
@end
@interface UISheetPresentationController : UIPresentationController
@property(nonatomic, strong) NSArray<UISheetPresentationControllerDetent *> *detents;
@property(nonatomic) BOOL prefersGrabberVisible;
@property(nonatomic) CGFloat preferredCornerRadius;
@end
@interface UIPopoverPresentationController : NSObject
@property(nonatomic, strong) UIView *sourceView;
@property(nonatomic) CGRect sourceRect;
@property(nonatomic) UIPopoverArrowDirection permittedArrowDirections;
@end
@interface UIActivityViewController : UIViewController
@property(nonatomic, strong) NSArray *fixtureItems;
@property(nonatomic, strong) NSArray<UIActivityType> *excludedActivityTypes;
@property(nonatomic, copy) void (^completionWithItemsHandler)(UIActivityType,BOOL,NSArray *,NSError *);
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities;
@end
@interface UIScene : NSObject
@property(nonatomic) UISceneActivationState activationState;
@end
@interface UIWindowScene : UIScene
@property(nonatomic) UIInterfaceOrientation interfaceOrientation;
@property(nonatomic, strong) NSArray<UIWindow *> *windows;
@end
@interface UIWindow : UIView
@property(nonatomic, weak) UIWindowScene *windowScene;
@property(nonatomic) UIWindowLevel windowLevel;
@property(nonatomic, strong) UIViewController *rootViewController;
@property(nonatomic, getter=isKeyWindow) BOOL fixtureKeyWindow;
@property(nonatomic) NSUInteger fixtureResignCalls;
- (instancetype)initWithWindowScene:(UIWindowScene *)scene;
- (void)makeKeyAndVisible; - (void)resignKeyWindow;
- (BOOL)canBecomeKeyWindow;
@end
@protocol UIApplicationDelegate <NSObject>
@optional
@property(nonatomic, strong) UIWindow *window;
@end
@interface UIApplication : NSObject
@property(nonatomic, strong) id<UIApplicationDelegate> delegate;
@property(nonatomic, strong) NSSet<UIScene *> *connectedScenes;
@property(nonatomic, strong) NSArray<UIWindow *> *windows;
+ (instancetype)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL success))completion;
@end
@interface UIDevice : NSObject
@property(nonatomic) UIUserInterfaceIdiom userInterfaceIdiom;
@property(nonatomic, copy) NSString *model;
+ (instancetype)currentDevice;
@end
@interface UIScreen : NSObject
@property(nonatomic) CGRect bounds;
@property(nonatomic) CGFloat brightness;
@property(nonatomic) NSUInteger fixtureBrightnessWrites;
+ (instancetype)mainScreen;
@end
@interface UIImpactFeedbackGenerator : NSObject
@property(nonatomic) UIImpactFeedbackStyle fixtureStyle;
- (instancetype)initWithStyle:(UIImpactFeedbackStyle)style;
- (void)prepare; - (void)impactOccurred;
@end
@interface UIPasteboard : NSObject
@property(nonatomic, strong) UIImage *image;
+ (instancetype)generalPasteboard;
@end
@interface UIGraphicsImageRendererContext : NSObject
@property(nonatomic, strong) NSMutableDictionary *fixtureContext;
@property(nonatomic) CGContextRef fixtureCGContext;
@property(nonatomic, readonly) CGContextRef CGContext;
@end
@interface UIGraphicsImageRenderer : NSObject
@property(nonatomic) CGSize fixtureSize;
- (instancetype)initWithSize:(CGSize)size;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions;
@end
@interface NSValue (PresentationFixtureGeometry)
+ (instancetype)valueWithCGPoint:(CGPoint)point;
+ (instancetype)valueWithCGRect:(CGRect)rect;
- (CGPoint)CGPointValue;
- (CGRect)CGRectValue;
@end
FOUNDATION_EXPORT void UIImageWriteToSavedPhotosAlbum(UIImage *image,id target,SEL completion,void *context);
FOUNDATION_EXPORT void UIGraphicsBeginImageContextWithOptions(CGSize size,BOOL opaque,CGFloat scale);
FOUNDATION_EXPORT CGContextRef UIGraphicsGetCurrentContext(void);
FOUNDATION_EXPORT UIImage *UIGraphicsGetImageFromCurrentImageContext(void);
FOUNDATION_EXPORT void UIGraphicsEndImageContext(void);
