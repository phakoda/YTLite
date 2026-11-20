// Host-only message/argument recorders; never part of a production build.
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import <objc/message.h>
#import <objc/runtime.h>

const UIFontWeight UIFontWeightSemibold=0.3, UIFontWeightLight=-0.4, UIFontWeightRegular=0;
const CGFloat UITableViewAutomaticDimension=-1;
const CGSize UILayoutFittingCompressedSize={0,0};
NSAttributedStringKey const NSFontAttributeName=@"NSFont",NSForegroundColorAttributeName=@"NSColor";
static CGContextRef currentContext;
CGFloat SettingsMeasuredFooterHeight = 13.9;
@implementation UIFont
+ (instancetype)systemFontOfSize:(CGFloat)size { return [self systemFontOfSize:size weight:0]; }
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight {
    UIFont *font=[self new];font.pointSize=size;font.recoveredTestWeight=weight;return font;
}
@end
@implementation UIColor
+ (BOOL)supportsSecureCoding { return YES; }
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    UIColor *c=[self new];c.recoveredRed=r;c.recoveredGreen=g;c.recoveredBlue=b;c.recoveredAlpha=a;
    CGColorSpaceRef space=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
    CGFloat values[]={r,g,b,a};c->_color=CGColorCreate(space,values);CGColorSpaceRelease(space);return c;
}
- (instancetype)initWithCoder:(NSCoder *)coder {
    return [UIColor colorWithRed:[coder decodeDoubleForKey:@"r"] green:[coder decodeDoubleForKey:@"g"]
                           blue:[coder decodeDoubleForKey:@"b"] alpha:[coder decodeDoubleForKey:@"a"]];
}
- (void)encodeWithCoder:(NSCoder *)coder {
    [coder encodeDouble:_recoveredRed forKey:@"r"];[coder encodeDouble:_recoveredGreen forKey:@"g"];
    [coder encodeDouble:_recoveredBlue forKey:@"b"];[coder encodeDouble:_recoveredAlpha forKey:@"a"];
}
- (CGColorRef)CGColor { return _color; }
- (void)dealloc { if (_color) CGColorRelease(_color); }
+ (instancetype)clearColor { return [self colorWithRed:0 green:0 blue:0 alpha:0]; }
+ (instancetype)labelColor { return [self blackColor]; }
+ (instancetype)secondaryLabelColor { return [self colorWithRed:0.4 green:0.4 blue:0.4 alpha:1]; }
+ (instancetype)grayColor { return [self colorWithRed:0.5 green:0.5 blue:0.5 alpha:1]; }
+ (instancetype)blackColor { return [self colorWithRed:0 green:0 blue:0 alpha:1]; }
+ (instancetype)whiteColor { return [self colorWithRed:1 green:1 blue:1 alpha:1]; }
+ (instancetype)systemBackgroundColor { return [self whiteColor]; }
+ (instancetype)systemRedColor { return [self colorWithRed:1 green:0 blue:0 alpha:1]; }
+ (instancetype)redColor { return [self systemRedColor]; }
- (instancetype)colorWithAlphaComponent:(CGFloat)a { return [UIColor colorWithRed:_recoveredRed green:_recoveredGreen blue:_recoveredBlue alpha:a]; }
- (void)setFill { if(currentContext) CGContextSetFillColorWithColor(currentContext,self.CGColor); }
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray *)constraints { for(NSLayoutConstraint *c in constraints)c.active=YES; }
- (void)setActive:(BOOL)active { _active=active;if(active)SettingsRecord(@"constraint",self); }
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor { return [self constraintEqualToAnchor:anchor constant:0]; }
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)constant {
    NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;c.constant=constant;return c;
}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)constant { return [self constraintEqualToAnchor:nil constant:constant]; }
@end
static NSLayoutAnchor *anchorFor(id owner,NSString *kind) { NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=owner;a.kind=kind;return a; }
#define SETTINGS_ANCHORS \
- (NSLayoutAnchor *)topAnchor { return anchorFor(self,@"top"); } \
- (NSLayoutAnchor *)bottomAnchor { return anchorFor(self,@"bottom"); } \
- (NSLayoutAnchor *)leadingAnchor { return anchorFor(self,@"leading"); } \
- (NSLayoutAnchor *)trailingAnchor { return anchorFor(self,@"trailing"); } \
- (NSLayoutAnchor *)centerXAnchor { return anchorFor(self,@"centerX"); } \
- (NSLayoutAnchor *)centerYAnchor { return anchorFor(self,@"centerY"); } \
- (NSLayoutAnchor *)heightAnchor { return anchorFor(self,@"height"); }
@implementation UILayoutGuide
SETTINGS_ANCHORS
@end
@interface UIView ()
@property(nonatomic,strong) NSMutableArray *fixtureSubviews;
@property(nonatomic,strong) UILayoutGuide *fixtureSafeArea,*fixtureMargins;
@end
@implementation UIView
- (instancetype)init {
    self=[super init];if(self){_layer=[CALayer layer];_fixtureSubviews=[NSMutableArray array];
        _fixtureSafeArea=[UILayoutGuide new];_fixtureMargins=[UILayoutGuide new];
        _tintColor=[UIColor colorWithRed:0 green:0 blue:1 alpha:1];_userInteractionEnabled=YES;_translatesAutoresizingMaskIntoConstraints=YES;}
    return self;
}
- (instancetype)initWithFrame:(CGRect)frame { self=[self init];if(self)self.frame=frame;return self; }
- (void)setFrame:(CGRect)frame { _frame=frame;_bounds.size=frame.size;_layer.frame=frame; }
- (void)setBounds:(CGRect)bounds { _bounds=bounds;_layer.bounds=bounds; }
- (void)addSubview:(UIView *)view { if(!view)return;[_fixtureSubviews addObject:view];view.superview=self;[_layer addSublayer:view.layer]; }
- (NSArray *)subviews { return _fixtureSubviews; }
- (UILayoutGuide *)safeAreaLayoutGuide { return _fixtureSafeArea; }
- (UILayoutGuide *)layoutMarginsGuide { return _fixtureMargins; }
- (void)layoutSubviews { _recoveredLayoutCalls++; }
- (void)sizeToFit { _recoveredSizeToFitCalls++; }
- (BOOL)resignFirstResponder { _recoveredResignCalls++;return YES; }
- (CGSize)systemLayoutSizeFittingSize:(CGSize)size { (void)size;return CGSizeMake(self.frame.size.width,38); }
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations { SettingsRecord(@"animation",@(duration));animations(); }
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute {
    return attribute==UISemanticContentAttributeForceRightToLeft?UIUserInterfaceLayoutDirectionRightToLeft:UIUserInterfaceLayoutDirectionLeftToRight;
}
SETTINGS_ANCHORS
@end
@implementation UILabel
- (instancetype)init { self=[super init];if(self)_textColor=UIColor.labelColor;return self; }
- (void)setText:(NSString *)text { _text=[text copy];_attributedText=nil; }
- (void)setAttributedText:(NSAttributedString *)text { _attributedText=[text copy];_text=text.string; }
@end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name { if(!name)return nil;UIImage *image=[self new];image.recoveredName=name;return image; }
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits {
    (void)bundle;(void)traits;SettingsRecord(@"imageNamed",name);return [self systemImageNamed:name];
}
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode { UIImage *image=[UIImage new];image.recoveredName=_recoveredName;image.size=_size;image.renderingMode=mode;return image; }
@end
@implementation UIImageView
- (instancetype)initWithImage:(UIImage *)image { self=[super init];if(self)_image=image;return self; }
@end
@implementation NSTextAttachment @end
@implementation NSAttributedString (SettingsFixtureAttachment)
+ (instancetype)attributedStringWithAttachment:(NSTextAttachment *)attachment {
    return [[self alloc]initWithString:@"\uFFFC" attributes:@{@"attachment":attachment}];
}
@end
@implementation NSString (SettingsFixtureDrawing)
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options attributes:(NSDictionary *)attributes context:(id)context {
    (void)context;SettingsRecord(@"boundingRect",@{@"width":@(size.width),@"height":@(size.height),@"options":@(options),@"attributes":attributes});
    // Deterministic fractional result distinguishes truncation from ceil().
    return CGRectMake(0,0,size.width,SettingsMeasuredFooterHeight);
}
@end
@implementation UIGraphicsImageRendererContext @end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size { self=[super init];if(self)_recoveredSize=size;return self; }
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions {
    SettingsRecord(@"renderer",@[@(_recoveredSize.width),@(_recoveredSize.height)]);
    CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();
    CGContextRef cg=CGBitmapContextCreate(NULL,MAX((size_t)_recoveredSize.width,1),MAX((size_t)_recoveredSize.height,1),8,0,space,(CGBitmapInfo)kCGImageAlphaPremultipliedLast);
    CGColorSpaceRelease(space);NSCAssert(cg!=NULL,@"fixture drawing context");
    UIGraphicsImageRendererContext *context=[UIGraphicsImageRendererContext new];context.CGContext=cg;
    CGContextRef previous=currentContext;currentContext=cg;actions(context);currentContext=previous;CGContextRelease(cg);
    UIImage *image=[UIImage new];image.size=_recoveredSize;return image;
}
@end
@implementation UIScreen
+ (instancetype)mainScreen { static UIScreen *screen; if(!screen){screen=[self new];screen.bounds=CGRectMake(0,0,390,844);screen.scale=3;}return screen; }
@end
@implementation UITraitCollection
- (BOOL)hasDifferentColorAppearanceComparedToTraitCollection:(UITraitCollection *)other { (void)other;return _recoveredDifferentAppearance; }
@end
@implementation UINavigationItem @end
@implementation UIViewController
- (instancetype)init { self=[super init];if(self){_navigationItem=[UINavigationItem new];_traitCollection=[UITraitCollection new];}return self; }
- (UIView *)view { if(!_view){[self loadView];[self viewDidLoad];}return _view; }
- (BOOL)recoveredLoaded { return _view!=nil; }
- (void)loadView { self.view=[[UIView alloc]initWithFrame:CGRectMake(0,0,390,844)]; }
- (void)viewDidLoad { SettingsRecord(@"super.viewDidLoad",NSStringFromClass(self.class)); }
- (void)viewWillAppear:(BOOL)animated { SettingsRecord(@"super.viewWillAppear",@(animated)); }
- (void)viewDidAppear:(BOOL)animated { SettingsRecord(@"super.viewDidAppear",@(animated)); }
- (void)traitCollectionDidChange:(UITraitCollection *)traits { (void)traits;SettingsRecord(@"super.traitChanged",@YES); }
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion { SettingsRecord(@"dismiss",@(animated));if(completion)completion(); }
@end
@implementation UINavigationController
- (void)pushViewController:(UIViewController *)controller animated:(BOOL)animated { self.recoveredPushedController=controller;self.recoveredPushAnimated=animated; }
@end
@implementation UIScrollView @end
@implementation UITableView
- (instancetype)init { self=[super init];if(self)_recoveredCells=[NSMutableDictionary dictionary];return self; }
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier { SettingsRecord(@"dequeue",identifier);return nil; }
- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath { return _recoveredCells[indexPath]; }
- (void)reloadData { _recoveredReloads++; }
- (void)reloadRowsAtIndexPaths:(NSArray *)paths withRowAnimation:(UITableViewRowAnimation)animation { _recoveredReloadedRows=paths;_recoveredAnimation=animation; }
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation { _recoveredReloadedSections=sections;_recoveredAnimation=animation; }
- (void)scrollToRowAtIndexPath:(NSIndexPath *)path atScrollPosition:(UITableViewScrollPosition)position animated:(BOOL)animated { _recoveredScrolled=path;_recoveredScrollPosition=position;SettingsRecord(@"scrollAnimated",@(animated)); }
- (void)deselectRowAtIndexPath:(NSIndexPath *)path animated:(BOOL)animated { _recoveredDeselected=path;SettingsRecord(@"deselectAnimated",@(animated)); }
- (void)setEditing:(BOOL)editing animated:(BOOL)animated { _recoveredEditing=editing;SettingsRecord(@"editingAnimated",@(animated)); }
- (void)moveRowAtIndexPath:(NSIndexPath *)source toIndexPath:(NSIndexPath *)destination { _recoveredMoveSource=source;_recoveredMoveDestination=destination; }
@end
@implementation UITableViewController
- (instancetype)initWithStyle:(UITableViewStyle)style { self=[super init];if(self)_recoveredStyle=style;return self; }
- (void)loadView { self.tableView=[[UITableView alloc]initWithFrame:CGRectMake(0,0,390,844)];self.view=self.tableView; }
- (UITableView *)tableView { if(!_tableView)(void)self.view;return _tableView; }
@end
@implementation UITableViewCell
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier {
    self=[super init];if(self){_recoveredStyle=style;_reuseIdentifier=[identifier copy];_textLabel=[UILabel new];_detailTextLabel=[UILabel new];
        _imageView=[UIImageView new];_contentView=[UIView new];[self addSubview:_contentView];[_contentView addSubview:_textLabel];[_contentView addSubview:_detailTextLabel];}
    return self;
}
- (void)setSelected:(BOOL)selected animated:(BOOL)animated { _recoveredSelected=selected;_recoveredSelectionAnimated=animated; }
- (void)setValue:(id)value forKey:(NSString *)key {
    if([key isEqual:@"_selectionFadeDuration"])_recoveredSelectionFade=[value doubleValue];else[super setValue:value forKey:key];
}
@end
@implementation UITableViewHeaderFooterView
- (instancetype)init { self=[super init];if(self)_textLabel=[UILabel new];return self; }
@end
@implementation NSIndexPath (SettingsFixtureTable)
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section { NSUInteger indexes[]={(NSUInteger)section,(NSUInteger)row};return [self indexPathWithIndexes:indexes length:2]; }
- (NSInteger)row { return (NSInteger)[self indexAtPosition:1]; }
- (NSInteger)section { return (NSInteger)[self indexAtPosition:0]; }
@end
@interface SettingsControlTarget : NSObject
@property(nonatomic,weak) id target;
@property(nonatomic) SEL action;
@property(nonatomic) UIControlEvents events;
@end
@implementation SettingsControlTarget @end
@implementation UIControl
- (instancetype)init { self=[super init];if(self)_recoveredTargets=[NSMutableArray array];return self; }
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events {
    SettingsControlTarget *entry=[SettingsControlTarget new];entry.target=target;entry.action=action;entry.events=events;[_recoveredTargets addObject:entry];
}
- (void)sendActionsForControlEvents:(UIControlEvents)events {
    for(SettingsControlTarget *entry in _recoveredTargets)if(entry.events & events){id target=entry.target;((void(*)(id,SEL,id))objc_msgSend)(target,entry.action,self);}
}
@end
@implementation UISegmentedControl
- (instancetype)initWithItems:(NSArray *)items { self=[super init];if(self){_recoveredItems=[items mutableCopy];_recoveredAttributes=[NSMutableDictionary dictionary];}return self; }
- (NSInteger)numberOfSegments { return (NSInteger)_recoveredItems.count; }
- (void)setTitleTextAttributes:(NSDictionary *)attributes forState:(UIControlState)state { _recoveredAttributes[@(state)]=attributes; }
- (void)insertSegmentWithImage:(UIImage *)image atIndex:(NSUInteger)index animated:(BOOL)animated { [_recoveredItems insertObject:image atIndex:index];SettingsRecord(@"insertSegmentAnimated",@(animated)); }
@end
@implementation UISlider
- (void)setThumbImage:(UIImage *)image forState:(UIControlState)state { (void)state;_recoveredThumb=image; }
@end
@implementation UIStepper @end
@implementation UIPickerView
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated { _recoveredSelectedRow=row;_recoveredSelectedComponent=component;_recoveredSelectedAnimated=animated; }
@end
@implementation UITextField @end
@implementation UITextView @end
@implementation UISearchBar
- (instancetype)init { self=[super init];if(self){_searchTextField=[UITextField new];[self addSubview:_searchTextField];}return self; }
@end
@implementation UIButton
- (instancetype)init { self=[super init];if(self)_titleLabel=[UILabel new];return self; }
+ (instancetype)buttonWithType:(UIButtonType)type { (void)type;return [self new]; }
- (void)setTitle:(NSString *)title forState:(UIControlState)state { (void)state;_recoveredTitle=[title copy]; }
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state { (void)state;_recoveredTitleColor=color; }
- (void)setImage:(UIImage *)image forState:(UIControlState)state { (void)state;_recoveredImage=image; }
@end
@implementation UIBarButtonItem
- (instancetype)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action {
    self=[super init];if(self){_title=[title copy];_recoveredStyle=style;_target=target;_action=action;}return self;
}
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)item target:(id)target action:(SEL)action {
    self=[super init];if(self){_recoveredSystemItem=item;_target=target;_action=action;}return self;
}
@end
@implementation UIAction
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler {
    (void)image;(void)identifier;UIAction *action=[self new];action.title=title;action.recoveredHandler=handler;return action;
}
@end
@implementation UIMenu
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children { UIMenu *menu=[self new];menu.title=title;menu.children=children;return menu; }
@end
@implementation UIActivityIndicatorView
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style { self=[super init];if(self)_recoveredStyle=style;return self; }
- (void)startAnimating { _recoveredAnimating=YES; }
- (void)stopAnimating { _recoveredAnimating=NO; }
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard { static UIPasteboard *pasteboard;if(!pasteboard)pasteboard=[self new];return pasteboard; }
@end
@implementation UIApplication
+ (instancetype)sharedApplication { static UIApplication *app;if(!app){app=[self new];app.recoveredCanOpen=YES;app.recoveredURLs=[NSMutableArray array];}return app; }
- (BOOL)canOpenURL:(NSURL *)url { _recoveredCanOpenURL=url;return _recoveredCanOpen; }
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {
    NSCAssert(options.count==0 && completion==nil,@"openURL contract");[_recoveredURLs addObject:url];
}
@end
@implementation UIDocumentPickerViewController @end
@implementation WKNavigation @end
@implementation WKWebView
- (instancetype)init { self=[super init];if(self)_scrollView=[UIScrollView new];return self; }
- (WKNavigation *)loadRequest:(NSURLRequest *)request { _recoveredRequest=request;return [WKNavigation new]; }
@end
