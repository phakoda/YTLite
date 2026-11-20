#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstStorageClassLookup(const char *name);
Class FirstStorageStringLookup(NSString *name);
#define objc_getClass FirstStorageClassLookup
#define NSClassFromString FirstStorageStringLookup
