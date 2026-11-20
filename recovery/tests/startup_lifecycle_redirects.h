#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import <dispatch/dispatch.h>
@interface StartupFixtureLayer : NSObject
@property(nonatomic) CGRect frame;
@property(nonatomic) float opacity;
@property(nonatomic,strong) NSMutableArray *sublayers;
- (void)addSublayer:(StartupFixtureLayer *)layer;
- (void)removeFromSuperlayer;
@end
@interface StartupFixtureTransaction : NSObject
+ (void)begin;
+ (void)setAnimationDuration:(double)duration;
+ (void)setCompletionBlock:(dispatch_block_t)block;
+ (void)commit;
@end
@interface StartupFixtureFileManager : NSObject
+ (instancetype)defaultManager;
- (BOOL)fileExistsAtPath:(NSString *)path;
- (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error;
@end
@interface StartupFixtureNotificationCenter : NSObject
+ (instancetype)defaultCenter;
- (id)addObserverForName:(NSString *)name object:(id)object queue:(NSOperationQueue *)queue usingBlock:(void (^)(NSNotification *))block;
- (void)removeObserver:(id)observer;
@end
@interface StartupFixtureBundle : NSObject
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table;
@end
NSArray<NSString *> *StartupFixtureSearchPaths(NSSearchPathDirectory directory,NSSearchPathDomainMask mask,BOOL expand);
NSString *StartupFixtureTemporaryDirectory(void);
void StartupFixtureAsync(dispatch_queue_t queue,dispatch_block_t block);
void StartupFixtureAfter(dispatch_time_t time,dispatch_queue_t queue,dispatch_block_t block);
dispatch_time_t StartupFixtureTime(dispatch_time_t when,int64_t delta);
#define CALayer StartupFixtureLayer
#define CATransaction StartupFixtureTransaction
#define NSFileManager StartupFixtureFileManager
#define NSNotificationCenter StartupFixtureNotificationCenter
#define NSBundle StartupFixtureBundle
#define NSSearchPathForDirectoriesInDomains StartupFixtureSearchPaths
#define NSTemporaryDirectory StartupFixtureTemporaryDirectory
#define dispatch_async StartupFixtureAsync
#define dispatch_after StartupFixtureAfter
#define dispatch_time StartupFixtureTime

#define AVAudioSession StartupFixtureAudioSession
#define AVPlayer StartupFixturePlayer
#define AVPlayerLayer StartupFixturePlayerLayer
