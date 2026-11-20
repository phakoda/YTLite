#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
@class UIColor,UIImage,UIViewController,UIWindow,UIWindowScene,UIEvent,UITapGestureRecognizer,UIPanGestureRecognizer,UILongPressGestureRecognizer,UILabel,UIProgressView,UIImageView,UIStackView,UIActivityIndicatorView,NSLayoutConstraint,UITableView,UIDocumentPickerViewController;
@protocol UITableViewDataSource @end
@protocol UITableViewDelegate @end
@interface UIView : NSObject
- (instancetype)initWithFrame:(CGRect)frame;
@property(nonatomic) CGRect frame,bounds;
@property(nonatomic) NSUInteger autoresizingMask;
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) NSMutableArray<UIView *> *subviews;
- (void)addSubview:(UIView *)view;
@end
@interface UIVisualEffectView : UIView @end
@interface UIColor : NSObject
+ (instancetype)blackColor;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *accessibilityIdentifier;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIView *view;
@property(nonatomic) NSInteger modalPresentationStyle;
@property(nonatomic) BOOL modalInPresentation;
- (void)viewDidLoad;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
@interface UIWindow : UIView
@property(nonatomic,strong) UIViewController *rootViewController;
@end
@interface UIAction : NSObject
+ (instancetype)actionWithHandler:(void (^)(UIAction *))handler;
@property(nonatomic,copy) void (^handler)(UIAction *);
@end
@interface UIButton : UIView
+ (instancetype)buttonWithType:(NSInteger)type;
- (void)addAction:(UIAction *)action forControlEvents:(NSUInteger)events;
@property(nonatomic,strong) UIAction *action;
@end
@interface UIApplication : NSObject
+ (instancetype)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@interface UIPasteboard : NSObject
+ (instancetype)generalPasteboard;
@property(nonatomic,copy) NSString *string;
@end
FOUNDATION_EXPORT NSString *const UIApplicationDidEnterBackgroundNotification;
enum { UIViewAutoresizingFlexibleWidth=2,UIViewAutoresizingFlexibleHeight=16,UIButtonTypeCustom=0,UIControlEventTouchUpInside=64,UIModalPresentationFormSheet=2 };
