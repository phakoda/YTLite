#import "YTLUserDefaults.h"
#import <UIKit/UIKit.h>
#import <Security/Security.h>
#import <CommonCrypto/CommonDigest.h>
#import "../recovery/source/Support/YTLRecoveredDefaults.h"

@protocol YTLPreferencesHostUI <NSObject>
+ (UIViewController *)topViewControllerForPresenting;
@end

#include "../recovery/source/Support/YTLSegmentColors.inc"

@implementation YTLUserDefaults

static NSString *const kDefaultsSuiteName = @"com.dvntm.ytlite";

+ (YTLUserDefaults *)standardUserDefaults {
    static dispatch_once_t onceToken;
    static YTLUserDefaults *defaults = nil;

    dispatch_once(&onceToken, ^{
        defaults = [[self alloc] initWithSuiteName:kDefaultsSuiteName];
        [defaults registerDefaults];
    });

    return defaults;
}

- (void)reset {
    [self removePersistentDomainForName:kDefaultsSuiteName];
}

- (void)registerDefaults {
    [self registerDefaults:YTLRecoveredDefaultValues(self)];
    [self registerDefaults:@{@"rememberPlaybackSpeed": @YES, @"dontEatMyContent": @YES}];
}

// -[YTLUserDefaults colorForSegment:], 0x1eb10c. The stored preference is
// archived NSData, not the UIColor itself. Unknown names produce nil.
- (NSData *)colorForSegment:(NSString *)segment {
    UIColor *color = YTLSegmentColors()[segment];
    return color ? [NSKeyedArchiver archivedDataWithRootObject:color requiringSecureCoding:NO error:NULL] : nil;
}

// -[YTLUserDefaults sbPrivateUserID], 0x1ebdbc. Preserve the package's
// byte-modulo-62 mapping, including its bias, rather than changing the format.
- (NSString *)sbPrivateUserID {
    unsigned char bytes[36];
    int status = SecRandomCopyBytes(kSecRandomDefault, sizeof(bytes), bytes);
    if (status != errSecSuccess) {
        NSLog(@"YTL --- failed to gen random bytes: %d", status);
        return nil;
    }
    static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    NSMutableString *identifier = [NSMutableString stringWithCapacity:sizeof(bytes)];
    for (NSUInteger index = 0; index < sizeof(bytes); index++) {
        [identifier appendFormat:@"%c", alphabet[bytes[index] % 62]];
    }
    return identifier;
}

// -[YTLUserDefaults sbPublicUserID:], 0x1ec5dc. Each round hashes the RAW
// previous digest. Hex encoding takes place only after all 5,000 rounds.
- (NSString *)sbPublicUserID:(NSString *)privateUserID {
    NSData *value = [privateUserID dataUsingEncoding:NSUTF8StringEncoding];
    unsigned char digest[CC_SHA256_DIGEST_LENGTH];
    for (NSUInteger round = 0; round < 5000; round++) {
        CC_SHA256(value.bytes, (CC_LONG)value.length, digest);
        value = [NSData dataWithBytes:digest length:sizeof(digest)];
    }
    NSMutableString *result = [NSMutableString stringWithCapacity:sizeof(digest) * 2];
    for (NSUInteger index = 0; index < sizeof(digest); index++) [result appendFormat:@"%02x", digest[index]];
    return result;
}

// 0x1ed5cc. The completion is copied AFTER presentation, as in the package.
- (void)presentDocumentPicker:(YTLPreferencesPickerCompletion)completion {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    UIDocumentPickerViewController *picker = [[UIDocumentPickerViewController alloc]
        initWithDocumentTypes:@[@"com.apple.property-list"] inMode:UIDocumentPickerModeImport];
#pragma clang diagnostic pop
    picker.delegate = (id<UIDocumentPickerDelegate>)self;
    picker.allowsMultipleSelection = NO;
    Class<YTLPreferencesHostUI> host = (Class<YTLPreferencesHostUI>)NSClassFromString(@"YTUIUtils");
    [[host topViewControllerForPresenting] presentViewController:picker animated:YES completion:nil];
    self.prefsPickerCompletion = completion;
}

// 0x1ed9d0. The callback remains stored; the package does not clear it here.
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentAtURL:(NSURL *)url {
    if (self.prefsPickerCompletion) self.prefsPickerCompletion(url);
}

// 0x1ec890 with selection block 0x1ec964 and enumeration block 0x1ed464.
// The latter's missing branch was checked at 0x1ed588: stop on read-back
// mismatch, synchronize, and report NO. Already-written keys are not rolled back.
+ (void)importYtlSettings:(YTLPreferencesImportCompletion)completion {
    [[self standardUserDefaults] presentDocumentPicker:^(NSURL *url) {
        if (!url) {
            NSLog(@"YTPlus --- No URL provided by document picker");
            completion(NO);
            return;
        }
        NSError *readError = nil;
        NSData *data = [NSData dataWithContentsOfURL:url options:0 error:&readError];
        if (readError) {
            NSLog(@"YTPlus --- Error reading data from URL: %@", readError);
            completion(NO);
            return;
        }
        NSError *parseError = nil;
        id settings = [NSPropertyListSerialization propertyListWithData:data options:0 format:NULL error:&parseError];
        if (parseError || ![settings isKindOfClass:[NSDictionary class]]) {
            NSLog(@"YTPlus --- Error parsing plist data: %@", parseError);
            completion(NO);
            return;
        }
        __block BOOL success = YES;
        [settings enumerateKeysAndObjectsUsingBlock:^(id key, id value, BOOL *stop) {
            [[self standardUserDefaults] setObject:value forKey:key];
            if (![[[self standardUserDefaults] objectForKey:key] isEqual:value]) {
                success = NO;
                *stop = YES;
            }
        }];
        [[self standardUserDefaults] synchronize];
        completion(success);
    }];
}

// 0x1edac4. This shares the actual suite plist rather than exporting registration
// defaults or manufacturing a merged dictionary. Popover x is width minus five.
+ (void)exportYtlSettings:(UIView *)sourceView {
    NSURL *library = [[[NSFileManager defaultManager] URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask] firstObject];
    NSURL *file = [library URLByAppendingPathComponent:@"Preferences/com.dvntm.ytlite.plist"];
    UIActivityViewController *activity = [[UIActivityViewController alloc] initWithActivityItems:@[file] applicationActivities:nil];
    activity.excludedActivityTypes = @[UIActivityTypeAssignToContact, UIActivityTypePrint];
    Class<YTLPreferencesHostUI> host = (Class<YTLPreferencesHostUI>)NSClassFromString(@"YTUIUtils");
    UIViewController *presenter = [host topViewControllerForPresenting];
    if (activity.popoverPresentationController) {
        activity.popoverPresentationController.sourceView = sourceView;
        activity.popoverPresentationController.sourceRect = CGRectMake(sourceView.bounds.size.width - 5, 0, 1, 1);
        activity.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionUp;
    }
    [presenter presentViewController:activity animated:YES completion:nil];
}

+ (void)resetUserDefaults {
    [[self standardUserDefaults] reset];
}

+ (BOOL)boolForKey:(NSString *)key {
    return [[self standardUserDefaults] boolForKey:key];
}

+ (NSInteger)integerForKey:(NSString *)key {
    return [[self standardUserDefaults] integerForKey:key];
}

+ (double)floatForKey:(NSString *)key {
    return [[self standardUserDefaults] floatForKey:key];
}

+ (void)setBool:(BOOL)value forKey:(NSString *)key {
    [[self standardUserDefaults] setBool:value forKey:key];
}

+ (void)setInteger:(NSInteger)value forKey:(NSString *)key {
    [[self standardUserDefaults] setInteger:value forKey:key];
}

+ (void)setFloat:(double)value forKey:(NSString *)key {
    [[self standardUserDefaults] setFloat:(float)value forKey:key];
}

@end
