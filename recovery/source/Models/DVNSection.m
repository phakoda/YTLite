#import "DVNSection.h"
#import "DVNCell.h"

@implementation DVNSection

// 0x18d94c.
- (instancetype)init {
    self = [super init];
    if (self) _cells = @[];
    return self;
}

// 0x18d9f0. The missing branch at 0x18dc14 was reviewed in the original
// instructions: a non-nil cell title becomes its identifier; otherwise use
// the section identifier. Even an empty (but non-nil) title takes that branch.
- (void)_appendCells:(NSArray *)cells {
    if (cells.count == 0) return;
    NSMutableArray *updated = [_cells mutableCopy];
    for (DVNCell *cell in cells) {
        NSString *title = cell.title;
        cell.identifier = title ? title : self.identifier;
        [updated addObject:cell];
    }
    _cells = [updated copy];
}

// 0x18ef44 / 0x18f018. Array-literal nil behavior is intentional.
- (void)addCell:(DVNCell *)cell { [self _appendCells:@[cell]]; }
- (void)addCells:(NSArray *)cells { [self _appendCells:cells]; }

// 0x18dde4.
+ (instancetype)sectionWithIdentifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.identifier = identifier;
    return section;
}

// 0x18de38. Unlike _appendCells:, factories assign the section identifier.
+ (instancetype)sectionWithCells:(NSArray *)cells identifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.identifier = identifier;
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
    return section;
}

// 0x18e15c.
+ (instancetype)sectionWithHeader:(NSString *)header cells:(NSArray *)cells identifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.header = header; section.identifier = identifier;
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
    return section;
}

// 0x18e4a8.
+ (instancetype)sectionWithHeader:(NSString *)header footer:(NSString *)footer cells:(NSArray *)cells identifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.header = header; section.footer = footer; section.identifier = identifier;
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
    return section;
}

// 0x18e824.
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon cells:(NSArray *)cells identifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.header = header; section.headerIcon = icon; section.identifier = identifier;
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
    return section;
}

// 0x18eba0.
+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon footer:(NSString *)footer cells:(NSArray *)cells identifier:(NSString *)identifier {
    DVNSection *section = [[DVNSection alloc] init];
    section.header = header; section.headerIcon = icon; section.footer = footer; section.identifier = identifier;
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
    return section;
}

// 0x18f04c..0x18f138: synthesized accessors and ARC destruction.
@end
