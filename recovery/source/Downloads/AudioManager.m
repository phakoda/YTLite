#import "AudioManager.h"
#import "DownloadsHost.h"
// First-package evidence and runtime checks: AudioManager.provenance.md.
@implementation AudioManager
@synthesize audioPlayer = _audioPlayer;
// First package 0x1ce700, singleton invoke 0x1ce7b4.
+ (instancetype)sharedInstance {
    static AudioManager *instance;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ instance = [[self alloc] init]; });
    return instance;
}
// First package 0x1ce7f8. The same NSError variable is reused for session and player setup.
- (instancetype)init {
    if ((self = [super init])) {
        NSError *error = nil;
        [[AVAudioSession sharedInstance] setCategory:AVAudioSessionCategoryPlayback
                                        withOptions:AVAudioSessionCategoryOptionMixWithOthers error:&error];
        if (error) NSLog(@"DVN --- Unable to set category: %@", error.localizedDescription);
        NSString *path = [[NSBundle ytl_defaultBundle] pathForResource:@"SponsorAudio" ofType:@"m4a"];
        NSURL *url = [NSURL fileURLWithPath:path];
        self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:&error];
        if (error) {
            NSLog(@"DVN --- Unable to init player: %@", error.localizedDescription);
            return nil;
        }
        self.audioPlayer.delegate = self;
        [self.audioPlayer prepareToPlay];
    }
    return self;
}
// First package 0x1cf0dc.
- (void)playAudio { if (![self.audioPlayer isPlaying]) [self.audioPlayer play]; }
// First package 0x1cf1bc. A stopped player is not rewound unless it was playing.
- (void)stopAudio {
    if ([self.audioPlayer isPlaying]) {
        [self.audioPlayer stop];
        self.audioPlayer.currentTime = 0.0;
    }
}
// First package 0x1cf2cc..0x1cf2e8 contains no behavior beyond the removed anti-analysis syscall.
- (void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag {
    (void)player; (void)flag;
}
// ARC supplies accessors 0x1cf2e8/0x1cf2f0 and .cxx_destruct 0x1cf2fc.
@end
