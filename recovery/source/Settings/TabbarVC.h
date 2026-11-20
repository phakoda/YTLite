#import "DVNTableViewController.h"

@interface TabbarVC : DVNTableViewController {
    BOOL _isSettings;
    NSArray *_sections;
    NSArray *_tabs;
    NSArray *_startup;
    NSArray *_tabbar;
    NSMutableArray *_activeTabs;
    NSMutableArray *_inactiveTabs;
}
- (instancetype)initForSettings:(BOOL)isSettings;
- (void)initTabs;
- (void)saveTabsOrder;
- (UIImage *)iconImageNamed:(NSString *)name;
- (UISegmentedControl *)segmentForItems:(NSArray *)items;
@end
