#pragma once
// TEST-ONLY Core Animation state recorder. No window server or rendering daemon.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

// Foundation/CoreGraphics may load QuartzCore transitively on macOS. Never
// register a duplicate system class or call the real animation/window server.
#define CAMediaTimingFunction PresentationFixtureTimingFunction
#define CAAnimation PresentationFixtureAnimation
#define CABasicAnimation PresentationFixtureBasicAnimation
#define CALayer PresentationFixtureLayer
#define CAShapeLayer PresentationFixtureShapeLayer
#define CATransaction PresentationFixtureTransaction

typedef struct CATransform3D {
    CGFloat m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44;
} CATransform3D;
FOUNDATION_EXPORT const CATransform3D CATransform3DIdentity;
FOUNDATION_EXPORT CATransform3D CATransform3DMakeScale(CGFloat x, CGFloat y, CGFloat z);
FOUNDATION_EXPORT CATransform3D CATransform3DMakeTranslation(CGFloat x, CGFloat y, CGFloat z);
typedef NSString *CAMediaTimingFunctionName;
typedef NSString *CACornerCurve;
typedef NSUInteger CACornerMask;
enum { kCALayerMinXMinYCorner = 1, kCALayerMaxXMinYCorner = 2 };
FOUNDATION_EXPORT CACornerCurve const kCACornerCurveContinuous;
FOUNDATION_EXPORT NSString *const kCAFillModeForwards;
FOUNDATION_EXPORT CAMediaTimingFunctionName const kCAMediaTimingFunctionLinear;
FOUNDATION_EXPORT CAMediaTimingFunctionName const kCAMediaTimingFunctionEaseIn;
FOUNDATION_EXPORT CAMediaTimingFunctionName const kCAMediaTimingFunctionEaseInEaseOut;

@interface CAMediaTimingFunction : NSObject
@property(nonatomic, copy) NSString *name;
+ (instancetype)functionWithName:(CAMediaTimingFunctionName)name;
@end
@interface CAAnimation : NSObject
@property(nonatomic) NSTimeInterval duration;
@property(nonatomic) BOOL removedOnCompletion;
@property(nonatomic, copy) NSString *fillMode;
@property(nonatomic, strong) CAMediaTimingFunction *timingFunction;
@end
@interface CABasicAnimation : CAAnimation
@property(nonatomic, copy) NSString *keyPath;
@property(nonatomic, strong) id fromValue,toValue;
+ (instancetype)animationWithKeyPath:(NSString *)path;
@end
@interface CALayer : NSObject {
    CGColorRef _backgroundColor, _borderColor, _shadowColor;
}
@property(nonatomic) CGRect frame,bounds;
@property(nonatomic) CGPoint position;
@property(nonatomic) CATransform3D transform;
@property(nonatomic) float opacity,shadowOpacity;
@property(nonatomic) CGFloat cornerRadius,borderWidth,shadowRadius;
@property(nonatomic) CGSize shadowOffset;
@property(nonatomic) BOOL masksToBounds;
@property(nonatomic) CACornerMask maskedCorners;
@property(nonatomic, copy) CACornerCurve cornerCurve;
@property(nonatomic) CGColorRef backgroundColor,borderColor,shadowColor;
@property(nonatomic, weak) CALayer *superlayer;
@property(nonatomic, weak) id fixtureOwner;
@property(nonatomic, strong) CALayer *presentationLayer;
@property(nonatomic, strong) NSMutableArray<CALayer *> *sublayers;
@property(nonatomic, strong) NSMutableDictionary<NSString *,CAAnimation *> *fixtureAnimations;
+ (instancetype)layer;
- (void)addSublayer:(CALayer *)layer;
- (void)addAnimation:(CAAnimation *)animation forKey:(NSString *)key;
- (void)removeAllAnimations;
- (void)renderInContext:(CGContextRef)context;
@end
@interface CAShapeLayer : CALayer @end
@interface CATransaction : NSObject
+ (void)begin;
+ (void)commit;
+ (void)setCompletionBlock:(dispatch_block_t)completion;
+ (void)setDisableActions:(BOOL)disabled;
+ (void)setAnimationDuration:(CFTimeInterval)duration;
@end
@interface NSValue (PresentationFixtureTransforms)
+ (instancetype)valueWithCATransform3D:(CATransform3D)transform;
- (CATransform3D)CATransform3DValue;
@end
