#import "YTLBootstrapCrypto.h"
#import "YTLCommonCryptoContract.h"
#import <CommonCrypto/CommonKeyDerivation.h>
#import <Security/Security.h>
#include <string.h>
#include <stdlib.h>

#include "YTLBootstrapConstants.inc"

// 0x27838. The once-initialized string in the package has been recovered to a
// literal from both byte-XOR stages, not replaced with a new derivation secret.
BOOL YTLBootstrapDeriveKey(NSString *password, NSData *salt, unsigned char output[32]) {
    NSString *combined = [NSString stringWithFormat:YTLBootstrapPasswordFormat, password, YTLBootstrapPepper];
    NSData *utf8 = [combined dataUsingEncoding:NSUTF8StringEncoding];
    return CCKeyDerivationPBKDF(kCCPBKDF2, utf8.bytes, utf8.length,
        salt.bytes, salt.length, kCCPRFHmacAlgSHA256, 10000, output, 32) == kCCSuccess;
}

// 0x27464: [salt:16][nonce:12][tag:16][ciphertext:at least 1], Base64 encoded.
// Preserve the strict minimum of 45 bytes; an empty authenticated payload is
// rejected here even though the underlying cipher can represent one.
NSString *YTLBootstrapDecrypt(NSString *encodedRecord, NSString *password) {
    if (!password) return nil;
    NSData *record = [[NSData alloc] initWithBase64EncodedString:encodedRecord options:0];
    if (!record || record.length < 45) return nil;
    NSData *salt = [record subdataWithRange:NSMakeRange(0, 16)];
    NSData *nonce = [record subdataWithRange:NSMakeRange(16, 12)];
    NSData *expectedTag = [record subdataWithRange:NSMakeRange(28, 16)];
    NSData *ciphertext = [record subdataWithRange:NSMakeRange(44, record.length - 44)];
    unsigned char key[32];
    if (!YTLBootstrapDeriveKey(password, salt, key)) return nil;
    NSMutableData *plaintext = [NSMutableData dataWithLength:ciphertext.length];
    unsigned char tag[16];
    size_t tagLength = sizeof(tag);
    CCCryptorStatus status = CCCryptorGCM(kCCDecrypt, kCCAlgorithmAES,
        key, sizeof(key), nonce.bytes, nonce.length, NULL, 0,
        ciphertext.bytes, ciphertext.length, plaintext.mutableBytes, tag, &tagLength);
    // The package clears the derived key after the cipher call, including its
    // error path. Use a volatile write so optimization cannot remove this.
    volatile unsigned char *clear = key;
    for (NSUInteger index = 0; index < sizeof(key); index++) clear[index] = 0;
    if (status != kCCSuccess || memcmp(tag, expectedTag.bytes, sizeof(tag)) != 0) return nil;
    return [[NSString alloc] initWithData:plaintext encoding:NSUTF8StringEncoding];
}

// 0x28ec0. The packaged writer uses arc4random_buf (which has no error result),
// not SecRandomCopyBytes. Salt and nonce are generated in two separate calls.
// Unlike the decoder's minimum-length check, this permits an empty plaintext.
NSString *YTLBootstrapEncrypt(NSString *plaintext, NSString *password) {
    if (!password) return nil;
    unsigned char salt[16], nonce[12], key[32], tag[16];
    arc4random_buf(salt, sizeof(salt));
    arc4random_buf(nonce, sizeof(nonce));
    NSData *saltData = [NSData dataWithBytes:salt length:sizeof(salt)];
    NSData *nonceData = [NSData dataWithBytes:nonce length:sizeof(nonce)];
    if (!YTLBootstrapDeriveKey(password, saltData, key)) return nil;
    NSData *input = [plaintext dataUsingEncoding:NSUTF8StringEncoding];
    NSMutableData *ciphertext = [NSMutableData dataWithLength:input.length];
    size_t tagLength = sizeof(tag);
    CCCryptorStatus status = CCCryptorGCM(kCCEncrypt, kCCAlgorithmAES,
        key, sizeof(key), nonceData.bytes, nonceData.length, NULL, 0,
        input.bytes, input.length, ciphertext.mutableBytes, tag, &tagLength);
    volatile unsigned char *clear = key;
    for (NSUInteger index = 0; index < sizeof(key); index++) clear[index] = 0;
    if (status != kCCSuccess) return nil;
    NSMutableData *record = [NSMutableData data];
    [record appendData:saltData];
    [record appendData:nonceData];
    [record appendBytes:tag length:sizeof(tag)];
    [record appendData:ciphertext];
    return [record base64EncodedStringWithOptions:0];
}

// 0x27078. Read one generic-password record using the original service/account.
// CFBridgingRelease consumes the retained object returned by SecItemCopyMatching.
NSString *YTLBootstrapReadCredential(NSString *account, NSString *password) {
    NSDictionary *query = @{(__bridge id)kSecClass: (__bridge id)kSecClassGenericPassword,
                            (__bridge id)kSecAttrService: @"com.dvntm.ytplus",
                            (__bridge id)kSecAttrAccount: account,
                            (__bridge id)kSecReturnData: @YES,
                            (__bridge id)kSecMatchLimit: (__bridge id)kSecMatchLimitOne};
    CFTypeRef value = NULL;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)query, &value);
    if (status != errSecSuccess) return nil;
    NSData *data = CFBridgingRelease(value);
    NSString *encodedRecord = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    return YTLBootstrapDecrypt(encodedRecord, password);
}

// 0x27ff4. This deletes only the supplied account, not all service entries.
void YTLBootstrapDeleteCredential(NSString *account) {
    NSDictionary *query = @{(__bridge id)kSecClass: (__bridge id)kSecClassGenericPassword,
                            (__bridge id)kSecAttrService: @"com.dvntm.ytplus",
                            (__bridge id)kSecAttrAccount: account};
    (void)SecItemDelete((__bridge CFDictionaryRef)query);
}

// 0x28954. The SAME five-entry dictionary is sent to SecItemDelete and
// SecItemAdd, including value/accessibility. Preserve that unusual matching
// behavior rather than quietly substituting an update or a reduced delete.
// The return statuses only feed unreachable diagnostic branches in the package
// (0x28cbc returns zero); this function itself has no success return value.
void YTLBootstrapWriteCredential(NSString *account, NSString *plaintext, NSString *password) {
    NSString *encoded = YTLBootstrapEncrypt(plaintext, password);
    if (!encoded) return;
    NSData *data = [encoded dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *query = @{(__bridge id)kSecClass: (__bridge id)kSecClassGenericPassword,
                            (__bridge id)kSecAttrService: @"com.dvntm.ytplus",
                            (__bridge id)kSecAttrAccount: account,
                            (__bridge id)kSecValueData: data,
                            (__bridge id)kSecAttrAccessible: (__bridge id)kSecAttrAccessibleAfterFirstUnlock};
    (void)SecItemDelete((__bridge CFDictionaryRef)query);
    (void)SecItemAdd((__bridge CFDictionaryRef)query, NULL);
}

// A narrow messaging contract avoids redefining any UIKit host class. Foundation
// tests provide a UIDevice double; production messages the real UIKit class.
@protocol YTLBootstrapDeviceContract <NSObject>
+ (id<YTLBootstrapDeviceContract>)currentDevice;
- (NSUUID *)identifierForVendor;
@end

// 0x287c0.
NSString *YTLBootstrapDeviceIdentifier(void) {
    Class<YTLBootstrapDeviceContract> device = (Class<YTLBootstrapDeviceContract>)NSClassFromString(@"UIDevice");
    return [[[device currentDevice] identifierForVendor] UUIDString] ?: @"unknown";
}

// 0x236c0. The second credential is encrypted using the recovered device ID,
// not the vendor UUID directly. No JWT signature or expiration test is added:
// those would be new behavior not present in this local lookup helper.
NSString *YTLBootstrapCurrentToken(void) {
    NSString *deviceID = YTLBootstrapReadCredential(@"deviceId", YTLBootstrapDeviceIdentifier());
    return deviceID ? YTLBootstrapReadCredential(@"jwt", deviceID) : nil;
}

// 0x239c8, originally two byte globals at 0x1225d48/49. Initialization is cached,
// including a negative result. The package does not use dispatch_once here.
static BOOL authorizationComputed;
static BOOL authorizationResult;
static BOOL featuresSuspended; // packaged byte 0x1225d11; defaults to zero
BOOL YTLBootstrapIsAuthorized(void) {
    if (authorizationComputed) return authorizationResult;
    authorizationResult = YTLBootstrapCurrentToken() != nil;
    authorizationComputed = YES;
    return authorizationResult;
}

void YTLBootstrapInvalidateAuthorizationCache(void) { authorizationComputed = NO; }
void YTLBootstrapSetFeatureSuspension(BOOL suspended) { featuresSuspended = suspended; }
BOOL YTLBootstrapFeaturesSuspended(void) { return featuresSuspended; }

// Feature reads live in YTLFeaturePolicy.m and deliberately do not consult any
// of this historical credential state. This file is not a production input.

#ifdef YTL_BOOTSTRAP_TESTING
// Test-only state reset; this symbol is absent from production objects.
void YTLBootstrapTestResetCache(void) { authorizationComputed = NO; authorizationResult = NO; }
#endif
