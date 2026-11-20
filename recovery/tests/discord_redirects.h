#import <Foundation/Foundation.h>
void YTLDiscordTestAsync(dispatch_queue_t queue, dispatch_block_t block);
void YTLDiscordTestAfter(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block);
dispatch_time_t YTLDiscordTestTime(dispatch_time_t base, int64_t delta);
#define dispatch_async YTLDiscordTestAsync
#define dispatch_after YTLDiscordTestAfter
#define dispatch_time YTLDiscordTestTime
