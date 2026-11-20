#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Helpers/HelpersHost.h"
#import <objc/runtime.h>

static NSMutableArray<NSString *> *buttonEvents;
static UIButton *redirectResult;
static Class redirectClass;
static NSUInteger redirectCalls,overlayDelegations,feedbackReads,imageCalls,titleCalls;
static id seenTarget,seenIcon;
static SEL seenSelector;
static CGSize seenSize;
static NSString *seenAccessibility,*seenLabel;
@class HelperTemplateProbe;
static HelperTemplateProbe *convertedImage;
static YTQTMButtonTouchFeedbackView *feedbacks[3];

@interface HelperFactoryDestination : NSObject @end
@implementation HelperFactoryDestination
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibility buttonLabel:(NSString *)label icon:(UIImage *)icon size:(CGSize)size selector:(SEL)selector {
    redirectCalls++;seenTarget=target;seenAccessibility=accessibility;seenLabel=label;
    seenIcon=icon;seenSize=size;seenSelector=selector;return redirectResult;
}
@end
@interface HelperFactoryRedirect : YTLHelper @end
@implementation HelperFactoryRedirect
+ (Class)class { return redirectClass; }
@end
@interface HelperOverlayDispatchProbe : YTLHelper @end
@implementation HelperOverlayDispatchProbe
+ (UIButton *)createYTQTMButton:(id)target accessibilityLabel:(NSString *)accessibility buttonLabel:(NSString *)label icon:(UIImage *)icon size:(CGSize)size selector:(SEL)selector {
    (void)target;(void)accessibility;(void)label;(void)icon;(void)size;(void)selector;
    overlayDelegations++;return redirectResult;
}
@end
@interface HelperTemplateProbe : UIImage @end
@implementation HelperTemplateProbe
- (UIImage *)imageWithRenderingMode:(UIImageRenderingMode)mode {
    PCheck(mode==UIImageRenderingModeAlwaysTemplate,@"overlay requests template conversion");
    [buttonEvents addObject:@"template"];return convertedImage;
}
@end
@interface HelperButtonProbe : YTQTMButton @end
@implementation HelperButtonProbe
- (void)setAccessibilityLabel:(NSString *)label {
    [buttonEvents addObject:@"accessibility"];[super setAccessibilityLabel:label];
}
- (void)enableNewTouchFeedback { [buttonEvents addObject:@"enable"]; }
- (void)setImage:(UIImage *)image forState:(UIControlState)state {
    imageCalls++;[buttonEvents addObject:@"image"];seenIcon=image;
    PCheck(state==UIControlStateNormal,@"overlay image uses normal state");[super setImage:image forState:state];
}
- (void)setTitle:(NSString *)title forState:(UIControlState)state {
    titleCalls++;[buttonEvents addObject:@"title"];[super setTitle:title forState:state];
}
- (YTQTMButtonTouchFeedbackView *)touchFeedbackView {
    PCheck(feedbackReads<3,@"overlay performs no extra feedback lookup");
    [buttonEvents addObject:[NSString stringWithFormat:@"feedback:%lu",(unsigned long)feedbackReads]];
    return feedbacks[feedbackReads++];
}
@end
static HelperButtonProbe *factoryButton;
static id ButtonFactory(id receiver,SEL selector) {
    (void)receiver;(void)selector;[buttonEvents addObject:@"factory"];return factoryButton;
}
static IMP originalWhiteColor;
static id ButtonWhiteColor(id receiver,SEL selector) {
    [buttonEvents addObject:@"white"];return ((id(*)(id,SEL))originalWhiteColor)(receiver,selector);
}

void PRunHelperButtons(void) {
    NSUInteger before=PresentationAssertions;
    buttonEvents=[NSMutableArray new];
    id target=[NSObject new];UIImage *icon=[UIImage systemImageNamed:@"factory.input"];
    NSString *accessibility=[@"Accessible" mutableCopy],*label=[@"Button" mutableCopy];
    SEL action=NSSelectorFromString(@"fixtureAction:");redirectResult=[UIButton buttonWithType:UIButtonTypeCustom];
    redirectClass=objc_getClass("HelperFactoryDestination");redirectCalls=0;
    UIButton *result=[HelperFactoryRedirect createYTQTMButton:target accessibilityLabel:accessibility buttonLabel:label icon:icon selector:action];
    PCheck(result==redirectResult && redirectCalls==1,@"default-size wrapper dispatches through class result");
    PCheck(seenTarget==target && seenAccessibility==accessibility && seenLabel==label && seenIcon==icon && seenSelector==action,@"default-size forwarding preserves object and selector identity");
    PCheck(seenSize.width==40 && seenSize.height==40,@"default-size forwarding dimensions");
    redirectClass=Nil;redirectCalls=0;
    PCheck([HelperFactoryRedirect createYTQTMButton:target accessibilityLabel:accessibility buttonLabel:label icon:icon selector:action]==nil && redirectCalls==0,@"nil class result receives the factory message");
    Method factory=class_getClassMethod(YTQTMButton.class,@selector(iconButton));
    Method white=class_getClassMethod(UIColor.class,@selector(whiteColor));
    IMP originalFactory=method_setImplementation(factory,(IMP)ButtonFactory);
    originalWhiteColor=method_setImplementation(white,(IMP)ButtonWhiteColor);
    @try {
        for(NSUInteger mode=0;mode<3;mode++) {
            factoryButton=[HelperButtonProbe buttonWithType:UIButtonTypeCustom];
            for(NSUInteger i=0;i<3;i++)feedbacks[i]=[YTQTMButtonTouchFeedbackView new];
            feedbackReads=imageCalls=titleCalls=overlayDelegations=0;[buttonEvents removeAllObjects];
            UIImage *input=mode==0 ? nil : [HelperTemplateProbe new];
            convertedImage=mode==2 ? [HelperTemplateProbe new] : nil;
            result=[HelperOverlayDispatchProbe createOverlayButton:target accessibilityLabel:accessibility buttonLabel:label icon:input selector:action];
            PCheck(result==factoryButton && overlayDelegations==0,@"overlay constructs its host button without delegating to the size factory");
            NSArray *prefix=input ? @[@"factory",@"accessibility",@"enable",@"template",@"image"] : @[@"factory",@"accessibility",@"enable",@"title"];
            PEqual([buttonEvents subarrayWithRange:NSMakeRange(0,prefix.count)],prefix,@"overlay creation precedes conditional image conversion");
            PCheck(imageCalls==(input ? 1u:0u) && titleCalls==(input ? 0u:1u),@"overlay branches on original icon, including nil conversion result");
            if(input)PCheck(seenIcon==convertedImage,@"converted image forwarded unchanged, including nil");
            PCheck(feedbackReads==3,@"overlay reads each feedback receiver separately");
            PCheck(feedbacks[0].forceCircularTouchFeedback && !feedbacks[1].forceCircularTouchFeedback && !feedbacks[2].forceCircularTouchFeedback,@"circular flag goes only to first feedback object");
            UIEdgeInsets insets=feedbacks[1].touchFeedbackInsets;
            PCheck(insets.top==0 && insets.left==-6 && insets.bottom==0 && insets.right==-6,@"insets go to second feedback object");
            PCheck(feedbacks[0].customTouchFeedbackColor==nil && feedbacks[1].customTouchFeedbackColor==nil && feedbacks[2].customTouchFeedbackColor!=nil,@"color goes only to third feedback object");
            PEqual([buttonEvents subarrayWithRange:NSMakeRange(buttonEvents.count-4,4)],@[@"feedback:0",@"feedback:1",@"white",@"feedback:2"],@"white color is read before final feedback getter");
        }
    } @finally {
        method_setImplementation(factory,originalFactory);method_setImplementation(white,originalWhiteColor);
    }
    factoryButton=nil;redirectResult=nil;convertedImage=nil;
    for(NSUInteger i=0;i<3;i++)feedbacks[i]=nil;
    printf("PASS Helper_first_package_buttons: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
