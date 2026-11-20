#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <objc/runtime.h>

static BOOL pathCallbackActive,pathScheduling;
static NSUInteger pathCase,pathCount,pathRoots,pathURLs,pathManagers;
static NSMutableArray *pathEvents;
static NSString *pathRoot;
static YTLHelper *pathHelper;
static NSURL *pathTokens[4],*pathResult,*pathDestination;
static NSURL *scheduledURLs[2];
static NSUInteger scheduledURLCount;
static IMP originalPathURL;
static NSArray *pathSuffixes;

@interface ConversionPathRoot : NSString @end
@implementation ConversionPathRoot
- (NSUInteger)length { return pathRoot.length; }
- (unichar)characterAtIndex:(NSUInteger)index { return [pathRoot characterAtIndex:index]; }
- (NSString *)stringByAppendingString:(NSString *)suffix {
    NSUInteger index=pathRoots++;
    PCheck(index<pathCount,@"conversion performs one root lookup for each intermediate");
    [pathEvents addObject:[NSString stringWithFormat:@"root:%lu",(unsigned long)index]];
    PSet(pathHelper,@"_videoID",[NSString stringWithFormat:@"id-%lu",(unsigned long)index]);
    return [[pathRoot stringByAppendingPathComponent:[NSString stringWithFormat:@"root-%lu",(unsigned long)index]] stringByAppendingString:suffix];
}
@end
static id ConversionPathURL(id receiver,SEL selector,NSString *path) {
    if(!pathCallbackActive) {
        NSURL *result=pathCase==7 ? nil : ((id(*)(id,SEL,id))originalPathURL)(receiver,selector,path);
        if(pathScheduling) {
            PCheck(scheduledURLCount<2,@"conversion captures one destination from each scheduled URL factory");
            scheduledURLs[scheduledURLCount++]=result;
        }
        return result;
    }
    NSUInteger index=pathURLs++;
    PCheck(index<pathCount,@"conversion uses fileURLWithPath for each intermediate");
    [pathEvents addObject:[NSString stringWithFormat:@"url:%lu",(unsigned long)index]];
    NSString *component=[NSString stringWithFormat:@"root-%lu/id-%lu/id-%lu%@",
        (unsigned long)index,(unsigned long)index,(unsigned long)index,pathSuffixes[index]];
    PEqual(path,[pathRoot stringByAppendingPathComponent:component],@"conversion reads ID after current root and repeats it in path and filename");
    PSet(pathHelper,@"_videoID",@"after-url");
    return pathTokens[index];
}
@interface ConversionPathManager : NSObject
@property NSUInteger index;
@end
@implementation ConversionPathManager
- (BOOL)removeItemAtURL:(NSURL *)url error:(NSError **)error {
    if(!pathCallbackActive)return NO;
    [pathEvents addObject:[NSString stringWithFormat:@"remove:%lu",(unsigned long)self.index]];
    NSURL *expected=self.index==0 ? pathResult : pathTokens[self.index-1];
    PCheck(url==expected && error==NULL,@"conversion forwards original removal result, including nil, with a null error pointer");
    PSet(pathHelper,@"_videoID",@"after-removal");
    return NO;
}
- (BOOL)moveItemAtURL:(NSURL *)source toURL:(NSURL *)destination error:(NSError **)error {
    [pathEvents addObject:@"move"];
    PCheck(source==pathResult && destination==pathDestination,@"move forwards original result and captured destination, including nil");
    PCheck(error!=NULL && *error==nil,@"move receives an initially nil error slot");
    if(pathCase==1)*error=[NSError errorWithDomain:@"synthetic.move" code:1 userInfo:nil];
    return pathCase!=1 && pathCase!=2;
}
@end
static ConversionPathManager *pathManagerObjects[5];
static id ConversionPathDefaultManager(id receiver,SEL selector) {
    (void)receiver;(void)selector;
    if(!pathCallbackActive)return pathManagerObjects[0];
    NSUInteger index=pathManagers++;
    PCheck(index<=pathCount,@"conversion manager lookups remain bounded by original calls");
    [pathEvents addObject:[NSString stringWithFormat:@"manager:%lu",(unsigned long)index]];
    return pathManagerObjects[index];
}
static void ConversionPathToast(id receiver,SEL selector,NSString *text,BOOL success) {
    (void)receiver;(void)selector;
    [pathEvents addObject:@"error"];
    PEqual(text,pathCase==1 ? @"Error.PathIssue" : @"converter problem",@"conversion selects original error text");
    PCheck(!success,@"conversion error uses failure presentation");
}
@interface ConversionPathHelper : YTLHelper @end
@implementation ConversionPathHelper
- (void)shareMedia:(NSURL *)url {
    [pathEvents addObject:@"share"];
    PCheck(url==pathDestination,@"conversion routes captured destination, including nil");
    PSet(self,@"_videoID",@"after-share");
}
@end
@interface ConversionPathToastProbe : NSObject @end
@implementation ConversionPathToastProbe
- (void)hide {}
@end

void PRunHelperConversionPaths(void) {
    NSUInteger before=PresentationAssertions;
    pathEvents=[NSMutableArray new];pathRoot=PresentationFixtureRoot;
    ConversionPathRoot *root=[ConversionPathRoot new];
    NSURL *incoming=[NSURL URLWithString:@"file:///synthetic-input"];
    NSURL *result=[NSURL URLWithString:@"file:///synthetic-converted"];
    NSError *failure=[NSError errorWithDomain:@"synthetic.converter" code:9 userInfo:@{NSLocalizedDescriptionKey:@"converter problem"}];
    for(NSUInteger i=0;i<5;i++){pathManagerObjects[i]=[ConversionPathManager new];pathManagerObjects[i].index=i;}
    Method factory=class_getClassMethod(NSURL.class,@selector(fileURLWithPath:));
    Method manager=class_getClassMethod(NSFileManager.class,@selector(defaultManager));
    Method toast=class_getClassMethod(ToastManager.class,@selector(showMessageWithText:isSuccess:));
    originalPathURL=method_setImplementation(factory,(IMP)ConversionPathURL);
    IMP oldManager=method_setImplementation(manager,(IMP)ConversionPathDefaultManager);
    IMP oldToast=method_setImplementation(toast,(IMP)ConversionPathToast);
    @try {
        for(NSUInteger audio=0;audio<2;audio++) {
            pathCount=audio ? 2 : 4;
            pathSuffixes=audio ? @[@"_a.m4a",@"_a.ytpmap"] : @[@"_v.mp4",@"_a.m4a",@"_a.ytpmap",@"_a.ytpmap"];
            for(pathCase=0;pathCase<8;pathCase++) {
                pathCallbackActive=NO;PresentationFixtureRoot=pathRoot;
                pathHelper=[ConversionPathHelper new];PSet(pathHelper,@"_toastView",[ConversionPathToastProbe new]);
                PSet(pathHelper,@"_videoID",@"scheduled-id");PSet(pathHelper,@"_title",@"ScheduledTitle");PSet(pathHelper,@"_format",@"mp4");
                PSet(pathHelper,@"_isVideoDownloaded",@YES);PSet(pathHelper,@"_isAudioOnly",@(audio));
                PSet(pathHelper,@"_videoUrl",incoming);PSet(pathHelper,@"_duration",@10);PresentationPostDownloadIndex=1;
                [PresentationConversions removeAllObjects];
                scheduledURLCount=0;pathScheduling=YES;
                [pathHelper downloadDidFinish:incoming fileName:@"ignored"];
                pathScheduling=NO;
                PCheck(PresentationConversions.count==1,@"one actual conversion callback scheduled");
                void (^completion)(NSURL *,NSError *)=PresentationConversions.lastObject[@"completion"];
                [PresentationConversions removeAllObjects];
                pathDestination=scheduledURLs[audio ? 1:0];
                for(NSUInteger i=0;i<pathCount;i++)pathTokens[i]=(pathCase==6 && i==pathCount-1) ? nil :
                    [NSURL URLWithString:[NSString stringWithFormat:@"file:///synthetic-sidecar-%lu",(unsigned long)i]];
                pathResult=(pathCase==4 || pathCase==5) ? nil : result;
                pathRoots=pathURLs=pathManagers=0;[pathEvents removeAllObjects];
                PresentationFixtureRoot=root;pathCallbackActive=YES;
                completion(pathResult,(pathCase==3 || pathCase==4) ? failure : nil);
                BOOL converterError=pathCase==3 || pathCase==4;
                NSMutableArray *expected=[NSMutableArray arrayWithObject:@"manager:0"];
                if(converterError) [expected addObjectsFromArray:@[@"remove:0",@"error"]];
                else {
                    [expected addObjectsFromArray:@[@"move",pathCase==1 ? @"error" : @"share"]];
                    for(NSUInteger i=0;i<pathCount;i++)[expected addObjectsFromArray:@[[NSString stringWithFormat:@"root:%lu",(unsigned long)i],[NSString stringWithFormat:@"url:%lu",(unsigned long)i]]];
                    for(NSUInteger i=1;i<=pathCount;i++)[expected addObjectsFromArray:@[[NSString stringWithFormat:@"manager:%lu",(unsigned long)i],[NSString stringWithFormat:@"remove:%lu",(unsigned long)i]]];
                }
                PEqual(pathEvents,expected,@"conversion preserves move/error routing, path construction and removal order");
                PCheck(pathRoots==(converterError ? 0:pathCount) && pathURLs==pathRoots && pathManagers==(converterError ? 1:pathCount+1),@"conversion preserves callback-specific call counts");
                pathCallbackActive=NO;PresentationFixtureRoot=pathRoot;
            }
        }
    } @finally {
        pathCallbackActive=NO;PresentationFixtureRoot=pathRoot;
        pathScheduling=NO;scheduledURLs[0]=nil;scheduledURLs[1]=nil;
        method_setImplementation(factory,originalPathURL);method_setImplementation(manager,oldManager);method_setImplementation(toast,oldToast);
        pathHelper=nil;pathRoot=nil;pathEvents=nil;pathResult=nil;pathDestination=nil;pathSuffixes=nil;
        for(NSUInteger i=0;i<4;i++)pathTokens[i]=nil;
        for(NSUInteger i=0;i<5;i++)pathManagerObjects[i]=nil;
        [PresentationConversions removeAllObjects];
    }
    printf("PASS Helper_first_package_paths: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
