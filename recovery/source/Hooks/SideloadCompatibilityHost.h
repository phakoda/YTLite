#pragma once
#import <UIKit/UIKit.h>

@interface SFAuthenticationViewController : UIViewController
@end
@interface YTInlineSignInController : NSObject
- (void)didTapShowAddAccount;
@end
@interface YTAlertView : NSObject
+ (instancetype)infoDialog;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) NSString *subtitle;
- (void)show;
@end

// Installs only the three recovered local path/UI hooks. The security-sensitive
// callbacks and environment/authorization routing are intentionally absent.
FOUNDATION_EXPORT void YTLInstallLocalSideloadCompatibilityHooks(void);

@interface NSMutableURLRequest (SideloadCompatibilityClientInfo)
+ (NSDictionary *)ak_clientInfoHeader;
@end
@interface LSApplicationProxy : NSObject
- (NSString *)teamID;
- (NSString *)appIDPrefix;
- (NSString *)applicationIdentifier;
@end
@interface LSBundleProxy : NSObject
- (NSString *)bundleIdentifier;
@end
FOUNDATION_EXPORT void YTLInstallSideloadMetadataCompatibilityHooks(void);
