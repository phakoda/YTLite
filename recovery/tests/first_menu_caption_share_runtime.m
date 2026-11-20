#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <math.h>
#undef dispatch_async
#undef NSClassFromString
#undef objc_getClass
static NSUInteger checks,failures,popReads;
static BOOL watching;
static NSMutableArray *trace;
static dispatch_block_t queued;
static NSArray *popSequence;
static id receivedController,receivedPresenter,topPresenter;
static UIActivityViewController *builtController;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
void FirstCaptionDispatch(dispatch_queue_t queue,dispatch_block_t block){Event(@"queue");Check(queue==dispatch_get_main_queue(),@"share uses main queue");Check(queued==nil,@"one queued share block");queued=[block copy];}
Class FirstCaptionStringLookup(NSString *name){if([name isEqual:@"YTUIUtils"])Event(@"class:UIUtils");return NSClassFromString(name);}
Class FirstCaptionClassLookup(const char *name){return objc_getClass(name);}
@interface ShareSource : UIView @end
@implementation ShareSource
- (CGRect)bounds{Event(@"bounds");return [super bounds];}
@end
@interface SharePopover : UIPopoverPresentationController
@property(nonatomic,copy) NSString *tag;
@end
@implementation SharePopover
- (void)setSourceView:(UIView *)source{Event([self.tag stringByAppendingString:@".source"]);[super setSourceView:source];}
- (void)setSourceRect:(CGRect)rect{Event([self.tag stringByAppendingString:@".rect"]);[super setSourceRect:rect];}
- (void)setPermittedArrowDirections:(UIPopoverArrowDirection)directions{Event([self.tag stringByAppendingString:@".arrows"]);[super setPermittedArrowDirections:directions];}
@end
@interface SharePresenter : UIViewController
@property(nonatomic,copy) NSString *tag;
@end
@implementation SharePresenter
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion{
    Event(self.tag);Check(animated&&!completion,@"animated share with nil completion");receivedController=controller;receivedPresenter=self;
}
@end
@interface YTUIUtils : NSObject
+ (UIViewController *)topViewControllerForPresenting;
+ (UIView *)sourceViewForActionSheetFromSourceView:(UIView *)source;
@end
static IMP originalInit,originalExcluded,originalPopover,originalTop,originalTransform;
static id Init(id self,SEL sel,NSArray *items,NSArray *activities){Event(@"activity.init");Check(activities==nil,@"nil application activities");id value=((id(*)(id,SEL,id,id))originalInit)(self,sel,items,activities);builtController=value;return value;}
static void Excluded(id self,SEL sel,NSArray *types){Event(@"excluded");Equal(types,(@[UIActivityTypeAssignToContact,UIActivityTypePrint]),@"excluded activity order");((void(*)(id,SEL,id))originalExcluded)(self,sel,types);}
static id Popover(id self,SEL sel){if(!watching||![self isKindOfClass:UIActivityViewController.class])return ((id(*)(id,SEL))originalPopover)(self,sel);Event(@"popover");NSUInteger i=popReads++;id p=popSequence[MIN(i,popSequence.count-1)];return p==NSNull.null?nil:p;}
static id Top(id cls,SEL sel){(void)cls;(void)sel;Event(@"top");return topPresenter;}
static id Transform(id cls,SEL sel,id source){(void)cls;(void)sel;Event(@"transform");return source;}
static void Begin(void){watching=NO;[trace removeAllObjects];queued=nil;popReads=0;receivedController=receivedPresenter=nil;builtController=nil;watching=YES;}
static BOOL Same(CGFloat a,CGFloat b){return a==b||(isnan(a)&&isnan(b));}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[[NSMutableArray alloc]init];DownloadMenuHelper *h=[DownloadMenuHelper new];
    SharePresenter *top=[SharePresenter new],*wrong=[SharePresenter new];top.tag=@"present.top";wrong.tag=@"present.toast";topPresenter=top;[ToastView toastWindow].rootViewController=wrong;
    originalInit=method_setImplementation(class_getInstanceMethod(UIActivityViewController.class,@selector(initWithActivityItems:applicationActivities:)),(IMP)Init);
    originalExcluded=method_setImplementation(class_getInstanceMethod(UIActivityViewController.class,@selector(setExcludedActivityTypes:)),(IMP)Excluded);
    originalPopover=method_setImplementation(class_getInstanceMethod(UIViewController.class,@selector(popoverPresentationController)),(IMP)Popover);
    originalTop=method_setImplementation(class_getClassMethod(YTUIUtils.class,@selector(topViewControllerForPresenting)),(IMP)Top);
    originalTransform=method_setImplementation(class_getClassMethod(YTUIUtils.class,@selector(sourceViewForActionSheetFromSourceView:)),(IMP)Transform);
    NSURL *url=[NSURL fileURLWithPath:@"/fixture/captions.srt"];ShareSource *source=[ShareSource new];
    CGFloat widths[]={0,5,41.25,-10,INFINITY,NAN};
    for(NSUInteger mask=0;mask<16;++mask)for(NSUInteger width=0;width<6;++width){
        NSMutableArray *pops=[[NSMutableArray alloc]init];for(NSUInteger i=0;i<4;++i){SharePopover *p=[SharePopover new];p.tag=[NSString stringWithFormat:@"p%lu",(unsigned long)i];[pops addObject:(mask&(1<<i))?p:NSNull.null];}popSequence=pops;
        source.bounds=CGRectMake(70,90,widths[width],300);Begin();[h shareSRT:url sourceView:source];Check(builtController==nil&&queued!=nil,@"activity construction deferred");Equal(trace,(@[@"queue"]),@"no UI work before queued callback");
        dispatch_block_t block=queued;queued=nil;block();block=nil;watching=NO;
        Equal(builtController.items,(@[url]),@"original URL is sole activity item");Check(builtController.items.firstObject==url,@"activity item identity");Equal(builtController.excludedActivityTypes,(@[UIActivityTypeAssignToContact,UIActivityTypePrint]),@"exclusions stored on activity");
        Check(receivedPresenter==top&&receivedController==builtController,@"present from current top controller");Check(popReads==((mask&1)?4:1),@"popover getters repeated for each operation");
        NSMutableArray *wanted=[[NSMutableArray alloc]initWithArray:@[@"queue",@"activity.init",@"excluded",@"class:UIUtils",@"top",@"popover"]];
        if(mask&1){[wanted addObject:@"popover"];if(mask&2){[wanted addObject:@"p1.source"];Check([(SharePopover *)pops[1] sourceView]==source,@"untransformed source assigned");}[wanted addObject:@"bounds"];[wanted addObject:@"popover"];if(mask&4){[wanted addObject:@"p2.rect"];CGRect rect=[(SharePopover *)pops[2] sourceRect];Check(Same(rect.origin.x,widths[width]-5)&&rect.origin.y==0&&rect.size.width==1&&rect.size.height==1,@"right-edge one-point source rect without clamping");}[wanted addObject:@"popover"];if(mask&8){[wanted addObject:@"p3.arrows"];Check([(SharePopover *)pops[3] permittedArrowDirections]==UIPopoverArrowDirectionUp,@"up arrow only");}}
        [wanted addObject:@"present.top"];Equal(trace,wanted,@"share getter and presentation order");
    }
    // Nil sources are forwarded; their nil bounds become the original x = -5 rect.
    SharePopover *p=[SharePopover new];p.tag=@"same";popSequence=@[p];Begin();[h shareSRT:url sourceView:nil];dispatch_block_t block=queued;queued=nil;block();block=nil;watching=NO;
    Check(p.sourceView==nil&&p.sourceRect.origin.x==-5,@"nil source still gets original source rect");
    // A nil URL is not silently dropped; literal construction fails inside the queue.
    Begin();[h shareSRT:nil sourceView:source];Check(queued!=nil,@"nil URL still queues");BOOL threw=NO;block=queued;queued=nil;@try{block();}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];}block=nil;watching=NO;Check(threw&&receivedController==nil,@"nil URL fails at deferred activity-array construction");
    // The queued block owns the source until it is released.
    __weak ShareSource *weakSource;@autoreleasepool{ShareSource *temporary=[ShareSource new];weakSource=temporary;Begin();[h shareSRT:url sourceView:temporary];watching=NO;}
    Check(weakSource!=nil,@"queue retains source");queued=nil;Check(weakSource==nil,@"queue releases source when discarded");
    method_setImplementation(class_getInstanceMethod(UIActivityViewController.class,@selector(initWithActivityItems:applicationActivities:)),originalInit);
    method_setImplementation(class_getInstanceMethod(UIActivityViewController.class,@selector(setExcludedActivityTypes:)),originalExcluded);
    method_setImplementation(class_getInstanceMethod(UIViewController.class,@selector(popoverPresentationController)),originalPopover);
    method_setImplementation(class_getClassMethod(YTUIUtils.class,@selector(topViewControllerForPresenting)),originalTop);
    method_setImplementation(class_getClassMethod(YTUIUtils.class,@selector(sourceViewForActionSheetFromSourceView:)),originalTransform);
    printf("%s First_menu_caption_share: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
