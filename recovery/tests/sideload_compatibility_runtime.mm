#import "../source/Hooks/SideloadCompatibilityHost.h"
#import "../source/Runtime/InitWorkaround.h"
#import "../../Utils/NSBundle+YTLite.h"
#undef objc_getClass

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { NSLog(@"FAIL %d %s",__LINE__,#__VA_ARGS__); exit(1); } } while (0)
static NSMutableArray *events;
static NSArray *directoryURLs;
static id forwardedGroup;
static NSUInteger originalCalls;
static BOOL originalEnablesFirstTime;
BOOL isYTPFirstTime;
NSDictionary *(*orig_infoDictionary)(NSBundle *,SEL);
void YTLInstallBundleInfoHook(void) { CHECK(!isYTPFirstTime); [events addObject:@"bundleHook"]; }
Class SideloadFixtureGetClass(const char *name) {
    if (strcmp(name,"LSApplicationProxy")==0) return LSApplicationProxy.class;
    if (strcmp(name,"LSBundleProxy")==0) return LSBundleProxy.class;
    if (strcmp(name,"NSMutableURLRequest")==0) return SideloadFixtureRequest.class;
    return strcmp(name,"NSFileManager")==0 ? SideloadFixtureFileManager.class : objc_getClass(name);
}
static NSDictionary *originalHeaders;
static NSString *originalIdentity;
static NSString *fixtureBundleID(id object, SEL selector) { return @"fixture.bundle"; }
@implementation SideloadFixtureRequest
+ (NSDictionary *)ak_clientInfoHeader { [events addObject:@"originalClientInfo"]; return originalHeaders; }
- (NSDictionary *)allHTTPHeaderFields { [events addObject:@"originalHeaders"]; return originalHeaders; }
@end
@implementation LSApplicationProxy
- (NSString *)teamID { [events addObject:@"originalTeam"]; return @"originalTeam"; }
- (NSString *)appIDPrefix { [events addObject:@"originalPrefix"]; return @"originalPrefix"; }
- (NSString *)applicationIdentifier { [events addObject:@"originalAppID"]; return originalIdentity; }
@end
@implementation LSBundleProxy
- (NSString *)bundleIdentifier { [events addObject:@"originalBundleID"]; return originalIdentity; }
@end
@implementation SideloadFixtureFileManager
+ (instancetype)defaultManager { static SideloadFixtureFileManager *manager; if (!manager) manager=[self new]; return manager; }
- (NSArray<NSURL *> *)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domains {
    CHECK(directory==NSDocumentDirectory && domains==NSUserDomainMask);
    [events addObject:@"documents"];
    return directoryURLs;
}
- (NSURL *)containerURLForSecurityApplicationGroupIdentifier:(NSString *)group {
    forwardedGroup=group;
    originalCalls++;
    [events addObject:@"originalPath"];
    return [NSURL fileURLWithPath:@"/synthetic/original"];
}
@end
@implementation UIViewController
- (void)viewDidAppear:(BOOL)animated { self.appearedAnimated=animated; [events addObject:@"appeared"]; if(originalEnablesFirstTime)isYTPFirstTime=YES; }
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion {
    CHECK(completion==nil);
    self.presented=controller;
    self.presentAnimated=animated;
    [events addObject:@"present"];
}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion {
    self.dismissAnimated=animated;
    self.dismissCompletion=completion;
    [events addObject:@"dismiss"];
}
@end
@implementation SFAuthenticationViewController @end
@implementation YTInlineSignInController
- (void)didTapShowAddAccount { [events addObject:@"addAccount"]; }
@end
// The canonical InitWorkaround module owns the spinner/two-second delay and has
// its own runtime tests. Here its completion is manually delivered as a boundary.
@implementation InitWorkaround @end
static YTAlertView *lastAlert;
@implementation YTAlertView
+ (instancetype)infoDialog { lastAlert=[self new]; [events addObject:@"dialog"]; return lastAlert; }
- (void)show { [events addObject:@"show"]; }
@end
@implementation NSBundle (SideloadFixtureBundle)
+ (NSBundle *)ytl_defaultBundle { return NSBundle.mainBundle; }
@end
@interface SideloadFixtureRemote : SFAuthenticationViewController
- (void)remoteViewControllerWillDismiss:(__unsafe_unretained id)unused;
@end
@implementation SideloadFixtureRemote
- (void)remoteViewControllerWillDismiss:(__unsafe_unretained id)unused { [events addObject:@"remoteDismiss"]; }
@end

int main(void) { @autoreleasepool {
    events=[NSMutableArray array];
    method_setImplementation(class_getInstanceMethod(NSBundle.class,@selector(bundleIdentifier)),(IMP)fixtureBundleID);
    YTLInstallLocalSideloadCompatibilityHooks();
    SideloadFixtureFileManager *manager=[SideloadFixtureFileManager defaultManager];
    directoryURLs=@[[NSURL fileURLWithPath:@"/synthetic/first"],[NSURL fileURLWithPath:@"/synthetic/last"]];
    for (NSString *group in @[@"group.example", @"", @"../../arbitrary-input"]) {
        [events removeAllObjects];
        NSURL *result=[manager containerURLForSecurityApplicationGroupIdentifier:group];
        CHECK([result.path isEqual:@"/synthetic/last/AppGroup"]);
        CHECK([events isEqual:@[@"documents"]] && originalCalls==0);
    }
    directoryURLs=@[];
    CHECK([manager containerURLForSecurityApplicationGroupIdentifier:@"group.example"]==nil);
    [events removeAllObjects];
    CHECK([[[manager containerURLForSecurityApplicationGroupIdentifier:nil] path] isEqual:@"/synthetic/original"]);
    CHECK(originalCalls==1 && forwardedGroup==nil && [events isEqual:@[@"originalPath"]]);
    for (SFAuthenticationViewController *host in @[[SFAuthenticationViewController new],[SideloadFixtureRemote new]]) {
        isYTPFirstTime=NO;
        [events removeAllObjects];
        [host viewDidAppear:NO];
        CHECK([events isEqual:@[@"appeared"]] && !host.appearedAnimated && host.presented==nil);
        isYTPFirstTime=YES;
        [events removeAllObjects];
        [host viewDidAppear:YES];
        CHECK([events isEqual:@[@"appeared",@"present"]]);
        CHECK(host.appearedAnimated && host.presentAnimated && [host.presented isKindOfClass:InitWorkaround.class]);
        CHECK(isYTPFirstTime); // The presenter does not mutate the shared first-time flag.
        InitWorkaround *workaround=(InitWorkaround *)host.presented;
        CHECK(workaround.completion!=nil);
        [events removeAllObjects];
        workaround.completion();
        CHECK([events isEqual:@[@"dismiss"]] && host.dismissAnimated && host.dismissCompletion!=nil);
        host.dismissCompletion();
        NSArray *expected=[host isKindOfClass:SideloadFixtureRemote.class] ? @[@"dismiss",@"remoteDismiss",@"dialog",@"show"] : @[@"dismiss",@"dialog",@"show"];
        CHECK([events isEqual:expected]);
        CHECK([lastAlert.title isEqual:@"YouTube Plus"] && [lastAlert.subtitle isEqual:@"RetryLogin"]);
    }
    originalEnablesFirstTime=YES;
    isYTPFirstTime=NO;
    SFAuthenticationViewController *host=[SFAuthenticationViewController new];
    [host viewDidAppear:NO];
    CHECK([host.presented isKindOfClass:InitWorkaround.class]);
    originalEnablesFirstTime=NO;
    YTInlineSignInController *inlineController=[YTInlineSignInController new];
    isYTPFirstTime=NO;
    [events removeAllObjects];
    [inlineController didTapShowAddAccount];
    CHECK([events isEqual:@[@"addAccount"]]);
    isYTPFirstTime=YES;
    [events removeAllObjects];
    [inlineController didTapShowAddAccount];
    CHECK(!isYTPFirstTime && [events isEqual:@[@"bundleHook",@"addAccount"]]);
    [events removeAllObjects];
    [inlineController didTapShowAddAccount];
    CHECK([events isEqual:@[@"addAccount"]]);
    YTLInstallSideloadMetadataCompatibilityHooks();
    for (NSString *key in @[@"X-MMe-Client-Info", @"User-Agent"]) {
        for (id raw in @[[NSNull null], @{}, @{key:@"other",@"unrelated":@"keep"}, @{key:@"fixture.bundle fixture.bundle",@"unrelated":@"keep"}]) {
            originalHeaders = raw==NSNull.null ? nil : raw;
            [events removeAllObjects];
            NSDictionary *result = [key isEqual:@"User-Agent"] ? [[SideloadFixtureRequest new] allHTTPHeaderFields] : [SideloadFixtureRequest ak_clientInfoHeader];
            CHECK([events isEqual:@[[key isEqual:@"User-Agent"] ? @"originalHeaders" : @"originalClientInfo"]]);
            if (!originalHeaders) CHECK(result==nil);
            else if (!originalHeaders[key]) CHECK([result isEqual:@{}]);
            else {
                NSString *expected = [originalHeaders[key] isEqual:@"other"] ? @"other" : @"com.google.ios.youtube com.google.ios.youtube";
                CHECK([result[key] isEqual:expected] && [result[@"unrelated"] isEqual:@"keep"]);
                CHECK(![result isKindOfClass:NSMutableDictionary.class]);
                CHECK([originalHeaders[key] isEqual:raw[key]]);
            }
        }
    }
    LSApplicationProxy *proxy=[LSApplicationProxy new];
    LSBundleProxy *bundleProxy=[LSBundleProxy new];
    [events removeAllObjects];
    CHECK([[proxy teamID] isEqual:@"EQHXZ8M8AV"] && [[proxy appIDPrefix] isEqual:@"EQHXZ8M8AV"]);
    CHECK(events.count==0);
    for (id raw in @[[NSNull null], @"other", @"fixture.bundle/fixture.bundle"]) {
        originalIdentity = raw==NSNull.null ? nil : raw;
        NSString *expected = raw==NSNull.null ? nil : [raw isEqual:@"other"] ? @"other" : @"com.google.ios.youtube/com.google.ios.youtube";
        [events removeAllObjects];
        NSString *application=[proxy applicationIdentifier];
        NSString *bundle=[bundleProxy bundleIdentifier];
        CHECK(expected ? [application isEqual:expected] && [bundle isEqual:expected] : application==nil && bundle==nil);
        CHECK([events isEqual:@[@"originalAppID",@"originalBundleID"]]);
    }
    NSLog(@"Sideload compatibility: %lu real Logos runtime checks passed",(unsigned long)checks);
} return 0; }
