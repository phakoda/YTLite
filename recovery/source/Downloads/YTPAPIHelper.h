#pragma once
#import <Foundation/Foundation.h>
@interface YTPAPIHelper : NSObject
// Invoke 0x1cb938 passes exactly one NSURL* (or nil), not image bytes and not an error pair.
+ (void)fetchChannelImageWithChannelID:(NSString *)channelID completion:(void (^)(NSURL *url))completion;
@end
