#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Helpers/HelpersHost.h"
#import <objc/runtime.h>

static NSMutableArray *assetEvents;
static YTAssetLoader *assetAllocated, *assetInitialized;
static NSBundle *assetBundle;
static NSString *assetName;
static UIImage *assetImage;
static BOOL assetMainBundle;

// Method-family declarations preserve ARC's alloc/init ownership conventions.
// Only the synthetic host class gets its own alloc method; NSObject is untouched.
@interface YTAssetLoader (HelperAssetProbe)
+ (instancetype)allocForAssetProbe;
- (instancetype)initForAssetProbe:(NSBundle *)bundle;
@end
@implementation YTAssetLoader (HelperAssetProbe)
+ (instancetype)allocForAssetProbe {
    [assetEvents addObject:@"alloc"];
    PCheck(self==YTAssetLoader.class,@"asset factory resolves the original host class");
    return assetAllocated;
}
- (instancetype)initForAssetProbe:(NSBundle *)bundle {
    [assetEvents addObject:@"init"];
    PCheck(self==assetAllocated && bundle==assetBundle,@"initializer receives allocated object and selected bundle unchanged");
    return assetInitialized;
}
@end
static id AssetBundle(id receiver,SEL selector) {
    (void)receiver;
    [assetEvents addObject:@"bundle"];
    PCheck(selector==(assetMainBundle ? @selector(mainBundle) : NSSelectorFromString(@"ytl_defaultBundle")),
        @"asset method chooses the original bundle factory");
    return assetBundle;
}
static id AssetNamed(id receiver,SEL selector,NSString *name) {
    (void)selector;[assetEvents addObject:@"image"];
    PCheck(receiver==assetInitialized && name==assetName,@"lookup uses initializer result and original name identity");
    return assetImage;
}

static void TestAssetLoaders(void) {
    NSBundle *bundleToken=NSBundle.mainBundle;
    NSString *nameToken=[NSMutableString stringWithString:@"fixture-icon"];
    YTAssetLoader *allocated=[YTAssetLoader new], *replacement=[YTAssetLoader new];
    UIImage *imageToken=[UIImage new];
    Method inherited=class_getClassMethod(YTAssetLoader.class,@selector(alloc));
    IMP oldAlloc=method_getImplementation(inherited);
    class_addMethod(object_getClass(YTAssetLoader.class),@selector(alloc),oldAlloc,method_getTypeEncoding(inherited));
    Method alloc=class_getClassMethod(YTAssetLoader.class,@selector(alloc));
    Method init=class_getInstanceMethod(YTAssetLoader.class,@selector(initWithBundle:));
    Method named=class_getInstanceMethod(YTAssetLoader.class,@selector(imageNamed:));
    Method main=class_getClassMethod(NSBundle.class,@selector(mainBundle));
    Method tweak=class_getClassMethod(NSBundle.class,NSSelectorFromString(@"ytl_defaultBundle"));
    method_setImplementation(alloc,method_getImplementation(class_getClassMethod(YTAssetLoader.class,@selector(allocForAssetProbe))));
    IMP oldInit=method_setImplementation(init,method_getImplementation(class_getInstanceMethod(YTAssetLoader.class,@selector(initForAssetProbe:))));
    IMP oldNamed=method_setImplementation(named,(IMP)AssetNamed);
    IMP oldMain=method_setImplementation(main,(IMP)AssetBundle);
    IMP oldTweak=method_setImplementation(tweak,(IMP)AssetBundle);
    @try {
        for(NSUInteger factory=0;factory<2;factory++)for(NSUInteger mode=0;mode<7;mode++) {
            assetMainBundle=factory==0;
            assetName=mode==1 ? nil : nameToken;
            assetBundle=mode==2 ? nil : bundleToken;
            assetAllocated=mode==3 ? nil : allocated;
            assetInitialized=mode==4 ? nil : mode==6 ? replacement : allocated;
            assetImage=mode==5 ? nil : imageToken;
            [assetEvents removeAllObjects];
            UIImage *result=assetMainBundle ? [YTLHelper YTImageNamed:assetName] : [YTLHelper YTLImageNamed:assetName];
            NSArray *order=mode==3 ? @[@"alloc",@"bundle"] : mode==4 ? @[@"alloc",@"bundle",@"init"] :
                @[@"alloc",@"bundle",@"init",@"image"];
            PEqual(assetEvents,order,@"allocation precedes bundle lookup, including nil allocation and initialization");
            PCheck(result==((mode==3 || mode==4) ? nil : assetImage),@"asset factory returns image lookup result unchanged, including nil");
        }
    } @finally {
        method_setImplementation(alloc,oldAlloc);method_setImplementation(init,oldInit);
        method_setImplementation(named,oldNamed);method_setImplementation(main,oldMain);method_setImplementation(tweak,oldTweak);
        assetAllocated=nil;assetInitialized=nil;assetBundle=nil;assetName=nil;assetImage=nil;
    }
}

static NSUInteger assetStyle;
@class HelperAssetRenderedImage;
static HelperAssetRenderedImage *assetRendered, *assetTemplate;
static UIView *assetContainer;
static IMP assetOldRenderer,assetOldSubview,assetOldRender;

@interface HelperAssetRenderedImage : UIImage @end
@implementation HelperAssetRenderedImage
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode {
    [assetEvents addObject:@"template"];
    PCheck(self==assetRendered && mode==2,@"named renderer converts its result to always-template mode");
    return assetTemplate;
}
@end
static id AssetUIImageNamed(id receiver,SEL selector,NSString *name,NSBundle *bundle,id traits) {
    (void)receiver;(void)selector;[assetEvents addObject:@"load"];
    PCheck(name==assetName && bundle==assetBundle && traits==nil,@"named renderer forwards name, default bundle and nil traits");
    return assetImage;
}
static void AssetSubview(id receiver,SEL selector,UIImageView *view) {
    [assetEvents addObject:@"subview"];assetContainer=receiver;
    double size=assetStyle==2 ? 24 : 19.5;
    PCheck(CGRectEqualToRect([receiver frame],CGRectMake(0,0,size,size)),@"renderer constructs the original square container");
    PCheck(view.image==assetImage && view.contentMode==1 && view.clipsToBounds,@"image identity, aspect fit and clipping reach the image view");
    PCheck(CGRectEqualToRect(view.frame,[receiver bounds]),@"image view frame comes from container bounds before insertion");
    if(assetStyle==0)
        PCheck(view.tintColor && CGColorGetAlpha(view.tintColor.CGColor)==0.699999988079071,@"only instance resizing applies the original exact tint alpha");
    else PCheck(view.tintColor==nil,@"class resizing and named rendering leave tint unset");
    ((void(*)(id,SEL,id))assetOldSubview)(receiver,selector,view);
}
static void AssetRender(id receiver,SEL selector,CGContextRef context) {
    [assetEvents addObject:@"render"];
    PCheck([receiver fixtureOwner]==assetContainer && context!=NULL,@"renderer draws the populated container layer in the supplied context");
    ((void(*)(id,SEL,CGContextRef))assetOldRender)(receiver,selector,context);
}
static id AssetRenderer(id receiver,SEL selector,void (^actions)(UIGraphicsImageRendererContext *)) {
    [assetEvents addObject:@"actions"];
    CGSize size=[receiver fixtureSize];double expected=assetStyle==2 ? 24 : 19.5;
    PCheck(size.width==expected && size.height==expected,@"renderer receives original square dimensions");
    // Execute the actual source callback through a bounded synthetic renderer.
    ((id(*)(id,SEL,id))assetOldRenderer)(receiver,selector,actions);
    [assetEvents addObject:@"result"];return assetRendered;
}

static void TestAssetRendering(void) {
    YTLHelper *helper=[YTLHelper new];PSettle();
    NSBundle *bundleToken=NSBundle.mainBundle;
    NSString *nameToken=[NSMutableString stringWithString:@"fixture-render"];
    UIImage *imageToken=[UIImage new];
    HelperAssetRenderedImage *renderToken=[HelperAssetRenderedImage new], *templateToken=[HelperAssetRenderedImage new];
    Method renderer=class_getInstanceMethod(UIGraphicsImageRenderer.class,@selector(imageWithActions:));
    Method subview=class_getInstanceMethod(UIView.class,@selector(addSubview:));
    Method render=class_getInstanceMethod(CALayer.class,@selector(renderInContext:));
    Method named=class_getClassMethod(UIImage.class,@selector(imageNamed:inBundle:compatibleWithTraitCollection:));
    Method bundle=class_getClassMethod(NSBundle.class,NSSelectorFromString(@"ytl_defaultBundle"));
    assetOldRenderer=method_setImplementation(renderer,(IMP)AssetRenderer);
    assetOldSubview=method_setImplementation(subview,(IMP)AssetSubview);
    assetOldRender=method_setImplementation(render,(IMP)AssetRender);
    IMP oldNamed=method_setImplementation(named,(IMP)AssetUIImageNamed);
    IMP oldBundle=method_setImplementation(bundle,(IMP)AssetBundle);
    @try {
        for(assetStyle=0;assetStyle<3;assetStyle++)for(NSUInteger mode=0;mode<5;mode++) {
            assetImage=mode==1 ? nil : imageToken;
            assetRendered=mode==2 ? nil : renderToken;
            assetTemplate=mode==3 ? nil : templateToken;
            assetName=mode==4 ? nil : nameToken;
            assetBundle=bundleToken;assetMainBundle=NO;assetContainer=nil;[assetEvents removeAllObjects];
            UIImage *result=assetStyle==0 ? [helper resizeImage:assetImage toSize:19.5] : assetStyle==1 ?
                [YTLHelper resizeImage:assetImage toSize:19.5] : [helper imageNamed:assetName];
            NSMutableArray *order=[NSMutableArray arrayWithObject:@"actions"];
            if(assetStyle==2)[order addObjectsFromArray:@[@"bundle",@"load"]];
            [order addObjectsFromArray:@[@"subview",@"render",@"result"]];
            if(assetStyle==2 && assetRendered)[order addObject:@"template"];
            PEqual(assetEvents,order,@"source renders before returning or applying template mode, including nil input and result");
            PCheck(result==(assetStyle==2 ? (assetRendered ? assetTemplate : nil) : assetRendered),
                @"source preserves renderer or template result identity without a fallback");
        }
    } @finally {
        method_setImplementation(renderer,assetOldRenderer);method_setImplementation(subview,assetOldSubview);
        method_setImplementation(render,assetOldRender);method_setImplementation(named,oldNamed);method_setImplementation(bundle,oldBundle);
        assetImage=nil;assetRendered=nil;assetTemplate=nil;assetContainer=nil;assetName=nil;assetBundle=nil;
    }
}

void PRunHelperAssets(void) {
    NSUInteger before=PresentationAssertions;assetEvents=[NSMutableArray new];
    TestAssetLoaders();TestAssetRendering();assetEvents=nil;
    printf("PASS Helper_first_package_assets: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
