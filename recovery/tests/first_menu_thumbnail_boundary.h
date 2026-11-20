#pragma once
#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>
void FirstThumbnailDispatch(dispatch_queue_t queue, dispatch_block_t block);
NSString *FirstThumbnailTemporaryDirectory(void);
#define dispatch_async FirstThumbnailDispatch
#define NSTemporaryDirectory FirstThumbnailTemporaryDirectory
