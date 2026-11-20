#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <CommonCrypto/CommonKeyDerivation.h>
#import <objc/runtime.h>
#import "../source/Runtime/YTLBootstrapCrypto.h"
#import "../source/Runtime/YTLCommonCryptoContract.h"
#import "../../Utils/YTLUserDefaults.h"

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)
extern void YTLBootstrapTestResetCache(void);

static NSMutableDictionary<NSString *, NSData *> *keychain;
static NSMutableArray<NSDictionary *> *queries;
static OSStatus queryStatus = errSecSuccess;
static int derivationStatus;
static CCCryptorStatus cipherStatus;
static NSUInteger derivationCalls, cipherCalls, preferenceReads, preferenceLookups;
static NSUInteger randomCalls;
static OSStatus addStatus;
static NSMutableArray<NSString *> *keychainOperations;

void YTLTestArc4RandomBuf(void *output, size_t count) {
    CHECK(output != NULL && (count == 16 || count == 12));
    CHECK(count == (randomCalls % 2 == 0 ? 16u : 12u));
    unsigned char *bytes = output;
    for (size_t index = 0; index < count; index++) bytes[index] = (unsigned char)(index + (count == 12 ? 32 : 0));
    randomCalls++;
}

// Only the production source object is compiled with these symbol redirects.
// This fixture object calls the actual CommonCrypto symbols, so successful test
// decryption is not a test-double implementation of the cryptographic algorithm.
int YTLTestDeriveKey(CCPBKDFAlgorithm algorithm, const char *password, size_t passwordLength,
                   const uint8_t *salt, size_t saltLength, CCPseudoRandomAlgorithm prf,
                   unsigned int rounds, uint8_t *output, size_t outputLength) {
    CHECK(algorithm == kCCPBKDF2 && prf == kCCPRFHmacAlgSHA256 && rounds == 10000 && outputLength == 32);
    derivationCalls++;
    if (derivationStatus) return derivationStatus;
    return CCKeyDerivationPBKDF(algorithm, password, passwordLength, salt, saltLength, prf, rounds, output, outputLength);
}
CCCryptorStatus YTLTestCryptorGCM(CCOperation operation, CCAlgorithm algorithm, const void *key, size_t keyLength,
    const void *nonce, size_t nonceLength, const void *additional, size_t additionalLength,
    const void *input, size_t inputLength, void *output, void *tag, size_t *tagLength) {
    CHECK((operation == kCCDecrypt || operation == kCCEncrypt) && algorithm == kCCAlgorithmAES && keyLength == 32);
    CHECK(nonceLength == 12 && additional == NULL && additionalLength == 0 && *tagLength == 16);
    CHECK(key && nonce && tag);
    if (inputLength) CHECK(input && output);
    if (operation == kCCDecrypt) CHECK(inputLength >= 1);
    cipherCalls++;
    if (cipherStatus) return cipherStatus;
    return CCCryptorGCM(operation, algorithm, key, keyLength, nonce, nonceLength,
        additional, additionalLength, input, inputLength, output, tag, tagLength);
}
OSStatus YTLTestSecItemCopyMatching(CFDictionaryRef reference, CFTypeRef *result) {
    NSDictionary *query = (__bridge NSDictionary *)reference;
    CHECK(query.count == 5);
    CHECK([query[(__bridge id)kSecClass] isEqual:(__bridge id)kSecClassGenericPassword]);
    CHECK([query[(__bridge id)kSecAttrService] isEqual:@"com.dvntm.ytplus"]);
    CHECK([query[(__bridge id)kSecReturnData] isEqual:@YES]);
    CHECK([query[(__bridge id)kSecMatchLimit] isEqual:(__bridge id)kSecMatchLimitOne]);
    CHECK(result != NULL && *result == NULL);
    [queries addObject:query];
    if (queryStatus != errSecSuccess) return queryStatus;
    NSData *data = keychain[query[(__bridge id)kSecAttrAccount]];
    if (!data) return errSecItemNotFound;
    *result = CFBridgingRetain(data);
    return errSecSuccess;
}
OSStatus YTLTestSecItemDelete(CFDictionaryRef reference) {
    NSDictionary *query = (__bridge NSDictionary *)reference;
    CHECK(query.count == 3 || query.count == 5);
    CHECK([query[(__bridge id)kSecClass] isEqual:(__bridge id)kSecClassGenericPassword]);
    CHECK([query[(__bridge id)kSecAttrService] isEqual:@"com.dvntm.ytplus"]);
    [queries addObject:query];
    [keychainOperations addObject:@"delete"];
    [keychain removeObjectForKey:query[(__bridge id)kSecAttrAccount]];
    return errSecInteractionNotAllowed; // the package ignores this status
}
OSStatus YTLTestSecItemAdd(CFDictionaryRef reference, CFTypeRef *result) {
    NSDictionary *query = (__bridge NSDictionary *)reference;
    CHECK(query.count == 5 && result == NULL);
    CHECK([query[(__bridge id)kSecClass] isEqual:(__bridge id)kSecClassGenericPassword]);
    CHECK([query[(__bridge id)kSecAttrService] isEqual:@"com.dvntm.ytplus"]);
    CHECK([query[(__bridge id)kSecAttrAccessible] isEqual:(__bridge id)kSecAttrAccessibleAfterFirstUnlock]);
    CHECK([query[(__bridge id)kSecValueData] isKindOfClass:[NSData class]]);
    CHECK([queries.lastObject isEqual:query]); // exact same dictionary used for deletion
    [queries addObject:query];
    [keychainOperations addObject:@"add"];
    if (addStatus == errSecSuccess) keychain[query[(__bridge id)kSecAttrAccount]] = query[(__bridge id)kSecValueData];
    return addStatus;
}

static NSUUID *vendor;
@interface UIDevice : NSObject
+ (instancetype)currentDevice;
- (NSUUID *)identifierForVendor;
@end
@implementation UIDevice
+ (instancetype)currentDevice { static UIDevice *device; if (!device) device = [self new]; return device; }
- (NSUUID *)identifierForVendor { return vendor; }
@end
@interface PreferenceDouble : NSObject
- (BOOL)boolForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
@end
@implementation PreferenceDouble
- (BOOL)boolForKey:(NSString *)key { preferenceReads++; return [key isEqual:@"enabled"]; }
- (NSInteger)integerForKey:(NSString *)key {
    preferenceReads++;
    return [key isEqual:@"large"] ? ((NSInteger)1 << 55) + 27 : -((NSInteger)1 << 40);
}
@end
static PreferenceDouble *preferences;
static id replacementPreferences(id receiver, SEL selector) { preferenceLookups++; return preferences; }

static NSData *unhex(NSString *hex) {
    CHECK(hex.length % 2 == 0);
    NSMutableData *bytes = [NSMutableData data];
    for (NSUInteger index = 0; index < hex.length; index += 2) {
        unsigned int number = 0;
        CHECK([[NSScanner scannerWithString:[hex substringWithRange:NSMakeRange(index, 2)]] scanHexInt:&number]);
        unsigned char byte = number;
        [bytes appendBytes:&byte length:1];
    }
    return bytes;
}
static NSDictionary *recordNamed(NSDictionary *fixture, NSString *name) {
    for (NSDictionary *record in fixture[@"records"]) if ([record[@"name"] isEqual:name]) return record;
    CHECK(NO); return nil;
}
static void storeRecord(NSString *name, NSDictionary *record) {
    keychain[name] = [record[@"encoded"] dataUsingEncoding:NSUTF8StringEncoding];
}

static void testDerivationAndDecryption(NSDictionary *fixtures) {
    for (NSDictionary *vector in fixtures[@"derivations"]) {
        unsigned char key[32];
        NSString *password = vector[@"password"] == [NSNull null] ? nil : vector[@"password"];
        CHECK(YTLBootstrapDeriveKey(password, unhex(vector[@"salt"]), key));
        CHECK([[NSData dataWithBytes:key length:sizeof(key)] isEqual:unhex(vector[@"key"])]);
    }
    for (NSDictionary *record in fixtures[@"records"]) {
        NSData *plain = [[NSData alloc] initWithBase64EncodedString:record[@"plaintext_base64"] options:0];
        NSString *expected = plain.length ? [[NSString alloc] initWithData:plain encoding:NSUTF8StringEncoding] : nil;
        NSString *actual = YTLBootstrapDecrypt(record[@"encoded"], record[@"password"]);
        CHECK(actual == expected || [actual isEqual:expected]);
    }
    NSDictionary *valid = recordNamed(fixtures, @"token");
    NSString *encoded = valid[@"encoded"], *password = valid[@"password"];
    CHECK(YTLBootstrapDecrypt(encoded, @"incorrect password") == nil);
    CHECK(YTLBootstrapDecrypt(encoded, nil) == nil);
    CHECK(YTLBootstrapDecrypt(@"not base64 !!!", password) == nil);
    CHECK(YTLBootstrapDecrypt([encoded stringByAppendingString:@"\n"], password) == nil);
    NSData *bytes = [[NSData alloc] initWithBase64EncodedString:encoded options:0];
    NSUInteger prior = derivationCalls;
    for (NSUInteger length = 0; length <= 44; length++) {
        CHECK(YTLBootstrapDecrypt([[bytes subdataWithRange:NSMakeRange(0, length)] base64EncodedStringWithOptions:0], password) == nil);
    }
    CHECK(derivationCalls == prior);
    // Exercise salt, nonce, authentication-tag and ciphertext corruption.
    for (NSUInteger index = 0; index < bytes.length; index++) {
        NSMutableData *corrupted = [bytes mutableCopy];
        ((unsigned char *)corrupted.mutableBytes)[index] ^= 1;
        CHECK(YTLBootstrapDecrypt([corrupted base64EncodedStringWithOptions:0], password) == nil);
    }
    derivationStatus = kCCParamError;
    prior = cipherCalls;
    CHECK(YTLBootstrapDecrypt(encoded, password) == nil && cipherCalls == prior);
    derivationStatus = 0;
    cipherStatus = kCCUnspecifiedError;
    CHECK(YTLBootstrapDecrypt(encoded, password) == nil);
    cipherStatus = 0;
}

static void testCredentialLookupAndGate(NSDictionary *fixtures) {
    keychain = [NSMutableDictionary dictionary]; queries = [NSMutableArray array];
    preferences = [PreferenceDouble new];
    Method getter = class_getClassMethod([YTLUserDefaults class], @selector(standardUserDefaults));
    IMP original = method_setImplementation(getter, (IMP)replacementPreferences);
    @try {
        vendor = [[NSUUID alloc] initWithUUIDString:fixtures[@"vendor"]];
        CHECK([YTLBootstrapDeviceIdentifier() isEqual:fixtures[@"vendor"]]);
        CHECK(YTLBootstrapReadCredential(@"missing", @"password") == nil);
        CHECK(queries.count == 1);
        CHECK(YTLBootstrapCurrentToken() == nil && queries.count == 2); // no JWT lookup without deviceId
        [queries removeAllObjects];
        YTLBootstrapTestResetCache();
        CHECK(ytpBool(@"enabled") && !ytpBool(@"disabled"));
        CHECK(ytpInt(@"large") == ((NSInteger)1 << 55) + 27);
        CHECK(queries.count == 0 && preferenceLookups == 3 && preferenceReads == 3);
        CHECK(!YTLBootstrapIsAuthorized() && queries.count == 1);
        storeRecord(@"deviceId", recordNamed(fixtures, @"device-id"));
        storeRecord(@"jwt", recordNamed(fixtures, @"token"));
        CHECK(!YTLBootstrapIsAuthorized() && queries.count == 1); // negative authorization is cached
        YTLBootstrapTestResetCache();
        CHECK(YTLBootstrapIsAuthorized());
        CHECK(queries.count == 3);
        CHECK([queries[1][(__bridge id)kSecAttrAccount] isEqual:@"deviceId"]);
        CHECK([queries[2][(__bridge id)kSecAttrAccount] isEqual:@"jwt"]);
        CHECK(ytpBool(@"enabled") && !ytpBool(@"disabled"));
        CHECK(queries.count == 3 && preferenceLookups == 5 && preferenceReads == 5);
        CHECK(ytpInt(@"large") == ((NSInteger)1 << 55) + 27);
        CHECK(ytpInt(@"negative") == -((NSInteger)1 << 40));
        NSUInteger reads = preferenceReads, lookups = preferenceLookups;
        YTLBootstrapSetFeatureSuspension(YES);
        CHECK(YTLBootstrapFeaturesSuspended() && YTLBootstrapIsAuthorized());
        CHECK(ytpBool(@"enabled") && ytpInt(@"large") == ((NSInteger)1 << 55) + 27);
        CHECK(preferenceReads == reads + 2 && preferenceLookups == lookups + 2 && queries.count == 3);
        YTLBootstrapSetFeatureSuspension(NO);
        CHECK(!YTLBootstrapFeaturesSuspended() && ytpBool(@"enabled"));
        YTLBootstrapDeleteCredential(@"jwt");
        CHECK(keychain[@"deviceId"] != nil && keychain[@"jwt"] == nil);
        CHECK(YTLBootstrapIsAuthorized()); // deletion does not invalidate the cache in this helper
        YTLBootstrapTestResetCache();
        CHECK(!YTLBootstrapIsAuthorized());
        reads = preferenceReads; lookups = preferenceLookups;
        NSUInteger queriesBefore = queries.count;
        CHECK(ytpBool(@"enabled") && ytpInt(@"large") == ((NSInteger)1 << 55) + 27);
        CHECK(preferenceReads == reads + 2 && preferenceLookups == lookups + 2);
        CHECK(queries.count == queriesBefore);
        storeRecord(@"jwt", recordNamed(fixtures, @"token"));
        CHECK([YTLBootstrapCurrentToken() isEqual:@"fixture.jwt.value"]);
        queryStatus = errSecInteractionNotAllowed;
        CHECK(YTLBootstrapReadCredential(@"jwt", @"fixture-device-id") == nil);
        queriesBefore = queries.count;
        YTLBootstrapInvalidateAuthorizationCache();
        YTLBootstrapSetFeatureSuspension(YES);
        CHECK(ytpBool(@"enabled") && !ytpBool(@"disabled"));
        CHECK(ytpInt(@"negative") == -((NSInteger)1 << 40));
        CHECK(queries.count == queriesBefore); // no blocked-Keychain read from preferences
        queryStatus = errSecSuccess;
        vendor = nil;
        CHECK([YTLBootstrapDeviceIdentifier() isEqual:@"unknown"]);
        CHECK(YTLBootstrapCurrentToken() == nil); // UUID changed; cannot decrypt prior device ID
        storeRecord(@"deviceId", recordNamed(fixtures, @"unknown-device-id"));
        CHECK([YTLBootstrapCurrentToken() isEqual:@"fixture.jwt.value"]);
        // Success with invalid UTF-8 data follows Foundation's actual nil-input
        // behavior; the reconstruction deliberately does not invent a fallback.
        unsigned char invalid[] = {0xff, 0xfe};
        keychain[@"invalid"] = [NSData dataWithBytes:invalid length:sizeof(invalid)];
        BOOL raised = NO, expectedRaised = NO;
        id expected = nil;
        @try { expected = YTLBootstrapDecrypt(nil, @"x"); } @catch (NSException *exception) { expectedRaised = YES; }
        id actual = nil;
        @try { actual = YTLBootstrapReadCredential(@"invalid", @"x"); } @catch (NSException *exception) { raised = YES; }
        CHECK(raised == expectedRaised && (raised || actual == expected));
    } @finally {
        method_setImplementation(getter, original);
        YTLBootstrapTestResetCache();
        vendor = nil; preferences = nil; keychain = nil; queries = nil;
        YTLBootstrapSetFeatureSuspension(NO);
    }
}

static void testCredentialEncryptionAndStorage(NSDictionary *fixtures) {
    for (NSDictionary *record in fixtures[@"records"]) {
        NSData *bytes = [[NSData alloc] initWithBase64EncodedString:record[@"plaintext_base64"] options:0];
        NSString *plaintext = [[NSString alloc] initWithData:bytes encoding:NSUTF8StringEncoding];
        if (!plaintext && bytes.length) continue;
        NSUInteger before = randomCalls;
        NSString *encoded = YTLBootstrapEncrypt(plaintext, record[@"password"]);
        CHECK([encoded isEqual:record[@"encoded"]] && randomCalls == before + 2);
    }
    NSUInteger before = randomCalls;
    CHECK(YTLBootstrapEncrypt(@"text", nil) == nil && randomCalls == before);
    derivationStatus = kCCParamError;
    NSUInteger cipherBefore = cipherCalls;
    CHECK(YTLBootstrapEncrypt(@"text", @"password") == nil && cipherCalls == cipherBefore);
    derivationStatus = 0;
    cipherStatus = kCCUnspecifiedError;
    CHECK(YTLBootstrapEncrypt(@"text", @"password") == nil);
    cipherStatus = 0;
    keychain = [NSMutableDictionary dictionary];
    queries = [NSMutableArray array];
    keychainOperations = [NSMutableArray array];
    NSDictionary *record = recordNamed(fixtures, @"token");
    YTLBootstrapWriteCredential(@"jwt", @"fixture.jwt.value", record[@"password"]);
    CHECK([keychainOperations isEqual:@[@"delete", @"add"]]);
    CHECK([keychain[@"jwt"] isEqual:[record[@"encoded"] dataUsingEncoding:NSUTF8StringEncoding]]);
    CHECK([YTLBootstrapReadCredential(@"jwt", record[@"password"]) isEqual:@"fixture.jwt.value"]);
    NSUInteger count = queries.count;
    YTLBootstrapWriteCredential(@"jwt", @"new", nil);
    CHECK(queries.count == count && keychainOperations.count == 2);
    derivationStatus = kCCParamError;
    YTLBootstrapWriteCredential(@"jwt", @"new", @"password");
    CHECK(queries.count == count && keychainOperations.count == 2);
    derivationStatus = 0;
    addStatus = errSecDuplicateItem;
    YTLBootstrapWriteCredential(@"jwt", @"new", @"password");
    CHECK([keychainOperations isEqual:@[@"delete", @"add", @"delete", @"add"]]);
    CHECK(keychain[@"jwt"] == nil); // no rollback or retry on failed add
    addStatus = errSecSuccess;
    keychain = nil; queries = nil; keychainOperations = nil;
}

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        if (argc != 2) { fprintf(stderr, "usage: bootstrap-test fixtures.json\n"); return 2; }
        NSError *error = nil;
        NSData *data = [NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]] options:0 error:&error];
        CHECK(data != nil && error == nil);
        NSDictionary *fixtures = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
        CHECK(fixtures != nil && error == nil);
        testDerivationAndDecryption(fixtures);
        testCredentialLookupAndGate(fixtures);
        testCredentialEncryptionAndStorage(fixtures);
        printf("Historical crypto and local-only preference assertions passed: %lu.\n", (unsigned long)checks);
    }
    return 0;
}
