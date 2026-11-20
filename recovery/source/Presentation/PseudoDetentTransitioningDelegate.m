#import "PseudoDetentTransitioningDelegate.h"

@implementation PseudoDetentTransitioningDelegate
- (UIPresentationController *)presentationControllerForPresentedViewController:(UIViewController *)presented
                                                   presentingViewController:(UIViewController *)presenting
                                                       sourceViewController:(UIViewController *)source {
    (void)source;
    PseudoDetentController *controller = [[PseudoDetentController alloc]
        initWithPresentedViewController:presented presentingViewController:presenting];
    controller.customHeight = self.customHeight;
    controller.heightCalculator = self.heightCalculator;
    return controller;
}
@end
