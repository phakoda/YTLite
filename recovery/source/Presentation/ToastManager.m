#import "ToastManager.h"
#import "ToastView.h"
#import "ToastWindow.h"
#import "PresentationHost.h"

@implementation ToastManager
+ (instancetype)sharedManager {
    static ToastManager *manager;
    static dispatch_once_t once;
    // 0x1c9ba4 loads the concrete class, even when a subclass calls first.
    dispatch_once(&once, ^{ manager = [[ToastManager alloc] init]; });
    return manager;
}
- (instancetype)init {
    self = [super init];
    if (self) _toasts = [NSMutableArray array];
    return self;
}
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success {
    // Original 0x1c9c8c constructs and registers before queuing presentation.
    ToastView *toast = [[ToastView alloc] init];
    [[ToastManager sharedManager] registerToast:toast];
    dispatch_async(dispatch_get_main_queue(), ^{
        [toast showMessageWithText:text isSuccess:success];
    });
}
- (void)registerToast:(ToastView *)toast {
    if (!toast) return;
    @synchronized (_toasts) {
        if ([_toasts containsObject:toast]) return;
        [_toasts addObject:toast];
        [self updateAllToasts];
    }
}
- (void)unregisterToast:(ToastView *)toast {
    if (!toast) return;
    @synchronized (_toasts) {
        [_toasts removeObject:toast];
        [self updateAllToasts];
    }
}
- (void)updateAllToasts {
    @synchronized (_toasts) {
        for (ToastView *toast in _toasts) [toast updateLayout];
    }
}
@end
