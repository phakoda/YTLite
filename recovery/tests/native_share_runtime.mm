#import "NativeShareHost.h"
#import <objc/runtime.h>
#include <stdio.h>
#include <stdlib.h>
static NSUInteger checks;
#define CHECK(...) do { checks++; if(!(__VA_ARGS__)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);} }while(0)
static BOOL enabled,popoverEnabled,fieldsNil;
static NSUInteger defaultsAllocations,defaultsReads,descriptionReads,deserializeCalls,parseCalls,fieldInitCalls,contextReads,presentCalls,screenReads;
static NSMutableArray *events,*fieldQueries;
static NSArray *activityItems,*applicationActivities,*originalArguments;
static UIActivityViewController *lastActivity;
static UIViewController *top;
static GPBMessage *deserialized,*parsedClip;
static NSString *lastSerialized;
static NSData *lastParsedData;
static UIView *conversionTarget;
static CGRect conversionInput,convertedRect;
static NSDictionary<NSNumber *,NSArray *> *messageFields,*clipFields;
static NSString *messageText,*commandText;
static NSUInteger explicitCount;
static BOOL parseErrorWasNil;
NSString *const UIActivityTypeAssignToContact=@"AssignToContact";
NSString *const UIActivityTypePrint=@"Print";
@implementation NativeShareFixtureDefaults
- (instancetype)initWithSuiteName:(NSString *)suite { CHECK([suite isEqual:@"com.dvntm.ytlite"]);defaultsAllocations++;return [super init]; }
- (BOOL)boolForKey:(NSString *)key { CHECK([key isEqual:@"nativeShare"]);defaultsReads++;return enabled; }
@end
@implementation UIView
- (CGRect)convertRect:(CGRect)rect toView:(UIView *)view { conversionInput=rect;conversionTarget=view;[events addObject:@"convert"];return convertedRect; }
@end
@implementation UIViewController
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion { CHECK(controller==lastActivity&&animated&&completion==nil);presentCalls++;[events addObject:@"present"]; }
@end
@implementation UIPopoverPresentationController @end
@implementation UIActivityViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities { if((self=[super init])){activityItems=[items copy];applicationActivities=activities;lastActivity=self;self.popoverPresentationController=popoverEnabled?[UIPopoverPresentationController new]:nil;[events addObject:@"activity"];}return self; }
@end
@implementation UIScreen
+ (instancetype)mainScreen { screenReads++;UIScreen *screen=[UIScreen new];screen.bounds=screenReads==1?CGRectMake(9,8,641,923):CGRectMake(7,6,111,927);return screen; }
@end
@implementation GPBMessage
+ (instancetype)deserializeFromString:(NSString *)string { deserializeCalls++;lastSerialized=string;return deserialized; }
+ (instancetype)parseFromData:(NSData *)data error:(NSError **)error { parseCalls++;lastParsedData=data;parseErrorWasNil=(error==NULL);return parsedClip; }
- (NSString *)description { descriptionReads++;return messageText; }
@end
@interface GPBUnknownField ()
@property(nonatomic,strong) NSData *lengthDelimited;
@end
@implementation GPBUnknownField @end
@interface GPBUnknownFields ()
@property(nonatomic,strong) NSDictionary<NSNumber *,NSArray *> *fixtureFields;
@property(nonatomic) BOOL clip;
@end
@implementation GPBUnknownFields
- (instancetype)initFromMessage:(GPBMessage *)message { fieldInitCalls++;if(fieldsNil)return nil;if((self=[super init])){self.clip=(message==parsedClip);self.fixtureFields=self.clip?clipFields:messageFields;}return self; }
- (NSUInteger)count { return explicitCount; }
- (NSArray *)fields:(int32_t)number { [fieldQueries addObject:[NSString stringWithFormat:@"%@:%d",self.clip?@"clip":@"main",number]];return self.fixtureFields[@(number)]; }
@end
@implementation YTUIUtils
+ (UIViewController *)topViewControllerForPresenting { [events addObject:@"top"];return top; }
@end
@implementation ELMPBShowActionSheetCommand
- (NSString *)description { descriptionReads++;return commandText; }
- (void)executeWithCommandContext:(id)context handler:(id)handler { [events addObject:@"sheetOrig"];originalArguments=@[context?:NSNull.null,handler?:NSNull.null]; }
@end
@implementation YTShareEntityEndpointCommandHandler
- (void)executeWithCommand:(id)command entry:(id)entry fromView:(UIView *)view sender:(id)sender { [events addObject:@"endpointOrig"];originalArguments=@[command?:NSNull.null,entry?:NSNull.null,view?:NSNull.null,sender?:NSNull.null]; }
@end
@interface ShareCommand : NSObject @end
@implementation ShareCommand
- (NSString *)description { descriptionReads++;return commandText; }
@end
@interface ShareContext : NSObject<YTLNativeShareCommandContext>
@property(nonatomic,strong) id<YTLNativeShareContext> value;
@end
@implementation ShareContext
- (id<YTLNativeShareContext>)context { contextReads++;return self.value; }
@end
@interface ShareViewContext : NSObject<YTLNativeShareContext>
@property(nonatomic,strong) UIView *fromView;
@end
@implementation ShareViewContext @end
static void Reset(void) {
    enabled=YES;popoverEnabled=NO;fieldsNil=NO;explicitCount=1;defaultsAllocations=defaultsReads=descriptionReads=deserializeCalls=parseCalls=fieldInitCalls=contextReads=presentCalls=screenReads=0;
    events=[NSMutableArray new];fieldQueries=[NSMutableArray new];activityItems=applicationActivities=originalArguments=nil;lastActivity=nil;top=[UIViewController new];top.view=[UIView new];
    deserialized=[GPBMessage new];parsedClip=[GPBMessage new];messageFields=@{};clipFields=@{};messageText=@"";commandText=@"serialized_share_entity: \"serialized-one\"";lastSerialized=nil;lastParsedData=nil;conversionTarget=nil;conversionInput=CGRectZero;convertedRect=CGRectMake(-9.25,18.5,77.25,90.5);parseErrorWasNil=NO;
}
static GPBUnknownField *Field(NSData *data) { GPBUnknownField *field=[GPBUnknownField new];field.lengthDelimited=data;return field; }
static NSArray *Values(NSString *value) { return @[Field([value dataUsingEncoding:NSUTF8StringEncoding])]; }
static void Endpoint(UIView *view) { [[YTShareEntityEndpointCommandHandler new] executeWithCommand:[ShareCommand new] entry:nil fromView:view sender:nil]; }
static void URL(NSString *expected) { CHECK(activityItems.count==1&&[activityItems[0]isEqual:expected]);CHECK(applicationActivities==nil);CHECK([lastActivity.excludedActivityTypes isEqual:@[UIActivityTypeAssignToContact,UIActivityTypePrint]]);CHECK(presentCalls==1&&originalArguments==nil);CHECK(defaultsAllocations==1&&defaultsReads==1); }
int main(void) { @autoreleasepool {
    Reset();IMP oldSheet=class_getMethodImplementation([ELMPBShowActionSheetCommand class],@selector(executeWithCommandContext:handler:));IMP oldEndpoint=class_getMethodImplementation([YTShareEntityEndpointCommandHandler class],@selector(executeWithCommand:entry:fromView:sender:));YTLInstallNativeShareHooks();CHECK(oldSheet!=class_getMethodImplementation([ELMPBShowActionSheetCommand class],@selector(executeWithCommandContext:handler:)));CHECK(oldEndpoint!=class_getMethodImplementation([YTShareEntityEndpointCommandHandler class],@selector(executeWithCommand:entry:fromView:sender:)));CHECK(defaultsAllocations==0);
    NSObject *entry=[NSObject new],*sender=[NSObject new];ShareCommand *command=[ShareCommand new];UIView *view=[UIView new];view.bounds=CGRectMake(0.25,1.5,44.75,29.5);
    Reset();enabled=NO;[[YTShareEntityEndpointCommandHandler new] executeWithCommand:command entry:entry fromView:view sender:sender];CHECK([originalArguments isEqual:@[command,entry,view,sender]]&&descriptionReads==0&&deserializeCalls==0);CHECK(defaultsAllocations==1&&defaultsReads==1);
    Reset();enabled=NO;[[ELMPBShowActionSheetCommand new] executeWithCommandContext:nil handler:sender];CHECK([originalArguments isEqual:@[NSNull.null,sender]]&&descriptionReads==0);
    for(NSString *text in @[@"unrelated",@"serialized_share_entity: \"\"",@"serialized_share_entity:\"tight\""]){Reset();commandText=text;Endpoint(nil);CHECK([events isEqual:@[@"endpointOrig"]]&&deserializeCalls==0);}
    Reset();deserialized=nil;Endpoint(nil);CHECK([events isEqual:@[@"endpointOrig"]]&&deserializeCalls==1&&fieldInitCalls==0);
    Reset();Endpoint(nil);CHECK([events isEqual:@[@"endpointOrig"]]);CHECK([fieldQueries isEqual:@[@"main:8",@"main:3",@"main:6",@"main:2",@"main:10",@"main:1"]]);
    NSArray *fieldNumbers=@[@3,@6,@2,@1];NSArray *urls=@[@"https://youtube.com/channel/id",@"https://youtube.com/post/id",@"https://youtube.com/playlist?list=id&playnext=1",@"https://youtube.com/watch?v=id"];
    for(NSUInteger i=0;i<4;i++){Reset();messageFields=@{fieldNumbers[i]:Values(@"id")};Endpoint(nil);URL(urls[i]);CHECK([lastSerialized isEqual:@"serialized-one"]);}
    Reset();messageFields=@{@8:Values(@"clip-data"),@3:Values(@"channel"),@6:Values(@"post"),@2:Values(@"PLx"),@1:Values(@"video")};clipFields=@{@1:Values(@"clip")};Endpoint(nil);URL(@"https://youtube.com/clip/clip");CHECK(parseCalls==1&&parseErrorWasNil&&[lastParsedData isEqual:[@"clip-data" dataUsingEncoding:NSUTF8StringEncoding]]);CHECK([fieldQueries isEqual:@[@"main:8",@"clip:1"]]);
    Reset();messageFields=@{@3:Values(@"channel"),@6:Values(@"post"),@2:Values(@"PLx"),@1:Values(@"video")};Endpoint(nil);URL(@"https://youtube.com/channel/channel");
    Reset();messageFields=@{@6:Values(@"post"),@2:Values(@"PLx"),@1:Values(@"video")};Endpoint(nil);URL(@"https://youtube.com/post/post");
    for(NSString *list in @[@"PLx",@"FLx",@"RDx",@""]){Reset();messageFields=@{@2:Values(list),@1:Values(@"video")};Endpoint(nil);URL([NSString stringWithFormat:@"https://youtube.com/playlist?list=%@%@",list,([list hasPrefix:@"PL"]||[list hasPrefix:@"FL"])?@"":@"&playnext=1"]);}
    Reset();messageFields=@{@10:@[[NSObject new],[NSObject new]],@1:Values(@"short")};Endpoint(nil);URL(@"https://youtube.com/shorts/short");
    Reset();messageFields=@{@8:@[Field([NSData data]),Field([NSData data])],@3:Values(@"next")};Endpoint(nil);URL(@"https://youtube.com/channel/next");CHECK(parseCalls==0);
    Reset();messageFields=@{@8:Values(@"badclip"),@3:Values(@"next")};parsedClip=nil;Endpoint(nil);URL(@"https://youtube.com/channel/next");CHECK(parseCalls==1&&fieldInitCalls==2);
    for(NSNumber *number in @[@3,@6,@2,@1]){Reset();messageFields=@{number:@[Field([NSData data]),Field([NSData data])]};Endpoint(nil);CHECK(originalArguments!=nil&&lastActivity==nil);}
    for(NSNumber *number in @[@3,@6,@2,@1]){Reset();const unsigned char bad[]={0xff};messageFields=@{number:@[Field([NSData dataWithBytes:bad length:1])]};Endpoint(nil);NSString *prefix=number.intValue==3?@"channel/":number.intValue==6?@"post/":number.intValue==2?@"playlist?list=":@"watch?v=";URL([NSString stringWithFormat:@"https://youtube.com/%@(null)%@",prefix,number.intValue==2?@"&playnext=1":@""]);}
    for(int nilFields=0;nilFields<2;nilFields++)for(NSUInteger i=0;i<4;i++){Reset();fieldsNil=nilFields;explicitCount=0;messageText=[NSString stringWithFormat:@"%@: \"id\"",fieldNumbers[i]];Endpoint(nil);URL(urls[i]);CHECK(fieldQueries.count==0);}
    Reset();explicitCount=0;messageText=@"1: \"video\" 2: \"PLlist\" 6: \"post\" 3: \"channel\"";Endpoint(nil);URL(@"https://youtube.com/channel/channel");
    Reset();explicitCount=0;messageText=@"13: \"wrong\" 1: \"first\" 1: \"second\" 10: \"short\"";Endpoint(nil);URL(@"https://youtube.com/watch?v=first");
    for(NSString *list in @[@"PLx",@"FLx"]){Reset();explicitCount=0;messageText=[NSString stringWithFormat:@"2: \"%@\"",list];Endpoint(nil);URL([@"https://youtube.com/playlist?list=" stringByAppendingString:list]);}
    Reset();explicitCount=0;messageText=@"8: \"clip\" 1: \"\"";Endpoint(nil);CHECK(originalArguments!=nil&&parseCalls==0);
    Reset();messageText=@"1: \"regex-must-not-run\"";Endpoint(nil);CHECK(originalArguments!=nil);
    Reset();messageFields=@{@1:Values(@"id")};commandText=@"serialized_share_entity: \"one\" serialized_share_entity: \"two\"";Endpoint(nil);URL(@"https://youtube.com/watch?v=id");CHECK([lastSerialized isEqual:@"one"]);
    Reset();popoverEnabled=YES;messageFields=@{@1:Values(@"id")};Endpoint(view);URL(@"https://youtube.com/watch?v=id");CHECK(lastActivity.popoverPresentationController.sourceView==view);CHECK(CGRectEqualToRect(lastActivity.popoverPresentationController.sourceRect,convertedRect));CHECK(CGRectEqualToRect(conversionInput,view.bounds)&&conversionTarget==top.view&&screenReads==0);CHECK([events isEqual:@[@"activity",@"top",@"convert",@"present"]]);
    Reset();popoverEnabled=YES;messageFields=@{@1:Values(@"id")};Endpoint(nil);URL(@"https://youtube.com/watch?v=id");CHECK(lastActivity.popoverPresentationController.sourceView==top.view);CHECK(CGRectEqualToRect(lastActivity.popoverPresentationController.sourceRect,CGRectMake(320.5,927,0,0)));CHECK(screenReads==2&&conversionTarget==nil);
    Reset();messageFields=@{@1:Values(@"id")};Endpoint(view);URL(@"https://youtube.com/watch?v=id");CHECK(conversionTarget==nil&&screenReads==0);
    ShareContext *context=[ShareContext new];ShareViewContext *viewContext=[ShareViewContext new];viewContext.fromView=view;context.value=viewContext;
    Reset();popoverEnabled=YES;messageFields=@{@1:Values(@"id")};[[ELMPBShowActionSheetCommand new]executeWithCommandContext:context handler:sender];URL(@"https://youtube.com/watch?v=id");CHECK(contextReads==2&&lastActivity.popoverPresentationController.sourceView==view);
    Reset();context.value=(id)[NSObject new];popoverEnabled=YES;messageFields=@{@1:Values(@"id")};[[ELMPBShowActionSheetCommand new]executeWithCommandContext:context handler:nil];URL(@"https://youtube.com/watch?v=id");CHECK(contextReads==1&&lastActivity.popoverPresentationController.sourceView==top.view);
    Reset();commandText=@"no match";[[ELMPBShowActionSheetCommand new]executeWithCommandContext:context handler:sender];CHECK([originalArguments isEqual:@[context,sender]]&&contextReads==0);
    Reset();deserialized=nil;[[ELMPBShowActionSheetCommand new]executeWithCommandContext:context handler:sender];CHECK([originalArguments isEqual:@[context,sender]]&&contextReads==1);
    Reset();enabled=NO;Endpoint(nil);enabled=YES;messageFields=@{@1:Values(@"live")};Endpoint(nil);CHECK(defaultsAllocations==2&&defaultsReads==2&&presentCalls==1);
    Reset();messageFields=@{@1:Values(@"id")};top=nil;Endpoint(nil);CHECK(lastActivity!=nil&&presentCalls==0&&originalArguments==nil);
    Reset();messageFields=@{@8:Values(@"clip-data")};const unsigned char invalid[]={0xff};clipFields=@{@1:@[Field([NSData dataWithBytes:invalid length:1])]};Endpoint(nil);URL(@"https://youtube.com/clip/(null)");
    Reset();messageFields=@{@8:Values(@"clip-data"),@3:Values(@"channel")};clipFields=@{@1:@[Field([NSData data]),Field([NSData data])]};Endpoint(nil);URL(@"https://youtube.com/channel/channel");
    Reset();commandText=nil;BOOL threw=NO;@try{Endpoint(nil);}@catch(NSException *exception){threw=[exception.name isEqual:NSInvalidArgumentException];}CHECK(threw&&originalArguments==nil);
    Reset();explicitCount=0;messageText=nil;threw=NO;@try{Endpoint(nil);}@catch(NSException *exception){threw=[exception.name isEqual:NSInvalidArgumentException];}CHECK(threw&&originalArguments==nil);
    NSLog(@"NativeShare: %lu actual Logos runtime checks passed",(unsigned long)checks);
}return 0;}
