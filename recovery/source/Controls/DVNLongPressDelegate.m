#import "DVNLongPressDelegate.h"

@implementation DVNLongPressDelegate
// 0x1f21c0, closed continuation in analysis-v3. Mode 1 is the left third,
// mode 2 the right third, mode 3 either outer third. Boundary points count.
// No Y-coordinate filter or bounds-origin adjustment is added to the original.
- (BOOL)isTouchInSpeedZone:(CGPoint)point {
    if (self.mode == 0 || !self.view) return NO;
    double third = self.view.bounds.size.width / 3.0;
    switch (self.mode) {
        case 1: return point.x <= third;
        case 2: return third + third <= point.x;
        case 3: return third + third <= point.x || point.x <= third;
        default: return NO;
    }
}
// 0x1f2444. UIKit computes the location in the weakly owned target view.
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)recognizer shouldReceiveTouch:(UITouch *)touch {
    (void)recognizer;
    return [self isTouchInSpeedZone:[touch locationInView:self.view]];
}
// The four accessors and weak-reference destruction are emitted by ARC.
@end
