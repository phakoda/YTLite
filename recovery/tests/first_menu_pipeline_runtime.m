#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks;
static NSMutableArray *trace;
static BOOL allocNil,initNil,useReplacement,nilGetter;
static id replacement,receivedHelper,returnedHelper,passedPlayer;
static NSDictionary *forwarded;
static void (^onDownload)(void);
static void Check(BOOL value,NSString *label){++checks;if(!value){fprintf(stderr,"FAIL %s\n",label.UTF8String);exit(1);}}
static void Equal(id a,id b,NSString *label){if(!(a==b || [a isEqual:b]))fprintf(stderr,"actual=%s expected=%s\n",[a description].UTF8String,[b description].UTF8String);Check(a==b || [a isEqual:b],label);}
static void Event(NSString *s){[trace addObject:s];}
static id Box(id value){return value?:NSNull.null;}
@interface YTLHelper : NSObject @end
@implementation YTLHelper (FirstMenuConstruction)
+ (instancetype)new { Event(@"new");return [super new]; }
+ (instancetype)allocWithZone:(struct _NSZone *)zone { Event(@"alloc");return allocNil?nil:[super allocWithZone:zone]; }
- (instancetype)init { Event(@"init");self=[super init];if(initNil)self=nil;else if(useReplacement)self=replacement;return self; }
@end
@interface PipelineReceiver : NSObject <YTPDownloadsPipeline> @end
@implementation PipelineReceiver
+ (void)downloadImageFromURL:(NSURL *)url download:(BOOL)download {(void)url;(void)download;Check(NO,@"unexpected image pipeline");}
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID audioSize:(unsigned long long)size duration:(unsigned long long)duration {
    (void)url;(void)name;(void)videoID;(void)size;(void)duration;Check(NO,@"unexpected audio pipeline");
}
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL fileName:(NSString *)name format:(NSString *)format videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions {
    Event(@"download");forwarded=@{@"video":Box(videoURL),@"audio":Box(audioURL),@"name":Box(name),@"format":Box(format),
        @"id":Box(videoID),@"videoSize":@(videoSize),@"audioSize":@(audioSize),@"duration":@(duration),@"captions":Box(captions)};
    if(onDownload)onDownload();
}
@end
@interface PipelineRoot : DownloadsRoot @end
@implementation PipelineRoot
- (void)setHelper:(id)helper {Event(@"setHelper");receivedHelper=helper;[super setHelper:helper];}
- (id)helper {Event(@"helper");return nilGetter?nil:returnedHelper;}
@end
@interface PipelineWindow : UIWindow @end
@implementation PipelineWindow
- (UIViewController *)rootViewController {Event(@"root");return [super rootViewController];}
@end
@interface PipelineDelegate : DownloadsAppDelegate @end
@implementation PipelineDelegate
- (UIWindow *)window {Event(@"window");return [super window];}
@end
@interface PipelineApplication : UIApplication @end
@implementation PipelineApplication
- (id)delegate {Event(@"delegate");return [super delegate];}
@end
@interface PipelineMenu : DownloadMenuHelper @end
@implementation PipelineMenu
- (void)getThumbnail:(id)player {Event(@"thumbnail");passedPlayer=player;}
@end
static IMP originalApplication,originalPreference;
static id SharedApplication(id cls,SEL selector){Event(@"application");return ((id(*)(id,SEL))originalApplication)(cls,selector);}
static BOOL Preference(id cls,SEL selector,id key){Event(@"preference");Equal(key,@"embedThumbnails",@"exact thumbnail preference");return ((BOOL(*)(id,SEL,id))originalPreference)(cls,selector,key);}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];
    UIApplication *app=[UIApplication sharedApplication];object_setClass(app,PipelineApplication.class);
    Method applicationMethod=class_getClassMethod(UIApplication.class,@selector(sharedApplication));
    originalApplication=method_setImplementation(applicationMethod,(IMP)SharedApplication);
    Method preferenceMethod=class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:));
    originalPreference=method_setImplementation(preferenceMethod,(IMP)Preference);
    PipelineMenu *menu=[PipelineMenu new];PipelineReceiver *receiver=[PipelineReceiver new];
    NSArray *values=@[[NSURL URLWithString:@"https://fixture.invalid/video"],[NSURL URLWithString:@"https://fixture.invalid/audio"],
        [[NSMutableString alloc]initWithString:@"unchanged name"],[[NSMutableString alloc]initWithString:@"MiXeD"],
        [[NSMutableString alloc]initWithString:@"unchanged ID"],[NSURL URLWithString:@"https://fixture.invalid/captions"]];
    unsigned long long sizes[]={0,0x100000011ULL,0x8000000000000001ULL,0xffffffffffffffffULL};
    for(NSUInteger construction=0;construction<4;++construction)
    for(NSUInteger rootMode=0;rootMode<4;++rootMode)
    for(NSUInteger playerMode=0;playerMode<3;++playerMode){
        PipelineRoot *root=[PipelineRoot new];PipelineWindow *window=[PipelineWindow new];
        PipelineDelegate *delegate=[PipelineDelegate new];window.rootViewController=root;delegate.window=window;app.delegate=delegate;
        if(rootMode==1)app.delegate=nil;else if(rootMode==2)delegate.window=nil;else if(rootMode==3)window.rootViewController=nil;
        allocNil=construction==1;initNil=construction==2;useReplacement=construction==3;replacement=receiver;returnedHelper=receiver;nilGetter=NO;
        id player=playerMode?[NSObject new]:nil;BOOL enabled=playerMode==2;
        DownloadsPreferences[@"embedThumbnails"]=@(!enabled);
        onDownload=^{DownloadsPreferences[@"embedThumbnails"]=@(enabled);app.delegate=nil;};
        if(rootMode)DownloadsPreferences[@"embedThumbnails"]=@(enabled);
        receivedHelper=nil;passedPlayer=nil;forwarded=nil;[trace removeAllObjects];
        unsigned long long videoSize=sizes[construction],audioSize=sizes[(construction+1)%4],duration=sizes[(construction+2)%4];
        [menu downloadVideoWithUrl:values[0] audioUrl:values[1] fileName:values[2] extension:values[3] videoID:values[4]
            videoSize:videoSize audioSize:audioSize duration:duration captions:values[5] playerVC:player];
        NSMutableArray *wanted=[NSMutableArray arrayWithArray:@[@"application",@"delegate"]];
        if(rootMode!=1)[wanted addObject:@"window"];
        if(rootMode!=1 && rootMode!=2)[wanted addObject:@"root"];
        [wanted addObject:@"alloc"];if(!allocNil)[wanted addObject:@"init"];
        if(rootMode==0)[wanted addObjectsFromArray:@[@"setHelper",@"helper",@"download"]];
        if(player)[wanted addObject:@"preference"];if(enabled)[wanted addObject:@"thumbnail"];
        Equal(trace,wanted,@"first-package handoff sequence");
        Check(passedPlayer==(enabled?player:nil),@"thumbnail forwards original player only when enabled");
        if(!rootMode){
            Check((receivedHelper==nil)==(allocNil||initNil),@"nil construction result still sent to root setter");
            if(useReplacement)Check(receivedHelper==receiver,@"replacement initializer result installed");
            else if(!allocNil && !initNil)Check([receivedHelper isKindOfClass:YTLHelper.class],@"fresh initialized helper installed");
            for(NSUInteger i=0;i<6;++i)Check(forwarded[(@[@"video",@"audio",@"name",@"format",@"id",@"captions"])[i]]==values[i],@"object argument identity preserved");
            Equal(forwarded[@"videoSize"],@(videoSize),@"full-width video size");Equal(forwarded[@"audioSize"],@(audioSize),@"full-width audio size");Equal(forwarded[@"duration"],@(duration),@"full-width duration");
        }else Check(forwarded==nil,@"missing app root receives no download");
    }
    allocNil=NO;initNil=NO;useReplacement=NO;nilGetter=YES;onDownload=nil;DownloadsPreferences[@"embedThumbnails"]=@NO;
    PipelineRoot *root=[PipelineRoot new];PipelineWindow *window=[PipelineWindow new];window.rootViewController=root;
    PipelineDelegate *delegate=[PipelineDelegate new];delegate.window=window;app.delegate=delegate;forwarded=nil;[trace removeAllObjects];
    [menu downloadVideoWithUrl:nil audioUrl:nil fileName:nil extension:nil videoID:nil videoSize:0 audioSize:0 duration:0 captions:nil playerVC:nil];
    Equal(trace,(@[@"application",@"delegate",@"window",@"root",@"alloc",@"init",@"setHelper",@"helper"]),@"nil current helper prevents downstream call");
    Check(forwarded==nil,@"nil helper does not fall back to freshly allocated helper");
    nilGetter=NO;[trace removeAllObjects];
    [menu downloadVideoWithUrl:nil audioUrl:nil fileName:nil extension:nil videoID:nil videoSize:0 audioSize:0 duration:0 captions:nil playerVC:nil];
    for(NSString *key in @[@"video",@"audio",@"name",@"format",@"id",@"captions"])Check(forwarded[key]==NSNull.null,@"nil object arguments forwarded");
    printf("PASS First_menu_pipeline: %lu assertions\n",(unsigned long)checks);return 0;
}}
