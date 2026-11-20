#pragma once
// Test-only UIKit boundary for the actual YTPMedia implementation.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <dispatch/dispatch.h>
@interface UITraitCollection : NSObject @end
@interface UIColor : NSObject
@property(nonatomic) CGFloat red, green, blue, alpha;
@property(nonatomic) BOOL cannotDecode;
@property(nonatomic,copy) UIColor *(^provider)(UITraitCollection *);
+ (UIColor *)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider;
+ (UIColor *)blackColor;
+ (UIColor *)whiteColor;
- (BOOL)getRed:(CGFloat *)red green:(CGFloat *)green blue:(CGFloat *)blue alpha:(CGFloat *)alpha;
@end
@interface UIImage : NSObject
@property(nonatomic,strong) id name;
@property(nonatomic,strong) UIColor *tint;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) id delegate;
+ (UIApplication *)sharedApplication;
@end
