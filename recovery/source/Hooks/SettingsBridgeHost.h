#pragma once
#import <UIKit/UIKit.h>

@protocol YTLSettingsEntry <NSObject>
- (NSNumber *)categoryId;
@end
@protocol YTLSettingsSection <NSObject>
- (NSArray<id<YTLSettingsEntry>> *)items;
@end
@protocol YTLSettingsSplitContainer <NSObject>
- (UIViewController *)secondViewController;
- (void)setSecondViewController:(UIViewController *)controller;
@end
@protocol YTLSettingsHeader <NSObject>
- (void)updateHeaderWithButtonsToDisplay:(NSArray *)buttons;
@end
@interface YTCollectionViewController : UIViewController
- (NSArray<id<YTLSettingsSection>> *)sectionControllers;
- (void)collectionView:(UICollectionView *)collection didSelectItemAtIndexPath:(NSIndexPath *)path;
@end
@interface YTQTMButton : UIButton
- (void)setEnablePageStyling:(BOOL)value;
@end
@interface YTAppSettingsPresentationData : NSObject
+ (NSArray *)settingsCategoryOrder;
@end
@interface YTSettingsSectionController : NSObject
- (void)setSelectedItem:(NSUInteger)item;
@end
@interface YTIIcon : NSObject
@property(nonatomic) int iconType;
@end
@protocol YTLSettingsSectionDelegate <NSObject>
- (void)setSectionItems:(NSArray *)items forCategory:(NSUInteger)category title:(NSString *)title
                  icon:(YTIIcon *)icon titleDescription:(NSString *)description headerHidden:(BOOL)hidden;
- (void)setSectionItems:(NSArray *)items forCategory:(NSUInteger)category title:(NSString *)title
      titleDescription:(NSString *)description headerHidden:(BOOL)hidden;
@end
@interface YTSettingsSectionItemManager : NSObject
- (void)updateYTLiteSectionWithEntry:(id)entry;
- (void)updateSectionForCategory:(NSUInteger)category withEntry:(id)entry;
@end
@interface YTSettingsGroupData : NSObject
- (NSInteger)type;
- (NSArray *)orderedCategories;
@end
@interface YTWrapperFlatViewController : UIViewController
- (instancetype)initWithParentResponder:(id)parent;
- (void)setContent:(UIViewController *)content;
- (id<YTLSettingsHeader>)headerViewController;
@end
@interface YTWrapperSplitViewController : UIViewController
- (instancetype)initWithParentResponder:(id)parent;
- (void)setContent:(UIViewController *)content;
@end
#ifdef __cplusplus
extern "C" {
#endif
void YTLInstallSettingsBridgeHooks(void);
#ifdef __cplusplus
}
#endif
