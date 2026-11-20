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
    fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #__VA_ARGS__); exit(3); \
} } while (0)
// Synthetic implementation of the original imported NSString boundary only.
extern NSString *jbroot(NSString *path) __asm__("__Z6jbrootP8NSString");
NSString *jbroot(NSString *path) {
    CHECK([path isEqual:@"/Library/Application Support/YTLite.bundle"]);pathCalls++;
    return installedFixture;
}
static NSString *seenInstalledPath;
static IMP originalExists;
static BOOL probeExists(id receiver,SEL selector,NSString *path) {
    seenInstalledPath=path;
    if(path.length>1024)return NO;
    return ((BOOL(*)(id,SEL,id))originalExists)(receiver,selector,path);
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
        if([mode isEqual:@"long"])
            installedFixture=[@"/" stringByAppendingString:[@"resource" stringByPaddingToLength:1400 withString:@"resource" startingAtIndex:0]];
        Method exists=class_getInstanceMethod(NSFileManager.class,@selector(fileExistsAtPath:));
        originalExists=method_setImplementation(exists,(IMP)probeExists);
        @try {
            NSBundle *bundle = [NSBundle ytl_defaultBundle];
            CHECK(pathCalls == 1);
            if([mode isEqual:@"long"])CHECK(seenInstalledPath==installedFixture&&seenInstalledPath.length==1401);
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
        } @finally { method_setImplementation(getter, original);method_setImplementation(exists, originalExists); }
        printf("First-package bundle assertions passed: %lu (%s).\n", (unsigned long)checks, mode.UTF8String);
    }
    return 0;
}
