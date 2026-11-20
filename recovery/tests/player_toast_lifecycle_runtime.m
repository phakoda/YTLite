#import "player_toast_lifecycle_doubles.h"
#import "../source/Presentation/PlayerToast.h"
#import "../source/Presentation/CustomHUD.h"
#import <objc/runtime.h>
#import <math.h>
static NSUInteger checks;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static NSMutableArray<NSDictionary *> *scheduled;
static id Get(PlayerToast *toast,const char *name){return object_getIvar(toast,class_getInstanceVariable(PlayerToast.class,name));}
static void Set(PlayerToast *toast,const char *name,id value){object_setIvarWithStrongDefault(toast,class_getInstanceVariable(PlayerToast.class,name),value);}
static void Clear(void){[scheduled removeAllObjects];PresentationResetEvents();}
void PlayerLifecycleSchedule(NSString *kind,UIView *view,double duration,double delay,UIViewAnimationOptions options,dispatch_block_t animations,void (^completion)(BOOL)){
    NSMutableDictionary *item=[@{@"kind":kind,@"duration":@(duration),@"delay":@(delay),@"options":@(options)}mutableCopy];if(view)item[@"view"]=view;if(animations)item[@"animations"]=[animations copy];if(completion)item[@"completion"]=[completion copy];[scheduled addObject:item];
}
static void Animate(NSUInteger index){dispatch_block_t block=scheduled[index][@"animations"];if(block)block();}
static void Finish(NSUInteger index,BOOL finished){void (^block)(BOOL)=scheduled[index][@"completion"];if(block)block(finished);}
@interface CustomHUD ()
@property(nonatomic) NSUInteger fixtureAdds,fixtureRemoves;
@end
@implementation CustomHUD
- (instancetype)init{return [super init];}
- (void)addToController{self.fixtureAdds++;PresentationRecord(@"hud.add",@1);}
- (void)removeFromController{self.fixtureRemoves++;PresentationRecord(@"hud.remove",@1);}
- (MPVolumeController *)controller{return nil;}
- (NSString *)volumeAudioCategory{return @"fixture";}
@end
@interface LifecycleSourceToast : PlayerToast
@property(nonatomic,strong) NSArray *sources;
@property(nonatomic) NSUInteger sourceReads;
@property(nonatomic) BOOL landscape;
@end
@implementation LifecycleSourceToast
- (UIView *)sourceView{NSUInteger index=MIN(self.sourceReads++,self.sources.count-1);id result=self.sources[index];return result==NSNull.null?nil:result;}
- (BOOL)isLandscape{return self.landscape;}
@end
@interface LifecycleChangingBounds : UIView
@property(nonatomic) NSUInteger reads;
@property(nonatomic) CGRect firstBounds,secondBounds;
@end
@implementation LifecycleChangingBounds
- (CGRect)bounds{return self.reads++?self.secondBounds:self.firstBounds;}
@end
static LifecycleSourceToast *Toast(UIView *source){LifecycleSourceToast *t=[LifecycleSourceToast new];t.sources=@[source?:NSNull.null];return t;}
static void Show(PlayerToast *t){[t showPlayerToastWithText:@"Volume" value:50 style:2 isCompact:NO];}
static void TestInit(void){
    Clear();PlayerToast *toast=[PlayerToast new];CHECK(toast!=nil);CHECK([PresentationEvents.firstObject[@"kind"]isEqual:@"blur.create"]);CHECK([PresentationEvents.firstObject[@"value"]integerValue]==5);CHECK(toast.alpha==0&&!toast.userInteractionEnabled&&!toast.translatesAutoresizingMaskIntoConstraints);CHECK(Get(toast,"_containerView")==nil);CHECK([Get(toast,"_activeConstraints") count]==0);
}
static void TestHide(void){
    Clear();UIView *parent=[UIView new];LifecycleSourceToast *t=Toast(parent);Show(t);CHECK(scheduled.count==1);Animate(0);CHECK(t.alpha==1&&t.superview==parent);
    [t hideToast];CHECK(scheduled.count==2);NSDictionary *hide=scheduled[1];CHECK([hide[@"duration"]doubleValue]==.3&&[hide[@"delay"]doubleValue]==1&&[hide[@"options"]unsignedIntegerValue]==0x10000);
    Animate(1);CHECK(t.alpha==0);CustomHUD *hud=Get(t,"_volumeHUD");Finish(1,NO);CHECK(t.superview==parent&&hud.fixtureRemoves==0);
    // The original only tests finished; an older successful completion removes a newer presentation.
    Show(t);CHECK(t.superview==parent);Finish(1,YES);CHECK(t.superview==nil&&hud.fixtureRemoves==1);
    CHECK([PresentationEventsOfKind(@"hud.remove") count]==1);
    Clear();[parent addSubview:t];[t hideToast];CustomHUD *newHUD=[CustomHUD new];Set(t,"_volumeHUD",newHUD);Finish(0,YES);CHECK(newHUD.fixtureRemoves==1&&hud.fixtureRemoves==1);CHECK(!t.superview);
}
static void TestShow(void){
    Clear();UIView *first=[UIView new],*second=[UIView new],*third=[UIView new];LifecycleSourceToast *t=Toast(first);t.sources=@[first,second,third];t.bounds=CGRectMake(0,0,200,50);UIVisualEffectView *material=Get(t,"_toastView");CGRect originalFrame=material.frame;
    Show(t);CHECK(t.sourceReads==3);CHECK(t.superview==first);CHECK(first.fixtureLayouts==0&&second.fixtureLayouts==0&&third.fixtureLayouts==0);CHECK(CGRectEqualToRect(material.frame,originalFrame));
    NSArray *constraints=Get(t,"_activeConstraints");CHECK(constraints.count==20);NSLayoutConstraint *top=constraints[18],*center=constraints[19];CHECK(top.firstAnchor.owner==t&&top.secondAnchor.owner==second.safeAreaLayoutGuide);CHECK(top.constant==20&&[top.firstAnchor.kind isEqual:@"top"]);CHECK(center.firstAnchor.owner==t&&center.secondAnchor.owner==third&&center.constant==0);for(NSLayoutConstraint *c in constraints)CHECK(c.active);
    CHECK(scheduled.count==1&&[scheduled[0][@"duration"]doubleValue]==.3&&[scheduled[0][@"delay"]doubleValue]==0&&[scheduled[0][@"options"]unsignedIntegerValue]==0x20000&&!scheduled[0][@"completion"]);CHECK(t.alpha==0);Animate(0);CHECK(t.alpha==1);
    NSArray *old=constraints;Clear();t.sourceReads=0;t.landscape=YES;[t showPlayerToastWithText:@"Compact" value:50 style:2 isCompact:YES];CHECK(t.sourceReads==3);constraints=Get(t,"_activeConstraints");CHECK(((NSLayoutConstraint *)constraints[18]).constant==5);for(NSLayoutConstraint *c in old)CHECK(!c.active);CHECK([Get(t,"_toastLabel") text]==nil);CHECK(((UIVisualEffectView *)Get(t,"_toastView")).layer.cornerRadius==15);
    // A permissive constraint double exposes continuation after a missing source; UIKit may raise for a nil anchor.
    Clear();LifecycleSourceToast *missing=Toast(nil);Show(missing);CHECK(missing.sourceReads==3);CHECK(scheduled.count==1);CHECK([Get(missing,"_activeConstraints") count]==20);CHECK(missing.superview==nil);
}
static void TestSource(void){
    Clear();PlayerToast *t=[PlayerToast new];UIWindow *sceneWindow=[UIWindow new];sceneWindow.fixtureKeyWindow=YES;UIWindowScene *scene=[UIWindowScene new];scene.windows=@[sceneWindow];scene.activationState=UISceneActivationStateForegroundActive;UIApplication.sharedApplication.connectedScenes=[NSSet setWithObject:scene];PresentationAppDelegate *delegate=[PresentationAppDelegate new];UIApplication.sharedApplication.delegate=delegate;
    CHECK(t.sourceView==nil);UIWindow *delegateWindow=[UIWindow new];delegateWindow.fixtureKeyWindow=NO;delegate.window=delegateWindow;CHECK(t.sourceView==delegateWindow);UIApplication.sharedApplication.delegate=nil;CHECK(t.sourceView==nil);
}
static double NativeClampedWidth(double value,double width){double result;__asm__ volatile("fmov d16, #1.0\n\tfcmp %d1, d16\n\tfcsel d16, d16, %d1, gt\n\tfmov d17, xzr\n\tfmaxnm d16, d16, d17\n\tfmul %d0, d16, %d2":"=w"(result):"w"(value),"w"(width):"v16","v17","cc");return result;}
static BOOL Same(double a,double b){return isnan(b)?isnan(a):a==b&&(b!=0||!!signbit(a)==!!signbit(b));}
static void TestProgress(void){
    Clear();PlayerToast *t=[PlayerToast new];UIView *progress=Get(t,"_toastProgress");CALayer *layer=Get(t,"_progressLayer");
    const double values[]={-INFINITY,-1,-0.0,0,.25,1,2,INFINITY,NAN};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(*values);i++){progress.bounds=CGRectMake(0,0,100,4);[t setProgress:values[i]];CHECK(Same(layer.frame.size.width,NativeClampedWidth(values[i],100)));CHECK(layer.frame.size.height==4&&layer.frame.origin.x==0&&layer.frame.origin.y==0);}
    LifecycleChangingBounds *changing=[LifecycleChangingBounds new];changing.firstBounds=CGRectMake(1,2,100,4);changing.secondBounds=CGRectMake(9,8,999,7);Set(t,"_toastProgress",changing);[t setProgress:.5];CHECK(changing.reads==2&&layer.frame.size.width==50&&layer.frame.size.height==7);
    for(NSNumber *width in @[@0,@(-1),@(NAN),@(INFINITY)]){changing.reads=0;changing.firstBounds=CGRectMake(0,0,width.doubleValue,4);changing.secondBounds=CGRectMake(0,0,900,9);CGRect before=layer.frame;[t setProgress:.5];if(width.doubleValue<=0){CHECK(changing.reads==1&&CGRectEqualToRect(layer.frame,before));}else{CHECK(changing.reads==2&&Same(layer.frame.size.width,NativeClampedWidth(.5,width.doubleValue))&&layer.frame.size.height==9);}}
}
@interface LifecycleImageToast : PlayerToast
@property(nonatomic,weak) UIImage *nextImage;
@end
@implementation LifecycleImageToast
- (UIImage *)imgForVal:(double)value{return self.nextImage;}
@end
static void TestUpdateAndCaptures(void){
    Clear();PlayerToast *t=[PlayerToast new];UIImageView *imageView=Get(t,"_toastImage");UIImage *old=[UIImage systemImageNamed:@"old"];imageView.image=old;[t setValue:@2 forKey:@"_style"];PresentationResetEvents();[t updateToastText:@"new" value:.125];NSArray *writes=PresentationEventsOfKind(@"image.set");CHECK(writes.count==1&&writes[0][@"value"]==old);CHECK([[Get(t,"_toastSubLabel") text]isEqual:@"13%"]);CHECK(scheduled.count==1&&[scheduled[0][@"kind"]isEqual:@"transition"]&&[scheduled[0][@"duration"]doubleValue]==.5&&[scheduled[0][@"options"]unsignedIntegerValue]==0x500000);CHECK(imageView.image==old);UIImageView *replacement=[UIImageView new];Set(t,"_toastImage",replacement);Animate(0);CHECK([replacement.image.fixtureName isEqual:@"vol.low"]&&imageView.image==old);
    Clear();__weak PlayerToast *weak;__strong dispatch_block_t animation;__strong void (^completion)(BOOL);
    @autoreleasepool{PlayerToast *temporary=[PlayerToast new];weak=temporary;[temporary hideToast];animation=scheduled[0][@"animations"];completion=scheduled[0][@"completion"];Clear();}
    CHECK(weak!=nil);animation=nil;CHECK(weak!=nil);completion(NO);completion=nil;CHECK(weak==nil);
    @autoreleasepool{LifecycleSourceToast *temporary=Toast(nil);weak=temporary;Show(temporary);animation=scheduled[0][@"animations"];Clear();}
    CHECK(weak!=nil);animation();animation=nil;CHECK(weak==nil);
    @autoreleasepool{PlayerToast *temporary=[PlayerToast new];weak=temporary;[temporary setValue:@2 forKey:@"_style"];[temporary updateToastText:@"value" value:.5];animation=scheduled[0][@"animations"];Clear();}
    CHECK(weak!=nil);animation();animation=nil;CHECK(weak==nil);
    @autoreleasepool{PlayerToast *temporary=[PlayerToast new];weak=temporary;[temporary hideToast];animation=scheduled[0][@"animations"];Clear();}
    CHECK(weak!=nil);animation=nil;CHECK(weak==nil);
    __weak UIImage *weakImage;
    @autoreleasepool{LifecycleImageToast *temporary=[LifecycleImageToast new];UIImage *fresh=[UIImage new];weakImage=fresh;temporary.nextImage=fresh;[temporary updateToastText:@"capture" value:.5];animation=scheduled[0][@"animations"];Clear();}
    CHECK(weakImage!=nil);animation=nil;CHECK(weakImage==nil);
    // Preserve the independently recovered float NSNumber boxing.
    CHECK([[t subLabelForVal:1.234567890123 style:1]isEqual:[NSString stringWithFormat:@"%@×",@((float)1.234567890123)]]);
}
int main(int argc,const char *argv[]){@autoreleasepool{CHECK(argc==2);PresentationInitialize();scheduled=[NSMutableArray new];NSString *mode=@(argv[1]);
    if([mode isEqual:@"init"])TestInit();else if([mode isEqual:@"hide"])TestHide();else if([mode isEqual:@"show"])TestShow();else if([mode isEqual:@"source"])TestSource();else if([mode isEqual:@"progress"])TestProgress();else if([mode isEqual:@"update"])TestUpdateAndCaptures();else return 2;
    Clear();printf("PLAYER_TOAST_LIFECYCLE_PASS %lu assertions mode=%s; actual whole PlayerToast.m\n",(unsigned long)checks,argv[1]);
}return 0;}
