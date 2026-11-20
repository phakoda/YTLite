#pragma once
#import <Foundation/Foundation.h>
#import "downloads_presentation_declarations.h"
void FirstFFProgressAsync(dispatch_queue_t queue, dispatch_block_t block);
#define dispatch_async FirstFFProgressAsync
