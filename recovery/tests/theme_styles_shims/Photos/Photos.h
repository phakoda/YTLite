#import <Foundation/Foundation.h>
@class UIImage;
@interface PHPhotoLibrary : NSObject
+ (instancetype)sharedPhotoLibrary;
- (void)performChanges:(void (^)(void))changes completionHandler:(void (^)(BOOL,NSError *))completion;
@end
@interface PHAssetCreationRequest : NSObject
@property(nonatomic,strong) NSDate *creationDate;
+ (instancetype)creationRequestForAssetFromImage:(UIImage *)image;
@end
