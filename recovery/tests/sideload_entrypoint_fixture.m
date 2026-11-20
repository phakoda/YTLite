#import <Foundation/Foundation.h>
#import "sideload_entrypoint_redirects.h"
#import "../source/Runtime/YTLSideloadEntrypoint.h"

static NSDictionary *entitlements, *bundleInfo;
static BOOL absentClass, absentProxy;
static NSMutableArray *events;
static NSUInteger checks;
#define CHECK(c) do {checks++; if (!(c)) {fprintf(stderr,"FAIL %d: %s\n",__LINE__,#c);exit(1);}} while(0)

@interface YTLSideloadFixtureProxy : NSObject
+ (instancetype)bundleProxyForCurrentProcess;
- (NSDictionary *)entitlements;
@end
@implementation YTLSideloadFixtureProxy
+ (instancetype)bundleProxyForCurrentProcess { [events addObject:@"proxy"]; return absentProxy ? nil : [self new]; }
- (NSDictionary *)entitlements { [events addObject:@"entitlements"]; return entitlements; }
@end
@implementation YTLSideloadFixtureBundle
+ (instancetype)mainBundle { [events addObject:@"mainBundle"]; return [self new]; }
- (NSDictionary *)infoDictionary { [events addObject:@"infoDictionary"]; return bundleInfo; }
@end
Class YTLSideloadFixtureClass(NSString *name) {
    CHECK([name isEqual:@"LSApplicationProxy"]);
    [events addObject:@"class"];
    return absentClass ? Nil : YTLSideloadFixtureProxy.class;
}
void YTLInstallSideloadIdentityHooks(void) { [events addObject:@"identity"]; }
void YTLInstallLocalSideloadCompatibilityHooks(void) { [events addObject:@"local"]; }

int main(void) { @autoreleasepool {
    NSArray *applicationIDs = @[[NSNull null], @"wrong", @"EQHXZ8M8AV.com.google.ios.youtube"];
    NSArray *bundleIDs = @[[NSNull null], @"wrong", @"com.google.ios.youtube"];
    for (NSUInteger a=0; a<3; a++) for (NSUInteger b=0; b<3; b++) {
        entitlements = a ? @{@"application-identifier":applicationIDs[a]} : nil;
        bundleInfo = b ? @{@"CFBundleIdentifier":bundleIDs[b]} : nil;
        for (NSUInteger environment=0; environment<3; environment++) {
            absentClass=environment==1; absentProxy=environment==2;
            events=[NSMutableArray new];
            BOOL expected=!(a==2 && b==2 && environment==0);
            CHECK(YTLPrepareSideloadCompatibility()==expected);
            NSMutableArray *order=[NSMutableArray arrayWithObject:@"class"];
            if (!absentClass) [order addObject:@"proxy"];
            if (!absentClass && !absentProxy) [order addObject:@"entitlements"];
            [order addObjectsFromArray:@[@"mainBundle", @"infoDictionary"]];
            if (expected) [order addObjectsFromArray:@[@"identity", @"local"]];
            CHECK([events isEqual:order]);
        }
    }
    printf("Sideload entrypoint: %lu assertions across 27 identity/environment cases\n",(unsigned long)checks);
} return 0; }
