#import "DVNPickerView.h"

@implementation DVNPickerView
// 0x11603c; closed-CFG edges 0x116140..0x1162ac and raw 0x116208..0x116244.
// The original adjusts every immediate subview, not only selection separators.
- (void)layoutSubviews {
    [super layoutSubviews];
    for (UIView *view in self.subviews) {
        CGRect frame = view.frame;
        frame.origin.x = 0;
        frame.size.width = self.bounds.size.width;
        view.frame = frame;
    }
}
@end
