#import <Foundation/Foundation.h>

typedef void (^YTLSRTCompletion)(NSURL *url, NSError *error);
typedef void (^YTLTranscriptCompletion)(NSString *transcript, NSError *error);

/// Reconstructed functional implementation. All networking uses NSURLSession;
/// tests replace that session rather than executing packaged machine code.
@interface SRTParser : NSObject <NSXMLParserDelegate> {
    NSMutableArray *_srtLines;
    NSMutableString *_currentText;
    NSString *_videoID;
    NSInteger _index;
    double _start;
    double _end;
    double _duration;
    BOOL _isTranscript;
}
- (void)parseXMLFromURL:(NSURL *)url forLanguage:(NSString *)language videoID:(NSString *)videoID completion:(YTLSRTCompletion)completion;
- (NSURL *)srtForLanguage:(NSString *)language videoID:(NSString *)videoID error:(NSError *__autoreleasing *)error;
- (void)parseTranscriptFromURL:(NSURL *)url completion:(YTLTranscriptCompletion)completion;
- (void)generateSRTWithText:(NSString *)text;
- (void)generateTranscriptWithText:(NSString *)text;
- (NSString *)formatTime:(double)time;
// This selector contains Cyrillic capital С (U+0421), not ASCII C.
- (NSString *)decodeHTMLСhars:(NSString *)text;
@end
