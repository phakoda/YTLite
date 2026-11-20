#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups;
static BOOL watch,sheetNil,actionNil,inputNil,copyNil,buttonNil;
static NSMutableArray *trace;
static id labelInput,labelCopy,labelAssigned;
static NSString *labelText;
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static id Box(id o){return o?:NSNull.null;}
Class FirstVideoSheetClassLookup(const char *n){
 if(!strcmp(n,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if(!strcmp(n,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionNil?Nil:YTActionSheetAction.class;}
 return objc_getClass(n);
}
Class FirstVideoSheetStringLookup(NSString *n){
 if([n isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetNil?Nil:YTDefaultSheetController.class;}
 if([n isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionNil?Nil:YTActionSheetAction.class;}
 return NSClassFromString(n);
}
@interface SheetString : NSString
@property(nonatomic,strong) NSMutableString *backing;
@property(nonatomic,copy) NSString *tag;
@end
@implementation SheetString
- (NSUInteger)length{Event([self.tag stringByAppendingString:@".length"]);return self.backing.length;}
- (unichar)characterAtIndex:(NSUInteger)i{return [self.backing characterAtIndex:i];}
- (void)getCharacters:(unichar *)buffer range:(NSRange)range{[self.backing getCharacters:buffer range:range];}
- (NSString *)substringToIndex:(NSUInteger)i{Event([self.tag stringByAppendingString:@".shorten"]);return [self.backing substringToIndex:i];}
- (NSString *)description{return self.backing;}
@end
static SheetString *String(NSString *tag,NSString *value){SheetString *s=[SheetString alloc];s.backing=[value mutableCopy];s.tag=tag;return s;}
@interface SheetNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSString *authorValue,*titleValue;
@property(nonatomic,copy) void (^onAuthor)(void);
@end
@implementation SheetNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"oldResponse"];return [super contentPlayerResponse];}
- (NSString *)videoID{[self event:@"id"];return [super videoID];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (NSString *)author{[self event:@"author"];if(self.onAuthor)self.onAuthor();return self.authorValue;}
- (NSString *)title{[self event:@"title"];return self.titleValue;}
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
static SheetNode *Node(NSString *s){SheetNode *n=[SheetNode new];n.tag=s;return n;}
@interface SheetLabel : NSAttributedString
@property(nonatomic,strong) NSAttributedString *backing;
@end
@implementation SheetLabel
- (NSString *)string{return self.backing.string;}
- (NSUInteger)length{return self.backing.length;}
- (NSDictionary *)attributesAtIndex:(NSUInteger)i effectiveRange:(NSRangePointer)range{return [self.backing attributesAtIndex:i effectiveRange:range];}
- (id)mutableCopyWithZone:(NSZone *)zone{(void)zone;Event(@"label.copy");labelCopy=copyNil?nil:[self.backing mutableCopy];return labelCopy;}
@end
@interface SheetButton : UIButton @end
@implementation SheetButton
- (NSAttributedString *)currentAttributedTitle{Event(@"button.title");return inputNil?nil:labelInput;}
- (void)setAttributedTitle:(NSAttributedString *)s forState:(UIControlState)state{Event(@"button.set");Check(state==0,@"normal button state");labelAssigned=s;}
@end
@interface SheetAction : YTActionSheetAction @end
@implementation SheetAction
- (UIButton *)button{Event(@"action.button");return buttonNil?nil:[super button];}
@end
@interface SheetMenu : DownloadMenuHelper
@property(nonatomic,strong) NSArray *videos,*audios;
@property(nonatomic,strong) id best,player,sender;
@property(nonatomic) BOOL hasCaps;
@property(nonatomic) long long checkedSize;
@property(nonatomic,copy) void (^space)(BOOL,NSString *);
@property(nonatomic,strong) NSDictionary *result;
@property(nonatomic,strong) NSString *detail;
@end
@implementation SheetMenu
- (NSArray *)getVideoFormatsArray:(id)p isShorts:(BOOL)s{Event(@"videos");Check(p==self.player&&!s,@"regular video filter inputs");return self.videos;}
- (NSArray *)getAudioFormatsArray:(id)p{Event(@"audios");Check(p==self.player,@"audio filter player identity");return self.audios;}
- (id)getBestAudioFormat:(NSArray *)a playerVC:(id)p{Event(@"best");Check(a==self.audios&&p==self.player,@"best audio input identity");return self.best;}
- (NSString *)detailForMimeType:(NSString *)s{Event(@"detail");(void)s;return self.detail;}
- (BOOL)hasCaptions:(id)p{Event(@"captions");Check(p==self.player,@"caption player identity");return self.hasCaps;}
- (void)checkSpaceAvailabilityForMedia:(long long)s completion:(void (^)(BOOL,NSString *))c{Event(@"space");self.checkedSize=s;self.space=c;}
- (void)downloadVideoWithFormat:(id)v withAudioFormats:(NSArray *)a fileName:(NSString *)n extension:(NSString *)e videoID:(NSString *)i playerVC:(id)p sender:(id)s{
 Event(@"tracks");self.result=@{@"route":@"tracks",@"video":Box(v),@"audio":Box(a),@"name":Box(n),@"ext":Box(e),@"id":Box(i),@"player":Box(p),@"sender":Box(s)};
}
- (void)downloadVideoWithFormat:(id)v audioFormat:(id)a fileName:(NSString *)n extension:(NSString *)e videoID:(NSString *)i playerVC:(id)p sender:(id)s{
 Event(@"captionDownload");self.result=@{@"route":@"caption",@"video":Box(v),@"audio":Box(a),@"name":Box(n),@"ext":Box(e),@"id":Box(i),@"player":Box(p),@"sender":Box(s)};
}
- (void)downloadVideoWithUrl:(NSURL *)v audioUrl:(NSURL *)a fileName:(NSString *)n extension:(NSString *)e videoID:(NSString *)i videoSize:(unsigned long long)vs audioSize:(unsigned long long)as duration:(unsigned long long)d captions:(NSURL *)c playerVC:(id)p{
 Event(@"direct");self.result=@{@"route":@"direct",@"video":Box(v),@"audio":Box(a),@"name":Box(n),@"ext":Box(e),@"id":Box(i),@"player":Box(p),@"vs":@(vs),@"as":@(as),@"duration":@(d),@"captions":Box(c)};
}
@end
static IMP oldFormat,oldSize,oldAction,oldSheet,oldImage,oldBool;
static NSString *Format(id cls,SEL sel,NSString *format,...){
 (void)cls;(void)sel;if([format isEqual:@"%@ %@"])Event(@"format.title");if([format isEqual:@"%@ - %@"])Event(@"format.name");
 va_list ap;va_start(ap,format);NSString *s=[[NSString alloc]initWithFormat:format arguments:ap];va_end(ap);return s;
}
static NSString *FormatSize(id cls,SEL sel,long long s,NSByteCountFormatterCountStyle style){Check(style==0,@"file size formatter style");Event(@"format.size");return ((id(*)(id,SEL,long long,NSByteCountFormatterCountStyle))oldSize)(cls,sel,s,style);}
static id Action(id cls,SEL sel,NSString *title,NSString *value,UIImage *icon,NSString *identifier,void (^handler)(void)){
 (void)cls;(void)sel;Event(@"action");Check(identifier==nil&&handler!=nil,@"action identifier and handler");SheetAction *a=[SheetAction new];a.title=title;a.value=value;a.icon=icon;a.handler=handler;a.button=[SheetButton new];
 SheetLabel *label=[SheetLabel alloc];label.backing=[[NSAttributedString alloc]initWithString:labelText?:title?:@""];labelInput=label;return a;
}
static id Sheet(id cls,SEL sel,id parent){Event(@"sheet");Check(parent==nil,@"nil sheet parent");return ((id(*)(id,SEL,id))oldSheet)(cls,sel,parent);}
static UIImage *Image(id cls,SEL sel,NSString *name){Event([@"icon:" stringByAppendingString:name]);return ((id(*)(id,SEL,id))oldImage)(cls,sel,name);}
static BOOL Bool(id cls,SEL sel,NSString *key){Event([@"pref:" stringByAppendingString:key]);return ((BOOL(*)(id,SEL,id))oldBool)(cls,sel,key);}
static void Begin(SheetMenu *h){watch=NO;h.result=nil;h.space=nil;DownloadsLastToast=nil;DownloadsLastSheet=nil;labelAssigned=nil;labelCopy=nil;[trace removeAllObjects];watch=YES;}
static void Show(SheetMenu *h){[h showVideoSheet:h.player withSender:h.sender];watch=NO;}
static void Select(SheetMenu *h){watch=YES;[trace removeAllObjects];DownloadsLastSheet.actions[0].handler();watch=NO;(void)h;}
int main(void){@autoreleasepool{
 DownloadsInstallDoubles();trace=[NSMutableArray new];
 oldFormat=method_setImplementation(class_getClassMethod(NSString.class,@selector(stringWithFormat:)),(IMP)Format);
 oldSize=method_setImplementation(class_getClassMethod(NSByteCountFormatter.class,@selector(stringFromByteCount:countStyle:)),(IMP)FormatSize);
 oldAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:currentValue:iconImage:accessibilityIdentifier:handler:)),(IMP)Action);
 oldSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),(IMP)Sheet);
 oldImage=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Image);
 oldBool=method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),(IMP)Bool);
 SheetMenu *h=[SheetMenu new];SheetNode *player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details"),*replacement=Node(@"replacement"),*video=Node(@"video"),*audio=Node(@"audio"),*active=Node(@"active"),*selected=Node(@"selected");
 SheetString *author=String(@"author",@"Author"),*title=String(@"title",@"Title");
 player.playerResponse=response;player.contentPlayerResponse=response;response.playerData=data;response.videoID=@"original-id";data.videoDetails=details;details.authorValue=author;details.titleValue=title;replacement.titleValue=title;replacement.authorValue=@"Wrong Author";
 player.activeVideo=active;active.selectedAudioFormat=selected;video.mimeType=@"video/mp4";video.qualityLabel=@"1080p";video.URL=@"https://fixture.invalid/v";audio.URL=@"https://fixture.invalid/a";video.contentLength=100;audio.contentLength=30;video.approxDurationMs=900;video.hasContentLength=YES;
 h.player=player;h.sender=[NSObject new];h.videos=@[video];h.audios=@[audio];h.best=audio;h.detail=@"H264";
 // Unresolved classes retry. Nil action retains array insertion failure.
 actionNil=YES;
 for(int i=0;i<2;++i){Begin(h);BOOL raised=NO;@try{Show(h);}@catch(NSException *e){raised=YES;}watch=NO;Check(raised,@"missing action causes host collection exception");}
 Check(actionLookups==2,@"failed action lookup retried");actionNil=NO;h.videos=@[];sheetNil=YES;
 for(int i=0;i<2;++i){Begin(h);Show(h);Check(DownloadsLastSheet==nil,@"missing sheet yields no presentation");}
 Check(sheetLookups==2,@"failed sheet lookup retried");sheetNil=NO;h.videos=@[video];
 __weak SheetNode *weakData=data;details.onAuthor=^{weakData.videoDetails=replacement;};
 Begin(h);Show(h);details.onAuthor=nil;data.videoDetails=details;
 NSArray *metadata=@[@"player.response",@"response.id",@"response.data",@"data.details",@"details.author",@"response.data",@"data.details",@"replacement.title",@"author.length",@"title.length",@"videos",@"audios",@"best",@"player.active",@"active.selected",@"selected.track"];
 Check(trace.count>=metadata.count,@"metadata trace present");if(trace.count>=metadata.count)Equal([trace subarrayWithRange:NSMakeRange(0,metadata.count)],metadata,@"first-package metadata order and separate details reads");
 NSUInteger quality=[trace indexOfObject:@"video.quality"],size=[trace indexOfObject:@"format.size"],lookup=[trace indexOfObject:@"class.action"],format=[trace indexOfObject:@"format.title"];
 Check(quality<size&&size<lookup&&lookup<format,@"quality then size then class then title format");
 Equal(DownloadsLastSheet.actions[0].title,@"1080p H264",@"quality title");Equal(DownloadsLastSheet.actions[0].value,[NSByteCountFormatter stringFromByteCount:130 countStyle:0],@"combined size label");Equal(DownloadsLastSheet.actions[0].icon.name,@"player",@"player icon");
 Check(labelAssigned==labelCopy&&labelCopy!=nil,@"custom mutableCopy result used");Check(DownloadsLastSheet.source==h.sender&&DownloadsLastSheet.presenter==[ToastView toastWindow].rootViewController,@"sender and toast-root presenter");
 NSDictionary *attrs=[labelAssigned attributesAtIndex:6 effectiveRange:NULL];Check(attrs.count==3&&[attrs[NSBaselineOffsetAttributeName] isEqual:@5],@"detail attributed at offset six");
 Check([labelAssigned attributesAtIndex:0 effectiveRange:NULL].count==0,@"quality prefix remains unstyled");
 NSUInteger cachedSheets=sheetLookups,cachedActions=actionLookups;
 Begin(h);Show(h);Check(sheetLookups==cachedSheets&&actionLookups==cachedActions,@"successful classes cached");
 // Selection and completion preserve captured objects/scalars while reading live media values.
 for(NSUInteger track=0;track<2;++track)for(NSUInteger caps=0;caps<3;++caps)for(NSUInteger available=0;available<2;++available){
 selected.audioTrack=track?[NSObject new]:nil;DownloadsPreferences[@"downloadWithCaps"]=@(caps>0);h.hasCaps=caps==2;
 [author.backing setString:@"Before"];[title.backing setString:@"Before"];video.contentLength=100;audio.contentLength=30;response.videoID=@"original-id";Begin(h);Show(h);
 [author.backing setString:@"After Author"];[title.backing setString:@"After Title"];response.videoID=@"replacement-id";selected.audioTrack=track?nil:[NSObject new];video.contentLength=300;audio.contentLength=70;
 Select(h);Equal(trace,(@[@"video.hasSize",@"space"]),@"action validates size before deferred space check");Check(h.space!=nil&&h.result==nil&&h.checkedSize==130,@"storage uses captured combined size");
 watch=YES;[trace removeAllObjects];h.space(available,@"no room");watch=NO;
 if(!available){Check(h.result==nil&&[DownloadsLastToast.text isEqual:@"no room"]&&!DownloadsLastToast.success,@"storage failure uses error toast");Check(![trace containsObject:@"pref:downloadWithCaps"],@"storage failure skips caption preferences");continue;}
 NSString *route=track?@"tracks":caps==2?@"caption":@"direct";Equal(h.result[@"route"],route,@"captured track flag controls routing");Equal(h.result[@"name"],@"After Author - After Title",@"filename formatted after storage from retained metadata");Equal(h.result[@"ext"],@"mp4",@"extension lowercased");Equal(h.result[@"id"],@"original-id",@"captured ID");Check(h.result[@"player"]==player,@"player identity");
 Check([trace containsObject:@"pref:downloadWithCaps"]==!track,@"track route skips caption preference");Check([trace containsObject:@"captions"]==(!track&&caps>0),@"caption availability short circuit");
 if([route isEqual:@"direct"]){Equal(h.result[@"vs"],@300,@"live video size");Equal(h.result[@"as"],@70,@"live audio size");Equal(h.result[@"duration"],@900,@"live duration");Check(h.result[@"captions"]==NSNull.null,@"direct captions nil");Check([trace indexOfObject:@"audio.URL"]<[trace indexOfObject:@"format.name"],@"URLs read before filename formatting");}
 else{Check(h.result[@"video"]==video&&h.result[@"sender"]==h.sender,@"handoff video/sender identities");Check(h.result[@"audio"]==(track?h.audios:audio),@"handoff audio identity");}
 }
 // Absent content length blocks even if size was previously nonzero.
 Begin(h);Show(h);video.hasContentLength=NO;Select(h);Check(h.space==nil&&h.result==nil&&[DownloadsLastToast.text isEqual:@"Error.TryLater"]&&!DownloadsLastToast.success,@"missing size prevents storage check");video.hasContentLength=YES;
 // Signed formatting and the stored size use wrapping 64-bit addition.
 unsigned long long values[]={0,1,0xffffffffULL,0x100000001ULL,LLONG_MAX,0x8000000000000000ULL,ULLONG_MAX};
 for(NSUInteger i=0;i<7;++i)for(NSUInteger j=0;j<7;++j){video.contentLength=values[i];audio.contentLength=values[j];Begin(h);Show(h);long long total=(long long)(values[i]+values[j]);Equal(DownloadsLastSheet.actions[0].value,[NSByteCountFormatter stringFromByteCount:total countStyle:0],@"full-width formatted sum");Select(h);Check(h.checkedSize==total,@"full-width stored sum");}
 // Copy and nil forwarding do not invent an attributed-string initializer.
 for(NSUInteger nilMode=0;nilMode<4;++nilMode){inputNil=nilMode==1;copyNil=nilMode==2;buttonNil=nilMode==3;Begin(h);BOOL threw=NO;@try{Show(h);}@catch(NSException *e){threw=YES;}watch=NO;Check(!threw,@"nil attributed input/copy/button forwards without initializer exception");if(nilMode)Check(labelAssigned==nil,@"nil attributed result remains nil");}
 inputNil=copyNil=buttonNil=NO;labelText=@"1080p OTHER";Begin(h);Show(h);Check([labelAssigned attributesAtIndex:0 effectiveRange:NULL].count==0,@"missing detail substring remains unstyled");labelText=@"1080p h264";Begin(h);Show(h);Check([labelAssigned attributesAtIndex:6 effectiveRange:NULL].count==3,@"case-insensitive detail styling");labelText=nil;
 // MIME fallback uses a second getter and fallback extension, including nil parser output.
 for(NSString *mime in @[@"video/mp4",@"video/webm",@"VIDEO/MP4",@""]){video.mimeType=mime;h.detail=nil;selected.audioTrack=[NSObject new];Begin(h);Show(h);NSString *ext=[mime hasPrefix:@"video/mp4"]?@"mp4":@"webM";Equal(DownloadsLastSheet.actions[0].title,[@"1080p " stringByAppendingString:ext],@"nil parser fallback extension");Select(h);h.space(YES,nil);Equal(h.result[@"ext"],ext.lowercaseString,@"fallback extension normalized only for download");}
 // Boundary lengths use UTF-16 and the original author/title limits.
 video.mimeType=@"video/mp4";h.detail=@"H264";NSUInteger lengths[]={0,29,30,31,199,200,201};
 for(NSUInteger i=0;i<7;++i)for(NSUInteger j=0;j<7;++j){NSString *av=[@"" stringByPaddingToLength:lengths[i] withString:@"a" startingAtIndex:0],*tv=[@"" stringByPaddingToLength:lengths[j] withString:@"t" startingAtIndex:0];author.backing=[av mutableCopy];title.backing=[tv mutableCopy];Begin(h);Show(h);Select(h);h.space(YES,nil);NSString *a=av.length>30?[[av substringToIndex:30]stringByAppendingString:@"…"]:av,*t=tv.length>200?[[tv substringToIndex:200]stringByAppendingString:@"…"]:tv;Equal(h.result[@"name"],[NSString stringWithFormat:@"%@ - %@",a,t],@"filename UTF-16 length thresholds");}
 // Two actions preserve input order and independently capture their format.
 SheetNode *other=Node(@"other");other.mimeType=@"video/webm";other.qualityLabel=@"2160p";other.contentLength=17;other.hasContentLength=YES;
 h.videos=@[other,video];Begin(h);Show(h);Check(DownloadsLastSheet.actions.count==2,@"one action per input format");Equal(DownloadsLastSheet.actions[0].title,@"2160p H264",@"input order retained");
 DownloadsLastSheet.actions[0].handler();h.space(YES,nil);Check(h.result[@"video"]==other,@"first action captures first format");DownloadsLastSheet.actions[1].handler();h.space(YES,nil);Check(h.result[@"video"]==video,@"second action captures second format");h.videos=@[video];
 author.backing=[[[[@"" stringByPaddingToLength:29 withString:@"a" startingAtIndex:0]stringByAppendingString:@"😀"] stringByAppendingString:@"z"] mutableCopy];title.backing=[@"title" mutableCopy];
 Begin(h);Show(h);Select(h);h.space(YES,nil);NSString *split=h.result[@"name"];Check([split characterAtIndex:29]==0xd83d&&[split characterAtIndex:30]==0x2026,@"author shortening preserves original UTF-16 split boundary");
 details.authorValue=nil;details.titleValue=nil;Begin(h);Show(h);Select(h);h.space(YES,nil);Equal(h.result[@"name"],@"(null) - (null)",@"nil metadata interpolates in deferred filename");details.authorValue=author;details.titleValue=title;
 // Empty lists still produce a sheet; nil selected audio is passed through.
 h.videos=@[];Begin(h);Show(h);Check(DownloadsLastSheet.actions.count==0,@"empty video list presents empty sheet");h.videos=@[video];h.best=nil;selected.audioTrack=nil;DownloadsPreferences[@"downloadWithCaps"]=@NO;Begin(h);Show(h);Select(h);h.space(YES,nil);Check(h.result[@"audio"]==NSNull.null&&[h.result[@"as"] isEqual:@0],@"nil best audio forwards nil URL and zero size");
 player.playerResponse=nil;Begin(h);Show(h);Equal(trace,(@[@"player.response"]),@"supported nil response does not fall back");
 h.player=[NSObject new];Begin(h);Show(h);Check(trace.count==0,@"unsupported player returns before getters");h.player=nil;Begin(h);Show(h);Check(trace.count==0,@"nil player returns");
 h.space=nil;watch=NO;
 method_setImplementation(class_getClassMethod(NSString.class,@selector(stringWithFormat:)),oldFormat);
 printf("%s First_menu_video_sheet: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
