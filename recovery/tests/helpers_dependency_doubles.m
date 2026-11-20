// Test boundaries for the separately verified Downloads/host implementations.
// This file is not a production build input and does not call a real downloader,
// codec, application settings store, or YouTube host implementation.
#import "presentation_doubles.h"
#import "../source/Helpers/HelpersHost.h"
#import "../source/Downloads/DownloaderDelegate.h"
#import "../source/Presentation/PresentationHost.h"
#import "../source/Runtime/YTLBootstrapCrypto.h"

@interface YTPDownloader : NSObject
@property(nonatomic,weak) id<DownloaderDelegate> delegate;
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID fileSize:(unsigned long long)size;
- (void)cancelDownload;
@end
@implementation YTPDownloader
- (void)downloadFileWithURL:(NSURL *)url fileName:(NSString *)name videoID:(NSString *)videoID fileSize:(unsigned long long)size {
    NSCAssert(url && name && videoID,@"non-null recovered transport arguments");
    [PresentationDownloads addObject:@{@"downloader":self,@"url":url,@"name":name,@"videoID":videoID,@"size":@(size)}];
}
- (void)cancelDownload { PresentationRecord(@"download.cancel",self); }
@end

@interface FFMpegHelper : NSObject
+ (instancetype)sharedInstance;
- (void)mergeVideo:(NSURL *)video withAudio:(NSURL *)audio captions:(NSURL *)captions duration:(long long)duration
        completion:(void (^)(NSURL *,NSError *))completion;
- (void)cutAudio:(NSURL *)audio duration:(long long)duration completion:(void (^)(NSURL *,NSError *))completion;
@end
@implementation FFMpegHelper
+ (instancetype)sharedInstance { static FFMpegHelper *helper;if(!helper)helper=[self new];return helper; }
- (void)mergeVideo:(NSURL *)video withAudio:(NSURL *)audio captions:(NSURL *)captions duration:(long long)duration
        completion:(void (^)(NSURL *,NSError *))completion {
    [PresentationConversions addObject:@{@"operation":@"merge",@"video":video,@"audio":audio,
        @"captions":captions ?: NSNull.null,@"duration":@(duration),@"completion":[completion copy]}];
}
- (void)cutAudio:(NSURL *)audio duration:(long long)duration completion:(void (^)(NSURL *,NSError *))completion {
    [PresentationConversions addObject:@{@"operation":@"cut",@"audio":audio,@"duration":@(duration),@"completion":[completion copy]}];
}
@end

@interface YTAssetLoader ()
@property(nonatomic,strong) NSBundle *fixtureBundle;
@end
@implementation YTAssetLoader
- (instancetype)initWithBundle:(NSBundle *)bundle { self=[super init];if(self){_fixtureBundle=bundle;PresentationRecord(@"host.assetLoader",bundle.bundlePath);}return self; }
- (UIImage *)imageNamed:(NSString *)name { return [UIImage imageNamed:name inBundle:_fixtureBundle compatibleWithTraitCollection:nil]; }
@end
@implementation YTQTMButtonTouchFeedbackView @end
@interface YTQTMButton ()
@property(nonatomic,strong) YTQTMButtonTouchFeedbackView *fixtureFeedback;
@end
@implementation YTQTMButton
+ (instancetype)iconButton { return [self buttonWithType:UIButtonTypeCustom]; }
- (void)enableNewTouchFeedback { _fixtureFeedback=[YTQTMButtonTouchFeedbackView new];PresentationRecord(@"host.touchFeedback",@YES); }
- (YTQTMButtonTouchFeedbackView *)touchFeedbackView { return _fixtureFeedback; }
@end
@implementation YTUIUtils
+ (UIViewController *)topViewControllerForPresenting { return UIApplication.sharedApplication.delegate.window.rootViewController; }
@end
@interface YTActionSheetAction ()
@property(nonatomic,copy) NSString *fixtureTitle;
@property(nonatomic,strong) UIImage *fixtureImage;
@property(nonatomic,copy) dispatch_block_t fixtureHandler;
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary
       accessibilityIdentifier:(NSString *)identifier handler:(dispatch_block_t)handler {
    NSCAssert(!secondary && !identifier,@"recovered action defaults");YTActionSheetAction *action=[self new];
    action.fixtureTitle=title;action.fixtureImage=icon;action.fixtureHandler=handler;return action;
}
@end
@interface YTDefaultSheetController ()
@property(nonatomic,copy) NSString *fixtureMessage;
@property(nonatomic,strong) NSMutableArray<YTActionSheetAction *> *fixtureActions;
@property(nonatomic,strong) UIView *fixtureSource;
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithMessage:(NSString *)message delegate:(id)delegate parentResponder:(id)parent {
    NSCAssert(!delegate&&!parent,@"sheet default ownership");YTDefaultSheetController *sheet=[self new];
    sheet.fixtureMessage=message;sheet.fixtureActions=[NSMutableArray new];return sheet;
}
- (void)addAction:(YTActionSheetAction *)action { [_fixtureActions addObject:action]; }
- (void)setSourceView:(UIView *)view { _fixtureSource=view; }
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion {
    PresentationRecord(@"host.sheet",@{@"sheet":self,@"presenter":controller,@"animated":@(animated)});if(completion)completion();
}
@end
@implementation YTUIResources
+ (UIImage *)actionsheetShareImage { return [UIImage systemImageNamed:@"host.share"]; }
@end
@implementation UIViewController (YTLHelperHostRoot)
- (UIViewController *)pivotBarViewController { return self; }
@end
@interface YTToastOffsetController ()
@property(nonatomic) double fixtureBottom;
@end
@implementation YTToastOffsetController
- (double)bottomOffset { return _fixtureBottom; }
@end

NSInteger ytpInt(NSString *key) {
    NSCAssert([key isEqualToString:@"postDownloadIndex"],@"only the recovered routing preference may be requested");
    PresentationRecord(@"preference.read",key);return PresentationPostDownloadIndex;
}
