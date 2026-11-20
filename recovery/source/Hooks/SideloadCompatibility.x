#import "SideloadCompatibilityHost.h"
#import "../Runtime/InitWorkaround.h"
#import "../../../Utils/NSBundle+YTLite.h"

%group YTLLocalSideloadCompatibility
%hook NSFileManager
// Original implementation 0x18924, registration at 0x16ff8.
- (NSURL *)containerURLForSecurityApplicationGroupIdentifier:(NSString *)groupIdentifier {
    if (groupIdentifier) {
        NSArray<NSURL *> *paths = [[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask];
        return [paths.lastObject URLByAppendingPathComponent:@"AppGroup"];
    }
    return %orig(groupIdentifier);
}
%end
%hook SFAuthenticationViewController
// Original implementation 0x18b78; completion callbacks 0x1c080 and 0x1c0f8.
- (void)viewDidAppear:(BOOL)animated {
    %orig;
    if (isYTPFirstTime) {
        InitWorkaround *controller = [InitWorkaround new];
        controller.completion = ^{
            [self dismissViewControllerAnimated:YES completion:^{
                if ([self respondsToSelector:@selector(remoteViewControllerWillDismiss:)]) {
                    // The package sends performSelector: without an argument despite
                    // the selector's colon. Preserve that dispatch, not an invented argument.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
                    [self performSelector:@selector(remoteViewControllerWillDismiss:)];
#pragma clang diagnostic pop
                }
                static Class alertClass;
                if (!alertClass) alertClass = NSClassFromString(@"YTAlertView");
                YTAlertView *alert = [alertClass infoDialog];
                alert.title = @"YouTube Plus";
                alert.subtitle = [[NSBundle ytl_defaultBundle] localizedStringForKey:@"RetryLogin" value:nil table:nil];
                [alert show];
            }];
        };
        [self presentViewController:controller animated:YES completion:nil];
    }
}
%end
%hook YTInlineSignInController
// Original implementation 0x18c88. Shared bundle hook is implemented in InitWorkaround.m.
- (void)didTapShowAddAccount {
    if (isYTPFirstTime) {
        isYTPFirstTime = NO;
        YTLInstallBundleInfoHook();
    }
    %orig;
}
%end
%end

void YTLInstallLocalSideloadCompatibilityHooks(void) {
    %init(YTLLocalSideloadCompatibility);
}

// Metadata normalization is separable from the registrar's excluded permission
// and playback authentication callbacks. Parent owns installation routing.
%group YTLSideloadMetadataCompatibility
%hook NSMutableURLRequest
+ (NSDictionary *)ak_clientInfoHeader {
    NSMutableDictionary *headers = [%orig mutableCopy];
    NSString *value = headers[@"X-MMe-Client-Info"];
    if (value) {
        headers[@"X-MMe-Client-Info"] = [value stringByReplacingOccurrencesOfString:NSBundle.mainBundle.bundleIdentifier withString:@"com.google.ios.youtube"];
    }
    return [headers copy];
}
- (NSDictionary *)allHTTPHeaderFields {
    NSMutableDictionary *headers = [%orig mutableCopy];
    NSString *value = headers[@"User-Agent"];
    if (value) {
        headers[@"User-Agent"] = [value stringByReplacingOccurrencesOfString:NSBundle.mainBundle.bundleIdentifier withString:@"com.google.ios.youtube"];
    }
    return [headers copy];
}
%end
%hook LSApplicationProxy
- (NSString *)teamID { return @"EQHXZ8M8AV"; }
- (NSString *)appIDPrefix { return @"EQHXZ8M8AV"; }
- (NSString *)applicationIdentifier {
    return [%orig stringByReplacingOccurrencesOfString:NSBundle.mainBundle.bundleIdentifier withString:@"com.google.ios.youtube"];
}
%end
%hook LSBundleProxy
- (NSString *)bundleIdentifier {
    return [%orig stringByReplacingOccurrencesOfString:NSBundle.mainBundle.bundleIdentifier withString:@"com.google.ios.youtube"];
}
%end
%end

void YTLInstallSideloadMetadataCompatibilityHooks(void) {
    %init(YTLSideloadMetadataCompatibility);
}
