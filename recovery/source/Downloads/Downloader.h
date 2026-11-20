#pragma once
#import <Foundation/Foundation.h>
#import "DownloaderDelegate.h"
@interface Downloader : NSObject <NSURLSessionDownloadDelegate> {
    NSURLSession *_session;
    NSURLSessionDownloadTask *_downloadTask;
    NSString *_fileName;
    NSUInteger _chunkSize;
    NSUInteger _totalChunks;
    NSUInteger _downloadedChunks;
    NSFileHandle *_fileHandle;
    NSURL *_fileURL;
    long long _totalDownloadedBytes;
    long long _totalExpectedBytes;
    __weak id<DownloaderDelegate> _delegate;
}
@property(nonatomic, weak) id<DownloaderDelegate> delegate;
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name fileSize:(unsigned long long)size;
- (void)downloadNextChunk;
- (void)cancelDownload;
- (NSString *)getFilePath;
@end
