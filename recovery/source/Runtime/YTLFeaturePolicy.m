#import "YTLFeaturePolicy.h"
#import "../../../Utils/YTLUserDefaults.h"

// Intentional local-fork change from 5.2.2: preferences are available without
// signing in. Keep each user's actual setting rather than forcing every feature
// on. Legacy authorization caches and suspension flags have no role here.
BOOL ytpBool(NSString *key) {
    return [[YTLUserDefaults standardUserDefaults] boolForKey:key];
}

NSInteger ytpInt(NSString *key) {
    return [[YTLUserDefaults standardUserDefaults] integerForKey:key];
}
