#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Downloads/FFMpegHelper.h"
#import <objc/runtime.h>

static NSMutableArray *finishEvents;
static YTLHelper *finishingHelper;
static NSString *finishRoot;
static NSURL *finishOutputs[2],*finishVideo,*finishCaptions;
static NSUInteger temporaryReads,urlReads,finishManagerReads,finishMode;
static IMP originalConverter;

@interface HelperFinishRoot : NSString @end
@implementation HelperFinishRoot
- (NSUInteger)length { return finishRoot.length; }
- (unichar)characterAtIndex:(NSUInteger)index { return [finishRoot characterAtIndex:index]; }
- (NSString *)stringByAppendingString:(NSString *)suffix {
    NSUInteger index=temporaryReads++;
    PCheck(index<2,@"finish looks up exactly two output roots");
    [finishEvents addObject:[NSString stringWithFormat:@"temporary:%lu",(unsigned long)index]];
    PSet(finishingHelper,@"_videoID",index ? @"audio-id" : @"video-id");
    PSet(finishingHelper,@"_title",index ? @"AudioTitle" : @"VideoTitle");
    PSet(finishingHelper,@"_format",@"mov");
    return [[finishRoot stringByAppendingPathComponent:index ? @"root-b" : @"root-a"] stringByAppendingString:suffix];
}
@end
static id FinishFileURL(id receiver,SEL selector,NSString *path) {
    (void)receiver;(void)selector;NSUInteger index=urlReads++;
    PCheck(index<2,@"finish creates two output URLs through fileURLWithPath:");
    [finishEvents addObject:[NSString stringWithFormat:@"url:%lu",(unsigned long)index]];
    NSString *suffix=index ? @"root-b/audio-id/AudioTitle.m4a" : @"root-a/video-id/VideoTitle.mov";
    PEqual(path,[finishRoot stringByAppendingPathComponent:suffix],@"each output uses its own root lookup and current ID/title");
    PSet(finishingHelper,@"_videoID",@"changed-after-url");
    return finishOutputs[index];
}
@interface HelperFinishFiles : NSObject
@property NSUInteger index;
@end
@implementation HelperFinishFiles
- (BOOL)removeItemAtURL:(NSURL *)url error:(NSError **)error {
    [finishEvents addObject:[NSString stringWithFormat:@"remove:%lu",(unsigned long)self.index]];
    PCheck(url==finishOutputs[self.index] && error==NULL,@"each manager removes its corresponding original URL and ignores errors");
    if(self.index==1)PSet(finishingHelper,@"_isVideoDownloaded",@(finishMode!=0));
    return NO;
}
@end
static HelperFinishFiles *finishManagers[2];
static id FinishDefaultManager(id receiver,SEL selector) {
    (void)receiver;(void)selector;NSUInteger index=finishManagerReads++;
    PCheck(index<2,@"finish performs separate manager lookups for the two removals");
    [finishEvents addObject:[NSString stringWithFormat:@"manager:%lu",(unsigned long)index]];
    return finishManagers[index];
}
@interface HelperFinishToast : NSObject @end
@implementation HelperFinishToast
- (void)hide {
    [finishEvents addObject:@"hide"];
    PSet(finishingHelper,@"_isAudioOnly",@(finishMode==1));
}
@end
static id FinishConverter(id receiver,SEL selector) {
    [finishEvents addObject:@"converter"];
    PSet(finishingHelper,@"_isAudioOnly",@(finishMode!=1));
    PSet(finishingHelper,@"_videoUrl",finishVideo);PSet(finishingHelper,@"_captionsUrl",finishCaptions);
    PSet(finishingHelper,@"_duration",@29);
    return ((id(*)(id,SEL))originalConverter)(receiver,selector);
}
@interface HelperFinishPhaseProbe : YTLHelper @end
@implementation HelperFinishPhaseProbe
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)identifier audioSize:(unsigned long long)size duration:(unsigned long long)duration {
    PCheck(url==nil && name==nil && identifier==nil && size==0 && duration==0,@"video completion starts audio with all-nil/zero arguments");
    [finishEvents addObject:@"audio-phase"];
}
@end

void PRunHelperFinish(void) {
    NSUInteger before=PresentationAssertions;
    finishEvents=[NSMutableArray new];finishRoot=PresentationFixtureRoot;
    HelperFinishRoot *root=[HelperFinishRoot new];
    NSURL *incoming=[NSURL URLWithString:@"file:///synthetic-incoming-media"];
    finishVideo=[NSURL URLWithString:@"file:///synthetic-current-video"];
    finishCaptions=[NSURL URLWithString:@"file:///synthetic-current-captions"];
    for(NSUInteger i=0;i<2;i++) {
        finishOutputs[i]=[NSURL URLWithString:[NSString stringWithFormat:@"file:///synthetic-output-%lu",(unsigned long)i]];
        finishManagers[i]=[HelperFinishFiles new];finishManagers[i].index=i;
    }
    Method fileURL=class_getClassMethod(NSURL.class,@selector(fileURLWithPath:));
    Method manager=class_getClassMethod(NSFileManager.class,@selector(defaultManager));
    Method converter=class_getClassMethod(FFMpegHelper.class,@selector(sharedInstance));
    IMP oldURL=method_setImplementation(fileURL,(IMP)FinishFileURL);
    IMP oldManager=method_setImplementation(manager,(IMP)FinishDefaultManager);
    originalConverter=method_setImplementation(converter,(IMP)FinishConverter);
    @try {
        for(finishMode=0;finishMode<3;finishMode++) {
            PresentationFixtureRoot=finishRoot;
            finishingHelper=[HelperFinishPhaseProbe new];PSet(finishingHelper,@"_toastView",[HelperFinishToast new]);
            PSet(finishingHelper,@"_videoID",@"initial-id");PSet(finishingHelper,@"_title",@"InitialTitle");
            PSet(finishingHelper,@"_format",@"mp4");
            PSet(finishingHelper,@"_isVideoDownloaded",@(finishMode==0));
            PSet(finishingHelper,@"_isAudioOnly",@(finishMode!=1));
            temporaryReads=urlReads=finishManagerReads=0;[finishEvents removeAllObjects];[PresentationConversions removeAllObjects];
            PresentationFixtureRoot=root;
            [finishingHelper downloadDidFinish:incoming fileName:@"ignored-name"];
            PCheck(temporaryReads==2 && urlReads==2 && finishManagerReads==2,@"finish retains independent root, URL and manager lookups");
            NSArray *prefix=@[@"temporary:0",@"url:0",@"temporary:1",@"url:1",@"manager:0",@"remove:0",@"manager:1",@"remove:1"];
            PCheck(finishEvents.count>=prefix.count,@"finish emits complete output preparation sequence");
            PEqual([finishEvents subarrayWithRange:NSMakeRange(0,prefix.count)],prefix,@"both URLs are complete before either removal");
            if(finishMode==0) {
                PEqual(finishEvents.lastObject,@"audio-phase",@"phase flag is read after the second removal");
                PCheck(PGet(finishingHelper,@"_videoUrl")==incoming && PresentationConversions.count==0,@"video result stored before starting audio, without conversion");
            } else {
                PEqual([finishEvents subarrayWithRange:NSMakeRange(prefix.count,2)],(@[@"hide",@"converter"]),@"completed phase hides toast before looking up converter");
                PCheck(PresentationConversions.count==1,@"completed phase starts one converter operation");
                NSDictionary *record=PresentationConversions.lastObject;
                PEqual(record[@"operation"],finishMode==1 ? @"cut" : @"merge",@"conversion mode read after hide and before singleton lookup");
                PCheck(record[@"audio"]==incoming && [record[@"duration"] longLongValue]==29 && record[@"completion"]!=nil,@"converter gets original incoming URL, current duration and completion");
                if(finishMode==2)PCheck(record[@"video"]==finishVideo && record[@"captions"]==finishCaptions,@"merge reads video and captions after singleton lookup");
            }
            [PresentationConversions removeAllObjects];
        }
    } @finally {
        PresentationFixtureRoot=finishRoot;
        method_setImplementation(fileURL,oldURL);method_setImplementation(manager,oldManager);method_setImplementation(converter,originalConverter);
        finishingHelper=nil;finishEvents=nil;finishRoot=nil;finishVideo=nil;finishCaptions=nil;
        for(NSUInteger i=0;i<2;i++){finishOutputs[i]=nil;finishManagers[i]=nil;}
        [PresentationConversions removeAllObjects];
    }
    printf("PASS Helper_first_package_finish: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
