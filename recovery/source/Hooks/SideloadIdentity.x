#import "SideloadIdentityHost.h"
#import "../Runtime/InitWorkaround.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <Security/Security.h>
#import <objc/runtime.h>
#include <dlfcn.h>
#include <stdint.h>

// 0x1bdc0. Query only the process's authorized keychain namespace. The original
// returns an attribute string and does not release the retained result dictionary.
static NSString *SideloadIdentityAccessGroup(void) {
    NSDictionary *query = @{
        (__bridge NSString *)kSecClass: (__bridge NSString *)kSecClassGenericPassword,
        (__bridge NSString *)kSecAttrAccount: @"bundleSeedID",
        (__bridge NSString *)kSecAttrService: @"",
        (__bridge NSString *)kSecReturnAttributes: @YES
    };
    CFTypeRef result = NULL;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, &result);
    if (status == errSecItemNotFound) {
        status = SecItemAdd((__bridge CFDictionaryRef)query, &result);
        if (status != errSecSuccess) return nil;
    }
    return [(__bridge NSDictionary *)result objectForKey:(__bridge NSString *)kSecAttrAccessGroup];
}

static void SideloadIdentityShowLoginInfo(void) {
    static Class alertClass;
    if (!alertClass) alertClass = NSClassFromString(@"YTAlertView");
    id<YTLSideloadIdentityAlert> alert = [(Class<YTLSideloadIdentityAlert>)alertClass dialog];
    [alert setTitle:@"YouTube Plus"];
    [alert setSubtitle:[[NSBundle ytl_defaultBundle] localizedStringForKey:@"LoginInfo" value:nil table:nil]];
    [alert addTitle:@"OK" withAction:nil];
    [alert show];
}

%group YTLSideloadIdentity
%hook YTVersionUtils
+ (NSString *)appName { return @"YouTube"; }
+ (NSString *)appID { return @"com.google.ios.youtube"; }
%end
%hook GCKBUtils
+ (NSString *)appIdentifier { return @"com.google.ios.youtube"; }
%end
%hook OGLBundle
+ (NSString *)shortAppName { return @"YouTube"; }
%end
%hook GVROverlayView
+ (NSString *)appName { return @"YouTube"; }
%end
%hook OGLPhenotypeFlagServiceImpl
- (NSString *)bundleId { return @"com.google.ios.youtube"; }
%end
%hook SSOConfiguration
- (instancetype)initWithClientID:(id)clientID supportedAccountServices:(id)services {
    SSOConfiguration *configuration = %orig;
    [configuration setValue:@"YouTube" forKey:@"_shortAppName"];
    [configuration setValue:@"com.google.ios.youtube" forKey:@"_applicationIdentifier"];
    return configuration;
}
%end
%hook NSBundle
- (NSString *)bundleIdentifier {
    NSArray *addresses = [NSThread callStackReturnAddresses];
    Dl_info info = {NULL, NULL, NULL, NULL};
    if (dladdr((const void *)(uintptr_t)[addresses[2] longLongValue], &info)) {
        NSString *path = [NSString stringWithUTF8String:info.dli_fname];
        if ([path hasPrefix:[[NSBundle mainBundle] bundlePath]]) return @"com.google.ios.youtube";
    }
    return %orig;
}
- (id)objectForInfoDictionaryKey:(NSString *)key {
    if ([key isEqualToString:@"CFBundleIdentifier"]) return @"com.google.ios.youtube";
    if ([key isEqualToString:@"CFBundleDisplayName"]) return @"YouTube";
    if ([key isEqualToString:@"CFBundleName"]) return @"YouTube";
    return %orig;
}
%end
%hook SSOKeychainHelper
+ (NSString *)accessGroup { return SideloadIdentityAccessGroup(); }
+ (NSString *)sharedAccessGroup { return SideloadIdentityAccessGroup(); }
%end
%hook SSOKeychainCore
+ (NSString *)accessGroup { return SideloadIdentityAccessGroup(); }
+ (NSString *)sharedAccessGroup { return SideloadIdentityAccessGroup(); }
%end
%hook SSOFolsomKeychainUtils
+ (NSString *)sharedAccessGroup { return SideloadIdentityAccessGroup(); }
%end
%hook GNPEncryptionConfiguration
+ (NSString *)keychainAccessGroup { return SideloadIdentityAccessGroup(); }
%end
%hook YTFirstTimeSignInViewController
- (void)viewDidAppear:(BOOL)animated {
    %orig;
    if (isYTPFirstTime) {
        isYTPFirstTime = NO;
        YTLInstallBundleInfoHook();
    }
}
- (void)viewDidDisappear:(BOOL)animated {
    %orig;
    if (!isYTPFirstTime) SideloadIdentityShowLoginInfo();
}
%end
%hook YTInlineSignInViewController
- (void)viewDidDisappear:(BOOL)animated {
    %orig;
    if (class_getInstanceVariable([[UIDevice currentDevice] class], "doc_symbolName")) {
        BOOL isMac = [[[UIDevice currentDevice] doc_symbolName] hasPrefix:@"mac"];
        if (!isYTPFirstTime && isMac) SideloadIdentityShowLoginInfo();
    }
}
%end
%end
void YTLInstallSideloadIdentityHooks(void) { %init(YTLSideloadIdentity); }
