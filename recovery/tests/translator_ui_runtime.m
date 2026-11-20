#import "../source/Subtitles/TranslatorVC.h"
#import "../source/Subtitles/YTPTranslator.h"
#import "../source/Support/YTPDB.h"
#import "../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>
#import <objc/message.h>

static NSUInteger checks;
#define CHECK(...) do { checks++; if(!(__VA_ARGS__)){fprintf(stderr,"FAIL line %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);} } while(0)
static NSMutableArray<NSString *> *events;
static NSMutableArray<dispatch_block_t> *pending;
static NSMutableArray *requests;
static NSArray *languages;
static NSInteger preferred;
static BOOL oled,failInitialization;
static NSUInteger languageReads,preferredReads,cellAllocations;
static NSArray<NSLayoutConstraint *> *constraints;
static UIView *renderedView;
static CGSize rendererSize;
static NSInteger layoutDirection=-1;
static NSMutableArray *mutateDuringAction;
static id ObjectIvar(id object,const char *name){return object_getIvar(object,class_getInstanceVariable(TranslatorVC.class,name));}
static NSInteger Index(TranslatorVC *vc){return [[vc valueForKey:@"_langIndex"]integerValue];}
static void SetIndex(TranslatorVC *vc,NSInteger value){[vc setValue:@(value) forKey:@"_langIndex"];}
static void Event(NSString *text){[events addObject:text];}
static void Reset(void){[events removeAllObjects];[requests removeAllObjects];[pending removeAllObjects];constraints=nil;renderedView=nil;languages=@[@"English",@"Arabic",@"Japanese"];preferred=1;oled=NO;layoutDirection=-1;}
void TranslatorFixtureDispatchAsync(dispatch_queue_t queue,dispatch_block_t block){CHECK(queue==dispatch_get_main_queue());Event(@"enqueue.main");[pending addObject:[block copy]];}
static void Drain(void){while(pending.count){dispatch_block_t block=pending.firstObject;[pending removeObjectAtIndex:0];block();}}
const UIFontWeight UIFontWeightSemibold=0.3;
NSString *const UIFontTextStyleBody=@"fixture.body";
NSString *const NSForegroundColorAttributeName=@"fixture.foreground";
const CGFloat UITableViewAutomaticDimension=-1;
@implementation CALayer
- (void)setBorderColor:(CGColorRef)value{if(value)CGColorRetain(value);if(_borderColor)CGColorRelease(_borderColor);_borderColor=value;}
- (CGColorRef)borderColor{return _borderColor;}
- (void)dealloc{if(_borderColor)CGColorRelease(_borderColor);}
- (void)renderInContext:(CGContextRef)context{CHECK(context!=NULL);renderedView=self.owner;Event(@"render.layer");}
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray *)items{constraints=items;Event(@"constraints");}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor{NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;return c;}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value{NSLayoutConstraint *c=[self constraintEqualToAnchor:nil];c.constant=value;return c;}
@end
@implementation UIView
- (instancetype)init{return [self initWithFrame:CGRectZero];}
- (instancetype)initWithFrame:(CGRect)frame{if((self=[super init])){_frame=frame;_bounds=(CGRect){CGPointZero,frame.size};_subviews=[NSMutableArray new];_layer=[CALayer new];_layer.owner=self;_tintColor=[UIColor colorWithRed:.1 green:.2 blue:.3 alpha:1];}return self;}
- (void)addSubview:(UIView *)view{[_subviews addObject:view];}
- (NSLayoutAnchor *)anchor:(NSString *)kind{NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.kind=kind;return a;}
- (NSLayoutAnchor *)heightAnchor{return [self anchor:@"height"];}
- (NSLayoutAnchor *)widthAnchor{return [self anchor:@"width"];}
- (NSLayoutAnchor *)leadingAnchor{return [self anchor:@"leading"];}
- (NSLayoutAnchor *)trailingAnchor{return [self anchor:@"trailing"];}
- (NSLayoutAnchor *)topAnchor{return [self anchor:@"top"];}
- (NSLayoutAnchor *)bottomAnchor{return [self anchor:@"bottom"];}
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)value{return layoutDirection>=0?layoutDirection:(value==4?1:0);}
@end
@implementation UIColor
+ (instancetype)named:(NSString *)name{UIColor *c=[self new];c.name=name;c.alpha=1;return c;}
+ (instancetype)labelColor{return [self named:@"label"];}
+ (instancetype)secondaryLabelColor{return [self named:@"secondary"];}
+ (instancetype)whiteColor{return [self named:@"white"];}
+ (instancetype)blackColor{return [self named:@"black"];}
+ (instancetype)systemBackgroundColor{return [self named:@"background"];}
+ (instancetype)clearColor{UIColor *c=[self named:@"clear"];c.alpha=0;return c;}
+ (instancetype)systemGrayColor{return [self named:@"gray"];}
+ (instancetype)systemRedColor{return [self named:@"red"];}
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha{UIColor *c=[self named:@"rgba"];c.red=red;c.green=green;c.blue=blue;c.alpha=alpha;return c;}
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider{UIColor *c=[self named:@"dynamic"];c.provider=provider;return c;}
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha{UIColor *c=[UIColor colorWithRed:self.red green:self.green blue:self.blue alpha:alpha];c.name=self.name;return c;}
- (CGColorRef)CGColor{if(!_color)_color=CGColorCreateGenericRGB(self.red,self.green,self.blue,self.alpha);return _color;}
- (void)dealloc{if(_color)CGColorRelease(_color);}
@end
@implementation UITraitCollection @end
@implementation UIFont
+ (instancetype)font:(NSString *)kind size:(CGFloat)size{UIFont *font=[self new];font.kind=kind;font.pointSize=size;return font;}
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight{UIFont *f=[self font:@"system" size:size];f.weight=weight;return f;}
+ (instancetype)systemFontOfSize:(CGFloat)size{return [self font:@"system" size:size];}
+ (instancetype)boldSystemFontOfSize:(CGFloat)size{return [self font:@"bold" size:size];}
+ (instancetype)italicSystemFontOfSize:(CGFloat)size{return [self font:@"italic" size:size];}
+ (instancetype)preferredFontForTextStyle:(NSString *)style{UIFont *f=[self font:@"preferred" size:0];f.style=style;return f;}
@end
@implementation UILabel @end
@implementation UITextView
- (void)setText:(NSString *)value{_text=[value copy];Event([@"text:" stringByAppendingString:value?:@"<nil>"]);}
- (void)setTextColor:(UIColor *)value{_textColor=value;Event([@"color:" stringByAppendingString:value.name?:@"<nil>"]);}
- (void)setFont:(UIFont *)value{_font=value;Event([@"font:" stringByAppendingString:value.kind?:@"<nil>"]);}
@end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name{UIImage *i=[self new];i.name=name;return i;}
@end
@implementation UIImageView
- (instancetype)initWithImage:(UIImage *)image{if((self=[super init]))_image=image;return self;}
@end
@implementation UIGraphicsImageRendererContext @end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size{if((self=[super init]))_size=size;return self;}
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions{rendererSize=self.size;CGColorSpaceRef colors=CGColorSpaceCreateDeviceRGB();CGContextRef bitmap=CGBitmapContextCreate(NULL,24,24,8,0,colors,(CGBitmapInfo)kCGImageAlphaPremultipliedLast);UIGraphicsImageRendererContext *context=[UIGraphicsImageRendererContext new];context.CGContext=bitmap;actions(context);CGContextRelease(bitmap);CGColorSpaceRelease(colors);return [UIImage systemImageNamed:@"rendered"];}
@end
@implementation UIAction
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler{UIAction *a=[self new];a.title=title;a.image=image;a.identifier=identifier;a.handler=handler;if(mutateDuringAction){[mutateDuringAction addObject:@"injected"];mutateDuringAction=nil;}return a;}
@end
@implementation UIMenu
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children{UIMenu *menu=[self new];menu.title=title;menu.children=children;return menu;}
@end
@implementation UIButton
+ (instancetype)buttonWithType:(UIButtonType)type{UIButton *b=[self new];b.type=type;b.titleLabel=[UILabel new];b.enabled=YES;return b;}
- (void)setImage:(UIImage *)image forState:(UIControlState)state{CHECK(state==0);self.image=image;}
- (void)setTitle:(NSString *)title forState:(UIControlState)state{CHECK(state==0);self.title=title;Event([@"button.title:" stringByAppendingString:title?:@"<nil>"]);}
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state{CHECK(state==0);self.titleColor=color;}
- (void)setEnabled:(BOOL)value{_enabled=value;Event(value?@"button.enabled:1":@"button.enabled:0");}
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)eventsValue{self.target=target;self.action=action;self.events=eventsValue;}
- (void)sizeToFit{self.sizedToFit=YES;}
@end
@implementation UIBarButtonItem
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)item target:(id)target action:(SEL)action{if((self=[super init])){_systemItem=item;_target=target;_action=action;}return self;}
@end
@implementation UINavigationItem @end
@implementation UIViewController
- (instancetype)init{if((self=[super init])){_navigationItem=[UINavigationItem new];_view=[UIView new];}return self;}
- (void)viewDidLoad{self.loaded=YES;Event(@"super.viewDidLoad");}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion{self.dismissed=YES;self.dismissAnimated=animated;CHECK(completion==nil);Event(@"dismiss");}
@end
@implementation UITableViewCell
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier{cellAllocations++;if((self=[super init])){_style=style;_reuseIdentifier=[identifier copy];_textLabel=[UILabel new];_contentView=[UIView new];}return self;}
@end
@implementation UITableView
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier{self.dequeuedIdentifier=identifier;return self.reusable;}
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation{self.reloadedSections=sections;self.animation=animation;Event(@"reload.sections");}
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated{self.deselected=indexPath;self.deselectAnimated=animated;}
@end
@implementation UITableViewController
- (instancetype)initWithStyle:(UITableViewStyle)style{if(failInitialization)return nil;if((self=[super init])){_style=style;_tableView=[UITableView new];self.view=_tableView;}return self;}
- (NSString *)tableView:(UITableView *)table titleForHeaderInSection:(NSInteger)section{self.headerSection=section;self.headerTable=table;return self.fixtureHeader;}
@end
@implementation UITableViewHeaderFooterView
- (instancetype)init{if((self=[super init]))_textLabel=[UILabel new];return self;}
@end
@implementation NSIndexPath (TranslatorFixtureTable)
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section{NSUInteger indexes[]={section,row};return [self indexPathWithIndexes:indexes length:2];}
- (NSInteger)section{return [self indexAtPosition:0];}
- (NSInteger)row{return [self indexAtPosition:1];}
@end
@interface NSString (TranslatorLocalizationFixture)
- (NSString *)ytl_localized;
@end
@implementation NSString (TranslatorLocalizationFixture)
- (NSString *)ytl_localized{Event([@"localize:" stringByAppendingString:self]);return [@"L:" stringByAppendingString:self];}
@end
@interface TranslatorFixtureDefaults : NSObject
- (BOOL)boolForKey:(NSString *)key;
@end
@implementation TranslatorFixtureDefaults
- (BOOL)boolForKey:(NSString *)key{CHECK([key isEqual:@"oledTheme"]);Event(@"defaults.oledTheme");return oled;}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static id defaults;if(!defaults)defaults=[TranslatorFixtureDefaults new];return defaults;}
@end
@implementation YTPDB
+ (NSArray *)supportedLanguages{languageReads++;return languages;}
+ (NSUInteger)indexOfPreferredLanguage{preferredReads++;return preferred;}
+ (NSString *)langCodeForIndex:(NSInteger)index{Event([NSString stringWithFormat:@"language:%ld",(long)index]);return [NSString stringWithFormat:@"fixture-%ld",(long)index];}
@end
@interface TranslatorFixtureRequest : NSObject
@property(nonatomic,strong) NSString *text,*source,*target;
@property(nonatomic,copy) YTLTranslationCompletion completion;
@end
@implementation TranslatorFixtureRequest @end
@implementation YTPTranslator
+ (void)translateText:(NSString *)text fromLanguage:(NSString *)source toLanguage:(NSString *)target completion:(YTLTranslationCompletion)completion{TranslatorFixtureRequest *r=[TranslatorFixtureRequest new];r.text=text;r.source=source;r.target=target;r.completion=completion;[requests addObject:r];Event(@"request");}
@end
static NSIndexPath *Path(NSInteger section){return [NSIndexPath indexPathForRow:0 inSection:section];}
static TranslatorVC *Controller(void){return [[TranslatorVC alloc]initWithText:@"original input"] ;}
static UITableViewCell *Cell(TranslatorVC *vc,NSInteger section){return [vc tableView:vc.tableView cellForRowAtIndexPath:Path(section)];}
static void Complete(NSUInteger index,NSString *translation,NSError *error){TranslatorFixtureRequest *r=requests[index];r.completion(translation,error);}
static void CheckEdges(UIView *inner,UIView *outer,NSUInteger count){CHECK(constraints.count==count);NSArray *names=@[@"leading",@"trailing",@"top",@"bottom"];for(NSUInteger i=0;i<4;i++){NSLayoutConstraint *c=constraints[i];NSLayoutAnchor *a=c.firstAnchor,*b=c.secondAnchor;CHECK(a.owner==inner&&b.owner==outer);CHECK([a.kind isEqual:names[i]]&&[b.kind isEqual:names[i]]);CHECK(c.constant==0);}if(count==6){CHECK([((NSLayoutAnchor *)constraints[4].firstAnchor).kind isEqual:@"height"]);CHECK([((NSLayoutAnchor *)constraints[5].firstAnchor).kind isEqual:@"width"]);for(NSUInteger i=4;i<6;i++){CHECK(((NSLayoutAnchor *)constraints[i].firstAnchor).owner==inner);CHECK(!constraints[i].secondAnchor&&constraints[i].constant==45);}}}
static void CheckBorder(UITableViewCell *cell){CHECK(cell.layer.borderWidth==1);CHECK(fabs(CGColorGetAlpha(cell.layer.borderColor)-.1)<1e-12);}

static void TestInitialization(void){
    Reset();preferred=2;NSMutableString *text=[NSMutableString stringWithString:@"retained"];
    NSUInteger before=preferredReads;TranslatorVC *vc=[[TranslatorVC alloc]initWithText:text];
    CHECK(vc.style==2&&Index(vc)==2&&preferredReads==before+1);
    CHECK(ObjectIvar(vc,"_sourceText")==text);[text appendString:@" mutable"];CHECK([ObjectIvar(vc,"_sourceText") isEqual:@"retained mutable"]);
    CHECK(!ObjectIvar(vc,"_tableView")&&!ObjectIvar(vc,"_translateButton")&&!ObjectIvar(vc,"_textView"));
    NSArray *type=ObjectIvar(vc,"_type"),*translation=ObjectIvar(vc,"_translation"),*translate=ObjectIvar(vc,"_translate"),*sections=ObjectIvar(vc,"_sections");
    CHECK([type isEqual:@[@{@"title":@"L:Language",@"indexes":languages,@"type":@"menu",@"key":@"languageKey",@"id":@"typeCell"}]]);
    CHECK([translation isEqual:@[@{@"type":@"textView",@"id":@"translationCell"}]]);
    CHECK([translate isEqual:@[@{@"title":@"L:Translate",@"type":@"action",@"key":@"translateText",@"id":@"translateCell"}]]);
    CHECK(sections.count==2&&sections[0]==type&&sections[1]==translation);
    CHECK([vc numberOfSectionsInTableView:nil]==2);CHECK([vc tableView:nil numberOfRowsInSection:0]==1);CHECK([vc tableView:nil numberOfRowsInSection:1]==1);
    CHECK([vc tableView:nil heightForRowAtIndexPath:Path(0)]==UITableViewAutomaticDimension);CHECK([vc tableView:nil heightForRowAtIndexPath:Path(1)]==300);
    [vc setValue:@[translation,type,translation] forKey:@"_sections"];
    CHECK([vc tableView:nil heightForRowAtIndexPath:Path(0)]==300);CHECK([vc tableView:nil heightForRowAtIndexPath:Path(2)]==UITableViewAutomaticDimension);
    CHECK(![vc tableView:nil shouldHighlightRowAtIndexPath:Path(99)]);
    NSIndexPath *path=Path(5);[vc tableView:vc.tableView didSelectRowAtIndexPath:path];CHECK(vc.tableView.deselected==path&&vc.tableView.deselectAnimated);
    [vc closeButtonTapped];CHECK(vc.dismissed&&vc.dismissAnimated);
    failInitialization=YES;before=preferredReads;CHECK(![[TranslatorVC alloc]initWithText:@"fail"]);CHECK(before==preferredReads);failInitialization=NO;
    vc=[[TranslatorVC alloc]initWithText:nil];CHECK(!ObjectIvar(vc,"_sourceText"));
}
static void TestViewAndHeaders(void){
    for(NSUInteger mode=0;mode<2;mode++){@autoreleasepool{
        Reset();oled=mode;TranslatorVC *vc=Controller();UIColor *old=[UIColor systemGrayColor];vc.tableView.backgroundColor=old;
        [events removeAllObjects];[vc viewDidLoad];CHECK(vc.loaded);CHECK([events.firstObject isEqual:@"super.viewDidLoad"]);
        CHECK([vc.title isEqual:@"L:Translation"]&&vc.tableView.separatorStyle==0);
        UIColor *tint=vc.tableView.tintColor;CHECK(tint.red==.75&&tint.green==.5&&tint.blue==.9&&tint.alpha==1);
        UIBarButtonItem *item=vc.navigationItem.rightBarButtonItem;CHECK(item.systemItem==24&&item.target==vc&&item.action==@selector(closeButtonTapped));
        CHECK(requests.count==1&&!ObjectIvar(vc,"_textView"));TranslatorFixtureRequest *r=requests[0];CHECK([r.text isEqual:@"original input"]&&[r.source isEqual:@"auto"]&&[r.target isEqual:@"fixture-1"]);
        if(mode){CHECK(vc.tableView.backgroundColor.provider!=nil);for(NSInteger style=-1;style<4;style++){UITraitCollection *traits=[UITraitCollection new];traits.userInterfaceStyle=style;CHECK([vc.tableView.backgroundColor.provider(traits).name isEqual:style==2?@"black":@"white"]);}}
        else CHECK(vc.tableView.backgroundColor==old);
        UITableViewHeaderFooterView *header=[UITableViewHeaderFooterView new];vc.fixtureHeader=@"MiXeD é";
        [vc tableView:vc.tableView willDisplayHeaderView:header forSection:7];CHECK(vc.headerTable==vc.tableView&&vc.headerSection==7);CHECK([header.textLabel.text isEqual:@"MIXED É"]);
        CHECK(header.textLabel.font.pointSize==13&&header.textLabel.font.weight==UIFontWeightSemibold);CHECK([header.textLabel.textColor.name isEqual:@"secondary"]);CHECK(header.textLabel.textAlignment==4&&header.textLabel.numberOfLines==0);
        vc.fixtureHeader=nil;[vc tableView:vc.tableView willDisplayHeaderView:header forSection:0];CHECK(!header.textLabel.text);
    }}Reset();
}
static void TestCells(void){
    Reset();TranslatorVC *vc=Controller();vc.view=[UIView new];CHECK(vc.view.tintColor!=vc.tableView.tintColor);NSUInteger count=cellAllocations;
    UITableViewCell *menu=Cell(vc,0);CHECK(cellAllocations==count+2);CHECK(menu.style==3&&[menu.reuseIdentifier isEqual:@"typeCell"]);CHECK([vc.tableView.dequeuedIdentifier isEqual:@"cell"]);
    CHECK([menu.textLabel.text isEqual:@"L:L:Language"]&&menu.textLabel.numberOfLines==0);CHECK([menu.backgroundColor.name isEqual:@"background"]);CheckBorder(menu);
    CHECK([((UIButton *)menu.accessoryView).menu.title isEqual:@"L:L:Language"]);
    vc.tableView.reusable=menu;count=cellAllocations;UITableViewCell *newMenu=Cell(vc,0);CHECK(newMenu!=menu&&cellAllocations==count+1);
    UITableViewCell *text=Cell(vc,1);UITextView *view=ObjectIvar(vc,"_textView");CHECK(text.style==3&&[text.reuseIdentifier isEqual:@"translationCell"]);CHECK([text.backgroundColor.name isEqual:@"clear"]);CheckBorder(text);
    CHECK(text.contentView.subviews.count==1&&text.contentView.subviews[0]==view);CHECK([view.font.style isEqual:UIFontTextStyleBody]&&[view.font.kind isEqual:@"preferred"]);
    CHECK(!view.editable&&view.selectable&&view.dataDetectorTypes==2);CHECK(view.linkTextAttributes.count==1&&view.linkTextAttributes[NSForegroundColorAttributeName]==vc.view.tintColor);CHECK(!view.translatesAutoresizingMaskIntoConstraints);CHECK(!view.text);
    CheckEdges(view,text.contentView,4);view.text=@"old result";UITableViewCell *replacement=Cell(vc,1);CHECK(ObjectIvar(vc,"_textView")!=view);CHECK(!((UITextView *)ObjectIvar(vc,"_textView")).text);CHECK(replacement!=text&&[view.text isEqual:@"old result"]);
    NSArray *sections=ObjectIvar(vc,"_sections");[vc setValue:[sections arrayByAddingObject:ObjectIvar(vc,"_translate")] forKey:@"_sections"];
    UITableViewCell *action=Cell(vc,2);UIButton *button=ObjectIvar(vc,"_translateButton");CHECK(action.style==3&&[action.reuseIdentifier isEqual:@"translateCell"]);CHECK(!action.textLabel.text&&[action.backgroundColor.name isEqual:@"clear"]);
    CHECK(button.type==1&&[button.title isEqual:@"L:Translate"]);CHECK(button.target==vc&&button.action==@selector(translateText)&&button.events==64);
    CHECK(button.backgroundColor==vc.view.tintColor&&[button.tintColor.name isEqual:@"white"]);CHECK(button.titleLabel.textAlignment==1&&button.titleLabel.font.pointSize==17&&[button.titleLabel.font.kind isEqual:@"bold"]);
    CHECK(button.layer.cornerRadius==10&&button.layer.masksToBounds&&!button.translatesAutoresizingMaskIntoConstraints);CHECK(action.contentView.subviews.count==1&&action.contentView.subviews[0]==button);CheckEdges(button,action.contentView,6);
    ((void(*)(id,SEL))objc_msgSend)(button.target,button.action);CHECK(requests.count==1);
    // Type and action-key tests are independent in the original method.
    [vc setValue:@[@[@{@"type":@"textView",@"id":@"combined",@"key":@"translateText",@"title":@"direct title"}]] forKey:@"_sections"];
    UITableViewCell *combined=Cell(vc,0);CHECK(combined.contentView.subviews.count==2);CHECK(combined.contentView.subviews[0]==ObjectIvar(vc,"_textView"));CHECK(combined.contentView.subviews[1]==ObjectIvar(vc,"_translateButton"));CHECK([((UIButton *)ObjectIvar(vc,"_translateButton")).title isEqual:@"direct title"]);
    [vc setValue:@[@[@{@"id":@"unknown",@"type":@"unknown"}]] forKey:@"_sections"];UITableViewCell *unknown=Cell(vc,0);CHECK([unknown.reuseIdentifier isEqual:@"unknown"]&&!unknown.accessoryView&&unknown.contentView.subviews.count==0);
    [vc setValue:nil forKey:@"_sections"];CHECK(Cell(vc,0)==menu);vc.tableView.reusable=nil;count=cellAllocations;UITableViewCell *fallback=Cell(vc,0);CHECK(cellAllocations==count+1&&fallback.style==3&&[fallback.reuseIdentifier isEqual:@"cell"]);
    [vc setValue:@[] forKey:@"_sections"];BOOL raised=NO;@try{(void)Cell(vc,0);}@catch(NSException *exception){raised=[exception.name isEqual:NSRangeException];}CHECK(raised);
}
@interface TranslatorMissingIndexArray : NSArray @end
@implementation TranslatorMissingIndexArray
- (NSUInteger)count{return 1;}
- (id)objectAtIndex:(NSUInteger)index{CHECK(index==0);return @"unfindable";}
- (NSUInteger)indexOfObject:(id)object{return NSNotFound;}
@end
static void TestMenusAndRendering(void){
    Reset();TranslatorVC *vc=Controller();languages=@[@"database English",@"database Arabic",@"database Japanese"];
    NSArray *labels=@[@"same",@"same",@"third"];NSUInteger reads=languageReads;
    for(NSInteger direction=0;direction<3;direction++){
        layoutDirection=direction;UIButton *button=[vc menuButtonWithTitle:@"unlocalized title" array:labels];
        CHECK(languageReads==++reads);CHECK(button.type==1&&[button.title isEqual:@"database Arabic"]);CHECK(button.semanticContentAttribute==(direction==1?3:4));CHECK([vc isRTL]==(direction==1));
        CHECK(button.titleLabel.font.pointSize==13&&[button.titleLabel.font.kind isEqual:@"system"]);CHECK(button.titleColor==vc.view.tintColor&&button.sizedToFit&&button.showsMenuAsPrimaryAction);
        CHECK([button.menu.title isEqual:@"unlocalized title"]&&button.menu.children.count==3);CHECK([button.image.name isEqual:@"rendered"]);
        CHECK(CGSizeEqualToSize(rendererSize,CGSizeMake(14,14)));CHECK(CGRectEqualToRect(renderedView.frame,CGRectMake(0,0,14,14)));CHECK(renderedView.subviews.count==1);UIImageView *image=(id)renderedView.subviews[0];CHECK([image.image.name isEqual:@"chevron.up.chevron.down"]&&image.contentMode==1&&image.clipsToBounds&&CGRectEqualToRect(image.frame,renderedView.bounds));
        for(NSUInteger i=0;i<3;i++){UIAction *a=button.menu.children[i];CHECK([a.title isEqual:labels[i]]&&!a.image&&!a.identifier);CHECK(a.state==0);}
        [events removeAllObjects];UIAction *duplicate=button.menu.children[1];duplicate.handler(duplicate);CHECK(Index(vc)==0);CHECK([events.firstObject isEqual:@"reload.sections"]);CHECK([events.lastObject isEqual:@"request"]);CHECK(vc.tableView.animation==5&&[vc.tableView.reloadedSections isEqual:[NSIndexSet indexSetWithIndex:0]]);
        SetIndex(vc,1);
    }
    SetIndex(vc,0);UIButton *button=[vc menuButtonWithTitle:@"duplicates" array:labels];CHECK(button.menu.children[0].state==1&&button.menu.children[1].state==1&&button.menu.children[2].state==0);
    UIAction *third=button.menu.children[2];third.handler(third);CHECK(Index(vc)==2&&[((TranslatorFixtureRequest *)requests.lastObject).target isEqual:@"fixture-2"]);
    NSUInteger count=requests.count;third.handler(nil);CHECK(requests.count==count+1); // Re-selecting current language still retranslates.
    UIButton *empty=[vc menuButtonWithTitle:@"empty" array:@[]];CHECK(empty.menu.children.count==0&&empty.showsMenuAsPrimaryAction);
    UIButton *nilArray=[vc menuButtonWithTitle:nil array:nil];CHECK(!nilArray.menu.title&&nilArray.menu.children.count==0);
    UIButton *missing=[vc menuButtonWithTitle:@"missing" array:[TranslatorMissingIndexArray new]];CHECK(missing.menu.children.count==1);UIAction *missingAction=missing.menu.children[0];count=requests.count;[events removeAllObjects];missingAction.handler(missingAction);CHECK(Index(vc)==2&&requests.count==count&&events.count==0);
    NSMutableArray *longLabels=[NSMutableArray new];for(NSUInteger i=0;i<24;i++)[longLabels addObject:[NSString stringWithFormat:@"Language %lu",(unsigned long)i]];
    languages=longLabels;SetIndex(vc,23);UIButton *longMenu=[vc menuButtonWithTitle:@"long" array:longLabels];CHECK(longMenu.menu.children.count==24);for(NSUInteger i=0;i<24;i++){CHECK([longMenu.menu.children[i].title isEqual:longLabels[i]]);CHECK(longMenu.menu.children[i].state==(i==23));}
    NSMutableArray *mutating=[@[@"first",@"second"]mutableCopy];mutateDuringAction=mutating;BOOL mutationRaised=NO;@try{[vc menuButtonWithTitle:@"mutation" array:mutating];}@catch(NSException *exception){mutationRaised=[exception.name isEqual:NSGenericException];}CHECK(mutationRaised);mutateDuringAction=nil;
    SetIndex(vc,-1);BOOL raised=NO;@try{[vc menuButtonWithTitle:@"invalid" array:@[]];}@catch(NSException *exception){raised=[exception.name isEqual:NSRangeException];}CHECK(raised);
    for(double size=0;size<=25;size+=12.5){UIImage *render=[vc systemImage:@"arbitrary.symbol" withSize:size];CHECK([render.name isEqual:@"rendered"]);CHECK(CGSizeEqualToSize(rendererSize,CGSizeMake(size,size)));CHECK(CGRectEqualToRect(renderedView.frame,CGRectMake(0,0,size,size)));CHECK([((UIImageView *)renderedView.subviews[0]).image.name isEqual:@"arbitrary.symbol"]);}
}
static void TestTranslation(void){
    Reset();TranslatorVC *vc=Controller();Cell(vc,1);UITextView *text=ObjectIvar(vc,"_textView");
    [vc setValue:[ObjectIvar(vc,"_sections") arrayByAddingObject:ObjectIvar(vc,"_translate")] forKey:@"_sections"];Cell(vc,2);UIButton *button=ObjectIvar(vc,"_translateButton");
    button.enabled=NO;button.title=@"before";text.font=[UIFont italicSystemFontOfSize:22];UIFont *oldFont=text.font;
    [events removeAllObjects];[vc translateText];CHECK([events isEqual:@[@"localize:Translating",@"text:L:Translating",@"color:rgba",@"language:1",@"request"]]);CHECK(!button.enabled&&[button.title isEqual:@"before"]&&text.font==oldFont);CHECK(text.textColor==vc.tableView.tintColor);
    [events removeAllObjects];Complete(0,@"translated",nil);CHECK([events isEqual:@[@"enqueue.main"]]);CHECK([text.text isEqual:@"L:Translating"]&&!button.enabled&&pending.count==1);
    [events removeAllObjects];Drain();CHECK([events isEqual:@[@"button.enabled:1",@"localize:Translate",@"button.title:L:Translate",@"text:translated",@"color:label",@"font:preferred"]]);CHECK(button.enabled&&[button.title isEqual:@"L:Translate"]&&[text.text isEqual:@"translated"]);CHECK([text.textColor.name isEqual:@"label"]&&[text.font.style isEqual:UIFontTextStyleBody]);
    NSError *error=[NSError errorWithDomain:@"synthetic" code:27 userInfo:@{NSLocalizedDescriptionKey:@"expected failure"}];[events removeAllObjects];Complete(0,@"ignored",error);CHECK([events isEqual:@[@"enqueue.main"]]);CHECK([text.text isEqual:@"translated"]);[events removeAllObjects];Drain();CHECK([events isEqual:@[@"button.enabled:1",@"localize:Translate",@"button.title:L:Translate",@"text:expected failure",@"color:red",@"font:italic"]]);CHECK([text.text isEqual:@"expected failure"]&&[text.textColor.name isEqual:@"red"]&&[text.font.kind isEqual:@"italic"]&&text.font.pointSize==14);
    [vc translateText];CHECK([text.text isEqual:@"L:Translating"]&&[text.font.kind isEqual:@"italic"]); // Loading does not reset an earlier error's italic font.
    Complete(1,nil,nil);Drain();CHECK(!text.text&&[text.textColor.name isEqual:@"label"]&&[text.font.kind isEqual:@"preferred"]);
    // No request identity or stale-result suppression: callbacks write in completion order.
    SetIndex(vc,2);[vc translateText];CHECK(requests.count==3);Complete(2,@"new language",nil);Complete(0,@"old language finishes later",nil);Drain();CHECK([text.text isEqual:@"old language finishes later"]);
    Complete(0,@"queued for current view",nil);Cell(vc,1);UITextView *current=ObjectIvar(vc,"_textView");CHECK(current!=text&&!current.text);Drain();CHECK([current.text isEqual:@"queued for current view"]&&[text.text isEqual:@"old language finishes later"]);
    // viewDidLoad writes the placeholder itself and then translateText repeats it.
    [events removeAllObjects];[vc viewDidLoad];NSUInteger placeholderWrites=0;for(NSString *event in events)if([event isEqual:@"text:L:Translating"])placeholderWrites++;CHECK(placeholderWrites==2);
    [vc closeButtonTapped];Complete(0,@"after dismissal",nil);Drain();CHECK([current.text isEqual:@"after dismissal"]);
    Reset();vc=[[TranslatorVC alloc]initWithText:nil];[vc translateText];CHECK(!((TranslatorFixtureRequest *)requests[0]).text);Complete(0,nil,error);Drain();CHECK(!ObjectIvar(vc,"_textView")&&!ObjectIvar(vc,"_translateButton"));
}
static void TestOwnership(void){
    Reset();__weak TranslatorVC *weakController;
    @autoreleasepool{TranslatorVC *vc=Controller();weakController=vc;[vc translateText];vc=nil;CHECK(weakController!=nil);Complete(0,@"value",nil);[requests removeAllObjects];}
    CHECK(weakController!=nil);@autoreleasepool{Drain();}CHECK(!weakController);
    __weak NSString *weakResult;__weak NSError *weakError;
    @autoreleasepool{TranslatorVC *vc=Controller();[vc translateText];NSString *result=[[NSString alloc]initWithFormat:@"temporary-%d",71];NSError *error=[[NSError alloc]initWithDomain:@"owned callback" code:1 userInfo:nil];weakResult=result;weakError=error;Complete(0,result,error);[requests removeAllObjects];}
    CHECK(weakResult&&weakError);@autoreleasepool{Drain();}CHECK(!weakResult&&!weakError);
    __strong UIAction *retainedAction;
    @autoreleasepool{TranslatorVC *vc=Controller();weakController=vc;UIButton *button=[vc menuButtonWithTitle:@"retained menu" array:@[@"only"]];retainedAction=button.menu.children[0];}
    CHECK(weakController!=nil&&retainedAction!=nil);retainedAction=nil;CHECK(!weakController);
    // All eight object ivars are strong, including the otherwise unused private _tableView.
    __weak id probes[8];const char *names[]={"_tableView","_translateButton","_textView","_sourceText","_sections","_type","_translation","_translate"};
    @autoreleasepool{TranslatorVC *vc=Controller();for(NSUInteger i=0;i<8;i++){NSObject *probe=[NSObject new];probes[i]=probe;object_setIvarWithStrongDefault(vc,class_getInstanceVariable(TranslatorVC.class,names[i]),probe);}for(NSUInteger i=0;i<8;i++)CHECK(probes[i]!=nil);}
    for(NSUInteger i=0;i<8;i++)CHECK(probes[i]==nil);
}
int main(void){@autoreleasepool{events=[NSMutableArray new];pending=[NSMutableArray new];requests=[NSMutableArray new];
    TestInitialization();TestViewAndHeaders();TestCells();TestMenusAndRendering();TestTranslation();TestOwnership();Reset();
    printf("TRANSLATOR_UI_RUNTIME_PASS %lu assertions; actual TranslatorVC source, isolated UIKit/translation/dispatch boundaries\n",(unsigned long)checks);
}return 0;}
