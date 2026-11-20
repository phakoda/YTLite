#import <Foundation/Foundation.h>

@class UIView;

/// Storage and ownership recovered from the nine packaged methods.
@interface SBPlayerDecorationData : NSObject
@property(nonatomic, strong) NSArray *segments;
@property(nonatomic) double playerBarWidth;
@property(nonatomic) double mediaDuration;
@property(nonatomic, weak) UIView *barView;
@end
