#import "../source/Hooks/GeneralInterfaceHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Presentation/ToastManager.h"
#import "../source/Helpers/YTPPlayerHelper.h"
#import "../source/Support/YTPDB.h"
#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Controls/YTPSpeedPopupController.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
static NSUInteger checks;static NSMapTable *states;static NSMutableDictionary *prefs;static NSMutableArray *events,*reads,*pending;static id available,videoID,opened,handlerSeen,downloaded,senderSeen,speedParent;static int64_t delay;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d %s events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String);exit(1);}}while(0)
static NSMutableDictionary *S(id o){if(!o)return nil;id s=[states objectForKey:o];if(!s){s=[NSMutableDictionary new];[states setObject:s forKey:o];}return s;}
static id N(id o){return o?:NSNull.null;}
static void Orig(id o,SEL s,NSArray *args=@[]){NSString *key=NSStringFromSelector(s);S(o)[key]=@([S(o)[key]unsignedIntegerValue]+1);S(o)[@"args"]=args;[events addObject:key];}
static NSUInteger Calls(id o,NSString *s){return[S(o)[s]unsignedIntegerValue];}
BOOL ytpBool(NSString *key){[reads addObject:key];return[prefs[key]boolValue];}
NSInteger ytpInt(NSString *key){[reads addObject:key];return[prefs[key]integerValue];}
void GeneralAfter(dispatch_time_t when,dispatch_queue_t queue,dispatch_block_t block){CHECK(when==123);CHECK(queue==dispatch_get_main_queue());[pending addObject:[block copy]];}
dispatch_time_t GeneralTime(dispatch_time_t when,int64_t delta){CHECK(when==DISPATCH_TIME_NOW);delay=delta;return 123;}
@implementation UIView
- (void)layoutSubviews{Orig(self,_cmd);}
@end
@implementation UIImage @end
@implementation UIViewController
- (void)viewDidLoad{Orig(self,_cmd);}
- (void)viewDidDisappear:(BOOL)a{Orig(self,_cmd,@[@(a)]);}
- (void)presentViewController:(UIViewController *)c animated:(BOOL)a completion:(void (^)(void))b{Orig(self,_cmd,@[N(c),@(a),N(b)]);}
- (void)dismissViewControllerAnimated:(BOOL)a completion:(void (^)(void))b{Orig(self,_cmd,@[@(a),N(b)]);if(b)[pending addObject:[b copy]];}
- (id)panelIdentifier{return S(self)[@"panel"];}
- (id)parentResponder{S(self)[@"parentReads"]=@([S(self)[@"parentReads"]unsignedIntegerValue]+1);return S(self)[@"parent"];}
- (id)delegate{return S(self)[@"delegate"];}
- (id)valueForUndefinedKey:(NSString *)key{return S(self)[key];}
- (void)setValue:(id)value forUndefinedKey:(NSString *)key{S(self)[key]=value;}
@end
@implementation UIDevice
- (void)setOrientation:(NSInteger)o animated:(BOOL)a{Orig(self,_cmd,@[@(o),@(a)]);}
- (UIUserInterfaceIdiom)userInterfaceIdiom{Orig(self,_cmd);return -7;}
@end
@implementation UIApplication
- (void)openURL:(NSURL *)u options:(NSDictionary *)o completionHandler:(void (^)(BOOL))b{Orig(self,_cmd,@[N(u),N(o),N(b)]);}
@end
@implementation YTToastOffsetController
- (void)update{Orig(self,_cmd);}
- (void)setWasPinnedTop:(BOOL)p{Orig(self,_cmd,@[@(p)]);}
@end
@implementation ToastManager
+ (instancetype)sharedManager{static ToastManager *m;if(!m)m=[ToastManager new];return m;}
- (void)updateAllToasts{[events addObject:@"toastUpdate"];}
@end
@implementation YTWatchViewController
- (void)setFullscreen:(BOOL)v{Orig(self,_cmd,@[@(v)]);}
- (NSUInteger)allowedFullScreenOrientations{Orig(self,_cmd);return 0x8123456789abcdefUL;}
@end
@implementation YTMultiSizeViewController @end
@interface YTLHelper:NSObject @end
@implementation YTLHelper @end
@implementation YTSettingsSectionItemManager
- (void)updatePremiumEarlyAccessSectionWithEntry:(id)e{Orig(self,_cmd,@[N(e)]);}
@end
@implementation YTRightNavigationButtons
- (UIView *)notificationButton{return S(self)[@"notification"];}
- (UIView *)searchButton{return S(self)[@"search"];}
@end
@implementation YTSearchViewController
- (void)viewDidLoad{Orig(self,_cmd);}
- (void)setSuggestions:(id)s{Orig(self,_cmd,@[N(s)]);}
@end
@implementation YTUserDefaults
- (BOOL)areHintsDisabled{Orig(self,_cmd);return YES;}
- (void)setHintsDisabled:(BOOL)v{Orig(self,_cmd,@[@(v)]);}
@end
@implementation UIKeyboardImpl
- (BOOL)floatingForced{Orig(self,_cmd);return NO;}
@end
@implementation ASCollectionView
- (CGSize)sizeForElement:(id<YTLGeneralNode>)e{Orig(self,_cmd,@[N(e)]);return CGSizeMake(123.25,-987.5);}
@end
@implementation ELMTouchCommandPropertiesHandler
- (void)handleTap{Orig(self,_cmd);}
- (id)valueForUndefinedKey:(NSString *)key{return S(self)[key];}
@end
@implementation YTMainAppVideoPlayerOverlayViewController
- (void)didPressVideoQuality:(id)sender{Orig(self,_cmd,@[N(sender)]);}
@end
@implementation YTActionSheetDialogViewController @end
@implementation YTBottomSheetController @end
@interface YTInterstitialElementsViewController:UIViewController @end
@implementation YTInterstitialElementsViewController @end
@interface YTEngagementPanelViewControllerImpl:UIViewController @end
@implementation YTEngagementPanelViewControllerImpl @end
@interface YTMainAppEngagementPanelViewController:UIViewController @end
@implementation YTMainAppEngagementPanelViewController @end
@interface GObj:NSObject<YTLGeneralNode,YTLGeneralPivotItem,YTLGeneralPivotSupported,YTLGeneralPivotBar,YTLGeneralGuideItem,YTLGeneralGuideResponse>
@property(nonatomic,strong) NSArray *yogaChildren,*subnodes;
@property(nonatomic,strong) id<YTLGeneralNode> node;
@property(nonatomic,strong) UIView *view;
@property(nonatomic,strong) UIViewController *closestViewController;
@property(nonatomic,copy) NSString *accessibilityIdentifier,*accessibilityLabel,*text,*pivotIdentifier;
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,strong) NSAttributedString *attributedText;
@property(nonatomic,strong) NSURL *URL;
@property(nonatomic,strong) id<YTLGeneralPivotItem> pivotBarItemRenderer,pivotBarIconOnlyItemRenderer;
@property(nonatomic,strong) id<YTLGeneralPivotBar> pivotBarRenderer;
@property(nonatomic,strong) NSMutableArray *itemsArray;
@end
@implementation GObj
- (NSString *)description{return self.text?:@"ordinary";}
- (id)valueForUndefinedKey:(NSString *)key{if([key isEqual:@"_accessibilityIdentifier"])return self.accessibilityIdentifier;return S(self)[key];}
@end
#define NODE_METHODS \
- (id<YTLGeneralNode>)node{return S(self)[@"node"];} \
- (UIView *)view{return S(self)[@"view"];} \
- (UIViewController *)closestViewController{return S(self)[@"controller"];} \
- (NSString *)accessibilityIdentifier{return S(self)[@"identifier"];} \
- (NSString *)accessibilityLabel{return S(self)[@"label"];} \
- (NSURL *)URL{return S(self)[@"URL"];} \
- (NSArray *)yogaChildren{return S(self)[@"yogaChildren"];} \
- (NSArray *)subnodes{return S(self)[@"subnodes"];} \
- (NSAttributedString *)attributedText{return S(self)[@"text"];} \
- (UIImage *)image{return S(self)[@"image"];} \
- (NSString *)description{return S(self)[@"description"]?:@"node";}
@implementation ASTextNode NODE_METHODS @end
@implementation ASImageNode NODE_METHODS @end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static id d;if(!d)d=[self alloc];return d;}
- (id)objectForKey:(NSString *)key{return prefs[key];}
@end
@implementation NSBundle (GeneralFixture)
+ (NSBundle *)ytl_defaultBundle{return [NSBundle mainBundle];}
@end
@implementation YTPPlayerHelper
+ (NSString *)getVideoID:(id)v{S(self)[@"URL"]=N(v);return videoID;}
+ (void)openVideoWithID:(id)v handler:(id)h{opened=v;handlerSeen=h;[events addObject:@"openVideo"];}
@end
@implementation DownloadMenuHelper
+ (void)showDownloadSheet:(id)p withSender:(id)s{downloaded=N(p);senderSeen=s;[events addObject:@"download"];}
@end
@implementation YTPSleepTimer
+ (instancetype)sharedTimer{static id t;if(!t)t=[self new];return t;}
- (id)getPlayerIfAvailable{return available;}
@end
@implementation YTPSpeedPopupController
+ (instancetype)speedController{static id c;if(!c)c=[self new];return c;}
- (void)presentFromViewController:(UIViewController *)c{speedParent=c;[events addObject:@"speed"];}
@end
static GObj *Pivot(NSString *identifier,BOOL icon){GObj *supported=[GObj new],*item=[GObj new];item.pivotIdentifier=identifier;if(icon)supported.pivotBarIconOnlyItemRenderer=item;else supported.pivotBarItemRenderer=item;return supported;}
@implementation YTIPivotBarRenderer
+ (id<YTLGeneralPivotSupported>)pivotSupportedRenderersWithBrowseId:(NSString *)b title:(NSString *)t iconType:(int)i{GObj *p=Pivot(b,NO);S(p)[@"icon"]=@(i);S(p)[@"title"]=N(t);[events addObject:@"buildPivot"];return p;}
@end
static void GuideOrig(id o,SEL s,id r,id e,id c){Orig(o,s,@[N(r),N(e),N(c)]);GObj *response=r;GObj *item=response.itemsArray.firstObject;S(o)[@"snapshot"]=[item.pivotBarRenderer.itemsArray copy]?:@[];}
@implementation YTGuideServiceCoordinator
- (void)handleResponse:(id<YTLGeneralGuideResponse>)r withCompletion:(id)c{GuideOrig(self,_cmd,r,nil,c);}
- (void)handleResponse:(id<YTLGeneralGuideResponse>)r error:(id)e completion:(id)c{GuideOrig(self,_cmd,r,e,c);}
@end
@implementation YTGuideServiceCoordinatorImpl
- (void)handleResponse:(id<YTLGeneralGuideResponse>)r error:(id)e completion:(id)c{GuideOrig(self,_cmd,r,e,c);}
- (void)handleLegacyResponse:(id<YTLGeneralGuideResponse>)r error:(id)e completion:(id)c{GuideOrig(self,_cmd,r,e,c);}
@end
@implementation YTAppGuideServiceCoordinator
- (void)handleResponse:(id<YTLGeneralGuideResponse>)r error:(id)e completion:(id)c{GuideOrig(self,_cmd,r,e,c);}
@end
static void Reset(void){[prefs removeAllObjects];[events removeAllObjects];[reads removeAllObjects];[pending removeAllObjects];available=nil;videoID=nil;opened=nil;handlerSeen=nil;downloaded=nil;senderSeen=nil;speedParent=nil;}
static void Drain(void){NSArray *blocks=[pending copy];[pending removeAllObjects];for(dispatch_block_t b in blocks)b();}
static GObj *Node(NSString *identifier){GObj *n=[GObj new];n.accessibilityIdentifier=identifier;n.view=[UIView new];return n;}
static ASImageNode *Image(NSString *identifier){ASImageNode *n=[ASImageNode new];UIImage *i=[UIImage new];i.accessibilityIdentifier=identifier;S(n)[@"image"]=i;return n;}
static ELMTouchCommandPropertiesHandler *Tap(GObj *node){ELMTouchCommandPropertiesHandler *h=[ELMTouchCommandPropertiesHandler new];GObj *controller=[GObj new];controller.node=node;S(h)[@"_controller"]=controller;return h;}
static GObj *Response(NSArray *pivots){GObj *response=[GObj new],*item=[GObj new],*bar=[GObj new];bar.itemsArray=[pivots mutableCopy];item.pivotBarRenderer=bar;response.itemsArray=[@[item]mutableCopy];return response;}
static NSMutableArray *Items(GObj *r){GObj *item=r.itemsArray[0];return item.pivotBarRenderer.itemsArray;}
static void TestEarly(void){
 Reset();YTToastOffsetController *toast=[YTToastOffsetController new];[toast update];CHECK([events isEqual:@[@"update",@"toastUpdate"]]);CHECK([ToastManager sharedManager].offsetController==toast);
 for(NSNumber *v in @[@NO,@YES]){[toast setWasPinnedTop:v.boolValue];CHECK([ToastManager sharedManager].isPinnedTop==v.boolValue);CHECK([S(toast)[@"args"]isEqual:@[v]]);YTWatchViewController *w=[YTWatchViewController new];[w setFullscreen:v.boolValue];CHECK([ToastManager sharedManager].isFullscreen==v.boolValue);CHECK([S(w)[@"args"]isEqual:@[v]]);}
 UIDevice *d=[UIDevice new];[events removeAllObjects];[d setOrientation:0x112233445566 animated:YES];CHECK([S(d)[@"args"]isEqual:@[@0x112233445566,@YES]]);CHECK(delay==300000000&&pending.count==1);CHECK([events isEqual:@[@"setOrientation:animated:"]]);Drain();CHECK([events.lastObject isEqual:@"toastUpdate"]);
 UIViewController *vc=[UIViewController new],*other=[UIViewController new];__block BOOL invoked=NO;dispatch_block_t b=^{invoked=YES;};[vc presentViewController:other animated:YES completion:b];CHECK(Calls(vc,@"presentViewController:animated:completion:")==1);CHECK(S(vc)[@"args"][0]==other&&S(vc)[@"args"][2]==b&&!invoked);
 [vc presentViewController:[YTInterstitialElementsViewController new] animated:NO completion:b];CHECK(Calls(vc,@"presentViewController:animated:completion:")==1&&!invoked);
 NSMutableArray *notices=[NSMutableArray new];id observer=[[NSNotificationCenter defaultCenter]addObserverForName:@"GOODHeightDidChangeNotification" object:nil queue:nil usingBlock:^(NSNotification *n){[notices addObject:n];CHECK([events.lastObject isEqual:@"viewDidLoad"]||[events.lastObject isEqual:@"viewDidDisappear:"]);}];
 for(Class c in @[[YTEngagementPanelViewControllerImpl class],[YTMainAppEngagementPanelViewController class],[UIViewController class]])for(NSString *identifier in @[@"xcomment-item-section-y",@"other"]){UIViewController *p=[c new];S(p)[@"panel"]=identifier;[notices removeAllObjects];[p viewDidLoad];[p viewDidDisappear:YES];BOOL match=c!=[UIViewController class]&&[identifier containsString:@"comment-item-section"];CHECK(notices.count==(match?2:0));if(match){CHECK([notices[0]object]==p);CHECK([[notices[0]userInfo][@"height"]isEqual:@90]);CHECK([[notices[1]userInfo][@"height"]isEqual:@0]);}CHECK([S(p)[@"args"]isEqual:@[@YES]]);}
 [[NSNotificationCenter defaultCenter]removeObserver:observer];YTInterstitialElementsViewController *inter=[YTInterstitialElementsViewController new];[inter viewDidLoad];CHECK(Calls(inter,@"dismissViewControllerAnimated:completion:")==1);CHECK([S(inter)[@"args"]isEqual:@[@NO,NSNull.null]]);
}
static void TestSimple(void){
 Reset();YTMultiSizeViewController *multi=[YTMultiSizeViewController new];CHECK(multi.helper==nil);__weak YTLHelper *weak;@autoreleasepool{YTLHelper *h=[YTLHelper new];weak=h;multi.helper=h;CHECK(multi.helper==h);}CHECK(weak!=nil);multi.helper=nil;CHECK(weak==nil);CHECK(strcmp(property_getAttributes(class_getProperty([YTMultiSizeViewController class],"helper")),"T@\"YTLHelper\",&,N")==0);
 YTSettingsSectionItemManager *manager=[YTSettingsSectionItemManager new];[manager updatePremiumEarlyAccessSectionWithEntry:@"entry"];CHECK(!Calls(manager,@"updatePremiumEarlyAccessSectionWithEntry:"));
 for(NSUInteger mask=0;mask<16;mask++){Reset();NSArray *keys=@[@"noNotifsButton",@"noSearchButton",@"noVoiceSearchButton",@"noCast"];for(NSUInteger i=0;i<4;i++)prefs[keys[i]]=@((mask>>i)&1);YTRightNavigationButtons *v=[YTRightNavigationButtons new];UIView *n=[UIView new],*s=[UIView new],*voice=[UIView new],*cast=[UIView new],*ordinary=[UIView new];S(v)[@"notification"]=n;S(v)[@"search"]=s;voice.accessibilityLabel=[[NSBundle mainBundle]localizedStringForKey:@"search.voice.access" value:@"" table:nil];cast.accessibilityIdentifier=@"id.mdx.playbackroute.button";v.subviews=@[voice,cast,ordinary];[v layoutSubviews];CHECK(n.hidden==!!(mask&1));CHECK(s.hidden==!!(mask&2));CHECK(voice.hidden==!!(mask&4));CHECK(cast.hidden==!!(mask&8));CHECK(!ordinary.hidden);CHECK(Calls(v,@"layoutSubviews")==1);[prefs removeAllObjects];[v layoutSubviews];CHECK(n.hidden==!!(mask&1));}
 for(NSNumber *enabled in @[@NO,@YES]){Reset();prefs[@"noVoiceSearchButton"]=enabled;YTSearchViewController *s=[YTSearchViewController new];S(s)[@"_isVoiceSearchAllowed"]=@YES;[s viewDidLoad];CHECK(Calls(s,@"viewDidLoad")==1);CHECK([S(s)[@"_isVoiceSearchAllowed"]boolValue]==!enabled.boolValue);prefs[@"noSearchHistory"]=enabled;NSArray *suggestions=@[@"s"];[s setSuggestions:suggestions];CHECK(Calls(s,@"setSuggestions:")==!enabled.boolValue);if(!enabled.boolValue)CHECK(S(s)[@"args"][0]==suggestions);
 prefs[@"portraitFullscreen"]=enabled;YTWatchViewController *w=[YTWatchViewController new];CHECK([w allowedFullScreenOrientations]==(enabled.boolValue?0x1a:0x8123456789abcdefUL));CHECK(Calls(w,@"allowedFullScreenOrientations")==!enabled.boolValue);
 prefs[@"noHints"]=enabled;YTUserDefaults *u=[YTUserDefaults new];CHECK([u areHintsDisabled]==enabled.boolValue);CHECK(!Calls(u,@"areHintsDisabled"));for(NSNumber *input in @[@NO,@YES]){[u setHintsDisabled:input.boolValue];CHECK([S(u)[@"args"][0]boolValue]==(enabled.boolValue||input.boolValue));}
 prefs[@"floatingKeyboard"]=enabled;UIKeyboardImpl *k=[UIKeyboardImpl new];CHECK([k floatingForced]==enabled.boolValue);CHECK(Calls(k,@"floatingForced")==!enabled.boolValue);}
 for(NSNumber *index in @[@0,@1,@2,@-9,@0x100000001LL]){Reset();prefs[@"idiomIndex"]=index;UIDevice *d=[UIDevice new];CHECK([d userInterfaceIdiom]==(!index.integerValue?-7:index.integerValue==1?1:0));CHECK(Calls(d,@"userInterfaceIdiom")==!index.integerValue);CHECK(reads.count==(index.integerValue?2:1));}
}
static void TestURLs(void){
 NSArray *inputs=@[@"https://youtube.com/redirect?q=https%3A%2F%2Fexample.org%2Fok",@"https://notyoutube.com/redirect?q=first&q=second",@"https://youtube.com/redirect?q&q=second",@"https://youtube.com/watch?q=other",@"https://example.org/redirect?q=other",@"https://youtube.com/redirect?q=",@"https://youtube.com/redirect?x=1"];
 NSArray *expected=@[@"https://example.org/ok",@"first",@"second",inputs[3],inputs[4],@"",inputs[6]];
 for(NSNumber *gate in @[@NO,@YES])for(NSUInteger i=0;i<inputs.count;i++){Reset();prefs[@"noLinkTracking"]=gate;UIApplication *app=[UIApplication new];NSURL *url=[NSURL URLWithString:inputs[i]];NSDictionary *options=@{@"sentinel":@7};__block BOOL invoked=NO;void(^completion)(BOOL)=^(BOOL b){invoked=YES;};[app openURL:url options:options completionHandler:completion];CHECK(Calls(app,@"openURL:options:completionHandler:")==1);CHECK([[S(app)[@"args"][0]absoluteString]isEqual:gate.boolValue?expected[i]:inputs[i]]);CHECK(S(app)[@"args"][1]==options&&S(app)[@"args"][2]==completion&&!invoked);}
}
static void TestSize(void){
 NSArray *ids=@[@"id.video.remix.button",@"id.video.share.button",@"id.ui.add_to.offline.button",@"id.video.add_to.button"];
 NSArray *keys=@[@"playerNoRemix",@"playerNoShare",@"playerNoDownload",@"playerNoSave"];
 for(NSUInteger i=0;i<ids.count;i++)for(NSNumber *gate in @[@NO,@YES])for(NSNumber *bar in @[@NO,@YES]){Reset();prefs[keys[i]]=gate;ASCollectionView *v=[ASCollectionView new];v.accessibilityIdentifier=bar.boolValue?@"id.video.scrollable_action_bar":@"other";GObj *e=[GObj new],*root=[GObj new],*first=[GObj new],*child=[GObj new];child.text=[NSString stringWithFormat:@"<%@>",ids[i]];first.yogaChildren=@[[GObj new],child];root.yogaChildren=@[first];e.node=root;CGSize size=[v sizeForElement:e];BOOL hide=gate.boolValue&&bar.boolValue;CHECK(CGSizeEqualToSize(size,hide?CGSizeZero:CGSizeMake(123.25,-987.5)));CHECK(Calls(v,@"sizeForElement:")==!hide);if(!hide)CHECK(S(v)[@"args"][0]==e);}
 NSArray *arrays=@[[YTPDB thanks],[YTPDB clip],[YTPDB report],[YTPDB hype],[YTPDB stopAds]],*labelKeys=@[@"playerNoThanks",@"playerNoClip",@"playerNoReport",@"playerNoHype",@"playerNoStopAds"];
 for(NSUInteger i=0;i<arrays.count;i++)for(NSString *title in arrays[i])for(NSNumber *gate in @[@NO,@YES]){Reset();prefs[labelKeys[i]]=gate;ASCollectionView *v=[ASCollectionView new];v.accessibilityIdentifier=@"id.video.scrollable_action_bar";GObj *e=[GObj new],*root=[GObj new],*first=[GObj new],*child=[GObj new];ASTextNode *text=[ASTextNode new];S(text)[@"text"]=[[NSAttributedString alloc]initWithString:title];child.yogaChildren=@[[GObj new],text];first.yogaChildren=@[child];root.yogaChildren=@[first];e.node=root;CHECK(CGSizeEqualToSize([v sizeForElement:e],gate.boolValue?CGSizeZero:CGSizeMake(123.25,-987.5)));CHECK(Calls(v,@"sizeForElement:")==!gate.boolValue);child.yogaChildren=@[text];CHECK(CGSizeEqualToSize([v sizeForElement:e],CGSizeMake(123.25,-987.5)));GObj *fake=[GObj new];fake.attributedText=[[NSAttributedString alloc]initWithString:title];child.yogaChildren=@[fake,fake];CHECK(CGSizeEqualToSize([v sizeForElement:e],CGSizeMake(123.25,-987.5)));}
 Reset();ASCollectionView *v=[ASCollectionView new];v.accessibilityIdentifier=@"id.video.scrollable_action_bar";CHECK(CGSizeEqualToSize([v sizeForElement:nil],CGSizeMake(123.25,-987.5)));
}
static void TestGuide(void){
 for(NSUInteger wrapper=0;wrapper<5;wrapper++){Reset();prefs[@"activeTabs"]=@[@"B",@"A"];GObj *a=Pivot(@"A",NO),*b=Pivot(@"B",NO),*r=Response(@[a,b,Pivot(@"removed",NO)]);NSMutableArray *alias=Items(r);NSObject *error=[NSObject new];__block BOOL invoked=NO;dispatch_block_t c=^{invoked=YES;};id target;NSString *selector;
 switch(wrapper){case 0:target=[YTGuideServiceCoordinator new];selector=@"handleResponse:withCompletion:";[target handleResponse:r withCompletion:c];break;case 1:target=[YTGuideServiceCoordinator new];selector=@"handleResponse:error:completion:";[target handleResponse:r error:error completion:c];break;case 2:target=[YTAppGuideServiceCoordinator new];selector=@"handleResponse:error:completion:";[target handleResponse:r error:error completion:c];break;case 3:target=[YTGuideServiceCoordinatorImpl new];selector=@"handleResponse:error:completion:";[target handleResponse:r error:error completion:c];break;default:target=[YTGuideServiceCoordinatorImpl new];selector=@"handleLegacyResponse:error:completion:";[target handleLegacyResponse:r error:error completion:c];}
 CHECK(Calls(target,selector)==1);CHECK(Items(r)==alias&&[alias isEqual:@[b,a]]);CHECK([S(target)[@"snapshot"]isEqual:@[b,a]]);CHECK(S(target)[@"args"][0]==r&&S(target)[@"args"][2]==c&&!invoked);CHECK(S(target)[@"args"][1]==(wrapper?error:NSNull.null));}
 NSArray *custom=@[@"FEexplore",@"FEhistory",@"VLWL",@"FEpost_home",@"FEhype_leaderboard",@"UC-9-kyTW8ZkZNDHQJ6FgpwQ",@"UC4R8DWoMoI7CAwX8_LjQHig",@"UCOpNcN46UbXVtpKMrmU4Abg",@"UCEgdi0XIXXZ-qJOFPf4JSKw",@"FEnotifications_inbox"];
 for(NSUInteger i=0;i<custom.count;i++){Reset();prefs[@"activeTabs"]=@[@"missing",custom[i]];GObj *r=Response(@[Pivot(@"removed",NO)]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK(Items(r).count==1);GObj *p=Items(r)[0];CHECK([p.pivotBarItemRenderer.pivotIdentifier isEqual:custom[i]]);CHECK([S(p)[@"icon"]intValue]==(i?875+(int)i:292));CHECK([S(p)[@"title"]isEqual:custom[i]]);}
 Reset();GObj *a=Pivot(@"A",NO),*r=Response(@[a]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK([Items(r)isEqual:@[a]]);prefs[@"activeTabs"]=@[];[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK(!Items(r).count);
 Reset();prefs[@"activeTabs"]=@[@"FEexplore"];r=Response(@[]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK(!Items(r).count);
 Reset();prefs[@"activeTabs"]=@[@"FEhistory",@"FEexplore"];GObj *explore=Pivot(@"FEexplore",NO),*history=Pivot(@"FEhistory",NO);r=Response(@[explore,history]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK([Items(r)isEqual:@[explore,history]]);CHECK(![events containsObject:@"buildPivot"]);
 Reset();prefs[@"activeTabs"]=@[@"FEuploads",@"A"];GObj *upload=Pivot(@"FEuploads",YES);r=Response(@[a,upload]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK([Items(r)isEqual:@[upload,a]]);
 Reset();prefs[@"activeTabs"]=@[@"A",@"A"];GObj *a2=Pivot(@"A",NO);r=Response(@[a,a2]);[[YTGuideServiceCoordinator new]handleResponse:r withCompletion:nil];CHECK([Items(r)isEqual:@[a2,a]]);
}
static void TestTap(void){
 for(NSString *identifier in @[@"short-thing",@"eml.video_card",@"eml.cvr",@"other"])for(NSUInteger length=0;length<=11;length++)for(NSNumber *gate in @[@NO,@YES]){Reset();prefs[@"shortsToRegular"]=gate;GObj *root=Node(identifier),*current=root;for(NSUInteger i=0;i<length;i++){GObj *next=Node(i==length-1?@"primary_image":@"child");current.subnodes=@[next];current=next;}current.URL=[NSURL URLWithString:@"https://example.invalid/video"];videoID=@"abc";ELMTouchCommandPropertiesHandler *h=Tap(root);[h handleTap];BOOL success=gate.boolValue&&![identifier isEqual:@"other"]&&length>=1&&length<=10;CHECK(Calls(h,@"handleTap")==!success);CHECK((opened!=nil)==success);if(success){CHECK(opened==videoID&&handlerSeen==h);CHECK(S([YTPPlayerHelper class])[@"URL"]==current.URL);}}
 Reset();prefs[@"shortsToRegular"]=@YES;GObj *root=Node(@"short"),*first=Node(@"primary_image");root.subnodes=@[first];first.subnodes=@[Node(@"primary_image")];ELMTouchCommandPropertiesHandler *h=Tap(root);[h handleTap];CHECK(Calls(h,@"handleTap")==1&&!opened);
 for(NSNumber *gate in @[@NO,@YES])for(NSNumber *index in @[@0,@1,@2,@-1])for(NSNumber *has in @[@NO,@YES]){Reset();prefs[@"downloadManager"]=gate;prefs[@"ytlButtonIndex"]=index;root=Node(@"id.ui.add_to.offline.button");UIViewController *vc=[UIViewController new];root.closestViewController=vc;GObj *provider=[GObj new],*watch=[GObj new];id player=[NSObject new];S(vc)[@"_metadataPanelStateProvider"]=provider;S(provider)[@"_watchViewController"]=watch;if(has.boolValue)S(watch)[@"_playerViewController"]=player;h=Tap(root);[h handleTap];BOOL success=gate.boolValue&&index.integerValue!=1;CHECK(Calls(h,@"handleTap")==!success);CHECK((downloaded!=nil)==success);if(success)CHECK(downloaded==(has.boolValue?player:NSNull.null)&&senderSeen==root.view);}
 for(NSNumber *has in @[@NO,@YES])for(NSNumber *gate in @[@NO,@YES]){Reset();prefs[@"downloadManager"]=gate;root=Node(@"id.elements.list_item");root.subnodes=@[[GObj new],Image(@"wrong"),Image(@"youtube_outline_experimental/arrow_down_24pt")];if(has.boolValue)available=[NSObject new];h=Tap(root);[h handleTap];BOOL success=has.boolValue&&gate.boolValue;CHECK(Calls(h,@"handleTap")==!success);CHECK((downloaded!=nil)==success);if(success)CHECK(downloaded==available&&senderSeen==root.view);}
 for(NSString *icon in @[@"yt_outline_play_arrow_half_circle_24pt",@"youtube_outline_experimental/play_circle_half_dashed_24pt"])for(NSNumber *firstImage in @[@NO,@YES])for(NSNumber *rightParent in @[@NO,@YES]){Reset();root=Node(@"ordinary");ASImageNode *image=Image(icon);root.subnodes=firstImage.boolValue?@[[GObj new],image]:@[Image(@"wrong"),image];UIViewController *vc=[UIViewController new],*delegate=[UIViewController new],*parent=rightParent.boolValue?[YTMainAppVideoPlayerOverlayViewController new]:[UIViewController new];root.closestViewController=vc;S(vc)[@"_delegate"]=delegate;S(delegate)[@"parent"]=parent;h=Tap(root);[h handleTap];BOOL success=firstImage.boolValue&&rightParent.boolValue;CHECK(Calls(h,@"handleTap")==!success);CHECK(pending.count==success&&!speedParent);if(success){CHECK(Calls(delegate,@"dismissViewControllerAnimated:completion:")==1);CHECK([S(delegate)[@"args"][0]boolValue]);CHECK([S(delegate)[@"parentReads"]intValue]==2);S(delegate)[@"parent"]=[UIViewController new];Drain();CHECK(speedParent==parent);}}
 for(NSUInteger mask=0;mask<32;mask++){Reset();prefs[@"classicQuality"]=@((mask&1)!=0);root=Node((mask&2)?@"id.elements.components.overflow_menu_item_7":@"ordinary");root.accessibilityLabel=(mask&4)?@"Video quality 1080p60":@"Auto";UIViewController *vc=(mask&8)?[YTActionSheetDialogViewController new]:[UIViewController new];root.closestViewController=vc;vc.parentViewController=(mask&16)?[YTBottomSheetController new]:[UIViewController new];UIViewController *delegate=[UIViewController new];YTMainAppVideoPlayerOverlayViewController *parent=[YTMainAppVideoPlayerOverlayViewController new];S(vc)[@"delegate"]=delegate;S(delegate)[@"parent"]=parent;h=Tap(root);[h handleTap];BOOL success=mask==31;CHECK(Calls(h,@"handleTap")==!success);CHECK(pending.count==success);CHECK(!Calls(parent,@"didPressVideoQuality:"));if(success){CHECK(Calls(parent,@"dismissViewControllerAnimated:completion:")==1);Drain();CHECK(Calls(parent,@"didPressVideoQuality:")==1);CHECK([S(parent)[@"args"]isEqual:@[NSNull.null]]);}}
}
int main(void){@autoreleasepool{states=[NSMapTable weakToStrongObjectsMapTable];prefs=[NSMutableDictionary new];events=[NSMutableArray new];reads=[NSMutableArray new];pending=[NSMutableArray new];CHECK(!class_getProperty([YTMultiSizeViewController class],"helper"));IMP tapBefore=class_getMethodImplementation([ELMTouchCommandPropertiesHandler class],@selector(handleTap));YTLInstallGeneralInterfaceEarlyHooks();CHECK(tapBefore==class_getMethodImplementation([ELMTouchCommandPropertiesHandler class],@selector(handleTap)));TestEarly();YTLInstallGeneralInterfaceHooks();CHECK(tapBefore!=class_getMethodImplementation([ELMTouchCommandPropertiesHandler class],@selector(handleTap)));TestSimple();TestURLs();TestSize();TestGuide();TestTap();printf("General interface actual Logos fixture: %lu checks passed\n",(unsigned long)checks);}return 0;}
