#pragma once
#import <Foundation/Foundation.h>
// Avoid colliding with macOS private AudioSession loaded by Foundation.
#define AVAudioSession DownloadsAVAudioSession
FOUNDATION_EXPORT NSString * const AVAudioSessionCategoryPlayback;
typedef NS_OPTIONS(NSUInteger, AVAudioSessionCategoryOptions) { AVAudioSessionCategoryOptionMixWithOthers = 1 };
@protocol AVAudioPlayerDelegate <NSObject>
@optional
- (void)audioPlayerDidFinishPlaying:(id)player successfully:(BOOL)success;
@end
@interface AVAudioSession : NSObject
@property(nonatomic,strong) NSString *category;
@property(nonatomic) AVAudioSessionCategoryOptions options;
+ (AVAudioSession *)sharedInstance;
- (BOOL)setCategory:(NSString *)category withOptions:(AVAudioSessionCategoryOptions)options error:(NSError **)error;
@end
@interface AVAudioPlayer : NSObject
@property(nonatomic,weak) id<AVAudioPlayerDelegate> delegate;
@property(nonatomic,getter=isPlaying) BOOL playing;
@property(nonatomic) double currentTime;
@property(nonatomic) NSUInteger playCount,stopCount,prepareCount;
@property(nonatomic,strong) NSURL *url;
- (instancetype)initWithContentsOfURL:(NSURL *)url error:(NSError **)error;
- (BOOL)prepareToPlay;
- (BOOL)play;
- (void)stop;
@end
@interface AVPlayer : NSObject
@property(nonatomic,strong) NSURL *url;
@property(nonatomic) BOOL playing;
+ (instancetype)playerWithURL:(NSURL *)url;
- (void)play;
@end
