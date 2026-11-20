#import "DVNSheetPresenter.h"
#import "PseudoDetentTransitioningDelegate.h"
#import "PresentationGeometry.h"

// This selector is the original iOS 15 constant-height detent entry point.
@interface UISheetPresentationControllerDetent (DVNConstantHeight)
+ (instancetype)_detentWithIdentifier:(NSString *)identifier constant:(CGFloat)height API_AVAILABLE(ios(15.0));
@end

static double DVNHeightForSections(NSArray<NSArray *> *sections) {
    // 0x1ef820–0x1efae4: 25 + 40 * section count + 50 * total row count.
    double height = 25 + 40 * (double)sections.count;
    for (NSArray *section in sections) height += 50 * (double)section.count;
    return height;
}

static void DVNPresentSheet(UIViewController *controller, UIViewController *presenter,
                            double height, BOOL halfScreen) {
    if (@available(iOS 15.0, *)) {
        controller.modalPresentationStyle = UIModalPresentationPageSheet;
        UISheetPresentationController *sheet = controller.sheetPresentationController;
        double nativeHeight = halfScreen ? presenter.view.bounds.size.height * 0.5 : height;
        sheet.detents = @[[UISheetPresentationControllerDetent
            _detentWithIdentifier:@"dvntm" constant:nativeHeight]];
        sheet.prefersGrabberVisible = YES;
        sheet.preferredCornerRadius = 15;
        [presenter presentViewController:controller animated:YES completion:nil];
        return;
    }
    // The original releases this local only after presentViewController: returns.
    __attribute__((objc_precise_lifetime)) PseudoDetentTransitioningDelegate *delegate =
        [PseudoDetentTransitioningDelegate new];
    if (halfScreen) {
        delegate.heightCalculator = ^CGFloat(CGSize size) {
            return YTLDetentHeight(size.width, size.height, 0, YES);
        };
    } else {
        delegate.heightCalculator = ^CGFloat(CGSize size) {
            return YTLDetentHeight(size.width, size.height, height, NO);
        };
    }
    controller.modalPresentationStyle = UIModalPresentationCustom;
    controller.transitioningDelegate = delegate;
    controller.preferredContentSize = CGSizeZero;
    [presenter presentViewController:controller animated:YES completion:nil];
}

@implementation DVNSheetPresenter
+ (void)presentCustomHeightViewController:(UIViewController *)controller
                      fromViewController:(UIViewController *)presenter {
    NSArray *sections = [controller.childViewControllers.firstObject valueForKey:@"_sections"];
    DVNPresentSheet(controller, presenter, DVNHeightForSections(sections) + 20, NO);
}
+ (void)presentHalfScreenViewController:(UIViewController *)controller
                    fromViewController:(UIViewController *)presenter {
    DVNPresentSheet(controller, presenter, 0, YES);
}
+ (void)presentViewController:(UIViewController *)controller
          fromViewController:(UIViewController *)presenter withHeight:(double)height {
    DVNPresentSheet(controller, presenter, height, NO);
}
@end
