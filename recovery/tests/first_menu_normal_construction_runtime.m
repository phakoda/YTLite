#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups,resourceLookups,helperInits;
static BOOL watch,sheetNil,actionNil,resourceNil,helperNil,captions;
static NSMutableArray *trace;
static id expectedPlayer,expectedSender,best,constructedHelper;
static NSArray *audios;
static void (^onLive)(void);
static IMP oldInit,oldSheet,oldAction,oldSecondary,oldImage,oldLocalization;
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static BOOL Captions(id self,SEL sel,id player){(void)sel;Event(@"captions");Check(self==constructedHelper&&player==expectedPlayer,@"captions arguments");return captions;}
static void Navigate(id self,SEL sel,id player,id sender){Event(NSStringFromSelector(sel));Check(self==constructedHelper&&player==expectedPlayer&&sender==expectedSender,@"navigation retains original helper/player/sender");}
Class FirstNormalClassLookup(const char *n){
 if(!strcmp(n,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if(!strcmp(n,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionNil?Nil:YTActionSheetAction.class;}
 if(!strcmp(n,"YTUIResources")){++resourceLookups;Event(@"class.resources");return resourceNil?Nil:objc_getClass(n);}
 return objc_getClass(n);
}
Class FirstNormalStringLookup(NSString *n){
 if([n isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if([n isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionNil?Nil:YTActionSheetAction.class;}
 if([n isEqual:@"YTUIResources"]){++resourceLookups;Event(@"string.resources");return resourceNil?Nil:NSClassFromString(n);}
 return NSClassFromString(n);
}
@interface NormalString : NSString
@property(nonatomic,strong) NSMutableString *backing;
@property(nonatomic,copy) NSString *tag;
@end
@implementation NormalString
- (NSUInteger)length{Event([self.tag stringByAppendingString:@".length"]);return self.backing.length;}
- (unichar)characterAtIndex:(NSUInteger)i{return [self.backing characterAtIndex:i];}
- (void)getCharacters:(unichar *)buffer range:(NSRange)range{[self.backing getCharacters:buffer range:range];}
- (NSString *)substringToIndex:(NSUInteger)i{Event([self.tag stringByAppendingString:@".shorten"]);return [self.backing substringToIndex:i];}
- (NSString *)description{return self.backing;}
@end
static NormalString *String(NSString *tag,NSString *value){NormalString *s=[NormalString alloc];s.backing=[value mutableCopy];s.tag=tag;return s;}
@interface NormalNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSString *authorValue,*titleValue;
@property(nonatomic,copy) void (^onAuthor)(void);
@property(nonatomic,copy) void (^onTitle)(void);
@property(nonatomic,strong) NSArray *ids;
@property(nonatomic) NSUInteger idReads;
@end
@implementation NormalNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"oldResponse"];return [super contentPlayerResponse];}
- (NSString *)videoID{[self event:@"id"];return [super videoID];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (NSString *)author{[self event:@"author"];if(self.onAuthor)self.onAuthor();return self.authorValue;}
- (NSString *)title{[self event:@"title"];if(self.onTitle)self.onTitle();return self.titleValue;}
- (BOOL)isLivePlayback{[self event:@"live"]; BOOL value=[super isLivePlayback]; if(onLive)onLive(); return value;}
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
static NormalNode *Node(NSString *s){NormalNode *n=[NormalNode new];n.tag=s;return n;}
static id HelperInit(id self,SEL sel){Event(@"helper.init");++helperInits;if(helperNil)return nil;constructedHelper=((id(*)(id,SEL))oldInit)(self,sel);return constructedHelper;}
static NSArray *Audios(id self,SEL sel,id player){(void)sel;Event(@"audios");Check(self==constructedHelper&&player==expectedPlayer,@"audio filter arguments");return audios;}
static id Best(id self,SEL sel,NSArray *formats,id player){(void)sel;Event(@"best");Check(self==constructedHelper&&formats==audios&&player==expectedPlayer,@"best audio arguments");return best;}
static id Sheet(id cls,SEL sel,id message,id sub,id delegate,id parent){Event(@"sheet");Check(delegate==nil&&parent==nil,@"nil sheet delegate/parent");return ((id(*)(id,SEL,id,id,id,id))oldSheet)(cls,sel,message,sub,delegate,parent);}
static id Action(id cls,SEL sel,NSString *title,NSString *value,UIImage *icon,NSString *identifier,void (^handler)(void)){Event([@"value:" stringByAppendingString:title]);Check(identifier==nil&&handler!=nil,@"value action identifier/handler");return ((id(*)(id,SEL,id,id,id,id,id))oldAction)(cls,sel,title,value,icon,identifier,handler);}
static id Secondary(id cls,SEL sel,NSString *title,UIImage *icon,UIImage *secondary,NSString *identifier,void (^handler)(void)){Event([@"secondary:" stringByAppendingString:title]);Check(identifier==nil&&handler!=nil,@"secondary action identifier/handler");return ((id(*)(id,SEL,id,id,id,id,id))oldSecondary)(cls,sel,title,icon,secondary,identifier,handler);}
static UIImage *Image(id cls,SEL sel,NSString *name){Event([@"icon:" stringByAppendingString:name]);return ((id(*)(id,SEL,id))oldImage)(cls,sel,name);}
static NSString *Localize(id self,SEL sel,NSString *key,NSString *value,NSString *table){Event([@"label:" stringByAppendingString:key]);return ((id(*)(id,SEL,id,id,id))oldLocalization)(self,sel,key,value,table);}
static IMP Swap(Class cls,SEL sel,IMP imp,BOOL classMethod){Method method=classMethod?class_getClassMethod(cls,sel):class_getInstanceMethod(cls,sel);Check(method!=NULL,@"fixture boundary exists");IMP old=method_getImplementation(method);Class target=classMethod?object_getClass(cls):cls;if(class_addMethod(target,sel,imp,method_getTypeEncoding(method)))return old;return method_setImplementation(method,imp);}
static void Begin(void){watch=NO;constructedHelper=nil;DownloadsLastSheet=nil;[trace removeAllObjects];watch=YES;}
static void Show(void){[DownloadMenuHelper showDownloadSheet:expectedPlayer withSender:expectedSender];watch=NO;}
static YTActionSheetAction *Find(NSString *title){for(YTActionSheetAction *a in DownloadsLastSheet.actions)if([a.title isEqual:title])return a;return nil;}
int main(void){@autoreleasepool{
 DownloadsInstallDoubles();trace=[NSMutableArray new];Class menu=DownloadMenuHelper.class;
 oldInit=Swap(menu,@selector(init),(IMP)HelperInit,NO);
 Swap(menu,@selector(getAudioFormatsArray:),(IMP)Audios,NO);Swap(menu,@selector(getBestAudioFormat:playerVC:),(IMP)Best,NO);Swap(menu,@selector(hasCaptions:),(IMP)Captions,NO);
 NSArray *selectors=@[@"showVideoSheet:withSender:",@"showImagesSheet:withSender:",@"showInformationSheet:withSender:",@"showCaptionsSheet:withSender:",@"showExtPlayerSheet:withSender:"];
 for(NSString *s in selectors)Swap(menu,NSSelectorFromString(s),(IMP)Navigate,NO);
 oldSheet=Swap(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:),(IMP)Sheet,YES);
 oldAction=Swap(YTActionSheetAction.class,@selector(actionWithTitle:currentValue:iconImage:accessibilityIdentifier:handler:),(IMP)Action,YES);
 oldSecondary=Swap(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:secondaryIconImage:accessibilityIdentifier:handler:),(IMP)Secondary,YES);
 oldImage=Swap(YTPMedia.class,@selector(imageWithName:),(IMP)Image,YES);
 oldLocalization=Swap(object_getClass([NSBundle ytl_defaultBundle]),@selector(localizedStringForKey:value:table:),(IMP)Localize,NO);
 NormalNode *player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details"),*replacement=Node(@"replacement"),*audio=Node(@"audio"),*active=Node(@"active"),*selected=Node(@"selected");
 NormalString *author=String(@"author",@"Author"),*title=String(@"title",@"Title");
 player.playerResponse=response;response.videoID=@"id";response.playerData=data;data.videoDetails=details;details.authorValue=author;details.titleValue=title;replacement.authorValue=author;replacement.titleValue=@"Wrong title";player.activeVideo=active;active.selectedAudioFormat=selected;
 audio.contentLength=500;expectedPlayer=player;expectedSender=[NSObject new];audios=@[audio];best=audio;captions=YES;
 sheetNil=resourceNil=actionNil=YES;
 for(int i=0;i<2;++i){Begin();Show();Check(DownloadsLastSheet==nil,@"nil sheet forwarded");}
 Check(sheetLookups==2&&resourceLookups==2&&actionLookups==12,@"unresolved classes retried per use");sheetNil=resourceNil=actionNil=NO;
 __weak NormalNode *weakData=data;details.onTitle=^{weakData.videoDetails=replacement;};Begin();Show();details.onTitle=nil;data.videoDetails=details;
 NSArray *metadata=@[@"helper.init",@"player.response",@"response.id",@"response.data",@"data.details",@"details.title",@"response.data",@"data.details",@"replacement.author",@"author.length",@"title.length",@"audios",@"best",@"player.active",@"active.selected",@"selected.track"];
 Check(trace.count>=metadata.count,@"complete metadata trace");if(trace.count>=metadata.count)Equal([trace subarrayWithRange:NSMakeRange(0,metadata.count)],metadata,@"fresh metadata and author-first shortening");
 Equal(DownloadsLastSheet.message,@"Author",@"author value");Equal(DownloadsLastSheet.subMessage,@"Title",@"title value");
 Check(DownloadsLastSheet.divider&&DownloadsLastSheet.source==expectedSender&&DownloadsLastSheet.presenter==[ToastView toastWindow].rootViewController,@"header/sender/toast presenter");
 NSArray *labels=@[@"DownloadVideo",@"SaveImage",@"CopyInformation",@"DownloadCaptions",@"PlayInExternalPlayer",@"DownloadAudio"];
 NSArray *icons=@[@"player",@"image",@"copy",@"captions",@"play_circle",@"music"];
 Equal([DownloadsLastSheet.actions valueForKey:@"title"],labels,@"all action order");
 UIImage *chevron=Find(@"SaveImage").secondary;Check(chevron!=nil&&chevron.flipsForRightToLeftLayoutDirection,@"RTL chevron");
 for(NSUInteger i=0;i<labels.count;++i){YTActionSheetAction *a=Find(labels[i]);Equal(a.icon.name,icons[i],@"action icon");Check(a.secondary==(i==5?nil:chevron),@"shared chevron on navigation only");NSUInteger l=[trace indexOfObject:[@"label:" stringByAppendingString:labels[i]]],im=[trace indexOfObject:[@"icon:" stringByAppendingString:icons[i]]];Check(l<im,@"label before icon");}
 Check([trace indexOfObject:@"class.action"]<[trace indexOfObject:@"label:DownloadVideo"],@"class before first label");
 Check([trace indexOfObject:@"audio.size"]<[trace indexOfObject:@"label:DownloadAudio"],@"size before audio label");
 NSUInteger sl=sheetLookups,al=actionLookups,rl=resourceLookups;Begin();Show();Check(sheetLookups==sl&&actionLookups==al&&resourceLookups==rl,@"successful class lookups cached");
 NSArray *savedActions=[DownloadsLastSheet.actions copy];DownloadsLastSheet=nil;
 for(NSUInteger i=0;i<selectors.count;++i){[trace removeAllObjects];watch=YES;((YTActionSheetAction *)savedActions[i]).handler();watch=NO;Equal(trace,@[selectors[i]],@"navigation callback selector");}
 // Each live-playback decision performs a fresh read, independently of captions.
 for(NSUInteger live=0;live<2;++live)for(NSUInteger next=0;next<2;++next)for(NSUInteger caps=0;caps<2;++caps){data.isLivePlayback=live;captions=caps;onLive=^{weakData.isLivePlayback=next;};Begin();Show();onLive=nil;
 Check((Find(@"DownloadVideo")!=nil)==!live,@"first live read controls video");Check((Find(@"DownloadAudio")!=nil)==!next,@"second live read controls audio");Check((Find(@"DownloadCaptions")!=nil)==caps,@"caption helper controls caption action");
 NSUInteger reads=0;for(NSString *e in trace)if([e isEqual:@"data.live"])++reads;Check(reads==2,@"two independent live getters");}
 data.isLivePlayback=NO;captions=YES;
 NSUInteger sizes[]={0,29,30,31,199,200,201};for(NSUInteger i=0;i<7;++i)for(NSUInteger j=0;j<7;++j){NSString *a=[@"" stringByPaddingToLength:sizes[i] withString:@"a" startingAtIndex:0],*t=[@"" stringByPaddingToLength:sizes[j] withString:@"t" startingAtIndex:0];author.backing=[a mutableCopy];title.backing=[t mutableCopy];Begin();Show();Equal(DownloadsLastSheet.message,a.length>30?[[a substringToIndex:30]stringByAppendingString:@"…"]:a,@"author threshold");Equal(DownloadsLastSheet.subMessage,t.length>200?[[t substringToIndex:200]stringByAppendingString:@"…"]:t,@"title threshold");}
 details.authorValue=nil;details.titleValue=nil;Begin();Show();Check(DownloadsLastSheet.message==nil&&DownloadsLastSheet.subMessage==nil,@"nil metadata forwarded");
 helperNil=YES;Begin();Show();Check(DownloadsLastSheet.actions.count==5&&Find(@"DownloadCaptions")==nil,@"nil helper leaves base navigation and audio menu");helperNil=NO;
 player.playerResponse=nil;Begin();Show();Equal(trace,(@[@"helper.init",@"player.response"]),@"nil response after init");expectedPlayer=nil;Begin();Show();Equal(trace,(@[@"helper.init"]),@"nil player after init");
 printf("%s First_menu_normal_construction: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
