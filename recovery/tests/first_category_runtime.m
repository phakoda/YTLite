#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "../../Utils/NSBundle+YTLite.h"
#import "../../Utils/NSString+YTLite.h"

// Runs the real category implementations. Only UIKit/NSBundle boundaries are
// replaced; no original executable code or platform image renderer is loaded.
static NSUInteger checks, stopStage, descriptionCalls, lookupCalls, lengthCalls;
static NSMutableArray<NSString *> *events;
static id expectedName, expectedColor, expectedBundle, translation, localizationHost;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { \
    fprintf(stderr,"FAIL %s:%d: %s\n",__FILE__,__LINE__,#__VA_ARGS__); exit(3); \
} } while (0)

extern NSString *jbroot(NSString *) __asm__("__Z6jbrootP8NSString");
NSString *jbroot(NSString *path) { CHECK(NO); return nil; }

@interface NameProbe : NSObject @end
@implementation NameProbe
- (NSString *)description { descriptionCalls++; [events addObject:@"description"]; return @"probe"; }
@end

@interface ImageProbe : UIImage
@property NSUInteger stage;
@end
static ImageProbe *stages[4];
@implementation ImageProbe
- (UIImage *)imageWithRenderingMode:(UIImageRenderingMode)mode {
    CHECK((self==stages[0] && mode==UIImageRenderingModeAlwaysTemplate) ||
          (self==stages[2] && mode==UIImageRenderingModeAlwaysOriginal));
    [events addObject:[NSString stringWithFormat:@"mode:%lu:%ld",self.stage,(long)mode]];
    return stopStage==self.stage+1 ? nil : stages[self.stage+1];
}
- (UIImage *)imageWithTintColor:(UIColor *)color {
    CHECK(self==stages[1] && color==expectedColor);
    [events addObject:@"tint"];
    return stopStage==2 ? nil : stages[2];
}
- (void)setAccessibilityIdentifier:(NSString *)identifier {
    CHECK(self==stages[3]);
    NSString *text=expectedName ? ([expectedName isKindOfClass:NameProbe.class] ? @"probe" : expectedName) : @"(null)";
    CHECK([identifier isEqual:[NSString stringWithFormat:@"ytp_%@_image",text]]);
    [events addObject:@"identifier"];
}
@end
static id loadImage(id receiver,SEL selector,id name,id bundle,id traits) {
    CHECK(receiver==UIImage.class && name==expectedName && bundle==expectedBundle && traits==nil);
    [events addObject:@"load"];
    return stopStage==0 ? nil : stages[0];
}

@interface LengthProbe : NSObject
@property NSUInteger result;
@end
@implementation LengthProbe
- (NSUInteger)length { lengthCalls++; return self.result; }
@end
@interface LocalizationProbe : NSObject @end
@implementation LocalizationProbe
- (id)localizedStringForKey:(id)key value:(id)value table:(id)table {
    CHECK(key==expectedName && value==nil && table==nil);lookupCalls++;
    return translation;
}
@end
static id defaultBundle(id receiver,SEL selector) { return localizationHost; }

// Preserve dynamic dispatch to imageWithName: in the tint helper. This proxy
// inherits the actual tint IMP but provides an observable imageWithName:.
@interface BundleProbe : NSObject
- (UIImage *)imageWithName:(NSString *)name;
@end
@implementation BundleProbe
- (UIImage *)imageWithName:(NSString *)name {
    CHECK(name==expectedName);[events addObject:@"override"];return stages[1];
}
@end

int main(void) {
    @autoreleasepool {
        events=[NSMutableArray new];
        for(NSUInteger i=0;i<4;i++) { stages[i]=[ImageProbe new];stages[i].stage=i; }
        expectedBundle=NSBundle.mainBundle;expectedColor=UIColor.redColor;
        Method loader=class_getClassMethod(UIImage.class,@selector(imageNamed:inBundle:compatibleWithTraitCollection:));
        IMP savedLoader=method_setImplementation(loader,(IMP)loadImage);
        @try {
            // Every intermediate image can be nil. Formatting still occurs
            // after the chain even when there is no final image.
            for(stopStage=0;stopStage<=4;stopStage++) {
                expectedName=[NameProbe new];descriptionCalls=0;[events removeAllObjects];
                UIImage *result=[expectedBundle imageWithName:expectedName tintColor:expectedColor];
                CHECK(result==(stopStage==4 ? stages[3] : nil));
                NSMutableArray *expected=[NSMutableArray arrayWithObject:@"load"];
                if(stopStage>0)[expected addObject:@"mode:0:2"];
                if(stopStage>1)[expected addObject:@"tint"];
                if(stopStage>2)[expected addObject:@"mode:2:1"];
                [expected addObject:@"description"];
                if(stopStage>3)[expected addObject:@"identifier"];
                CHECK([events isEqual:expected]);CHECK(descriptionCalls==1);
            }
            for(NSUInteger missing=0;missing<2;missing++) {
                stopStage=missing ? 0 : 4;expectedName=@"plain";[events removeAllObjects];
                CHECK([expectedBundle originalImageWithName:expectedName]==(missing ? nil : stages[0]));
                CHECK([events isEqual:@[@"load"]]);[events removeAllObjects];
                CHECK([expectedBundle imageWithName:expectedName]==(missing ? nil : stages[1]));
                CHECK([events isEqual:missing ? @[@"load"] : @[@"load",@"mode:0:2"]]);
            }
            // These assert forwarding at a fake UIKit boundary, not UIKit's
            // behavior for nil or empty names/tints on an actual device.
            for(NSUInteger empty=0;empty<2;empty++) {
                stopStage=4;expectedName=empty ? @"" : nil;expectedColor=nil;[events removeAllObjects];
                CHECK([expectedBundle imageWithName:expectedName tintColor:expectedColor]==stages[3]);
                CHECK([events isEqual:@[@"load",@"mode:0:2",@"tint",@"mode:2:1",@"identifier"]]);
            }
            Method tint=class_getInstanceMethod(NSBundle.class,@selector(imageWithName:tintColor:));
            CHECK(class_addMethod(BundleProbe.class,method_getName(tint),method_getImplementation(tint),method_getTypeEncoding(tint)));
            expectedName=@"override";expectedColor=UIColor.redColor;[events removeAllObjects];
            CHECK([(NSBundle *)(id)[BundleProbe new] imageWithName:expectedName tintColor:expectedColor]==stages[3]);
            CHECK([events isEqual:@[@"override",@"tint",@"mode:2:1",@"identifier"]]);
        } @finally { method_setImplementation(loader,savedLoader); }

        Method bundle=class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle));
        IMP savedBundle=method_setImplementation(bundle,(IMP)defaultBundle);
        @try {
            expectedName=[@"mutable key" mutableCopy];localizationHost=[LocalizationProbe new];
            for(NSNumber *number in @[@0,@1,@(NSUIntegerMax)]) {
                LengthProbe *value=[LengthProbe new];value.result=number.unsignedIntegerValue;translation=value;
                lengthCalls=lookupCalls=0;
                CHECK([expectedName ytl_localized]==(value.result ? value : expectedName));
                CHECK(lengthCalls==1 && lookupCalls==1);
            }
            translation=nil;lookupCalls=0;
            CHECK([expectedName ytl_localized]==expectedName && lookupCalls==1);
            localizationHost=nil;lookupCalls=0;
            CHECK([expectedName ytl_localized]==expectedName && lookupCalls==0);
        } @finally { method_setImplementation(bundle,savedBundle); }
        printf("First-package category assertions passed: %lu.\n",(unsigned long)checks);
    }
}
