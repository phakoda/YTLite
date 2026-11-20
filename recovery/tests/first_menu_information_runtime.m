#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#import <math.h>
#import <limits.h>
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups,toastLookups,toastAllocs,toastInits,toastNews,messages,transcripts;
static BOOL watching,sheetClassNil,actionClassNil,toastClassNil;
static NSMutableArray *trace;
static id pasted,transcriptPlayer,transcriptSender;
static NSString *toastMessage;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
Class FirstInformationClassLookup(const char *name){
    if(!strcmp(name,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if(!strcmp(name,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    if(!strcmp(name,"YTToastController")){++toastLookups;Event(@"class.toast");return toastClassNil?Nil:NSClassFromString(@"YTToastController");}
    return objc_getClass(name);
}
Class FirstInformationStringLookup(NSString *name){
    if([name isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if([name isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    if([name isEqual:@"YTToastController"]){++toastLookups;Event(@"string.toast");return toastClassNil?Nil:NSClassFromString(name);}
    return NSClassFromString(name);
}
@interface InformationString : NSMutableString
@property(nonatomic,strong) NSMutableString *backing;
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,copy) void (^onLength)(void);
@end
@implementation InformationString
- (NSUInteger)length{Event([self.tag stringByAppendingString:@".length"]);if(self.onLength)self.onLength();return self.backing.length;}
- (unichar)characterAtIndex:(NSUInteger)i{return [self.backing characterAtIndex:i];}
- (void)replaceCharactersInRange:(NSRange)r withString:(NSString *)s{[self.backing replaceCharactersInRange:r withString:s];}
- (NSString *)substringToIndex:(NSUInteger)i{Event([self.tag stringByAppendingString:@".substring"]);return [self.backing substringToIndex:i];}
@end
static InformationString *String(NSString *tag,NSString *value){InformationString *s=[InformationString new];s.tag=tag;s.backing=[value mutableCopy];return s;}
@interface InformationNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSArray *dataSequence;
@property(nonatomic) NSUInteger dataReads;
@property(nonatomic) BOOL noModern,noLegacy;
@property(nonatomic,strong) NSString *titleObject,*authorObject,*descriptionObject;
@property(nonatomic,copy) void (^onDescriptionFlag)(void),(^onTime)(void);
@end
@implementation InformationNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (BOOL)respondsToSelector:(SEL)s{if(s==@selector(playerResponse)){[self event:@"supportsModern"];return !self.noModern;}if(s==@selector(contentPlayerResponse)){[self event:@"supportsLegacy"];return !self.noLegacy;}return [super respondsToSelector:s];}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"legacy"];return [super contentPlayerResponse];}
- (id)playerData{[self event:@"data"];return self.dataSequence?self.dataSequence[MIN(self.dataReads++,self.dataSequence.count-1)]:[super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (NSString *)title{[self event:@"title"];return self.titleObject;}
- (NSString *)author{[self event:@"author"];return self.authorObject;}
- (NSString *)shortDescription{[self event:@"description"];return self.descriptionObject;}
- (BOOL)hasShortDescription{[self event:@"hasDescription"];if(self.onDescriptionFlag)self.onDescriptionFlag();return [super hasShortDescription];}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (NSArray *)availableCaptionTracks{[self event:@"tracks"];return [super availableCaptionTracks];}
- (double)contentVideoMediaTime{[self event:@"time"];if(self.onTime)self.onTime();return [super contentVideoMediaTime];}
- (NSString *)contentVideoID{[self event:@"videoID"];return [super contentVideoID];}
@end
static InformationNode *Node(NSString *name){InformationNode *n=[InformationNode new];n.tag=name;return n;}
@interface InformationCount : NSArray
@property(nonatomic) NSUInteger reportedCount;
@end
@implementation InformationCount
- (NSUInteger)count{Event(@"captions.count");return self.reportedCount;}
- (id)objectAtIndex:(NSUInteger)i{(void)i;Check(NO,@"caption elements must not be read");return nil;}
@end
@interface InformationMenu : DownloadMenuHelper @end
@implementation InformationMenu
- (BOOL)hasCaptions:(id)player{(void)player;Check(NO,@"information sheet must not use download-caption filtering");return NO;}
- (void)showTranscriptSheet:(id)player withSender:(id)sender{Event(@"transcript");++transcripts;transcriptPlayer=player;transcriptSender=sender;}
@end
@interface InformationBundle : NSBundle @end
@implementation InformationBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table{Event([@"localize." stringByAppendingString:key]);Check(value==nil&&table==nil,@"localization ancillary arguments");return key;}
@end
@interface YTToastController : NSObject @end
@implementation YTToastController (InformationConstruction)
+ (instancetype)allocWithZone:(NSZone *)zone{++toastAllocs;Event(@"toast.alloc");return [super allocWithZone:zone];}
+ (instancetype)new{++toastNews;Event(@"toast.new");return [super new];}
- (instancetype)init{++toastInits;Event(@"toast.init");return [super init];}
@end
static InformationBundle *bundle;
static IMP oldBundle,oldIcon,oldSheet,oldAction,oldSource,oldPresent,oldPaste,oldGeneralPaste,oldMessage;
static id Bundle(id cls,SEL sel){(void)cls;(void)sel;Event(@"bundle");return bundle;}
static id Icon(id cls,SEL sel,NSString *name){(void)cls;(void)sel;Event(@"icon");if(watching)Equal(name,@"copy",@"information action icon");UIImage *image=[UIImage new];image.name=name;return image;}
static id Sheet(id cls,SEL sel,id parent){Event(@"sheet");if(watching)Check(parent==nil,@"nil sheet parent");return ((id(*)(id,SEL,id))oldSheet)(cls,sel,parent);}
static id Action(id cls,SEL sel,id title,id icon,long long style,id handler){Event([@"action." stringByAppendingString:title]);if(watching)Check(style==0&&handler!=nil,@"action style and callback");return ((id(*)(id,SEL,id,id,long long,id))oldAction)(cls,sel,title,icon,style,handler);}
static void Source(id self,SEL sel,id sender){Event(@"sheet.source");((void(*)(id,SEL,id))oldSource)(self,sel,sender);}
static void Present(id self,SEL sel,id root,BOOL animated,id completion){Event(@"sheet.present");if(watching)Check(root==[ToastView toastWindow].rootViewController&&animated&&completion==nil,@"toast-root sheet presentation");((void(*)(id,SEL,id,BOOL,id))oldPresent)(self,sel,root,animated,completion);}
static id GeneralPaste(id cls,SEL sel){Event(@"pasteboard");return ((id(*)(id,SEL))oldGeneralPaste)(cls,sel);}
static void Paste(id self,SEL sel,id value){
    Event(@"paste");pasted=value;
    // The shim setter copies strings internally; those reads are boundary internals.
    BOOL logging=watching;watching=NO;((void(*)(id,SEL,id))oldPaste)(self,sel,value);watching=logging;
}
static void Message(id self,SEL sel,id text){(void)self;(void)sel;Event(@"toast.message");++messages;toastMessage=text;}
static void Begin(InformationNode *response){watching=NO;[trace removeAllObjects];DownloadsLastSheet=nil;response.dataReads=0;pasted=nil;toastMessage=nil;messages=toastAllocs=toastInits=toastNews=transcripts=0;transcriptPlayer=transcriptSender=nil;watching=YES;}
static BOOL Show(DownloadMenuHelper *helper,id player,id source){BOOL threw=NO;@try{[helper showInformationSheet:player withSender:source];}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];if(!threw)Check(NO,@"unexpected exception");}return threw;}
static YTActionSheetAction *Find(NSArray *actions,NSString *key){for(YTActionSheetAction *a in actions)if([a.title isEqual:key])return a;return nil;}
static void Invoke(YTActionSheetAction *action){Check(action!=nil&&action.handler!=nil,@"requested action exists");if(action.handler)action.handler();}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];bundle=[InformationBundle new];
    oldBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    oldIcon=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Icon);
    oldSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),(IMP)Sheet);
    oldAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),(IMP)Action);
    oldSource=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),(IMP)Source);
    oldPresent=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),(IMP)Present);
    oldGeneralPaste=method_setImplementation(class_getClassMethod(UIPasteboard.class,@selector(generalPasteboard)),(IMP)GeneralPaste);
    oldPaste=method_setImplementation(class_getInstanceMethod(UIPasteboard.class,@selector(setString:)),(IMP)Paste);
    oldMessage=method_setImplementation(class_getInstanceMethod(YTToastController.class,@selector(showMessage:)),(IMP)Message);
    InformationNode *player=Node(@"player"),*response=Node(@"response"),*active=Node(@"active");player.playerResponse=response;player.contentPlayerResponse=response;player.activeVideo=active;
    NSMutableArray *dataNodes=[NSMutableArray new],*detailsNodes=[NSMutableArray new];
    for(NSUInteger i=0;i<4;++i){InformationNode *data=Node([NSString stringWithFormat:@"data%lu",(unsigned long)i]),*details=Node([NSString stringWithFormat:@"details%lu",(unsigned long)i]);data.videoDetails=details;[dataNodes addObject:data];[detailsNodes addObject:details];}response.dataSequence=dataNodes;
    InformationNode *titleDetails=detailsNodes[0],*authorDetails=detailsNodes[1],*descriptionDetails=detailsNodes[2],*flagDetails=detailsNodes[3];
    InformationString *title=String(@"title",@"Title"),*author=String(@"author",@"Author"),*description=String(@"description",@"Description");titleDetails.titleObject=title;authorDetails.authorObject=author;descriptionDetails.descriptionObject=description;flagDetails.hasShortDescription=YES;
    InformationCount *captions=[InformationCount new];captions.reportedCount=1;active.availableCaptionTracks=captions;
    InformationMenu *helper=[InformationMenu new];UIView *source=[UIView new];
    player.noModern=player.noLegacy=YES;Begin(response);Check(!Show(helper,player,source),@"unsupported player silent return");watching=NO;Equal(trace,(@[@"player.supportsModern",@"player.supportsLegacy"]),@"unsupported response selection");Check(sheetLookups==0&&actionLookups==0,@"unsupported player skips factories");player.noModern=player.noLegacy=NO;
    player.playerResponse=nil;Begin(response);Check(!Show(helper,player,source),@"nil modern response returns");watching=NO;Equal(trace,(@[@"player.supportsModern",@"player.response"]),@"nil modern response does not fall back");player.playerResponse=response;
    sheetClassNil=actionClassNil=YES;
    for(NSUInteger attempt=0;attempt<2;++attempt){NSUInteger sl=sheetLookups,al=actionLookups;Begin(response);Check(!Show(helper,player,source),@"nil classes preserve argument evaluation");watching=NO;Check(sheetLookups==sl+1&&actionLookups==al+5,@"nil classes retried at each use");Check(DownloadsLastSheet==nil,@"nil sheet result not presented");}
    sheetClassNil=NO;Begin(response);Check(Show(helper,player,source),@"nil action preserves nonnil collection exception");watching=NO;
    actionClassNil=NO;Begin(response);Check(!Show(helper,player,source),@"valid information sheet");watching=NO;
    NSArray *prefix=@[@"player.supportsModern",@"player.response",@"response.data",@"data0.details",@"details0.title",@"response.data",@"data1.details",@"details1.author",@"response.data",@"data2.details",@"details2.description",@"response.data",@"data3.details",@"details3.hasDescription",@"author.length",@"title.length",@"sheet",@"class.action",@"bundle",@"localize.CopyChannelName"];
    Check(trace.count>=prefix.count,@"full metadata trace available");if(trace.count>=prefix.count)Equal([trace subarrayWithRange:NSMakeRange(0,prefix.count)],prefix,@"independent metadata reads, truncation order and early action class lookup");
    Equal([DownloadsLastSheet.actions valueForKey:@"title"],(@[@"CopyChannelName",@"CopyTitle",@"CopyDescription",@"CopyTimestampedLink",@"CopyTranscript"]),@"original localization keys and action order");Check(DownloadsLastSheet.source==source,@"sheet sender identity");
    Check([trace indexOfObject:@"action.CopyTimestampedLink"]<[trace indexOfObject:@"player.active"],@"caption availability read after timestamp action creation");
    NSArray *actions=[DownloadsLastSheet.actions copy];
    // Original unshortened metadata objects remain live rather than copied.
    [title.backing setString:@"Changed title"];[author.backing setString:@"Changed author"];[description.backing setString:@"Changed description"];
    toastClassNil=YES;
    for(NSUInteger i=0;i<2;++i){NSUInteger before=toastLookups;Begin(response);Invoke(Find(actions,@"CopyChannelName"));watching=NO;Check(pasted==author&&messages==0&&toastAllocs==0&&toastLookups==before+1,@"copy succeeds while missing toast class is retried");Equal(trace,(@[@"pasteboard",@"paste",@"class.toast",@"bundle",@"localize.Copied"]),@"paste precedes missing-toast class and localization");}
    toastClassNil=NO;Begin(response);Invoke(Find(actions,@"CopyTitle"));watching=NO;Check(pasted==title&&toastAllocs==1&&!toastInits&&!toastNews&&messages==1,@"copy feedback allocates without init");Equal(toastMessage,@"Copied",@"copy feedback key");Equal(trace,(@[@"pasteboard",@"paste",@"class.toast",@"toast.alloc",@"bundle",@"localize.Copied",@"toast.message"]),@"copy and feedback call order");
    NSUInteger tl=toastLookups;Begin(response);Invoke(Find(actions,@"CopyDescription"));watching=NO;Check(pasted==description&&toastLookups==tl&&toastAllocs==1&&messages==1,@"description identity and cached toast class");Check(!toastInits&&!toastNews,@"cached class still allocates without initialization");
    Begin(response);Invoke(Find(actions,@"CopyTranscript"));watching=NO;Check(transcripts==1&&transcriptPlayer==player&&transcriptSender==source,@"transcript callback forwards captured player and sender");Equal(trace,(@[@"transcript"]),@"transcript callback does not copy or show legacy feedback");
    // Metadata shortening happens after the fourth metadata read and in author/title order.
    NSArray *lengths=@[@0,@29,@30,@31,@199,@200,@201,@240];
    for(NSNumber *authorLength in lengths)for(NSNumber *titleLength in lengths){
        NSUInteger na=authorLength.unsignedIntegerValue,nt=titleLength.unsignedIntegerValue;
        [author.backing setString:[@"a" stringByPaddingToLength:na withString:@"a" startingAtIndex:0]];[title.backing setString:[@"t" stringByPaddingToLength:nt withString:@"t" startingAtIndex:0]];
        Begin(response);Check(!Show(helper,player,source),@"metadata boundary sheet");watching=NO;NSArray *current=DownloadsLastSheet.actions;
        Check([trace indexOfObject:@"details3.hasDescription"]<[trace indexOfObject:@"author.length"]&&[trace indexOfObject:@"author.length"]<[trace indexOfObject:@"title.length"],@"shortening after metadata, author before title");
        Invoke(Find(current,@"CopyChannelName"));Equal(pasted,na>30?[[author.backing substringToIndex:30] stringByAppendingString:@"…"]:author.backing,@"author shortening boundary");
        Invoke(Find(current,@"CopyTitle"));Equal(pasted,nt>200?[[title.backing substringToIndex:200] stringByAppendingString:@"…"]:title.backing,@"title shortening boundary");
    }
    [author.backing setString:@"Initial"];[title.backing setString:@"Initial"];
    flagDetails.onDescriptionFlag=^{[author.backing setString:@"After flag author"];[title.backing setString:@"After flag title"];};
    Begin(response);Check(!Show(helper,player,source),@"metadata mutation sheet");watching=NO;actions=DownloadsLastSheet.actions;flagDetails.onDescriptionFlag=nil;Invoke(Find(actions,@"CopyChannelName"));Equal(pasted,@"After flag author",@"author getter value retained through later metadata reads");Invoke(Find(actions,@"CopyTitle"));Equal(pasted,@"After flag title",@"title getter value retained through later metadata reads");
    // Truncation uses UTF-16 indices, including a split surrogate at a boundary.
    [author.backing setString:[[@"a" stringByPaddingToLength:29 withString:@"a" startingAtIndex:0] stringByAppendingString:@"😀"]];
    Begin(response);Check(!Show(helper,player,source),@"UTF16 boundary sheet");watching=NO;Invoke(Find(DownloadsLastSheet.actions,@"CopyChannelName"));Check([pasted length]==31&&[pasted characterAtIndex:29]==0xd83d&&[pasted characterAtIndex:30]==0x2026,@"original UTF16 split and ellipsis preserved");
    NSUInteger counts[]={0,1,2,1ULL<<32,NSUIntegerMax};
    for(NSUInteger c=0;c<5;++c)for(NSUInteger hasDescription=0;hasDescription<2;++hasDescription){captions.reportedCount=counts[c];flagDetails.hasShortDescription=hasDescription;
        Begin(response);Check(!Show(helper,player,source),@"caption count and description sheet");watching=NO;
        Check((Find(DownloadsLastSheet.actions,@"CopyTranscript")!=nil)==(counts[c]!=0),@"full-width raw caption count decides transcript availability");Check((Find(DownloadsLastSheet.actions,@"CopyDescription")!=nil)==(hasDescription!=0),@"description flag controls description action");}
    DownloadsNode *automatic=[DownloadsNode new];automatic.VSSID=@"a.en";active.availableCaptionTracks=@[automatic];DownloadsPreferences[@"addAutoCaps"]=@NO;
    Begin(response);Check(!Show(helper,player,source),@"automatic caption sheet");watching=NO;Check(Find(DownloadsLastSheet.actions,@"CopyTranscript")!=nil,@"automatic captions offer transcript independent of download preference");
    titleDetails.titleObject=nil;authorDetails.authorObject=nil;descriptionDetails.descriptionObject=nil;flagDetails.hasShortDescription=YES;active.availableCaptionTracks=nil;
    Begin(response);Check(!Show(helper,player,nil),@"nil metadata sheet");watching=NO;actions=DownloadsLastSheet.actions;
    for(NSString *key in @[@"CopyChannelName",@"CopyTitle",@"CopyDescription"]){pasted=@"sentinel";Invoke(Find(actions,key));Check(pasted==nil,@"nil metadata forwarded to pasteboard");}
    // Callback reads media time and then the current ID; rounding matches FCVTAS.
    YTActionSheetAction *timestamp=Find(actions,@"CopyTimestampedLink");__weak InformationNode *weakPlayer=player;player.onTime=^{weakPlayer.contentVideoID=@"after-time";};
    double times[]={0,0.49,0.5,1.5,-0.49,-0.5,-1.5,2147483648.5,0x1p63,-0x1p63,INFINITY,-INFINITY,NAN};
    long expected[]={0,0,1,2,0,-1,-2,2147483649L,LONG_MAX,LONG_MIN,LONG_MAX,LONG_MIN,0};
    for(NSUInteger i=0;i<sizeof(times)/sizeof(*times);++i){player.contentVideoID=@"before-time";player.contentVideoMediaTime=times[i];Begin(response);Invoke(timestamp);watching=NO;
        Equal(pasted,[NSString stringWithFormat:@"https://www.youtube.com/watch?v=after-time&t=%lds",expected[i]],@"timestamp rounding and live ID");Check([trace indexOfObject:@"player.time"]<[trace indexOfObject:@"player.videoID"]&&[trace indexOfObject:@"player.videoID"]<[trace indexOfObject:@"pasteboard"],@"timestamp argument evaluation before paste");}
    player.onTime=nil;player.contentVideoID=nil;player.contentVideoMediaTime=3;Begin(response);Invoke(timestamp);watching=NO;Equal(pasted,@"https://www.youtube.com/watch?v=(null)&t=3s",@"nil live ID is formatted without guard");
    player.noModern=YES;Begin(response);Check(!Show(helper,player,source),@"legacy response sheet");watching=NO;Check([trace containsObject:@"player.legacy"],@"legacy response getter");player.noModern=NO;
    NSUInteger sl=sheetLookups,al=actionLookups;Begin(response);Check(!Show(helper,player,source),@"repeat information sheet");watching=NO;Check(sl==sheetLookups&&al==actionLookups,@"sheet and action caches persist");
    response.dataReads=0;[helper showImagesSheet:player withSender:source];Check(sl==sheetLookups&&al==actionLookups,@"information and thumbnail menus share successful caches");
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),oldBundle);
    method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),oldIcon);
    method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),oldSheet);
    method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),oldAction);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),oldSource);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),oldPresent);
    method_setImplementation(class_getClassMethod(UIPasteboard.class,@selector(generalPasteboard)),oldGeneralPaste);
    method_setImplementation(class_getInstanceMethod(UIPasteboard.class,@selector(setString:)),oldPaste);
    method_setImplementation(class_getInstanceMethod(YTToastController.class,@selector(showMessage:)),oldMessage);
    printf("%s First_menu_information: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
