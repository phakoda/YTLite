#import "ToastWindow.h"
#import "ToastView.h"
#import "PresentationHost.h"

@implementation ToastWindow
+ (void)initialize {
    Method appearance = class_getInstanceMethod(self, @selector(shouldAffectStatusBarAppearance));
    class_addMethod(self, NSSelectorFromString(@"_canAffectStatusBarAppearance"),
                    method_getImplementation(appearance), method_getTypeEncoding(appearance));
    Method keyWindow = class_getInstanceMethod(self, @selector(canBecomeKeyWindow));
    class_addMethod(self, NSSelectorFromString(@"_canBecomeKeyWindow"),
                    method_getImplementation(keyWindow), method_getTypeEncoding(keyWindow));
}
- (instancetype)initWithWindowScene:(UIWindowScene *)scene {
    self = [super initWithWindowScene:scene];
    if (self) {
        self.windowLevel = UIWindowLevelAlert - 1;
        self.backgroundColor = UIColor.clearColor;
    }
    return self;
}
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    UIView *hit = [super hitTest:point withEvent:event];
    UIView *view = hit;
    while (view) {
        // The packaged implementation reads the ancestor afresh for each check,
        // including the repeated action-sheet check, and walks through the window.
        if ([view isKindOfClass:ToastView.class] ||
            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"YTActionSheetDialogViewController")] ||
            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"YTDefaultSheetController")] ||
            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"YTActionSheetDialogViewController")] ||
            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"YTBottomSheetController")] ||
            [[view _viewControllerForAncestor] isKindOfClass:NSClassFromString(@"WelcomeVC")] ||
            [view isKindOfClass:NSClassFromString(@"YTTouchForwardingView")]) break;
        view = view.superview;
    }
    if (hit == self || hit == self.rootViewController.view || !view) return nil;
    return hit;
}
- (BOOL)canBecomeKeyWindow { return NO; }
- (void)makeKeyAndVisible {
    [super makeKeyAndVisible];
    if (self.isKeyWindow) [self resignKeyWindow];
}
- (BOOL)shouldAffectStatusBarAppearance { return NO; }
- (BOOL)_windowControlsStatusBarOrientation { return NO; }
- (BOOL)_canBecomeKeyWindow { return NO; }
- (UIWindow *)appKeyWindow {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    for (UIWindow *window in UIApplication.sharedApplication.windows)
        if (window.isKeyWindow) return window;
#pragma clang diagnostic pop
    return nil;
}
@end
