#import "WelcomeVC.h"
#import "WelcomeHost.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import "../../../Utils/YTLUserDefaults.h"
#import <QuartzCore/QuartzCore.h>

static NSString *WelcomeLocalized(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}
// Original helper 0x4477c reads the application delegate's window, not keyWindow.
static BOOL WelcomeHasTallSafeArea(void) {
    return UIApplication.sharedApplication.delegate.window.safeAreaInsets.top > 20.0;
}
static void WelcomeOpen(NSString *address) {
    [UIApplication.sharedApplication openURL:[NSURL URLWithString:address] options:@{} completionHandler:nil];
}

@implementation WelcomeVC
- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.translucent = YES;
    [self.navigationController.navigationBar setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
    self.navigationController.navigationBar.shadowImage = [UIImage new];
    _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleInsetGrouped];
    _tableView.translatesAutoresizingMaskIntoConstraints = NO;
    _tableView.dataSource = self;
    _tableView.delegate = self;
    _tableView.separatorColor = UIColor.clearColor;
    [self.view addSubview:_tableView];
    [self.view bringSubviewToFront:_tableView];
    _tableView.backgroundColor = [UIColor colorWithWhite:0 alpha:0.6];
    [NSLayoutConstraint activateConstraints:@[
        [_tableView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [_tableView.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor],
        [_tableView.widthAnchor constraintEqualToAnchor:self.view.widthAnchor],
        [_tableView.heightAnchor constraintEqualToAnchor:self.view.heightAnchor]]];
    UIVisualEffectView *background = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleLight]];
    background.frame = self.view.bounds;
    background.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:background];
    [self.view sendSubviewToBack:background];
    UIImageView *logo = [[UIImageView alloc] initWithImage:[self imageNamed:@"ytl_logo"]];
    UILabel *name = [UILabel new];
    name.text = @"YouTube Plus";
    name.textColor = UIColor.whiteColor;
    name.font = [UIFont boldSystemFontOfSize:24];
    UIStackView *header = [[UIStackView alloc] initWithArrangedSubviews:@[logo, name]];
    header.axis = UILayoutConstraintAxisVertical;
    header.alignment = UIStackViewAlignmentCenter;
    header.spacing = 20;
    header.translatesAutoresizingMaskIntoConstraints = NO;
    _tableView.tableHeaderView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 0, 230)];
    _tableView.contentInset = UIEdgeInsetsMake(0, 0, WelcomeHasTallSafeArea() ? 140 : 100, 0);
    [_tableView.tableHeaderView addSubview:header];
    [NSLayoutConstraint activateConstraints:@[
        [header.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [header.topAnchor constraintEqualToAnchor:_tableView.tableHeaderView.topAnchor constant:40],
        [logo.heightAnchor constraintEqualToConstant:128], [logo.widthAnchor constraintEqualToConstant:128]]];
    UIView *footer = [UIView new];
    footer.backgroundColor = UIColor.clearColor;
    footer.userInteractionEnabled = NO;
    footer.layer.cornerRadius = 6;
    footer.layer.cornerCurve = kCACornerCurveContinuous;
    footer.layer.maskedCorners = kCALayerMinXMinYCorner | kCALayerMaxXMinYCorner;
    footer.layer.masksToBounds = YES;
    footer.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:footer];
    UIVisualEffectView *footerBlur = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleDark]];
    footerBlur.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    footerBlur.frame = footer.bounds;
    footerBlur.alpha = 0.8;
    [footer addSubview:footerBlur];
    [NSLayoutConstraint activateConstraints:@[
        [footer.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor],
        [footer.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor],
        [footer.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
        [footer.heightAnchor constraintEqualToConstant:WelcomeHasTallSafeArea() ? 170 : 130]]];
    UIButton *thanks = [UIButton buttonWithType:UIButtonTypeCustom];
    [thanks setTitle:WelcomeLocalized(@"Continue") forState:UIControlStateNormal];
    [thanks setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
    [thanks setTitleColor:[UIColor.whiteColor colorWithAlphaComponent:0.5] forState:UIControlStateHighlighted];
    thanks.titleLabel.font = [UIFont boldSystemFontOfSize:15];
    thanks.backgroundColor = [UIColor.whiteColor colorWithAlphaComponent:0.15];
    thanks.layer.cornerRadius = 25;
    thanks.layer.cornerCurve = kCACornerCurveContinuous;
    thanks.translatesAutoresizingMaskIntoConstraints = NO;
    [thanks addTarget:self action:@selector(thanksButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:thanks];
    [NSLayoutConstraint activateConstraints:@[
        [thanks.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [thanks.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor constant:WelcomeHasTallSafeArea() ? -60 : -20],
        [thanks.heightAnchor constraintEqualToConstant:50], [thanks.widthAnchor constraintEqualToConstant:300]]];
    UIStackView *contacts = [UIStackView new];
    contacts.axis = UILayoutConstraintAxisHorizontal;
    contacts.distribution = UIStackViewDistributionFillEqually;
    contacts.alignment = UIStackViewAlignmentCenter;
    contacts.spacing = 10;
    contacts.translatesAutoresizingMaskIntoConstraints = NO;
    NSArray *titles = @[@"@Dayanch96", WelcomeLocalized(@"SupportMe")];
    NSArray *images = @[@"x", @"heart"];
    for (NSUInteger index = 0; index < titles.count; index++) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
        [button setTitle:titles[index] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor.whiteColor colorWithAlphaComponent:0.75] forState:UIControlStateNormal];
        [button setTitleColor:[UIColor.whiteColor colorWithAlphaComponent:0.5] forState:UIControlStateHighlighted];
        button.titleLabel.font = [UIFont monospacedDigitSystemFontOfSize:14 weight:UIFontWeightLight];
        button.backgroundColor = UIColor.clearColor;
        button.tintColor = UIColor.whiteColor;
        [button addTarget:self action:@selector(contactsButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
        [button setImage:[[self imageNamed:images[index]] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate] forState:UIControlStateNormal];
        button.imageView.contentMode = UIViewContentModeScaleAspectFit;
        button.semanticContentAttribute = UISemanticContentAttributeForceLeftToRight;
        button.imageEdgeInsets = UIEdgeInsetsMake(0, -5, 0, 5);
        button.tag = index;
        [contacts addArrangedSubview:button];
    }
    contacts.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:contacts];
    [NSLayoutConstraint activateConstraints:@[
        [contacts.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [contacts.bottomAnchor constraintEqualToAnchor:thanks.topAnchor constant:-15]]];
    _settingsData = @[
        @{@"title":WelcomeLocalized(@"Welcome.Download"), @"desc":WelcomeLocalized(@"Welcome.DownloadDesc"), @"image":@"arrow.down.app"},
        @{@"title":WelcomeLocalized(@"Welcome.Content"), @"desc":WelcomeLocalized(@"Welcome.ContentDesc"), @"image":@"paintbrush"},
        @{@"title":WelcomeLocalized(@"Welcome.Player"), @"desc":WelcomeLocalized(@"Welcome.PlayerDesc"), @"image":@"hand.draw"},
        @{@"title":WelcomeLocalized(@"Welcome.More"), @"desc":WelcomeLocalized(@"Welcome.MoreDesc"), @"image":@"ellipsis"}];
}
- (void)thanksButtonTapped {
    [[YTLUserDefaults standardUserDefaults] setBool:YES forKey:@"hasShownWelcome"];
    [self dismissViewControllerAnimated:YES completion:nil];
}
- (void)contactsButtonTapped:(UIButton *)sender {
    if (sender.tag == 0) {
        NSString *link = @"twitter://user?screen_name=Dayanch96";
        if (![UIApplication.sharedApplication canOpenURL:[NSURL URLWithString:link]]) link = @"https://twitter.com/Dayanch96";
        WelcomeOpen(link);
    } else if (sender.tag == 1) {
        id<YTLWelcomeSheet> sheet = [(Class<YTLWelcomeSheet>)NSClassFromString(@"YTDefaultSheetController")
            sheetControllerWithMessage:WelcomeLocalized(@"SupportDevelopment") subMessage:WelcomeLocalized(@"SupportDevelopmentDesc") delegate:nil parentResponder:nil];
        id<YTLWelcomeSheetHeader> header = [sheet valueForKey:@"_headerView"];
        [(UILabel *)[header valueForKey:@"_subtitleLabel"] setNumberOfLines:0];
        [header showHeaderDivider];
        Class<YTLWelcomeAction> actions = (Class<YTLWelcomeAction>)NSClassFromString(@"YTActionSheetAction");
        [sheet addAction:[actions actionWithTitle:@"Patreon" iconImage:[self imageNamed:@"patreon"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ WelcomeOpen(@"https://www.patreon.com/dayanch96"); }]];
        [sheet addAction:[actions actionWithTitle:@"Github Sponsors" iconImage:[self imageNamed:@"github"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ WelcomeOpen(@"https://github.com/sponsors/dayanch96"); }]];
        [sheet addAction:[actions actionWithTitle:@"Buy Me a Coffee" iconImage:[self imageNamed:@"coffee"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ WelcomeOpen(@"https://www.buymeacoffee.com/dayanch96"); }]];
        [sheet addAction:[actions actionWithTitle:@"USDT (TRC20)" iconImage:[self imageNamed:@"usdt"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{
            UIPasteboard.generalPasteboard.string = @"TEdKJdKwc1Bbu8Py4um8qPQ6MbproEqNJw";
            [self showAlertWithTitle:WelcomeLocalized(@"Copied") imageName:@"checkmark"];
        }]];
        [sheet addAction:[actions actionWithTitle:@"BNB Smart Chain (BEP20)" iconImage:[self imageNamed:@"bnb"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{
            UIPasteboard.generalPasteboard.string = @"0xc6f9fddb30ce10d70e6497950f44c8e10b72bcd6";
            [self showAlertWithTitle:WelcomeLocalized(@"Copied") imageName:@"checkmark"];
        }]];
        [sheet addAction:[actions actionWithTitle:@"Boosty" iconImage:[self imageNamed:@"boosty"] secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ WelcomeOpen(@"https://boosty.to/dayanch96"); }]];
        [sheet setSourceView:sender];
        [sheet presentFromViewController:self animated:YES completion:nil];
    }
}
- (UIImage *)imageNamed:(NSString *)name {
    return [UIImage imageNamed:name inBundle:[NSBundle ytl_defaultBundle] compatibleWithTraitCollection:nil];
}
- (CGFloat)tableView:(UITableView *)table heightForRowAtIndexPath:(NSIndexPath *)path { return UITableViewAutomaticDimension; }
- (NSInteger)numberOfSectionsInTableView:(UITableView *)table { return 1; }
- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section { return _settingsData.count; }
- (void)tableView:(UITableView *)table willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)path { table.separatorStyle = UITableViewCellSeparatorStyleNone; }
- (UITableViewCell *)tableView:(UITableView *)table cellForRowAtIndexPath:(NSIndexPath *)path {
    UITableViewCell *cell = [table dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cell"];
    if (path.section == 0) {
        NSDictionary *row = _settingsData[path.row];
        cell.textLabel.text = row[@"title"];
        cell.textLabel.font = [UIFont boldSystemFontOfSize:16];
        cell.textLabel.adjustsFontSizeToFitWidth = YES;
        cell.textLabel.textColor = UIColor.whiteColor;
        cell.detailTextLabel.text = row[@"desc"];
        cell.detailTextLabel.numberOfLines = 0;
        cell.detailTextLabel.font = [UIFont systemFontOfSize:14];
        cell.detailTextLabel.textColor = [UIColor.whiteColor colorWithAlphaComponent:0.8];
        cell.imageView.image = [self cellImageWithName:row[@"image"]];
        cell.backgroundColor = UIColor.clearColor;
        cell.userInteractionEnabled = NO;
    }
    return cell;
}
- (BOOL)tableView:(UITableView *)table shouldHighlightRowAtIndexPath:(NSIndexPath *)path { return NO; }
- (void)showAlertWithTitle:(NSString *)title imageName:(NSString *)name {
    UIImpactFeedbackGenerator *feedback = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleMedium];
    [feedback prepare];
    UIImageView *image = [[UIImageView alloc] initWithImage:[UIImage systemImageNamed:name]];
    image.tintColor = UIColor.whiteColor;
    image.contentMode = UIViewContentModeScaleAspectFit;
    UILabel *label = [UILabel new];
    label.text = title;
    label.textAlignment = NSTextAlignmentCenter;
    label.font = [UIFont boldSystemFontOfSize:16];
    label.textColor = UIColor.whiteColor;
    label.numberOfLines = 2;
    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[image, label]];
    stack.axis = UILayoutConstraintAxisVertical;
    stack.alignment = UIStackViewAlignmentCenter;
    stack.distribution = UIStackViewDistributionFillProportionally;
    stack.spacing = 5;
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    UIVisualEffectView *alert = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleProminent]];
    alert.layer.cornerRadius = 15;
    alert.layer.cornerCurve = kCACornerCurveContinuous;
    alert.clipsToBounds = YES;
    alert.translatesAutoresizingMaskIntoConstraints = NO;
    alert.userInteractionEnabled = NO;
    [alert.contentView addSubview:stack];
    [self.view addSubview:alert];
    NSLayoutConstraint *centerY = [alert.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor];
    [NSLayoutConstraint activateConstraints:@[
        [stack.centerXAnchor constraintEqualToAnchor:alert.centerXAnchor], [stack.centerYAnchor constraintEqualToAnchor:alert.centerYAnchor],
        [image.widthAnchor constraintEqualToConstant:50], [image.heightAnchor constraintEqualToConstant:50],
        [label.leadingAnchor constraintEqualToAnchor:alert.leadingAnchor constant:5], [label.trailingAnchor constraintEqualToAnchor:alert.trailingAnchor constant:-5],
        [alert.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor], centerY,
        [alert.widthAnchor constraintEqualToConstant:150], [alert.heightAnchor constraintEqualToConstant:150]]];
    alert.alpha = 0;
    alert.transform = CGAffineTransformMakeScale(1.2, 1.2);
    [feedback impactOccurred];
    [UIView animateWithDuration:0.5 delay:0 usingSpringWithDamping:1 initialSpringVelocity:15 options:0 animations:^{
        alert.alpha = 1;
        alert.transform = CGAffineTransformIdentity;
    } completion:^(BOOL finished) {
        [UIView animateWithDuration:0.5 delay:2 usingSpringWithDamping:1 initialSpringVelocity:15 options:0 animations:^{
            alert.alpha = 0;
            alert.transform = CGAffineTransformMakeScale(0.8, 0.8);
            centerY.constant = 50;
            [self.view layoutIfNeeded];
        } completion:^(BOOL finishedAgain) { [alert removeFromSuperview]; }];
    }];
}
- (UIImage *)cellImageWithName:(NSString *)name {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(40, 40)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIImage *image = [UIImage systemImageNamed:name];
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 40, 40)];
        UIImageView *imageView = [[UIImageView alloc] initWithImage:image];
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.clipsToBounds = YES;
        imageView.tintColor = UIColor.whiteColor;
        imageView.frame = view.bounds;
        [view addSubview:imageView];
        [view.layer renderInContext:context.CGContext];
    }];
}
@end
