#import <UIKit/UIKit.h>

// Behavioral doubles for testing call arguments and ARC on macOS. No rendering
// or byte-for-byte UIKit archive equivalence is asserted by these tests.
const UIFontWeight UIFontWeightSemibold = 0.3;
@implementation UIFont
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight {
    UIFont *font = [self new]; font.pointSize = size; font.recoveredTestWeight = weight;
    return font;
}
@end
@implementation UIView @end
@implementation UIViewController
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion {
    self.recoveredPresentedController = controller;
    self.recoveredPresentedAnimated = animated;
    if (self.recoveredOnPresentation) self.recoveredOnPresentation(controller);
    if (completion) completion();
}
@end
@implementation UIImage
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits {
    if ([name isEqual:@"missing"]) return nil;
    UIImage *image = [self new];
    image.recoveredName = name; image.recoveredBundle = bundle;
    image.recoveredOperations = traits ? @[@"non-nil-traits"] : @[@"load"];
    return image;
}
- (UIImage *)imageWithRenderingMode:(UIImageRenderingMode)mode {
    UIImage *image = [UIImage new];
    image.recoveredName = self.recoveredName; image.recoveredBundle = self.recoveredBundle;
    image.recoveredTint = self.recoveredTint; image.renderingMode = mode;
    image.recoveredOperations = [self.recoveredOperations arrayByAddingObject:[NSString stringWithFormat:@"mode:%ld", (long)mode]];
    return image;
}
- (UIImage *)imageWithTintColor:(UIColor *)color {
    UIImage *image = [UIImage new];
    image.recoveredName = self.recoveredName; image.recoveredBundle = self.recoveredBundle;
    image.recoveredTint = color; image.renderingMode = self.renderingMode;
    image.recoveredOperations = [self.recoveredOperations arrayByAddingObject:@"tint"];
    return image;
}
@end
@implementation UIColor
+ (BOOL)supportsSecureCoding { return YES; }
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha {
    UIColor *color = [self new];
    color.recoveredRed = red; color.recoveredGreen = green;
    color.recoveredBlue = blue; color.recoveredAlpha = alpha;
    return color;
}
+ (instancetype)redColor { return [self colorWithRed:1 green:0 blue:0 alpha:1]; }
- (void)encodeWithCoder:(NSCoder *)coder {
    [coder encodeDouble:self.recoveredRed forKey:@"red"];
    [coder encodeDouble:self.recoveredGreen forKey:@"green"];
    [coder encodeDouble:self.recoveredBlue forKey:@"blue"];
    [coder encodeDouble:self.recoveredAlpha forKey:@"alpha"];
}
- (instancetype)initWithCoder:(NSCoder *)coder {
    return [UIColor colorWithRed:[coder decodeDoubleForKey:@"red"]
                          green:[coder decodeDoubleForKey:@"green"]
                           blue:[coder decodeDoubleForKey:@"blue"]
                          alpha:[coder decodeDoubleForKey:@"alpha"]];
}
@end

@implementation UIDocumentPickerViewController
- (instancetype)initWithDocumentTypes:(NSArray *)types inMode:(UIDocumentPickerMode)mode {
    self = [super init];
    if (self) { _recoveredDocumentTypes = types; _recoveredMode = mode; }
    return self;
}
@end
@implementation UIPopoverPresentationController @end
const UIActivityType UIActivityTypeAssignToContact = @"test.assignToContact";
const UIActivityType UIActivityTypePrint = @"test.print";
@implementation UIActivityViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities {
    self = [super init];
    if (self) {
        _recoveredActivityItems = items; _recoveredApplicationActivities = activities;
        self.popoverPresentationController = [UIPopoverPresentationController new];
    }
    return self;
}
@end
