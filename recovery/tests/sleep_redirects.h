#import <Foundation/Foundation.h>
// Capture scheduling while retaining real libdispatch source lifecycle checks.
void YTLSleepTestAsync(dispatch_queue_t queue, dispatch_block_t block);
void YTLSleepTestAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
void YTLSleepTestSetTimer(dispatch_source_t timer, dispatch_time_t start, uint64_t interval, uint64_t leeway);
void YTLSleepTestSetHandler(dispatch_source_t timer, dispatch_block_t block);
dispatch_time_t YTLSleepTestTime(dispatch_time_t base, int64_t delta);
#define dispatch_async YTLSleepTestAsync
#define dispatch_after YTLSleepTestAfter
#define dispatch_source_set_timer YTLSleepTestSetTimer
#define dispatch_source_set_event_handler YTLSleepTestSetHandler
#define dispatch_time YTLSleepTestTime
