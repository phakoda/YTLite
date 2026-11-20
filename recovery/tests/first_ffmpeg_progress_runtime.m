#import "downloads_doubles.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>
#import <math.h>
#import <stdint.h>
#undef dispatch_async
static NSUInteger checks,failures;
static BOOL watch,bundleNil,labelNil;
static NSMutableArray *trace,*jobs;
static void (^onBundle)(void),(^onLabel)(void);
static __weak FFMpegHelper *expectedHelper;
static __weak id expectedStatistics;
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
void FirstFFProgressAsync(dispatch_queue_t queue,dispatch_block_t block){Check(queue==dispatch_get_main_queue()&&block!=nil,@"statistics callback dispatched to main");Event(@"enqueue");[jobs addObject:[block copy]];}
static void Drain(void){Check(jobs.count>0,@"pending statistics callback");if(!jobs.count)return;void (^block)(void)=[jobs[0] copy];[jobs removeObjectAtIndex:0];watch=YES;[trace removeAllObjects];block();watch=NO;}
@interface FFProgressStats : NSObject
@property(nonatomic) int time;
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,copy) void (^onRead)(void);
@end
@implementation FFProgressStats
- (int)getTime{Event([self.tag stringByAppendingString:@".time"]);int value=self.time;if(self.onRead)self.onRead();return value;}
@end
@interface FFProgressToast : ToastView
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) NSUInteger updates;
@end
@implementation FFProgressToast
- (void)updateText:(NSString *)text progress:(float)progress{Event([self.tag stringByAppendingString:@".update"]);self.text=text;self.progress=progress;++self.updates;}
@end
@interface FFProgressProbe : FFMpegHelper @end
@implementation FFProgressProbe
- (void)updateProgressDialog{Event(@"update");Check(self==expectedHelper&&[self valueForKey:@"_statistics"]==expectedStatistics,@"captured statistics stored before update dispatch");[super updateProgressDialog];}
@end
static IMP oldBundle,oldLocalization;
static id Bundle(id cls,SEL sel){Event(@"bundle");if(onBundle)onBundle();return bundleNil?nil:((id(*)(id,SEL))oldBundle)(cls,sel);}
static id Localize(id self,SEL sel,id key,id value,id table){Event(@"label");Equal(key,@"Converting",@"exact progress localization key");Check(value==nil&&table==nil,@"nil localization fallback and table");if(onLabel)onLabel();return labelNil?nil:((id(*)(id,SEL,id,id,id))oldLocalization)(self,sel,key,value,table);}
static void LogDelegate(id cls,SEL sel,id delegate){(void)cls;(void)sel;Event(@"log.delegate");Check(delegate==expectedHelper,@"activation log delegate identity");}
static void StatsDelegate(id cls,SEL sel,id delegate){(void)cls;(void)sel;Event(@"stats.delegate");Check(delegate==expectedHelper,@"activation statistics delegate identity");}
static IMP Swap(Class cls,SEL sel,IMP imp,BOOL isClass){Method method=isClass?class_getClassMethod(cls,sel):class_getInstanceMethod(cls,sel);Check(method!=NULL,@"fixture selector exists");IMP old=method_getImplementation(method);Class target=isClass?object_getClass(cls):cls;if(class_addMethod(target,sel,imp,method_getTypeEncoding(method)))return old;return method_setImplementation(method,imp);}
// Independent hardware oracle for the observed FCVTZS Wd, Dn instruction.
// This emits a fresh arithmetic instruction; it never loads original code.
static int OriginalPercent(double value){int result;__asm__("fcvtzs %w0, %d1" : "=r"(result) : "w"(value));return result;}
static double OriginalRatio(int time,long long duration){volatile double seconds=(double)time/1000.0;return seconds/(double)duration;}
static uint32_t Bits(float value){uint32_t bits;memcpy(&bits,&value,sizeof(bits));return bits;}
static void CheckProgress(FFProgressToast *toast,int time,long long duration,NSString *label){double p=OriginalRatio(time,duration);Equal(toast.text,[NSString stringWithFormat:@"%@: %d%%",label,OriginalPercent(p*100.0)],@"percentage matches first-package arithmetic");Check(Bits(toast.progress)==Bits((float)p),@"progress float preserves exact narrowed bits");}
static void Set(FFMpegHelper *h,id stats,long long duration,id toast){[h setValue:stats forKey:@"_statistics"];[h setValue:@(duration) forKey:@"_duration"];[h setValue:toast forKey:@"_toastView"];}
static void Update(FFMpegHelper *h){[trace removeAllObjects];watch=YES;[h updateProgressDialog];watch=NO;}
int main(void){@autoreleasepool{
 DownloadsInstallDoubles();trace=[NSMutableArray new];jobs=[NSMutableArray new];
 oldBundle=Swap(NSBundle.class,@selector(ytl_defaultBundle),(IMP)Bundle,YES);oldLocalization=Swap(object_getClass([NSBundle ytl_defaultBundle]),@selector(localizedStringForKey:value:table:),(IMP)Localize,NO);Swap(MobileFFmpegConfig.class,@selector(setLogDelegate:),(IMP)LogDelegate,YES);Swap(MobileFFmpegConfig.class,@selector(setStatisticsDelegate:),(IMP)StatsDelegate,YES);
 FFMpegHelper *h=[FFMpegHelper new];FFProgressStats *s=[FFProgressStats new];s.tag=@"s";FFProgressToast *first=[FFProgressToast new],*second=[FFProgressToast new];first.tag=@"first";second.tag=@"second";DownloadsLastToast=nil;
 Set(h,nil,1,first);Update(h);Check(trace.count==0&&first.updates==0,@"nil statistics exits without getters or localization");
 // Reentrant bundle/localization changes must not replace the already-read receiver.
 __weak FFMpegHelper *weakH=h;
 for(NSUInteger stage=0;stage<2;++stage)for(NSUInteger nilFirst=0;nilFirst<2;++nilFirst){s.time=1750;Set(h,s,2,nilFirst?nil:first);NSUInteger a=first.updates,b=second.updates;void (^change)(void)=^{[weakH setValue:second forKey:@"_toastView"];[weakH setValue:@999 forKey:@"_duration"];};if(stage)onLabel=change;else onBundle=change;Update(h);onBundle=onLabel=nil;
 Equal(trace,nilFirst?(@[@"s.time",@"bundle",@"label"]):(@[@"s.time",@"bundle",@"label",@"first.update"]),@"toast selected before bundle/localization");Check(first.updates==a+!nilFirst&&second.updates==b,@"captured receiver identity including nil");if(!nilFirst)CheckProgress(first,1750,2,@"Converting");}
 // Exact signed widths and double/float conversions across boundaries.
 int times[]={INT_MIN,-1,0,1,9,10,333,999,1000,1001,1000003,INT_MAX};
 long long durations[]={LLONG_MIN,-9007199254740993LL,-0x100000001LL,-1000,-3,-1,0,1,3,1000,0x100000001LL,9007199254740993LL,LLONG_MAX};
 for(NSUInteger i=0;i<sizeof(times)/sizeof(*times);++i)for(NSUInteger j=0;j<sizeof(durations)/sizeof(*durations);++j){s.time=times[i];Set(h,s,durations[j],first);NSUInteger before=first.updates;Update(h);if(times[i]<=0){Equal(trace,(@[@"s.time"]),@"nonpositive signed time skips update");Check(first.updates==before,@"nonpositive time preserves toast");}else{Equal(trace,(@[@"s.time",@"bundle",@"label",@"first.update"]),@"positive time evaluated once before update");CheckProgress(first,times[i],durations[j],@"Converting");}}
 uint64_t seed=0x192f8b45;for(NSUInteger i=0;i<512;++i){seed=seed*6364136223846793005ULL+1;int time=(int)((seed>>33)%INT_MAX)+1;seed=seed*6364136223846793005ULL+1;long long duration=(long long)(seed%2000001)-1000000;s.time=time;Set(h,s,duration,first);Update(h);CheckProgress(first,time,duration,@"Converting");}
 // getTime can change duration and current toast before either is read.
 s.time=2000;Set(h,s,5,first);s.onRead=^{Set(weakH,nil,4,second);};Update(h);s.onRead=nil;Equal(trace,(@[@"s.time",@"bundle",@"label",@"second.update"]),@"duration and receiver loaded after getTime");CheckProgress(second,2000,4,@"Converting");
 for(NSUInteger nilBundle=0;nilBundle<2;++nilBundle){bundleNil=nilBundle;labelNil=!nilBundle;s.time=1000;Set(h,s,0,first);Update(h);Equal(trace,nilBundle?(@[@"s.time",@"bundle",@"first.update"]):(@[@"s.time",@"bundle",@"label",@"first.update"]),@"nil localization result forwarded");CheckProgress(first,1000,0,nil);}bundleNil=labelNil=NO;
 // Two queued snapshots remain distinct; their values are read when executed.
 FFProgressProbe *probe=[FFProgressProbe new];FFProgressStats *a=[FFProgressStats new],*b=[FFProgressStats new];a.tag=@"a";b.tag=@"b";a.time=100;b.time=200;Set(probe,s,1,first);expectedHelper=probe;expectedStatistics=a;watch=YES;[trace removeAllObjects];[probe statisticsCallback:(id)a];[probe statisticsCallback:(id)b];watch=NO;Equal(trace,(@[@"enqueue",@"enqueue"]),@"statistics callbacks only enqueue work");Check([probe valueForKey:@"_statistics"]==s,@"queued callbacks do not mutate statistics early");a.time=1000;b.time=2000;[probe setValue:@2 forKey:@"_duration"];[probe setValue:second forKey:@"_toastView"];Drain();Equal(trace,(@[@"update",@"a.time",@"bundle",@"label",@"second.update"]),@"first queued capture updates live state");CheckProgress(second,1000,2,@"Converting");expectedStatistics=b;Drain();CheckProgress(second,2000,2,@"Converting");
 expectedStatistics=nil;watch=YES;[probe statisticsCallback:nil];watch=NO;Check([probe valueForKey:@"_statistics"]==b,@"queued nil does not clear early");Drain();Equal(trace,(@[@"update"]),@"nil callback clears before update");Check([probe valueForKey:@"_statistics"]==nil,@"nil statistics replaces prior object");
 __weak FFProgressProbe *retainedHelper;__weak FFProgressStats *retainedStats;
 @autoreleasepool{FFProgressProbe *owned=[FFProgressProbe new];FFProgressStats *ownedStats=[FFProgressStats new];ownedStats.tag=@"owned";ownedStats.time=1000;Set(owned,nil,1,first);expectedHelper=owned;expectedStatistics=ownedStats;retainedHelper=owned;retainedStats=ownedStats;[owned statisticsCallback:(id)ownedStats];owned=nil;ownedStats=nil;Check(retainedHelper!=nil&&retainedStats!=nil,@"queue retains helper and statistics");Drain();}Check(retainedHelper==nil&&retainedStats==nil,@"queue release permits helper and statistics destruction");
 // Activation and the intentionally empty logging callback run synchronously.
 expectedHelper=h;watch=YES;[trace removeAllObjects];[h setActive];watch=NO;Equal(trace,(@[@"log.delegate",@"stats.delegate"]),@"activation delegates installed in original order");
 Set(h,s,42,first);for(NSNumber *execution in @[@(LLONG_MIN),@0,@(LLONG_MAX)])for(NSNumber *level in @[@(INT_MIN),@0,@(INT_MAX)])for(id text in @[@"log",NSNull.null]){watch=YES;[trace removeAllObjects];[h logCallback:execution.longLongValue :level.intValue :text==NSNull.null?nil:text];watch=NO;Check(trace.count==0&&jobs.count==0,@"logging callback has no application operations");Check([h valueForKey:@"_statistics"]==s&&[h valueForKey:@"_toastView"]==first&&[[h valueForKey:@"_duration"] longLongValue]==42,@"logging callback leaves state unchanged");}
 printf("%s First_ffmpeg_progress: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
