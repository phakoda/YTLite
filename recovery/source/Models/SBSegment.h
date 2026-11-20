#import <Foundation/Foundation.h>

/// Reconstructed from recovery/classes/SBSegment.c and arm-classes.json.
/// Strings are retained, not copied, as in the packaged class.
@interface SBSegment : NSObject
@property(nonatomic, strong) NSString *uuid;
@property(nonatomic, strong) NSString *category;
@property(nonatomic, strong) NSString *actionType;
@property(nonatomic, strong) NSString *segmentDescription;
@property(nonatomic) double start;
@property(nonatomic) double end;
@property(nonatomic) double videoDuration;
@property(nonatomic) BOOL locked;
@property(nonatomic) NSInteger votes;
+ (instancetype)segmentWithDictionary:(NSDictionary *)dictionary;
@end
