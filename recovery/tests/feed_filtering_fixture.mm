#import "../source/Hooks/FeedFilteringHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import <objc/runtime.h>
static NSUInteger checks;
static NSMapTable *states;
static NSMutableDictionary *prefs;
static NSMutableArray *events,*reads;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { fprintf(stderr,"FAIL %d %s events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String); exit(1); } } while(0)
static NSMutableDictionary *S(id object) { if(!object)return nil; NSMutableDictionary *state=[states objectForKey:object];if(!state){state=[NSMutableDictionary new];[states setObject:state forKey:object];}return state; }
static void Original(id object, SEL selector, NSArray *args=@[]) { NSMutableDictionary *s=S(object);NSString *key=NSStringFromSelector(selector);s[key]=@([s[key]unsignedIntegerValue]+1);s[@"args"]=args;[events addObject:key]; }
static NSUInteger Calls(id object, NSString *selector) { return [S(object)[selector]unsignedIntegerValue]; }
static NSString *Description(id object) { return S(object)[@"description"] ?: @"ordinary"; }
BOOL ytpBool(NSString *key) { [reads addObject:key]; return [prefs[key]boolValue]; }
NSInteger ytpInt(NSString *key) { return [prefs[key]integerValue]; }
@interface FFObject:NSObject<YTLFeedNode,YTLFeedNodeController,YTLFeedCompatibility,YTLFeedElement,YTLFeedRenderer,YTLFeedHorizontalList,YTLFeedShelfContent,YTLFeedIdentifier,YTLFeedEndpoint,YTLFeedExecutor,YTLFeedCommand,YTLFeedWatchModel,YTLFeedThrottleRules>
@property(nonatomic,copy) NSString *text;
@property(nonatomic,copy) NSArray *yogaChildren;
@property(nonatomic,strong) id<YTLFeedNodeController> controller;
@property(nonatomic,copy) NSArray *children;
@property(nonatomic) BOOL hasAdLoggingData,hasCompatibilityOptions;
@property(nonatomic,strong) id<YTLFeedCompatibility> compatibilityOptions;
@property(nonatomic,strong) id<YTLFeedElement> elementRenderer;
@property(nonatomic,strong) NSMutableArray *itemsArray,*commandsArray;
@property(nonatomic,strong) id<YTLFeedHorizontalList> horizontalListRenderer;
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) id<YTLFeedIdentifier> identifier;
@property(nonatomic,strong) id<YTLFeedEndpoint> endpoint;
@property(nonatomic,strong) id<YTLFeedExecutor> executor;
@property(nonatomic,strong) id<YTLFeedCommand> onUiReady;
@property(nonatomic) BOOL throttled;
@property(nonatomic) NSUInteger yogaWrites;
@end
@implementation FFObject
- (NSString *)description{return self.text?:@"ordinary";}
- (id<YTLFeedEndpoint>)yt_showEngagementPanelEndpoint{return self.endpoint;}
- (id<YTLFeedExecutor>)yt_commandExecutorCommand{return self.executor;}
- (void)setYogaChildren:(NSArray *)value{_yogaChildren=[value copy];_yogaWrites++;}
- (void)setThrottledAfterRecentSignIn:(BOOL)value{self.throttled=value;[events addObject:@"throttle-rule"];}
@end
static FFObject *Obj(NSString *text) { FFObject *o=[FFObject new];o.text=text;return o; }
@interface YTSectionListViewController:NSObject
@property(nonatomic,copy) NSString *_browseId;
@end
@implementation YTSectionListViewController @end
@implementation ELMComponent
- (NSString *)description{return Description(self);}
- (id<YTLFeedNode>)node{Original(self,_cmd);return S(self)[@"return"];}
@end
@implementation YTIElementRenderer
- (NSString *)description{return Description(self);}
- (NSData *)elementData{Original(self,_cmd);return S(self)[@"return"];}
- (BOOL)respondsToSelector:(SEL)selector{if(selector==@selector(hasCompatibilityOptions)&&[S(self)[@"missing"]boolValue])return NO;return [super respondsToSelector:selector];}
- (BOOL)hasCompatibilityOptions{return [S(self)[@"has"]boolValue];}
- (id<YTLFeedCompatibility>)compatibilityOptions{return S(self)[@"options"];}
@end
@implementation YTIItemSectionRenderer
- (NSMutableArray *)contentsArray{return S(self)[@"contents"];}
@end
@implementation YTIShelfRenderer
- (NSString *)description{return Description(self);}
- (id<YTLFeedShelfContent>)content{return S(self)[@"content"];}
@end
@implementation YTInnerTubeCollectionViewController
- (id)delegate{return S(self)[@"delegate"];}
- (void)addSectionsFromArray:(NSArray *)sections{Original(self,_cmd,@[sections?:NSNull.null]);S(self)[@"forwarded"]=sections;}
@end
@implementation YTWatchNextResponseViewController
- (void)loadWithModel:(id<YTLFeedWatchModel>)model{Original(self,_cmd,@[(id)model?:NSNull.null]);S(self)[@"readyAtOriginal"]=(id)model.onUiReady?:NSNull.null;}
@end
@implementation YTICommand
- (id<YTLFeedEndpoint>)yt_showEngagementPanelEndpoint{Original(self,_cmd);return S(self)[@"return"];}
- (id<YTLFeedExecutor>)yt_commandExecutorCommand{return S(self)[@"executor"];}
@end
@implementation YTICommandWrapperPromoRenderer
- (void)setHasPromoType:(BOOL)value{Original(self,_cmd,@[@(value)]);}
- (void)setPromoType:(int32_t)value{Original(self,_cmd,@[@(value)]);}
- (void)setHasPromoCommand:(BOOL)value{Original(self,_cmd,@[@(value)]);}
- (void)setPromoCommand:(id)value{Original(self,_cmd,@[value?:NSNull.null]);}
- (void)setHasWatchPageTriggerCondition:(BOOL)value{Original(self,_cmd,@[@(value)]);}
- (void)setWatchPageTriggerCondition:(int32_t)value{Original(self,_cmd,@[@(value)]);}
- (NSMutableArray *)clientFrequencyCapConfigsArray{Original(self,_cmd);return [NSMutableArray arrayWithObject:@"original"];}
- (NSUInteger)clientFrequencyCapConfigsArray_Count{Original(self,_cmd);return 0x123456789;}
@end
@implementation YTIPromoMessageSupportedRenderers
- (uint32_t)rendererOneOfCase{Original(self,_cmd);return 0x87654321;}
- (void)setHasCommandWrapperPromoRenderer:(BOOL)value{Original(self,_cmd,@[@(value)]);}
- (void)setCommandWrapperPromoRenderer:(id)value{Original(self,_cmd,@[value?:NSNull.null]);}
- (void)setHasUpsellDialogRenderer:(BOOL)value{Original(self,_cmd,@[@(value)]);}
- (void)setUpsellDialogRenderer:(id)value{Original(self,_cmd,@[value?:NSNull.null]);}
@end
@implementation YTCommerceEventGroupHandler
- (void)addEventHandlers{Original(self,_cmd);}
@end
@implementation YTInterstitialPromoEventGroupHandler
- (void)addEventHandlers{Original(self,_cmd);}
@end
@implementation YTPromosheetEventGroupHandler
- (void)addEventHandlers{Original(self,_cmd);}
@end
@implementation YTPromoThrottleController
- (BOOL)canShowThrottledPromo{Original(self,_cmd);return YES;}
- (BOOL)canShowThrottledPromoWithFrequencyCap:(id)cap{Original(self,_cmd);return YES;}
- (BOOL)canShowThrottledPromoWithFrequencyCaps:(id)caps{Original(self,_cmd);return YES;}
@end
@implementation YTIShowFullscreenInterstitialCommand
- (BOOL)hasModalClientThrottlingRules{return [S(self)[@"has"]boolValue];}
- (id<YTLFeedThrottleRules>)modalClientThrottlingRules{return S(self)[@"rules"];}
- (BOOL)shouldThrottleInterstitial{Original(self,_cmd);return [S(self)[@"return"]boolValue];}
@end
@implementation YTSurveyController
- (void)showSurveyWithRenderer:(id)renderer surveyParentResponder:(id)responder{Original(self,_cmd);}
@end
@implementation YTPersonalizedSuggestionsCacheProvider
- (id)activeCache{Original(self,_cmd);return S(self)[@"return"];}
@end
static void Reset(void){[prefs removeAllObjects];[events removeAllObjects];[reads removeAllObjects];}
static void TestPromo(void){
    YTICommandWrapperPromoRenderer *wrapper=[YTICommandWrapperPromoRenderer new];YTIPromoMessageSupportedRenderers *supported=[YTIPromoMessageSupportedRenderers new];
    for(int n=0;n<3;n++){
        for(NSString *name in @[@"setHasPromoType:",@"setHasPromoCommand:",@"setHasWatchPageTriggerCondition:"]){SEL sel=NSSelectorFromString(name);((void(*)(id,SEL,BOOL))[wrapper methodForSelector:sel])(wrapper,sel,n!=0);CHECK([S(wrapper)[@"args"]isEqual:@[@NO]]);CHECK(Calls(wrapper,name)==(NSUInteger)n+1);}
        for(NSString *name in @[@"setPromoType:",@"setWatchPageTriggerCondition:"]){SEL sel=NSSelectorFromString(name);((void(*)(id,SEL,int32_t))[wrapper methodForSelector:sel])(wrapper,sel,n==2?INT32_MIN:123);CHECK([S(wrapper)[@"args"]isEqual:@[@0]]);CHECK(Calls(wrapper,name)==(NSUInteger)n+1);}
        [wrapper setPromoCommand:n?Obj(@"command"):nil];CHECK([S(wrapper)[@"args"]isEqual:@[NSNull.null]]);
        for(NSString *name in @[@"setHasCommandWrapperPromoRenderer:",@"setHasUpsellDialogRenderer:"]){SEL sel=NSSelectorFromString(name);((void(*)(id,SEL,BOOL))[supported methodForSelector:sel])(supported,sel,n!=0);CHECK([S(supported)[@"args"]isEqual:@[@NO]]);CHECK(Calls(supported,name)==(NSUInteger)n+1);}
        for(NSString *name in @[@"setCommandWrapperPromoRenderer:",@"setUpsellDialogRenderer:"]){SEL sel=NSSelectorFromString(name);((void(*)(id,SEL,id))[supported methodForSelector:sel])(supported,sel,n?Obj(@"renderer"):nil);CHECK([S(supported)[@"args"]isEqual:@[NSNull.null]]);CHECK(Calls(supported,name)==(NSUInteger)n+1);}
    }
    NSMutableArray *a=[wrapper clientFrequencyCapConfigsArray],*b=[wrapper clientFrequencyCapConfigsArray];CHECK(a!=b&&a.count==0&&b.count==0);[a addObject:@"mutable"];CHECK(b.count==0);CHECK([wrapper clientFrequencyCapConfigsArray_Count]==0&&[supported rendererOneOfCase]==0);CHECK(Calls(wrapper,@"clientFrequencyCapConfigsArray")==0&&Calls(wrapper,@"clientFrequencyCapConfigsArray_Count")==0&&Calls(supported,@"rendererOneOfCase")==0);
    for(id handler in @[[YTCommerceEventGroupHandler new],[YTInterstitialPromoEventGroupHandler new],[YTPromosheetEventGroupHandler new]]){[handler addEventHandlers];CHECK(Calls(handler,@"addEventHandlers")==0);}
    YTPromoThrottleController *throttle=[YTPromoThrottleController new];CHECK(![throttle canShowThrottledPromo]);CHECK(![throttle canShowThrottledPromoWithFrequencyCap:nil]);CHECK(![throttle canShowThrottledPromoWithFrequencyCaps:@[@1,@2]]);CHECK(S(throttle).count==0);
    YTSurveyController *survey=[YTSurveyController new];[survey showSurveyWithRenderer:Obj(@"survey") surveyParentResponder:Obj(@"parent")];CHECK(S(survey).count==0);
    for(int has=0;has<2;has++)for(int result=0;result<2;result++)for(int present=0;present<2;present++){
        Reset();YTIShowFullscreenInterstitialCommand *command=[YTIShowFullscreenInterstitialCommand new];FFObject *rules=Obj(@"rules");S(command)[@"has"]=@(has);S(command)[@"return"]=@(result);if(present)S(command)[@"rules"]=rules;
        CHECK([command shouldThrottleInterstitial]==result);CHECK(rules.throttled==(has&&present));CHECK(Calls(command,@"shouldThrottleInterstitial")==1);CHECK([events isEqual:has&&present?@[@"throttle-rule",@"shouldThrottleInterstitial"]:@[@"shouldThrottleInterstitial"]]);
    }
    for(int gate=0;gate<2;gate++){Reset();prefs[@"noSearchHistory"]=@(gate);YTPersonalizedSuggestionsCacheProvider *provider=[YTPersonalizedSuggestionsCacheProvider new];id value=Obj(@"cache");S(provider)[@"return"]=value;CHECK([provider activeCache]==(gate?nil:value));CHECK(Calls(provider,@"activeCache")==!gate);}
}
static void TestCommands(void){
    for(NSString *text in @[@"ordinary",@"prefix mealbar_promo suffix"]){YTICommand *command=[YTICommand new];FFObject *endpoint=Obj(text);S(command)[@"return"]=endpoint;CHECK([command yt_showEngagementPanelEndpoint]==([text containsString:@"mealbar_promo"]?nil:endpoint));CHECK(Calls(command,@"yt_showEngagementPanelEndpoint")==1);}
    YTICommand *empty=[YTICommand new];CHECK([empty yt_showEngagementPanelEndpoint]==nil&&Calls(empty,@"yt_showEngagementPanelEndpoint")==1);
    for(int gate=0;gate<2;gate++)for(int outerProduct=0;outerProduct<2;outerProduct++){
        Reset();prefs[@"noAds"]=@(gate);FFObject *product=Obj(@"product"),*other=Obj(@"other"),*outer=Obj(@"outer"),*model=Obj(@"model"),*executor=Obj(@"executor");FFObject *tag=Obj(@"identifier");tag.tag=@"PAproduct_list";FFObject *endpoint=Obj(@"endpoint");endpoint.identifier=tag;product.endpoint=endpoint;if(outerProduct)outer.endpoint=endpoint;
        id opaque=[NSObject new];NSMutableArray *commands=[@[other,product,opaque,product]mutableCopy];executor.commandsArray=commands;outer.executor=executor;model.onUiReady=outer;YTWatchNextResponseViewController *vc=[YTWatchNextResponseViewController new];[vc loadWithModel:model];
        CHECK(executor.commandsArray==commands);CHECK([commands isEqual:gate?@[other,opaque]:@[other,product,opaque,product]]);CHECK(model.onUiReady==(gate&&outerProduct?nil:outer));CHECK(S(vc)[@"readyAtOriginal"]==(gate&&outerProduct?NSNull.null:outer));CHECK(Calls(vc,@"loadWithModel:")==1);CHECK([S(vc)[@"args"]firstObject]==model);
    }
    Reset();YTWatchNextResponseViewController *vc=[YTWatchNextResponseViewController new];[vc loadWithModel:nil];CHECK(Calls(vc,@"loadWithModel:")==1);
    FFObject *model=Obj(@"model");model.onUiReady=(id)[NSObject new];[vc loadWithModel:model];CHECK(model.onUiReady!=nil&&Calls(vc,@"loadWithModel:")==2);
}
static YTIElementRenderer *Element(NSString *text, NSData *data, BOOL has, BOOL ad){YTIElementRenderer *e=[YTIElementRenderer new];S(e)[@"description"]=text;if(data)S(e)[@"return"]=data;S(e)[@"has"]=@(has);FFObject *options=Obj(@"options");options.hasAdLoggingData=ad;S(e)[@"options"]=options;return e;}
static void TestDivider(void){
    Reset();NSData *a=[@"a" dataUsingEncoding:NSUTF8StringEncoding],*b=[@"b" dataUsingEncoding:NSUTF8StringEncoding];YTIElementRenderer *ad=Element(@"ad",a,YES,YES);CHECK([ad elementData]==a&&Calls(ad,@"elementData")==1);
    YTIElementRenderer *divider=Element(@"cell_divider",nil,NO,NO);CHECK([divider elementData]==nil);CHECK([divider elementData]==nil&&Calls(divider,@"elementData")==2);S(divider)[@"return"]=b;CHECK([divider elementData]==b&&Calls(divider,@"elementData")==3);S(divider)[@"return"]=a;CHECK([divider elementData]==b&&Calls(divider,@"elementData")==3);
    YTIElementRenderer *second=Element(@"prefix cell_divider suffix",a,NO,NO);CHECK([second elementData]==b&&Calls(second,@"elementData")==0);
    for(int gate=0;gate<2;gate++)for(int has=0;has<2;has++)for(int logging=0;logging<2;logging++)for(int missing=0;missing<2;missing++){
        Reset();prefs[@"noAds"]=@(gate);YTIElementRenderer *e=Element(@"normal",a,has,logging);S(e)[@"missing"]=@(missing);BOOL replaced=has&&logging&&!missing;CHECK([e elementData]==(replaced?b:a));CHECK(Calls(e,@"elementData")==!replaced);CHECK(reads.count==0);
    }
}
static YTIItemSectionRenderer *Section(NSString *description){YTIItemSectionRenderer *section=[YTIItemSectionRenderer new];FFObject *renderer=Obj(@"renderer");renderer.elementRenderer=Obj(description);S(section)[@"contents"]=[@[renderer]mutableCopy];return section;}
static NSArray *Filter(YTInnerTubeCollectionViewController *vc, NSArray *array){NSUInteger n=Calls(vc,@"addSectionsFromArray:");[vc addSectionsFromArray:array];CHECK(Calls(vc,@"addSectionsFromArray:")==n+1);NSArray *result=S(vc)[@"forwarded"];CHECK(![result isKindOfClass:NSMutableArray.class]);return result;}
static void TestSections(void){
    NSArray *cases=@[
        @[@"hideCommunityPosts",@"post_base_wrapper.eml",@"post_base_wrapper.eml FEpost_home"],
        @[@"hideCommunityPosts",@"image_post_root.eml",@"image_post_root.eml FEpost_home"],
        @[@"hideCommunityPosts",@"images_post_root.eml",@"images_post_root.eml FEpost_home"],
        @[@"hideCommunityPosts",@"images_post_root_slim.eml",@"images_post_root_slim.eml FEpost_home"],
        @[@"hideCommunityPosts",@"text_post_root.eml",@"text_post_root.eml FEpost_home"],
        @[@"hideCommunityPosts",@"post_base_wrapper_slim.eml",@"post_base_wrapper_slim.eml FEpost_home"],
        @[@"hideHorizontalFeeds",@"news_shelf_inline_playback FEwhat_to_watch",@"news_shelf_inline_playback"],
        @[@"hideHorizontalFeeds",@"horizontal_shelf.eml FEwhat_to_watch",@"horizontal_shelf.eml"],
        @[@"hideLiveInFeed",@"yt_outline_radar_live_24pt _live.jpg? FEwhat_to_watch",@"_live.jpg? FEwhat_to_watch"],
        @[@"hideLiveInFeed",@"yt_outline_radar_live_24pt immersive_live_header.eml FEwhat_to_watch",@"yt_outline_radar_live_24pt FEwhat_to_watch"],
        @[@"hideLiveInFeed",@"yt_outline_radar_live_24pt live_frame.jpg? FEwhat_to_watch",@"yt_outline_radar_live_24pt live_frame.jpg?"],
        @[@"hideMixPlaylists",@"mix-watch &list=",@"mix-watch"],
        @[@"hideMixPlaylists",@"home_vertical_feed_prominence_group_key &list=",@"&list="],
        @[@"hideInlineComment",@"comment-item-section",@"ordinary"],@[@"hideInlineComment",@"spacing_cell.eml",@"ordinary"],
        @[@"hideGuidelines",@"community_guidelines.eml",@"ordinary"],@[@"hideGuidelines",@"channel_guidelines_entry_banner.eml",@"ordinary"],
        @[@"hideMoreTopicsChip",@"chips_shelf.eml",@"chips_shelf.eml video_lockup"],@[@"hideMoreTopicsChip",@"chips_shelf.eml",@"chips_shelf.eml shorts_video"],
        @[@"hidePlayables",@"horizontal_gaming_shelf.eml",@"ordinary"],@[@"hidePlayables",@".com/playables/",@"ordinary"]
    ];YTInnerTubeCollectionViewController *vc=[YTInnerTubeCollectionViewController new];
    for(NSArray *row in cases)for(int gate=0;gate<2;gate++){
        Reset();prefs[row[0]]=@(gate);id match=Section(row[1]),exception=Section(row[2]),opaque=Obj(row[1]);NSMutableArray *input=[@[match,exception,opaque]mutableCopy];NSArray *result=Filter(vc,input);CHECK([result isEqual:gate?@[exception,opaque]:input]);CHECK(input.count==3);
    }
    for(int gate=0;gate<2;gate++)for(int has=0;has<2;has++)for(int ad=0;ad<2;ad++){
        Reset();prefs[@"noAds"]=@(gate);YTIItemSectionRenderer *section=Section(@"ordinary");FFObject *renderer=S(section)[@"contents"][0];renderer.elementRenderer=(id)Element(@"ordinary",nil,has,ad);CHECK(Filter(vc,@[section]).count==(NSUInteger)!(gate&&has&&ad));
    }
    for(int gate=0;gate<2;gate++)for(int index=0;index<3;index++){
        Reset();prefs[@"noAds"]=@(gate);YTIItemSectionRenderer *section=Section(@"ordinary");NSMutableArray *contents=S(section)[@"contents"];FFObject *second=Obj(@"second"),*third=Obj(@"third");second.elementRenderer=Obj(@"ordinary");third.elementRenderer=Obj(@"ordinary");[contents addObjectsFromArray:@[second,third]];((FFObject *)((FFObject *)contents[index]).elementRenderer).text=@"brand_promo";
        CHECK(Filter(vc,@[section]).count==(NSUInteger)!(gate&&index<2));CHECK(contents.count==3);
    }
    Reset();YTIItemSectionRenderer *empty=[YTIItemSectionRenderer new];S(empty)[@"contents"]=[NSMutableArray new];CHECK([Filter(vc,@[empty])isEqual:@[empty]]);CHECK(Filter(vc,@[]).count==0);CHECK(Filter(vc,nil)==nil);
    for(int hide=0;hide<2;hide++)for(int keep=0;keep<2;keep++)for(int subscriptions=0;subscriptions<2;subscriptions++){
        Reset();prefs[@"hideShorts"]=@(hide);prefs[@"keepSubsShorts"]=@(keep);YTSectionListViewController *delegate=[YTSectionListViewController new];delegate._browseId=subscriptions?@"FEsubscriptions":@"FEwhat_to_watch";S(vc)[@"delegate"]=delegate;id shorts=Section(@"shorts_shelf"),history=Section(@"shorts_shelf history*");BOOL removed=hide&&!(keep&&subscriptions);CHECK([Filter(vc,@[shorts,history])isEqual:removed?@[history]:@[shorts,history]]);
    }
    NSArray *shelfCases=@[@[@"hideCommunityPosts",@"post_base_wrapper.eml"],@[@"hideCommunityPosts",@"image_post_root.eml"],@[@"hideCommunityPosts",@"images_post_root.eml"],@[@"hideCommunityPosts",@"images_post_root_slim.eml"],@[@"hideCommunityPosts",@"text_post_root.eml"],@[@"hideCommunityPosts",@"post_base_wrapper_slim.eml"],@[@"hideHorizontalFeeds",@"news_shelf_inline_playback"],@[@"hideHorizontalFeeds",@"horizontal_shelf.eml"],@[@"hideLiveInFeed",@"yt_outline_radar_live_24pt"],@[@"hideMixPlaylists",@"&list="],@[@"hidePlayables",@"horizontal_gaming_shelf.eml"],@[@"hidePlayables",@".com/playables/"]];
    for(NSArray *row in shelfCases)for(int gate=0;gate<2;gate++){
        Reset();prefs[row[0]]=@(gate);YTIShelfRenderer *shelf=[YTIShelfRenderer new];FFObject *content=Obj(@"content"),*list=Obj(@"list"),*match=Obj(row[1]),*keep=Obj(@"ordinary"),*exception=Obj(@"post_base_wrapper.eml FEpost_home");content.horizontalListRenderer=list;list.itemsArray=[@[match,keep,match,exception]mutableCopy];S(shelf)[@"content"]=content;NSMutableArray *items=list.itemsArray;CHECK([Filter(vc,@[shelf])isEqual:@[shelf]]);CHECK(list.itemsArray==items);CHECK([items isEqual:gate?@[keep,exception]:@[match,keep,match,exception]]);
    }
    Reset();prefs[@"hideShorts"]=@YES;prefs[@"hideMixPlaylists"]=@YES;YTIShelfRenderer *shelf=[YTIShelfRenderer new];S(shelf)[@"description"]=@"shorts_shelf";FFObject *content=Obj(@"content"),*list=Obj(@"list");content.horizontalListRenderer=list;list.itemsArray=[@[Obj(@"&list=")]mutableCopy];S(shelf)[@"content"]=content;CHECK(Filter(vc,@[shelf]).count==0);CHECK(list.itemsArray.count==0);
}
static FFObject *Node(NSString *text, NSArray *children){FFObject *n=Obj(text);n.yogaChildren=children;n.yogaWrites=0;n.controller=Obj(@"controller");return n;}
static FFObject *RunNode(NSString *description, FFObject *node){ELMComponent *component=[ELMComponent new];S(component)[@"description"]=description;if(node)S(component)[@"return"]=node;CHECK([component node]==node);CHECK(Calls(component,@"node")==1);return node;}
static void TestNodes(void){
    for(int gate=0;gate<2;gate++){Reset();prefs[@"shortsNoProducts"]=@(gate);FFObject *node=Node(@"root",@[Obj(@"a")]);RunNode(@"default_product_sticker.eml",node);CHECK(node.yogaChildren.count==(NSUInteger)!gate);CHECK(node.yogaWrites==(NSUInteger)gate);}
    NSArray *keys=@[@"shortsNoLike",@"shortsNoDislike",@"shortsNoComment",@"shortsNoShare",@"shortsNoRemix"];
    for(NSString *bar in @[@"shorts_action_bar.eml",@"reel_action_bar.eml"])for(NSUInteger mask=0;mask<32;mask++){
        Reset();NSMutableArray *children=[NSMutableArray new],*expected=[NSMutableArray new];for(NSUInteger i=0;i<5;i++){id child=Obj([NSString stringWithFormat:@"%lu",(unsigned long)i]);[children addObject:child];prefs[keys[i]]=@((mask>>i)&1);if(!((mask>>i)&1))[expected addObject:child];}FFObject *node=Node(@"root",children);RunNode(bar,node);CHECK([node.yogaChildren isEqual:expected]);CHECK(children.count==5&&node.yogaWrites==1);CHECK(![node.yogaChildren isKindOfClass:NSMutableArray.class]);
    }
    for(NSUInteger count=3;count<=4;count++){NSArray *carousel=count==3?@[@"carouselNoSub",@"carouselNoLive",@"carouselNoShopping"]:@[@"carouselNoSub",@"carouselNoLive",@"carouselNoTrends",@"carouselNoShopping"];for(NSUInteger mask=0;mask<(1UL<<count);mask++){
        Reset();NSMutableArray *children=[NSMutableArray new],*expected=[NSMutableArray new];for(NSUInteger i=0;i<count;i++){id child=Obj([NSString stringWithFormat:@"%lu",(unsigned long)i]);[children addObject:child];prefs[carousel[i]]=@((mask>>i)&1);if(!((mask>>i)&1))[expected addObject:child];}FFObject *node=Node(@"root",children);RunNode(@"shorts_paused_state.eml",node);CHECK([node.yogaChildren isEqual:expected]&&node.yogaWrites==1);
    }}
    Reset();prefs[@"shortsNoLike"]=@YES;id duplicate=Obj(@"duplicate");FFObject *node=Node(@"root",@[duplicate,Obj(@"b"),duplicate,Obj(@"d"),Obj(@"e")]);RunNode(@"shorts_action_bar.eml",node);CHECK(node.yogaChildren.count==3&&![node.yogaChildren containsObject:duplicate]);
    for(NSString *name in @[@"shorts_action_bar.eml",@"shorts_paused_state.eml"]){Reset();for(NSString *key in keys)prefs[key]=@YES;FFObject *n=Node(@"root",@[Obj(@"a"),Obj(@"b")]);NSArray *before=n.yogaChildren;RunNode(name,n);CHECK([before isEqual:n.yogaChildren]&&n.yogaWrites==1);RunNode(name,nil);}
    NSArray *meta=@[@[@"shorts_video_title_item.eml",@"shortsNoDescription"],@[@"participation_composer.eml",@"shortsNoCommentBar"],@[@"reel_multi_format_link.eml",@"shortsNoSource"],@[@"reel_sound_metadata.eml",@"shortsNoAudio"]];
    for(NSArray *row in meta)for(int gate=0;gate<2;gate++){
        Reset();prefs[row[1]]=@(gate);FFObject *child=Node(@"child",@[]);((FFObject *)child.controller).children=@[Obj(row[0])];FFObject *keep=Node(@"keep",@[]);FFObject *root=Node(@"root",@[child,keep,child]);RunNode(@"reel_metapanel.eml",root);CHECK([root.yogaChildren isEqual:gate?@[keep]:@[child,keep,child]]);CHECK(root.yogaWrites==1);
    }
    for(int count=0;count<4;count++)for(int gate=0;gate<2;gate++){
        Reset();prefs[@"shortsNoSuggestion"]=@(gate);NSMutableArray *children=[NSMutableArray new];for(int i=0;i<count;i++)[children addObject:Obj(@"id.elements.components.suggested_action")];FFObject *child=Node(@"child",children),*root=Node(@"root",@[child]);RunNode(@"reel_metapanel.eml",root);CHECK(root.yogaChildren.count==(NSUInteger)!(gate&&count==1));
        Reset();prefs[@"shortsNoTitle"]=@(gate);children=[NSMutableArray new];for(int i=0;i<count;i++)[children addObject:Node(@"nested",@[Obj(@"decorated-avatar-id")])];child=Node(@"child",children);root=Node(@"root",@[child]);RunNode(@"reel_metapanel.eml",root);CHECK(root.yogaChildren.count==(NSUInteger)!(gate&&count==2));
    }
    // A recognized earlier metapanel kind returns its own disabled gate; later matches do not win.
    Reset();prefs[@"shortsNoAudio"]=@YES;FFObject *child=Node(@"child",@[]);((FFObject *)child.controller).children=@[Obj(@"shorts_video_title_item.eml reel_sound_metadata.eml")];FFObject *root=Node(@"root",@[child]);RunNode(@"reel_metapanel.eml",root);CHECK(root.yogaChildren.count==1);
    Reset();FFObject *ordinary=Node(@"root",@[Obj(@"keep")]);RunNode(@"unrecognized",ordinary);CHECK(ordinary.yogaWrites==0);RunNode(@"reel_metapanel.eml",nil);
}
int main(int argc,const char **argv){@autoreleasepool{CHECK(argc==2);states=[NSMapTable strongToStrongObjectsMapTable];prefs=[NSMutableDictionary new];events=[NSMutableArray new];reads=[NSMutableArray new];NSData *data=[NSData dataWithContentsOfFile:@(argv[1])];NSDictionary *manifest=[NSJSONSerialization JSONObjectWithData:data options:0 error:nil];CHECK(manifest!=nil);NSMutableArray *prior=[NSMutableArray new];NSMutableDictionary *propertyCounts=[NSMutableDictionary new];
for(NSDictionary *record in manifest[@"registrations"]){Class cls=NSClassFromString(record[@"class_name"]);SEL sel=NSSelectorFromString(record[@"selector"]);Method method=class_getInstanceMethod(cls,sel);CHECK(cls!=Nil&&method!=NULL);[prior addObject:@{ @"imp":[NSValue valueWithPointer:(const void *)method_getImplementation(method)],@"encoding":@(method_getTypeEncoding(method)) }];unsigned count=0;objc_property_t *properties=class_copyPropertyList(cls,&count);free(properties);propertyCounts[record[@"class_name"]]=@(count);}
YTLInstallFeedFilteringHooks();NSUInteger ri=0;for(NSDictionary *record in manifest[@"registrations"]){Class cls=NSClassFromString(record[@"class_name"]);Method method=class_getInstanceMethod(cls,NSSelectorFromString(record[@"selector"]));CHECK((const void *)method_getImplementation(method)!=[prior[ri][@"imp"]pointerValue]);CHECK([@(method_getTypeEncoding(method))isEqual:prior[ri][@"encoding"]]);unsigned count=0;objc_property_t *properties=class_copyPropertyList(cls,&count);free(properties);CHECK(count==[propertyCounts[record[@"class_name"]]unsignedIntValue]);ri++;}CHECK(ri==27);TestPromo();TestCommands();TestDivider();TestSections();TestNodes();printf("Feed filtering runtime: %lu assertions passed\n",(unsigned long)checks);}return 0;}
