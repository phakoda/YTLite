#import "downloads_doubles.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,failures;
static BOOL watching,synthetic,nilArray,nilJoin,nilBoard,nilNewline;
static NSUInteger trimCalls,substringCalls,nilTrimAt,nilSubstringAt,whiteCalls;
static NSMutableArray *trace;
static NSArray *whiteResults;
static id lastWhitespace,newlineResult,captured;
static IMP oldWhite,oldNewline,oldArray,oldJoin;
static id sink,board;
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static void Event(NSString *event){if(watching)[trace addObject:event];}
@interface FLLine : NSObject
@property(nonatomic,copy) NSString *value,*tag;
@end
@implementation FLLine
- (BOOL)isEqualToString:(id)other {
    Event([NSString stringWithFormat:@"eq:%@:%@",self.tag,[other isKindOfClass:FLLine.class]?[(FLLine *)other tag]:(other?:@"nil")]);
    return [self.value isEqualToString:[other isKindOfClass:FLLine.class]?[(FLLine *)other value]:other];
}
@end
@interface FLText : NSObject
@property(nonatomic,copy) NSString *value;
+ (instancetype)text:(NSString *)value;
@end
@implementation FLText
+ (instancetype)text:(NSString *)value {FLText *x=[FLText new];x.value=value;return x;}
- (id)stringByTrimmingCharactersInSet:(NSCharacterSet *)set {
    Event(@"trim");++trimCalls;Check(set==lastWhitespace,@"trim receives latest factory result including nil");
    if(nilTrimAt==trimCalls)return nil;
    return [FLText text:set?[self.value stringByTrimmingCharactersInSet:set]:self.value];
}
- (BOOL)hasSuffix:(NSString *)suffix {Event(@"suffix");Equal(suffix,@".",@"exact suffix");return [self.value hasSuffix:suffix];}
- (NSUInteger)length {Event(@"length");return self.value.length;}
- (id)substringToIndex:(NSUInteger)index {Event(@"substring");++substringCalls;Check(index==self.value.length-1,@"remove one UTF-16 unit");if(nilSubstringAt==substringCalls)return nil;return [FLText text:[self.value substringToIndex:index]];}
@end
@interface FLSink : NSObject
@property(nonatomic,strong) NSMutableArray *accepted;
@end
@implementation FLSink
- (void)addObject:(FLLine *)line {Event([@"add:" stringByAppendingString:line.tag]);[self.accepted addObject:line];}
- (id)componentsJoinedByString:(NSString *)separator {Event(@"join");Equal(separator,@"\n",@"exact line separator");if(nilJoin)return nil;NSMutableArray *values=[NSMutableArray new];for(FLLine *line in self.accepted)[values addObject:line.value];BOOL old=watching;watching=NO;NSString *value=[values componentsJoinedByString:separator];watching=old;return [FLText text:value];}
@end
@interface FLLog : NSObject
@property(nonatomic,strong) NSArray *lines;
@end
@implementation FLLog
- (NSArray *)componentsSeparatedByCharactersInSet:(NSCharacterSet *)set {Event(@"split");Check(set==newlineResult,@"split receives newline factory result including nil");return self.lines;}
@end
@interface FLBoard : NSObject @end
@implementation FLBoard
- (void)setString:(id)value {Event(@"set");captured=value;}
@end
static id White(id cls,SEL sel) {
    if(!watching)return ((id(*)(id,SEL))oldWhite)(cls,sel);
    Event(@"white");++whiteCalls;
    id value=whiteResults?whiteResults[MIN(whiteCalls-1,whiteResults.count-1)]:((id(*)(id,SEL))oldWhite)(cls,sel);
    lastWhitespace=value==NSNull.null?nil:value;return lastWhitespace;
}
static id Newline(id cls,SEL sel) {
    if(!watching)return ((id(*)(id,SEL))oldNewline)(cls,sel);
    if(synthetic)Event(@"newline");newlineResult=nilNewline?nil:((id(*)(id,SEL))oldNewline)(cls,sel);return newlineResult;
}
static id Array(id cls,SEL sel) {if(watching&&synthetic){Event(@"array");return nilArray?nil:sink;}return ((id(*)(id,SEL))oldArray)(cls,sel);}
static id Join(id self,SEL sel,id separator) {Event(@"join");return ((id(*)(id,SEL,id))oldJoin)(self,sel,separator);}
static id Board(id cls,SEL sel) {(void)cls;(void)sel;Event(@"board");return nilBoard?nil:board;}
static IMP Swap(Class cls,SEL selector,IMP replacement) {Method m=class_getInstanceMethod(cls,selector);Check(m!=NULL,@"fixture selector exists");IMP old=method_getImplementation(m);if(!class_addMethod(cls,selector,replacement,method_getTypeEncoding(m)))method_setImplementation(m,replacement);return old;}
static void Reset(void) {watching=NO;synthetic=NO;nilArray=nilJoin=nilBoard=nilNewline=NO;nilTrimAt=nilSubstringAt=trimCalls=substringCalls=whiteCalls=0;whiteResults=nil;lastWhitespace=newlineResult=nil;captured=NSNull.null;[trace removeAllObjects];FLSink *s=[FLSink new];s.accepted=[NSMutableArray new];sink=s;}
static FLLog *Log(NSArray *values) {FLLog *log=[FLLog new];NSMutableArray *lines=[NSMutableArray new];NSUInteger n=0;for(NSString *value in values){FLLine *line=[FLLine new];line.value=value;line.tag=[NSString stringWithFormat:@"%lu",(unsigned long)n++];[lines addObject:line];}log.lines=lines;return log;}
static void Run(FFMpegHelper *helper,id log) {watching=YES;[helper getCleanLog:log];watching=NO;}
static id CapturedValue(void) {return [captured isKindOfClass:FLText.class]?[(FLText *)captured value]:captured;}
int main(int argc,char **argv) {@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];board=[FLBoard new];
    oldWhite=Swap(object_getClass(NSCharacterSet.class),@selector(whitespaceAndNewlineCharacterSet),(IMP)White);
    oldNewline=Swap(object_getClass(NSCharacterSet.class),@selector(newlineCharacterSet),(IMP)Newline);
    oldArray=Swap(object_getClass(NSMutableArray.class),@selector(array),(IMP)Array);
    oldJoin=Swap(object_getClass([NSMutableArray array]),@selector(componentsJoinedByString:),(IMP)Join);
    Swap(object_getClass(UIPasteboard.class),@selector(generalPasteboard),(IMP)Board);
    FFMpegHelper *helper=[FFMpegHelper new];
    Check(argc==2,@"vector argument");if(argc!=2)return 1;
    NSArray *vectors=[NSJSONSerialization JSONObjectWithData:[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]] options:0 error:nil];
    Check(vectors.count>500,@"independent output vectors loaded");
    for(NSDictionary *v in vectors){Reset();Run(helper,v[@"input"]==NSNull.null?nil:v[@"input"]);Equal(CapturedValue(),v[@"output"],@"real Foundation log output");Check(whiteCalls==[v[@"whites"] unsignedIntegerValue],@"one fresh character set per trim");NSMutableArray *expected=[NSMutableArray arrayWithObject:@"join"];for(NSUInteger i=0;i<[v[@"whites"] unsignedIntegerValue];++i)[expected addObject:@"white"];[expected addObjectsFromArray:@[@"board",@"set"]];Equal(trace,expected,@"join then all trims then pasteboard");}
    // Receiver and previous-line identity, including duplicates separated by empties.
    Reset();synthetic=YES;Run(helper,Log(@[@"a",@"",@"a",@"b",@"a"]));
    Equal(trace,(@[@"newline",@"split",@"array",@"eq:0:",@"eq:0:nil",@"add:0",@"eq:1:",@"eq:2:",@"eq:2:0",@"eq:3:",@"eq:3:0",@"add:3",@"eq:4:",@"eq:4:3",@"add:4",@"join",@"white",@"trim",@"suffix",@"board",@"set"]),@"filter compares before append and preserves previous across empty lines");Equal(CapturedValue(),@"a\nb\na",@"nonconsecutive duplicate retained");
    NSCharacterSet *normal=[NSCharacterSet whitespaceAndNewlineCharacterSet];NSCharacterSet *xset=[NSCharacterSet characterSetWithCharactersInString:@"x"];
    Reset();synthetic=YES;whiteResults=@[normal,xset,normal];Run(helper,Log(@[@" q .x. "]));
    Equal(CapturedValue(),@"q",@"fresh factory results change successive trims");
    Equal(trace,(@[@"newline",@"split",@"array",@"eq:0:",@"eq:0:nil",@"add:0",@"join",@"white",@"trim",@"suffix",@"length",@"substring",@"white",@"trim",@"suffix",@"length",@"substring",@"white",@"trim",@"suffix",@"board",@"set"]),@"substring precedes each fresh whitespace factory");
    for(NSUInteger mode=0;mode<9;++mode){Reset();synthetic=YES;FLLog *log=Log(@[@"a... "]);if(mode==0)log=nil;if(mode==1)log.lines=nil;if(mode==2)nilArray=YES;if(mode==3)nilJoin=YES;if(mode==4)nilTrimAt=1;if(mode==5)nilTrimAt=2;if(mode==6)nilSubstringAt=1;if(mode==7)nilBoard=YES;if(mode==8)nilNewline=YES;Run(helper,log);
        id expected=mode==0||mode==1?@"":mode>=2&&mode<=6?nil:mode==7?NSNull.null:@"a";Equal(CapturedValue(),expected,@"nil boundary result is forwarded");
        NSUInteger whites=mode==5||mode==6?2:mode>=7?4:1;Check(whiteCalls==whites,@"nil receivers preserve argument evaluation");Check([trace containsObject:@"board"],@"pasteboard still selected at terminal stage");
    }
    // Synthetic trim permits a nil character set so argument forwarding is visible.
    Reset();synthetic=YES;whiteResults=@[NSNull.null];Run(helper,Log(@[@"a."]));Equal(CapturedValue(),@"a",@"nil character sets forwarded without replacement");Check(whiteCalls==2,@"nil factory looked up independently for each trim");
    printf("%s First_ffmpeg_log: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
