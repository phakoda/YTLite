#pragma once
#import <Foundation/Foundation.h>
#import "downloads_presentation_declarations.h"
dispatch_queue_t FirstFFLifecycleQueue(const char *label, dispatch_queue_attr_t attributes) __attribute__((ns_returns_retained));
#define dispatch_queue_create FirstFFLifecycleQueue
