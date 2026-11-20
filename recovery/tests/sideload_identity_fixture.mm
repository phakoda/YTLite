#import "../source/Hooks/SideloadIdentityHost.h"
#import "../source/Runtime/InitWorkaround.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "sideload_identity_redirects.h"
#import <objc/message.h>
#include <initializer_list>
#undef objc_getClass
BOOL isYTPFirstTime=YES;
static NSUInteger checks,originals,installed,copyCalls,addCalls,alerts,deviceReads;
static NSMutableArray *events,*retainedResults;
static id originalObject,lastObject,lastSecond,returnedConfiguration;
static CFDictionaryRef copiedQuery;
static CFTypeRef *copiedResultPointer;
static int initializeMode,originalFlag=-1,resolveResult;
static BOOL animatedValue;
static NSString *imagePath,*rootPath,*symbolValue;
static NSArray *stackAddresses;
static OSStatus copyStatus,addStatus;
static NSDictionary *copyAttributes,*addAttributes;
static id device;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
Class SideloadIdentityGetClass(const char*n){return strcmp(n,"NSBundle")==0?[SideloadIdentityBundle class]:objc_getClass(n);}
static void original(){originals++;[events addObject:@"original"];if(originalFlag>=0)isYTPFirstTime=originalFlag;}
static void reset(){originals=installed=copyCalls=addCalls=alerts=deviceReads=0;[events removeAllObjects];lastObject=lastSecond=returnedConfiguration=nil;copiedQuery=NULL;copiedResultPointer=NULL;originalFlag=-1;initializeMode=0;}
void YTLInstallBundleInfoHook(void){CHECK(!isYTPFirstTime);installed++;[events addObject:@"installBundle"];}
int SideloadIdentityDladdr(const void*a,Dl_info*i){CHECK((uintptr_t)a==UINT64_C(0x123456789abcdef0));CHECK(!i->dli_fname&&!i->dli_fbase&&!i->dli_sname&&!i->dli_saddr);[events addObject:@"dladdr"];if(resolveResult)i->dli_fname=imagePath.UTF8String;return resolveResult;}
static void checkQuery(CFDictionaryRef q){NSDictionary*d=(__bridge NSDictionary*)q;CHECK(d.count==4);CHECK([d[(__bridge id)kSecClass]isEqual:(__bridge id)kSecClassGenericPassword]);CHECK([d[(__bridge id)kSecAttrAccount]isEqual:@"bundleSeedID"]);CHECK([d[(__bridge id)kSecAttrService]isEqual:@""]);CHECK([d[(__bridge id)kSecReturnAttributes]isEqual:@YES]);CHECK(!d[(__bridge id)kSecAttrAccessGroup]);}
static void resultAttributes(NSDictionary*d,CFTypeRef*r){if(d){*r=CFBridgingRetain(d);[retainedResults addObject:[NSValue valueWithPointer:*r]];}else*r=NULL;}
OSStatus SideloadIdentityCopy(CFDictionaryRef q,CFTypeRef*r){copyCalls++;[events addObject:@"copy"];checkQuery(q);CHECK(r&&!*r);copiedQuery=q;copiedResultPointer=r;resultAttributes(copyAttributes,r);return copyStatus;}
OSStatus SideloadIdentityAdd(CFDictionaryRef q,CFTypeRef*r){addCalls++;[events addObject:@"add"];checkQuery(q);CHECK(r!=NULL&&r==copiedResultPointer);CHECK(q==copiedQuery);resultAttributes(addAttributes,r);return addStatus;}
@implementation SideloadIdentityThread
+ (NSArray*)callStackReturnAddresses{[events addObject:@"stack"];return stackAddresses;}
@end
@implementation SideloadIdentityBundle
+ (instancetype)mainBundle{static SideloadIdentityBundle*b;if(!b)b=[self new];return b;}
+ (instancetype)ytl_defaultBundle{return[self mainBundle];}
- (NSString*)bundlePath{[events addObject:@"bundlePath"];return rootPath;}
- (NSString*)bundleIdentifier{original();return originalObject;}
- (id)objectForInfoDictionaryKey:(NSString*)key{original();lastObject=key;return originalObject;}
- (NSString*)localizedStringForKey:(NSString*)k value:(NSString*)v table:(NSString*)t{CHECK([k isEqual:@"LoginInfo"]&&!v&&!t);[events addObject:@"localize"];return @"localized login message";}
@end
@implementation YTVersionUtils
+ (NSString*)appName{original();return @"oldname";}
+ (NSString*)appID{original();return @"oldid";}
@end
@implementation GCKBUtils
+ (NSString*)appIdentifier{original();return @"oldid";}
@end
@implementation OGLBundle
+ (NSString*)shortAppName{original();return @"oldname";}
@end
@implementation GVROverlayView
+ (NSString*)appName{original();return @"oldname";}
@end
@implementation OGLPhenotypeFlagServiceImpl
- (NSString*)bundleId{original();return @"oldid";}
@end
@implementation SSOConfiguration {NSString *_shortAppName,*_applicationIdentifier;}
- (instancetype)initWithClientID:(id)c supportedAccountServices:(id)s{original();lastObject=c;lastSecond=s;if(initializeMode==1)return nil;if(initializeMode==2)return(id)[NSObject new];returnedConfiguration=[super init];return returnedConfiguration;}
- (void)setValue:(id)v forKey:(NSString*)k{[events addObject:k];[super setValue:v forKey:k];}
@end
@implementation SSOKeychainHelper
+ (NSString*)accessGroup{original();return @"originalGroup";}
+ (NSString*)sharedAccessGroup{original();return @"originalGroup";}
@end
@implementation SSOKeychainCore
+ (NSString*)accessGroup{original();return @"originalGroup";}
+ (NSString*)sharedAccessGroup{original();return @"originalGroup";}
@end
@implementation SSOFolsomKeychainUtils
+ (NSString*)sharedAccessGroup{original();return @"originalGroup";}
@end
@implementation GNPEncryptionConfiguration
+ (NSString*)keychainAccessGroup{original();return @"originalGroup";}
@end
@implementation UIViewController
- (void)viewDidAppear:(BOOL)a{original();animatedValue=a;}
- (void)viewDidDisappear:(BOOL)a{original();animatedValue=a;}
@end
@implementation YTFirstTimeSignInViewController @end
@implementation YTInlineSignInViewController @end
@implementation UIDevice
+ (instancetype)currentDevice{deviceReads++;return device;}
@end
@interface SymbolDevice:UIDevice { @public NSString *doc_symbolName; }
- (NSString*)doc_symbolName;
@end
@implementation SymbolDevice
- (NSString*)doc_symbolName{return symbolValue;}
@end
@interface YTAlertView:NSObject<YTLSideloadIdentityAlert> @end
@implementation YTAlertView
+ (id<YTLSideloadIdentityAlert>)dialog{alerts++;[events addObject:@"dialog"];return[self new];}
- (void)setTitle:(NSString*)t{CHECK([t isEqual:@"YouTube Plus"]);[events addObject:@"title"];}
- (void)setSubtitle:(NSString*)t{CHECK([t isEqual:@"localized login message"]);[events addObject:@"subtitle"];}
- (void)addTitle:(NSString*)t withAction:(id)a{CHECK([t isEqual:@"OK"]&&!a);[events addObject:@"button"];}
- (void)show{[events addObject:@"show"];}
@end
static id call(id o,SEL s){return((id(*)(id,SEL))objc_msgSend)(o,s);}
static void nameTests(){reset();CHECK([[YTVersionUtils appName]isEqual:@"YouTube"]);CHECK([[YTVersionUtils appID]isEqual:@"com.google.ios.youtube"]);CHECK([[GCKBUtils appIdentifier]isEqual:@"com.google.ios.youtube"]);CHECK([[OGLBundle shortAppName]isEqual:@"YouTube"]);CHECK([[GVROverlayView appName]isEqual:@"YouTube"]);CHECK([[[OGLPhenotypeFlagServiceImpl new]bundleId]isEqual:@"com.google.ios.youtube"]);CHECK(originals==0);}
static void configurationTests(){
    id client=[NSObject new],services=[NSMutableArray new];
    for(int mode=0;mode<3;mode++)for(int nilArgs=0;nilArgs<2;nilArgs++){
        reset();initializeMode=mode;BOOL threw=NO;SSOConfiguration*c;
        @try{c=[[SSOConfiguration alloc]initWithClientID:nilArgs?nil:client supportedAccountServices:nilArgs?nil:services];}@catch(NSException*e){threw=[e.name isEqual:NSUndefinedKeyException];}
        CHECK(originals==1&&lastObject==(nilArgs?nil:client)&&lastSecond==(nilArgs?nil:services));CHECK(threw==(mode==2));
        if(mode==0){CHECK(c==returnedConfiguration);CHECK([[c valueForKey:@"_shortAppName"]isEqual:@"YouTube"]);CHECK([[c valueForKey:@"_applicationIdentifier"]isEqual:@"com.google.ios.youtube"]);CHECK([events isEqual:@[@"original",@"_shortAppName",@"_applicationIdentifier"]]);}
        if(mode==1)CHECK(c==nil&&events.count==1);
    }
}
static void bundleTests(){
    SideloadIdentityBundle*b=[SideloadIdentityBundle new];originalObject=[NSMutableString stringWithString:@"original"];rootPath=@"/Applications/YouTube.app";stackAddresses=@[@0,@1,@(UINT64_C(0x123456789abcdef0))];
    for(NSString*path in @[@"/Applications/YouTube.app/Frameworks/X",@"/Applications/YouTube.app",@"/Applications/YouTube.app-other/X",@"/System/Library/X"])for(int result=0;result<2;result++){
        reset();imagePath=path;resolveResult=result;BOOL useName=result&&[path hasPrefix:rootPath];id value=[b bundleIdentifier];CHECK(useName?[value isEqual:@"com.google.ios.youtube"]:value==originalObject);CHECK(originals==!useName);CHECK([events.firstObject isEqual:@"stack"]);CHECK([events containsObject:@"bundlePath"]==(BOOL)result);
    }
    reset();stackAddresses=@[@0,@1];BOOL threw=NO;@try{[b bundleIdentifier];}@catch(NSException*e){threw=[e.name isEqual:NSRangeException];}CHECK(threw&&originals==0);stackAddresses=@[@0,@1,@(UINT64_C(0x123456789abcdef0))];
    for(NSString*k in @[@"CFBundleIdentifier",@"CFBundleDisplayName",@"CFBundleName",@"CFBundleVersion",@"cfbundleidentifier",@""]){reset();id v=[b objectForInfoDictionaryKey:k];if([k isEqual:@"CFBundleIdentifier"]){CHECK([v isEqual:@"com.google.ios.youtube"]&&originals==0);}else if([k isEqual:@"CFBundleName"]||[k isEqual:@"CFBundleDisplayName"]){CHECK([v isEqual:@"YouTube"]&&originals==0);}else CHECK(v==originalObject&&originals==1&&lastObject==k);}
    reset();CHECK([b objectForInfoDictionaryKey:nil]==originalObject&&lastObject==nil&&originals==1);originalObject=nil;CHECK([b objectForInfoDictionaryKey:@"unknown"]==nil);
}
static void keychainTests(){
    NSArray*owners=@[[SSOKeychainHelper class],[SSOKeychainHelper class],[SSOKeychainCore class],[SSOKeychainCore class],[SSOFolsomKeychainUtils class],[GNPEncryptionConfiguration class]];
    SEL sels[]={@selector(accessGroup),@selector(sharedAccessGroup),@selector(accessGroup),@selector(sharedAccessGroup),@selector(sharedAccessGroup),@selector(keychainAccessGroup)};
    NSString*group=[NSMutableString stringWithString:@"AUTHORIZED.fixture.group"];
    for(NSUInteger i=0;i<owners.count;i++)for(int scenario=0;scenario<7;scenario++){
        reset();copyStatus=errSecSuccess;addStatus=errSecSuccess;copyAttributes=@{(__bridge id)kSecAttrAccessGroup:group};addAttributes=@{(__bridge id)kSecAttrAccessGroup:group};
        if(scenario==1){copyStatus=errSecItemNotFound;copyAttributes=nil;}
        if(scenario==2){copyStatus=errSecItemNotFound;copyAttributes=nil;addStatus=errSecAuthFailed;addAttributes=nil;}
        if(scenario==3){copyStatus=errSecInteractionNotAllowed;copyAttributes=nil;}
        if(scenario==4){copyAttributes=@{};}
        if(scenario==5){copyStatus=errSecInteractionNotAllowed;}
        if(scenario==6){copyStatus=errSecItemNotFound;copyAttributes=nil;addAttributes=@{};}
        id output=call(owners[i],sels[i]);CHECK(output==((scenario==0||scenario==1||scenario==5)?group:nil));CHECK(copyCalls==1&&addCalls==((scenario==1||scenario==2||scenario==6)?1:0)&&originals==0);
    }
}
static void lifecycleTests(){
    YTFirstTimeSignInViewController*v=[YTFirstTimeSignInViewController new];
    for(int initial=0;initial<2;initial++)for(int mutation:{-1,0,1})for(int animated=0;animated<2;animated++){
        reset();isYTPFirstTime=initial;originalFlag=mutation;BOOL flagAfter=mutation<0?initial:mutation;[v viewDidAppear:animated];CHECK(originals==1&&animatedValue==animated&&installed==flagAfter&&!isYTPFirstTime);CHECK([events.firstObject isEqual:@"original"]);
        reset();isYTPFirstTime=initial;originalFlag=mutation;[v viewDidDisappear:animated];CHECK(originals==1&&animatedValue==animated&&alerts==!flagAfter&&isYTPFirstTime==flagAfter);CHECK([events.firstObject isEqual:@"original"]);
    }
    YTInlineSignInViewController*inlineView=[YTInlineSignInViewController new];
    for(int hasIvar=0;hasIvar<2;hasIvar++)for(NSString*symbol in @[@"mac",@"macbook",@"Mac",@"iphone",@""])for(int initial=0;initial<2;initial++)for(int mutation:{-1,0,1})for(int animated=0;animated<2;animated++){
        reset();isYTPFirstTime=initial;originalFlag=mutation;BOOL flagAfter=mutation<0?initial:mutation;device=hasIvar?[SymbolDevice new]:[UIDevice new];symbolValue=symbol;[inlineView viewDidDisappear:animated];CHECK(originals==1&&animatedValue==animated);CHECK(alerts==(hasIvar&&[symbol hasPrefix:@"mac"]&&!flagAfter));CHECK(isYTPFirstTime==flagAfter);CHECK([events.firstObject isEqual:@"original"]);CHECK(deviceReads==(hasIvar?2u:1u));
    }
    reset();device=[SymbolDevice new];symbolValue=nil;isYTPFirstTime=NO;[inlineView viewDidDisappear:NO];CHECK(alerts==0);
}
int main(){@autoreleasepool{
    events=[NSMutableArray new];retainedResults=[NSMutableArray new];YTLInstallSideloadIdentityHooks();nameTests();configurationTests();bundleTests();keychainTests();lifecycleTests();
    // The original helper leaves its CF results retained. Balance only fixture-
    // created dictionaries here after every production behavior assertion.
    for(NSValue*v in retainedResults)CFRelease((CFTypeRef)v.pointerValue);
    printf("%lu actual-hook assertions passed; intercepted keychain and loader calls; zero external requests.\n",(unsigned long)checks);
}return 0;}
