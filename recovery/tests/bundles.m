#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "../../Utils/NSBundle+YTLite.h"
#import "../../Utils/NSString+YTLite.h"
#import "../source/Runtime/YTLRootPaths.h"

static NSUInteger checks, pathCalls, alerts;
static NSBundle *mainFixture;
static NSString *installedFixture;
static NSString *alertTitle, *alertSubtitle;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); abort(); \
} } while (0)
char *YTLJailbreakPath(const char *path, char *output) {
    CHECK(!strcmp(path, "/Library/Application Support/YTLite.bundle"));
    CHECK(output != NULL); pathCalls++;
    if (!installedFixture) return NULL;
    strlcpy(output, installedFixture.fileSystemRepresentation, 1024);
    return output;
}
@interface YTAlertView : NSObject
+ (instancetype)infoDialog;
- (void)setTitle:(NSString *)title;
- (void)setSubtitle:(NSString *)subtitle;
- (void)show;
@end
@implementation YTAlertView
+ (instancetype)infoDialog { return [self new]; }
- (void)setTitle:(NSString *)title { alertTitle = title; }
- (void)setSubtitle:(NSString *)subtitle { alertSubtitle = subtitle; }
- (void)show { alerts++; }
@end
static NSBundle *replacementMainBundle(id receiver, SEL selector) { return mainFixture; }

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        if (argc != 4) { fprintf(stderr, "usage: bundles-test main.bundle installed.bundle mode\n"); return 2; }
        NSString *mode = [NSString stringWithUTF8String:argv[3]];
        mainFixture = [NSBundle bundleWithPath:[NSString stringWithUTF8String:argv[1]]];
        installedFixture = [mode isEqual:@"null"] ? nil : [NSString stringWithUTF8String:argv[2]];
        CHECK(mainFixture != nil);
        Method getter = class_getClassMethod([NSBundle class], @selector(mainBundle));
        IMP original = method_setImplementation(getter, (IMP)replacementMainBundle);
        @try {
            NSBundle *bundle = [NSBundle ytl_defaultBundle];
            CHECK(pathCalls == 1);
            if ([mode isEqual:@"bundled"]) {
                CHECK([bundle.bundlePath hasSuffix:@"/YTLite.bundle"] && bundle != mainFixture && alerts == 0);
            } else if ([mode isEqual:@"installed"]) {
                CHECK([bundle.bundlePath isEqual:installedFixture] && alerts == 0);
            } else if ([mode isEqual:@"invalid"]) {
                CHECK(bundle == nil && alerts == 0);
            } else {
                CHECK(bundle == mainFixture && alerts == 1);
                CHECK([alertTitle isEqual:@"Warning"]);
                CHECK([alertSubtitle isEqual:@"Resource files for YouTube Plus not found. YouTube might not function correctly."]);
            }
            CHECK([NSBundle ytl_defaultBundle] == bundle && [NSBundle ytl_defaultBundle] == bundle && pathCalls == 1);
            CHECK(alerts <= 1);
            if (bundle) {
                CHECK([[@"Translated" ytl_localized] isEqual:@"Fixture translation"]);
                NSMutableString *empty = [@"Empty" mutableCopy];
                CHECK([empty ytl_localized] == empty);
                CHECK([[@"Unknown fixture key" ytl_localized] isEqual:@"Unknown fixture key"]);
                UIImage *plain = [bundle originalImageWithName:@"symbol"];
                CHECK(plain.renderingMode == UIImageRenderingModeAutomatic && plain.recoveredBundle == bundle);
                CHECK([plain.recoveredName isEqual:@"symbol"] && [plain.recoveredOperations isEqual:@[@"load"]]);
                UIImage *template = [bundle imageWithName:@"symbol"];
                CHECK(template.renderingMode == UIImageRenderingModeAlwaysTemplate);
                CHECK([template.recoveredOperations isEqual:@[@"load", @"mode:2"]]);
                UIColor *color = [UIColor redColor];
                UIImage *tinted = [bundle imageWithName:@"symbol" tintColor:color];
                CHECK(tinted.renderingMode == UIImageRenderingModeAlwaysOriginal && tinted.recoveredTint == color);
                CHECK([tinted.recoveredOperations isEqual:@[@"load", @"mode:2", @"tint", @"mode:1"]]);
                CHECK([tinted.accessibilityIdentifier isEqual:@"ytp_symbol_image"]);
                CHECK([bundle imageWithName:@"missing"] == nil);
                CHECK([bundle originalImageWithName:@"missing"] == nil);
                CHECK([bundle imageWithName:@"missing" tintColor:color] == nil);
            } else {
                CHECK([[@"key" ytl_localized] isEqual:@"key"]);
            }
        } @finally { method_setImplementation(getter, original); }
        printf("Bundle/localization assertions passed: %lu (%s).\n", (unsigned long)checks, mode.UTF8String);
    }
    return 0;
}
