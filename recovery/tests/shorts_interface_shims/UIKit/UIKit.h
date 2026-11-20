#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint ShortsFixtureConstraint
#define NSLayoutAnchor ShortsFixtureAnchor
@class UIViewController,UIImage,UIColor,UILabel,UIImageView,UIVisualEffectView,UITouch;
@protocol UIGestureRecognizerDelegate <NSObject> @end
@interface NSLayoutConstraint:NSObject
@property(strong) id firstAnchor,secondAnchor;
@property CGFloat constant;
@property(nonatomic) BOOL active;
@end
@interface NSLayoutAnchor:NSObject
@property(weak) id owner;
@property(copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value;
@end
@interface UIGestureRecognizer:NSObject
@property NSInteger state;
@property(weak) id target;
@property SEL action;
@property(weak) id<UIGestureRecognizerDelegate> delegate;
@property CGPoint location;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
- (CGPoint)locationInView:(id)view;
@end
@interface UILongPressGestureRecognizer:UIGestureRecognizer
@property double minimumPressDuration;
@property NSUInteger numberOfTouchesRequired;
@end
enum {UIGestureRecognizerStateBegan=1,UIGestureRecognizerStateEnded=3,UIGestureRecognizerStateCancelled=4};
@interface UIView:NSObject
@property(nonatomic,getter=isHidden) BOOL hidden;
@property(nonatomic) CGFloat alpha;
@property(nonatomic) NSInteger tag;
@property(strong) CALayer *layer;
@property(strong) NSMutableArray *subviews,*gestureRecognizers;
@property(readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*centerXAnchor,*widthAnchor,*heightAnchor;
- (void)addSubview:(UIView *)view;
- (UIView *)viewWithTag:(NSInteger)tag;
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (void)layoutSubviews;
@end
@interface UIViewController:NSObject
@property(strong) UIViewController *parentViewController,*navigationController;
- (void)viewDidAppear:(BOOL)animated;
@end
@interface UIWindow:UIView
@property(strong) UIViewController *rootViewController;
@end
@protocol UIApplicationDelegate <NSObject>
- (UIWindow *)window;
@end
@interface UIApplication:NSObject
+ (instancetype)sharedApplication;
@property(strong) id<UIApplicationDelegate> delegate;
@end
@interface UIColor:NSObject
+ (instancetype)blackColor;
+ (instancetype)whiteColor;
- (CGColorRef)CGColor;
@end
@interface UIImage:NSObject @end
@interface UIButton:UIView
@property(weak) id target;
@property SEL action;
@property CGSize requestedSize;
@end
