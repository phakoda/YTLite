#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#define CALayer TranslatorFixtureLayer
@interface CALayer : NSObject { CGColorRef _borderColor; }
@property CGFloat cornerRadius,borderWidth;
@property BOOL masksToBounds;
@property CGColorRef borderColor;
@property(nonatomic,weak) id owner;
- (void)renderInContext:(CGContextRef)context;
@end
