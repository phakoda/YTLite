#pragma once
#import <Foundation/Foundation.h>
// Recovered optional callbacks, not NSURLSession's cumulative progress signature.
@protocol DownloaderDelegate <NSObject>
@optional
- (void)downloadProgress:(float)progress;
- (void)downloadDidFinish:(NSURL *)url fileName:(NSString *)fileName;
- (void)downloadDidFailureWithError:(NSError *)error;
@end
