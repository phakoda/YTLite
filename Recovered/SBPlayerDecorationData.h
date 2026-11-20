#import <Foundation/Foundation.h>
@class UIView;
@class SBSegment;

// All methods in the package are synthesized accessors or ARC destruction.
@interface SBPlayerDecorationData : NSObject
@property(nonatomic, strong) NSArray<SBSegment *> *segments;
@property(nonatomic) double playerBarWidth;
@property(nonatomic) double mediaDuration;
@property(nonatomic, weak) UIView *barView;
@end
