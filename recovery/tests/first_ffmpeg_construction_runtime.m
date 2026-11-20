#import "downloads_doubles.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>
#undef dispatch_async
#undef NSClassFromString
static NSUInteger checks,failures,allocations,nilToast,managerReads,completions;
static BOOL watch,webpExists,nilManagers;
static int returnCode;
static long long expectedDuration;
static NSMutableArray *trace,*mainJobs,*serialJobs,*globalJobs,*weakToasts,*commands;
static NSString *phase;
static FFMpegHelper *helper;
static id video,audio,captions,output,jpeg,webp;
static id resultURL;
static NSError *resultError;
static NSString *lastLog;
static void Event(NSString *e){if(watch)[trace addObject:e];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
Class FirstFFClassLookup(NSString *name){if([name isEqual:@"ToastView"])Event(@"toast.lookup");return NSClassFromString(name);}
static id Box(id obj){return obj?:NSNull.null;}
@interface FFWeak : NSObject
@property(nonatomic,weak) id value;
@end
@implementation FFWeak @end
static FFWeak *Weak(id o){FFWeak *b=[FFWeak new];b.value=o;return b;}
void FirstFFAsync(dispatch_queue_t queue,dispatch_block_t block){NSString *name=queue==dispatch_get_main_queue()?@"main":queue==dispatch_get_global_queue(0,0)?@"global":@"serial";Check(queue!=NULL&&block!=nil,@"queue and callback provided");Event([@"enqueue:" stringByAppendingString:name]);[([name isEqual:@"main"]?mainJobs:[name isEqual:@"global"]?globalJobs:serialJobs) addObject:[block copy]];}
static void Run(NSString *name){NSMutableArray *jobs=[name isEqual:@"main"]?mainJobs:[name isEqual:@"global"]?globalJobs:serialJobs;Check(jobs.count>0,[@"queued " stringByAppendingString:name]);if(!jobs.count)return;void (^block)(void)=[jobs[0] copy];[jobs removeObjectAtIndex:0];phase=name;[trace removeAllObjects];watch=YES;block();watch=NO;DownloadsLastToast=nil;}
@interface FFURL : NSObject
@property(nonatomic,copy) NSString *name;
@property(nonatomic,strong) id directory;
@property(nonatomic,strong) NSDictionary *children;
@end
@implementation FFURL
- (id)URLByDeletingLastPathComponent{Event([self.name stringByAppendingString:@".directory"]);return self.directory;}
- (id)URLByAppendingPathComponent:(NSString *)component{Event([@"append:" stringByAppendingString:component]);return self.children[component];}
- (NSString *)path{Event([self.name stringByAppendingString:@".path"]);return self.name;}
- (NSString *)description{return self.name;}
@end
static FFURL *URL(NSString *n){FFURL *u=[FFURL new];u.name=n;return u;}
@interface FFManager : NSObject
@property(nonatomic) NSUInteger number;
@end
@implementation FFManager
- (BOOL)removeItemAtURL:(id)url error:(NSError **)error{Check(error==NULL,@"removal ignores NSError");Event([NSString stringWithFormat:@"remove%lu:%@",(unsigned long)self.number,url]);return NO;}
- (BOOL)fileExistsAtPath:(NSString *)path{Check(path==[webp name]||(!path&&!webp),@"thumbnail path forwarded");Event([NSString stringWithFormat:@"exists%lu",(unsigned long)self.number]);return webpExists;}
@end
static id Manager(id cls,SEL sel){(void)cls;(void)sel;Event(@"manager");++managerReads;if(nilManagers)return nil;FFManager *m=[FFManager new];m.number=managerReads;return m;}
static const void *toastKey=&toastKey;
static NSString *Tag(id self){return [NSString stringWithFormat:@"toast%@",objc_getAssociatedObject(self,toastKey)];}
@interface ToastView (FFDeclarations)
- (void)showToast:(NSString *)text;
- (void)hide;
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)withStop stopCompletion:(void (^)(void))completion;
@end
@interface FFToast : ToastView @end
@implementation FFToast
- (instancetype)init{Event([Tag(self) stringByAppendingString:@".init"]);if([objc_getAssociatedObject(self,toastKey) unsignedIntegerValue]==nilToast)return nil;self=[super init];[weakToasts addObject:Weak(self)];return self;}
- (void)showToast:(NSString *)text{Event([Tag(self) stringByAppendingString:@".waiting"]);Equal(phase,@"main",@"waiting toast main queue");Equal(text,@"WaitsForConversion",@"waiting label");[super showToast:text];}
- (void)hide{Event([Tag(self) stringByAppendingString:@".hide"]);Equal(phase,@"main",@"hide main queue");Check([[helper valueForKey:@"_isProcessing"] boolValue],@"hide happens before processing resets");[super hide];}
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)withStop stopCompletion:(void (^)(void))completion{Event([Tag(self) stringByAppendingString:@".progress"]);Equal(phase,@"main",@"progress main queue");Equal(text,@"Converting",@"converting label");Check(progress==0&&withStop&&completion!=nil,@"zero progress and stop enabled");[super showProgressWithText:text progress:progress withStop:withStop stopCompletion:completion];}
@end
@implementation ToastView (FFAllocation)
+ (instancetype)allocWithZone:(struct _NSZone *)zone{id o=[super allocWithZone:zone];object_setClass(o,FFToast.class);objc_setAssociatedObject(o,toastKey,@(++allocations),OBJC_ASSOCIATION_RETAIN_NONATOMIC);Event([Tag(o) stringByAppendingString:@".alloc"]);return o;}
+ (instancetype)new{Event(@"toast.new");return [super new];}
@end
@interface FFProbe : FFMpegHelper @end
@implementation FFProbe
- (void)setActive{Event(@"active");Equal(phase,@"main",@"activation main queue");}
- (NSString *)getCommandWithVideoURL:(NSURL *)v audioURL:(NSURL *)a captionsURL:(NSURL *)c thumbnailURL:(NSURL *)t duration:(long long)d outputURL:(NSURL *)o{Event(@"command");Equal(phase,@"serial",@"merge command prepared on serial queue");Check(v==video&&a==audio&&c==captions&&t==jpeg&&o==output&&d==expectedDuration,@"merge command captured arguments");return @"merge-command";}
- (void)getCleanLog:(NSString *)log{Event(@"clean");Equal(phase,@"main",@"error cleaning main queue");Check(log==lastLog,@"raw log passed unchanged");}
@end
static void ResetStatistics(id cls,SEL sel){(void)cls;(void)sel;Event(@"reset");Equal(phase,@"serial",@"reset on preparation queue");Check([[helper valueForKey:@"_isProcessing"] boolValue]&&[[helper valueForKey:@"_duration"] longLongValue]==expectedDuration&&[helper valueForKey:@"_statistics"]==nil,@"state is assigned before resetStatistics");}
static void LogDelegate(id cls,SEL sel,id delegate){(void)cls;(void)sel;Event(@"logDelegate");Check(delegate==helper,@"library log delegate helper identity");Equal(phase,@"serial",@"log delegate on preparation queue");}
static int Execute(id cls,SEL sel,NSString *command){(void)cls;(void)sel;Event(@"execute");[commands addObject:Box(command)];return returnCode;}
static void Cancel(id cls,SEL sel){(void)cls;(void)sel;Event(@"cancel");}
static NSString *Log(id cls,SEL sel){(void)cls;(void)sel;Event(@"lastLog");return lastLog;}
static IMP oldLocalization;
static id Localize(id self,SEL sel,id key,id value,id table){Event([@"label:" stringByAppendingString:key]);return ((id(*)(id,SEL,id,id,id))oldLocalization)(self,sel,key,value,table);}
static IMP Swap(Class cls,SEL sel,IMP imp,BOOL isClass){Method m=isClass?class_getClassMethod(cls,sel):class_getInstanceMethod(cls,sel);Check(m!=NULL,@"fixture selector exists");IMP old=method_getImplementation(m);Class target=isClass?object_getClass(cls):cls;if(class_addMethod(target,sel,imp,method_getTypeEncoding(m)))return old;return method_setImplementation(m,imp);}
static void Start(BOOL merge,BOOL busy){watch=NO;allocations=managerReads=completions=0;resultURL=nil;resultError=nil;[commands removeAllObjects];[weakToasts removeAllObjects];[trace removeAllObjects];[helper setValue:@(busy) forKey:@"_isProcessing"];[helper setValue:@(-55) forKey:@"_duration"];[helper setValue:[NSObject new] forKey:@"_statistics"];phase=@"caller";watch=YES;
 void (^completion)(NSURL *,NSError *)=^(NSURL *u,NSError *e){Event(@"completion");Equal(phase,@"main",@"completion main queue");Check(![[helper valueForKey:@"_isProcessing"] boolValue],@"processing reset before completion");++completions;resultURL=u;resultError=e;};
 if(merge)[helper mergeVideo:video withAudio:audio captions:captions duration:expectedDuration completion:completion];else [helper cutAudio:audio duration:expectedDuration completion:completion];watch=NO;DownloadsLastToast=nil;
}
static void Case(BOOL merge,BOOL busy,BOOL exists,int rc){helper=[FFProbe new];webpExists=exists;returnCode=rc;Start(merge,busy);
 NSMutableArray *initial=[NSMutableArray arrayWithArray:@[@"toast1.alloc",@"toast1.init"]];if(busy)[initial addObject:@"enqueue:main"];[initial addObject:@"enqueue:serial"];Equal(trace,initial,@"entry allocation and scheduling");Check([[helper valueForKey:@"_isProcessing"] boolValue]==busy&&[[helper valueForKey:@"_duration"] longLongValue]==-55,@"entry defers state mutations");
 if(busy){Run(@"main");if(nilToast!=1)Equal(trace,(@[@"label:WaitsForConversion",@"toast1.waiting"]),@"waiting label inside main callback");else Equal(trace,(@[@"label:WaitsForConversion"]),@"nil waiting receiver still localizes");}
 Check(nilToast==1||((FFWeak *)weakToasts.firstObject).value!=nil,@"waiting toast retained by queued preparation");Run(@"serial");
 NSMutableArray *prepared=[NSMutableArray arrayWithArray:@[@"reset",@"enqueue:main",merge?@"video.directory":@"audio.directory",merge?@"append:output.mp4":@"append:output.m4a"]];
 if(merge){[prepared addObjectsFromArray:@[@"append:thumbnail.webp",@"append:thumbnail.jpg",@"manager",@"remove1:jpeg",@"manager",@"remove2:output",@"manager",@"webp.path",@"exists3"]];if(exists)[prepared addObject:@"execute"];[prepared addObject:@"command"];}else [prepared addObjectsFromArray:@[@"manager",@"remove1:output"]];[prepared addObjectsFromArray:@[@"logDelegate",@"enqueue:global"]];if(!nilManagers)Equal(trace,prepared,@"preparation order and independent file manager receivers");
 Check(managerReads==(merge?3u:1u),@"fresh file-manager lookup per operation");Check(globalJobs.count==1&&mainJobs.count==1&&completions==0,@"execution and presentation separately deferred");
 if(merge&&exists&&!nilManagers)Equal(commands.firstObject,@"-hide_banner -loglevel error -i webp -q:v 1 jpeg",@"thumbnail conversion string and input order");
 Run(@"main");NSMutableArray *ui=[NSMutableArray arrayWithObject:@"active"];if(nilToast!=1)[ui addObject:@"toast1.hide"];[ui addObjectsFromArray:@[@"toast2.alloc",@"toast2.init",@"label:Converting"]];if(nilToast!=2)[ui addObject:@"toast2.progress"];Equal(trace,ui,@"activation hide allocation localization progress order");
 Check(nilToast==1||((FFWeak *)weakToasts.firstObject).value==nil,@"waiting toast released after presentation callback");
 ToastView *progress=[helper valueForKey:@"_toastView"];if(progress){watch=YES;[trace removeAllObjects];progress.stop();watch=NO;Equal(trace,(@[@"cancel"]),@"stop callback forwards only cancel");}
 Run(@"global");Equal(trace,(@[@"execute",@"enqueue:main"]),@"library executes in global callback before main completion queued");Equal(commands.lastObject,merge?@"merge-command":[NSString stringWithFormat:@"-hide_banner -loglevel error -i audio -to %lld -c copy output",expectedDuration],@"exact final command");Check(completions==0,@"completion still deferred");
 Run(@"main");NSMutableArray *terminal=[NSMutableArray array];if(nilToast!=2)[terminal addObject:@"toast2.hide"];if(rc!=0){if(rc!=255)[terminal addObjectsFromArray:@[@"lastLog",@"clean"]];[terminal addObject:rc==255?@"label:Cancelled":@"label:Error.Clipboard"];}[terminal addObject:@"completion"];Equal(trace,terminal,@"terminal callback hides before error work and completion");
 Check(completions==1,@"one completion per execution");if(rc==0){Check(resultURL==output&&resultError==nil,@"success forwards output identity");}else{Check(resultURL==nil&&resultError.code==0,@"failure returns nil URL and code zero");Equal(resultError.domain,@"ErrDomain",@"error domain");Equal(resultError.localizedDescription,rc==255?@"Cancelled":@"Error.Clipboard",@"error localized label");}
 Check(mainJobs.count==0&&serialJobs.count==0&&globalJobs.count==0,@"all queued work consumed");helper=nil;progress=nil;
}
int main(void){@autoreleasepool{
 DownloadsInstallDoubles();trace=[NSMutableArray new];mainJobs=[NSMutableArray new];serialJobs=[NSMutableArray new];globalJobs=[NSMutableArray new];weakToasts=[NSMutableArray new];commands=[NSMutableArray new];
 Swap(NSFileManager.class,@selector(defaultManager),(IMP)Manager,YES);Swap(MobileFFmpegConfig.class,@selector(resetStatistics),(IMP)ResetStatistics,YES);Swap(MobileFFmpegConfig.class,@selector(setLogDelegate:),(IMP)LogDelegate,YES);Swap(MobileFFmpegConfig.class,@selector(getLastCommandOutput),(IMP)Log,YES);Swap(MobileFFmpeg.class,@selector(execute:),(IMP)Execute,YES);Swap(MobileFFmpeg.class,@selector(cancel),(IMP)Cancel,YES);oldLocalization=Swap(object_getClass([NSBundle ytl_defaultBundle]),@selector(localizedStringForKey:value:table:),(IMP)Localize,NO);
 FFURL *v=URL(@"video"),*a=URL(@"audio"),*directory=URL(@"directory");video=v;audio=a;captions=URL(@"captions");output=URL(@"output");jpeg=URL(@"jpeg");webp=URL(@"webp");v.directory=a.directory=directory;directory.children=@{@"output.mp4":output,@"output.m4a":output,@"thumbnail.webp":webp,@"thumbnail.jpg":jpeg};expectedDuration=12;lastLog=@"conversion log";
 for(NSUInteger merge=0;merge<2;++merge)for(NSUInteger busy=0;busy<2;++busy)for(NSUInteger exists=0;exists<(merge?2u:1u);++exists)for(NSNumber *rc in @[@0,@255,@(-7),@(INT_MAX)])Case(merge,busy,exists,rc.intValue);
 for(NSUInteger merge=0;merge<2;++merge)for(NSUInteger n=1;n<=2;++n){nilToast=n;Case(merge,YES,YES,0);}nilToast=0;
 for(NSNumber *duration in @[@(LLONG_MIN),@(-1),@0,@(0x100000001LL),@(LLONG_MAX)]){expectedDuration=duration.longLongValue;Case(NO,NO,NO,0);Case(YES,NO,NO,0);}expectedDuration=12;
 nilManagers=YES;Case(YES,NO,YES,0);Case(NO,NO,NO,0);nilManagers=NO;
 printf("%s First_ffmpeg_construction: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
