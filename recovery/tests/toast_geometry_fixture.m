#import "toast_geometry_doubles.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastManager.h"
#import "../source/Presentation/ToastWindow.h"
#import <objc/runtime.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

static NSUInteger checks, syncCalls;
static BOOL recording;
static NSMutableArray *trace;
static CGRect screenBounds;
#define CHECK(...) do { checks++; if (!(__VA_ARGS__)) { fprintf(stderr,"FAIL %d %s\n",__LINE__,#__VA_ARGS__); exit(1); } } while(0)
static void record(NSString *event) { if(recording)[trace addObject:event]; }
int objc_sync_enter(id object) { (void)object; syncCalls++; return 0; }
int objc_sync_exit(id object) { (void)object; return 0; }

@interface GeometryCollection : NSMutableArray
@property(nonatomic) NSUInteger fixtureCount,fixtureIndex;
@end
@implementation GeometryCollection
- (NSUInteger)count {record(@"count");return _fixtureCount;}
- (NSUInteger)indexOfObject:(id)object {(void)object;record(@"index");return _fixtureIndex;}
@end
static GeometryCollection *collection;
@implementation ToastManager
+ (instancetype)sharedManager {static ToastManager *m;if(!m)m=[self new];record(@"manager");return m;}
- (NSMutableArray *)toasts {record(@"toasts");_toasts=collection;return _toasts;}
@end
@implementation ToastWindow @end
@interface GeometrySource : UIView
@end
@implementation GeometrySource
- (UIEdgeInsets)safeAreaInsets {record(@"safeTop");return [super safeAreaInsets];}
- (CGRect)frame {record(@"frame");return [super frame];}
@end
static CGRect boundsGetter(id object,SEL selector) {(void)object;(void)selector;record(@"screen.bounds");return screenBounds;}

@interface GeometryToast : ToastView
@property(nonatomic) double firstBottom,secondBottom;
@property(nonatomic) NSUInteger bottomReads;
@property(nonatomic) double *outBottom,*outTop,*outScale;
@property(nonatomic) double observedTop;
@property(nonatomic) BOOL mutateGoodHeight;
@end
@implementation GeometryToast
- (instancetype)init {return [super initWithEffect:nil];}
- (void)removeObservers {}
- (double)bottomOffset {
    self.bottomReads++;
    if(self.bottomReads==1) {
        record(@"bottom.first");
        CHECK(*_outBottom==-999&&*_outTop==-999&&*_outScale==-999);
        return _firstBottom;
    }
    record(@"bottom.second");
    CHECK(self.bottomReads==2&&*_outBottom==-999&&*_outScale==1);
    CHECK(*_outTop==_observedTop||(isnan(*_outTop)&&isnan(_observedTop)));
    if(_mutateGoodHeight)_goodHeight=9999;
    return _secondBottom;
}
@end

// Newly compiled native instructions mirror the original scalar FPU operations.
static double goodAdjustment(double value) {
    double answer;
    __asm__ volatile("fmov d1, #-30.0\n\tfadd d1, %d1, d1\n\tfmov d2, xzr\n\tfcmp %d1, #0.0\n\tfcsel %d0, d1, d2, gt"
                     : "=&w"(answer) : "w"(value) : "d1","d2","cc");
    return answer;
}
static BOOL keyboardPositive(double value) {
    unsigned result;
    __asm__ volatile("fcmp %d1, #0.0\n\tcset %w0, gt" : "=r"(result) : "w"(value) : "cc");
    return result;
}
static double add(double a,double b) {double v;__asm__ volatile("fadd %d0, %d1, %d2":"=w"(v):"w"(a),"w"(b));return v;}
static BOOL same(double a,double b) {return (isnan(a)&&isnan(b))||memcmp(&a,&b,sizeof(a))==0;}

static void calculateCase(double keyboard,double good,double safeTop,double width,double first,double second,NSUInteger index,NSUInteger count) {
    recording=NO;
    GeometryToast *toast=[GeometryToast new]; GeometrySource *source=[GeometrySource new];
    source.safeAreaInsets=UIEdgeInsetsMake(safeTop,0,0,0); [toast setValue:source forKey:@"sourceView"];
    [toast setValue:@(good) forKey:@"goodHeight"]; screenBounds=CGRectMake(0,0,width,800);
    collection.fixtureIndex=index;collection.fixtureCount=count;
    double bottom=-999,top=-999,scale=-999;
    toast.firstBottom=first;toast.secondBottom=second;toast.outBottom=&bottom;toast.outTop=&top;toast.outScale=&scale;
    toast.observedTop=add(safeTop,15);toast.mutateGoodHeight=YES;
    [trace removeAllObjects];syncCalls=0;recording=YES;
    [toast calculateToastParametersWithKeyboardHeight:keyboard bottomOffset:&bottom topOffset:&top scale:&scale];
    recording=NO;
    BOOL positive=keyboardPositive(keyboard);
    NSArray *expectedTrace=positive?@[@"safeTop",@"manager",@"toasts",@"index",@"count",@"screen.bounds",@"bottom.first"]:
        @[@"safeTop",@"manager",@"toasts",@"index",@"count",@"screen.bounds",@"bottom.first",@"bottom.second"];
    CHECK([trace isEqual:expectedTrace]);CHECK(syncCalls==0);
    double expectedBottom=positive?add(add(good,keyboard),15):add(add((width!=375&&first==0)?30:0,add(second,goodAdjustment(good))),15);
    double expectedTop=add(safeTop,15),expectedScale=1;
    BOOL addsOffset=NO;double offset=0;
    if(count!=1) {
        if(index==count-1) {if(count==2){offset=5;addsOffset=YES;}else if(count>2){offset=10;addsOffset=YES;}}
        else if(index==count-2){expectedScale=0.95;offset=count==2?0:5;addsOffset=YES;}
        else expectedScale=0.9;
    }
    if(addsOffset){expectedBottom=add(expectedBottom,offset);expectedTop=add(expectedTop,offset);}
    CHECK(same(bottom,expectedBottom));CHECK(same(top,expectedTop));CHECK(same(scale,expectedScale));
    CHECK(toast.bottomReads==(positive?1:2));
}

@interface LayoutToast : ToastView
@property(nonatomic) BOOL landscape;
@property(nonatomic) NSUInteger calculations,configures;
@property(nonatomic) double width;
@end
@implementation LayoutToast
- (instancetype)init {return [super initWithEffect:nil];}
- (void)removeObservers {}
- (BOOL)isLandscape {record(@"landscape");_isiPad=!_isiPad;return _landscape;}
- (void)calculateToastParametersWithKeyboardHeight:(double)keyboard bottomOffset:(double*)bottom topOffset:(double*)top scale:(double*)scale {
    record(@"calculate");self.calculations++;CHECK(keyboard==216);
    _sourceView.frame=CGRectMake(0,0,9999,8888);*bottom=11;*top=22;*scale=0.9;
}
- (void)configureToastAppearanceWithBottomOffset:(double)bottom topOffset:(double)top scale:(double)scale width:(double)width animationDuration:(double)duration {
    record(@"configure");self.configures++;self.width=width;CHECK(bottom==11&&top==22&&scale==0.9&&duration==0.5);
}
@end
static void layoutCases(void) {
    for(NSUInteger pad=0;pad<2;pad++)for(NSUInteger landscape=0;landscape<2;landscape++) {
        recording=NO;LayoutToast *toast=[LayoutToast new];GeometrySource *source=[GeometrySource new];
        source.frame=CGRectMake(0,0,400,800);[toast setValue:source forKey:@"sourceView"];
        [toast setValue:@(pad) forKey:@"isiPad"];[toast setValue:@216 forKey:@"keyboardHeight"];toast.landscape=landscape;
        [trace removeAllObjects];recording=YES;[toast updateLayout];recording=NO;
        CHECK([trace isEqual:@[@"frame",@"landscape",@"calculate",@"configure"]]);
        CHECK(toast.calculations==1&&toast.configures==1);
        CHECK(toast.width==400*(pad?(landscape?0.3:0.5):(landscape?0.5:0.95)));
    }
    LayoutToast *missing=[LayoutToast new];[trace removeAllObjects];recording=YES;[missing updateLayout];recording=NO;
    CHECK(trace.count==0&&missing.calculations==0&&missing.configures==0);
}

int main(void) {@autoreleasepool {
    PresentationInitialize();trace=[NSMutableArray new];collection=[GeometryCollection new];
    Method method=class_getInstanceMethod(UIScreen.class,@selector(bounds));method_setImplementation(method,(IMP)boundsGetter);
    calculateCase(0,45,44,390,0,7,0,1);
    for(NSUInteger count=0;count<=5;count++)for(NSUInteger index=0;index<=6;index++)
        calculateCase(0,45,44,390,0,7,index,count);
    for(NSNumber *index in @[@(NSNotFound),@(NSUIntegerMax),@(NSUIntegerMax-1)])
        calculateCase(0,45,44,390,0,7,index.unsignedIntegerValue,0);
    NSArray *numbers=@[@0,@(-0.0),@(-1),@1,@15,@30,@45,@(DBL_MIN),@(DBL_MAX),@(INFINITY),@(-INFINITY),@(NAN)];
    for(NSNumber *keyboard in numbers)for(NSNumber *good in numbers)
        calculateCase(keyboard.doubleValue,good.doubleValue,44,390,0,7,1,3);
    for(NSNumber *width in @[@375,@390,@(NAN)])for(NSNumber *first in numbers)for(NSNumber *second in numbers)
        calculateCase(0,45,44,width.doubleValue,first.doubleValue,second.doubleValue,0,1);
    calculateCase(0,0x1p60,44,390,0,-0x1p60,0,1);
    calculateCase(NAN,NAN,NAN,NAN,0,0,NSNotFound,0);
    layoutCases();
    printf("Toast geometry actual source: %lu checks passed\n",(unsigned long)checks);
}return 0;}
