#import <UIKit/UIKit.h>
#import "../Models/DVNCell.h"
#import "../Models/DVNSection.h"
#import "../Models/DVNTableModel.h"

@interface YTPSettingsBuilder : NSObject {
    __weak UIViewController *_presenter;
}
@property(nonatomic, weak) UIViewController *presenter;
- (DVNTableModel *)rootTable;
- (DVNTableModel *)downloadingTable;
- (DVNTableModel *)navbarTable;
- (DVNTableModel *)feedTable;
- (DVNTableModel *)playerTable;
- (DVNTableModel *)shortsTable;
- (DVNTableModel *)interfaceTable;
- (DVNTableModel *)tabBarTable;
- (DVNTableModel *)sbTable;
- (DVNTableModel *)rpcTable;
- (DVNTableModel *)contribsTable;
- (DVNTableModel *)libsTable;
- (DVNTableModel *)thanksTable;
- (DVNTableModel *)prefsTable;
- (DVNSection *)devSection;
- (DVNSection *)creditsSection;
- (DVNSection *)patreonSection:(DVNTableModel *)model;
- (DVNCell *)patreonButtonCellWithType:(NSString *)type model:(DVNTableModel *)model;
- (void)importPreferences;
- (void)resetSettings;
- (void)showDonationSheet:(UIView *)sourceView;
- (void)openURL:(NSString *)string;
- (UIImage *)thanksImage:(NSString *)name;
- (NSArray *)sbSegments;
- (void)clearCacheWithCompletion:(void (^)(void))completion;
- (NSString *)getCacheSize;
@end
