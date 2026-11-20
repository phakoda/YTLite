#import "../source/Hooks/MediaPolicyHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import <objc/message.h>
#import <objc/runtime.h>
#include <initializer_list>
static NSUInteger checks,calls;
static BOOL originalBool,lastBool;
static int32_t lastType;
static id originalObject,lastObject,lastReceiver;
static SEL lastSelector;
static NSMutableDictionary *prefs;
static NSMutableArray *reads,*events;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
BOOL ytpBool(NSString*k){[reads addObject:k];[events addObject:k];return [prefs[k]boolValue];}
static void record(id receiver,SEL selector){calls++;lastReceiver=receiver;lastSelector=selector;[events addObject:@"orig"];}
static void reset(){calls=0;lastObject=nil;lastReceiver=nil;lastSelector=NULL;lastBool=YES;lastType=-1;[prefs removeAllObjects];[reads removeAllObjects];[events removeAllObjects];}
@implementation YTIPlayabilityStatus
- (BOOL)isPlayableInBackground{record(self,_cmd);return originalBool;}
@end
@implementation MLVideo
- (BOOL)playableInBackground{record(self,_cmd);return originalBool;}
@end
@implementation YTIBackgroundOfflineSettingCategoryEntryRenderer
- (BOOL)isBackgroundEnabled{record(self,_cmd);return originalBool;}
@end
@implementation YTGlobalConfig
- (BOOL)shouldBlockUpgradeDialog{record(self,_cmd);return originalBool;}
@end
@implementation YTIPlayerResponse
- (BOOL)isMonetized{record(self,_cmd);return originalBool;}
- (NSMutableArray*)playerAdsArray{record(self,_cmd);return originalObject;}
- (NSMutableArray*)adSlotsArray{record(self,_cmd);return originalObject;}
- (id)auxiliaryUi{record(self,_cmd);return originalObject;}
- (void)setHasAuxiliaryUi:(BOOL)v{record(self,_cmd);lastBool=v;}
- (void)setAuxiliaryUi:(id)v{record(self,_cmd);lastObject=v;}
@end
@implementation YTIClientMdxGlobalConfig
- (BOOL)enableSkippableAd{record(self,_cmd);return originalBool;}
@end
@implementation YTAdShieldUtils
+ (NSDictionary*)spamSignalsDictionary{record(self,_cmd);return originalObject;}
+ (NSDictionary*)spamSignalsDictionaryWithoutIDFA{record(self,_cmd);return originalObject;}
@end
@implementation YTDataUtils
+ (NSDictionary*)spamSignalsDictionary{record(self,_cmd);return originalObject;}
+ (NSDictionary*)spamSignalsDictionaryWithoutIDFA{record(self,_cmd);return originalObject;}
@end
@implementation YTAdsInnerTubeContextDecorator
- (void)decorateContext:(id)v{record(self,_cmd);lastObject=v;}
@end
@implementation YTAccountScopedAdsInnerTubeContextDecorator
- (void)decorateContext:(id)v{record(self,_cmd);lastObject=v;}
@end
@implementation YTLocalPlaybackController
- (id)createAdsPlaybackCoordinator{record(self,_cmd);return originalObject;}
@end
@implementation MDXSession
- (void)adPlaying:(id)v{record(self,_cmd);lastObject=v;}
@end
@implementation YTIAuxiliaryUi
- (void)setHasMessageRenderers:(BOOL)v{record(self,_cmd);lastBool=v;}
- (void)setMessageRenderers:(id)v{record(self,_cmd);lastObject=v;}
@end
@implementation YTITriggerConditions
- (BOOL)hasPlayerCueRangeSet{record(self,_cmd);return originalBool;}
- (NSUInteger)validAdsStatesArray_Count{record(self,_cmd);return UINT64_MAX;}
@end
@implementation YTIVideoPlaybackRelativePosition
- (int64_t)streamTimeMs{record(self,_cmd);return INT64_MIN;}
- (BOOL)hasStreamTimeMs{record(self,_cmd);return originalBool;}
@end
@implementation YTICoWatchability
- (int32_t)type{record(self,_cmd);return INT32_MIN;}
- (void)setType:(int32_t)v{record(self,_cmd);lastType=v;}
@end
static id callObject(id r,SEL s){return((id(*)(id,SEL))objc_msgSend)(r,s);}
static BOOL callBool(id r,SEL s){return((BOOL(*)(id,SEL))objc_msgSend)(r,s);}
static void callObjectSetter(id r,SEL s,id v){((void(*)(id,SEL,id))objc_msgSend)(r,s,v);}
static void callBoolSetter(id r,SEL s,BOOL v){((void(*)(id,SEL,BOOL))objc_msgSend)(r,s,v);}
static void checkOriginal(id r,SEL s,NSUInteger n){CHECK(calls==n);if(n){CHECK(lastReceiver==r);CHECK(sel_isEqual(lastSelector,s));}}
static void backgroundTests(){
    NSArray*objects=@[[YTIPlayabilityStatus new],[MLVideo new],[YTIBackgroundOfflineSettingCategoryEntryRenderer new]];
    const SEL selectors[]={@selector(isPlayableInBackground),@selector(playableInBackground),@selector(isBackgroundEnabled)};
    for(NSUInteger i=0;i<3;i++)for(int gate=0;gate<2;gate++)for(int native=0;native<2;native++){
        reset();prefs[@"backgroundPlayback"]=@(gate);prefs[@"noAds"]=@(!gate);originalBool=native;CHECK(callBool(objects[i],selectors[i])==gate);CHECK(calls==0);CHECK([reads isEqual:@[@"backgroundPlayback"]]);
    }
}
static void gatedTests(){
    NSArray*objects=@[[YTGlobalConfig new],[YTIPlayerResponse new],[YTIClientMdxGlobalConfig new]];
    const SEL selectors[]={@selector(shouldBlockUpgradeDialog),@selector(isMonetized),@selector(enableSkippableAd)};
    for(NSUInteger i=0;i<3;i++)for(int gate=0;gate<2;gate++)for(int native=0;native<2;native++){
        reset();prefs[@"noAds"]=@(gate);originalBool=native;CHECK(callBool(objects[i],selectors[i])==(gate?(i!=1):native));checkOriginal(objects[i],selectors[i],!gate);CHECK([reads isEqual:@[@"noAds"]]);CHECK([events.firstObject isEqual:@"noAds"]);
    }
    YTIPlayerResponse*r=[YTIPlayerResponse new];originalObject=[NSMutableArray arrayWithObject:@"original"];
    for(SEL s:{@selector(playerAdsArray),@selector(adSlotsArray)}){
        reset();CHECK(callObject(r,s)==originalObject);checkOriginal(r,s,1);
        reset();prefs[@"noAds"]=@YES;NSMutableArray*a=callObject(r,s),*b=callObject(r,s);CHECK(a!=b&&a.count==0&&b.count==0&&calls==0);CHECK([a isKindOfClass:[NSMutableArray class]]);[a addObject:@"changed"];CHECK(a.count==1&&b.count==0&&[originalObject count]==1);CHECK([reads isEqual:@[@"noAds",@"noAds"]]);
        reset();originalObject=nil;CHECK(callObject(r,s)==nil);checkOriginal(r,s,1);originalObject=[NSMutableArray arrayWithObject:@"original"];
    }
    NSArray*classes=@[[YTAdShieldUtils class],[YTDataUtils class]];
    for(Class cls in classes)for(SEL s:{@selector(spamSignalsDictionary),@selector(spamSignalsDictionaryWithoutIDFA)}){
        reset();originalObject=[NSMutableDictionary dictionaryWithObject:@"value" forKey:@"key"];CHECK(callObject(cls,s)==originalObject);checkOriginal(cls,s,1);
        reset();prefs[@"noAds"]=@YES;NSDictionary*a=callObject(cls,s),*b=callObject(cls,s);CHECK(a.count==0&&b.count==0&&a!=nil&&calls==0);CHECK(![a isKindOfClass:[NSMutableDictionary class]]);CHECK(a==b);CHECK([reads isEqual:@[@"noAds",@"noAds"]]);
        reset();originalObject=nil;CHECK(callObject(cls,s)==nil);checkOriginal(cls,s,1);
    }
    YTLocalPlaybackController*local=[YTLocalPlaybackController new];
    for(int gate=0;gate<2;gate++)for(int nilResult=0;nilResult<2;nilResult++){
        reset();prefs[@"noAds"]=@(gate);originalObject=nilResult?nil:[NSObject new];CHECK([local createAdsPlaybackCoordinator]==(gate?nil:originalObject));checkOriginal(local,@selector(createAdsPlaybackCoordinator),!gate);CHECK([reads isEqual:@[@"noAds"]]);
    }
}
static void forwardingTests(){
    id value=[NSObject new];
    for(id object in @[[YTAdsInnerTubeContextDecorator new],[YTAccountScopedAdsInnerTubeContextDecorator new]])for(int gate=0;gate<2;gate++)for(int nilInput=0;nilInput<2;nilInput++){
        reset();prefs[@"noAds"]=@(gate);id input=nilInput?nil:value;callObjectSetter(object,@selector(decorateContext:),input);checkOriginal(object,@selector(decorateContext:),1);CHECK(lastObject==(gate?nil:input));CHECK([events isEqual:@[@"noAds",@"orig"]]);
    }
    MDXSession*session=[MDXSession new];
    for(int gate=0;gate<2;gate++)for(int nilInput=0;nilInput<2;nilInput++){
        reset();prefs[@"noAds"]=@(gate);id input=nilInput?nil:value;[session adPlaying:input];checkOriginal(session,@selector(adPlaying:),!gate);CHECK(lastObject==(gate?nil:input));CHECK([reads isEqual:@[@"noAds"]]);
    }
}
static void protobufTests(){
    YTIPlayerResponse*response=[YTIPlayerResponse new];YTIAuxiliaryUi*aux=[YTIAuxiliaryUi new];YTITriggerConditions*trigger=[YTITriggerConditions new];YTIVideoPlaybackRelativePosition*position=[YTIVideoPlaybackRelativePosition new];YTICoWatchability*co=[YTICoWatchability new];
    originalObject=[NSObject new];originalBool=YES;
    for(int gate=0;gate<2;gate++){
        reset();prefs[@"noAds"]=@(gate);CHECK([response auxiliaryUi]==nil);CHECK(![trigger hasPlayerCueRangeSet]);CHECK([trigger validAdsStatesArray_Count]==(NSUInteger)0);CHECK([position streamTimeMs]==(int64_t)0);CHECK(![position hasStreamTimeMs]);CHECK([co type]==(int32_t)2);CHECK(calls==0&&reads.count==0);
        for(NSUInteger i=0;i<2;i++)for(int input=0;input<2;input++){
            reset();prefs[@"noAds"]=@(gate);id owner=i?aux:response;SEL selector=i?@selector(setHasMessageRenderers:):@selector(setHasAuxiliaryUi:);callBoolSetter(owner,selector,input);checkOriginal(owner,selector,1);CHECK(!lastBool&&reads.count==0);
            reset();prefs[@"noAds"]=@(gate);selector=i?@selector(setMessageRenderers:):@selector(setAuxiliaryUi:);callObjectSetter(owner,selector,input?originalObject:nil);checkOriginal(owner,selector,1);CHECK(lastObject==nil&&reads.count==0);
        }
        for(int32_t input:{INT32_MIN,-1,0,1,2,3,INT32_MAX}){reset();prefs[@"noAds"]=@(gate);[co setType:input];checkOriginal(co,@selector(setType:),1);CHECK(lastType==2&&reads.count==0);}
    }
}
int main(){@autoreleasepool{
    prefs=[NSMutableDictionary new];reads=[NSMutableArray new];events=[NSMutableArray new];
    NSArray*classes=@[[YTIPlayabilityStatus class],[MLVideo class],[YTIBackgroundOfflineSettingCategoryEntryRenderer class],[YTGlobalConfig class],[YTIPlayerResponse class],[YTIClientMdxGlobalConfig class],[YTAdShieldUtils class],[YTDataUtils class],[YTAdsInnerTubeContextDecorator class],[YTAccountScopedAdsInnerTubeContextDecorator class],[YTLocalPlaybackController class],[MDXSession class],[YTIAuxiliaryUi class],[YTITriggerConditions class],[YTIVideoPlaybackRelativePosition class],[YTICoWatchability class]];
    for(Class cls in classes){unsigned n=0;objc_property_t*p=class_copyPropertyList(cls,&n);free(p);CHECK(n==0);}
    YTLInstallMediaPolicyHooks();
    for(Class cls in classes){unsigned n=0;objc_property_t*p=class_copyPropertyList(cls,&n);free(p);CHECK(n==0);}
    backgroundTests();gatedTests();forwardingTests();protobufTests();
    printf("%lu actual-hook assertions passed; original image never executed; zero network requests.\n",(unsigned long)checks);
}return 0;}
