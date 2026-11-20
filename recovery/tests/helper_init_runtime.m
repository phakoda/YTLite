#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <objc/runtime.h>

static NSMutableArray *initEvents;
static BOOL nilToast;
static NSUInteger newCalls;
static ToastView *constructedToast;
static NSCharacterSet *factoryCharacters;
static YTLHelper *initializingHelper;

@interface ToastView (HelperInitProbe)
- (instancetype)initForHelperProbe;
+ (instancetype)newForHelperProbe;
@end
@implementation ToastView (HelperInitProbe)
- (instancetype)initForHelperProbe {
    [initEvents addObject:@"toast"];
    if (nilToast) return nil;
    constructedToast=self;
    return self;
}
+ (instancetype)newForHelperProbe {
    newCalls++;
    return [[self alloc] init];
}
@end

static id HelperCharacterFactory(id receiver,SEL selector,NSString *characters) {
    (void)receiver;(void)selector;
    [initEvents addObject:@"characters"];
    PEqual(characters,@"/\\?*|\"<>",@"initializer passes original illegal-character string");
    PCheck(object_getIvar(initializingHelper,class_getInstanceVariable(YTLHelper.class,"_toastView"))==constructedToast,
        @"toast result stored before character-set factory runs");
    return factoryCharacters;
}

void PRunHelperInit(void) {
    NSUInteger before=PresentationAssertions;
    initEvents=[NSMutableArray new];
    NSCharacterSet *sentinel=[NSCharacterSet characterSetWithCharactersInString:@"fixture"];
    Method toastInit=class_getInstanceMethod(ToastView.class,@selector(init));
    Method probeInit=class_getInstanceMethod(ToastView.class,@selector(initForHelperProbe));
    Method inheritedNew=class_getClassMethod(ToastView.class,@selector(new));
    IMP oldNew=method_getImplementation(inheritedNew);
    class_addMethod(object_getClass(ToastView.class),@selector(new),oldNew,method_getTypeEncoding(inheritedNew));
    Method toastNew=class_getClassMethod(ToastView.class,@selector(new));
    Method probeNew=class_getClassMethod(ToastView.class,@selector(newForHelperProbe));
    Method characters=class_getClassMethod(NSCharacterSet.class,@selector(characterSetWithCharactersInString:));
    IMP oldInit=method_setImplementation(toastInit,method_getImplementation(probeInit));
    method_setImplementation(toastNew,method_getImplementation(probeNew));
    IMP oldCharacters=method_setImplementation(characters,(IMP)HelperCharacterFactory);
    @try {
        for(NSUInteger mode=0;mode<4;mode++) {
            nilToast=(mode&1)!=0;factoryCharacters=(mode&2) ? nil : sentinel;
            constructedToast=nil;newCalls=0;[initEvents removeAllObjects];
            initializingHelper=[YTLHelper alloc];
            YTLHelper *result=[initializingHelper init];
            PEqual(initEvents,(@[@"toast",@"characters"]),@"initializer creates toast before character set, even with nil results");
            PCheck(newCalls==0,@"toast construction uses alloc/init without class new dispatch");
            PCheck(result==initializingHelper,@"initializer returns initialized helper");
            PCheck(object_getIvar(result,class_getInstanceVariable(YTLHelper.class,"_toastView"))==constructedToast,
                @"initializer preserves toast result identity");
            PCheck(object_getIvar(result,class_getInstanceVariable(YTLHelper.class,"_illegalChars"))==factoryCharacters,
                @"initializer preserves character-set result identity");
        }
    } @finally {
        method_setImplementation(toastInit,oldInit);method_setImplementation(toastNew,oldNew);
        method_setImplementation(characters,oldCharacters);
        initializingHelper=nil;constructedToast=nil;factoryCharacters=nil;initEvents=nil;
    }
    printf("PASS Helper_first_package_init: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
