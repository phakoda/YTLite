#pragma once
#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>
#import <objc/runtime.h>
void FirstCaptionDispatch(dispatch_queue_t queue, dispatch_block_t block);
Class FirstCaptionStringLookup(NSString *name);
Class FirstCaptionClassLookup(const char *name);
#define dispatch_async FirstCaptionDispatch
#define NSClassFromString FirstCaptionStringLookup
#define objc_getClass FirstCaptionClassLookup
