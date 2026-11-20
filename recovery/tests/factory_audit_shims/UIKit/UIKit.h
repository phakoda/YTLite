#pragma once
// Only declarations needed to compile the whole ToastManager source. No UI runs.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UILabel,UIProgressView,UIImageView,UIStackView,UIButton,UIActivityIndicatorView,NSLayoutConstraint,UIPanGestureRecognizer,UILongPressGestureRecognizer,UIImage,UIViewController,UIEvent,UIWindowScene;
@interface UIView : NSObject
@property(nonatomic) BOOL hidden;
@end
@interface UIVisualEffectView : UIView @end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIView *view;
@end
@interface UIScene : NSObject
@property(nonatomic) NSInteger activationState;
@end
@interface UIWindow : UIView
@property(nonatomic) BOOL isKeyWindow;
@end
@interface UIWindowScene : UIScene
@property(nonatomic,strong) NSArray<UIWindow *> *windows;
@end
@protocol UIApplicationDelegate <NSObject>
@property(nonatomic,strong) UIWindow *window;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) id<UIApplicationDelegate> delegate;
@property(nonatomic,strong) NSSet<UIScene *> *connectedScenes;
+ (instancetype)sharedApplication;
@end
@interface UIImpactFeedbackGenerator : NSObject
- (instancetype)initWithStyle:(NSInteger)style;
- (void)prepare;
- (void)impactOccurred;
@end
@interface UIPopoverPresentationController : NSObject
@property(nonatomic,strong) UIView *sourceView;
@property(nonatomic) CGRect sourceRect;
@property(nonatomic) NSUInteger permittedArrowDirections;
@end
@interface UIActivityViewController : UIViewController
@property(nonatomic,strong) UIPopoverPresentationController *popoverPresentationController;
@end
@interface UIScreen : NSObject
@property(nonatomic) CGRect bounds;
+ (instancetype)mainScreen;
@end
enum { UISceneActivationStateForegroundActive=0,UIImpactFeedbackStyleMedium=1,UIPopoverArrowDirectionAny=15 };
