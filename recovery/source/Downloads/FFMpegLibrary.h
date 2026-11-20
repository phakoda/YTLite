#pragma once
#import <Foundation/Foundation.h>
// Declaration-only boundary for the bundled mobile-ffmpeg library. Its classes and
// return-code globals must be supplied by the actual library at link/load time.
// No FFmpeg class implementation or substitute codec pipeline is defined here.
@class Statistics;
@protocol StatisticsDelegate <NSObject>
- (void)statisticsCallback:(Statistics *)statistics;
@end
@protocol LogDelegate <NSObject>
- (void)logCallback:(long long)executionId :(int)level :(NSString *)message;
@end
@interface MobileFFmpeg : NSObject
+ (int)execute:(NSString *)command;
+ (void)cancel;
@end
@interface MobileFFmpegConfig : NSObject
+ (void)resetStatistics;
+ (void)setLogDelegate:(id<LogDelegate>)delegate;
+ (void)setStatisticsDelegate:(id<StatisticsDelegate>)delegate;
+ (NSString *)getLastCommandOutput;
@end
FOUNDATION_EXPORT const int RETURN_CODE_SUCCESS;
FOUNDATION_EXPORT const int RETURN_CODE_CANCEL;
@protocol YTPDownloadsStatistics <NSObject>
- (int)getTime;
@end
