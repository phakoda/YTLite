#pragma once
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>
@interface YTAppDelegate : NSObject
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options;
- (void)appDidBecomeActive;
@end
@interface YTStartupAnimationViewController : UIViewController
- (void)playLottieAnimation;
- (void)forceDismissStartupAnimationAnimated:(BOOL)animated;
@end
@interface UIView (YTLStartupDarkMode)
- (BOOL)_mapkit_isDarkModeEnabled;
@end
@interface QTMIcon : NSObject
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color;
@end
FOUNDATION_EXPORT void YTLInstallStartupLifecycleEarlyHooks(void);
FOUNDATION_EXPORT void YTLInstallStartupLifecycleMainHooks(void);
FOUNDATION_EXPORT void YTLScheduleWelcome(void);
FOUNDATION_EXPORT void YTLFinalizePrimaryStartup(void);
