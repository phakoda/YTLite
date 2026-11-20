#import "image_viewer_ui_doubles.h"
#import "../source/Presentation/DVNImageViewController.h"
#import "../source/Presentation/BlurButton.h"
#import <objc/runtime.h>
#import <math.h>
static NSUInteger checks,popoverReads,screenReads;
static NSArray *popovers,*screens;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static id Get(id o,const char *name){return object_getIvar(o,class_getInstanceVariable(DVNImageViewController.class,name));}
static void Set(id o,const char *name,id v){object_setIvarWithStrongDefault(o,class_getInstanceVariable(DVNImageViewController.class,name),v);}
static NSArray *Kinds(void){return [PresentationEvents valueForKey:@"kind"];}
static void Clear(void){PresentationResetEvents();}
static BOOL Same(double a,double b){return isnan(b)?isnan(a):a==b&&(b!=0||!!signbit(a)==!!signbit(b));}
id ImageViewerNextPopover(id fallback){if(!popovers)return fallback;id p=popovers[MIN(popoverReads++,popovers.count-1)];return p==NSNull.null?nil:p;}
CGRect ImageViewerNextScreenBounds(CGRect fallback){if(!screens)return fallback;return [screens[MIN(screenReads++,screens.count-1)]CGRectValue];}
void PlayerLifecycleSchedule(NSString *kind,UIView *view,double duration,double delay,UIViewAnimationOptions options,dispatch_block_t animations,void (^completion)(BOOL)){CHECK(NO);}
@interface PresentationTarget : NSObject
@property(nonatomic) SEL selector;
@end
@implementation BlurButton
+ (instancetype)createButtonWithImage:(UIImage *)image target:(id)target action:(SEL)action menu:(UIMenu *)menu {
 BlurButton *b=[self new];b.menu=menu;if(target)[b addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];PresentationRecord(@"blur.button",image.fixtureName?:@"");return b;
}
@end
@interface AuditViewer : DVNImageViewController
@property(nonatomic,strong) NSArray *images,*navs;
@property(nonatomic) NSUInteger imageReads,navReads,viewReads,haptics,shares;
@property(nonatomic) BOOL interceptShare;
@end
@implementation AuditViewer
- (UIImage *)fullImage {if(!self.images)return [super fullImage];PresentationRecord(@"fullImage",@1);id result=self.images[MIN(self.imageReads++,self.images.count-1)];return result==NSNull.null?nil:result;}
- (UINavigationController *)navigationController {if(!self.navs)return [super navigationController];return self.navs[MIN(self.navReads++,self.navs.count-1)];}
- (UIView *)view {self.viewReads++;return [super view];}
- (void)hapticFeedback {self.haptics++;PresentationRecord(@"haptic",@1);}
- (void)share {if(self.interceptShare){self.shares++;PresentationRecord(@"share",@1);}else [super share];}
@end
static AuditViewer *Viewer(void){AuditViewer *v=[AuditViewer new];v.view=[UIView new];return v;}
static NSArray *Actions(AuditViewer *v){return [(UIButton *)v.navigationItem.rightBarButtonItem.customView menu].children;}
static void Invoke(UIAction *a){a.fixtureHandler(a);}
static void TestMenu(void){
 UIImage *image=[UIImage new];AuditViewer *v=Viewer();v.images=@[image];v.interceptShare=YES;[v setupNavbar];NSArray *a=Actions(v);CHECK(a.count==3);CHECK([[a valueForKey:@"title"]isEqual:@[@"SaveToPhotos",@"Share",@"Copy"]]);
 Clear();Invoke(a[0]);CHECK(v.imageReads==1&&v.haptics==1);CHECK([Kinds()isEqual:@[@"haptic",@"fullImage",@"photos.UIImage"]]);CHECK(PresentationEvents.lastObject[@"value"]==image);
 v.images=@[NSNull.null];v.imageReads=0;Clear();Invoke(a[0]);CHECK(v.imageReads==1);CHECK([PresentationEventsOfKind(@"photos.UIImage") count]==1);CHECK(PresentationEvents.lastObject[@"value"]==NSNull.null);
 v.images=@[image];v.imageReads=0;Clear();Invoke(a[2]);CHECK(v.imageReads==1&&UIPasteboard.generalPasteboard.image==image);CHECK([Kinds()isEqual:@[@"haptic",@"fullImage"]]);v.images=@[NSNull.null];Invoke(a[2]);CHECK(UIPasteboard.generalPasteboard.image==nil);
 Clear();Invoke(a[1]);CHECK(v.shares==1&&[Kinds()isEqual:@[@"haptic",@"share"]]);
 v.navigationItem.rightBarButtonItem=nil;a=nil;Clear();
 for(NSUInteger index=0;index<3;index++){
  __weak AuditViewer *weak;void (^handler)(UIAction *);
  @autoreleasepool {AuditViewer *temporary=Viewer();temporary.images=@[image];temporary.interceptShare=YES;[temporary setupNavbar];handler=[Actions(temporary)[index]fixtureHandler];temporary.navigationItem.rightBarButtonItem=nil;weak=temporary;Clear();}
  CHECK(weak!=nil);handler(nil);CHECK(weak.haptics==1);Clear();handler=nil;CHECK(weak==nil);
 }
 // Own menu cycle is original behavior; removing the item is fixture teardown only.
 __weak AuditViewer *cycle;
 @autoreleasepool{AuditViewer *temporary=Viewer();[temporary setupNavbar];cycle=temporary;Clear();}
 CHECK(cycle!=nil);cycle.navigationItem.rightBarButtonItem=nil;Clear();CHECK(cycle==nil);
}
static void TestNavbar(void){
 AuditViewer *v=Viewer();UINavigationController *one=[UINavigationController new],*two=[UINavigationController new],*three=[UINavigationController new];v.navs=@[one,two,three];Clear();[v setupNavbar];CHECK(v.navReads==3);CHECK(one.navigationBar.translucent&&!two.navigationBar.translucent);CHECK(two.navigationBar.fixtureBackgroundImage!=nil&&one.navigationBar.fixtureBackgroundImage==nil);CHECK(three.navigationBar.shadowImage!=nil&&two.navigationBar.shadowImage==nil);
 NSArray *k=Kinds();NSUInteger left=[k indexOfObject:@"navbar.left"],right=[k indexOfObject:@"navbar.right"];CHECK(left>[[k indexesOfObjectsPassingTest:^BOOL(id o,NSUInteger idx,BOOL *stop){return [o isEqual:@"action.create"];} ]lastIndex]);CHECK(right>left);
 UIButton *close=(id)v.navigationItem.leftBarButtonItem.customView;PresentationTarget *target=close.fixtureTargets.firstObject;CHECK([NSStringFromSelector(target.selector)isEqual:@"closeButtonTapped:"]);CHECK(![v respondsToSelector:NSSelectorFromString(@"closeButtonTapped:")]);CHECK([v respondsToSelector:@selector(closeButtonTapped)]);BOOL rejected=NO;@try{[close sendActionsForControlEvents:UIControlEventTouchUpInside];}@catch(NSException *exception){rejected=[exception.name isEqual:NSInvalidArgumentException];}CHECK(rejected&&v.haptics==0);[v closeButtonTapped];CHECK(v.haptics==1&&v.fixtureDismissals==1);v.navigationItem.rightBarButtonItem=nil;Clear();
}
static void TestShare(void){
 AuditViewer *v=Viewer();UIImage *stored=[UIImage new],*getter=[UIImage new];v.fullImage=stored;v.images=@[getter];v.imageReads=0;popoverReads=screenReads=0;popovers=@[NSNull.null];screens=@[[NSValue valueWithCGRect:CGRectMake(0,0,100,200)]];v.viewReads=0;Clear();[v share];CHECK(v.imageReads==1);UIActivityViewController *activity=(id)v.presentedViewController;CHECK([activity.fixtureItems isEqual:@[getter]]);CHECK([activity.excludedActivityTypes isEqual:@[UIActivityTypeAssignToContact,UIActivityTypePrint]]);CHECK(popoverReads==1&&screenReads==0&&v.viewReads==0);CHECK([Kinds().firstObject isEqual:@"activity.alloc"]);CHECK([Kinds()[1]isEqual:@"fullImage"]);CHECK(v.fixturePresentations==1);
 UIPopoverPresentationController *probe=[UIPopoverPresentationController new],*source=[UIPopoverPresentationController new],*rect=[UIPopoverPresentationController new],*arrows=[UIPopoverPresentationController new];popovers=@[probe,source,rect,arrows];screens=@[[NSValue valueWithCGRect:CGRectMake(3,4,100,200)],[NSValue valueWithCGRect:CGRectMake(5,6,900,700)]];popoverReads=screenReads=0;v.viewReads=0;Clear();[v share];CHECK(popoverReads==4&&screenReads==2&&v.viewReads==1);CHECK(source.sourceView==v.view);CHECK(CGRectEqualToRect(rect.sourceRect,CGRectMake(50,700,0,0)));CHECK(arrows.permittedArrowDirections==15);CHECK(probe.sourceView==nil&&CGRectEqualToRect(probe.sourceRect,CGRectZero));
 v.images=@[NSNull.null];v.imageReads=0;popoverReads=screenReads=0;Clear();BOOL raised=NO;@try{[v share];}@catch(NSException *exception){raised=[exception.name isEqual:NSInvalidArgumentException];}CHECK(raised&&v.imageReads==1&&popoverReads==0);CHECK([Kinds()isEqual:@[@"activity.alloc",@"fullImage"]]);CHECK(v.fixturePresentations==2);popovers=screens=nil;Clear();
}
@interface ChangingImageView : UIImageView
@property(nonatomic,strong) NSArray *images;
@property(nonatomic) NSUInteger imageReads;
@end
@implementation ChangingImageView
- (UIImage *)image {id i=self.images[MIN(self.imageReads++,self.images.count-1)];return i==NSNull.null?nil:i;}
@end
@interface AxisViewer : AuditViewer
@property(nonatomic) BOOL horizontal;
@property(nonatomic) double fitted;
@property(nonatomic) NSUInteger adjustments;
@end
@implementation AxisViewer
- (void)adjustHorizontalInsetsWithImageWidth:(double)v {self.horizontal=YES;self.fitted=v;self.adjustments++;}
- (void)adjustVerticalInsetsWithImageHeight:(double)v {self.horizontal=NO;self.fitted=v;self.adjustments++;}
@end
@interface ChangingScroll : UIScrollView
@property(nonatomic) NSUInteger frameReads,maxReads,boundsReads;
@property(nonatomic,strong) NSArray *frames,*maxima;
@property(nonatomic,strong) NSMutableArray *reads;
@end
@implementation ChangingScroll
- (CGRect)frame {if(!self.frames)return [super frame];return [self.frames[MIN(self.frameReads++,self.frames.count-1)]CGRectValue];}
- (CGFloat)maximumZoomScale {if(!self.maxima)return [super maximumZoomScale];[self.reads addObject:@"maximum"];return [self.maxima[MIN(self.maxReads++,self.maxima.count-1)]doubleValue];}
- (CGRect)bounds {self.boundsReads++;[self.reads addObject:@"bounds"];return [super bounds];}
@end
static void TestGeometry(void){
 AxisViewer *v=[AxisViewer new];ChangingImageView *iv=[ChangingImageView new];UIImage *a=[UIImage new],*b=[UIImage new];a.size=CGSizeMake(400,999);b.size=CGSizeMake(999,200);iv.images=@[a,b];iv.frame=CGRectMake(0,0,300,500);Set(v,"_imageView",iv);[v adjustScrollViewInsets];CHECK(iv.imageReads==2&&!v.horizontal&&v.fitted==150&&v.adjustments==1);
 const CGSize sizes[]={{0,0},{0,10},{10,0},{-10,20},{20,-10},{NAN,10},{10,NAN},{200,400},{400,200},{300,500}};
 for(NSUInteger i=0;i<sizeof(sizes)/sizeof(*sizes);i++){a.size=sizes[i];iv.images=@[a];iv.imageReads=0;NSUInteger count=v.adjustments;[v adjustScrollViewInsets];double aspect=sizes[i].width/sizes[i].height,h=300/aspect,w=aspect*500;BOOL horizontal=!(h<=500);CHECK(iv.imageReads==2&&v.adjustments==count+1);CHECK(v.horizontal==horizontal&&Same(v.fitted,horizontal?w:h));}
 iv.images=@[NSNull.null];iv.imageReads=0;[v adjustScrollViewInsets];CHECK(iv.imageReads==2&&v.horizontal&&isnan(v.fitted));
 AuditViewer *ordinary=Viewer();ChangingScroll *scroll=[ChangingScroll new];scroll.contentSize=CGSizeMake(1000,1200);Set(ordinary,"_scrollView",scroll);scroll.frames=@[[NSValue valueWithCGRect:CGRectMake(0,0,300,400)],[NSValue valueWithCGRect:CGRectMake(0,0,500,600)]];
 [ordinary adjustHorizontalInsetsWithImageWidth:100];CHECK(scroll.frameReads==2&&scroll.contentInset.left==-250&&scroll.contentInset.right==-250);scroll.frameReads=0;[ordinary adjustVerticalInsetsWithImageHeight:100];CHECK(scroll.frameReads==2&&scroll.contentInset.top==-300&&scroll.contentInset.bottom==-300);
 scroll.frameReads=0;[ordinary adjustHorizontalInsetsWithImageWidth:300];CHECK(scroll.frameReads==1&&scroll.contentInset.left==-350);scroll.frameReads=0;[ordinary adjustVerticalInsetsWithImageHeight:NAN];CHECK(scroll.frameReads==1&&isnan(scroll.contentInset.top));
 scroll.frames=nil;scroll.frame=CGRectMake(0,0,300,600);scroll.reads=[NSMutableArray new];scroll.maxima=@[@3,@6,@9];scroll.zoomScale=1;UITapGestureRecognizer *tap=[UITapGestureRecognizer new];tap.fixtureLocation=CGPointMake(100,200);[ordinary handleDoubleTap:tap];CHECK(scroll.maxReads==2&&scroll.boundsReads==1);CHECK([scroll.reads isEqual:@[@"maximum",@"maximum",@"bounds"]]);CHECK(CGRectEqualToRect(scroll.fixtureZoomRect,CGRectMake(75,150,50,100)));CHECK(scroll.fixtureZoomAnimated);
 scroll.maxReads=scroll.boundsReads=0;[scroll.reads removeAllObjects];scroll.zoomScale=3;scroll.minimumZoomScale=.5;[ordinary handleDoubleTap:tap];CHECK(scroll.zoomScale==.5&&scroll.maxReads==1&&scroll.boundsReads==0);
 scroll.maxima=nil;scroll.contentSize=CGSizeMake(100,200);Set(v,"_scrollView",scroll);[v viewDidLayoutSubviews];CHECK(scroll.contentOffset.x==0&&scroll.contentOffset.y==0);scroll.contentSize=CGSizeMake(NAN,1000);[v viewDidLayoutSubviews];CHECK(isnan(scroll.contentOffset.x)&&scroll.contentOffset.y==200);CHECK(v.fixtureLayouts==2);scroll.bounds=CGRectZero;scroll.contentSize=CGSizeMake(-0.0,-0.0);[v viewDidLayoutSubviews];CHECK(signbit(scroll.contentOffset.x)&&signbit(scroll.contentOffset.y));
 NSUInteger count=v.adjustments;[v scrollViewDidZoom:scroll];[v scrollViewWillBeginZooming:scroll withView:iv];[v scrollViewDidEndZooming:scroll withView:iv atScale:2];CHECK(v.adjustments==count+3);CHECK([v viewForZoomingInScrollView:scroll]==iv);Clear();
}
static void TestSetup(void){
 AuditViewer *v=Viewer();UIImage *stored=[UIImage new],*getter=[UIImage new];v.fullImage=stored;v.images=@[getter];Clear();[v setupViewer];CHECK(v.imageReads==1);UIImageView *iv=Get(v,"_imageView");UIScrollView *sv=Get(v,"_scrollView");CHECK(iv.image==getter&&iv.contentMode==UIViewContentModeScaleAspectFit&&!iv.translatesAutoresizingMaskIntoConstraints);CHECK(sv.minimumZoomScale==1&&sv.maximumZoomScale==3&&sv.delegate==v&&sv.decelerationRate==.499);CHECK(!sv.showsHorizontalScrollIndicator&&!sv.showsVerticalScrollIndicator&&!sv.translatesAutoresizingMaskIntoConstraints);CHECK(PresentationEventsOfKind(@"scroll.new").count==0);
 NSArray *k=Kinds();CHECK([k indexOfObject:@"blur.create"]<[k indexOfObject:@"view.init"]);CHECK([k indexOfObject:@"zoom.maximum"]<[k indexOfObject:@"zoom.minimum"]);CHECK([k indexOfObject:@"image.translates"]<[k indexOfObject:@"image.mode"]);CHECK([k indexOfObject:@"image.mode"]<[k indexOfObject:@"fullImage"]);CHECK([k indexOfObject:@"fullImage"]<[k indexOfObject:@"image.set"]);NSArray *constraints=[PresentationEvents filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSDictionary *e,NSDictionary *bindings){return [e[@"kind"]hasPrefix:@"constraint."];}]];CHECK(constraints.count==16);for(NSUInteger i=0;i<16;i++)CHECK([constraints[i][@"kind"]isEqual:i%2?@"constraint.active":@"constraint.create"]);
 CHECK(sv.fixtureConstraints.count==4&&iv.fixtureConstraints.count==4);NSArray *expected=@[@"leading",@"trailing",@"top",@"bottom",@"width",@"height",@"centerX",@"centerY"];NSArray *active=PresentationEventsOfKind(@"constraint.active");for(NSUInteger i=0;i<8;i++){NSLayoutConstraint *c=active[i][@"value"][1];CHECK([c.firstAnchor.kind isEqual:expected[i]]&&[c.secondAnchor.kind isEqual:expected[i]]&&c.active&&c.constant==0);CHECK(c.firstAnchor.owner==(i<4?sv:iv)&&c.secondAnchor.owner==(i<4?v.view:sv));}
 CHECK(sv.gestureRecognizers.count==1&&[(UITapGestureRecognizer *)sv.gestureRecognizers[0]numberOfTapsRequired]==2);UIVisualEffectView *blur=(id)v.view.subviews.firstObject;CHECK(blur.effect.fixtureStyle==1&&blur.autoresizingMask==0x12&&CGRectEqualToRect(blur.frame,v.view.bounds));
 AuditViewer *nilImage=Viewer();nilImage.images=@[NSNull.null];[nilImage setupViewer];CHECK(nilImage.imageReads==1&&[(UIImageView *)Get(nilImage,"_imageView")image]==nil);[nilImage viewDidLoad];CHECK(nilImage.fixtureViewDidLoad==1);nilImage.navigationItem.rightBarButtonItem=nil;Clear();
}
static void TestBase(void){
 DVNImageViewController *v=[DVNImageViewController new];v.view=[UIView new];CHECK(v.fullImage==nil);__weak UIImage *weak;
 @autoreleasepool {UIImage *image=[UIImage new];weak=image;v.fullImage=image;CHECK(v.fullImage==image);}
 CHECK(weak!=nil);v.fullImage=nil;CHECK(weak==nil);Clear();[v hapticFeedback];CHECK([Kinds()isEqual:@[@"haptic.prepare",@"haptic.impact"]]);for(NSDictionary *e in PresentationEvents)CHECK([e[@"value"]integerValue]==1);
 Clear();[v closeButtonTapped];CHECK([Kinds()isEqual:@[@"haptic.prepare",@"haptic.impact",@"controller.dismiss"]]);CHECK(v.fixtureDismissals==1&&[PresentationEvents.lastObject[@"value"]boolValue]);
 __weak UIScrollView *ws;__weak UIImageView *wi;__weak UIImage *wf;
 @autoreleasepool {DVNImageViewController *temporary=[DVNImageViewController new];UIScrollView *scroll=[UIScrollView new];UIImageView *imageView=[UIImageView new];UIImage *full=[UIImage new];ws=scroll;wi=imageView;wf=full;Set(temporary,"_scrollView",scroll);Set(temporary,"_imageView",imageView);temporary.fullImage=full;Clear();}
 CHECK(ws==nil&&wi==nil&&wf==nil);Clear();
}
static void Unexpected(NSException *exception){fprintf(stderr,"UNEXPECTED %s: %s\n",exception.name.UTF8String,exception.reason.UTF8String);exit(1);}
int main(int argc,const char *argv[]){@autoreleasepool{NSSetUncaughtExceptionHandler(Unexpected);CHECK(argc==2);PresentationInitialize();NSString *mode=@(argv[1]);if([mode isEqual:@"menu"])TestMenu();else if([mode isEqual:@"navbar"])TestNavbar();else if([mode isEqual:@"share"])TestShare();else if([mode isEqual:@"geometry"])TestGeometry();else if([mode isEqual:@"setup"])TestSetup();else if([mode isEqual:@"base"])TestBase();else return 2;Clear();printf("IMAGE_VIEWER_UI_PASS %lu assertions mode=%s; actual whole source\n",(unsigned long)checks,argv[1]);}return 0;}
