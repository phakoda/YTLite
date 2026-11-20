#pragma once
#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>
// These macros affect fixture builds ONLY. iOS objects have no redirections.
FOUNDATION_EXPORT NSArray *SettingsFixtureSearchPaths(NSSearchPathDirectory directory,NSSearchPathDomainMask domain,BOOL expand);
FOUNDATION_EXPORT NSString *SettingsFixtureTemporaryDirectory(void);
FOUNDATION_EXPORT void SettingsFixtureDispatchAsync(dispatch_queue_t queue,dispatch_block_t block);
FOUNDATION_EXPORT void SettingsFixtureDispatchAfter(dispatch_time_t when,dispatch_queue_t queue,dispatch_block_t block);
@interface SettingsFixtureTask : NSObject
@property(nonatomic) BOOL resumed;
- (void)resume;
@end
@interface SettingsFixtureSession : NSObject
@property(nonatomic,strong) NSURL *url;
@property(nonatomic,strong) SettingsFixtureTask *task;
@property(nonatomic,copy) void (^handler)(NSData *,NSURLResponse *,NSError *);
+ (instancetype)sharedSession;
- (SettingsFixtureTask *)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData *,NSURLResponse *,NSError *))handler;
@end
#define NSSearchPathForDirectoriesInDomains SettingsFixtureSearchPaths
#define NSTemporaryDirectory SettingsFixtureTemporaryDirectory
#define dispatch_async SettingsFixtureDispatchAsync
#define dispatch_after SettingsFixtureDispatchAfter
#define NSURLSession SettingsFixtureSession
