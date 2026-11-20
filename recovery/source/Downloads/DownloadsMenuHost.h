#pragma once
#import "DownloadsHost.h"
// Only selectors exercised by the recovered menu; these are host contracts, not
// implementations of YouTube, YTLHelper, or other recovered classes.
@protocol YTPDownloadsNode <NSObject>
- (id<YTPDownloadsNode>)playerResponse;
- (id<YTPDownloadsNode>)contentPlayerResponse;
- (id<YTPDownloadsNode>)playerData;
- (id<YTPDownloadsNode>)videoDetails;
- (id<YTPDownloadsNode>)streamingData;
- (id<YTPDownloadsNode>)thumbnail;
- (id<YTPDownloadsNode>)activeVideo;
- (id<YTPDownloadsNode>)selectedAudioFormat;
- (id<YTPDownloadsNode>)formatStream;
- (id<YTPDownloadsNode>)audioTrack;
- (id<YTPDownloadsNode>)videoData;
- (id<YTPDownloadsNode>)playbackData;
- (id<YTPDownloadsNode>)video;
- (NSArray<id<YTPDownloadsNode>> *)adaptiveFormatsArray;
- (NSArray<id<YTPDownloadsNode>> *)thumbnailsArray;
- (NSArray<id<YTPDownloadsNode>> *)availableCaptionTracks;
- (NSString *)videoID;
- (NSString *)title;
- (NSString *)author;
- (NSString *)shortDescription;
- (BOOL)hasShortDescription;
- (BOOL)isLivePlayback;
- (NSString *)mimeType;
- (NSString *)qualityLabel;
- (id)URL; // NSString for format records, NSURL for caption-track objects
- (unsigned long long)contentLength;
- (unsigned long long)approxDurationMs;
- (int)itag;
- (BOOL)isDrc;
- (BOOL)hasContentLength;
- (BOOL)audioIsDefault;
- (NSString *)id_p;
- (NSString *)displayName;
- (NSString *)VSSID;
- (NSString *)languageCode;
- (NSURL *)HLSMasterPlaylistURL;
- (double)contentVideoMediaTime;
- (NSString *)contentVideoID;
- (void)pause;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@protocol YTPDownloadsSheet <NSObject>
+ (id<YTPDownloadsSheet>)sheetControllerWithParentResponder:(id)parent;
+ (id<YTPDownloadsSheet>)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent;
- (void)addAction:(id)action;
- (void)setSourceView:(id)view;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
- (id)valueForKey:(NSString *)key;
@end
@protocol YTPDownloadsAction <NSObject>
+ (id<YTPDownloadsAction>)actionWithTitle:(NSString *)title iconImage:(UIImage *)image style:(long long)style handler:(void (^)(void))handler;
+ (id<YTPDownloadsAction>)actionWithTitle:(NSString *)title currentValue:(NSString *)value iconImage:(UIImage *)image accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
+ (id<YTPDownloadsAction>)actionWithTitle:(NSString *)title iconImage:(UIImage *)image secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
- (UIButton *)button;
@end
@protocol YTPDownloadsSheetHeader <NSObject>
- (void)showHeaderDivider;
@end
@protocol YTPDownloadsResources <NSObject>
+ (UIViewController *)topViewControllerForPresenting;
+ (UIImage *)chevronRightImage;
+ (UIView *)sourceViewForActionSheetFromSourceView:(UIView *)source;
@end
@interface UIImage (YTPDownloadsHostImage)
- (void)setFlipsForRightToLeftLayoutDirection:(BOOL)flips;
@end
@protocol YTPDownloadsMenuToast <NSObject>
+ (UIWindow *)toastWindow;
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success;
- (void)showToast:(NSString *)text;
- (void)hide;
@end
@protocol YTPDownloadsLegacyToast <NSObject>
- (void)showMessage:(NSString *)text;
@end
@protocol YTPDownloadsPipeline <NSObject>
+ (void)downloadImageFromURL:(NSURL *)url download:(BOOL)download;
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL fileName:(NSString *)name format:(NSString *)format videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions;
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID audioSize:(unsigned long long)size duration:(unsigned long long)duration;
@end
@protocol YTPDownloadsAppRoot <NSObject>
- (id<YTPDownloadsPipeline>)helper;
- (void)setHelper:(id<YTPDownloadsPipeline>)helper;
@end
@protocol YTPDownloadsApplicationDelegate <NSObject>
- (UIWindow *)window;
@end
@protocol YTPDownloadsImageViewer <NSObject>
- (void)setFullImage:(UIImage *)image;
@end
@protocol YTPDownloadsPlayerHelper <NSObject>
+ (void)openVideoWithID:(NSString *)videoID viewController:(id)controller;
@end
@protocol YTPDownloadsStorage <NSObject>
- (long long)freeDeviceStorageBytes;
@end
@protocol YTPDownloadsMutablePreferences <NSObject>
+ (id<YTPDownloadsMutablePreferences>)standardUserDefaults;
- (void)setInteger:(long long)value forKey:(NSString *)key;
@end
