#pragma once
#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger,PHAssetResourceType) { PHAssetResourceTypePhoto=1,PHAssetResourceTypeVideo=2 };
@interface PHAssetResourceCreationOptions : NSObject @end
@interface PHAssetCreationRequest : NSObject
+ (instancetype)creationRequestForAsset;
- (void)addResourceWithType:(PHAssetResourceType)type fileURL:(NSURL *)url options:(PHAssetResourceCreationOptions *)options;
- (void)addResourceWithType:(PHAssetResourceType)type data:(NSData *)data options:(PHAssetResourceCreationOptions *)options;
@end
@interface PHPhotoLibrary : NSObject
+ (instancetype)sharedPhotoLibrary;
- (void)performChanges:(dispatch_block_t)changes completionHandler:(void (^)(BOOL,NSError *))completion;
@end
