#pragma once
#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
@interface YTWatchController : NSObject
- (void)handleRemoteControlEvent:(NSInteger)event withInterval:(double)interval;
@end
FOUNDATION_EXPORT void YTLInstallRemoteControlsEarlyHooks(void);
FOUNDATION_EXPORT void YTLInstallRemoteControlsMainHooks(void);
