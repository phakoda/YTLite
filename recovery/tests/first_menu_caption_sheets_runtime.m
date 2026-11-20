#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Subtitles/SRTParser.h"
#undef dispatch_async
#undef NSClassFromString
#undef objc_getClass
static NSUInteger checks,failures,actionLookups,parseCalls,resultCalls,hideCalls,messageCalls;
static BOOL watching;
static NSMutableArray *trace;
static void (^onActionLookup)(void);
static void (^parserCompletion)(id,NSError *);
static NSDictionary *parserArguments;
static id forwardedResult,pastedValue,messageReceiver,hideReceiver;
static NSString *messageText;
static BOOL messageSuccess;
static UIImage *captionIcon;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static id Box(id o){return o?:NSNull.null;}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
void FirstCaptionDispatch(dispatch_queue_t queue,dispatch_block_t block){(void)queue;(void)block;Check(NO,@"sheet fixture must intercept sharing before dispatch");}
Class FirstCaptionStringLookup(NSString *name){if([name isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"action.class");if(onActionLookup)onActionLookup();}if([name isEqual:@"YTDefaultSheetController"])Event(@"sheet.class");return NSClassFromString(name);}
Class FirstCaptionClassLookup(const char *name){if(!strcmp(name,"YTActionSheetAction")){Event(@"cached.action.class");if(onActionLookup)onActionLookup();}return objc_getClass(name);}
@interface FlowNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) BOOL noModern,noLegacy;
@property(nonatomic,strong) NSString *idObject;
@property(nonatomic,copy) void (^onURL)(void);
@end
@implementation FlowNode
- (void)event:(NSString *)key{Event([NSString stringWithFormat:@"%@.%@",self.tag,key]);}
- (BOOL)respondsToSelector:(SEL)sel{if(sel==@selector(playerResponse)){[self event:@"supportsModern"];return !self.noModern;}if(sel==@selector(contentPlayerResponse)){[self event:@"supportsLegacy"];return !self.noLegacy;}return [super respondsToSelector:sel];}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"legacy"];return [super contentPlayerResponse];}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (NSArray *)availableCaptionTracks{[self event:@"tracks"];return [super availableCaptionTracks];}
- (NSString *)videoID{[self event:@"id"];return self.idObject?:[super videoID];}
- (id)URL{[self event:@"URL"];if(self.onURL)self.onURL();return [super URL];}
- (NSString *)languageCode{[self event:@"language"];return [super languageCode];}
@end
static FlowNode *Node(NSString *tag){FlowNode *n=[FlowNode new];n.tag=tag;return n;}
@interface FlowMenu : DownloadMenuHelper
@property(nonatomic,strong) NSArray *expectedTracks,*filteredTracks;
@property(nonatomic,strong) id sharedURL,sharedSource;
@property(nonatomic) NSUInteger shares;
@end
@implementation FlowMenu
- (NSArray *)captionsForDownloading:(NSArray *)tracks{Event(@"filter");Check(tracks==self.expectedTracks,@"original track array passed to filter");return self.filteredTracks;}
- (NSString *)titleForCaption:(id)caption{Event(@"title");return [caption displayName];}
- (void)shareSRT:(NSURL *)url sourceView:(UIView *)source{Event(@"share");++self.shares;self.sharedURL=Box(url);self.sharedSource=source;}
@end
@implementation SRTParser (FlowConstruction)
+ (instancetype)new{Event(@"parser.new");return [super new];}
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"parser.alloc");return [super allocWithZone:zone];}
- (instancetype)init{Event(@"parser.init");return [super init];}
@end
@implementation ToastView (FlowConstruction)
+ (instancetype)new{Event(@"toast.new");return [super new];}
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"toast.alloc");return [super allocWithZone:zone];}
@end
@interface FlowError : NSError @end
@implementation FlowError
- (NSString *)localizedDescription{Event(@"error.description");return @"Parse failed";}
@end
static IMP originalXML,originalTranscript,originalToastInit,originalToastShow,originalMessage,originalHide,originalBundle,originalImage,originalAction,originalSheet,originalPaste;
static void ParseXML(id self,SEL sel,id url,id language,id videoID,void(^completion)(id,NSError *)){(void)self;(void)sel;++parseCalls;Event(@"parse.xml");parserArguments=@{@"URL":Box(url),@"language":Box(language),@"id":Box(videoID)};parserCompletion=[completion copy];}
static void ParseTranscript(id self,SEL sel,id url,void(^completion)(id,NSError *)){(void)self;(void)sel;++parseCalls;Event(@"parse.transcript");parserArguments=@{@"URL":Box(url)};parserCompletion=[completion copy];}
static id ToastInit(id self,SEL sel){Event(@"toast.init");return ((id(*)(id,SEL))originalToastInit)(self,sel);}
static void ToastShow(id self,SEL sel,id text){Event(@"toast.show");((void(*)(id,SEL,id))originalToastShow)(self,sel,text);}
static void Message(id self,SEL sel,NSString *text,BOOL success){Event(@"message");++messageCalls;messageReceiver=self;messageText=text;messageSuccess=success;((void(*)(id,SEL,id,BOOL))originalMessage)(self,sel,text,success);}
static void Hide(id self,SEL sel){Event(@"hide");++hideCalls;hideReceiver=self;((void(*)(id,SEL))originalHide)(self,sel);}
static id Bundle(id cls,SEL sel){Event(@"bundle");return ((id(*)(id,SEL))originalBundle)(cls,sel);}
static id Image(id cls,SEL sel,NSString *name){(void)cls;(void)sel;Event(@"image");Equal(name,@"captions",@"caption action image");return captionIcon;}
static id Action(id cls,SEL sel,id title,id icon,long long style,id handler){Event(@"action");Check(icon==captionIcon&&style==0&&handler!=nil,@"action arguments");return ((id(*)(id,SEL,id,id,long long,id))originalAction)(cls,sel,title,icon,style,handler);}
static id Sheet(id cls,SEL sel,id message,id sub,id delegate,id parent){Event(@"sheet");Equal(message,@"SelectCaption",@"caption sheet message");Check(!sub&&!delegate&&!parent,@"nil sheet ancillary arguments");return ((id(*)(id,SEL,id,id,id,id))originalSheet)(cls,sel,message,sub,delegate,parent);}
static void Paste(id self,SEL sel,id text){Event(@"paste");pastedValue=Box(text);((void(*)(id,SEL,id))originalPaste)(self,sel,text);}
static void Begin(FlowMenu *h){watching=NO;[trace removeAllObjects];DownloadsLastSheet=nil;DownloadsLastToast=nil;parserCompletion=nil;parserArguments=nil;h.shares=0;h.sharedURL=h.sharedSource=nil;resultCalls=parseCalls=actionLookups=hideCalls=messageCalls=0;forwardedResult=pastedValue=messageReceiver=hideReceiver=nil;messageText=nil;messageSuccess=NO;watching=YES;}
static void Show(FlowMenu *h,NSUInteger mode,id player,id sender){if(mode==0)[h showTranscriptSheet:player withSender:sender];else if(mode==1)[h showCaptionsSheet:player withSender:sender];else[h getCaptionsUrlSheet:player sender:sender completion:^(NSURL *url){Event(@"result");++resultCalls;forwardedResult=Box(url);}];}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[[NSMutableArray alloc]init];captionIcon=[UIImage new];
    originalXML=method_setImplementation(class_getInstanceMethod(SRTParser.class,@selector(parseXMLFromURL:forLanguage:videoID:completion:)),(IMP)ParseXML);
    originalTranscript=method_setImplementation(class_getInstanceMethod(SRTParser.class,@selector(parseTranscriptFromURL:completion:)),(IMP)ParseTranscript);
    originalToastInit=method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(init)),(IMP)ToastInit);
    originalToastShow=method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(showToast:)),(IMP)ToastShow);
    originalMessage=method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(showMessageWithText:isSuccess:)),(IMP)Message);
    originalHide=method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(hide)),(IMP)Hide);
    originalBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    originalImage=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Image);
    originalAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),(IMP)Action);
    originalSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:)),(IMP)Sheet);
    originalPaste=method_setImplementation(class_getInstanceMethod(UIPasteboard.class,@selector(setString:)),(IMP)Paste);
    FlowMenu *h=[FlowMenu new];FlowNode *player=Node(@"player"),*response=Node(@"response"),*active=Node(@"active"),*track=Node(@"track"),*other=Node(@"other");id sender=[UIView new];
    player.playerResponse=response;player.contentPlayerResponse=response;player.activeVideo=active;response.videoID=@"captured-id";
    track.displayName=@"Before";other.displayName=@"Other";active.availableCaptionTracks=@[track,other];h.expectedTracks=active.availableCaptionTracks;h.filteredTracks=@[track];
    NSURL *oldURL=[NSURL fileURLWithPath:@"/fixture/old.xml"],*newURL=[NSURL fileURLWithPath:@"/fixture/new.xml"],*resultURL=[NSURL fileURLWithPath:@"/fixture/result.srt"];
    NSError *error=[FlowError errorWithDomain:@"fixture" code:1 userInfo:nil];
    for(NSUInteger mode=0;mode<3;++mode){
        track.URL=oldURL;track.languageCode=@"old";response.videoID=@"captured-id";track.displayName=@"Before";__weak FlowNode *weakTrack=track;onActionLookup=^{weakTrack.displayName=@"AfterLookup";};
        Begin(h);Show(h,mode,player,sender);watching=NO;
        Check(DownloadsLastSheet.actions.count==(mode==0?2:1),@"transcript uses all tracks; caption paths use filtered tracks");Check(actionLookups==DownloadsLastSheet.actions.count,@"uncached string lookup for each caption action");
        Equal(DownloadsLastSheet.actions.firstObject.title,@"AfterLookup",@"class lookup before title helper");Check(DownloadsLastSheet.source==sender,@"sender assigned to sheet");
        Check([trace containsObject:@"filter"]==(mode!=0),@"only caption paths filter tracks");Check([trace containsObject:@"response.id"]==(mode!=0),@"transcript does not query video ID");Check(parseCalls==0&&DownloadsLastToast==nil,@"parser and toast deferred until selection");onActionLookup=nil;
        // Source captures the ID object, while URL/language are read at action time.
        track.URL=newURL;track.onURL=^{weakTrack.languageCode=@"changed-language";};response.videoID=@"later-id";
        [trace removeAllObjects];watching=YES;DownloadsLastSheet.actions.firstObject.handler();watching=NO;track.onURL=nil;
        Equal(trace,mode==0?(@[@"toast.alloc",@"toast.init",@"bundle",@"toast.show",@"parser.alloc",@"parser.init",@"track.URL",@"parse.transcript"]):(@[@"toast.alloc",@"toast.init",@"bundle",@"toast.show",@"parser.alloc",@"parser.init",@"track.URL",@"track.language",@"parse.xml"]),@"action constructor and parser argument order");
        Check(parseCalls==1&&parserCompletion!=nil,@"one deferred parser callback");Equal(parserArguments[@"URL"],newURL,@"action reads current track URL");if(mode){Equal(parserArguments[@"id"],@"captured-id",@"video ID captured when sheet is built");Equal(parserArguments[@"language"],@"changed-language",@"language read after URL getter");}
        ToastView *toast=DownloadsLastToast;Equal(toast.text,mode==0?@"ParsingTranscript":@"ParsingCaptions",@"parsing toast key");
        for(NSUInteger hasValue=0;hasValue<2;++hasValue)for(NSUInteger hasError=0;hasError<2;++hasError){
            id value=hasValue?(mode==0?(id)@"Transcript":resultURL):nil;h.shares=hideCalls=messageCalls=resultCalls=0;pastedValue=forwardedResult=nil;messageReceiver=hideReceiver=nil;[trace removeAllObjects];watching=YES;
            parserCompletion(value,hasError?error:nil);watching=NO;
            BOOL success=mode==2?hasValue:!hasError;
            if(!success){Check(messageCalls==1&&messageReceiver==toast&&!messageSuccess,@"failure updates captured toast");Equal(messageText,hasError?@"Parse failed":@"Error. Parser didn't returned any links",@"failure diagnostic");Check(!hideCalls&&!h.shares&&!resultCalls&&pastedValue==nil,@"failure has no success side effects");}
            else if(mode==0){Check(messageCalls==1&&messageReceiver==toast&&messageSuccess,@"transcript success updates same toast");Equal(messageText,@"Copied",@"transcript copied label");Equal(pastedValue,Box(value),@"transcript forwards even nil text to pasteboard");Check(hideCalls==0,@"transcript success does not hide toast");Equal(trace,(@[@"paste",@"bundle",@"message"]),@"copy before success localization and toast");}
            else if(mode==1){Check(hideCalls==1&&hideReceiver==toast&&h.shares==1,@"caption success hides then shares");Equal(h.sharedURL,Box(value),@"caption share forwards nil URL without an invented guard");Check(h.sharedSource==sender,@"caption share source identity");Equal(trace,(@[@"hide",@"share"]),@"hide precedes share");}
            else{Check(hideCalls==1&&hideReceiver==toast&&resultCalls==1,@"URL success hides then resumes");Check(forwardedResult==value,@"result URL identity");Check(messageCalls==0,@"URL result takes precedence over simultaneous error");Equal(trace,(@[@"hide",@"result"]),@"hide precedes URL completion");}
        }
        // Missing response distinguishes silent return from a nil completion.
        player.playerResponse=nil;Begin(h);Show(h,mode,player,sender);watching=NO;if(mode){Check(DownloadsLastSheet==nil,@"missing response does not build caption sheet");Check(resultCalls==(mode==2?1:0),@"only URL-selection path completes nil for absent response");if(mode==2)Check(forwardedResult==NSNull.null,@"absent response result nil");}else Check(DownloadsLastSheet.actions.count==2,@"transcript independent of player response");player.playerResponse=response;
        player.noModern=YES;Begin(h);Show(h,mode,player,sender);watching=NO;Check(DownloadsLastSheet!=nil,@"legacy response path works");if(mode)Check([trace containsObject:@"player.legacy"],@"legacy response getter selected");player.noModern=NO;
        h.filteredTracks=nil;active.availableCaptionTracks=@[];h.expectedTracks=active.availableCaptionTracks;Begin(h);Show(h,mode,player,sender);watching=NO;Check(DownloadsLastSheet!=nil&&DownloadsLastSheet.actions.count==0&&resultCalls==0,@"empty track selection still presents sheet without completion");active.availableCaptionTracks=@[track,other];h.expectedTracks=active.availableCaptionTracks;h.filteredTracks=@[track];
    }
    parserCompletion=nil;onActionLookup=nil;
    method_setImplementation(class_getInstanceMethod(SRTParser.class,@selector(parseXMLFromURL:forLanguage:videoID:completion:)),originalXML);
    method_setImplementation(class_getInstanceMethod(SRTParser.class,@selector(parseTranscriptFromURL:completion:)),originalTranscript);
    method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(init)),originalToastInit);
    method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(showToast:)),originalToastShow);
    method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(showMessageWithText:isSuccess:)),originalMessage);
    method_setImplementation(class_getInstanceMethod(ToastView.class,@selector(hide)),originalHide);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),originalBundle);
    method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),originalImage);
    method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),originalAction);
    method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:)),originalSheet);
    method_setImplementation(class_getInstanceMethod(UIPasteboard.class,@selector(setString:)),originalPaste);
    printf("%s First_menu_caption_sheets: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
