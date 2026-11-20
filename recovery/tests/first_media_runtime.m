// Executes reconstructed source. Original package bytes are never loaded as code.
#import "../source/Downloads/YTPMedia.h"
#import "../source/Downloads/DownloadsHost.h"
#import <objc/runtime.h>
#import <math.h>
#import <limits.h>
static NSUInteger checks, styleReads, colorReads, initializations;
static long long style;
static BOOL oled, discord, nilBundle, nilImage;
static id version, bundle, imageName;
static NSMutableArray *events;
static void (^bundleHook)(void), (^preferenceHook)(void);
static void Check(BOOL value, NSString *label) {
    ++checks;
    if (!value) { fprintf(stderr,"FAIL %s\n",label.UTF8String); exit(1); }
}
static void Equal(id a,id b,NSString *label) { Check(a==b || [a isEqual:b],label); }
static void Event(NSString *name) { [events addObject:name]; }
@implementation UITraitCollection @end
@implementation UIImage @end
@implementation UIColor
+ (UIColor *)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    UIColor *c=[self new];c.red=r;c.green=g;c.blue=b;c.alpha=a;return c;
}
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))p {
    Event(@"provider");UIColor *c=[self new];c.provider=p;return c;
}
+ (UIColor *)blackColor { Event(@"black");return [self colorWithRed:0 green:0 blue:0 alpha:1]; }
+ (UIColor *)whiteColor { Event(@"white");return [self colorWithRed:1 green:1 blue:1 alpha:1]; }
- (BOOL)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a {
    ++colorReads;Event(@"getRed");if(self.cannotDecode)return NO;
    *r=self.red;*g=self.green;*b=self.blue;*a=self.alpha;return YES;
}
@end
@implementation UIApplication
+ (UIApplication *)sharedApplication {
    Event(@"application");static UIApplication *a;static dispatch_once_t once;
    dispatch_once(&once,^{a=[self new];});return a;
}
- (id)delegate { Event(@"delegate");return _delegate; }
@end
@interface YTLUserDefaults : NSObject @end
@implementation YTLUserDefaults
+ (BOOL)boolForKey:(NSString *)key {
    Event([@"preference:" stringByAppendingString:key]);
    Check([key isEqual:@"oledTheme"] || [key isEqual:@"discordRPC"],@"exact preference key");
    BOOL answer=[key isEqual:@"oledTheme"]?oled:discord;
    if(preferenceHook)preferenceHook();return answer;
}
@end
@interface MediaBundle : NSObject @end
@implementation MediaBundle
- (id)objectForInfoDictionaryKey:(id)key {
    Equal(key,@"CFBundleShortVersionString",@"version dictionary key");Event(@"version");return version;
}
- (UIImage *)imageWithName:(id)name {
    Event(@"image");imageName=name;if(nilImage)return nil;
    UIImage *image=[UIImage new];image.name=name;return image;
}
- (UIImage *)imageWithName:(id)name tintColor:(UIColor *)tint {
    UIImage *image=[self imageWithName:name];image.tint=tint;return image;
}
@end
static id MainBundle(id self,SEL cmd) { (void)self;(void)cmd;Event(@"mainBundle");return bundle; }
@implementation NSBundle (FirstMediaBoundary)
+ (NSBundle *)ytl_defaultBundle { Event(@"bundle");if(bundleHook)bundleHook();return nilBundle?nil:bundle; }
@end
@interface VersionProbe : NSObject
@property(nonatomic) NSComparisonResult result;
@end
@implementation VersionProbe
- (NSComparisonResult)compare:(id)other options:(NSStringCompareOptions)options {
    Equal(other,@"20.12.4",@"minimum version literal");Check(options==NSNumericSearch,@"numeric compare option");
    Event(@"compare");return self.result;
}
@end
@interface NameProbe : NSObject
@property(nonatomic,strong) id suffixResult;
@end
@implementation NameProbe
- (id)stringByAppendingString:(id)suffix {
    Event(@"append");Equal(suffix,@"_cairo",@"exact suffix");return self.suffixResult;
}
@end
@interface FirstMedia : YTPMedia @end
@implementation FirstMedia
- (instancetype)init { ++initializations;return [super init]; }
+ (long long)pageStyle { ++styleReads;Event(@"style");return style; }
@end
@interface StyleRoot : NSObject
@property(nonatomic) long long value;
@end
@implementation StyleRoot
- (long long)pageStyle { Event(@"rootStyle");return self.value; }
@end
@interface RootDelegate : NSObject
@property(nonatomic,strong) id first,second;
@property(nonatomic) NSUInteger reads;
@property(nonatomic,copy) void (^onRoot)(void);
@end
@implementation RootDelegate
- (id)responderRoot { Event(@"root");++_reads;if(self.onRoot)self.onRoot();return _reads==1?self.first:self.second; }
@end
static void ResetEvents(void) { [events removeAllObjects]; }
static void CheckColor(UIColor *color,double expected,NSString *label) {
    Check(color.red==expected && color.green==expected && color.blue==expected && color.alpha==1,label);
}
static void Singleton(void) {
    YTPMedia *first=[FirstMedia sharedMedia];Check([first class]==FirstMedia.class,@"singleton captures first receiving class");
    Check([YTPMedia sharedMedia]==first,@"singleton shared across subclasses");
    dispatch_apply(32,dispatch_get_global_queue(QOS_CLASS_DEFAULT,0),^(size_t i){
        (void)i;if([YTPMedia sharedMedia]!=first)exit(2);
    });
    Check(initializations==1,@"once-only initialization including concurrent reads");
}
static void Versions(void) {
    YTPMedia *media=[YTPMedia sharedMedia];
    NSArray *values=@[@"20.12.3",@"20.12.4",@"20.12.10",@"20.9.99",@"21.0",@"",NSNull.null];
    BOOL allowed[]={NO,YES,YES,NO,YES,NO,YES};
    for(NSUInteger i=0;i<values.count;++i)for(NSUInteger flag=0;flag<2;++flag){
        version=values[i]==NSNull.null?nil:values[i];media.cairo=flag;
        Check(media.isCairo==(allowed[i] && flag),@"numeric version gate");
    }
    VersionProbe *probe=[VersionProbe new];version=probe;
    // CMN x0,#1 rejects exactly -1, rather than all negative results.
    for(NSUInteger i=0;i<5;++i){
        probe.result=(NSComparisonResult[]){-2,-1,0,1,LLONG_MIN}[i];
        ResetEvents();media.cairo=YES;
        Equal(events,(@[@"mainBundle",@"version",@"compare"]),@"version receiver/call order");
        Check(media.isCairo==(probe.result!=-1),@"only NSOrderedAscending disables Cairo");
    }
    version=@"99.0";
}
static void PageStyles(void) {
    UIApplication *app=[UIApplication sharedApplication];
    app.delegate=nil;Check([YTPMedia pageStyle]==-1,@"nil delegate sentinel");
    app.delegate=[NSObject new];Check([YTPMedia pageStyle]==-1,@"missing responderRoot sentinel");
    RootDelegate *delegate=[RootDelegate new];app.delegate=delegate;
    Check([YTPMedia pageStyle]==-1 && delegate.reads==1,@"nil first root stops lookup");
    delegate.reads=0;delegate.first=[NSObject new];
    Check([YTPMedia pageStyle]==-1 && delegate.reads==1,@"root without pageStyle stops lookup");
    StyleRoot *root=[StyleRoot new];root.value=13;delegate.first=root;delegate.second=nil;delegate.reads=0;
    Check([YTPMedia pageStyle]==0 && delegate.reads==2,@"second nil root returns objc nil scalar");
    StyleRoot *second=[StyleRoot new];second.value=LLONG_MAX;delegate.second=second;delegate.reads=0;
    delegate.onRoot=^{app.delegate=nil;};ResetEvents();
    Check([YTPMedia pageStyle]==LLONG_MAX,@"second root read on retained original delegate");
    Equal(events,(@[@"application",@"delegate",@"root",@"root",@"rootStyle"]),@"root lookup sequence");
    delegate.onRoot=nil;
}
static void Backgrounds(void) {
    for(NSUInteger captured=0;captured<2;++captured){
        oled=captured;style=1;styleReads=0;ResetEvents();
        UIColor *color=[FirstMedia adaptiveBackgroundColor];
        Equal(events,(@[@"preference:oledTheme",@"provider"]),@"background captures preference before provider creation");
        Check(styleReads==0,@"theme evaluated only when provider resolves");oled=!captured;
        long long styles[]={-1,0,1,2,LLONG_MIN,LLONG_MAX};
        for(NSUInteger i=0;i<6;++i){style=styles[i];NSUInteger before=styleReads;
            UIColor *resolved=color.provider(nil);
            CheckColor(resolved,style==1?(captured?0:0.059):1,@"live style and captured OLED preference");
            Check(styleReads==before+1,@"provider dispatches to captured subclass");
        }
    }
}
static void OLEDColors(void) {
    style=1;Check([FirstMedia oledForColor:nil]==nil,@"nil color passthrough");
    UIColor *invalid=[UIColor new];invalid.cannotDecode=YES;
    Check([FirstMedia oledForColor:invalid]==invalid,@"undecodable color identity");
    for(NSUInteger grayIndex=0;grayIndex<2;++grayIndex)for(NSUInteger channel=0;channel<4;++channel){
        double gray=grayIndex?0.129:0.059,center=channel==3?1:gray;
        double low=center-0.001,high=center+0.001;
        double probes[]={center,center-0.0005,center+0.0005,nextafter(low,center),nextafter(high,center),
            nextafter(low,-INFINITY),nextafter(high,INFINITY),NAN,INFINITY,-INFINITY};
        for(NSUInteger i=0;i<10;++i){
            double rgba[]={gray,gray,gray,1};rgba[channel]=probes[i];
            UIColor *input=[UIColor colorWithRed:rgba[0] green:rgba[1] blue:rgba[2] alpha:rgba[3]];
            style=1;styleReads=0;colorReads=0;UIColor *output=[FirstMedia oledForColor:input];
            Check(styleReads==1 && colorReads==1,@"single initial style and component read");
            if(i<5){
                Check(output!=input && output.provider!=nil,@"neutral opaque color inside strict threshold gets provider");
                CheckColor(output.provider(nil),0,@"OLED dark resolution");
                style=0;CheckColor(output.provider(nil),1,@"OLED provider tracks later light mode");
                style=-1;CheckColor(output.provider(nil),1,@"OLED provider sentinel resolves white");
            }else Check(output==input,@"outside threshold or nonfinite channel preserves object");
        }
    }
    for(NSUInteger i=0;i<4;++i){style=(long long[]){-1,0,2,LLONG_MAX}[i];colorReads=0;
        Check([FirstMedia oledForColor:invalid]==invalid && colorReads==0,@"non-dark skips component decode");
    }
}
static void Assets(void) {
    YTPMedia *media=[YTPMedia sharedMedia];NameProbe *name=[NameProbe new];
    id original=[NSObject new],changed=[NSObject new];name.suffixResult=original;
    for(NSUInteger cairo=0;cairo<2;++cairo){
        media.cairo=cairo;name.suffixResult=original;
        bundleHook=^{media.cairo=!cairo;name.suffixResult=changed;};ResetEvents();
        UIImage *result=[YTPMedia imageWithName:(id)name];
        Check(result.name==(cairo?changed:name),@"Cairo captured before bundle; suffix appended after bundle");
        Equal(events,cairo?(@[@"bundle",@"mainBundle",@"version",@"append",@"image"]):
              (@[@"bundle",@"mainBundle",@"version",@"image"]),@"generic image receiver evaluation order");
        bundleHook=nil;media.cairo=cairo;ResetEvents();
        [YTPMedia imageWithName:nil];Check(imageName==nil,@"nil name passed unchanged through suffix branch");
        nilImage=YES;Check([YTPMedia imageWithName:@"absent"]==nil,@"missing image no fallback");nilImage=NO;
        nilBundle=YES;ResetEvents();Check([YTPMedia imageWithName:(id)name]==nil,@"nil bundle result");
        Equal(events,cairo?(@[@"bundle",@"append"]):(@[@"bundle"]),@"argument evaluated even when bundle nil");nilBundle=NO;
    }
    for(NSUInteger enabled=0;enabled<2;++enabled)for(NSUInteger cairo=0;cairo<2;++cairo){
        discord=enabled;media.cairo=!cairo;
        preferenceHook=^{media.cairo=cairo;};bundleHook=^{discord=!enabled;media.cairo=!cairo;};ResetEvents();
        UIImage *result=[YTPMedia adaptiveDiscord];
        Equal(result.name,enabled?(cairo?@"discord_fill_cairo":@"discord_fill"):(cairo?@"discord_cairo":@"discord"),
              @"Discord preference before Cairo snapshot; bundle mutation does not change selection");
        Equal(events,(@[@"preference:discordRPC",@"mainBundle",@"version",@"bundle",@"mainBundle",@"version",@"image"]),
              @"Discord preference and bundle order");preferenceHook=nil;bundleHook=nil;
    }
}
int main(void) { @autoreleasepool {
    events=[NSMutableArray new];bundle=[MediaBundle new];version=@"99.0";
    Method method=class_getClassMethod(NSBundle.class,@selector(mainBundle));
    class_replaceMethod(object_getClass(NSBundle.class),@selector(mainBundle),(IMP)MainBundle,method_getTypeEncoding(method));
    Singleton();Versions();PageStyles();Backgrounds();OLEDColors();Assets();
    printf("PASS First_media_theme: %lu assertions\n",(unsigned long)checks);
    return 0;
} }
