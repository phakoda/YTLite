#pragma once
#import <Foundation/Foundation.h>
#import <Security/Security.h>
#import <objc/runtime.h>
#include <dlfcn.h>
@interface SideloadIdentityBundle:NSObject
+ (instancetype)mainBundle;
+ (instancetype)ytl_defaultBundle;
- (NSString *)bundlePath;
- (NSString *)bundleIdentifier;
- (id)objectForInfoDictionaryKey:(NSString *)key;
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table;
@end
@interface SideloadIdentityThread:NSObject
+ (NSArray *)callStackReturnAddresses;
@end
FOUNDATION_EXPORT Class SideloadIdentityGetClass(const char *name);
FOUNDATION_EXPORT int SideloadIdentityDladdr(const void *address, Dl_info *info);
FOUNDATION_EXPORT OSStatus SideloadIdentityCopy(CFDictionaryRef query, CFTypeRef *result);
FOUNDATION_EXPORT OSStatus SideloadIdentityAdd(CFDictionaryRef query, CFTypeRef *result);
#define NSBundle SideloadIdentityBundle
#define NSThread SideloadIdentityThread
#define objc_getClass SideloadIdentityGetClass
#define dladdr SideloadIdentityDladdr
#define SecItemCopyMatching SideloadIdentityCopy
#define SecItemAdd SideloadIdentityAdd
