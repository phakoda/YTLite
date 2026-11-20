#import "ImageGesturesHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Runtime/YTLHookEntrypoints.h"

%group YTLImageGestures
%hook YTPlayerView
- (void)didPinch:(UIPinchGestureRecognizer *)gesture {
    %orig;
    UIViewController *delegate = self.playerViewDelegate;
    if (ytpBool(@"pinchToFullscreenShorts") &&
        [delegate.parentViewController isKindOfClass:NSClassFromString(@"YTShortsPlayerViewController")]) {
        id<YTLImageGestureShortsView> view = (id)delegate.parentViewController.view;
        id<YTLImageGestureRoot> root = (id)UIApplication.sharedApplication.delegate.window.rootViewController;
        CGFloat scale = gesture.scale;
        BOOL shortsOnly = ytpBool(@"shortsOnlyMode");
        if (scale > 1.0) {
            if (!shortsOnly) [root hidePivotBar];
            [UIView animateWithDuration:0.3 animations:^{
                [view playbackOverlay].alpha = 0;
                isOverlayShown = [view playbackOverlay].alpha != 0;
            }];
        } else {
            if (!shortsOnly) [root showPivotBar];
            [UIView animateWithDuration:0.3 animations:^{
                [view playbackOverlay].alpha = 1;
                isOverlayShown = [view playbackOverlay].alpha != 0;
            }];
        }
    }
}
%end
%hook YTImageZoomNode
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)other {
    id loaded = [self valueForKey:@"_didLoadImage"];
    BOOL enabled = ytpBool(@"postManager");
    // The packaged branch tests the KVC object's presence, including boxed NO.
    if (loaded != nil && enabled) {
        NSURL *url = [self isKindOfClass:%c(ASNetworkImageNode)] ? self.URL : nil;
        for (ASDisplayNode *container in self.supernodes.allObjects) {
            if ([container.description containsString:@"id.ui.backstage.original_post"]) {
                container.copiedURL = url;
                break;
            }
        }
    }
    return %orig;
}
%end
%end
void YTLInstallImageGesturesHooks(void) { %init(YTLImageGestures); }
