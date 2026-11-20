#import "toast_lifecycle_doubles.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastManager.h"
#import "../source/Presentation/ToastWindow.h"
#include <math.h>
#include <float.h>
static NSUInteger checks,managerUpdates,cleanups,processed,hiddenCalls;
static NSMutableArray *commands,*completions,*flow;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
@implementation ToastManager
+ (instancetype)sharedManager{static ToastManager*m;if(!m){m=[self new];m.toasts=[NSMutableArray new];}return m;}
- (void)registerToast:(ToastView*)t{[_toasts addObject:t];}
- (void)unregisterToast:(ToastView*)t{[_toasts removeObjectIdenticalTo:t];}
- (void)updateAllToasts{managerUpdates++;}
@end
@implementation ToastWindow @end
@interface LifecycleToast:ToastView @end
@implementation LifecycleToast
- (instancetype)init{self=[super initWithEffect:nil];if(self){_commandQueue=[NSMutableArray new];_toastLabel=[UILabel new];_toastProgress=[UIProgressView new];_toastButton=[UIButton buttonWithType:0];_actionsStack=[[UIStackView alloc]initWithArrangedSubviews:@[]];_widthConstraint=[self.widthAnchor constraintEqualToConstant:123];}return self;}
- (void)cleanup{cleanups++;[flow addObject:@"cleanup"];}
- (void)processQueue{processed++;[flow addObject:@"process"];}
- (void)removeObservers{}
@end
@interface HideProbe:LifecycleToast @end
@implementation HideProbe
- (void)hideAnimatedWithCompletion:(dispatch_block_t)c{hiddenCalls++;[flow addObject:@"animated"];if(c)c();}
@end
@interface TimerProbe:LifecycleToast @end
@implementation TimerProbe
- (void)hide{hiddenCalls++;[flow addObject:@"hide"];}
@end
@interface CommandProbe:LifecycleToast @end
@implementation CommandProbe
- (void)enqueueCommand:(dispatch_block_t)c{[commands addObject:[c copy]];}
- (void)hideWithCompletion:(dispatch_block_t)c{[flow addObject:@"hideCompletion"];if(c)c();}
- (void)setupInterfaceWithText:(NSString*)t progress:(float)p withStop:(BOOL)stop isStatus:(BOOL)status isSuccess:(BOOL)success withWait:(BOOL)wait{[flow addObject:@{ @"text":t?:NSNull.null,@"progress":@(p),@"stop":@(stop),@"status":@(status),@"success":@(success),@"wait":@(wait)}];}
- (void)calculateToastParametersWithKeyboardHeight:(double)k bottomOffset:(double*)b topOffset:(double*)t scale:(double*)s{CHECK(k==0);*b=11;*t=22;*s=0.9;_widthConstraint=[self.widthAnchor constraintEqualToConstant:321];}
- (void)configureToastAppearanceWithBottomOffset:(double)b topOffset:(double)t scale:(double)s width:(double)w alpha:(double)a animationDuration:(double)d completion:(dispatch_block_t)c{CHECK(b==11&&t==22&&s==0.9&&w==321&&a==1&&d==0.3);[flow addObject:@"configure"];if(c)[completions addObject:[c copy]];}
- (void)startTimerCountdown:(double)d{[flow addObject:@{@"timer":@(d)}];}
- (void)hideWithDelay:(double)d{[flow addObject:@{@"delay":@(d)}];}
- (void)hide{hiddenCalls++;}
@end
static void reset(void){ToastLifecycleResetScheduling();cleanups=processed=hiddenCalls=0;[flow removeAllObjects];[commands removeAllObjects];[completions removeAllObjects];PresentationResetEvents();}
static void delayTests(void){HideProbe*t=[HideProbe new];t.alpha=0;[t hideWithDelay:0];CHECK(hiddenCalls==0);PresentationAdvanceTime(0);CHECK(hiddenCalls==1&&cleanups==0&&processed==0);reset();for(NSNumber*n in @[@(-0.5),@0,@1,@(NAN),@(INFINITY),@(-INFINITY)]){[t hideWithDelay:n.doubleValue];NSDictionary*e=PresentationEventsOfKind(@"dispatch.delta").lastObject;double ns=n.doubleValue*1e9;int64_t expected=isnan(ns)?0:ns>=0x1p63?INT64_MAX:ns<=-0x1p63?INT64_MIN:(int64_t)ns;CHECK([e[@"value"]longLongValue]==expected);} }
static void hideTests(void){reset();LifecycleToast*t=[LifecycleToast new];[t setValue:@YES forKey:@"isAnimating"];t.alpha=0.75;[t hideImmediately];CHECK(cleanups==1&&processed==1&&t.alpha==0.75&&[[t valueForKey:@"isAnimating"]boolValue]);reset();HideProbe*p=[HideProbe new];p.alpha=0;[p hideWithCompletion:nil];CHECK(!cleanups&&!processed&&!hiddenCalls);__block int calls=0;[p hideWithCompletion:^{calls++;}];CHECK(calls==1&&PresentationMainQueue.count==0);p.alpha=1;[p hideWithCompletion:^{calls++;}];CHECK(calls==1&&hiddenCalls==0);PresentationDrainMain();CHECK(calls==2&&hiddenCalls==1);managerUpdates=0;BOOL result=p.isHidden;(void)result;CHECK(managerUpdates==0);PresentationAdvanceTime(0.3);CHECK(managerUpdates==1);}
static void timerTests(void){reset();TimerProbe*t=[TimerProbe new];PresentationFixtureTimer*sentinel=[PresentationFixtureTimer timerWithTimeInterval:9 repeats:YES block:^(id timer){}];[t setValue:sentinel forKey:@"progressTimer"];[t startTimerCountdown:0.032];CHECK([t valueForKey:@"progressTimer"]==sentinel&&sentinel.valid);NSArray*timers=[PresentationFixtureRunLoop.mainRunLoop.timers copy];CHECK(timers.count==1);PresentationFixtureTimer*timer=timers[0];CHECK(timer.timeInterval==0.016&&timer.repeats&&timer.valid);timer.fixtureBlock(timer);CHECK([(UIProgressView*)[t valueForKey:@"toastProgress"]progress]==0.5f&&!hiddenCalls);timer.fixtureBlock(timer);CHECK(!timer.valid&&hiddenCalls==1&&[t valueForKey:@"progressTimer"]==sentinel);for(NSNumber*d in @[@0,@(-0.0),@(-1),@(NAN),@(INFINITY),@(-INFINITY),@(DBL_MIN),@(DBL_MAX)]){hiddenCalls=0;[t startTimerCountdown:d.doubleValue];timer=PresentationFixtureRunLoop.mainRunLoop.timers.lastObject;CHECK(timer.valid);timer.fixtureBlock(timer);if((d.doubleValue==0&&!signbit(d.doubleValue))||d.doubleValue==DBL_MIN){CHECK(!timer.valid&&hiddenCalls==1);}else{CHECK(timer.valid&&hiddenCalls==0);if(isnan(d.doubleValue))CHECK(isnan([(UIProgressView*)[t valueForKey:@"toastProgress"]progress]));[timer invalidate];}}
 __weak id weak;@autoreleasepool{TimerProbe*owned=[TimerProbe new];weak=owned;[owned startTimerCountdown:1];}CHECK(weak!=nil);timer=PresentationFixtureRunLoop.mainRunLoop.timers.lastObject;[timer invalidate];CHECK(weak==nil);
}
static void commandTests(void){reset();__weak CommandProbe*weak;@autoreleasepool{CommandProbe*t=[CommandProbe new];weak=t;[t showText:@"hello"];}CHECK(weak!=nil&&commands.count==1);dispatch_block_t c=commands[0];[commands removeAllObjects];c();c=nil;CHECK(weak!=nil&&completions.count==1);c=completions[0];[completions removeAllObjects];c();c=nil;CHECK(weak==nil);}
static void invokeCommand(CommandProbe *t, NSUInteger variant, dispatch_block_t completion) {
    switch (variant) {
    case 0: [t showProgressWithText:@"text" progress:0.375f withStop:YES stopCompletion:completion]; break;
    case 1: [t showMessageWithText:@"text" isSuccess:YES duration:4.25]; break;
    case 2: [t showText:@"text"]; break;
    case 3: [t showToast:@"text"]; break;
    case 4: [t showProgressiveToastWithText:@"text" duration:4.25 isSuccess:YES]; break;
    case 5: [t showProgressiveToastWithText:@"text" duration:4.25 actionTitle:@"Go" actionCompletion:completion]; break;
    case 6: [t showProgressiveToastWithText:@"text" duration:4.25 actionIcon:[UIImage systemImageNamed:@"icon"] ignoresPan:YES actionCompletion:completion]; break;
    case 7: [t showDonationReminder:@"text"]; break;
    case 8: [t showMessageWithText:@"text" isSuccess:NO]; break;
    case 9: [t showProgressiveToastWithText:@"text" duration:4.25 actionIcon:[UIImage systemImageNamed:@"icon"] actionCompletion:completion]; break;
    }
}
static void allCommandTests(void) {
    for (NSUInteger variant=0;variant<10;variant++) for (NSUInteger supplied=0;supplied<2;supplied++) {
        reset(); __block NSUInteger actions=0; CommandProbe *t=[CommandProbe new];
        dispatch_block_t old=^{actions+=100;}; t.completion=old;
        dispatch_block_t replacement=supplied ? ^{actions++;} : nil;
        invokeCommand(t,variant,replacement);
        CHECK(commands.count==1 && flow.count==0);
        dispatch_block_t command=commands.firstObject; [commands removeAllObjects]; command(); command=nil;
        CHECK([flow.firstObject isEqual:@"hideCompletion"]);
        NSDictionary *setup=flow[1];
        CHECK([setup[@"text"] isEqual:@"text"]);
        CHECK([setup[@"progress"] floatValue]==(variant==0?0.375f:variant>=4&&variant!=8?1:0));
        CHECK([setup[@"stop"] boolValue]==(variant==0||variant==6||variant==9));
        CHECK([setup[@"status"] boolValue]==(variant==1||variant==4||variant==8));
        CHECK([setup[@"success"] boolValue]==(variant==1||variant==4));
        CHECK([setup[@"wait"] boolValue]==(variant==3));
        CHECK([[t valueForKey:@"ignoresFullscreenOpacity"] boolValue]==(variant==4||variant==5||variant==6||variant==9));
        CHECK([[t valueForKey:@"ignoresPanGesture"] boolValue]==(variant==6||variant==7));
        CHECK([flow[2] isEqual:@"configure"]);
        BOOL completionExpected=variant==0||variant==1||variant==2||variant==3||variant==6||variant==8||variant==9;
        CHECK(completions.count==(completionExpected?1:0));
        if (completions.count) {dispatch_block_t c=completions.firstObject;[completions removeAllObjects];c();}
        if (variant==0||variant==6||variant==9) CHECK(t.completion==(supplied?replacement:old));
        else CHECK(t.completion==old);
        if (variant==1||variant==2||variant==8) CHECK([flow.lastObject[@"delay"] doubleValue]==(variant==1?4.25:2.5));
        if (variant>=4&&variant!=8) CHECK([flow.lastObject[@"timer"] doubleValue]==(variant==7?10:4.25));
        if (variant==3) {
            [t setValue:@YES forKey:@"isAnimating"];
            PresentationAdvanceTime(0.499); CHECK(processed==0);
            PresentationAdvanceTime(0.002); CHECK(processed==1&&![[t valueForKey:@"isAnimating"] boolValue]);
        }
        if (variant==5) {
            UIStackView *stack=[t valueForKey:@"actionsStack"]; UIButton *button=(UIButton *)stack.arrangedSubviews.lastObject;
            CHECK(button!=nil&&stack.arrangedSubviews.count==1);
            UIAction *action=button.fixtureActions.firstObject[@"action"];
            CHECK(action!=nil); action.fixtureHandler(action); CHECK(actions==supplied&&hiddenCalls==1);
            [button.fixtureActions removeAllObjects];
        }
        if (variant==5||variant==6||variant==9) {
            UILabel *label=[t valueForKey:@"toastLabel"];
            CHECK(label.textAlignment==NSTextAlignmentNatural);
        }
    }
    for (NSUInteger variant=0;variant<8;variant++) {
        reset(); __weak CommandProbe *weak;
        @autoreleasepool { CommandProbe *t=[CommandProbe new];weak=t;invokeCommand(t,variant,nil); }
        CHECK(weak!=nil); [commands removeAllObjects]; CHECK(weak==nil);
    }
    reset(); __weak CommandProbe *weak; UIAction *retainedAction;
    @autoreleasepool {
        CommandProbe *t=[CommandProbe new]; weak=t; invokeCommand(t,5,nil);
        dispatch_block_t command=commands.firstObject; [commands removeAllObjects]; command();
        UIButton *button=(UIButton *)[(UIStackView *)[t valueForKey:@"actionsStack"] arrangedSubviews].lastObject;
        retainedAction=button.fixtureActions.firstObject[@"action"]; [button.fixtureActions removeAllObjects];
    }
    CHECK(weak!=nil); retainedAction.fixtureHandler(retainedAction); CHECK(hiddenCalls==1);
    retainedAction=nil; CHECK(weak==nil);
}
static void animationTests(void) {
    for (NSUInteger supplied=0;supplied<2;supplied++) for (NSUInteger animating=0;animating<2;animating++) {
        reset(); LifecycleToast *t=[LifecycleToast new]; [t setValue:@(animating) forKey:@"isAnimating"];
        PresentationFixtureTimer *sentinel=[PresentationFixtureTimer timerWithTimeInterval:1 repeats:YES block:^(id x){}];
        [t setValue:sentinel forKey:@"progressTimer"]; __block NSUInteger called=0;
        dispatch_block_t completion=supplied?^{called++;}:nil; [t hideAnimatedWithCompletion:completion];
        CHECK(sentinel.valid&&[t valueForKey:@"progressTimer"]==sentinel);
        CHECK([[t valueForKey:@"isAnimating"] boolValue]==animating);
        CABasicAnimation *scale=(id)t.layer.fixtureAnimations[@"scale"],*fade=(id)t.layer.fixtureAnimations[@"opacity"];
        CHECK([scale.keyPath isEqual:@"transform.scale"]&&[scale.fromValue doubleValue]==1&&[scale.toValue doubleValue]==0.8);
        CHECK([fade.keyPath isEqual:@"opacity"]&&[fade.fromValue doubleValue]==1&&[fade.toValue doubleValue]==0);
        CHECK(scale.duration==0.3&&fade.duration==0.3&&[scale.timingFunction.name isEqual:@"easeIn"]&&[fade.timingFunction.name isEqual:@"easeIn"]);
        CHECK(t.layer.transform.m11==0.8&&t.layer.transform.m22==0.8&&t.layer.transform.m33==1&&t.layer.opacity==0);
        CHECK(called==0&&cleanups==0&&processed==0);
        PresentationCompleteAnimations(NO);
        CHECK(![[t valueForKey:@"isAnimating"] boolValue]&&called==supplied);
        CHECK(cleanups==!supplied&&processed==!supplied&&sentinel.valid);
    }
}
@interface UpdatingProbe:LifecycleToast @end
@implementation UpdatingProbe
- (void)updateText:(NSString*)text progress:(float)progress animated:(BOOL)animated{CHECK(NO);}
@end
@interface CompletionProbe:TimerProbe
@property(nonatomic) NSUInteger reads;
@property(nonatomic,copy) dispatch_block_t first,second;
@end
@implementation CompletionProbe
- (dispatch_block_t)completion {self.reads++;return self.reads==1?self.first:self.second;}
@end
static void directTests(void) {
    reset(); UpdatingProbe *u=[UpdatingProbe new];[u updateText:@"direct" progress:0.25f];
    CHECK([[(UILabel*)[u valueForKey:@"toastLabel"] text] isEqual:@"direct"]);
    UIProgressView *p=[u valueForKey:@"toastProgress"];CHECK(p.progress==0.25f&&p.fixtureAnimated);
    LifecycleToast *t=[LifecycleToast new]; dispatch_semaphore_t done=dispatch_semaphore_create(0);
    [NSThread detachNewThreadWithBlock:^{@autoreleasepool{[t updateText:@"background" progress:0.75f animated:NO];dispatch_semaphore_signal(done);}}];
    CHECK(dispatch_semaphore_wait(done,DISPATCH_TIME_FOREVER)==0);
    CHECK(PresentationMainQueue.count==0&&[[(UILabel*)[t valueForKey:@"toastLabel"] text] isEqual:@"background"]);
    CHECK([(UIProgressView*)[t valueForKey:@"toastProgress"] progress]==0.75f);
    for (NSUInteger ignores=0;ignores<2;ignores++) for (NSUInteger supplied=0;supplied<2;supplied++) {
        reset(); CompletionProbe *c=[CompletionProbe new];__block NSUInteger a=0,b=0;
        c.first=supplied?^{a++;}:nil;c.second=^{b++;};[c setValue:@(ignores) forKey:@"ignoresPanGesture"];
        [c cancelButtonTapped];CHECK(c.reads==(supplied?2:1)&&a==0&&b==supplied&&hiddenCalls==!ignores);
    }
    TimerProbe *longPress=[TimerProbe new]; UILongPressGestureRecognizer *gesture=[UILongPressGestureRecognizer new];
    for (NSInteger state=0;state<=5;state++){hiddenCalls=0;gesture.state=state;[longPress handleLongPress:gesture];CHECK(hiddenCalls==(state==UIGestureRecognizerStateBegan));}
    PresentationFixtureTimer *sentinel=[PresentationFixtureTimer timerWithTimeInterval:1 repeats:YES block:^(id x){}];
    @autoreleasepool{LifecycleToast *owned=[LifecycleToast new];[owned setValue:sentinel forKey:@"progressTimer"];}
    CHECK(sentinel.valid);
}
int main(void){@autoreleasepool{PresentationInitialize();commands=[NSMutableArray new];completions=[NSMutableArray new];flow=[NSMutableArray new];delayTests();hideTests();timerTests();commandTests();allCommandTests();animationTests();directTests();printf("Toast lifecycle actual source: %lu checks passed\n",(unsigned long)checks);}return 0;}
