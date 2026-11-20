#import "SRTParser.h"

@implementation SRTParser

// 0x1fdf2c. The counter is initialized here, not at the start of each request.
- (instancetype)init {
    self = [super init];
    if (self) {
        _srtLines = [NSMutableArray array];
        _index = 1;
        _currentText = [NSMutableString string];
    }
    return self;
}

// 0x1fe01c; network block 0x1fe1c4; main-queue blocks 0x1fe490/4cc/508.
- (void)parseXMLFromURL:(NSURL *)url forLanguage:(NSString *)language videoID:(NSString *)videoID completion:(YTLSRTCompletion)completion {
    _isTranscript = NO;
    _srtLines = [NSMutableArray array];
    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithURL:url
        completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, error); });
            return;
        }
        NSXMLParser *parser = [[NSXMLParser alloc] initWithData:data];
        parser.delegate = self;
        if ([parser parse]) {
            NSError *writeError = nil;
            NSURL *file = [self srtForLanguage:language videoID:videoID error:&writeError];
            dispatch_async(dispatch_get_main_queue(), ^{ completion(file, writeError); });
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, parser.parserError); });
        }
    }];
    [task resume];
}

// 0x1fe570. The tail omitted by the original decompiler was reviewed at
// 0x1fecf8..0x1fefb4. The caller supplies a valid NSError** initialized to nil.
// Per-video mkdir errors are deliberately ignored; a failed write reports them.
- (NSURL *)srtForLanguage:(NSString *)language videoID:(NSString *)videoID error:(NSError *__autoreleasing *)error {
    NSString *temporary = NSTemporaryDirectory();
    BOOL isDirectory = NO;
    BOOL exists = [[NSFileManager defaultManager] fileExistsAtPath:temporary isDirectory:&isDirectory];
    if (!exists || !isDirectory) {
        [[NSFileManager defaultManager] createDirectoryAtPath:temporary withIntermediateDirectories:YES attributes:nil error:error];
        if (*error) {
            NSLog(@"YTPlus --- Error creating temporary directory: %@", [*error localizedDescription]);
            return nil;
        }
    }
    NSString *directory = [NSTemporaryDirectory() stringByAppendingPathComponent:videoID];
    [[NSFileManager defaultManager] createDirectoryAtPath:directory withIntermediateDirectories:YES attributes:nil error:NULL];
    NSURL *file = [NSURL fileURLWithPath:[directory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.srt", language]]];
    NSString *contents = [_srtLines componentsJoinedByString:@"\n"];
    if (![contents writeToURL:file atomically:YES encoding:NSUTF8StringEncoding error:error]) {
        NSLog(@"YTPlus --- Error while creating srt file: %@", [*error localizedDescription]);
        return nil;
    }
    return file;
}

// 0x1fefb8; network block 0x1ff110. A missing completion is checked for
// parse success/failure, but NOT for a network error, matching the three blocks.
- (void)parseTranscriptFromURL:(NSURL *)url completion:(YTLTranscriptCompletion)completion {
    _isTranscript = YES;
    _srtLines = [NSMutableArray array];
    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithURL:url
        completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, error); });
            return;
        }
        NSXMLParser *parser = [[NSXMLParser alloc] initWithData:data];
        parser.delegate = self;
        if ([parser parse]) {
            NSString *transcript = [self->_srtLines componentsJoinedByString:@" "];
            dispatch_async(dispatch_get_main_queue(), ^{ if (completion) completion(transcript, nil); });
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{ if (completion) completion(nil, parser.parserError); });
        }
    }];
    [task resume];
}

// 0x1ff5b4.
- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary<NSString *, NSString *> *)attributes {
    if (![elementName isEqualToString:@"text"]) return;
    _start = [attributes[@"start"] doubleValue];
    _duration = [attributes[@"dur"] doubleValue];
    _end = _start + _duration;
    [_currentText setString:@""];
}

// 0x1ff874. Character data is appended even outside a text element; the next
// text start clears the buffer. This is not replaced with a different XML model.
- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
    [_currentText appendString:string];
}

// 0x1ff8b0.
- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName {
    if (![elementName isEqualToString:@"text"]) return;
    NSString *text = [[self decodeHTMLСhars:_currentText] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if (_isTranscript) [self generateTranscriptWithText:text];
    else [self generateSRTWithText:text];
}

// 0x1ffa9c.
- (void)generateSRTWithText:(NSString *)text {
    NSString *start = [self formatTime:_start];
    NSString *end = [self formatTime:_end];
    [_srtLines addObject:[NSString stringWithFormat:@"%ld", (long)_index]];
    [_srtLines addObject:[NSString stringWithFormat:@"%@ --> %@", start, end]];
    [_srtLines addObject:text];
    [_srtLines addObject:@""];
    _index++;
}

// 0x1ffd74.
- (void)generateTranscriptWithText:(NSString *)text {
    NSString *line = [[text stringByReplacingOccurrencesOfString:@"\n" withString:@" "]
                     stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    [_srtLines addObject:line];
}

// 0x1fff08. Integer conversions truncate; rounding would change cue boundaries.
- (NSString *)formatTime:(double)time {
    NSInteger hours = (NSInteger)(time / 3600.0);
    double remainder = time - (double)(hours * 3600);
    NSInteger minutes = (NSInteger)(remainder / 60.0);
    NSInteger seconds = (NSInteger)(remainder - (double)(minutes * 60));
    NSInteger milliseconds = (NSInteger)((time - (double)(NSInteger)time) * 1000.0);
    return [NSString stringWithFormat:@"%02ld:%02ld:%02ld,%03ld", (long)hours, (long)minutes, (long)seconds, (long)milliseconds];
}

// 0x200164. Keep dictionary iteration rather than imposing a new entity order.
- (NSString *)decodeHTMLСhars:(NSString *)text {
    NSMutableString *result = [NSMutableString stringWithString:text];
    NSDictionary *replacements = @{@"&lt;": @"<", @"&gt;": @">", @"&amp;": @"&",
                                   @"&quot;": @"\"", @"&#39;": @"'", @"&nbsp;": @" "};
    for (NSString *entity in replacements) {
        [result replaceOccurrencesOfString:entity withString:replacements[entity] options:0 range:NSMakeRange(0, result.length)];
    }
    return result;
}

// 0x2008e8: ARC synthesizes destruction of the three retained object ivars.
@end
