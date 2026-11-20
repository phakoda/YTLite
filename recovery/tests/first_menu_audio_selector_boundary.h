#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstSelectorClassLookup(const char *);
Class FirstSelectorStringLookup(NSString *);
#define objc_getClass FirstSelectorClassLookup
#define NSClassFromString FirstSelectorStringLookup
