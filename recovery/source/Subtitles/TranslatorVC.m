#import "TranslatorVC.h"
#import "YTPTranslator.h"
#import "../Support/YTPDB.h"
#import "../../../Utils/YTLUserDefaults.h"
#import <QuartzCore/QuartzCore.h>

// The packaged NSString category supplies this selector. This is a declaration,
// not a substitute localization implementation; category integration is audited
// separately from this screen's object compilation.
@interface NSString (YTLTranslatorLocalizationContract)
- (NSString *)ytl_localized;
@end

@implementation TranslatorVC

// 0x1e06b4. The action section is constructed, but is not in the initial table.
- (instancetype)initWithText:(NSString *)text {
    self = [super initWithStyle:UITableViewStyleInsetGrouped];
    if (self) {
        _sourceText = text;
        _langIndex = [YTPDB indexOfPreferredLanguage];
        _type = @[@{@"title": [@"Language" ytl_localized], @"indexes": [YTPDB supportedLanguages],
                    @"type": @"menu", @"key": @"languageKey", @"id": @"typeCell"}];
        _translation = @[@{@"type": @"textView", @"id": @"translationCell"}];
        _translate = @[@{@"title": [@"Translate" ytl_localized], @"type": @"action",
                         @"key": @"translateText", @"id": @"translateCell"}];
        _sections = @[_type, _translation];
    }
    return self;
}

// 0x1e13ac; the OLED dynamic provider is block 0x1e1910.
- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = [@"Translation" ytl_localized];
    self.tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    self.tableView.tintColor = [UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:1];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
        initWithBarButtonSystemItem:UIBarButtonSystemItemClose target:self action:@selector(closeButtonTapped)];
    if ([[YTLUserDefaults standardUserDefaults] boolForKey:@"oledTheme"]) {
        self.tableView.backgroundColor = [UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) {
            return traits.userInterfaceStyle == UIUserInterfaceStyleDark ? [UIColor blackColor] : [UIColor whiteColor];
        }];
    }
    _textView.text = [@"Translating" ytl_localized];
    [self translateText];
}

// 0x1e1964.
- (void)closeButtonTapped { [self dismissViewControllerAnimated:YES completion:nil]; }

// 0x1e19a0. Do not synthesize a titleForHeader method absent from the package.
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section {
    UITableViewHeaderFooterView *header = (UITableViewHeaderFooterView *)view;
    header.textLabel.font = [UIFont systemFontOfSize:13 weight:UIFontWeightSemibold];
    header.textLabel.textColor = [UIColor secondaryLabelColor];
    header.textLabel.text = [[self tableView:tableView titleForHeaderInSection:section] uppercaseString];
    header.textLabel.textAlignment = NSTextAlignmentNatural;
    header.textLabel.numberOfLines = 0;
}

// 0x1e1bd4, 0x1e1c44, 0x1e1c5c.
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return indexPath.section == (NSInteger)[_sections indexOfObject:_translation] ? 300 : UITableViewAutomaticDimension;
}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView { return _sections.count; }
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section { return [_sections[section] count]; }

// 0x1e1cb8. A row with a descriptor gets a new cell, even if dequeue succeeded.
// Keeping that behavior avoids accidentally retaining the previous text view.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell"];
    if (!cell) cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"cell"];
    if (!_sections[indexPath.section]) return cell;
    NSDictionary *row = _sections[indexPath.section][indexPath.row];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:row[@"id"]];
    if ([row[@"type"] isEqualToString:@"menu"]) {
        cell.textLabel.text = [row[@"title"] ytl_localized];
        cell.textLabel.numberOfLines = 0;
        cell.accessoryView = [self menuButtonWithTitle:[row[@"title"] ytl_localized] array:row[@"indexes"]];
        cell.backgroundColor = [UIColor systemBackgroundColor];
        cell.layer.borderColor = [[UIColor systemGrayColor] colorWithAlphaComponent:0.1].CGColor;
        cell.layer.borderWidth = 1;
    }
    if ([row[@"type"] isEqualToString:@"textView"]) {
        cell.backgroundColor = [UIColor clearColor];
        cell.layer.borderColor = [[UIColor systemGrayColor] colorWithAlphaComponent:0.1].CGColor;
        cell.layer.borderWidth = 1;
        _textView = [[UITextView alloc] init];
        _textView.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
        _textView.editable = NO;
        _textView.selectable = YES;
        _textView.dataDetectorTypes = UIDataDetectorTypeLink;
        _textView.linkTextAttributes = @{NSForegroundColorAttributeName: self.view.tintColor};
        _textView.translatesAutoresizingMaskIntoConstraints = NO;
        [cell.contentView addSubview:_textView];
        [NSLayoutConstraint activateConstraints:@[
            [_textView.leadingAnchor constraintEqualToAnchor:cell.contentView.leadingAnchor],
            [_textView.trailingAnchor constraintEqualToAnchor:cell.contentView.trailingAnchor],
            [_textView.topAnchor constraintEqualToAnchor:cell.contentView.topAnchor],
            [_textView.bottomAnchor constraintEqualToAnchor:cell.contentView.bottomAnchor],
        ]];
    }
    if ([row[@"key"] isEqualToString:@"translateText"]) {
        cell.textLabel.text = nil;
        cell.backgroundColor = [UIColor clearColor];
        _translateButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_translateButton setTitle:row[@"title"] forState:UIControlStateNormal];
        [_translateButton addTarget:self action:NSSelectorFromString(row[@"key"]) forControlEvents:UIControlEventTouchUpInside];
        _translateButton.backgroundColor = self.view.tintColor;
        _translateButton.translatesAutoresizingMaskIntoConstraints = NO;
        _translateButton.tintColor = [UIColor whiteColor];
        _translateButton.titleLabel.textAlignment = NSTextAlignmentCenter;
        _translateButton.titleLabel.font = [UIFont boldSystemFontOfSize:17];
        _translateButton.layer.cornerRadius = 10;
        _translateButton.layer.masksToBounds = YES;
        [cell.contentView addSubview:_translateButton];
        [NSLayoutConstraint activateConstraints:@[
            [_translateButton.leadingAnchor constraintEqualToAnchor:cell.contentView.leadingAnchor],
            [_translateButton.trailingAnchor constraintEqualToAnchor:cell.contentView.trailingAnchor],
            [_translateButton.topAnchor constraintEqualToAnchor:cell.contentView.topAnchor],
            [_translateButton.bottomAnchor constraintEqualToAnchor:cell.contentView.bottomAnchor],
            [_translateButton.heightAnchor constraintEqualToConstant:45],
            [_translateButton.widthAnchor constraintEqualToConstant:45],
        ]];
    }
    return cell;
}

// 0x1e3458; selection block 0x1e3c1c. indexOfObject intentionally gives the
// first index for duplicate labels. The current title comes from YTPDB again.
- (UIButton *)menuButtonWithTitle:(NSString *)title array:(NSArray *)array {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:[YTPDB supportedLanguages][_langIndex] forState:UIControlStateNormal];
    [button setImage:[self systemImage:@"chevron.up.chevron.down" withSize:14] forState:UIControlStateNormal];
    button.semanticContentAttribute = [self isRTL] ? UISemanticContentAttributeForceLeftToRight : UISemanticContentAttributeForceRightToLeft;
    button.titleLabel.font = [UIFont systemFontOfSize:13];
    [button setTitleColor:self.view.tintColor forState:UIControlStateNormal];
    [button sizeToFit];
    NSMutableArray<UIAction *> *actions = [NSMutableArray array];
    for (NSString *label in array) {
        NSUInteger index = [array indexOfObject:label];
        UIAction *action = [UIAction actionWithTitle:label image:nil identifier:nil handler:^(UIAction *selected) {
            if (index != NSNotFound) {
                self->_langIndex = index;
                [self.tableView reloadSections:[NSIndexSet indexSetWithIndex:0] withRowAnimation:UITableViewRowAnimationNone];
                [self translateText];
            }
        }];
        action.state = index == (NSUInteger)_langIndex ? UIMenuElementStateOn : UIMenuElementStateOff;
        [actions addObject:action];
    }
    button.menu = [UIMenu menuWithTitle:title children:actions];
    button.showsMenuAsPrimaryAction = YES;
    return button;
}

// 0x1e3d38; drawing block 0x1e3e18 renders a view/layer, not a direct image draw.
- (UIImage *)systemImage:(NSString *)name withSize:(double)size {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(size, size)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, size, size)];
        UIImageView *image = [[UIImageView alloc] initWithImage:[UIImage systemImageNamed:name]];
        image.contentMode = UIViewContentModeScaleAspectFit;
        image.frame = view.bounds;
        image.clipsToBounds = YES;
        [view addSubview:image];
        [view.layer renderInContext:context.CGContext];
    }];
}

// 0x1e3fa0.
- (BOOL)isRTL {
    return [UIView userInterfaceLayoutDirectionForSemanticContentAttribute:self.view.semanticContentAttribute] == UIUserInterfaceLayoutDirectionRightToLeft;
}

// 0x1e400c; callback 0x1e431c always enqueues the UI update at 0x1e43d8.
- (void)translateText {
    _textView.text = [@"Translating" ytl_localized];
    _textView.textColor = self.tableView.tintColor;
    [YTPTranslator translateText:_sourceText fromLanguage:@"auto" toLanguage:[YTPDB langCodeForIndex:_langIndex]
                     completion:^(NSString *translation, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self->_translateButton.enabled = YES;
            [self->_translateButton setTitle:[@"Translate" ytl_localized] forState:UIControlStateNormal];
            if (error) {
                self->_textView.text = error.localizedDescription;
                self->_textView.textColor = [UIColor systemRedColor];
                self->_textView.font = [UIFont italicSystemFontOfSize:14];
            } else {
                self->_textView.text = translation;
                self->_textView.textColor = [UIColor labelColor];
                self->_textView.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
            }
        });
    }];
}

// 0x1e46fc / 0x1e4704. ARC supplies .cxx_destruct (0x1e471c).
- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath { return NO; }
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}
@end
