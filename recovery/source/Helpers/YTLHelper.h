#pragma once
#import <UIKit/UIKit.h>
#import "../Downloads/DownloaderDelegate.h"

@class YTPDownloader, ToastView;
@interface YTLHelper : NSObject <DownloaderDelegate> {
    NSCharacterSet *_illegalChars;
    YTPDownloader *_downloader;
    ToastView *_toastView;
    NSString *_title;
    NSString *_videoID;
    NSString *_format;
    unsigned long long _duration;
    BOOL _isVideoDownloaded;
    BOOL _isAudioOnly;
    NSURL *_videoUrl;
    NSURL *_audioUrl;
    NSURL *_captionsUrl;
    unsigned long long _audioSize;
}
- (instancetype)init;
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL
                   fileName:(NSString *)name format:(NSString *)format videoID:(NSString *)videoID
                  videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize
                   duration:(unsigned long long)duration captions:(NSURL *)captions;
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID
                  audioSize:(unsigned long long)size duration:(unsigned long long)duration;
- (void)downloadProgress:(float)progress;
- (void)downloadDidFinish:(NSURL *)url fileName:(NSString *)name;
- (void)downloadDidFailureWithError:(NSError *)error;
- (void)saveMedia:(NSURL *)url;
- (void)shareMedia:(NSURL *)url;
- (void)cleanup;
- (void)askForAction:(NSURL *)url;
- (UIImage *)resizeImage:(UIImage *)image toSize:(double)size;
- (UIImage *)imageNamed:(NSString *)name;
+ (UIImage *)YTImageNamed:(NSString *)name;
+ (UIImage *)YTLImageNamed:(NSString *)name;
+ (BOOL)isConnectedToWiFi;
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                   buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector;
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                   buttonLabel:(NSString *)label icon:(UIImage *)icon size:(CGSize)size selector:(SEL)selector;
+ (UIButton *)createOverlayButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                     buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector;
+ (void)downloadImageFromURL:(NSURL *)url download:(BOOL)download;
+ (void)genImageFromLayer:(CALayer *)layer backgroundColor:(UIColor *)color
      completionHandler:(void (^)(UIImage *image))completion;
+ (UIImage *)resizeImage:(UIImage *)image toSize:(double)size;
@end
