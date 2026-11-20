#pragma once
#import <Foundation/Foundation.h>
@interface MPRemoteCommand : NSObject
@property(nonatomic,getter=isEnabled) BOOL enabled;
- (void)addTarget:(id)target action:(SEL)action;
@end
@interface MPSkipIntervalCommand : MPRemoteCommand
@property(nonatomic,copy) NSArray<NSNumber *> *preferredIntervals;
@end
@interface MPRemoteCommandCenter : NSObject
+ (instancetype)sharedCommandCenter;
@property(nonatomic,strong) MPRemoteCommand *previousTrackCommand;
@property(nonatomic,strong) MPRemoteCommand *nextTrackCommand;
@property(nonatomic,strong) MPSkipIntervalCommand *skipBackwardCommand;
@property(nonatomic,strong) MPSkipIntervalCommand *skipForwardCommand;
@end
@interface MPNowPlayingInfoCenter : NSObject
- (void)setNowPlayingInfo:(NSDictionary *)info;
@end
