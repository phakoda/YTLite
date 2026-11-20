#import "Downloader.h"
#import <math.h>
// Provenance: recovery/classes/Downloader.c, arm addresses below; async invoke 0x1ce0f4.
@implementation Downloader
@synthesize delegate = _delegate;
// 0x1cce24
- (instancetype)init {
    if ((self = [super init])) {
        _chunkSize = 0x500000;
        _downloadedChunks = 0;
        _session = [NSURLSession sessionWithConfiguration:[NSURLSessionConfiguration defaultSessionConfiguration]
                                                 delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    }
    return self;
}
// 0x1ccf54; fcvtpu at 0x1cd2f4, not the decompiler's truncating cast.
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name fileSize:(unsigned long long)size {
    _fileName = name;
    _fileURL = url;
    _totalExpectedBytes = (long long)size;
    _totalChunks = (NSUInteger)ceil((double)size / (double)_chunkSize);
    NSString *path = [self getFilePath];
    NSFileManager *manager = [NSFileManager defaultManager];
    [manager removeItemAtPath:path error:nil];
    if (![manager fileExistsAtPath:path]) {
        [manager createFileAtPath:path contents:nil attributes:@{NSFileSize: @((NSUInteger)size)}];
    }
    _fileHandle = [NSFileHandle fileHandleForWritingAtPath:path];
    NSError *error = nil;
    if (![_fileHandle truncateAtOffset:size error:&error]) {
        NSLog(@"YTPlus --- Truncate failed with error: %@", error);
    }
    [self downloadNextChunk];
}
// 0x1cd570. The original does not clamp the last Range to the file size.
- (void)downloadNextChunk {
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:_fileURL];
    NSUInteger start = _chunkSize * _downloadedChunks;
    [request setValue:[NSString stringWithFormat:@"bytes=%lu-%lu", (unsigned long)start,
                       (unsigned long)(start + _chunkSize - 1)] forHTTPHeaderField:@"Range"];
    NSURLSessionDownloadTask *task = [_session downloadTaskWithRequest:request];
    [task resume];
    _downloadTask = task;
}
// 0x1cd81c. An explicit cancellation notification precedes the session's own callback.
- (void)cancelDownload {
    if (_downloadTask) {
        [_downloadTask cancel];
        [_fileHandle closeFile];
        NSError *error = [NSError errorWithDomain:NSURLErrorDomain code:NSURLErrorCancelled userInfo:nil];
        if ([_delegate respondsToSelector:@selector(downloadDidFailureWithError:)]) {
            [_delegate downloadDidFailureWithError:error];
        }
        [[NSFileManager defaultManager] removeItemAtPath:[self getFilePath] error:nil];
    }
}
// 0x1cd9f8; closed by raw 0x1cde10–0x1cdf18.
- (NSString *)getFilePath {
    NSString *directory = NSTemporaryDirectory();
    BOOL isDirectory = NO;
    NSFileManager *manager = [NSFileManager defaultManager];
    if (![manager fileExistsAtPath:directory isDirectory:&isDirectory] || !isDirectory) {
        NSError *error = nil;
        [manager createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:&error];
        if (error) NSLog(@"YTPlus --- Error creating temporary directory: %@", error.localizedDescription);
    }
    return [directory stringByAppendingPathComponent:_fileName];
}
// 0x1cdf18. Deliberately counts per-callback bytes, with single-precision progress.
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)task
     didWriteData:(int64_t)bytesWritten totalBytesWritten:(int64_t)totalBytesWritten
 totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    (void)session; (void)task; (void)totalBytesWritten; (void)totalBytesExpectedToWrite;
    _totalDownloadedBytes = (long long)((unsigned long long)_totalDownloadedBytes + (unsigned long long)bytesWritten);
    float progress = (float)_totalDownloadedBytes / (float)_totalExpectedBytes;
    if ([_delegate respondsToSelector:@selector(downloadProgress:)]) [_delegate downloadProgress:progress];
}
// 0x1ce018, block 0x1ce0f4: synchronous read, global-queue write/notification.
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)task
 didFinishDownloadingToURL:(NSURL *)location {
    (void)session; (void)task;
    NSData *data = [NSData dataWithContentsOfURL:location];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @synchronized (self->_fileHandle) {
            [self->_fileHandle seekToFileOffset:self->_chunkSize * self->_downloadedChunks];
            [self->_fileHandle writeData:data];
        }
        self->_downloadedChunks++;
        if (self->_downloadedChunks == self->_totalChunks) {
            [self->_fileHandle closeFile];
            if ([self->_delegate respondsToSelector:@selector(downloadDidFinish:fileName:)]) {
                // Original uses URLWithString:, not fileURLWithPath:.
                [self->_delegate downloadDidFinish:[NSURL URLWithString:[self getFilePath]] fileName:self->_fileName];
            }
        } else {
            [self downloadNextChunk];
        }
    });
}
// 0x1ce31c
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(NSError *)error {
    (void)session; (void)task;
    if (error) {
        [_fileHandle closeFile];
        if ([_delegate respondsToSelector:@selector(downloadDidFailureWithError:)]) [_delegate downloadDidFailureWithError:error];
        [[NSFileManager defaultManager] removeItemAtPath:[self getFilePath] error:nil];
    }
}
// ARC supplies the exact weak accessors (0x1ce4c4/0x1ce4dc) and .cxx_destruct (0x1ce510).
@end
