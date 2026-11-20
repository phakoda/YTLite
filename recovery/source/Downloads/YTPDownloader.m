#import "YTPDownloader.h"
#import <CommonCrypto/CommonDigest.h>
#import <string.h>
// Provenance: recovery/classes/YTPDownloader.c and closed raw regions recorded in PROVENANCE.md.
@implementation YTPDownloader
@synthesize delegate = _delegate;
// 0x1cfddc
- (instancetype)init {
    if ((self = [super init])) {
        _session = [NSURLSession sessionWithConfiguration:[NSURLSessionConfiguration defaultSessionConfiguration]
                                                 delegate:self delegateQueue:[NSOperationQueue mainQueue]];
        _chunkSize = 0x500000;
        _chunkMap = [NSMutableDictionary dictionary];
    }
    return self;
}
// 0x1cff34
- (void)cancelDownload {
    [_dataTask cancel];
    [self cleanup];
    [[NSFileManager defaultManager] removeItemAtPath:_filePath error:nil];
}
// 0x1cffa8. Completed maps intentionally survive; incomplete maps are removed.
- (void)cleanup {
    @synchronized (_fileHandle) {
        if (_fileHandle) { [_fileHandle closeFile]; _fileHandle = nil; }
    }
    if (_downloadedSize < _totalFileSize && _chunkMapPath && [[NSFileManager defaultManager] fileExistsAtPath:_chunkMapPath]) {
        [[NSFileManager defaultManager] removeItemAtPath:_chunkMapPath error:nil];
    }
    _dataTask = nil;
    _chunkMap = nil;
}
// 0x1d01c0; raw 0x1d0814–0x1d0b6c resolves both file/map tests and the early finish.
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID fileSize:(unsigned long long)size {
    _fileName = name;
    _videoID = videoID;
    _totalFileSize = (long long)size;
    _filePath = [self getFilePath];
    _chunkMapPath = [self getChunkMapPath];
    NSFileManager *manager = [NSFileManager defaultManager];
    BOOL fileExists = [manager fileExistsAtPath:_filePath];
    BOOL mapExists = [manager fileExistsAtPath:_chunkMapPath];
    BOOL createFile = !fileExists;
    if (fileExists && mapExists) {
        if ([self loadChunkMap]) {
            if (_downloadedSize >= _totalFileSize) {
                NSLog(@"YTPlus --- File has been downloaded");
                if ([self.delegate respondsToSelector:@selector(downloadDidFinish:fileName:)]) {
                    [self.delegate downloadDidFinish:[NSURL fileURLWithPath:_filePath] fileName:_fileName];
                }
                return;
            }
        } else {
            [self cleanup];
            createFile = YES;
        }
    }
    if (createFile) {
        [manager createFileAtPath:_filePath contents:nil attributes:nil];
        _fileHandle = [NSFileHandle fileHandleForWritingAtPath:_filePath];
        [_fileHandle truncateFileAtOffset:size];
    } else {
        _fileHandle = [NSFileHandle fileHandleForWritingAtPath:_filePath];
    }
    // Original neither resets downloadedSize nor recreates chunkMap after cleanup.
    [self continueDownloadingForURL:url];
}
// 0x1d0b6c: SHA256 of UTF-8 filename immediately followed by decimal unsigned size.
- (NSData *)hashForFile:(NSString *)name fileSize:(unsigned long long)size {
    NSData *data = [[NSString stringWithFormat:@"%@%lu", name, (unsigned long)size] dataUsingEncoding:NSUTF8StringEncoding];
    unsigned char digest[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(data.bytes, (CC_LONG)data.length, digest);
    return [NSData dataWithBytes:digest length:sizeof(digest)];
}
// 0x1d0d50, raw continuation 0x1d10ec–0x1d124c.
- (NSString *)createTempDirectoryIfNeeded {
    NSString *directory = NSTemporaryDirectory();
    BOOL isDirectory = NO;
    NSFileManager *manager = [NSFileManager defaultManager];
    if (![manager fileExistsAtPath:directory isDirectory:&isDirectory] || !isDirectory) {
        NSError *error = nil;
        [manager createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:&error];
        if (error) NSLog(@"YTPlus --- Error creating temporary directory: %@", error.localizedDescription);
    }
    return directory;
}
// 0x1d124c
- (NSString *)getFilePath {
    NSString *directory = [[self createTempDirectoryIfNeeded] stringByAppendingPathComponent:_videoID];
    [[NSFileManager defaultManager] createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:nil];
    return [directory stringByAppendingPathComponent:_fileName];
}
// 0x1d1324. Extension replacement (not appending to the complete filename).
- (NSString *)getChunkMapPath {
    NSString *directory = [[self createTempDirectoryIfNeeded] stringByAppendingPathComponent:_videoID];
    [[NSFileManager defaultManager] createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:nil];
    NSString *mapName = [[_fileName stringByDeletingPathExtension] stringByAppendingPathExtension:@"ytpmap"];
    return [directory stringByAppendingPathComponent:mapName];
}
// 0x1d1528: native little-endian digest[32], uint32 count, then {uint64,uint32,uint32}.
- (void)saveChunkMap {
    NSMutableData *data = [NSMutableData data];
    [data appendData:[self hashForFile:_fileName fileSize:(unsigned long long)_totalFileSize]];
    uint32_t count = (uint32_t)_chunkMap.count;
    [data appendBytes:&count length:4];
    for (NSNumber *key in _chunkMap) {
        NSDictionary *entry = _chunkMap[key];
        uint64_t offset = key.unsignedLongLongValue;
        uint32_t downloaded = [entry[@"downloaded"] unsignedIntValue];
        uint32_t full = [entry[@"full"] unsignedIntValue];
        [data appendBytes:&offset length:8];
        [data appendBytes:&downloaded length:4];
        [data appendBytes:&full length:4];
    }
    [data writeToFile:_chunkMapPath atomically:YES];
}
// 0x1d1b4c, sum continuation 0x1d2770–0x1d2a48.
- (BOOL)loadChunkMap {
    NSData *data = [NSData dataWithContentsOfFile:_chunkMapPath];
    if (!data) return NO;
    // Fidelity: the original trusts the encoded length/count. Do not supply truncated maps.
    const unsigned char *bytes = data.bytes;
    NSData *digest = [NSData dataWithBytes:bytes length:32];
    if (![digest isEqualToData:[self hashForFile:_fileName fileSize:(unsigned long long)_totalFileSize]]) {
        NSLog(@"YTPlus --- Hash not matching, removing old files");
        [self cleanup];
        return NO;
    }
    uint32_t count;
    memcpy(&count, bytes + 32, 4);
    _chunkMap = [NSMutableDictionary dictionary];
    for (uint32_t i = 0; i != count; ++i) {
        const unsigned char *entry = bytes + 36 + (NSUInteger)i * 16;
        uint64_t offset; uint32_t downloaded, full;
        memcpy(&offset, entry, 8); memcpy(&downloaded, entry + 8, 4); memcpy(&full, entry + 12, 4);
        if ((NSUInteger)full > _chunkSize || downloaded > full) {
            NSLog(@"YTPlus --- Invalid chunk data detected, removing old files");
            [self cleanup];
            return NO;
        }
        _chunkMap[@((unsigned long long)offset)] = @{@"downloaded": @((unsigned int)downloaded), @"full": @((unsigned int)full)};
    }
    _downloadedSize = 0;
    for (NSDictionary *entry in _chunkMap.allValues) {
        _downloadedSize = (long long)((unsigned long long)_downloadedSize + [entry[@"downloaded"] unsignedLongLongValue]);
    }
    return YES;
}
// 0x1d2a48. The map is indexed by current downloadedSize, not rounded to chunk boundaries.
- (void)continueDownloadingForURL:(NSURL *)url {
    if (_downloadedSize < _totalFileSize) {
        long long start = _downloadedSize;
        NSDictionary *entry = _chunkMap[@(start)];
        long long end;
        if (!entry) {
            unsigned long long proposed = (unsigned long long)start + _chunkSize - 1;
            unsigned long long last = (unsigned long long)_totalFileSize - 1;
            end = (long long)MIN(proposed, last);
            NSLog(@"YTPlus --- Downloading new chunk %lld-%lld", start, end);
        } else {
            unsigned long long downloaded = [entry[@"downloaded"] unsignedLongLongValue];
            start = (long long)((unsigned long long)start + downloaded);
            end = (long long)((unsigned long long)start + [entry[@"full"] unsignedLongLongValue] - downloaded - 1);
            end = MIN(end, _totalFileSize - 1);
            NSLog(@"YTPlus --- Continuing download of chunk from %lld to %lld", start, end);
        }
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
        [request setValue:[NSString stringWithFormat:@"bytes=%lld-%lld", start, end] forHTTPHeaderField:@"Range"];
        _dataTask = [_session dataTaskWithRequest:request];
        [_dataTask resume];
    } else {
        NSLog(@"YTPlus --- File has been downloaded");
        [self cleanup];
        if ([self.delegate respondsToSelector:@selector(downloadDidFinish:fileName:)]) {
            [self.delegate downloadDidFinish:[NSURL fileURLWithPath:_filePath] fileName:_fileName];
        }
    }
}
// 0x1d3924, complete raw body 0x1d3d98–0x1d4250.
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)task didReceiveData:(NSData *)data {
    (void)session; (void)task;
    long long offset = _downloadedSize;
    @synchronized (_fileHandle) {
        [_fileHandle seekToFileOffset:(unsigned long long)offset];
        [_fileHandle writeData:data];
    }
    _downloadedSize = (long long)((unsigned long long)_downloadedSize + data.length);
    NSDictionary *entry = _chunkMap[@(offset)];
    if (!entry) {
        _chunkMap[@(offset)] = @{@"downloaded": @(data.length), @"full": @(_chunkSize)};
    } else {
        NSUInteger downloaded = [entry[@"downloaded"] unsignedIntegerValue] + data.length;
        NSUInteger full = [entry[@"full"] unsignedIntegerValue];
        if (downloaded <= full) _chunkMap[@(offset)] = @{@"downloaded": @(downloaded), @"full": @(full)};
    }
    [self saveChunkMap];
    float progress = (float)_downloadedSize / (float)_totalFileSize;
    if ([self.delegate respondsToSelector:@selector(downloadProgress:)]) [self.delegate downloadProgress:progress];
    // 0x1d4234–0x1d424c through NSLog thunk 0x1d6104: multiply as float before promotion.
    NSLog(@"YTPlus --- Downloading progress: %.2f%%", (double)(progress * 100.0f));
}
// 0x1d42d4. Error forwarding intentionally does not call cleanup.
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(NSError *)error {
    (void)session;
    if (error) {
        NSLog(@"YTPlus --- Error while downloading: %@", error.localizedDescription);
        if ([self.delegate respondsToSelector:@selector(downloadDidFailureWithError:)]) [self.delegate downloadDidFailureWithError:error];
    } else if (_downloadedSize < _totalFileSize) {
        NSLog(@"YTPlus --- Сhunk downloaded, downloading next chunk");
        [self continueDownloadingForURL:task.originalRequest.URL];
    } else {
        NSLog(@"YTPlus --- File has been downloaded");
        [self cleanup];
        if ([self.delegate respondsToSelector:@selector(downloadDidFinish:fileName:)]) {
            [self.delegate downloadDidFinish:[NSURL fileURLWithPath:_filePath] fileName:_fileName];
        }
    }
}
// ARC emits delegate accessors 0x1d4e28/0x1d4e40 and .cxx_destruct 0x1d4e74.
@end
