#import <Foundation/Foundation.h>

@protocol YTLFeedNode;
@protocol YTLFeedNodeController <NSObject>
- (NSArray *)children;
@end
@protocol YTLFeedNode <NSObject>
@property(nonatomic, copy) NSArray<id<YTLFeedNode>> *yogaChildren;
- (id<YTLFeedNodeController>)controller;
@end
@protocol YTLFeedCompatibility <NSObject>
- (BOOL)hasAdLoggingData;
@end
@protocol YTLFeedElement <NSObject>
- (BOOL)hasCompatibilityOptions;
- (id<YTLFeedCompatibility>)compatibilityOptions;
@end
@protocol YTLFeedRenderer <NSObject>
- (id<YTLFeedElement>)elementRenderer;
@end
@protocol YTLFeedHorizontalList <NSObject>
- (NSMutableArray *)itemsArray;
@end
@protocol YTLFeedShelfContent <NSObject>
- (id<YTLFeedHorizontalList>)horizontalListRenderer;
@end
@protocol YTLFeedIdentifier <NSObject>
- (NSString *)tag;
@end
@protocol YTLFeedEndpoint <NSObject>
- (id<YTLFeedIdentifier>)identifier;
@end
@protocol YTLFeedExecutor <NSObject>
- (NSMutableArray *)commandsArray;
@end
@protocol YTLFeedCommand <NSObject>
- (id<YTLFeedExecutor>)yt_commandExecutorCommand;
- (id<YTLFeedEndpoint>)yt_showEngagementPanelEndpoint;
@end
@protocol YTLFeedWatchModel <NSObject>
@property(nonatomic, strong) id<YTLFeedCommand> onUiReady;
@end
@protocol YTLFeedThrottleRules <NSObject>
- (void)setThrottledAfterRecentSignIn:(BOOL)value;
@end
@interface ELMComponent : NSObject
- (id<YTLFeedNode>)node;
@end
@interface YTIElementRenderer : NSObject <YTLFeedElement>
- (NSData *)elementData;
@end
@interface YTIItemSectionRenderer : NSObject
- (NSMutableArray<id<YTLFeedRenderer>> *)contentsArray;
@end
@interface YTIShelfRenderer : NSObject
- (id<YTLFeedShelfContent>)content;
@end
@interface YTInnerTubeCollectionViewController : NSObject
- (id)delegate;
- (void)addSectionsFromArray:(NSArray *)sections;
@end
@interface YTWatchNextResponseViewController : NSObject
- (void)loadWithModel:(id<YTLFeedWatchModel>)model;
@end
@interface YTICommand : NSObject <YTLFeedCommand>
@end
@interface YTICommandWrapperPromoRenderer : NSObject
- (void)setHasPromoType:(BOOL)value;
- (void)setPromoType:(int32_t)value;
- (void)setHasPromoCommand:(BOOL)value;
- (void)setPromoCommand:(id)value;
- (void)setHasWatchPageTriggerCondition:(BOOL)value;
- (void)setWatchPageTriggerCondition:(int32_t)value;
- (NSMutableArray *)clientFrequencyCapConfigsArray;
- (NSUInteger)clientFrequencyCapConfigsArray_Count;
@end
@interface YTIPromoMessageSupportedRenderers : NSObject
- (uint32_t)rendererOneOfCase;
- (void)setHasCommandWrapperPromoRenderer:(BOOL)value;
- (void)setCommandWrapperPromoRenderer:(id)value;
- (void)setHasUpsellDialogRenderer:(BOOL)value;
- (void)setUpsellDialogRenderer:(id)value;
@end
@interface YTCommerceEventGroupHandler : NSObject
- (void)addEventHandlers;
@end
@interface YTInterstitialPromoEventGroupHandler : NSObject
- (void)addEventHandlers;
@end
@interface YTPromosheetEventGroupHandler : NSObject
- (void)addEventHandlers;
@end
@interface YTPromoThrottleController : NSObject
- (BOOL)canShowThrottledPromo;
- (BOOL)canShowThrottledPromoWithFrequencyCap:(id)cap;
- (BOOL)canShowThrottledPromoWithFrequencyCaps:(id)caps;
@end
@interface YTIShowFullscreenInterstitialCommand : NSObject
- (BOOL)hasModalClientThrottlingRules;
- (id<YTLFeedThrottleRules>)modalClientThrottlingRules;
- (BOOL)shouldThrottleInterstitial;
@end
@interface YTSurveyController : NSObject
- (void)showSurveyWithRenderer:(id)renderer surveyParentResponder:(id)responder;
@end
@interface YTPersonalizedSuggestionsCacheProvider : NSObject
- (id)activeCache;
@end
FOUNDATION_EXPORT void YTLInstallFeedFilteringHooks(void);
