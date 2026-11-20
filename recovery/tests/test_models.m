#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "SBSegment.h"
#import "SBPlayerDecorationData.h"
#import "RPCMedia.h"
#import "DVNCell.h"
#import "DVNSection.h"

extern void testSettingsModels(void);

static NSUInteger assertions;
#define REQUIRE(condition) do { \
    assertions++; \
    if (!(condition)) { \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
        abort(); \
    } \
} while (0)

@interface SegmentSubclass : SBSegment @end
@implementation SegmentSubclass @end
@interface RPCSubclass : RPCMedia @end
@implementation RPCSubclass @end

@interface FixtureVideoTime : NSObject
@property(nonatomic) double time;
@end
@implementation FixtureVideoTime @end
@interface FixtureActiveVideo : NSObject
@property(nonatomic) double totalMediaTime;
@property(nonatomic, strong) FixtureVideoTime *currentVideoTime;
@end
@implementation FixtureActiveVideo @end
@interface FixtureThumbnail : NSObject
@property(nonatomic, copy) NSString *URL;
@end
@implementation FixtureThumbnail @end
@interface FixtureThumbnailDetails : NSObject
@property(nonatomic, strong) NSArray *thumbnailsArray;
@end
@implementation FixtureThumbnailDetails @end
@interface FixtureDetails : NSObject
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *author;
@property(nonatomic, strong) FixtureThumbnailDetails *thumbnail;
@end
@implementation FixtureDetails @end
@interface FixturePlayerData : NSObject
@property(nonatomic, strong) FixtureDetails *videoDetails;
@end
@implementation FixturePlayerData @end
@interface FixtureResponse : NSObject
@property(nonatomic, strong) FixturePlayerData *playerData;
@end
@implementation FixtureResponse @end
@interface FixturePlayerBase : NSObject
@property(nonatomic, copy) NSString *currentVideoID;
@property(nonatomic, strong) FixtureActiveVideo *activeVideo;
@property(nonatomic, strong) FixtureResponse *response;
@property(nonatomic) NSUInteger fallbackCalls;
@end
@implementation FixturePlayerBase @end
@interface FixtureFallbackPlayer : FixturePlayerBase
- (FixtureResponse *)contentPlayerResponse;
@end
@implementation FixtureFallbackPlayer
- (FixtureResponse *)contentPlayerResponse { self.fallbackCalls++; return self.response; }
@end
@interface FixturePrimaryPlayer : FixtureFallbackPlayer
- (FixtureResponse *)playerResponse;
@end
@implementation FixturePrimaryPlayer
- (FixtureResponse *)playerResponse { return self.response; }
@end

static void testSegments(void) {
    REQUIRE([SBSegment segmentWithDictionary:nil] == nil);
    REQUIRE([SBSegment segmentWithDictionary:@{}] == nil);
    REQUIRE([SBSegment segmentWithDictionary:@{@"segment": @"invalid"}] == nil);
    REQUIRE([SBSegment segmentWithDictionary:@{@"segment": @[@1]}] == nil);
    NSArray *tooMany = @[@1, @2, @3];
    REQUIRE([SBSegment segmentWithDictionary:@{@"segment": tooMany}] == nil);

    NSMutableString *uuid = [@"segment-1" mutableCopy];
    NSDictionary *dictionary = @{@"segment": @[@"12.25", @"4.5"], @"UUID": uuid,
        @"category": @"sponsor", @"actionType": @"skip", @"description": @"intro",
        @"videoDuration": @90.75, @"locked": @YES, @"votes": @((NSInteger)1 << 40)};
    SBSegment *segment = [SBSegment segmentWithDictionary:dictionary];
    REQUIRE(segment.start == 12.25 && segment.end == 4.5);
    REQUIRE(segment.videoDuration == 90.75 && segment.locked);
    REQUIRE(segment.votes == ((NSInteger)1 << 40));
    REQUIRE([segment.category isEqual:@"sponsor"]);
    REQUIRE([segment.actionType isEqual:@"skip"]);
    REQUIRE([segment.segmentDescription isEqual:@"intro"]);
    [uuid appendString:@"-mutated"];
    REQUIRE(segment.uuid == uuid);
    REQUIRE([segment.uuid isEqual:@"segment-1-mutated"]);
    REQUIRE([[SegmentSubclass segmentWithDictionary:dictionary] class] == SBSegment.class);

    NSArray *interval = @[@1, @2];
    SBSegment *minimal = [SBSegment segmentWithDictionary:@{@"segment": interval}];
    REQUIRE(minimal != nil && minimal.videoDuration == 0 && minimal.votes == 0 && !minimal.locked);
    REQUIRE(minimal.uuid == nil && minimal.category == nil);
}

static void testDecoration(void) {
    SBPlayerDecorationData *data = [SBPlayerDecorationData new];
    REQUIRE(data.segments == nil && data.barView == nil);
    data.playerBarWidth = 201.125;
    data.mediaDuration = 7200.5;
    REQUIRE(data.playerBarWidth == 201.125 && data.mediaDuration == 7200.5);
    NSMutableArray *segments = [NSMutableArray array];
    data.segments = segments;
    REQUIRE(data.segments == segments);
    @autoreleasepool {
        NSObject *view = [NSObject new];
        data.barView = (id)view;
        REQUIRE((id)data.barView == view);
    }
    REQUIRE(data.barView == nil);
}

static FixtureResponse *makeResponse(void) {
    FixtureThumbnail *thumbnail = [FixtureThumbnail new];
    thumbnail.URL = @"https://invalid.example/thumbnail";
    FixtureThumbnailDetails *thumbnails = [FixtureThumbnailDetails new];
    thumbnails.thumbnailsArray = @[thumbnail];
    FixtureDetails *details = [FixtureDetails new];
    details.title = @"Title";
    details.author = @"Author";
    details.thumbnail = thumbnails;
    FixturePlayerData *data = [FixturePlayerData new];
    data.videoDetails = details;
    FixtureResponse *response = [FixtureResponse new];
    response.playerData = data;
    return response;
}

static void testRPC(void) {
    REQUIRE([RPCMedia mediaWithPlayer:nil] == nil);
    REQUIRE([RPCMedia mediaWithPlayer:[NSObject new]] == nil);
    FixturePrimaryPlayer *primary = [FixturePrimaryPlayer new];
    REQUIRE([RPCMedia mediaWithPlayer:primary] == nil && primary.fallbackCalls == 0);
    primary.currentVideoID = @"video-1";
    primary.response = makeResponse();
    primary.activeVideo = [FixtureActiveVideo new];
    primary.activeVideo.totalMediaTime = 1234.875;
    primary.activeVideo.currentVideoTime = [FixtureVideoTime new];
    primary.activeVideo.currentVideoTime.time = 12.125;
    RPCMedia *media = [RPCMedia mediaWithPlayer:primary];
    REQUIRE([media.videoID isEqual:@"video-1"] && [media.title isEqual:@"Title"]);
    REQUIRE([media.author isEqual:@"Author"]);
    REQUIRE(media.totalTime == 1234.875 && media.currentTime == 12.125);
    REQUIRE([media.thumbnailURL isEqual:@"https://invalid.example/thumbnail"]);
    REQUIRE(!media.isPaused && primary.fallbackCalls == 0);
    media.isPaused = YES;
    REQUIRE(media.isPaused);
    REQUIRE([[RPCSubclass mediaWithPlayer:primary] class] == RPCMedia.class);

    NSMutableString *value = [@"before" mutableCopy];
    media.videoID = value; media.title = value; media.author = value; media.thumbnailURL = value;
    [value appendString:@"-after"];
    REQUIRE([media.videoID isEqual:@"before"] && [media.title isEqual:@"before"]);
    REQUIRE([media.author isEqual:@"before"] && [media.thumbnailURL isEqual:@"before"]);

    FixtureFallbackPlayer *fallback = [FixtureFallbackPlayer new];
    fallback.response = primary.response;
    REQUIRE([RPCMedia mediaWithPlayer:fallback] != nil && fallback.fallbackCalls == 1);
    primary.response.playerData.videoDetails.thumbnail.thumbnailsArray = @[];
    BOOL rangeException = NO;
    @try { (void)[RPCMedia mediaWithPlayer:primary]; }
    @catch (NSException *exception) { rangeException = [exception.name isEqual:NSRangeException]; }
    REQUIRE(rangeException);
}

static NSDictionary *runtimeMetadata(Class cls) {
    NSMutableArray *methods = [NSMutableArray array];
    for (NSNumber *meta in @[@NO, @YES]) {
        unsigned count = 0;
        Method *list = class_copyMethodList(meta.boolValue ? object_getClass(cls) : cls, &count);
        for (unsigned i = 0; i < count; i++) {
            [methods addObject:@{@"kind": meta.boolValue ? @"+" : @"-",
                @"selector": NSStringFromSelector(method_getName(list[i])),
                @"encoding": @(method_getTypeEncoding(list[i]))}];
        }
        free(list);
    }
    return @{@"name": NSStringFromClass(cls), @"methods": methods};
}

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        testSegments(); testDecoration(); testRPC(); testSettingsModels();
        if (argc == 2) {
            NSArray *metadata = @[runtimeMetadata(SBSegment.class),
                runtimeMetadata(SBPlayerDecorationData.class), runtimeMetadata(RPCMedia.class),
                runtimeMetadata(DVNCell.class), runtimeMetadata(DVNSection.class)];
            NSError *error = nil;
            NSData *json = [NSJSONSerialization dataWithJSONObject:metadata options:NSJSONWritingPrettyPrinted error:&error];
            REQUIRE(json != nil && error == nil);
            REQUIRE([json writeToFile:@(argv[1]) atomically:YES]);
        }
        printf("Model runtime tests: %lu assertions passed.\n", (unsigned long)assertions);
    }
    return 0;
}
