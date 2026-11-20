#import <UIKit/UIKit.h>
@class ASWebAuthenticationSession;
@interface UIViewController (DVNPatreonContext)
- (UIWindow *)presentationAnchorForWebAuthenticationSession:(ASWebAuthenticationSession *)session;
@end
