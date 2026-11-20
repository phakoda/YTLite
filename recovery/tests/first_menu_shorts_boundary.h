#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstShortsClassLookup(const char *name);
Class FirstShortsStringLookup(NSString *name);
#define objc_getClass FirstShortsClassLookup
#define NSClassFromString FirstShortsStringLookup
