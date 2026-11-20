#import "../source/Hooks/PlayerBarsHost.h"
#import "../source/Playback/SBPlayerDecorator.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>
#import <objc/message.h>
#include <math.h>
#include <string.h>

static NSUInteger checks;

#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){NSLog(@"FAIL %d %s",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
static NSMutableDictionary *flags;

static NSMutableArray *events,*gates;

static id lastArgument;

static UIView *originalDot;

static UIImage *originalImage;

static UIColor *originalColor;

static CGRect lastRect;

static double lastDouble;

static BOOL lastBool,activeResult;

static NSString *suite;

static UIView *decoratedBar;

static CALayer *decoratedLayer;

static id decoratedPlayer,decoratedPlayerBar;

static void record(NSString *event){[events addObject:event];
}
BOOL ytpBool(NSString *key){[gates addObject:key];
return [flags[key] boolValue];
}
NSInteger ytpInt(NSString *key){[gates addObject:key];
return [flags[key] integerValue];
}
static void reset(void){[events removeAllObjects];
[gates removeAllObjects];
decoratedBar=nil;
decoratedLayer=nil;
decoratedPlayer=nil;
decoratedPlayerBar=nil;
lastArgument=nil;
}
@implementation UIView
- (instancetype)init{if((self=[super init]))_layer=[CALayer layer];
return self;
}
- (void)setFrame:(CGRect)frame{_frame=frame;
lastRect=frame;
record(@"frame");
}
- (void)layoutSubviews{record(@"layout");
}
- (UIViewController *)_viewControllerForAncestor{return self.ancestor;
}
@end
@implementation UILabel
- (void)sizeToFit{self.fits++;
record(@"fit");
}
@end
@implementation UIViewController @end
@implementation UIColor
+ (BOOL)supportsSecureCoding{return YES;
}
+ (instancetype)named:(NSString *)name{UIColor *c=[self new];
c.name=name;
return c;
}
- (void)encodeWithCoder:(NSCoder *)coder{[coder encodeObject:self.name forKey:@"name"];
}
- (instancetype)initWithCoder:(NSCoder *)coder{if((self=[super init]))_name=[coder decodeObjectOfClass:NSString.class forKey:@"name"];
return self;
}
- (CGColorRef)CGColor{if(!_cgColor)_cgColor=CGColorCreateGenericRGB([self.name isEqual:@"main"]?1:0,[self.name isEqual:@"end"]?1:0,[self.name isEqual:@"scrubber"]?1:0,1);
return _cgColor;
}
- (void)dealloc{if(_cgColor)CGColorRelease(_cgColor);
}
@end
@implementation UIImage
- (UIImage *)_flatImageWithColor:(UIColor *)color{UIImage *i=[UIImage new];
i.name=@"flat";
i.tint=color;
record(@"flat");
return i;
}
@end
@implementation UISlider @end
@implementation UIScreen
+ (instancetype)mainScreen{static UIScreen *s;
if(!s){s=[self new];
s.bounds=CGRectMake(0,0,390,844);
}return s;
}
@end
@implementation UIGestureRecognizer
- (CGPoint)locationInView:(UIView *)view{self.locationView=view;
return self.point;
}
@end
@implementation YTLUserDefaults
+ (instancetype)standardUserDefaults{static YTLUserDefaults *d;
if(!d){suite=[@"PlayerBarsFixture." stringByAppendingString:NSUUID.UUID.UUIDString];
d=[[self alloc] initWithSuiteName:suite];
}return d;
}
@end
@implementation SBPlayerDecorator
+ (void)drawSegmentsDecorationView:(UIView *)bar{decoratedBar=bar;
record(@"decoration");
}
+ (void)drawSegments:(UIView *)bar layer:(CALayer *)layer playerVC:(id)player{decoratedBar=bar;
decoratedLayer=layer;
decoratedPlayer=player;
record(@"segments");
}
+ (void)drawSegmentableSegments:(UIView *)bar playerBar:(id)playerBar playerVC:(id)player{decoratedBar=bar;
decoratedPlayerBar=playerBar;
decoratedPlayer=player;
record(@"segmentable");
}
@end
@implementation YTInlinePlayerBarContainerView
@dynamic sbTimeString,endTimeString;

- (void)setPeekableViewVisible:(BOOL)value{lastBool=value;
record(@"peek");
}
- (void)setPlayerBarAlpha:(CGFloat)value{lastDouble=value;
record(@"alpha");
}
- (UIColor *)quietProgressBarColor{record(@"quiet");
return originalColor;
}
- (void)didPressScrubber:(UIGestureRecognizer *)recognizer{lastArgument=recognizer;
record(@"press");
}
- (CGFloat)scrubRangeForScrubX:(CGFloat)x{lastDouble=x;
record(@"range");
return x/100.0;
}
@end
@implementation YTPlayerBarRectangleDecorationView
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient{lastRect=rect;
lastArgument=gradient;
record(@"overall");
}
- (void)applyGradientForRect:(CGRect)rect{lastRect=rect;
record(@"gradient");
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color{lastRect=rect;
lastArgument=color;
record(@"draw");
}
- (BOOL)isStateActive{record(@"active");
return activeResult;
}
@end
@implementation YTPlayerBarProgressDecorationView
- (void)applyGradientColorForRect:(CGRect)rect withOverallGradient:(CAGradientLayer *)gradient{lastRect=rect;
lastArgument=gradient;
record(@"overall");
}
- (void)applyGradientForRect:(CGRect)rect{lastRect=rect;
record(@"gradient");
}
- (void)drawProgressRect:(CGRect)rect withColor:(UIColor *)color{lastRect=rect;
lastArgument=color;
record(@"draw");
}
- (BOOL)isStateActive{record(@"active");
return activeResult;
}
@end
@implementation YTPlayerBarScrubberDotDecorationView
- (UIView *)scrubberDot{record(@"dot");
return originalDot;
}
@end
@implementation YTPlayerBarScrubberDotDecorationViewV1
- (UIView *)scrubberDot{record(@"dotV1");
return originalDot;
}
@end
@implementation YTModularPlayerBarView @end
@implementation YTProgressView
- (void)setProgress:(double)value{lastDouble=value;
record(@"progress");
}
- (void)setProgressBarColor:(UIColor *)color{lastArgument=color;
record(@"progressColor");
}
@end
@implementation YTInlineMutedPlaybackScrubberView
- (void)setMediaTime:(double)value{lastDouble=value;
record(@"mediaTime");
}
- (void)addGradient{record(@"addGradient");
}
// These optional selectors deliberately have no implementation in the base host fixture.
@end
@implementation YTInlineMutedPlaybackScrubbingSlider
- (UIImage *)currentMinimumTrackImage{record(@"trackImage");
return originalImage;
}
@end
@interface PBRectangle : YTPlayerBarRectangleDecorationView
@property(nonatomic,strong) UIView *brandGradient;

@end
@implementation PBRectangle @end
@interface PBProgressDecoration : YTPlayerBarProgressDecorationView
@property(nonatomic,strong) UIView *brandGradient;

@end
@implementation PBProgressDecoration @end
@interface PBModular : YTModularPlayerBarView
@property(nonatomic,strong) UIView *scrubberCircle;

@end
@implementation PBModular @end
@interface PBProgress : YTProgressView
@property(nonatomic,strong) UIView *progressBarGradientView;

@property(nonatomic,strong) CAGradientLayer *progressBarGradient;

@end
@implementation PBProgress @end
@interface PBMuted : YTInlineMutedPlaybackScrubberView
@property(nonatomic,strong) UIView *playingProgress;

@property(nonatomic,strong) CAGradientLayer *progressBarGradient;

@end
@implementation PBMuted @end
@interface PBSegmentable : PBMuted
@property BOOL enabled;

@property(nonatomic,strong) id playerBar;

@end
@implementation PBSegmentable
- (BOOL)segmentablePlayerBarEnabled{record(@"enabledGetter");
return self.enabled;
}
- (id)segmentablePlayerBar{return self.playerBar;
}
@end
@interface YTPlayerViewController : UIViewController<YTLPlayerBarsPlayer>
@property double duration,seek;

@end
@implementation YTPlayerViewController
- (double)currentVideoTotalMediaTime{return self.duration;
}
- (void)seekToTime:(double)time{self.seek=time;
record(@"seek");
}
@end
@interface YTWatchMiniBarViewController : UIViewController @end
@implementation YTWatchMiniBarViewController @end
@interface PBMini : YTWatchMiniBarViewController
@property(nonatomic,strong) id playerViewController;

@end
@implementation PBMini @end
@interface YTWatchFloatingMiniplayerViewController : UIViewController @end
@implementation YTWatchFloatingMiniplayerViewController @end
@interface PBFloating : YTWatchFloatingMiniplayerViewController
@property(nonatomic,strong) id playerViewController;

@end
@implementation PBFloating @end
@interface YTVideoThumbnailView : UIView @end
@implementation YTVideoThumbnailView @end
@interface YTInlineMutedPlaybackScrubberViewController : UIViewController @end
@implementation YTInlineMutedPlaybackScrubberViewController @end
@interface YTInlineMutedPlaybackPlayerOverlayViewController : UIViewController @end
@implementation YTInlineMutedPlaybackPlayerOverlayViewController @end

static void colorPref(NSString *key,NSString *name){YTLUserDefaults *d=[YTLUserDefaults standardUserDefaults];
if(name)[d setObject:[NSKeyedArchiver archivedDataWithRootObject:[UIColor named:name] requiringSecureCoding:YES error:nil] forKey:key];
else[d removeObjectForKey:key];
}
static BOOL colorIs(UIColor *color,NSString *name){return [color.name isEqual:name];
}
static BOOL rgbIs(id value,CGFloat red,CGFloat green,CGFloat blue){CGColorRef c=(__bridge CGColorRef)value;
const CGFloat *components=CGColorGetComponents(c);
return CGColorGetNumberOfComponents(c)==4&&components[0]==red&&components[1]==green&&components[2]==blue&&components[3]==1;
}
static void testGradient(CAGradientLayer *gradient,BOOL solid){CHECK(gradient.colors.count==3);
CHECK(rgbIs(gradient.colors[0],1,0,0)&&rgbIs(gradient.colors[1],1,0,0));
CHECK(solid?rgbIs(gradient.colors[2],1,0,0):rgbIs(gradient.colors[2],0,1,0));
CHECK([gradient.locations isEqual:@[@0,@0.75,@1]]);
CHECK(CGPointEqualToPoint(gradient.startPoint,CGPointMake(0,0.5))&&CGPointEqualToPoint(gradient.endPoint,CGPointMake(1,0.5)));
}
static void testPair(CAGradientLayer *gradient,NSInteger mode){CHECK(gradient.colors.count==2);
CHECK(rgbIs(gradient.colors[0],1,0,0));
CHECK(mode==1?rgbIs(gradient.colors[1],1,0,0):rgbIs(gradient.colors[1],0,1,0));
}
static void mutedHierarchy(PBMuted *bar,YTPlayerViewController *player){UIViewController *scrub=[YTInlineMutedPlaybackScrubberViewController new],*overlay=[YTInlineMutedPlaybackPlayerOverlayViewController new];
overlay.parentResponder=player;
scrub.parentViewController=overlay;
bar.ancestor=scrub;
bar.playingProgress=[UIView new];
}
int main(void){@autoreleasepool{
    flags=[NSMutableDictionary dictionary];
events=[NSMutableArray array];
gates=[NSMutableArray array];
originalColor=[UIColor named:@"original"];
originalImage=[UIImage new];

    colorPref(@"progressMainColor",@"main");
colorPref(@"progressGradientColor",@"end");
colorPref(@"scrubberColor",@"scrubber");

    YTLInstallPlayerBarsSponsorHooks();

    YTInlinePlayerBarContainerView *bar=[YTInlinePlayerBarContainerView new];
bar.durationLabel=[UILabel new];
bar.durationLabel.text=@"10:00";
NSMutableString *sb=[@"8:00" mutableCopy];
bar.sbTimeString=sb;
[sb appendString:@"!"];
CHECK(bar.sbTimeString==sb);
CHECK(![bar respondsToSelector:@selector(endTimeString)]);

    flags[@"sponsorBlock"]=@YES;
flags[@"sbDurationLabel"]=@YES;
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"10:00 (8:00!)"]&&lastBool);
CHECK([events isEqual:@[@"peek",@"fit"]]);
reset();
[bar setPeekableViewVisible:NO];
CHECK([events isEqual:@[@"peek"]]&&!lastBool);

    YTLInstallPlayerBarsAppearanceHooks();

    reset();
bar.endTimeString=@"20:00";
flags[@"videoEndTime"]=@YES;
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"10:00 (8:00!) • 20:00"]);
CHECK([events isEqual:@[@"peek",@"fit"]]);
reset();
bar.durationLabel.text=@"10:00";
[bar setPeekableViewVisible:YES];
CHECK([events isEqual:@[@"peek",@"fit",@"fit"]]);
CHECK([bar.durationLabel.text isEqual:@"10:00 (8:00!) • 20:00"]);

    reset();
[bar setPeekableViewVisible:NO];
CHECK([events isEqual:@[@"peek"]]);
reset();
flags[@"sponsorBlock"]=@NO;
flags[@"videoEndTime"]=@NO;
bar.durationLabel.text=@"clean";
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"clean"]);
CHECK(![gates containsObject:@"sbDurationLabel"]);
flags[@"sponsorBlock"]=@YES;
flags[@"sbDurationLabel"]=@NO;
flags[@"videoEndTime"]=@YES;
bar.endTimeString=nil;
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"clean"]);
bar.sbTimeString=nil;
flags[@"sbDurationLabel"]=@YES;
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"clean"]);
bar.endTimeString=@"";
[bar setPeekableViewVisible:YES];
CHECK([bar.durationLabel.text isEqual:@"clean • "]); // Foundation containsString:@"" is false.

    reset();
flags[@"persistentProgressBar"]=@NO;
[bar setPlayerBarAlpha:0.1234567890123];
CHECK(lastDouble==0.1234567890123);
flags[@"persistentProgressBar"]=@YES;
[bar setPlayerBarAlpha:-2];
CHECK(lastDouble==1.0);

    bar.superview=[UIView new];
bar.superview.bounds=CGRectMake(0,0,844,390);
bar.superview.safeAreaInsets=(UIEdgeInsets){1,2,34,4};
CGRect rect=CGRectMake(11.125,20.25,700.5,9.75);
flags[@"noFullscreenActions"]=@NO;
[bar setFrame:rect];
CHECK(CGRectEqualToRect(lastRect,rect));
flags[@"noFullscreenActions"]=@YES;
[bar setFrame:rect];
CHECK(lastRect.origin.x==rect.origin.x&&lastRect.origin.y==336.25&&lastRect.size.width==rect.size.width&&lastRect.size.height==rect.size.height);
rect.size.width=390;
reset();
[bar setFrame:rect];
CHECK(CGRectEqualToRect(lastRect,rect)&&![gates containsObject:@"noFullscreenActions"]);

    flags[@"progressBarIndex"]=@0;
CHECK([bar quietProgressBarColor]==originalColor);
flags[@"progressBarIndex"]=@2;
reset();
CHECK(colorIs([bar quietProgressBarColor],@"main")&&events.count==0);
colorPref(@"progressMainColor",nil);
CHECK([bar quietProgressBarColor]==originalColor);
colorPref(@"progressMainColor",@"main");

    UIGestureRecognizer *gesture=[UIGestureRecognizer new];
gesture.point=CGPointMake(25.123456789,999);
bar.ancestor=[UIViewController new];
YTPlayerViewController *player=[YTPlayerViewController new];
player.duration=333.123456789;
bar.ancestor.parentViewController=player;
flags[@"tapToSeek"]=@YES;
reset();
[bar didPressScrubber:gesture];
CHECK(lastArgument==gesture&&gesture.locationView==bar);
CHECK(player.seek==gesture.point.x/100*player.duration);
CHECK([events isEqual:@[@"press",@"range",@"seek"]]);
flags[@"tapToSeek"]=@NO;
reset();
[bar didPressScrubber:gesture];
CHECK([events isEqual:@[@"press"]]);
flags[@"tapToSeek"]=@YES;
bar.ancestor.parentViewController=[UIViewController new];
reset();
[bar didPressScrubber:gesture];
CHECK([events isEqual:@[@"press"]]&&![gates containsObject:@"tapToSeek"]);

    for(id dotView in @[[YTPlayerBarScrubberDotDecorationView new],[YTPlayerBarScrubberDotDecorationViewV1 new]]){originalDot=[UIView new];
flags[@"progressBarIndex"]=@0;
CHECK([dotView scrubberDot]==originalDot&&[originalDot backgroundColor]==nil);
flags[@"progressBarIndex"]=@(-1);
CHECK([dotView scrubberDot]==originalDot&&colorIs([originalDot backgroundColor],@"scrubber"));
originalDot=nil;
reset();
CHECK([dotView scrubberDot]==nil&&gates.count==0);
}
    for(id decoration in @[[PBRectangle new],[PBProgressDecoration new]]){
        [decoration setBrandGradient:[UIView new]];
UIView *brand=[decoration brandGradient];
brand.bounds=CGRectMake(1,2,300.125,4.5);
rect=CGRectMake(2.125,3.25,4.5,6.75);

        for(NSNumber *mode in @[@0,@1,@2,@3]){flags[@"progressBarIndex"]=mode;
reset();
[decoration drawProgressRect:rect withColor:originalColor];
CHECK(CGRectEqualToRect(lastRect,rect));
CHECK([events isEqual:@[@"draw",@"decoration"]]);
CHECK(mode.integerValue?colorIs(lastArgument,@"main"):lastArgument==originalColor);

            CAGradientLayer *overall=[CAGradientLayer layer];
[decoration applyGradientColorForRect:rect withOverallGradient:overall];
CHECK(CGRectEqualToRect(lastRect,rect)&&lastArgument==overall);
if(mode.integerValue==1||mode.integerValue==2)testPair(overall,mode.integerValue);
else CHECK(overall.colors==nil);

        }
        flags[@"progressBarIndex"]=@0;
[decoration applyGradientForRect:rect];
CHECK(brand.layer.sublayers.count==0);

        for(NSNumber *mode in @[@1,@2,@3]){flags[@"progressBarIndex"]=mode;
[decoration applyGradientForRect:rect];
CHECK(brand.layer.sublayers.count==1);
CAGradientLayer *g=(id)brand.layer.sublayers[0];
CHECK([g.name isEqual:@"ytpGradient"]&&CGRectEqualToRect(g.frame,brand.bounds));
testGradient(g,mode.integerValue==1);
CHECK(brand.layer.masksToBounds);
}
        for(NSNumber *value in @[@NO,@YES]){activeResult=value.boolValue;
reset();
CHECK([decoration isStateActive]==activeResult);
CHECK([events isEqual:@[@"decoration",@"active"]]);
}
        CAGradientLayer *old=(id)brand.layer.sublayers[0];
colorPref(@"progressGradientColor",nil);
flags[@"progressBarIndex"]=@2;
NSArray *oldColors=old.colors;
[decoration applyGradientForRect:rect];
CHECK(old.colors==oldColors);
flags[@"progressBarIndex"]=@3;
BOOL threw=NO;
@try{[decoration applyGradientForRect:rect];
}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];
}CHECK(threw);
colorPref(@"progressGradientColor",@"end");

        colorPref(@"progressMainColor",nil);
reset();
[decoration drawProgressRect:rect withColor:originalColor];
CHECK(lastArgument==originalColor);
oldColors=old.colors;
[decoration applyGradientForRect:rect];
CHECK(old.colors==oldColors);
colorPref(@"progressMainColor",@"main");

    }
    flags[@"progressBarIndex"]=@1;
reset();
[[YTPlayerBarRectangleDecorationView new] applyGradientForRect:CGRectZero];
CHECK([events isEqual:@[@"gradient"]]);
reset();
[[YTPlayerBarProgressDecorationView new] applyGradientForRect:CGRectZero];
CHECK([events isEqual:@[@"gradient",@"decoration"]]);

    PBModular *modular=[PBModular new];
modular.scrubberCircle=[UIView new];
[modular layoutSubviews];
CHECK(colorIs(modular.scrubberCircle.backgroundColor,@"scrubber"));
flags[@"progressBarIndex"]=@0;
modular.scrubberCircle.backgroundColor=originalColor;
[modular layoutSubviews];
CHECK(modular.scrubberCircle.backgroundColor==originalColor);
reset();
[[YTModularPlayerBarView new] layoutSubviews];
CHECK([events isEqual:@[@"layout"]]&&gates.count==0);

    PBProgress *progress=[PBProgress new];
progress.progressBarGradient=[CAGradientLayer layer];
progress.progressBarGradientView=[UIView new];
progress.progressBarGradientView.bounds=CGRectMake(0,0,200,3);

    for(NSNumber *mode in @[@0,@1,@2,@3]){flags[@"progressBarIndex"]=mode;
progress.progressBarGradient.colors=nil;
[progress setProgressBarColor:originalColor];
CHECK(mode.integerValue?colorIs(lastArgument,@"main"):lastArgument==originalColor);
if(mode.integerValue==1||mode.integerValue==2)testPair(progress.progressBarGradient,mode.integerValue);
else CHECK(progress.progressBarGradient.colors==nil);
}
    flags[@"sponsorBlock"]=@YES;
flags[@"sbMiniPlayer"]=@YES;
flags[@"progressBarIndex"]=@0;
reset();
[progress setProgress:0.123456789012345];
CHECK(lastDouble==0.123456789012345);
CHECK([events isEqual:@[@"progress",@"segments"]]&&decoratedPlayer==nil&&decoratedLayer==progress.layer);

    for(UIViewController *mini in @[[PBMini new],[PBFloating new]]){[mini setValue:player forKey:@"playerViewController"];
progress.ancestor=mini;
reset();
[progress setProgress:0.25];
CHECK(decoratedPlayer==player&&decoratedBar==progress);
}
    for(UIViewController *mini in @[[YTWatchMiniBarViewController new],[YTWatchFloatingMiniplayerViewController new]]){progress.ancestor=mini;
reset();
[progress setProgress:0.25];
CHECK([events isEqual:@[@"progress"]]);
}
    flags[@"sbMiniPlayer"]=@NO;
flags[@"progressBarIndex"]=@2;
[progress setProgress:1.234567890123];
CHECK(lastDouble==1.234567890123);
CHECK(progress.progressBarGradientView.layer.sublayers.count==1);
testGradient((id)progress.progressBarGradientView.layer.sublayers[0],NO);
flags[@"progressBarIndex"]=@1;
[progress setProgress:-2];
testGradient((id)progress.progressBarGradientView.layer.sublayers[0],YES);

    progress.superview=[YTVideoThumbnailView new];
NSArray *beforeColors=((CAGradientLayer *)progress.progressBarGradientView.layer.sublayers[0]).colors;
flags[@"progressBarIndex"]=@2;
[progress setProgress:2];
CHECK(((CAGradientLayer *)progress.progressBarGradientView.layer.sublayers[0]).colors==beforeColors);
progress.superview=nil;

    colorPref(@"progressMainColor",nil);
[progress setProgressBarColor:originalColor];
CHECK(lastArgument==originalColor);
colorPref(@"progressMainColor",@"main");
colorPref(@"progressGradientColor",nil);
beforeColors=((CAGradientLayer *)progress.progressBarGradientView.layer.sublayers[0]).colors;
[progress setProgress:3];
CHECK(((CAGradientLayer *)progress.progressBarGradientView.layer.sublayers[0]).colors==beforeColors);
colorPref(@"progressGradientColor",@"end");

    PBMuted *muted=[PBMuted new];
mutedHierarchy(muted,player);
flags[@"sponsorBlock"]=@YES;
flags[@"sbFeedPlayer"]=@YES;
flags[@"progressBarIndex"]=@0;
reset();
[muted setMediaTime:123.123456789123];
CHECK(lastDouble==123.123456789123&&decoratedLayer==muted.playingProgress.layer&&decoratedPlayer==player);
CHECK([events isEqual:@[@"mediaTime",@"segments"]]);

    reset();
[muted addGradient];
CHECK([events isEqual:@[@"addGradient",@"segments"]]);
flags[@"progressBarIndex"]=@1;
reset();
[muted addGradient];
CHECK(events.count==0&&![gates containsObject:@"sponsorBlock"]);

    PBSegmentable *segmentable=[PBSegmentable new];
mutedHierarchy(segmentable,player);
segmentable.playerBar=@"bar";
for(NSNumber *enabled in @[@NO,@YES]){segmentable.enabled=enabled.boolValue;
reset();
[segmentable setMediaTime:-9.123456789];
CHECK(lastDouble==-9.123456789);
CHECK([events isEqual:@[@"mediaTime",@"enabledGetter",@"segmentable"]]);
CHECK(decoratedPlayerBar==segmentable.playerBar&&decoratedPlayer==player);
}
    flags[@"sbFeedPlayer"]=@NO;
reset();
[muted setMediaTime:4];
CHECK([events isEqual:@[@"mediaTime"]]);
flags[@"sbFeedPlayer"]=@YES;
muted.ancestor=[UIViewController new];
reset();
[muted setMediaTime:4];
CHECK([events isEqual:@[@"mediaTime"]]);
mutedHierarchy(muted,player);
muted.ancestor.parentViewController=[UIViewController new];
reset();
[muted setMediaTime:4];
CHECK([events isEqual:@[@"mediaTime"]]);
mutedHierarchy(muted,player);
muted.ancestor.parentViewController.parentResponder=[NSObject new];
reset();
[muted setMediaTime:4];
CHECK([events isEqual:@[@"mediaTime"]]);

    YTInlineMutedPlaybackScrubberView *bare=[YTInlineMutedPlaybackScrubberView new];
mutedHierarchy(muted,player);
bare.ancestor=muted.ancestor;
reset();
[bare setMediaTime:4];
CHECK([events isEqual:@[@"mediaTime"]]);

    muted.progressBarGradient=[CAGradientLayer layer];
for(NSNumber *mode in @[@0,@1,@2,@3]){flags[@"progressBarIndex"]=mode;
muted.progressBarGradient.colors=nil;
reset();
[muted layoutSubviews];
CHECK([events isEqual:@[@"layout"]]);
if(mode.integerValue==1||mode.integerValue==2)testPair(muted.progressBarGradient,mode.integerValue);
else CHECK(muted.progressBarGradient.colors==nil);
}reset();
[bare layoutSubviews];
CHECK([events isEqual:@[@"layout"]]&&gates.count==0);

    YTInlineMutedPlaybackScrubbingSlider *slider=[YTInlineMutedPlaybackScrubbingSlider new];
flags[@"progressBarIndex"]=@0;
CHECK([slider currentMinimumTrackImage]==originalImage);
flags[@"progressBarIndex"]=@1;
UIImage *flat=[slider currentMinimumTrackImage];
CHECK(flat!=originalImage&&colorIs(flat.tint,@"main"));
originalImage=nil;
CHECK([slider currentMinimumTrackImage]==nil);
colorPref(@"progressMainColor",nil);
originalImage=[UIImage new];
CHECK([slider currentMinimumTrackImage]==originalImage);

    // The pass-through hooks preserve the full FP register, including an opaque
    // single-precision payload in its low 32 bits, signed zero and NaN payloads.
    flags[@"sponsorBlock"] = @NO;
    flags[@"progressBarIndex"] = @0;
    const uint64_t payloads[] = {0x3eaaaaabULL, 0x80000000ULL, 0x7fc01234ULL,
        0x8000000000000000ULL, 0x7ff8000000001234ULL, 0x3fd5555555555555ULL};
    for (uint64_t bits : payloads) {
        double value;
        memcpy(&value, &bits, sizeof(value));
        [progress setProgress:value];
        uint64_t received;
        memcpy(&received, &lastDouble, sizeof(received));
        CHECK(received == bits);
        [muted setMediaTime:value];
        memcpy(&received, &lastDouble, sizeof(received));
        CHECK(received == bits);
    }
    [[YTLUserDefaults standardUserDefaults] removePersistentDomainForName:suite];
NSLog(@"PlayerBars: %lu real Logos runtime checks passed",(unsigned long)checks);

}return 0;
}
