#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/message.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
#import "../source/Models/DVNSection.h"
#import "../source/Models/DVNTableModel.h"
#import "../source/Support/YTPDB.h"

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)

@interface SectionSubclass : DVNSection @end
@implementation SectionSubclass @end
@interface TableModelSubclass : DVNTableModel @end
@implementation TableModelSubclass @end

static DVNCell *cell(NSString *title, NSString *subtitle) {
    return [DVNCell cellWithTitle:title subtitle:subtitle type:0 key:nil];
}

static void testSections(void) {
    DVNCell *titled = cell(@"Title", nil), *untitled = cell(nil, nil), *emptyTitle = cell(@"", nil);
    DVNSection *section = [DVNSection sectionWithIdentifier:@"section"];
    CHECK(section.cells != nil && section.cells.count == 0);
    NSArray *before = section.cells;
    [section addCells:nil]; [section addCells:@[]];
    CHECK(section.cells == before);
    [section addCells:@[titled, untitled, emptyTitle]];
    CHECK([section.cells isEqual:@[titled, untitled, emptyTitle]]);
    CHECK([titled.identifier isEqual:@"Title"] && [untitled.identifier isEqual:@"section"]);
    CHECK([emptyTitle.identifier isEqual:@""]);
    CHECK(before.count == 0 && section.cells != before);
    DVNCell *extra = cell(@"extra", nil);
    [section addCell:extra];
    CHECK(section.cells.lastObject == extra && [extra.identifier isEqual:@"extra"]);
    BOOL raised = NO;
    @try { [section addCell:nil]; } @catch (NSException *exception) { raised = YES; }
    CHECK(raised);
    section.cells = nil;
    [section addCell:titled];
    CHECK(section.cells == nil); // nil mutableCopy is not replaced with an array

    NSMutableArray *cells = [NSMutableArray arrayWithObjects:titled, untitled, nil];
    UIImage *icon = [UIImage new];
    NSArray *factories = @[
        [DVNSection sectionWithCells:cells identifier:@"id"],
        [DVNSection sectionWithHeader:@"header" cells:cells identifier:@"id"],
        [DVNSection sectionWithHeader:@"header" footer:@"footer" cells:cells identifier:@"id"],
        [DVNSection sectionWithHeader:@"header" headerIcon:icon cells:cells identifier:@"id"],
        [DVNSection sectionWithHeader:@"header" headerIcon:icon footer:@"footer" cells:cells identifier:@"id"],
    ];
    for (DVNSection *result in factories) {
        CHECK(result.cells == cells && [result.identifier isEqual:@"id"]);
        CHECK([titled.identifier isEqual:@"id"] && [untitled.identifier isEqual:@"id"]);
    }
    CHECK([factories[1] header] == [factories[2] header]);
    CHECK([[factories[2] footer] isEqual:@"footer"]);
    CHECK([factories[3] headerIcon] == icon && [factories[4] headerIcon] == icon);
    CHECK([DVNSection sectionWithCells:nil identifier:nil].cells.count == 0);
    CHECK(object_getClass([SectionSubclass sectionWithIdentifier:nil]) == [DVNSection class]);
    __weak id weakCapture;
    section = [DVNSection new];
    @autoreleasepool {
        id capture = [NSObject new]; weakCapture = capture;
        section.cellsProvider = ^{ return @[capture]; };
    }
    @autoreleasepool {
        CHECK(weakCapture != nil && section.cellsProvider().count == 1);
    }
    section.cellsProvider = nil;
    CHECK(weakCapture == nil);
}

static void testTableModels(void) {
    DVNTableModel *model = [DVNTableModel model];
    CHECK(model.sections != nil && model.sections.count == 0);
    CHECK(model.headerFont.pointSize == 14 && model.footerFont.pointSize == 13);
    CHECK(model.headerFont.recoveredTestWeight == UIFontWeightSemibold);
    CHECK(model.footerFont.recoveredTestWeight == UIFontWeightSemibold);
    CHECK(model.headerAlignment == 1 && model.footerAlignment == 1);
    CHECK(!model.supportsSearching && !model.showsThanksHeart);
    DVNCell *a = cell(@"Alpha", nil), *b = cell(nil, @"needle"), *c = cell(@"child", nil);
    DVNSection *first = [DVNSection sectionWithCells:@[a] identifier:@"first"];
    DVNSection *second = [DVNSection sectionWithCells:@[b] identifier:@"second"];
    NSArray *before = model.sections;
    [model addSection:first]; [model addSections:@[second]];
    CHECK(before.count == 0 && [model.sections isEqual:@[first, second]]);
    CHECK([model cellForString:@"Alpha"] == a && [model cellForString:@"needle"] == b);
    CHECK([model cellForString:@"alpha"] == nil && [model cellForString:@"child"] == nil);
    CHECK([model cellForString:@""] == nil);
    CHECK([[model cellsMatching:^BOOL(DVNCell *candidate) { return candidate == b; }] isEqual:@[b]]);
    first.cellsProvider = ^{ CHECK(NO); return @[]; }; // model searches stored cells, not a provider
    DVNTableModel *child = [DVNTableModel modelWithTitle:@"child" sections:@[[DVNSection sectionWithCells:@[c] identifier:nil]]];
    child.supportsSearching = YES;
    a.controllerModel = child; b.controllerModel = child;
    c.controllerModel = model;
    model.supportsSearching = YES;
    NSArray *matches = [model cellsMatchingRecursive:^BOOL(DVNCell *candidate) { return YES; }];
    CHECK([matches isEqual:@[a, c, b]]); // depth-first order; shared child visited once; cycle terminates
    CHECK([[model cellsMatching:^BOOL(DVNCell *candidate) { return YES; }] isEqual:@[a, b]]);
    child.supportsSearching = NO;
    CHECK([[model cellsMatchingRecursive:^BOOL(DVNCell *candidate) { return YES; }] isEqual:@[a, b]]);
    child.supportsSearching = YES; model.supportsSearching = NO;
    CHECK([[model cellsMatchingRecursive:^BOOL(DVNCell *candidate) { return YES; }] isEqual:@[a, c, b]]);
    NSMutableArray *existing = [NSMutableArray arrayWithObject:c];
    NSHashTable *visited = [NSHashTable weakObjectsHashTable];
    [visited addObject:model];
    [model _collectMatching:^BOOL(DVNCell *candidate) { CHECK(NO); return YES; } into:existing visited:visited];
    CHECK([existing isEqual:@[c]]);
    CHECK([[DVNTableModel model] cellsMatching:nil].count == 0);

    UIViewController *controller = [UIViewController new];
    DVNTableModel *withController = [DVNTableModel modelWithTitle:@"t" header:@"h" footer:@"f" viewController:controller];
    CHECK([withController.title isEqual:@"t"] && [withController.header isEqual:@"h"] && [withController.footer isEqual:@"f"]);
    CHECK(withController.viewController == controller && withController.sections.count == 0);
    NSMutableArray *sections = [NSMutableArray arrayWithObject:first];
    DVNTableModel *withSections = [DVNTableModel modelWithTitle:@"t" header:@"h" footer:@"f" sections:sections];
    CHECK(withSections.sections == sections && [withSections.footer isEqual:@"f"]);
    CHECK([DVNTableModel modelWithTitle:nil sections:nil].sections.count == 0);
    CHECK(object_getClass([TableModelSubclass model]) == [DVNTableModel class]);
    __weak id weakController;
    @autoreleasepool {
        UIViewController *temporary = [UIViewController new]; weakController = temporary;
        model.selfViewController = temporary;
        CHECK(model.selfViewController == temporary);
    }
    CHECK(weakController == nil && model.selfViewController == nil);
    a.controllerModel = nil; b.controllerModel = nil; c.controllerModel = nil;
}

@interface BundleDouble : NSObject
@property(nonatomic, strong) NSArray *localizations;
@property(nonatomic, strong) NSArray *preferredLocalizations;
@property(nonatomic, strong) NSBundle *underlyingBundle;
@end
@implementation BundleDouble
- (id)forwardingTargetForSelector:(SEL)selector {
    return [self.underlyingBundle respondsToSelector:selector] ? self.underlyingBundle : [super forwardingTargetForSelector:selector];
}
@end
@interface LocaleDouble : NSObject
@property(nonatomic, strong) NSDictionary *names;
- (NSString *)displayNameForKey:(NSLocaleKey)key value:(id)value;
@end
@implementation LocaleDouble
- (NSString *)displayNameForKey:(NSLocaleKey)key value:(id)value {
    CHECK([key isEqual:NSLocaleIdentifier]);
    return value ? self.names[value] : nil;
}
@end
static BundleDouble *bundleDouble;
static LocaleDouble *localeDouble;
static id replacementBundle(id receiver, SEL selector) { return bundleDouble; }
static id replacementLocale(id receiver, SEL selector) { return localeDouble; }

static void testDatabase(NSString *evidenceDirectory) {
    NSData *data = [NSData dataWithContentsOfFile:[evidenceDirectory stringByAppendingPathComponent:@"support-constants.json"]];
    CHECK(data != nil);
    NSDictionary *constants = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];
    for (NSString *name in @[@"thanks", @"clip", @"report", @"hype", @"stopAds"]) {
        NSArray *actual = ((id (*)(id, SEL))objc_msgSend)([YTPDB class], NSSelectorFromString(name));
        CHECK([actual isEqual:constants[@"arrays"][name][@"values"]]);
        CHECK(actual.count == [constants[@"arrays"][name][@"count"] unsignedIntegerValue]);
        for (id value in actual) CHECK([value isKindOfClass:[NSString class]] && [value length] > 0);
    }
    bundleDouble = [BundleDouble new];
    bundleDouble.underlyingBundle = [NSBundle mainBundle];
    bundleDouble.localizations = @[@"en", @"en-GB", @"unmapped", @"fr"];
    bundleDouble.preferredLocalizations = @[@"fr"];
    localeDouble = [LocaleDouble new];
    localeDouble.names = @{@"en": @"English", @"en-GB": @"English", @"fr": @"French"};
    Method bundleMethod = class_getClassMethod([NSBundle class], @selector(mainBundle));
    Method localeMethod = class_getClassMethod([NSLocale class], @selector(currentLocale));
    IMP savedBundle = method_setImplementation(bundleMethod, (IMP)replacementBundle);
    IMP savedLocale = method_setImplementation(localeMethod, (IMP)replacementLocale);
    @try {
        CHECK([[YTPDB supportedLanguages] isEqual:@[@"English", @"French", @"unmapped"]]);
        CHECK([[YTPDB langCodeForIndex:0] isEqual:@"en"]); // first duplicate display name wins
        CHECK([[YTPDB langCodeForIndex:1] isEqual:@"fr"]);
        CHECK([YTPDB langCodeForIndex:2] == nil); // unmapped display remains visible but has no code
        CHECK([YTPDB langCodeForIndex:-1] == nil && [YTPDB langCodeForIndex:NSIntegerMin] == nil);
        CHECK([YTPDB langCodeForIndex:3] == nil && [YTPDB langCodeForIndex:NSIntegerMax] == nil);
        CHECK([YTPDB indexOfPreferredLanguage] == 1);
        bundleDouble.preferredLocalizations = @[@"en-GB"];
        CHECK([YTPDB indexOfPreferredLanguage] == 0);
        bundleDouble.preferredLocalizations = @[@"missing"];
        CHECK([YTPDB indexOfPreferredLanguage] == 0);
        bundleDouble.localizations = @[]; bundleDouble.preferredLocalizations = @[];
        CHECK([YTPDB supportedLanguages].count == 0);
        CHECK([YTPDB langCodeForIndex:0] == nil && [YTPDB indexOfPreferredLanguage] == 0);
    } @finally {
        method_setImplementation(bundleMethod, savedBundle);
        method_setImplementation(localeMethod, savedLocale);
        bundleDouble = nil; localeDouble = nil;
    }
}

NSUInteger runTableTests(NSString *evidenceDirectory) {
    testSections(); testTableModels(); testDatabase(evidenceDirectory);
    return checks;
}
