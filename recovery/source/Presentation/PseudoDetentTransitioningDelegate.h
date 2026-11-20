#pragma once
#import "PseudoDetentController.h"

@interface PseudoDetentTransitioningDelegate : NSObject <UIViewControllerTransitioningDelegate> {
    DVNHeightCalculator _heightCalculator;
    double _customHeight;
}
@property(nonatomic, copy) DVNHeightCalculator heightCalculator;
@property(nonatomic) double customHeight;
- (UIPresentationController *)presentationControllerForPresentedViewController:(UIViewController *)presented
                                                   presentingViewController:(UIViewController *)presenting
                                                       sourceViewController:(UIViewController *)source;
@end
