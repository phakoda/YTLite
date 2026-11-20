#import "PseudoDetentController.h"

@implementation PseudoDetentController
- (instancetype)initWithPresentedViewController:(UIViewController *)presented
                      presentingViewController:(UIViewController *)presenting {
    self = [super initWithPresentedViewController:presented presentingViewController:presenting];
    if (self) {
        self.dimmingView = [[UIView alloc] initWithFrame:CGRectZero];
        self.dimmingView.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:0.5];
        self.dimmingView.alpha = 0;
        [self.dimmingView addGestureRecognizer:[[UITapGestureRecognizer alloc]
            initWithTarget:self action:@selector(dismissController)]];
    }
    return self;
}
- (void)dismissController {
    [self.presentedViewController dismissViewControllerAnimated:YES completion:nil];
}
- (CGRect)frameOfPresentedViewInContainerView {
    CGRect bounds = self.containerView.bounds;
    CGFloat height = self.customHeight;
    // 0x1f10d4 and 0x1f1130 are separate getter calls.
    if (self.heightCalculator) height = self.heightCalculator(bounds.size);
    return CGRectMake(0, CGRectGetHeight(bounds) - height, CGRectGetWidth(bounds), height);
}
- (void)containerViewWillLayoutSubviews {
    [super containerViewWillLayoutSubviews];
    CGRect frame = self.frameOfPresentedViewInContainerView;
    self.presentedView.frame = frame;
}
- (void)presentationTransitionWillBegin {
    self.dimmingView.frame = self.containerView.bounds;
    [self.containerView addSubview:self.dimmingView];
    self.presentedView.layer.cornerRadius = 15;
    self.presentedView.layer.masksToBounds = YES;
    self.presentedView.layer.cornerRadius = 15;
    self.presentedView.layer.maskedCorners = kCALayerMinXMinYCorner | kCALayerMaxXMinYCorner;
    // Original descriptor 0x1062f00 retains self when this block is copied.
    [self.presentedViewController.transitionCoordinator
        animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext> context) {
            (void)context;
            self.dimmingView.alpha = 1;
        } completion:nil];
}
- (void)dismissalTransitionWillBegin {
    [self.presentedViewController.transitionCoordinator
        animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext> context) {
            (void)context;
            self.dimmingView.alpha = 0;
        } completion:^(id<UIViewControllerTransitionCoordinatorContext> context) {
            // Original invoke 0x1f16e0 ignores the transition context.
            (void)context;
            [self.dimmingView removeFromSuperview];
        }];
}
@end
