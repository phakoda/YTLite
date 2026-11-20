#import "../source/Presentation/BlurButton.h"
#import <objc/runtime.h>

static NSMutableArray *events;
static void SuperHighlighted(id self, SEL selector, BOOL value) {
    (void)self; (void)selector;
    [events addObject:value ? @"super:YES" : @"super:NO"];
}
@interface HighlightProbe : UIImageView
@end
@implementation HighlightProbe
- (void)setAlpha:(CGFloat)value {
    [events addObject:@(value)];
    [super setAlpha:value];
}
@end
int main(void) {
    @autoreleasepool {
        events = [NSMutableArray new];
        Method method = class_getInstanceMethod(UIButton.class, @selector(setHighlighted:));
        IMP original = method_setImplementation(method, (IMP)SuperHighlighted);
        BlurButton *button = [BlurButton new];
        HighlightProbe *icon = [HighlightProbe new];
        [button setValue:icon forKey:@"_buttonImageView"];
        for (NSNumber *value in @[@YES, @NO, @NO, @YES]) {
            [events removeAllObjects];
            [button setHighlighted:value.boolValue];
            NSArray *expected = @[value.boolValue ? @"super:YES" : @"super:NO",
                                  value.boolValue ? @0.25 : @1.0];
            if (![events isEqual:expected]) return 1;
            if (icon.alpha != [expected[1] doubleValue]) return 2;
        }
        [button setValue:nil forKey:@"_buttonImageView"];
        [events removeAllObjects];
        [button setHighlighted:YES];
        if (![events isEqual:@[@"super:YES"]]) return 3;
        method_setImplementation(method, original);
        puts("PASS: highlight superclass order, alpha transitions, repeat calls, nil image");
    }
    return 0;
}
