#pragma once
// Host-only UIKit message doubles. iOS builds use the actual SDK header.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>

typedef NS_OPTIONS(NSUInteger, UIRectCorner) {
    UIRectCornerTopLeft = 1UL << 0,
    UIRectCornerTopRight = 1UL << 1,
    UIRectCornerBottomLeft = 1UL << 2,
    UIRectCornerBottomRight = 1UL << 3,
    UIRectCornerAllCorners = ~0UL,
};

@interface UIView : NSObject
@property(nonatomic) CGRect frame;
@property(nonatomic) CGRect bounds;
@property(nonatomic, strong) CALayer *layer;
@property(nonatomic, weak) UIView *superview;
@property(nonatomic, strong) id window;
@property(nonatomic, strong) id recoveredAncestor;
- (id)_viewControllerForAncestor;
@end

@interface UILabel : UIView
@property(nonatomic, copy) NSString *text;
@property(nonatomic) NSUInteger sizeToFitCalls;
- (void)sizeToFit;
@end

@interface UIColor : NSObject <NSSecureCoding> {
@private
    CGColorRef _color;
}
@property(nonatomic, readonly) CGColorRef CGColor;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
@end

@interface UIBezierPath : NSObject {
@private
    CGPathRef _path;
}
@property(nonatomic, readonly) CGPathRef CGPath;
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)corners
                            cornerRadii:(CGSize)radii;
+ (NSMutableArray<NSDictionary *> *)recoveredCalls;
@end
