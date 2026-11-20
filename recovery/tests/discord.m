#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <UIKit/UIKit.h>
#import "../source/Discord/YTPDiscordRPC.h"
#import "../source/Models/RPCMedia.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSString+YTLite.h"

static NSUInteger checks;
static void Check(BOOL success, NSString *description) {
    checks++;
    if (!success) { fprintf(stderr, "FAIL: %s\n", description.UTF8String); exit(1); }
}
static NSMutableArray *asyncBlocks, *afterBlocks, *tasks;
static NSTimeInterval clockValue;
static NSUInteger delayedCalls;
static NSURL *openedURL;
static NSDictionary *openedOptions;
static BOOL openCompletionWasNil;

void YTLDiscordTestAsync(dispatch_queue_t queue, dispatch_block_t block) {
    Check(queue == dispatch_get_main_queue(), @"permission completion goes to main queue");
    [asyncBlocks addObject:[block copy]];
}
dispatch_time_t YTLDiscordTestTime(dispatch_time_t base, int64_t delta) {
    Check(base == DISPATCH_TIME_NOW && delta == NSEC_PER_SEC, @"startup waits one second from now");
    return 77;
}
void YTLDiscordTestAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block) {
    Check(when == 77 && queue == dispatch_get_main_queue(), @"startup schedules on main queue");
    delayedCalls++;
    [afterBlocks addObject:[block copy]];
}
static void Drain(NSMutableArray *blocks) {
    NSArray *ready = [blocks copy]; [blocks removeAllObjects];
    for (dispatch_block_t block in ready) block();
}
NSString *const UIApplicationOpenSettingsURLString = @"app-settings:";
@implementation UIApplication
+ (instancetype)sharedApplication { static UIApplication *app; if (!app) app = [self new]; return app; }
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {
    openedURL = url; openedOptions = options; openCompletionWasNil = completion == nil;
}
@end
@implementation NSString (YTLite)
- (NSString *)ytl_localized { return [@"localized:" stringByAppendingString:self]; }
@end
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults {
    static YTLUserDefaults *defaults;
    if (!defaults) defaults = [[self alloc] initWithSuiteName:@"com.ytlite.recovery.discord.offline"];
    return defaults;
}
@end
#pragma clang diagnostic pop
@interface YTAlertView : NSObject
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *subtitle;
@property(nonatomic, strong) NSMutableArray *buttons;
@property(nonatomic, strong) NSMutableArray *actions;
@property(nonatomic) BOOL shown;
+ (instancetype)dialog;
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action;
- (void)show;
@end
static NSMutableArray<YTAlertView *> *alerts;
@implementation YTAlertView
+ (instancetype)dialog {
    YTAlertView *dialog = [self new]; dialog.buttons = [NSMutableArray array]; dialog.actions = [NSMutableArray array];
    [alerts addObject:dialog]; return dialog;
}
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action {
    [self.buttons addObject:title]; [self.actions addObject:action ? [action copy] : [NSNull null]];
}
- (void)show { self.shown = YES; }
@end
@interface DiscordTask : NSObject
@property(nonatomic, strong) NSURLRequest *request;
@property(nonatomic, copy) void (^completion)(NSData *, NSURLResponse *, NSError *);
- (void)resume;
@end
@implementation DiscordTask
- (void)resume { [tasks addObject:self]; }
@end
@interface DiscordSession : NSObject
- (DiscordTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData *, NSURLResponse *, NSError *))completion;
@end
@implementation DiscordSession
- (DiscordTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData *, NSURLResponse *, NSError *))completion {
    DiscordTask *task = [DiscordTask new]; task.request = [request copy]; task.completion = completion; return task;
}
@end
static NSError *Error(NSInteger code) { return [NSError errorWithDomain:@"test.synthetic" code:code userInfo:@{NSLocalizedDescriptionKey: @"offline fixture error"}]; }
static NSDictionary *Body(DiscordTask *task) { return [NSJSONSerialization JSONObjectWithData:task.request.HTTPBody options:0 error:NULL]; }
static void Finish(DiscordTask *task, NSError *error) {
    task.completion([@"unused data" dataUsingEncoding:NSUTF8StringEncoding], [[NSHTTPURLResponse alloc] initWithURL:task.request.URL statusCode:503 HTTPVersion:@"HTTP/1.1" headerFields:@{}], error);
}
static void Reset(void) { [tasks removeAllObjects]; [alerts removeAllObjects]; [asyncBlocks removeAllObjects]; [afterBlocks removeAllObjects]; }
static RPCMedia *Media(NSString *videoID) { RPCMedia *media = [RPCMedia new]; media.videoID = videoID; return media; }

static void URLs(void) {
    YTPDiscordRPC *rpc = [YTPDiscordRPC new];
    NSDictionary *examples = @{@"127.0.0.1": @"http://127.0.0.1:5001/update",
      @"https://desktop.example/": @"http://desktop.example:5001/update",
      @"http://host.test:8080/custom?x=1#two": @"http://host.test:8080/custom?x=1#two",
      @"https://host.test:443/rpc": @"http://host.test:443/rpc",
      @"http://[::1]": @"http://[::1]:5001/update"};
    for (NSString *input in examples) { rpc.serverURL = input; Check([rpc.serverURL isEqual:examples[input]], input); }
    NSMutableString *input = [@"host.test" mutableCopy]; rpc.serverURL = input; [input appendString:@"changed"];
    Check([rpc.serverURL isEqual:@"http://host.test:5001/update"], @"stored normalized URL independent of mutable input");
    Check([YTPDiscordRPC sharedPresence] == [YTPDiscordRPC sharedPresence], @"sharedPresence singleton identity");
}

static void Permissions(void) {
    [YTPDiscordRPC sharedPresence].serverURL = @"permission.test";
    NSArray *codes = @[@0, @(-1009), @(-1004), @(-1001), @(-1003), @(-1)];
    for (NSNumber *code in codes) {
        Reset(); __block NSUInteger callbacks = 0; __block BOOL permitted = NO, server = NO;
        [YTPDiscordRPC checkLocalNetworkPermission:^(BOOL p, BOOL s) { callbacks++; permitted = p; server = s; }];
        Check(tasks.count == 1, @"probe task resumed once");
        DiscordTask *task = tasks.lastObject;
        Check([task.request.URL.absoluteString isEqual:@"http://permission.test:5001/update"], @"probe uses normalized singleton URL");
        Check([task.request.HTTPMethod isEqual:@"GET"] && !task.request.HTTPBody, @"probe GET has no body");
        Check(task.request.timeoutInterval == 3.0, @"probe timeout three seconds");
        Finish(task, code.integerValue ? Error(code.integerValue) : nil);
        Check(callbacks == 0 && asyncBlocks.count == 1, @"permission callback asynchronously dispatched");
        Drain(asyncBlocks);
        Check(callbacks == 1, @"permission callback invoked once");
        Check(permitted == (code.integerValue != -1009), @"exact permission code mapping");
        Check(server == (code.integerValue != -1009 && code.integerValue != -1004), @"exact availability code mapping including timeout");
    }
}

static void Start(void) {
    YTLUserDefaults *defaults = [YTLUserDefaults standardUserDefaults];
    [defaults removePersistentDomainForName:@"com.ytlite.recovery.discord.offline"];
    YTPDiscordRPC *rpc = [YTPDiscordRPC new];
    Reset(); [rpc startIfPossible]; Check(!tasks.count && !alerts.count, @"disabled RPC does nothing");
    [defaults setBool:YES forKey:@"discordRPC"];
    [rpc startIfPossible]; Check(!tasks.count && alerts.count == 1, @"missing address shows alert without probe");
    Check([alerts.lastObject.subtitle isEqual:@"localized:RPC.MissingServerAddress"], @"missing address localized message");
    [defaults setObject:@"next.test:88/endpoint" forKey:@"rpcAddress"];
    NSArray *codes = @[@0, @(-1009), @(-1004), @(-1001)];
    for (NSNumber *code in codes) {
        for (NSNumber *suppress in @[@NO, @YES]) {
            Reset(); [defaults setBool:suppress.boolValue forKey:@"rpcNoServerAlerts"];
            rpc = [YTPDiscordRPC new]; rpc.media = Media(@"video");
            [YTPDiscordRPC sharedPresence].serverURL = @"old.test";
            [rpc startIfPossible];
            Check(tasks.count == 1 && !alerts.count, @"enabled with address probes before acting");
            Check(!rpc.serverURL, @"server not assigned before permission result");
            DiscordTask *probe = tasks.lastObject;
            Check([probe.request.URL.host isEqual:@"old.test"], @"probe uses existing singleton URL rather than captured preference");
            Finish(probe, code.integerValue ? Error(code.integerValue) : nil); Drain(asyncBlocks);
            if (code.integerValue == -1009) {
                Check(alerts.count == 1 && [alerts.lastObject.subtitle isEqual:@"localized:RPC.LocalPermissionRequired"], @"denied permission always alerts");
                Check(alerts.lastObject.buttons.count == 2 && !rpc.serverURL && !afterBlocks.count, @"denied permission offers settings and does not start");
            } else if (code.integerValue == -1004) {
                Check(alerts.count == (suppress.boolValue ? 0 : 1), @"missing server respects suppression preference");
                if (!suppress.boolValue) Check([alerts.lastObject.subtitle isEqual:@"localized:RPC.DesktopServerRequired"], @"missing server message");
                Check(!rpc.serverURL && !afterBlocks.count, @"missing server does not start");
            } else {
                Check(!alerts.count && [rpc.serverURL isEqual:@"http://next.test:88/endpoint"], @"success or timeout assigns captured address");
                Check(afterBlocks.count == 1, @"startup schedules initial send");
            }
        }
    }
    Reset(); rpc = [YTPDiscordRPC new];
    [rpc startIfPossible]; [defaults setObject:@"changed.test" forKey:@"rpcAddress"];
    Finish(tasks.lastObject, nil); Drain(asyncBlocks);
    Check([rpc.serverURL isEqual:@"http://next.test:88/endpoint"], @"permission completion retains address captured at start");
    [defaults removePersistentDomainForName:@"com.ytlite.recovery.discord.offline"];
}

static void Playback(void) {
    Reset(); clockValue = 100;
    YTPDiscordRPC *rpc = [YTPDiscordRPC new]; rpc.serverURL = @"playback.test";
    Check([rpc buildBody] == nil, @"no media produces nil body");
    [rpc startRPC]; [rpc updateTime]; [rpc updateState]; [rpc clearPlayback]; [rpc sendBody];
    Check(!tasks.count && !afterBlocks.count, @"no media lifecycle methods do nothing");
    rpc.media = Media(@"v1"); rpc.media.isPaused = YES;
    NSDictionary *body = [rpc buildBody];
    Check(body.count == 7 && [body[@"title"] isEqual:@""] && [body[@"channel"] isEqual:@""] && [body[@"thumbnail_url"] isEqual:@""], @"nil media fields use empty strings");
    Check([body[@"state"] isEqual:@"paused"] && [body[@"video_id"] isEqual:@"v1"], @"body carries pause state and identifier");
    rpc.media.title = @"A title 🎵"; rpc.media.author = @"Creator"; rpc.media.thumbnailURL = @"https://image.test/i";
    rpc.media.currentTime = 12.125; rpc.media.totalTime = 99.75;
    body = [rpc buildBody];
    Check([body[@"title"] isEqual:@"A title 🎵"] && [body[@"channel"] isEqual:@"Creator"] && [body[@"thumbnail_url"] isEqual:rpc.media.thumbnailURL], @"body text fields mapped exactly");
    Check([body[@"current_time"] doubleValue] == 12.125 && [body[@"total_time"] doubleValue] == 99.75, @"body preserves double times");
    [rpc updateTime]; [rpc updateState]; Check(!tasks.count, @"update before start ignores unmatched video");
    [rpc startRPC]; Check(afterBlocks.count == 1 && !tasks.count, @"new video defers first send");
    [rpc startRPC]; Check(afterBlocks.count == 1, @"same video does not schedule another startup");
    Drain(afterBlocks); Check(!rpc.media.isPaused && tasks.count == 1, @"delayed start clears pause and sends");
    DiscordTask *post = tasks.lastObject;
    Check([post.request.HTTPMethod isEqual:@"POST"] && post.request.timeoutInterval == 5.0, @"POST timeout five seconds");
    Check([[post.request valueForHTTPHeaderField:@"Content-Type"] isEqual:@"application/json"], @"POST JSON content type");
    Check([Body(post) isEqual:[rpc buildBody]], @"POST serializes complete actual body as JSON");
    Finish(post, nil); Finish(post, Error(-1004)); Check(tasks.count == 1, @"POST errors do not retry");
    [rpc updateTime]; Check(tasks.count == 1, @"same timestamp throttled");
    clockValue = 100.999; [rpc updateState]; Check(tasks.count == 1, @"less than one second throttled");
    clockValue = 101; rpc.media.isPaused = YES; [rpc updateState];
    Check(tasks.count == 2 && [Body(tasks.lastObject)[@"state"] isEqual:@"paused"], @"exact one second boundary sends new state");
    clockValue = 99; [rpc sendBody]; Check(tasks.count == 2, @"backwards wall clock remains throttled");
    clockValue = 102; [rpc updateTime]; Check(tasks.count == 3, @"time updates send after interval");
    rpc.media = Media(@"v2"); [rpc updateTime]; [rpc updateState]; Check(tasks.count == 3, @"changed video update ignored before start");
    [rpc startRPC]; [rpc sendBody]; Check(tasks.count == 4, @"new video resets throttle immediately");
    [rpc clearPlayback]; Check(!rpc.media && tasks.count == 5 && [Body(tasks.lastObject) isEqual:@{@"state":@"stopped"}], @"clear bypasses throttle with stopped only body");
    [rpc clearPlayback]; Check(tasks.count == 5, @"second clear does nothing");
    Drain(afterBlocks); Check(tasks.count == 5, @"pending initial callback after clear sends nothing");
    rpc.media = Media(@"v2"); [rpc startRPC]; Check(afterBlocks.count == 1, @"clear resets current video ID");
    rpc.media = Media(@"unstarted"); Drain(afterBlocks); Check(tasks.count == 5, @"delayed callback checks current media against saved ID");
    Reset(); rpc = [YTPDiscordRPC new]; rpc.serverURL = @"replacement.test"; rpc.media = Media(@"a");
    [rpc startRPC]; rpc.media = Media(@"b"); rpc.media.isPaused = YES; [rpc startRPC];
    Check(afterBlocks.count == 2, @"video replacement retains both scheduled blocks");
    Drain(afterBlocks); Check(tasks.count == 1 && [Body(tasks.lastObject)[@"video_id"] isEqual:@"b"], @"older callback observes latest current ID; throttle suppresses duplicate");
    rpc.media = Media(nil); body = [rpc buildBody]; Check([body[@"video_id"] isEqual:@""], @"nil ID uses empty body value");
}

static void Alerts(void) {
    Reset(); YTPDiscordRPC *rpc = [YTPDiscordRPC new];
    [rpc showAlertWithMessage:@"message.key" showSettingsButton:NO];
    YTAlertView *alert = alerts.lastObject;
    Check(alert.shown && [alert.title isEqual:@"localized:YouTube Plus Discord RPC"] && [alert.subtitle isEqual:@"localized:message.key"], @"alert title/subtitle localized and shown");
    Check([alert.buttons isEqual:@[@"OK"]] && alert.actions[0] == NSNull.null, @"OK button remains literal with nil action");
    [rpc showAlertWithMessage:@"permission" showSettingsButton:YES]; alert = alerts.lastObject;
    Check([alert.buttons isEqual:@[@"localized:RPC.OpenSettings", @"OK"]], @"settings button precedes OK");
    dispatch_block_t action = alert.actions[0]; action();
    Check([openedURL.absoluteString isEqual:UIApplicationOpenSettingsURLString] && openedOptions.count == 0 && openCompletionWasNil, @"settings opens application settings URL with empty options and nil completion");
}

int main(void) {
    @autoreleasepool {
        tasks = [NSMutableArray array]; alerts = [NSMutableArray array]; asyncBlocks = [NSMutableArray array]; afterBlocks = [NSMutableArray array];
        DiscordSession *session = [DiscordSession new];
        Method sessionMethod = class_getClassMethod(NSURLSession.class, @selector(sharedSession));
        IMP originalSession = method_setImplementation(sessionMethod, imp_implementationWithBlock(^id(id receiver) { return session; }));
        Method dateMethod = class_getClassMethod(NSDate.class, @selector(date));
        IMP originalDate = method_setImplementation(dateMethod, imp_implementationWithBlock(^id(id receiver) { return [NSDate dateWithTimeIntervalSince1970:clockValue]; }));
        URLs(); Permissions(); Start(); Playback(); Alerts();
        method_setImplementation(sessionMethod, originalSession); method_setImplementation(dateMethod, originalDate);
        printf("YTPDiscordRPC: %lu runtime checks passed; all NSURLSession calls intercepted; zero network requests.\n", (unsigned long)checks);
    }
    return 0;
}
