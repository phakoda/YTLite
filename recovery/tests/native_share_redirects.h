#import <Foundation/Foundation.h>
@interface NativeShareFixtureDefaults : NSObject
- (instancetype)initWithSuiteName:(NSString *)suite;
- (BOOL)boolForKey:(NSString *)key;
@end
#define NSUserDefaults NativeShareFixtureDefaults
