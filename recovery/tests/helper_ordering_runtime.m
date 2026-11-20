#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"
#import <objc/runtime.h>

static NSMutableArray *orderingEvents;
static YTLHelper *orderingHelper;
static id orderingTarget,orderingReplacement;
static NSUInteger mutationBoundary;
static IMP orderingOldBundle,orderingOldLocalization;
@interface HelperOrderingToast : NSObject
@property(copy) NSString *text;
@end
@implementation HelperOrderingToast
- (void)updateText:(NSString *)text progress:(float)progress {
    orderingTarget=self;self.text=text;[orderingEvents addObject:@"update"];
    PCheck(progress==0.25f,@"progress receiver gets original float");
}
@end
static void MutateProgressState(void) {
    PSet(orderingHelper,@"_toastView",orderingReplacement);
    PSet(orderingHelper,@"_isVideoDownloaded",@(![PGet(orderingHelper,@"_isVideoDownloaded") boolValue]));
}
static id OrderingBundle(id receiver,SEL selector) {
    [orderingEvents addObject:@"bundle"];
    if(mutationBoundary==0)MutateProgressState();
    return ((id(*)(id,SEL))orderingOldBundle)(receiver,selector);
}
static id OrderingLocalized(id receiver,SEL selector,NSString *key,NSString *value,NSString *table) {
    [orderingEvents addObject:@"localized"];
    if(mutationBoundary==1)MutateProgressState();
    return ((id(*)(id,SEL,id,id,id))orderingOldLocalization)(receiver,selector,key,value,table);
}

static UIImage *orderingImage;
static NSData *orderingData;
static UIPasteboard *orderingBoard;
static IMP orderingOldSetImage;
static id OrderingDecode(id receiver,SEL selector,NSData *data) {
    (void)receiver;(void)selector;[orderingEvents addObject:@"decode"];
    PCheck(data==orderingData,@"copy decodes the captured data object");return orderingImage;
}
static id OrderingPasteboard(id receiver,SEL selector) {
    (void)receiver;(void)selector;[orderingEvents addObject:@"pasteboard"];return orderingBoard;
}
static void OrderingSetImage(id receiver,SEL selector,UIImage *image) {
    [orderingEvents addObject:@"set-image"];
    PCheck(receiver==orderingBoard && image==orderingImage,@"copy forwards image-factory result unchanged, including nil");
    ((void(*)(id,SEL,id))orderingOldSetImage)(receiver,selector,image);
}
static void OrderingCopied(id receiver,SEL selector,NSString *text,BOOL success) {
    (void)receiver;(void)selector;[orderingEvents addObject:@"toast"];
    PCheck([text isEqual:@"Copied"] && success,@"copy reports success after pasteboard assignment");
}

void PRunHelperOrdering(void) {
    NSUInteger before=PresentationAssertions;
    orderingHelper=[YTLHelper new];orderingEvents=[NSMutableArray new];
    Method bundle=class_getClassMethod(NSBundle.class,NSSelectorFromString(@"ytl_defaultBundle"));
    Method localize=class_getInstanceMethod(NSBundle.class,@selector(localizedStringForKey:value:table:));
    orderingOldBundle=method_setImplementation(bundle,(IMP)OrderingBundle);
    orderingOldLocalization=method_setImplementation(localize,(IMP)OrderingLocalized);
    @try {
        for(mutationBoundary=0;mutationBoundary<2;mutationBoundary++)
            for(NSUInteger phase=0;phase<2;phase++)
                for(NSUInteger nilReceiver=0;nilReceiver<2;nilReceiver++) {
                    HelperOrderingToast *original=nilReceiver ? nil : [HelperOrderingToast new];
                    HelperOrderingToast *replacement=[HelperOrderingToast new];orderingReplacement=replacement;
                    orderingTarget=nil;[orderingEvents removeAllObjects];
                    PSet(orderingHelper,@"_toastView",original);PSet(orderingHelper,@"_isVideoDownloaded",@(phase));
                    [orderingHelper downloadProgress:0.25f];
                    PCheck(orderingTarget==original,@"progress uses receiver read before bundle and localization");
                    PCheck(replacement.text==nil,@"progress never redirects to replacement toast");
                    PEqual(orderingEvents,nilReceiver ? @[@"bundle",@"localized"] : @[@"bundle",@"localized",@"update"],@"progress evaluates text even when original receiver is nil");
                    if(original)PEqual(original.text,phase ? @"DownloadingAudio: 25%" : @"DownloadingVideo: 25%",@"progress formats phase read before bundle lookup");
                }
    } @finally {
        method_setImplementation(bundle,orderingOldBundle);method_setImplementation(localize,orderingOldLocalization);
        orderingHelper=nil;orderingReplacement=nil;orderingTarget=nil;
    }

    Method decode=class_getClassMethod(UIImage.class,@selector(imageWithData:));
    Method pasteboard=class_getClassMethod(UIPasteboard.class,@selector(generalPasteboard));
    Method setImage=class_getInstanceMethod(UIPasteboard.class,@selector(setImage:));
    Method copied=class_getClassMethod(ToastManager.class,@selector(showMessageWithText:isSuccess:));
    IMP oldDecode=method_setImplementation(decode,(IMP)OrderingDecode);
    IMP oldPasteboard=method_setImplementation(pasteboard,(IMP)OrderingPasteboard);
    orderingOldSetImage=method_setImplementation(setImage,(IMP)OrderingSetImage);
    IMP oldCopied=method_setImplementation(copied,(IMP)OrderingCopied);
    @try {
        orderingData=[@"synthetic image data" dataUsingEncoding:NSUTF8StringEncoding];
        for(NSUInteger nilImage=0;nilImage<2;nilImage++) {
            orderingImage=nilImage ? nil : [UIImage new];orderingBoard=[UIPasteboard new];
            [orderingEvents removeAllObjects];
            [YTLHelper downloadImageFromURL:[NSURL URLWithString:@"https://fixture.invalid/copy"] download:NO];
            NSUInteger pending=PresentationMainQueue.count;
            PresentationLastNetworkTask.fixtureCompletion(orderingData,nil,nil);
            PCheck(PresentationMainQueue.count==pending+1 && orderingEvents.count==0,@"copy queues image decode and assignment together");
            PSettle();
            PEqual(orderingEvents,(@[@"decode",@"pasteboard",@"set-image",@"toast"]),@"copy decodes before looking up pasteboard and reports success afterward");
            PCheck(orderingBoard.image==orderingImage,@"synthetic pasteboard stores original image result");
        }
    } @finally {
        method_setImplementation(decode,oldDecode);method_setImplementation(pasteboard,oldPasteboard);
        method_setImplementation(setImage,orderingOldSetImage);method_setImplementation(copied,oldCopied);
        orderingData=nil;orderingImage=nil;orderingBoard=nil;orderingEvents=nil;PresentationLastNetworkTask=nil;
    }
    printf("PASS Helper_first_package_ordering: %lu assertions\n",(unsigned long)(PresentationAssertions-before));
}
