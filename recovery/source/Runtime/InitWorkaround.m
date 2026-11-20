#import "InitWorkaround.h"
#import <objc/runtime.h>

extern void MSHookMessageEx(Class cls, SEL selector, IMP replacement, IMP *original);
// Raw packaged data at 0x1153530 is 1; later runtime writes are not initializers.
BOOL isYTPFirstTime = YES;
NSDictionary *(*orig_infoDictionary)(NSBundle *, SEL);

// 0x148c8. Always return a mutable copy; replace the main bundle's ID even when
// the original dictionary lacks CFBundleIdentifier. Other bundles retain data.
NSDictionary *replaceInfoDict(NSBundle *bundle, SEL selector) {
    NSMutableDictionary *info = [orig_infoDictionary(bundle, selector) mutableCopy];
    if ([bundle isEqual:NSBundle.mainBundle]) info[@"CFBundleIdentifier"] = @"com.google.ios.youtube";
    return info;
}
void YTLInstallBundleInfoHook(void) {
    MSHookMessageEx(NSBundle.class, @selector(infoDictionary), (IMP)replaceInfoDict, (IMP *)&orig_infoDictionary);
}
@implementation InitWorkaround
// 0x14cc0; delayed callback 0x14e60, dismissal completion 0x15014.
- (void)viewDidLoad {
    [super viewDidLoad];
    isYTPFirstTime = NO;
    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleLarge];
    spinner.color = UIColor.whiteColor;
    spinner.center = self.view.center;
    [self.view addSubview:spinner];
    [spinner startAnimating];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        YTLInstallBundleInfoHook();
        [self dismissViewControllerAnimated:YES completion:^{ if (self.completion) self.completion(); }];
    });
}
@end
