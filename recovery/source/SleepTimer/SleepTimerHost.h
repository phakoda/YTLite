#pragma once
#import <UIKit/UIKit.h>
// Typed declarations for the selectors sent to YouTube's existing objects.
@protocol YTLSleepNode <NSObject>
- (id<YTLSleepNode>)responderRoot;
- (id<YTLSleepNode>)appView;
- (id<YTLSleepNode>)delegate;
- (id<YTLSleepNode>)watchLayerView;
- (id<YTLSleepNode>)watchCollectionView;
- (id<YTLSleepNode>)watchViewController;
- (id<YTLSleepNode>)_viewControllerForAncestor;
- (id<YTLSleepNode>)playerViewController;
- (UIViewController *)pivotBarViewController;
- (id<YTLSleepNode>)slimStatusBarView;
- (double)currentVideoTotalMediaTime;
- (double)currentVideoMediaTime;
- (void)setVolume:(float)volume;
- (void)pausePlayback;
- (void)slimStatusBarDisplayStatusDidChange;
- (UILabel *)statusLabel;
- (void)setBackgroundColor:(UIColor *)color;
- (void)setDisplayed:(BOOL)displayed;
- (void)setDismissing:(BOOL)dismissing;
@end
@protocol YTLSleepAlert <NSObject>
+ (instancetype)dialog;
+ (instancetype)infoDialog;
+ (instancetype)confirmationDialogWithAction:(dispatch_block_t)action actionTitle:(NSString *)title;
- (void)setTitle:(NSString *)title;
- (void)setSubtitle:(NSString *)subtitle;
- (void)setCustomContentView:(UIView *)view;
- (void)addTitle:(NSString *)title withAction:(dispatch_block_t)action;
- (void)show;
@end
@protocol YTLSleepSheet <NSObject>
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent;
- (void)addAction:(id)action;
- (void)setSourceView:(UIView *)view;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
@protocol YTLSleepAction <NSObject>
+ (instancetype)actionWithTitle:(NSString *)title subtitle:(NSString *)subtitle iconImage:(UIImage *)image handler:(void (^)(id))handler;
@end
@protocol YTLSleepToastWindow <NSObject>
+ (UIWindow *)toastWindow;
@end
@protocol YTLSleepSpeed <NSObject>
+ (double)playbackRateForPlayer:(id)player;
@end
static inline id<YTLSleepNode> YTLSleepRoot(void) {
    return [(id<YTLSleepNode>)UIApplication.sharedApplication.delegate responderRoot];
}
static inline id<YTLSleepNode> YTLSleepAppRoot(void) {
    id<YTLSleepNode> root = YTLSleepRoot();
    return [NSStringFromClass([root class]) hasPrefix:@"YTAppViewController"] ? root : nil;
}
