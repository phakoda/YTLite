#import <Foundation/Foundation.h>
@interface NSDate (PlayerLifecycleClock)
+ (instancetype)ytlFixtureDateWithTimeIntervalSinceNow:(NSTimeInterval)interval;
@end
#define dateWithTimeIntervalSinceNow ytlFixtureDateWithTimeIntervalSinceNow
