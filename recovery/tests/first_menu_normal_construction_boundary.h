#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstNormalClassLookup(const char *name);
Class FirstNormalStringLookup(NSString *name);
#define objc_getClass FirstNormalClassLookup
#define NSClassFromString FirstNormalStringLookup
