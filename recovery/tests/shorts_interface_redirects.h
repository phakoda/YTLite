#import <dispatch/dispatch.h>
void ShortsFixtureAsync(dispatch_queue_t queue, dispatch_block_t block);
#define dispatch_async ShortsFixtureAsync
