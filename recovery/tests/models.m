#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "../source/Models/DVNCell.h"
#import "../source/Models/SBSegment.h"
#import "../source/Models/SBPlayerDecorationData.h"
#import "../source/Models/RPCMedia.h"

static NSUInteger checks;
extern NSUInteger runTableTests(NSString *evidenceDirectory);
extern NSUInteger runPreferenceTests(NSString *evidenceDirectory, NSString *workDirectory);
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)

@interface SegmentSubclass : SBSegment @end
@implementation SegmentSubclass @end
@interface CellSubclass : DVNCell @end
@implementation CellSubclass
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [super sliderCellWithMinimum:minimum maximum:maximum divider:divider format:format key:key];
    cell.customData = @{@"subclassForwarding": @YES};
    return (id)cell;
}
@end

// Foundation-only host doubles. They test typed messaging, not YouTube itself.
@interface RPCTimeDouble : NSObject
@property(nonatomic) double time;
@end
@implementation RPCTimeDouble @end
@interface RPCActiveDouble : NSObject
@property(nonatomic) double totalMediaTime;
@property(nonatomic, strong) RPCTimeDouble *currentVideoTime;
@end
@implementation RPCActiveDouble @end
@interface RPCNodeDouble : NSObject
@property(nonatomic, strong) id playerData;
@property(nonatomic, strong) id videoDetails;
@property(nonatomic, strong) id thumbnail;
@property(nonatomic, strong) NSArray *thumbnailsArray;
@property(nonatomic, strong) NSString *URL;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *author;
@end
@implementation RPCNodeDouble @end
@interface RPCBasePlayerDouble : NSObject
@property(nonatomic, strong) NSString *currentVideoID;
@property(nonatomic, strong) RPCActiveDouble *activeVideo;
@end
@implementation RPCBasePlayerDouble @end
@interface RPCPrimaryPlayerDouble : RPCBasePlayerDouble
@property(nonatomic, strong) RPCNodeDouble *playerResponse;
@property(nonatomic, strong) RPCNodeDouble *contentPlayerResponse;
@end
@implementation RPCPrimaryPlayerDouble @end
@interface RPCSecondaryPlayerDouble : RPCBasePlayerDouble
@property(nonatomic, strong) RPCNodeDouble *contentPlayerResponse;
@end
@implementation RPCSecondaryPlayerDouble @end

static void testSegments(void) {
    CHECK([SBSegment segmentWithDictionary:nil] == nil);
    CHECK([SBSegment segmentWithDictionary:@{}] == nil);
    CHECK([SBSegment segmentWithDictionary:@{@"segment": @"bad"}] == nil);
    CHECK([SBSegment segmentWithDictionary:@{@"segment": @[]}] == nil);
    CHECK([SBSegment segmentWithDictionary:@{@"segment": @[@1]}] == nil);
    CHECK([SBSegment segmentWithDictionary:@{@"segment": @[@1, @2, @3]}] == nil);
    NSMutableString *identifier = [@"uuid" mutableCopy];
    NSDictionary *dictionary = @{@"segment": @[@1.25, @5.75], @"UUID": identifier,
        @"category": @"sponsor", @"actionType": @"skip", @"description": @"description",
        @"videoDuration": @123.456, @"locked": @YES, @"votes": @(((NSInteger)1 << 40) + 7)};
    SBSegment *segment = [SBSegment segmentWithDictionary:dictionary];
    CHECK(segment.start == 1.25 && segment.end == 5.75);
    CHECK(segment.videoDuration == 123.456 && segment.locked);
    CHECK(segment.votes == ((NSInteger)1 << 40) + 7);
    CHECK([segment.category isEqual:@"sponsor"]);
    CHECK([segment.actionType isEqual:@"skip"]);
    CHECK([segment.segmentDescription isEqual:@"description"]);
    CHECK(segment.uuid == identifier);
    [identifier appendString:@" changed"];
    CHECK([segment.uuid isEqual:@"uuid changed"]);
    SBSegment *emptyFields = [SBSegment segmentWithDictionary:@{@"segment": @[@0, @0]}];
    CHECK(emptyFields != nil && emptyFields.uuid == nil && !emptyFields.locked);
    CHECK(emptyFields.votes == 0 && emptyFields.videoDuration == 0);
    CHECK(object_getClass([SegmentSubclass segmentWithDictionary:dictionary]) == [SBSegment class]);
}

static void testCellFactories(void) {
    NSString *title = @"title", *subtitle = @"subtitle", *key = @"key";
    NSArray *indexes = @[@"one", @"two"];
    UIImage *icon = (id)[NSObject new], *image = (id)[NSObject new], *accessory = (id)[NSObject new];
    DVNTableModel *model = (id)[NSObject new];
    __block NSUInteger calls = 0;
    void (^handler)(void) = ^{ calls++; };
    DVNCell *cell = [DVNCell controllerCellWithModel:model title:title subtitle:subtitle icon:icon];
    CHECK(cell.type == 4 && cell.controllerModel == model && cell.icon == icon);
    CHECK(cell.title == title && cell.subtitle == subtitle);
    cell = [DVNCell cellWithTitleIndexes:indexes key:key];
    CHECK(cell.type == 1 && cell.titleIndexes == indexes && cell.key == key);
    cell = [DVNCell cellWithImageIndexes:indexes key:key];
    CHECK(cell.type == 1 && cell.imageIndexes == indexes && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle handler:handler];
    CHECK(cell.type == 5 && cell.handler && !cell.selfHandler);
    ((void (^)(void))cell.handler)();
    cell = [DVNCell cellWithTitle:title subtitle:subtitle selfHandler:handler];
    CHECK(cell.type == 5 && cell.selfHandler && !cell.handler);
    ((void (^)(void))cell.selfHandler)();
    cell = [DVNCell cellWithTitle:title subtitle:subtitle type:12 key:key];
    CHECK(cell.type == 12 && cell.title == title && cell.subtitle == subtitle && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle icon:icon type:11 key:key];
    CHECK(cell.type == 11 && cell.icon == icon && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle imageIndexes:indexes key:key];
    CHECK(cell.type == 2 && cell.imageIndexes == indexes && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle titleIndexes:indexes key:key];
    CHECK(cell.type == 2 && cell.titleIndexes == indexes && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle titleIndexes:indexes type:3 key:key];
    CHECK(cell.type == 3 && cell.titleIndexes == indexes && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle icon:icon accessoryIcon:accessory type:8 key:key];
    CHECK(cell.type == 8 && cell.icon == icon && cell.accessoryIcon == accessory && cell.key == key);
    cell = [DVNCell cellWithTitle:title subtitle:subtitle icon:icon accessoryIcon:accessory type:5 handler:handler];
    CHECK(cell.icon == icon && cell.accessoryIcon == accessory && cell.handler && !cell.selfHandler);
    ((void (^)(void))cell.handler)();
    cell = [DVNCell cellWithTitle:title subtitle:subtitle image:image accessoryIcon:accessory type:5 handler:handler];
    CHECK(cell.image == image && cell.accessoryIcon == accessory && !cell.handler && cell.selfHandler);
    CHECK(cell.renderingMode == 1);
    ((void (^)(void))cell.selfHandler)();
    CHECK(calls == 4);
    cell = [DVNCell sliderCellWithMinimum:0.125 maximum:4.5 divider:0.25 key:key];
    CHECK(cell.type == 6 && cell.sliderFormat == 0 && cell.minimumValue == 0.125 && cell.maximumValue == 4.5);
    CHECK(cell.dividerValue == 0.25 && cell.key == key);
    cell = [DVNCell sliderCellWithMinimum:-2 maximum:9 divider:0.5 format:2 key:key];
    CHECK(cell.type == 6 && cell.sliderFormat == 2 && cell.minimumValue == -2 && cell.maximumValue == 9);
    CHECK(cell.dividerValue == 0.5 && cell.key == key);
    cell = [DVNCell textFieldCellWithTitle:title subtitle:subtitle placeholder:@"hint" key:key];
    CHECK(cell.type == 10 && [cell.placeholder isEqual:@"hint"] && cell.key == key);
    cell = [DVNCell timePickerWithTitle:title subtitle:subtitle minimum:5 maximum:120 format:1 key:key];
    CHECK(cell.type == 7 && cell.minimumValue == 5 && cell.maximumValue == 120 && cell.sliderFormat == 1);
    cell = [DVNCell stepperCellWithTitle:title subtitle:subtitle minimum:1 maximum:12 step:0.125 format:3 key:key];
    CHECK(cell.type == 9 && cell.minimumValue == 1 && cell.maximumValue == 12 && cell.dividerValue == 0.125);
    CHECK(cell.sliderFormat == 3 && cell.key == key);
    CHECK(object_getClass([CellSubclass cellWithTitleIndexes:indexes key:key]) == [DVNCell class]);
    cell = [CellSubclass sliderCellWithMinimum:1 maximum:3 divider:0.25 key:key];
    CHECK([cell.customData[@"subclassForwarding"] boolValue]);

    DVNCell *first = [DVNCell new], *second = [DVNCell new];
    CHECK(first.reuseIdentifier.length > 0 && ![first.reuseIdentifier isEqual:second.reuseIdentifier]);
    CHECK(!first.reloadsCell && !first.reloadsTable && !first.shouldHideDetail && first.type == 0);
    CHECK(first.minimumValue == 0 && first.maximumValue == 0 && first.dividerValue == 0);
    NSMutableString *mutableTitle = [@"retained" mutableCopy];
    first.title = mutableTitle;
    [mutableTitle appendString:@" title"];
    CHECK(first.title == mutableTitle && [first.title isEqual:@"retained title"]);
}

static void testOwnership(void) {
    DVNCell *cell = [DVNCell new];
    SBPlayerDecorationData *decoration = [SBPlayerDecorationData new];
    __weak id weakView;
    @autoreleasepool {
        id view = [NSObject new]; weakView = view;
        cell.sourceView = view; decoration.barView = view;
        CHECK(cell.sourceView == view && decoration.barView == view);
    }
    CHECK(weakView == nil && cell.sourceView == nil && decoration.barView == nil);
    __weak id weakCapture;
    @autoreleasepool {
        id capture = [NSObject new]; weakCapture = capture;
        cell.handler = ^{ (void)[capture description]; };
    }
    CHECK(weakCapture != nil);
    cell.handler = nil;
    CHECK(weakCapture == nil);
    NSMutableArray *segments = [NSMutableArray array];
    decoration.segments = segments;
    [segments addObject:[SBSegment new]];
    CHECK(decoration.segments == segments && decoration.segments.count == 1);
    decoration.playerBarWidth = 319.75; decoration.mediaDuration = 3600.25;
    CHECK(decoration.playerBarWidth == 319.75 && decoration.mediaDuration == 3600.25);
}

static void testRPC(void) {
    RPCNodeDouble *node = [RPCNodeDouble new];
    node.title = [@"title" mutableCopy]; node.author = [@"author" mutableCopy];
    node.URL = [@"https://example.invalid/image" mutableCopy];
    // One node is sufficient for the nested host data getters; break cycles below.
    node.playerData = node; node.videoDetails = node; node.thumbnail = node; node.thumbnailsArray = @[node];
    RPCPrimaryPlayerDouble *primary = [RPCPrimaryPlayerDouble new];
    primary.currentVideoID = [@"video" mutableCopy];
    primary.activeVideo = [RPCActiveDouble new];
    primary.activeVideo.totalMediaTime = 100.25;
    primary.activeVideo.currentVideoTime = [RPCTimeDouble new];
    primary.activeVideo.currentVideoTime.time = 33.125;
    primary.playerResponse = node;
    RPCMedia *media = [RPCMedia mediaWithPlayer:primary];
    CHECK([media.videoID isEqual:@"video"] && [media.title isEqual:@"title"] && [media.author isEqual:@"author"]);
    CHECK(media.totalTime == 100.25 && media.currentTime == 33.125 && !media.isPaused);
    CHECK([media.thumbnailURL isEqual:node.URL]);
    [(NSMutableString *)primary.currentVideoID appendString:@" changed"];
    [(NSMutableString *)node.title appendString:@" changed"];
    [(NSMutableString *)node.author appendString:@" changed"];
    [(NSMutableString *)node.URL appendString:@" changed"];
    CHECK([media.videoID isEqual:@"video"] && [media.title isEqual:@"title"] && [media.author isEqual:@"author"]);
    CHECK([media.thumbnailURL isEqual:@"https://example.invalid/image"]);
    RPCSecondaryPlayerDouble *secondary = [RPCSecondaryPlayerDouble new];
    secondary.contentPlayerResponse = node; secondary.currentVideoID = @"fallback";
    secondary.activeVideo = primary.activeVideo;
    CHECK([[RPCMedia mediaWithPlayer:secondary].videoID isEqual:@"fallback"]);
    primary.playerResponse = nil; primary.contentPlayerResponse = node;
    CHECK([RPCMedia mediaWithPlayer:primary] == nil); // no fallback on a nil primary response
    CHECK([RPCMedia mediaWithPlayer:[NSObject new]] == nil && [RPCMedia mediaWithPlayer:nil] == nil);
    secondary.contentPlayerResponse = nil;
    CHECK([RPCMedia mediaWithPlayer:secondary] == nil);
    primary.playerResponse = node; node.thumbnailsArray = @[];
    BOOL raised = NO;
    @try { (void)[RPCMedia mediaWithPlayer:primary]; } @catch (NSException *exception) { raised = YES; }
    CHECK(raised);
    node.playerData = nil; node.videoDetails = nil; node.thumbnail = nil;
}

static void checkMetadata(NSString *path) {
    NSError *error = nil;
    NSData *data = [NSData dataWithContentsOfFile:path options:0 error:&error];
    CHECK(data != nil && error == nil);
    NSArray *classes = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
    CHECK(classes != nil && error == nil);
    NSSet *selected = [NSSet setWithArray:@[@"SBSegment", @"SBPlayerDecorationData", @"DVNCell", @"RPCMedia",
        @"DVNSection", @"DVNTableModel", @"YTPDB", @"YTLUserDefaults"]];
    NSUInteger methods = 0, properties = 0, foundClasses = 0;
    for (NSDictionary *entry in classes) {
        if (![selected containsObject:entry[@"name"]]) continue;
        Class cls = NSClassFromString(entry[@"name"]);
        CHECK(cls != Nil); foundClasses++;
        for (NSDictionary *spec in entry[@"methods"]) {
            SEL selector = NSSelectorFromString(spec[@"selector"]);
            Method method = [spec[@"kind"] isEqual:@"+"] ? class_getClassMethod(cls, selector) : class_getInstanceMethod(cls, selector);
            CHECK(method != NULL);
            NSString *actual = [NSString stringWithUTF8String:method_getTypeEncoding(method)];
            if (![actual isEqual:spec[@"encoding"]]) {
                fprintf(stderr, "%s %s: expected %s, got %s\n", class_getName(cls), sel_getName(selector),
                    [spec[@"encoding"] UTF8String], actual.UTF8String);
            }
            CHECK([actual isEqual:spec[@"encoding"]]); methods++;
        }
        for (NSDictionary *spec in entry[@"properties"]) {
            objc_property_t property = class_getProperty(cls, [spec[@"name"] UTF8String]);
            CHECK(property != NULL);
            NSString *actual = [NSString stringWithUTF8String:property_getAttributes(property)];
            if (![actual isEqual:spec[@"attributes"]]) {
                fprintf(stderr, "%s.%s: expected %s, got %s\n", class_getName(cls), [spec[@"name"] UTF8String],
                    [spec[@"attributes"] UTF8String], actual.UTF8String);
            }
            CHECK([actual isEqual:spec[@"attributes"]]); properties++;
        }
    }
    CHECK(foundClasses == selected.count);
    printf("Metadata matched: %lu classes, %lu methods, %lu properties.\n",
        (unsigned long)foundClasses, (unsigned long)methods, (unsigned long)properties);
}

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        if (argc != 3) { fprintf(stderr, "usage: models-test arm-classes.json work-directory\n"); return 2; }
        testSegments(); testCellFactories(); testOwnership(); testRPC();
        checks += runTableTests([[NSString stringWithUTF8String:argv[1]] stringByDeletingLastPathComponent]);
        checks += runPreferenceTests([[NSString stringWithUTF8String:argv[1]] stringByDeletingLastPathComponent],
                                     [NSString stringWithUTF8String:argv[2]]);
        checkMetadata([NSString stringWithUTF8String:argv[1]]);
        printf("Model behavior/ABI assertions passed: %lu.\n", (unsigned long)checks);
    }
    return 0;
}
