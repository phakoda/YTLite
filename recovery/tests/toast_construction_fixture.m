#import "presentation_doubles.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastWindow.h"
#import "../source/Presentation/ToastManager.h"
#import <objc/runtime.h>
static NSUInteger checks, sceneReads, windowInits, keyCalls, trapReads, deviceReads;
static BOOL createdOnMain;
static NSArray *sceneValues;
static id fixtureApp;
static IMP oldDevice;
static NSUInteger centerReads, observerAdds, observerRemoves, layoutUpdates;
static BOOL lastLayoutMain;
static double scaleAtPinnedRead;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
@interface ConstructionScenes : NSObject <NSFastEnumeration>
@property(nonatomic,strong) NSArray *values;
- (NSArray *)allObjects;
@end
@implementation ConstructionScenes
- (NSArray *)allObjects { return _values; }
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained *)buffer count:(NSUInteger)count {
    return [_values countByEnumeratingWithState:state objects:buffer count:count];
}
@end
@interface ConstructionApp : UIApplication @end
@implementation ConstructionApp
- (NSSet *)connectedScenes {
    ConstructionScenes *result=[ConstructionScenes new];
    result.values=sceneValues[MIN(sceneReads,sceneValues.count-1)];sceneReads++;
    return (id)result;
}
@end
static id GetApp(id cls,SEL sel) { (void)cls;(void)sel;return fixtureApp; }
static id GetDevice(id cls,SEL sel) { deviceReads++; return ((id(*)(id,SEL))oldDevice)(cls,sel); }
@implementation ToastWindow
- (instancetype)initWithWindowScene:(UIWindowScene *)scene {
    windowInits++;createdOnMain=NSThread.isMainThread;
    return [super initWithWindowScene:scene];
}
- (void)makeKeyAndVisible { keyCalls++;[super makeKeyAndVisible]; }
@end
@interface ConstructionToast : ToastView @end
@implementation ConstructionToast
+ (ToastWindow *)toastWindow { trapReads++;return nil; }
- (void)updateLayout {layoutUpdates++;lastLayoutMain=NSThread.isMainThread;}
- (BOOL)isPinnedTop {scaleAtPinnedRead=self.transform.a;return NO;}
@end
@implementation ConstructionNotificationCenter
+ (instancetype)defaultCenter {centerReads++;static id center;if(!center)center=[self new];return center;}
- (void)addObserver:(id)observer selector:(SEL)selector name:(NSString *)name object:(id)object {(void)observer;(void)selector;(void)name;(void)object;observerAdds++;}
- (void)removeObserver:(id)observer name:(NSString *)name object:(id)object {(void)observer;(void)name;(void)object;observerRemoves++;}
@end
static id Get(id object,NSString *key) { return [object valueForKey:key]; }
static void Set(id object,NSString *key,id value) { [object setValue:value forKey:key]; }
static UIWindowScene *Scene(NSInteger state) { UIWindowScene *s=[UIWindowScene new];s.activationState=state;s.windows=@[];return s; }
static void NotificationChecks(void) {
    ConstructionToast *toast=[[ConstructionToast alloc] init];
    centerReads=observerAdds=observerRemoves=0;
    [toast setupObservers];CHECK(centerReads==3 && observerAdds==3 && observerRemoves==0);
    [toast setupObservers];CHECK(centerReads==6 && observerAdds==6 && observerRemoves==0);
    [toast removeObservers];CHECK(centerReads==9 && observerRemoves==3);
    layoutUpdates=0;[PresentationMainQueue removeAllObjects];
    dispatch_semaphore_t done=dispatch_semaphore_create(0);
    NSThread *thread=[[NSThread alloc] initWithBlock:^{
        [toast goodHeightDidChange:[NSNotification notificationWithName:@"height" object:nil userInfo:@{@"height":@1.234567890123}]];
        CHECK(layoutUpdates==1 && !lastLayoutMain);
        CHECK([Get(toast,@"_goodHeight") doubleValue]==(double)(float)1.234567890123);
        [toast keyboardWillShow:[NSNotification notificationWithName:@"keyboard" object:nil userInfo:@{UIKeyboardFrameEndUserInfoKey:[NSValue valueWithCGRect:CGRectMake(0,0,100,222)]}]];
        CHECK(layoutUpdates==2 && !lastLayoutMain && [Get(toast,@"_keyboardHeight") doubleValue]==222);
        [toast keyboardWillHide:nil];CHECK(layoutUpdates==3 && !lastLayoutMain && [Get(toast,@"_keyboardHeight") doubleValue]==0);
        CHECK(PresentationMainQueue.count==0);dispatch_semaphore_signal(done);
    }];[thread start];CHECK(dispatch_semaphore_wait(done,DISPATCH_TIME_FOREVER)==0);
}
static void ConfigureChecks(void) {
    ConstructionToast *toast=[[ConstructionToast alloc] init];
    [toast setupInterfaceWithText:@"configure" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
    UIView *source=Get(toast,@"_sourceView");toast.hidden=YES;
    NSUInteger layouts=source.fixtureLayouts;
    __block NSUInteger completions=0;
    [toast configureToastAppearanceWithBottomOffset:10 topOffset:20 scale:.8 width:200 alpha:.7 animationDuration:.2 completion:^{completions++;}];
    CHECK(toast.hidden);CHECK(source.fixtureLayouts==layouts);
    CHECK(toast.alpha==.7 && toast.transform.a==.8);
    PresentationCompleteAnimations(NO);CHECK(completions==1);
    Set(toast,@"_ignoresFullscreenOpacity",@YES);toast.hidden=YES;
    [toast configureToastAppearanceWithBottomOffset:11 topOffset:21 scale:.6 width:210 animationDuration:.3];
    CHECK(toast.hidden && source.fixtureLayouts==layouts+1 && scaleAtPinnedRead==.6);
    CHECK([Get(toast,@"_bottomConstraint") constant]==-11 && [Get(toast,@"_widthConstraint") constant]==210 && [Get(toast,@"_topConstraint") constant]==21);
    [toast cleanup];
}
int main(int argc,const char **argv) { @autoreleasepool {
    CHECK(argc==2);NSString *mode=@(argv[1]);PresentationInitialize();
    ConstructionApp *app=[ConstructionApp new];fixtureApp=app;
    PresentationAppDelegate *delegate=[PresentationAppDelegate new];app.delegate=delegate;
    UIWindowScene *inactive=Scene(1), *active=Scene(0), *fallback=Scene(1);
    sceneValues=[mode isEqual:@"empty"]?@[@[],@[]]:
        [mode isEqual:@"fallback"]?@[@[inactive],@[fallback]]:@[@[inactive,active]];
    method_setImplementation(class_getClassMethod(UIApplication.class,@selector(sharedApplication)),(IMP)GetApp);
    __block ToastWindow *window;
    if ([mode isEqual:@"background"]) {
        dispatch_semaphore_t done=dispatch_semaphore_create(0);
        NSThread *thread=[[NSThread alloc] initWithBlock:^{ window=[ToastView toastWindow];dispatch_semaphore_signal(done); }];
        [thread start];CHECK(dispatch_semaphore_wait(done,DISPATCH_TIME_FOREVER)==0);
        CHECK(window && !createdOnMain);
    } else window=[ToastView toastWindow];
    if ([mode isEqual:@"notifications"] || [mode isEqual:@"configure"]) {
        if ([mode isEqual:@"notifications"]) NotificationChecks(); else ConfigureChecks();
    } else if ([mode isEqual:@"empty"]) {
        CHECK(window==nil && sceneReads==2);sceneValues=@[@[active]];
        CHECK([ToastView toastWindow]==nil);CHECK(windowInits==0 && sceneReads==2);
    } else {
        CHECK(windowInits==1 && window);
        CHECK(window.windowScene==([mode isEqual:@"fallback"]?fallback:active));
        CHECK(sceneReads==([mode isEqual:@"fallback"]?2:1));
        CHECK(PresentationMainQueue.count==1 && keyCalls==0);
        CHECK([ToastView toastWindow]==window && windowInits==1);
        PresentationDrainMain();CHECK(keyCalls==1);
        CHECK(CGRectEqualToRect(window.frame,UIScreen.mainScreen.bounds));
        CHECK(window.rootViewController.view.fixtureConstraints.count==4);
        CHECK(!window.rootViewController.view.translatesAutoresizingMaskIntoConstraints);
        // The init uses the global window and app delegate directly.
        ConstructionToast *toast=[[ConstructionToast alloc] init];
        CHECK(trapReads==0 && Get(toast,@"_sourceView")==window.rootViewController.view);
        CHECK(Get(toast,@"_ytSourceView")==nil);
        NSArray *models=@[@"iPhone",@"iPad",@"iPhone iPad",@"Mac",@""];
        oldDevice=method_setImplementation(class_getClassMethod(UIDevice.class,@selector(currentDevice)),(IMP)GetDevice);
        UIDevice *device=UIDevice.currentDevice;
        for (NSInteger idiom=0;idiom<3;idiom++) for (NSString *model in models) {
            device.model=model;device.userInterfaceIdiom=idiom;deviceReads=0;
            ConstructionToast *candidate=[[ConstructionToast alloc] init];
            BOOL pad=(idiom==1 || [model containsString:@"iPad"]) && ![model containsString:@"iPhone"];
            CHECK([Get(candidate,@"_isiPad") boolValue]==pad);
            NSUInteger expected=idiom==1?2:([model containsString:@"iPad"]?3:2);
            CHECK(deviceReads==expected);
        }
        device.model=@"iPhone";device.userInterfaceIdiom=0;
        __block NSUInteger delivered=0;
        [toast enqueueCommand:^{delivered++;}];CHECK(delivered==1 && [Get(toast,@"_isAnimating") boolValue]);
        [toast enqueueCommand:^{delivered+=10;}];CHECK(delivered==1);
        Set(toast,@"_isAnimating",@NO);[toast processQueue];CHECK(delivered==11);
        BOOL raised=NO;@try { [toast enqueueCommand:nil]; } @catch(NSException *e) {raised=[e.name isEqual:NSInvalidArgumentException];}CHECK(raised);
        Set(toast,@"_isAnimating",@NO);
        dispatch_semaphore_t done=dispatch_semaphore_create(0);
        NSThread *thread=[[NSThread alloc] initWithBlock:^{
            [toast enqueueCommand:^{CHECK(!NSThread.isMainThread);delivered++;}];
            CHECK(delivered==12);dispatch_semaphore_signal(done);
        }];[thread start];CHECK(dispatch_semaphore_wait(done,DISPATCH_TIME_FOREVER)==0);
        CHECK(PresentationMainQueue.count==0);
        // Repeated setup preserves prior UI and constraint state in the package.
        UILabel *label=Get(toast,@"_toastLabel");UIFont *font=[UIFont systemFontOfSize:23 weight:UIFontWeightBold];label.font=font;label.textAlignment=NSTextAlignmentLeft;
        UIButton *button=Get(toast,@"_toastButton");UIImage *icon=[UIImage systemImageNamed:@"custom"];[button setImage:icon forState:UIControlStateNormal];
        UIStackView *stack=Get(toast,@"_actionsStack");UIView *extra=[UIView new];[stack addArrangedSubview:extra];
        PresentationFixtureTimer *timer=[PresentationFixtureTimer timerWithTimeInterval:2 repeats:YES block:^(id t){(void)t;}];Set(toast,@"_progressTimer",timer);
        dispatch_block_t completion=^{delivered++;};toast.completion=completion;
        UIView *source=Get(toast,@"_sourceView");
        [toast setupInterfaceWithText:@"first" progress:.3 withStop:YES isStatus:NO isSuccess:YES withWait:NO];
        NSLayoutConstraint *oldBottom=Get(toast,@"_bottomConstraint");
        NSUInteger gestureCount=toast.gestureRecognizers.count;
        [toast setupInterfaceWithText:@"second" progress:.7 withStop:NO isStatus:YES isSuccess:NO withWait:YES];
        CHECK(Get(toast,@"_sourceView")==source && trapReads==0);
        CHECK(timer.valid && Get(toast,@"_progressTimer")==timer && toast.completion==completion);
        CHECK(oldBottom.active && toast.gestureRecognizers.count==gestureCount+2);
        CHECK([stack.arrangedSubviews containsObject:extra] && label.font==font && label.textAlignment==NSTextAlignmentLeft);
        CHECK(button.fixtureImage==icon && button.hidden);
        CHECK([label.text isEqual:@"second"] && [(UIProgressView *)Get(toast,@"_toastProgress") progress]==.7f);
        CHECK([(UIActivityIndicatorView *)Get(toast,@"_activityIndicator") fixtureAnimating]);
        [toast cleanup];CHECK(!timer.valid && toast.completion==completion);
        CHECK(Get(toast,@"_sourceView")==source);
    }
    printf("Toast construction: %lu checks passed mode=%s\n",(unsigned long)checks,argv[1]);
} return 0; }
