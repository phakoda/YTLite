#pragma once
#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
#import "../source/Downloads/DownloadsMenuHost.h"
#import "../source/Downloads/FFMpegLibrary.h"
FOUNDATION_EXPORT NSString *DownloadsFixtureRoot;
FOUNDATION_EXPORT NSString *DownloadsBundleVersion;
FOUNDATION_EXPORT NSMutableDictionary *DownloadsPreferences;
FOUNDATION_EXPORT NSMutableArray *DownloadsEvents;
FOUNDATION_EXPORT long long DownloadsFreeSpace;
FOUNDATION_EXPORT BOOL DownloadsAuthorized;
FOUNDATION_EXPORT NSError *DownloadsAudioCategoryError, *DownloadsAudioPlayerError;
FOUNDATION_EXPORT int DownloadsFFmpegResult;
FOUNDATION_EXPORT NSString *DownloadsFFmpegLog;
FOUNDATION_EXPORT id DownloadsSRTResult;
FOUNDATION_EXPORT NSError *DownloadsSRTError;
FOUNDATION_EXPORT void DownloadsInstallDoubles(void);
FOUNDATION_EXPORT NSString *DownloadsTestTemporaryDirectory(void);
FOUNDATION_EXPORT NSUInteger DownloadsAudit(NSString *repository);
@interface DownloadsNode : UIViewController
@property(nonatomic,strong) id playerResponse,contentPlayerResponse,playerData,videoDetails,streamingData,thumbnail,activeVideo,selectedAudioFormat,formatStream,audioTrack,videoData,playbackData,video;
@property(nonatomic,strong) NSArray *adaptiveFormatsArray,*thumbnailsArray,*availableCaptionTracks;
@property(nonatomic,copy) NSString *videoID,*title,*author,*shortDescription,*mimeType,*qualityLabel,*id_p,*displayName,*VSSID,*languageCode,*contentVideoID;
@property(nonatomic,copy) id URL;
@property(nonatomic,strong) NSURL *baseURL,*HLSMasterPlaylistURL;
@property(nonatomic) unsigned long long contentLength,approxDurationMs;
@property(nonatomic) int itag;
@property(nonatomic) BOOL hasShortDescription,isLivePlayback,isDrc,hasContentLength,audioIsDefault,paused;
@property(nonatomic) double contentVideoMediaTime;
- (void)pause;
@end
@interface DownloadsOldPlayer : NSObject
@property(nonatomic,strong) id contentPlayerResponse;
@end
@interface DownloadsRoot : UIViewController
@property(nonatomic,strong) id helper;
@property(nonatomic) long long pageStyle;
@end
@interface DownloadsAppDelegate : NSObject
@property(nonatomic,strong) UIWindow *window;
@property(nonatomic,strong) DownloadsRoot *responderRoot;
@end
@interface YTLUserDefaults : NSObject
+ (BOOL)boolForKey:(NSString *)key;
+ (long long)integerForKey:(NSString *)key;
+ (double)floatForKey:(NSString *)key;
+ (instancetype)standardUserDefaults;
- (BOOL)boolForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (void)setInteger:(long long)value forKey:(NSString *)key;
@end
@interface YTActionSheetAction : NSObject
@property(nonatomic,copy) NSString *title,*value;
@property(nonatomic,strong) UIImage *icon,*secondary;
@property(nonatomic,strong) UIButton *button;
@property(nonatomic,copy) void (^handler)(void);
+ (id)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon style:(long long)style handler:(void (^)(void))handler;
+ (id)actionWithTitle:(NSString *)title currentValue:(NSString *)value iconImage:(UIImage *)icon accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
+ (id)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
@end
@interface YTDefaultSheetController : NSObject
@property(nonatomic,strong) NSMutableArray<YTActionSheetAction *> *actions;
@property(nonatomic,strong) NSString *message,*subMessage;
@property(nonatomic,strong) id source;
@property(nonatomic,strong) UIViewController *presenter;
@property(nonatomic) BOOL divider;
+ (instancetype)sheetControllerWithParentResponder:(id)parent;
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent;
@end
FOUNDATION_EXPORT YTDefaultSheetController *DownloadsLastSheet;
@interface ToastView : NSObject
@property(nonatomic,copy) NSString *text;
@property(nonatomic) float progress;
@property(nonatomic) BOOL hidden,success,withStop;
@property(nonatomic,copy) void (^stop)(void);
+ (UIWindow *)toastWindow;
@end
FOUNDATION_EXPORT ToastView *DownloadsLastToast;
@interface DownloadsSession : NSObject
@property(nonatomic,strong) NSMutableArray *tasks;
@property(nonatomic,weak) id delegate;
@property(nonatomic,strong) NSOperationQueue *delegateQueue;
@end
@interface DownloadsTask : NSObject
@property(nonatomic,strong) NSURLRequest *originalRequest;
@property(nonatomic) BOOL resumed,cancelled;
@property(nonatomic,copy) void (^completion)(NSData *,NSURLResponse *,NSError *);
- (void)resume;
- (void)cancel;
@end
FOUNDATION_EXPORT DownloadsSession *DownloadsLastSession;
FOUNDATION_EXPORT DownloadsSession *DownloadsSharedSession;
@interface Statistics : NSObject
@property(nonatomic) int time;
- (int)getTime;
@end
