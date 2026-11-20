#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <objc/runtime.h>

static CGSize helperRendererRequestedSize;
static NSUInteger helperRendererCalls;
static UIImage *HelperRendererBoundary(id receiver, SEL selector, id actions) {
    (void)selector;(void)actions;
    helperRendererCalls++;
    helperRendererRequestedSize=[receiver fixtureSize];
    // No callback or bitmap allocation here. Invalid dimensions are observed at
    // the synthetic renderer boundary, without claiming UIKit accepts them.
    return [UIImage new];
}

@interface HelperFrameProbe : CALayer
@property(nonatomic) NSUInteger frameReads, renderCalls;
@property(nonatomic) BOOL fillMatches;
@end
@implementation HelperFrameProbe
- (CGRect)frame {
    self.frameReads++;
    if(self.frameReads==1)return CGRectMake(1,2,32,16);
    if(self.frameReads==2)return CGRectMake(3,4,7,8);
    return CGRectMake(5,6,9,10);
}
- (void)renderInContext:(CGContextRef)context {
    self.renderCalls++;
    unsigned char *pixels=CGBitmapContextGetData(context);
    size_t row=CGBitmapContextGetBytesPerRow(context);
    // CGBitmap memory rows run opposite the context's default y coordinates.
    // A standalone 32x16 / 7x10 Core Graphics probe verified this mapping.
    BOOL matches=YES;
    for(NSUInteger y=0;y<16;y++)for(NSUInteger x=0;x<32;x++) {
        BOOL filled=pixels[y*row+x*4+3]!=0;
        if(filled != (x<7 && y>=6))matches=NO;
    }
    self.fillMatches=matches;
}
@end

void PRunHelperRendering(void) {
    NSUInteger start=PresentationAssertions;
    YTLHelper *helper=[YTLHelper new];PSettle();
    Method renderer=class_getInstanceMethod(UIGraphicsImageRenderer.class,@selector(imageWithActions:));
    IMP original=method_setImplementation(renderer,(IMP)HelperRendererBoundary);
    double values[]={0,-1,NAN,INFINITY,-INFINITY,23.5};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(values[0]);i++) {
        for(NSNumber *instance in @[@NO,@YES]) {
            helperRendererCalls=0;
            UIImage *image=instance.boolValue ? [helper resizeImage:nil toSize:values[i]] :
                [YTLHelper resizeImage:nil toSize:values[i]];
            PCheck(image!=nil&&helperRendererCalls==1,@"resize forwards every size to renderer boundary");
            PCheck((isnan(values[i])&&isnan(helperRendererRequestedSize.width)&&isnan(helperRendererRequestedSize.height)) ||
                (helperRendererRequestedSize.width==values[i]&&helperRendererRequestedSize.height==values[i]),
                @"resize preserves original requested dimensions");
        }
    }
    method_setImplementation(renderer,original);
    HelperFrameProbe *layer=[HelperFrameProbe new];
    __block BOOL called=NO;
    [YTLHelper genImageFromLayer:layer backgroundColor:UIColor.whiteColor completionHandler:^(UIImage *image){
        called=YES;
        PCheck(layer.renderCalls==1,@"layer callback follows render");
        PCheck(layer.frameReads==3,@"layer rendering reads frame three times");
        PCheck(layer.fillMatches,@"fill rectangle uses second width and third height");
        PNear(image.size.width,32,@"layer context uses first width");
        PNear(image.size.height,16,@"layer context uses first height");
    }];
    PCheck(called,@"layer completion remains synchronous");
    layer.frameReads=0;layer.renderCalls=0;
    [YTLHelper genImageFromLayer:layer backgroundColor:UIColor.whiteColor completionHandler:nil];
    PCheck(layer.frameReads==3&&layer.renderCalls==1,@"nil completion still renders");
    fprintf(stdout,"PASS Helper_rendering_fidelity: %lu assertions\n",(unsigned long)(PresentationAssertions-start));
}
