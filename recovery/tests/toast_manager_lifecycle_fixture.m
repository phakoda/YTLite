#import "../source/Presentation/ToastManager.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastWindow.h"
#import <objc/runtime.h>

static NSUInteger checks, lockDepth, layoutCalls, windowCalls, newCalls, subclassSharedCalls;
static NSMutableArray<dispatch_block_t> *pending;
static NSMutableArray *events;
static id lockedObject;
static BOOL shouldMutate;
static ToastManager *activeManager;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
void YTLManagerDispatch(dispatch_queue_t queue, dispatch_block_t block) {
    CHECK(queue == dispatch_get_main_queue());
    [events addObject:@"dispatch"];
    [pending addObject:[block copy]];
}
int YTLManagerSyncEnter(id object) {
    if (lockDepth) CHECK(object == lockedObject);
    else lockedObject = object;
    lockDepth++;
    [events addObject:@"enter"];
    return 0;
}
int YTLManagerSyncExit(id object) {
    CHECK(lockDepth && object == lockedObject);
    [events addObject:@"exit"];
    if (!--lockDepth) lockedObject = nil;
    return 0;
}
@implementation UIView @end
@implementation UIWindow @end
@implementation UIVisualEffectView @end
@implementation ToastWindow @end
@implementation ToastView
+ (instancetype)new { newCalls++; return [super new]; }
+ (ToastWindow *)toastWindow { windowCalls++; return nil; }
- (void)updateLayout {
    layoutCalls++;
    [events addObject:@"layout"];
    if (shouldMutate) { shouldMutate=NO; [activeManager.toasts addObject:[[ToastView alloc] init]]; }
}
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success {
    [events addObject:@[text ?: NSNull.null, @(success)]];
}
@end
@interface LifecycleManagerSubclass : ToastManager @end
@implementation LifecycleManagerSubclass
+ (instancetype)sharedManager { subclassSharedCalls++; return [super sharedManager]; }
@end
static void Reset(void) {
    [events removeAllObjects]; [pending removeAllObjects];
    CHECK(lockDepth==0); layoutCalls=windowCalls=0;
}
int main(void) { @autoreleasepool {
    pending=[NSMutableArray new]; events=[NSMutableArray new];
    activeManager=[[ToastManager alloc] init];
    ToastView *one=[[ToastView alloc] init], *two=[[ToastView alloc] init];
    [activeManager registerToast:one];
    CHECK(windowCalls==0);
    CHECK(layoutCalls==1 && pending.count==0);
    CHECK([events isEqual:@[@"enter",@"enter",@"layout",@"exit",@"exit"]]);
    CHECK([activeManager.toasts isEqual:@[one]]);
    Reset(); [activeManager registerToast:one];
    CHECK(layoutCalls==0 && activeManager.toasts.count==1);
    CHECK([events isEqual:@[@"enter",@"exit"]]);
    Reset(); [activeManager registerToast:two];
    CHECK(layoutCalls==2);
    CHECK([events isEqual:@[@"enter",@"enter",@"layout",@"layout",@"exit",@"exit"]]);
    Reset(); [activeManager registerToast:nil]; [activeManager unregisterToast:nil];
    CHECK(events.count==0 && activeManager.toasts.count==2);
    Reset(); [activeManager unregisterToast:one];
    CHECK(layoutCalls==1 && [activeManager.toasts isEqual:@[two]]);
    CHECK([events isEqual:@[@"enter",@"enter",@"layout",@"exit",@"exit"]]);
    Reset(); [activeManager unregisterToast:one];
    CHECK(layoutCalls==1);
    Reset(); [activeManager updateAllToasts];
    CHECK([events isEqual:@[@"enter",@"layout",@"exit"]]);
    // A snapshot silently tolerates mutation; original fast enumeration reports it.
    [activeManager.toasts addObject:one]; Reset(); shouldMutate=YES;
    BOOL mutationRaised=NO;
    @try { [activeManager updateAllToasts]; }
    @catch (NSException *exception) { mutationRaised=[exception.name isEqual:NSGenericException]; }
    CHECK(mutationRaised && lockDepth==0);
    Reset(); [activeManager.toasts removeAllObjects]; [activeManager updateAllToasts];
    CHECK([events isEqual:@[@"enter",@"exit"]]);
    // The method runs synchronously on its caller's thread, even off the main queue.
    dispatch_sync(dispatch_get_global_queue(QOS_CLASS_DEFAULT,0), ^{
        [activeManager registerToast:one];
        CHECK(layoutCalls==1 && pending.count==0);
    });
    Reset();
    ToastManager *singleton=[ToastManager sharedManager]; [singleton.toasts removeAllObjects];
    [LifecycleManagerSubclass showMessageWithText:@"shown later" isSuccess:YES];
    CHECK(subclassSharedCalls==0 && newCalls==0);
    CHECK(singleton.toasts.count==1 && layoutCalls==1 && pending.count==1);
    CHECK([events.lastObject isEqual:@"dispatch"]);
    CHECK([events isEqual:@[@"enter",@"enter",@"layout",@"exit",@"exit",@"dispatch"]]);
    dispatch_block_t block=pending.firstObject; [pending removeAllObjects]; block(); block=nil;
    CHECK([events.lastObject isEqual:@[@"shown later",@YES]]);
    Reset(); [singleton.toasts removeAllObjects];
    __weak NSString *weakText; __weak ToastView *weakToast;
    @autoreleasepool {
        NSString *text=[[NSMutableString alloc] initWithString:@"captured text"];
        weakText=text;
        [ToastManager showMessageWithText:text isSuccess:NO];
        weakToast=singleton.toasts.lastObject;
        [singleton.toasts removeAllObjects]; text=nil;
    }
    CHECK(weakText && weakToast && pending.count==1);
    @autoreleasepool { dispatch_block_t delivery=pending.firstObject; [pending removeAllObjects]; delivery(); }
    CHECK([events.lastObject isEqual:@[@"captured text",@NO]]);
    [events removeAllObjects];
    CHECK(!weakToast && !weakText);
    activeManager=nil;
    printf("Toast manager lifecycle: %lu checks passed\n",(unsigned long)checks);
} return 0; }
