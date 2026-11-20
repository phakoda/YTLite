#import "DVNSection.h"
#import "DVNCell.h"

// Factories assign the section identifier to each initial cell. This differs
// from _appendCells:, which prefers a nonnil cell title (including an empty one).
static void DVNAssignInitialCells(DVNSection *section, NSArray<DVNCell *> *cells, NSString *identifier) {
    if (cells) {
        for (DVNCell *cell in cells) cell.identifier = identifier;
        section.cells = cells;
    }
}

@implementation DVNSection

- (instancetype)init {
    self = [super init];
    if (self) _cells = @[];
    return self;
}

// VA 0x18d9f0; the formerly unresolved branch at 0x18dc14 was checked against
// both raw destinations and the selector reference at 0x114d998.
- (void)_appendCells:(NSArray<DVNCell *> *)cells {
    if (cells.count == 0) return;
    NSMutableArray<DVNCell *> *combined = [_cells mutableCopy];
    for (DVNCell *cell in cells) {
        NSString *title = cell.title;
        cell.identifier = title ? title : self.identifier;
        [combined addObject:cell];
    }
    _cells = [combined copy];
}

- (void)addCell:(DVNCell *)cell { [self _appendCells:@[cell]]; }
- (void)addCells:(NSArray<DVNCell *> *)cells { [self _appendCells:cells]; }

+ (instancetype)sectionWithIdentifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    return section;
}

+ (instancetype)sectionWithCells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    DVNAssignInitialCells(section, cells, identifier);
    return section;
}

+ (instancetype)sectionWithHeader:(NSString *)header cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    section.header = header;
    DVNAssignInitialCells(section, cells, identifier);
    return section;
}

+ (instancetype)sectionWithHeader:(NSString *)header footer:(NSString *)footer cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    section.header = header;
    section.footer = footer;
    DVNAssignInitialCells(section, cells, identifier);
    return section;
}

+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    section.header = header;
    section.headerIcon = icon;
    DVNAssignInitialCells(section, cells, identifier);
    return section;
}

+ (instancetype)sectionWithHeader:(NSString *)header headerIcon:(UIImage *)icon footer:(NSString *)footer cells:(NSArray<DVNCell *> *)cells identifier:(NSString *)identifier {
    DVNSection *section = [DVNSection new];
    section.identifier = identifier;
    section.header = header;
    section.headerIcon = icon;
    section.footer = footer;
    DVNAssignInitialCells(section, cells, identifier);
    return section;
}

@end
