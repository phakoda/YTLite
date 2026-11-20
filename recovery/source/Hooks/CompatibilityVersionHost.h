#pragma once
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
// GPBMessage is a host-owned superclass. The hook uses no declared storage.
@interface GPBMessage : NSObject @end
@interface YTIIcon : GPBMessage
- (int)iconType;
@end
@interface QTMIcon : NSObject
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color;
@end
@interface YTELMResourceLoader : NSObject
- (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color bundleId:(NSString *)bundleID;
@end
@interface YTWatchFloatingMiniplayerWithControlsOverlayView : UIView @end
@interface YTVersionUtils : NSObject
+ (NSString *)appVersion;
@end
@interface YTSettingsCell : UIView
- (void)setDetailText:(NSString *)text;
@end
@interface ELMTouchCommandPropertiesHandler : NSObject
- (void)handleTap;
@end
@protocol YTLVersionNode <NSObject>
@property(nonatomic,readonly) NSArray *subnodes;
@property(nonatomic,readonly) id<YTLVersionNode> yogaParent;
@property(nonatomic,readonly) UIViewController *closestViewController;
@property(nonatomic,readonly) id parentResponder;
@end
@protocol YTLVersionController <NSObject>
@property(nonatomic,readonly) id<YTLVersionNode> node;
@end
@interface ASNetworkImageNode : NSObject
@property(nonatomic,readonly) UIImage *image;
@end
@interface YTVideoWithContextNode : NSObject<YTLVersionNode> @end
@interface YTCellController : NSObject
@property(nonatomic,readonly) id entry;
@end
@interface YTActionSheetDialogViewController : UIViewController @end
FOUNDATION_EXPORT void YTLInstallCompatibilityVersionHooks(void);
