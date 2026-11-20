#import "SettingsBridgeHost.h"
#import "../Settings/YTPSettingsBuilder.h"
#import "../Settings/DVNTableViewController.h"
#import "../../../Utils/YTLUserDefaults.h"

static const NSUInteger YTLSettingsCategory = 789;

%group YTLSettingsBridge
%hook YTCollectionViewController
- (void)collectionView:(UICollectionView *)collection didSelectItemAtIndexPath:(NSIndexPath *)path {
    if (![self respondsToSelector:@selector(sectionControllers)]) { %orig; return; }
    id<YTLSettingsSection> section = self.sectionControllers[path.section];
    if (![section respondsToSelector:@selector(items)]) { %orig; return; }
    id<YTLSettingsEntry> entry = section.items[path.row];
    if (![entry.categoryId isEqualToNumber:@(YTLSettingsCategory)]) { %orig; return; }

    YTPSettingsBuilder *builder = [YTPSettingsBuilder new];
    builder.presenter = self;
    DVNTableViewController *table = [[DVNTableViewController alloc] initWithModel:[builder rootTable]
                                                                     defaults:[YTLUserDefaults standardUserDefaults]];
    id<YTLSettingsSplitContainer> container = (id)self.parentViewController.parentViewController;
    if ([container secondViewController]) {
        YTWrapperSplitViewController *wrapper = [[%c(YTWrapperSplitViewController) alloc] initWithParentResponder:self.parentViewController];
        wrapper.title = @"YouTube Plus";
        [wrapper setContent:table];
        [container setSecondViewController:wrapper];
    } else {
        YTWrapperFlatViewController *wrapper = [[%c(YTWrapperFlatViewController) alloc] initWithParentResponder:self.parentViewController];
        wrapper.title = @"YouTube Plus";
        [wrapper setContent:table];
        [[wrapper headerViewController] updateHeaderWithButtonsToDisplay:@[]];
        [self.navigationController pushViewController:wrapper animated:YES];
    }
}
%end
%hook YTQTMButton
- (void)layoutSubviews {
    %orig;
    if ([self.accessibilityIdentifier isEqualToString:@"id.ui.browse.back.button"]) {
        self.tintColor = UIColor.labelColor;
        [self setEnablePageStyling:YES];
    }
}
%end
%hook YTAppSettingsPresentationData
+ (NSArray *)settingsCategoryOrder {
    NSArray *original = %orig;
    NSMutableArray *order = [original mutableCopy];
    NSUInteger index = [original indexOfObject:@1];
    if (index != NSNotFound) [order insertObject:@(YTLSettingsCategory) atIndex:index + 1];
    return order;
}
%end
%hook YTSettingsSectionController
- (void)setSelectedItem:(NSUInteger)item {
    NSLog(@"DVN --- setSelectedItem: %ld", (long)item);
    if (item != NSNotFound) %orig;
}
%end
%hook YTSettingsSectionItemManager
%new(v@:@)
- (void)updateYTLiteSectionWithEntry:(id)entry {
    id<YTLSettingsSectionDelegate> controller = [self valueForKey:@"_settingsViewControllerDelegate"];
    YTIIcon *icon = [%c(YTIIcon) new];
    icon.iconType = 530;
    if ([controller respondsToSelector:@selector(setSectionItems:forCategory:title:icon:titleDescription:headerHidden:)]) {
        [controller setSectionItems:nil forCategory:YTLSettingsCategory title:@"YouTube Plus" icon:icon titleDescription:nil headerHidden:NO];
    } else {
        [controller setSectionItems:nil forCategory:YTLSettingsCategory title:@"YouTube Plus" titleDescription:nil headerHidden:NO];
    }
}
- (void)updateSectionForCategory:(NSUInteger)category withEntry:(id)entry {
    if (category == YTLSettingsCategory) [self updateYTLiteSectionWithEntry:entry];
    else %orig;
}
%end
%hook YTSettingsGroupData
- (NSArray *)orderedCategories {
    NSInteger type = [self type];
    NSArray *original = %orig;
    if (type != 1) return original;
    NSMutableArray *order = [original mutableCopy];
    [order insertObject:@(YTLSettingsCategory) atIndex:0];
    return [order copy];
}
%end
%end

void YTLInstallSettingsBridgeHooks(void) { %init(YTLSettingsBridge); }
