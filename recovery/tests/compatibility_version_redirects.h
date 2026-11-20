#import <Foundation/Foundation.h>
@class UIImage,UIColor;
@interface VersionFixtureBundle : NSObject
+ (instancetype)mainBundle;
- (id)objectForInfoDictionaryKey:(NSString *)key;
- (NSDictionary *)infoDictionary;
@end
#define NSBundle VersionFixtureBundle
