#import "../source/Presentation/DVNSheetPresenter.h"
#import "../source/Presentation/PseudoDetentTransitioningDelegate.h"
#import <objc/message.h>
#import <math.h>
#include <stdio.h>
static NSUInteger checks,failures,viewNews,viewFrames,presents,nativeQueries,availabilityReads;
static BOOL nativeAvailable=YES,nativeSelector=YES,sawDelegate,failPresentationInit;
static __weak id lastDelegate;
static DVNHeightCalculator savedCalculator;
static NSMutableArray<NSString *> *events;
#define CHECK(c) do{checks++;if(!(c)){failures++;fprintf(stderr,"FAIL %d: %s\n",__LINE__,#c);}}while(0)
static BOOL equalFP(double a,double b){return isnan(b)?isnan(a):(a==b&&(b!=0||!!signbit(a)==!!signbit(b)));}
BOOL SheetNativeAvailable(void){availabilityReads++;return nativeAvailable;}
@implementation CALayer
@synthesize cornerRadius=_cornerRadius;
- (void)setCornerRadius:(CGFloat)v{_cornerRadius=v;_radiusWrites++;}
@end
@implementation UIColor
+ (instancetype)blackColor{return [self new];}
- (instancetype)colorWithAlphaComponent:(CGFloat)v{UIColor *c=[UIColor new];c.opacity=v;return c;}
@end
@implementation UITapGestureRecognizer
- (instancetype)initWithTarget:(id)t action:(SEL)a{self=[super init];if(self){_target=t;_action=a;}return self;}
@end
@implementation UIView
+ (instancetype)new{viewNews++;return [super new];}
- (instancetype)init{self=[super init];if(self){_children=[NSMutableArray new];_gestures=[NSMutableArray new];_layer=[CALayer new];_alpha=1;}return self;}
- (instancetype)initWithFrame:(CGRect)f{self=[self init];if(self){viewFrames++;_frame=f;_bounds=CGRectMake(0,0,f.size.width,f.size.height);}return self;}
- (void)addGestureRecognizer:(UITapGestureRecognizer *)g{[_gestures addObject:g];}
- (void)addSubview:(UIView *)v{[v removeFromSuperview];[_children addObject:v];v.superview=self;}
- (void)removeFromSuperview{[self.superview.children removeObjectIdenticalTo:self];self.superview=nil;}
@end
@implementation UIViewController
@synthesize view=_view;
- (instancetype)init{self=[super init];if(self){_view=[[UIView alloc]initWithFrame:CGRectMake(0,0,390,844)];_childViewControllers=@[];}return self;}
- (UIView *)view{_viewReads++;return _view;}
- (UISheetPresentationController *)sheetPresentationController{if(!_sheetPresentationController)_sheetPresentationController=[[UISheetPresentationController alloc]initWithPresentedViewController:self presentingViewController:nil];return _sheetPresentationController;}
- (void)presentViewController:(UIViewController *)c animated:(BOOL)a completion:(void (^)(void))completion{
    presents++;CHECK(a&&completion==nil);id<UIViewControllerTransitioningDelegate>d=c.transitioningDelegate;sawDelegate=d!=nil;lastDelegate=d;
    if(d){savedCalculator=[(PseudoDetentTransitioningDelegate *)d heightCalculator];c.presentationController=[d presentationControllerForPresentedViewController:c presentingViewController:self sourceViewController:self];}
}
- (void)dismissViewControllerAnimated:(BOOL)a completion:(void (^)(void))completion{CHECK(a&&completion==nil);_dismissals++;}
@end
@implementation UIPresentationController
- (instancetype)initWithPresentedViewController:(UIViewController *)p presentingViewController:(UIViewController *)q{self=[super init];if(failPresentationInit)return nil;if(self){_presentedViewController=p;_presentingViewController=q;_containerView=[[UIView alloc]initWithFrame:CGRectMake(0,0,390,844)];}return self;}
- (UIView *)presentedView{return self.presentedViewController.view;}
- (CGRect)frameOfPresentedViewInContainerView{return self.containerView.bounds;}
- (void)containerViewWillLayoutSubviews{_layouts++;}
@end
@implementation UISheetPresentationControllerDetent
+ (BOOL)respondsToSelector:(SEL)s{nativeQueries++;return s==@selector(_detentWithIdentifier:constant:)?nativeSelector:[super respondsToSelector:s];}
+ (instancetype)_detentWithIdentifier:(NSString *)s constant:(CGFloat)h{UISheetPresentationControllerDetent*d=[self new];d.identifier=s;d.height=h;return d;}
@end
@implementation UISheetPresentationController @end
@interface Coordinator:NSObject<UIViewControllerTransitionCoordinator,UIViewControllerTransitionCoordinatorContext>
@property(nonatomic,copy) void(^animation)(id<UIViewControllerTransitionCoordinatorContext>),(^completion)(id<UIViewControllerTransitionCoordinatorContext>);
@property(nonatomic,getter=isCancelled) BOOL cancelled;
@property BOOL accept;
@property NSUInteger cancelledReads,calls;
@end
@implementation Coordinator
- (BOOL)isCancelled{_cancelledReads++;return _cancelled;}
- (BOOL)animateAlongsideTransition:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))a completion:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))c{self.animation=a;self.completion=c;_calls++;return _accept;}
@end
@interface ControllerProbe:PseudoDetentController
@property NSUInteger dimSets,dimReads,heightReads,calculatorReads;
@property BOOL probeHeight;
@end
@implementation ControllerProbe
- (void)setDimmingView:(UIView *)v{_dimSets++;[super setDimmingView:v];}
- (UIView *)dimmingView{_dimReads++;return [super dimmingView];}
- (double)customHeight{_heightReads++;[events addObject:@"height"];return _probeHeight?777:[super customHeight];}
- (DVNHeightCalculator)heightCalculator{_calculatorReads++;[events addObject:@"calculator"];if(!_probeHeight)return [super heightCalculator];if(_calculatorReads==1)return ^CGFloat(CGSize s){return 999;};return ^CGFloat(CGSize s){CHECK(s.width==390&&s.height==844);return 123;};}
@end
@interface DelegateProbe:PseudoDetentTransitioningDelegate @end
@implementation DelegateProbe
- (double)customHeight{[events addObject:@"height"];return 321;}
- (DVNHeightCalculator)heightCalculator{[events addObject:@"calculator"];return ^CGFloat(CGSize s){return s.width+1;};}
@end
static void checkBlock(id block,const char*signature,BOOL capturesObject,NSUInteger size) {
    struct BlockHeader{void *isa;unsigned flags,reserved;void *invoke;uintptr_t *descriptor;};
    const struct BlockHeader *b=(__bridge const void *)block;
    CHECK(b!=NULL);if(!b)return;
    CHECK(!!(b->flags&(1u<<25))==capturesObject);CHECK(b->flags&(1u<<30));CHECK(b->descriptor[1]==size);
    const char *actual=(const char *)b->descriptor[capturesObject?4:2];CHECK(strcmp(actual,signature)==0);
    if(capturesObject)CHECK(b->descriptor[5]==0x100);
}
static void testController(void){
    UIViewController*p=[UIViewController new];NSUInteger oldNews=viewNews;ControllerProbe*c=[[ControllerProbe alloc]initWithPresentedViewController:p presentingViewController:nil];
    CHECK(viewNews==oldNews);CHECK(c.dimSets==1&&c.dimReads==3);CHECK(CGRectEqualToRect(c.dimmingView.frame,CGRectZero));CHECK(c.dimmingView.alpha==0&&c.dimmingView.backgroundColor.opacity==.5);
    CHECK(c.dimmingView.gestures.count==1);UITapGestureRecognizer*t=c.dimmingView.gestures[0];CHECK(t.target==c&&t.action==@selector(dismissController));((void(*)(id,SEL))objc_msgSend)(t.target,t.action);CHECK(p.dismissals==1);
    [events removeAllObjects];c.probeHeight=YES;c.calculatorReads=0;c.heightReads=0;CGRect r=[c frameOfPresentedViewInContainerView];
    CHECK(CGRectEqualToRect(r,CGRectMake(0,721,390,123)));CHECK(c.heightReads==1&&c.calculatorReads==2);CHECK(([events isEqual:@[@"height",@"calculator",@"calculator"]]));
    c.probeHeight=NO;c.heightCalculator=nil;c.customHeight=200;r=[c frameOfPresentedViewInContainerView];CHECK(CGRectEqualToRect(r,CGRectMake(0,644,390,200)));
    CGRect sentinel=CGRectMake(2,3,4,5);c.dimmingView.frame=sentinel;[c containerViewWillLayoutSubviews];CHECK(c.layouts==1&&CGRectEqualToRect(p.view.frame,r));CHECK(CGRectEqualToRect(c.dimmingView.frame,sentinel));
    [c presentationTransitionWillBegin];CHECK(c.dimmingView.superview==c.containerView);CHECK(CGRectEqualToRect(c.dimmingView.frame,c.containerView.bounds));CHECK(c.dimmingView.alpha==0);
    CHECK(p.view.layer.cornerRadius==15&&p.view.layer.radiusWrites==2&&p.view.layer.masksToBounds&&p.view.layer.maskedCorners==3);
    c.dimmingView.alpha=.4;[c dismissalTransitionWillBegin];CHECK(c.dimmingView.alpha==.4&&c.dimmingView.superview==c.containerView);
    Coordinator*k=[Coordinator new];p.transitionCoordinator=k;[c presentationTransitionWillBegin];CHECK(k.calls==1&&k.animation&&k.completion==nil);CHECK(c.dimmingView.alpha==.4);checkBlock(k.animation,"v16@?0@\"<UIViewControllerTransitionCoordinatorContext>\"8",YES,40);k.animation(k);CHECK(c.dimmingView.alpha==1);
    [c dismissalTransitionWillBegin];CHECK(k.calls==2&&k.animation&&k.completion);checkBlock(k.animation,"v16@?0@\"<UIViewControllerTransitionCoordinatorContext>\"8",YES,40);checkBlock(k.completion,"v16@?0@\"<UIViewControllerTransitionCoordinatorContext>\"8",YES,40);k.animation(k);CHECK(c.dimmingView.alpha==0);k.cancelled=YES;k.completion(k);CHECK(c.dimmingView.superview==nil&&c.dimmingView.alpha==0&&k.cancelledReads==0);
    [c.containerView addSubview:c.dimmingView];k.cancelled=NO;k.completion(k);CHECK(c.dimmingView.superview==nil&&k.cancelledReads==0);
    k.animation=nil;k.completion=nil;p.transitionCoordinator=nil;
    failPresentationInit=YES;NSUInteger frames=viewFrames;CHECK([[PseudoDetentController alloc]initWithPresentedViewController:p presentingViewController:nil]==nil);CHECK(viewFrames==frames);failPresentationInit=NO;
}
static void testCapture(void){
    for(NSUInteger mode=0;mode<3;mode++){
        Coordinator*k=[Coordinator new];__weak PseudoDetentController*weak;__weak UIView*shade;
        @autoreleasepool{UIViewController*p=[UIViewController new];p.transitionCoordinator=k;PseudoDetentController*c=[[PseudoDetentController alloc]initWithPresentedViewController:p presentingViewController:nil];weak=c;shade=c.dimmingView;[c.containerView addSubview:c.dimmingView];if(mode==0)[c presentationTransitionWillBegin];else{[c dismissalTransitionWillBegin];if(mode==1)k.completion=nil;else k.animation=nil;}}
        CHECK(weak!=nil&&shade!=nil);if(k.animation)k.animation(k);else if(k.completion)k.completion(k);k.animation=nil;k.completion=nil;
        @autoreleasepool{}CHECK(weak==nil&&shade==nil);
    }
}
static void testDelegate(void){
    [events removeAllObjects];DelegateProbe*d=[DelegateProbe new];UIViewController*p=[UIViewController new],*q=[UIViewController new];
    PseudoDetentController*c=(id)[d presentationControllerForPresentedViewController:p presentingViewController:q sourceViewController:[UIViewController new]];
    CHECK(c.presentedViewController==p&&c.presentingViewController==q);CHECK(c.customHeight==321);CHECK(c.heightCalculator&&c.heightCalculator(CGSizeMake(10,20))==11);CHECK(([events isEqual:@[@"height",@"calculator"]]));
    __weak id weak;@autoreleasepool{NSObject*o=[NSObject new];weak=o;d.heightCalculator=^CGFloat(CGSize s){return [o hash]+s.width;};}CHECK(weak!=nil);d.heightCalculator=nil;CHECK(weak==nil);
}
static double originalHeight(CGSize s,double custom,BOOL half){double alternate=half?s.height*.5:custom,result;__asm__ volatile("fcmp %d1,%d2\n\tfcsel %d0,%d2,%d3,gt":"=w"(result):"w"(s.width),"w"(s.height),"w"(alternate):"cc");return result;}
static void testPresenter(void){
    UIViewController*p=[UIViewController new],*c=[UIViewController new],*child=[UIViewController new];c.childViewControllers=@[child];child._sections=@[@[@1,@2],@[@3]];
    for(int native=0;native<2;native++)for(int kind=0;kind<3;kind++){
        nativeAvailable=native;nativeSelector=NO;nativeQueries=0;availabilityReads=0;NSUInteger before=presents;p.viewReads=0;sawDelegate=NO;c.presentationController=nil;c.sheetPresentationController=nil;
        @autoreleasepool{
            if(kind==0)[DVNSheetPresenter presentCustomHeightViewController:c fromViewController:p];else if(kind==1)[DVNSheetPresenter presentHalfScreenViewController:c fromViewController:p];else[DVNSheetPresenter presentViewController:c fromViewController:p withHeight:267];
        }
        double h=kind==0?275:kind==1?422:267;CHECK(presents==before+1&&availabilityReads==1&&nativeQueries==0);
        if(native){CHECK(c.modalPresentationStyle==1);CHECK(c.sheetPresentationController.detents.count==1);CHECK(c.sheetPresentationController.detents[0].height==h);CHECK([c.sheetPresentationController.detents[0].identifier isEqual:@"dvntm"]);CHECK(c.sheetPresentationController.prefersGrabberVisible&&c.sheetPresentationController.preferredCornerRadius==15);}
        else{CHECK(c.modalPresentationStyle==4&&sawDelegate);CHECK(c.transitioningDelegate==nil&&lastDelegate==nil);CHECK(CGSizeEqualToSize(c.preferredContentSize,CGSizeZero));CHECK(p.viewReads==0);CHECK(savedCalculator!=nil);checkBlock(savedCalculator,"d24@?0{CGSize=dd}8",NO,kind==1?32:40);
            const double widths[]={390,844,400,NAN,INFINITY,-INFINITY,0.0,-0.0};const double heights[]={844,390,400,NAN,INFINITY,-INFINITY,0.0,-0.0};
            if(savedCalculator)for(NSUInteger i=0;i<8;i++)for(NSUInteger j=0;j<8;j++){CGSize s=CGSizeMake(widths[i],heights[j]);CHECK(equalFP(savedCalculator(s),originalHeight(s,h,kind==1)));}
        }
    }
    nativeAvailable=YES;nativeSelector=YES;NSUInteger before=presents;[DVNSheetPresenter presentViewController:nil fromViewController:p withHeight:20];CHECK(presents==before+1);
    for(NSUInteger n=0;n<4;n++){NSMutableArray*sections=[NSMutableArray new];for(NSUInteger i=0;i<n;i++)[sections addObject:@[@1,@2]];child._sections=sections;[DVNSheetPresenter presentCustomHeightViewController:c fromViewController:p];CHECK(c.sheetPresentationController.detents[0].height==45+140*n);}
    savedCalculator=nil;c.presentationController=nil;c.sheetPresentationController=nil;
}
int main(void){@autoreleasepool{events=[NSMutableArray new];testController();testCapture();testDelegate();testPresenter();printf("Sheet lifecycle: %lu checks, %lu failures\n",(unsigned long)checks,(unsigned long)failures);return failures?1:0;}}
