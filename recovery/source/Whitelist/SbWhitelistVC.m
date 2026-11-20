#import "SbWhitelistVC.h"
#import "../Settings/YTPTableViewCell.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import <QuartzCore/QuartzCore.h>

@protocol YTLWhitelistHostColors
+ (UIColor *)black2;
@end

static NSString *WhitelistString(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}

@implementation SbWhitelistVC
- (instancetype)init {
    self = [super initWithStyle:UITableViewStyleGrouped];
    if (self) {
        _channels = [@[] mutableCopy];
        _sections = @[_channels];
        [self setupWhitelist];
    }
    return self;
}

- (void)setupWhitelist {
    [_channels removeAllObjects];
    NSArray *sorts = @[@{@"key":@"date", @"ascending":@NO},
                       @{@"key":@"date", @"ascending":@YES},
                       @{@"key":@"name", @"ascending":@YES},
                       @{@"key":@"name", @"ascending":@NO}];
    NSInteger sortType = [[YTLUserDefaults standardUserDefaults] integerForKey:@"sbWhitelistSortType"];
    // The image rejects negative values, then checks the unsigned array bound.
    NSUInteger index = sortType < 0 || (NSUInteger)sortType >= sorts.count ? 0 : (NSUInteger)sortType;
    NSDictionary *sort = sorts[index];
    NSMutableDictionary *whitelist = [[[YTLUserDefaults standardUserDefaults] objectForKey:@"sbWhitelist"] mutableCopy];
    NSString *key = sort[@"key"];
    BOOL ascending = [sort[@"ascending"] boolValue];
    NSSortDescriptor *descriptor = [key isEqualToString:@"name"]
        ? [NSSortDescriptor sortDescriptorWithKey:key ascending:ascending selector:@selector(localizedStandardCompare:)]
        : [NSSortDescriptor sortDescriptorWithKey:key ascending:ascending];
    for (NSDictionary *entry in [whitelist.allValues sortedArrayUsingDescriptors:@[descriptor]]) {
        UIImage *image = entry[@"pfp"] ? [UIImage imageWithData:entry[@"pfp"]] : [self ytlImageWithName:@"FElibrary"];
        // Dictionary literal nil rejection is preserved for malformed stored entries.
        [_channels addObject:@{@"title":entry[@"name"], @"image":image, @"type":@"channel", @"key":entry[@"link"], @"id":@"channelCell"}];
    }
    if (_channels.count == 0) {
        [_channels addObject:@{@"title":WhitelistString(@"Sb.ChannelsHere"), @"image":@"FEuploads", @"type":@"nochannel", @"key":@"", @"id":@"channelCell"}];
    }
    [self.tableView reloadData];
}

- (void)loadView {
    [super loadView];
    self.title = WhitelistString(@"Sb.Whitelist");
    UIEdgeInsets inset = self.tableView.contentInset;
    inset.top += 15;
    self.tableView.contentInset = inset;
    self.tableView.backgroundColor = [UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) {
        return traits.userInterfaceStyle == UIUserInterfaceStyleDark
            ? [(Class<YTLWhitelistHostColors>)NSClassFromString(@"YTColor") black2] : [UIColor whiteColor];
    }];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemClose target:self action:@selector(closeButtonTapped)];
}
- (void)closeButtonTapped { [self dismissViewControllerAnimated:YES completion:nil]; }

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return (NSInteger)[_sections indexOfObject:_channels] == section ? WhitelistString(@"Sb.Channels") : nil;
}
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section {
    UITableViewHeaderFooterView *header = (UITableViewHeaderFooterView *)view;
    header.textLabel.font = [UIFont systemFontOfSize:14 weight:UIFontWeightLight];
    header.textLabel.textColor = [UIColor labelColor];
    header.textLabel.text = [self tableView:tableView titleForHeaderInSection:section];
    header.textLabel.textAlignment = NSTextAlignmentNatural;
    header.textLabel.numberOfLines = 0;
    if ((NSInteger)[_sections indexOfObject:_channels] == section && ![header viewWithTag:1000]) {
        _sortButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_sortButton setImage:[self ytlImageWithName:@"sort"] forState:UIControlStateNormal];
        _sortButton.tag = 1000;
        _sortButton.translatesAutoresizingMaskIntoConstraints = NO;
        [header.contentView addSubview:_sortButton];
        [NSLayoutConstraint activateConstraints:@[
            [header.contentView.heightAnchor constraintEqualToConstant:30],
            [_sortButton.trailingAnchor constraintEqualToAnchor:header.contentView.trailingAnchor constant:-20],
            [_sortButton.centerYAnchor constraintEqualToAnchor:header.textLabel.centerYAnchor],
            [_sortButton.heightAnchor constraintEqualToConstant:20],
            [_sortButton.widthAnchor constraintEqualToConstant:20]]];
        _sortButton.menu = [UIMenu menuWithTitle:WhitelistString(@"SortType") image:nil identifier:@"sb_menu" options:UIMenuOptionsDisplayInline children:[self getSortActions]];
        _sortButton.showsMenuAsPrimaryAction = YES;
    }
}
- (NSArray<UIAction *> *)getSortActions {
    NSMutableArray *actions = [NSMutableArray array];
    NSArray *sorts = @[@{@"title":WhitelistString(@"Sb.Newest"), @"icon":@"clock", @"sortType":@0},
                       @{@"title":WhitelistString(@"Sb.Oldest"), @"icon":@"clock.arrow.circlepath", @"sortType":@1},
                       @{@"title":WhitelistString(@"Sb.Alphabetical"), @"icon":@"textformat", @"sortType":@2},
                       @{@"title":WhitelistString(@"Sb.AlphabeticalRev"), @"icon":@"textformat.size", @"sortType":@3}];
    for (NSDictionary *sort in sorts) {
        UIAction *action = [UIAction actionWithTitle:sort[@"title"] image:[UIImage systemImageNamed:sort[@"icon"]] identifier:nil handler:^(UIAction *sender) {
            [[YTLUserDefaults standardUserDefaults] setInteger:[sort[@"sortType"] integerValue] forKey:@"sbWhitelistSortType"];
            [self setupWhitelist];
            [self updateSortMenu];
        }];
        action.state = [[YTLUserDefaults standardUserDefaults] integerForKey:@"sbWhitelistSortType"] == [sort[@"sortType"] integerValue];
        [actions addObject:action];
    }
    return actions;
}
- (void)updateSortMenu {
    _sortButton.menu = [UIMenu menuWithTitle:WhitelistString(@"SortType") image:nil identifier:@"sb_menu" options:UIMenuOptionsDisplayInline children:[self getSortActions]];
}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView { return _sections.count; }
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section { return [_sections[section] count]; }
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) cell = [[YTPTableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:@"cell"];
    if (!_sections[indexPath.section]) return cell;
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    // The package allocates a row-specific cell even when dequeue succeeded.
    cell = [[YTPTableViewCell alloc] initWithStyle:UITableViewCellStyleValue2 reuseIdentifier:row[@"id"]];
    if (row[@"title"]) {
        cell.textLabel.text = row[@"title"];
        cell.textLabel.numberOfLines = 0;
        cell.textLabel.textColor = [UIColor labelColor];
    }
    id image = row[@"image"];
    if ([image isKindOfClass:NSString.class]) cell.imageView.image = [self ytlImageWithName:image];
    else if ([image isKindOfClass:UIImage.class]) cell.imageView.image = [self channelImage:image];
    return cell;
}
- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath { return YES; }
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    if ([row[@"type"] isEqualToString:@"channel"]) {
        NSString *link = row[@"key"];
        if (link) [[UIApplication sharedApplication] openURL:[NSURL URLWithString:link] options:@{} completionHandler:nil];
    }
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}
- (UISwipeActionsConfiguration *)tableView:(UITableView *)tableView trailingSwipeActionsConfigurationForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    if (![row[@"type"] isEqualToString:@"channel"]) return nil;
    UIContextualAction *action = [UIContextualAction contextualActionWithStyle:UIContextualActionStyleDestructive title:@"" handler:^(UIContextualAction *sender, UIView *sourceView, void (^completion)(BOOL)) {
        [self removeChannelWithLink:row[@"key"]];
        completion(YES);
    }];
    action.image = [UIImage systemImageNamed:@"trash"];
    UISwipeActionsConfiguration *configuration = [UISwipeActionsConfiguration configurationWithActions:@[action]];
    configuration.performsFirstActionWithFullSwipe = YES;
    return configuration;
}
- (void)removeChannelWithLink:(NSString *)link {
    NSMutableDictionary *whitelist = [[[YTLUserDefaults standardUserDefaults] objectForKey:@"sbWhitelist"] mutableCopy];
    if (whitelist) {
        for (NSString *key in whitelist) {
            if ([whitelist[key][@"link"] isEqualToString:link]) {
                [whitelist removeObjectForKey:key];
                break;
            }
        }
        [[YTLUserDefaults standardUserDefaults] setObject:whitelist forKey:@"sbWhitelist"];
        [[YTLUserDefaults standardUserDefaults] synchronize];
        [self setupWhitelist];
    }
}
- (UIImage *)ytlImageWithName:(NSString *)name {
    return [[UIImage imageNamed:name inBundle:[NSBundle ytl_defaultBundle] compatibleWithTraitCollection:nil] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}
- (UIImage *)channelImage:(UIImage *)image {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(24, 24)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 24, 24)];
        UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.clipsToBounds = YES;
        imageView.frame = view.bounds;
        imageView.layer.cornerRadius = 12;
        imageView.layer.borderWidth = 1;
        imageView.layer.borderColor = [[UIColor whiteColor] colorWithAlphaComponent:0.25].CGColor;
        [view addSubview:imageView];
        [view.layer renderInContext:context.CGContext];
    }];
}
@end
