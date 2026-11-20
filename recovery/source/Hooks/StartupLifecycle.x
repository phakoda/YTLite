#import "StartupLifecycleHost.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import "../Downloads/YTPMedia.h"
#import "../Presentation/ToastView.h"
#import <objc/runtime.h>
#import "../Welcome/WelcomeVC.h"
#import "../Support/YTPDB.h"
#import "../Presentation/ToastWindow.h"

static void YTLStartupRemoveObservers(NSArray *observers) {
    for (id observer in observers) [[NSNotificationCenter defaultCenter] removeObserver:observer];
}
%group YTLStartupLifecycleEarly
%hook YTAppDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    if ([[YTLUserDefaults standardUserDefaults] boolForKey:@"autoClearCache"]) {
        dispatch_async(dispatch_get_global_queue(0,0), ^{
            NSString *cache=NSSearchPathForDirectoriesInDomains(NSCachesDirectory,NSUserDomainMask,YES).firstObject;
            [[NSFileManager defaultManager] removeItemAtPath:cache error:nil];
            [[NSFileManager defaultManager] removeItemAtPath:NSTemporaryDirectory() error:nil];
        });
    }
    return %orig;
}
%end
%hook YTStartupAnimationViewController
- (void)viewDidLoad {
    %orig;
    if ([[YTLUserDefaults standardUserDefaults] boolForKey:@"oledTheme"] && [self.view _mapkit_isDarkModeEnabled]) self.view.backgroundColor=UIColor.blackColor;
}
- (void)playLottieAnimation {
    if ([[YTLUserDefaults standardUserDefaults] integerForKey:@"startupAnimation"]!=3) { %orig; return; }
    NSString *documents=NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject;
    NSString *path=nil;
    for (NSString *extension in @[@"mp4",@"mov"]) {
        NSString *candidate=[documents stringByAppendingPathComponent:[NSString stringWithFormat:@"startup_animation.%@",extension]];
        if ([[NSFileManager defaultManager] fileExistsAtPath:candidate]) { path=candidate; break; }
    }
    if (!path) { %orig; return; }
    UIView *cover=[[UIView alloc] initWithFrame:self.view.bounds];
    cover.backgroundColor=[YTPMedia adaptiveBackgroundColor];
    cover.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:cover];
    AVAudioSession *audio=[AVAudioSession sharedInstance];
    [audio setCategory:AVAudioSessionCategoryPlayback withOptions:AVAudioSessionCategoryOptionDuckOthers error:nil];
    [audio setActive:YES error:nil];
    AVPlayer *player=[AVPlayer playerWithURL:[NSURL fileURLWithPath:path]];
    AVPlayerLayer *layer=[AVPlayerLayer playerLayerWithPlayer:player];
    layer.frame=self.view.bounds;
    layer.videoGravity=AVLayerVideoGravityResizeAspectFill;
    layer.opacity=0;
    [self.view.layer addSublayer:layer];
    [player play];
    [CATransaction begin];
    [CATransaction setAnimationDuration:0.2];
    layer.opacity=1;
    [CATransaction commit];
    // Original block copy/dispose retains the layer only; the controller capture is raw.
    __unsafe_unretained YTStartupAnimationViewController *controller=self;
    void (^finish)(void)=^{
        [[AVAudioSession sharedInstance] setActive:NO withOptions:AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation error:nil];
        [CATransaction begin];
        [CATransaction setAnimationDuration:0.2];
        [CATransaction setCompletionBlock:^{ [layer removeFromSuperlayer]; [controller forceDismissStartupAnimationAnimated:YES]; }];
        layer.opacity=0;
        [CATransaction commit];
    };
    NSMutableArray *observers=[NSMutableArray array];
    id ended=[[NSNotificationCenter defaultCenter] addObserverForName:AVPlayerItemDidPlayToEndTimeNotification object:player.currentItem queue:NSOperationQueue.mainQueue usingBlock:^(NSNotification *notification){ YTLStartupRemoveObservers(observers); finish(); }];
    id background=[[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidEnterBackgroundNotification object:nil queue:NSOperationQueue.mainQueue usingBlock:^(NSNotification *notification){ YTLStartupRemoveObservers(observers); [player pause]; finish(); }];
    [observers addObject:ended];
    [observers addObject:background];
    objc_setAssociatedObject(self,@selector(playLottieAnimation),observers,OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    UIAction *action=[UIAction actionWithHandler:^(UIAction *sender){ YTLStartupRemoveObservers(observers); [player pause]; finish(); }];
    UIButton *button=[UIButton buttonWithType:UIButtonTypeCustom];
    button.frame=cover.bounds;
    button.autoresizingMask=UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    [button addAction:action forControlEvents:UIControlEventTouchUpInside];
    [cover addSubview:button];
}
- (void)dealloc { YTLStartupRemoveObservers(objc_getAssociatedObject(self,@selector(playLottieAnimation))); %orig; }
%end
%end
%group YTLStartupLifecycleMain
%hook QTMIcon
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color {
    BOOL moon=[name isEqualToString:@"youtube_outline/moon_z_24pt"];
    UIImage *image=%orig;
    if (!moon) image.accessibilityIdentifier=name;
    return image;
}
%end
%hook YTAppDelegate
- (void)appDidBecomeActive {
    %orig;
    if (![[YTLUserDefaults standardUserDefaults] boolForKey:@"autoCheckCb"]) return;
    NSString *string=UIPasteboard.generalPasteboard.string;
    if (!string.length) return;
    for (NSString *domain in @[@"youtube.com",@"youtu.be",@"youtube-nocookie.com"]) {
        if ([string containsString:domain]) {
            ToastView *toast=[ToastView new];
            NSString *text=[[NSBundle ytl_defaultBundle] localizedStringForKey:@"LinkDetected" value:nil table:nil];
            NSString *title=[[NSBundle ytl_defaultBundle] localizedStringForKey:@"Open" value:nil table:nil];
            [toast showProgressiveToastWithText:text duration:10 actionTitle:title actionCompletion:^{
                NSString *stripped=[string stringByReplacingOccurrencesOfString:@"^https?://" withString:@"" options:NSRegularExpressionSearch range:NSMakeRange(0,string.length)];
                NSString *url=[NSString stringWithFormat:@"vnd.youtube://%@",stripped];
                [UIApplication.sharedApplication openURL:[NSURL URLWithString:url] options:@{} completionHandler:^(BOOL success){ if (success) UIPasteboard.generalPasteboard.string=nil; }];
            }];
            break;
        }
    }
}
%end
%end
void YTLInstallStartupLifecycleEarlyHooks(void) { %init(YTLStartupLifecycleEarly); }
void YTLInstallStartupLifecycleMainHooks(void) { %init(YTLStartupLifecycleMain); }

// Ordinary constructor 0x44488 and delayed callback 0x444d4.
void YTLScheduleWelcome(void) {
    // No promotional sheet on first launch, including after a preferences reset.
    [[YTLUserDefaults standardUserDefaults] setBool:YES forKey:@"hasShownWelcome"];
}

// Ordinary defaults tail at 0x65d08 in registrar 0x53fac; call after all primary hooks.
void YTLFinalizePrimaryStartup(void) {
    YTLUserDefaults *defaults=[YTLUserDefaults standardUserDefaults];
    if (![defaults objectForKey:@"sbPrivateUserID"]) {
        NSString *privateID=[defaults sbPrivateUserID];
        NSString *publicID=[defaults sbPublicUserID:privateID];
        [defaults setObject:privateID forKey:@"sbPrivateUserID"];
        [defaults setObject:publicID forKey:@"sbPublicUserID"];
        [defaults synchronize];
    }
    if ((NSUInteger)[defaults integerForKey:@"customTrack"] >= [YTPDB supportedLanguages].count) [defaults setInteger:(NSInteger)[YTPDB indexOfPreferredLanguage] forKey:@"customTrack"];
    if ((NSUInteger)[defaults integerForKey:@"customCaption"] >= [YTPDB supportedLanguages].count) [defaults setInteger:(NSInteger)[YTPDB indexOfPreferredLanguage] forKey:@"customCaption"];
}
