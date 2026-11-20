#import "SBSegment.h"

@implementation SBSegment

// +[SBSegment segmentWithDictionary:], VA 0x193a60.
+ (instancetype)segmentWithDictionary:(NSDictionary *)dictionary {
    if (!dictionary) return nil;
    id interval = dictionary[@"segment"];
    if (![interval isKindOfClass:NSArray.class] || [interval count] != 2) return nil;

    // The binary allocates SBSegment, not self, and accepts NSNumber-compatible
    // values without sorting, clamping, or rejecting reversed intervals.
    SBSegment *segment = [SBSegment new];
    segment.uuid = dictionary[@"UUID"];
    segment.category = dictionary[@"category"];
    segment.actionType = dictionary[@"actionType"];
    segment.segmentDescription = dictionary[@"description"];
    segment.start = [dictionary[@"segment"][0] doubleValue];
    segment.end = [dictionary[@"segment"][1] doubleValue];
    segment.videoDuration = [dictionary[@"videoDuration"] doubleValue];
    segment.locked = [dictionary[@"locked"] boolValue];
    segment.votes = [dictionary[@"votes"] integerValue];
    return segment;
}

@end
