#import "presentation_redirects.h"
@interface ConstructionNotificationCenter : NSObject
+ (instancetype)defaultCenter;
- (void)addObserver:(id)observer selector:(SEL)selector name:(NSString *)name object:(id)object;
- (void)removeObserver:(id)observer name:(NSString *)name object:(id)object;
@end
#define NSNotificationCenter ConstructionNotificationCenter
