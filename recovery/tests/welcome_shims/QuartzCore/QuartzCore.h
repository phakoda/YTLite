#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#define CALayer WelcomeFixtureLayer
#define kCACornerCurveContinuous @"continuous"
enum { kCALayerMinXMinYCorner=1, kCALayerMaxXMinYCorner=2 };
@interface CALayer : NSObject
@property CGFloat cornerRadius;
@property(copy) NSString *cornerCurve;
@property NSUInteger maskedCorners;
@property BOOL masksToBounds;
@property(weak) id owner;
- (void)renderInContext:(CGContextRef)context;
@end
