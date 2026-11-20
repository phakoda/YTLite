#import <UIKit/UIKit.h>
#import "../Models/DVNCell.h"
#import "../Models/DVNSection.h"
#import "../Models/DVNTableModel.h"

@interface DVNTableViewController : UITableViewController
    <UISearchBarDelegate, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate>

@property(nonatomic, strong) DVNTableModel *model;
@property(nonatomic, strong) NSUserDefaults *defaults;
@property(nonatomic, strong) DVNCell *pendingScrollCell;

- (instancetype)initWithModel:(DVNTableModel *)model defaults:(NSUserDefaults *)defaults;
- (void)_removeSearchFieldCornerRadius:(UISearchBar *)searchBar;
- (void)_performSearch:(NSString *)query;
- (void)_searchClearTapped:(id)sender;
- (void)navigateToCell:(DVNCell *)target;
- (BOOL)cellExistsInModel:(DVNTableModel *)model target:(DVNCell *)target;
- (void)highlightRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)pushController:(UIViewController *)controller withTitle:(NSString *)title;
- (void)addDismissButton:(BOOL)left;
- (void)closeButtonTapped;
- (void)addLeftBarItem:(NSString *)title image:(UIImage *)image handler:(void (^)(void))handler;
- (void)addRightBarItem:(NSString *)title image:(UIImage *)image handler:(void (^)(void))handler;
- (void)_barButtonTriggered:(UIBarButtonItem *)button;
- (void)setupThanksHeart;
- (DVNCell *)_cellForIndexPath:(NSIndexPath *)indexPath;
- (NSString *)formatSliderValue:(double)value format:(NSInteger)format;
- (UIImage *)headerImage:(UIImage *)image;
- (UIImage *)iconImage:(UIImage *)image mode:(NSInteger)mode size:(double)size;
- (UIImage *)accessoryImage:(UIImage *)image;
- (DVNCell *)_cellForTag:(NSInteger)tag;
- (NSArray *)_cellsForSection:(DVNSection *)section;
- (id)switchForKey:(NSString *)key;
- (void)toggleSwitch:(id)sender;
- (void)setSegment:(UISegmentedControl *)sender;
- (void)sliderValueChanged:(UISlider *)sender;
- (void)stepperValueChanged:(UIStepper *)sender;
- (void)colorWellTap:(id)sender;
- (void)titleValue:(UITextField *)sender;
- (UISegmentedControl *)segmentForItems:(NSArray *)items isCompact:(BOOL)compact;
- (UISlider *)sliderWithKey:(NSString *)key min:(double)minimum max:(double)maximum;
- (UIPickerView *)timePickerForCell:(DVNCell *)cell indexPath:(NSIndexPath *)indexPath;
- (UIStepper *)stepperForCell:(DVNCell *)cell indexPath:(NSIndexPath *)indexPath;
- (NSAttributedString *)stepperLabelForCell:(DVNCell *)cell;
- (id)colorWellForKey:(NSString *)key title:(NSString *)title;
- (UITextField *)textFieldForCell:(DVNCell *)cell;
- (void)editorForIndexPath:(NSIndexPath *)indexPath;
- (UIButton *)menuButtonWithTitle:(NSString *)title array:(NSArray *)items key:(NSString *)key;
- (UIImage *)systemImage:(NSString *)name withSize:(double)size;
- (BOOL)isRTL;
- (void)_reloadSections;
@end
