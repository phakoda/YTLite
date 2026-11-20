// Host-only state recorders. No original dylib, UI server, Photos library,
// network session, FFmpeg process, standard preferences, or real media access.
#import "presentation_doubles.h"
#import <objc/message.h>
#import <objc/runtime.h>
#import <SystemConfiguration/SystemConfiguration.h>

NSMutableArray<NSDictionary *> *PresentationEvents;
NSMutableArray<dispatch_block_t> *PresentationMainQueue;
NSMutableArray<void (^)(BOOL)> *PresentationAnimations;
NSMutableArray<NSDictionary *> *PresentationPhotoChanges;
NSMutableArray<NSDictionary *> *PresentationDownloads;
NSMutableArray<NSDictionary *> *PresentationConversions;
PresentationFixtureURLSessionDataTask *PresentationLastNetworkTask;
NSInteger PresentationPostDownloadIndex;
BOOL PresentationNativeDetents = YES;
BOOL PresentationSheetNativeAvailable(void) { return PresentationNativeDetents; }
BOOL PresentationReachabilitySucceeded = YES;
BOOL PresentationReachabilityCreated = YES;
uint32_t PresentationReachabilityFlags = 2;
NSString *PresentationFixtureRoot;
static NSMutableArray<NSDictionary *> *delayed;
static NSMutableArray<NSMutableDictionary *> *transactions;
static double fixtureClock;
static CGContextRef currentContext;
static CGSize currentContextSize;
static NSMutableDictionary *currentDrawing;

void PresentationInitialize(void) {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        PresentationEvents=[NSMutableArray new]; PresentationMainQueue=[NSMutableArray new];
        PresentationAnimations=[NSMutableArray new]; PresentationPhotoChanges=[NSMutableArray new];
        PresentationDownloads=[NSMutableArray new]; PresentationConversions=[NSMutableArray new];
        delayed=[NSMutableArray new]; transactions=[NSMutableArray new];
        PresentationFixtureRoot = [[[NSProcessInfo.processInfo.environment objectForKey:@"TMPDIR"]
            stringByStandardizingPath] copy];
        NSCAssert([PresentationFixtureRoot containsString:@"/.recovery-work/presentation-helpers/"], @"isolated fixture TMPDIR");
    });
}
NSString *PresentationFixtureTemporaryDirectory(void) {
    PresentationInitialize();return [PresentationFixtureRoot stringByAppendingString:@"/"];
}
void PresentationFixtureLog(NSString *format, ...) {
    va_list arguments;va_start(arguments,format);
    NSString *message=[[NSString alloc]initWithFormat:format arguments:arguments];va_end(arguments);
    PresentationRecord(@"diagnostic.log",message);
}
@implementation PresentationFixtureBundle
+ (instancetype)mainBundle { static PresentationFixtureBundle *bundle;if(!bundle)bundle=[self new];return bundle; }
- (NSString *)bundlePath { return [PresentationFixtureTemporaryDirectory() stringByAppendingPathComponent:@"Synthetic.bundle"]; }
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table {
    (void)table;return value.length?value:key;
}
@end
void PresentationRecord(NSString *kind,id value) {
    PresentationInitialize();
    [PresentationEvents addObject:@{@"kind":kind,@"value":value ?: NSNull.null}];
}
NSArray<NSDictionary *> *PresentationEventsOfKind(NSString *kind) {
    NSMutableArray *result=[NSMutableArray new];
    for (NSDictionary *event in PresentationEvents) if ([event[@"kind"] isEqual:kind]) [result addObject:event];
    return result;
}
void PresentationResetEvents(void) { [PresentationEvents removeAllObjects]; }
void PresentationDispatchAsync(dispatch_queue_t queue,dispatch_block_t block) {
    PresentationInitialize(); NSCAssert(queue==dispatch_get_main_queue(),@"only recovered main queue in fixture");
    [PresentationMainQueue addObject:[block copy]];
}
dispatch_time_t PresentationDispatchTime(dispatch_time_t when,int64_t delta) {
    NSCAssert(when==DISPATCH_TIME_NOW,@"relative fixture time");
    return (dispatch_time_t)((fixtureClock*1e9) + (double)MAX(delta,0));
}
void PresentationDispatchAfter(dispatch_time_t time,dispatch_queue_t queue,dispatch_block_t block) {
    PresentationInitialize(); NSCAssert(queue==dispatch_get_main_queue(),@"fixture delayed main queue");
    [delayed addObject:@{@"time":@((double)time/1e9),@"block":[block copy]}];
}
void PresentationDrainMain(void) {
    NSUInteger iterations=0;
    while (PresentationMainQueue.count) {
        NSCAssert(++iterations<10000,@"main queue bounded");
        dispatch_block_t block=PresentationMainQueue.firstObject;
        [PresentationMainQueue removeObjectAtIndex:0]; block();
    }
}
void PresentationAdvanceTime(double seconds) {
    fixtureClock+=seconds;
    for (NSDictionary *entry in [delayed copy]) if ([entry[@"time"] doubleValue]<=fixtureClock) {
        [PresentationMainQueue addObject:entry[@"block"]]; [delayed removeObjectIdenticalTo:entry];
    }
    PresentationDrainMain();
}
void PresentationCompleteAnimations(BOOL finished) {
    NSUInteger iterations=0;
    while (PresentationAnimations.count) {
        NSCAssert(++iterations<1000,@"animation chain bounded");
        void (^completion)(BOOL)=PresentationAnimations.firstObject;
        [PresentationAnimations removeObjectAtIndex:0]; completion(finished);
        PresentationDrainMain();
    }
}
void PresentationFireTimers(NSUInteger count) {
    for (NSUInteger i=0;i<count;i++) for (PresentationFixtureTimer *timer in [PresentationFixtureRunLoop.mainRunLoop.timers copy]) {
        if (timer.valid && timer.fixtureBlock) timer.fixtureBlock(timer);
        if (!timer.repeats) [timer invalidate];
    }
    PresentationDrainMain();
}
@implementation PresentationFixtureTimer
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats block:(void (^)(PresentationFixtureTimer *))block {
    PresentationFixtureTimer *timer=[self new]; timer.timeInterval=interval; timer.repeats=repeats;
    timer.valid=YES; timer.fixtureBlock=block; return timer;
}
- (void)invalidate { _valid=NO; _fixtureBlock=nil; [PresentationFixtureRunLoop.mainRunLoop.timers removeObjectIdenticalTo:self]; }
@end
@implementation PresentationFixtureRunLoop
+ (instancetype)mainRunLoop { static PresentationFixtureRunLoop *loop; if (!loop) { loop=[self new]; loop.timers=[NSMutableArray new]; } return loop; }
- (void)addTimer:(PresentationFixtureTimer *)timer forMode:(NSRunLoopMode)mode {
    PresentationRecord(@"timer.mode",mode); [_timers addObject:timer];
}
@end
@implementation PresentationFixtureURLSession
+ (instancetype)sharedSession { static PresentationFixtureURLSession *session; if (!session) session=[self new]; return session; }
- (PresentationFixtureURLSessionDataTask *)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData *,NSURLResponse *,NSError *))completion {
    PresentationLastNetworkTask=[PresentationFixtureURLSessionDataTask new];
    PresentationLastNetworkTask.fixtureURL=url; PresentationLastNetworkTask.fixtureCompletion=completion;
    PresentationRecord(@"network.request",url); return PresentationLastNetworkTask;
}
@end
@implementation PresentationFixtureURLSessionDataTask
- (void)resume { _fixtureResumed=YES; PresentationRecord(@"network.resume",_fixtureURL); }
@end

const CATransform3D CATransform3DIdentity={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
CATransform3D CATransform3DMakeScale(CGFloat x,CGFloat y,CGFloat z) { CATransform3D t=CATransform3DIdentity;t.m11=x;t.m22=y;t.m33=z;return t; }
CATransform3D CATransform3DMakeTranslation(CGFloat x,CGFloat y,CGFloat z) { CATransform3D t=CATransform3DIdentity;t.m41=x;t.m42=y;t.m43=z;return t; }
CACornerCurve const kCACornerCurveContinuous=@"continuous";
NSString *const kCAFillModeForwards=@"forwards";
CAMediaTimingFunctionName const kCAMediaTimingFunctionLinear=@"linear",kCAMediaTimingFunctionEaseIn=@"easeIn",kCAMediaTimingFunctionEaseInEaseOut=@"easeInEaseOut";
@implementation CAMediaTimingFunction
+ (instancetype)functionWithName:(CAMediaTimingFunctionName)name { CAMediaTimingFunction *v=[self new];v.name=name;return v; }
@end
@implementation CAAnimation @end
@implementation CABasicAnimation
+ (instancetype)animationWithKeyPath:(NSString *)path { CABasicAnimation *a=[self new];a.keyPath=path;return a; }
@end
@implementation CALayer
+ (instancetype)layer { return [self new]; }
- (instancetype)init { self=[super init];if(self){_opacity=1;_transform=CATransform3DIdentity;_sublayers=[NSMutableArray new];_fixtureAnimations=[NSMutableDictionary new];}return self; }
- (void)setFrame:(CGRect)frame { _frame=frame;_bounds.size=frame.size;_position=CGPointMake(CGRectGetMidX(frame),CGRectGetMidY(frame)); }
- (void)addSublayer:(CALayer *)layer { [layer.superlayer.sublayers removeObjectIdenticalTo:layer];[_sublayers addObject:layer];layer.superlayer=self; }
- (void)addAnimation:(CAAnimation *)animation forKey:(NSString *)key { _fixtureAnimations[key]=animation;PresentationRecord(@"layer.animation",animation); }
- (void)removeAllAnimations { [_fixtureAnimations removeAllObjects];PresentationRecord(@"layer.removeAnimations",self); }
- (void)renderInContext:(CGContextRef)context {
    NSCAssert(context!=NULL,@"memory renderer context exists");
    NSDictionary *record=@{@"class":NSStringFromClass([_fixtureOwner class]) ?: @"CALayer",@"frame":[NSValue valueWithCGRect:_frame],@"sublayers":@(_sublayers.count)};
    PresentationRecord(@"layer.render",record);if(currentDrawing)currentDrawing[@"layer"]=record;
}
- (void)setBackgroundColor:(CGColorRef)color { if(color)CGColorRetain(color);if(_backgroundColor)CGColorRelease(_backgroundColor);_backgroundColor=color; }
- (void)setBorderColor:(CGColorRef)color { if(color)CGColorRetain(color);if(_borderColor)CGColorRelease(_borderColor);_borderColor=color; }
- (void)setShadowColor:(CGColorRef)color { if(color)CGColorRetain(color);if(_shadowColor)CGColorRelease(_shadowColor);_shadowColor=color; }
- (void)dealloc { if(_backgroundColor)CGColorRelease(_backgroundColor);if(_borderColor)CGColorRelease(_borderColor);if(_shadowColor)CGColorRelease(_shadowColor); }
@end
@implementation CAShapeLayer @end
@implementation CATransaction
+ (void)begin { PresentationInitialize();[transactions addObject:[NSMutableDictionary new]]; }
+ (void)setCompletionBlock:(dispatch_block_t)completion { if(completion)transactions.lastObject[@"completion"]=[completion copy]; }
+ (void)setDisableActions:(BOOL)disabled { PresentationRecord(@"transaction.disabled",@(disabled)); }
+ (void)setAnimationDuration:(CFTimeInterval)duration { PresentationRecord(@"transaction.duration",@(duration)); }
+ (void)commit {
    NSCAssert(transactions.count,@"balanced transaction");dispatch_block_t block=transactions.lastObject[@"completion"];
    [transactions removeLastObject];if(block)[PresentationAnimations addObject:^(BOOL finished){(void)finished;block();}];
}
@end
@implementation NSValue (PresentationFixtureTransforms)
+ (instancetype)valueWithCATransform3D:(CATransform3D)transform { return [self valueWithBytes:&transform objCType:@encode(CATransform3D)]; }
- (CATransform3D)CATransform3DValue { CATransform3D value;[self getValue:&value size:sizeof(value)];return value; }
@end

const UIFontWeight UIFontWeightRegular=0,UIFontWeightBold=0.4;
const UILayoutPriority UILayoutPriorityRequired=1000;
const UIWindowLevel UIWindowLevelAlert=2000;
const UIScrollViewDecelerationRate UIScrollViewDecelerationRateNormal=0.998;
UIActivityType const UIActivityTypeAssignToContact=@"assign",UIActivityTypePrint=@"print";
NSString *const UIKeyboardWillShowNotification=@"keyboardWillShow",*const UIKeyboardWillHideNotification=@"keyboardWillHide",*const UIKeyboardFrameEndUserInfoKey=@"keyboardEndFrame";
@implementation UIFont
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight { UIFont *f=[self new];f.pointSize=size;f.fixtureWeight=weight;return f; }
+ (instancetype)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight { UIFont *f=[self systemFontOfSize:size weight:weight];f.fixtureMonospaced=YES;return f; }
@end
@implementation UIColor
+ (instancetype)fixtureColor:(CGFloat)white alpha:(CGFloat)alpha {
    UIColor *c=[self new];CGFloat components[]={white,white,white,alpha};
    c.fixtureComponents=[NSData dataWithBytes:components length:sizeof(components)];
    CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();c->_fixtureColor=CGColorCreate(space,components);CGColorSpaceRelease(space);return c;
}
+ (instancetype)whiteColor { return [self fixtureColor:1 alpha:1]; }
+ (instancetype)blackColor { return [self fixtureColor:0 alpha:1]; }
+ (instancetype)clearColor { return [self fixtureColor:0 alpha:0]; }
+ (instancetype)labelColor { return [self blackColor]; }
+ (instancetype)secondaryLabelColor { return [self fixtureColor:0.5 alpha:1]; }
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha { const CGFloat *c=_fixtureComponents.bytes;return [UIColor fixtureColor:c[0] alpha:alpha]; }
- (CGColorRef)CGColor { return _fixtureColor; }
- (void)dealloc { if(_fixtureColor)CGColorRelease(_fixtureColor); }
@end
@implementation NSLayoutConstraint
+ (void)activateConstraints:(NSArray<NSLayoutConstraint *> *)constraints { for(NSLayoutConstraint *c in constraints)c.active=YES; }
+ (void)deactivateConstraints:(NSArray<NSLayoutConstraint *> *)constraints { for(NSLayoutConstraint *c in constraints)c.active=NO; }
- (void)setActive:(BOOL)active {
    _active=active;id owner=_firstAnchor.owner;if([owner isKindOfClass:UILayoutGuide.class])owner=[owner owningView];
    if([owner isKindOfClass:UIView.class]) {
        NSMutableArray *array=[owner fixtureConstraints];
        if(active && ![array containsObject:self])[array addObject:self];
        else if(!active)[array removeObjectIdenticalTo:self];
    }
    PresentationRecord(@"constraint.active",@[@(active),self]);
}
@end
@implementation NSLayoutAnchor
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor { return [self constraintEqualToAnchor:anchor constant:0]; }
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)constant {
    NSLayoutConstraint *c=[NSLayoutConstraint new];c.firstAnchor=self;c.secondAnchor=anchor;c.constant=constant;return c;
}
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)constant { return [self constraintEqualToAnchor:nil constant:constant]; }
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToAnchor:(NSLayoutAnchor *)anchor { NSLayoutConstraint *c=[self constraintEqualToAnchor:anchor];c.fixtureRelation=1;return c; }
- (NSLayoutConstraint *)constraintGreaterThanOrEqualToConstant:(CGFloat)constant { NSLayoutConstraint *c=[self constraintEqualToConstant:constant];c.fixtureRelation=1;return c; }
@end
static NSLayoutAnchor *MakeAnchor(id owner,NSString *kind) { NSLayoutAnchor *a=[NSLayoutAnchor new];a.owner=owner;a.kind=kind;return a; }
#define IMPLEMENT_ANCHORS \
- (NSLayoutAnchor *)topAnchor { return MakeAnchor(self,@"top"); } \
- (NSLayoutAnchor *)bottomAnchor { return MakeAnchor(self,@"bottom"); } \
- (NSLayoutAnchor *)leadingAnchor { return MakeAnchor(self,@"leading"); } \
- (NSLayoutAnchor *)trailingAnchor { return MakeAnchor(self,@"trailing"); } \
- (NSLayoutAnchor *)centerXAnchor { return MakeAnchor(self,@"centerX"); } \
- (NSLayoutAnchor *)centerYAnchor { return MakeAnchor(self,@"centerY"); } \
- (NSLayoutAnchor *)widthAnchor { return MakeAnchor(self,@"width"); } \
- (NSLayoutAnchor *)heightAnchor { return MakeAnchor(self,@"height"); }
@implementation UILayoutGuide
IMPLEMENT_ANCHORS
@end
@implementation UIEvent @end
@interface UIView ()
@property(nonatomic,strong) NSMutableArray<UIView *> *fixtureSubviews;
@property(nonatomic,strong) NSMutableArray<UIGestureRecognizer *> *fixtureRecognizers;
@property(nonatomic,strong) UILayoutGuide *fixtureSafeArea;
@end
@implementation UIView
- (instancetype)init {
    self=[super init];if(self){_alpha=1;_transform=CGAffineTransformIdentity;_layer=[CALayer layer];_layer.fixtureOwner=self;
        _fixtureSubviews=[NSMutableArray new];_fixtureRecognizers=[NSMutableArray new];_fixtureConstraints=[NSMutableArray new];
        _fixtureHugging=[NSMutableDictionary new];_fixtureCompression=[NSMutableDictionary new];_fixtureSafeArea=[UILayoutGuide new];
        _fixtureSafeArea.owningView=self;_userInteractionEnabled=YES;_translatesAutoresizingMaskIntoConstraints=YES;}return self;
}
- (instancetype)initWithFrame:(CGRect)frame { self=[self init];if(self)self.frame=frame;return self; }
- (void)setFrame:(CGRect)frame { _frame=frame;_bounds.size=frame.size;_center=CGPointMake(CGRectGetMidX(frame),CGRectGetMidY(frame));_layer.frame=frame; }
- (void)setBounds:(CGRect)bounds { _bounds=bounds;_layer.bounds=bounds; }
- (void)setCenter:(CGPoint)center { _center=center;_frame.origin=CGPointMake(center.x-_frame.size.width/2,center.y-_frame.size.height/2);_layer.position=center; }
- (void)setAlpha:(CGFloat)alpha { _alpha=alpha;_layer.opacity=(float)alpha; }
- (void)setTransform:(CGAffineTransform)transform { _transform=transform;_layer.transform=CATransform3DMakeScale(transform.a,transform.d,1); }
- (void)addSubview:(UIView *)view { if(!view)return;[view removeFromSuperview];[_fixtureSubviews addObject:view];view.superview=self;[_layer addSublayer:view.layer]; }
- (void)removeFromSuperview { [_superview.fixtureSubviews removeObjectIdenticalTo:self];_superview=nil;[_layer.superlayer.sublayers removeObjectIdenticalTo:_layer];_layer.superlayer=nil; }
- (void)bringSubviewToFront:(UIView *)view { if([_fixtureSubviews containsObject:view]){[_fixtureSubviews removeObjectIdenticalTo:view];[_fixtureSubviews addObject:view];} }
- (void)sendSubviewToBack:(UIView *)view { if([_fixtureSubviews containsObject:view]){[_fixtureSubviews removeObjectIdenticalTo:view];[_fixtureSubviews insertObject:view atIndex:0];} }
- (NSArray<UIView *> *)subviews { return [_fixtureSubviews copy]; }
- (NSArray<UIGestureRecognizer *> *)gestureRecognizers { return [_fixtureRecognizers copy]; }
- (UILayoutGuide *)safeAreaLayoutGuide { return _fixtureSafeArea; }
- (void)addGestureRecognizer:(UIGestureRecognizer *)r { [_fixtureRecognizers addObject:r];r.view=self; }
- (void)removeGestureRecognizer:(UIGestureRecognizer *)r { [_fixtureRecognizers removeObjectIdenticalTo:r];r.view=nil; }
- (void)setContentHuggingPriority:(UILayoutPriority)p forAxis:(UILayoutConstraintAxis)a { _fixtureHugging[@(a)]=@(p); }
- (void)setContentCompressionResistancePriority:(UILayoutPriority)p forAxis:(UILayoutConstraintAxis)a { _fixtureCompression[@(a)]=@(p); }
- (void)layoutIfNeeded { _fixtureLayouts++;PresentationRecord(@"view.layout",NSStringFromClass(self.class)); }
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    if(_hidden||_alpha<=0.01||!_userInteractionEnabled||!CGRectContainsPoint(_bounds,point))return nil;
    for(UIView *view in [_fixtureSubviews reverseObjectEnumerator]){
        UIView *hit=[view hitTest:CGPointMake(point.x-view.frame.origin.x,point.y-view.frame.origin.y) withEvent:event];if(hit)return hit;
    }return self;
}
- (CGRect)convertRect:(CGRect)rect fromView:(UIView *)view { (void)view;return rect; }
- (UIViewController *)_viewControllerForAncestor { return _fixtureController ?: [_superview _viewControllerForAncestor]; }
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay usingSpringWithDamping:(CGFloat)damping
     initialSpringVelocity:(CGFloat)velocity options:(UIViewAnimationOptions)options animations:(dispatch_block_t)animations completion:(void (^)(BOOL))completion {
    PresentationRecord(@"view.spring",@[@(duration),@(delay),@(damping),@(velocity),@(options)]);
    if(animations)animations();if(completion)[PresentationAnimations addObject:[completion copy]];
}
+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options
                animations:(dispatch_block_t)animations completion:(void (^)(BOOL))completion {
    PresentationRecord(@"view.animation",@[@(duration),@(delay),@(options)]);if(animations)animations();if(completion)[PresentationAnimations addObject:[completion copy]];
}
+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options
               animations:(dispatch_block_t)animations completion:(void (^)(BOOL))completion {
    PresentationRecord(@"view.transition",@[view,@(duration),@(options)]);if(animations)animations();if(completion)[PresentationAnimations addObject:[completion copy]];
}
IMPLEMENT_ANCHORS
@end
@implementation UILabel @end
@implementation UIImage
+ (instancetype)systemImageNamed:(NSString *)name { if(!name)return nil;UIImage *image=[self new];image.fixtureName=name;image.size=CGSizeMake(24,24);return image; }
+ (instancetype)imageWithData:(NSData *)data { if(!data.length)return nil;UIImage *image=[self new];image.fixtureData=data;image.size=CGSizeMake(400,200);return image; }
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(id)traits {
    (void)traits;PresentationRecord(@"image.bundle",bundle.bundlePath);return [self systemImageNamed:name];
}
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode {
    UIImage *image=[UIImage new];image.fixtureName=_fixtureName;image.fixtureData=_fixtureData;image.fixtureDrawing=_fixtureDrawing;image.size=_size;image.renderingMode=mode;return image;
}
- (BOOL)isEqual:(id)object { return object==self || ([object isKindOfClass:UIImage.class] && _fixtureName && [_fixtureName isEqual:[object fixtureName]]); }
- (NSUInteger)hash { return _fixtureName.hash; }
@end
@implementation UIImageView
- (instancetype)initWithImage:(UIImage *)image { self=[super init];if(self){_image=image;self.userInteractionEnabled=NO;}return self; }
@end
@interface PresentationTarget : NSObject
@property(nonatomic,weak) id target;
@property(nonatomic) SEL selector;
@property(nonatomic) UIControlEvents events;
@end
@implementation PresentationTarget @end
@implementation UIControl
- (instancetype)init { self=[super init];if(self){_fixtureTargets=[NSMutableArray new];_fixtureActions=[NSMutableArray new];}return self; }
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events {
    PresentationTarget *entry=[PresentationTarget new];entry.target=target;entry.selector=action;entry.events=events;[_fixtureTargets addObject:entry];
}
- (void)addAction:(UIAction *)action forControlEvents:(UIControlEvents)events { [_fixtureActions addObject:@{@"action":action,@"events":@(events)}]; }
- (void)sendActionsForControlEvents:(UIControlEvents)events {
    for(PresentationTarget *entry in [_fixtureTargets copy])if((entry.events&events)&&entry.target&&entry.selector)
        ((void (*)(id,SEL,id))objc_msgSend)(entry.target,entry.selector,self);
    for(NSDictionary *entry in [_fixtureActions copy])if([entry[@"events"] unsignedIntegerValue]&events){UIAction *a=entry[@"action"];a.fixtureHandler(a);}
}
@end
@implementation UIButton
- (instancetype)init { self=[super init];if(self){_titleLabel=[UILabel new];_fixtureTitleColors=[NSMutableDictionary new];}return self; }
+ (instancetype)buttonWithType:(UIButtonType)type { (void)type;return [self new]; }
- (void)setImage:(UIImage *)image forState:(UIControlState)state { (void)state;_fixtureImage=image; }
- (void)setTitle:(NSString *)title forState:(UIControlState)state { (void)state;_fixtureTitle=[title copy];_titleLabel.text=title; }
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state { if(color)_fixtureTitleColors[@(state)]=color; }
@end
@implementation UIBlurEffect
+ (instancetype)effectWithStyle:(UIBlurEffectStyle)style { UIBlurEffect *effect=[self new];effect.fixtureStyle=style;return effect; }
@end
@implementation UIVisualEffectView
- (instancetype)initWithEffect:(UIBlurEffect *)effect { self=[super init];if(self){_effect=effect;_contentView=[UIView new];[self addSubview:_contentView];}return self; }
- (void)setFrame:(CGRect)frame { [super setFrame:frame];_contentView.frame=self.bounds; }
@end
@implementation UIProgressView
- (instancetype)initWithProgressViewStyle:(UIProgressViewStyle)style { self=[super init];if(self)PresentationRecord(@"progress.style",@(style));return self; }
- (void)setProgress:(float)progress animated:(BOOL)animated { _progress=progress;_fixtureAnimated=animated; }
@end
@implementation UIActivityIndicatorView
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style { self=[super init];if(self)PresentationRecord(@"spinner.style",@(style));return self; }
- (void)startAnimating { _fixtureAnimating=YES; }
- (void)stopAnimating { _fixtureAnimating=NO; }
@end
@interface UIStackView ()
@property(nonatomic,strong) NSMutableArray<UIView *> *fixtureArranged;
@end
@implementation UIStackView
- (instancetype)initWithArrangedSubviews:(NSArray<UIView *> *)views { self=[super init];if(self){_fixtureArranged=[NSMutableArray new];for(UIView *v in views)[self addArrangedSubview:v];}return self; }
- (NSArray<UIView *> *)arrangedSubviews { return [_fixtureArranged copy]; }
- (void)addArrangedSubview:(UIView *)view { [_fixtureArranged addObject:view];[self addSubview:view]; }
- (void)removeArrangedSubview:(UIView *)view { [_fixtureArranged removeObjectIdenticalTo:view]; }
@end
@implementation UIGestureRecognizer
- (instancetype)initWithTarget:(id)target action:(SEL)action { self=[super init];if(self){_fixtureTarget=target;_fixtureAction=action;}return self; }
- (CGPoint)locationInView:(UIView *)view { (void)view;return _fixtureLocation; }
@end
@implementation UITapGestureRecognizer @end
@implementation UIPanGestureRecognizer
- (CGPoint)translationInView:(UIView *)view { (void)view;return _fixtureTranslation; }
@end
@implementation UILongPressGestureRecognizer @end
@implementation UIAction
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler {
    (void)identifier;UIAction *action=[self new];action.title=title;action.image=image;action.fixtureHandler=handler;return action;
}
+ (instancetype)actionWithHandler:(void (^)(UIAction *))handler { return [self actionWithTitle:nil image:nil identifier:nil handler:handler]; }
@end
@implementation UIMenu
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children { UIMenu *menu=[self new];menu.title=title;menu.children=children;return menu; }
@end
@implementation UIBarButtonItem
- (instancetype)initWithCustomView:(UIView *)view { self=[super init];if(self)_customView=view;return self; }
@end
@implementation UINavigationItem @end
@implementation UINavigationBar
- (void)setBackgroundImage:(UIImage *)image forBarMetrics:(UIBarMetrics)metrics { (void)metrics;_fixtureBackgroundImage=image; }
@end
@implementation UIViewController
@synthesize view = _view;
- (instancetype)init { self=[super init];if(self){_navigationItem=[UINavigationItem new];_childViewControllers=@[];_popoverPresentationController=[UIPopoverPresentationController new];}return self; }
- (UIView *)view { if(!_view){[self loadView];[self viewDidLoad];}return _view; }
- (void)setView:(UIView *)view { _view=view;view.fixtureController=self; }
- (void)loadView { self.view=[[UIView alloc]initWithFrame:UIScreen.mainScreen.bounds]; }
- (void)viewDidLoad { _fixtureViewDidLoad++; }
- (void)viewDidLayoutSubviews { _fixtureLayouts++; }
- (UISheetPresentationController *)sheetPresentationController {
    if(!_sheetPresentationController)_sheetPresentationController=[[UISheetPresentationController alloc]initWithPresentedViewController:self presentingViewController:nil];return _sheetPresentationController;
}
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion {
    _fixturePresentations++;_presentedViewController=controller;controller.presentingViewController=self;
    id<UIViewControllerTransitioningDelegate> delegate=controller.transitioningDelegate;
    if(delegate)controller.presentationController=[delegate presentationControllerForPresentedViewController:controller presentingViewController:self sourceViewController:self];
    PresentationRecord(@"controller.present",@[controller,@(animated)]);if(completion)completion();
}
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion {
    _fixtureDismissals++;if(_presentingViewController.presentedViewController==self)_presentingViewController.presentedViewController=nil;
    _presentedViewController=nil;PresentationRecord(@"controller.dismiss",@(animated));if(completion)completion();
}
@end
@implementation UINavigationController
- (instancetype)init { self=[super init];if(self)_navigationBar=[UINavigationBar new];return self; }
- (instancetype)initWithRootViewController:(UIViewController *)root { self=[self init];if(self){self.childViewControllers=@[root];root.navigationController=self;}return self; }
@end
@implementation UIScrollView
- (instancetype)init { self=[super init];if(self)_zoomScale=1;return self; }
- (void)setZoomScale:(CGFloat)scale animated:(BOOL)animated { _zoomScale=scale;_fixtureZoomAnimated=animated; }
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated { _fixtureZoomRect=rect;_fixtureZoomAnimated=animated;_zoomScale=_maximumZoomScale; }
@end
@implementation UIPresentationController
- (instancetype)initWithPresentedViewController:(UIViewController *)presented presentingViewController:(UIViewController *)presenting {
    self=[super init];if(self){_presentedViewController=presented;_presentingViewController=presenting;_containerView=[[UIView alloc]initWithFrame:UIScreen.mainScreen.bounds];}return self;
}
- (UIView *)presentedView { return _presentedViewController.view; }
- (CGRect)frameOfPresentedViewInContainerView { return _containerView.bounds; }
- (void)containerViewWillLayoutSubviews { _fixtureLayoutCalls++; }
- (void)presentationTransitionWillBegin { PresentationRecord(@"presentation.begin",self); }
- (void)dismissalTransitionWillBegin { PresentationRecord(@"dismissal.begin",self); }
@end
@implementation UISheetPresentationControllerDetent
+ (BOOL)respondsToSelector:(SEL)selector { return selector==@selector(_detentWithIdentifier:constant:) ? PresentationNativeDetents : [super respondsToSelector:selector]; }
+ (instancetype)_detentWithIdentifier:(NSString *)identifier constant:(CGFloat)height { UISheetPresentationControllerDetent *d=[self new];d.identifier=identifier;d.fixtureHeight=height;return d; }
@end
@implementation UISheetPresentationController @end
@implementation UIPopoverPresentationController @end
@implementation UIActivityViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities { self=[super init];if(self){_fixtureItems=items;NSCAssert(!activities,@"no custom activities");}return self; }
@end
@implementation UIScene @end
@implementation UIWindowScene @end
@implementation UIWindow
- (instancetype)initWithWindowScene:(UIWindowScene *)scene { self=[super init];if(self){_windowScene=scene;NSMutableArray *windows=[scene.windows mutableCopy]?:[NSMutableArray new];[windows addObject:self];scene.windows=windows;}return self; }
- (void)setRootViewController:(UIViewController *)root { [_rootViewController.view removeFromSuperview];_rootViewController=root;if(root){root.view.frame=self.bounds;[self addSubview:root.view];} }
- (void)makeKeyAndVisible { _fixtureKeyWindow=YES;self.hidden=NO; }
- (void)resignKeyWindow { _fixtureKeyWindow=NO;_fixtureResignCalls++; }
- (BOOL)canBecomeKeyWindow { return YES; }
@end
@implementation UIApplication
+ (instancetype)sharedApplication { static UIApplication *app;if(!app){app=[self new];app.connectedScenes=[NSSet set];}return app; }
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion {
    PresentationRecord(@"application.openURL",@{@"url":url?:NSNull.null,@"options":options?:@{}});
    if(completion)completion(YES);
}
@end
@implementation UIDevice
+ (instancetype)currentDevice { static UIDevice *device;if(!device){device=[self new];device.model=@"iPhone";device.userInterfaceIdiom=UIUserInterfaceIdiomPhone;}return device; }
@end
@implementation UIScreen
+ (instancetype)mainScreen { static UIScreen *screen;if(!screen){screen=[self new];screen.bounds=CGRectMake(0,0,390,844);}return screen; }
- (void)setBrightness:(CGFloat)value { _brightness=value;_fixtureBrightnessWrites++;PresentationRecord(@"screen.brightness",@(value)); }
@end
@implementation UIImpactFeedbackGenerator
- (instancetype)initWithStyle:(UIImpactFeedbackStyle)style { self=[super init];if(self)_fixtureStyle=style;return self; }
- (void)prepare { PresentationRecord(@"haptic.prepare",@(_fixtureStyle)); }
- (void)impactOccurred { PresentationRecord(@"haptic.impact",@(_fixtureStyle)); }
@end
@implementation UIPasteboard
+ (instancetype)generalPasteboard { static UIPasteboard *pasteboard;if(!pasteboard)pasteboard=[self new];return pasteboard; }
@end
static CGContextRef NewBitmap(CGSize size) {
    NSCAssert(isfinite(size.width)&&isfinite(size.height)&&size.width>0&&size.height>0&&size.width<=1024&&size.height<=1024,@"bounded synthetic bitmap");
    CGColorSpaceRef space=CGColorSpaceCreateDeviceRGB();CGContextRef context=CGBitmapContextCreate(NULL,(size_t)ceil(size.width),(size_t)ceil(size.height),8,0,space,(CGBitmapInfo)kCGImageAlphaPremultipliedLast);CGColorSpaceRelease(space);return context;
}
@implementation UIGraphicsImageRendererContext
- (CGContextRef)CGContext { return _fixtureCGContext; }
@end
@implementation UIGraphicsImageRenderer
- (instancetype)initWithSize:(CGSize)size { self=[super init];if(self)_fixtureSize=size;return self; }
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions {
    UIGraphicsImageRendererContext *context=[UIGraphicsImageRendererContext new];context.fixtureCGContext=NewBitmap(_fixtureSize);
    context.fixtureContext=[NSMutableDictionary new];NSMutableDictionary *prior=currentDrawing;currentDrawing=context.fixtureContext;
    actions(context);currentDrawing=prior;CGContextRelease(context.fixtureCGContext);context.fixtureCGContext=NULL;
    UIImage *image=[UIImage new];image.size=_fixtureSize;image.fixtureDrawing=context.fixtureContext;return image;
}
@end
void UIGraphicsBeginImageContextWithOptions(CGSize size,BOOL opaque,CGFloat scale) {
    NSCAssert(!currentContext,@"balanced synthetic UIGraphics context");currentContext=NewBitmap(size);currentContextSize=size;
    currentDrawing=[NSMutableDictionary new];PresentationRecord(@"graphics.begin",@[@(size.width),@(size.height),@(opaque),@(scale)]);
}
CGContextRef UIGraphicsGetCurrentContext(void) { return currentContext; }
UIImage *UIGraphicsGetImageFromCurrentImageContext(void) { UIImage *image=[UIImage new];image.size=currentContextSize;image.fixtureDrawing=[currentDrawing copy];return image; }
void UIGraphicsEndImageContext(void) { if(currentContext)CGContextRelease(currentContext);currentContext=NULL;currentDrawing=nil;PresentationRecord(@"graphics.end",@YES); }
void UIImageWriteToSavedPhotosAlbum(UIImage *image,id target,SEL completion,void *context) {
    NSCAssert(!target&&!completion&&!context,@"image viewer Photos callback contract");PresentationRecord(@"photos.UIImage",image);
}
@implementation NSValue (PresentationFixtureGeometry)
+ (instancetype)valueWithCGPoint:(CGPoint)p { return [self valueWithBytes:&p objCType:@encode(CGPoint)]; }
+ (instancetype)valueWithCGRect:(CGRect)r { return [self valueWithBytes:&r objCType:@encode(CGRect)]; }
- (CGPoint)CGPointValue { CGPoint p;[self getValue:&p size:sizeof(p)];return p; }
- (CGRect)CGRectValue { CGRect r;[self getValue:&r size:sizeof(r)];return r; }
@end
@implementation PHAssetResourceCreationOptions @end
@implementation PHAssetCreationRequest
+ (instancetype)creationRequestForAsset { PresentationRecord(@"photos.request",@YES);return [self new]; }
- (void)addResourceWithType:(PHAssetResourceType)type fileURL:(NSURL *)url options:(PHAssetResourceCreationOptions *)options {
    NSCAssert(!options,@"Photos default options");PresentationRecord(@"photos.resource",@{@"type":@(type),@"url":url});
}
- (void)addResourceWithType:(PHAssetResourceType)type data:(NSData *)data options:(PHAssetResourceCreationOptions *)options {
    NSCAssert(!options,@"Photos default options");PresentationRecord(@"photos.resource",@{@"type":@(type),@"data":data});
}
@end
@implementation PHPhotoLibrary
+ (instancetype)sharedPhotoLibrary { static PHPhotoLibrary *library;if(!library)library=[self new];return library; }
- (void)performChanges:(dispatch_block_t)changes completionHandler:(void (^)(BOOL,NSError *))completion {
    [PresentationPhotoChanges addObject:@{@"changes":[changes copy],@"completion":[completion copy]}];
}
@end
SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator,const struct sockaddr *address) {
    (void)allocator;if(!PresentationReachabilityCreated)return NULL;
    PresentationRecord(@"reachability.address",[NSData dataWithBytes:address length:address->sa_len]);
    return (SCNetworkReachabilityRef)CFDataCreate(NULL,(const UInt8 *)address,address->sa_len);
}
Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef reference,SCNetworkReachabilityFlags *flags) {
    NSCAssert(reference&&flags,@"reachable fixture flags arguments");*flags=PresentationReachabilityFlags;return PresentationReachabilitySucceeded;
}
@implementation NSBundle (PresentationFixtureBundle)
+ (NSBundle *)ytl_defaultBundle { return NSBundle.mainBundle; }
@end
@implementation PresentationAppDelegate @end
@implementation PresentationTransition
- (BOOL)animateAlongsideTransition:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))animation
                       completion:(void (^)(id<UIViewControllerTransitionCoordinatorContext>))completion {
    if(animation)animation(self);_fixtureCompletion=completion;return YES;
}
@end
@implementation PresentationSheetController @end
@implementation MPVolumeController
- (instancetype)init { self=[super init];if(self)_volumeAudioCategory=@"Audio/Video";return self; }
@end
@implementation MPVolumeHUDController
+ (instancetype)sharedInstance { static MPVolumeHUDController *controller;if(!controller){controller=[self new];controller.fixtureDisplays=[NSMutableArray new];}return controller; }
- (void)addVolumeDisplay:(id)display { if(![_fixtureDisplays containsObject:display])[_fixtureDisplays addObject:display];PresentationRecord(@"volume.add",display); }
- (void)removeVolumeDisplay:(id)display { [_fixtureDisplays removeObjectIdenticalTo:display];PresentationRecord(@"volume.remove",display); }
@end
