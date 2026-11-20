#pragma once
#import <Foundation/Foundation.h>
#import "downloads_presentation_declarations.h"
Class FirstFFClassLookup(NSString *name);
#define NSClassFromString FirstFFClassLookup
void FirstFFAsync(dispatch_queue_t queue, dispatch_block_t block);
#define dispatch_async FirstFFAsync
