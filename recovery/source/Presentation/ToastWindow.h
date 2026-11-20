#pragma once
#import <UIKit/UIKit.h>

@interface ToastWindow : UIWindow
+ (void)initialize;
- (instancetype)initWithWindowScene:(UIWindowScene *)scene;
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event;
- (BOOL)canBecomeKeyWindow;
- (void)makeKeyAndVisible;
- (BOOL)shouldAffectStatusBarAppearance;
- (BOOL)_windowControlsStatusBarOrientation;
- (BOOL)_canBecomeKeyWindow;
- (UIWindow *)appKeyWindow;
@end
