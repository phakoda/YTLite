#import <Foundation/Foundation.h>
@class DVNCell, UIImage;

@interface DVNSection : NSObject
@property(nonatomic, strong) NSString *header;
@property(nonatomic, strong) NSString *footer;
@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, strong) UIImage *headerIcon;
@property(nonatomic, strong) NSArray<DVNCell *> *cells;
@property(nonatomic, copy) NSArray<DVNCell *> * (^cellsProvider)(void);
- (void)_appendCells:(NSArray<DVNCell *> *)cells;
- (void)addCell:(DVNCell *)cell;
- (void)addCells:(NSArray<DVNCell *> *)cells;
+ (instancetype)sectionWithIdentifier:(NSString *)identifier;
+ (instancetype)sectionWithCells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header footer:(NSString *)footer cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier;
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon footer:(NSString *)footer cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier;
@end
