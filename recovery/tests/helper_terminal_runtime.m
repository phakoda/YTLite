#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <objc/runtime.h>

static NSMutableArray<NSString *> *terminalEvents;
static YTLHelper *terminalHelper;
static NSString *plainRoot;
static NSURL *cleanupURL,*removedURL;
static id cleanupManager;
static NSUInteger removalCalls,managerCalls;

@interface HelperCleanupRoot : NSString @end
@implementation HelperCleanupRoot
- (NSUInteger)length { return plainRoot.length; }
- (unichar)characterAtIndex:(NSUInteger)index { return [plainRoot characterAtIndex:index]; }
- (NSString *)stringByAppendingString:(NSString *)suffix {
    [terminalEvents addObject:@"temporary-directory"];
    PSet(terminalHelper,@"_videoID",@"cleanup-after-temp");
    return [plainRoot stringByAppendingString:suffix];
}
@end
@interface HelperCleanupFiles : NSObject @end
@implementation HelperCleanupFiles
- (BOOL)removeItemAtURL:(NSURL *)url error:(NSError **)error {
    [terminalEvents addObject:@"remove"];removalCalls++;removedURL=url;
    PCheck(error==NULL,@"cleanup ignores removal error by passing a null error pointer");
    return NO;
}
@end
static id CleanupFileURL(id receiver,SEL selector,NSString *path) {
    (void)receiver;(void)selector;[terminalEvents addObject:@"file-url"];
    PEqual(path,[plainRoot stringByAppendingPathComponent:@"cleanup-after-temp"],
        @"cleanup reads active ID after temporary-directory lookup");
    PSet(terminalHelper,@"_videoID",@"cleanup-after-url");
    return cleanupURL;
}
static id CleanupManager(id receiver,SEL selector) {
    (void)receiver;(void)selector;[terminalEvents addObject:@"manager"];managerCalls++;
    PSet(terminalHelper,@"_videoID",@"cleanup-after-manager");
    return cleanupManager;
}

static NSString *terminalText;
static id terminalRecipient,logToast,descriptionToast;
static NSInteger terminalCode;
@interface HelperTerminalError : NSError @end
@implementation HelperTerminalError
- (NSInteger)code { [terminalEvents addObject:@"code"];return terminalCode; }
- (NSString *)description {
    [terminalEvents addObject:@"log"];
    PSet(terminalHelper,@"_toastView",logToast);
    return @"synthetic terminal error";
}
- (NSString *)localizedDescription {
    [terminalEvents addObject:@"localized"];
    PSet(terminalHelper,@"_toastView",descriptionToast);
    return terminalText;
}
@end
@interface HelperTerminalToast : NSObject @end
@implementation HelperTerminalToast
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success {
    [terminalEvents addObject:@"message"];terminalRecipient=self;
    PCheck(text==terminalText && !success,@"failure forwards description identity and false success, including nil text");
}
@end

void PRunHelperTerminal(void) {
    NSUInteger before=PresentationAssertions;
    terminalEvents=[NSMutableArray new];terminalHelper=[YTLHelper new];
    HelperTerminalError *error=[[HelperTerminalError alloc] initWithDomain:@"synthetic.other-domain" code:0 userInfo:nil];
    logToast=[HelperTerminalToast new];descriptionToast=[HelperTerminalToast new];
    NSInteger codes[]={-999,0,999,((NSInteger)1<<32)-999};
    for(NSUInteger mode=0;mode<6;mode++) {
        [terminalEvents removeAllObjects];terminalRecipient=nil;
        terminalCode=codes[mode<4 ? mode : 1];
        terminalText=mode==4 ? nil : [@"failure text" mutableCopy];
        [terminalHelper downloadDidFailureWithError:mode==5 ? nil : error];
        NSArray *expected=mode==5 ? @[] : mode==0 ? @[@"code"] : @[@"code",@"log",@"localized",@"message"];
        PEqual(terminalEvents,expected,@"failure branches and call order match first package");
        PCheck(terminalRecipient==((mode==0 || mode==5) ? nil : logToast),
            @"failure reads toast after logging but before localized description");
    }
    terminalText=nil;logToast=nil;descriptionToast=nil;terminalRecipient=nil;

    plainRoot=PresentationFixtureRoot;
    HelperCleanupRoot *root=[HelperCleanupRoot new];
    id manager=[HelperCleanupFiles new];
    NSURL *token=[NSURL URLWithString:@"file:///synthetic-cleanup-target"];
    Method fileURL=class_getClassMethod(NSURL.class,@selector(fileURLWithPath:));
    Method defaultManager=class_getClassMethod(NSFileManager.class,@selector(defaultManager));
    IMP oldURL=method_setImplementation(fileURL,(IMP)CleanupFileURL);
    IMP oldManager=method_setImplementation(defaultManager,(IMP)CleanupManager);
    @try {
        PresentationFixtureRoot=root;
        for(NSUInteger mode=0;mode<4;mode++) {
            cleanupURL=(mode&1) ? nil : token;cleanupManager=(mode&2) ? nil : manager;
            removedURL=nil;removalCalls=managerCalls=0;[terminalEvents removeAllObjects];
            PSet(terminalHelper,@"_videoID",@"cleanup-before-temp");
            [terminalHelper cleanup];
            NSArray *expected=cleanupManager ? @[@"temporary-directory",@"file-url",@"manager",@"remove"] :
                @[@"temporary-directory",@"file-url",@"manager"];
            PEqual(terminalEvents,expected,@"cleanup preserves original Foundation call order");
            PCheck(managerCalls==1 && removalCalls==(cleanupManager ? 1u:0u),@"cleanup performs one manager lookup and one removal message");
            PCheck(removedURL==(cleanupManager ? cleanupURL : nil),@"cleanup forwards URL result unchanged, including nil");
            PEqual(PGet(terminalHelper,@"_videoID"),@"cleanup-after-manager",@"cleanup does not reset active ID after removal");
        }
    } @finally {
        PresentationFixtureRoot=plainRoot;
        method_setImplementation(fileURL,oldURL);method_setImplementation(defaultManager,oldManager);
        cleanupURL=nil;removedURL=nil;cleanupManager=nil;terminalHelper=nil;terminalEvents=nil;plainRoot=nil;
    }
    printf("PASS Helper_first_package_terminal: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
