#import <Foundation/Foundation.h>
void YTLManagerDispatch(dispatch_queue_t queue, dispatch_block_t block);
int YTLManagerSyncEnter(id object);
int YTLManagerSyncExit(id object);
#define dispatch_async YTLManagerDispatch
