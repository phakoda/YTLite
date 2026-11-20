#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@interface UIView:NSObject
@property(nonatomic) CGFloat alpha;
@property(nonatomic) CGRect bounds;
@property(nonatomic,strong) UIView *superview;
@property(nonatomic,copy) NSArray<UIView *> *subviews;
@property(nonatomic) BOOL hidden;
- (void)layoutSubviews;
- (void)didMoveToWindow;
@end
@interface UIColor:NSObject<NSSecureCoding>
@property(nonatomic,readonly) CGColorRef CGColor;
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b;
@end
@interface UIImage:NSObject
@property(copy) NSString *text;
@end
@interface UIButton:UIView
@property(strong) UIImage *currentImage;
@end
@interface UIGestureRecognizer:NSObject
@property(strong) UIView *view;
@property CGPoint point;
- (CGPoint)locationInView:(UIView *)view;
@end
@interface UILongPressGestureRecognizer:UIGestureRecognizer @end
