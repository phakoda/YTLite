#import "YTLHelper.h"
#import "HelpersHost.h"
#import "HelpersTransforms.h"
#import "../Downloads/YTPDownloader.h"
#import "../Downloads/FFMpegHelper.h"
#import "../Presentation/ToastView.h"
#import "../Presentation/ToastManager.h"
#import "../Presentation/PresentationHost.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import <Photos/Photos.h>
#import <SystemConfiguration/SystemConfiguration.h>
#include <netinet/in.h>

static NSError *YTLHelperPathError(void) {
    return [NSError errorWithDomain:@"YTLHelper" code:NSFileWriteInvalidFileNameError
        userInfo:@{NSLocalizedDescriptionKey:YTLPresentationLocalized(@"Error.PathIssue")}];
}

static UIImage *YTLRenderHelperImage(UIImage *image, double size, BOOL tint) {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(size, size)];
    return [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0, 0, size, size)];
        UIImageView *view = [[UIImageView alloc] initWithImage:image];
        view.contentMode = UIViewContentModeScaleAspectFit;
        view.clipsToBounds = YES;
        if (tint) view.tintColor = [UIColor.labelColor colorWithAlphaComponent:0.699999988079071];
        view.frame = container.bounds;
        [container addSubview:view];
        [container.layer renderInContext:context.CGContext];
    }];
}

static void YTLCompleteConversion(YTLHelper *helper, NSURL *result, NSError *error,
                                  NSURL *destination, NSString * __strong *videoID, BOOL audioOnly) {
    // The callback owns helper; this ivar address stays valid for the synchronous
    // call and is read after routing, as in the original two-capture blocks.
    NSFileManager *manager = NSFileManager.defaultManager;
    if (error) {
        [manager removeItemAtURL:result error:nil];
        [ToastManager showMessageWithText:error.localizedDescription isSuccess:NO];
        return;
    }
    NSError *moveError = nil;
    [manager moveItemAtURL:result toURL:destination error:&moveError];
    if (moveError) {
        [ToastManager showMessageWithText:YTLPresentationLocalized(@"Error.PathIssue") isSuccess:NO];
    } else if (audioOnly) {
        [helper shareMedia:destination];
    } else if (ytpInt(@"postDownloadIndex") == 0) {
        [helper saveMedia:destination];
    } else if (ytpInt(@"postDownloadIndex") == 1) {
        [helper shareMedia:destination];
    } else {
        [helper askForAction:destination];
    }
    NSArray<NSString *> *formats = audioOnly ? @[@"%@/%@_a.m4a", @"%@/%@_a.ytpmap"] :
        @[@"%@/%@_v.mp4", @"%@/%@_a.m4a", @"%@/%@_a.ytpmap", @"%@/%@_a.ytpmap"];
    // The repeated audio map (rather than a video map) is in the original
    // 0x22da70 / 0x22db0c call sites. Preserve it; cleanup removes the directory.
    NSUInteger count = formats.count;
    NSURL *intermediates[4] = {nil};
    for (NSUInteger index = 0; index < count; index++) {
        NSString *temporaryDirectory = NSTemporaryDirectory();
        NSString *identifier = *videoID;
        if (!YTLIsSinglePathComponent(identifier)) return;
        intermediates[index] = [NSURL fileURLWithPath:[temporaryDirectory stringByAppendingPathComponent:
            [NSString stringWithFormat:formats[index], identifier, identifier]]];
    }
    for (NSUInteger index = 0; index < count; index++)
        [NSFileManager.defaultManager removeItemAtURL:intermediates[index] error:nil];
}

@implementation YTLHelper
- (instancetype)init {
    self = [super init];
    if (self) {
        _toastView = [[ToastView alloc] init];
        _illegalChars = [NSCharacterSet characterSetWithCharactersInString:@"/\\?*|\"<>"];
    }
    return self;
}
- (void)downloadVideoWithUrl:(NSURL *)videoURL audioUrl:(NSURL *)audioURL
                   fileName:(NSString *)name format:(NSString *)format videoID:(NSString *)videoID
                  videoSize:(unsigned long long)videoSize audioSize:(unsigned long long)audioSize
                   duration:(unsigned long long)duration captions:(NSURL *)captions {
    if (!YTLIsSinglePathComponent(videoID) || !YTLIsSinglePathComponent(format)) {
        [self downloadDidFailureWithError:YTLHelperPathError()];
        return;
    }
    _isVideoDownloaded = NO;
    _isAudioOnly = NO;
    _audioUrl = audioURL;
    _title = YTLDownloadSanitizedTitle(name, _illegalChars);
    _videoID = videoID;
    _audioSize = audioSize;
    _format = format;
    _duration = YTLDownloadDurationSeconds(duration);
    _captionsUrl = captions;
    _downloader = [[YTPDownloader alloc] init];
    _downloader.delegate = self;
    [_downloader downloadFileWithURL:videoURL fileName:[NSString stringWithFormat:@"%@_v.mp4", _videoID]
        videoID:_videoID fileSize:videoSize];
    // The copied stop block retains this operation across root-helper replacement.
    // Original toast cleanup preserves this callback even after hiding.
    [_toastView showProgressWithText:YTLPresentationLocalized(@"DownloadingVideo") progress:0 withStop:YES
        stopCompletion:^{ [self->_downloader cancelDownload]; }];
}
- (void)downloadAudioWithUrl:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID
                  audioSize:(unsigned long long)size duration:(unsigned long long)duration {
    if (url && name && videoID && size && duration) {
        if (!YTLIsSinglePathComponent(videoID)) {
            [self downloadDidFailureWithError:YTLHelperPathError()];
            return;
        }
        _isAudioOnly = YES;
        _audioUrl = url;
        _title = YTLDownloadSanitizedTitle(name, _illegalChars);
        _videoID = videoID;
        _audioSize = size;
        _duration = YTLDownloadDurationSeconds(duration);
    }
    // All-nil/zero arguments mean the second phase of the existing video job.
    if (!_audioUrl || !YTLIsSinglePathComponent(_videoID)) {
        [self downloadDidFailureWithError:YTLHelperPathError()];
        return;
    }
    _isVideoDownloaded = YES;
    _downloader = [[YTPDownloader alloc] init];
    _downloader.delegate = self;
    [_downloader downloadFileWithURL:_audioUrl fileName:[NSString stringWithFormat:@"%@_a.m4a", _videoID]
        videoID:_videoID fileSize:_audioSize];
    if (_isAudioOnly) {
        [_toastView showProgressWithText:YTLPresentationLocalized(@"DownloadingAudio") progress:0 withStop:YES stopCompletion:^{
            [self->_downloader cancelDownload];
        }];
    } else [_toastView updateText:YTLPresentationLocalized(@"DownloadingAudio") progress:0 animated:NO];
}
- (void)downloadProgress:(float)progress {
    [_toastView updateText:[NSString stringWithFormat:@"%@: %.0f%%",
        YTLPresentationLocalized(_isVideoDownloaded ? @"DownloadingAudio" : @"DownloadingVideo"),
        (double)(progress * 100.0f)] progress:progress];
}
- (void)downloadDidFinish:(NSURL *)url fileName:(NSString *)name {
    (void)name;
    if (!url) { [self downloadDidFailureWithError:YTLHelperPathError()]; return; }
    NSString *videoTemporaryDirectory = NSTemporaryDirectory();
    NSString *videoIdentifier = _videoID;
    if (!YTLIsSinglePathComponent(videoIdentifier)) { [self downloadDidFailureWithError:YTLHelperPathError()]; return; }
    NSURL *videoOutput = [NSURL fileURLWithPath:[videoTemporaryDirectory stringByAppendingPathComponent:
        [NSString stringWithFormat:@"%@/%@.%@", videoIdentifier, _title, _format]]];
    NSString *audioTemporaryDirectory = NSTemporaryDirectory();
    NSString *audioIdentifier = _videoID;
    if (!YTLIsSinglePathComponent(audioIdentifier)) { [self downloadDidFailureWithError:YTLHelperPathError()]; return; }
    NSURL *audioOutput = [NSURL fileURLWithPath:[audioTemporaryDirectory stringByAppendingPathComponent:
        [NSString stringWithFormat:@"%@/%@.m4a", audioIdentifier, _title]]];
    [NSFileManager.defaultManager removeItemAtURL:videoOutput error:nil];
    [NSFileManager.defaultManager removeItemAtURL:audioOutput error:nil];
    if (!_isVideoDownloaded) {
        _videoUrl = url;
        [self downloadAudioWithUrl:nil fileName:nil videoID:nil audioSize:0 duration:0];
        return;
    }
    [_toastView hide];
    if (_isAudioOnly) {
        [[FFMpegHelper sharedInstance] cutAudio:url duration:(long long)_duration
            completion:^(NSURL *result, NSError *error) {
                YTLCompleteConversion(self, result, error, audioOutput, &self->_videoID, YES);
            }];
    } else {
        [[FFMpegHelper sharedInstance] mergeVideo:_videoUrl withAudio:url captions:_captionsUrl
            duration:(long long)_duration completion:^(NSURL *result, NSError *error) {
                YTLCompleteConversion(self, result, error, videoOutput, &self->_videoID, NO);
            }];
    }
}
- (void)downloadDidFailureWithError:(NSError *)error {
    if (error && error.code != NSURLErrorCancelled) {
        NSLog(@"YTPlus --- %@", error);
        [_toastView showMessageWithText:error.localizedDescription isSuccess:NO];
    }
}
- (void)saveMedia:(NSURL *)url {
    if ([url.pathExtension isEqualToString:@"m4a"]) { [self shareMedia:url]; return; }
    [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
        [[PHAssetCreationRequest creationRequestForAsset] addResourceWithType:PHAssetResourceTypeVideo
            fileURL:url options:nil];
    } completionHandler:^(BOOL success, NSError *error) {
        (void)error;
        dispatch_async(dispatch_get_main_queue(), ^{
            if (success) {
                [self cleanup];
                [ToastManager showMessageWithText:YTLPresentationLocalized(@"Saved") isSuccess:YES];
            } else [self shareMedia:url];
        });
    }];
}
- (void)shareMedia:(NSURL *)url {
    UIActivityViewController *activity = [[UIActivityViewController alloc]
        initWithActivityItems:@[url] applicationActivities:nil];
    activity.excludedActivityTypes = @[UIActivityTypeAssignToContact, UIActivityTypePrint];
    activity.completionWithItemsHandler = ^(UIActivityType type, BOOL completed, NSArray *items, NSError *error) {
        (void)type; (void)completed; (void)items; (void)error;
        [self cleanup];
    };
    UIViewController *presenter = [NSClassFromString(@"YTUIUtils") topViewControllerForPresenting];
    if (activity.popoverPresentationController) {
        activity.popoverPresentationController.sourceView = presenter.view;
        CGFloat width = UIScreen.mainScreen.bounds.size.width;
        CGFloat height = UIScreen.mainScreen.bounds.size.height;
        activity.popoverPresentationController.sourceRect = CGRectMake(width * 0.5, height, 0, 0);
        activity.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionAny;
    }
    [presenter presentViewController:activity animated:YES completion:nil];
}
- (void)cleanup {
    NSString *temporaryDirectory = NSTemporaryDirectory();
    NSString *identifier = _videoID;
    if (!YTLIsSinglePathComponent(identifier)) return;
    NSURL *directory = [NSURL fileURLWithPath:[temporaryDirectory
        stringByAppendingPathComponent:[NSString stringWithFormat:@"%@", identifier]]];
    [NSFileManager.defaultManager removeItemAtURL:directory error:nil];
}
- (void)askForAction:(NSURL *)url {
    YTDefaultSheetController *sheet = [NSClassFromString(@"YTDefaultSheetController")
        sheetControllerWithMessage:YTLPresentationLocalized(@"DownloadCompleted") delegate:nil parentResponder:nil];
    [sheet addAction:[NSClassFromString(@"YTActionSheetAction")
        actionWithTitle:YTLPresentationLocalized(@"SaveToPhotos") iconImage:[self imageNamed:@"save_photos"]
        secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ [self saveMedia:url]; }]];
    [sheet addAction:[NSClassFromString(@"YTActionSheetAction")
        actionWithTitle:YTLPresentationLocalized(@"Share")
        iconImage:[NSClassFromString(@"YTUIResources") actionsheetShareImage]
        secondaryIconImage:nil accessibilityIdentifier:nil handler:^{ [self shareMedia:url]; }]];
    UIViewController *root = UIApplication.sharedApplication.delegate.window.rootViewController;
    [sheet setSourceView:[root pivotBarViewController].view];
    [sheet presentFromViewController:root animated:YES completion:nil];
}
- (UIImage *)resizeImage:(UIImage *)image toSize:(double)size {
    return YTLRenderHelperImage(image, size, YES);
}
- (UIImage *)imageNamed:(NSString *)name {
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(24, 24)];
    UIImage *result = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        UIImage *image = [UIImage imageNamed:name inBundle:[NSBundle ytl_defaultBundle] compatibleWithTraitCollection:nil];
        UIView *container = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 24, 24)];
        UIImageView *view = [[UIImageView alloc] initWithImage:image];
        view.contentMode = UIViewContentModeScaleAspectFit;
        view.clipsToBounds = YES;
        view.frame = container.bounds;
        [container addSubview:view];
        [container.layer renderInContext:context.CGContext];
    }];
    return [result imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}
+ (UIImage *)YTImageNamed:(NSString *)name {
    YTAssetLoader *loader = [[NSClassFromString(@"YTAssetLoader") alloc] initWithBundle:NSBundle.mainBundle];
    return [loader imageNamed:name];
}
+ (UIImage *)YTLImageNamed:(NSString *)name {
    YTAssetLoader *loader = [[NSClassFromString(@"YTAssetLoader") alloc] initWithBundle:[NSBundle ytl_defaultBundle]];
    return [loader imageNamed:name];
}
+ (BOOL)isConnectedToWiFi {
    struct sockaddr_in address = {0};
    address.sin_len = sizeof(address);
    address.sin_family = AF_INET;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    SCNetworkReachabilityRef reachability = SCNetworkReachabilityCreateWithAddress(NULL, (const struct sockaddr *)&address);
    if (!reachability) return NO;
    SCNetworkReachabilityFlags flags = 0;
    BOOL success = SCNetworkReachabilityGetFlags(reachability, &flags);
    CFRelease(reachability);
#pragma clang diagnostic pop
    return YTLReachabilityFlagsAreWiFi(success, flags);
}
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                   buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector {
    return [[self class] createYTQTMButton:target accessibilityLabel:accessibilityLabel buttonLabel:label
        icon:icon size:CGSizeMake(40, 40) selector:selector];
}
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                   buttonLabel:(NSString *)label icon:(UIImage *)icon size:(CGSize)size selector:(SEL)selector {
    YTQTMButton *button = [NSClassFromString(@"YTQTMButton") iconButton];
    button.accessibilityLabel = accessibilityLabel;
    [button enableNewTouchFeedback];
    if (icon) [button setImage:icon forState:UIControlStateNormal];
    else {
        [button setTitle:label forState:UIControlStateNormal];
        button.titleLabel.adjustsFontSizeToFitWidth = YES;
    }
    button.tintColor = UIColor.whiteColor;
    button.translatesAutoresizingMaskIntoConstraints = NO;
    [button addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    [button.widthAnchor constraintEqualToConstant:size.width].active = YES;
    [button.heightAnchor constraintEqualToConstant:size.height].active = YES;
    return button;
}
+ (UIButton *)createOverlayButton:(id)target accessibilityLabel:(NSString *)accessibilityLabel
                     buttonLabel:(NSString *)label icon:(UIImage *)icon selector:(SEL)selector {
    YTQTMButton *button = [NSClassFromString(@"YTQTMButton") iconButton];
    button.accessibilityLabel = accessibilityLabel;
    [button enableNewTouchFeedback];
    if (icon) [button setImage:[icon imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate]
                     forState:UIControlStateNormal];
    else {
        [button setTitle:label forState:UIControlStateNormal];
        button.titleLabel.adjustsFontSizeToFitWidth = YES;
    }
    button.tintColor = UIColor.whiteColor;
    button.translatesAutoresizingMaskIntoConstraints = NO;
    [button addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    [button.widthAnchor constraintEqualToConstant:24].active = YES;
    [button.heightAnchor constraintEqualToConstant:36].active = YES;
    button.touchFeedbackView.forceCircularTouchFeedback = YES;
    button.touchFeedbackView.touchFeedbackInsets = UIEdgeInsetsMake(0, -6, 0, -6);
    UIColor *feedbackColor = UIColor.whiteColor;
    button.touchFeedbackView.customTouchFeedbackColor = feedbackColor;
    return button;
}
+ (void)downloadImageFromURL:(NSURL *)url download:(BOOL)download {
    NSURL *requestURL = YTLDownloadImageURL(url);
    [[NSURLSession.sharedSession dataTaskWithURL:requestURL
        completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
            (void)response;
            if (!data) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    NSString *text = [NSString stringWithFormat:@"%@: %@",
                        YTLPresentationLocalized(@"Error"), error.localizedDescription];
                    [ToastManager showMessageWithText:text isSuccess:NO];
                });
            } else if (!download) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    UIPasteboard.generalPasteboard.image = [UIImage imageWithData:data];
                    [ToastManager showMessageWithText:YTLPresentationLocalized(@"Copied") isSuccess:YES];
                });
            } else {
                [[PHPhotoLibrary sharedPhotoLibrary] performChanges:^{
                    [[PHAssetCreationRequest creationRequestForAsset] addResourceWithType:PHAssetResourceTypePhoto
                        data:data options:nil];
                } completionHandler:^(BOOL success, NSError *photoError) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *text = success ? YTLPresentationLocalized(@"Saved") :
                            [NSString stringWithFormat:YTLPresentationLocalized(@"%@: %@"),
                                YTLPresentationLocalized(@"Error"), photoError.localizedDescription];
                        [ToastManager showMessageWithText:text isSuccess:success];
                    });
                }];
            }
        }] resume];
}
+ (void)genImageFromLayer:(CALayer *)layer backgroundColor:(UIColor *)color
      completionHandler:(void (^)(UIImage *))completion {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    UIGraphicsBeginImageContextWithOptions(layer.frame.size, NO, 0);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, color.CGColor);
    CGFloat width = layer.frame.size.width;
    CGFloat height = layer.frame.size.height;
    CGContextFillRect(context, CGRectMake(0, 0, width, height));
    [layer renderInContext:context];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
#pragma clang diagnostic pop
    if (completion) completion(image);
}
+ (UIImage *)resizeImage:(UIImage *)image toSize:(double)size {
    return YTLRenderHelperImage(image, size, NO);
}
@end
