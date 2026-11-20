#import <Foundation/Foundation.h>
#import "DVNCell.h"
#import "DVNSection.h"

static NSUInteger assertions;
#define REQUIRE(condition) do { \
    assertions++; \
    if (!(condition)) { \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
        abort(); \
    } \
} while (0)

@interface FixtureCellSubclass : DVNCell @end
@implementation FixtureCellSubclass @end
@interface FixtureSectionSubclass : DVNSection @end
@implementation FixtureSectionSubclass @end

@interface FixtureSliderOverride : DVNCell @end
@implementation FixtureSliderOverride
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key {
    FixtureSliderOverride *cell = [FixtureSliderOverride new];
    cell.minimumValue = minimum;
    cell.maximumValue = maximum;
    cell.dividerValue = divider;
    cell.sliderFormat = format;
    cell.key = key;
    return cell;
}
@end

static void checkFields(DVNCell *cell, NSDictionary *expected) {
    REQUIRE(cell.class == DVNCell.class);
    REQUIRE(cell.reuseIdentifier.length == 36);
    for (NSString *key in expected) REQUIRE([[cell valueForKey:key] isEqual:expected[key]]);
}

static void testFactories(void) {
    NSObject *icon = [NSObject new], *image = [NSObject new], *accessory = [NSObject new], *model = [NSObject new];
    NSArray *indexes = @[@"one", @"two"];
    checkFields([FixtureCellSubclass controllerCellWithModel:(id)model title:@"T" subtitle:@"S" icon:(id)icon],
                @{@"controllerModel": model, @"title": @"T", @"subtitle": @"S", @"icon": icon, @"type": @4});
    checkFields([DVNCell cellWithTitleIndexes:indexes key:@"K"], @{@"titleIndexes": indexes, @"key": @"K", @"type": @1});
    checkFields([DVNCell cellWithImageIndexes:indexes key:@"K"], @{@"imageIndexes": indexes, @"key": @"K", @"type": @1});
    __block NSUInteger called = 0;
    DVNCellHandler handler = ^{ called++; };
    DVNCell *cell = [DVNCell cellWithTitle:@"T" subtitle:@"S" handler:handler];
    checkFields(cell, @{@"title": @"T", @"subtitle": @"S", @"type": @5});
    cell.handler(); REQUIRE(called == 1 && cell.selfHandler == nil);
    __block DVNCell *received = nil;
    DVNCellSelfHandler selfHandler = ^(DVNCell *argument) { received = argument; };
    cell = [DVNCell cellWithTitle:@"T" subtitle:@"S" selfHandler:selfHandler];
    checkFields(cell, @{@"title": @"T", @"subtitle": @"S", @"type": @5});
    cell.selfHandler(cell); REQUIRE(received == cell && cell.handler == nil); received = nil;
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" type:DVNCellTypeTextEditor key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"type": @11, @"key": @"K"});
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" icon:(id)icon type:DVNCellTypeColor key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"icon": icon, @"type": @8, @"key": @"K"});
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" imageIndexes:indexes key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"imageIndexes": indexes, @"type": @2, @"key": @"K"});
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" titleIndexes:indexes key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"titleIndexes": indexes, @"type": @2, @"key": @"K"});
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" titleIndexes:indexes type:DVNCellTypeMenu key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"titleIndexes": indexes, @"type": @12, @"key": @"K"});
    checkFields([DVNCell cellWithTitle:@"T" subtitle:@"S" icon:(id)icon accessoryIcon:(id)accessory type:DVNCellTypeSelection key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"icon": icon, @"accessoryIcon": accessory, @"type": @3, @"key": @"K"});
    cell = [DVNCell cellWithTitle:@"T" subtitle:@"S" icon:(id)icon accessoryIcon:(id)accessory type:DVNCellTypeAction handler:handler];
    checkFields(cell, @{@"title": @"T", @"subtitle": @"S", @"icon": icon, @"accessoryIcon": accessory, @"type": @5});
    cell.handler(); REQUIRE(called == 2 && cell.selfHandler == nil);
    cell = [DVNCell cellWithTitle:@"T" subtitle:@"S" image:(id)image accessoryIcon:(id)accessory type:DVNCellTypeAction handler:selfHandler];
    checkFields(cell, @{@"title": @"T", @"subtitle": @"S", @"image": image, @"renderingMode": @1, @"accessoryIcon": accessory, @"type": @5});
    cell.selfHandler(cell); REQUIRE(received == cell && cell.handler == nil && cell.icon == nil); received = nil;
    checkFields([DVNCell sliderCellWithMinimum:-1.125 maximum:9.875 divider:0.25 key:@"K"],
                @{@"minimumValue": @-1.125, @"maximumValue": @9.875, @"dividerValue": @0.25, @"sliderFormat": @0, @"type": @6, @"key": @"K"});
    checkFields([DVNCell sliderCellWithMinimum:9.875 maximum:-1.125 divider:0 format:2 key:@"K"],
                @{@"minimumValue": @9.875, @"maximumValue": @-1.125, @"dividerValue": @0, @"sliderFormat": @2, @"type": @6, @"key": @"K"});
    cell = [FixtureSliderOverride sliderCellWithMinimum:1.125 maximum:8.5 divider:0.25 key:@"K"];
    REQUIRE(cell.class == FixtureSliderOverride.class && cell.minimumValue == 1.125 && cell.maximumValue == 8.5);
    REQUIRE(cell.dividerValue == 0.25 && cell.sliderFormat == 0 && [cell.key isEqual:@"K"]);
    checkFields([DVNCell textFieldCellWithTitle:@"T" subtitle:@"S" placeholder:@"P" key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"placeholder": @"P", @"key": @"K", @"type": @10});
    checkFields([DVNCell timePickerWithTitle:@"T" subtitle:@"S" minimum:1.125 maximum:1234.5 format:2 key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"minimumValue": @1.125, @"maximumValue": @1234.5, @"sliderFormat": @2, @"type": @7, @"key": @"K"});
    checkFields([DVNCell stepperCellWithTitle:@"T" subtitle:@"S" minimum:0.1 maximum:8.8 step:0.2 format:1 key:@"K"],
                @{@"title": @"T", @"subtitle": @"S", @"minimumValue": @0.1, @"maximumValue": @8.8, @"dividerValue": @0.2, @"sliderFormat": @1, @"type": @9, @"key": @"K"});
    REQUIRE(![[DVNCell new].reuseIdentifier isEqual:[DVNCell new].reuseIdentifier]);
}

static void testOwnershipAndBlocks(void) {
    DVNCell *cell = [DVNCell new];
    NSMutableString *text = [@"mutable" mutableCopy];
    for (NSString *key in @[@"identifier", @"title", @"subtitle", @"detailText", @"key", @"placeholder", @"errorText"]) {
        [cell setValue:text forKey:key];
        REQUIRE([cell valueForKey:key] == text);
    }
    @autoreleasepool {
        NSObject *view = [NSObject new];
        cell.sourceView = (id)view;
        REQUIRE((id)cell.sourceView == view);
    }
    REQUIRE(cell.sourceView == nil);
    cell.reloadsCell = YES; cell.reloadsTable = YES; cell.shouldHideDetail = YES;
    REQUIRE(cell.reloadsCell && cell.reloadsTable && cell.shouldHideDetail);
    __block NSUInteger completed = 0;
    cell.handlerWithCompletion = ^(void (^completion)(void)) { completion(); };
    cell.handlerWithCompletion(^{ completed++; });
    REQUIRE(completed == 1);
    cell.subtitleProvider = ^{ return text; };
    REQUIRE(cell.subtitleProvider() == text);
    NSArray *indexes = @[@1, @2];
    cell.titleIndexesProvider = ^{ return indexes; };
    REQUIRE(cell.titleIndexesProvider() == indexes);
    cell.validationHandler = ^NSString *(NSString *input) { return input.length ? input.uppercaseString : nil; };
    REQUIRE([cell.validationHandler(@"valid") isEqual:@"VALID"] && cell.validationHandler(@"") == nil);
    __weak NSObject *captured;
    @autoreleasepool {
        NSObject *object = [NSObject new];
        captured = object;
        cell.handler = ^{ (void)[object description]; };
    }
    REQUIRE(captured != nil);
    cell.handler(); cell.handler = nil;
    REQUIRE(captured == nil);
}

static void testSections(void) {
    DVNSection *empty = [FixtureSectionSubclass sectionWithIdentifier:@"section"];
    REQUIRE(empty.class == DVNSection.class && empty.cells.count == 0);
    DVNCell *initial = [DVNCell cellWithTitle:@"Initial title" subtitle:nil type:DVNCellTypeSwitch key:nil];
    NSMutableArray *initialCells = [NSMutableArray arrayWithObject:initial];
    NSObject *icon = [NSObject new];
    NSArray<DVNSection *> *sections = @[
        [DVNSection sectionWithCells:initialCells identifier:@"section"],
        [DVNSection sectionWithHeader:@"H" cells:initialCells identifier:@"section"],
        [DVNSection sectionWithHeader:@"H" footer:@"F" cells:initialCells identifier:@"section"],
        [DVNSection sectionWithHeader:@"H" headerIcon:(id)icon cells:initialCells identifier:@"section"],
        [DVNSection sectionWithHeader:@"H" headerIcon:(id)icon footer:@"F" cells:initialCells identifier:@"section"]];
    for (DVNSection *section in sections) {
        REQUIRE(section.cells == initialCells && [section.identifier isEqual:@"section"]);
        REQUIRE([initial.identifier isEqual:@"section"]);
    }
    REQUIRE([sections[1].header isEqual:@"H"] && [sections[2].footer isEqual:@"F"]);
    REQUIRE((id)sections[3].headerIcon == icon && (id)sections[4].headerIcon == icon && [sections[4].footer isEqual:@"F"]);
    REQUIRE([DVNSection sectionWithCells:nil identifier:nil].cells.count == 0);
    DVNSection *section = sections.lastObject;
    DVNCell *titled = [DVNCell cellWithTitle:@"Appended title" subtitle:nil type:0 key:nil];
    DVNCell *untitled = [DVNCell new];
    DVNCell *blank = [DVNCell cellWithTitle:@"" subtitle:nil type:0 key:nil];
    [section addCells:@[titled, untitled, blank]];
    REQUIRE([titled.identifier isEqual:@"Appended title"]);
    REQUIRE([untitled.identifier isEqual:@"section"] && [blank.identifier isEqual:@""]);
    REQUIRE(section.cells.count == 4 && initialCells.count == 1 && section.cells != initialCells);
    REQUIRE(![section.cells isKindOfClass:NSMutableArray.class]);
    NSArray *before = section.cells;
    [section addCells:nil]; [section addCells:@[]];
    REQUIRE(section.cells == before);
    DVNCell *extra = [DVNCell new];
    [section addCell:extra];
    REQUIRE(section.cells.count == 5 && section.cells.lastObject == extra);
    BOOL threw = NO;
    @try { [section addCell:nil]; }
    @catch (NSException *exception) { threw = [exception.name isEqual:NSInvalidArgumentException]; }
    REQUIRE(threw);
    section.cells = nil;
    [section addCell:extra];
    REQUIRE(section.cells == nil && [extra.identifier isEqual:@"section"]);
    __block NSUInteger providerCalls = 0;
    section.cellsProvider = ^{ providerCalls++; return initialCells; };
    [section addCells:@[extra]];
    REQUIRE(providerCalls == 0);
    REQUIRE(section.cellsProvider() == initialCells && providerCalls == 1);
}

void testSettingsModels(void) {
    testFactories(); testOwnershipAndBlocks(); testSections();
    printf("Settings model tests: %lu assertions passed.\n", (unsigned long)assertions);
}
