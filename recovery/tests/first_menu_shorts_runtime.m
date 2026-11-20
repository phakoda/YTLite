#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups,resourceLookups,helperInits,opens;
static BOOL watch,sheetNil,actionNil,resourceNil,helperNil;
static NSMutableArray *trace;
static id expectedPlayer,expectedSender,best,constructedHelper,openedID,openedPlayer;
static NSArray *videos,*audios;
static NSDictionary *result;
static long long spaceSize;
static void (^spaceCompletion)(BOOL,NSString *);
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static id Box(id o){return o?:NSNull.null;}
Class FirstShortsClassLookup(const char *n){
 if(!strcmp(n,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if(!strcmp(n,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionNil?Nil:YTActionSheetAction.class;}
 if(!strcmp(n,"YTUIResources")){++resourceLookups;Event(@"class.resources");return resourceNil?Nil:objc_getClass(n);}
 return objc_getClass(n);
}
Class FirstShortsStringLookup(NSString *n){
 if([n isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if([n isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionNil?Nil:YTActionSheetAction.class;}
 if([n isEqual:@"YTUIResources"]){++resourceLookups;Event(@"string.resources");return resourceNil?Nil:NSClassFromString(n);}
 return NSClassFromString(n);
}
@interface ShortsString : NSString
@property(nonatomic,strong) NSMutableString *backing;
@property(nonatomic,copy) NSString *tag;
@end
@implementation ShortsString
- (NSUInteger)length{Event([self.tag stringByAppendingString:@".length"]);return self.backing.length;}
- (unichar)characterAtIndex:(NSUInteger)i{return [self.backing characterAtIndex:i];}
- (void)getCharacters:(unichar *)buffer range:(NSRange)range{[self.backing getCharacters:buffer range:range];}
- (NSString *)substringToIndex:(NSUInteger)i{Event([self.tag stringByAppendingString:@".shorten"]);return [self.backing substringToIndex:i];}
- (NSString *)description{return self.backing;}
@end
static ShortsString *String(NSString *tag,NSString *value){ShortsString *s=[ShortsString alloc];s.backing=[value mutableCopy];s.tag=tag;return s;}
@interface ShortsNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSString *authorValue,*titleValue;
@property(nonatomic,copy) void (^onAuthor)(void);
@property(nonatomic,copy) void (^onTitle)(void);
@property(nonatomic,strong) NSArray *ids;
@property(nonatomic) NSUInteger idReads;
@end
@implementation ShortsNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"oldResponse"];return [super contentPlayerResponse];}
- (NSString *)videoID{[self event:@"id"];return [super videoID];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (NSString *)author{[self event:@"author"];if(self.onAuthor)self.onAuthor();return self.authorValue;}
- (NSString *)title{[self event:@"title"];if(self.onTitle)self.onTitle();return self.titleValue;}
- (BOOL)isLivePlayback{[self event:@"live"];return [super isLivePlayback];}
- (NSString *)contentVideoID{[self event:@"contentID"];id value=self.ids?self.ids[MIN(self.idReads++,self.ids.count-1)]:[super contentVideoID];return value==NSNull.null?nil:value;}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (id)selectedAudioFormat{[self event:@"selected"];return [super selectedAudioFormat];}
- (id)audioTrack{[self event:@"track"];return [super audioTrack];}
- (NSString *)mimeType{[self event:@"mime"];return [super mimeType];}
- (NSString *)qualityLabel{[self event:@"quality"];return [super qualityLabel];}
- (unsigned long long)contentLength{[self event:@"size"];return [super contentLength];}
- (BOOL)hasContentLength{[self event:@"hasSize"];return [super hasContentLength];}
- (id)URL{[self event:@"URL"];return [super URL];}
- (unsigned long long)approxDurationMs{[self event:@"duration"];return [super approxDurationMs];}
@end
static ShortsNode *Node(NSString *s){ShortsNode *n=[ShortsNode new];n.tag=s;return n;}
static IMP oldInit,oldSheet,oldAction,oldSecondary,oldImage,oldInt,oldStandard,oldSet,oldLocalization;
static id HelperInit(id self,SEL sel){Event(@"helper.init");++helperInits;if(helperNil)return nil;constructedHelper=((id(*)(id,SEL))oldInit)(self,sel);return constructedHelper;}
static NSArray *Videos(id self,SEL sel,id player,BOOL shorts){(void)sel;Event(@"videos");Check(self==constructedHelper&&player==expectedPlayer&&shorts,@"shorts filter arguments");return videos;}
static NSArray *Audios(id self,SEL sel,id player){(void)sel;Event(@"audios");Check(self==constructedHelper&&player==expectedPlayer,@"audio filter arguments");return audios;}
static id Best(id self,SEL sel,NSArray *formats,id player){(void)sel;Event(@"best");Check(self==constructedHelper&&formats==audios&&player==expectedPlayer,@"best audio arguments");return best;}
static void Space(id self,SEL sel,long long size,void (^completion)(BOOL,NSString *)){(void)self;(void)sel;Event(@"space");spaceSize=size;spaceCompletion=[completion copy];}
static void Tracks(id self,SEL sel,id v,NSArray *a,NSString *name,NSString *ext,NSString *identifier,id player,id sender){(void)self;(void)sel;Event(@"tracks");result=@{@"route":@"tracks",@"video":Box(v),@"audio":Box(a),@"name":Box(name),@"ext":Box(ext),@"id":Box(identifier),@"player":Box(player),@"sender":Box(sender)};}
static void Direct(id self,SEL sel,NSURL *v,NSURL *a,NSString *name,NSString *ext,NSString *identifier,unsigned long long vs,unsigned long long as,unsigned long long duration,NSURL *caps,id player){(void)self;(void)sel;Event(@"direct");result=@{@"route":@"direct",@"video":Box(v),@"audio":Box(a),@"name":Box(name),@"ext":Box(ext),@"id":Box(identifier),@"vs":@(vs),@"as":@(as),@"duration":@(duration),@"caps":Box(caps),@"player":Box(player)};}
static void Images(id self,SEL sel,id player,id sender){(void)sel;Event(@"images");Check(self==constructedHelper&&player==expectedPlayer&&sender==expectedSender,@"images handoff identities");}
static void Information(id self,SEL sel,id player,id sender){(void)sel;Event(@"information");Check(self==constructedHelper&&player==expectedPlayer&&sender==expectedSender,@"information handoff identities");}
static id Sheet(id cls,SEL sel,id message,id sub,id delegate,id parent){Event(@"sheet");Check(delegate==nil&&parent==nil,@"nil sheet delegate/parent");return ((id(*)(id,SEL,id,id,id,id))oldSheet)(cls,sel,message,sub,delegate,parent);}
static id Action(id cls,SEL sel,NSString *title,NSString *value,UIImage *icon,NSString *identifier,void (^handler)(void)){Event([@"value:" stringByAppendingString:title]);Check(identifier==nil&&handler!=nil,@"value action identifier/handler");return ((id(*)(id,SEL,id,id,id,id,id))oldAction)(cls,sel,title,value,icon,identifier,handler);}
static id Secondary(id cls,SEL sel,NSString *title,UIImage *icon,UIImage *secondary,NSString *identifier,void (^handler)(void)){Event([@"secondary:" stringByAppendingString:title]);Check(identifier==nil&&handler!=nil,@"secondary action identifier/handler");return ((id(*)(id,SEL,id,id,id,id,id))oldSecondary)(cls,sel,title,icon,secondary,identifier,handler);}
static UIImage *Image(id cls,SEL sel,NSString *name){Event([@"icon:" stringByAppendingString:name]);return ((id(*)(id,SEL,id))oldImage)(cls,sel,name);}
static long long Int(id cls,SEL sel,NSString *key){Event([@"int:" stringByAppendingString:key]);return ((long long(*)(id,SEL,id))oldInt)(cls,sel,key);}
static id Standard(id cls,SEL sel){Event(@"preferences");return ((id(*)(id,SEL))oldStandard)(cls,sel);}
static void Set(id self,SEL sel,long long value,NSString *key){Event(@"set.preference");Check([key isEqual:@"shortsPlaybackIndex"]&&(value==0||value==1),@"toggle writes Boolean integer for exact key");((void(*)(id,SEL,long long,id))oldSet)(self,sel,value,key);}
static NSString *Localize(id self,SEL sel,NSString *key,NSString *value,NSString *table){Event([@"label:" stringByAppendingString:key]);return ((id(*)(id,SEL,id,id,id))oldLocalization)(self,sel,key,value,table);}
static void Open(id cls,SEL sel,NSString *identifier,id player){(void)cls;(void)sel;Event(@"open");++opens;openedID=identifier;openedPlayer=player;}
static IMP Swap(Class cls,SEL sel,IMP imp,BOOL classMethod){Method method=classMethod?class_getClassMethod(cls,sel):class_getInstanceMethod(cls,sel);Check(method!=NULL,@"fixture boundary exists");IMP old=method_getImplementation(method);Class target=classMethod?object_getClass(cls):cls;if(class_addMethod(target,sel,imp,method_getTypeEncoding(method)))return old;return method_setImplementation(method,imp);}
static void Begin(void){watch=NO;result=nil;spaceCompletion=nil;constructedHelper=nil;DownloadsLastSheet=nil;DownloadsLastToast=nil;openedID=nil;openedPlayer=nil;[trace removeAllObjects];watch=YES;}
static void Show(void){[DownloadMenuHelper showDownloadSheetShorts:expectedPlayer withSender:expectedSender];watch=NO;}
static YTActionSheetAction *Find(NSString *title){for(YTActionSheetAction *a in DownloadsLastSheet.actions)if([a.title isEqual:title])return a;return nil;}
static void Select(NSString *name){YTActionSheetAction *action=Find(name);Check(action!=nil,@"action available");watch=YES;[trace removeAllObjects];if(action.handler)action.handler();watch=NO;}
int main(void){@autoreleasepool{
 DownloadsInstallDoubles();trace=[NSMutableArray new];Class menu=DownloadMenuHelper.class;
 oldInit=Swap(menu,@selector(init),(IMP)HelperInit,NO);
 Swap(menu,@selector(getVideoFormatsArray:isShorts:),(IMP)Videos,NO);Swap(menu,@selector(getAudioFormatsArray:),(IMP)Audios,NO);Swap(menu,@selector(getBestAudioFormat:playerVC:),(IMP)Best,NO);
 Swap(menu,@selector(checkSpaceAvailabilityForMedia:completion:),(IMP)Space,NO);
 Swap(menu,@selector(downloadVideoWithFormat:withAudioFormats:fileName:extension:videoID:playerVC:sender:),(IMP)Tracks,NO);
 Swap(menu,@selector(downloadVideoWithUrl:audioUrl:fileName:extension:videoID:videoSize:audioSize:duration:captions:playerVC:),(IMP)Direct,NO);
 Swap(menu,@selector(showImagesSheet:withSender:),(IMP)Images,NO);Swap(menu,@selector(showInformationSheet:withSender:),(IMP)Information,NO);
 oldSheet=Swap(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),(IMP)Sheet,YES);
 oldAction=Swap(YTActionSheetAction.class,@selector(actionWithTitle:currentValue:iconImage:accessibilityIdentifier:handler:),(IMP)Action,YES);
 oldSecondary=Swap(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:secondaryIconImage:accessibilityIdentifier:handler:),(IMP)Secondary,YES);
 oldImage=Swap(YTPMedia.class,@selector(imageWithName:),(IMP)Image,YES);
 oldInt=Swap(YTLUserDefaults.class,@selector(integerForKey:),(IMP)Int,YES);oldStandard=Swap(YTLUserDefaults.class,@selector(standardUserDefaults),(IMP)Standard,YES);oldSet=Swap(YTLUserDefaults.class,@selector(setInteger:forKey:),(IMP)Set,NO);
 oldLocalization=Swap(object_getClass([NSBundle ytl_defaultBundle]),@selector(localizedStringForKey:value:table:),(IMP)Localize,NO);
 Swap(NSClassFromString(@"YTPPlayerHelper"),@selector(openVideoWithID:viewController:),(IMP)Open,YES);
 ShortsNode *player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details"),*replacement=Node(@"replacement"),*video=Node(@"video"),*audio=Node(@"audio"),*active=Node(@"active"),*selected=Node(@"selected");
 ShortsString *author=String(@"author",@"Author"),*title=String(@"title",@"Title");
 player.playerResponse=response;response.videoID=@"id";response.playerData=data;data.videoDetails=details;details.authorValue=author;details.titleValue=title;replacement.authorValue=author;replacement.titleValue=@"Wrong title";player.activeVideo=active;active.selectedAudioFormat=selected;
 video.URL=@"https://fixture.invalid/v";video.contentLength=500;video.approxDurationMs=ULLONG_MAX;audio.URL=@"https://fixture.invalid/a";audio.contentLength=100;
 expectedPlayer=player;expectedSender=[NSObject new];videos=@[video];audios=@[audio];best=audio;
 // All unresolved caches retry; nil sheet still evaluates action arguments.
 sheetNil=resourceNil=actionNil=YES;
 for(int i=0;i<2;++i){Begin();Show();Check(DownloadsLastSheet==nil,@"nil sheet is forwarded without presentation");}
 Check(sheetLookups==2&&resourceLookups==2&&actionLookups==10,@"failed lookups retried per use");sheetNil=resourceNil=actionNil=NO;
 __weak ShortsNode *weakData=data;details.onTitle=^{weakData.videoDetails=replacement;};Begin();Show();details.onTitle=nil;data.videoDetails=details;
 NSArray *metadata=@[@"helper.init",@"player.response",@"response.id",@"response.data",@"data.details",@"details.title",@"response.data",@"data.details",@"replacement.author",@"author.length",@"title.length",@"videos",@"audios",@"best",@"player.active",@"active.selected",@"selected.track",@"video.size"];
 if(trace.count>=metadata.count)Equal([trace subarrayWithRange:NSMakeRange(0,metadata.count)],metadata,@"metadata getter and shortening order");else Check(NO,@"complete metadata trace");
 Equal(DownloadsLastSheet.message,@"Author",@"sheet author");Equal(DownloadsLastSheet.subMessage,@"Title",@"sheet title");Check(DownloadsLastSheet.divider&&DownloadsLastSheet.source==expectedSender&&DownloadsLastSheet.presenter==[ToastView toastWindow].rootViewController,@"header divider/sender/presenter");
 NSArray *labels=@[@"DownloadVideo",@"SaveImage",@"CopyInformation",@"OpenAsRegularVideo",@"AutoSkipShorts"];
 Equal([DownloadsLastSheet.actions valueForKey:@"title"],labels,@"action order");Check(Find(@"DownloadVideo").secondary==nil,@"download action has no secondary icon");Equal(Find(@"DownloadVideo").icon.name,@"FEshorts",@"shorts download icon");
 UIImage *chevron=Find(@"SaveImage").secondary;Check(chevron!=nil&&Find(@"CopyInformation").secondary==chevron&&Find(@"OpenAsRegularVideo").secondary==chevron,@"same chevron on three navigation actions");
 Check(chevron.flipsForRightToLeftLayoutDirection,@"chevron flips for RTL");
 NSUInteger label=[trace indexOfObject:@"label:AutoSkipShorts"],icon=[trace indexOfObject:@"icon:fast_forward"],pref=[trace indexOfObject:@"int:shortsPlaybackIndex"],check=[trace indexOfObject:@"icon:box_empty"];
 Check(label<icon&&icon<pref&&pref<check,@"auto-skip label/icon/preference/checkmark order");
 NSUInteger sl=sheetLookups,al=actionLookups,rl=resourceLookups;Begin();Show();Check(sheetLookups==sl&&actionLookups==al&&resourceLookups==rl,@"successful classes cached");
 // Navigation uses the captured player and sender; open-video ID is read twice.
 Select(@"SaveImage");Equal(trace,(@[@"images"]),@"image callback only");Select(@"CopyInformation");Equal(trace,(@[@"information"]),@"information callback only");
 for(NSArray *ids in @[@[NSNull.null],@[@"first",@"second"],@[@"first",NSNull.null]]){player.ids=ids;player.idReads=0;NSUInteger before=opens;Select(@"OpenAsRegularVideo");if(ids[0]==NSNull.null){Check(opens==before&&player.idReads==1,@"nil first ID prevents opening");}else{Check(opens==before+1&&player.idReads==2&&openedPlayer==player,@"second ID read then open with captured player");Check(Box(openedID)==ids.lastObject,@"second ID forwarded even nil");}}player.ids=nil;
 // Toggle observes current full-width preference, independently of the displayed icon.
 // The local ytpInt policy adds its own defaults getter before its value read;
 // the method then performs the explicit defaults getter for writing.
 for(NSNumber *n in @[@(LLONG_MIN),@(-1),@0,@1,@2,@(0x100000001LL),@(LLONG_MAX)]){DownloadsPreferences[@"shortsPlaybackIndex"]=n;Begin();Show();Equal(Find(@"AutoSkipShorts").secondary.name,n.longLongValue==1?@"box_checkmark":@"box_empty",@"full-width displayed checkmark");DownloadsPreferences[@"shortsPlaybackIndex"]=@(n.longLongValue==1?2:1);Select(@"AutoSkipShorts");Equal(trace,(@[@"preferences",@"int:shortsPlaybackIndex",@"preferences",@"set.preference"]),@"toggle read/store order");Equal(DownloadsPreferences[@"shortsPlaybackIndex"],@(n.longLongValue==1),@"toggle uses current preference");DownloadsPreferences[@"shortsPlaybackIndex"]=n;Select(@"AutoSkipShorts");Equal(DownloadsPreferences[@"shortsPlaybackIndex"],@(n.longLongValue!=1),@"toggle compares full-width current value");}
 // Storage uses only captured video size. Direct Shorts download passes nil player/captions.
 for(NSUInteger track=0;track<2;++track)for(NSUInteger available=0;available<2;++available){selected.audioTrack=track?[NSObject new]:nil;video.contentLength=500;audio.contentLength=100;[author.backing setString:@"before"];[title.backing setString:@"before"];response.videoID=@"id";Begin();Show();video.contentLength=900;audio.contentLength=200;[author.backing setString:@"after author"];[title.backing setString:@"after title"];selected.audioTrack=track?nil:[NSObject new];response.videoID=@"new-id";
 Select(@"DownloadVideo");Equal(trace,(@[@"space"]),@"Shorts action checks storage without hasContentLength");Check(spaceSize==500&&spaceCompletion!=nil&&result==nil,@"captured video-only storage size");watch=YES;[trace removeAllObjects];spaceCompletion(available,@"no space");watch=NO;
 if(!available){Check(result==nil&&[DownloadsLastToast.text isEqual:@"no space"]&&!DownloadsLastToast.success,@"storage failure toast");continue;}
 Equal(result[@"route"],track?@"tracks":@"direct",@"captured track flag");Equal(result[@"name"],@"after author - after title",@"retained metadata formatted at completion");Equal(result[@"id"],@"id",@"captured video ID");Equal(result[@"ext"],@"mp4",@"Shorts mp4 extension");
 if(track){Check(result[@"video"]==video&&result[@"audio"]==audios&&result[@"sender"]==expectedSender&&result[@"player"]==player,@"track handoff identities");}
 else{Check(result[@"player"]==NSNull.null&&result[@"caps"]==NSNull.null,@"direct Shorts nil player and captions");Equal(result[@"vs"],@900,@"live video size");Equal(result[@"as"],@200,@"live audio size");Equal(result[@"duration"],@(ULLONG_MAX),@"full-width duration");}
 }
 // Full-width video sizes and metadata thresholds, including unsigned-high values.
 for(NSNumber *n in @[@0,@1,@(0x100000001ULL),@(0x8000000000000000ULL),@(ULLONG_MAX)]){video.contentLength=n.unsignedLongLongValue;Begin();Show();Equal(Find(@"DownloadVideo").value,[NSByteCountFormatter stringFromByteCount:n.longLongValue countStyle:0],@"signed full-width video size label");Select(@"DownloadVideo");Check(spaceSize==n.longLongValue,@"full-width captured video size");}
 NSUInteger sizes[]={0,29,30,31,199,200,201};for(NSUInteger i=0;i<7;++i)for(NSUInteger j=0;j<7;++j){NSString *a=[@"" stringByPaddingToLength:sizes[i] withString:@"a" startingAtIndex:0],*t=[@"" stringByPaddingToLength:sizes[j] withString:@"t" startingAtIndex:0];author.backing=[a mutableCopy];title.backing=[t mutableCopy];Begin();Show();Equal(DownloadsLastSheet.message,a.length>30?[[a substringToIndex:30]stringByAppendingString:@"…"]:a,@"author boundary");Equal(DownloadsLastSheet.subMessage,t.length>200?[[t substringToIndex:200]stringByAppendingString:@"…"]:t,@"title boundary");}
 data.isLivePlayback=YES;Begin();Show();Check(DownloadsLastSheet.actions.count==4&&Find(@"DownloadVideo")==nil,@"live playback omits only download action");data.isLivePlayback=NO;
 videos=@[];Begin();BOOL threw=NO;@try{Show();}@catch(NSException *e){threw=YES;}watch=NO;Check(threw&&DownloadsLastSheet==nil,@"empty formats preserve index-zero exception");videos=nil;best=nil;Begin();Show();Check(DownloadsLastSheet.actions.count==5,@"nil formats forwarded without empty-array exception");Select(@"DownloadVideo");Check(spaceSize==0,@"nil video storage size zero");spaceCompletion(YES,nil);Check(result[@"video"]==NSNull.null&&result[@"audio"]==NSNull.null,@"nil video/audio URLs forwarded");videos=@[video];best=audio;
 helperNil=YES;Begin();Show();Check(DownloadsLastSheet.actions.count==5,@"nil helper initialization still builds menu");Select(@"DownloadVideo");Check(spaceCompletion==nil&&result==nil,@"nil helper does not perform storage check");helperNil=NO;
 player.playerResponse=nil;Begin();Show();Equal(trace,(@[@"helper.init",@"player.response"]),@"nil supported response exits after helper construction");expectedPlayer=nil;Begin();Show();Equal(trace,(@[@"helper.init"]),@"nil player still constructs helper");
 spaceCompletion=nil;constructedHelper=nil;watch=NO;
 printf("%s First_menu_shorts: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
