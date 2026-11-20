#import "TabbarVC.h"
#import "YTPTableViewCell.h"
#import "SettingsContracts.h"
#import <QuartzCore/QuartzCore.h>

static NSString *SettingsTabLocalized(NSString *key) {
    return [NSBundle.ytl_defaultBundle localizedStringForKey:key value:nil table:nil];
}
static void SettingsTabRefreshPivot(void) {
    YTLSettingsHostHeader *header = [NSClassFromString(@"YTHeaderContentComboViewController") new];
    [header refreshPivotBar];
}

@implementation TabbarVC
// 0x12ea7c.
- (instancetype)init { return [self initForSettings:YES]; }

// 0x12ea8c. This calls initWithStyle:, NOT initWithModel:defaults:. Arrays are
// installed before first accessing tableView (which invokes loadView/initTabs).
- (instancetype)initForSettings:(BOOL)isSettings {
    self = [super initWithStyle:UITableViewStyleGrouped];
    if (self) {
        _isSettings = isSettings;
        _tabs = @[
            @{@"type":@"tab", @"key":@"FEwhat_to_watch"},
            @{@"type":@"tab", @"key":@"FEshorts"},
            @{@"type":@"tab", @"key":@"FEsubscriptions"},
            @{@"type":@"tab", @"key":@"FElibrary"},
            @{@"type":@"tab", @"key":@"FEhistory"},
            @{@"type":@"tab", @"key":@"FEpost_home"},
            @{@"type":@"tab", @"key":@"VLWL"},
            @{@"type":@"tab", @"key":@"FEhype_leaderboard"},
            @{@"type":@"tab", @"key":@"UC-9-kyTW8ZkZNDHQJ6FgpwQ"},
            @{@"type":@"tab", @"key":@"UC4R8DWoMoI7CAwX8_LjQHig"},
            @{@"type":@"tab", @"key":@"UCOpNcN46UbXVtpKMrmU4Abg"},
            @{@"type":@"tab", @"key":@"UCEgdi0XIXXZ-qJOFPf4JSKw"},
            @{@"type":@"tab", @"key":@"FEnotifications_inbox"},
            @{@"type":@"tab", @"key":@"FEuploads"}
        ];
        _startup = @[@{@"type":@"int", @"key":@"startupTab", @"id":@"startupCell"}];
        _tabbar = @[
            @{@"title":@"TranslucentBar", @"type":@"bool", @"key":@"frostedPivot", @"id":@"tabbarCell"},
            @{@"title":@"RemoveLabels", @"type":@"bool", @"key":@"removeLabels", @"id":@"tabbarCell"},
            @{@"title":@"RemoveIndicators", @"type":@"bool", @"key":@"removeIndicators", @"id":@"tabbarCell"}
        ];
        _activeTabs = [@[] mutableCopy];
        _inactiveTabs = [@[] mutableCopy];
        _sections = @[_tabbar, _startup, _activeTabs, _inactiveTabs];
        [self.tableView setEditing:YES animated:NO];
        self.tableView.allowsSelectionDuringEditing = YES;
    }
    return self;
}

// 0x130ce0. The settings-embedded instance leaves title/button installation to
// its containing host; only standalone presentation installs its own close item.
- (void)loadView {
    [super loadView];
    [self initTabs];
    if (!_isSettings) {
        self.title = SettingsTabLocalized(@"Tabbar");
        self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
            initWithBarButtonSystemItem:(UIBarButtonSystemItem)24 target:self action:@selector(closeButtonTapped)];
    }
}
// 0x130f4c.
- (void)closeButtonTapped { [self dismissViewControllerAnimated:YES completion:nil]; }

// 0x130f88; missing loop body reconstructed at 0x131414..0x131600. Match against
// remaining tabs, so unknown IDs and repeated saved keys do not create rows.
- (void)initTabs {
    [_activeTabs removeAllObjects];
    [_inactiveTabs removeAllObjects];
    NSArray *saved = [YTLUserDefaults.standardUserDefaults objectForKey:@"activeTabs"];
    NSMutableArray *active = [NSMutableArray array];
    NSMutableArray *remaining = [_tabs mutableCopy];
    if (saved) {
        for (NSString *key in saved) {
            NSArray *matches = [remaining filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"key == %@", key]];
            if (matches.count) {
                NSDictionary *tab = matches.firstObject;
                [active addObject:tab];
                [remaining removeObject:tab];
            }
        }
    }
    [_activeTabs addObjectsFromArray:active];
    [_inactiveTabs addObjectsFromArray:remaining];
}
// 0x1316d0. The newly instantiated host is intentional; this does not find a
// visible singleton/controller or post a replacement notification.
- (void)saveTabsOrder {
    NSArray *keys = [_activeTabs valueForKey:@"key"];
    [YTLUserDefaults.standardUserDefaults setObject:keys forKey:@"activeTabs"];
    [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:[_sections indexOfObject:_startup]]
                 withRowAnimation:UITableViewRowAnimationAutomatic];
    SettingsTabRefreshPivot();
    if ([self.parentViewController isKindOfClass:NSClassFromString(@"YTHeaderContentComboViewController")]) {
        YTLSettingsHostHeader *header = [(YTLSettingsHostWrapper *)self.parentViewController headerViewController];
        if ([header respondsToSelector:@selector(hideRightNavigationButtons)]) {
            [header performSelector:@selector(hideRightNavigationButtons)];
        }
    }
}
// 0x131ee4. indexOfObject: uses equality, including for equal empty sections.
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    (void)tableView;
    if ((NSUInteger)section == [_sections indexOfObject:_startup]) return SettingsTabLocalized(@"Startup");
    if ((NSUInteger)section == [_sections indexOfObject:_tabbar]) return SettingsTabLocalized(@"Main");
    if ((NSUInteger)section == [_sections indexOfObject:_activeTabs]) return SettingsTabLocalized(@"ActiveTabs");
    if ((NSUInteger)section == [_sections indexOfObject:_inactiveTabs]) return SettingsTabLocalized(@"InactiveTabs");
    return nil;
}
// 0x13248c.
- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section {
    (void)tableView;
    return (NSUInteger)section == _sections.count - 1 ? SettingsTabLocalized(@"HideLibraryFooter") : nil;
}
// 0x1326e8.
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView { (void)tableView; return (NSInteger)_sections.count; }
// 0x132700.
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    (void)tableView;
    return (NSInteger)[(NSArray *)_sections[section] count];
}
// 0x13275c. Preserve the initial dequeue/allocation even though a non-nil
// section causes another allocation using its row dictionary's identifier.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) cell = [[YTPTableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:@"cell"];
    if (!_sections[indexPath.section]) return cell;
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    cell = [[YTPTableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:row[@"id"]];
    if ([row[@"type"] isEqualToString:@"bool"]) {
        cell.textLabel.text = SettingsTabLocalized(row[@"title"]);
        YTLSettingsHostSwitch *control = [self switchForKey:row[@"key"]];
        control.tag = (NSInteger)(((NSUInteger)indexPath.section << 16) | ((NSUInteger)indexPath.row & 0xffff));
        cell.accessoryView = control;
    }
    if ([row[@"type"] isEqualToString:@"int"]) {
        NSString *startup = [YTLUserDefaults.standardUserDefaults objectForKey:@"startupTab"];
        NSMutableArray *keys = [[YTLUserDefaults.standardUserDefaults objectForKey:@"activeTabs"] mutableCopy];
        if ([keys containsObject:@"FEuploads"]) [keys removeObject:@"FEuploads"];
        UISegmentedControl *control = [self segmentForItems:keys];
        control.selectedSegmentIndex = (NSInteger)[keys indexOfObject:startup];
        [control addTarget:self action:@selector(setSegment:) forControlEvents:UIControlEventValueChanged];
        [cell.contentView addSubview:control];
        [control.centerYAnchor constraintEqualToAnchor:cell.contentView.centerYAnchor].active = YES;
        [control.centerXAnchor constraintEqualToAnchor:cell.contentView.centerXAnchor].active = YES;
        [control.leadingAnchor constraintEqualToAnchor:cell.contentView.leadingAnchor constant:20].active = YES;
        [control.trailingAnchor constraintEqualToAnchor:cell.contentView.trailingAnchor constant:-20].active = YES;
    }
    if ([row[@"type"] isEqualToString:@"tab"]) {
        cell.textLabel.text = SettingsTabLocalized(row[@"key"]);
        cell.textLabel.adjustsFontSizeToFitWidth = YES;
        cell.imageView.image = [self iconImageNamed:row[@"key"]];
        cell.imageView.tintColor = UIColor.labelColor;
    }
    return cell;
}
// 0x13379c; renderer invoke 0x133890 captures the name, then loads the media
// image inside the renderer callback (not before renderer construction).
- (UIImage *)iconImageNamed:(NSString *)name {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(24, 24)];
    UIImage *image = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIImage *source = [(Class<YTLSettingsMedia>)NSClassFromString(@"YTPMedia") imageWithName:name];
        UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 24, 24)];
        UIImageView *imageView = [[UIImageView alloc] initWithImage:source];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.clipsToBounds = YES;
        imageView.frame = container.bounds;
        [container addSubview:imageView];
        [container.layer renderInContext:context.CGContext];
    }];
    return [image imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}
// 0x133a1c. Row selection refreshes in addition to the generated toggle event.
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    if ([row[@"type"] isEqualToString:@"bool"]) {
        YTLSettingsHostSwitch *control = (id)[tableView cellForRowAtIndexPath:indexPath].accessoryView;
        if ([control isKindOfClass:NSClassFromString(@"ABCSwitch")]) {
            [control prepareHapticFeedback];
            [control setOn:!control.isOn animated:YES userGenerated:YES];
            [control releaseHapticFeedback];
            [control fireHapticFeedback];
            SettingsTabRefreshPivot();
        }
    }
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}
// 0x134094. Unlike the base implementation, reads shared YTL defaults and view tint.
- (id)switchForKey:(NSString *)key {
    YTLSettingsHostSwitch *control = [NSClassFromString(@"ABCSwitch") new];
    control.onTintColor = self.view.tintColor;
    control.offTrackColor = [UIColor.grayColor colorWithAlphaComponent:0.5];
    control.on = [YTLUserDefaults.standardUserDefaults boolForKey:key];
    [control addTarget:self action:@selector(toggleSwitch:) forControlEvents:UIControlEventValueChanged];
    return control;
}
// 0x13432c. Refresh happens even when row lookup returns nil.
- (void)toggleSwitch:(id)sender {
    YTLSettingsHostSwitch *control = sender;
    NSDictionary *row = _sections[control.tag >> 16][control.tag & 0xffff];
    if (row) [YTLUserDefaults.standardUserDefaults setBool:control.isOn forKey:row[@"key"]];
    SettingsTabRefreshPivot();
}
// 0x134788; missing insert loop recovered at 0x134ca4..0x134ef0.
- (UISegmentedControl *)segmentForItems:(NSArray *)items {
    UISegmentedControl *control = [[UISegmentedControl alloc] initWithItems:@[]];
    control.translatesAutoresizingMaskIntoConstraints = NO;
    [control setTitleTextAttributes:@{NSForegroundColorAttributeName:self.view.tintColor} forState:UIControlStateSelected];
    [control setTitleTextAttributes:@{NSForegroundColorAttributeName:UIColor.secondaryLabelColor} forState:UIControlStateNormal];
    for (NSString *key in items) {
        NSArray *matches = [_tabs filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"key == %@", key]];
        if (matches.count) {
            UIImage *image = [self iconImageNamed:[matches.firstObject objectForKeyedSubscript:@"key"]];
            [control insertSegmentWithImage:image atIndex:(NSUInteger)control.numberOfSegments animated:NO];
        }
    }
    return control;
}
// 0x134f50. No fallback when selection is NSNotFound/out-of-range.
- (void)setSegment:(UISegmentedControl *)sender {
    NSMutableArray *keys = [[YTLUserDefaults.standardUserDefaults objectForKey:@"activeTabs"] mutableCopy];
    if ([keys containsObject:@"FEuploads"]) [keys removeObject:@"FEuploads"];
    NSString *key = keys[sender.selectedSegmentIndex];
    [YTLUserDefaults.standardUserDefaults setObject:key forKey:@"startupTab"];
}
// 0x135354.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    (void)tableView;
    return (NSUInteger)indexPath.section == [_sections indexOfObject:_activeTabs] ||
           (NSUInteger)indexPath.section == [_sections indexOfObject:_inactiveTabs];
}
// 0x135464.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    (void)tableView;
    return (NSUInteger)indexPath.section == [_sections indexOfObject:_activeTabs];
}
// 0x1354c0.
- (NSIndexPath *)tableView:(UITableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)source
      toProposedIndexPath:(NSIndexPath *)proposed {
    (void)tableView;
    return source.section == proposed.section ? proposed : source;
}
// 0x135540. The destination comparison is unsigned; append when outside count.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)source toIndexPath:(NSIndexPath *)destination {
    (void)tableView;
    NSDictionary *tab = _activeTabs[source.row];
    [_activeTabs removeObjectAtIndex:source.row];
    if ((NSUInteger)destination.row < _activeTabs.count) [_activeTabs insertObject:tab atIndex:destination.row];
    else [_activeTabs addObject:tab];
    [self saveTabsOrder];
}
// 0x1356e4. Preserve the binary's odd fallback: it tests inactive section INDEX
// for nonzero, NOT whether indexPath.section equals that index (0x13579c).
- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath {
    (void)tableView;
    if ((NSUInteger)indexPath.section == [_sections indexOfObject:_activeTabs]) return UITableViewCellEditingStyleDelete;
    return [_sections indexOfObject:_inactiveTabs] != 0 ? UITableViewCellEditingStyleInsert : UITableViewCellEditingStyleNone;
}
// 0x1357c4. Both limits compare for equality (one saved tab, six current tabs),
// not <=/>=. Startup replacement is the first remaining active tab, even upload.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle
 forRowAtIndexPath:(NSIndexPath *)indexPath {
    NSArray *saved = [YTLUserDefaults.standardUserDefaults objectForKey:@"activeTabs"];
    NSString *startup = [YTLUserDefaults.standardUserDefaults objectForKey:@"startupTab"];
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        if (saved.count == 1) {
            YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") infoDialog];
            alert.title = SettingsTabLocalized(@"Warning");
            alert.subtitle = SettingsTabLocalized(@"AtLeastOneTab");
            [alert show];
        } else {
            NSDictionary *tab = _activeTabs[indexPath.row];
            [_activeTabs removeObjectAtIndex:indexPath.row];
            [_inactiveTabs addObject:tab];
            if ([tab[@"key"] isEqualToString:startup]) {
                [YTLUserDefaults.standardUserDefaults setObject:[_activeTabs[0] objectForKeyedSubscript:@"key"] forKey:@"startupTab"];
            }
            NSIndexPath *destination = [NSIndexPath indexPathForRow:(NSInteger)_inactiveTabs.count - 1
                                                          inSection:(NSInteger)[_sections indexOfObject:_inactiveTabs]];
            [tableView moveRowAtIndexPath:indexPath toIndexPath:destination];
            [self saveTabsOrder];
        }
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        if (_activeTabs.count == 6) {
            YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") infoDialog];
            alert.title = SettingsTabLocalized(@"Warning");
            alert.subtitle = SettingsTabLocalized(@"TabsCountRestricted");
            [alert show];
        } else {
            NSDictionary *tab = _inactiveTabs[indexPath.row];
            [_inactiveTabs removeObjectAtIndex:indexPath.row];
            [_activeTabs addObject:tab];
            NSIndexPath *destination = [NSIndexPath indexPathForRow:(NSInteger)_activeTabs.count - 1
                                                          inSection:(NSInteger)[_sections indexOfObject:_activeTabs]];
            [tableView moveRowAtIndexPath:indexPath toIndexPath:destination];
            [self saveTabsOrder];
        }
    }
}
// ARC generates .cxx_destruct at the original selector (0x136528) for six arrays.
@end
