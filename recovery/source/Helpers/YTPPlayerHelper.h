#pragma once
#import <Foundation/Foundation.h>
@class UIViewController;

@interface YTPPlayerHelper : NSObject
+ (NSString *)getVideoID:(id)value;
+ (void)openVideoWithID:(id)videoID;
+ (void)openVideoWithID:(id)videoID handler:(id)handler;
+ (void)openVideoWithID:(id)videoID viewController:(UIViewController *)controller;
@end
