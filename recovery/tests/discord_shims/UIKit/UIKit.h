#pragma once
#import <Foundation/Foundation.h>
extern NSString *const UIApplicationOpenSettingsURLString;
@interface UIApplication : NSObject
+ (instancetype)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
