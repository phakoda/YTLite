#import "../source/Whitelist/SbWhitelistVC.h"
#import "../source/Settings/YTPTableViewCell.h"
#import "../../Utils/YTLUserDefaults.h"
#import "../../Utils/NSBundle+YTLite.h"
#import <objc/runtime.h>

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { NSLog(@"FAIL %d: %s",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
static NSArray *constraints;
static UIView *renderedView;
static CGSize rendererSize;
static BOOL failDecode;
static NSString *suite;
static NSUInteger writes,synchronizes;
const UIFontWeight UIFontWeightLight=-0.4;
@implementation CALayer
- (void)setBorderColor:(CGColorRef)color { if(color)CGColorRetain(color);if(_borderColor)CGColorRelease(_borderColor);_borderColor=color; }
- (CGColorRef)borderColor {return _borderColor;}
- (void)dealloc {if(_borderColor)CGColorRelease(_borderColor);}
- (void)renderInContext:(CGContextRef)context { CHECK(context != NULL); renderedView=self.owner; }
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray *)items { constraints=items; }
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value { NSLayoutConstraint *c=[NSLayoutConstraint new]; c.firstAnchor=self; c.secondAnchor=anchor; c.constant=value; return c; }
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor { return [self constraintEqualToAnchor:anchor constant:0]; }
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value { return [self constraintEqualToAnchor:nil constant:value]; }
@end
@implementation UIView
- (instancetype)init { return [self initWithFrame:CGRectZero]; }
- (instancetype)initWithFrame:(CGRect)frame { if ((self=[super init])) { _frame=frame;_bounds=(CGRect){CGPointZero,frame.size};_subviews=[NSMutableArray array];_layer=[CALayer new];_layer.owner=self; } return self; }
- (void)addSubview:(UIView *)view { [self.subviews addObject:view]; }
- (UIView *)viewWithTag:(NSInteger)tag { if(self.tag==tag)return self; for(UIView *v in self.subviews){UIView *found=[v viewWithTag:tag];if(found)return found;} return nil; }
- (NSLayoutAnchor *)anchor:(NSString *)kind { NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.kind=kind;return a; }
- (NSLayoutAnchor *)heightAnchor{return [self anchor:@"height"];}
- (NSLayoutAnchor *)widthAnchor{return [self anchor:@"width"];}
- (NSLayoutAnchor *)trailingAnchor{return [self anchor:@"trailing"];}
- (NSLayoutAnchor *)centerYAnchor{return [self anchor:@"centerY"];}
@end
@implementation UIColor
+ (instancetype)named:(NSString *)name { UIColor *c=[self new];c.name=name;c.alpha=1;return c; }
+ (instancetype)labelColor{return [self named:@"label"];}
+ (instancetype)whiteColor{return [self named:@"white"];}
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider { UIColor *c=[self new]; c.provider=provider;return c; }
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha { UIColor *c=[UIColor named:self.name];c.alpha=alpha;return c; }
- (CGColorRef)CGColor { if(!_color)_color=CGColorCreateGenericRGB(1,1,1,self.alpha);return _color; }
- (void)dealloc {if(_color)CGColorRelease(_color);}
@end
@interface YTColor : NSObject
+ (UIColor *)black2;
@end
@implementation YTColor
+ (UIColor *)black2 { UIColor *c=[UIColor new];c.name=@"black2";return c; }
@end
@implementation UITraitCollection @end
@implementation UIFont
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight { UIFont *f=[self new];f.pointSize=size;f.weight=weight;return f; }
@end
@implementation UILabel @end
@implementation UIImage
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits { CHECK(traits==nil);UIImage *i=[self new];i.name=name;i.bundle=bundle;return i; }
+ (instancetype)systemImageNamed:(NSString *)name {UIImage *i=[self new];i.name=name;return i;}
+ (instancetype)imageWithData:(NSData *)data { if(failDecode)return nil;UIImage *i=[self new];i.data=data;return i; }
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode { self.renderingMode=mode;return self; }
@end
@implementation UIImageView
- (instancetype)initWithImage:(UIImage *)image {if((self=[super init]))_image=image;return self;}
@end
@implementation UIGraphicsImageRendererContext @end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size {if((self=[super init]))_size=size;return self;}
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions { rendererSize=self.size;CGColorSpaceRef cs=CGColorSpaceCreateDeviceRGB();CGContextRef ctx=CGBitmapContextCreate(NULL,24,24,8,0,cs,(CGBitmapInfo)kCGImageAlphaPremultipliedLast);UIGraphicsImageRendererContext *c=[UIGraphicsImageRendererContext new];c.CGContext=ctx;actions(c);CGContextRelease(ctx);CGColorSpaceRelease(cs);return [UIImage systemImageNamed:@"rendered"]; }
@end
@implementation UIAction
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler {UIAction *a=[self new];a.title=title;a.image=image;a.identifier=identifier;a.handler=handler;return a;}
@end
@implementation UIMenu
+ (instancetype)menuWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier options:(UIMenuOptions)options children:(NSArray *)children {UIMenu *m=[self new];m.title=title;m.image=image;m.identifier=identifier;m.options=options;m.children=children;return m;}
@end
@implementation UIButton
+ (instancetype)buttonWithType:(UIButtonType)type {UIButton *b=[self new];b.type=type;return b;}
- (void)setImage:(UIImage *)image forState:(UIControlState)state {CHECK(state==0);self.image=image;}
@end
@implementation UIBarButtonItem
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)item target:(id)target action:(SEL)action {if((self=[super init])){_systemItem=item;_target=target;_action=action;}return self;}
@end
@implementation UINavigationItem @end
@implementation UIViewController
- (instancetype)init {if((self=[super init]))_navigationItem=[UINavigationItem new];return self;}
- (void)loadView {self.loaded=YES;self.view=[UIView new];}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion {self.dismissed=YES;self.dismissAnimated=animated;CHECK(completion==nil);}
@end
@implementation UITableViewCell
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier {if((self=[super init])){_style=style;_reuseIdentifier=identifier;_textLabel=[UILabel new];_imageView=[UIImageView new];}return self;}
@end
@implementation UITableView
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier {self.dequeuedIdentifier=identifier;return self.reusable;}
- (void)reloadData {self.reloads++;}
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated {self.deselected=indexPath;self.deselectAnimated=animated;}
@end
@implementation UITableViewController
- (instancetype)initWithStyle:(UITableViewStyle)style {if((self=[super init])){_style=style;_tableView=[UITableView new];}return self;}
@end
// The production class imports the canonical superclass; only its inherited UIKit initialization is needed here.
@implementation DVNTableViewController @end
@implementation YTPTableViewCell @end
@implementation UITableViewHeaderFooterView
- (instancetype)init {if((self=[super init])){_textLabel=[UILabel new];_contentView=[UIView new];[self addSubview:_contentView];[self addSubview:_textLabel];}return self;}
@end
@implementation NSIndexPath (WhitelistTable)
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section {NSUInteger indexes[]={(NSUInteger)section,(NSUInteger)row};return [self indexPathWithIndexes:indexes length:2];}
- (NSInteger)section{return [self indexAtPosition:0];}
- (NSInteger)row{return [self indexAtPosition:1];}
@end
@implementation UIApplication
+ (instancetype)sharedApplication {static UIApplication *a;if(!a){a=[self new];a.urls=[NSMutableArray array];}return a;}
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {CHECK(url!=nil);[self.urls addObject:url];self.lastOptions=options;self.hadCompletion=completion!=nil;}
@end
@implementation UIContextualAction
+ (instancetype)contextualActionWithStyle:(UIContextualActionStyle)style title:(NSString *)title handler:(void (^)(UIContextualAction *, UIView *, void (^)(BOOL)))handler {UIContextualAction *a=[self new];a.style=style;a.title=title;a.handler=handler;return a;}
@end
@implementation UISwipeActionsConfiguration
+ (instancetype)configurationWithActions:(NSArray *)actions {UISwipeActionsConfiguration *c=[self new];c.actions=actions;return c;}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults {static YTLUserDefaults *d;if(!d){suite=[@"YTLWhitelistFixture." stringByAppendingString:NSUUID.UUID.UUIDString];d=[[self alloc] initWithSuiteName:suite];}return d;}
- (void)setObject:(id)value forKey:(NSString *)key {writes++;[super setObject:value forKey:key];}
- (BOOL)synchronize {synchronizes++;return [super synchronize];}
@end
@implementation NSBundle (WhitelistLocalization)
+ (NSBundle *)ytl_defaultBundle {return NSBundle.mainBundle;}
@end

static NSArray *rows(SbWhitelistVC *vc) {return [vc valueForKey:@"_channels"];}
static NSArray *titles(SbWhitelistVC *vc) {return [rows(vc) valueForKey:@"title"];}
static NSDictionary *entry(NSString *name, NSInteger date, NSString *link) {return @{@"name":name,@"date":@(date),@"link":link};}
static void checkSort(SbWhitelistVC *vc, NSInteger sort, NSArray *expected) {
    [[YTLUserDefaults standardUserDefaults] setInteger:sort forKey:@"sbWhitelistSortType"];
    NSUInteger before=vc.tableView.reloads;[vc setupWhitelist];CHECK(vc.tableView.reloads==before+1);CHECK([titles(vc) isEqual:expected]);
}
int main(void) {@autoreleasepool {
    YTLUserDefaults *defaults=[YTLUserDefaults standardUserDefaults];
    SbWhitelistVC *vc=[SbWhitelistVC new];NSIndexPath *first=[NSIndexPath indexPathForRow:0 inSection:0];
    CHECK(vc.style==1);CHECK([vc numberOfSectionsInTableView:vc.tableView]==1);CHECK([vc tableView:vc.tableView numberOfRowsInSection:0]==1);
    CHECK([rows(vc)[0] isEqual:@{@"title":@"Sb.ChannelsHere",@"image":@"FEuploads",@"type":@"nochannel",@"key":@"",@"id":@"channelCell"}]);
    CHECK([vc tableView:vc.tableView shouldHighlightRowAtIndexPath:first]);
    CHECK([vc tableView:vc.tableView trailingSwipeActionsConfigurationForRowAtIndexPath:first]==nil);
    [vc tableView:vc.tableView didSelectRowAtIndexPath:first];CHECK([UIApplication sharedApplication].urls.count==0);CHECK([vc.tableView.deselected isEqual:first]&&vc.tableView.deselectAnimated);
    UITableViewCell *placeholder=[vc tableView:vc.tableView cellForRowAtIndexPath:first];CHECK(placeholder.style==3);CHECK([placeholder.imageView.image.name isEqual:@"FEuploads"]);CHECK(placeholder.imageView.image.renderingMode==2);
    NSUInteger before=vc.tableView.reloads, sync=synchronizes;[vc removeChannelWithLink:@"none"];CHECK(vc.tableView.reloads==before&&synchronizes==sync);
    NSDictionary *dataset=@{@"a":entry(@"Channel 10",30,@"https://example.test/a"),@"b":entry(@"Channel 2",10,@"https://example.test/b"),@"c":entry(@"Alpha",20,@"https://example.test/c")};
    [defaults setObject:dataset forKey:@"sbWhitelist"];
    NSArray *newest=@[@"Channel 10",@"Alpha",@"Channel 2"];
    checkSort(vc,0,newest);checkSort(vc,1,@[@"Channel 2",@"Alpha",@"Channel 10"]);checkSort(vc,2,@[@"Alpha",@"Channel 2",@"Channel 10"]);checkSort(vc,3,@[@"Channel 10",@"Channel 2",@"Alpha"]);
    checkSort(vc,-1,newest);checkSort(vc,4,newest);checkSort(vc,NSIntegerMax,newest);checkSort(vc,NSIntegerMin,newest);checkSort(vc,0x100000000LL,newest);
    CHECK([rows(vc)[0][@"type"] isEqual:@"channel"]);CHECK([rows(vc)[0][@"key"] isEqual:@"https://example.test/a"]);
    UIImage *fallback=rows(vc)[0][@"image"];CHECK([fallback.name isEqual:@"FElibrary"]&&fallback.renderingMode==2);
    vc.tableView.reusable=placeholder;UITableViewCell *cell=[vc tableView:vc.tableView cellForRowAtIndexPath:first];CHECK(cell!=placeholder);CHECK([vc.tableView.dequeuedIdentifier isEqual:@"cell"]);CHECK([cell.reuseIdentifier isEqual:@"channelCell"]);CHECK([cell.textLabel.text isEqual:@"Channel 10"]);CHECK(cell.textLabel.numberOfLines==0&&[cell.textLabel.textColor.name isEqual:@"label"]);
    CHECK(CGSizeEqualToSize(rendererSize,CGSizeMake(24,24)));UIImageView *drawn=(UIImageView *)renderedView.subviews.firstObject;CHECK(drawn.image==fallback);CHECK(drawn.contentMode==1&&drawn.clipsToBounds);CHECK(CGRectEqualToRect(drawn.frame,CGRectMake(0,0,24,24)));CHECK(drawn.layer.cornerRadius==12&&drawn.layer.borderWidth==1);
    CHECK(CGColorGetAlpha(drawn.layer.borderColor)==0.25);
    [vc tableView:vc.tableView didSelectRowAtIndexPath:first];CHECK([[[UIApplication sharedApplication].urls lastObject] isEqual:[NSURL URLWithString:@"https://example.test/a"]]);CHECK([UIApplication sharedApplication].lastOptions.count==0&&![UIApplication sharedApplication].hadCompletion);
    vc.tableView.contentInset=(UIEdgeInsets){2,3,4,5};[vc loadView];CHECK(vc.loaded&&[vc.title isEqual:@"Sb.Whitelist"]);CHECK(vc.tableView.contentInset.top==17&&vc.tableView.contentInset.left==3&&vc.tableView.contentInset.bottom==4&&vc.tableView.contentInset.right==5);
    UITraitCollection *traits=[UITraitCollection new];traits.userInterfaceStyle=2;CHECK([vc.tableView.backgroundColor.provider(traits).name isEqual:@"black2"]);traits.userInterfaceStyle=1;CHECK([vc.tableView.backgroundColor.provider(traits).name isEqual:@"white"]);traits.userInterfaceStyle=0;CHECK([vc.tableView.backgroundColor.provider(traits).name isEqual:@"white"]);
    CHECK(vc.navigationItem.rightBarButtonItem.systemItem==24&&vc.navigationItem.rightBarButtonItem.target==vc&&vc.navigationItem.rightBarButtonItem.action==@selector(closeButtonTapped));[vc closeButtonTapped];CHECK(vc.dismissed&&vc.dismissAnimated);
    CHECK([[vc tableView:vc.tableView titleForHeaderInSection:0] isEqual:@"Sb.Channels"]);CHECK([vc tableView:vc.tableView titleForHeaderInSection:1]==nil);
    UITableViewHeaderFooterView *header=[UITableViewHeaderFooterView new];[vc tableView:vc.tableView willDisplayHeaderView:header forSection:0];UIButton *button=(UIButton *)[header viewWithTag:1000];CHECK(button!=nil&&button.type==1);CHECK([button.image.name isEqual:@"sort"]&&button.image.renderingMode==2);CHECK(!button.translatesAutoresizingMaskIntoConstraints&&button.showsMenuAsPrimaryAction);
    CHECK(header.textLabel.font.pointSize==14&&header.textLabel.font.weight==UIFontWeightLight);CHECK(header.textLabel.numberOfLines==0&&header.textLabel.textAlignment==4&&[header.textLabel.text isEqual:@"Sb.Channels"]);CHECK([header.textLabel.textColor.name isEqual:@"label"]);
    CHECK(constraints.count==5);CHECK([constraints valueForKey:@"constant"]&&[[constraints valueForKey:@"constant"] isEqual:@[@30,@(-20),@0,@20,@20]]);CHECK([[(NSLayoutAnchor *)[constraints[0] firstAnchor] kind] isEqual:@"height"]);CHECK([(NSLayoutAnchor *)[constraints[1] firstAnchor] owner]==button);CHECK([(NSLayoutAnchor *)[constraints[1] secondAnchor] owner]==header.contentView);CHECK([(NSLayoutAnchor *)[constraints[2] secondAnchor] owner]==header.textLabel);
    CHECK([button.menu.title isEqual:@"SortType"]&&[button.menu.identifier isEqual:@"sb_menu"]&&button.menu.options==1&&button.menu.image==nil);CHECK(button.menu.children.count==4);
    NSArray *menuTitles=@[@"Sb.Newest",@"Sb.Oldest",@"Sb.Alphabetical",@"Sb.AlphabeticalRev"],*icons=@[@"clock",@"clock.arrow.circlepath",@"textformat",@"textformat.size"];
    NSArray *expectedSorts=@[newest,@[@"Channel 2",@"Alpha",@"Channel 10"],@[@"Alpha",@"Channel 2",@"Channel 10"],@[@"Channel 10",@"Channel 2",@"Alpha"]];
    for(NSUInteger i=0;i<4;i++){UIAction *a=button.menu.children[i];CHECK([a.title isEqual:menuTitles[i]]&&[a.image.name isEqual:icons[i]]&&a.identifier==nil);sync=synchronizes;a.handler(a);CHECK(synchronizes==sync);CHECK([defaults integerForKey:@"sbWhitelistSortType"]==(NSInteger)i);CHECK([titles(vc) isEqual:expectedSorts[i]]);for(NSUInteger j=0;j<4;j++)CHECK(((UIAction *)button.menu.children[j]).state==(i==j));}
    UIMenu *existingMenu=button.menu;[vc tableView:vc.tableView willDisplayHeaderView:header forSection:0];CHECK(header.contentView.subviews.count==1&&button.menu==existingMenu);
    UITableViewHeaderFooterView *other=[UITableViewHeaderFooterView new];[vc tableView:vc.tableView willDisplayHeaderView:other forSection:1];CHECK(other.contentView.subviews.count==0&&other.textLabel.text==nil);
    UISwipeActionsConfiguration *swipe=[vc tableView:vc.tableView trailingSwipeActionsConfigurationForRowAtIndexPath:first];CHECK(swipe.actions.count==1&&swipe.performsFirstActionWithFullSwipe);UIContextualAction *remove=swipe.actions[0];CHECK(remove.style==1&&[remove.title isEqual:@""]&&[remove.image.name isEqual:@"trash"]);__block BOOL completion=NO;remove.handler(remove,[UIView new],^(BOOL success){CHECK(success);completion=YES;});CHECK(completion);CHECK([defaults dictionaryForKey:@"sbWhitelist"].count==2);CHECK([defaults dictionaryForKey:@"sbWhitelist"][@"a"]==nil);
    before=vc.tableView.reloads;sync=synchronizes;NSUInteger oldWrites=writes;[vc removeChannelWithLink:@"unmatched"];CHECK(vc.tableView.reloads==before+1&&synchronizes==sync+1&&writes==oldWrites+1);
    [defaults setObject:@{@"a":entry(@"First",1,@"same"),@"b":entry(@"Second",2,@"same")} forKey:@"sbWhitelist"];[vc removeChannelWithLink:@"same"];CHECK([defaults dictionaryForKey:@"sbWhitelist"].count==1);[vc removeChannelWithLink:@"same"];CHECK([defaults dictionaryForKey:@"sbWhitelist"].count==0);CHECK([rows(vc)[0][@"type"] isEqual:@"nochannel"]);
    NSMutableDictionary *photoEntry=[entry(@"Photo",0,@"https://example.test/photo") mutableCopy];photoEntry[@"pfp"]=[@"synthetic-image" dataUsingEncoding:NSUTF8StringEncoding];[defaults setObject:@{@"p":photoEntry} forKey:@"sbWhitelist"];[vc setupWhitelist];CHECK([((UIImage *)rows(vc)[0][@"image"]).data isEqual:photoEntry[@"pfp"]]);
    failDecode=YES;BOOL threw=NO;@try{[vc setupWhitelist];}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];}CHECK(threw);failDecode=NO;
    [defaults setObject:@{@"broken":@{@"date":@0,@"link":@"x"}} forKey:@"sbWhitelist"];threw=NO;@try{[vc setupWhitelist];}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];}CHECK(threw);
    // Cover nil image/title, unrecognized image type, missing channel link, and absent channel type using the actual row array.
    NSMutableArray *mutableRows=[vc valueForKey:@"_channels"];[mutableRows setArray:@[@{@"id":@"minimal",@"image":@42,@"type":@"channel"}]];
    cell=[vc tableView:vc.tableView cellForRowAtIndexPath:first];CHECK(cell.textLabel.text==nil&&cell.imageView.image==nil);NSUInteger urls=[UIApplication sharedApplication].urls.count;[vc tableView:vc.tableView didSelectRowAtIndexPath:first];CHECK([UIApplication sharedApplication].urls.count==urls);
    [mutableRows setArray:@[@{@"id":@"bare"}]];cell=[vc tableView:vc.tableView cellForRowAtIndexPath:first];CHECK(cell.imageView.image==nil&&cell.textLabel.text==nil);CHECK([vc tableView:vc.tableView trailingSwipeActionsConfigurationForRowAtIndexPath:first]==nil);
    [defaults setObject:@{} forKey:@"sbWhitelist"];
    __weak id weakRows,weakSections,weakButton,weakController;
    @autoreleasepool { SbWhitelistVC *temporary=[SbWhitelistVC new];UIButton *b=[UIButton new];[temporary setValue:b forKey:@"_sortButton"];weakController=temporary;weakRows=[temporary valueForKey:@"_channels"];weakSections=[temporary valueForKey:@"_sections"];weakButton=b;CHECK(weakController&&weakRows&&weakSections&&weakButton); }
    CHECK(weakController==nil&&weakRows==nil&&weakSections==nil&&weakButton==nil);
    [defaults removePersistentDomainForName:suite];NSLog(@"SbWhitelistVC: %lu runtime checks passed",(unsigned long)checks);
}return 0;}
