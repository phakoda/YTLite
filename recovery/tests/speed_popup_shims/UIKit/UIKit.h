#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint SpeedPopupConstraint
#define NSLayoutAnchor SpeedPopupAnchor
typedef struct {CGFloat top,left,bottom,right;} UIEdgeInsets;
typedef NSUInteger UIViewAnimationOptions;
enum {UIModalPresentationOverFullScreen=6,UIModalTransitionStyleCrossDissolve=2,UIViewAnimationOptionCurveEaseIn=0x10000,UIViewAnimationOptionCurveEaseOut=0x20000,UIUserInterfaceIdiomPad=1,UIGestureRecognizerStateBegan=1,UIGestureRecognizerStateChanged=2,UIGestureRecognizerStateEnded=3,UIGestureRecognizerStateCancelled=4};
@class UIView,UIViewController,NSLayoutConstraint,NSLayoutAnchor,UILayoutGuide,UILabel,UISlider,UIButton;
@class UIGestureRecognizer,UITouch;
@protocol UIGestureRecognizerDelegate <NSObject>
- (BOOL)gestureRecognizer:(UIGestureRecognizer*)g shouldReceiveTouch:(UITouch*)t;
@end
@interface UIColor:NSObject
@property CGFloat alpha;
@property(copy) NSString *name;
+ (instancetype)blackColor;
+ (instancetype)labelColor;
+ (instancetype)clearColor;
- (UIColor*)colorWithAlphaComponent:(CGFloat)a;
@end
@interface NSLayoutConstraint:NSObject
@property CGFloat constant;
@property(strong) NSLayoutAnchor *first,*second;
+ (void)activateConstraints:(NSArray*)c;
@end
@interface NSLayoutAnchor:NSObject
@property(weak) id owner;
@property(copy) NSString *attribute;
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)a;
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)a constant:(CGFloat)c;
- (NSLayoutConstraint*)constraintEqualToConstant:(CGFloat)c;
@end
@interface UILayoutGuide:NSObject
@property(strong) NSLayoutAnchor *bottomAnchor;
@end
@interface UIGestureRecognizer:NSObject
@property(nonatomic) NSInteger state;
@property(strong) UIView *view;
@property(weak) id target,delegate;
@property SEL action;
@property(strong) NSMutableArray *states;
@property NSUInteger stateReads;
- (instancetype)initWithTarget:(id)t action:(SEL)a;
@end
@interface UITapGestureRecognizer:UIGestureRecognizer @end
@interface UIPanGestureRecognizer:UIGestureRecognizer
@property CGPoint translation,velocity;
@property(weak) UIView *coordinateView;
@property NSUInteger translationReads,velocityReads;
- (CGPoint)translationInView:(UIView*)v;
- (CGPoint)velocityInView:(UIView*)v;
@end
@interface UITouch:NSObject
@property(strong) UIView *view;
@end
@interface UIView:NSObject
@property CGRect bounds;
@property(strong) UIColor *backgroundColor;
@property(strong) CALayer *layer;
@property BOOL translatesAutoresizingMaskIntoConstraints;
@property(strong) NSMutableArray *subviews,*gestures;
@property(strong) NSLayoutAnchor *bottomAnchor,*topAnchor,*centerXAnchor,*widthAnchor,*heightAnchor;
@property(strong) UILayoutGuide *safeAreaLayoutGuide;
@property NSUInteger layouts;
- (void)addSubview:(UIView*)v;
- (void)addGestureRecognizer:(UIGestureRecognizer*)g;
- (void)layoutIfNeeded;
+ (void)animateWithDuration:(double)d delay:(double)delay usingSpringWithDamping:(double)damping initialSpringVelocity:(double)velocity options:(UIViewAnimationOptions)o animations:(void(^)(void))a completion:(void(^)(BOOL))c;
@end
@interface UIViewController:NSObject
@property(strong) UIView *view;
@property NSInteger modalPresentationStyle,modalTransitionStyle;
@property NSUInteger loads,appearances,dismissals;
@property BOOL lastAnimated;
@property(strong) UIViewController *presented;
- (void)viewDidLoad;
- (void)viewDidAppear:(BOOL)a;
- (void)presentViewController:(UIViewController*)v animated:(BOOL)a completion:(void(^)(void))c;
- (void)dismissViewControllerAnimated:(BOOL)a completion:(void(^)(void))c;
@end
@interface UIDevice:NSObject
@property NSInteger userInterfaceIdiom;
@property(copy) NSString *model;
+ (instancetype)currentDevice;
@end
@interface UIScreen:NSObject
@property CGRect bounds;
+ (instancetype)mainScreen;
@end
@interface UIWindow:UIView
@property UIEdgeInsets safeAreaInsets;
@end
@protocol UIApplicationDelegate <NSObject>
@property(strong) UIWindow *window;
@end
@interface UIApplication:NSObject
@property(strong) id<UIApplicationDelegate> delegate;
+ (instancetype)sharedApplication;
@end
