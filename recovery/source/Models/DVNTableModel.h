#import <Foundation/Foundation.h>

@class UIFont, UIViewController, DVNCell, DVNSection;
typedef BOOL (^DVNCellPredicate)(DVNCell *cell);

@interface DVNTableModel : NSObject
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *header;
@property(nonatomic, strong) NSString *footer;
@property(nonatomic, strong) UIFont *headerFont;
@property(nonatomic, strong) UIFont *footerFont;
@property(nonatomic) NSInteger headerAlignment;
@property(nonatomic) NSInteger footerAlignment;
@property(nonatomic) BOOL showsThanksHeart;
@property(nonatomic) BOOL supportsSearching;
@property(nonatomic, strong) NSArray *sections;
@property(nonatomic, strong) UIViewController *viewController;
@property(nonatomic, weak) UIViewController *selfViewController;
- (void)addSection:(DVNSection *)section;
- (void)addSections:(NSArray *)sections;
- (DVNCell *)cellForString:(NSString *)string;
- (NSArray *)cellsMatching:(DVNCellPredicate)predicate;
- (NSArray *)cellsMatchingRecursive:(DVNCellPredicate)predicate;
- (void)_collectMatching:(DVNCellPredicate)predicate into:(NSMutableArray *)matches visited:(NSHashTable *)visited;
+ (instancetype)model;
+ (instancetype)modelWithTitle:(NSString *)title sections:(NSArray *)sections;
+ (instancetype)modelWithTitle:(NSString *)title header:(NSString *)header footer:(NSString *)footer sections:(NSArray *)sections;
+ (instancetype)modelWithTitle:(NSString *)title header:(NSString *)header footer:(NSString *)footer viewController:(UIViewController *)viewController;
@end
