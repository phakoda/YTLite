#pragma once
#import <UIKit/UIKit.h>
@class PHPickerViewController, PHPickerResult;
@protocol PHPickerViewControllerDelegate <NSObject>
- (void)picker:(PHPickerViewController *)picker didFinishPicking:(NSArray<PHPickerResult *> *)results;
@end
@interface PHPickerFilter : NSObject
+ (instancetype)videosFilter;
@end
@interface PHPickerConfiguration : NSObject
@property(nonatomic) NSInteger selectionLimit;
@property(nonatomic, strong) PHPickerFilter *filter;
@end
@interface PHPickerViewController : UIViewController
@property(nonatomic, weak) id<PHPickerViewControllerDelegate> delegate;
@property(nonatomic, strong) PHPickerConfiguration *configuration;
- (instancetype)initWithConfiguration:(PHPickerConfiguration *)configuration;
@end
@interface PHPickerResult : NSObject
@property(nonatomic, strong) NSItemProvider *itemProvider;
@end
