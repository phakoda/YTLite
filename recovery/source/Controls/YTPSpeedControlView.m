#import "YTPSpeedControlView.h"
#import "YTPSpeedMaster.h"
#import "ControlsNumbers.h"
#import "../Downloads/YTPMedia.h"

@implementation YTPSpeedControlView
// 0x238360 / 0x238398.
+ (instancetype)speedControls { return [[YTPSpeedControlView alloc] initWithFrame:CGRectZero]; }
- (instancetype)initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) { _step = 0.05f; _presets = @[@1.0, @2.0, @3.0, @5.0, @10.0]; [self setupUI]; }
    return self;
}
// 0x2385a0. All dimensions/colors and action selectors come from the package.
- (void)setupUI {
    self.translatesAutoresizingMaskIntoConstraints = NO;
    self.layer.cornerRadius = 16.0;
    self.backgroundColor = [YTPMedia adaptiveBackgroundColor];
    _valueLabel = [UILabel new];
    _valueLabel.text = [NSString stringWithFormat:@"%.2fx", [YTPSpeedMaster currentPlaybackRate]];
    _valueLabel.textColor = UIColor.labelColor;
    _valueLabel.font = [UIFont boldSystemFontOfSize:18.0];
    _valueLabel.textAlignment = NSTextAlignmentCenter;
    UIButton *minus = [self makeStepButton:@"minus"];
    [minus addTarget:self action:@selector(minusTapped) forControlEvents:UIControlEventTouchUpInside];
    UIButton *plus = [self makeStepButton:@"plus"];
    [plus addTarget:self action:@selector(plusTapped) forControlEvents:UIControlEventTouchUpInside];
    _slider = [UISlider new];
    _slider.minimumValue = 0.25f;
    _slider.maximumValue = 10.0f;
    _slider.value = (float)[YTPSpeedMaster currentPlaybackRate];
    _slider.minimumTrackTintColor = UIColor.labelColor;
    _slider.maximumTrackTintColor = [UIColor.labelColor colorWithAlphaComponent:0.15];
    UIGraphicsImageRenderer *renderer = [[UIGraphicsImageRenderer alloc] initWithSize:CGSizeMake(12, 15)];
    UIImage *thumb = [renderer imageWithActions:^(UIGraphicsImageRendererContext *context) {
        // 0x239344: shadow (0,.5), blur 1, alpha .25; circle (6,7.5), r=6.
        CGContextSetShadowWithColor(context.CGContext, CGSizeMake(0, 0.5), 1.0,
            [UIColor.blackColor colorWithAlphaComponent:0.25].CGColor);
        [UIColor.whiteColor setFill];
        CGContextAddArc(context.CGContext, 6.0, 7.5, 6.0, 0.0, 2.0 * M_PI, 1);
        CGContextFillPath(context.CGContext);
    }];
    [_slider setThumbImage:thumb forState:UIControlStateNormal];
    [_slider addTarget:self action:@selector(sliderChanged:) forControlEvents:UIControlEventValueChanged];
    [_slider addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(sliderTapped:)]];
    UIStackView *controls = [[UIStackView alloc] initWithArrangedSubviews:@[minus, _slider, plus]];
    controls.axis = UILayoutConstraintAxisHorizontal;
    controls.spacing = 12.0;
    controls.alignment = UIStackViewAlignmentCenter;
    NSMutableArray *buttons = [NSMutableArray array];
    for (NSNumber *preset in _presets) [buttons addObject:[self makePresetButton:preset]];
    UIStackView *presets = [[UIStackView alloc] initWithArrangedSubviews:buttons];
    presets.axis = UILayoutConstraintAxisHorizontal;
    presets.spacing = 8.0;
    presets.distribution = UIStackViewDistributionFillEqually;
    UIStackView *stack = [[UIStackView alloc] initWithArrangedSubviews:@[_valueLabel, controls, presets]];
    stack.axis = UILayoutConstraintAxisVertical;
    stack.spacing = 12.0;
    stack.alignment = UIStackViewAlignmentFill;
    stack.translatesAutoresizingMaskIntoConstraints = NO;
    [self addSubview:stack];
    [NSLayoutConstraint activateConstraints:@[
        [stack.topAnchor constraintEqualToAnchor:self.topAnchor constant:24.0],
        [stack.leadingAnchor constraintEqualToAnchor:self.leadingAnchor constant:16.0],
        [stack.trailingAnchor constraintEqualToAnchor:self.trailingAnchor constant:-16.0],
        [stack.bottomAnchor constraintEqualToAnchor:self.bottomAnchor constant:-16.0],
        [presets.heightAnchor constraintEqualToConstant:32.0]]];
}
// 0x239460.
- (UIButton *)makeStepButton:(NSString *)name {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setImage:[UIImage systemImageNamed:name] forState:UIControlStateNormal];
    button.tintColor = UIColor.labelColor;
    button.backgroundColor = [UIColor.labelColor colorWithAlphaComponent:0.15];
    button.layer.cornerRadius = 20.0;
    button.translatesAutoresizingMaskIntoConstraints = NO;
    [NSLayoutConstraint activateConstraints:@[[button.widthAnchor constraintEqualToConstant:40.0],
        [button.heightAnchor constraintEqualToConstant:40.0]]];
    [self addSubview:button];
    return button;
}
// 0x23973c.
- (UIButton *)makePresetButton:(NSNumber *)rate {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:[NSString stringWithFormat:@"%.1f", (double)rate.floatValue] forState:UIControlStateNormal];
    [button setTitleColor:UIColor.labelColor forState:UIControlStateNormal];
    [button addTarget:self action:@selector(presetTapped:) forControlEvents:UIControlEventTouchUpInside];
    button.titleLabel.font = [UIFont systemFontOfSize:12.0 weight:UIFontWeightMedium];
    button.backgroundColor = [UIColor.labelColor colorWithAlphaComponent:0.15];
    button.layer.cornerRadius = 16.0;
    button.tag = (NSInteger)YTLControlsInt64((double)(rate.floatValue * 100.0f));
    button.translatesAutoresizingMaskIntoConstraints = NO;
    [button.heightAnchor constraintEqualToConstant:32.0].active = YES;
    return button;
}
// 0x239ae0 through 0x239e70: FRINTA rounds single-precision step counts.
- (void)sliderChanged:(UISlider *)slider {
    float value = YTLControlsQuantize(slider.value, _step);
    slider.value = value;
    [self updateLabel:value];
}
- (void)sliderTapped:(UITapGestureRecognizer *)recognizer {
    double x = [recognizer locationInView:_slider].x;
    double width = _slider.bounds.size.width;
    float minimum = _slider.minimumValue;
    float maximum = _slider.maximumValue;
    float secondMinimum = _slider.minimumValue;
    float value = YTLControlsQuantize(fmaf((float)(x / width), maximum - secondMinimum, minimum), _step);
    _slider.value = value;
    [self updateLabel:value];
}
- (void)minusTapped {
    float minimum = _slider.minimumValue;
    float value = _slider.value - _step;
    value = minimum < value ? value : minimum;
    value = YTLControlsQuantize(value, _step);
    _slider.value = value;
    [self updateLabel:value];
}
- (void)plusTapped {
    float maximum = _slider.maximumValue;
    float value = _slider.value + _step;
    value = maximum < value ? maximum : value;
    value = YTLControlsQuantize(value, _step);
    _slider.value = value;
    [self updateLabel:value];
}
- (void)presetTapped:(UIButton *)button {
    float value = (float)((double)button.tag / 100.0);
    _slider.value = value;
    [self updateLabel:value];
}
- (void)updateLabel:(float)value {
    _valueLabel.text = [NSString stringWithFormat:@"%.2fx", (double)value];
    [YTPSpeedMaster setPlaybackRate:(double)value forPlayer:nil];
}
@end
