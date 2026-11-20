#import "CustomHUD.h"

@interface MPVolumeController : NSObject
@property(nonatomic) float volumeValue;
@property(nonatomic, readonly) NSString *volumeAudioCategory;
@end
@interface MPVolumeHUDController : NSObject
+ (instancetype)sharedInstance;
- (void)addVolumeDisplay:(id<MPVolumeDisplaying>)display;
- (void)removeVolumeDisplay:(id<MPVolumeDisplaying>)display;
@end

@implementation CustomHUD
@synthesize controller = _controller;
- (instancetype)init {
    self = [super init];
    if (self) _controller = [NSClassFromString(@"MPVolumeController") new];
    return self;
}
- (void)addToController {
    [[NSClassFromString(@"MPVolumeHUDController") sharedInstance] addVolumeDisplay:self];
}
- (void)removeFromController {
    [[NSClassFromString(@"MPVolumeHUDController") sharedInstance] removeVolumeDisplay:self];
}
- (void)setVolumeLevel:(float)level { _controller.volumeValue = level; }
- (float)volumeLevel { return _controller.volumeValue; }
- (UIWindowScene *)windowSceneForVolumeDisplay {
    return (UIWindowScene *)UIApplication.sharedApplication.connectedScenes.anyObject;
}
- (NSString *)volumeAudioCategory { return _controller.volumeAudioCategory; }
- (MPVolumeController *)controller { return _controller; }
@end
