#import "PlayerToast.h"
#import "CustomHUD.h"
#import "PresentationHost.h"
#import "PresentationGeometry.h"
#include <limits.h>

static BOOL YTLPlayerBrightnessAlreadyZero;

static long YTLPlayerInteger(double value) {
    if (isnan(value)) return 0;
    if (value >= (double)LONG_MAX) return LONG_MAX;
    if (value <= (double)LONG_MIN) return LONG_MIN;
    return (long)value;
}

@implementation PlayerToast
+ (instancetype)sharedToast {
    static PlayerToast *toast;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ toast = [[self alloc] init]; });
    return toast;
}
- (instancetype)init {
    UIBlurEffect *effect = [UIBlurEffect effectWithStyle:(UIBlurEffectStyle)5];
    self = [super init];
    if (!self) return nil;
    _volumeHUD = [CustomHUD new];
    _activeConstraints = [NSMutableArray new];
    self.alpha = 0;
    self.userInteractionEnabled = NO;
    self.translatesAutoresizingMaskIntoConstraints = NO;
    self.layer.shadowColor = UIColor.blackColor.CGColor;
    self.layer.shadowOffset = CGSizeMake(0, 2);
    self.layer.shadowRadius = 12;
    self.layer.shadowOpacity = 0.2f;
    _toastView = [[UIVisualEffectView alloc] initWithEffect:effect];
    _toastView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _toastView.layer.cornerCurve = kCACornerCurveContinuous;
    _toastView.clipsToBounds = YES;
    _toastImage = [UIImageView new];
    _toastImage.tintColor = UIColor.secondaryLabelColor;
    _toastImage.contentMode = UIViewContentModeScaleAspectFit;
    _toastImage.translatesAutoresizingMaskIntoConstraints = NO;
    _toastLabel = [UILabel new];
    _toastLabel.textColor = UIColor.secondaryLabelColor;
    _toastLabel.font = [UIFont monospacedDigitSystemFontOfSize:13 weight:UIFontWeightBold];
    _toastLabel.textAlignment = NSTextAlignmentCenter;
    _toastLabel.translatesAutoresizingMaskIntoConstraints = NO;
    _toastSubLabel = [UILabel new];
    _toastSubLabel.textColor = UIColor.secondaryLabelColor;
    _toastSubLabel.font = [UIFont monospacedDigitSystemFontOfSize:13 weight:UIFontWeightRegular];
    _toastSubLabel.textAlignment = NSTextAlignmentCenter;
    _toastSubLabel.translatesAutoresizingMaskIntoConstraints = NO;
    _toastProgress = [UIView new];
    _toastProgress.backgroundColor = [UIColor.secondaryLabelColor colorWithAlphaComponent:0.25];
    _toastProgress.translatesAutoresizingMaskIntoConstraints = NO;
    _toastProgress.clipsToBounds = YES;
    _toastProgress.layer.cornerRadius = 2;
    _toastProgress.layer.cornerCurve = kCACornerCurveContinuous;
    _progressLayer = [CAShapeLayer layer];
    _progressLayer.frame = CGRectMake(0, 0, 0, 4);
    [_toastProgress.layer addSublayer:_progressLayer];
    [self addSubview:_toastView];
    [_toastView.contentView addSubview:_toastImage];
    [_toastView.contentView addSubview:_toastLabel];
    [_toastView.contentView addSubview:_toastSubLabel];
    [_toastView.contentView addSubview:_toastProgress];
    return self;
}
- (void)showPlayerToastWithText:(NSString *)text value:(double)value style:(long long)style isCompact:(BOOL)compact {
    _style = style;
    _isCompact = compact;
    _toastImage.image = [self imgForVal:value];
    _toastLabel.text = compact ? nil : text;
    _toastSubLabel.text = [self subLabelForVal:value style:style];
    _progressLayer.backgroundColor = UIColor.secondaryLabelColor.CGColor;
    [self prepareForPresentation];
    [self clearConstraints];
    [self setupConstraints];
    [self setupSubForStyle:style];
    [self.sourceView addSubview:self];
    [_activeConstraints addObjectsFromArray:@[
        [self.topAnchor constraintEqualToAnchor:self.sourceView.safeAreaLayoutGuide.topAnchor constant:self.isLandscape ? 5 : 20],
        [self.centerXAnchor constraintEqualToAnchor:self.sourceView.centerXAnchor]
    ]];
    [NSLayoutConstraint activateConstraints:_activeConstraints];
    [UIView animateWithDuration:0.3 delay:0 options:UIViewAnimationOptionCurveEaseOut animations:^{
        self.alpha = 1;
    } completion:nil];
}
- (void)prepareForPresentation {
    [self.layer removeAllAnimations];
    [self removeFromSuperview];
    self.alpha = 0;
}
- (void)updateToastText:(NSString *)text value:(double)value {
    _toastImage.image = _toastImage.image;
    [self setProgress:value];
    _toastLabel.text = _isCompact ? nil : text;
    // 0x23c2a4 FCVTAS: nearest ties-away, then signed saturation (NaN -> 0).
    const double percentage = (double)YTLPlayerInteger(round(value * 100.0));
    _toastSubLabel.text = [self subLabelForVal:percentage style:_style];
    [self setValue:value forEventWithStyle:_style];
    UIImage *image = [self imgForVal:percentage];
    if (![_toastImage.image isEqual:image]) {
        [UIView transitionWithView:_toastImage duration:0.5 options:(UIViewAnimationOptions)0x500000 animations:^{
            self->_toastImage.image = image;
        } completion:nil];
    }
}
- (void)setProgress:(double)value {
    const CGFloat width = _toastProgress.bounds.size.width;
    if (width <= 0) return;
    // 0x23c5bc/0x23c5c4: FCSEL GT then FMAXNM, including infinities/NaN.
    const CGFloat progressWidth = width * fmax(value > 1 ? 1 : value, 0);
    [CATransaction begin];
    [CATransaction setDisableActions:NO];
    [CATransaction setAnimationDuration:0.1];
    _progressLayer.frame = CGRectMake(0, 0, progressWidth, _toastProgress.bounds.size.height);
    [CATransaction commit];
}
- (void)hideToast {
    [UIView animateWithDuration:0.3 delay:1 options:UIViewAnimationOptionCurveEaseIn animations:^{
        self.alpha = 0;
    } completion:^(BOOL finished) {
        if (finished) {
            [self removeFromSuperview];
            [self->_volumeHUD removeFromController];
        }
    }];
}
- (void)setupConstraints {
    _toastView.layer.cornerRadius = _isCompact ? 15 : 25;
    _toastLabel.hidden = _isCompact;
    const CGFloat right = _isCompact ? -25 : -40;
    const CGFloat secondaryY = _isCompact ? 0 : 10;
    const CGFloat iconSize = _isCompact ? 15 : 25;
    _activeConstraints = [@[
        [self.heightAnchor constraintEqualToConstant:_isCompact ? 30 : 50],
        [self.widthAnchor constraintGreaterThanOrEqualToConstant:_isCompact ? 100 : 200],
        [_toastImage.centerYAnchor constraintEqualToAnchor:self.centerYAnchor],
        [_toastImage.centerXAnchor constraintEqualToAnchor:self.leadingAnchor constant:_isCompact ? 20 : 35],
        [_toastImage.heightAnchor constraintEqualToConstant:iconSize],
        [_toastImage.widthAnchor constraintEqualToConstant:iconSize],
        [_toastLabel.leadingAnchor constraintEqualToAnchor:_toastImage.trailingAnchor constant:10],
        [_toastLabel.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:right],
        [_toastLabel.centerYAnchor constraintEqualToAnchor:self.centerYAnchor constant:_isCompact ? 0 : -10],
        [_toastSubLabel.leadingAnchor constraintEqualToAnchor:_toastImage.trailingAnchor constant:10],
        [_toastSubLabel.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:right],
        [_toastSubLabel.centerYAnchor constraintEqualToAnchor:self.centerYAnchor constant:secondaryY],
        [_toastProgress.widthAnchor constraintGreaterThanOrEqualToConstant:_isCompact ? 60 : 100],
        [_toastProgress.widthAnchor constraintGreaterThanOrEqualToAnchor:_toastLabel.widthAnchor],
        [_toastProgress.heightAnchor constraintEqualToConstant:4],
        [_toastProgress.leadingAnchor constraintEqualToAnchor:_toastImage.trailingAnchor constant:10],
        [_toastProgress.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:right],
        [_toastProgress.centerYAnchor constraintEqualToAnchor:self.centerYAnchor constant:secondaryY]
    ] mutableCopy];
}
- (void)clearConstraints {
    [NSLayoutConstraint deactivateConstraints:_activeConstraints];
    [_activeConstraints removeAllObjects];
}
- (UIImage *)imgForVal:(double)value {
    NSArray<NSString *> *names = @[@"sun.min", @"sun.mid", @"sun.max", @"speed.slow", @"speed.reg",
                                  @"speed.fast", @"vol.off", @"vol.low", @"vol.mid", @"vol.max"];
    const int index = YTLPlayerIconIndex(value, (long)_style);
    if (index < 0) return nil;
    return [UIImage imageNamed:names[(NSUInteger)index] inBundle:[NSBundle ytl_defaultBundle]
        compatibleWithTraitCollection:nil];
}
- (NSString *)subLabelForVal:(double)value style:(long long)style {
    // Decoded UTF-16 initializer at 0x11d2624: 0025 0040 00d7 0000.
    // 0x23de6c FCVT s0,d0 precedes NSNumber numberWithFloat: at 0x23de78.
    if (style == 1) return [NSString stringWithFormat:@"%@×", @((float)value)];
    return [NSString stringWithFormat:@"%ld%%", YTLPlayerInteger(value)];
}
- (void)setupSubForStyle:(long long)style {
    _toastProgress.alpha = style == 1 ? 0 : 1;
    _toastSubLabel.alpha = style == 1 ? 1 : 0;
}
- (void)setValue:(double)value forEventWithStyle:(long long)style {
    if (style == 0) {
        if (value <= 0) {
            if (!YTLPlayerBrightnessAlreadyZero) {
                UIScreen.mainScreen.brightness = 0;
                YTLPlayerBrightnessAlreadyZero = YES;
            }
        } else {
            YTLPlayerBrightnessAlreadyZero = NO;
            UIScreen.mainScreen.brightness = value;
        }
    } else if (style == 2) {
        [_volumeHUD addToController];
        _volumeHUD.volumeLevel = (float)value;
    }
    // Style 1 changes display only; the player gesture owner sets playback rate.
}
- (UIView *)sourceView { return UIApplication.sharedApplication.delegate.window; }
- (BOOL)isLandscape {
    UIWindowScene *scene = (UIWindowScene *)UIApplication.sharedApplication.connectedScenes.allObjects.firstObject;
    return UIInterfaceOrientationIsLandscape(scene.interfaceOrientation);
}
@end
