#import "downloads_doubles.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>
#undef dispatch_queue_create
static NSUInteger checks,failures,allocations,superCalls,queueCalls;
static BOOL watching,nilQueue;
static unsigned parentMode;
static void *expectedSuperInput;
static id replacement;
static NSMutableArray *trace;
static IMP oldInit;
static void (^duringSuper)(id);
static uintptr_t ownerAddress,newQueueAddress;
static ptrdiff_t queueOffset,statsOffset,toastOffset,processingOffset;
static __weak id lastQueue;
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static void Event(NSString *s){if(watching)[trace addObject:s];}
static uintptr_t Raw(ptrdiff_t offset){uintptr_t value=0;memcpy(&value,(void *)(ownerAddress+offset),sizeof(value));return value;}
static BOOL Processing(void){unsigned char value;memcpy(&value,(void *)(ownerAddress+processingOffset),1);return value!=0;}
@interface FFLifeToken : NSObject
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) unsigned role;
@end
@implementation FFLifeToken
- (void)dealloc {
    Event(self.tag);
    if(ownerAddress&&watching){
        if(self.role==1)Check(Raw(toastOffset)==0&&Raw(statsOffset)!=0&&Raw(queueOffset)!=0,@"toast cleared before statistics and queue");
        if(self.role==2)Check(Raw(toastOffset)==0&&Raw(statsOffset)==0&&Raw(queueOffset)!=0,@"statistics cleared before queue");
        if(self.role==3)Check(Raw(toastOffset)==0&&Raw(statsOffset)==0&&Raw(queueOffset)==0,@"queue cleared last");
        if(self.role==4)Check(Raw(queueOffset)==newQueueAddress&&Processing(),@"new queue stored before old queue release and processing reset");
    }
}
@end
static FFLifeToken *Token(NSString *tag,unsigned role){FFLifeToken *t=[FFLifeToken new];t.tag=tag;t.role=role;return t;}
dispatch_queue_t FirstFFLifecycleQueue(const char *label,dispatch_queue_attr_t attributes){
    Event(@"queue");++queueCalls;Check(label&&strcmp(label,"com.dvntm.ffmpeg.serialqueue")==0,@"exact serial queue label");Check(attributes==NULL,@"nil serial queue attributes");
    FFLifeToken *t=nilQueue?nil:Token(@"queue.release",0);lastQueue=t;newQueueAddress=(uintptr_t)(__bridge void *)t;return (dispatch_queue_t)(id)t;
}
// An init IMP consumes its receiver and returns a retained result. Keep that
// ownership convention when substituting a nil or different superclass result.
typedef id (*InitFunction)(id __attribute__((ns_consumed)),SEL) __attribute__((ns_returns_retained));
static id ParentInit(id self __attribute__((ns_consumed)),SEL sel) __attribute__((ns_returns_retained));
static id ParentInit(id self __attribute__((ns_consumed)),SEL sel){
    if(!(watching&&(__bridge void *)self==expectedSuperInput))return ((InitFunction)oldInit)(self,sel);
    expectedSuperInput=NULL;++superCalls;Event(@"super");if(duringSuper)duringSuper(self);
    if(parentMode==1)return nil;
    if(parentMode==2)return replacement;
    return ((InitFunction)oldInit)(self,sel);
}
@implementation FFMpegHelper (FFLifeAllocation)
+ (instancetype)allocWithZone:(NSZone *)zone {id result=[super allocWithZone:zone];if(watching){++allocations;Event(@"alloc");expectedSuperInput=(__bridge void *)result;}return result;}
@end
@interface FFLifeSubclass : FFMpegHelper @end
@implementation FFLifeSubclass @end
static void Reset(void){watching=NO;ownerAddress=0;replacement=nil;duringSuper=nil;parentMode=0;nilQueue=NO;expectedSuperInput=NULL;newQueueAddress=0;lastQueue=nil;[trace removeAllObjects];}
static id Initialize(id object){expectedSuperInput=(__bridge void *)object;watching=YES;id result=[object init];watching=NO;return result;}
int main(int argc,const char **argv){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];
    queueOffset=ivar_getOffset(class_getInstanceVariable(FFMpegHelper.class,"_ffmpegQueue"));statsOffset=ivar_getOffset(class_getInstanceVariable(FFMpegHelper.class,"_statistics"));toastOffset=ivar_getOffset(class_getInstanceVariable(FFMpegHelper.class,"_toastView"));processingOffset=ivar_getOffset(class_getInstanceVariable(FFMpegHelper.class,"_isProcessing"));
    Check(queueOffset==8&&statsOffset==16&&toastOffset==24&&processingOffset==40,@"fixture has reviewed ivar offsets");
    Method init=class_getInstanceMethod(NSObject.class,@selector(init));oldInit=method_setImplementation(init,(IMP)ParentInit);
    if(argc>1){
        Reset();BOOL failed=!strcmp(argv[1],"nil-singleton");parentMode=failed?1:0;Class cls=!strcmp(argv[1],"subclass-singleton")?FFLifeSubclass.class:FFMpegHelper.class;
        watching=YES;FFMpegHelper *first=[cls sharedInstance];watching=NO;NSUInteger beforeAlloc=allocations,beforeSuper=superCalls,beforeQueue=queueCalls;
        Equal(trace,failed?(@[@"alloc",@"super"]):(@[@"alloc",@"super",@"queue"]),@"singleton initializes receiving class once");Check(failed?first==nil:object_getClass(first)==cls,@"singleton returns receiving-class instance or nil");
        parentMode=0;__weak id weakFirst=first;first=nil;Check(failed?weakFirst==nil:weakFirst!=nil,@"singleton owns initialized instance");
        for(NSUInteger i=0;i<32;++i)Check([FFMpegHelper sharedInstance]==weakFirst&&[FFLifeSubclass sharedInstance]==weakFirst,@"one singleton shared across receiving classes including nil result");
        Check(allocations==beforeAlloc&&beforeAlloc==1&&superCalls==beforeSuper&&beforeSuper==1&&queueCalls==beforeQueue&&beforeQueue==!failed,@"singleton never retries initialization");
    }else{
        // A superclass can return nil or a replacement. Exercise the actual
        // implementation's branches without changing its declared superclass.
        Reset();FFMpegHelper *fresh=[FFMpegHelper alloc];duringSuper=^(id o){[o setValue:@YES forKey:@"_isProcessing"];};FFMpegHelper *h=Initialize(fresh);Equal(trace,(@[@"super",@"queue"]),@"super initialization before queue creation");Check(h==fresh&&![[h valueForKey:@"_isProcessing"] boolValue],@"normal init returns self and clears processing");Check([h valueForKey:@"_ffmpegQueue"]==lastQueue&&lastQueue!=nil,@"queue factory result retained by helper");fresh=nil;h=nil;Check(lastQueue==nil,@"helper destruction releases created queue");
        Reset();parentMode=1;__weak id failedObject;@autoreleasepool{FFMpegHelper *o=[FFMpegHelper alloc];failedObject=o;id result=Initialize(o);Check(result==nil,@"nil superclass result returned");o=nil;}Equal(trace,(@[@"super"]),@"nil superclass skips queue construction");Check(failedObject==nil,@"failed initialization releases allocated receiver");
        Reset();FFMpegHelper *other=[FFMpegHelper alloc];[other setValue:@YES forKey:@"_isProcessing"];replacement=other;parentMode=2;__weak id original;@autoreleasepool{FFMpegHelper *o=[FFMpegHelper alloc];original=o;h=Initialize(o);o=nil;}Check(original==nil&&h==other,@"replacement superclass result becomes self");Check([h valueForKey:@"_ffmpegQueue"]==lastQueue&&![[h valueForKey:@"_isProcessing"] boolValue],@"queue and processing stored on replacement receiver");Equal(trace,(@[@"super",@"queue"]),@"replacement result follows normal queue path");replacement=nil;other=nil;h=nil;Check(lastQueue==nil,@"replacement helper owns queue until destruction");
        // Reinitialization replaces the queue and preserves unrelated fields.
        for(NSUInteger empty=0;empty<2;++empty){Reset();nilQueue=empty;h=[FFMpegHelper alloc];id stats=Token(@"unrelated.stats",0),toast=Token(@"unrelated.toast",0);[h setValue:stats forKey:@"_statistics"];[h setValue:toast forKey:@"_toastView"];[h setValue:@(LLONG_MIN+7) forKey:@"_duration"];[h setValue:@YES forKey:@"_isProcessing"];__weak id oldQueue;@autoreleasepool{id t=Token(@"old.queue",4);oldQueue=t;[h setValue:t forKey:@"_ffmpegQueue"];}ownerAddress=(uintptr_t)(__bridge void *)h;id result=Initialize(h);ownerAddress=0;Check(result==h&&oldQueue==nil,@"repeat initialization replaces and releases old queue");Check([h valueForKey:@"_statistics"]==stats&&[h valueForKey:@"_toastView"]==toast&&[[h valueForKey:@"_duration"] longLongValue]==LLONG_MIN+7,@"unrelated fields survive init");Check(![[h valueForKey:@"_isProcessing"] boolValue]&&[h valueForKey:@"_ffmpegQueue"]==lastQueue,@"nil and nonnil queue results stored before reset");Equal(trace,(@[@"super",@"queue",@"old.queue"]),@"old queue released after factory and assignment");result=nil;h=nil;Check(lastQueue==nil,@"replacement queue lifetime ends with helper");}
        // Read raw pointer slots during child destruction; do not retain or
        // message the owner once ARC has begun tearing it down.
        Reset();h=[FFMpegHelper alloc];__weak id weakToast,weakStats,weakQueue;@autoreleasepool{id t=Token(@"toast.release",1),s=Token(@"stats.release",2),q=Token(@"queue.release",3);weakToast=t;weakStats=s;weakQueue=q;[h setValue:t forKey:@"_toastView"];[h setValue:s forKey:@"_statistics"];[h setValue:q forKey:@"_ffmpegQueue"];}Check(weakToast&&weakStats&&weakQueue,@"three strong ivars retain their objects");ownerAddress=(uintptr_t)(__bridge void *)h;watching=YES;h=nil;watching=NO;ownerAddress=0;Equal(trace,(@[@"toast.release",@"stats.release",@"queue.release"]),@"destructor clears toast then statistics then queue");Check(!weakToast&&!weakStats&&!weakQueue,@"destructor releases all three owned objects");
    }
    method_setImplementation(init,oldInit);
    printf("%s First_ffmpeg_lifecycle: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
