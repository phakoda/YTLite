#import "../source/Media/DVNMediaPicker.h"
#import <AVFoundation/AVFoundation.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#import <objc/runtime.h>
#import "../source/Presentation/ToastManager.h"
#import "../../Utils/NSString+YTLite.h"

static NSString *root, *toast;
static BOOL success;
static double duration;
static NSUInteger checks;
#define CHECK(value) do { checks++; if (!(value)) { NSLog(@"FAIL line %d: %s", __LINE__, #value); exit(1); } } while (0)
NSString *YTLTestTemporaryDirectory(void) { return [root stringByAppendingPathComponent:@"tmp"]; }
NSArray *YTLTestSearchPath(NSSearchPathDirectory directory, NSSearchPathDomainMask domain, BOOL expand) {
    CHECK(directory == NSDocumentDirectory && domain == NSUserDomainMask && expand);
    return @[[root stringByAppendingPathComponent:@"Documents"]];
}
@implementation NSString (MediaTestLocalization)
- (NSString *)ytl_localized { return self; }
@end
// Only the toast boundary is implemented here; no production UI is replaced.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation ToastManager
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)value { toast = text; success = value; }
@end
#pragma clang diagnostic pop
@implementation UIViewController
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion {
    CHECK(animated); self.presented = controller; if (completion) completion();
}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion {
    CHECK(animated); self.dismissed = YES; if (completion) completion();
}
@end
@implementation UIDocumentPickerViewController
- (instancetype)initWithDocumentTypes:(NSArray *)types inMode:(UIDocumentPickerMode)mode {
    if ((self = [super init])) { self.types = types; self.mode = mode; } return self;
}
@end
@implementation UITextField @end
@implementation UIAlertAction
+ (instancetype)actionWithTitle:(NSString *)title style:(UIAlertActionStyle)style handler:(void (^)(UIAlertAction *))handler {
    UIAlertAction *action = [self new]; action.title = title; action.style = style; action.handler = handler; return action;
}
@end
@implementation UIAlertController
+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message preferredStyle:(UIAlertControllerStyle)style {
    UIAlertController *alert = [self new]; alert.title = title; alert.message = message; alert.style = style;
    alert.textFields = [NSMutableArray array]; alert.actions = [NSMutableArray array]; return alert;
}
- (void)addTextFieldWithConfigurationHandler:(void (^)(UITextField *))handler {
    UITextField *field = [UITextField new]; [self.textFields addObject:field]; handler(field);
}
- (void)addAction:(UIAlertAction *)action { [self.actions addObject:action]; }
@end
@implementation PHPickerFilter
+ (instancetype)videosFilter { static PHPickerFilter *filter; if (!filter) filter = [self new]; return filter; }
@end
@implementation PHPickerConfiguration @end
@implementation PHPickerViewController
- (instancetype)initWithConfiguration:(PHPickerConfiguration *)configuration {
    if ((self = [super init])) self.configuration = configuration; return self;
}
@end
@implementation PHPickerResult @end
@implementation AVAsset
+ (instancetype)assetWithURL:(NSURL *)url { CHECK(url != nil); AVAsset *asset = [self new]; asset.duration = CMTimeMakeWithSeconds(duration, 1000000); return asset; }
@end
@interface MediaProvider : NSItemProvider
@property(nonatomic) BOOL supported;
@property(nonatomic) NSUInteger loads;
@property(nonatomic, strong) NSURL *url;
@end
@implementation MediaProvider
- (BOOL)hasItemConformingToTypeIdentifier:(NSString *)type { CHECK([type isEqual:UTTypeMovie.identifier]); return self.supported; }
- (NSProgress *)loadFileRepresentationForTypeIdentifier:(NSString *)type completionHandler:(void (^)(NSURL *, NSError *))handler {
    CHECK([type isEqual:UTTypeMovie.identifier]); self.loads++;
    handler(self.url, self.url ? nil : [NSError errorWithDomain:@"provider" code:1 userInfo:nil]);
    return [NSProgress progressWithTotalUnitCount:1];
}
@end
@interface RoutingPicker : DVNMediaPicker
@property(nonatomic, strong) NSURL *single;
@property(nonatomic, strong) NSArray *multiple;
@end
@implementation RoutingPicker
- (void)prepareMediaForUse:(NSURL *)url { self.single = url; }
- (void)prepareURLsForImport:(NSArray *)urls { self.multiple = urls; }
@end
static NSURL *writeFile(NSString *path, NSString *contents) {
    NSString *full = [root stringByAppendingPathComponent:path];
    [NSFileManager.defaultManager createDirectoryAtPath:full.stringByDeletingLastPathComponent withIntermediateDirectories:YES attributes:nil error:nil];
    CHECK([contents writeToFile:full atomically:YES encoding:NSUTF8StringEncoding error:nil]);
    return [NSURL fileURLWithPath:full];
}
static BOOL exists(NSString *path) { return [NSFileManager.defaultManager fileExistsAtPath:[root stringByAppendingPathComponent:path]]; }
static NSString *readFile(NSString *path) { return [NSString stringWithContentsOfFile:[root stringByAppendingPathComponent:path] encoding:NSUTF8StringEncoding error:nil]; }
static void drain(void) {
    __block BOOL done = NO;
    dispatch_async(dispatch_get_main_queue(), ^{ done = YES; });
    NSDate *deadline = [NSDate dateWithTimeIntervalSinceNow:2];
    while (!done && deadline.timeIntervalSinceNow > 0) [NSRunLoop.currentRunLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.001]];
    CHECK(done);
}
static UIAlertController *importAlert(DVNMediaPicker *picker, UIViewController *host, NSArray *urls, NSString *folder) {
    [picker prepareURLsForImport:urls];
    UIAlertController *alert = (id)host.presented;
    CHECK([alert.title isEqual:@"LocalImport"] && [alert.message isEqual:@"FolderName"]);
    CHECK([alert.textFields.firstObject.text isEqual:@"Local files"]);
    CHECK(alert.textFields.firstObject.clearButtonMode == UITextFieldViewModeWhileEditing);
    CHECK(alert.actions.count == 2 && alert.actions.lastObject.style == UIAlertActionStyleCancel);
    alert.textFields.firstObject.text = folder; return alert;
}
// Original once block 0x1a3254 invokes alloc/init on its captured receiver.
static NSUInteger factoryNewCalls,factoryInitCalls;
@interface FactoryMediaPicker : DVNMediaPicker @end
@implementation FactoryMediaPicker
+ (instancetype)new { factoryNewCalls++; return [super new]; }
- (instancetype)init { factoryInitCalls++; return [super init]; }
@end
@interface OtherFactoryMediaPicker : DVNMediaPicker @end
@implementation OtherFactoryMediaPicker @end
int main(int argc, const char *argv[]) { @autoreleasepool {
    CHECK(argc == 2); root = @(argv[1]);
    DVNMediaPicker *picker = FactoryMediaPicker.sharedPicker;
    CHECK(object_getClass(picker) == FactoryMediaPicker.class);
    CHECK(factoryNewCalls == 0 && factoryInitCalls == 1);
    CHECK(OtherFactoryMediaPicker.sharedPicker == picker);
    CHECK(picker == DVNMediaPicker.sharedPicker);
    UIViewController *host = [UIViewController new];
    [picker presentImagePickerForVC:host];
    PHPickerViewController *photos = (id)host.presented;
    CHECK(photos.delegate == picker && photos.configuration.selectionLimit == 1);
    CHECK(photos.configuration.filter == PHPickerFilter.videosFilter);
    [picker picker:photos didFinishPicking:@[]]; CHECK(photos.dismissed);
    MediaProvider *provider = [MediaProvider new]; PHPickerResult *result = [PHPickerResult new]; result.itemProvider = provider;
    [picker picker:photos didFinishPicking:@[result]]; CHECK(provider.loads == 0);
    provider.supported = YES;
    [picker picker:photos didFinishPicking:@[result]]; CHECK(provider.loads == 1);
    provider.url = writeFile(@"provider/long.mov", @"long"); duration = 10.000001;
    [picker picker:photos didFinishPicking:@[result]]; drain();
    CHECK([toast isEqual:@"VideoTooLong"] && !success && exists(@"provider/long.mov"));
    writeFile(@"Documents/startup_animation.mp4", @"old");
    provider.url = writeFile(@"provider/short.mov", @"selected"); duration = 10.0;
    [picker picker:photos didFinishPicking:@[result]];
    CHECK(exists(@"tmp/short.mov")); // Copy completes within the provider callback.
    drain();
    CHECK([toast isEqual:@"Done"] && success);
    CHECK([readFile(@"Documents/startup_animation.mov") isEqual:@"selected"]);
    CHECK(!exists(@"Documents/startup_animation.mp4") && !exists(@"tmp/short.mov") && exists(@"provider/short.mov"));
    [picker prepareMediaForUse:nil]; CHECK([toast isEqual:@"MediaNotFound"] && !success);
    NSURL *same = writeFile(@"tmp/same.mov", @"keep"); CHECK([[picker tempCopyOfURL:same] isEqual:same]); CHECK(exists(@"tmp/same.mov"));
    writeFile(@"tmp/collision.mov", @"old");
    NSURL *copySource = writeFile(@"provider/collision.mov", @"new");
    CHECK([picker tempCopyOfURL:copySource] != nil && [readFile(@"tmp/collision.mov") isEqual:@"new"]);
    CHECK([picker tempCopyOfURL:[NSURL fileURLWithPath:[root stringByAppendingPathComponent:@"missing.mov"]]] == nil);
    [picker presentFilePickerForVC:host isMultipleSelection:YES];
    UIDocumentPickerViewController *files = (id)host.presented;
    CHECK(files.delegate == picker && files.allowsMultipleSelection && files.mode == UIDocumentPickerModeImport);
    CHECK(files.types.count == 30 && [files.types.firstObject isEqual:@"public.avi"] && [files.types.lastObject isEqual:@"com.firecore.fileformat.mxf"]);
    RoutingPicker *routing = [RoutingPicker new];
    [routing documentPicker:files didPickDocumentsAtURLs:@[copySource]]; CHECK(routing.single == copySource);
    [routing documentPicker:files didPickDocumentsAtURLs:@[]]; CHECK(routing.multiple.count == 0 && routing.multiple != nil);
    NSURL *a = writeFile(@"provider/a.mp4", @"A"), *b = writeFile(@"provider/b.mkv", @"B");
    [routing documentPicker:files didPickDocumentsAtURLs:@[a,b]]; CHECK(routing.multiple.count == 2);
    NSString *inbox = [NSString stringWithFormat:@"tmp/%@-Inbox", NSBundle.mainBundle.bundleIdentifier];
    writeFile([inbox stringByAppendingPathComponent:@"imported"], @"temporary");
    writeFile(@"tmp/unrelated/keep", @"keep");
    UIAlertController *alert = importAlert(picker, host, @[a,b], @"");
    alert.actions.firstObject.handler(alert.actions.firstObject);
    CHECK([readFile(@"Documents/Local files/a.mp4") isEqual:@"A"] && [readFile(@"Documents/Local files/b.mkv") isEqual:@"B"]);
    CHECK([toast isEqual:@"Imported"] && success && !exists(inbox) && exists(@"tmp/unrelated/keep") && exists(@"provider/a.mp4"));
    // Existing destination: copy failure leaves bytes intact, reports partial.
    writeFile(@"provider/a.mp4", @"CHANGED"); alert = importAlert(picker, host, @[a,b], @"Local files");
    alert.actions.firstObject.handler(alert.actions.firstObject);
    CHECK([toast isEqual:@"Imported.Partly"] && success && [readFile(@"Documents/Local files/a.mp4") isEqual:@"A"]);
    alert = importAlert(picker, host, @[a,b], @"../escape"); alert.actions.firstObject.handler(alert.actions.firstObject);
    CHECK(!success && !exists(@"escape"));
    NSString *outside = [root stringByAppendingPathComponent:@"outside"];
    [NSFileManager.defaultManager createDirectoryAtPath:outside withIntermediateDirectories:YES attributes:nil error:nil];
    CHECK([NSFileManager.defaultManager createSymbolicLinkAtPath:[root stringByAppendingPathComponent:@"Documents/link"] withDestinationPath:outside error:nil]);
    alert = importAlert(picker, host, @[a,b], @"link"); alert.actions.firstObject.handler(alert.actions.firstObject);
    CHECK(!success && !exists(@"outside/a.mp4"));
    NSString *suffixInbox = [inbox stringByAppendingString:@"-2"];
    writeFile([suffixInbox stringByAppendingPathComponent:@"cancelled"], @"temporary");
    alert = importAlert(picker, host, @[a,b], @"Cancelled"); alert.actions.lastObject.handler(alert.actions.lastObject);
    CHECK(!exists(suffixInbox) && !exists(@"Documents/Cancelled") && exists(@"tmp/unrelated/keep"));
    [picker prepareMediaForUse:[NSURL fileURLWithPath:[root stringByAppendingPathComponent:@"missing.mov"]]];
    CHECK(!success && toast.length > 0);
    NSLog(@"PASS: %lu media picker checks; actual copied/removed files confined to %@", (unsigned long)checks, root);
} return 0; }
