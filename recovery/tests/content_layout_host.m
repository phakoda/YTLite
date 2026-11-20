#import <UIKit/UIKit.h>
#import "../../Utils/YTLUserDefaults.h"

// Synthetic YouTube boundaries; production Logos callbacks and UIKit views run unchanged.
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults { return (id)NSUserDefaults.standardUserDefaults; }
@end
@interface YTMainAppVideoPlayerOverlayViewController : UIViewController
@property(nonatomic) BOOL fullscreen;
@property(nonatomic) CGFloat rate;
- (BOOL)isFullscreen;
- (void)setPlaybackRate:(CGFloat)rate;
@end
@implementation YTMainAppVideoPlayerOverlayViewController
- (BOOL)isFullscreen { return self.fullscreen; }
- (void)setPlaybackRate:(CGFloat)rate { self.rate=rate; }
@end
@interface YTPlayerView : UIView
@property(nonatomic,strong) UIView *renderingView;
- (void)setAspectRatio:(CGFloat)ratio;
@end
@implementation YTPlayerView
- (void)setAspectRatio:(CGFloat)ratio {}
- (void)layoutSubviews { [super layoutSubviews]; self.renderingView.frame=self.bounds; }
@end
@interface YTPlayerViewController : UIViewController
@property(nonatomic,strong) YTMainAppVideoPlayerOverlayViewController *activeVideoPlayerOverlay;
- (UIView *)playerView;
@end
@implementation YTPlayerViewController
- (UIView *)playerView { return self.view; }
- (void)playbackController:(id)c didActivateVideo:(id)v withPlaybackData:(id)d {}
@end
@interface YTVideoZoomOverlayView : UIView
- (void)showLabelForSnapState:(NSInteger)snap;
@end
@implementation YTVideoZoomOverlayView
- (void)didRecognizePinch:(UIPinchGestureRecognizer *)gesture {}
- (void)showLabelForSnapState:(NSInteger)snap {}
@end
extern void YTLInstallContentLayoutHooks(void);
void YTLRunContentLayoutTests(NSMutableArray *errors, UIWindow *window) {
    YTLInstallContentLayoutHooks();
    NSUserDefaults *defaults=NSUserDefaults.standardUserDefaults;
    [defaults setBool:YES forKey:@"rememberPlaybackSpeed"];
    YTMainAppVideoPlayerOverlayViewController *overlay=[YTMainAppVideoPlayerOverlayViewController new];
    [overlay setPlaybackRate:1.75];
    if ([defaults doubleForKey:@"rememberedPlaybackRate"]!=1.75) [errors addObject:@"Native speed menu was not remembered"];
    [overlay setPlaybackRate:1];
    if ([defaults doubleForKey:@"rememberedPlaybackRate"]!=1) [errors addObject:@"Normal speed reset was not remembered"];
    YTPlayerViewController *player=[YTPlayerViewController new];
    player.activeVideoPlayerOverlay=overlay;overlay.fullscreen=YES;
    YTPlayerView *view=[[YTPlayerView alloc] initWithFrame:window.bounds];
    view.renderingView=[UIView new];[view addSubview:view.renderingView];player.view=view;
    [window.rootViewController addChildViewController:player];
    [window.rootViewController.view addSubview:view];
    [player didMoveToParentViewController:window.rootViewController];
    [view setAspectRatio:2];
    [view layoutSubviews];
    CGRect safe=[window convertRect:UIEdgeInsetsInsetRect(window.bounds,window.safeAreaInsets) toView:view];
    if (!CGRectContainsRect(safe,view.renderingView.frame)) [errors addObject:@"Rendering frame crosses safe area"];
    if (fabs(view.renderingView.frame.size.width/view.renderingView.frame.size.height-2)>0.001) [errors addObject:@"Video aspect ratio was distorted"];
    view.renderingView.translatesAutoresizingMaskIntoConstraints=NO;
    [view layoutSubviews];
    if (!CGRectContainsRect(safe,view.renderingView.frame)) [errors addObject:@"Auto Layout rendering frame crosses safe area"];
    YTVideoZoomOverlayView *zoom=[YTVideoZoomOverlayView new];[view addSubview:zoom];
    [zoom showLabelForSnapState:1];[view layoutSubviews];
    if (!CGRectEqualToRect(view.renderingView.frame,view.bounds)) [errors addObject:@"Intentional zoom was constrained"];
    [zoom showLabelForSnapState:0];[view layoutSubviews];
    if (!CGRectContainsRect(safe,view.renderingView.frame)) [errors addObject:@"Original zoom did not restore protection"];
    [defaults setBool:NO forKey:@"dontEatMyContent"];[view layoutSubviews];
    if (!CGRectEqualToRect(view.renderingView.frame,view.bounds)) [errors addObject:@"Disabled protection altered layout"];
    [defaults setBool:YES forKey:@"dontEatMyContent"];
    [view removeFromSuperview];[player removeFromParentViewController];
}
