#import <Foundation/Foundation.h>

// Property types and ownership: recovery/evidence/arm-classes.json.
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
