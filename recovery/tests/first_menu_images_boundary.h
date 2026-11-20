#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstImagesClassLookup(const char *name);
Class FirstImagesStringLookup(NSString *name);
#define objc_getClass FirstImagesClassLookup
#define NSClassFromString FirstImagesStringLookup
