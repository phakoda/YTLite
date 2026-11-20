#import <Foundation/Foundation.h>
@interface YTLSideloadFixtureBundle : NSObject
+ (instancetype)mainBundle;
- (NSDictionary *)infoDictionary;
@end
Class YTLSideloadFixtureClass(NSString *name);
#define NSBundle YTLSideloadFixtureBundle
#define NSClassFromString YTLSideloadFixtureClass
