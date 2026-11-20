#import "../source/Controls/YTPSpeedPopupController.h"
#include <math.h>
static NSUInteger checks,deviceReads;
static NSMutableArray *animations,*devices;
static NSArray *activeConstraints;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
@interface PopupAnimation:NSObject
@property double duration,delay,damping,velocity;
@property NSUInteger options;
@property(copy) void(^animation)(void);
@property(copy) void(^completion)(BOOL);
@end
@implementation PopupAnimation @end
@implementation UIColor
+ (instancetype)named:(NSString*)n alpha:(double)a{UIColor*c=[self new];c.name=n;c.alpha=a;return c;}
+ (instancetype)blackColor{return[self named:@"black" alpha:1];}
+ (instancetype)labelColor{return[self named:@"label" alpha:1];}
+ (instancetype)clearColor{return[self named:@"clear" alpha:0];}
- (UIColor*)colorWithAlphaComponent:(CGFloat)a{return[UIColor named:_name alpha:a];}
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray*)c{activeConstraints=c;}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)a constant:(CGFloat)c{NSLayoutConstraint*n=[NSLayoutConstraint new];n.first=self;n.second=a;n.constant=c;return n;}
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutAnchor*)a{return[self constraintEqualToAnchor:a constant:0];}
- (NSLayoutConstraint*)constraintEqualToConstant:(CGFloat)c{return[self constraintEqualToAnchor:nil constant:c];}
@end
@implementation UILayoutGuide @end
@implementation UIGestureRecognizer
- (instancetype)initWithTarget:(id)t action:(SEL)a{self=[super init];if(self){_target=t;_action=a;}return self;}
- (NSInteger)state{_stateReads++;if(_states.count){NSInteger s=[_states[0]integerValue];[_states removeObjectAtIndex:0];return s;}return _state;}
@end
@implementation UITapGestureRecognizer @end
@implementation UIPanGestureRecognizer
- (CGPoint)translationInView:(UIView*)v{CHECK(v==self.coordinateView);_translationReads++;return _translation;}
- (CGPoint)velocityInView:(UIView*)v{CHECK(v==self.coordinateView);_velocityReads++;return _velocity;}
@end
@implementation UITouch @end
static NSLayoutAnchor *anchor(id o,NSString*a){NSLayoutAnchor*n=[NSLayoutAnchor new];n.owner=o;n.attribute=a;return n;}
@implementation UIView
- (instancetype)init{self=[super init];if(self){_subviews=[NSMutableArray new];_gestures=[NSMutableArray new];_layer=[CALayer layer];_translatesAutoresizingMaskIntoConstraints=YES;_bottomAnchor=anchor(self,@"bottom");_topAnchor=anchor(self,@"top");_centerXAnchor=anchor(self,@"centerX");_widthAnchor=anchor(self,@"width");_heightAnchor=anchor(self,@"height");_safeAreaLayoutGuide=[UILayoutGuide new];_safeAreaLayoutGuide.bottomAnchor=anchor(_safeAreaLayoutGuide,@"safeBottom");}return self;}
- (void)addSubview:(UIView*)v{[_subviews addObject:v];}
- (void)addGestureRecognizer:(UIGestureRecognizer*)g{[_gestures addObject:g];g.view=self;}
- (void)layoutIfNeeded{_layouts++;}
+ (void)animateWithDuration:(double)d delay:(double)delay usingSpringWithDamping:(double)damping initialSpringVelocity:(double)v options:(UIViewAnimationOptions)o animations:(void(^)(void))a completion:(void(^)(BOOL))c{PopupAnimation*r=[PopupAnimation new];r.duration=d;r.delay=delay;r.damping=damping;r.velocity=v;r.options=o;r.animation=a;r.completion=c;[animations addObject:r];}
@end
@implementation UIViewController
- (instancetype)init{self=[super init];if(self)_view=[UIView new];return self;}
- (void)viewDidLoad{_loads++;}
- (void)viewDidAppear:(BOOL)a{_appearances++;_lastAnimated=a;}
- (void)presentViewController:(UIViewController*)v animated:(BOOL)a completion:(void(^)(void))c{CHECK(!c);_presented=v;_lastAnimated=a;}
- (void)dismissViewControllerAnimated:(BOOL)a completion:(void(^)(void))c{CHECK(!c);_dismissals++;_lastAnimated=a;}
@end
@implementation UIDevice
+ (instancetype)currentDevice{deviceReads++;if(devices.count>1){id d=devices[0];[devices removeObjectAtIndex:0];return d;}return devices.firstObject;}
@end
@implementation UIScreen
+ (instancetype)mainScreen{static id s;if(!s)s=[self new];return s;}
@end
@implementation UIWindow @end
@implementation UIApplication
+ (instancetype)sharedApplication{static id a;if(!a)a=[self new];return a;}
@end
@interface PopupDelegate:NSObject<UIApplicationDelegate>
@property(strong) UIWindow *window;
@end
@implementation PopupDelegate @end
@implementation YTPSpeedControlView
+ (instancetype)speedControls{YTPSpeedControlView*v=[self new];v.bounds=CGRectMake(0,0,300,250);return v;}
@end
@interface PopupSubclass:YTPSpeedPopupController @end
@implementation PopupSubclass @end
static UIDevice*device(NSInteger idiom,NSString*model){UIDevice*d=[UIDevice new];d.userInterfaceIdiom=idiom;d.model=model;return d;}
static void setDevice(NSInteger idiom,NSString*model){devices=[NSMutableArray arrayWithObject:device(idiom,model)];deviceReads=0;}
static void geometryTests(YTPSpeedPopupController*p){
 for(NSInteger idiom=0;idiom<3;idiom++)for(NSString*model in @[@"iPad",@"iPhone",@"iPad iPhone",@"Mac"]){setDevice(idiom,model);BOOL isPad=(idiom==1||[model containsString:@"iPad"])&&![model containsString:@"iPhone"];CHECK(p.isiPad==isPad);CHECK(deviceReads==(idiom==1?2:([model containsString:@"iPad"]?3:2)));}
 devices=[NSMutableArray arrayWithObjects:device(1,@"iPad"),device(0,@"iPhone"),nil];CHECK(!p.isiPad);
 setDevice(0,@"iPhone");for(NSValue*v in @[[NSValue valueWithRect:CGRectMake(0,0,400,800)],[NSValue valueWithRect:CGRectMake(0,0,800,400)]]){UIScreen.mainScreen.bounds=v.rectValue;CHECK(p.calculateWidth==380);}
 setDevice(1,@"iPad");UIScreen.mainScreen.bounds=CGRectMake(0,0,1000,700);CHECK(p.calculateWidth==350);UIScreen.mainScreen.bounds=CGRectMake(0,0,NAN,700);CHECK(p.calculateWidth==350);UIScreen.mainScreen.bounds=CGRectMake(0,0,700,NAN);CHECK(isnan(p.calculateWidth));
 PopupDelegate*d=[PopupDelegate new];d.window=[UIWindow new];UIApplication.sharedApplication.delegate=d;for(NSNumber*top in @[@0,@20,@20.01,@44,@(NAN)]){d.window.safeAreaInsets=(UIEdgeInsets){top.doubleValue,0,0,0};CHECK(p.hasNotch==(top.doubleValue>20));CHECK(p.bottomConstant==(top.doubleValue>20?0:-10));}d.window.safeAreaInsets=(UIEdgeInsets){44,0,0,0};
}
static void layoutTests(YTPSpeedPopupController*p){setDevice(0,@"iPhone");UIScreen.mainScreen.bounds=CGRectMake(0,0,400,800);[p viewDidLoad];CHECK(p.loads==1&&p.view.backgroundColor.alpha==0.1);CHECK(p.view.subviews.count==1&&p.view.subviews[0]==p.speedView);CHECK(p.view.gestures.count==1);UIGestureRecognizer*t=p.view.gestures[0];CHECK([t isKindOfClass:UITapGestureRecognizer.class]&&t.target==p&&t.delegate==p&&t.action==@selector(dismiss));CHECK(p.speedView.gestures.count==1);UIGestureRecognizer*g=p.speedView.gestures[0];CHECK([g isKindOfClass:UIPanGestureRecognizer.class]&&g.target==p&&g.action==@selector(handlePan:)&&!g.delegate);UIView*grabber=p.speedView.subviews[0];CHECK(grabber.backgroundColor.alpha==0.3&&[grabber.backgroundColor.name isEqual:@"label"]&&grabber.layer.cornerRadius==2.5&&!grabber.translatesAutoresizingMaskIntoConstraints);CHECK(activeConstraints.count==7&&activeConstraints[6]==p.bottomConstraint&&p.bottomConstraint.constant==270);NSArray*first=@[grabber.topAnchor,grabber.centerXAnchor,grabber.widthAnchor,grabber.heightAnchor,p.speedView.centerXAnchor,p.speedView.widthAnchor,p.speedView.bottomAnchor];NSArray*second=@[p.speedView.topAnchor,p.speedView.centerXAnchor,NSNull.null,NSNull.null,p.view.centerXAnchor,NSNull.null,p.view.safeAreaLayoutGuide.bottomAnchor];NSArray*values=@[@8,@0,@36,@5,@0,@380,@270];for(NSUInteger i=0;i<7;i++){NSLayoutConstraint*c=activeConstraints[i];CHECK(c.first==first[i]&&(c.second?:NSNull.null)==second[i]&&c.constant==[values[i]doubleValue]);}}
static void animationTests(YTPSpeedPopupController*p){[animations removeAllObjects];[p viewDidAppear:YES];CHECK(p.appearances==1&&p.lastAnimated&&p.bottomConstraint.constant==0&&animations.count==1);PopupAnimation*a=animations[0];CHECK(a.duration==0.4&&a.delay==0&&a.damping==0.8&&a.velocity==0.5&&a.options==0x20000&&!a.completion);UIView*old=p.view,*newView=[UIView new];p.view=newView;a.animation();CHECK(old.layouts==0&&newView.layouts==1);p.view=old;[animations removeAllObjects];[p setValue:@1200 forKey:@"dismissVelocity"];[p dismiss];CHECK(p.bottomConstraint.constant==300&&animations.count==1&&p.dismissals==0);a=animations[0];CHECK(a.duration==0.3&&a.delay==0&&a.damping==1&&a.velocity==1.2&&a.options==0x10000&&a.completion);a.animation();CHECK([p.view.backgroundColor.name isEqual:@"clear"]&&p.view.layouts==1);a.completion(NO);CHECK(p.dismissals==1&&!p.lastAnimated);}
static void panTests(YTPSpeedPopupController*p){
 UIApplication.sharedApplication.delegate.window.safeAreaInsets=(UIEdgeInsets){0,0,0,0};UIPanGestureRecognizer*fused=[UIPanGestureRecognizer new];fused.view=p.speedView;fused.coordinateView=p.view;fused.state=2;fused.translation=CGPointMake(0,-2.66);[p handlePan:fused];CHECK(p.bottomConstraint.constant==-0x1.4cc49ba5e353fp+3);UIApplication.sharedApplication.delegate.window.safeAreaInsets=(UIEdgeInsets){44,0,0,0};
 for(NSNumber*n in @[@(-100),@0,@100,@200,@300,@(NAN)]){[animations removeAllObjects];UIPanGestureRecognizer*g=[UIPanGestureRecognizer new];g.view=p.speedView;g.coordinateView=p.view;g.state=2;g.translation=CGPointMake(0,n.doubleValue);NSUInteger layouts=p.view.layouts;[p handlePan:g];double y=n.doubleValue;CHECK(isnan(y)?isnan(p.bottomConstraint.constant):p.bottomConstraint.constant==(y>0?y:0.15*y));double alpha=isnan(y)||y<=0?0.1:y>=200?0:(1-y/200)*0.1;CHECK(p.view.backgroundColor.alpha==alpha&&p.view.layouts==layouts+1&&!animations.count&&g.translationReads==1&&!g.velocityReads);}
 for(NSInteger state=0;state<=5;state++){if(state==2)continue;for(NSNumber*y in @[@120,@120.01,@600])for(NSNumber*v in @[@120,@600,@600.01]){[animations removeAllObjects];UIPanGestureRecognizer*g=[UIPanGestureRecognizer new];g.view=p.speedView;g.coordinateView=p.view;g.state=state;g.translation=CGPointMake(0,y.doubleValue);g.velocity=CGPointMake(0,v.doubleValue);[p handlePan:g];BOOL ending=state==3||state==4;CHECK(animations.count==ending&&g.velocityReads==ending);if(!ending)continue;PopupAnimation*a=animations[0];BOOL dismiss=y.doubleValue>120||v.doubleValue>600;CHECK(a.duration==0.3&&a.delay==0&&a.damping==(dismiss?1:0.7)&&a.velocity==(dismiss?v.doubleValue/1000:0.5)&&a.options==(dismiss?0x10000:0x20000));CHECK(p.bottomConstraint.constant==(dismiss?300:0));a.animation();CHECK(p.view.backgroundColor.alpha==(dismiss?0:0.1));}}
 UITouch*t=[UITouch new];t.view=p.view;CHECK([p gestureRecognizer:nil shouldReceiveTouch:t]);t.view=p.speedView;CHECK(![p gestureRecognizer:nil shouldReceiveTouch:t]);}
static void ownershipTests(void){YTPSpeedPopupController*p=[YTPSpeedPopupController new];YTPSpeedControlView*v=[YTPSpeedControlView new];__weak id weakView=v;p.speedView=v;v=nil;CHECK(weakView!=nil);p.speedView=nil;CHECK(weakView==nil);NSLayoutConstraint*c=[NSLayoutConstraint new];__weak id weakConstraint=c;p.bottomConstraint=c;c=nil;CHECK(weakConstraint!=nil);p.bottomConstraint=nil;CHECK(weakConstraint==nil);}
int main(void){@autoreleasepool{animations=[NSMutableArray new];YTPSpeedPopupController*p=[PopupSubclass speedController];CHECK(p.class==YTPSpeedPopupController.class);CHECK(p.modalPresentationStyle==6&&p.modalTransitionStyle==2);UIViewController*owner=[UIViewController new];[p presentFromViewController:owner];CHECK(owner.presented==p&&!owner.lastAnimated);geometryTests(p);layoutTests(p);animationTests(p);panTests(p);ownershipTests();printf("SpeedPopup actual source: %lu checks passed\n",(unsigned long)checks);}return 0;}
