#pragma once
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>

FOUNDATION_EXPORT NSMutableArray<NSDictionary *> *PresentationEvents;
FOUNDATION_EXPORT NSMutableArray<dispatch_block_t> *PresentationMainQueue;
FOUNDATION_EXPORT NSMutableArray<void (^)(BOOL)> *PresentationAnimations;
FOUNDATION_EXPORT NSMutableArray<NSDictionary *> *PresentationPhotoChanges;
FOUNDATION_EXPORT NSMutableArray<NSDictionary *> *PresentationDownloads;
FOUNDATION_EXPORT NSMutableArray<NSDictionary *> *PresentationConversions;
FOUNDATION_EXPORT PresentationFixtureURLSessionDataTask *PresentationLastNetworkTask;
FOUNDATION_EXPORT NSInteger PresentationPostDownloadIndex;
FOUNDATION_EXPORT BOOL PresentationNativeDetents;
FOUNDATION_EXPORT BOOL PresentationReachabilitySucceeded;
FOUNDATION_EXPORT BOOL PresentationReachabilityCreated;
FOUNDATION_EXPORT uint32_t PresentationReachabilityFlags;
FOUNDATION_EXPORT NSString *PresentationFixtureRoot;
FOUNDATION_EXPORT void PresentationRecord(NSString *kind,id value);
FOUNDATION_EXPORT NSArray<NSDictionary *> *PresentationEventsOfKind(NSString *kind);
FOUNDATION_EXPORT void PresentationInitialize(void);
FOUNDATION_EXPORT void PresentationDrainMain(void);
FOUNDATION_EXPORT void PresentationAdvanceTime(double seconds);
FOUNDATION_EXPORT void PresentationCompleteAnimations(BOOL finished);
FOUNDATION_EXPORT void PresentationFireTimers(NSUInteger count);
FOUNDATION_EXPORT void PresentationResetEvents(void);

@interface PresentationAppDelegate : NSObject <UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window;
@end
@interface PresentationTransition : NSObject <UIViewControllerTransitionCoordinator,UIViewControllerTransitionCoordinatorContext>
@property(nonatomic,getter=isCancelled) BOOL cancelled;
@property(nonatomic,copy) void (^fixtureCompletion)(id<UIViewControllerTransitionCoordinatorContext>);
@end
@interface PresentationSheetController : UIViewController
@property(nonatomic,strong) NSArray *_sections;
@end

// Definitions exist only in the host test executable, never in the tweak.
@interface MPVolumeController : NSObject
@property(nonatomic) float volumeValue;
@property(nonatomic,copy) NSString *volumeAudioCategory;
@end
@interface MPVolumeHUDController : NSObject
@property(nonatomic,strong) NSMutableArray *fixtureDisplays;
+ (instancetype)sharedInstance;
- (void)addVolumeDisplay:(id)display;
- (void)removeVolumeDisplay:(id)display;
@end

void PlayerLifecycleSchedule(NSString *kind,UIView *view,double duration,double delay,UIViewAnimationOptions options,dispatch_block_t animations,void (^completion)(BOOL));

FOUNDATION_EXPORT id ImageViewerNextPopover(id fallback);
FOUNDATION_EXPORT CGRect ImageViewerNextScreenBounds(CGRect fallback);
