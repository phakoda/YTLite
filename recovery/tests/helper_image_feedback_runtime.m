#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <Photos/Photos.h>
#import <objc/runtime.h>

static NSMutableArray *imageFlowEvents;
static NSArray<NSBundle *> *imageFlowBundles;
static NSUInteger imageFlowBundleReads;
static NSString *imageFlowText;
static BOOL imageFlowSuccess, imageFlowNilRequest;
static __weak NSData *imageFlowData;
static PHAssetCreationRequest *imageFlowRequest;
@interface HelperImageFeedbackError : NSError
@property(copy) NSString *fixtureDescription;
@end
static __weak HelperImageFeedbackError *imageFlowError;
@implementation HelperImageFeedbackError
- (NSString *)localizedDescription {
    PCheck(self==imageFlowError,@"image feedback reads the captured error object");
    [imageFlowEvents addObject:@"description"];return self.fixtureDescription;
}
@end
static id ImageFlowBundle(id receiver,SEL selector) {
    (void)receiver;(void)selector;[imageFlowEvents addObject:@"bundle"];
    PCheck(imageFlowBundleReads<2,@"image feedback makes only the original bundle lookups");
    return imageFlowBundles[imageFlowBundleReads++];
}
static id ImageFlowLocalized(id receiver,SEL selector,NSString *key,NSString *value,NSString *table) {
    (void)selector;[imageFlowEvents addObject:key];
    PCheck(receiver==imageFlowBundles[imageFlowBundleReads-1] && value==nil && table==nil,
        @"each localization uses its independently obtained bundle and nil defaults");
    if([key isEqual:@"%@: %@"])return @"%2$@ | %1$@";
    if([key isEqual:@"Error"]) {
        imageFlowError.fixtureDescription=@"AFTER PREFIX";
        return @"PREFIX";
    }
    PEqual(key,@"Saved",@"successful image import localizes only Saved");return @"DONE";
}
static void ImageFlowToast(id receiver,SEL selector,NSString *text,BOOL success) {
    (void)receiver;(void)selector;[imageFlowEvents addObject:@"toast"];
    imageFlowText=text;imageFlowSuccess=success;
}
static id ImageFlowRequest(id receiver,SEL selector) {
    (void)receiver;(void)selector;[imageFlowEvents addObject:@"request"];
    return imageFlowNilRequest ? nil : imageFlowRequest;
}
static void ImageFlowResource(id receiver,SEL selector,PHAssetResourceType type,NSData *data,PHAssetResourceCreationOptions *options) {
    (void)selector;[imageFlowEvents addObject:@"resource"];
    PCheck(receiver==imageFlowRequest && type==1 && data==imageFlowData && options==nil,
        @"image import forwards photo resource type, original raw data identity and nil options");
}
static void ResetImageFlow(void) {
    [imageFlowEvents removeAllObjects];imageFlowBundleReads=0;imageFlowText=nil;imageFlowSuccess=NO;
}
static HelperImageFeedbackError *ImageFlowMakeError(void) {
    HelperImageFeedbackError *error=[[HelperImageFeedbackError alloc] initWithDomain:@"fixture.image.feedback" code:9 userInfo:nil];
    error.fixtureDescription=@"BEFORE PREFIX";imageFlowError=error;return error;
}

static void TestImageNetworkFeedback(NSURL *url) {
    for(NSUInteger download=0;download<2;download++)for(NSUInteger nilError=0;nilError<2;nilError++) {
        ResetImageFlow();__weak NSError *weakError;
        NSUInteger queued=PresentationMainQueue.count;
        @autoreleasepool {
            HelperImageFeedbackError *error=nilError ? nil : ImageFlowMakeError();weakError=error;
            [YTLHelper downloadImageFromURL:url download:download!=0];
            PresentationLastNetworkTask.fixtureCompletion(nil,nil,error);
            PresentationLastNetworkTask=nil;
        }
        PCheck(imageFlowEvents.count==0 && PresentationMainQueue.count==queued+1,@"network failure defers localization and error description to one main callback");
        PCheck(nilError || weakError!=nil,@"queued network failure retains its error after the task is released");
        PSettle();
        PEqual(imageFlowEvents,nilError ? @[@"bundle",@"Error",@"toast"] : @[@"bundle",@"Error",@"description",@"toast"],
            @"network failure localizes the prefix but keeps the literal format string");
        PEqual(imageFlowText,nilError ? @"PREFIX: (null)" : @"PREFIX: AFTER PREFIX",@"network feedback reads description after prefix localization");
        PCheck(!imageFlowSuccess && weakError==nil,@"network failure reports false and releases its captured error after feedback");
    }
}

static void TestImagePhotosFeedback(NSURL *url) {
    for(NSUInteger mode=0;mode<10;mode++) {
        BOOL success=(mode&1)!=0;
        BOOL nilError=(mode&2)!=0;
        imageFlowNilRequest=mode>=8;
        ResetImageFlow();NSUInteger queued=PresentationMainQueue.count;
        void (^completion)(BOOL,NSError *);
        __weak NSData *weakData;
        @autoreleasepool {
            // Mutable data gives even the empty case an independently owned object.
            NSMutableData *data=[NSMutableData new];
            if(mode<4 || mode>=8)[data appendData:[@"synthetic image payload" dataUsingEncoding:NSUTF8StringEncoding]];
            weakData=data;imageFlowData=data;
            [YTLHelper downloadImageFromURL:url download:YES];
            PresentationLastNetworkTask.fixtureCompletion(data,nil,nil);
            PresentationLastNetworkTask=nil;
            PCheck(PresentationPhotoChanges.count==1 && PresentationMainQueue.count==queued,
                @"nonnil image data starts Photos immediately, including zero-length data");
            completion=[PresentationPhotoChanges[0][@"completion"] copy];
        }
        PCheck(weakData!=nil,@"Photos changes own raw data after transport callback and input owner are released");
        @autoreleasepool {
            dispatch_block_t changes=PresentationPhotoChanges[0][@"changes"];changes();
            [PresentationPhotoChanges removeAllObjects];
        }
        PEqual(imageFlowEvents,imageFlowNilRequest ? @[@"request"] : @[@"request",@"resource"],
            @"image changes forward the original creation-request result without a nil fallback");
        PCheck(weakData==nil,@"image Photos completion does not retain input data after changes are released");
        ResetImageFlow();__weak NSError *weakError;
        @autoreleasepool {
            HelperImageFeedbackError *error=nilError ? nil : ImageFlowMakeError();weakError=error;
            completion(success,error);completion=nil;
        }
        PCheck(imageFlowEvents.count==0 && PresentationMainQueue.count==queued+1,@"Photos feedback is always queued before localization");
        PCheck(nilError || weakError!=nil,@"queued Photos feedback retains the supplied error even on success");
        PSettle();
        NSMutableArray *order=[NSMutableArray arrayWithArray:success ? @[@"bundle",@"Saved"] : @[@"bundle",@"%@: %@",@"bundle",@"Error"]];
        if(!success && !nilError)[order addObject:@"description"];
        [order addObject:@"toast"];
        PEqual(imageFlowEvents,order,@"Photos failure localizes format and prefix separately before reading the error; success skips error access");
        PEqual(imageFlowText,success ? @"DONE" : nilError ? @"(null) | PREFIX" : @"AFTER PREFIX | PREFIX",
            @"Photos uses the localized positional format and latest error description");
        PCheck(imageFlowSuccess==success && weakError==nil,@"Photos forwards the completion success flag and releases error ownership after feedback");
    }
}

void PRunHelperImageFeedback(void) {
    NSUInteger before=PresentationAssertions;PSettle();
    imageFlowEvents=[NSMutableArray new];imageFlowBundles=@[[NSBundle new],[NSBundle new]];
    imageFlowRequest=[PHAssetCreationRequest new];
    NSURL *url=[NSURL URLWithString:@"https://fixture.invalid/image-feedback"];
    Method bundle=class_getClassMethod(NSBundle.class,NSSelectorFromString(@"ytl_defaultBundle"));
    Method localized=class_getInstanceMethod(NSBundle.class,@selector(localizedStringForKey:value:table:));
    Method toast=class_getClassMethod(ToastManager.class,@selector(showMessageWithText:isSuccess:));
    Method request=class_getClassMethod(PHAssetCreationRequest.class,@selector(creationRequestForAsset));
    Method resource=class_getInstanceMethod(PHAssetCreationRequest.class,@selector(addResourceWithType:data:options:));
    IMP oldBundle=method_setImplementation(bundle,(IMP)ImageFlowBundle);
    IMP oldLocalized=method_setImplementation(localized,(IMP)ImageFlowLocalized);
    IMP oldToast=method_setImplementation(toast,(IMP)ImageFlowToast);
    IMP oldRequest=method_setImplementation(request,(IMP)ImageFlowRequest);
    IMP oldResource=method_setImplementation(resource,(IMP)ImageFlowResource);
    @try { TestImageNetworkFeedback(url);TestImagePhotosFeedback(url); }
    @finally {
        method_setImplementation(bundle,oldBundle);method_setImplementation(localized,oldLocalized);
        method_setImplementation(toast,oldToast);method_setImplementation(request,oldRequest);method_setImplementation(resource,oldResource);
        imageFlowBundles=nil;imageFlowEvents=nil;imageFlowText=nil;imageFlowRequest=nil;imageFlowData=nil;imageFlowError=nil;
    }
    printf("PASS Helper_first_package_imageflow: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
