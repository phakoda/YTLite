#pragma once
#import <UIKit/UIKit.h>

// The recovered invokes 1eff74 / 1f0350 / 1f06d0 consume width and height
// in d0/d1 and return a CGFloat in d0; callers pass container.bounds.size.
typedef CGFloat (^DVNHeightCalculator)(CGSize containerSize);

@interface PseudoDetentController : UIPresentationController {
    DVNHeightCalculator _heightCalculator;
    double _customHeight;
    UIView *_dimmingView;
}
@property(nonatomic, copy) DVNHeightCalculator heightCalculator;
@property(nonatomic) double customHeight;
@property(nonatomic, strong) UIView *dimmingView;
- (instancetype)initWithPresentedViewController:(UIViewController *)presented
                      presentingViewController:(UIViewController *)presenting;
- (void)dismissController;
- (CGRect)frameOfPresentedViewInContainerView;
- (void)containerViewWillLayoutSubviews;
- (void)presentationTransitionWillBegin;
- (void)dismissalTransitionWillBegin;
@end
