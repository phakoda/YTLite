#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@protocol UIGestureRecognizerDelegate <NSObject> @end
@interface UIView:NSObject
@property(nonatomic) CGRect bounds;
@property(nonatomic,strong) NSArray *ancestors;
@property(nonatomic) NSUInteger ancestorReads;
@end
@interface UIViewController:NSObject
@property(nonatomic,strong) UIView *view;
@end
@interface UIGestureRecognizer:NSObject
@property(nonatomic,strong) UIView *view;
@end
@interface UIPanGestureRecognizer:UIGestureRecognizer
@property(nonatomic) CGPoint velocity;
@property(nonatomic) NSUInteger velocityReads;
@property(nonatomic,weak) UIView *velocityView;
- (CGPoint)velocityInView:(UIView *)view;
@end
@interface UITouch:NSObject
@property(nonatomic) CGPoint point;
@property(nonatomic) NSUInteger reads;
@property(nonatomic,weak) UIView *locationView;
- (CGPoint)locationInView:(UIView *)view;
@end
@interface UIApplication:NSObject
@property(nonatomic,strong) id delegate;
+ (instancetype)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
