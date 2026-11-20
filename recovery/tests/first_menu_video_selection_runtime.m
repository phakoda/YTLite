#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,failures;
static NSMutableArray *trace;
static BOOL watch;
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static id Box(id value){return value?:NSNull.null;}
@interface VideoNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,copy) void (^onTitle)(void);
@property(nonatomic,copy) void (^onAuthor)(void);
@property(nonatomic,strong) NSString *titleObject;
@end
@implementation VideoNode
- (void)event:(NSString *)key{Event([NSString stringWithFormat:@"%@.%@",self.tag,key]);}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (NSString *)author{[self event:@"author"];if(self.onAuthor)self.onAuthor();return [super author];}
- (NSString *)title{[self event:@"title"];if(self.onTitle)self.onTitle();return self.titleObject?:[super title];}
- (id)URL{[self event:@"URL"];return [super URL];}
- (unsigned long long)contentLength{[self event:@"size"];return [super contentLength];}
- (unsigned long long)approxDurationMs{[self event:@"duration"];return [super approxDurationMs];}
@end
@interface VideoMenu : DownloadMenuHelper
@property(nonatomic,strong) id selected;
@property(nonatomic) BOOL captionsAvailable,driveCaptionHandoff;
@property(nonatomic,copy) void (^audioCompletion)(id);
@property(nonatomic,copy) void (^captionCompletion)(NSURL *);
@property(nonatomic,strong) NSDictionary *captionArguments,*downloadArguments;
@property(nonatomic,strong) id expectedFormats,expectedPlayer,expectedSender;
@end
@implementation VideoMenu
- (id)getDefaultAudioTrack:(NSArray *)formats{Event(@"default");Check(formats==self.expectedFormats,@"default formats identity");return self.selected;}
- (id)getBestAudioFormat:(NSArray *)formats playerVC:(id)player{Event(@"best");Check(formats==self.expectedFormats&&player==self.expectedPlayer,@"best selection input identity");return self.selected;}
- (id)getEnglishAudioTrack:(NSArray *)formats{Event(@"English");Check(formats==self.expectedFormats,@"English formats identity");return self.selected;}
- (BOOL)hasCaptions:(id)player{Event(@"hasCaptions");Check(player==self.expectedPlayer,@"caption availability player identity");return self.captionsAvailable;}
- (void)showAudioTrackSelector:(NSArray *)formats sender:(id)sender playerVC:(id)player completion:(void (^)(id))completion{
    Event(@"audioSelector");Check(formats==self.expectedFormats&&sender==self.expectedSender&&player==self.expectedPlayer,@"deferred selector input identity");self.audioCompletion=completion;
}
- (void)downloadVideoWithFormat:(id)video audioFormat:(id)audio fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID playerVC:(id)player sender:(id)sender{
    Event(@"captionHandoff");self.captionArguments=@{@"video":Box(video),@"audio":Box(audio),@"name":Box(name),@"extension":Box(extension),@"id":Box(videoID),@"player":Box(player),@"sender":Box(sender)};
    if(self.driveCaptionHandoff)[super downloadVideoWithFormat:video audioFormat:audio fileName:name extension:extension videoID:videoID playerVC:player sender:sender];
}
- (void)getCaptionsUrlSheet:(id)player sender:(id)sender completion:(void (^)(NSURL *))completion{
    Event(@"captionSelector");Check(player==self.expectedPlayer&&sender==self.expectedSender,@"caption selector input identity");self.captionCompletion=completion;
}
- (void)downloadVideoWithUrl:(NSURL *)video audioUrl:(NSURL *)audio fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions playerVC:(id)player{
    Event(@"download");self.downloadArguments=@{@"video":Box(video),@"audio":Box(audio),@"name":Box(name),@"extension":Box(extension),@"id":Box(videoID),@"videoSize":@(videoSize),@"audioSize":@(audioSize),@"duration":@(duration),@"captions":Box(captions),@"player":Box(player)};
}
@end
static IMP originalBool,originalInt;
static BOOL BoolPreference(id cls,SEL selector,NSString *key){Event([@"bool:" stringByAppendingString:key]);return ((BOOL(*)(id,SEL,id))originalBool)(cls,selector,key);}
static long long IntPreference(id cls,SEL selector,NSString *key){Event([@"int:" stringByAppendingString:key]);return ((long long(*)(id,SEL,id))originalInt)(cls,selector,key);}
static VideoNode *Node(NSString *tag){VideoNode *n=[VideoNode new];n.tag=tag;return n;}
static void Begin(VideoMenu *h){[trace removeAllObjects];h.captionArguments=nil;h.downloadArguments=nil;h.audioCompletion=nil;h.captionCompletion=nil;watch=YES;}
static void Start(VideoMenu *h,VideoNode *video,NSString *name){[h downloadVideoWithFormat:video withAudioFormats:h.expectedFormats fileName:name extension:@"Mp4" videoID:@"id" playerVC:h.expectedPlayer sender:h.expectedSender];}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];
    originalBool=method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),(IMP)BoolPreference);
    originalInt=method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(integerForKey:)),(IMP)IntPreference);
    VideoMenu *h=[VideoMenu new];VideoNode *video=Node(@"video"),*audio=Node(@"audio"),*player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details");
    video.URL=@"https://fixture.invalid/video";audio.URL=@"https://fixture.invalid/audio";
    video.contentLength=0x8000000000000001ULL;audio.contentLength=0x100000001ULL;video.approxDurationMs=ULLONG_MAX;
    player.playerResponse=response;response.playerData=data;data.videoDetails=details;details.author=@"Author";details.title=@"Title";
    h.expectedPlayer=player;h.expectedSender=[NSObject new];h.expectedFormats=@[audio];h.selected=audio;
    for(NSNumber *index in @[@(-1),@0,@1,@2,@3,@4,@(LLONG_MAX)])for(NSUInteger caps=0;caps<3;++caps){
        DownloadsPreferences[@"ytlAudioIndex"]=index;DownloadsPreferences[@"downloadWithCaps"]=@(caps>0);h.captionsAvailable=caps==2;Begin(h);Start(h,video,@"provided");watch=NO;
        Check([[trace filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF == %@",@"int:ytlAudioIndex"]] count]==1,@"audio preference read once");
        BOOL valid=index.intValue>=0&&index.intValue<=3;
        if(!valid){Check(h.downloadArguments==nil&&h.captionArguments==nil&&h.audioCompletion==nil,@"out-of-range preference has no handoff");continue;}
        if(index.intValue==3){Check(h.downloadArguments==nil&&h.captionArguments==nil&&h.audioCompletion!=nil,@"selector is deferred");[trace removeAllObjects];watch=YES;h.audioCompletion(audio);watch=NO;}
        if(caps==2){Equal(h.captionArguments[@"name"],@"Author - Title",@"captions recompute filename");Equal(h.captionArguments[@"extension"],@"mp4",@"caption extension lowercased");Check(h.captionArguments[@"audio"]==audio,@"caption selected audio identity");}
        else{Equal(h.downloadArguments[@"name"],@"provided",@"direct download keeps supplied filename");Equal(h.downloadArguments[@"extension"],@"Mp4",@"direct download keeps extension case");Equal(h.downloadArguments[@"videoSize"],@(0x8000000000000001ULL),@"full-width video size");Equal(h.downloadArguments[@"audioSize"],@(0x100000001ULL),@"full-width audio size");Equal(h.downloadArguments[@"duration"],@(ULLONG_MAX),@"full-width duration");Check(h.downloadArguments[@"captions"]==NSNull.null,@"direct path has nil captions");}
        Check([trace containsObject:@"hasCaptions"]==(caps>0),@"caption preference short circuits availability");
    }
    // Mutating details on title access distinguishes the first package's reads.
    VideoNode *replacement=Node(@"replacement");replacement.author=@"New Author";replacement.title=@"Wrong Title";
    __weak VideoNode *weakData=data;details.onTitle=^{weakData.videoDetails=replacement;};
    DownloadsPreferences[@"ytlAudioIndex"]=@0;DownloadsPreferences[@"downloadWithCaps"]=@YES;h.captionsAvailable=YES;
    Begin(h);Start(h,video,@"ignored");watch=NO;
    Equal(h.captionArguments[@"name"],@"New Author - Title",@"fresh author lookup after title changes details");
    Equal(trace,(@[@"player.response",@"int:ytlAudioIndex",@"default",@"bool:downloadWithCaps",@"hasCaptions",@"response.data",@"data.details",@"details.title",@"response.data",@"data.details",@"replacement.author",@"captionHandoff"]),@"caption metadata getter sequence");
    details.onTitle=nil;data.videoDetails=details;
    details.titleObject=[NSMutableString stringWithString:@"Before"];__weak VideoNode *weakDetails=details;
    details.onAuthor=^{[(NSMutableString *)weakDetails.titleObject setString:@"After"];};
    Begin(h);Start(h,video,@"ignored");watch=NO;Equal(h.captionArguments[@"name"],@"Author - After",@"title is retained rather than copied before author lookup");
    details.onAuthor=nil;details.titleObject=nil;
    // Nil selector results proceed and preserve the last nonnil shared selection.
    DownloadsPreferences[@"ytlAudioIndex"]=@3;DownloadsPreferences[@"downloadWithCaps"]=@NO;Begin(h);Start(h,video,@"provided");h.audioCompletion(nil);watch=NO;
    Check(h.downloadArguments[@"audio"]==NSNull.null,@"initial nil audio selection forwards nil URL");
    h.audioCompletion(audio);h.downloadArguments=nil;h.audioCompletion(nil);Equal(h.downloadArguments[@"audio"],[NSURL URLWithString:audio.URL],@"later nil selection retains previous audio");
    // Drive the actual caption-handoff method and its retained completion.
    DownloadsPreferences[@"ytlAudioIndex"]=@0;DownloadsPreferences[@"downloadWithCaps"]=@YES;h.driveCaptionHandoff=YES;Begin(h);Start(h,video,@"ignored");watch=NO;
    Check(h.captionCompletion!=nil&&h.downloadArguments==nil,@"caption handoff waits for URL callback");h.captionCompletion(nil);Check(h.downloadArguments==nil,@"nil caption callback does not download");
    NSURL *caption=[NSURL URLWithString:@"https://fixture.invalid/captions"];video.URL=@"https://fixture.invalid/changed";audio.contentLength=ULLONG_MAX;
    [trace removeAllObjects];watch=YES;h.captionCompletion(caption);watch=NO;
    Equal(trace,(@[@"video.URL",@"audio.URL",@"video.size",@"audio.size",@"video.duration",@"download"]),@"caption callback live format getter order");
    Equal(h.downloadArguments[@"video"],[NSURL URLWithString:video.URL],@"caption callback uses current video URL");Equal(h.downloadArguments[@"audioSize"],@(ULLONG_MAX),@"caption callback reads current full-width size");Check(h.downloadArguments[@"captions"]==caption,@"caption URL identity");
    h.driveCaptionHandoff=NO;h.selected=nil;DownloadsPreferences[@"ytlAudioIndex"]=@0;DownloadsPreferences[@"downloadWithCaps"]=@NO;Begin(h);Start(h,video,@"provided");watch=NO;Check(h.downloadArguments!=nil,@"missing default track still downloads");
    DownloadsPreferences[@"ytlAudioIndex"]=@2;Begin(h);Start(h,video,@"provided");watch=NO;Check(h.downloadArguments==nil&&h.captionArguments==nil,@"missing English track prevents download");Check(![trace containsObject:@"bool:downloadWithCaps"],@"error returns before caption preference");
    player.playerResponse=nil;Begin(h);Start(h,video,@"provided");watch=NO;Equal(trace,(@[@"player.response"]),@"nil response returns before selection");
    h.audioCompletion=nil;h.captionCompletion=nil;
    method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),originalBool);
    method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(integerForKey:)),originalInt);
    printf("%s First_menu_video_selection: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
