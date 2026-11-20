#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint ControlsFixtureConstraint
#define NSLayoutAnchor ControlsFixtureAnchor
@class UIImage,UIColor,UILabel,UIWindowScene,UIEvent,UISlider,UIProgressView,UIActivityIndicatorView,UIImageView,UIViewController;
enum {UILayoutConstraintAxisHorizontal=0,UILayoutConstraintAxisVertical=1,UIStackViewDistributionFillEqually=1,UIStackViewAlignmentCenter=3};
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
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value;
@end
@interface UIGestureRecognizer:NSObject
@property NSInteger state;
@property(weak) id target;
@property SEL action;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
@end
@interface UILongPressGestureRecognizer:UIGestureRecognizer
@property double minimumPressDuration;
@end
@interface UITapGestureRecognizer:UIGestureRecognizer @end
@interface UIPanGestureRecognizer:UIGestureRecognizer @end
@interface UIView:NSObject
@property BOOL hidden,clipsToBounds,translatesAutoresizingMaskIntoConstraints;
@property CGFloat alpha;
@property NSInteger tag;
@property(strong) UIColor *backgroundColor;
@property(strong) CALayer *layer;
@property(strong) NSMutableArray *subviews,*gestureRecognizers;
@property(readonly) UIView *safeAreaLayoutGuide;
@property(readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*centerYAnchor;
@property NSUInteger layoutCount;
- (void)addSubview:(UIView *)view;
- (UIView *)viewWithTag:(NSInteger)tag;
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (void)layoutIfNeeded;
- (void)layoutSubviews;
@end
@interface UIViewController:NSObject
@property(strong) UIViewController *parentViewController;
@end
@interface UIWindow:UIView
@property(strong) UIViewController *rootViewController;
@end
@interface UIVisualEffectView:UIView @end
@interface UIStackView:UIView
@property NSInteger axis,alignment,distribution;
@property CGFloat spacing;
@property(strong) NSMutableArray *arrangedSubviews;
- (instancetype)initWithArrangedSubviews:(NSArray *)views;
- (void)addArrangedSubview:(UIView *)view;
@end
@interface UIColor:NSObject
@property CGFloat alpha;
+ (instancetype)blackColor;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
@end
@interface UIImage:NSObject
@property(copy) NSString *name;
@property BOOL flips;
+ (instancetype)systemImageNamed:(NSString *)name;
- (void)setFlipsForRightToLeftLayoutDirection:(BOOL)flips;
@end
@interface UIButton:UIView
@property(copy) NSString *title,*accessibilityLabel;
@property(strong) UIImage *image;
@property(weak) id target;
@property SEL action;
@property BOOL overlay;
- (void)setTitle:(NSString *)title forState:(NSUInteger)state;
- (void)setImage:(UIImage *)image forState:(NSUInteger)state;
@end
