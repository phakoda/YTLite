#import <Foundation/Foundation.h>

@class UIImage, DVNCell;
typedef NSArray *(^DVNCellsProvider)(void);

@interface DVNSection : NSObject
@property(nonatomic, strong) NSString *header;
@property(nonatomic, strong) NSString *footer;
@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, strong) UIImage *headerIcon;
@property(nonatomic, strong) NSArray *cells;
@property(nonatomic, copy) DVNCellsProvider cellsProvider;
- (void)_appendCells:(NSArray *)cells;
- (void)addCell:(DVNCell *)cell;
- (void)addCells:(NSArray *)cells;
+ (instancetype)sectionWithIdentifier:(NSString *)identifier;
+ (instancetype)sectionWithCells:(NSArray *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header cells:(NSArray *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header footer:(NSString *)footer cells:(NSArray *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon cells:(NSArray *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon footer:(NSString *)footer cells:(NSArray *)cells identifier:(NSString *)identifier;
@end
