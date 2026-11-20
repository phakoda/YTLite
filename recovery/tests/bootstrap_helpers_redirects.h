#import <Foundation/Foundation.h>
void YTLHelpersTestLog(NSString *format, ...);
void YTLHelpersTestAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
dispatch_time_t YTLHelpersTestTime(dispatch_time_t base, int64_t delta);
#define NSLog YTLHelpersTestLog
#define dispatch_after YTLHelpersTestAfter
#define dispatch_time YTLHelpersTestTime
