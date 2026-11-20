#import "RPCMedia.h"

// Narrow host contracts, not replacement definitions for YouTube classes.
// In particular, the two time selectors return doubles, not object pointers.
@protocol YTLRecoveredRPCTime <NSObject>
- (double)time;
@end
@protocol YTLRecoveredRPCActiveVideo <NSObject>
- (double)totalMediaTime;
- (id<YTLRecoveredRPCTime>)currentVideoTime;
@end
@protocol YTLRecoveredRPCThumbnail <NSObject>
- (NSString *)URL;
@end
@protocol YTLRecoveredRPCThumbnails <NSObject>
- (NSArray<id<YTLRecoveredRPCThumbnail>> *)thumbnailsArray;
@end
@protocol YTLRecoveredRPCDetails <NSObject>
- (NSString *)title;
- (NSString *)author;
- (id<YTLRecoveredRPCThumbnails>)thumbnail;
@end
@protocol YTLRecoveredRPCPlayerData <NSObject>
- (id<YTLRecoveredRPCDetails>)videoDetails;
@end
@protocol YTLRecoveredRPCResponse <NSObject>
- (id<YTLRecoveredRPCPlayerData>)playerData;
@end
@protocol YTLRecoveredRPCPlayer <NSObject>
- (NSString *)currentVideoID;
- (id<YTLRecoveredRPCActiveVideo>)activeVideo;
@optional
- (id<YTLRecoveredRPCResponse>)playerResponse;
- (id<YTLRecoveredRPCResponse>)contentPlayerResponse;
@end

@implementation RPCMedia

// +[RPCMedia mediaWithPlayer:], 0x21aaf0.
+ (instancetype)mediaWithPlayer:(id<YTLRecoveredRPCPlayer>)player {
    id<YTLRecoveredRPCResponse> response = nil;
    if ([player respondsToSelector:@selector(playerResponse)]) {
        response = [player playerResponse];
    } else if ([player respondsToSelector:@selector(contentPlayerResponse)]) {
        response = [player contentPlayerResponse];
    } else {
        return nil;
    }
    if (!response) return nil;

    RPCMedia *media = [[RPCMedia alloc] init];
    media.videoID = [player currentVideoID];
    media.title = [[[response playerData] videoDetails] title];
    media.author = [[[response playerData] videoDetails] author];
    media.totalTime = [[player activeVideo] totalMediaTime];
    media.currentTime = [[[player activeVideo] currentVideoTime] time];
    // The binary uses subscript zero (not firstObject). An empty, non-nil
    // thumbnails array therefore raises, rather than silently returning nil.
    media.thumbnailURL = [[[[[response playerData] videoDetails] thumbnail]
                           thumbnailsArray][0] URL];
    // isPaused is not populated by this factory in the package.
    return media;
}

// Accessors 0x21af10..0x21b010 and ARC destruction at 0x21b040.
@end
