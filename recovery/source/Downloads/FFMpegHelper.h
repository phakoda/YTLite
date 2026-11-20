#pragma once
#import <Foundation/Foundation.h>
#import "FFMpegLibrary.h"
@class ToastView;
@interface FFMpegHelper : NSObject <StatisticsDelegate, LogDelegate> {
    dispatch_queue_t _ffmpegQueue;
    Statistics *_statistics;
    ToastView *_toastView;
    long long _duration;
    BOOL _isProcessing;
}
+ (instancetype)sharedInstance;
- (void)mergeVideo:(NSURL *)videoURL withAudio:(NSURL *)audioURL captions:(NSURL *)captionsURL
          duration:(long long)duration completion:(void (^)(NSURL *outputURL, NSError *error))completion;
- (NSString *)getCommandWithVideoURL:(NSURL *)videoURL audioURL:(NSURL *)audioURL
                       captionsURL:(NSURL *)captionsURL thumbnailURL:(NSURL *)thumbnailURL
                          duration:(long long)duration outputURL:(NSURL *)outputURL;
- (void)cutAudio:(NSURL *)audioURL duration:(long long)duration completion:(void (^)(NSURL *outputURL, NSError *error))completion;
- (void)getCleanLog:(NSString *)log;
- (void)setActive;
- (void)updateProgressDialog;
- (NSString *)codeForCaps:(NSURL *)url;
@end
