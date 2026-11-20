#import "SRTParser.h"
#import <dispatch/dispatch.h>

@implementation SRTParser

// -[SRTParser init], 0x1fdf2c.
- (instancetype)init {
    self = [super init];
    if (self) {
        _srtLines = [NSMutableArray array];
        _index = 1;
        _currentText = [NSMutableString string];
    }
    return self;
}

// 0x1fe01c; completion blocks 0x1fe1c4, 0x1fe490, 0x1fe4cc, 0x1fe508.
- (void)parseXMLFromURL:(NSURL *)url forLanguage:(NSString *)language
               videoID:(NSString *)videoID completion:(YTPSRTCompletion)completion {
    _isTranscript = NO;
    _srtLines = [NSMutableArray array];
    [[[NSURLSession sharedSession] dataTaskWithURL:url completionHandler:
        ^(NSData *data, NSURLResponse *response, NSError *networkError) {
        (void)response;
        if (networkError) {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, networkError); });
            return;
        }
        NSXMLParser *parser = [[NSXMLParser alloc] initWithData:data];
        parser.delegate = self;
        if ([parser parse]) {
            NSError *error = nil;
            NSURL *result = [self srtForLanguage:language videoID:videoID error:&error];
            dispatch_async(dispatch_get_main_queue(), ^{ completion(result, error); });
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, parser.parserError); });
        }
    }] resume];
}

// 0x1fe570. The earlier pseudocode stopped at 0x1fecf4; raw instructions through
// 0x1fefb4 establish both directory paths, UTF-8 atomic writing and failure exits.
- (NSURL *)srtForLanguage:(NSString *)language videoID:(NSString *)videoID error:(NSError **)error {
    NSString *temporaryDirectory = NSTemporaryDirectory();
    BOOL isDirectory = NO;
    if (![[NSFileManager defaultManager] fileExistsAtPath:temporaryDirectory isDirectory:&isDirectory]
            || !isDirectory) {
        [[NSFileManager defaultManager] createDirectoryAtPath:temporaryDirectory
                                  withIntermediateDirectories:YES attributes:nil error:error];
        if (*error) {
            NSLog(@"YTPlus --- Error creating temporary directory: %@", [*error localizedDescription]);
            return nil;
        }
    }
    NSString *directory = [NSTemporaryDirectory() stringByAppendingPathComponent:videoID];
    // Failure here is intentionally reported by the following write, matching
    // the original nil error argument on the per-video directory creation.
    [[NSFileManager defaultManager] createDirectoryAtPath:directory
                              withIntermediateDirectories:YES attributes:nil error:NULL];
    NSURL *url = [NSURL fileURLWithPath:[directory stringByAppendingPathComponent:
                                       [NSString stringWithFormat:@"%@.srt", language]]];
    NSString *contents = [_srtLines componentsJoinedByString:@"\n"];
    if (![contents writeToURL:url atomically:YES encoding:NSUTF8StringEncoding error:error]) {
        NSLog(@"YTPlus --- Error while creating srt file: %@", [*error localizedDescription]);
        return nil;
    }
    return url;
}

// 0x1fefb8; blocks 0x1ff110, 0x1ff438, 0x1ff474, 0x1ff504. The success and
// parser-error callbacks guard a nil completion; the network-error one does not.
- (void)parseTranscriptFromURL:(NSURL *)url completion:(YTPTranscriptCompletion)completion {
    _isTranscript = YES;
    _srtLines = [NSMutableArray array];
    [[[NSURLSession sharedSession] dataTaskWithURL:url completionHandler:
        ^(NSData *data, NSURLResponse *response, NSError *networkError) {
        (void)response;
        if (networkError) {
            dispatch_async(dispatch_get_main_queue(), ^{ completion(nil, networkError); });
            return;
        }
        NSXMLParser *parser = [[NSXMLParser alloc] initWithData:data];
        parser.delegate = self;
        if ([parser parse]) {
            NSString *text = [self->_srtLines componentsJoinedByString:@" "];
            dispatch_async(dispatch_get_main_queue(), ^{ if (completion) completion(text, nil); });
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{ if (completion) completion(nil, parser.parserError); });
        }
    }] resume];
}

// 0x1ff5b4.
- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName
  namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName
    attributes:(NSDictionary<NSString *, NSString *> *)attributes {
    (void)parser; (void)namespaceURI; (void)qualifiedName;
    if ([elementName isEqualToString:@"text"]) {
        _start = [attributes[@"start"] doubleValue];
        _duration = [attributes[@"dur"] doubleValue];
        _end = _start + _duration;
        [_currentText setString:@""];
    }
}

// 0x1ff874: appends every parser character callback, not just text-node events.
- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
    (void)parser;
    [_currentText appendString:string];
}

// 0x1ff8b0.
- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName
  namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName {
    (void)parser; (void)namespaceURI; (void)qualifiedName;
    if ([elementName isEqualToString:@"text"]) {
        NSString *text = [[self decodeHTMLСhars:_currentText]
            stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        if (_isTranscript) [self generateTranscriptWithText:text];
        else [self generateSRTWithText:text];
    }
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

// 0x1fff08. Integer conversions truncate toward zero; milliseconds are not
// rounded and are not carried into the next second.
- (NSString *)formatTime:(double)seconds {
    long hours = (long)(seconds / 3600.0);
    double remainder = seconds - (double)(hours * 3600);
    long minutes = (long)(remainder / 60.0);
    long wholeSeconds = (long)(remainder - (double)(minutes * 60));
    long milliseconds = (long)((seconds - (double)(long)seconds) * 1000.0);
    return [NSString stringWithFormat:@"%02ld:%02ld:%02ld,%03ld", hours, minutes, wholeSeconds, milliseconds];
}

// 0x200164. This is the recovered six-entity pass, not a general HTML parser.
- (NSString *)decodeHTMLСhars:(NSString *)text {
    NSMutableString *decoded = [NSMutableString stringWithString:text];
    NSDictionary<NSString *, NSString *> *entities = @{
        @"&lt;": @"<", @"&gt;": @">", @"&amp;": @"&", @"&quot;": @"\"",
        @"&#39;": @"'", @"&nbsp;": @" "
    };
    for (NSString *entity in entities) {
        [decoded replaceOccurrencesOfString:entity withString:entities[entity]
                                    options:0 range:NSMakeRange(0, decoded.length)];
    }
    return decoded;
}

@end
