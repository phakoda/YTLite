#import <UIKit/UIKit.h>

@implementation UIView
- (instancetype)init {
    self = [super init];
    if (self) _layer = [CALayer layer];
    return self;
}
- (void)setFrame:(CGRect)frame {
    _frame = frame;
    _bounds.size = frame.size;
    _layer.frame = frame;
}
- (void)setBounds:(CGRect)bounds {
    _bounds = bounds;
    _layer.bounds = bounds;
}
- (id)_viewControllerForAncestor { return self.recoveredAncestor; }
@end

@implementation UILabel
- (void)sizeToFit { self.sizeToFitCalls++; }
@end

@implementation UIColor
+ (BOOL)supportsSecureCoding { return YES; }
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha {
    UIColor *color = [self new];
    CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
    CGFloat components[] = {red, green, blue, alpha};
    color->_color = CGColorCreate(space, components);
    CGColorSpaceRelease(space);
    return color;
}
- (instancetype)initWithCoder:(NSCoder *)coder {
    self = [super init];
    if (self) {
        CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
        CGFloat components[] = {[coder decodeDoubleForKey:@"r"], [coder decodeDoubleForKey:@"g"],
                                [coder decodeDoubleForKey:@"b"], [coder decodeDoubleForKey:@"a"]};
        _color = CGColorCreate(space, components);
        CGColorSpaceRelease(space);
    }
    return self;
}
- (void)encodeWithCoder:(NSCoder *)coder {
    const CGFloat *values = CGColorGetComponents(_color);
    [coder encodeDouble:values[0] forKey:@"r"];
    [coder encodeDouble:values[1] forKey:@"g"];
    [coder encodeDouble:values[2] forKey:@"b"];
    [coder encodeDouble:values[3] forKey:@"a"];
}
- (CGColorRef)CGColor { return _color; }
- (void)dealloc { if (_color) CGColorRelease(_color); }
@end

@implementation UIBezierPath
+ (NSMutableArray<NSDictionary *> *)recoveredCalls {
    static NSMutableArray *calls;
    if (!calls) calls = [NSMutableArray array];
    return calls;
}
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)corners
                            cornerRadii:(CGSize)radii {
    [[self recoveredCalls] addObject:@{@"rect": [NSValue valueWithBytes:&rect objCType:@encode(CGRect)],
        @"corners": @(corners), @"radii": [NSValue valueWithBytes:&radii objCType:@encode(CGSize)]}];
    UIBezierPath *path = [self new];
    // Runtime tests assert the actual UIKit call arguments, not pixel rendering
    // by this double. A real retained CGPath exercises CAShapeLayer ownership.
    path->_path = CGPathCreateWithRect(rect, NULL);
    return path;
}
- (CGPathRef)CGPath { return _path; }
- (void)dealloc { if (_path) CGPathRelease(_path); }
@end
