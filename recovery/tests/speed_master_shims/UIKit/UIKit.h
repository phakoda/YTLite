#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UIColor,UIImage,UIImageView,UILabel,UIProgressView,UIStackView,UIButton,UIActivityIndicatorView,NSLayoutConstraint,UIPanGestureRecognizer,UIViewController,UIWindow;
@interface UIView:NSObject @end
@interface UIVisualEffectView:UIView @end
@interface UIApplication:NSObject
@property(strong) id delegate;
+ (instancetype)sharedApplication;
@end
enum {UIGestureRecognizerStateBegan=1,UIGestureRecognizerStateChanged=2,UIGestureRecognizerStateEnded=3,UIGestureRecognizerStateCancelled=4,UIGestureRecognizerStateFailed=5};
@interface UILongPressGestureRecognizer:NSObject
@property(nonatomic) NSInteger state;
@property(strong) UIView *view;
@property CGPoint point;
@property(strong) NSMutableArray *states;
@property NSUInteger stateReads;
@property NSUInteger locationReads;
- (CGPoint)locationInView:(UIView *)view;
@end
