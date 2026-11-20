#import "SBSegment.h"

@implementation SBSegment

// +[SBSegment segmentWithDictionary:], 0x193a60.
+ (instancetype)segmentWithDictionary:(NSDictionary *)dictionary {
    if (!dictionary) return nil;
    id times = dictionary[@"segment"];
    if (![times isKindOfClass:[NSArray class]] || [times count] != 2) return nil;

    // The binary allocates SBSegment, rather than dynamically allocating self.
    SBSegment *segment = [[SBSegment alloc] init];
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

// Accessors 0x19435c..0x1944dc and .cxx_destruct at 0x1944fc are
// synthesized by Clang/ARC from the recovered property attributes.
@end
