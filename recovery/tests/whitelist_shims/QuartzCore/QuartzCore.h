#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#define CALayer WhitelistLayer
@interface CALayer : NSObject { CGColorRef _borderColor; }
@property CGFloat cornerRadius,borderWidth;
@property CGColorRef borderColor;
@property(nonatomic,weak) id owner;
- (void)renderInContext:(CGContextRef)context;
@end
