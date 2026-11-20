#pragma once
#import <UIKit/UIKit.h>

@interface YTPSpeedControlView : UIView {
    UISlider *_slider;
    UILabel *_valueLabel;
    NSArray *_presets;
    float _step;
}
+ (instancetype)speedControls;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)setupUI;
- (UIButton *)makeStepButton:(NSString *)name;
- (UIButton *)makePresetButton:(NSNumber *)rate;
- (void)sliderChanged:(UISlider *)slider;
- (void)sliderTapped:(UITapGestureRecognizer *)recognizer;
- (void)minusTapped;
- (void)plusTapped;
- (void)presetTapped:(UIButton *)button;
- (void)updateLabel:(float)value;
@end
