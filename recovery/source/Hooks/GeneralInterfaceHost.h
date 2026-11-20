#import <UIKit/UIKit.h>
@class YTLHelper;
@protocol YTLGeneralNode <NSObject>
- (id)valueForKey:(NSString *)key;
- (NSArray<id<YTLGeneralNode>> *)yogaChildren;
- (NSArray<id<YTLGeneralNode>> *)subnodes;
- (id<YTLGeneralNode>)node;
- (UIView *)view;
- (UIViewController *)closestViewController;
- (NSString *)accessibilityIdentifier;
- (NSString *)accessibilityLabel;
- (UIImage *)image;
- (NSAttributedString *)attributedText;
- (NSURL *)URL;
@end
@protocol YTLGeneralPivotItem <NSObject>
- (NSString *)pivotIdentifier;
@end
@protocol YTLGeneralPivotSupported <NSObject>
- (id<YTLGeneralPivotItem>)pivotBarItemRenderer;
- (id<YTLGeneralPivotItem>)pivotBarIconOnlyItemRenderer;
@end
@protocol YTLGeneralPivotBar <NSObject>
- (NSMutableArray<id<YTLGeneralPivotSupported>> *)itemsArray;
@end
@protocol YTLGeneralGuideItem <NSObject>
- (id<YTLGeneralPivotBar>)pivotBarRenderer;
@end
@protocol YTLGeneralGuideResponse <NSObject>
- (NSArray<id<YTLGeneralGuideItem>> *)itemsArray;
@end
@interface UIViewController (YTLGeneralMessages)
- (id)panelIdentifier;
- (id)parentResponder;
- (id)delegate;
@end
@interface UIDevice (YTLGeneralPrivate)
- (void)setOrientation:(NSInteger)orientation animated:(BOOL)animated;
@end
@interface YTToastOffsetController : NSObject
- (void)update;
- (void)setWasPinnedTop:(BOOL)pinned;
@end
@interface YTWatchViewController : UIViewController
- (void)setFullscreen:(BOOL)fullscreen;
- (NSUInteger)allowedFullScreenOrientations;
@end
@interface YTMultiSizeViewController : UIViewController @end
@interface YTMultiSizeViewController (YTLGeneralHelper)
@property(nonatomic,strong) YTLHelper *helper;
@end
@interface YTSearchViewController : UIViewController
- (void)setSuggestions:(id)suggestions;
@end
@interface YTRightNavigationButtons : UIView
- (UIView *)notificationButton;
- (UIView *)searchButton;
@end
@interface YTUserDefaults : NSObject
- (BOOL)areHintsDisabled;
- (void)setHintsDisabled:(BOOL)disabled;
@end
@interface YTGuideServiceCoordinator : NSObject
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response withCompletion:(id)completion;
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion;
@end
@interface YTGuideServiceCoordinatorImpl : NSObject
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion;
- (void)handleLegacyResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion;
@end
@interface YTAppGuideServiceCoordinator : NSObject
- (void)handleResponse:(id<YTLGeneralGuideResponse>)response error:(id)error completion:(id)completion;
@end
@interface YTIPivotBarRenderer : NSObject
+ (id<YTLGeneralPivotSupported>)pivotSupportedRenderersWithBrowseId:(NSString *)browseId title:(NSString *)title iconType:(int)icon;
@end
@interface UIKeyboardImpl : NSObject
- (BOOL)floatingForced;
@end
@interface YTSettingsSectionItemManager : NSObject
- (void)updatePremiumEarlyAccessSectionWithEntry:(id)entry;
@end
@interface ELMTouchCommandPropertiesHandler : NSObject
- (void)handleTap;
@end
@interface ASCollectionView : UIView
- (CGSize)sizeForElement:(id<YTLGeneralNode>)element;
@end
@interface ASTextNode : NSObject <YTLGeneralNode> @end
@interface ASImageNode : NSObject <YTLGeneralNode> @end
@interface YTMainAppVideoPlayerOverlayViewController : UIViewController
- (void)didPressVideoQuality:(id)sender;
@end
@interface YTActionSheetDialogViewController : UIViewController @end
@interface YTBottomSheetController : UIViewController @end
FOUNDATION_EXPORT void YTLInstallGeneralInterfaceEarlyHooks(void);
FOUNDATION_EXPORT void YTLInstallGeneralInterfaceHooks(void);
