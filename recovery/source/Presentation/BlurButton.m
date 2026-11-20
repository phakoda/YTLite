#import "BlurButton.h"

@implementation BlurButton
+ (instancetype)createButtonWithImage:(UIImage *)image target:(id)target
                               action:(SEL)action menu:(UIMenu *)menu {
    BlurButton *button = [BlurButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(0, 0, 28, 28);
    // Original 0x2231d0 creates the effect before allocation at 0x2231e8.
    UIBlurEffect *effect = [UIBlurEffect effectWithStyle:(UIBlurEffectStyle)16];
    UIVisualEffectView *blur = [[UIVisualEffectView alloc] initWithEffect:effect];
    blur.frame = button.bounds;
    blur.layer.cornerRadius = 14;
    blur.clipsToBounds = YES;
    blur.userInteractionEnabled = NO;
    [button addSubview:blur];
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 18, 18)];
    imageView.center = blur.center;
    imageView.contentMode = UIViewContentModeCenter;
    imageView.image = image;
    imageView.tintColor = UIColor.whiteColor;
    [blur.contentView addSubview:imageView];
    button->_buttonImageView = imageView;
    if (menu) {
        button.menu = menu;
        button.showsMenuAsPrimaryAction = YES;
    } else {
        [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    }
    return button;
}
- (void)setHighlighted:(BOOL)highlighted {
    [super setHighlighted:highlighted];
    _buttonImageView.alpha = highlighted ? 0.25 : 1.0;
}
@end
