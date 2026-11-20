#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups,toastLookups,toastAllocs,toastInits,controllerNews,pauses,plays,opens,urlCalls;
static BOOL watching,sheetClassNil,actionClassNil,toastClassNil,controllerInitNil,urlResultNil,appResultNil;
static NSMutableArray *trace;
static id factoryURL,assignedPlayer,openedReceiver;
static NSURL *convertedURL,*openedURL;
static NSString *urlText,*message;
static AVPlayer *videoResult;
static AVPlayerViewController *builtController;
static void (^presentationCompletion)(void),(^openCompletion)(BOOL),(^onApplication)(void),(^onURL)(void);
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
Class FirstExternalClassLookup(const char *name){
    if(!strcmp(name,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if(!strcmp(name,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    if(!strcmp(name,"YTToastController")){++toastLookups;Event(@"class.toast");return toastClassNil?Nil:NSClassFromString(@"YTToastController");}
    return objc_getClass(name);
}
Class FirstExternalStringLookup(NSString *name){
    if([name isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if([name isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    if([name isEqual:@"YTToastController"]){++toastLookups;Event(@"string.toast");return toastClassNil?Nil:NSClassFromString(name);}
    return NSClassFromString(name);
}
// Synthetic object returned through the playlist-URL boundary. Its description
// records exactly when format evaluation occurs; no URL is opened by this test.
@interface ExternalPlaylist : NSObject
@property(nonatomic,copy) NSString *text;
@end
@implementation ExternalPlaylist
- (NSString *)description{Event(@"playlist.describe");return self.text;}
@end
@interface ExternalNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@end
@implementation ExternalNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (id)videoData{[self event:@"data"];return [super videoData];}
- (id)playbackData{[self event:@"playback"];return [super playbackData];}
- (id)video{[self event:@"video"];return [super video];}
- (id)streamingData{[self event:@"streaming"];return [super streamingData];}
- (NSURL *)HLSMasterPlaylistURL{[self event:@"playlist"];return [super HLSMasterPlaylistURL];}
- (void)pause{[self event:@"pause"];++pauses;}
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion{[self event:@"present"];Check(animated&&completion!=nil,@"native player animated presentation with completion");self.presented=controller;presentationCompletion=[completion copy];}
@end
static ExternalNode *Node(NSString *name){ExternalNode *n=[ExternalNode new];n.tag=name;return n;}
@interface ExternalVideo : AVPlayer @end
@implementation ExternalVideo
- (void)play{Event(@"video.play");++plays;}
@end
@implementation AVPlayerViewController (ExternalConstruction)
+ (instancetype)new{++controllerNews;Event(@"controller.new");return [super new];}
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"controller.alloc");return [super allocWithZone:zone];}
- (instancetype)init{Event(@"controller.init");if(controllerInitNil)return nil;self=[super init];builtController=self;return self;}
@end
@interface ExternalApp : UIApplication @end
@implementation ExternalApp
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion{Event(@"app.open");++opens;openedReceiver=self;openedURL=url;Check(options!=nil&&options.count==0&&completion!=nil,@"empty options and nonnil completion");openCompletion=[completion copy];}
@end
@interface ExternalBundle : NSBundle @end
@implementation ExternalBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table{Event([@"localize." stringByAppendingString:key]);if(watching)Check(value==nil&&table==nil,@"localization ancillary arguments");return key;}
@end
@interface YTToastController : NSObject @end
@implementation YTToastController (ExternalConstruction)
+ (instancetype)allocWithZone:(NSZone *)zone{++toastAllocs;Event(@"toast.alloc");return [super allocWithZone:zone];}
- (instancetype)init{++toastInits;Event(@"toast.init");return [super init];}
@end
static ExternalBundle *lastBundle;
static ExternalApp *activeApp;
static IMP oldVideo,oldSetPlayer,oldApplication,oldURL,oldBundle,oldIcon,oldAsset,oldSheet,oldAction,oldPresent,oldMessage;
static id Video(id cls,SEL sel,id url){(void)cls;(void)sel;Event(@"video.factory");factoryURL=url;return videoResult;}
static void SetPlayer(id self,SEL sel,id player){Event(@"controller.player");assignedPlayer=player;((void(*)(id,SEL,id))oldSetPlayer)(self,sel,player);}
static id Application(id cls,SEL sel){(void)cls;(void)sel;Event(@"app.shared");id result=appResultNil?nil:activeApp;if(onApplication)onApplication();return result;}
static id URL(id cls,SEL sel,NSString *text){Event(@"URL.create");++urlCalls;urlText=text;if(onURL)onURL();convertedURL=urlResultNil?nil:((id(*)(id,SEL,id))oldURL)(cls,sel,text);return convertedURL;}
static id Bundle(id cls,SEL sel){(void)cls;(void)sel;Event(@"bundle");lastBundle=[ExternalBundle new];return lastBundle;}
static id Icon(id cls,SEL sel,NSString *name){(void)cls;(void)sel;Event([@"icon." stringByAppendingString:name]);UIImage *i=[UIImage new];i.name=name;return i;}
static id Asset(id cls,SEL sel,NSString *name,NSBundle *bundle,UITraitCollection *traits){(void)cls;(void)sel;Event([@"asset." stringByAppendingString:name]);Check(bundle==lastBundle&&traits==nil,@"asset uses separately retrieved bundle and nil traits");UIImage *i=[UIImage new];i.name=name;return i;}
static id Sheet(id cls,SEL sel,id parent){Event(@"sheet");if(watching)Check(parent==nil,@"nil sheet parent");return ((id(*)(id,SEL,id))oldSheet)(cls,sel,parent);}
static id Action(id cls,SEL sel,id title,id icon,long long style,id handler){Event([@"action." stringByAppendingString:title]);if(watching)Check(style==0&&handler!=nil,@"action style and callback");return ((id(*)(id,SEL,id,id,long long,id))oldAction)(cls,sel,title,icon,style,handler);}
static void Present(id self,SEL sel,id root,BOOL animated,id completion){Event(@"sheet.present");if(watching)Check(root==[ToastView toastWindow].rootViewController&&animated&&completion==nil,@"sheet presents from toast root");((void(*)(id,SEL,id,BOOL,id))oldPresent)(self,sel,root,animated,completion);}
static void Message(id self,SEL sel,id text){(void)self;(void)sel;Event(@"toast.message");message=text;}
static void Begin(void){watching=NO;[trace removeAllObjects];DownloadsLastSheet=nil;builtController=nil;factoryURL=assignedPlayer=openedReceiver=nil;convertedURL=openedURL=nil;urlText=message=nil;pauses=plays=opens=urlCalls=toastAllocs=toastInits=controllerNews=0;presentationCompletion=nil;openCompletion=nil;watching=YES;}
static BOOL Show(DownloadMenuHelper *h,id player,id sender){BOOL threw=NO;@try{[h showExtPlayerSheet:player withSender:sender];}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];if(!threw)Check(NO,@"unexpected exception");}return threw;}
static YTActionSheetAction *Find(NSArray *actions,NSString *key){for(YTActionSheetAction *a in actions)if([a.title isEqual:key])return a;return nil;}
static void Invoke(YTActionSheetAction *action){Check(action.handler!=nil,@"requested action exists");if(action.handler)action.handler();}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];ExternalApp *firstApp=[ExternalApp new],*secondApp=[ExternalApp new];activeApp=firstApp;
    oldVideo=method_setImplementation(class_getClassMethod(AVPlayer.class,@selector(playerWithURL:)),(IMP)Video);
    oldSetPlayer=method_setImplementation(class_getInstanceMethod(AVPlayerViewController.class,@selector(setPlayer:)),(IMP)SetPlayer);
    oldApplication=method_setImplementation(class_getClassMethod(UIApplication.class,@selector(sharedApplication)),(IMP)Application);
    oldURL=method_setImplementation(class_getClassMethod(NSURL.class,@selector(URLWithString:)),(IMP)URL);
    oldBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    oldIcon=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Icon);
    oldAsset=method_setImplementation(class_getClassMethod(UIImage.class,@selector(imageNamed:inBundle:compatibleWithTraitCollection:)),(IMP)Asset);
    oldSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),(IMP)Sheet);
    oldAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),(IMP)Action);
    oldPresent=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),(IMP)Present);
    oldMessage=method_setImplementation(class_getInstanceMethod(YTToastController.class,@selector(showMessage:)),(IMP)Message);
    ExternalNode *player=Node(@"player"),*active=Node(@"active"),*data=Node(@"data"),*playback=Node(@"playback"),*video=Node(@"video"),*stream=Node(@"stream");
    player.activeVideo=active;active.videoData=data;data.playbackData=playback;playback.video=video;video.streamingData=stream;ExternalPlaylist *playlist=[ExternalPlaylist new];playlist.text=@"https://fixture.invalid/playlist.m3u8?a=1&b=2";stream.HLSMasterPlaylistURL=(id)playlist;
    DownloadMenuHelper *helper=[DownloadMenuHelper new];UIView *source=[UIView new];
    sheetClassNil=actionClassNil=YES;
    for(NSUInteger i=0;i<2;++i){NSUInteger sl=sheetLookups,al=actionLookups;Begin();Check(!Show(helper,player,source),@"nil classes still evaluate actions");watching=NO;Check(sheetLookups==sl+1&&actionLookups==al+3,@"failed classes retry at each use");Check(DownloadsLastSheet==nil&&!opens&&!plays,@"nil classes have no player side effects");}
    sheetClassNil=NO;Begin();Check(Show(helper,player,source),@"nil action preserves collection exception");watching=NO;
    actionClassNil=NO;Begin();Check(!Show(helper,player,source),@"external-player sheet");watching=NO;
    NSArray *prefix=@[@"player.active",@"active.data",@"data.playback",@"playback.video",@"video.streaming",@"stream.playlist",@"sheet",@"class.action",@"bundle",@"localize.PlayInSystemPlayer",@"icon.player",@"action.PlayInSystemPlayer",@"bundle",@"localize.PlayInInfuse",@"bundle",@"asset.infuse",@"action.PlayInInfuse",@"bundle",@"localize.PlayInVLC",@"bundle",@"asset.vlc",@"action.PlayInVLC",@"sheet.present"];
    Equal(trace,prefix,@"playlist retrieval, class/localization order, separate asset bundles and action order");
    Check(DownloadsLastSheet.source==source&&!opens&&!pauses&&!plays,@"sheet sender and deferred actions");NSArray *actions=[DownloadsLastSheet.actions copy];
    Equal([actions valueForKey:@"title"],(@[@"PlayInSystemPlayer",@"PlayInInfuse",@"PlayInVLC"]),@"three original labels");Equal([actions valueForKeyPath:@"icon.name"],(@[@"player",@"infuse",@"vlc"]),@"three original icons");
    stream.HLSMasterPlaylistURL=nil; // Selection retains the original URL object.
    for(NSUInteger nilVideo=0;nilVideo<2;++nilVideo)for(NSUInteger nilController=0;nilController<2;++nilController){videoResult=nilVideo?nil:[ExternalVideo new];controllerInitNil=nilController;Begin();Invoke(Find(actions,@"PlayInSystemPlayer"));watching=NO;
        NSMutableArray *expected=[@[@"video.factory",@"controller.alloc",@"controller.init"] mutableCopy];if(!nilController)[expected addObject:@"controller.player"];[expected addObjectsFromArray:@[@"player.pause",@"player.present"]];Equal(trace,expected,@"system-player creation, assignment, pause and presentation order");
        Check(factoryURL==(id)playlist&&controllerNews==0,@"captured playlist and alloc/init construction");Check(pauses==1&&plays==0&&presentationCompletion!=nil,@"play waits for presentation completion");Check(player.presented==builtController,@"actual controller result forwarded");
        presentationCompletion();Check(plays==(nilVideo?0:1),@"completion plays returned AVPlayer");presentationCompletion();Check(plays==(nilVideo?0:2),@"completion preserves repeat invocation");}
    controllerInitNil=NO;videoResult=[ExternalVideo new];
    for(NSUInteger index=1;index<3;++index){NSString *prefixURL=index==1?@"infuse://x-callback-url/play?url=":@"vlc-x-callback://x-callback-url/stream?url=";
        for(NSString *text in @[@"https://fixture.invalid/a?x=1&y=2",@"https://fixture.invalid/a path/#part",@"https://fixture.invalid/é?q=%25"]){
            playlist.text=text;activeApp=firstApp;onApplication=^{playlist.text=@"changed-after-format";};onURL=^{activeApp=secondApp;};
            Begin();Invoke(actions[index]);watching=NO;onApplication=onURL=nil;
            Equal(trace,(@[@"playlist.describe",@"app.shared",@"URL.create",@"app.open"]),@"format before application lookup, then URL construction and open");Equal(urlText,[prefixURL stringByAppendingString:text],@"raw nested URL interpolated without invented query escaping");Check(opens==1&&openedReceiver==firstApp&&openedURL==convertedURL&&openCompletion!=nil,@"open uses captured application and converted URL identity");Check(pauses==0&&message==nil,@"opening waits for completion before feedback");
            openCompletion(YES);Check(pauses==1&&message==nil,@"successful external open pauses original player");
            // A failed completion uses the same class cache as information copying.
            toastClassNil=toastLookups==0;NSUInteger before=toastLookups;[trace removeAllObjects];watching=YES;openCompletion(NO);watching=NO;
            if(toastClassNil){Check(toastLookups==before+1&&toastAllocs==0&&message==nil,@"missing failure-toast class is retried");toastClassNil=NO;[trace removeAllObjects];watching=YES;openCompletion(NO);watching=NO;}
            Check(pauses==1&&toastAllocs==1&&!toastInits,@"failure allocates toast without init and does not pause again");Equal(message,@"PlayerNotFound",@"failure localized label");
            NSMutableArray *events=[NSMutableArray array];if(before==0)[events addObject:@"class.toast"];[events addObjectsFromArray:@[@"toast.alloc",@"bundle",@"localize.PlayerNotFound",@"toast.message"]];Equal(trace,events,@"failure cache and feedback order");
        }
        playlist.text=@"https://fixture.invalid/nil-url";urlResultNil=YES;activeApp=firstApp;Begin();Invoke(actions[index]);watching=NO;Check(urlCalls==1&&opens==1&&openedURL==nil&&openCompletion!=nil,@"nil URL conversion still forwarded to application");urlResultNil=NO;
        appResultNil=YES;Begin();Invoke(actions[index]);watching=NO;Check(urlCalls==1&&opens==0&&openCompletion==nil,@"nil application still evaluates URL argument");appResultNil=NO;
    }
    // Nil player and nil playlist preserve menu construction and nil forwarding.
    Begin();Check(!Show(helper,nil,nil),@"nil player still builds external menu");watching=NO;NSArray *nilActions=DownloadsLastSheet.actions;Check(nilActions.count==3&&DownloadsLastSheet.source==nil,@"nil player has three actions");
    Begin();Invoke(nilActions[0]);watching=NO;Check(factoryURL==nil&&pauses==0&&presentationCompletion==nil&&plays==0,@"nil player does not present or play");
    for(NSUInteger i=1;i<3;++i){activeApp=firstApp;Begin();Invoke(nilActions[i]);watching=NO;Check([urlText hasSuffix:@"url=(null)"]&&opens==1,@"nil playlist formatted without early return");openCompletion(YES);Check(pauses==0,@"nil captured player ignores success pause");}
    // Completion owns the AVPlayer independently of the controller property.
    __weak AVPlayer *weakVideo;
    @autoreleasepool {videoResult=[ExternalVideo new];Begin();Invoke(actions[0]);watching=NO;weakVideo=videoResult;videoResult=nil;assignedPlayer=nil;builtController.player=nil;player.presented=nil;builtController=nil;}
    Check(weakVideo!=nil,@"presentation completion retains player");presentationCompletion=nil;Check(weakVideo==nil,@"completion release relinquishes player");
    NSUInteger sl=sheetLookups,al=actionLookups,tl=toastLookups;Begin();Check(!Show(helper,player,source),@"repeated external sheet");watching=NO;Check(sl==sheetLookups&&al==actionLookups,@"successful menu class caches persist");
    DownloadsNode *response=[DownloadsNode new],*details=[DownloadsNode new],*metadata=[DownloadsNode new];response.playerData=metadata;metadata.videoDetails=details;player.playerResponse=response;
    [helper showInformationSheet:player withSender:source];Invoke(Find(DownloadsLastSheet.actions,@"CopyChannelName"));Check(sl==sheetLookups&&al==actionLookups&&tl==toastLookups,@"external and information menus share all three caches");
    method_setImplementation(class_getClassMethod(AVPlayer.class,@selector(playerWithURL:)),oldVideo);
    method_setImplementation(class_getInstanceMethod(AVPlayerViewController.class,@selector(setPlayer:)),oldSetPlayer);
    method_setImplementation(class_getClassMethod(UIApplication.class,@selector(sharedApplication)),oldApplication);
    method_setImplementation(class_getClassMethod(NSURL.class,@selector(URLWithString:)),oldURL);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),oldBundle);
    method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),oldIcon);
    method_setImplementation(class_getClassMethod(UIImage.class,@selector(imageNamed:inBundle:compatibleWithTraitCollection:)),oldAsset);
    method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),oldSheet);
    method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),oldAction);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),oldPresent);
    method_setImplementation(class_getInstanceMethod(YTToastController.class,@selector(showMessage:)),oldMessage);
    openCompletion=nil;presentationCompletion=nil;
    printf("%s First_menu_external_player: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
