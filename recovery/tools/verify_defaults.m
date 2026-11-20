#import <Foundation/Foundation.h>
#import "../../Utils/YTLUserDefaults.h"

// Use an isolated suite so this check cannot change the user's tweak settings.
@interface RecoveryDefaults : YTLUserDefaults
@end
@implementation RecoveryDefaults
+ (YTLUserDefaults *)standardUserDefaults {
    static YTLUserDefaults *defaults;
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        NSString *suite = [@"ytlite.recovery.verification." stringByAppendingString:NSUUID.UUID.UUIDString];
        defaults = [[YTLUserDefaults alloc] initWithSuiteName:suite];
    });
    return defaults;
}
@end

int main(void) {
    @autoreleasepool {
        [RecoveryDefaults setBool:YES forKey:@"enabled"];
        NSCAssert([RecoveryDefaults boolForKey:@"enabled"], @"BOOL forwarding");
        [RecoveryDefaults setBool:NO forKey:@"enabled"];
        NSCAssert(![RecoveryDefaults boolForKey:@"enabled"], @"BOOL clearing");
        [RecoveryDefaults setInteger:((NSInteger)1 << 40) + 7 forKey:@"integer"];
        NSCAssert([RecoveryDefaults integerForKey:@"integer"] == ((NSInteger)1 << 40) + 7, @"64-bit integer forwarding");
        double input = 1.234567890123;
        [RecoveryDefaults setFloat:input forKey:@"rate"];
        NSCAssert([RecoveryDefaults floatForKey:@"rate"] == (double)(float)input, @"Recovered API narrows to float storage and returns double");
        for (NSString *key in @[@"enabled", @"integer", @"rate"])
            [[RecoveryDefaults standardUserDefaults] removeObjectForKey:key];
        puts("Recovered defaults accessors passed on Foundation.");
    }
    return 0;
}
