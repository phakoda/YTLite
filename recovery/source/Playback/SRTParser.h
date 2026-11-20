#pragma once
#import <Foundation/Foundation.h>

typedef void (^YTPSRTCompletion)(NSURL *url, NSError *error);
typedef void (^YTPTranscriptCompletion)(NSString *transcript, NSError *error);

// The original class is stateful: do not share one parser between concurrent
// operations. Its cue index is initialized once, not reset for each request.
@interface SRTParser : NSObject <NSXMLParserDelegate> {
@private
    NSMutableArray<NSString *> *_srtLines;
    NSMutableString *_currentText;
    NSString *_videoID;
    NSInteger _index;
    double _start;
    double _end;
    double _duration;
    BOOL _isTranscript;
}
- (void)parseXMLFromURL:(NSURL *)url forLanguage:(NSString *)language
               videoID:(NSString *)videoID completion:(YTPSRTCompletion)completion;
// The recovered implementation dereferences error on a failure path. Callers
// supply a nonnull pointer to an NSError * initialized to nil.
- (NSURL *)srtForLanguage:(NSString *)language videoID:(NSString *)videoID error:(NSError **)error;
- (void)parseTranscriptFromURL:(NSURL *)url completion:(YTPTranscriptCompletion)completion;
- (void)generateSRTWithText:(NSString *)text;
- (void)generateTranscriptWithText:(NSString *)text;
- (NSString *)formatTime:(double)seconds;
// The letter after HTML is Cyrillic capital ES (U+0421), as in the binary.
- (NSString *)decodeHTMLСhars:(NSString *)text;
@end
