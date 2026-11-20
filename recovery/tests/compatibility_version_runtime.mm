#import "../source/Hooks/CompatibilityVersionHost.h"
#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../source/Helpers/YTPPlayerHelper.h"
#import "../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>
static NSUInteger checks;
#define CHECK(...) do { checks++; if(!(__VA_ARGS__)){NSLog(@"FAIL %d %s",__LINE__,#__VA_ARGS__);exit(1);} } while(0)
static NSString *gateVersion,*detailVersion;
static NSMutableArray *events;
static NSArray<NSNumber *> *originalIconValues;
static NSUInteger iconCalls;
static NSString *forwardedName,*forwardedBundle,*forwardedText,*parsedDescription;
static UIColor *forwardedColor;
static UIImage *originalImage,*replacementImage;
static id openedID,openedHandler;
static NSUInteger bundleLookups,dictionaryLookups,nodeReads,parentResponderReads;
static BOOL parseNil;
@implementation VersionFixtureBundle
+ (instancetype)mainBundle { static VersionFixtureBundle *b;if(!b)b=[self new];return b; }
+ (instancetype)ytl_defaultBundle { return self.mainBundle; }
- (id)objectForInfoDictionaryKey:(NSString *)k { CHECK([k isEqual:@"CFBundleShortVersionString"]);bundleLookups++;return gateVersion; }
- (NSDictionary *)infoDictionary { dictionaryLookups++;return detailVersion?@{@"CFBundleShortVersionString":detailVersion}:@{}; }
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color { CHECK([name isEqual:@"moon"]);forwardedColor=color;[events addObject:@"bundleImage"];return replacementImage; }
@end
@implementation UIColor @end
@implementation UIImage @end
@implementation UIView
- (instancetype)init { if((self=[super init]))_layer=[CALayer layer];return self; }
- (void)layoutSubviews { [events addObject:@"layout"];self.layer.cornerRadius=99; }
@end
@implementation UIViewController
- (void)dismissViewControllerAnimated:(BOOL)a completion:(void (^)(void))b { CHECK(a&&!b);[events addObject:@"dismiss"]; }
@end
@implementation GPBMessage @end
@implementation YTIIcon
- (int)iconType { CHECK(iconCalls<originalIconValues.count);return originalIconValues[iconCalls++].intValue; }
@end
@implementation QTMIcon
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color { forwardedName=name;forwardedColor=color;[events addObject:@"qtmOrig"];return originalImage; }
@end
@implementation YTELMResourceLoader
- (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color bundleId:(NSString *)bundle { forwardedName=name;forwardedColor=color;forwardedBundle=bundle;[events addObject:@"loaderOrig"];return originalImage; }
@end
@implementation YTWatchFloatingMiniplayerWithControlsOverlayView @end
@implementation YTVersionUtils
+ (NSString *)appVersion { [events addObject:@"versionOrig"];return @"originalVersion"; }
@end
@implementation YTSettingsCell
- (void)setDetailText:(NSString *)text { forwardedText=text;[events addObject:@"detailOrig"]; }
@end
@implementation ELMTouchCommandPropertiesHandler
- (void)handleTap { [events addObject:@"tapOrig"]; }
@end
@interface VersionFixtureHandler : ELMTouchCommandPropertiesHandler
@property(nonatomic,strong) id controller;
@end
@implementation VersionFixtureHandler @end
@interface VersionFixtureController : NSObject<YTLVersionController>
@property(nonatomic,strong) id<YTLVersionNode> node;
@end
@implementation VersionFixtureController @end
@interface VersionFixtureNode : NSObject<YTLVersionNode>
@property(nonatomic,copy) NSString *accessibilityIdentifier;
@property(nonatomic,strong) NSArray *subnodes;
@property(nonatomic,strong) id<YTLVersionNode> yogaParent;
@property(nonatomic,strong) UIViewController *closestViewController;
@property(nonatomic,strong) id parentResponder;
@end
@implementation VersionFixtureNode
@synthesize subnodes=_subnodes;
- (NSArray *)subnodes { nodeReads++;return _subnodes; }
- (void)setSubnodes:(NSArray *)n { _subnodes=n; }
@end
@interface ASNetworkImageNode ()
@property(nonatomic,strong) UIImage *image;
@end
@implementation ASNetworkImageNode @end
@interface YTVideoWithContextNode ()
@property(nonatomic,strong) NSArray *subnodes;
@property(nonatomic,strong) id<YTLVersionNode> yogaParent;
@property(nonatomic,strong) UIViewController *closestViewController;
@property(nonatomic,strong) id parentResponder;
@end
@implementation YTVideoWithContextNode
@synthesize parentResponder=_parentResponder;
- (id)parentResponder { parentResponderReads++;return _parentResponder; }
- (void)setParentResponder:(id)r { _parentResponder=r; }
@end
@interface YTCellController ()
@property(nonatomic,strong) id entry;
@end
@implementation YTCellController @end
@implementation YTActionSheetDialogViewController @end
@implementation YTPSleepTimer
+ (instancetype)sharedTimer { static YTPSleepTimer *t;if(!t)t=[self new];return t; }
- (void)showOptions:(UIView *)v { CHECK(v==nil);[events addObject:@"sleep"]; }
@end
@implementation YTPPlayerHelper
+ (NSString *)getVideoID:(id)value { parsedDescription=value;[events addObject:@"parse"];return parseNil?nil:@"parsed-id"; }
+ (void)openVideoWithID:(id)videoID handler:(id)handler { openedID=videoID;openedHandler=handler;[events addObject:@"open"]; }
@end
static void Reset(void) { [events removeAllObjects];forwardedName=nil;forwardedColor=nil;forwardedBundle=nil;forwardedText=nil;openedID=nil;openedHandler=nil;parsedDescription=nil;nodeReads=0;parentResponderReads=0; }
static IMP Current(Class cls,SEL sel,BOOL meta) { return method_getImplementation(class_getInstanceMethod(meta?object_getClass(cls):cls,sel)); }
int main(int argc,const char **argv) { @autoreleasepool {
    CHECK(argc==3);gateVersion=strcmp(argv[1],"nil")==0?nil:[NSString stringWithUTF8String:argv[1]];BOOL expectInstall=strcmp(argv[2],"yes")==0;
    events=[NSMutableArray array];originalImage=[UIImage new];replacementImage=[UIImage new];detailVersion=@"actual-visible-version";
    Class classes[]={YTIIcon.class,QTMIcon.class,YTELMResourceLoader.class,YTWatchFloatingMiniplayerWithControlsOverlayView.class,YTVersionUtils.class,YTSettingsCell.class,ELMTouchCommandPropertiesHandler.class};
    SEL selectors[]={@selector(iconType),@selector(imageWithName:color:),@selector(imageWithName:color:bundleId:),@selector(layoutSubviews),@selector(appVersion),@selector(setDetailText:),@selector(handleTap)};
    BOOL metas[]={NO,YES,NO,NO,YES,NO,NO};IMP before[7];for(int i=0;i<7;i++)before[i]=Current(classes[i],selectors[i],metas[i]);
    YTLInstallCompatibilityVersionHooks();CHECK(bundleLookups==1&&dictionaryLookups==0);
    for(int i=0;i<7;i++)CHECK((Current(classes[i],selectors[i],metas[i])!=before[i])==expectInstall);
    if(!expectInstall){CHECK([[YTVersionUtils appVersion]isEqual:@"originalVersion"]);NSLog(@"CompatibilityVersion gate %@: %lu checks passed",gateVersion,(unsigned long)checks);return 0;}
    YTIIcon *icon=[YTIIcon new];NSArray *old=@[@1154,@1155,@1157,@1161,@1162,@1160,@1156];NSArray *mapped=@[@65,@66,@776,@734,@44,@60,@355];
    for(NSUInteger i=0;i<7;i++) {
        NSMutableArray *sequence=[NSMutableArray array];for(NSUInteger n=0;n<i;n++)[sequence addObject:@-100];[sequence addObject:old[i]];originalIconValues=sequence;iconCalls=0;CHECK([icon iconType]==[mapped[i]intValue]);CHECK(iconCalls==i+1);
        originalIconValues=@[old[i],old[i],old[i],old[i],old[i],old[i],old[i],old[i]];iconCalls=0;CHECK([icon iconType]==[mapped[i]intValue]);CHECK(iconCalls==i+1);
    }
    originalIconValues=@[@0,@0,@0,@0,@0,@0,@0,@(-2147483647-1)];iconCalls=0;CHECK([icon iconType]==INT_MIN&&iconCalls==8);
    // A prior value matching a later comparison must not be cached and mapped.
    originalIconValues=@[@1155,@0,@0,@0,@0,@0,@0,@77];iconCalls=0;CHECK([icon iconType]==77&&iconCalls==8);
    UIColor *color=[UIColor new];
    for(id name in @[[NSNull null],@"other",@"youtube_outline/moon_z_24pt"]) {
        Reset();NSString *input=name==NSNull.null?nil:name;UIImage *result=[QTMIcon imageWithName:input color:color];BOOL moon=[input isEqual:@"youtube_outline/moon_z_24pt"];
        CHECK(result==(moon?replacementImage:originalImage)&&forwardedColor==color);CHECK([events isEqual:@[moon?@"bundleImage":@"qtmOrig"]]);CHECK(moon||forwardedName==input);
    }
    Reset();CHECK([QTMIcon imageWithName:@"youtube_outline/moon_z_24pt" color:nil]==replacementImage&&forwardedColor==nil);
    NSArray *sources=@[@"ic_shorts_like_outline_32dp",@"ic_shorts_like_fill_32dp",@"ic_shorts_dislike_outline_32dp",@"ic_shorts_dislike_fill_32dp",@"ic_shorts_comment_outline_32dp",@"ic_shorts_share_outline_32dp",@"ic_shorts_remix_outline_32dp",@"youtube_shorts_24_cairo"];
    NSArray *targets=@[@"ic_shorts_thumb_up_filled_style_c",@"ic_shorts_thumb_up_colored_style_c",@"ic_shorts_thumb_down_filled_style_c",@"ic_shorts_thumb_down_colored_style_c",@"ic_shorts_comment_filled_style_c",@"ic_shorts_share_filled_style_c",@"ic_remix_filled",@"youtube_shorts_24"];
    YTELMResourceLoader *loader=[YTELMResourceLoader new];NSString *bundle=@"bundle";
    for(NSUInteger i=0;i<sources.count;i++){Reset();CHECK([loader imageWithName:sources[i] color:color bundleId:bundle]==originalImage);CHECK([forwardedName isEqual:targets[i]]&&forwardedColor==color&&forwardedBundle==bundle);CHECK([events isEqual:@[@"loaderOrig"]]);}
    Reset();CHECK([loader imageWithName:nil color:nil bundleId:nil]==originalImage&&!forwardedName&&!forwardedColor&&!forwardedBundle);
    CHECK([loader imageWithName:@"unrelated" color:color bundleId:bundle]==originalImage&&[forwardedName isEqual:@"unrelated"]);
    Reset();YTWatchFloatingMiniplayerWithControlsOverlayView *mini=[YTWatchFloatingMiniplayerWithControlsOverlayView new];[mini layoutSubviews];CHECK([events isEqual:@[@"layout"]]&&mini.layer.cornerRadius==12&&mini.layer.masksToBounds);
    Reset();CHECK([[YTVersionUtils appVersion]isEqual:@"20.21.6"]&&events.count==0);
    YTSettingsCell *cell=[YTSettingsCell new];[cell setDetailText:@"20.21.6"];CHECK([forwardedText isEqual:detailVersion]&&dictionaryLookups==1);[cell setDetailText:@"different"];CHECK([forwardedText isEqual:@"different"]&&dictionaryLookups==1);[cell setDetailText:nil];CHECK(!forwardedText);detailVersion=nil;[cell setDetailText:@"20.21.6"];CHECK(!forwardedText&&dictionaryLookups==2);
    Reset();[[ELMTouchCommandPropertiesHandler new]handleTap];CHECK([events isEqual:@[@"tapOrig"]]);
    VersionFixtureHandler *handler=[VersionFixtureHandler new];[events removeAllObjects];[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]);
    VersionFixtureController *controller=[VersionFixtureController new];VersionFixtureNode *node=[VersionFixtureNode new];controller.node=node;handler.controller=controller;
    Reset();node.accessibilityIdentifier=@"other";[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]);
    node.accessibilityIdentifier=@"id.elements.components.overflow_menu_item_1";
    node.subnodes=@[[NSObject new]];Reset();[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]&&nodeReads==1);
    ASNetworkImageNode *imageNode=[ASNetworkImageNode new];imageNode.image=[UIImage new];node.subnodes=@[imageNode];Reset();[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]&&nodeReads==2);
    imageNode.image.accessibilityIdentifier=@"ytp_moon_image";node.closestViewController=[UIViewController new];Reset();[handler handleTap];CHECK([events isEqual:@[@"sleep"]]&&nodeReads==2);
    node.closestViewController=[YTActionSheetDialogViewController new];Reset();[handler handleTap];CHECK([events isEqual:@[@"dismiss",@"sleep"]]);
    node.subnodes=@[];BOOL threw=NO;@try{[handler handleTap];}@catch(NSException *e){threw=[e.name isEqual:NSRangeException];}CHECK(threw);
    node.accessibilityIdentifier=@"eml.vwc";Reset();[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]);
    YTVideoWithContextNode *parent=[YTVideoWithContextNode new];node.yogaParent=parent;Reset();[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]&&parentResponderReads==1);
    YTCellController *entryCell=[YTCellController new];parent.parentResponder=entryCell;entryCell.entry=@"no image";Reset();[handler handleTap];CHECK([events isEqual:@[@"tapOrig"]]&&parentResponderReads==2);
    entryCell.entry=@"payload https://i.ytimg.com/vi/abc123/thumbnail.jpg";Reset();[handler handleTap];CHECK([events isEqual:@[@"parse",@"open"]]&&[openedID isEqual:@"parsed-id"]&&openedHandler==handler&&[parsedDescription isEqual:entryCell.entry]);
    parseNil=YES;Reset();[handler handleTap];CHECK([events isEqual:@[@"parse",@"open"]]&&!openedID&&openedHandler==handler);
    NSLog(@"CompatibilityVersion %@: %lu real Logos runtime checks passed",gateVersion,(unsigned long)checks);
}return 0;}
