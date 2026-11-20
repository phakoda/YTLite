#import "ToastWindow.h"
#import "ToastView.h"
#import <objc/runtime.h>

static NSUInteger checks, failures, ancestorReads, rootReads, rootViewReads, hitCalls;
static NSUInteger sceneReads, delegateReads, windowsReads, keyReads, makeCalls, nilClassProbes;
static BOOL failInit, superMakesKey=YES, hideAncestorSelector;
static UIView *nextHit;
static UIEvent *expectedEvent;
static NSArray *appWindows;
static NSMapTable *sequences,*positions;
static NSMutableArray *probes;
#define CHECK(x) do { checks++; if(!(x)){failures++;fprintf(stderr,"FAIL %s:%d %s\n",__FILE__,__LINE__,#x);} }while(0)
const UIWindowLevel UIWindowLevelAlert=2371;
@implementation UIColor
+ (instancetype)clearColor { static UIColor *color; if(!color)color=[self new];return color; }
@end
@implementation UIEvent @end
@implementation UIView
- (UIViewController *)_viewControllerForAncestor {
    ancestorReads++;
    NSArray *sequence=[sequences objectForKey:self];
    NSUInteger index=[[positions objectForKey:self] unsignedIntegerValue];
    [positions setObject:@(index+1) forKey:self];
    id controller=index<sequence.count?sequence[index]:self.fixtureController;
    return controller==NSNull.null?nil:controller;
}
- (BOOL)respondsToSelector:(SEL)selector {
    if(hideAncestorSelector && selector==@selector(_viewControllerForAncestor))return NO;
    return [super respondsToSelector:selector];
}
@end
@implementation UIVisualEffectView @end
// Only the external class identity is needed; ToastView behavior is tested separately.
@implementation ToastView @end
@implementation UIViewController
@synthesize view=_view;
- (UIView *)view {rootViewReads++;return _view;}
- (BOOL)isKindOfClass:(Class)cls {
    if(!cls)nilClassProbes++;
    [probes addObject:cls?NSStringFromClass(cls):@"<nil>"];
    return [super isKindOfClass:cls];
}
@end
@implementation UIScene @end
@implementation UIWindowScene @end
@implementation UIWindow
@synthesize rootViewController=_rootViewController;
- (instancetype)initWithWindowScene:(UIWindowScene *)scene {
    self=[super init];if(failInit)return nil;if(self)_windowScene=scene;return self;
}
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    hitCalls++;CHECK(point.x==17.25&&point.y==-39.5);CHECK(event==expectedEvent);return nextHit;
}
- (UIViewController *)rootViewController {rootReads++;return _rootViewController;}
- (BOOL)isKeyWindow {keyReads++;return _fixtureKeyWindow;}
- (void)makeKeyAndVisible {makeCalls++;_fixtureKeyWindow=superMakesKey;}
- (void)resignKeyWindow {_fixtureResignCalls++;_fixtureKeyWindow=NO;}
- (BOOL)canBecomeKeyWindow {return YES;}
@end
@implementation UIApplication
@dynamic windows;
- (void)setWindows:(NSArray<UIWindow *> *)value {appWindows=value;}
+ (instancetype)sharedApplication {static UIApplication *app;if(!app)app=[self new];return app;}
- (NSArray<UIWindow *> *)windows {windowsReads++;return appWindows;}
- (NSSet *)connectedScenes {sceneReads++;return _connectedScenes;}
- (id<UIApplicationDelegate>)delegate {delegateReads++;return _delegate;}
@end
static void Reset(void) {
    ancestorReads=rootReads=rootViewReads=hitCalls=sceneReads=delegateReads=windowsReads=keyReads=nilClassProbes=0;
    sequences=[NSMapTable weakToStrongObjectsMapTable];positions=[NSMapTable weakToStrongObjectsMapTable];probes=[NSMutableArray new];
    nextHit=nil;hideAncestorSelector=NO;
}
static UIView *Hit(ToastWindow *window,UIView *view) {
    nextHit=view;return [window hitTest:CGPointMake(17.25,-39.5) withEvent:expectedEvent];
}
static Class Host(NSString *name,Class superclass) {
    Class cls=NSClassFromString(name);
    if(!cls){cls=objc_allocateClassPair(superclass,name.UTF8String,0);objc_registerClassPair(cls);}
    return cls;
}
static BOOL Owns(Class cls,SEL selector) {
    unsigned count=0;Method *methods=class_copyMethodList(cls,&count);BOOL found=NO;
    for(unsigned i=0;i<count;i++)if(sel_isEqual(method_getName(methods[i]),selector))found=YES;
    free(methods);return found;
}
static BOOL AliasYes(id self,SEL cmd){(void)self;(void)cmd;return YES;}
static void TestAliases(void) {
    Class cls=ToastWindow.class;
    SEL alias=NSSelectorFromString(@"_canAffectStatusBarAppearance");
    CHECK(Owns(cls,alias));
    Method a=class_getInstanceMethod(cls,alias),b=class_getInstanceMethod(cls,@selector(shouldAffectStatusBarAppearance));
    CHECK(method_getImplementation(a)==method_getImplementation(b));CHECK(!strcmp(method_getTypeEncoding(a),method_getTypeEncoding(b)));
    Class child=Host(@"ToastWindowAliasChild",cls);(void)[child new];
    CHECK(Owns(child,alias));CHECK(Owns(child,@selector(_canBecomeKeyWindow)));
    CHECK(method_getImplementation(class_getInstanceMethod(child,@selector(_canBecomeKeyWindow)))==method_getImplementation(class_getInstanceMethod(child,@selector(canBecomeKeyWindow))));
    Class grandchild=Host(@"ToastWindowAliasGrandchild",child);(void)[grandchild new];CHECK(Owns(grandchild,alias));
    Class existing=objc_allocateClassPair(cls,"ToastWindowExistingAlias",0);
    class_addMethod(existing,alias,(IMP)AliasYes,method_getTypeEncoding(b));objc_registerClassPair(existing);id instance=[existing new];
    CHECK(((BOOL(*)(id,SEL))method_getImplementation(class_getInstanceMethod(existing,alias)))(instance,alias));
}
static void TestHit(void) {
    ToastWindow *window=[ToastWindow new];UIViewController *root=[UIViewController new];UIView *rootView=[UIView new];root.view=rootView;window.rootViewController=root;
    Reset();CHECK(Hit(window,nil)==nil);CHECK(rootReads==1&&rootViewReads==1&&ancestorReads==0&&hitCalls==1);
    Reset();CHECK(Hit(window,window)==nil);CHECK(ancestorReads==5&&rootReads==0);
    Reset();CHECK(Hit(window,rootView)==nil);CHECK(ancestorReads==5&&rootReads==1&&rootViewReads==1);
    Reset();UIView *ordinary=[UIView new];__attribute__((objc_precise_lifetime)) UIViewController *ordinaryController=[UIViewController new];ordinary.fixtureController=ordinaryController;
    CHECK(Hit(window,ordinary)==nil);CHECK(ancestorReads==5&&nilClassProbes==5);CHECK(probes.count==5);
    NSArray *names=@[@"YTActionSheetDialogViewController",@"YTDefaultSheetController",@"YTActionSheetDialogViewController",@"YTBottomSheetController",@"WelcomeVC"];
    for(NSString *name in names)Host(name,UIViewController.class);
    for(NSUInteger index=0;index<names.count;index++) {
        Reset();UIView *view=[UIView new];NSMutableArray *sequence=[NSMutableArray new];
        for(NSUInteger i=0;i<index;i++)[sequence addObject:[UIViewController new]];
        [sequence addObject:[NSClassFromString(names[index]) new]];[sequences setObject:sequence forKey:view];
        CHECK(Hit(window,view)==view);CHECK(ancestorReads==index+1);CHECK(rootReads==1&&rootViewReads==1);
        CHECK([probes isEqualToArray:[names subarrayWithRange:NSMakeRange(0,index+1)]]);
        Reset();[sequences setObject:sequence forKey:view];hideAncestorSelector=YES;
        CHECK(Hit(window,view)==view);CHECK(ancestorReads==index+1);
    }
    Reset();ToastView *toast=[ToastView new];CHECK(Hit(window,toast)==toast);CHECK(ancestorReads==0&&rootReads==1);
    Reset();UIView *child=[UIView new];child.superview=toast;CHECK(Hit(window,child)==child);CHECK(ancestorReads==5);
    Reset();UIView *grandchild=[UIView new];grandchild.superview=child;CHECK(Hit(window,grandchild)==grandchild);CHECK(ancestorReads==10);
    Reset();__attribute__((objc_precise_lifetime)) UIViewController *action=[NSClassFromString(@"YTActionSheetDialogViewController") new];window.fixtureController=action;child.superview=window;
    CHECK(Hit(window,child)==child);CHECK(ancestorReads==6);window.fixtureController=nil;
    Reset();__attribute__((objc_precise_lifetime)) UIViewController *welcome=[NSClassFromString(@"WelcomeVC") new];rootView.fixtureController=welcome;CHECK(Hit(window,rootView)==nil);CHECK(ancestorReads==5&&rootReads==1);rootView.fixtureController=nil;
    Reset();window.fixtureController=welcome;CHECK(Hit(window,window)==nil);CHECK(ancestorReads==5&&rootReads==0);window.fixtureController=nil;
    Class forwarding=Host(@"YTTouchForwardingView",UIView.class);
    for(Class cls in @[forwarding,Host(@"ForwardingSubclass",forwarding)]) {
        Reset();UIView *view=[cls new];CHECK(Hit(window,view)==view);CHECK(ancestorReads==5);
        Reset();child.superview=view;CHECK(Hit(window,child)==child);CHECK(ancestorReads==10);
    }
    Reset();window.rootViewController=nil;UIView *unknown=[UIView new];CHECK(Hit(window,unknown)==nil);CHECK(rootReads==1&&rootViewReads==0);
}
static void TestKeyWindow(void) {
    ToastWindow *window=[ToastWindow new];UIWindow *a=[UIWindow new],*b=[UIWindow new];
    for(id list in @[NSNull.null,@[],@[a,b]]) {
        Reset();appWindows=list==NSNull.null?nil:list;CHECK([window appKeyWindow]==nil);CHECK(windowsReads==1&&sceneReads==0&&delegateReads==0);CHECK(keyReads==appWindows.count);
    }
    a.fixtureKeyWindow=YES;b.fixtureKeyWindow=YES;
    Reset();appWindows=@[a,b];CHECK([window appKeyWindow]==a);CHECK(keyReads==1&&windowsReads==1&&sceneReads==0&&delegateReads==0);
    Reset();appWindows=@[b,a];CHECK([window appKeyWindow]==b);CHECK(keyReads==1);
    Reset();window.fixtureKeyWindow=YES;appWindows=@[window,a];CHECK([window appKeyWindow]==window);CHECK(keyReads==1);
    Reset();NSMutableArray *many=[NSMutableArray new];for(NSUInteger i=0;i<35;i++)[many addObject:[UIWindow new]];[many addObject:a];[many addObject:b];appWindows=many;
    CHECK([window appKeyWindow]==a);CHECK(keyReads==36&&sceneReads==0&&delegateReads==0);
}
static void TestRemaining(void) {
    UIWindowScene *scene=[UIWindowScene new];ToastWindow *window=[[ToastWindow alloc]initWithWindowScene:scene];
    CHECK(window.windowScene==scene);CHECK(window.windowLevel==2370);CHECK(window.backgroundColor==UIColor.clearColor);
    failInit=YES;CHECK([[ToastWindow alloc]initWithWindowScene:scene]==nil);failInit=NO;
    CHECK(!window.canBecomeKeyWindow);CHECK(!window.shouldAffectStatusBarAppearance);CHECK(!window._windowControlsStatusBarOrientation);CHECK(!window._canBecomeKeyWindow);
    makeCalls=0;superMakesKey=YES;[window makeKeyAndVisible];CHECK(makeCalls==1&&window.fixtureResignCalls==1&&!window.isKeyWindow);
    superMakesKey=NO;[window makeKeyAndVisible];CHECK(makeCalls==2&&window.fixtureResignCalls==1&&!window.isKeyWindow);
}
int main(void) {@autoreleasepool {
    expectedEvent=[UIEvent new];TestAliases();TestRemaining();TestHit();TestKeyWindow();
    printf("Toast window: %lu checks, %lu failures\n",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
