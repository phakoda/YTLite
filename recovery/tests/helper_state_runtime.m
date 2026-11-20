#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#include <limits.h>

static NSMutableArray *helperReleasedIvars;
@interface HelperIvarLifetimeProbe : NSObject
@property(copy) NSString *name;
@end
@implementation HelperIvarLifetimeProbe
- (void)dealloc { [helperReleasedIvars addObject:_name]; }
@end

static void TestHelperIvarTeardown(void) {
    NSArray *names=@[@"_illegalChars",@"_downloader",@"_toastView",@"_title",@"_videoID",@"_format",
        @"_videoUrl",@"_audioUrl",@"_captionsUrl"];
    helperReleasedIvars=[NSMutableArray new];
    for(NSUInteger mode=0;mode<4;mode++) {
        [helperReleasedIvars removeAllObjects];NSMutableArray *expected=[NSMutableArray new];
        __weak YTLHelper *weakHelper;
        @autoreleasepool {
            YTLHelper *helper=[YTLHelper new];PSettle();weakHelper=helper;
            for(NSUInteger i=0;i<names.count;i++) {
                @autoreleasepool {
                    BOOL present=mode==0 || (mode==1 && i%2==0) || (mode==2 && i%2!=0);
                    HelperIvarLifetimeProbe *token=present ? [HelperIvarLifetimeProbe new] : nil;
                    token.name=names[i];PSet(helper,names[i],token);
                    if(present)[expected insertObject:names[i] atIndex:0];
                }
            }
            PSet(helper,@"_duration",@(ULLONG_MAX));PSet(helper,@"_audioSize",@(ULLONG_MAX));
            PSet(helper,@"_isVideoDownloaded",@YES);PSet(helper,@"_isAudioOnly",@YES);
            PCheck(helperReleasedIvars.count==0,@"all nonnil object ivars own their values until helper teardown");
        }
        PCheck(weakHelper==nil,@"helper is released when its final owner leaves scope");
        PEqual(helperReleasedIvars,expected,@"compiler-generated destructor releases each object ivar once in original reverse order and skips scalar fields");
    }
    helperReleasedIvars=nil;
}

static void TestHelperWiFiFlags(void) {
    BOOL oldCreated=PresentationReachabilityCreated,oldSucceeded=PresentationReachabilitySucceeded;
    uint32_t oldFlags=PresentationReachabilityFlags;
    NSMutableArray<NSNumber *> *irrelevant=[NSMutableArray arrayWithObjects:@0,@(UINT32_MAX & ~0x40002U),nil];
    for(NSUInteger bit=0;bit<32;bit++)if(bit!=1 && bit!=18)[irrelevant addObject:@(UINT32_C(1)<<bit)];
    PresentationReachabilityCreated=YES;
    @try {
        for(NSUInteger readSucceeded=0;readSucceeded<2;readSucceeded++)
            for(NSUInteger relevant=0;relevant<4;relevant++)
                for(NSNumber *other in irrelevant) {
                    BOOL reachable=(relevant&1)!=0,cellular=(relevant&2)!=0;
                    PresentationReachabilitySucceeded=readSucceeded!=0;
                    PresentationReachabilityFlags=other.unsignedIntValue | (reachable ? 2U : 0U) | (cellular ? 0x40000U : 0U);
                    PCheck([YTLHelper isConnectedToWiFi]==(readSucceeded && reachable && !cellular),
                        @"WiFi depends only on a successful flags read, reachable bit and absent cellular bit");
                }
        unsigned char expected[16]={16,2};NSData *address=(id)PLast(@"reachability.address");
        PCheck(address.length==sizeof(expected) && memcmp(address.bytes,expected,sizeof(expected))==0,
            @"reachability receives the complete original zero IPv4 socket address");
    } @finally {
        PresentationReachabilityCreated=oldCreated;PresentationReachabilitySucceeded=oldSucceeded;
        PresentationReachabilityFlags=oldFlags;
    }
}

void PRunHelperState(void) {
    NSUInteger before=PresentationAssertions;
    TestHelperIvarTeardown();TestHelperWiFiFlags();
    printf("PASS Helper_first_package_state: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
