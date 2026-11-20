#pragma once
#import <UIKit/UIKit.h>
#import <PhotosUI/PhotosUI.h>

@interface DVNMediaPicker : NSObject <PHPickerViewControllerDelegate, UIDocumentPickerDelegate> {
    UIViewController *_viewController;
}
+ (instancetype)sharedPicker;
- (void)presentImagePickerForVC:(UIViewController *)controller;
- (void)picker:(PHPickerViewController *)picker didFinishPicking:(NSArray<PHPickerResult *> *)results;
- (void)presentFilePickerForVC:(UIViewController *)controller isMultipleSelection:(BOOL)multiple;
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls;
- (NSURL *)tempCopyOfURL:(NSURL *)url;
- (void)prepareMediaForUse:(NSURL *)url;
- (void)prepareURLsForImport:(NSArray<NSURL *> *)urls;
@end
