#pragma once
#import <Foundation/Foundation.h>

// Message contracts inferred from call sites. These are declarations only:
// host and shared tweak classes must supply their real implementations.
@protocol YTLPlaybackPreferences <NSObject>
+ (BOOL)boolForKey:(NSString *)key;
+ (NSInteger)integerForKey:(NSString *)key;
+ (double)floatForKey:(NSString *)key;
+ (NSUserDefaults *)standardUserDefaults;
@end

@protocol YTLPlaybackVideoDetails <NSObject>
- (NSString *)channelId;
@end
@protocol YTLPlaybackPlayerData <NSObject>
- (id<YTLPlaybackVideoDetails>)videoDetails;
@end
@protocol YTLPlaybackResponse <NSObject>
- (id<YTLPlaybackPlayerData>)playerData;
@end
@protocol YTLSponsorPlayer <NSObject>
- (NSString *)contentVideoID;
- (double)currentVideoMediaTime;
- (id)parentViewController;
- (id<YTLPlaybackResponse>)playerResponse;
- (id<YTLPlaybackResponse>)contentPlayerResponse;
- (void)seekToTime:(double)time;
@end

@protocol YTLPlaybackToast <NSObject>
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(id)icon actionCompletion:(void (^)(void))completion;
@end
@protocol YTLPlaybackAudio <NSObject>
+ (instancetype)sharedInstance;
- (void)playAudio;
@end

@interface NSString (YTLPlaybackLocalization)
- (NSString *)ytl_localized;
@end
@interface NSBundle (YTLPlaybackResources)
+ (NSBundle *)ytl_defaultBundle;
- (id)imageWithName:(NSString *)name;
@end
