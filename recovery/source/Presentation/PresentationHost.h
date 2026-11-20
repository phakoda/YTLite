#pragma once
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>

// Declarations for real host classes/categories only. No host implementations.
@interface NSBundle (YTLPresentationBundle)
+ (NSBundle *)ytl_defaultBundle;
@end
@interface YTToastOffsetController : NSObject
- (double)bottomOffset;
@end
@interface UIView (YTLPresentationAncestor)
- (UIViewController *)_viewControllerForAncestor;
@end

static inline NSString *YTLPresentationLocalized(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}

static inline void YTLPresentationOnMain(dispatch_block_t block) {
    if (NSThread.isMainThread) block();
    else dispatch_async(dispatch_get_main_queue(), block);
}

static inline UIWindowScene *YTLPresentationScene(void) {
    UIWindowScene *fallback = nil;
    for (UIScene *scene in UIApplication.sharedApplication.connectedScenes) {
        if (![scene isKindOfClass:UIWindowScene.class]) continue;
        if (scene.activationState == UISceneActivationStateForegroundActive)
            return (UIWindowScene *)scene;
        if (!fallback) fallback = (UIWindowScene *)scene;
    }
    return fallback;
}

static inline UIWindow *YTLPresentationAppWindow(void) {
    id<UIApplicationDelegate> delegate = UIApplication.sharedApplication.delegate;
    if ([delegate respondsToSelector:@selector(window)] && delegate.window) return delegate.window;
    for (UIWindow *window in YTLPresentationScene().windows)
        if (window.isKeyWindow) return window;
    return nil;
}

static inline void YTLPresentationHaptic(void) {
    UIImpactFeedbackGenerator *generator = [[UIImpactFeedbackGenerator alloc]
        initWithStyle:UIImpactFeedbackStyleMedium];
    [generator prepare];
    [generator impactOccurred];
}

static inline void YTLPresentationAnchorActivity(UIActivityViewController *activity,
                                                UIViewController *presenter) {
    UIPopoverPresentationController *popover = activity.popoverPresentationController;
    popover.sourceView = presenter.view;
    CGSize screenSize = UIScreen.mainScreen.bounds.size;
    popover.sourceRect = CGRectMake(screenSize.width * 0.5, screenSize.height, 0, 0);
    popover.permittedArrowDirections = UIPopoverArrowDirectionAny;
}
