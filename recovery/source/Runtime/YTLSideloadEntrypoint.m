#import "YTLSideloadEntrypoint.h"

@protocol YTLSideloadProxy <NSObject>
+ (id<YTLSideloadProxy>)bundleProxyForCurrentProcess;
- (NSDictionary *)entitlements;
@end

extern void YTLInstallSideloadIdentityHooks(void);
extern void YTLInstallLocalSideloadCompatibilityHooks(void);

BOOL YTLPrepareSideloadCompatibility(void) {
    Class<YTLSideloadProxy> proxyClass = (Class<YTLSideloadProxy>)NSClassFromString(@"LSApplicationProxy");
    NSDictionary *entitlements = [[proxyClass bundleProxyForCurrentProcess] entitlements];
    BOOL applicationMatches = [entitlements[@"application-identifier"] isEqualToString:@"EQHXZ8M8AV.com.google.ios.youtube"];
    NSDictionary *info = [NSBundle.mainBundle infoDictionary];
    BOOL bundleMatches = [info[@"CFBundleIdentifier"] isEqualToString:@"com.google.ios.youtube"];
    if (applicationMatches & bundleMatches) return NO;
    YTLInstallSideloadIdentityHooks();
    YTLInstallLocalSideloadCompatibilityHooks();
    return YES;
}
