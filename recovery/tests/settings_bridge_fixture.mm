#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "../source/Hooks/SettingsBridgeHost.h"
#import "../source/Settings/YTPSettingsBuilder.h"
#import "../source/Settings/DVNTableViewController.h"
#import "../../Utils/YTLUserDefaults.h"

static NSUInteger checks, originals, sectionCalls, builders, tables, logs;
static NSMutableArray *events;
static NSArray *originalOrder, *lastArguments, *headerButtons;
static __weak id lastReceiver, presenter, wrapperParent;
static SEL lastSelector;
static UIViewController *pushed, *content;
static BOOL pushAnimated;
static NSUserDefaults *defaults;
static DVNTableModel *rootModel;
#define CHECK(v) do {checks++;if(!(v)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#v);exit(1);}}while(0)
void SettingsBridgeLog(NSString *format, ...) { logs++; CHECK([format isEqual:@"DVN --- setSelectedItem: %ld"]); }
@implementation UIColor
+ (UIColor *)labelColor {static UIColor *color; if(!color)color=[UIColor new];return color;}
@end
@implementation UIView
- (void)layoutSubviews {}
@end
@implementation UIButton @end
@implementation UICollectionView @end
@implementation UIViewController @end
@implementation UINavigationController
- (void)pushViewController:(UIViewController *)controller animated:(BOOL)animated { pushed=controller;pushAnimated=animated;[events addObject:@"push"]; }
@end
@implementation UITableViewController @end
@implementation NSIndexPath (SettingsBridgeUIKit)
- (NSInteger)section {return [self indexAtPosition:0];}
- (NSInteger)row {return [self indexAtPosition:1];}
@end
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults {return (YTLUserDefaults *)defaults;}
@end
@implementation YTPSettingsBuilder
- (instancetype)init {if((self=[super init])){builders++;[events addObject:@"builder"];}return self;}
- (void)setPresenter:(UIViewController *)value {_presenter=value;presenter=value;}
- (DVNTableModel *)rootTable {[events addObject:@"model"];return rootModel;}
@end
@implementation DVNTableViewController
- (instancetype)initWithModel:(DVNTableModel *)model defaults:(NSUserDefaults *)value {
    if((self=[super init])){tables++;CHECK(model==rootModel);CHECK(value==defaults);[events addObject:@"table"];}return self;
}
@end
@interface HeaderFixture : NSObject <YTLSettingsHeader> @end
@implementation HeaderFixture
- (void)updateHeaderWithButtonsToDisplay:(NSArray *)buttons {headerButtons=buttons;[events addObject:@"header"];}
@end
@implementation YTWrapperFlatViewController
- (instancetype)initWithParentResponder:(id)parent {if((self=[super init])){wrapperParent=parent;[events addObject:@"flat"];}return self;}
- (void)setContent:(UIViewController *)value {content=value;}
- (id<YTLSettingsHeader>)headerViewController {return [HeaderFixture new];}
@end
@implementation YTWrapperSplitViewController
- (instancetype)initWithParentResponder:(id)parent {if((self=[super init])){wrapperParent=parent;[events addObject:@"split"];}return self;}
- (void)setContent:(UIViewController *)value {content=value;}
@end
@interface ContainerFixture : UIViewController <YTLSettingsSplitContainer>
@property(nonatomic,strong) UIViewController *secondViewController;
@end
@implementation ContainerFixture
- (void)setSecondViewController:(UIViewController *)value {_secondViewController=value;[events addObject:@"second"];}
@end
@interface EntryFixture : NSObject <YTLSettingsEntry>
@property(nonatomic,strong) NSNumber *categoryId;
@end
@implementation EntryFixture @end
@interface SectionFixture : NSObject <YTLSettingsSection>
@property(nonatomic,strong) NSArray *items;
@end
@implementation SectionFixture @end
@interface YTCollectionViewController ()
@property(nonatomic) BOOL hasSections;
@property(nonatomic,strong) NSArray *fixtureSections;
@end
@implementation YTCollectionViewController
- (BOOL)respondsToSelector:(SEL)selector {return selector==@selector(sectionControllers)?self.hasSections:[super respondsToSelector:selector];}
- (NSArray *)sectionControllers {return self.fixtureSections;}
- (void)collectionView:(UICollectionView *)collection didSelectItemAtIndexPath:(NSIndexPath *)path {
    originals++;lastReceiver=self;lastSelector=_cmd;lastArguments=@[collection,path];[events addObject:@"original"];
}
@end
@interface YTQTMButton () @property(nonatomic) BOOL fixtureStyling; @end
@implementation YTQTMButton
- (void)layoutSubviews {originals++;lastReceiver=self;[events addObject:@"original"];}
- (void)setEnablePageStyling:(BOOL)value {self.fixtureStyling=value;[events addObject:@"styling"];}
@end
@implementation YTAppSettingsPresentationData
+ (NSArray *)settingsCategoryOrder {originals++;lastReceiver=self;lastSelector=_cmd;return originalOrder;}
@end
@implementation YTSettingsSectionController
- (void)setSelectedItem:(NSUInteger)item {originals++;lastReceiver=self;lastArguments=@[@(item)];}
@end
@interface YTSettingsSectionItemManager () @property(nonatomic,strong) id settingsViewControllerDelegate; @end
@implementation YTSettingsSectionItemManager
- (void)updateSectionForCategory:(NSUInteger)category withEntry:(id)entry {originals++;lastReceiver=self;lastArguments=@[@(category),entry];}
@end
@implementation YTIIcon @end
static void recordSection(NSArray *items, NSUInteger category, NSString *title, YTIIcon *icon, NSString *description, BOOL hidden) {
    sectionCalls++; CHECK(items==nil);CHECK(category==789);CHECK([title isEqual:@"YouTube Plus"]);CHECK(description==nil);CHECK(hidden==NO);
    if(icon)CHECK(icon.iconType==530);
}
@interface OldDelegate : NSObject @end
@implementation OldDelegate
- (void)setSectionItems:(NSArray *)items forCategory:(NSUInteger)category title:(NSString *)title titleDescription:(NSString *)description headerHidden:(BOOL)hidden {
    recordSection(items,category,title,nil,description,hidden);[events addObject:@"oldDelegate"];
}
@end
@interface NewDelegate : OldDelegate @end
@implementation NewDelegate
- (void)setSectionItems:(NSArray *)items forCategory:(NSUInteger)category title:(NSString *)title icon:(YTIIcon *)icon titleDescription:(NSString *)description headerHidden:(BOOL)hidden {
    CHECK(icon!=nil);recordSection(items,category,title,icon,description,hidden);[events addObject:@"newDelegate"];
}
@end
@interface YTSettingsGroupData () @property(nonatomic) NSInteger fixtureType; @end
@implementation YTSettingsGroupData
- (NSInteger)type {[events addObject:@"type"];return self.fixtureType;}
- (NSArray *)orderedCategories {originals++;[events addObject:@"original"];return originalOrder;}
@end
static void reset(void) {originals=sectionCalls=builders=tables=0;lastArguments=nil;lastReceiver=nil;lastSelector=NULL;pushed=nil;content=nil;headerButtons=nil;wrapperParent=nil;[events removeAllObjects];}

int main(void) {@autoreleasepool {
    events=[NSMutableArray new];defaults=[[NSUserDefaults alloc]initWithSuiteName:[@"SettingsBridge." stringByAppendingString:NSUUID.UUID.UUIDString]];
    rootModel=(DVNTableModel *)[NSObject new];YTLInstallSettingsBridgeHooks();
    // The original array is preserved. This path returns a mutable copy.
    for(NSArray *order in @[@[],@[@1],@[@2,@1,@3],@[@789,@1],@[@2,@3]]) {
        originalOrder=order;reset();NSArray *result=[YTAppSettingsPresentationData settingsCategoryOrder];
        NSMutableArray *expected=[order mutableCopy];NSUInteger index=[order indexOfObject:@1];if(index!=NSNotFound)[expected insertObject:@789 atIndex:index+1];
        CHECK([result isEqual:expected]);CHECK(result!=order);CHECK([result isKindOfClass:NSMutableArray.class]);CHECK(originals==1);CHECK(lastReceiver==YTAppSettingsPresentationData.class);
    }
    YTSettingsSectionController *sectionController=[YTSettingsSectionController new];
    for(NSNumber *value in @[@0,@(NSNotFound),@(NSUIntegerMax),@(0x100000001ULL)]) {
        reset();NSUInteger oldLogs=logs;[sectionController setSelectedItem:value.unsignedIntegerValue];
        CHECK(logs==oldLogs+1);CHECK(originals==(NSUInteger)(value.unsignedIntegerValue!=NSNotFound));if(originals)CHECK([lastArguments[0]isEqual:value]);
    }
    YTSettingsGroupData *group=[YTSettingsGroupData new];originalOrder=@[@2,@789];
    for(NSNumber *type in @[@0,@1,@2,@(0x100000001LL),@(-1)]) {
        group.fixtureType=type.integerValue;reset();NSArray *result=[group orderedCategories];
        CHECK(originals==1);CHECK(([events isEqual:@[@"type",@"original"]]));
        if(type.integerValue==1){CHECK(([result isEqual:@[@789,@2,@789]]));CHECK(![result isKindOfClass:NSMutableArray.class]);}else CHECK(result==originalOrder);
    }
    YTSettingsSectionItemManager *manager=[YTSettingsSectionItemManager new];id entry=[NSObject new];
    for(id delegate in @[[OldDelegate new],[NewDelegate new]]) {
        manager.settingsViewControllerDelegate=delegate;reset();[manager updateSectionForCategory:789 withEntry:entry];CHECK(originals==0);CHECK(sectionCalls==1);
        CHECK([events isEqual:@[[delegate isKindOfClass:NewDelegate.class]?@"newDelegate":@"oldDelegate"]]);
        reset();[manager updateSectionForCategory:0x100000315ULL withEntry:entry];CHECK(originals==1);CHECK(sectionCalls==0);CHECK(([lastArguments isEqual:@[@(0x100000315ULL),entry]]));
    }
    for(id identifier in @[NSNull.null,@"other",@"id.ui.browse.back.button"]) {
        YTQTMButton *button=[YTQTMButton new];UIColor *old=[UIColor new];button.tintColor=old;button.accessibilityIdentifier=identifier==NSNull.null?nil:identifier;
        reset();[button layoutSubviews];BOOL back=[identifier isEqual:@"id.ui.browse.back.button"];CHECK(originals==1);CHECK(button.fixtureStyling==back);CHECK(button.tintColor==(back?UIColor.labelColor:old));
        CHECK([events.firstObject isEqual:@"original"]);
    }
    YTCollectionViewController *controller=[YTCollectionViewController new];UICollectionView *collection=[UICollectionView new];NSUInteger positions[]={1,1};NSIndexPath *path=[NSIndexPath indexPathWithIndexes:positions length:2];
    SectionFixture *section=[SectionFixture new];EntryFixture *item=[EntryFixture new];item.categoryId=@789;section.items=@[[NSObject new],item];
    controller.fixtureSections=@[[NSObject new],section];controller.hasSections=NO;
    for(NSNumber *fallback in @[@0,@1,@2]) {
        controller.hasSections=fallback.intValue!=0;controller.fixtureSections=@[[NSObject new],fallback.intValue==1?[NSObject new]:section];item.categoryId=fallback.intValue==2?@788:@789;
        reset();[controller collectionView:collection didSelectItemAtIndexPath:path];CHECK(originals==1);CHECK(builders==0);CHECK(lastReceiver==controller);CHECK(([lastArguments isEqual:@[collection,path]]));
    }
    controller.fixtureSections=@[[NSObject new],section];item.categoryId=@789;controller.hasSections=YES;
    UIViewController *parent=[UIViewController new];ContainerFixture *container=[ContainerFixture new];parent.parentViewController=container;controller.parentViewController=parent;controller.navigationController=[UINavigationController new];
    for(NSNumber *split in @[@NO,@YES]) {
        container.secondViewController=split.boolValue?[UIViewController new]:nil;reset();[controller collectionView:collection didSelectItemAtIndexPath:path];
        CHECK(originals==0);CHECK(builders==1&&tables==1);CHECK(presenter==controller);CHECK(wrapperParent==parent);CHECK([content isKindOfClass:DVNTableViewController.class]);
        UIViewController *wrapper=split.boolValue?container.secondViewController:pushed;
        CHECK([wrapper.title isEqual:@"YouTube Plus"]);CHECK([wrapper isKindOfClass:split.boolValue?YTWrapperSplitViewController.class:YTWrapperFlatViewController.class]);
        if(split.boolValue){CHECK(pushed==nil);CHECK(headerButtons==nil);}else{CHECK(pushAnimated);CHECK(headerButtons.count==0&&headerButtons!=nil);}
        CHECK(([events isEqual:split.boolValue?@[@"builder",@"model",@"table",@"split",@"second"]:@[@"builder",@"model",@"table",@"flat",@"header",@"push"]]));
    }
    printf("Settings bridge: %lu actual Logos/runtime assertions passed\n",(unsigned long)checks);
}return 0;}
