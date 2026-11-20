#pragma once
#import <Foundation/Foundation.h>
#import "DownloaderDelegate.h"
@interface YTPDownloader : NSObject <NSURLSessionDataDelegate> {
    NSURLSession *_session;
    NSURLSessionDataTask *_dataTask;
    NSFileHandle *_fileHandle;
    NSString *_fileName;
    NSString *_videoID;
    long long _totalFileSize;
    long long _downloadedSize;
    NSMutableDictionary *_chunkMap;
    NSUInteger _chunkSize;
    NSString *_filePath;
    NSString *_chunkMapPath;
    __weak id<DownloaderDelegate> _delegate;
}
@property(nonatomic, weak) id<DownloaderDelegate> delegate;
- (void)cancelDownload;
- (void)cleanup;
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID fileSize:(unsigned long long)size;
- (NSData *)hashForFile:(NSString *)name fileSize:(unsigned long long)size;
- (NSString *)createTempDirectoryIfNeeded;
- (NSString *)getFilePath;
- (NSString *)getChunkMapPath;
- (void)saveChunkMap;
- (BOOL)loadChunkMap;
- (void)continueDownloadingForURL:(NSURL *)url;
@end
