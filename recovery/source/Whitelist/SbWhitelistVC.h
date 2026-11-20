#import "../Settings/DVNTableViewController.h"

@interface SbWhitelistVC : DVNTableViewController {
    UIButton *_sortButton;
    NSArray *_sections;
    NSMutableArray *_channels;
}
- (instancetype)init;
- (void)setupWhitelist;
- (void)loadView;
- (void)closeButtonTapped;
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section;
- (NSArray<UIAction *> *)getSortActions;
- (void)updateSortMenu;
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (UISwipeActionsConfiguration *)tableView:(UITableView *)tableView trailingSwipeActionsConfigurationForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)removeChannelWithLink:(NSString *)link;
- (UIImage *)ytlImageWithName:(NSString *)name;
- (UIImage *)channelImage:(UIImage *)image;
@end
