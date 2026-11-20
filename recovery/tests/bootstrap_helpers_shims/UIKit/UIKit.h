#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@interface UIColor : NSObject
+ (instancetype)whiteColor;
@end
@interface UIView : NSObject
@property(nonatomic) CGPoint center;
@property(nonatomic, strong) NSMutableArray *subviews;
- (void)addSubview:(UIView *)view;
@end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIView *view;
@property(nonatomic) NSUInteger loaded;
@property(nonatomic) BOOL dismissed;
@property(nonatomic, copy) dispatch_block_t dismissal;
- (void)viewDidLoad;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
typedef NS_ENUM(NSInteger, UIActivityIndicatorViewStyle) { UIActivityIndicatorViewStyleLarge = 101 };
@interface UIActivityIndicatorView : UIView
@property(nonatomic) UIActivityIndicatorViewStyle style;
@property(nonatomic, strong) UIColor *color;
@property(nonatomic) BOOL animating;
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style;
- (void)startAnimating;
@end
