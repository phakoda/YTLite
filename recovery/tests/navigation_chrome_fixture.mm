#import "../source/Hooks/NavigationChromeHost.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/Downloads/YTPMedia.h"
#import "../source/Settings/TabbarVC.h"
#import "../source/Whitelist/SbWhitelistVC.h"
#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "navigation_chrome_redirects.h"
#import <objc/message.h>
#undef NSClassFromString
#undef class_getInstanceMethod
BOOL isTabSelected=NO,isOverlayShown=YES;
static NSUInteger checks,originals,resets,partialResets,hideCalls,rendererReads,indicatorReads,styleInits,fontCalls,presentations,openCalls,tabInitializations,sleepCalls;
static NSMutableDictionary *prefs,*gated;
static NSMutableArray *events,*defaultReads,*gateReads,*selected;
static BOOL originalBool,animatedValue,padding,styleAvailable=YES,missingClass,missingMethod,settingsValue;
static id originalObject,rendererObject,lastObject,sleepView;
static NSArray *resetIdentifiers;
static uintptr_t rawSlot;
static double widthValue;
static int scrollMode;
static CGRect frameValue;
static UINavigationController *presented;
static NSURL *opened;

#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
Class NavigationFixtureClass(NSString*name){return missingClass&&[name isEqual:@"YTPivotBarViewController"]?Nil:NSClassFromString(name);}
Method NavigationFixtureMethod(Class cls,SEL s){return missingMethod&&s==@selector(renderer)?NULL:class_getInstanceMethod(cls,s);}
BOOL ytpBool(NSString*key){[events addObject:key];[gateReads addObject:key];return [gated[key]boolValue];}
@implementation UIView
- (instancetype)init{if((self=[super init]))_interactions=[NSMutableArray new];return self;}
- (void)addInteraction:(id)i{[_interactions addObject:i];}
- (void)layoutSubviews{originals++;[events addObject:@"orig"];}
- (void)setFrame:(CGRect)frame{_frame=frame;frameValue=frame;originals++;}
@end
@implementation UIImage @end
@implementation UIFont @end
@implementation UIColor
+ (instancetype)labelColor{return [self new];}
@end
@implementation UIButton
- (instancetype)init{if((self=[super init])){_images=[NSMutableDictionary new];_titles=[NSMutableDictionary new];}return self;}
- (void)setImage:(UIImage*)image forState:(NSUInteger)s{if(image)_images[@(s)]=image;else[_images removeObjectForKey:@(s)];}
- (void)setTitle:(NSString*)title forState:(NSUInteger)s{if(title)_titles[@(s)]=title;else[_titles removeObjectForKey:@(s)];}
@end
@implementation UIViewController
- (void)viewDidAppear:(BOOL)a{originals++;animatedValue=a;[events addObject:@"orig"];}
- (void)presentViewController:(UIViewController*)c animated:(BOOL)a completion:(void(^)(void))completion{presentations++;CHECK(a&&completion==nil);presented=(id)c;}
- (void)hidePivotBar{hideCalls++;}
@end
@implementation UITableViewController @end
@implementation UINavigationBar @end
@implementation UINavigationController
- (instancetype)initWithRootViewController:(UIViewController*)c{if((self=[super init])){_root=c;_navigationBar=[UINavigationBar new];}return self;}
@end
@implementation UIWindow @end
@implementation UIApplication
+ (instancetype)sharedApplication{static UIApplication*a;if(!a)a=[self new];return a;}
- (void)openURL:(NSURL*)url options:(NSDictionary*)options completionHandler:(void(^)(BOOL))completion{openCalls++;opened=url;CHECK(options.count==0&&completion==nil);}
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard{static UIPasteboard*p;if(!p)p=[self new];return p;}
@end
@implementation UIMenuElement @end
@implementation UIAction
+ (instancetype)actionWithTitle:(NSString*)title image:(UIImage*)image identifier:(id)identifier handler:(void(^)(UIAction*))handler{CHECK(identifier==nil&&image!=nil);UIAction*a=[self new];a.title=title;a.image=image;a.handler=handler;return a;}
@end
@implementation UIMenu
+ (instancetype)menuWithTitle:(NSString*)title image:(UIImage*)image identifier:(NSString*)identifier options:(NSUInteger)options children:(NSArray*)children{CHECK(image==nil);UIMenu*m=[self new];m.title=title;m.identifier=identifier;m.options=options;m.children=children;return m;}
+ (instancetype)menuWithTitle:(NSString*)title children:(NSArray*)children{UIMenu*m=[self new];m.title=title;m.children=children;return m;}
@end
@implementation UIContextMenuInteraction
- (instancetype)initWithDelegate:(id)d{if((self=[super init]))_delegate=d;return self;}
@end
@implementation UIContextMenuConfiguration
+ (instancetype)configurationWithIdentifier:(id)i previewProvider:(id)p actionProvider:(UIMenu*(^)(NSArray<UIMenuElement*>*))provider{CHECK(i==nil&&p==nil);UIContextMenuConfiguration*c=[self new];c.provider=provider;return c;}
@end
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
#pragma clang diagnostic ignored "-Wprotocol"
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults*d;if(!d)d=[[self alloc]initWithSuiteName:@"NavigationChromeFixture-unused"];return d;}
- (BOOL)boolForKey:(NSString*)k{[defaultReads addObject:k];[events addObject:k];return [prefs[k]boolValue];}
- (NSInteger)integerForKey:(NSString*)k{[defaultReads addObject:k];return [prefs[k]integerValue];}
- (id)objectForKey:(NSString*)k{[defaultReads addObject:k];return prefs[k];}
@end
@implementation NSBundle (YTLite)
+ (NSBundle*)ytl_defaultBundle{return [NSBundle mainBundle];}
@end
@implementation DVNTableViewController @end
@implementation TabbarVC
- (instancetype)initForSettings:(BOOL)settings{tabInitializations++;settingsValue=settings;return [super init];}
@end
@implementation SbWhitelistVC @end
@implementation YTPSleepTimer
+ (instancetype)sharedTimer{static YTPSleepTimer*t;if(!t)t=[self new];return t;}
- (void)showOptions:(UIView*)view{sleepCalls++;sleepView=view;}
@end
@implementation YTPMedia
+ (instancetype)sharedMedia{static YTPMedia*m;if(!m)m=[self new];return m;}
#define IMAGE(method) + (UIImage*)method{UIImage*i=[UIImage new];i.name=@#method;return i;}
IMAGE(tabbar) IMAGE(link) IMAGE(moon) IMAGE(sponsorblock)
IMAGE(historyTab) IMAGE(historyTabSelected) IMAGE(watchLaterTab) IMAGE(watchLaterTabSelected) IMAGE(postsTab) IMAGE(postsTabSelected) IMAGE(hypeTab) IMAGE(hypeTabSelected) IMAGE(musicTab) IMAGE(musicTabSelected) IMAGE(liveTab) IMAGE(liveTabSelected) IMAGE(gamingTab) IMAGE(gamingTabSelected) IMAGE(sportsTab) IMAGE(sportsTabSelected) IMAGE(notificationsTab) IMAGE(notificationsTabSelected)
@end
@implementation YTDefaultTypeStyle
- (instancetype)init{styleInits++;return [super init];}
- (BOOL)respondsToSelector:(SEL)s{if(s==@selector(ytSansFontOfSize:weight:))return styleAvailable;return [super respondsToSelector:s];}
- (UIFont*)ytSansFontOfSize:(CGFloat)s weight:(CGFloat)w{fontCalls++;CHECK(s==20&&w==UIFontWeightBold);return [UIFont new];}
@end
@implementation YTQTMButton
- (void)setSizeWithPaddingAndInsets:(BOOL)value{padding=value;}
@end
@implementation YTHeaderView
- (BOOL)stickyNavHeaderEnabled{originals++;return originalBool;}
- (BOOL)clipsToStatusArea{originals++;return originalBool;}
@end
@implementation YTChipCloudCell
- (id)framesForChipViewsWithWidth:(double)w{originals++;widthValue=w;return originalObject;}
@end
@implementation YTMySubsFilterHeaderView
- (void)setChipFilterView:(id)v{originals++;lastObject=v;}
@end
@implementation YTHeaderContentComboView
- (void)enableSubheaderBarWithView:(id)v{originals++;lastObject=v;}
- (void)setFeedHeaderScrollMode:(int)m{originals++;scrollMode=m;}
@end
@implementation YTIPivotBarRenderer
- (int)backgroundStyle{originals++;return -7;}
@end
@implementation YTPivotBarViewController
- (void)resetViewControllersCache{resets++;[events addObject:@"reset"];}
- (void)resetViewControllersCacheForPivotIdentifiers:(NSArray*)a{partialResets++;resetIdentifiers=a;}
- (void)selectItemWithPivotIdentifier:(NSString*)s{[selected addObject:s?:NSNull.null];}
- (BOOL)isFrostedPivotBarPermitted{originals++;return !originalBool;}
- (id)renderer{originals++;return rendererObject;}
@end
@implementation YTPivotBarView
- (UIView*)itemView1{originals++;return originalObject;}
@end
@implementation YTWatchMiniBarViewController
- (void)updateMiniBarPlayerStateFromRenderer{originals++;}
@end
@implementation YTPlaylistMiniBarView @end
static YTQTMButton *navigationButton;
static UIView *indicator;
static id ancestor,itemRenderer;
@implementation YTPivotBarItemView
- (YTQTMButton*)navigationButton{originals++;[events addObject:@"orig"];return navigationButton;}
- (id<YTLNavigationAncestor>)_viewControllerForAncestor{return ancestor;}
- (id<YTLNavigationRenderer>)renderer{rendererReads++;return itemRenderer;}
- (void)setRenderer:(uintptr_t)r{originals++;rawSlot=r;[events addObject:@"orig"];}
- (UIView*)indicatorDot{indicatorReads++;return indicator;}
@end
@implementation YTAppViewController
- (void)showPivotBar{originals++;isOverlayShown=NO;}
@end
#pragma clang diagnostic pop
@interface Renderer:NSObject<YTLNavigationRenderer,YTLNavigationIcon>
@property unsigned int iconType;
@property(copy) NSString *text;
@end
@implementation Renderer
- (id<YTLNavigationIcon>)icon{return self;}
- (NSString*)description{return _text;}
@end
@interface Ancestor:NSObject<YTLNavigationAncestor>
@property id renderer;
@end
@implementation Ancestor @end
@interface AppDelegate:NSObject<UIApplicationDelegate>
@property UIWindow *window;
@end
@implementation AppDelegate @end
static void Reset(void){originals=resets=partialResets=hideCalls=rendererReads=indicatorReads=styleInits=fontCalls=presentations=openCalls=tabInitializations=sleepCalls=0;[prefs removeAllObjects];[gated removeAllObjects];[events removeAllObjects];[defaultReads removeAllObjects];[gateReads removeAllObjects];[selected removeAllObjects];originalObject=lastObject=nil;resetIdentifiers=nil;presented=nil;opened=nil;styleAvailable=YES;[YTPMedia sharedMedia].cairo=NO;}
static void Early(void){
    YTHeaderView*h=[YTHeaderView new];for(NSNumber*g in @[@NO,@YES])for(NSNumber*o in @[@NO,@YES]){Reset();prefs[@"stickyNavbar"]=g;originalBool=o.boolValue;CHECK([h stickyNavHeaderEnabled]==(g.boolValue?YES:o.boolValue)&&originals==!g.boolValue);originals=0;CHECK([h clipsToStatusArea]==(g.boolValue?NO:o.boolValue)&&originals==!g.boolValue);CHECK(gateReads.count==0);}
    for(NSNumber*noSub in @[@NO,@YES])for(NSNumber*inlineHidden in @[@NO,@YES]){Reset();prefs[@"noSubbar"]=noSub;gated[@"hideInlineComment"]=inlineHidden;originalObject=@"frames";double width=1.123456789123;id r=[[YTChipCloudCell new]framesForChipViewsWithWidth:width];BOOL blocked=noSub.boolValue||inlineHidden.boolValue;CHECK(r==(blocked?nil:originalObject)&&originals==!blocked);if(!blocked)CHECK(widthValue==width);CHECK(gateReads.count==!noSub.boolValue);}
    for(NSNumber*hidden in @[@NO,@YES]){Reset();prefs[@"noSubbar"]=hidden;[[YTMySubsFilterHeaderView new]setChipFilterView:@"chip"];CHECK(originals==!hidden.boolValue);[[YTHeaderContentComboView new]enableSubheaderBarWithView:@"header"];CHECK(originals==2*!hidden.boolValue);for(NSNumber*mode in @[@(INT_MIN),@(-1),@0,@1,@(INT_MAX)]){[[YTHeaderContentComboView new]setFeedHeaderScrollMode:mode.intValue];CHECK(scrollMode==(hidden.boolValue?0:mode.intValue));}}
    for(NSNumber*f in @[@NO,@YES]){Reset();prefs[@"frostedPivot"]=f;CHECK([[YTIPivotBarRenderer new]backgroundStyle]==(f.boolValue?2:1)&&!originals);CHECK([[YTPivotBarViewController new]isFrostedPivotBarPermitted]==f.boolValue&&!originals);}
    YTPivotBarViewController*c=[YTPivotBarViewController new];c.parentViewController=[UIViewController new];
    for(NSNumber*already in @[@NO,@YES])for(NSNumber*shorts in @[@NO,@YES]){Reset();isTabSelected=already.boolValue;prefs[@"shortsOnlyMode"]=shorts;prefs[@"startupTab"]=@"FElibrary";[c viewDidAppear:YES];CHECK(originals==1&&animatedValue&&[events.firstObject isEqual:@"orig"]);BOOL first=!already.boolValue&&!shorts.boolValue;CHECK(resets==first&&partialResets==first&&isTabSelected==(already.boolValue||first));CHECK(hideCalls==shorts.boolValue);if(first)CHECK([resetIdentifiers isEqual:@[@"FElibrary, FEsubscriptions"]]&&[selected isEqual:@[@"FElibrary"]]);else CHECK([selected isEqual:shorts.boolValue?@[@"FEshorts"]:@[]]);}
    Reset();isTabSelected=NO;[c viewDidAppear:NO];CHECK([selected isEqual:@[NSNull.null]]&&isTabSelected);[c viewDidAppear:YES];CHECK(resets==1&&selected.count==1);
}
static void MainHooks(void){
    for(NSNumber*g in @[@NO,@YES]){Reset();gated[@"miniplayer"]=g;[[YTWatchMiniBarViewController new]updateMiniBarPlayerStateFromRenderer];CHECK(originals==!g.boolValue);}
    Reset();CGRect f=CGRectMake(-1.123456789,2e99,3.5,-7.25);[[YTPlaylistMiniBarView new]setFrame:f];CHECK(originals==1&&CGRectEqualToRect(f,frameValue));
    YTPivotBarItemView*v=[YTPivotBarItemView new];Ancestor*a=[Ancestor new];ancestor=a;Renderer*r=[Renderer new];itemRenderer=r;Renderer*ar=[Renderer new];a.renderer=ar;
    NSArray*names=@[@"historyTab",@"watchLaterTab",@"postsTab",@"hypeTab",@"musicTab",@"liveTab",@"gamingTab",@"sportsTab",@"notificationsTab"];
    for(unsigned int code=875;code<=885;code++){Reset();navigationButton=[YTQTMButton new];r.iconType=code;ar.text=code%2?@"_CAIRO":@"cairo";CHECK([v navigationButton]==navigationButton&&originals==1&&rendererReads==9);CHECK([YTPMedia sharedMedia].cairo==(code%2!=0));if(code>=876&&code<=884){CHECK([[(UIImage*)navigationButton.images[@0]name]isEqual:names[code-876]]);CHECK([[(UIImage*)navigationButton.images[@4]name]isEqual:[names[code-876]stringByAppendingString:@"Selected"]]);}else CHECK(navigationButton.images.count==0);}
    for(NSNumber*g in @[@NO,@YES]){Reset();r.iconType=0;ar.text=@"_CAIRO";navigationButton=[YTQTMButton new];gated[@"removeLabels"]=g;[v setRenderer:UINT64_C(0xfedcba9876543210)];CHECK(rawSlot==UINT64_C(0xfedcba9876543210)&&padding==!g.boolValue&&originals==(g.boolValue?3:2));CHECK(gateReads.count==2);CHECK(g.boolValue?[navigationButton.titles[@0]isEqual:@""]:navigationButton.titles.count==0);}
    for(NSNumber*g in @[@NO,@YES])for(NSNumber*has in @[@NO,@YES]){Reset();gated[@"removeIndicators"]=g;indicator=has.boolValue?[UIView new]:nil;indicator.alpha=0.6;[v layoutSubviews];CHECK(originals==1&&indicatorReads==(g.boolValue?(has.boolValue?2:1):0));if(indicator)CHECK(indicator.alpha==(g.boolValue?0:0.6));}
    for(NSNumber*g in @[@NO,@YES]){Reset();gated[@"shortsOnlyMode"]=g;isOverlayShown=NO;[[YTAppViewController new]showPivotBar];CHECK(originals==!g.boolValue&&isOverlayShown==!g.boolValue);}
}
static void Menus(void){
    __weak YTPivotBarView *weakBar; UIContextMenuConfiguration *retainedConfiguration;
    @autoreleasepool {YTPivotBarView *temporary=[YTPivotBarView new];weakBar=temporary;retainedConfiguration=[temporary contextMenuInteraction:nil configurationForMenuAtLocation:CGPointZero];}
    CHECK(weakBar==nil&&retainedConfiguration!=nil); // Original captured self is unsafe-unretained; never invoke after deallocation.
    YTPivotBarView*bar=[YTPivotBarView new];Reset();originalObject=[UIView new];UIView*item=[bar itemView1];CHECK(item==originalObject&&item.userInteractionEnabled&&item.interactions.count==1);CHECK([(UIContextMenuInteraction*)item.interactions[0]delegate]==bar);[bar itemView1];CHECK(item.interactions.count==2);originalObject=nil;CHECK([bar itemView1]==nil);
    for(NSNumber*mode in @[@(-1),@0,@1,@2,@3,@4,@(0x100000002ULL)]){Reset();prefs[@"ytlSleepTimerIndex"]=mode;UIContextMenuConfiguration*c=[bar contextMenuInteraction:nil configurationForMenuAtLocation:CGPointMake(1.5,-2.5)];CHECK(defaultReads.count==0);UIMenu*m=c.provider(@[]);CHECK([m.title isEqual:@""]&&m.children.count==2);UIMenu*sb=m.children[0],*tabs=m.children[1];CHECK([sb.identifier isEqual:@"sb_menu"]&&sb.options==1&&[tabs.identifier isEqual:@"tabs_menu"]&&tabs.options==1);BOOL sleep=mode.integerValue==2||mode.integerValue==3;CHECK(tabs.children.count==(sleep?3:2)&&sb.children.count==1);CHECK(defaultReads.count==(mode.integerValue==2?1:2));CHECK([[(UIAction*)tabs.children[0]title]isEqual:@"Tabbar"]&&[[(UIAction*)tabs.children[1]title]isEqual:@"OpenLink"]);if(sleep){originalObject=[UIView new];UIAction*a=tabs.children[2];CHECK([a.title isEqual:@"SleepTimer"]);a.handler(a);CHECK(sleepCalls==1&&sleepView==originalObject&&[(UIView*)originalObject interactions].count==1);}}
    AppDelegate*app=[AppDelegate new];app.window=[UIWindow new];app.window.rootViewController=[UIViewController new];[UIApplication sharedApplication].delegate=app;
    Reset();UIContextMenuConfiguration*c=[bar contextMenuInteraction:nil configurationForMenuAtLocation:CGPointZero];UIMenu*m=c.provider(@[]);UIMenu*tabs=m.children[1],*sb=m.children[0];UIAction*tab=tabs.children[0],*link=tabs.children[1],*white=sb.children[0];
    for(NSNumber*available in @[@NO,@YES])for(UIAction*a in @[tab,white]){Reset();styleAvailable=available.boolValue;a.handler(a);CHECK(presentations==1&&presented.modalPresentationStyle==1&&styleInits==1&&fontCalls==available.boolValue);CHECK(presented.navigationBar.titleTextAttributes.count==(available.boolValue?2:0));if(a==tab)CHECK([presented.root isKindOfClass:TabbarVC.class]&&tabInitializations==1&&!settingsValue);else CHECK([presented.root isKindOfClass:SbWhitelistVC.class]);}
    NSArray*inputs=@[@"",@"example.com",@"https://youtube.com/watch?v=x",@"http://youtu.be/x",@"https://youtube-nocookie.com/embed/x",@"https://YOUTUBE.COM/x",@"youtube.com/x",@"other.example/youtube.com",@"HTTPS://youtu.be/x"];
    NSArray*expected=@[NSNull.null,NSNull.null,@"vnd.youtube://youtube.com/watch?v=x",@"vnd.youtube://youtu.be/x",@"vnd.youtube://youtube-nocookie.com/embed/x",NSNull.null,@"vnd.youtube://youtube.com/x",@"vnd.youtube://other.example/youtube.com",@"vnd.youtube://HTTPS://youtu.be/x"];
    for(NSUInteger i=0;i<inputs.count;i++){Reset();[UIPasteboard generalPasteboard].string=inputs[i];link.handler(link);if(expected[i]==NSNull.null)CHECK(!openCalls);else CHECK(openCalls==1&&[opened.absoluteString isEqual:expected[i]]);}
}
static NSDictionary*Properties(void){NSMutableDictionary*d=[NSMutableDictionary new];for(NSString*n in @[@"YTHeaderView",@"YTChipCloudCell",@"YTMySubsFilterHeaderView",@"YTHeaderContentComboView",@"YTIPivotBarRenderer",@"YTPivotBarViewController",@"YTPivotBarView",@"YTWatchMiniBarViewController",@"YTPlaylistMiniBarView",@"YTPivotBarItemView",@"YTAppViewController"]){unsigned int count=0;objc_property_t*p=class_copyPropertyList(NSClassFromString(n),&count);NSMutableArray*a=[NSMutableArray new];for(unsigned int i=0;i<count;i++)[a addObject:@[[NSString stringWithUTF8String:property_getName(p[i])],[NSString stringWithUTF8String:property_getAttributes(p[i])]]];free(p);d[n]=a;}return d;}
int main(void){@autoreleasepool{prefs=[NSMutableDictionary new];gated=[NSMutableDictionary new];events=[NSMutableArray new];defaultReads=[NSMutableArray new];gateReads=[NSMutableArray new];selected=[NSMutableArray new];NSDictionary*properties=Properties();CHECK(!class_getInstanceMethod(YTPivotBarView.class,@selector(contextMenuInteraction:configurationForMenuAtLocation:)));YTLInstallNavigationChromeEarlyHooks();YTLInstallNavigationChromeHooks();CHECK(class_getInstanceMethod(YTPivotBarView.class,@selector(contextMenuInteraction:configurationForMenuAtLocation:)));Early();MainHooks();Menus();
    YTPivotBarViewController*controller=[YTPivotBarViewController new];Method method=class_getInstanceMethod(YTPivotBarViewController.class,@selector(renderer));IMP old=method_getImplementation(method);missingClass=YES;YTLInstallNavigationChromeRendererHook();CHECK(method_getImplementation(method)==old);missingClass=NO;missingMethod=YES;YTLInstallNavigationChromeRendererHook();CHECK(method_getImplementation(method)==old);missingMethod=NO;YTLInstallNavigationChromeRendererHook();CHECK(method_getImplementation(method)!=old);
    for(id text in @[@"_CAIRO",@"plain",@"_cairo",NSNull.null])for(NSNumber*initial in @[@NO,@YES]){Reset();rendererObject=text==NSNull.null?nil:text;[YTPMedia sharedMedia].cairo=initial.boolValue;CHECK([controller renderer]==rendererObject&&originals==1);CHECK([YTPMedia sharedMedia].cairo==(initial.boolValue||[text isEqual:@"_CAIRO"]));}CHECK([properties isEqual:Properties()]);printf("NavigationChrome: %lu actual-hook assertions passed across 17 registrations and manual renderer\n",(unsigned long)checks);}return 0;}
