#import "../source/Support/Dvbug.h"
#import "../source/Runtime/InitWorkaround.h"
#import <objc/runtime.h>
#include <stdarg.h>
static NSMutableArray *logs;
static dispatch_block_t delayed;
static NSDictionary *originalInfo;
static NSUInteger checks, hookCalls;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
void YTLHelpersTestLog(NSString *format, ...) {
    va_list args; va_start(args,format); [logs addObject:[[NSString alloc] initWithFormat:format arguments:args]]; va_end(args);
}
dispatch_time_t YTLHelpersTestTime(dispatch_time_t base,int64_t delta) { CHECK(base==0 && delta==2000000000); return 42; }
void YTLHelpersTestAfter(dispatch_time_t when,dispatch_queue_t queue,dispatch_block_t block) { CHECK(when==42 && queue==dispatch_get_main_queue()); delayed=block; }
static NSDictionary *fixtureInfo(NSBundle *bundle,SEL selector) { CHECK(bundle!=nil && selector==@selector(infoDictionary)); return originalInfo; }
void MSHookMessageEx(Class cls,SEL selector,IMP replacement,IMP *original) {
    CHECK(cls==NSBundle.class && selector==@selector(infoDictionary) && replacement==(IMP)replaceInfoDict);
    hookCalls++; *original=(IMP)fixtureInfo;
}
@implementation UIColor
+ (instancetype)whiteColor { static UIColor *white; if (!white) white=[self new]; return white; }
@end
@implementation UIView
- (void)addSubview:(UIView *)view { if (!_subviews) _subviews=[NSMutableArray array]; [_subviews addObject:view]; }
@end
@implementation UIViewController
- (void)viewDidLoad { self.loaded++; }
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion { CHECK(animated); self.dismissed=YES; self.dismissal=completion; }
@end
@implementation UIActivityIndicatorView
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style { if ((self=[super init])) _style=style; return self; }
- (void)startAnimating { self.animating=YES; }
@end
@interface IvarFixture : NSObject {
@public
    id objectValue;
    long long number;
    unsigned char before, flag, after;
}
- (id)objectValue;
@end
@implementation IvarFixture
- (id)objectValue { return @"accessor value"; }
@end
int main(void) { @autoreleasepool {
    logs=[NSMutableArray array];
    IvarFixture *fixture=[IvarFixture new]; fixture->objectValue=@"stored value"; fixture->number=0x102030405060708;
    fixture->before=0xaa; fixture->flag=0x80; fixture->after=0xbb;
    CHECK([[Dvbug instanceForObject:fixture name:@"objectValue"] isEqual:@"accessor value"]);
    CHECK([[Dvbug getObservedIvar:fixture name:@"objectValue"] isEqual:@"stored value"]);
    [Dvbug setObservedIvar:fixture name:@"objectValue" value:@"changed"]; CHECK([fixture->objectValue isEqual:@"changed"]);
    [Dvbug observeIvar:fixture name:@"objectValue"]; CHECK([logs.lastObject isEqual:@"DVN --- objectValue: changed"]);
    [Dvbug setObservedIvar:fixture name:@"objectValue" value:nil]; CHECK(!fixture->objectValue);
    [Dvbug observeIvar:fixture name:@"objectValue"]; CHECK([logs.lastObject isEqual:@"DVN --- objectValue: (null)"]);
    [Dvbug observeIvar:fixture name:@"missing"]; CHECK([logs.lastObject isEqual:@"DVN --- ivar missing not found in class IvarFixture"]);
    CHECK(![Dvbug instanceForObject:nil name:@"objectValue"] && [logs.lastObject containsString:@"senderObject"]);
    CHECK(![Dvbug instanceForObject:fixture name:@""] && [logs.lastObject containsString:@"or name"]);
    CHECK(![Dvbug instanceForObject:fixture name:@"missing"] && ![Dvbug getObservedIvar:fixture name:@"missing"]);
    [Dvbug setObservedIvar:fixture name:@"missing" value:@"ignored"];
    CHECK([Dvbug getObservedIntIvar:fixture name:@"number"]==fixture->number);
    CHECK([Dvbug getObservedIvarLongLong:fixture name:@"number"]==fixture->number);
    fixture->number=-0x100000008; CHECK([Dvbug getObservedIntIvar:fixture name:@"number"]==fixture->number);
    CHECK([Dvbug getObservedIntIvar:fixture name:@"missing"]==0 && [Dvbug getObservedIvarLongLong:fixture name:@"missing"]==0);
    CHECK([Dvbug getObservedBoolIvar:fixture name:@"flag"] && ![Dvbug getObservedBoolIvar:fixture name:@"missing"]);
    [Dvbug setObservedBoolIvar:fixture name:@"flag" value:NO]; CHECK(fixture->flag==0 && fixture->before==0xaa && fixture->after==0xbb);
    [Dvbug setObservedBoolIvar:fixture name:@"flag" value:YES]; CHECK(fixture->flag==1 && fixture->before==0xaa && fixture->after==0xbb);
    [Dvbug setObservedBoolIvar:fixture name:@"missing" value:NO]; CHECK(fixture->flag==1);
    InitWorkaround *controller=[InitWorkaround new]; controller.view=[UIView new]; controller.view.center=CGPointMake(150,300);
    __block NSUInteger completed=0; controller.completion=^{ completed++; };
    CHECK(isYTPFirstTime == YES); [controller viewDidLoad];
    CHECK(!isYTPFirstTime && controller.loaded==1 && !controller.dismissed && !hookCalls && !completed);
    CHECK(controller.view.subviews.count==1);
    UIActivityIndicatorView *spinner=controller.view.subviews.firstObject;
    CHECK(spinner.style==101 && spinner.animating && spinner.color==UIColor.whiteColor && CGPointEqualToPoint(spinner.center,controller.view.center));
    delayed(); CHECK(hookCalls==1 && controller.dismissed && !completed);
    controller.dismissal(); CHECK(completed==1);
    controller.completion=nil; controller.dismissal(); CHECK(completed==1);
    originalInfo=@{@"CFBundleIdentifier":@"original.id",@"unchanged":@YES};
    NSDictionary *main=replaceInfoDict(NSBundle.mainBundle,@selector(infoDictionary));
    CHECK([main[@"CFBundleIdentifier"] isEqual:@"com.google.ios.youtube"] && [main isKindOfClass:NSMutableDictionary.class]);
    CHECK([originalInfo[@"CFBundleIdentifier"] isEqual:@"original.id"] && [main[@"unchanged"] boolValue]);
    NSBundle *other=[NSBundle bundleForClass:NSObject.class]; CHECK(![other isEqual:NSBundle.mainBundle]);
    NSDictionary *copy=replaceInfoDict(other,@selector(infoDictionary)); CHECK([copy isEqual:originalInfo] && copy!=originalInfo);
    originalInfo=@{}; CHECK([replaceInfoDict(NSBundle.mainBundle,@selector(infoDictionary))[@"CFBundleIdentifier"] isEqual:@"com.google.ios.youtube"]);
    printf("PASS: %lu bootstrap/helper assertions; real Objective-C ivars, intercepted hook installation and UI timing\n",(unsigned long)checks);
} return 0; }
