#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,lookupCalls,formatterCalls,callbacks,deallocations;
static BOOL watching,lookupNil,allocNil,initNil,expectedAlive;
static long long freeBytes;
static __weak id currentController;
static NSMutableArray *trace,*formatted;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
@interface StorageProbe : NSObject @end
@implementation StorageProbe
+ (instancetype)new{Event(@"new");return [super new];}
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"alloc");return allocNil?nil:[super allocWithZone:zone];}
- (instancetype)init{Event(@"init");self=[super init];if(initNil)self=nil;currentController=self;return self;}
- (long long)freeDeviceStorageBytes{Event(@"free");return freeBytes;}
- (void)dealloc{++deallocations;Event(@"dealloc");}
@end
Class FirstStorageClassLookup(const char *name){
    if(strcmp(name,"YTAutoOfflineController"))return objc_getClass(name);
    ++lookupCalls;Event(@"lookup");return lookupNil?Nil:StorageProbe.class;
}
Class FirstStorageStringLookup(NSString *name){
    if(![name isEqual:@"YTAutoOfflineController"])return NSClassFromString(name);
    ++lookupCalls;Event(@"stringLookup");return lookupNil?Nil:StorageProbe.class;
}
static IMP originalFormatter,originalBundle;
static id FormatBytes(id cls,SEL selector,long long bytes,NSByteCountFormatterCountStyle style){
    (void)cls;(void)selector;++formatterCalls;Event(@"format");[formatted addObject:@(bytes)];
    Check(style==NSByteCountFormatterCountStyleFile,@"file byte-count style");
    Check((currentController!=nil)==expectedAlive,@"controller lifetime during formatting");
    freeBytes=LLONG_MIN;return [NSString stringWithFormat:@"B%lld",bytes];
}
static id Bundle(id cls,SEL selector){Event(@"bundle");return ((id(*)(id,SEL))originalBundle)(cls,selector);}
static void Run(DownloadMenuHelper *h,long long size,long long available,BOOL missingClass,NSUInteger expectedLookups){
    watching=NO;[trace removeAllObjects];[formatted removeAllObjects];callbacks=formatterCalls=deallocations=0;freeBytes=available;currentController=nil;
    expectedAlive=!missingClass&&!allocNil&&!initNil;watching=YES;
    long long observedFree=expectedAlive?available:0;
    long long twice=(long long)((unsigned long long)size<<1),needed=(long long)((unsigned long long)twice-(unsigned long long)observedFree);
    BOOL wanted=twice<observedFree;
    [h checkSpaceAvailabilityForMedia:size completion:^(BOOL enough,NSString *message){
        ++callbacks;Event(@"callback");Check(enough==wanted,@"signed comparison after wrapping size doubling");
        Check((currentController!=nil)==expectedAlive,@"controller alive through completion");
        if(enough)Check(message==nil,@"enough space passes nil message");
        else Equal(message,[NSString stringWithFormat:@"Need B%lld; free B%lld",needed,observedFree],@"wrapped deficit and original free bytes in message");
    }];watching=NO;
    Check(callbacks==1,@"synchronous callback exactly once");Check(formatterCalls==2,@"both sizes formatted before callback");
    Equal(formatted,(@[@(observedFree),@(needed)]),@"formatter order and full-width arguments");
    Check(lookupCalls==expectedLookups,@"successful class lookup cached, nil lookup retried");
    Check(currentController==nil,@"controller released after method returns");
    Check(![trace containsObject:@"new"],@"alloc/init construction rather than new");
    Check([trace containsObject:@"bundle"]==!wanted,@"localize only insufficient-space branch");
    if(expectedAlive){Check(deallocations==1,@"fresh controller released once");Check([trace indexOfObject:@"dealloc"]>[trace indexOfObject:@"callback"],@"controller released after callback");}
    Check([trace indexOfObject:@"format"]<[trace indexOfObject:@"callback"],@"format before callback");
}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];formatted=[NSMutableArray new];
    originalFormatter=method_setImplementation(class_getClassMethod(NSByteCountFormatter.class,@selector(stringFromByteCount:countStyle:)),(IMP)FormatBytes);
    originalBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    DownloadMenuHelper *h=[DownloadMenuHelper new];lookupNil=YES;Run(h,1,100,YES,1);
    lookupNil=NO;Run(h,100,201,NO,2);
    // Once resolved, later lookup results must not affect the cached class.
    lookupNil=YES;
    long long sizes[]={LLONG_MIN,LLONG_MIN/2,-1,0,1,100,LLONG_MAX/2,LLONG_MAX/2+1,LLONG_MAX};
    long long spaces[]={LLONG_MIN,-1,0,1,199,200,201,LLONG_MAX};
    for(NSUInteger i=0;i<9;++i)for(NSUInteger j=0;j<8;++j)Run(h,sizes[i],spaces[j],NO,2);
    allocNil=YES;Run(h,1,100,NO,2);allocNil=NO;
    initNil=YES;Run(h,-1,100,NO,2);initNil=NO;
    method_setImplementation(class_getClassMethod(NSByteCountFormatter.class,@selector(stringFromByteCount:countStyle:)),originalFormatter);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),originalBundle);
    printf("%s First_menu_storage: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
