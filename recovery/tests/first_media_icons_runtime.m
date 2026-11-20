// Actual YTPMedia icon factories, with synthetic UIKit and asset-loading boundaries.
#import "../source/Downloads/YTPMedia.h"
#import "../source/Downloads/DownloadsHost.h"
#import <objc/message.h>
#import <objc/runtime.h>
static NSUInteger checks;
static NSMutableArray *events;
static id bundle,passedName;
static UIColor *passedTint;
static __weak UIImage *lastImage;
static BOOL nilBundle,nilImage,nilWhite;
static void (^onBundle)(void);
static void Check(BOOL value,NSString *label) {
    ++checks;if(!value){fprintf(stderr,"FAIL %s\n",label.UTF8String);exit(1);}
}
static void Equal(id a,id b,NSString *label) { Check(a==b || [a isEqual:b],label); }
static void Event(NSString *event){[events addObject:event];}
@implementation UIImage @end
@implementation UITraitCollection @end
@implementation UIColor
+ (UIColor *)whiteColor { Event(@"white");return nilWhite?nil:[self colorWithRed:1 green:1 blue:1 alpha:1]; }
+ (UIColor *)blackColor { Check(NO,@"icon factory unexpectedly requests black");return nil; }
+ (UIColor *)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    UIColor *color=[self new];color.red=r;color.green=g;color.blue=b;color.alpha=a;return color;
}
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider {
    (void)provider;Check(NO,@"icon factory unexpectedly requests dynamic color");return nil;
}
- (BOOL)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a {
    *r=self.red;*g=self.green;*b=self.blue;*a=self.alpha;return YES;
}
@end
@implementation UIApplication
+ (UIApplication *)sharedApplication { Check(NO,@"icon factory unexpectedly reads application state");return nil; }
@end
@interface YTLUserDefaults : NSObject @end
@implementation YTLUserDefaults
+ (BOOL)boolForKey:(NSString *)key { (void)key;Check(NO,@"icon factory unexpectedly reads preferences");return NO; }
@end
@interface IconBundle : NSObject @end
@implementation IconBundle
- (id)objectForInfoDictionaryKey:(NSString *)key { (void)key;return @"99.0"; }
- (UIImage *)imageWithName:(NSString *)name {
    Event(@"image");passedName=name;passedTint=nil;if(nilImage)return nil;
    UIImage *image=[UIImage new];image.name=name;lastImage=image;return image;
}
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)tint {
    Event(@"tintedImage");passedName=name;passedTint=tint;if(nilImage)return nil;
    UIImage *image=[UIImage new];image.name=name;image.tint=tint;lastImage=image;return image;
}
@end
static id MainBundle(id self,SEL cmd){(void)self;(void)cmd;return bundle;}
@implementation NSBundle (IconBoundary)
+ (NSBundle *)ytl_defaultBundle { Event(@"bundle");if(onBundle)onBundle();return nilBundle?nil:bundle; }
@end
@interface CairoProbeMedia : YTPMedia @end
@implementation CairoProbeMedia
- (BOOL)isCairo { Event(@"cairo");return [super isCairo]; }
@end
@interface IconSubclass : YTPMedia @end
@implementation IconSubclass
+ (instancetype)sharedMedia { Check(NO,@"factory must use base YTPMedia singleton dispatch");return nil; }
@end
static UIImage *Factory(Class cls,SEL selector) {
    // A constant copy selector preserves ARC's +1 return-family convention.
    if(selector==@selector(copy))return [cls copy];
    return ((UIImage *(*)(id,SEL))objc_msgSend)(cls,selector);
}
int main(int argc,const char **argv) { @autoreleasepool {
    Check(argc==2,@"first-package icon evidence path supplied");events=[NSMutableArray new];bundle=[IconBundle new];
    Method method=class_getClassMethod(NSBundle.class,@selector(mainBundle));
    class_replaceMethod(object_getClass(NSBundle.class),@selector(mainBundle),(IMP)MainBundle,method_getTypeEncoding(method));
    NSData *data=[NSData dataWithContentsOfFile:@(argv[1])];
    NSDictionary *evidence=[NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    NSArray *icons=evidence[@"icons"];Check(icons.count==59,@"all 59 original icon factories supplied");
    YTPMedia *media=[CairoProbeMedia sharedMedia];
    for(NSDictionary *icon in icons){
        NSString *name=icon[@"selector"],*kind=icon[@"kind"];
        BOOL tinted=[kind isEqual:@"tinted"],fixed=[kind isEqual:@"fixed"];
        SEL selector=NSSelectorFromString(name);
        for(NSUInteger subclass=0;subclass<2;++subclass)for(NSUInteger cairo=0;cairo<2;++cairo)
        for(NSUInteger mode=0;mode<(tinted?5u:4u);++mode){
            __weak UIImage *released;
            @autoreleasepool {
                media.cairo=cairo;nilImage=mode==2;nilBundle=mode==3;nilWhite=mode==4;
                onBundle=mode==1?^{media.cairo=!cairo;}:nil;
                passedName=nil;passedTint=nil;lastImage=nil;[events removeAllObjects];
                UIImage *result=Factory(subclass?IconSubclass.class:YTPMedia.class,selector);released=result;
                NSMutableArray *wanted=[NSMutableArray new];
                if(!fixed)[wanted addObject:@"cairo"];[wanted addObject:@"bundle"];
                if(tinted)[wanted addObject:@"white"];
                if(!nilBundle)[wanted addObject:tinted?@"tintedImage":@"image"];
                Equal(events,wanted,[name stringByAppendingString:@" exact factory call order"]);
                if(nilBundle){Check(passedName==nil,@"nil bundle receives no asset lookup");}
                else{
                    Equal(passedName,icon[cairo?@"cairo":@"normal"],[name stringByAppendingString:@" first-package asset name"]);
                    if(tinted && !nilWhite)
                        Check(passedTint.red==1 && passedTint.green==1 && passedTint.blue==1 && passedTint.alpha==1,@"white tint forwarded");
                    else Check(passedTint==nil,@"no invented tint");
                }
                if(nilImage || nilBundle)Check(result==nil,@"nil result forwarded without fallback");
                else{
                    Check(result!=nil && result==lastImage,@"original bundle image object returned");
                    Equal(result.name,passedName,@"returned image retains requested asset name");
                    Check(result.tint==passedTint,@"returned image retains the tint object");
                }
                passedTint=nil;onBundle=nil;
            }
            Check(released==nil && lastImage==nil,[name stringByAppendingString:@" image released after caller and autorelease pool"]);
        }
    }
    printf("PASS First_media_icons: %lu assertions\n",(unsigned long)checks);return 0;
} }
