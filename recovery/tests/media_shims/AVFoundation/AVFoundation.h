#pragma once
#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
@interface AVAsset : NSObject
+ (instancetype)assetWithURL:(NSURL *)url;
@property(nonatomic) CMTime duration;
@end
