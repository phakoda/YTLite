#import "RPCMedia.h"

// Structural host protocols keep object messages and floating-point returns
// correctly typed without requiring a particular YouTube header revision.
@protocol YTLRPCThumbnail <NSObject>
- (NSString *)URL;
@end
@protocol YTLRPCThumbnailDetails <NSObject>
- (NSArray<id<YTLRPCThumbnail>> *)thumbnailsArray;
@end
@protocol YTLRPCVideoDetails <NSObject>
- (NSString *)title;
- (NSString *)author;
- (id<YTLRPCThumbnailDetails>)thumbnail;
@end
@protocol YTLRPCPlayerData <NSObject>
- (id<YTLRPCVideoDetails>)videoDetails;
@end
@protocol YTLRPCPlayerResponse <NSObject>
- (id<YTLRPCPlayerData>)playerData;
@end
@protocol YTLRPCTime <NSObject>
- (double)time;
@end
@protocol YTLRPCActiveVideo <NSObject>
- (double)totalMediaTime;
- (id<YTLRPCTime>)currentVideoTime;
@end
@protocol YTLRPCPlayer <NSObject>
- (id<YTLRPCPlayerResponse>)playerResponse;
- (id<YTLRPCPlayerResponse>)contentPlayerResponse;
- (NSString *)currentVideoID;
- (id<YTLRPCActiveVideo>)activeVideo;
@end

@implementation RPCMedia

// +[RPCMedia mediaWithPlayer:], VA 0x21aaf0.
+ (instancetype)mediaWithPlayer:(id)untypedPlayer {
    id<YTLRPCPlayer> player = untypedPlayer;
    id<YTLRPCPlayerResponse> response;
    if ([player respondsToSelector:@selector(playerResponse)]) {
        response = [player playerResponse];
    } else if ([player respondsToSelector:@selector(contentPlayerResponse)]) {
        response = [player contentPlayerResponse];
    } else {
        return nil;
    }
    if (!response) return nil;

    RPCMedia *media = [RPCMedia new];
    media.videoID = [player currentVideoID];
    media.title = [[[response playerData] videoDetails] title];
    media.author = [[[response playerData] videoDetails] author];
    media.totalTime = [[player activeVideo] totalMediaTime];
    media.currentTime = [[[player activeVideo] currentVideoTime] time];
    media.thumbnailURL = [[[[[response playerData] videoDetails] thumbnail] thumbnailsArray][0] URL];
    // The factory does not set isPaused. An empty (nonnull) thumbnail array
    // raises NSRangeException, as in the original objectAtIndexedSubscript:.
    return media;
}

@end
