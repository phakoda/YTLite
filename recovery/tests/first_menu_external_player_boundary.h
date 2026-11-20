#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstExternalClassLookup(const char *name);
Class FirstExternalStringLookup(NSString *name);
#define objc_getClass FirstExternalClassLookup
#define NSClassFromString FirstExternalStringLookup
