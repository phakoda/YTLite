#import "downloads_doubles.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>
#import <stdarg.h>
static NSUInteger checks,failures,managerReads,formats,codeCalls;
static BOOL watching,languagePhase,nilDictionary,nilLookup,nilFormat;
static unsigned existsMask,nilManagers;
static NSMutableArray *trace;
static NSArray *languagePairs;
static NSDictionary *languageMap;
static id codeResult,expectedCaps,expectedCode,lookupResult;
static id dictionaryObject;
static IMP oldDictionary;
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static void Event(NSString *s){if(watching)[trace addObject:s];}
@interface FCComponent : NSObject
@property(nonatomic,strong) id code;
@end
@implementation FCComponent
- (id)stringByDeletingPathExtension{Event(@"strip");return self.code;}
@end
@interface FCURL : NSObject
@property(nonatomic,copy) NSString *tag,*pathValue,*display;
@property(nonatomic,strong) id component;
@end
@implementation FCURL
- (id)path {Event([self.tag stringByAppendingString:@".path"]);return self.pathValue;}
- (id)lastPathComponent {Event(@"last");return self.component;}
- (NSString *)description {return self.display;}
@end
@interface FCManager : NSObject
@property(nonatomic) NSUInteger number;
@end
@implementation FCManager
- (BOOL)fileExistsAtPath:(id)path {Event(self.number==1?@"exists1":@"exists2");id expected=self.number==1?[(FCURL *)expectedCaps pathValue]:nil; if(self.number==2)expected=objc_getAssociatedObject(dictionaryObject,@selector(fileExistsAtPath:));Check(path==expected,@"path forwarded to its selected manager including nil");return (existsMask&(1u<<(self.number-1)))!=0;}
@end
static id Manager(id cls,SEL sel){(void)cls;(void)sel;++managerReads;Event(managerReads==1?@"manager1":@"manager2");Check(managerReads<=2,@"two manager lookups");if(managerReads>2||nilManagers&(1u<<(managerReads-1)))return nil;FCManager *m=[FCManager new];m.number=managerReads;return m;}
@interface FCProbe : FFMpegHelper @end
@implementation FCProbe
- (NSString *)codeForCaps:(NSURL *)url {Event(@"language");++codeCalls;Check(url==expectedCaps,@"caption URL identity in command branch");return codeResult;}
@end
@interface FCDictionary : NSObject @end
@implementation FCDictionary
- (id)objectForKeyedSubscript:(id)key {Event(@"lookup");Check(key==expectedCode,@"dictionary receives stripped code object including nil");if(nilLookup)return nil;if(lookupResult)return lookupResult;return key?languageMap[key]:nil;}
@end
static id Dictionary(id cls,SEL sel,const id *objects,const id *keys,NSUInteger count) {
    if(!(watching&&languagePhase))return ((id(*)(id,SEL,const id *,const id *,NSUInteger))oldDictionary)(cls,sel,objects,keys,count);
    Event(@"dictionary");Check(count==80,@"all 80 language pairs passed to constructor");BOOL equal=count==languagePairs.count;for(NSUInteger i=0;i<MIN(count,languagePairs.count);++i){NSDictionary *p=languagePairs[i];equal=equal&&[keys[i] isEqual:p[@"key"]]&&[objects[i] isEqual:p[@"value"]];}Check(equal,@"ordered key/value pairs match original stack arrays");return nilDictionary?nil:dictionaryObject;
}
static id Format(id cls,SEL sel,NSString *format,...) {
    (void)cls;(void)sel;va_list args;va_start(args,format);
    BOOL target=watching&&!languagePhase&&[format hasPrefix:@"-hide_banner"];
    if(target){Event(@"format");++formats;}
    id result=target&&nilFormat?nil:[[NSString alloc] initWithFormat:format arguments:args];va_end(args);return result;
}
static IMP Swap(Class cls,SEL sel,IMP replacement){Method m=class_getInstanceMethod(cls,sel);Check(m!=NULL,@"fixture selector exists");IMP old=method_getImplementation(m);if(!class_addMethod(cls,sel,replacement,method_getTypeEncoding(m)))method_setImplementation(m,replacement);return old;}
static FCURL *URL(NSString *tag,NSString *value){FCURL *u=[FCURL new];u.tag=tag;u.display=value;u.pathValue=[tag stringByAppendingString:@"-path"];return u;}
static void Reset(void){watching=NO;languagePhase=NO;managerReads=formats=codeCalls=0;existsMask=nilManagers=0;nilDictionary=nilLookup=nilFormat=NO;lookupResult=nil;codeResult=@"eng";[trace removeAllObjects];}
int main(int argc,char **argv){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];dictionaryObject=[FCDictionary new];
    Check(argc==2,@"vector argument");if(argc!=2)return 1;
    NSDictionary *data=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]] options:0 error:nil];languagePairs=data[@"languages"];Check(languagePairs.count==80,@"original table loaded");NSMutableDictionary *map=[NSMutableDictionary new];for(NSDictionary *p in languagePairs)map[p[@"key"]]=p[@"value"];languageMap=map;
    oldDictionary=Swap(object_getClass(NSDictionary.class),@selector(dictionaryWithObjects:forKeys:count:),(IMP)Dictionary);
    Swap(object_getClass(NSFileManager.class),@selector(defaultManager),(IMP)Manager);
    Swap(object_getClass(NSString.class),@selector(stringWithFormat:),(IMP)Format);
    FCProbe *probe=[FCProbe new];FFMpegHelper *helper=[FFMpegHelper new];
    NSArray *names=@[@"v folder/%20\".mp4",@"a'with space.m4a",@"EN.srt",@"#thumb.webp",@"o %@.mp4"];
    for(NSDictionary *v in data[@"commands"]){Reset();unsigned mask=[v[@"nil_mask"] unsignedIntValue];existsMask=[v[@"exists"] unsignedIntValue];nilManagers=[v[@"nil_managers"] unsignedIntValue];nilFormat=[v[@"nil_format"] boolValue];codeResult=[v[@"nil_language"] boolValue]?nil:@"eng";
        id urls[5];for(NSUInteger i=0;i<5;++i)urls[i]=(mask&(1u<<i))?nil:URL(i==2?@"caps":i==3?@"thumb":@"unused",names[i]);if([v[@"nil_paths"] unsignedIntValue]&1)[(FCURL *)urls[2] setPathValue:nil];if([v[@"nil_paths"] unsignedIntValue]&2)[(FCURL *)urls[3] setPathValue:nil];expectedCaps=urls[2];objc_setAssociatedObject(dictionaryObject,@selector(fileExistsAtPath:),[(FCURL *)urls[3] pathValue],OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        watching=YES;id result=[probe getCommandWithVideoURL:urls[0] audioURL:urls[1] captionsURL:urls[2] thumbnailURL:urls[3] duration:[v[@"duration"] longLongValue] outputURL:urls[4]];watching=NO;
        Equal(result,v[@"output"]==NSNull.null?nil:v[@"output"],@"exact original command format and argument order");Equal(trace,v[@"trace"],@"manager, path, language and formatting order");Check(managerReads==2&&formats==1,@"both existence checks precede one format call");Check(codeCalls==((existsMask&1)&&!(nilManagers&1)?1u:0u),@"language requested exactly on caption branches");
    }
    // All table entries run through the actual caption method and constructor.
    for(NSDictionary *p in languagePairs){Reset();languagePhase=YES;FCURL *u=URL(@"caps",@"unused");FCComponent *component=[FCComponent new];component.code=[p[@"key"] mutableCopy];u.component=component;expectedCode=component.code;watching=YES;id result=[helper codeForCaps:(id)u];watching=NO;Equal(result,p[@"value"],@"mapped caption language");Equal(trace,(@[@"last",@"strip",@"dictionary",@"lookup"]),@"language construction and lookup order");}
    for(NSUInteger mode=0;mode<7;++mode){Reset();languagePhase=YES;FCURL *u=URL(@"caps",@"unused");FCComponent *component=[FCComponent new];component.code=[@"unknown-CASE" mutableCopy];u.component=component;expectedCode=component.code;
        if(mode==0)u=nil;if(mode==1){u.component=nil;expectedCode=nil;}if(mode==2){component.code=nil;expectedCode=nil;}if(mode==3)nilDictionary=YES;if(mode==4)nilLookup=YES;if(mode==5)lookupResult=[NSObject new];
        watching=YES;id result=[helper codeForCaps:(id)u];watching=NO;id expected=mode==0?nil:mode==5?lookupResult:expectedCode;Check(result==expected,@"fallback preserves exact code or returned object identity");NSMutableArray *order=[NSMutableArray new];if(mode!=0){[order addObject:@"last"];if(mode!=1)[order addObject:@"strip"];[order addObject:@"dictionary"];if(mode!=3)[order addObject:@"lookup"];}Equal(trace,order,@"nil boundary evaluation order");
    }
    // Native NSURL and NSString path handling, including case and multiple dots.
    NSArray *paths=@[@"en.srt",@"fr-CA.vtt",@"zh-Hant-HK.srt",@"unknown.srt",@"EN.srt",@"en.extra.srt",@"en",@".hidden",@"en.srt/"];
    NSArray *expected=@[@"eng",@"fra",@"zho",@"unknown",@"EN",@"en.extra",@"eng",@".hidden",@"eng"];
    for(NSUInteger i=0;i<paths.count;++i){Reset();NSURL *u=[NSURL fileURLWithPath:[@"/synthetic-only/" stringByAppendingString:paths[i]]];Equal([helper codeForCaps:u],expected[i],@"native filename and extension behavior");}
    printf("%s First_ffmpeg_command: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
