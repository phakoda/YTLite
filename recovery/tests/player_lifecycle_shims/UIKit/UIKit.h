#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class CALayer,UIColor,UIImage,UIButton,UILongPressGestureRecognizer,UITapGestureRecognizer;
@interface UIView:NSObject @end
@interface UIViewController:NSObject
@property(nonatomic,strong) UIViewController *parentViewController;
@property(nonatomic,strong) UIView *view;
@end
@interface UILabel:UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic) NSUInteger fixtureFits;
- (void)sizeToFit;
@end
