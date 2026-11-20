#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UIColor,UISlider,UILabel,UIButton,UITapGestureRecognizer,UIPanGestureRecognizer,NSLayoutConstraint;
@protocol UIGestureRecognizerDelegate <NSObject> @end
typedef NSInteger UIUserInterfaceIdiom;
enum { UIUserInterfaceIdiomPhone=0, UIUserInterfaceIdiomPad=1 };
@interface UIView:NSObject
@property(nonatomic) BOOL hidden;
@property(nonatomic,copy) NSString *accessibilityIdentifier,*accessibilityLabel;
@property(nonatomic,strong) NSArray *subviews;
- (void)layoutSubviews;
@end
@interface UIImage:NSObject
@property(nonatomic,copy) NSString *accessibilityIdentifier;
@end
@interface UIViewController:NSObject
@property(nonatomic,strong) UIView *view;
@property(nonatomic,strong) UIViewController *parentViewController;
- (void)viewDidLoad;
- (void)viewDidDisappear:(BOOL)animated;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UIDevice:NSObject
- (UIUserInterfaceIdiom)userInterfaceIdiom;
@end
@interface UIApplication:NSObject
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
FOUNDATION_EXPORT void GeneralAfter(dispatch_time_t when,dispatch_queue_t queue,dispatch_block_t block);
FOUNDATION_EXPORT dispatch_time_t GeneralTime(dispatch_time_t when,int64_t delta);
#define dispatch_after GeneralAfter
#define dispatch_time GeneralTime
