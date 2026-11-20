#import <Foundation/Foundation.h>

// Local feature preferences. Neither function reads credentials, contacts an
// account service, or applies a subscription/device-activation restriction.
FOUNDATION_EXPORT BOOL ytpBool(NSString *key);
FOUNDATION_EXPORT NSInteger ytpInt(NSString *key);
