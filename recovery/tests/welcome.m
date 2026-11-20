#import "../source/Welcome/WelcomeVC.h"
#import "../source/Welcome/WelcomeHost.h"
#import "../../Utils/NSBundle+YTLite.h"
#import "../../Utils/YTLUserDefaults.h"
#import <objc/message.h>
static NSUInteger checks;
#define CHECK(c) do {checks++;if(!(c)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#c);exit(1);}}while(0)
static NSMutableArray *constraints,*animations;
static UIView *renderedView;
static NSInteger prepared,impacts;
@implementation CALayer
- (void)renderInContext:(CGContextRef)context {CHECK(context==(CGContextRef)(uintptr_t)0x1234); renderedView=self.owner;}
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray *)items {[constraints addObjectsFromArray:items];}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor {return [self constraintEqualToAnchor:anchor constant:0];}
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value {NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;c.constant=value;return c;}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value {return [self constraintEqualToAnchor:nil constant:value];}
@end
@implementation UIColor
+ (instancetype)colorWithWhite:(CGFloat)white alpha:(CGFloat)alpha {UIColor *c=[self new];c.white=white;c.alpha=alpha;return c;}
+ (instancetype)whiteColor{return [self colorWithWhite:1 alpha:1];}
+ (instancetype)clearColor{return [self colorWithWhite:0 alpha:0];}
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha{return [UIColor colorWithWhite:self.white alpha:alpha];}
@end
@implementation UIFont
+ (instancetype)systemFontOfSize:(CGFloat)size {UIFont *f=[self new];f.pointSize=size;return f;}
+ (instancetype)boldSystemFontOfSize:(CGFloat)size {UIFont *f=[self systemFontOfSize:size];f.bold=YES;return f;}
+ (instancetype)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight {UIFont *f=[self systemFontOfSize:size];f.monospaced=YES;f.weight=weight;return f;}
@end
@implementation UIView
- (instancetype)init {if((self=[super init])){_subviews=[NSMutableArray new];_layer=[CALayer new];_layer.owner=self;_userInteractionEnabled=YES;_alpha=1;_transform=CGAffineTransformIdentity;}return self;}
- (instancetype)initWithFrame:(CGRect)frame {if((self=[self init])){self.frame=frame;self.bounds=(CGRect){CGPointZero,frame.size};}return self;}
- (void)addSubview:(UIView *)view {[self.subviews addObject:view];view.superview=self;}
- (void)bringSubviewToFront:(UIView *)view {[self.subviews removeObjectIdenticalTo:view];[self.subviews addObject:view];}
- (void)sendSubviewToBack:(UIView *)view {[self.subviews removeObjectIdenticalTo:view];[self.subviews insertObject:view atIndex:0];}
- (void)removeFromSuperview {[self.superview.subviews removeObjectIdenticalTo:self];self.superview=nil;}
- (void)layoutIfNeeded {self.layoutCount++;}
#define ANCHOR(n) - (NSLayoutAnchor *)n {NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.kind=@#n;return a;}
ANCHOR(centerXAnchor) ANCHOR(centerYAnchor) ANCHOR(widthAnchor) ANCHOR(heightAnchor) ANCHOR(leadingAnchor) ANCHOR(trailingAnchor) ANCHOR(topAnchor) ANCHOR(bottomAnchor)
+ (void)animateWithDuration:(double)duration delay:(double)delay usingSpringWithDamping:(CGFloat)damping initialSpringVelocity:(CGFloat)velocity options:(NSUInteger)options animations:(void (^)(void))body completion:(void (^)(BOOL))completion {
    [animations addObject:@{@"duration":@(duration),@"delay":@(delay),@"damping":@(damping),@"velocity":@(velocity),@"options":@(options),@"body":[body copy],@"completion":[completion copy]}];
}
@end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name {UIImage *i=[self new];i.name=name;i.system=YES;return i;}
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(id)traits {UIImage *i=[self new];i.name=name;i.bundle=bundle;i.traits=traits;return i;}
- (UIImage *)imageWithRenderingMode:(NSInteger)mode {self.renderingMode=mode;return self;}
@end
@implementation UIImageView
- (instancetype)initWithImage:(UIImage *)image {if((self=[super init]))self.image=image;return self;}
@end
@implementation UILabel @end
@implementation UIStackView
- (instancetype)init {if((self=[super init]))_arrangedSubviews=[NSMutableArray new];return self;}
- (instancetype)initWithArrangedSubviews:(NSArray *)views {if((self=[self init]))for(UIView *v in views)[self addArrangedSubview:v];return self;}
- (void)addArrangedSubview:(UIView *)view {[self.arrangedSubviews addObject:view];[self addSubview:view];}
@end
@implementation UIBlurEffect
+ (instancetype)effectWithStyle:(NSInteger)style {UIBlurEffect *e=[self new];e.style=style;return e;}
@end
@implementation UIVisualEffectView
- (instancetype)initWithEffect:(UIBlurEffect *)effect {if((self=[super init])){self.effect=effect;self.contentView=[UIView new];[self addSubview:self.contentView];}return self;}
@end
@implementation UIButton
+ (instancetype)buttonWithType:(NSInteger)type {UIButton *b=[self new];b.type=type;b.titles=[NSMutableDictionary new];b.titleColors=[NSMutableDictionary new];b.titleLabel=[UILabel new];b.imageView=[UIImageView new];return b;}
- (void)setTitle:(NSString *)title forState:(NSUInteger)state {self.titles[@(state)]=title;}
- (void)setTitleColor:(UIColor *)color forState:(NSUInteger)state {self.titleColors[@(state)]=color;}
- (void)setImage:(UIImage *)image forState:(NSUInteger)state {CHECK(state==0);self.imageView.image=image;}
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(NSUInteger)events {self.target=target;self.action=action;self.events=events;}
@end
@implementation UITableView
- (instancetype)initWithFrame:(CGRect)frame style:(NSInteger)style {if((self=[super initWithFrame:frame]))self.style=style;return self;}
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier {CHECK([identifier isEqual:@"cell"]);return self.reusable;}
@end
@implementation UITableViewCell
- (instancetype)initWithStyle:(NSInteger)style reuseIdentifier:(NSString *)identifier {if((self=[super init])){self.style=style;self.reuseIdentifier=identifier;self.textLabel=[UILabel new];self.detailTextLabel=[UILabel new];self.imageView=[UIImageView new];}return self;}
@end
@implementation NSIndexPath (WelcomeFixture)
- (NSInteger)row{return [self indexAtPosition:1];}
- (NSInteger)section{return [self indexAtPosition:0];}
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section {NSUInteger values[2]={section,row};return [self indexPathWithIndexes:values length:2];}
@end
@implementation UINavigationBar
- (void)setBackgroundImage:(UIImage *)image forBarMetrics:(NSInteger)metrics {self.backgroundImage=image;self.metrics=metrics;}
@end
@implementation UINavigationController @end
@implementation UIViewController
- (instancetype)init {if((self=[super init])){_view=[[UIView alloc]initWithFrame:CGRectMake(0,0,390,844)];_navigationController=[UINavigationController new];_navigationController.navigationBar=[UINavigationBar new];}return self;}
- (void)viewDidLoad {self.superViewDidLoad++;}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion {self.dismissed=YES;self.animated=animated;CHECK(completion==nil);}
@end
@implementation UIWindow @end
@interface FixtureDelegate:NSObject<UIApplicationDelegate>
@property(strong) UIWindow *window;
@end
@implementation FixtureDelegate @end
@implementation UIApplication
+ (instancetype)sharedApplication {static UIApplication *app;static dispatch_once_t once;dispatch_once(&once,^{app=[self new];app.openedURLs=[NSMutableArray new];FixtureDelegate *d=[FixtureDelegate new];d.window=[UIWindow new];app.delegate=d;});return app;}
- (BOOL)canOpenURL:(NSURL *)url {self.queriedURL=url;return self.canOpen;}
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {CHECK(options.count==0);CHECK(completion==nil);[self.openedURLs addObject:url.absoluteString];}
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard {static UIPasteboard *p;static dispatch_once_t once;dispatch_once(&once,^{p=[self new];});return p;}
@end
@implementation UIImpactFeedbackGenerator
- (instancetype)initWithStyle:(NSInteger)style {if((self=[super init]))self.style=style;return self;}
- (void)prepare {CHECK(self.style==1);prepared++;}
- (void)impactOccurred {CHECK(self.style==1);CHECK(prepared>impacts);impacts++;}
@end
@implementation UIGraphicsImageRendererContext @end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size {if((self=[super init]))self.size=size;return self;}
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions {UIGraphicsImageRendererContext *context=[UIGraphicsImageRendererContext new];context.CGContext=(CGContextRef)(uintptr_t)0x1234;actions(context);UIImage *image=[UIImage new];image.size=self.size;return image;}
@end
@interface FixtureBundle:NSBundle @end
@implementation FixtureBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table {CHECK(value==nil);CHECK(table==nil);return [@"localized:" stringByAppendingString:key];}
@end
@implementation NSBundle (WelcomeFixture)
+ (NSBundle *)ytl_defaultBundle {static NSBundle *bundle;static dispatch_once_t once;dispatch_once(&once,^{bundle=[FixtureBundle new];});return bundle;}
@end
static NSUserDefaults *testDefaults;
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults{return (YTLUserDefaults *)testDefaults;}
@end
@interface FixtureHeader:NSObject<YTLWelcomeSheetHeader>
@property(strong) UILabel *_subtitleLabel;
@property BOOL divider;
@end
@implementation FixtureHeader
- (void)showHeaderDivider {self.divider=YES;}
@end
@interface YTActionSheetAction:NSObject<YTLWelcomeAction>
@property(copy) NSString *title;
@property(strong) UIImage *image;
@property(copy) void (^handler)(void);
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)image secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler {
CHECK(secondary==nil);CHECK(identifier==nil);YTActionSheetAction *a=[self new];a.title=title;a.image=image;a.handler=handler;return a;}
@end
static id latestSheet;
@interface YTDefaultSheetController:NSObject<YTLWelcomeSheet>
@property(copy) NSString *message,*subMessage;
@property(strong) NSMutableArray<YTActionSheetAction *> *actions;
@property(strong) FixtureHeader *_headerView;
@property(strong) UIView *sourceView;
@property(strong) UIViewController *presenter;
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent {
CHECK(delegate==nil);CHECK(parent==nil);YTDefaultSheetController *s=[self new];s.message=message;s.subMessage=subMessage;s.actions=[NSMutableArray new];s._headerView=[FixtureHeader new];s._headerView._subtitleLabel=[UILabel new];latestSheet=s;return s;}
- (void)addAction:(id)action {[self.actions addObject:action];}
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion {CHECK(animated);CHECK(completion==nil);self.presenter=controller;}
@end
static NSLayoutConstraint *Find(UIView *view,NSString *kind) {for(NSLayoutConstraint *c in constraints)if([c.firstAnchor owner]==view&&[[c.firstAnchor kind]isEqual:kind])return c;return nil;}
static void RunAlert(WelcomeVC *vc,NSString *title) {
    [animations removeAllObjects];NSUInteger old=vc.view.subviews.count;NSInteger oldImpacts=impacts;
    [vc showAlertWithTitle:title imageName:@"checkmark"];
    CHECK(vc.view.subviews.count==old+1);CHECK(impacts==oldImpacts+1);
    UIVisualEffectView *alert=(id)vc.view.subviews.lastObject;
    CHECK(alert.effect.style==4);CHECK(alert.layer.cornerRadius==15);CHECK([alert.layer.cornerCurve isEqual:@"continuous"]);CHECK(alert.clipsToBounds);CHECK(!alert.userInteractionEnabled);CHECK(!alert.translatesAutoresizingMaskIntoConstraints);
    CHECK(alert.alpha==0);CHECK(alert.transform.a==1.2);CHECK(alert.transform.d==1.2);
    UIStackView *stack=(id)alert.contentView.subviews[0];UILabel *label=stack.arrangedSubviews[1];UIImageView *image=stack.arrangedSubviews[0];
    CHECK([label.text isEqual:title]);CHECK(label.numberOfLines==2);CHECK(label.font.pointSize==16&&label.font.bold);CHECK(label.textAlignment==1);
    CHECK(stack.axis==1&&stack.alignment==3&&stack.distribution==2&&stack.spacing==5);CHECK([image.image.name isEqual:@"checkmark"]&&image.image.system);
    CHECK(Find(image,@"widthAnchor").constant==50);CHECK(Find(image,@"heightAnchor").constant==50);CHECK(Find(label,@"leadingAnchor").constant==5);CHECK(Find(label,@"trailingAnchor").constant==-5);
    CHECK(Find(alert,@"widthAnchor").constant==150);CHECK(Find(alert,@"heightAnchor").constant==150);
    CHECK(animations.count==1);NSDictionary *first=animations[0];CHECK([first[@"duration"]doubleValue]==.5&&[first[@"delay"]doubleValue]==0);CHECK([first[@"damping"]doubleValue]==1&&[first[@"velocity"]doubleValue]==15&&[first[@"options"]integerValue]==0);
    ((void(^)(void))first[@"body"])();CHECK(alert.alpha==1);CHECK(CGAffineTransformIsIdentity(alert.transform));
    ((void(^)(BOOL))first[@"completion"])(NO);CHECK(animations.count==2);NSDictionary *second=animations[1];CHECK([second[@"duration"]doubleValue]==.5&&[second[@"delay"]doubleValue]==2);CHECK([second[@"damping"]doubleValue]==1&&[second[@"velocity"]doubleValue]==15&&[second[@"options"]integerValue]==0);
    NSInteger layout=vc.view.layoutCount;((void(^)(void))second[@"body"])();CHECK(alert.alpha==0&&alert.transform.a==.8&&alert.transform.d==.8);CHECK(Find(alert,@"centerYAnchor").constant==50);CHECK(vc.view.layoutCount==layout+1);
    ((void(^)(BOOL))second[@"completion"])(NO);CHECK(vc.view.subviews.count==old);CHECK(alert.superview==nil);
}
static void TestView(CGFloat safeTop) {
    [constraints removeAllObjects];UIApplication.sharedApplication.delegate.window.safeAreaInsets=UIEdgeInsetsMake(safeTop,0,0,0);
    WelcomeVC *vc=[WelcomeVC new];CHECK([vc tableView:nil numberOfRowsInSection:0]==0);[vc viewDidLoad];
    CHECK(vc.superViewDidLoad==1);CHECK(vc.navigationController.navigationBar.translucent);CHECK(vc.navigationController.navigationBar.shadowImage!=nil);CHECK(vc.navigationController.navigationBar.backgroundImage!=nil);CHECK(vc.navigationController.navigationBar.metrics==0);
    CHECK(vc.view.subviews.count==5);UIVisualEffectView *background=(id)vc.view.subviews[0];UITableView *table=(id)vc.view.subviews[1];UIView *footer=vc.view.subviews[2];UIButton *thanks=(id)vc.view.subviews[3];UIStackView *contacts=(id)vc.view.subviews[4];
    CHECK(background.effect.style==1);CHECK(CGRectEqualToRect(background.frame,vc.view.bounds));CHECK(background.autoresizingMask==18);
    CHECK(table.style==2&&table.dataSource==vc&&table.delegate==vc);CHECK(table.backgroundColor.alpha==.6&&table.backgroundColor.white==0);CHECK(table.separatorColor.alpha==0);CHECK(!table.translatesAutoresizingMaskIntoConstraints);
    CHECK(table.contentInset.top==0&&table.contentInset.left==0&&table.contentInset.right==0);CHECK(table.contentInset.bottom==(safeTop>20?140:100));CHECK(table.tableHeaderView.frame.size.height==230);
    for(NSString *kind in @[@"centerXAnchor",@"centerYAnchor",@"widthAnchor",@"heightAnchor"]){NSLayoutConstraint *c=Find(table,kind);CHECK([c.secondAnchor owner]==vc.view);CHECK(c.constant==0);}
    UIStackView *header=(id)table.tableHeaderView.subviews[0];UIImageView *logo=header.arrangedSubviews[0];UILabel *name=header.arrangedSubviews[1];CHECK(header.axis==1&&header.alignment==3&&header.spacing==20);CHECK([name.text isEqual:@"YouTube Plus"]);CHECK(name.font.pointSize==24&&name.font.bold);CHECK([logo.image.name isEqual:@"ytl_logo"]);CHECK(Find(logo,@"widthAnchor").constant==128&&Find(logo,@"heightAnchor").constant==128);CHECK(Find(header,@"topAnchor").constant==40);
    CHECK(footer.layer.cornerRadius==6&&footer.layer.maskedCorners==3&&footer.layer.masksToBounds);CHECK(!footer.userInteractionEnabled);CHECK(Find(footer,@"heightAnchor").constant==(safeTop>20?170:130));UIVisualEffectView *blur=(id)footer.subviews[0];CHECK(blur.effect.style==2&&blur.alpha==.8&&blur.autoresizingMask==18);
    CHECK([thanks.titles[@0]isEqual:@"localized:Continue"]);CHECK(thanks.titleLabel.font.pointSize==15&&thanks.titleLabel.font.bold);CHECK(thanks.backgroundColor.alpha==.15);CHECK(((UIColor *)thanks.titleColors[@1]).alpha==.5);CHECK(thanks.layer.cornerRadius==25);CHECK(thanks.target==vc&&thanks.action==@selector(thanksButtonTapped)&&thanks.events==64);CHECK(Find(thanks,@"bottomAnchor").constant==(safeTop>20?-60:-20));CHECK(Find(thanks,@"heightAnchor").constant==50&&Find(thanks,@"widthAnchor").constant==300);
    CHECK(contacts.axis==0&&contacts.distribution==1&&contacts.alignment==3&&contacts.spacing==10);CHECK(contacts.arrangedSubviews.count==2);CHECK(Find(contacts,@"bottomAnchor").constant==-15&&[Find(contacts,@"bottomAnchor").secondAnchor owner]==thanks);
    for(NSUInteger i=0;i<2;i++){UIButton *b=contacts.arrangedSubviews[i];CHECK(b.tag==(NSInteger)i&&b.type==1&&b.target==vc&&b.action==@selector(contactsButtonTapped:)&&b.events==64);CHECK(b.titleLabel.font.monospaced&&b.titleLabel.font.pointSize==14&&b.titleLabel.font.weight==-.4);CHECK(b.imageView.image.renderingMode==2);CHECK([b.imageView.image.name isEqual:(i?@"heart":@"x")]);CHECK(b.imageEdgeInsets.left==-5&&b.imageEdgeInsets.right==5);CHECK(b.semanticContentAttribute==3);CHECK(((UIColor *)b.titleColors[@0]).alpha==.75);}
    CHECK([vc numberOfSectionsInTableView:table]==1);CHECK([vc tableView:table numberOfRowsInSection:99]==4);
    NSArray *keys=@[@"Download",@"Content",@"Player",@"More"],*icons=@[@"arrow.down.app",@"paintbrush",@"hand.draw",@"ellipsis"];
    for(NSInteger row=0;row<4;row++){NSIndexPath *p=[NSIndexPath indexPathForRow:row inSection:0];UITableViewCell *cell=[vc tableView:table cellForRowAtIndexPath:p];CHECK(cell.style==3);CHECK([cell.textLabel.text isEqual:[@"localized:Welcome." stringByAppendingString:keys[row]]]);CHECK([cell.detailTextLabel.text isEqual:[[ @"localized:Welcome." stringByAppendingString:keys[row]]stringByAppendingString:@"Desc"]]);CHECK(cell.textLabel.font.bold&&cell.textLabel.font.pointSize==16&&cell.textLabel.adjustsFontSizeToFitWidth);CHECK(cell.detailTextLabel.font.pointSize==14&&!cell.detailTextLabel.font.bold&&cell.detailTextLabel.numberOfLines==0);CHECK(cell.detailTextLabel.textColor.alpha==.8&&!cell.userInteractionEnabled&&cell.backgroundColor.alpha==0);CHECK(CGSizeEqualToSize(cell.imageView.image.size,CGSizeMake(40,40)));UIImageView *rendered=(id)renderedView.subviews[0];CHECK([rendered.image.name isEqual:icons[row]]&&rendered.image.system);CHECK(rendered.contentMode==1&&rendered.clipsToBounds&&rendered.tintColor.white==1);CHECK(CGRectEqualToRect(rendered.frame,CGRectMake(0,0,40,40)));CHECK(![vc tableView:table shouldHighlightRowAtIndexPath:p]);CHECK([vc tableView:table heightForRowAtIndexPath:p]==-1);table.separatorStyle=1;[vc tableView:table willDisplayCell:cell forRowAtIndexPath:p];CHECK(table.separatorStyle==0);table.reusable=cell;}
    UITableViewCell *last=table.reusable;NSString *saved=last.textLabel.text;CHECK([vc tableView:table cellForRowAtIndexPath:[NSIndexPath indexPathForRow:99 inSection:1]]==last);CHECK([last.textLabel.text isEqual:saved]);
    UIImage *asset=[vc imageNamed:@"sample"];CHECK([asset.name isEqual:@"sample"]&&asset.bundle==[NSBundle ytl_defaultBundle]&&asset.traits==nil);
    RunAlert(vc,@"Synthetic copied message");
    ((void(*)(id,SEL))objc_msgSend)(thanks.target,thanks.action);CHECK([testDefaults boolForKey:@"hasShownWelcome"]&&vc.dismissed&&vc.animated);
}
static void TestContacts(void) {
    WelcomeVC *vc=[WelcomeVC new];UIButton *b=[UIButton buttonWithType:1];UIApplication *app=UIApplication.sharedApplication;b.tag=0;
    for(NSNumber *can in @[@NO,@YES]){app.canOpen=can.boolValue;[vc contactsButtonTapped:b];CHECK([app.queriedURL.absoluteString isEqual:@"twitter://user?screen_name=Dayanch96"]);CHECK([app.openedURLs.lastObject isEqual:can.boolValue?@"twitter://user?screen_name=Dayanch96":@"https://twitter.com/Dayanch96"]);}
    NSUInteger before=app.openedURLs.count;b.tag=77;[vc contactsButtonTapped:b];CHECK(app.openedURLs.count==before&&latestSheet==nil);
    b.tag=1;[vc contactsButtonTapped:b];YTDefaultSheetController *s=latestSheet;CHECK([s.message isEqual:@"localized:SupportDevelopment"]);CHECK([s.subMessage isEqual:@"localized:SupportDevelopmentDesc"]);CHECK(s._headerView.divider&&s._headerView._subtitleLabel.numberOfLines==0);CHECK(s.sourceView==b&&s.presenter==vc);CHECK(s.actions.count==6);
    NSArray *titles=@[@"Patreon",@"Github Sponsors",@"Buy Me a Coffee",@"USDT (TRC20)",@"BNB Smart Chain (BEP20)",@"Boosty"],*icons=@[@"patreon",@"github",@"coffee",@"usdt",@"bnb",@"boosty"];
    NSArray *urls=@[@"https://www.patreon.com/dayanch96",@"https://github.com/sponsors/dayanch96",@"https://www.buymeacoffee.com/dayanch96",@"",@"",@"https://boosty.to/dayanch96"];
    for(NSUInteger i=0;i<6;i++){YTActionSheetAction *a=s.actions[i];CHECK([a.title isEqual:titles[i]]);CHECK([a.image.name isEqual:icons[i]]);[animations removeAllObjects];before=app.openedURLs.count;a.handler();if(i==3||i==4){CHECK(app.openedURLs.count==before);CHECK([UIPasteboard.generalPasteboard.string isEqual:i==3?@"TEdKJdKwc1Bbu8Py4um8qPQ6MbproEqNJw":@"0xc6f9fddb30ce10d70e6497950f44c8e10b72bcd6"]);CHECK(animations.count==1);UIVisualEffectView *alert=(id)vc.view.subviews.lastObject;UIStackView *stack=(id)alert.contentView.subviews[0];CHECK([((UILabel *)stack.arrangedSubviews[1]).text isEqual:@"localized:Copied"]);CHECK([((UIImageView *)stack.arrangedSubviews[0]).image.name isEqual:@"checkmark"]);}else{CHECK(app.openedURLs.count==before+1);CHECK([app.openedURLs.lastObject isEqual:urls[i]]);}}
}
int main(void) {@autoreleasepool {NSString *suite=[@"WelcomeFixture." stringByAppendingString:NSUUID.UUID.UUIDString];testDefaults=[[NSUserDefaults alloc]initWithSuiteName:suite];constraints=[NSMutableArray new];animations=[NSMutableArray new];TestView(0);TestView(20);TestView(20.5);TestContacts();[testDefaults removePersistentDomainForName:suite];printf("WelcomeVC: %lu actual-source runtime checks passed\n",(unsigned long)checks);}return 0;}
