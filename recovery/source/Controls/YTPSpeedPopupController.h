#pragma once
#import <UIKit/UIKit.h>
#import "YTPSpeedControlView.h"

@interface YTPSpeedPopupController : UIViewController <UIGestureRecognizerDelegate> {
    double _dismissVelocity;
}
@property(nonatomic, strong) YTPSpeedControlView *speedView;
@property(nonatomic, strong) NSLayoutConstraint *bottomConstraint;
+ (instancetype)speedController;
- (void)presentFromViewController:(UIViewController *)controller;
- (double)calculateWidth;
- (double)bottomConstant;
- (BOOL)isiPad;
- (BOOL)hasNotch;
- (void)dismiss;
- (void)handlePan:(UIPanGestureRecognizer *)gesture;
@end
