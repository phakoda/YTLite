#pragma once
#import <UIKit/UIKit.h>
FOUNDATION_EXPORT void YTLInstallSideloadIdentityHooks(void);
@interface YTVersionUtils:NSObject
+ (NSString *)appName;
+ (NSString *)appID;
@end
@interface GCKBUtils:NSObject
+ (NSString *)appIdentifier;
@end
@interface OGLBundle:NSObject
+ (NSString *)shortAppName;
@end
@interface GVROverlayView:NSObject
+ (NSString *)appName;
@end
@interface OGLPhenotypeFlagServiceImpl:NSObject
- (NSString *)bundleId;
@end
@interface SSOConfiguration:NSObject
- (instancetype)initWithClientID:(id)clientID supportedAccountServices:(id)services;
@end
@interface SSOKeychainHelper:NSObject
+ (NSString *)accessGroup;
+ (NSString *)sharedAccessGroup;
@end
@interface SSOKeychainCore:NSObject
+ (NSString *)accessGroup;
+ (NSString *)sharedAccessGroup;
@end
@interface SSOFolsomKeychainUtils:NSObject
+ (NSString *)sharedAccessGroup;
@end
@interface GNPEncryptionConfiguration:NSObject
+ (NSString *)keychainAccessGroup;
@end
@interface YTFirstTimeSignInViewController:UIViewController @end
@interface YTInlineSignInViewController:UIViewController @end
@interface UIDevice (YTLSideloadIdentity)
- (NSString *)doc_symbolName;
@end
@protocol YTLSideloadIdentityAlert <NSObject>
+ (id<YTLSideloadIdentityAlert>)dialog;
- (void)setTitle:(NSString *)title;
- (void)setSubtitle:(NSString *)subtitle;
- (void)addTitle:(NSString *)title withAction:(id)action;
- (void)show;
@end
