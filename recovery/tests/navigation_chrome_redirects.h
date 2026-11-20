#pragma once
#import <Foundation/Foundation.h>
#import <objc/runtime.h>
Class NavigationFixtureClass(NSString *name);
Method NavigationFixtureMethod(Class cls, SEL selector);
#define NSClassFromString NavigationFixtureClass
#define class_getInstanceMethod NavigationFixtureMethod
