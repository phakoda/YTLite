#pragma once
#import <Foundation/Foundation.h>

@interface Dvbug : NSObject
+ (id)instanceForObject:(id)object name:(NSString *)name;
+ (void)observeIvar:(id)object name:(NSString *)name;
+ (id)getObservedIvar:(id)object name:(NSString *)name;
+ (void)setObservedIvar:(id)object name:(NSString *)name value:(id)value;
+ (long long)getObservedIntIvar:(id)object name:(NSString *)name;
+ (long long)getObservedIvarLongLong:(id)object name:(NSString *)name;
+ (BOOL)getObservedBoolIvar:(id)object name:(NSString *)name;
+ (void)setObservedBoolIvar:(id)object name:(NSString *)name value:(BOOL)value;
@end
