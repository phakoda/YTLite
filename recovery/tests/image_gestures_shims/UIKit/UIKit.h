#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UIViewController;
@interface UIView : NSObject
@property(nonatomic) CGFloat alpha;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void(^)(void))animations;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIViewController *parentViewController;
@property(nonatomic,strong) UIView *view;
@end
@interface UIWindow : UIView
@property(nonatomic,strong) UIViewController *rootViewController;
@end
@protocol UIApplicationDelegate <NSObject>
@property(nonatomic,strong) UIWindow *window;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) id<UIApplicationDelegate> delegate;
+ (UIApplication *)sharedApplication;
@end
@interface UIGestureRecognizer : NSObject @end
@interface UIPinchGestureRecognizer : UIGestureRecognizer
@property(nonatomic) CGFloat scale;
@end
