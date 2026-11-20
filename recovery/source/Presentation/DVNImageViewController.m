#import "DVNImageViewController.h"
#import "BlurButton.h"
#import "PresentationGeometry.h"
#import "PresentationHost.h"

@implementation DVNImageViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupNavbar];
    [self setupViewer];
}
- (void)setupNavbar {
    self.navigationController.navigationBar.translucent = YES;
    [self.navigationController.navigationBar setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
    self.navigationController.navigationBar.shadowImage = [UIImage new];
    UIBarButtonItem *left = [UIBarButtonItem alloc];
    // The packaged action has a colon, although the class method below does not.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wundeclared-selector"
    BlurButton *close = [BlurButton createButtonWithImage:[UIImage systemImageNamed:@"xmark"]
        target:self action:@selector(closeButtonTapped:) menu:nil];
#pragma clang diagnostic pop
    left = [left initWithCustomView:close];
    UIAction *copy = [UIAction actionWithTitle:YTLPresentationLocalized(@"Copy")
        image:[UIImage systemImageNamed:@"doc.on.doc"] identifier:nil handler:^(UIAction *action) {
            (void)action;
            [self hapticFeedback];
            UIImage *image = self.fullImage;
            UIPasteboard.generalPasteboard.image = image;
        }];
    UIAction *share = [UIAction actionWithTitle:YTLPresentationLocalized(@"Share")
        image:[UIImage systemImageNamed:@"square.and.arrow.up"] identifier:nil handler:^(UIAction *action) {
            (void)action;
            [self hapticFeedback];
            [self share];
        }];
    UIAction *save = [UIAction actionWithTitle:YTLPresentationLocalized(@"SaveToPhotos")
        image:[UIImage systemImageNamed:@"photo"] identifier:nil handler:^(UIAction *action) {
            (void)action;
            [self hapticFeedback];
            UIImageWriteToSavedPhotosAlbum(self.fullImage, nil, NULL, NULL);
        }];
    UIBarButtonItem *right = [UIBarButtonItem alloc];
    UIImage *moreImage = [UIImage systemImageNamed:@"ellipsis"];
    UIMenu *menu = [UIMenu menuWithTitle:@"" children:@[save, share, copy]];
    BlurButton *more = [BlurButton createButtonWithImage:moreImage
        target:nil action:NULL menu:menu];
    right = [right initWithCustomView:more];
    self.navigationItem.leftBarButtonItem = left;
    self.navigationItem.rightBarButtonItem = right;
}
- (void)setupViewer {
    self.view.backgroundColor = UIColor.clearColor;
    UIBlurEffect *effect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleLight];
    UIVisualEffectView *blur = [[UIVisualEffectView alloc] initWithEffect:effect];
    blur.frame = self.view.bounds;
    blur.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:blur];
    [self.view sendSubviewToBack:blur];
    _scrollView = [[UIScrollView alloc] init];
    _scrollView.maximumZoomScale = 3;
    _scrollView.minimumZoomScale = 1;
    _scrollView.delegate = self;
    _scrollView.showsHorizontalScrollIndicator = NO;
    _scrollView.showsVerticalScrollIndicator = NO;
    _scrollView.decelerationRate = UIScrollViewDecelerationRateNormal * 0.5;
    _scrollView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:_scrollView];
    _imageView = [[UIImageView alloc] init];
    _imageView.translatesAutoresizingMaskIntoConstraints = NO;
    _imageView.contentMode = UIViewContentModeScaleAspectFit;
    _imageView.image = self.fullImage;
    [_scrollView addSubview:_imageView];
    UITapGestureRecognizer *doubleTap = [[UITapGestureRecognizer alloc]
        initWithTarget:self action:@selector(handleDoubleTap:)];
    doubleTap.numberOfTapsRequired = 2;
    [_scrollView addGestureRecognizer:doubleTap];
    [_scrollView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor].active = YES;
    [_scrollView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor].active = YES;
    [_scrollView.topAnchor constraintEqualToAnchor:self.view.topAnchor].active = YES;
    [_scrollView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor].active = YES;
    [_imageView.widthAnchor constraintEqualToAnchor:_scrollView.widthAnchor].active = YES;
    [_imageView.heightAnchor constraintEqualToAnchor:_scrollView.heightAnchor].active = YES;
    [_imageView.centerXAnchor constraintEqualToAnchor:_scrollView.centerXAnchor].active = YES;
    [_imageView.centerYAnchor constraintEqualToAnchor:_scrollView.centerYAnchor].active = YES;
}
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView {
    (void)scrollView;
    return _imageView;
}
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self adjustScrollViewInsets];
    _scrollView.contentOffset = CGPointMake(
        MAX((_scrollView.contentSize.width - _scrollView.bounds.size.width) * 0.5, 0),
        MAX((_scrollView.contentSize.height - _scrollView.bounds.size.height) * 0.5, 0));
}
- (void)handleDoubleTap:(UITapGestureRecognizer *)recognizer {
    if (_scrollView.zoomScale == _scrollView.maximumZoomScale) {
        [_scrollView setZoomScale:_scrollView.minimumZoomScale animated:YES];
        return;
    }
    CGPoint point = [recognizer locationInView:_imageView];
    CGFloat maximum = _scrollView.maximumZoomScale;
    CGSize size = _scrollView.bounds.size;
    size.width /= maximum;
    size.height /= maximum;
    [_scrollView zoomToRect:CGRectMake(point.x - size.width * 0.5, point.y - size.height * 0.5,
                                      size.width, size.height) animated:YES];
}
- (void)scrollViewDidZoom:(UIScrollView *)scrollView {
    (void)scrollView;
    [self adjustScrollViewInsets];
}
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(CGFloat)scale {
    (void)scrollView; (void)view; (void)scale;
    [self adjustScrollViewInsets];
}
- (void)scrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(UIView *)view {
    (void)scrollView; (void)view;
    [self adjustScrollViewInsets];
}
- (void)adjustScrollViewInsets {
    double width = _imageView.image.size.width;
    double height = _imageView.image.size.height;
    double aspect = width / height;
    CGSize frameSize = _imageView.frame.size;
    double fittedHeight = frameSize.width / aspect;
    if (fittedHeight <= frameSize.height) [self adjustVerticalInsetsWithImageHeight:fittedHeight];
    else [self adjustHorizontalInsetsWithImageWidth:aspect * frameSize.height];
}
- (void)adjustHorizontalInsetsWithImageWidth:(double)width {
    double inset = (_scrollView.contentSize.width - width) * 0.5;
    if (width < _scrollView.frame.size.width) {
        inset += (_scrollView.frame.size.width - width) * -0.5;
    }
    _scrollView.contentInset = UIEdgeInsetsMake(0, -inset, 0, -inset);
}
- (void)adjustVerticalInsetsWithImageHeight:(double)height {
    double inset = (_scrollView.contentSize.height - height) * 0.5;
    if (height < _scrollView.frame.size.height) {
        inset += (_scrollView.frame.size.height - height) * -0.5;
    }
    _scrollView.contentInset = UIEdgeInsetsMake(-inset, 0, -inset, 0);
}
- (void)hapticFeedback { YTLPresentationHaptic(); }
- (void)closeButtonTapped {
    [self hapticFeedback];
    [self dismissViewControllerAnimated:YES completion:nil];
}
- (void)share {
    UIActivityViewController *activity = [[UIActivityViewController alloc]
        initWithActivityItems:@[self.fullImage] applicationActivities:nil];
    activity.excludedActivityTypes = @[UIActivityTypeAssignToContact, UIActivityTypePrint];
    if (activity.popoverPresentationController) {
        activity.popoverPresentationController.sourceView = self.view;
        double width = UIScreen.mainScreen.bounds.size.width;
        double height = UIScreen.mainScreen.bounds.size.height;
        activity.popoverPresentationController.sourceRect = CGRectMake(width * 0.5, height, 0, 0);
        activity.popoverPresentationController.permittedArrowDirections = UIPopoverArrowDirectionAny;
    }
    [self presentViewController:activity animated:YES completion:nil];
}
@end
