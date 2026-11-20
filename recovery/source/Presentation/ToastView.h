#pragma once
#import <UIKit/UIKit.h>

@class ToastWindow;
@interface ToastView : UIVisualEffectView {
    NSMutableArray<dispatch_block_t> *_commandQueue;
    BOOL _isiPad;
    BOOL _isAnimating;
    BOOL _ignoresFullscreenOpacity;
    BOOL _ignoresPanGesture;
    UIWindow *_ytSourceView;
    UIView *_sourceView;
    double _keyboardHeight;
    double _goodHeight;
    UILabel *_toastLabel;
    UIProgressView *_toastProgress;
    UIImageView *_toastIcon;
    UIStackView *_actionsStack;
    UIButton *_toastButton;
    UIActivityIndicatorView *_activityIndicator;
    NSTimer *_progressTimer;
    NSLayoutConstraint *_topConstraint;
    NSLayoutConstraint *_bottomConstraint;
    NSLayoutConstraint *_centerXConstraint;
    NSLayoutConstraint *_widthConstraint;
    NSLayoutConstraint *_heightConstraint;
    dispatch_block_t _completion;
}
@property(nonatomic, copy) dispatch_block_t completion;
+ (void)initialize;
+ (ToastWindow *)toastWindow;
- (instancetype)init;
- (void)enqueueCommand:(dispatch_block_t)command;
- (void)processQueue;
- (void)setupInterfaceWithText:(NSString *)text progress:(float)progress withStop:(BOOL)stop
                     isStatus:(BOOL)status isSuccess:(BOOL)success withWait:(BOOL)wait;
- (void)handlePanGesture:(UIPanGestureRecognizer *)recognizer;
- (void)handleTap;
- (void)updateLayout;
- (void)calculateToastParametersWithKeyboardHeight:(double)keyboard
                                     bottomOffset:(double *)bottom topOffset:(double *)top scale:(double *)scale;
- (void)configureToastAppearanceWithBottomOffset:(double)bottom topOffset:(double)top
                                           scale:(double)scale width:(double)width animationDuration:(double)duration;
- (void)configureToastAppearanceWithBottomOffset:(double)bottom topOffset:(double)top
                                           scale:(double)scale width:(double)width alpha:(double)alpha
                               animationDuration:(double)duration completion:(dispatch_block_t)completion;
- (void)setupObservers;
- (void)removeObservers;
- (void)goodHeightDidChange:(NSNotification *)notification;
- (void)keyboardWillShow:(NSNotification *)notification;
- (void)keyboardWillHide:(NSNotification *)notification;
- (void)cleanup;
- (void)cancelButtonTapped;
- (void)handleLongPress:(UILongPressGestureRecognizer *)recognizer;
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)stop
             stopCompletion:(dispatch_block_t)completion;
- (void)updateText:(NSString *)text progress:(float)progress;
- (void)updateText:(NSString *)text progress:(float)progress animated:(BOOL)animated;
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success;
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success duration:(double)duration;
- (void)showText:(NSString *)text;
- (void)showToast:(NSString *)text;
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration isSuccess:(BOOL)success;
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                       actionTitle:(NSString *)title actionCompletion:(dispatch_block_t)completion;
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(UIImage *)icon actionCompletion:(dispatch_block_t)completion;
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(UIImage *)icon ignoresPan:(BOOL)ignoresPan
                  actionCompletion:(dispatch_block_t)completion;
- (void)showDonationReminder:(NSString *)text;
- (void)startTimerCountdown:(double)duration;
- (void)hideAnimatedWithCompletion:(dispatch_block_t)completion;
- (void)hideImmediately;
- (void)hideWithDelay:(double)delay;
- (void)hide;
- (BOOL)isHidden;
- (void)hideWithCompletion:(dispatch_block_t)completion;
- (BOOL)isLandscape;
- (BOOL)isFullscreen;
- (BOOL)isPinnedTop;
- (double)bottomOffset;
@end
