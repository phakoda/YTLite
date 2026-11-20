#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#define CALayer SheetLifecycleLayer
#define kCALayerMinXMinYCorner 1
#define kCALayerMaxXMinYCorner 2
typedef NS_ENUM(NSInteger,UIModalPresentationStyle){UIModalPresentationPageSheet=1,UIModalPresentationCustom=4};
@class UIViewController,UIPresentationController,UISheetPresentationController;
@protocol UIViewControllerTransitionCoordinatorContext <NSObject>
@property(nonatomic,readonly,getter=isCancelled) BOOL cancelled;
@end
@protocol UIViewControllerTransitionCoordinator <NSObject>
- (BOOL)animateAlongsideTransition:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))animation completion:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))completion;
@end
@protocol UIViewControllerTransitioningDelegate <NSObject>
- (UIPresentationController *)presentationControllerForPresentedViewController:(UIViewController *)presented presentingViewController:(UIViewController *)presenting sourceViewController:(UIViewController *)source;
@end
@interface CALayer:NSObject
@property(nonatomic) CGFloat cornerRadius;
@property BOOL masksToBounds;
@property NSUInteger maskedCorners;
@property NSUInteger radiusWrites;
@end
@interface UIColor:NSObject
@property CGFloat opacity;
+ (instancetype)blackColor;
- (instancetype)colorWithAlphaComponent:(CGFloat)value;
@end
@interface UITapGestureRecognizer:NSObject
@property(nonatomic,weak) id target;
@property SEL action;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
@end
@interface UIView:NSObject
@property CGRect frame,bounds;
@property CGFloat alpha;
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) NSMutableArray<UIView *> *children;
@property(nonatomic,strong) NSMutableArray<UITapGestureRecognizer *> *gestures;
@property(nonatomic,weak) UIView *superview;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addGestureRecognizer:(UITapGestureRecognizer *)gesture;
- (void)addSubview:(UIView *)view;
- (void)removeFromSuperview;
@end
@interface UIViewController:NSObject
@property(nonatomic,strong) UIView *view;
@property(nonatomic,strong) NSArray<UIViewController *> *childViewControllers;
@property(nonatomic,strong) NSArray *_sections;
@property(nonatomic,weak) id<UIViewControllerTransitioningDelegate> transitioningDelegate;
@property(nonatomic,strong) id<UIViewControllerTransitionCoordinator> transitionCoordinator;
@property(nonatomic,strong) UIPresentationController *presentationController;
@property(nonatomic,strong) UISheetPresentationController *sheetPresentationController;
@property UIModalPresentationStyle modalPresentationStyle;
@property CGSize preferredContentSize;
@property NSUInteger dismissals,viewReads;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UIPresentationController:NSObject
@property(nonatomic,strong) UIViewController *presentedViewController,*presentingViewController;
@property(nonatomic,strong) UIView *containerView;
@property(nonatomic,readonly) UIView *presentedView;
@property NSUInteger layouts;
- (instancetype)initWithPresentedViewController:(UIViewController *)presented presentingViewController:(UIViewController *)presenting;
- (CGRect)frameOfPresentedViewInContainerView;
- (void)containerViewWillLayoutSubviews;
@end
@interface UISheetPresentationControllerDetent:NSObject
@property(nonatomic,copy) NSString *identifier;
@property CGFloat height;
+ (instancetype)_detentWithIdentifier:(NSString *)identifier constant:(CGFloat)height;
@end
@interface UISheetPresentationController:UIPresentationController
@property(nonatomic,strong) NSArray<UISheetPresentationControllerDetent *> *detents;
@property BOOL prefersGrabberVisible;
@property CGFloat preferredCornerRadius;
@end
BOOL SheetNativeAvailable(void);
