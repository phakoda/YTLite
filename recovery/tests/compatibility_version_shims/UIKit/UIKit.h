#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
@interface UIColor : NSObject @end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *accessibilityIdentifier;
@end
@interface UIView : NSObject
@property(nonatomic,strong) CALayer *layer;
- (void)layoutSubviews;
@end
@interface UIViewController : NSObject
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@class UITapGestureRecognizer;
