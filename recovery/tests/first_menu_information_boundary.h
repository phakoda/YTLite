#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class FirstInformationClassLookup(const char *name);
Class FirstInformationStringLookup(NSString *name);
#define objc_getClass FirstInformationClassLookup
#define NSClassFromString FirstInformationStringLookup
