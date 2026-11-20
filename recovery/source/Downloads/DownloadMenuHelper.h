#pragma once
#import <Foundation/Foundation.h>
@class UIView;
@interface DownloadMenuHelper : NSObject
+ (void)showDownloadSheetShorts:(id)player withSender:(id)sender;
+ (void)showDownloadSheet:(id)player withSender:(id)sender;
- (void)showVideoSheet:(id)player withSender:(id)sender;
- (void)showImagesSheet:(id)player withSender:(id)sender;
- (void)showInformationSheet:(id)player withSender:(id)sender;
- (void)showExtPlayerSheet:(id)player withSender:(id)sender;
- (NSArray *)getVideoFormatsArray:(id)player isShorts:(BOOL)shorts;
- (NSArray *)getAudioFormatsArray:(id)player;
- (id)getBestAudioFormat:(NSArray *)formats playerVC:(id)player;
- (id)getDefaultAudioTrack:(NSArray *)formats;
- (id)getEnglishAudioTrack:(NSArray *)formats;
- (NSString *)detailForMimeType:(NSString *)mimeType;
- (long long)getResoForQuality:(NSString *)quality;
- (void)downloadVideoWithFormat:(id)video withAudioFormats:(NSArray *)formats fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID playerVC:(id)player sender:(id)sender;
- (void)downloadVideoWithFormat:(id)video audioFormat:(id)audio fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID playerVC:(id)player sender:(id)sender;
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL fileName:(NSString *)name extension:(NSString *)extension videoID:(NSString *)videoID videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize duration:(unsigned long long)duration captions:(NSURL *)captions playerVC:(id)player;
- (void)getThumbnail:(id)player;
- (void)checkSpaceAvailabilityForMedia:(long long)size completion:(void (^)(BOOL available, NSString *message))completion;
- (void)showAudioTrackSelector:(NSArray *)formats sender:(id)sender playerVC:(id)player completion:(void (^)(id format))completion;
- (BOOL)hasCaptions:(id)player;
- (void)showTranscriptSheet:(id)player withSender:(id)sender;
- (void)showCaptionsSheet:(id)player withSender:(id)sender;
- (NSArray *)captionsForDownloading:(NSArray *)tracks;
- (NSString *)titleForCaption:(id)track;
- (void)getCaptionsUrlSheet:(id)player sender:(id)sender completion:(void (^)(NSURL *url))completion;
- (void)shareSRT:(NSURL *)url sourceView:(UIView *)sourceView;
@end
