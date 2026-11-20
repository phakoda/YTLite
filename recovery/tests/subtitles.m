#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "MetadataAudit.h"
#import "../source/Subtitles/SRTParser.h"
#import "../source/Subtitles/YTPTranslator.h"

static NSUInteger checks;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)
static char mainQueueKey;
static NSString *temporaryDirectory;
NSString *YTLTestTemporaryDirectory(void) { return temporaryDirectory; }

@interface SubtitleRequestDouble : NSObject
@property(nonatomic, strong) NSURL *url;
@property(nonatomic, copy) void (^callback)(NSData *, NSURLResponse *, NSError *);
@property(nonatomic) BOOL resumed;
- (void)resume;
- (void)finish:(NSData *)data error:(NSError *)error;
@end
@implementation SubtitleRequestDouble
- (void)resume { self.resumed = YES; }
- (void)finish:(NSData *)data error:(NSError *)error {
    CHECK(self.resumed);
    // A 503 response is intentional: the packaged code does not inspect status.
    NSHTTPURLResponse *response = [[NSHTTPURLResponse alloc] initWithURL:self.url statusCode:503 HTTPVersion:@"HTTP/1.1" headerFields:@{}];
    self.callback(data, response, error);
}
@end
@interface SubtitleSessionDouble : NSObject
@property(nonatomic, strong) NSMutableArray<SubtitleRequestDouble *> *requests;
- (id)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData *, NSURLResponse *, NSError *))completion;
@end
@implementation SubtitleSessionDouble
- (id)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData *, NSURLResponse *, NSError *))completion {
    SubtitleRequestDouble *request = [SubtitleRequestDouble new];
    request.url = url; request.callback = completion;
    [self.requests addObject:request];
    return request;
}
@end
static SubtitleSessionDouble *sessionDouble;
static id replacementSession(id receiver, SEL selector) { return sessionDouble; }

static NSData *utf8(NSString *text) { return [text dataUsingEncoding:NSUTF8StringEncoding]; }
static void waitFor(dispatch_semaphore_t semaphore) {
    CHECK(dispatch_semaphore_wait(semaphore, dispatch_time(DISPATCH_TIME_NOW, 10 * NSEC_PER_SEC)) == 0);
}
static void flushMain(void) {
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    dispatch_async(dispatch_get_main_queue(), ^{ dispatch_semaphore_signal(semaphore); });
    waitFor(semaphore);
}
static NSString *fileContents(NSURL *url) {
    NSError *error = nil;
    NSString *text = [NSString stringWithContentsOfURL:url encoding:NSUTF8StringEncoding error:&error];
    CHECK(text != nil && error == nil);
    return text;
}

static void testFormattingAndFiles(NSString *work) {
    SRTParser *parser = [SRTParser new];
    NSXMLParser *xmlParser = [[NSXMLParser alloc] initWithData:utf8(@"<fixture/>")];
    NSDictionary *times = @{@0: @"00:00:00,000", @1.125: @"00:00:01,125", @59.9999: @"00:00:59,999",
        @60: @"00:01:00,000", @3600.125: @"01:00:00,125", @90061.125: @"25:01:01,125", @(-0.125): @"00:00:00,-125"};
    for (NSNumber *time in times) CHECK([[parser formatTime:time.doubleValue] isEqual:times[time]]);
    CHECK([[parser formatTime:1.001] isEqual:@"00:00:01,000"]); // binary floating-point truncation
    CHECK([[parser decodeHTMLСhars:@"&lt;x&gt; &amp; &quot;q&quot; &#39;a&#39;&nbsp;end"] isEqual:@"<x> & \"q\" 'a' end"]);
    CHECK([[parser decodeHTMLСhars:@"Plain 😃 &unknown;"] isEqual:@"Plain 😃 &unknown;"]);
    CHECK(![parser respondsToSelector:NSSelectorFromString(@"decodeHTMLChars:")]);
    CHECK([parser respondsToSelector:NSSelectorFromString(@"decodeHTMLСhars:")]);
    [parser parser:xmlParser foundCharacters:@"ignored outside"];
    [parser parser:xmlParser didStartElement:@"text" namespaceURI:nil qualifiedName:nil attributes:@{@"start": @"1.25", @"dur": @"2.5"}];
    [parser parser:xmlParser foundCharacters:@"  first\nline "];
    [parser parser:xmlParser didEndElement:@"not-text" namespaceURI:nil qualifiedName:nil];
    [parser parser:xmlParser didEndElement:@"text" namespaceURI:nil qualifiedName:nil];
    NSError *error = nil;
    temporaryDirectory = [work stringByAppendingPathComponent:@"created-on-demand"];
    NSURL *file = [parser srtForLanguage:@"en" videoID:@"video" error:&error];
    CHECK(file != nil && error == nil && [file.lastPathComponent isEqual:@"en.srt"]);
    CHECK([file.path isEqual:[temporaryDirectory stringByAppendingPathComponent:@"video/en.srt"]]);
    CHECK([fileContents(file) isEqual:@"1\n00:00:01,250 --> 00:00:03,750\nfirst\nline\n"]);
    [parser parser:xmlParser didStartElement:@"text" namespaceURI:nil qualifiedName:nil attributes:@{}];
    [parser parser:xmlParser didEndElement:@"text" namespaceURI:nil qualifiedName:nil];
    file = [parser srtForLanguage:@"en" videoID:@"video" error:&error];
    CHECK([fileContents(file) hasSuffix:@"\n2\n00:00:00,000 --> 00:00:00,000\n\n"]);
    NSString *base = temporaryDirectory;
    temporaryDirectory = [work stringByAppendingPathComponent:@"not-a-directory"];
    CHECK([utf8(@"obstruction") writeToFile:temporaryDirectory atomically:YES]);
    CHECK([parser srtForLanguage:@"en" videoID:@"video" error:&error] == nil && error != nil);
    temporaryDirectory = base;
    NSString *obstruction = [base stringByAppendingPathComponent:@"blocked-video"];
    CHECK([utf8(@"obstruction") writeToFile:obstruction atomically:YES]);
    error = nil;
    CHECK([parser srtForLanguage:@"en" videoID:@"blocked-video" error:&error] == nil && error != nil);
}

static void testParserRequests(void) {
    SRTParser *parser = [SRTParser new];
    NSURL *url = [NSURL URLWithString:@"https://example.invalid/subtitles"];
    NSString *xml = @"<transcript><text start=\"0.5\" dur=\"1.25\"> Hello &amp;amp; &amp;lt;world&amp;gt; </text>"
                     "<text start=\"2\" dur=\"0.5\">Second\nline</text></transcript>";
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    __block NSURL *result;
    __block NSError *failure;
    __block NSUInteger calls = 0;
    [parser parseXMLFromURL:url forLanguage:@"fr" videoID:@"request-video" completion:^(NSURL *file, NSError *error) {
        CHECK(dispatch_get_specific(&mainQueueKey) == &mainQueueKey);
        result = file; failure = error; calls++;
        dispatch_semaphore_signal(semaphore);
    }];
    CHECK(calls == 0 && [sessionDouble.requests.lastObject.url isEqual:url]);
    [sessionDouble.requests.lastObject finish:utf8(xml) error:nil];
    waitFor(semaphore);
    CHECK(calls == 1 && failure == nil && result != nil);
    CHECK([fileContents(result) isEqual:@"1\n00:00:00,500 --> 00:00:01,750\nHello & <world>\n\n2\n00:00:02,000 --> 00:00:02,500\nSecond\nline\n"]);
    __block NSString *transcript;
    [parser parseTranscriptFromURL:url completion:^(NSString *text, NSError *error) {
        CHECK(dispatch_get_specific(&mainQueueKey) == &mainQueueKey);
        transcript = text; failure = error; dispatch_semaphore_signal(semaphore);
    }];
    [sessionDouble.requests.lastObject finish:utf8(xml) error:nil];
    waitFor(semaphore);
    CHECK([transcript isEqual:@"Hello & <world> Second line"] && failure == nil);
    [parser parseXMLFromURL:url forLanguage:@"de" videoID:@"request-video" completion:^(NSURL *file, NSError *error) {
        result = file; failure = error; dispatch_semaphore_signal(semaphore);
    }];
    [sessionDouble.requests.lastObject finish:utf8(@"<transcript><text>third</text></transcript>") error:nil];
    waitFor(semaphore);
    CHECK([fileContents(result) isEqual:@"3\n00:00:00,000 --> 00:00:00,000\nthird\n"] && failure == nil);
    NSError *networkError = [NSError errorWithDomain:@"offline.fixture" code:99 userInfo:nil];
    for (NSNumber *transcriptMode in @[@NO, @YES]) {
        void (^completion)(id, NSError *) = ^(id value, NSError *error) {
            CHECK(dispatch_get_specific(&mainQueueKey) == &mainQueueKey);
            CHECK(value == nil); failure = error; dispatch_semaphore_signal(semaphore);
        };
        if (transcriptMode.boolValue) [parser parseTranscriptFromURL:url completion:completion];
        else [parser parseXMLFromURL:url forLanguage:@"en" videoID:@"failure" completion:completion];
        [sessionDouble.requests.lastObject finish:nil error:networkError]; waitFor(semaphore);
        CHECK(failure == networkError);
        if (transcriptMode.boolValue) [parser parseTranscriptFromURL:url completion:completion];
        else [parser parseXMLFromURL:url forLanguage:@"en" videoID:@"failure" completion:completion];
        [sessionDouble.requests.lastObject finish:utf8(@"<transcript><text>broken") error:nil]; waitFor(semaphore);
        CHECK(failure != nil && failure != networkError);
    }
    // Optional transcript callbacks are safe for the two parse outcomes.
    [parser parseTranscriptFromURL:url completion:nil];
    [sessionDouble.requests.lastObject finish:utf8(xml) error:nil]; flushMain();
    [parser parseTranscriptFromURL:url completion:nil];
    [sessionDouble.requests.lastObject finish:utf8(@"<broken") error:nil]; flushMain();
    // Parser state is shared across overlapping requests, as in the binary.
    [parser parseXMLFromURL:url forLanguage:@"en" videoID:@"overlap" completion:^(NSURL *file, NSError *error) {
        result = file; dispatch_semaphore_signal(semaphore);
    }];
    SubtitleRequestDouble *earlier = sessionDouble.requests.lastObject;
    [parser parseTranscriptFromURL:url completion:nil];
    [earlier finish:utf8(@"<transcript><text>shared mode</text></transcript>") error:nil];
    waitFor(semaphore);
    CHECK([fileContents(result) isEqual:@"shared mode"]);
}

@interface TranslationBatchDouble : YTPTranslator
@end
static NSMutableArray<NSDictionary *> *batchRequests;
@implementation TranslationBatchDouble
+ (void)translateSingleText:(NSString *)text fromLanguage:(NSString *)source toLanguage:(NSString *)target completion:(YTLTranslationCompletion)completion {
    [batchRequests addObject:@{@"text": text ?: [NSNull null], @"source": source ?: [NSNull null],
                              @"target": target ?: [NSNull null], @"completion": [completion copy]}];
}
@end
static void completeBatch(NSUInteger index, NSString *result, NSError *error) {
    YTLTranslationCompletion completion = batchRequests[index][@"completion"];
    completion(result, error);
}

static void testTranslationBatches(void) {
    batchRequests = [NSMutableArray array];
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    __block NSString *result;
    __block NSError *failure;
    __block BOOL completed = NO;
    YTLTranslationCompletion completion = ^(NSString *text, NSError *error) {
        result = text; failure = error; completed = YES; dispatch_semaphore_signal(semaphore);
    };
    NSString *limit = [@"x" stringByPaddingToLength:1500 withString:@"x" startingAtIndex:0];
    [TranslationBatchDouble translateText:limit fromLanguage:@"en" toLanguage:@"fr" completion:completion];
    CHECK(batchRequests.count == 1 && [batchRequests[0][@"text"] isEqual:limit]);
    completeBatch(0, @"direct", nil); waitFor(semaphore);
    CHECK([result isEqual:@"direct"] && failure == nil);
    [batchRequests removeAllObjects]; completed = NO;
    NSString *longText = [limit stringByAppendingString:[limit stringByAppendingString:@"end"]];
    [TranslationBatchDouble translateText:longText fromLanguage:@"en" toLanguage:@"de" completion:^(NSString *text, NSError *error) {
        CHECK(dispatch_get_specific(&mainQueueKey) == &mainQueueKey); completion(text, error);
    }];
    CHECK(batchRequests.count == 3 && !completed);
    CHECK([batchRequests[0][@"text"] length] == 1500 && [batchRequests[1][@"text"] length] == 1500);
    CHECK([batchRequests[2][@"text"] isEqual:@"end"]);
    completeBatch(2, @"C", nil); completeBatch(0, @"A", nil);
    CHECK(!completed);
    completeBatch(1, @"B", nil); waitFor(semaphore);
    CHECK([result isEqual:@"CAB"] && failure == nil); // preserve completion order
    [batchRequests removeAllObjects]; completed = NO;
    NSMutableString *punctuated = [longText mutableCopy];
    [punctuated replaceCharactersInRange:NSMakeRange(100, 1) withString:@"."];
    [punctuated replaceCharactersInRange:NSMakeRange(400, 1) withString:@"\n"];
    [TranslationBatchDouble translateText:punctuated fromLanguage:@"auto" toLanguage:@"es" completion:completion];
    CHECK([batchRequests[0][@"text"] length] == 401);
    CHECK([[batchRequests valueForKey:@"text"] componentsJoinedByString:@""].length == punctuated.length);
    CHECK([[[batchRequests valueForKey:@"text"] componentsJoinedByString:@""] isEqual:punctuated]);
    NSError *first = [NSError errorWithDomain:@"batch" code:1 userInfo:nil];
    NSError *last = [NSError errorWithDomain:@"batch" code:2 userInfo:nil];
    for (NSUInteger index = 0; index < batchRequests.count; index++) {
        CHECK([batchRequests[index][@"source"] isEqual:@"auto"] && [batchRequests[index][@"target"] isEqual:@"es"]);
        completeBatch(index, index == 0 ? nil : @"part", index == 0 ? first : index == batchRequests.count - 1 ? last : nil);
    }
    waitFor(semaphore);
    CHECK(result == nil && failure == last);
    batchRequests = nil;
}

static void testSingleTranslation(void) {
    __block NSString *result;
    __block NSError *failure;
    __block NSUInteger calls = 0;
    YTLTranslationCompletion completion = ^(NSString *text, NSError *error) {
        CHECK(dispatch_get_specific(&mainQueueKey) == NULL);
        result = text; failure = error; calls++;
    };
    [YTPTranslator translateSingleText:@"№ 2 – hello & more" fromLanguage:@"auto" toLanguage:@"fr" completion:completion];
    CHECK(calls == 0);
    NSString *address = sessionDouble.requests.lastObject.url.absoluteString;
    CHECK([address isEqual:@"https://translate.googleapis.com/translate_a/single?client=gtx&sl=auto&tl=fr&dt=t&q=No%202%20-%20hello%20&%20more"]);
    // Non-array/empty segment entries are skipped; the first field is appended.
    [sessionDouble.requests.lastObject finish:utf8(@"[[[\"Bonjour\",\"Hello\"],[],\"skip\",[\" monde\"]],null,\"en\"]") error:nil];
    CHECK(calls == 1 && [result isEqual:@"Bonjour monde"] && failure == nil);
    for (NSString *json in @[@"{}", @"[]", @"[[]]"]) {
        [YTPTranslator translateSingleText:@"x" fromLanguage:@"en" toLanguage:@"fr" completion:completion];
        [sessionDouble.requests.lastObject finish:utf8(json) error:nil];
        CHECK([result isEqual:@""] && failure == nil);
    }
    [YTPTranslator translateSingleText:@"x" fromLanguage:@"en" toLanguage:@"fr" completion:completion];
    [sessionDouble.requests.lastObject finish:utf8(@"not JSON") error:nil];
    CHECK(result == nil && failure != nil);
    NSError *network = [NSError errorWithDomain:@"network.fixture" code:12 userInfo:nil];
    [YTPTranslator translateSingleText:@"x" fromLanguage:@"en" toLanguage:@"fr" completion:completion];
    [sessionDouble.requests.lastObject finish:nil error:network];
    CHECK(result == nil && failure == network);
    // Validation is intentionally not broadened: a non-string segment field
    // reaches Foundation unchanged. Compare with Foundation's actual behavior
    // instead of assuming an exception (an empty-string fast path may not raise).
    BOOL expectedRaised = NO;
    id expectedValue = nil;
    @try { expectedValue = [@"" stringByAppendingString:(id)[NSNull null]]; }
    @catch (NSException *exception) { expectedRaised = YES; }
    [YTPTranslator translateSingleText:@"x" fromLanguage:@"en" toLanguage:@"fr" completion:completion];
    BOOL raised = NO;
    @try { [sessionDouble.requests.lastObject finish:utf8(@"[[[null]]]") error:nil]; }
    @catch (NSException *exception) { raised = YES; }
    CHECK(raised == expectedRaised);
    if (!raised) CHECK(result == expectedValue || [result isEqual:expectedValue]);
}

int main(int argc, const char *argv[]) {
    if (argc != 3) { fprintf(stderr, "usage: subtitles-test evidence-directory work-directory\n"); return 2; }
    @autoreleasepool {
        NSString *evidence = [NSString stringWithUTF8String:argv[1]];
        NSString *work = [NSString stringWithUTF8String:argv[2]];
        dispatch_queue_set_specific(dispatch_get_main_queue(), &mainQueueKey, &mainQueueKey, NULL);
        dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
            @autoreleasepool {
                sessionDouble = [SubtitleSessionDouble new]; sessionDouble.requests = [NSMutableArray array];
                Method method = class_getClassMethod([NSURLSession class], @selector(sharedSession));
                IMP original = method_setImplementation(method, (IMP)replacementSession);
                @try {
                    testFormattingAndFiles(work); testParserRequests(); testTranslationBatches(); testSingleTranslation();
                    checks += YTLAuditMetadata([evidence stringByAppendingPathComponent:@"arm-classes.json"],
                        @[@"SRTParser", @"YTPTranslator"], [evidence stringByAppendingPathComponent:@"ivars.json"]);
                } @finally { method_setImplementation(method, original); }
                printf("Subtitle/translation runtime assertions passed: %lu.\n", (unsigned long)checks);
                exit(0);
            }
        });
    }
    dispatch_main();
}
