#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "ContentLayout.h"
#import "../Controls/PlaybackPreferences.h"
#import "../../../Utils/YTLUserDefaults.h"

// Safe-area behavior adapted from therealFoxster/DontEatMyContent (MIT).
// Layout state belongs to each player, so inline players cannot resize the watch player.
@interface YTLContentLayoutState : NSObject
@property(nonatomic) CGFloat aspectRatio;
@property(nonatomic) BOOL zoomed;
@property(nonatomic) BOOL panelVisible;
@property(nonatomic, weak) UIView *playerView;
@end
@implementation YTLContentLayoutState @end
static char YTLContentStateKey;
static __weak YTLContentLayoutState *YTLFullscreenContent;

@protocol YTLContentPlayer <NSObject>
- (UIView *)playerView;
- (id)activeVideoPlayerOverlay;
- (BOOL)isFullscreen;
- (UIView *)renderingView;
- (BOOL)isLandscapeEngagementPanel;
- (BOOL)isPeekingSupported;
@end
@interface YTPlayerView : UIView @end
@interface YTPlayerViewController : UIViewController @end
@interface YTMainAppVideoPlayerOverlayViewController : UIViewController @end
@interface YTVideoFreeZoomOverlayView : UIView @end
@interface YTVideoZoomOverlayView : UIView @end
@interface YTMainAppEngagementPanelViewController : UIViewController @end
@interface YTEngagementPanelContainerViewController : UIViewController @end

static YTLContentLayoutState *YTLContentState(UIView *view) {
    YTLContentLayoutState *state = objc_getAssociatedObject(view, &YTLContentStateKey);
    if (!state && view) {
        state = [YTLContentLayoutState new];
        state.aspectRatio = 16.0 / 9.0;
        state.playerView = view;
        objc_setAssociatedObject(view, &YTLContentStateKey, state, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return state;
}
static id<YTLContentPlayer> YTLPlayerForView(UIView *view) {
    for (UIResponder *responder = view; responder; responder = responder.nextResponder)
        if ([responder isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) return (id)responder;
    return nil;
}
static void YTLRequestContentLayout(YTLContentLayoutState *state) {
    [state.playerView setNeedsLayout];
}
static void YTLContentPinch(UIPinchGestureRecognizer *gesture) {
    id<YTLContentPlayer> player = YTLPlayerForView(gesture.view);
    YTLContentLayoutState *state = player ? YTLContentState(player.playerView) : YTLFullscreenContent;
    state.zoomed = YES;
    YTLRequestContentLayout(state);
}
static void YTLContentSnap(UIView *view, NSInteger snap) {
    id<YTLContentPlayer> player = YTLPlayerForView(view);
    YTLContentLayoutState *state = player ? YTLContentState(player.playerView) : YTLFullscreenContent;
    if (snap == 0 || snap == 1) state.zoomed = snap == 1;
    YTLRequestContentLayout(state);
}

%group YTLContentLayout
%hook YTMainAppVideoPlayerOverlayViewController
- (void)setPlaybackRate:(CGFloat)rate {
    %orig;
    YTLRememberPlaybackRate([YTLUserDefaults standardUserDefaults], rate);
}
%end
%hook YTPlayerViewController
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data {
    %orig;
    YTLContentLayoutState *state = YTLContentState([(id<YTLContentPlayer>)self playerView]);
    state.zoomed = NO;
    state.panelVisible = NO;
    YTLRequestContentLayout(state);
}
%end
%hook YTPlayerView
- (void)setAspectRatio:(CGFloat)ratio {
    %orig;
    YTLContentState(self).aspectRatio = ratio;
    [self setNeedsLayout];
}
- (void)layoutSubviews {
    %orig;
    YTLContentLayoutState *state = YTLContentState(self);
    id<YTLContentPlayer> player = YTLPlayerForView(self);
    id<YTLContentPlayer> overlay = [player activeVideoPlayerOverlay];
    BOOL fullscreen = [overlay respondsToSelector:@selector(isFullscreen)] && [overlay isFullscreen];
    if (fullscreen) YTLFullscreenContent = state;
    else if (YTLFullscreenContent == state) YTLFullscreenContent = nil;
    NSUserDefaults *defaults = [YTLUserDefaults standardUserDefaults];
    if (!YTLShouldProtectContent([defaults boolForKey:@"dontEatMyContent"], fullscreen, state.zoomed,
                                state.panelVisible, [defaults boolForKey:@"dontEatMyContentAllVideos"], state.aspectRatio)) return;
    UIView *rendering = [(id<YTLContentPlayer>)self renderingView];
    UIView *container = rendering.superview;
    UIWindow *window = self.window;
    if (!container || !window) return;
    CGRect safe = [window convertRect:UIEdgeInsetsInsetRect(window.bounds, window.safeAreaInsets) toView:container];
    safe = CGRectIntersection(safe, container.bounds);
    double height = YTLContentScale(safe.size.width, safe.size.height, state.aspectRatio);
    if (CGRectIsNull(safe) || height <= 0) return;
    CGSize size = CGSizeMake(height * state.aspectRatio, height);
    rendering.frame = CGRectMake(CGRectGetMidX(safe) - size.width / 2, CGRectGetMidY(safe) - size.height / 2, size.width, size.height);
}
%end
%hook YTVideoFreeZoomOverlayView
- (void)didRecognizePinch:(UIPinchGestureRecognizer *)gesture { YTLContentPinch(gesture); %orig; }
- (void)showLabelForSnapState:(NSInteger)snap { %orig; YTLContentSnap(self, snap); }
%end
%hook YTVideoZoomOverlayView
- (void)didRecognizePinch:(UIPinchGestureRecognizer *)gesture { YTLContentPinch(gesture); %orig; }
- (void)showLabelForSnapState:(NSInteger)snap { %orig; YTLContentSnap(self, snap); }
%end
%hook YTMainAppEngagementPanelViewController
- (void)viewWillAppear:(BOOL)animated {
    %orig;
    id<YTLContentPlayer> panel = (id)self;
    if ([panel respondsToSelector:@selector(isLandscapeEngagementPanel)] && [panel isLandscapeEngagementPanel]) {
        YTLFullscreenContent.panelVisible = YES;
        YTLRequestContentLayout(YTLFullscreenContent);
    }
}
- (void)viewDidDisappear:(BOOL)animated {
    %orig;
    YTLFullscreenContent.panelVisible = NO;
    YTLRequestContentLayout(YTLFullscreenContent);
}
%end
%end
void YTLInstallContentLayoutHooks(void) { %init(YTLContentLayout); }
