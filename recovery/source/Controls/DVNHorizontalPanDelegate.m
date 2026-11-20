#import "DVNHorizontalPanDelegate.h"
#import "ControlsHost.h"
#include <math.h>

@implementation DVNHorizontalPanDelegate
// 0x1b9608. Preserve the zoom exclusion and the strict velocity comparison;
// a diagonal tie, a stationary gesture, and unordered comparisons return NO.
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)recognizer {
    id<YTLControlsNode> overlay = [recognizer.view _viewControllerForAncestor];
    if ([(id)overlay isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")]) {
        overlay = [recognizer.view _viewControllerForAncestor];
        if ([overlay respondsToSelector:@selector(videoFreeZoomOverlayController)]) {
            id<YTLControlsNode> zoom = [overlay videoFreeZoomOverlayController];
            if ([zoom minFreeZoomFactor] < [zoom videoZoomFactor] && [zoom isSnappedToFillByDefault]) return NO;
        }
    }
    CGPoint velocity = [(UIPanGestureRecognizer *)recognizer velocityInView:recognizer.view];
    return fabs(velocity.y) < fabs(velocity.x);
}
@end
