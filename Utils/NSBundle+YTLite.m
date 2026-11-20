#import "NSBundle+YTLite.h"
#import <UIKit/UIKit.h>
#import "../recovery/source/Runtime/YTLRootPaths.h"

#if defined(YTLITE_RESOURCE_ROOTHIDE)
// The first supplied package imports this C++ function. Keep its exact linker
// name when declaring the NSString boundary in this Objective-C source file.
extern NSString *jbroot(NSString *path) __asm__("__Z6jbrootP8NSString");
#endif

@protocol YTLBundleAlert <NSObject>
+ (id<YTLBundleAlert>)infoDialog;
- (void)setTitle:(NSString *)title;
- (void)setSubtitle:(NSString *)subtitle;
- (void)show;
@end

@implementation NSBundle (YTLite)

+ (NSBundle *)ytl_defaultBundle {
    static NSBundle *bundle = nil;
    static dispatch_once_t onceToken;

    dispatch_once(&onceToken, ^{
        NSString *tweakBundlePath = [[NSBundle mainBundle] pathForResource:@"YTLite" ofType:@"bundle"];
#if defined(YTLITE_RESOURCE_ROOTHIDE)
        NSString *installedPath = jbroot(@"/Library/Application Support/YTLite.bundle");
#else
        char storage[1024];
        const char *resolved = YTLJailbreakPath([@"/Library/Application Support/YTLite.bundle" fileSystemRepresentation], storage);
        NSString *installedPath = resolved ? [NSString stringWithUTF8String:resolved] : nil;
#endif
        NSString *path = tweakBundlePath ?: installedPath;
        if ([[NSFileManager defaultManager] fileExistsAtPath:path]) {
            bundle = [NSBundle bundleWithPath:path];
        } else {
            bundle = [NSBundle mainBundle];
            Class<YTLBundleAlert> alertClass = (Class<YTLBundleAlert>)NSClassFromString(@"YTAlertView");
            id<YTLBundleAlert> alert = [alertClass infoDialog];
            [alert setTitle:@"Warning"];
            [alert setSubtitle:@"Resource files for YouTube Plus not found. YouTube might not function correctly."];
            [alert show];
        }
    });

    return bundle;
}

// 0x2355c0.
- (UIImage *)imageWithName:(NSString *)name {
    return [[UIImage imageNamed:name inBundle:self compatibleWithTraitCollection:nil] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
}

// 0x235628.
- (UIImage *)originalImageWithName:(NSString *)name {
    return [UIImage imageNamed:name inBundle:self compatibleWithTraitCollection:nil];
}

// 0x235644.
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color {
    UIImage *image = [[[self imageWithName:name] imageWithTintColor:color] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
    image.accessibilityIdentifier = [NSString stringWithFormat:@"ytp_%@_image", name];
    return image;
}
@end
