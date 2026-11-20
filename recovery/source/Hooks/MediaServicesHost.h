#import <Foundation/Foundation.h>
@interface MDXPlaybackRouteButtonController : NSObject
- (BOOL)isPersistentCastIconEnabled;
- (void)updateRouteButton:(id)button;
- (void)updateAllRouteButtons;
@end
@interface YTSettings : NSObject
- (void)setDisableMDXDeviceDiscovery:(BOOL)disabled;
- (BOOL)areHintsDisabled;
- (void)setHintsDisabled:(BOOL)disabled;
@end
@interface _UIConcretePasteboard : NSObject
- (void)setString:(NSString *)value;
@end
@interface YTIIosSystemShareEndpoint : NSObject
- (NSString *)shareURL;
@end
@interface YTSingleVideoController : NSObject
- (void)setAudioFormatConstraint:(uintptr_t)constraint;
@end
@interface YTWatchFlowController : NSObject
- (BOOL)shouldExitFullScreenOnFinish;
@end
@protocol YTLMediaServicesCaptions <NSObject>
- (void)selectCaptions;
@end
@protocol YTLMediaServicesPlayerView <NSObject>
- (id<YTLMediaServicesCaptions>)_viewControllerForAncestor;
@end
FOUNDATION_EXPORT void YTLInstallMediaServicesHooks(void);
