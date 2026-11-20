#pragma once
#import <UIKit/UIKit.h>

@protocol YTLPlayerCaption <NSObject>
- (NSString *)languageCode;
@end
@protocol YTLPlayerAudioTrack <NSObject>
- (NSString *)id_p;
@end
@protocol YTLPlayerFormat <NSObject>
- (int)singleDimensionResolution;
- (NSString *)qualityLabel;
- (id<YTLPlayerAudioTrack>)audioTrack;
@end
@protocol YTLPlayerAudioConstraint <NSObject>
- (BOOL)DRCEnabled;
- (instancetype)initWithAudioTrack:(id<YTLPlayerAudioTrack>)track audioQualityConfig:(id)config formatSelectionReason:(int)reason DRCEnabled:(BOOL)drc;
@end
@protocol YTLPlayerVideoConstraint <NSObject>
- (instancetype)initWithVideoQualitySetting:(int)setting formatSelectionReason:(NSInteger)reason qualityLabel:(NSString *)label;
@end
@protocol YTLPlayerVideo <NSObject>
- (id)delegate;
- (double)totalMediaTime;
- (NSArray<id<YTLPlayerCaption>> *)availableCaptionTracks;
- (void)setActiveCaptionTrack:(id<YTLPlayerCaption>)track;
- (void)setActiveCaptionTrack:(id<YTLPlayerCaption>)track source:(NSInteger)source;
- (NSArray<id<YTLPlayerFormat>> *)selectableVideoFormats;
- (NSArray<id<YTLPlayerFormat>> *)selectableAudioFormats;
- (id<YTLPlayerFormat>)selectedAudioFormat;
- (id<YTLPlayerAudioConstraint>)audioFormatConstraint;
- (void)setAudioFormatConstraint:(id<YTLPlayerAudioConstraint>)constraint;
- (void)setVideoFormatConstraint:(id<YTLPlayerVideoConstraint>)constraint;
@end
@protocol YTLPlayerTime <NSObject>
- (double)time;
@end
@protocol YTLPlayerLoopOverlay <NSObject>
- (NSInteger)loopMode;
- (void)setLoopMode:(NSInteger)mode;
@end
@protocol YTLPlayerLocalPlayback <NSObject>
- (BOOL)loopingEnabled;
- (void)setLoopingEnabled:(BOOL)enabled;
@end
@protocol YTLPlayerFullscreenDelegate <NSObject>
- (void)showFullScreen;
@end
@protocol YTLPlayerDefaultAudioData <NSObject>
- (NSString *)audioTrackId;
@end
@protocol YTLPlayerCaptionList <NSObject>
- (NSArray<id<YTLPlayerCaption>> *)captionTracksArray;
- (id<YTLPlayerDefaultAudioData>)ml_defaultAudioTrackData;
@end
@protocol YTLPlayerCaptions <NSObject>
- (id<YTLPlayerCaptionList>)playerCaptionsTracklistRenderer;
@end
@protocol YTLPlayerData <NSObject>
- (id<YTLPlayerCaptions>)captions;
@end
@protocol YTLPlayerResponse <NSObject>
- (id<YTLPlayerData>)playerData;
@end
@interface YTPlayerViewController : UIViewController
- (id<YTLPlayerVideo>)activeVideo;
- (id<YTLPlayerLoopOverlay>)activeVideoPlayerOverlay;
- (id<YTLPlayerResponse>)playerResponse;
- (id<YTLPlayerResponse>)contentPlayerResponse;
- (BOOL)isMDXActive;
- (void)playbackController:(id)controller didActivateVideo:(id)video withPlaybackData:(id)data;
- (void)restoreLoopMode;
- (void)autoFullscreen;
- (void)setAutoSpeed;
- (void)selectCaptions;
- (void)autoQuality;
- (void)selectAudioTrack;
- (void)singleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time;
- (void)potentiallyMutatedSingleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time;
@end

FOUNDATION_EXPORT void YTLInstallPlayerLifecycleHooks(void);
