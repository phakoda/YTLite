#pragma once
#import <Foundation/Foundation.h>
@class SBSegment;

@interface SBManager : NSObject {
@private
    NSString *_categories;
}
@property(nonatomic, strong) NSMutableDictionary<NSString *, NSMutableArray<SBSegment *> *> *segments;
+ (instancetype)sharedManager;
- (void)getSegmentsForID:(NSString *)videoID;
@end
