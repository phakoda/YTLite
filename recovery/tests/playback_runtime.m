#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <dispatch/dispatch.h>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>
#import "../source/Playback/SRTParser.h"
#import "../source/Playback/SBManager.h"
#import "../source/Playback/SBPlaybackController.h"
#import "../source/Playback/SBPlayerDecorator.h"
#import "../source/Models/SBSegment.h"

static NSUInteger assertions;
#define CHECK(expression) do { \
    assertions++; \
    if (!(expression)) { \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #expression); \
        abort(); \
    } \
} while (0)

typedef void (^FixtureHTTPCompletion)(NSData *, NSURLResponse *, NSError *);

@interface FixtureHTTPTask : NSObject
@property(nonatomic, strong) NSURLRequest *request;
@property(nonatomic, copy) FixtureHTTPCompletion completion;
@property(nonatomic) NSUInteger resumeCount;
- (void)resume;
- (void)deliverData:(NSData *)data error:(NSError *)error;
@end
@implementation FixtureHTTPTask
- (void)resume { self.resumeCount++; }
- (void)deliverData:(NSData *)data error:(NSError *)error {
    FixtureHTTPCompletion completion = self.completion;
    self.completion = nil;
    completion(data, nil, error);
}
@end

@interface FixtureHTTPSession : NSObject
@property(nonatomic, strong) NSMutableArray<FixtureHTTPTask *> *tasks;
- (FixtureHTTPTask *)dataTaskWithURL:(NSURL *)url completionHandler:(FixtureHTTPCompletion)completion;
- (FixtureHTTPTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(FixtureHTTPCompletion)completion;
@end
@implementation FixtureHTTPSession
- (instancetype)init {
    self = [super init];
    if (self) _tasks = [NSMutableArray array];
    return self;
}
- (FixtureHTTPTask *)dataTaskWithURL:(NSURL *)url completionHandler:(FixtureHTTPCompletion)completion {
    return [self dataTaskWithRequest:[NSURLRequest requestWithURL:url] completionHandler:completion];
}
- (FixtureHTTPTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(FixtureHTTPCompletion)completion {
    FixtureHTTPTask *task = [FixtureHTTPTask new];
    task.request = request;
    task.completion = completion;
    [self.tasks addObject:task];
    return task;
}
@end

static FixtureHTTPSession *fixtureSession;
NSUInteger YTLPlaybackHTTPTaskCount(void) { return fixtureSession.tasks.count; }
extern NSUInteger testSponsorPlayback(void);
extern NSUInteger testSponsorDrawing(void);
static id fixtureSharedSession(id receiver, SEL selector) {
    (void)receiver; (void)selector;
    return fixtureSession;
}

static NSData *utf8(NSString *text) { return [text dataUsingEncoding:NSUTF8StringEncoding]; }
static void awaitCondition(BOOL (^condition)(void)) {
    NSDate *deadline = [NSDate dateWithTimeIntervalSinceNow:5];
    while (!condition() && deadline.timeIntervalSinceNow > 0) {
        [[NSRunLoop mainRunLoop] runMode:NSDefaultRunLoopMode
                            beforeDate:[NSDate dateWithTimeIntervalSinceNow:0.005]];
    }
    CHECK(condition());
}

static void testFormatting(void) {
    SRTParser *parser = [SRTParser new];
    NSXMLParser *delegateSource = [[NSXMLParser alloc] initWithData:utf8(@"<transcript/>")];
    CHECK([parser respondsToSelector:NSSelectorFromString(@"decodeHTMLСhars:")]);
    CHECK(![parser respondsToSelector:NSSelectorFromString(@"decodeHTMLChars:")]);
    CHECK([[parser formatTime:0] isEqualToString:@"00:00:00,000"]);
    CHECK([[parser formatTime:3661.125] isEqualToString:@"01:01:01,125"]);
    CHECK([[parser formatTime:59.9999] isEqualToString:@"00:00:59,999"]);
    CHECK([[parser formatTime:-0.125] isEqualToString:@"00:00:00,-125"]);
    CHECK([[parser formatTime:360000.5] isEqualToString:@"100:00:00,500"]);
    CHECK([[parser decodeHTMLСhars:@"&lt;&gt;&amp;&quot;&#39;&nbsp; &copy;"]
           isEqualToString:@"<>&\"'  &copy;"]);
    CHECK([[parser decodeHTMLСhars:@"&#65; &#x41;"] isEqualToString:@"&#65; &#x41;"]);

    [parser parser:delegateSource didStartElement:@"text" namespaceURI:nil qualifiedName:nil
        attributes:@{@"start": @"1.125", @"dur": @"2.5"}];
    [parser parser:delegateSource foundCharacters:@"  Hello &lt;world&gt; "];
    [parser parser:delegateSource didEndElement:@"text" namespaceURI:nil qualifiedName:nil];
    NSArray *lines = [parser valueForKey:@"_srtLines"];
    NSArray *expected = @[@"1", @"00:00:01,125 --> 00:00:03,625", @"Hello <world>", @""];
    CHECK([lines isEqualToArray:expected]);
    CHECK([[parser valueForKey:@"_index"] integerValue] == 2);
    [parser parser:delegateSource didEndElement:@"ignored" namespaceURI:nil qualifiedName:nil];
    CHECK(lines.count == 4);
    [parser parser:delegateSource didStartElement:@"text" namespaceURI:nil qualifiedName:nil attributes:@{}];
    [parser parser:delegateSource didEndElement:@"text" namespaceURI:nil qualifiedName:nil];
    CHECK(lines.count == 8 && [lines[4] isEqual:@"2"] && [lines[6] isEqual:@""]);
    CHECK([lines[5] isEqual:@"00:00:00,000 --> 00:00:00,000"]);
    [parser generateTranscriptWithText:@" \n first\nsecond \t"];
    CHECK([lines.lastObject isEqual:@"first second"]);
    CHECK([[parser valueForKey:@"_index"] integerValue] == 3);
}

static void testSubtitleFiles(void) {
    SRTParser *parser = [SRTParser new];
    [parser generateSRTWithText:@"Unicode: 🔥"];
    NSError *error = nil;
    NSURL *url = [parser srtForLanguage:@"en-US" videoID:@"subtitle-file-fixture" error:&error];
    CHECK(url != nil && error == nil);
    CHECK([url.lastPathComponent isEqual:@"en-US.srt"]);
    CHECK([url.URLByDeletingLastPathComponent.lastPathComponent isEqual:@"subtitle-file-fixture"]);
    CHECK([url.path hasPrefix:NSTemporaryDirectory()]);
    CHECK([[NSString stringWithContentsOfURL:url encoding:NSUTF8StringEncoding error:&error]
           isEqual:@"1\n00:00:00,000 --> 00:00:00,000\nUnicode: 🔥\n"]);
    CHECK(error == nil);
    NSString *blockerName = [@"not-a-directory-" stringByAppendingString:NSUUID.UUID.UUIDString];
    NSString *blocker = [NSTemporaryDirectory() stringByAppendingPathComponent:blockerName];
    CHECK([@"occupied" writeToFile:blocker atomically:YES encoding:NSUTF8StringEncoding error:&error]);
    error = nil;
    CHECK([parser srtForLanguage:@"en" videoID:blockerName error:&error] == nil);
    CHECK(error != nil);
}

static void testSubtitleRequests(void) {
    SRTParser *parser = [SRTParser new];
    NSURL *inputURL = [NSURL URLWithString:@"https://fixture.invalid/subtitles"];
    NSString *xml = @"<transcript><text start=\"1.125\" dur=\"2.5\"> One &amp;lt;two&amp;gt; </text>"
                    "<text start=\"4\" dur=\"0.5\">Three\nlines</text></transcript>";
    __block BOOL completed = NO;
    __block NSURL *result;
    __block NSError *failure;
    [parser parseXMLFromURL:inputURL forLanguage:@"en" videoID:@"subtitle-request-fixture"
        completion:^(NSURL *url, NSError *error) {
        CHECK([NSThread isMainThread]);
        result = url; failure = error; completed = YES;
    }];
    FixtureHTTPTask *task = fixtureSession.tasks.lastObject;
    CHECK(task.resumeCount == 1 && [task.request.URL isEqual:inputURL]);
    [task deliverData:utf8(xml) error:nil];
    CHECK(!completed);
    awaitCondition(^{ return completed; });
    CHECK(result != nil && failure == nil);
    NSString *text = [NSString stringWithContentsOfURL:result encoding:NSUTF8StringEncoding error:NULL];
    CHECK([text isEqual:@"1\n00:00:01,125 --> 00:00:03,625\nOne <two>\n\n2\n00:00:04,000 --> 00:00:04,500\nThree\nlines\n"]);

    completed = NO;
    [parser parseXMLFromURL:inputURL forLanguage:@"en" videoID:@"subtitle-request-fixture"
        completion:^(NSURL *url, NSError *error) { result = url; failure = error; completed = YES; }];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"<transcript><text start=\"0\" dur=\"1\">Again</text></transcript>") error:nil];
    awaitCondition(^{ return completed; });
    text = [NSString stringWithContentsOfURL:result encoding:NSUTF8StringEncoding error:NULL];
    CHECK([text hasPrefix:@"3\n"] && [text containsString:@"Again"]);
    CHECK(![text containsString:@"One <two>"] && failure == nil);

    completed = NO;
    [parser parseXMLFromURL:inputURL forLanguage:@"en" videoID:@"subtitle-request-fixture"
        completion:^(NSURL *url, NSError *error) {
        CHECK([NSThread isMainThread]); result = url; failure = error; completed = YES;
    }];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"<transcript><text>") error:nil];
    awaitCondition(^{ return completed; });
    CHECK(result == nil && failure != nil);

    completed = NO;
    NSError *networkError = [NSError errorWithDomain:NSURLErrorDomain code:NSURLErrorNotConnectedToInternet userInfo:nil];
    [parser parseXMLFromURL:inputURL forLanguage:@"en" videoID:@"subtitle-request-fixture"
        completion:^(NSURL *url, NSError *error) {
        CHECK([NSThread isMainThread]); result = url; failure = error; completed = YES;
    }];
    [fixtureSession.tasks.lastObject deliverData:nil error:networkError];
    awaitCondition(^{ return completed; });
    CHECK(result == nil && failure == networkError);

    completed = NO;
    __block NSString *transcript;
    [parser parseTranscriptFromURL:inputURL completion:^(NSString *value, NSError *error) {
        CHECK([NSThread isMainThread]); transcript = value; failure = error; completed = YES;
    }];
    [fixtureSession.tasks.lastObject deliverData:utf8(xml) error:nil];
    awaitCondition(^{ return completed; });
    CHECK([transcript isEqual:@"One <two> Three lines"] && failure == nil);

    completed = NO;
    [parser parseTranscriptFromURL:inputURL completion:^(NSString *value, NSError *error) {
        CHECK([NSThread isMainThread]); transcript = value; failure = error; completed = YES;
    }];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"<transcript><text>") error:nil];
    awaitCondition(^{ return completed; });
    CHECK(transcript == nil && failure != nil);

    completed = NO;
    [parser parseTranscriptFromURL:inputURL completion:^(NSString *value, NSError *error) {
        CHECK([NSThread isMainThread]); transcript = value; failure = error; completed = YES;
    }];
    [fixtureSession.tasks.lastObject deliverData:nil error:networkError];
    awaitCondition(^{ return completed; });
    CHECK(transcript == nil && failure == networkError);

    // Only success/parser-error transcript paths are nil-completion safe.
    [parser parseTranscriptFromURL:inputURL completion:nil];
    [fixtureSession.tasks.lastObject deliverData:utf8(xml) error:nil];
    [parser parseTranscriptFromURL:inputURL completion:nil];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"<broken>") error:nil];
    __block BOOL drained = NO;
    dispatch_async(dispatch_get_main_queue(), ^{ drained = YES; });
    awaitCondition(^{ return drained; });
}

static void testSponsorBlockRequests(void) {
    SBManager *manager = [SBManager new];
    CHECK(manager.segments != nil && manager.segments.count == 0);
    CHECK([SBManager sharedManager] == [SBManager sharedManager]);
    NSUInteger before = fixtureSession.tasks.count;
    [manager getSegmentsForID:nil]; [manager getSegmentsForID:@""];
    CHECK(fixtureSession.tasks.count == before);
    manager.segments[@"video"] = [NSMutableArray array];
    [manager getSegmentsForID:@"video"];
    CHECK(manager.segments[@"video"] == nil);
    FixtureHTTPTask *task = fixtureSession.tasks.lastObject;
    CHECK(task.resumeCount == 1);
    NSURLComponents *components = [NSURLComponents componentsWithURL:task.request.URL resolvingAgainstBaseURL:NO];
    CHECK([components.scheme isEqual:@"https"] && [components.host isEqual:@"sponsor.ajay.app"]);
    CHECK([components.path isEqual:@"/api/skipSegments"]);
    NSMutableDictionary *query = [NSMutableDictionary dictionary];
    for (NSURLQueryItem *item in components.queryItems) query[item.name] = item.value;
    CHECK([query[@"videoID"] isEqual:@"video"]);
    NSArray *categories = [NSJSONSerialization JSONObjectWithData:utf8(query[@"categories"]) options:0 error:NULL];
    NSArray *expectedCategories = @[@"sponsor", @"intro", @"outro", @"interaction", @"selfpromo",
                                    @"music_offtopic", @"preview", @"poi_highlight", @"filler"];
    CHECK([categories isEqual:expectedCategories]);
    NSArray *json = @[
        @{@"segment": @[@8, @9], @"UUID": @"later", @"category": @"sponsor"},
        @{@"segment": @[@1], @"UUID": @"invalid"},
        @{@"segment": @[@1.25, @4.5], @"UUID": @"earlier", @"category": @"intro"},
        @{@"UUID": @"absent-interval"}
    ];
    [task deliverData:[NSJSONSerialization dataWithJSONObject:json options:0 error:NULL] error:nil];
    NSArray<SBSegment *> *segments = manager.segments[@"video"];
    CHECK(segments.count == 2);
    CHECK([segments[0].uuid isEqual:@"later"] && [segments[1].uuid isEqual:@"earlier"]);
    CHECK(segments[1].start == 1.25 && segments[1].end == 4.5);
    CHECK([segments isKindOfClass:NSMutableArray.class]);

    [manager getSegmentsForID:@"video"];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"[]") error:nil];
    CHECK(manager.segments[@"video"] != nil && manager.segments[@"video"].count == 0);
    [manager getSegmentsForID:@"video"];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"{}") error:nil];
    CHECK(manager.segments[@"video"] == nil);
    [manager getSegmentsForID:@"video"];
    [fixtureSession.tasks.lastObject deliverData:utf8(@"not-json") error:nil];
    CHECK(manager.segments[@"video"] == nil);
    [manager getSegmentsForID:@"video"];
    NSError *networkError = [NSError errorWithDomain:NSURLErrorDomain code:NSURLErrorTimedOut userInfo:nil];
    [fixtureSession.tasks.lastObject deliverData:nil error:networkError];
    CHECK(manager.segments[@"video"] == nil);
    [manager getSegmentsForID:@"video"];
    [fixtureSession.tasks.lastObject deliverData:nil error:nil];
    CHECK(manager.segments[@"video"] == nil);
}

static NSDictionary *runtimeMetadata(Class cls) {
    NSMutableArray *methods = [NSMutableArray array];
    for (NSNumber *meta in @[@NO, @YES]) {
        unsigned count = 0;
        Method *list = class_copyMethodList(meta.boolValue ? object_getClass(cls) : cls, &count);
        for (unsigned index = 0; index < count; index++) {
            [methods addObject:@{@"kind": meta.boolValue ? @"+" : @"-",
                @"selector": NSStringFromSelector(method_getName(list[index])),
                @"encoding": @(method_getTypeEncoding(list[index]))}];
        }
        free(list);
    }
    NSMutableArray *ivars = [NSMutableArray array];
    unsigned count = 0;
    Ivar *list = class_copyIvarList(cls, &count);
    for (unsigned index = 0; index < count; index++) {
        [ivars addObject:@{@"name": @(ivar_getName(list[index])),
                          @"offset": @(ivar_getOffset(list[index])),
                          @"encoding": @(ivar_getTypeEncoding(list[index]))}];
    }
    free(list);
    return @{@"name": NSStringFromClass(cls), @"methods": methods, @"ivars": ivars};
}

static void reportUnhandledException(NSException *exception) {
    fprintf(stderr, "Unhandled test exception: %s\n%s\n", exception.description.UTF8String,
            [exception.callStackSymbols componentsJoinedByString:@"\n"].UTF8String);
}

static void reportAbort(int signalNumber) {
    void *frames[64];
    int count = backtrace(frames, 64);
    backtrace_symbols_fd(frames, count, STDERR_FILENO);
    _exit(128 + signalNumber);
}

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        NSSetUncaughtExceptionHandler(reportUnhandledException);
        signal(SIGABRT, reportAbort);
        CHECK(argc == 2);
        fixtureSession = [FixtureHTTPSession new];
        Method method = class_getClassMethod(NSURLSession.class, @selector(sharedSession));
        IMP original = method_setImplementation(method, (IMP)fixtureSharedSession);
        @try {
            testFormatting(); testSubtitleFiles(); testSubtitleRequests(); testSponsorBlockRequests();
            assertions += testSponsorPlayback();
            assertions += testSponsorDrawing();
        } @finally {
            method_setImplementation(method, original);
        }
        NSDictionary *report = @{@"assertions": @(assertions + 1),
            @"classes": @[runtimeMetadata(SRTParser.class), runtimeMetadata(SBManager.class),
                          runtimeMetadata(SBPlaybackController.class), runtimeMetadata(SBPlayerDecorator.class)]};
        NSData *json = [NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:NULL];
        CHECK([json writeToFile:@(argv[1]) atomically:YES]);
        printf("Playback Foundation tests: %lu assertions passed. No network requests issued.\n", (unsigned long)assertions);
    }
    return 0;
}
