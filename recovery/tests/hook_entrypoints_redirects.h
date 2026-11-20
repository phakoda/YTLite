#import <Foundation/Foundation.h>
void HookEntrypointsDispatchAsync(dispatch_queue_t queue, dispatch_block_t block);
#define dispatch_async HookEntrypointsDispatchAsync
