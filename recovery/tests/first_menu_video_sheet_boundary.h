#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstVideoSheetClassLookup(const char *name);
Class FirstVideoSheetStringLookup(NSString *name);
#define objc_getClass FirstVideoSheetClassLookup
#define NSClassFromString FirstVideoSheetStringLookup
