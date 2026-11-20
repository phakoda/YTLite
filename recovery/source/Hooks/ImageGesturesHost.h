#import "FeedNodesHost.h"
@interface YTPlayerView : UIView
@property(nonatomic, strong) UIViewController *playerViewDelegate;
- (void)didPinch:(UIPinchGestureRecognizer *)gesture;
@end
@interface YTShortsPlayerViewController : UIViewController @end
@interface ASNetworkImageNode : ASDisplayNode
@property(nonatomic, strong) NSURL *URL;
@end
@interface YTImageZoomNode : ASNetworkImageNode
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)gesture shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)other;
@end
@protocol YTLImageGestureShortsView <NSObject>
- (UIView *)playbackOverlay;
@end
@protocol YTLImageGestureRoot <NSObject>
- (void)showPivotBar;
- (void)hidePivotBar;
@end
FOUNDATION_EXPORT void YTLInstallImageGesturesHooks(void);
