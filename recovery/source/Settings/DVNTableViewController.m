#import "DVNTableViewController.h"
#import "DVNPickerView.h"
#import "YTPTableViewCell.h"
#import "SettingsContracts.h"
#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>
#import <math.h>

// Private extension preserves the original non-fragile subclass ivar layout.
@interface DVNTableViewController () {
    NSArray *_searchResults;
    UISearchBar *_searchBar;
    BOOL _isSearching;
    DVNTableModel *_model;
    NSUserDefaults *_defaults;
    DVNCell *_pendingScrollCell;
}
@end

// Explicit ARM64 FCVTZS semantics avoid undefined C casts for a non-finite
// model value. The recovered instructions return zero for NaN and saturate.
static NSInteger SettingsIntegerFromDouble(double value) {
    if (isnan(value)) return 0;
    if (value >= 0x1p63) return NSIntegerMax;
    if (value < -0x1p63) return NSIntegerMin;
    return (NSInteger)value;
}

static NSInteger SettingsTag(NSIndexPath *path) {
    return (NSInteger)(((NSUInteger)path.section << 16) | ((NSUInteger)path.row & 0xffff));
}
static NSIndexPath *SettingsIndexPath(NSInteger tag) {
    return [NSIndexPath indexPathForRow:tag & 0xffff inSection:tag >> 16];
}
static void SettingsRenderAspectFit(UIImage *image, CGFloat size, UIGraphicsImageRendererContext *context) {
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, size, size)];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
    imageView.contentMode = UIViewContentModeScaleAspectFit;
    imageView.clipsToBounds = YES;
    imageView.frame = view.bounds;
    [view addSubview:imageView];
    [view.layer renderInContext:context.CGContext];
}
static UIView *SettingsTableText(NSString *text, UIFont *font, UIColor *color,
                               NSTextAlignment alignment, CGFloat width) {
    UIView *container = [UIView new];
    UILabel *label = [UILabel new];
    label.text = text;
    label.font = font;
    label.textColor = color;
    label.textAlignment = alignment;
    label.numberOfLines = 0;
    label.translatesAutoresizingMaskIntoConstraints = NO;
    [container addSubview:label];
    [label.topAnchor constraintEqualToAnchor:container.topAnchor constant:8].active = YES;
    [label.bottomAnchor constraintEqualToAnchor:container.bottomAnchor constant:-8].active = YES;
    [label.leadingAnchor constraintEqualToAnchor:container.safeAreaLayoutGuide.leadingAnchor constant:25].active = YES;
    [label.trailingAnchor constraintEqualToAnchor:container.safeAreaLayoutGuide.trailingAnchor constant:-25].active = YES;
    container.frame = CGRectMake(0, 0, width, 0);
    CGSize fitting = [container systemLayoutSizeFittingSize:UILayoutFittingCompressedSize];
    container.frame = CGRectMake(0, 0, width, fitting.height);
    return container;
}

@implementation DVNTableViewController
@synthesize model = _model, defaults = _defaults, pendingScrollCell = _pendingScrollCell;

// 0x1163f8; the model retains no controller cycle (selfViewController is weak).
- (instancetype)initWithModel:(DVNTableModel *)model defaults:(NSUserDefaults *)defaults {
    self = [super initWithStyle:UITableViewStyleInsetGrouped];
    if (self) {
        self.model = model;
        self.defaults = defaults;
        if (model) model.selfViewController = self;
        [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(_reloadSections)
                                                  name:@"DVNAccStatusChanged" object:nil];
    }
    return self;
}

// 0x116764.
- (void)loadView {
    [super loadView];
    self.title = self.model.title;
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
    self.tableView.rowHeight = UITableViewAutomaticDimension;
    self.tableView.estimatedRowHeight = 52;
    self.tableView.contentInset = UIEdgeInsetsMake(0, 0, 20, 0);
    self.tableView.tintColor = [UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:1];
    self.tableView.backgroundColor = UIColor.systemGroupedBackgroundColor;
    if (self.model.showsThanksHeart) [self setupThanksHeart];
}

// 0x1169e4. Header/footer construction is inside supportsSearching in the image;
// the subsequent search bar replaces the optional table header, intentionally.
- (void)viewDidLoad {
    [super viewDidLoad];
    if ([self.parentViewController isKindOfClass:NSClassFromString(@"YTHeaderContentComboViewController")]) {
        YTLSettingsHostHeader *header = [(YTLSettingsHostWrapper *)self.parentViewController headerViewController];
        if ([header respondsToSelector:@selector(hideRightNavigationButtons)]) {
            [header performSelector:@selector(hideRightNavigationButtons)];
        }
    }
    if (self.model.supportsSearching) {
        if (self.model.header) {
            self.tableView.tableHeaderView = SettingsTableText(self.model.header, self.model.headerFont,
                UIColor.labelColor, self.model.headerAlignment, self.tableView.bounds.size.width);
        }
        if (self.model.footer) {
            self.tableView.tableFooterView = SettingsTableText(self.model.footer, self.model.footerFont,
                UIColor.secondaryLabelColor, self.model.footerAlignment, self.tableView.bounds.size.width);
        }
        _searchResults = @[];
        _searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, self.tableView.bounds.size.width, 45)];
        _searchBar.delegate = self;
        _searchBar.returnKeyType = UIReturnKeyDone;
        _searchBar.placeholder = [@"Search" ytl_localized];
        _searchBar.backgroundImage = [UIImage new];
        _searchBar.backgroundColor = [(Class<YTLSettingsMedia>)NSClassFromString(@"YTPMedia") adaptiveBackgroundColor];
        UITextField *field = _searchBar.searchTextField;
        field.enablesReturnKeyAutomatically = NO;
        field.tintColor = self.tableView.tintColor;
        field.layer.cornerRadius = 0;
        field.layer.masksToBounds = YES;
        // UISearchBar owns the search field's internal layout and margins.
        self.tableView.tableHeaderView = _searchBar;
    }
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    if (_searchBar) {
        CGFloat height = MAX(56, [UIFont preferredFontForTextStyle:UIFontTextStyleBody].lineHeight + 32);
        if (fabs(_searchBar.frame.size.height - height) > 0.5) {
            _searchBar.frame = CGRectMake(0, 0, self.tableView.bounds.size.width, height);
            self.tableView.tableHeaderView = _searchBar;
        }
    }
}

// 0x118008.
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self _removeSearchFieldCornerRadius:_searchBar];
}
// 0x118064.
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection {
    [super traitCollectionDidChange:previousTraitCollection];
    if ([self.traitCollection hasDifferentColorAppearanceComparedToTraitCollection:previousTraitCollection]) {
        [self _removeSearchFieldCornerRadius:_searchBar];
    }
}
// 0x118178.
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar { [searchBar resignFirstResponder]; }
// 0x1181b0, async invoke 0x11824c. Every immediate search-field subview is adjusted.
- (void)_removeSearchFieldCornerRadius:(UISearchBar *)searchBar {
    dispatch_async(dispatch_get_main_queue(), ^{
        for (UIView *view in searchBar.searchTextField.subviews) view.layer.cornerRadius = 0;
    });
}
// 0x118500; predicate 0x1186d8, provider invoke 0x118cc8 is NSArray *(^)(void).
- (void)_performSearch:(NSString *)query {
    _isSearching = query.length != 0;
    if (_isSearching) {
        NSString *lowercase = query.lowercaseString;
        _searchResults = [self.model cellsMatchingRecursive:^BOOL(DVNCell *cell) {
            if (cell.type == 4) return NO;
            if ([cell.title.lowercaseString containsString:lowercase] ||
                [cell.subtitle.lowercaseString containsString:lowercase] ||
                [cell.identifier.lowercaseString containsString:lowercase]) return YES;
            for (NSString *title in cell.titleIndexes) {
                if ([title.lowercaseString containsString:lowercase]) return YES;
            }
            if (cell.titleIndexesProvider) {
                for (NSString *title in ((YTLSettingsTitlesProvider)cell.titleIndexesProvider)()) {
                    if ([title.lowercaseString containsString:lowercase]) return YES;
                }
            }
            return NO;
        }];
    } else {
        _searchResults = @[];
    }
    [self.tableView reloadData];
}
// 0x118ef0.
- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText {
    [self _removeSearchFieldCornerRadius:searchBar];
    [self _performSearch:searchText];
}
// 0x118f70.
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar {
    searchBar.text = @"";
    [searchBar resignFirstResponder];
    [self _performSearch:@""];
}
// 0x119004.
- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar {
    searchBar.searchTextField.rightViewMode = UITextFieldViewModeAlways;
    YTLSettingsHostButton *button = [(id)NSClassFromString(@"YTQTMButton") iconButton];
    [button enableNewTouchFeedback];
    [button setImage:[UIImage systemImageNamed:@"xmark.circle.fill"] forState:UIControlStateNormal];
    button.tintColor = self.tableView.tintColor;
    [button addTarget:self action:@selector(_searchClearTapped:) forControlEvents:UIControlEventTouchUpInside];
    searchBar.searchTextField.rightView = button;
    [self _removeSearchFieldCornerRadius:searchBar];
}
// 0x11941c.
- (void)searchBarTextDidEndEditing:(UISearchBar *)searchBar {
    searchBar.searchTextField.rightView = nil;
    searchBar.searchTextField.rightViewMode = UITextFieldViewModeNever;
    [self _removeSearchFieldCornerRadius:searchBar];
}
// 0x1194e8.
- (void)_searchClearTapped:(id)sender {
    (void)sender;
    _searchBar.text = @"";
    [_searchBar resignFirstResponder];
    [self _performSearch:@""];
    [self _removeSearchFieldCornerRadius:_searchBar];
}

// 0x119580. First pass is indexOfObject: over live provider results; second pass
// tests child containment over stored cells. These are deliberately not merged.
- (void)navigateToCell:(DVNCell *)target {
    for (NSUInteger section = 0; section < _model.sections.count; ++section) {
        NSArray *cells = [self _cellsForSection:_model.sections[section]];
        NSUInteger row = [cells indexOfObject:target];
        if (row != NSNotFound) {
            _searchBar.text = @"";
            [self _performSearch:@""];
            NSIndexPath *path = [NSIndexPath indexPathForRow:(NSInteger)row inSection:(NSInteger)section];
            [self.tableView scrollToRowAtIndexPath:path atScrollPosition:UITableViewScrollPositionMiddle animated:YES];
            [self highlightRowAtIndexPath:path];
            return;
        }
    }
    for (NSUInteger section = 0; section < _model.sections.count; ++section) {
        for (DVNCell *cell in [self _cellsForSection:_model.sections[section]]) {
            if (cell.type == 4 && cell.controllerModel && [self cellExistsInModel:cell.controllerModel target:target]) {
                _searchBar.text = @"";
                [self _performSearch:@""];
                DVNTableViewController *controller = [[DVNTableViewController alloc] initWithModel:cell.controllerModel defaults:self.defaults];
                controller.pendingScrollCell = target;
                [self pushController:controller withTitle:cell.title];
                return;
            }
        }
    }
}
// 0x119e58. Identity comparison, stored cells, and no supportsSearching filter.
- (BOOL)cellExistsInModel:(DVNTableModel *)model target:(DVNCell *)target {
    for (DVNSection *section in model.sections) {
        for (DVNCell *cell in section.cells) {
            if (cell == target) return YES;
            if (cell.controllerModel && [self cellExistsInModel:cell.controllerModel target:target]) return YES;
        }
    }
    return NO;
}
// 0x11a490, invokes 0x11a538 and 0x11a6a8; both captures are strong.
- (void)highlightRowAtIndexPath:(NSIndexPath *)indexPath {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 350000000), dispatch_get_main_queue(), ^{
        UITableViewCell *cell = [self.tableView cellForRowAtIndexPath:indexPath];
        cell.backgroundColor = [self.tableView.tintColor colorWithAlphaComponent:0.2];
        [UIView animateWithDuration:1 animations:^{ cell.backgroundColor = UIColor.clearColor; }];
    });
}
// 0x11a718.
- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    if (self.pendingScrollCell) {
        [self navigateToCell:self.pendingScrollCell];
        self.pendingScrollCell = nil;
    }
}
// 0x11a830. Split replacement occurs only when the ancestor already has a
// second controller (raw cset eq at 0x11ad94; false -> 0x11adc8).
- (void)pushController:(UIViewController *)controller withTitle:(NSString *)title {
    UIViewController *parent = self.parentViewController;
    while (parent && ![parent isKindOfClass:NSClassFromString(@"YTWrapperSplitViewController")]) {
        parent = parent.parentViewController;
    }
    YTLSettingsHostWrapper *split = (id)parent;
    if (split.secondViewController) {
        YTLSettingsHostWrapper *wrapper = [(YTLSettingsHostWrapper *)[NSClassFromString(@"YTWrapperSplitViewController") alloc]
                                           initWithParentResponder:self.parentViewController];
        wrapper.title = title;
        wrapper.content = controller;
        split.secondViewController = wrapper;
    } else {
        YTLSettingsHostWrapper *wrapper = [(YTLSettingsHostWrapper *)[NSClassFromString(@"YTWrapperFlatViewController") alloc]
                                           initWithParentResponder:self.parentViewController];
        wrapper.title = title;
        wrapper.content = controller;
        [wrapper.headerViewController updateHeaderWithButtonsToDisplay:@[]];
        [self.navigationController pushViewController:wrapper animated:YES];
    }
}
// 0x11afa0.
- (void)addDismissButton:(BOOL)left {
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:(UIBarButtonSystemItem)24
                                                                       target:self action:@selector(closeButtonTapped)];
    if (left) self.navigationItem.leftBarButtonItem = item;
    else self.navigationItem.rightBarButtonItem = item;
}
// 0x11b05c.
- (void)closeButtonTapped { [self dismissViewControllerAnimated:YES completion:nil]; }
// 0x11b098.
- (void)addLeftBarItem:(NSString *)title image:(UIImage *)image handler:(void (^)(void))handler {
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:title style:UIBarButtonItemStylePlain
                                                         target:self action:@selector(_barButtonTriggered:)];
    if (image) item.image = image;
    objc_setAssociatedObject(item, (__bridge const void *)@"handler", [handler copy], OBJC_ASSOCIATION_COPY_NONATOMIC);
    self.navigationItem.leftBarButtonItem = item;
}
// 0x11b2fc.
- (void)addRightBarItem:(NSString *)title image:(UIImage *)image handler:(void (^)(void))handler {
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithTitle:title style:UIBarButtonItemStylePlain
                                                         target:self action:@selector(_barButtonTriggered:)];
    if (image) item.image = image;
    objc_setAssociatedObject(item, (__bridge const void *)@"handler", [handler copy], OBJC_ASSOCIATION_COPY_NONATOMIC);
    self.navigationItem.rightBarButtonItem = item;
}
// 0x11b560.
- (void)_barButtonTriggered:(UIBarButtonItem *)button {
    void (^handler)(void) = objc_getAssociatedObject(button, (__bridge const void *)@"handler");
    if (handler) handler();
}
// 0x11b6d0; Unicode constant 0x118bc70, doubles 0xc4c360/368.
- (void)setupThanksHeart {
    UILabel *label = [UILabel new];
    label.textAlignment = NSTextAlignmentCenter;
    label.text = @"💜";
    label.font = [UIFont systemFontOfSize:35];
    label.translatesAutoresizingMaskIntoConstraints = NO;
    [label sizeToFit];
    [self.tableView addSubview:label];
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
    animation.fromValue = @0.7;
    animation.toValue = @1;
    animation.autoreverses = YES;
    animation.repeatCount = INFINITY;
    animation.duration = 0.5;
    [label.layer addAnimation:animation forKey:@"scaleAnimation"];
    [label.centerXAnchor constraintEqualToAnchor:self.tableView.centerXAnchor].active = YES;
    [label.bottomAnchor constraintEqualToAnchor:self.tableView.topAnchor constant:-15].active = YES;
}

// 0x11bd8c.
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    (void)tableView;
    return [self _cellForIndexPath:indexPath].type == 7 ? 76 : UITableViewAutomaticDimension;
}
// 0x11bd9c.
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    (void)tableView;
    return _isSearching ? nil : [(DVNSection *)_model.sections[section] header];
}
// 0x11be90.
- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section {
    (void)tableView;
    return _isSearching ? nil : [(DVNSection *)_model.sections[section] footer];
}
// 0x11bf84.
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section {
    UILabel *label = [(UITableViewHeaderFooterView *)view textLabel];
    NSString *title = [self tableView:tableView titleForHeaderInSection:section];
    label.text = title;
    label.font = [UIFont preferredFontForTextStyle:UIFontTextStyleFootnote];
    label.textColor = UIColor.labelColor;
    label.textAlignment = NSTextAlignmentNatural;
    label.numberOfLines = 0;
    DVNSection *modelSection = _model.sections[section];
    if (modelSection.headerIcon) {
        NSTextAttachment *attachment = [NSTextAttachment new];
        attachment.image = [self headerImage:modelSection.headerIcon];
        attachment.bounds = CGRectMake(0, -3, 16, 16);
        NSMutableAttributedString *text = [[NSAttributedString attributedStringWithAttachment:attachment] mutableCopy];
        [text appendAttributedString:[[NSAttributedString alloc] initWithString:@" "]];
        [text appendAttributedString:[[NSAttributedString alloc] initWithString:title]];
        label.attributedText = text;
    }
}
// 0x11c4a4.
- (void)tableView:(UITableView *)tableView willDisplayFooterView:(UIView *)view forSection:(NSInteger)section {
    UILabel *label = [(UITableViewHeaderFooterView *)view textLabel];
    label.font = [UIFont preferredFontForTextStyle:UIFontTextStyleFootnote];
    label.textColor = UIColor.secondaryLabelColor;
    label.text = [self tableView:tableView titleForFooterInSection:section];
    label.textAlignment = NSTextAlignmentNatural;
    label.numberOfLines = 0;
}
// 0x11c698; measured height is rounded upward in double precision.
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return [self tableView:tableView titleForFooterInSection:section].length ? UITableViewAutomaticDimension : 0;
}
// 0x11c868.
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    (void)tableView;
    return _isSearching ? 1 : (NSInteger)_model.sections.count;
}
// 0x11c924.
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    (void)tableView;
    return (NSInteger)(_isSearching ? _searchResults.count : [self _cellsForSection:_model.sections[section]].count);
}
// 0x11ca5c.
- (DVNCell *)_cellForIndexPath:(NSIndexPath *)indexPath {
    if (_isSearching) return _searchResults[indexPath.row];
    return [self _cellsForSection:_model.sections[indexPath.section]][indexPath.row];
}

// 0x11cc18..0x11f260. Raw dispatch preserves all thirteen cell types. The
// original creates a fresh cell with the model's identifier; it never dequeues.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    (void)tableView;
    DVNCell *model = [self _cellForIndexPath:indexPath];
    UITableViewCellStyle style = UITableViewCellStyleSubtitle;
    YTPTableViewCell *cell = [[YTPTableViewCell alloc] initWithStyle:style reuseIdentifier:model.reuseIdentifier];
    model.sourceView = cell;
    if (model.title) {
        cell.textLabel.text = model.title;
        if (!model.subtitle) cell.textLabel.numberOfLines = 0;
        if (model.tintColor) cell.textLabel.textColor = model.tintColor;
    }
    if (model.subtitle && model.type != 3) cell.detailTextLabel.text = model.subtitle;
    if (model.subtitleProvider) {
        cell.detailTextLabel.text = ((YTLSettingsSubtitleProvider)model.subtitleProvider)();
    }
    if (model.icon) {
        NSInteger mode = model.renderingMode == 0 ? UIImageRenderingModeAlwaysTemplate : model.renderingMode;
        cell.imageView.image = [self iconImage:model.icon mode:mode size:0];
        if (model.tintColor) cell.imageView.tintColor = model.tintColor;
        else if (model.customData[@"iconTintColor"]) cell.imageView.tintColor = model.customData[@"iconTintColor"];
        else cell.imageView.tintColor = UIColor.labelColor;
    }
    if (model.image) cell.imageView.image = [self iconImage:model.image mode:UIImageRenderingModeAlwaysOriginal size:32];
    if (model.accessoryIcon) {
        cell.accessoryView = [[UIImageView alloc] initWithImage:[self accessoryImage:model.accessoryIcon]];
        cell.accessoryView.tintColor = [UIColor.grayColor colorWithAlphaComponent:0.75];
    }
    if (model.type == 4) cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    if (model.type == 0) {
        UISwitch *control = [self switchForKey:model.key];
        control.tag = SettingsTag(indexPath);
        if (model.tintColor) control.onTintColor = model.tintColor;
        cell.accessoryView = control;
    }
    if (model.type == 1) {
        NSArray *titles = model.titleIndexesProvider ? ((YTLSettingsTitlesProvider)model.titleIndexesProvider)() : model.titleIndexes;
        UISegmentedControl *control = nil;
        if (titles) control = [self segmentForItems:titles isCompact:NO];
        else if (model.imageIndexes) control = [self segmentForItems:model.imageIndexes isCompact:NO];
        control.selectedSegmentIndex = [self.defaults integerForKey:model.key];
        control.tag = SettingsTag(indexPath);
        [control addTarget:self action:@selector(setSegment:) forControlEvents:UIControlEventValueChanged];
        [cell.contentView addSubview:control];
        [control.topAnchor constraintEqualToAnchor:cell.contentView.layoutMarginsGuide.topAnchor].active = YES;
        [control.bottomAnchor constraintEqualToAnchor:cell.contentView.layoutMarginsGuide.bottomAnchor].active = YES;
        [control.leadingAnchor constraintEqualToAnchor:cell.contentView.leadingAnchor constant:10].active = YES;
        [control.trailingAnchor constraintEqualToAnchor:cell.contentView.trailingAnchor constant:-10].active = YES;
    }
    if (model.type == 2) {
        NSArray *titles = model.titleIndexesProvider ? ((YTLSettingsTitlesProvider)model.titleIndexesProvider)() : model.titleIndexes;
        UISegmentedControl *control = nil;
        if (titles) control = [self segmentForItems:titles isCompact:YES];
        else if (model.imageIndexes) control = [self segmentForItems:model.imageIndexes isCompact:YES];
        control.selectedSegmentIndex = [self.defaults integerForKey:model.key];
        control.tag = SettingsTag(indexPath);
        [control addTarget:self action:@selector(setSegment:) forControlEvents:UIControlEventValueChanged];
        cell.accessoryView = control;
    }
    if (model.type == 6) {
        UISlider *slider = [self sliderWithKey:model.key min:model.minimumValue max:model.maximumValue];
        slider.tag = SettingsTag(indexPath);
        cell.detailTextLabel.text = [self formatSliderValue:(double)slider.value format:model.sliderFormat];
        [cell.contentView addSubview:slider];
        UILabel *value = cell.detailTextLabel;
        value.textAlignment = NSTextAlignmentRight;
        value.font = [UIFont monospacedDigitSystemFontOfSize:14 weight:UIFontWeightRegular];
        value.translatesAutoresizingMaskIntoConstraints = NO;
        UILayoutGuide *margins = cell.contentView.layoutMarginsGuide;
        [NSLayoutConstraint activateConstraints:@[
            [slider.leadingAnchor constraintEqualToAnchor:margins.leadingAnchor],
            [slider.trailingAnchor constraintEqualToAnchor:value.leadingAnchor constant:-12],
            [slider.topAnchor constraintEqualToAnchor:margins.topAnchor constant:4],
            [slider.bottomAnchor constraintEqualToAnchor:margins.bottomAnchor constant:-4],
            [value.trailingAnchor constraintEqualToAnchor:margins.trailingAnchor],
            [value.centerYAnchor constraintEqualToAnchor:slider.centerYAnchor],
            [value.widthAnchor constraintGreaterThanOrEqualToConstant:64]
        ]];
    }
    if (model.type == 7) cell.accessoryView = [self timePickerForCell:model indexPath:indexPath];
    if (model.type == 9) {
        cell.textLabel.attributedText = [self stepperLabelForCell:model];
        cell.accessoryView = [self stepperForCell:model indexPath:indexPath];
    }
    if (model.type == 3) {
        cell.textLabel.numberOfLines = 0;
        UIButton *button = [self menuButtonWithTitle:model.title array:model.titleIndexes key:model.key];
        button.tag = SettingsTag(indexPath);
        cell.accessoryView = button;
    }
    if (model.type == 8) {
        YTLSettingsHostColorWell *well = [self colorWellForKey:model.key title:model.title];
        well.tag = SettingsTag(indexPath);
        cell.accessoryView = well;
    }
    if (model.type == 10) {
        UITextField *field = [self textFieldForCell:model];
        field.tag = SettingsTag(indexPath);
        [cell.contentView addSubview:field];
        [field.leadingAnchor constraintEqualToAnchor:cell.textLabel.trailingAnchor constant:15].active = YES;
        [field.trailingAnchor constraintEqualToAnchor:cell.contentView.trailingAnchor constant:-20].active = YES;
        [field.centerYAnchor constraintEqualToAnchor:cell.contentView.centerYAnchor].active = YES;
        [field.heightAnchor constraintGreaterThanOrEqualToConstant:44].active = YES;
    }
    if (model.type == 11) {
        cell.detailTextLabel.numberOfLines = 1;
        cell.detailTextLabel.lineBreakMode = NSLineBreakByTruncatingTail;
        if (model.shouldHideDetail) cell.detailTextLabel.text = model.detailText;
        else {
            NSString *text = [self.defaults stringForKey:model.key];
            if (text.length > 15) text = [[text substringToIndex:15] stringByAppendingString:@"..."];
            cell.detailTextLabel.text = text ?: model.detailText;
        }
    }
    return cell;
}

// 0x11f264; synchronous handlers take priority over handlerWithCompletion.
// Reload callbacks: 0x120008, 0x1200bc, 0x120240. Completion does not marshal
// all its work to main: only its optional row reload is dispatched there.
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    DVNCell *cell = [self _cellForIndexPath:indexPath];
    if (_isSearching) {
        [_searchBar resignFirstResponder];
        [tableView deselectRowAtIndexPath:indexPath animated:YES];
        [self navigateToCell:cell];
        return;
    }
    if (cell.type == 0) {
        UISwitch *control = (id)[tableView cellForRowAtIndexPath:indexPath].accessoryView;
        [control setOn:!control.isOn animated:YES];
        [self toggleSwitch:control];
    }

    if (cell.type == 3 && cell.subtitle) {
        YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") infoDialog];
        alert.title = cell.title;
        alert.subtitle = cell.subtitle;
        [alert show];
    }
    if (cell.type == 8) {
        YTLSettingsHostColorWell *well = (id)[tableView cellForRowAtIndexPath:indexPath].accessoryView;
        if ([well respondsToSelector:@selector(styleRequestedColorPickerPresentation)]) {
            [well styleRequestedColorPickerPresentation];
        } else {
            // Exact original selector dispatch (one-argument performSelector:
            // despite invokeColorPicker: having a colon). Do not fabricate an arg.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
            [well performSelector:NSSelectorFromString(@"invokeColorPicker:")];
#pragma clang diagnostic pop
        }
    }
    if (cell.type == 11) [self editorForIndexPath:indexPath];
    if (cell.type == 4) {
        UIViewController *controller = cell.controllerModel.viewController;
        if (!controller) controller = [[DVNTableViewController alloc] initWithModel:cell.controllerModel defaults:self.defaults];
        [self pushController:controller withTitle:cell.title];
    }
    if (cell.handler || cell.selfHandler) {
        if (cell.handler) ((YTLSettingsHandler)cell.handler)();
        else {
            cell.sourceView = [tableView cellForRowAtIndexPath:indexPath];
            ((YTLSettingsCellHandler)cell.selfHandler)(cell);
        }
        if (cell.reloadsTable) [tableView reloadData];
        if (cell.reloadsCell) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationNone];
            });
        }
    } else if (cell.handlerWithCompletion) {
        UIActivityIndicatorView *indicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
        indicator.color = UIColor.labelColor;
        UITableViewCell *view = [tableView cellForRowAtIndexPath:indexPath];
        view.detailTextLabel.text = nil;
        view.accessoryView = indicator;
        [indicator startAnimating];
        ((YTLSettingsCompletionHandler)cell.handlerWithCompletion)(^{
            [tableView cellForRowAtIndexPath:indexPath].accessoryView = nil;
            if (cell.reloadsTable) [tableView reloadData];
            if (cell.reloadsCell) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationNone];
                });
            }
        });
    }
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

// 0x1202f4.
- (NSString *)formatSliderValue:(double)value format:(NSInteger)format {
    if (format == 1) return [NSString stringWithFormat:@"%.2fx", value];
    if (format == 2) {
        NSDateComponentsFormatter *formatter = [NSDateComponentsFormatter new];
        formatter.unitsStyle = (NSDateComponentsFormatterUnitsStyle)2;
        return [formatter stringFromTimeInterval:value];
    }
    return [NSString stringWithFormat:@"%.1f", value];
}
// 0x1205ac.
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row
         forComponent:(NSInteger)component reusingView:(UIView *)view {
    (void)component;
    DVNCell *cell = [self _cellForTag:pickerView.tag];
    UILabel *label = (UILabel *)view;
    if (!label) {
        label = [UILabel new];
        label.textAlignment = NSTextAlignmentCenter;
        label.font = [UIFont systemFontOfSize:13 weight:UIFontWeightRegular];
        label.textColor = self.view.tintColor;
    }
    label.text = [self formatSliderValue:(double)row format:cell.sliderFormat];
    return label;
}
// 0x1207bc.
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView { (void)pickerView; return 1; }
// 0x1207c4.
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    (void)component;
    return SettingsIntegerFromDouble([self _cellForTag:pickerView.tag].maximumValue + 1);
}
// 0x120834; NSUserDefaults instance API takes float, not the class-wrapper double.
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    (void)component;
    DVNCell *cell = [self _cellForTag:pickerView.tag];
    NSUserDefaults *defaults = self.defaults;
    double minimum = cell.minimumValue;
    [defaults setFloat:(float)((double)row < minimum ? minimum : (double)row) forKey:cell.key];
    if ((double)row < cell.minimumValue) {
        [pickerView selectRow:SettingsIntegerFromDouble(cell.minimumValue) inComponent:0 animated:YES];
        [self pickerView:pickerView didSelectRow:SettingsIntegerFromDouble(cell.minimumValue) inComponent:0];
    }
}
// 0x120a04; renderer invoke 0x120afc.
- (UIImage *)headerImage:(UIImage *)image {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(16, 16)];
    UIImage *result = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) { SettingsRenderAspectFit(image, 16, context); }];
    return [result imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}
// 0x120c58; renderer invoke 0x120d6c.
- (UIImage *)iconImage:(UIImage *)image mode:(NSInteger)mode size:(double)size {
    double actualSize = size == 0 ? 24 : size;
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(actualSize, actualSize)];
    UIImage *result = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) { SettingsRenderAspectFit(image, actualSize, context); }];
    return [result imageWithRenderingMode:(UIImageRenderingMode)mode];
}
// 0x120ec8; renderer invoke 0x120fbc.
- (UIImage *)accessoryImage:(UIImage *)image {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(20, 20)];
    UIImage *result = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) { SettingsRenderAspectFit(image, 20, context); }];
    return [result imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}
// 0x121118.
- (DVNCell *)_cellForTag:(NSInteger)tag {
    if (_isSearching) return _searchResults[tag & 0xffff];
    return [self _cellsForSection:_model.sections[tag >> 16]][tag & 0xffff];
}
// 0x12126c. No caching, no fallback to cells when the provider returns nil.
- (NSArray *)_cellsForSection:(DVNSection *)section {
    return section.cellsProvider ? section.cellsProvider() : section.cells;
}
// 0x12137c.
- (id)switchForKey:(NSString *)key {
    UISwitch *control = [UISwitch new];
    control.onTintColor = self.tableView.tintColor;
    control.on = [self.defaults boolForKey:key];
    [control addTarget:self action:@selector(toggleSwitch:) forControlEvents:UIControlEventValueChanged];
    return control;
}
// 0x1215f4.
- (void)toggleSwitch:(id)sender {
    UISwitch *control = sender;
    DVNCell *cell = [self _cellForTag:control.tag];
    if (cell) [self.defaults setBool:control.isOn forKey:cell.key];
}
// 0x12174c.
- (void)setSegment:(UISegmentedControl *)sender {
    DVNCell *cell = [self _cellForTag:sender.tag];
    if (cell) [self.defaults setInteger:sender.selectedSegmentIndex forKey:cell.key];
}
// 0x121888. FRINTA rounds the double quotient to nearest, ties away from zero.
- (void)sliderValueChanged:(UISlider *)sender {
    DVNCell *cell = [self _cellForTag:sender.tag];
    if (cell) {
        if (cell.dividerValue > 0) {
            // 0x121960..0x1219c4 reads value, divisor, then multiplier in that
            // order. Separate reads also preserve behavior of model subclasses.
            double value = (double)sender.value;
            double divisor = cell.dividerValue;
            double steps = round(value / divisor);
            double multiplier = cell.dividerValue;
            sender.value = (float)(multiplier * steps);
        }
        [self.defaults setFloat:sender.value forKey:cell.key];
        UITableViewCell *view = [self.tableView cellForRowAtIndexPath:SettingsIndexPath(sender.tag)];
        view.detailTextLabel.text = [self formatSliderValue:(double)sender.value format:cell.sliderFormat];
    }
}
// 0x121bac.
- (void)stepperValueChanged:(UIStepper *)sender {
    DVNCell *cell = [self _cellForTag:sender.tag];
    if (cell) {
        [self.defaults setFloat:(float)sender.value forKey:cell.key];
        [self.tableView cellForRowAtIndexPath:SettingsIndexPath(sender.tag)].textLabel.attributedText = [self stepperLabelForCell:cell];
    }
}
// 0x121e08.
- (void)colorWellTap:(id)sender {
    YTLSettingsHostColorWell *well = sender;
    DVNCell *cell = [self _cellForTag:well.tag];
    if (cell) {
        NSData *data = [NSKeyedArchiver archivedDataWithRootObject:well.selectedColor requiringSecureCoding:NO error:NULL];
        [self.defaults setObject:data forKey:cell.key];
    }
}
// 0x121fa8.
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    [self.tableView reloadData];
    return YES;
}
// 0x122008. WhitespaceCharacterSet is intentionally not whitespaceAndNewline.
- (void)titleValue:(UITextField *)sender {
    DVNCell *cell = [self _cellForTag:sender.tag];
    if (cell) {
        BOOL blank = sender.text.length == 0 ||
            [sender.text rangeOfCharacterFromSet:NSCharacterSet.whitespaceCharacterSet.invertedSet].location == NSNotFound;
        if (blank) {
            [self.defaults removeObjectForKey:cell.key];
            sender.placeholder = cell.placeholder;
            sender.text = @"";
        } else {
            [self.defaults setValue:sender.text forKey:cell.key];
        }
    }
}
// 0x122380. Only grandchildren that are UILabels have this sizing option set.
- (UISegmentedControl *)segmentForItems:(NSArray *)items isCompact:(BOOL)compact {
    UISegmentedControl *control = [[UISegmentedControl alloc] initWithItems:items];
    control.translatesAutoresizingMaskIntoConstraints = compact;
    for (UIView *view in control.subviews) {
        for (UIView *subview in view.subviews) {
            if ([subview isKindOfClass:UILabel.class]) ((UILabel *)subview).adjustsFontSizeToFitWidth = YES;
        }
    }
    return control;
}
// 0x122900; global thumb renderer 0x122b2c is void (^)(UIGraphicsImageRendererContext *).
- (UISlider *)sliderWithKey:(NSString *)key min:(double)minimum max:(double)maximum {
    UISlider *slider = [UISlider new];
    slider.tintColor = self.tableView.tintColor;
    slider.minimumValue = (float)minimum;
    slider.maximumValue = (float)maximum;
    slider.value = [self.defaults floatForKey:key];
    slider.translatesAutoresizingMaskIntoConstraints = NO;
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(12, 15)];
    UIImage *image = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        CGContextRef cg = context.CGContext;
        CGContextSetShadowWithColor(cg, CGSizeMake(0, 0.5), 1, [UIColor.blackColor colorWithAlphaComponent:0.25].CGColor);
        [UIColor.whiteColor setFill];
        CGContextAddArc(cg, 6, 7.5, 6, 0, 6.283185307179586, 1);
        CGContextFillPath(cg);
    }];
    [slider setThumbImage:image forState:UIControlStateNormal];
    [slider addTarget:self action:@selector(sliderValueChanged:) forControlEvents:UIControlEventValueChanged];
    [slider.heightAnchor constraintEqualToConstant:30].active = YES;
    return slider;
}
// 0x122c48.
- (UIPickerView *)timePickerForCell:(DVNCell *)cell indexPath:(NSIndexPath *)indexPath {
    DVNPickerView *picker = [DVNPickerView new];
    picker.delegate = self;
    picker.dataSource = self;
    picker.frame = CGRectMake(0, 0, 80, 60);
    picker.tag = SettingsTag(indexPath);
    float value = [self.defaults floatForKey:cell.key];
    double minimum = cell.minimumValue;
    // 0x122db8..0x122dc4: FCMP then FCSEL LT includes unordered operands.
    // This is not the ordered C comparison value < minimum.
    if (!((double)value >= minimum)) value = (float)minimum;
    [picker selectRow:SettingsIntegerFromDouble((double)value) inComponent:0 animated:NO];
    return picker;
}
// 0x122e44.
- (UIStepper *)stepperForCell:(DVNCell *)cell indexPath:(NSIndexPath *)indexPath {
    UIStepper *stepper = [UIStepper new];
    stepper.minimumValue = cell.minimumValue;
    stepper.maximumValue = cell.maximumValue;
    stepper.stepValue = cell.dividerValue;
    stepper.value = (double)[self.defaults floatForKey:cell.key];
    stepper.tintColor = self.tableView.tintColor;
    stepper.tag = SettingsTag(indexPath);
    [stepper addTarget:self action:@selector(stepperValueChanged:) forControlEvents:UIControlEventValueChanged];
    return stepper;
}
// 0x123038; UTF-16 separator is space, bullet, space (0x118bf00).
- (NSAttributedString *)stepperLabelForCell:(DVNCell *)cell {
    NSMutableAttributedString *text = [[NSMutableAttributedString alloc] initWithString:cell.title];
    NSString *value = [NSString stringWithFormat:@" • %@", [self formatSliderValue:(double)[self.defaults floatForKey:cell.key] format:cell.sliderFormat]];
    [text appendAttributedString:[[NSAttributedString alloc] initWithString:value attributes:@{NSForegroundColorAttributeName:UIColor.secondaryLabelColor}]];
    return text;
}
// 0x123394.
- (id)colorWellForKey:(NSString *)key title:(NSString *)title {
    NSData *data = [self.defaults objectForKey:key];
    UIColor *color = [NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:data error:NULL];
    YTLSettingsHostColorWell *well = [(YTLSettingsHostColorWell *)[NSClassFromString(@"UIColorWell") alloc] initWithFrame:CGRectMake(0, 0, 30, 30)];
    well.title = title;
    well.supportsAlpha = YES;
    well.selectedColor = color;
    [well addTarget:self action:@selector(colorWellTap:) forControlEvents:UIControlEventValueChanged];
    return well;
}
// 0x123508.
- (UITextField *)textFieldForCell:(DVNCell *)cell {
    UITextField *field = [UITextField new];
    field.font = [UIFont systemFontOfSize:14];
    field.keyboardType = UIKeyboardTypeDefault;
    field.returnKeyType = UIReturnKeyDone;
    field.delegate = self;
    field.borderStyle = UITextBorderStyleNone;
    field.textAlignment = NSTextAlignmentRight;
    field.clearButtonMode = UITextFieldViewModeWhileEditing;
    field.translatesAutoresizingMaskIntoConstraints = NO;
    NSString *text = [self.defaults stringForKey:cell.key];
    if (!text) field.placeholder = cell.placeholder;
    else {
        field.text = text;
        field.textColor = self.view.tintColor;
    }
    [field addTarget:self action:@selector(titleValue:) forControlEvents:UIControlEventEditingChanged];
    return field;
}
// 0x1237ac. This editor indexes section.cells directly, not the provider.
// Copy/save/reload invokes: 0x12409c, 0x124254, 0x12455c.
- (void)editorForIndexPath:(NSIndexPath *)indexPath {
    DVNCell *cell = [(DVNSection *)_model.sections[indexPath.section] cells][indexPath.row];
    UITextView *textView = [UITextView new];
    textView.backgroundColor = [UIColor.labelColor colorWithAlphaComponent:0.15];
    textView.layer.cornerRadius = 3;
    textView.layer.borderWidth = 1;
    textView.layer.borderColor = [UIColor.grayColor colorWithAlphaComponent:0.5].CGColor;
    textView.textColor = UIColor.labelColor;
    textView.text = [self.defaults valueForKey:cell.key];
    textView.editable = YES;
    textView.scrollEnabled = YES;
    textView.textAlignment = NSTextAlignmentNatural;
    textView.font = [UIFont systemFontOfSize:14];
    YTLSettingsHostAlert *alert = [(id)NSClassFromString(@"YTAlertView") dialog];
    alert.title = cell.title;
    alert.backgroundColor = [UIColor.labelColor colorWithAlphaComponent:0.15];
    [alert addTitle:[@"Copy" ytl_localized] withAction:^{
        UIPasteboard.generalPasteboard.string = textView.text;
        [(Class<YTLSettingsToast>)NSClassFromString(@"ToastManager") showMessageWithText:[@"Copied" ytl_localized] isSuccess:YES];
    }];
    [alert addTitle:[@"Save" ytl_localized] withAction:^{
        NSString *value = cell.validationHandler ? ((YTLSettingsValidationHandler)cell.validationHandler)(textView.text) : textView.text;
        if (value) {
            [self.defaults setObject:value forKey:cell.key];
            [self.defaults synchronize];
            dispatch_async(dispatch_get_main_queue(), ^{ [self.tableView reloadData]; });
        } else if (cell.errorText) {
            [(Class<YTLSettingsToast>)NSClassFromString(@"ToastManager") showMessageWithText:cell.errorText isSuccess:NO];
        }
    }];
    [alert addTitle:[@"Cancel" ytl_localized] withAction:nil];
    UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0, 0, [alert frameForDialog].size.width - 50, 75)];
    textView.frame = container.frame;
    [container addSubview:textView];
    alert.customContentView = container;
    [alert show];
}
// 0x1245bc; each action captures indexOfObject: (first equal item), not its loop
// index. Negative/out-of-range persisted indices reset to zero and synchronize.
- (UIButton *)menuButtonWithTitle:(NSString *)title array:(NSArray *)items key:(NSString *)key {
    NSInteger selected = [self.defaults integerForKey:key];
    if (selected < 0 || selected >= (NSInteger)items.count) {
        [self.defaults setInteger:0 forKey:key];
        [self.defaults synchronize];
        selected = 0;
    }
    NSString *buttonTitle = [NSString stringWithFormat:@"%@ ", items[selected]];
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:buttonTitle forState:UIControlStateNormal];
    [button setImage:[self systemImage:@"chevron.up.chevron.down" withSize:14] forState:UIControlStateNormal];
    button.semanticContentAttribute = [self isRTL] ? UISemanticContentAttributeForceLeftToRight : UISemanticContentAttributeForceRightToLeft;
    button.titleLabel.font = [UIFont systemFontOfSize:13];
    [button setTitleColor:self.view.tintColor forState:UIControlStateNormal];
    [button sizeToFit];
    NSMutableArray *actions = [NSMutableArray array];
    for (NSString *item in items) {
        NSUInteger index = [items indexOfObject:item];
        UIAction *action = [UIAction actionWithTitle:item image:nil identifier:nil handler:^(UIAction *sender) {
            (void)sender;
            if (index != NSNotFound) {
                [self.defaults setInteger:(NSInteger)index forKey:key];
                if ([key isEqualToString:@"autoSpeedIndex"]) [self.defaults removeObjectForKey:@"rememberedPlaybackRate"];
                [self.defaults synchronize];
                [self.tableView reloadData];
            }
        }];
        action.state = index == (NSUInteger)selected ? UIMenuElementStateOn : UIMenuElementStateOff;
        [actions addObject:action];
    }
    [(id<YTLSettingsButtonMenu>)button setMenu:[UIMenu menuWithTitle:title children:actions]];
    [(id<YTLSettingsButtonMenu>)button setShowsMenuAsPrimaryAction:YES];
    return button;
}
// 0x1250e4; system-image renderer invoke 0x1251c4.
- (UIImage *)systemImage:(NSString *)name withSize:(double)size {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(size, size)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        SettingsRenderAspectFit([UIImage systemImageNamed:name], size, context);
    }];
}
// 0x12534c.
- (BOOL)isRTL {
    return [UIView userInterfaceLayoutDirectionForSemanticContentAttribute:self.view.semanticContentAttribute] == UIUserInterfaceLayoutDirectionRightToLeft;
}
// 0x1253b8.
- (void)_reloadSections { [self.tableView reloadData]; }
// 0x1253f8. ARC generates the matching .cxx_destruct (0x12552c).
- (void)dealloc { [NSNotificationCenter.defaultCenter removeObserver:self]; }
@end
