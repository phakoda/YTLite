#pragma once
#import <UIKit/UIKit.h>

@interface DVNImageViewController : UIViewController <UIScrollViewDelegate> {
    UIScrollView *_scrollView;
    UIImageView *_imageView;
    UIImage *_fullImage;
}
@property(nonatomic, strong) UIImage *fullImage;
- (void)viewDidLoad;
- (void)setupNavbar;
- (void)setupViewer;
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView;
- (void)viewDidLayoutSubviews;
- (void)handleDoubleTap:(UITapGestureRecognizer *)recognizer;
- (void)scrollViewDidZoom:(UIScrollView *)scrollView;
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(CGFloat)scale;
- (void)scrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(UIView *)view;
- (void)adjustScrollViewInsets;
- (void)adjustHorizontalInsetsWithImageWidth:(double)width;
- (void)adjustVerticalInsetsWithImageHeight:(double)height;
- (void)hapticFeedback;
- (void)closeButtonTapped;
- (void)share;
@end
