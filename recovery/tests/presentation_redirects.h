#pragma once
// TEST ONLY. Included before owned .m files for the native macOS fixture build.
// iOS compilation never includes this file or the presentation_shims directory.
#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>

FOUNDATION_EXPORT void PresentationDispatchAsync(dispatch_queue_t queue, dispatch_block_t block);
FOUNDATION_EXPORT void PresentationDispatchAfter(dispatch_time_t time, dispatch_queue_t queue, dispatch_block_t block);
FOUNDATION_EXPORT dispatch_time_t PresentationDispatchTime(dispatch_time_t when, int64_t delta);
#define dispatch_async PresentationDispatchAsync
#define dispatch_after PresentationDispatchAfter
#define dispatch_time PresentationDispatchTime
#define NSTimer PresentationFixtureTimer
#define NSRunLoop PresentationFixtureRunLoop
#define NSURLSession PresentationFixtureURLSession
#define NSURLSessionDataTask PresentationFixtureURLSessionDataTask
#define NSTemporaryDirectory PresentationFixtureTemporaryDirectory
#define NSBundle PresentationFixtureBundle
#define NSLog PresentationFixtureLog

// Used only by the verifier's recorded @available-expression host substitution.
FOUNDATION_EXPORT BOOL PresentationSheetNativeAvailable(void);
FOUNDATION_EXPORT NSString *PresentationFixtureTemporaryDirectory(void);
FOUNDATION_EXPORT void PresentationFixtureLog(NSString *format, ...) NS_FORMAT_FUNCTION(1,2);
@interface PresentationFixtureBundle : NSObject
@property(nonatomic,readonly) NSString *bundlePath;
+ (instancetype)mainBundle;
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table;
@end

@interface PresentationFixtureTimer : NSObject
@property(nonatomic) NSTimeInterval timeInterval;
@property(nonatomic) BOOL valid, repeats;
@property(nonatomic, copy) void (^fixtureBlock)(PresentationFixtureTimer *timer);
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats
                               block:(void (^)(PresentationFixtureTimer *timer))block;
- (void)invalidate;
@end
@interface PresentationFixtureRunLoop : NSObject
@property(nonatomic, strong) NSMutableArray<PresentationFixtureTimer *> *timers;
+ (instancetype)mainRunLoop;
- (void)addTimer:(PresentationFixtureTimer *)timer forMode:(NSRunLoopMode)mode;
@end
@interface PresentationFixtureURLSessionDataTask : NSObject
@property(nonatomic, strong) NSURL *fixtureURL;
@property(nonatomic) BOOL fixtureResumed;
@property(nonatomic, copy) void (^fixtureCompletion)(NSData *, NSURLResponse *, NSError *);
- (void)resume;
@end
@interface PresentationFixtureURLSession : NSObject
+ (instancetype)sharedSession;
- (PresentationFixtureURLSessionDataTask *)dataTaskWithURL:(NSURL *)url
                                      completionHandler:(void (^)(NSData *, NSURLResponse *, NSError *))completion;
@end
