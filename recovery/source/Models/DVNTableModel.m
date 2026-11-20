#import "DVNTableModel.h"
#import "DVNSection.h"
#import "DVNCell.h"
#import <UIKit/UIKit.h>

@implementation DVNTableModel

// 0x18b72c.
- (instancetype)init {
    self = [super init];
    if (self) {
        _sections = @[];
        _headerFont = [UIFont systemFontOfSize:14 weight:UIFontWeightSemibold];
        _footerFont = [UIFont systemFontOfSize:13 weight:UIFontWeightSemibold];
        _headerAlignment = 1;
        _footerAlignment = 1;
    }
    return self;
}

// 0x18bbb0 / 0x18bc0c: use immutable array replacement, not in-place mutation.
- (void)addSection:(DVNSection *)section { _sections = [_sections arrayByAddingObject:section]; }
- (void)addSections:(NSArray *)sections { _sections = [_sections arrayByAddingObjectsFromArray:sections]; }

// 0x18bc68. This is a case-sensitive, non-recursive title/subtitle search.
- (DVNCell *)cellForString:(NSString *)string {
    for (DVNSection *section in self.sections) {
        for (DVNCell *cell in section.cells) {
            if ([cell.title containsString:string] || [cell.subtitle containsString:string]) return cell;
        }
    }
    return nil;
}

// 0x18c24c; loop body independently inspected at 0x18c3a8..0x18c760.
- (NSArray *)cellsMatching:(DVNCellPredicate)predicate {
    NSMutableArray *matches = [NSMutableArray array];
    for (DVNSection *section in self.sections) {
        for (DVNCell *cell in section.cells) {
            if (predicate(cell)) [matches addObject:cell];
        }
    }
    return matches;
}

// 0x18c764.
- (NSArray *)cellsMatchingRecursive:(DVNCellPredicate)predicate {
    NSMutableArray *matches = [NSMutableArray array];
    NSHashTable *visited = [NSHashTable weakObjectsHashTable];
    [self _collectMatching:predicate into:matches visited:visited];
    return matches;
}

// 0x18c80c. The binary checks the CHILD's supportsSearching before descending.
// A model is visited once, so shared submodels and cycles cannot recurse forever.
- (void)_collectMatching:(DVNCellPredicate)predicate into:(NSMutableArray *)matches visited:(NSHashTable *)visited {
    if ([visited containsObject:self]) return;
    [visited addObject:self];
    for (DVNSection *section in self.sections) {
        for (DVNCell *cell in section.cells) {
            if (predicate(cell)) [matches addObject:cell];
            if (cell.controllerModel && cell.controllerModel.supportsSearching) {
                [cell.controllerModel _collectMatching:predicate into:matches visited:visited];
            }
        }
    }
}

// 0x18b85c.
+ (instancetype)model { return [[DVNTableModel alloc] init]; }

// 0x18b878.
+ (instancetype)modelWithTitle:(NSString *)title sections:(NSArray *)sections {
    DVNTableModel *model = [[DVNTableModel alloc] init];
    model.title = title;
    if (sections) model.sections = sections;
    return model;
}

// 0x18b950.
+ (instancetype)modelWithTitle:(NSString *)title header:(NSString *)header footer:(NSString *)footer sections:(NSArray *)sections {
    DVNTableModel *model = [[DVNTableModel alloc] init];
    model.title = title; model.header = header; model.footer = footer;
    if (sections) model.sections = sections;
    return model;
}

// 0x18ba80.
+ (instancetype)modelWithTitle:(NSString *)title header:(NSString *)header footer:(NSString *)footer viewController:(UIViewController *)viewController {
    DVNTableModel *model = [[DVNTableModel alloc] init];
    model.title = title; model.header = header; model.footer = footer;
    if (viewController) model.viewController = viewController;
    return model;
}

// 0x18cef8..0x18d138: synthesized accessors and ARC destruction.
@end
