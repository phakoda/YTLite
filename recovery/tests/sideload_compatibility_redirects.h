#import <Foundation/Foundation.h>
#import <objc/runtime.h>
// Fixture-only redirects keep Foundation's file manager unmodified.
NS_ASSUME_NONNULL_BEGIN
@interface SideloadFixtureFileManager : NSFileManager
+ (instancetype)defaultManager;
- (nullable NSURL *)containerURLForSecurityApplicationGroupIdentifier:(nullable NSString *)group;
@end
@interface SideloadFixtureRequest : NSObject
+ (nullable NSDictionary *)ak_clientInfoHeader;
- (nullable NSDictionary *)allHTTPHeaderFields;
@end
FOUNDATION_EXPORT Class _Nullable SideloadFixtureGetClass(const char *name);
NS_ASSUME_NONNULL_END
#define NSFileManager SideloadFixtureFileManager
#define NSMutableURLRequest SideloadFixtureRequest
#define LSApplicationProxy SideloadFixtureApplicationProxy
#define LSBundleProxy SideloadFixtureBundleProxy
#define objc_getClass SideloadFixtureGetClass
