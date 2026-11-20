#import "UIViewController+DVNPatreonContext.h"
@implementation UIViewController (DVNPatreonContext)
// Original 0x23e9c. This supplies an anchor only; it starts no authentication.
- (UIWindow *)presentationAnchorForWebAuthenticationSession:(ASWebAuthenticationSession *)session {
    return self.view.window;
}
@end
