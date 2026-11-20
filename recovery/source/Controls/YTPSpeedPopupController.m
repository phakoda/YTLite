#import "YTPSpeedPopupController.h"
#include <math.h>

@implementation YTPSpeedPopupController
// 0x235b74 / 0x235bc4.
+ (instancetype)speedController {
    YTPSpeedPopupController *controller = [YTPSpeedPopupController new];
    controller.modalPresentationStyle = UIModalPresentationOverFullScreen;
    controller.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;
    return controller;
}
- (void)presentFromViewController:(UIViewController *)controller {
    [controller presentViewController:self animated:NO completion:nil];
}
// 0x235c0c / block 0x235d04.
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.bottomConstraint.constant = [self bottomConstant];
    [UIView animateWithDuration:0.4 delay:0 usingSpringWithDamping:0.8 initialSpringVelocity:0.5
        options:UIViewAnimationOptionCurveEaseOut animations:^{ [self.view layoutIfNeeded]; } completion:nil];
}
// 0x235d64.
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:0.1];
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismiss)];
    tap.delegate = self;
    [self.view addGestureRecognizer:tap];
    self.speedView = [YTPSpeedControlView speedControls];
    [self.view addSubview:self.speedView];
    UIView *grabber = [UIView new];
    grabber.backgroundColor = [UIColor.labelColor colorWithAlphaComponent:0.3];
    grabber.layer.cornerRadius = 2.5;
    grabber.translatesAutoresizingMaskIntoConstraints = NO;
    [self.speedView addSubview:grabber];
    self.bottomConstraint = [self.speedView.bottomAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.bottomAnchor
        constant:self.speedView.bounds.size.height + 20.0];
    [NSLayoutConstraint activateConstraints:@[
        [grabber.topAnchor constraintEqualToAnchor:self.speedView.topAnchor constant:8.0],
        [grabber.centerXAnchor constraintEqualToAnchor:self.speedView.centerXAnchor],
        [grabber.widthAnchor constraintEqualToConstant:36.0], [grabber.heightAnchor constraintEqualToConstant:5.0],
        [self.speedView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [self.speedView.widthAnchor constraintEqualToConstant:[self calculateWidth]], self.bottomConstraint]];
    [self.speedView addGestureRecognizer:[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePan:)]];
}
// 0x236564 / 0x236634 / 0x236660 / 0x236994.
- (double)calculateWidth {
    double width = UIScreen.mainScreen.bounds.size.width;
    double height = UIScreen.mainScreen.bounds.size.height;
    return (width < height ? width : height) * ([self isiPad] ? 0.5 : 0.95);
}
- (double)bottomConstant { return [self hasNotch] ? 0.0 : -10.0; }
- (BOOL)isiPad {
    UIDevice *device = UIDevice.currentDevice;
    return (device.userInterfaceIdiom == UIUserInterfaceIdiomPad || [UIDevice.currentDevice.model containsString:@"iPad"])
        && ![UIDevice.currentDevice.model containsString:@"iPhone"];
}
- (BOOL)hasNotch { return UIApplication.sharedApplication.delegate.window.safeAreaInsets.top > 20.0; }
// 0x236a38, blocks 0x236b84 / 0x236c30.
- (void)dismiss {
    self.bottomConstraint.constant = self.speedView.bounds.size.height + 50.0;
    [UIView animateWithDuration:0.3 delay:0 usingSpringWithDamping:1.0 initialSpringVelocity:_dismissVelocity / 1000.0
        options:UIViewAnimationOptionCurveEaseIn animations:^{
            self.view.backgroundColor = UIColor.clearColor;
            [self.view layoutIfNeeded];
        } completion:^(__unused BOOL finished) { [self dismissViewControllerAnimated:NO completion:nil]; }];
}
// 0x236c70. The previously omitted continuation was checked against original
// instructions 0x236cdc..0x23719c: d8 is translation, d9 is velocity.
- (void)handlePan:(UIPanGestureRecognizer *)gesture {
    double y = [gesture translationInView:self.view].y;
    if (gesture.state == UIGestureRecognizerStateChanged) {
        double bottom = [self bottomConstant];
        self.bottomConstraint.constant = y > 0.0 ? bottom + y : fma(y, 0.15, bottom);
        double fraction = y / 200.0;
        fraction = fraction > 1.0 ? 1.0 : fraction;
        fraction = fmax(fraction, 0.0);
        self.view.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:(1.0 - fraction) * 0.1];
        [self.view layoutIfNeeded];
        return;
    }
    if (gesture.state != UIGestureRecognizerStateEnded && gesture.state != UIGestureRecognizerStateCancelled) return;
    double velocity = [gesture velocityInView:self.view].y;
    if (y > 120.0 || velocity > 600.0) {
        _dismissVelocity = velocity;
        [self dismiss];
    } else {
        self.bottomConstraint.constant = [self bottomConstant];
        [UIView animateWithDuration:0.3 delay:0 usingSpringWithDamping:0.7 initialSpringVelocity:0.5
            options:UIViewAnimationOptionCurveEaseOut animations:^{
                self.view.backgroundColor = [UIColor.blackColor colorWithAlphaComponent:0.1];
                [self.view layoutIfNeeded];
            } completion:nil];
    }
}
// 0x23719c: taps on controls must not trigger background dismissal.
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)recognizer shouldReceiveTouch:(UITouch *)touch {
    (void)recognizer;
    return touch.view == self.view;
}
@end
