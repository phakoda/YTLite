#pragma once
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
@class CustomHUD;

@interface PlayerToast : UIView {
    BOOL _isCompact;
    long long _style;
    NSMutableArray *_activeConstraints;
    UIView *_containerView;
    UIVisualEffectView *_toastView;
    UIImageView *_toastImage;
    UILabel *_toastLabel;
    UILabel *_toastSubLabel;
    UIView *_toastProgress;
    CAShapeLayer *_progressLayer;
    CustomHUD *_volumeHUD;
}
+ (instancetype)sharedToast;
- (instancetype)init;
- (void)showPlayerToastWithText:(NSString *)text value:(double)value style:(long long)style isCompact:(BOOL)compact;
- (void)prepareForPresentation;
- (void)updateToastText:(NSString *)text value:(double)value;
- (void)setProgress:(double)value;
- (void)hideToast;
- (void)setupConstraints;
- (void)clearConstraints;
- (UIImage *)imgForVal:(double)value;
- (NSString *)subLabelForVal:(double)value style:(long long)style;
- (void)setupSubForStyle:(long long)style;
- (void)setValue:(double)value forEventWithStyle:(long long)style;
- (UIView *)sourceView;
- (BOOL)isLandscape;
@end
