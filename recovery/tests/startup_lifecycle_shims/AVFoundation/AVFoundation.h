#pragma once
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
FOUNDATION_EXPORT NSString *const AVAudioSessionCategoryPlayback;
FOUNDATION_EXPORT NSString *const AVLayerVideoGravityResizeAspectFill;
FOUNDATION_EXPORT NSString *const AVPlayerItemDidPlayToEndTimeNotification;
enum { AVAudioSessionCategoryOptionDuckOthers=2,AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation=1 };
@interface AVAudioSession : NSObject
+ (instancetype)sharedInstance;
- (BOOL)setCategory:(NSString *)category withOptions:(NSUInteger)options error:(NSError **)error;
- (BOOL)setActive:(BOOL)active error:(NSError **)error;
- (BOOL)setActive:(BOOL)active withOptions:(NSUInteger)options error:(NSError **)error;
@end
@interface AVPlayer : NSObject
+ (instancetype)playerWithURL:(NSURL *)url;
@property(nonatomic,strong) id currentItem;
- (void)play;
- (void)pause;
@end
@interface AVPlayerLayer : CALayer
+ (instancetype)playerLayerWithPlayer:(AVPlayer *)player;
@property(nonatomic,strong) AVPlayer *player;
@property(nonatomic,copy) NSString *videoGravity;
@end
