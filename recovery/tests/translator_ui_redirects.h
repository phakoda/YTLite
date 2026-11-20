#import <Foundation/Foundation.h>
// Queue callbacks are retained and manually drained by the runtime fixture.
void TranslatorFixtureDispatchAsync(dispatch_queue_t queue,dispatch_block_t block);
#define dispatch_async TranslatorFixtureDispatchAsync
