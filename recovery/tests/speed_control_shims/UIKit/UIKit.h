#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutAnchor SpeedControlAnchor
#define NSLayoutConstraint SpeedControlConstraint
typedef NS_ENUM(NSInteger, NSTextAlignment) { NSTextAlignmentCenter=1 };
typedef NS_ENUM(NSInteger, UIButtonType) { UIButtonTypeCustom=0 };
typedef NS_ENUM(NSInteger, UIControlState) { UIControlStateNormal=0 };
typedef NS_OPTIONS(NSUInteger, UIControlEvents) { UIControlEventTouchUpInside=0x40, UIControlEventValueChanged=0x1000 };
typedef NS_ENUM(NSInteger, UILayoutConstraintAxis) { UILayoutConstraintAxisHorizontal=0, UILayoutConstraintAxisVertical=1 };
typedef NS_ENUM(NSInteger, UIStackViewAlignment) { UIStackViewAlignmentFill=0, UIStackViewAlignmentCenter=3 };
typedef NS_ENUM(NSInteger, UIStackViewDistribution) { UIStackViewDistributionFillEqually=1 };
static const CGFloat UIFontWeightMedium=0.23;
@class UIView, UIGestureRecognizer, NSLayoutAnchor;
@interface NSLayoutConstraint : NSObject
@property(nonatomic) BOOL active;
@property(nonatomic,strong) NSLayoutAnchor *firstAnchor,*secondAnchor;
@property(nonatomic) CGFloat constant;
+ (void)activateConstraints:(NSArray *)constraints;
@end
@interface NSLayoutAnchor : NSObject
@property(nonatomic,weak) UIView *owner;
@property(nonatomic,copy) NSString *name;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)other constant:(CGFloat)value;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value;
@end
@interface UIColor : NSObject { CGColorRef _CGColor; }
@property(nonatomic,readonly) CGColorRef CGColor;
@property(nonatomic,copy) NSString *name;
@property(nonatomic) CGFloat alpha;
+ (instancetype)labelColor;
+ (instancetype)blackColor;
+ (instancetype)whiteColor;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
- (void)setFill;
@end
@interface UIFont : NSObject
@property(nonatomic) CGFloat pointSize,weight;
@property(nonatomic) BOOL bold;
+ (instancetype)boldSystemFontOfSize:(CGFloat)size;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(CGFloat)weight;
@end
@interface UIImage : NSObject { CGImageRef _image; }
@property(nonatomic,copy) NSString *name;
@property(nonatomic,readonly) CGImageRef CGImage;
+ (instancetype)systemImageNamed:(NSString *)name;
- (instancetype)initWithCGImage:(CGImageRef)image;
@end
@interface UIView : NSObject
@property(nonatomic) CGRect frame,bounds;
@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints;
@property(nonatomic,strong) UIColor *backgroundColor,*tintColor;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,weak) UIView *superview;
@property(nonatomic,strong) NSMutableArray *subviews,*gestureRecognizers;
@property(nonatomic) NSInteger tag;
@property(nonatomic,readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*widthAnchor,*heightAnchor;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
- (void)addGestureRecognizer:(UIGestureRecognizer *)recognizer;
@end
@interface UILabel : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,strong) UIColor *textColor;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic) NSTextAlignment textAlignment;
@end
@interface SpeedControlAction : NSObject
@property(nonatomic,weak) id target;
@property(nonatomic) SEL selector;
@property(nonatomic) UIControlEvents events;
@end
@interface UIControl : UIView
@property(nonatomic,strong) NSMutableArray<SpeedControlAction *> *actions;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events;
- (void)fire:(UIControlEvents)events;
@end
@interface UIButton : UIControl
@property(nonatomic,strong) UILabel *titleLabel;
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UIColor *titleColor;
@property(nonatomic) UIButtonType buttonType;
+ (instancetype)buttonWithType:(UIButtonType)type;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
@end
@interface UISlider : UIControl
@property(nonatomic) float minimumValue,maximumValue,value;
@property(nonatomic,strong) UIColor *minimumTrackTintColor,*maximumTrackTintColor;
@property(nonatomic,strong) UIImage *thumb;
@property(nonatomic,strong) NSMutableArray *minimumSequence,*writes;
- (void)setThumbImage:(UIImage *)image forState:(UIControlState)state;
@end
@interface UIGestureRecognizer : NSObject
@property(nonatomic,weak) id target;
@property(nonatomic,weak) UIView *view;
@property(nonatomic) SEL action;
@property(nonatomic) CGPoint location;
- (instancetype)initWithTarget:(id)target action:(SEL)action;
- (CGPoint)locationInView:(UIView *)view;
@end
@interface UITapGestureRecognizer : UIGestureRecognizer @end
@interface UILongPressGestureRecognizer : UIGestureRecognizer @end
@interface UIStackView : UIView
@property(nonatomic,strong) NSArray *arrangedSubviews;
@property(nonatomic) UILayoutConstraintAxis axis;
@property(nonatomic) CGFloat spacing;
@property(nonatomic) UIStackViewAlignment alignment;
@property(nonatomic) UIStackViewDistribution distribution;
- (instancetype)initWithArrangedSubviews:(NSArray *)views;
@end
@interface UIGraphicsImageRendererContext : NSObject
@property(nonatomic) CGContextRef CGContext;
@end
@interface UIGraphicsImageRenderer : NSObject
@property(nonatomic) CGSize size;
- (instancetype)initWithSize:(CGSize)size;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions;
@end
