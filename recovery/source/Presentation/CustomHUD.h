#pragma once
#import <UIKit/UIKit.h>

@class MPVolumeController;
// Private MediaPlayer protocol surface present in the original class metadata.
@protocol MPVolumeDisplaying <NSObject>
@property(nonatomic) float volumeLevel;
@property(nonatomic, readonly) NSString *volumeAudioCategory;
@optional
@property(nonatomic, readonly, getter=isOnScreen) BOOL onScreen;
@property(nonatomic, readonly, getter=isOnScreenForVolumeDisplay) BOOL onScreenForVolumeDisplay;
@property(nonatomic, readonly) UIWindowScene *windowSceneForVolumeDisplay;
@end

@interface CustomHUD : NSObject <MPVolumeDisplaying> {
    MPVolumeController *_controller;
}
@property(nonatomic, readonly) MPVolumeController *controller;
@property(nonatomic) float volumeLevel;
@property(nonatomic, readonly) NSString *volumeAudioCategory;
- (instancetype)init;
- (void)addToController;
- (void)removeFromController;
- (UIWindowScene *)windowSceneForVolumeDisplay;
@end
