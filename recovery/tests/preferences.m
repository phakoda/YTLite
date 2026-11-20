#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Security/Security.h>
#import "../../Utils/YTLUserDefaults.h"
#import "../source/Support/YTPDB.h"
#import "../source/Support/YTLRecoveredDefaults.h"

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)

// The host test compiler redirects ONLY calls from the compiled source to this
// explicit random-source double. The iOS objects use the real Security API.
static NSData *randomFixture;
static int randomStatus;
static NSUInteger randomCalls;
int YTLTestSecRandomCopyBytes(SecRandomRef random, size_t count, void *bytes) {
    CHECK(random == kSecRandomDefault && count == 36);
    randomCalls++;
    if (randomStatus) return randomStatus;
    CHECK(randomFixture.length == count);
    memcpy(bytes, randomFixture.bytes, count);
    return 0;
}

@interface MemoryPreferences : YTLUserDefaults
@property(nonatomic, strong) NSMutableDictionary *memory;
@property(nonatomic, strong) NSDictionary *registered;
@property(nonatomic, copy) NSString *rejectedKey;
@property(nonatomic, copy) NSString *removedDomain;
@property(nonatomic) NSUInteger synchronizations;
@property(nonatomic) float receivedFloat;
@end
static MemoryPreferences *memoryPreferences;
@implementation MemoryPreferences
+ (YTLUserDefaults *)standardUserDefaults { return memoryPreferences; }
- (instancetype)init {
    self = [super initWithSuiteName:@"com.dvntm.ytlite.recovery.memory-only"];
    if (self) { _memory = [NSMutableDictionary dictionary]; _registered = @{}; }
    return self;
}
- (void)registerDefaults:(NSDictionary *)values { self.registered = [values copy]; }
- (id)objectForKey:(NSString *)key { return self.memory[key] ?: self.registered[key]; }
- (void)setObject:(id)value forKey:(NSString *)key {
    if ([key isEqual:self.rejectedKey]) return;
    if (value) self.memory[key] = value;
    else [self.memory removeObjectForKey:key];
}
- (BOOL)boolForKey:(NSString *)key { return [[self objectForKey:key] boolValue]; }
- (NSInteger)integerForKey:(NSString *)key { return [[self objectForKey:key] integerValue]; }
- (float)floatForKey:(NSString *)key { return [[self objectForKey:key] floatValue]; }
- (void)setBool:(BOOL)value forKey:(NSString *)key { [self setObject:@(value) forKey:key]; }
- (void)setInteger:(NSInteger)value forKey:(NSString *)key { [self setObject:@(value) forKey:key]; }
- (void)setFloat:(float)value forKey:(NSString *)key {
    self.receivedFloat = value;
    [self setObject:@(value) forKey:key];
}
- (void)removePersistentDomainForName:(NSString *)domain {
    self.removedDomain = domain;
    [self.memory removeAllObjects];
}
- (BOOL)synchronize { self.synchronizations++; return NO; }
@end

// Exact host class name looked up by the source, never linked into production.
static UIViewController *presenter;
@interface YTUIUtils : NSObject
+ (UIViewController *)topViewControllerForPresenting;
@end
@implementation YTUIUtils
+ (UIViewController *)topViewControllerForPresenting { return presenter; }
@end

static id readJSON(NSString *path) {
    NSError *error = nil;
    NSData *data = [NSData dataWithContentsOfFile:path options:0 error:&error];
    CHECK(data != nil && error == nil);
    id value = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingFragmentsAllowed error:&error];
    CHECK(value != nil && error == nil);
    return value;
}

static NSString *unquote(NSString *expression) {
    CHECK([expression hasPrefix:@"@\""]);
    NSData *data = [[expression substringFromIndex:1] dataUsingEncoding:NSUTF8StringEncoding];
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingFragmentsAllowed error:NULL];
}

static void checkArchivedColor(NSData *data, NSString *name, NSDictionary *constants) {
    CHECK([data isKindOfClass:[NSData class]] && data.length > 0);
    NSError *error = nil;
    UIColor *color = [NSKeyedUnarchiver unarchivedObjectOfClass:[UIColor class] fromData:data error:&error];
    CHECK(color != nil && error == nil);
    NSArray *components = constants[@"colors"][name][@"components"] ?: @[@1, @0, @0, @1];
    CHECK(color.recoveredRed == [components[0] doubleValue]);
    CHECK(color.recoveredGreen == [components[1] doubleValue]);
    CHECK(color.recoveredBlue == [components[2] doubleValue]);
    CHECK(color.recoveredAlpha == [components[3] doubleValue]);
}

static void testIDsAndDefaults(NSString *evidenceDirectory, NSString *workDirectory) {
    NSDictionary *vectors = readJSON([workDirectory stringByAppendingPathComponent:@"preference-vectors.json"]);
    NSMutableData *bytes = [NSMutableData data];
    for (NSNumber *number in vectors[@"random_bytes"]) {
        unsigned char byte = number.unsignedCharValue;
        [bytes appendBytes:&byte length:1];
    }
    randomFixture = bytes;
    memoryPreferences = [MemoryPreferences new];
    CHECK([[memoryPreferences sbPrivateUserID] isEqual:vectors[@"private_id"]]);
    CHECK(randomCalls == 1);
    for (NSDictionary *vector in vectors[@"hash_vectors"]) {
        CHECK([[memoryPreferences sbPublicUserID:vector[@"input"]] isEqual:vector[@"public_id"]]);
    }
    CHECK([[memoryPreferences sbPublicUserID:nil] isEqual:vectors[@"hash_vectors"][0][@"public_id"]]);
    randomStatus = errSecParam;
    CHECK([memoryPreferences sbPrivateUserID] == nil);
    // The packaged dictionary uses a literal, so an entropy failure raises
    // instead of inventing an empty ID or silently changing stored defaults.
    BOOL raised = NO;
    @try { (void)YTLRecoveredDefaultValues(memoryPreferences); }
    @catch (NSException *exception) { raised = YES; }
    CHECK(raised);
    randomStatus = 0;
    NSDictionary *constants = readJSON([evidenceDirectory stringByAppendingPathComponent:@"support-constants.json"]);
    for (NSString *name in constants[@"colors"]) {
        checkArchivedColor([memoryPreferences colorForSegment:name], name, constants);
    }
    CHECK([memoryPreferences colorForSegment:@"not-a-segment"] == nil);
    [memoryPreferences setBool:NO forKey:@"noAds"];
    [memoryPreferences registerDefaults];
    CHECK(memoryPreferences.registered.count == 49);
    CHECK(![memoryPreferences boolForKey:@"noAds"]); // registration must not overwrite a persisted value
    CHECK([[memoryPreferences.registered objectForKey:@"sbPrivateUserID"] isEqual:vectors[@"private_id"]]);
    CHECK([[memoryPreferences.registered objectForKey:@"sbPublicUserID"] isEqual:vectors[@"private_public_id"]]);

    NSArray *specification = readJSON([evidenceDirectory stringByAppendingPathComponent:@"defaults.json"]);
    NSMutableSet *keys = [NSMutableSet set];
    for (NSDictionary *entry in specification) {
        NSString *key = unquote(entry[@"key"]), *expression = entry[@"value"];
        [keys addObject:key];
        id actual = memoryPreferences.registered[key];
        CHECK(actual != nil);
        if ([expression hasPrefix:@"[self colorForSegment:"]) {
            NSString *argument = [expression substringWithRange:NSMakeRange(22, expression.length - 23)];
            checkArchivedColor(actual, unquote(argument), constants);
        } else if ([expression isEqual:@"@YES"] || [expression isEqual:@"@NO"]) {
            CHECK([actual isEqual:@([expression isEqual:@"@YES"])]);
        } else if ([expression hasPrefix:@"@[ "] || [expression hasPrefix:@"@["] || [expression hasPrefix:@"@\""]) {
            NSString *json = [expression stringByReplacingOccurrencesOfString:@"@" withString:@""];
            id expected = [NSJSONSerialization JSONObjectWithData:[json dataUsingEncoding:NSUTF8StringEncoding]
                options:NSJSONReadingFragmentsAllowed error:NULL];
            CHECK(expected != nil && [actual isEqual:expected]);
        } else if ([expression hasPrefix:@"@([YTPDB "]) {
            CHECK([actual unsignedIntegerValue] == [YTPDB indexOfPreferredLanguage]);
        } else if ([expression hasPrefix:@"@"] && [expression length] > 1) {
            CHECK([actual isEqual:@([[expression substringFromIndex:1] integerValue])]);
        } else {
            CHECK([key isEqual:@"sbPrivateUserID"] || [key isEqual:@"sbPublicUserID"]);
        }
    }
    CHECK([keys isEqual:[NSSet setWithArray:memoryPreferences.registered.allKeys]]);
    [MemoryPreferences setBool:YES forKey:@"flag"];
    CHECK([MemoryPreferences boolForKey:@"flag"]);
    NSInteger large = ((NSInteger)1 << 55) + 19;
    [MemoryPreferences setInteger:large forKey:@"integer"];
    CHECK([MemoryPreferences integerForKey:@"integer"] == large);
    double value = 1.234567890123;
    [MemoryPreferences setFloat:value forKey:@"float"];
    CHECK(memoryPreferences.receivedFloat == (float)value);
    CHECK([MemoryPreferences floatForKey:@"float"] == (double)(float)value);
    CHECK([MemoryPreferences floatForKey:@"float"] != value);
    [MemoryPreferences resetUserDefaults];
    CHECK([memoryPreferences.removedDomain isEqual:@"com.dvntm.ytlite"] && memoryPreferences.memory.count == 0);
    CHECK(memoryPreferences.registered.count == 49 && [memoryPreferences boolForKey:@"noAds"]);
}

static NSURL *writePlist(id object, NSString *path) {
    NSError *error = nil;
    NSData *data = [NSPropertyListSerialization dataWithPropertyList:object format:NSPropertyListBinaryFormat_v1_0 options:0 error:&error];
    CHECK(data != nil && error == nil);
    CHECK([data writeToFile:path options:NSDataWritingAtomic error:&error] && error == nil);
    return [NSURL fileURLWithPath:path];
}

static void testPickerAndImport(NSString *workDirectory) {
    presenter = [UIViewController new];
    __block BOOL selected = NO;
    __weak id weakCapture;
    @autoreleasepool {
        id capture = [NSObject new]; weakCapture = capture;
        [memoryPreferences presentDocumentPicker:^(NSURL *url) { (void)[capture description]; selected = YES; }];
    }
    CHECK(weakCapture != nil);
    UIDocumentPickerViewController *picker = (id)presenter.recoveredPresentedController;
    CHECK([picker isKindOfClass:[UIDocumentPickerViewController class]]);
    CHECK([picker.recoveredDocumentTypes isEqual:@[@"com.apple.property-list"]]);
    CHECK(picker.recoveredMode == UIDocumentPickerModeImport && !picker.allowsMultipleSelection);
    CHECK(picker.delegate == memoryPreferences && presenter.recoveredPresentedAnimated);
    [memoryPreferences documentPicker:picker didPickDocumentAtURL:[NSURL fileURLWithPath:workDirectory]];
    CHECK(selected && memoryPreferences.prefsPickerCompletion != nil);
    memoryPreferences.prefsPickerCompletion = nil;
    CHECK(weakCapture == nil);

    __block NSUInteger calls = 0;
    __block BOOL success = YES;
    presenter.recoveredOnPresentation = ^(UIViewController *controller) {
        CHECK(memoryPreferences.prefsPickerCompletion == nil);
    };
    [MemoryPreferences importYtlSettings:^(BOOL result) { calls++; success = result; }];
    presenter.recoveredOnPresentation = nil;
    CHECK(calls == 0 && memoryPreferences.prefsPickerCompletion != nil);
    memoryPreferences.prefsPickerCompletion(nil);
    CHECK(calls == 1 && !success && memoryPreferences.synchronizations == 0);
    memoryPreferences.prefsPickerCompletion([NSURL fileURLWithPath:[workDirectory stringByAppendingPathComponent:@"missing.plist"]]);
    CHECK(calls == 2 && !success && memoryPreferences.synchronizations == 0);
    NSString *path = [workDirectory stringByAppendingPathComponent:@"import-fixture.plist"];
    CHECK([@"not a property list" writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:NULL]);
    memoryPreferences.prefsPickerCompletion([NSURL fileURLWithPath:path]);
    CHECK(calls == 3 && !success && memoryPreferences.synchronizations == 0);
    memoryPreferences.prefsPickerCompletion(writePlist(@[@"not", @"a dictionary"], path));
    CHECK(calls == 4 && !success && memoryPreferences.synchronizations == 0);
    NSDictionary *settings = @{@"flag": @YES, @"large": @(((NSInteger)1 << 50) + 9), @"data": [@"bytes" dataUsingEncoding:NSUTF8StringEncoding]};
    memoryPreferences.prefsPickerCompletion(writePlist(settings, path));
    CHECK(calls == 5 && success && memoryPreferences.synchronizations == 1);
    for (NSString *key in settings) CHECK([[memoryPreferences objectForKey:key] isEqual:settings[key]]);
    memoryPreferences.rejectedKey = @"reject";
    memoryPreferences.prefsPickerCompletion(writePlist(@{@"reject": @1}, path));
    CHECK(calls == 6 && !success && memoryPreferences.synchronizations == 2);
    CHECK([memoryPreferences objectForKey:@"reject"] == nil);
    CHECK([[memoryPreferences objectForKey:@"large"] isEqual:settings[@"large"]]);
    memoryPreferences.rejectedKey = nil;
    memoryPreferences.prefsPickerCompletion(writePlist(@{}, path));
    CHECK(calls == 7 && success && memoryPreferences.synchronizations == 3);
    // synchronize returns NO in this fixture: the package ignores that value.
    CHECK(memoryPreferences.prefsPickerCompletion != nil);
    memoryPreferences.prefsPickerCompletion = nil;
}

static void testExport(void) {
    UIView *source = [UIView new];
    source.bounds = CGRectMake(10, 20, 120.25, 34);
    [MemoryPreferences exportYtlSettings:source];
    UIActivityViewController *activity = (id)presenter.recoveredPresentedController;
    CHECK([activity isKindOfClass:[UIActivityViewController class]] && presenter.recoveredPresentedAnimated);
    CHECK(activity.recoveredActivityItems.count == 1 && activity.recoveredApplicationActivities == nil);
    CHECK([[activity.recoveredActivityItems[0] path] hasSuffix:@"/Library/Preferences/com.dvntm.ytlite.plist"]);
    CHECK([activity.excludedActivityTypes isEqual:@[UIActivityTypeAssignToContact, UIActivityTypePrint]]);
    UIPopoverPresentationController *popover = activity.popoverPresentationController;
    CHECK(popover.sourceView == source && popover.permittedArrowDirections == UIPopoverArrowDirectionUp);
    CHECK(popover.sourceRect.origin.x == 115.25 && popover.sourceRect.origin.y == 0);
    CHECK(popover.sourceRect.size.width == 1 && popover.sourceRect.size.height == 1);
}

NSUInteger runPreferenceTests(NSString *evidenceDirectory, NSString *workDirectory) {
    testIDsAndDefaults(evidenceDirectory, workDirectory);
    testPickerAndImport(workDirectory);
    testExport();
    presenter = nil; memoryPreferences = nil; randomFixture = nil;
    return checks;
}
