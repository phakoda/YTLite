#pragma once
#import <UIKit/UIKit.h>

// Recovered selector/ivar surface: 0x22311c–0x2234cc. ARC emits .cxx_destruct.
@interface BlurButton : UIButton {
    UIImageView *_buttonImageView;
}
+ (instancetype)createButtonWithImage:(UIImage *)image
                               target:(id)target
                               action:(SEL)action
                                 menu:(UIMenu *)menu;
- (void)setHighlighted:(BOOL)highlighted;
@end
