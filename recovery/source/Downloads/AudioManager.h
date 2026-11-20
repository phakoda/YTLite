#pragma once
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
@interface AudioManager : NSObject <AVAudioPlayerDelegate> {
    AVAudioPlayer *_audioPlayer;
}
@property(nonatomic, strong) AVAudioPlayer *audioPlayer;
+ (instancetype)sharedInstance;
- (void)playAudio;
- (void)stopAudio;
@end
