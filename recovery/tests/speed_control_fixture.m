#import <UIKit/UIKit.h>
#import <objc/message.h>
#import "../source/Controls/YTPSpeedControlView.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Downloads/YTPMedia.h"
#include <math.h>
#include <stdint.h>
#include <string.h>
static NSUInteger checks,rateCalls,currentCalls,backgroundCalls,rendererCalls;
static double receivedRate;
static __weak id receivedPlayer;
static NSMutableArray *rateSequence,*events,*constraints;
static BOOL failViewInit;
static CGContextRef currentContext;
static __weak UIView *locationReceiver;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static uint32_t bits(float x){uint32_t r;memcpy(&r,&x,4);return r;}
static BOOL same(float a,float b){return isnan(a)&&isnan(b) ? YES : bits(a)==bits(b);}
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray *)values {for(NSLayoutConstraint *c in values)c.active=YES;}
- (void)setActive:(BOOL)value {_active=value;if(value && ![constraints containsObject:self])[constraints addObject:self];}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)other constant:(CGFloat)value {NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=other;c.constant=value;return c;}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value{return [self constraintEqualToAnchor:nil constant:value];}
@end
@implementation UIColor
+ (instancetype)color:(NSString *)name white:(CGFloat)white alpha:(CGFloat)alpha {UIColor *c=[self new];c.name=name;c.alpha=alpha;CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();CGFloat components[]={white,white,white,alpha};c->_CGColor=CGColorCreate(space,components);CGColorSpaceRelease(space);return c;}
+ (instancetype)labelColor {static UIColor *c;if(!c)c=[self color:@"label" white:0.2 alpha:1];return c;}
+ (instancetype)blackColor {static UIColor *c;if(!c)c=[self color:@"black" white:0 alpha:1];return c;}
+ (instancetype)whiteColor {static UIColor *c;if(!c)c=[self color:@"white" white:1 alpha:1];return c;}
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha {return [UIColor color:self.name white:CGColorGetComponents(_CGColor)[0] alpha:alpha];}
- (CGColorRef)CGColor{return _CGColor;}
- (void)setFill {CGContextSetFillColorWithColor(currentContext,_CGColor);}
- (void)dealloc {CGColorRelease(_CGColor);}
@end
@implementation UIFont
+ (instancetype)boldSystemFontOfSize:(CGFloat)size {UIFont *f=[self new];f.pointSize=size;f.bold=YES;return f;}
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(CGFloat)weight {UIFont *f=[self new];f.pointSize=size;f.weight=weight;return f;}
@end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name {UIImage *i=[self new];i.name=name;return i;}
- (instancetype)initWithCGImage:(CGImageRef)image {if((self=[super init]))_image=CGImageRetain(image);return self;}
- (CGImageRef)CGImage{return _image;}
- (void)dealloc{if(_image)CGImageRelease(_image);}
@end
@implementation UIView
- (instancetype)init {return [self initWithFrame:CGRectZero];}
- (instancetype)initWithFrame:(CGRect)frame {if(failViewInit){failViewInit=NO;return nil;}if((self=[super init])){_frame=frame;_bounds=(CGRect){CGPointZero,frame.size};_subviews=[NSMutableArray new];_gestureRecognizers=[NSMutableArray new];_layer=[CALayer new];_translatesAutoresizingMaskIntoConstraints=YES;}return self;}
- (void)addSubview:(UIView *)view {[view.superview.subviews removeObjectIdenticalTo:view];view.superview=self;[_subviews addObject:view];}
- (void)addGestureRecognizer:(UIGestureRecognizer *)g {g.view=self;[_gestureRecognizers addObject:g];}
- (NSLayoutAnchor *)anchor:(NSString *)name {NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=self;a.name=name;return a;}
- (NSLayoutAnchor *)topAnchor{return [self anchor:@"top"];}
- (NSLayoutAnchor *)bottomAnchor{return [self anchor:@"bottom"];}
- (NSLayoutAnchor *)leadingAnchor{return [self anchor:@"leading"];}
- (NSLayoutAnchor *)trailingAnchor{return [self anchor:@"trailing"];}
- (NSLayoutAnchor *)widthAnchor{return [self anchor:@"width"];}
- (NSLayoutAnchor *)heightAnchor{return [self anchor:@"height"];}
@end
@implementation UILabel
- (void)setText:(NSString *)text{_text=[text copy];[events addObject:@"label"];}
@end
@implementation SpeedControlAction @end
@implementation UIControl
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)event {if(!_actions)_actions=[NSMutableArray new];SpeedControlAction *a=[SpeedControlAction new];a.target=target;a.selector=action;a.events=event;[_actions addObject:a];}
- (void)fire:(UIControlEvents)event {for(SpeedControlAction *a in _actions)if(a.events==event){if([NSStringFromSelector(a.selector) containsString:@":"])((void(*)(id,SEL,id))objc_msgSend)(a.target,a.selector,self);else ((void(*)(id,SEL))objc_msgSend)(a.target,a.selector);}}
@end
@implementation UIButton
+ (instancetype)buttonWithType:(UIButtonType)type{UIButton *b=[self new];b.buttonType=type;b.titleLabel=[UILabel new];return b;}
- (void)setImage:(UIImage *)image forState:(UIControlState)state{CHECK(state==0);self.image=image;}
- (void)setTitle:(NSString *)title forState:(UIControlState)state{CHECK(state==0);self.title=title;}
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state{CHECK(state==0);self.titleColor=color;}
@end
@implementation UISlider
- (float)minimumValue {if(_minimumSequence.count){float v=[_minimumSequence[0] floatValue];[_minimumSequence removeObjectAtIndex:0];return v;}return _minimumValue;}
- (void)setValue:(float)value {_value=value;if(!_writes)_writes=[NSMutableArray new];[_writes addObject:@(value)];[events addObject:@"slider"];}
- (void)setThumbImage:(UIImage *)image forState:(UIControlState)state{CHECK(state==0);self.thumb=image;}
@end
@implementation UIGestureRecognizer
- (instancetype)initWithTarget:(id)target action:(SEL)action {if((self=[super init])){_target=target;_action=action;}return self;}
- (CGPoint)locationInView:(UIView *)view {locationReceiver=view;return _location;}
@end
@implementation UITapGestureRecognizer @end
@implementation UILongPressGestureRecognizer @end
@implementation UIStackView
- (instancetype)initWithArrangedSubviews:(NSArray *)views {if((self=[super init])){_arrangedSubviews=[views copy];for(UIView *v in views)[self addSubview:v];}return self;}
@end
@implementation UIGraphicsImageRendererContext @end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size {if((self=[super init]))_size=size;return self;}
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions {rendererCalls++;CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();CGContextRef context=CGBitmapContextCreate(NULL,(size_t)_size.width,(size_t)_size.height,8,0,space,(CGBitmapInfo)kCGImageAlphaPremultipliedLast);CGColorSpaceRelease(space);CHECK(context!=NULL);UIGraphicsImageRendererContext *wrapper=[UIGraphicsImageRendererContext new];wrapper.CGContext=context;currentContext=context;actions(wrapper);currentContext=NULL;CGImageRef image=CGBitmapContextCreateImage(context);UIImage *result=[[UIImage alloc]initWithCGImage:image];CGImageRelease(image);CGContextRelease(context);return result;}
@end
@implementation YTPSpeedMaster
+ (double)currentPlaybackRate {currentCalls++;if(rateSequence.count){double v=[rateSequence[0] doubleValue];[rateSequence removeObjectAtIndex:0];return v;}return 1;}
+ (void)setPlaybackRate:(double)rate forPlayer:(id)player {rateCalls++;receivedRate=rate;receivedPlayer=player;[events addObject:@"rate"];}
@end
@implementation YTPMedia
+ (UIColor *)adaptiveBackgroundColor{backgroundCalls++;return UIColor.blackColor;}
@end
@interface SpeedControlSubclass : YTPSpeedControlView @end
@implementation SpeedControlSubclass @end

// Independent arithmetic oracles execute isolated, newly compiled ARM64
// operations from the audited sequences. They never load the supplied dylib.
static float Quantized(float value,float step) {float out;__asm__("fdiv %s0, %s1, %s2\nfrinta %s0, %s0\nfmul %s0, %s2, %s0":"=&w"(out):"w"(value),"w"(step));return out;}
static float Tapped(float min,float max,float secondMin,double x,double width,float step) {float result,ratio=(float)(x/width);__asm__("fsub %s0, %s2, %s3\nfmadd %s0, %s4, %s0, %s1":"=&w"(result):"w"(min),"w"(max),"w"(secondMin),"w"(ratio));return Quantized(result,step);}
static float Minus(float value,float minimum,float step) {float out;__asm__("fsub %s0, %s1, %s3\nfcmp %s2, %s0\nfcsel %s0, %s0, %s2, mi":"=&w"(out):"w"(value),"w"(minimum),"w"(step):"cc");return Quantized(out,step);}
static float Plus(float value,float maximum,float step) {float out;__asm__("fadd %s0, %s1, %s3\nfcmp %s2, %s0\nfcsel %s0, %s2, %s0, mi":"=&w"(out):"w"(value),"w"(maximum),"w"(step):"cc");return Quantized(out,step);}
static int64_t Tag(float value) {float product;int64_t result;float hundred=100;__asm__("fmul %s0, %s2, %s3\nfcvtzs %1, %s0":"=&w"(product),"=r"(result):"w"(value),"w"(hundred));return result;}
static void reset(UISlider *slider) {[slider.writes removeAllObjects];[events removeAllObjects];rateCalls=0;receivedPlayer=nil;receivedRate=42;}
static void checkUpdate(YTPSpeedControlView *view,UISlider *slider,float expected) {CHECK(slider.writes.count==1);CHECK(same([slider.writes[0] floatValue],expected));CHECK(rateCalls==1 && receivedPlayer==nil);CHECK(isnan(expected)?isnan(receivedRate):receivedRate==(double)expected);UILabel *label=[view valueForKey:@"_valueLabel"];CHECK([label.text isEqual:[NSString stringWithFormat:@"%.2fx",(double)expected]]);CHECK([events isEqual:@[@"slider",@"label",@"rate"]]);}
int main(void) {@autoreleasepool {
    events=[NSMutableArray new];constraints=[NSMutableArray new];rateSequence=[@[@1.23456,@2.34567] mutableCopy];
    YTPSpeedControlView *view=[[YTPSpeedControlView alloc]initWithFrame:CGRectMake(4,5,320,180)];
    UISlider *slider=[view valueForKey:@"_slider"];UILabel *label=[view valueForKey:@"_valueLabel"];
    CHECK(CGRectEqualToRect(view.frame,CGRectMake(4,5,320,180)));CHECK([[view valueForKey:@"_step"]floatValue]==0.05f);
    CHECK([[view valueForKey:@"_presets"]isEqual:@[@1,@2,@3,@5,@10]]);CHECK(!view.translatesAutoresizingMaskIntoConstraints&&view.layer.cornerRadius==16);CHECK(view.backgroundColor==UIColor.blackColor&&backgroundCalls==1);
    CHECK(currentCalls==2&&[label.text isEqual:@"1.23x"]&&same(slider.value,(float)2.34567));CHECK(!rateCalls);
    CHECK(label.textColor==UIColor.labelColor&&label.font.pointSize==18&&label.font.bold&&label.textAlignment==1);
    CHECK(slider.minimumValue==0.25f&&slider.maximumValue==10&&slider.minimumTrackTintColor==UIColor.labelColor&&slider.maximumTrackTintColor.alpha==0.15);
    CHECK(rendererCalls==1&&CGImageGetWidth(slider.thumb.CGImage)==12&&CGImageGetHeight(slider.thumb.CGImage)==15);
    CFDataRef pixels=CGDataProviderCopyData(CGImageGetDataProvider(slider.thumb.CGImage));const UInt8 *bytes=CFDataGetBytePtr(pixels);size_t row=CGImageGetBytesPerRow(slider.thumb.CGImage);CHECK(bytes[7*row+6*4+3]==255&&bytes[7*row+6*4]==255);CHECK(bytes[3]<255);CFRelease(pixels);
    CHECK(view.subviews.count==1);UIStackView *stack=view.subviews[0];CHECK(stack.axis==1&&stack.spacing==12&&stack.alignment==0&&!stack.translatesAutoresizingMaskIntoConstraints);
    CHECK(stack.arrangedSubviews.count==3&&stack.arrangedSubviews[0]==label);UIStackView *controls=stack.arrangedSubviews[1],*presets=stack.arrangedSubviews[2];CHECK(controls.axis==0&&controls.spacing==12&&controls.alignment==3&&controls.arrangedSubviews[1]==slider);CHECK(presets.axis==0&&presets.spacing==8&&presets.distribution==1&&presets.arrangedSubviews.count==5);
    UIButton *minus=controls.arrangedSubviews[0],*plus=controls.arrangedSubviews[2];CHECK([minus.image.name isEqual:@"minus"]&&[plus.image.name isEqual:@"plus"]);CHECK(minus.layer.cornerRadius==20&&plus.layer.cornerRadius==20&&minus.backgroundColor.alpha==0.15);CHECK(!minus.translatesAutoresizingMaskIntoConstraints&&!plus.translatesAutoresizingMaskIntoConstraints);CHECK(minus.superview==controls&&plus.superview==controls);
    CHECK(minus.actions.count==1&&minus.actions[0].target==view&&minus.actions[0].selector==@selector(minusTapped)&&minus.actions[0].events==0x40);CHECK(plus.actions[0].selector==@selector(plusTapped));CHECK(slider.actions[0].selector==@selector(sliderChanged:)&&slider.actions[0].events==0x1000);
    CHECK(constraints.count==14);NSArray *edges=@[@"top",@"leading",@"trailing",@"bottom"];NSArray *offsets=@[@24,@16,@(-16),@(-16)];for(NSUInteger i=0;i<4;i++){NSLayoutConstraint *c=constraints[9+i];CHECK(c.firstAnchor.owner==stack&&[c.firstAnchor.name isEqual:edges[i]]&&c.secondAnchor.owner==view&&c.constant==[offsets[i]doubleValue]&&c.active);}CHECK(((NSLayoutConstraint *)constraints[13]).firstAnchor.owner==presets&&((NSLayoutConstraint *)constraints[13]).constant==32);
    for(UIButton *button in presets.arrangedSubviews){CHECK(button.actions[0].target==view&&button.actions[0].selector==@selector(presetTapped:));CHECK(button.layer.cornerRadius==16&&button.titleLabel.font.pointSize==12&&button.titleLabel.font.weight==UIFontWeightMedium&&button.titleColor==UIColor.labelColor);reset(slider);[button fire:0x40];checkUpdate(view,slider,(float)((double)button.tag/100));}
    UITapGestureRecognizer *tap=slider.gestureRecognizers.firstObject;CHECK(tap.target==view&&tap.action==@selector(sliderTapped:)&&tap.view==slider);
    // These values distinguish nearest-away rounding, truncation, signed zeros,
    // infinities, NaNs and the two distinct FCSEL operand orders.
    const float values[]={0.276f,0.024f,0.025f,0.075f,-0.025f,-0.075f,0,-0.0f,1,1.234f,9.98f,10,11,-1,INFINITY,-INFINITY,NAN};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(values[0]);i++){float value=values[i];slider.value=value;reset(slider);[slider fire:0x1000];checkUpdate(view,slider,Quantized(value,0.05f));slider.value=value;reset(slider);[minus fire:0x40];checkUpdate(view,slider,Minus(value,0.25f,0.05f));slider.value=value;reset(slider);[plus fire:0x40];checkUpdate(view,slider,Plus(value,10,0.05f));}
    const double positions[]={-30,0,1,50,100,110,INFINITY,-INFINITY,NAN};const double widths[]={100,0,-100};
    for(NSUInteger w=0;w<3;w++)for(NSUInteger i=0;i<9;i++){slider.bounds=CGRectMake(9,8,widths[w],20);tap.location=CGPointMake(positions[i],77);reset(slider);[view sliderTapped:tap];checkUpdate(view,slider,Tapped(0.25f,10,0.25f,positions[i],widths[w],0.05f));CHECK(locationReceiver==slider);}
    slider.minimumSequence=[@[@0.5,@0.75]mutableCopy];slider.bounds=CGRectMake(0,0,37,12);tap.location=CGPointMake(19,0);reset(slider);[view sliderTapped:tap];checkUpdate(view,slider,Tapped(0.5f,10,0.75f,19,37,0.05f));CHECK(slider.minimumSequence.count==0);
    // Many finite tags expose the original single-precision multiplication.
    for(NSUInteger i=0;i<300;i++){float value=(float)i/37.0f;UIButton *b=[view makePresetButton:@(value)];CHECK(b.tag==Tag(value));CHECK([b.title isEqual:[NSString stringWithFormat:@"%.1f",(double)value]]);}
    for(NSNumber *number in @[@(NAN),@(INFINITY),@(-INFINITY),@(0x1p60f),@(-0x1p60f)]){UIButton *b=[view makePresetButton:number];CHECK(b.tag==Tag(number.floatValue));}
    for(NSNumber *tag in @[@(NSIntegerMin),@(-1),@0,@101,@(NSIntegerMax)]){UIButton *b=[UIButton new];b.tag=tag.integerValue;reset(slider);[view presetTapped:b];checkUpdate(view,slider,(float)((double)b.tag/100));}
    reset(slider);[view sliderChanged:nil];CHECK(slider.writes.count==0&&rateCalls==1&&receivedRate==0&&[events isEqual:@[@"label",@"rate"]]);
    CHECK([[SpeedControlSubclass speedControls]isMemberOfClass:YTPSpeedControlView.class]);failViewInit=YES;NSUInteger before=currentCalls;CHECK([[YTPSpeedControlView alloc]initWithFrame:CGRectZero]==nil&&currentCalls==before);
    __weak id weakSlider,weakLabel,weakView;@autoreleasepool{YTPSpeedControlView *temporary=[YTPSpeedControlView speedControls];weakView=temporary;weakSlider=[temporary valueForKey:@"_slider"];weakLabel=[temporary valueForKey:@"_valueLabel"];}CHECK(!weakView&&!weakSlider&&!weakLabel);
    printf("Speed control: %lu actual-source assertions passed, including ARM64 arithmetic oracles and real CoreGraphics drawing\n",(unsigned long)checks);
}return 0;}
