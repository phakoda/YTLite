#import "presentation_test_support.h"
#import "../source/Helpers/YTLHelper.h"

// Synthetic Objective-C URL/string boundaries expose independent getter results.
// They are never passed to a real URL session.
@interface HelperImageStringProbe : NSObject
@property(nonatomic,strong) NSMutableArray *trace;
@property(nonatomic) BOOL containsCrop, missingRange;
- (BOOL)containsString:(NSString *)value;
- (NSRange)rangeOfString:(NSString *)value;
- (NSString *)substringFromIndex:(NSUInteger)index;
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)old withString:(NSString *)replacement;
@end
@implementation HelperImageStringProbe
- (BOOL)containsString:(NSString *)value {
    [self.trace addObject:@"contains"];PEqual(value,@"c-fcrop",@"original crop marker");return self.containsCrop;
}
- (NSRange)rangeOfString:(NSString *)value {
    [self.trace addObject:@"range"];PEqual(value,@"c-fcrop",@"range uses same crop marker");
    return NSMakeRange(self.missingRange?NSNotFound:5,7);
}
- (NSString *)substringFromIndex:(NSUInteger)index {
    [self.trace addObject:@"suffix"];PCheck(index==5,@"crop suffix uses original range index");return @"original-suffix";
}
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)old withString:(NSString *)replacement {
    [self.trace addObject:@"replace"];
    PEqual(old,@"original-suffix",@"replacement uses extracted suffix");
    PEqual(replacement,@"nd-v1",@"original uncropped suffix");return @"https://fixture.invalid/nd-v1";
}
@end
@interface HelperImageURLProbe : NSObject
@property(nonatomic,strong) HelperImageStringProbe *string;
- (NSString *)absoluteString;
@end
@implementation HelperImageURLProbe
- (NSString *)absoluteString { [self.string.trace addObject:@"absolute"];return (id)self.string; }
@end

static NSString *ImageFeedback(void) {
    return [PGet(ToastManager.sharedManager.toasts.lastObject,@"_toastLabel") text];
}
void PRunHelperImage(void) {
    NSUInteger start=PresentationAssertions;
    HelperImageURLProbe *probe=[HelperImageURLProbe new];
    probe.string=[HelperImageStringProbe new];probe.string.trace=[NSMutableArray new];
    [YTLHelper downloadImageFromURL:(id)probe download:NO];
    PCheck((id)PresentationLastNetworkTask.fixtureURL==probe,@"uncropped URL preserves object identity");
    PEqual(probe.string.trace,(@[@"absolute",@"contains"]),@"uncropped path skips range lookup");
    PCheck(PresentationLastNetworkTask.fixtureResumed,@"uncropped image task resumes");
    [probe.string.trace removeAllObjects];probe.string.containsCrop=YES;probe.string.missingRange=YES;
    [YTLHelper downloadImageFromURL:(id)probe download:YES];
    PCheck(PresentationLastNetworkTask.fixtureURL==nil&&PresentationLastNetworkTask.fixtureResumed,
           @"missing range after contains sends nil URL to session boundary");
    PEqual(probe.string.trace,(@[@"absolute",@"contains",@"range"]),@"missing range skips substring and replacement");
    [probe.string.trace removeAllObjects];probe.string.missingRange=NO;
    [YTLHelper downloadImageFromURL:(id)probe download:YES];
    PEqual(probe.string.trace,(@[@"absolute",@"contains",@"range",@"suffix",@"replace"]),@"cropped path preserves selector order");
    PEqual(PresentationLastNetworkTask.fixtureURL.absoluteString,@"https://fixture.invalid/nd-v1",@"rewritten URL reaches session");
    PClearToasts();NSUInteger queued=PresentationMainQueue.count;
    [YTLHelper downloadImageFromURL:nil download:YES];
    PCheck(PresentationLastNetworkTask.fixtureURL==nil&&PresentationLastNetworkTask.fixtureResumed,@"nil input still reaches session and resume");
    PCheck(PresentationMainQueue.count==queued&&ToastManager.sharedManager.toasts.count==0,@"nil input adds no early error feedback");

    NSURL *url=[NSURL URLWithString:@"https://fixture.invalid/image"];
    NSError *error=[NSError errorWithDomain:@"fixture.image" code:1 userInfo:@{NSLocalizedDescriptionKey:@"fixture failure"}];
    NSData *bytes=[@"synthetic image bytes" dataUsingEncoding:NSUTF8StringEncoding];
    [YTLHelper downloadImageFromURL:url download:NO];
    queued=PresentationMainQueue.count;
    PresentationLastNetworkTask.fixtureCompletion(bytes,nil,error);
    PCheck(PresentationMainQueue.count==queued+1,@"data takes precedence over simultaneous transport error");
    PSettle();PEqual(UIPasteboard.generalPasteboard.image.fixtureData,bytes,@"data is copied even when error is nonnil");
    PEqual(ImageFeedback(),@"Copied",@"copy branch reports success");PClearToasts();
    [YTLHelper downloadImageFromURL:url download:NO];
    PresentationLastNetworkTask.fixtureCompletion([NSData data],nil,nil);PSettle();
    PCheck(UIPasteboard.generalPasteboard.image.fixtureData.length==0,@"empty nonnil data follows copy branch");
    PEqual(ImageFeedback(),@"Copied",@"empty data does not become a transport error");PClearToasts();
    [YTLHelper downloadImageFromURL:url download:YES];
    PresentationLastNetworkTask.fixtureCompletion(nil,nil,nil);PSettle();
    PEqual(ImageFeedback(),@"Error: (null)",@"nil data and nil error preserve original formatting");PClearToasts();
    [YTLHelper downloadImageFromURL:url download:YES];
    queued=PresentationMainQueue.count;
    PresentationLastNetworkTask.fixtureCompletion(bytes,nil,error);
    PCheck(PresentationPhotoChanges.count==1&&PresentationMainQueue.count==queued,@"download data starts Photos without a main-queue hop");
    NSDictionary *transaction=PresentationPhotoChanges.firstObject;
    dispatch_block_t changes=transaction[@"changes"];changes();
    PEqual(PLast(@"photos.resource")[@"data"],bytes,@"Photos receives original raw data");
    void (^completion)(BOOL,NSError *)=transaction[@"completion"];
    completion(NO,nil);
    PCheck(PresentationMainQueue.count==queued+1,@"Photos completion queues feedback");
    PSettle();PEqual(ImageFeedback(),@"Error: (null)",@"Photos nil error preserves localized formatting");
    [PresentationPhotoChanges removeAllObjects];PresentationLastNetworkTask=nil;PClearToasts();
    fprintf(stdout,"PASS Helper_image_fidelity: %lu assertions\n",(unsigned long)(PresentationAssertions-start));
}
