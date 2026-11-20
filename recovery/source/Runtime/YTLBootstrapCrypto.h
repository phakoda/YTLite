#import <Foundation/Foundation.h>
#import "YTLFeaturePolicy.h"

/// Historical credential-format helpers, retained for offline recovery tests.
/// Not included in the local-only production build; not a feature prerequisite.
FOUNDATION_EXPORT BOOL YTLBootstrapDeriveKey(NSString *password, NSData *salt, unsigned char output[32]);
FOUNDATION_EXPORT NSString *YTLBootstrapDecrypt(NSString *encodedRecord, NSString *password);
FOUNDATION_EXPORT NSString *YTLBootstrapEncrypt(NSString *plaintext, NSString *password);
FOUNDATION_EXPORT NSString *YTLBootstrapReadCredential(NSString *account, NSString *password);
FOUNDATION_EXPORT void YTLBootstrapWriteCredential(NSString *account, NSString *plaintext, NSString *password);
FOUNDATION_EXPORT void YTLBootstrapDeleteCredential(NSString *account);
FOUNDATION_EXPORT NSString *YTLBootstrapDeviceIdentifier(void);
FOUNDATION_EXPORT NSString *YTLBootstrapCurrentToken(void);
FOUNDATION_EXPORT BOOL YTLBootstrapIsAuthorized(void);
FOUNDATION_EXPORT void YTLBootstrapInvalidateAuthorizationCache(void);
FOUNDATION_EXPORT void YTLBootstrapSetFeatureSuspension(BOOL suspended);
FOUNDATION_EXPORT BOOL YTLBootstrapFeaturesSuspended(void);
