#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,indexRead;
static NSMutableArray *trace,*downloads;
static NSArray *indexValues,*formats;
static id menuReplacement,best,defaultFormat,englishFormat,receivedHelper,rootReceiver;
static void (^spaceCompletion)(BOOL,NSString *),(^trackCompletion)(id),(^onURL)(void);
static long long requestedSize;
static BOOL nilHelper;
static void Check(BOOL v,NSString *label){++checks;if(!v){fprintf(stderr,"FAIL %s\n",label.UTF8String);exit(1);}}
static void Equal(id a,id b,NSString *label){if(!(a==b||[a isEqual:b]))fprintf(stderr,"actual=%s expected=%s\n",[a description].UTF8String,[b description].UTF8String);Check(a==b||[a isEqual:b],label);}
static void Event(NSString *s){[trace addObject:s];}
@interface AudioName : NSObject
@property(nonatomic,copy) NSString *value,*tag;
@end
@implementation AudioName
- (NSUInteger)length{return 1;}
- (NSString *)description{Event([@"name:" stringByAppendingString:self.tag]);return self.value;}
@end
@interface AudioDetails : DownloadsNode
@property(nonatomic,strong) AudioName *testAuthor,*testTitle;
@end
@implementation AudioDetails
- (NSString *)author{return (id)self.testAuthor;}
- (NSString *)title{return (id)self.testTitle;}
@end
@interface AudioFormat : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@end
@implementation AudioFormat
- (id)URL{Event([@"URL:" stringByAppendingString:self.tag]);if(onURL)onURL();return [super URL];}
- (BOOL)hasContentLength{Event(@"hasLength");return [super hasContentLength];}
- (unsigned long long)contentLength{Event([@"size:" stringByAppendingString:self.tag]);return [super contentLength];}
- (unsigned long long)approxDurationMs{Event([@"duration:" stringByAppendingString:self.tag]);return [super approxDurationMs];}
@end
@implementation DownloadMenuHelper (AudioConstruction)
+ (instancetype)new{Event(@"menu.new");return [super new];}
+ (instancetype)allocWithZone:(struct _NSZone *)zone{Event(@"menu.alloc");return [super allocWithZone:zone];}
- (instancetype)init{Event(@"menu.init");self=[super init];if(menuReplacement)self=menuReplacement;return self;}
@end
@interface AudioMenu : DownloadMenuHelper @end
@implementation AudioMenu
- (NSArray *)getAudioFormatsArray:(id)player{(void)player;return formats;}
- (id)getBestAudioFormat:(NSArray *)f playerVC:(id)player{(void)f;(void)player;return best;}
- (BOOL)hasCaptions:(id)player{(void)player;return NO;}
- (void)checkSpaceAvailabilityForMedia:(long long)size completion:(void (^)(BOOL,NSString *))completion{Event(@"space");requestedSize=size;spaceCompletion=completion;}
- (id)getDefaultAudioTrack:(NSArray *)f{Check(f==formats,@"captured formats for default selection");Event(@"default");return defaultFormat;}
- (id)getEnglishAudioTrack:(NSArray *)f{Check(f==formats,@"captured formats for English selection");Event(@"english");return englishFormat;}
- (void)showAudioTrackSelector:(NSArray *)f sender:(id)sender playerVC:(id)player completion:(void (^)(id))completion{
    Check(f==formats && sender!=nil && player!=nil,@"track selector captures arguments");Event(@"selector");trackCompletion=completion;
}
@end
@interface YTLHelper : NSObject @end
@implementation YTLHelper (AudioConstruction)
+ (instancetype)new{Event(@"pipeline.new");return [super new];}
+ (instancetype)allocWithZone:(struct _NSZone *)zone{Event(@"pipeline.alloc");return [super allocWithZone:zone];}
- (instancetype)init{Event(@"pipeline.init");return [super init];}
@end
@interface AudioRoot : DownloadsRoot @end
@implementation AudioRoot
- (void)setHelper:(id)helper{Event(@"setHelper");receivedHelper=helper;[super setHelper:helper];}
- (id)helper{Event(@"helper");return nilHelper?nil:rootReceiver;}
@end
@interface AudioReceiver : NSObject @end
@implementation AudioReceiver
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID audioSize:(unsigned long long)size duration:(unsigned long long)duration{
    Event(@"download");[downloads addObject:@{@"url":url?:NSNull.null,@"name":name?:NSNull.null,@"id":videoID?:NSNull.null,@"size":@(size),@"duration":@(duration)}];
}
@end
@interface ToastView (AudioMessageDeclaration)
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success;
@end
@interface AudioToast : ToastView @end
@implementation AudioToast
- (instancetype)init{Event(@"toast.init");return [super init];}
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success{Event(@"toast.message");[super showMessageWithText:text isSuccess:success];}
@end
@implementation ToastView (AudioConstruction)
+ (instancetype)new{Event(@"toast.new");return [super new];}
+ (instancetype)allocWithZone:(struct _NSZone *)zone{id result=[super allocWithZone:zone];Event(@"toast.alloc");object_setClass(result,AudioToast.class);return result;}
@end
static IMP originalBundle,originalLocalization;
static id Bundle(id cls,SEL sel){Event(@"bundle");return ((id(*)(id,SEL))originalBundle)(cls,sel);}
static id Localize(id self,SEL sel,id key,id value,id table){Event([@"localize:" stringByAppendingString:key]);return ((id(*)(id,SEL,id,id,id))originalLocalization)(self,sel,key,value,table);}
static long long Integer(id cls,SEL sel,id key){(void)cls;(void)sel;Equal(key,@"ytlAudioIndex",@"four exact preference reads");long long value=[indexValues[MIN(indexRead,indexValues.count-1)] longLongValue];++indexRead;Event([NSString stringWithFormat:@"index:%lld",value]);return value;}
static AudioName *Name(NSString *tag){AudioName *n=[AudioName new];n.tag=tag;n.value=tag;return n;}
static AudioFormat *Format(NSString *tag,NSUInteger offset){AudioFormat *f=[AudioFormat new];f.tag=tag;f.URL=[@"https://fixture.invalid/" stringByAppendingString:tag];f.contentLength=0x8000000000000011ULL+offset;f.approxDurationMs=0xfffffffffffffff0ULL+offset;f.hasContentLength=YES;return f;}
static void Reset(void){[trace removeAllObjects];[downloads removeAllObjects];spaceCompletion=nil;trackCompletion=nil;indexRead=0;receivedHelper=nil;}
static NSArray *SendTrace(NSString *tag){return @[@"helper",[@"URL:" stringByAppendingString:tag],@"name:author",@"name:title",[@"size:" stringByAppendingString:tag],[@"duration:" stringByAppendingString:tag],@"download"];}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];downloads=[NSMutableArray new];
    Method method=class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle));originalBundle=method_setImplementation(method,(IMP)Bundle);
    id bundle=[NSBundle ytl_defaultBundle];method=class_getInstanceMethod([bundle class],@selector(localizedStringForKey:value:table:));originalLocalization=method_setImplementation(method,(IMP)Localize);
    method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(integerForKey:)),(IMP)Integer);
    AudioMenu *probe=[AudioMenu new];menuReplacement=probe;
    AudioFormat *b=Format(@"best",0),*d=Format(@"default",1),*e=Format(@"english",2),*picked=Format(@"picked",3);
    best=b;defaultFormat=d;englishFormat=e;formats=@[b,d,e,picked];rootReceiver=[AudioReceiver new];
    DownloadsAppDelegate *delegate=(id)[UIApplication sharedApplication].delegate;
    AudioRoot *root=[AudioRoot new];delegate.window.rootViewController=root;
    DownloadsNode *player=[DownloadsNode new],*response=[DownloadsNode new],*data=[DownloadsNode new],*active=[DownloadsNode new],*selected=[DownloadsNode new];
    AudioDetails *details=[AudioDetails new];details.testAuthor=Name(@"author");details.testTitle=Name(@"title");
    player.playerResponse=response;response.playerData=data;data.videoDetails=details;response.videoID=@"original-id";player.activeVideo=active;active.selectedAudioFormat=selected;
    UIView *sender=[UIView new];
    for(NSUInteger track=0;track<2;++track)for(NSInteger index=0;index<5;++index){
        selected.audioTrack=track?[NSObject new]:nil;indexValues=@[@(index)];defaultFormat=d;englishFormat=e;nilHelper=NO;
        [trace removeAllObjects];[DownloadMenuHelper showDownloadSheet:player withSender:sender];
        Equal([trace subarrayWithRange:NSMakeRange(0,2)],(@[@"menu.alloc",@"menu.init"]),@"menu alloc/init precedes construction");
        Check(DownloadsLastSheet.divider && DownloadsLastSheet.source==sender,@"normal sheet header and sender");
        Equal([DownloadsLastSheet.actions valueForKey:@"title"],(@[@"DownloadVideo",@"SaveImage",@"CopyInformation",@"PlayInExternalPlayer",@"DownloadAudio"]),@"normal action ordering");
        void (^action)(void)=[DownloadsLastSheet.actions.lastObject.handler copy];Reset();
        action();Equal(trace,(@[@"hasLength",@"size:best",@"space"]),@"audio validates size before deferred storage check");
        Check(requestedSize==(long long)0x8000000000000011ULL,@"storage size preserves signed 64-bit bits");
        Check(downloads.count==0,@"storage completion deferred");
        [trace removeAllObjects];onURL=^{details.testAuthor.value=@"author-after-URL";details.testTitle.value=@"title-after-URL";};
        details.testAuthor.value=@"before";details.testTitle.value=@"before";spaceCompletion(YES,nil);
        NSMutableArray *wanted=[NSMutableArray arrayWithArray:@[@"pipeline.alloc",@"pipeline.init",@"setHelper"]];
        NSString *tag=track?(index==0?@"default":index==1?@"best":index==2?@"english":nil):@"best";
        if(track){for(NSInteger step=0;step<4;++step){[wanted addObject:[NSString stringWithFormat:@"index:%ld",(long)index]];if(index==step){if(step==0)[wanted addObject:@"default"];if(step==2)[wanted addObject:@"english"];if(step<3)[wanted addObjectsFromArray:SendTrace(tag)];else [wanted addObject:@"selector"];}}}
        else [wanted addObjectsFromArray:SendTrace(@"best")];
        Equal(trace,wanted,@"storage completion branch and filename timing");Check(receivedHelper!=nil,@"initialized helper installed");
        Check(indexRead==(track?4u:0u),@"track availability controls independent preference reads");
        if(tag){Check(downloads.count==1,@"one selected audio download");Equal(downloads[0][@"name"],@"author-after-URL - title-after-URL",@"filename uses values after URL evaluation");Equal(downloads[0][@"id"],@"original-id",@"captured video ID");}
        if(track && index==3){
            Check(trackCompletion!=nil && downloads.count==0,@"track selection remains deferred");
            [trace removeAllObjects];trackCompletion(nil);Check(trace.count==0,@"nil selected track ignored");
            DownloadsLastSheet=nil;action=nil;spaceCompletion=nil;[trace removeAllObjects];details.testAuthor.value=@"before";
            trackCompletion(picked);Equal(trace,SendTrace(@"picked"),@"delayed selector uses captured arguments and builds filename after URL");
            Equal(downloads.lastObject[@"name"],@"author-after-URL - title-after-URL",@"late selector filename");
        }
        onURL=nil;
    }
    // Re-enter different branches within the same completion, as four independent reads permit.
    selected.audioTrack=[NSObject new];indexValues=@[@0,@1,@2,@3];[DownloadMenuHelper showDownloadSheet:player withSender:sender];
    void (^action)(void)=[DownloadsLastSheet.actions.lastObject.handler copy];Reset();action();[trace removeAllObjects];spaceCompletion(YES,nil);
    Check(indexRead==4 && downloads.count==3 && trackCompletion!=nil,@"changing preference can select three immediate branches and deferred selection");
    for(NSUInteger i=0;i<3;++i)Equal(downloads[i][@"size"],@((unsigned long long[]){0x8000000000000012ULL,0x8000000000000011ULL,0x8000000000000013ULL}[i]),@"audio size keeps all 64 bits");
    trackCompletion(picked);Equal(downloads.lastObject[@"duration"],@(0xfffffffffffffff3ULL),@"selected duration keeps all 64 bits");
    // Failures construct the toast before resolving localized messages.
    Reset();b.hasContentLength=NO;action();Equal(trace,(@[@"hasLength",@"toast.alloc",@"toast.init",@"bundle",@"localize:Error.TryLater",@"toast.message"]),@"missing-size error construction/localization order");
    Equal(DownloadsLastToast.text,@"Error.TryLater",@"missing-size message");Check(!DownloadsLastToast.success,@"error toast failure flag");
    b.hasContentLength=YES;Reset();action();[trace removeAllObjects];spaceCompletion(NO,@"storage-message");
    Equal(trace,(@[@"toast.alloc",@"toast.init",@"toast.message"]),@"space error preserves supplied text");Equal(DownloadsLastToast.text,@"storage-message",@"space error text");
    indexValues=@[@2];englishFormat=nil;Reset();action();[trace removeAllObjects];spaceCompletion(YES,nil);
    Equal(trace,(@[@"pipeline.alloc",@"pipeline.init",@"setHelper",@"index:2",@"index:2",@"index:2",@"english",@"toast.alloc",@"toast.init",@"bundle",@"localize:EnglishNotFound",@"toast.message",@"index:2"]),@"English miss reports error then performs final independent preference read");
    indexValues=@[@0];defaultFormat=nil;Reset();action();[trace removeAllObjects];spaceCompletion(YES,nil);
    Equal(trace,(@[@"pipeline.alloc",@"pipeline.init",@"setHelper",@"index:0",@"default",@"index:0",@"index:0",@"index:0"]),@"missing default skips URL and filename construction");
    indexValues=@[@1];nilHelper=YES;Reset();action();[trace removeAllObjects];spaceCompletion(YES,nil);
    Equal(trace,(@[@"pipeline.alloc",@"pipeline.init",@"setHelper",@"index:1",@"index:1",@"helper",@"URL:best",@"name:author",@"name:title",@"size:best",@"duration:best",@"index:1",@"index:1"]),@"nil helper still evaluates download arguments");
    Check(downloads.count==0,@"nil current helper receives no download");
    printf("PASS First_menu_audio: %lu assertions\n",(unsigned long)checks);return 0;
}}
