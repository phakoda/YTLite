#import "DVNMediaPicker.h"
#import <AVFoundation/AVFoundation.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#import "../Presentation/ToastManager.h"
#import "../../../Utils/NSString+YTLite.h"

static NSString *YTLMediaDocuments(void) {
    return NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
}
static NSString *YTLMediaInboxPrefix(void) {
    return [NSString stringWithFormat:@"%@-Inbox", NSBundle.mainBundle.bundleIdentifier];
}
// 0x1a8b58..0x1a8ee0 and 0x1a8f50: import and cancellation share cleanup.
static void YTLMediaCleanInboxes(void) {
    NSFileManager *manager = NSFileManager.defaultManager;
    for (NSString *name in [manager contentsOfDirectoryAtPath:NSTemporaryDirectory() error:nil]) {
        if ([name hasPrefix:YTLMediaInboxPrefix()])
            [manager removeItemAtPath:[NSTemporaryDirectory() stringByAppendingPathComponent:name] error:nil];
    }
}

@implementation DVNMediaPicker
// 0x1a31a0 / singleton block 0x1a3254.
+ (instancetype)sharedPicker {
    static DVNMediaPicker *picker;
    static dispatch_once_t once;
    // The original uses objc_alloc_init on the receiver, bypassing +new.
    dispatch_once(&once, ^{ picker = [[self alloc] init]; });
    return picker;
}
// 0x1a327c: despite the selector name, this is a one-video picker.
- (void)presentImagePickerForVC:(UIViewController *)controller {
    _viewController = controller;
    PHPickerConfiguration *configuration = [PHPickerConfiguration new];
    configuration.selectionLimit = 1;
    configuration.filter = PHPickerFilter.videosFilter;
    PHPickerViewController *picker = [[PHPickerViewController alloc] initWithConfiguration:configuration];
    picker.delegate = self;
    [controller presentViewController:picker animated:YES completion:nil];
}
// 0x1a3390 and provider callback 0x1a35a8.
- (void)picker:(PHPickerViewController *)picker didFinishPicking:(NSArray<PHPickerResult *> *)results {
    [picker dismissViewControllerAnimated:YES completion:nil];
    if (results.count == 0) return;
    NSItemProvider *provider = results.firstObject.itemProvider;
    if (![provider hasItemConformingToTypeIdentifier:UTTypeMovie.identifier]) return;
    [provider loadFileRepresentationForTypeIdentifier:UTTypeMovie.identifier completionHandler:^(NSURL *url, NSError *error) {
        if (!url) return;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        double duration = CMTimeGetSeconds([AVAsset assetWithURL:url].duration);
#pragma clang diagnostic pop
        if (duration > 10.0) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [ToastManager showMessageWithText:[@"VideoTooLong" ytl_localized] isSuccess:NO];
            });
        } else {
            // Provider URLs expire when this callback returns. Copy before dispatch.
            NSURL *copy = [self tempCopyOfURL:url];
            dispatch_async(dispatch_get_main_queue(), ^{ [self prepareMediaForUse:copy]; });
        }
    }];
}
// 0x1a39b8: original import mode and all 30 declared media UTIs.
- (void)presentFilePickerForVC:(UIViewController *)controller isMultipleSelection:(BOOL)multiple {
    _viewController = controller;
    NSArray *types = @[@"public.avi", @"public.mpeg", @"public.mpeg-4", @"public.3gpp", @"public.3gpp2", @"public.movie",
        @"com.microsoft.advanced-systems-format", @"com.microsoft.windows-media-wmv",
        @"com.firecore.fileformat.dvr-ms", @"com.firecore.fileformat.flv", @"com.firecore.fileformat.mpg",
        @"com.firecore.fileformat.wmv", @"com.firecore.fileformat.mkv", @"com.firecore.fileformat.ts",
        @"com.firecore.fileformat.m2ts", @"com.firecore.fileformat.mts", @"com.firecore.fileformat.avi",
        @"com.firecore.fileformat.m4v", @"com.firecore.fileformat.mov", @"com.firecore.fileformat.mp4",
        @"com.firecore.fileformat.mpeg", @"com.firecore.fileformat.mod", @"com.firecore.fileformat.wtv",
        @"com.firecore.fileformat.ogm", @"com.firecore.fileformat.ogv", @"com.firecore.fileformat.webm",
        @"com.firecore.fileformat.asf", @"com.firecore.fileformat.rmvb", @"com.firecore.fileformat.vob", @"com.firecore.fileformat.mxf"];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    UIDocumentPickerViewController *picker = [[UIDocumentPickerViewController alloc] initWithDocumentTypes:types inMode:UIDocumentPickerModeImport];
#pragma clang diagnostic pop
    picker.delegate = self;
    picker.allowsMultipleSelection = multiple;
    [controller presentViewController:picker animated:YES completion:nil];
}
// 0x1a691c: a single document becomes the startup animation; other counts import.
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls {
    if (urls.count == 1) [self prepareMediaForUse:urls.firstObject];
    else [self prepareURLsForImport:urls];
}
// 0x1a6a20. Same-location protection is a recovery addition.
- (NSURL *)tempCopyOfURL:(NSURL *)url {
    NSURL *copy = [[NSURL fileURLWithPath:NSTemporaryDirectory() isDirectory:YES] URLByAppendingPathComponent:url.lastPathComponent];
    if ([url.URLByStandardizingPath isEqual:copy.URLByStandardizingPath]) return url;
    NSFileManager *manager = NSFileManager.defaultManager;
    if ([manager fileExistsAtPath:copy.path]) [manager removeItemAtURL:copy error:nil];
    NSError *error = nil;
    [manager copyItemAtURL:url toURL:copy error:&error];
    return error ? nil : copy;
}
// 0x1a6c7c. Preserve removal order, successful-source cleanup and failure toast.
- (void)prepareMediaForUse:(NSURL *)url {
    if (!url) {
        [ToastManager showMessageWithText:[@"MediaNotFound" ytl_localized] isSuccess:NO];
        return;
    }
    NSFileManager *manager = NSFileManager.defaultManager;
    NSString *documents = YTLMediaDocuments();
    NSString *filename = [NSString stringWithFormat:@"startup_animation.%@", url.pathExtension];
    NSURL *destination = [NSURL fileURLWithPath:[documents stringByAppendingPathComponent:filename]];
    // Avoid deleting an existing animation if it is itself selected as input.
    if ([url.URLByStandardizingPath isEqual:destination.URLByStandardizingPath]) return;
    for (NSString *extension in @[@"mp4", @"mov"])
        [manager removeItemAtPath:[documents stringByAppendingPathComponent:[NSString stringWithFormat:@"startup_animation.%@", extension]] error:nil];
    NSError *error = nil;
    if ([manager copyItemAtURL:url toURL:destination error:&error]) {
        [ToastManager showMessageWithText:[@"Done" ytl_localized] isSuccess:YES];
        [manager removeItemAtURL:url error:nil];
    } else {
        [ToastManager showMessageWithText:error.localizedDescription isSuccess:NO];
        NSLog(@"DVN --- error: %@, full path: %@", error, url);
    }
    [manager removeItemAtPath:[NSTemporaryDirectory() stringByAppendingPathComponent:YTLMediaInboxPrefix()] error:nil];
}
// 0x1a79a0, text-field block 0x1a7f3c, import block 0x1a80f8.
- (void)prepareURLsForImport:(NSArray<NSURL *> *)urls {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:[@"LocalImport" ytl_localized]
        message:[@"FolderName" ytl_localized] preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField *field) {
        field.placeholder = @"Local files";
        field.clearButtonMode = UITextFieldViewModeWhileEditing;
        field.text = @"Local files";
    }];
    __weak UIAlertController *weakAlert = alert;
    [alert addAction:[UIAlertAction actionWithTitle:[@"ImportToFolder" ytl_localized] style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
        NSString *folder = weakAlert.textFields.firstObject.text;
        if (folder.length == 0) folder = @"Local files";
        // Boundary addition: the entered name must stay inside Documents, even
        // when an existing directory is a symbolic link.
        NSURL *documents = [[NSURL fileURLWithPath:YTLMediaDocuments() isDirectory:YES] URLByResolvingSymlinksInPath];
        NSURL *directory = [[documents URLByAppendingPathComponent:folder isDirectory:YES] URLByResolvingSymlinksInPath];
        NSString *prefix = [documents.path stringByAppendingString:@"/"];
        if (![directory.path hasPrefix:prefix] || [folder isEqualToString:@"."] || [folder isEqualToString:@".."]) {
            [ToastManager showMessageWithText:[@"Imported.Partly" ytl_localized] isSuccess:NO];
            return;
        }
        NSFileManager *manager = NSFileManager.defaultManager;
        NSUInteger imported = 0;
        for (NSURL *url in urls) {
            [manager createDirectoryAtPath:directory.path withIntermediateDirectories:YES attributes:nil error:nil];
            NSError *error = nil;
            [manager copyItemAtURL:url toURL:[directory URLByAppendingPathComponent:url.lastPathComponent] error:&error];
            if (!error) imported++;
        }
        [ToastManager showMessageWithText:[(imported == urls.count ? @"Imported" : @"Imported.Partly") ytl_localized] isSuccess:YES];
        YTLMediaCleanInboxes();
    }]];
    [alert addAction:[UIAlertAction actionWithTitle:[@"Cancel" ytl_localized] style:UIAlertActionStyleCancel handler:^(UIAlertAction *action) {
        YTLMediaCleanInboxes();
    }]];
    [_viewController presentViewController:alert animated:YES completion:nil];
}
@end
