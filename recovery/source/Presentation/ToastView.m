#import "ToastView.h"
#import "ToastWindow.h"
#import "ToastManager.h"
#import "PresentationHost.h"
#import "PresentationGeometry.h"

static ToastWindow *YTLSharedToastWindow;
static NSString *const YTLGoodHeightNotification = @"GOODHeightDidChangeNotification";

static CABasicAnimation *YTLToastAnimation(NSString *key, id from, id to, double duration,
                                         CAMediaTimingFunctionName timing) {
    CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:key];
    animation.fromValue = from;
    animation.toValue = to;
    animation.duration = duration;
    animation.timingFunction = [CAMediaTimingFunction functionWithName:timing];
    return animation;
}

@implementation ToastView
+ (void)initialize {
    if (self != ToastView.class) return;
    [self toastWindow];
}
+ (ToastWindow *)toastWindow {
    static dispatch_once_t once;
    dispatch_once(&once, ^{
        UIWindowScene *scene;
        for (UIWindowScene *candidate in UIApplication.sharedApplication.connectedScenes) {
            if (candidate.activationState == UISceneActivationStateForegroundActive) {
                scene = candidate;
                break;
            }
        }
        if (!scene) scene = (UIWindowScene *)UIApplication.sharedApplication.connectedScenes.allObjects.firstObject;
        if (!scene) return;
        YTLSharedToastWindow = [[ToastWindow alloc] initWithWindowScene:scene];
        YTLSharedToastWindow.frame = UIScreen.mainScreen.bounds;
        UIViewController *root = [[UIViewController alloc] init];
        root.view.backgroundColor = UIColor.clearColor;
        root.view.translatesAutoresizingMaskIntoConstraints = NO;
        YTLSharedToastWindow.rootViewController = root;
        YTLSharedToastWindow.hidden = NO;
        dispatch_async(dispatch_get_main_queue(), ^{ [YTLSharedToastWindow makeKeyAndVisible]; });
        [NSLayoutConstraint activateConstraints:@[
            [root.view.topAnchor constraintEqualToAnchor:YTLSharedToastWindow.topAnchor],
            [root.view.leadingAnchor constraintEqualToAnchor:YTLSharedToastWindow.leadingAnchor],
            [root.view.trailingAnchor constraintEqualToAnchor:YTLSharedToastWindow.trailingAnchor],
            [root.view.bottomAnchor constraintEqualToAnchor:YTLSharedToastWindow.bottomAnchor]
        ]];
    });
    return YTLSharedToastWindow;
}
- (instancetype)init {
    _isiPad = (UIDevice.currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPad ||
        [UIDevice.currentDevice.model containsString:@"iPad"]) &&
        ![UIDevice.currentDevice.model containsString:@"iPhone"];
    self = [super initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleDark]];
    if (!self) return nil;
    _commandQueue = [NSMutableArray array];
    _ytSourceView = UIApplication.sharedApplication.delegate.window;
    _sourceView = YTLSharedToastWindow.rootViewController.view;
    _isAnimating = NO;
    self.alpha = 0;
    self.transform = CGAffineTransformMakeScale(1.2, 1.2);
    self.translatesAutoresizingMaskIntoConstraints = NO;
    self.layer.cornerRadius = 22.5;
    self.layer.cornerCurve = kCACornerCurveContinuous;
    self.layer.borderColor = [UIColor.whiteColor colorWithAlphaComponent:0.1].CGColor;
    self.layer.borderWidth = 1;
    self.clipsToBounds = YES;
    _toastLabel = [UILabel new];
    _toastLabel.numberOfLines = 0;
    _toastLabel.textColor = UIColor.whiteColor;
    _toastLabel.textAlignment = NSTextAlignmentCenter;
    _toastLabel.font = [UIFont monospacedDigitSystemFontOfSize:15 weight:UIFontWeightBold];
    _toastLabel.translatesAutoresizingMaskIntoConstraints = NO;
    [_toastLabel setContentHuggingPriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
    [_toastLabel setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
    _toastProgress = [[UIProgressView alloc] initWithProgressViewStyle:UIProgressViewStyleBar];
    _toastProgress.progressTintColor = [UIColor.blackColor colorWithAlphaComponent:0.3];
    _toastProgress.trackTintColor = UIColor.clearColor;
    _toastProgress.translatesAutoresizingMaskIntoConstraints = NO;
    _toastIcon = [UIImageView new];
    _toastIcon.tintColor = UIColor.whiteColor;
    _toastIcon.translatesAutoresizingMaskIntoConstraints = NO;
    _toastIcon.alpha = 0;
    _toastButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _toastButton.tintColor = UIColor.whiteColor;
    [_toastButton setImage:[UIImage systemImageNamed:@"stop.circle"] forState:UIControlStateNormal];
    [_toastButton addTarget:self action:@selector(cancelButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    UILongPressGestureRecognizer *longPress = [[UILongPressGestureRecognizer alloc]
        initWithTarget:self action:@selector(handleLongPress:)];
    longPress.minimumPressDuration = 3;
    [_toastButton addGestureRecognizer:longPress];
    _activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    _activityIndicator.color = UIColor.whiteColor;
    _actionsStack = [[UIStackView alloc] initWithArrangedSubviews:@[_toastButton, _activityIndicator]];
    _actionsStack.axis = UILayoutConstraintAxisHorizontal;
    _actionsStack.distribution = UIStackViewDistributionFill;
    _actionsStack.alignment = UIStackViewAlignmentCenter;
    _actionsStack.spacing = 10;
    _actionsStack.translatesAutoresizingMaskIntoConstraints = NO;
    [self.contentView addSubview:_toastProgress];
    [self.contentView addSubview:_toastLabel];
    [self.contentView addSubview:_toastIcon];
    [self.contentView addSubview:_actionsStack];
    [NSLayoutConstraint activateConstraints:@[
        [_toastProgress.topAnchor constraintEqualToAnchor:self.contentView.topAnchor],
        [_toastProgress.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor],
        [_toastProgress.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor],
        [_toastProgress.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor],
        [_toastLabel.topAnchor constraintEqualToAnchor:self.contentView.topAnchor constant:5],
        [_toastLabel.bottomAnchor constraintEqualToAnchor:self.contentView.bottomAnchor constant:-5],
        [_toastLabel.leadingAnchor constraintEqualToAnchor:_toastIcon.trailingAnchor constant:5],
        [_toastLabel.trailingAnchor constraintEqualToAnchor:_actionsStack.leadingAnchor constant:-5],
        [_toastIcon.centerYAnchor constraintEqualToAnchor:self.contentView.centerYAnchor],
        [_toastIcon.leadingAnchor constraintEqualToAnchor:self.contentView.leadingAnchor constant:10],
        [_toastIcon.widthAnchor constraintEqualToConstant:24],
        [_toastIcon.heightAnchor constraintEqualToConstant:24],
        [_actionsStack.centerYAnchor constraintEqualToAnchor:self.contentView.centerYAnchor],
        [_actionsStack.trailingAnchor constraintEqualToAnchor:self.contentView.trailingAnchor constant:-10],
        [_toastButton.widthAnchor constraintEqualToConstant:24],
        [_toastButton.heightAnchor constraintEqualToConstant:24],
        [_activityIndicator.widthAnchor constraintEqualToConstant:30],
        [_activityIndicator.heightAnchor constraintEqualToConstant:30]
    ]];
    return self;
}
- (void)enqueueCommand:(dispatch_block_t)command {
    [_commandQueue addObject:[command copy]];
    [self processQueue];
}
- (void)processQueue {
    if (_isAnimating || _commandQueue.count == 0) return;
    _isAnimating = YES;
    dispatch_block_t command = _commandQueue.firstObject;
    [_commandQueue removeObjectAtIndex:0];
    command();
}
- (void)setupInterfaceWithText:(NSString *)text progress:(float)progress withStop:(BOOL)stop
                     isStatus:(BOOL)status isSuccess:(BOOL)success withWait:(BOOL)wait {
    [[ToastManager sharedManager] registerToast:self];
    [_toastProgress setProgress:progress animated:NO];
    _toastLabel.text = text;
    _toastIcon.alpha = status ? 1 : 0;
    _toastButton.alpha = stop ? 1 : 0;
    _toastButton.hidden = wait;
    _activityIndicator.hidden = !wait;
    _toastIcon.image = [UIImage systemImageNamed:success ? @"checkmark.circle" : @"xmark.circle"];
    if (wait) [_activityIndicator startAnimating]; else [_activityIndicator stopAnimating];
    [_sourceView addSubview:self];
    [_sourceView bringSubviewToFront:self];
    double width = _sourceView.frame.size.width * YTLToastWidthFraction(_isiPad, self.isLandscape);
    double bottom, top, scale;
    [self calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
    _topConstraint = [self.topAnchor constraintEqualToAnchor:_sourceView.topAnchor constant:top];
    _bottomConstraint = [self.bottomAnchor constraintEqualToAnchor:_sourceView.bottomAnchor constant:-bottom];
    _centerXConstraint = [self.centerXAnchor constraintEqualToAnchor:_sourceView.centerXAnchor];
    _widthConstraint = [self.widthAnchor constraintEqualToConstant:width];
    _heightConstraint = [self.heightAnchor constraintGreaterThanOrEqualToConstant:45];
    [NSLayoutConstraint activateConstraints:@[_centerXConstraint, _widthConstraint, _heightConstraint]];
    [NSLayoutConstraint activateConstraints:@[self.isPinnedTop ? _topConstraint : _bottomConstraint]];
    [self addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap)]];
    if (!_ignoresPanGesture)
        [self addGestureRecognizer:[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePanGesture:)]];
    [self setupObservers];
}
- (void)handlePanGesture:(UIPanGestureRecognizer *)recognizer {
    if (_ignoresPanGesture) return;
    double translation = YTLToastPanTranslation([recognizer translationInView:self.superview].y, self.isPinnedTop);
    if (recognizer.state == UIGestureRecognizerStateChanged) {
        CATransform3D fromTransform = self.layer.presentationLayer ? self.layer.presentationLayer.transform : self.layer.transform;
        float fromOpacity = self.layer.presentationLayer ? self.layer.presentationLayer.opacity : self.layer.opacity;
        [self.layer removeAllAnimations];
        CABasicAnimation *move = YTLToastAnimation(@"transform", [NSValue valueWithCATransform3D:fromTransform],
            [NSValue valueWithCATransform3D:CATransform3DMakeTranslation(0, translation, 0)], 0.01, kCAMediaTimingFunctionLinear);
        CABasicAnimation *fade = YTLToastAnimation(@"opacity", @(fromOpacity), @(fabs(translation) > 60 ? 0.25 : 1),
                                                  0.01, kCAMediaTimingFunctionLinear);
        move.removedOnCompletion = NO; move.fillMode = kCAFillModeForwards;
        fade.removedOnCompletion = NO; fade.fillMode = kCAFillModeForwards;
        [self.layer addAnimation:move forKey:@"panTranslation"];
        [self.layer addAnimation:fade forKey:@"panOpacity"];
    } else if (recognizer.state == UIGestureRecognizerStateEnded || recognizer.state == UIGestureRecognizerStateCancelled) {
        [self.layer removeAllAnimations];
        if (fabs(translation) > 60) [self hide];
        else [self updateLayout];
    }
}
- (void)handleTap {
    NSMutableArray *toasts = [ToastManager sharedManager].toasts;
    ToastView *next;
    @synchronized (toasts) {
        if (toasts.count < 2) return;
        if ([toasts containsObject:self]) { [toasts removeObject:self]; [toasts insertObject:self atIndex:0]; }
        next = toasts.lastObject;
        for (ToastView *toast in [toasts copy]) [toast updateLayout];
    }
    const double position = self.layer.position.y;
    const double height = self.bounds.size.height;
    CABasicAnimation *lift = YTLToastAnimation(@"position.y", @(position), @(position - height), 0.25,
                                              kCAMediaTimingFunctionEaseInEaseOut);
    CABasicAnimation *scale = YTLToastAnimation(@"transform.scale", @1, @(toasts.count == 2 ? 0.95 : 0.9),
                                               0.25, kCAMediaTimingFunctionEaseInEaseOut);
    [CATransaction begin];
    [CATransaction setCompletionBlock:^{
        if (next) [self->_sourceView bringSubviewToFront:next];
        [CATransaction begin];
        [CATransaction setCompletionBlock:^{ [self->_sourceView sendSubviewToBack:self]; }];
        [self.layer addAnimation:YTLToastAnimation(@"position.y", @(position - height), @(position), 0.25,
            kCAMediaTimingFunctionEaseInEaseOut) forKey:@"toastReturn"];
        [CATransaction commit];
    }];
    [self.layer addAnimation:lift forKey:@"toastLift"];
    [self.layer addAnimation:scale forKey:@"toastScale"];
    [CATransaction commit];
}
- (void)updateLayout {
    if (!_sourceView) return;
    double width = _sourceView.frame.size.width;
    BOOL pad = _isiPad;
    BOOL landscape = self.isLandscape;
    width *= YTLToastWidthFraction(pad, landscape);
    double bottom, top, scale;
    [self calculateToastParametersWithKeyboardHeight:_keyboardHeight bottomOffset:&bottom topOffset:&top scale:&scale];
    [self configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
        width:width animationDuration:0.5];
}
- (void)calculateToastParametersWithKeyboardHeight:(double)keyboard
                                     bottomOffset:(double *)bottom topOffset:(double *)top scale:(double *)scale {
    double safeTop = _sourceView.safeAreaInsets.top;
    NSMutableArray *toasts = [ToastManager sharedManager].toasts;
    NSUInteger index = [toasts indexOfObject:self];
    NSUInteger count = toasts.count;
    double screenWidth = CGRectGetWidth(UIScreen.mainScreen.bounds);
    double firstBottom = self.bottomOffset;
    *scale = 1;
    *top = safeTop + 15;
    if (keyboard > 0) {
        *bottom = (_goodHeight + keyboard) + 15;
    } else {
        double gap = screenWidth != 375 && firstBottom == 0 ? 30 : 0;
        double goodHeight = _goodHeight;
        double adjustment = goodHeight - 30;
        // The original FCSEL GT excludes unordered NaN, unlike a <= 0 ternary.
        if (!(goodHeight > 0)) adjustment = 0;
        double secondBottom = self.bottomOffset;
        *bottom = (gap + (secondBottom + adjustment)) + 15;
    }
    if (count == 1) return;
    double stackOffset;
    if (index == count - 1) {
        if (count == 2) stackOffset = 5;
        else if (count > 2) stackOffset = 10;
        else return;
    } else if (index == count - 2) {
        *scale = 0.95;
        stackOffset = count == 2 ? 0 : 5;
    } else {
        *scale = 0.9;
        return;
    }
    *bottom = *bottom + stackOffset;
    *top = *top + stackOffset;
}
- (void)configureToastAppearanceWithBottomOffset:(double)bottom topOffset:(double)top
                                           scale:(double)scale width:(double)width animationDuration:(double)duration {
    _bottomConstraint.constant = -bottom;
    _widthConstraint.constant = width;
    _topConstraint.constant = top;
    if (!_ignoresFullscreenOpacity) self.hidden = self.isFullscreen;
    [UIView animateWithDuration:duration delay:0 usingSpringWithDamping:1 initialSpringVelocity:15 options:0 animations:^{
        self.transform = CGAffineTransformMakeScale(scale, scale);
        BOOL pinned = self.isPinnedTop;
        (pinned ? self->_bottomConstraint : self->_topConstraint).active = NO;
        (pinned ? self->_topConstraint : self->_bottomConstraint).active = YES;
        [self->_sourceView layoutIfNeeded];
    } completion:nil];
}
- (void)configureToastAppearanceWithBottomOffset:(double)bottom topOffset:(double)top
                                           scale:(double)scale width:(double)width alpha:(double)alpha
                               animationDuration:(double)duration completion:(dispatch_block_t)completion {
    _bottomConstraint.constant = -bottom;
    _widthConstraint.constant = width;
    _topConstraint.constant = top;
    [UIView animateWithDuration:duration delay:0 usingSpringWithDamping:1 initialSpringVelocity:15 options:0 animations:^{
        self.alpha = alpha;
        BOOL pinned = self.isPinnedTop;
        (pinned ? self->_bottomConstraint : self->_topConstraint).active = NO;
        (pinned ? self->_topConstraint : self->_bottomConstraint).active = YES;
        self.transform = CGAffineTransformMakeScale(scale, scale);
    } completion:^(BOOL finished) { (void)finished; if (completion) completion(); }];
}
- (void)setupObservers {
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(keyboardWillHide:) name:UIKeyboardWillHideNotification object:nil];
    [NSNotificationCenter.defaultCenter addObserver:self selector:@selector(goodHeightDidChange:) name:YTLGoodHeightNotification object:nil];
}
- (void)removeObservers {
    [NSNotificationCenter.defaultCenter removeObserver:self name:UIKeyboardWillShowNotification object:nil];
    [NSNotificationCenter.defaultCenter removeObserver:self name:UIKeyboardWillHideNotification object:nil];
    [NSNotificationCenter.defaultCenter removeObserver:self name:YTLGoodHeightNotification object:nil];
}
- (void)goodHeightDidChange:(NSNotification *)notification {
    _goodHeight = [notification.userInfo[@"height"] floatValue];
    [self updateLayout];
}
- (void)keyboardWillShow:(NSNotification *)notification {
    CGRect rect = [notification.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    _keyboardHeight = CGRectGetHeight([self convertRect:rect fromView:nil]);
    [self updateLayout];
}
- (void)keyboardWillHide:(NSNotification *)notification {
    (void)notification;
    _keyboardHeight = 0;
    [self updateLayout];
}
- (void)cleanup {
    [self.layer removeAllAnimations];
    [_progressTimer invalidate];
    _progressTimer = nil;
    _ignoresFullscreenOpacity = NO;
    _ignoresPanGesture = NO;
    [self removeFromSuperview];
    [self removeObservers];
    [[ToastManager sharedManager] unregisterToast:self];
}
- (void)cancelButtonTapped {
    if (self.completion) self.completion();
    if (!_ignoresPanGesture) [self hide];
}
- (void)handleLongPress:(UILongPressGestureRecognizer *)recognizer {
    if (recognizer.state == UIGestureRecognizerStateBegan) [self hide];
}
- (void)showProgressWithText:(NSString *)text progress:(float)progress withStop:(BOOL)stop
             stopCompletion:(dispatch_block_t)completion {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            [toast setupInterfaceWithText:text progress:progress withStop:stop isStatus:NO isSuccess:NO withWait:NO];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:^{ if (completion) toast.completion = completion; }];
        }];
    }];
}
- (void)updateText:(NSString *)text progress:(float)progress {
    _toastLabel.text = text;
    [_toastProgress setProgress:progress animated:YES];
}
- (void)updateText:(NSString *)text progress:(float)progress animated:(BOOL)animated {
    _toastLabel.text = text;
    [_toastProgress setProgress:progress animated:animated];
}
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success {
    [self showMessageWithText:text isSuccess:success duration:2.5];
}
- (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success duration:(double)duration {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            YTLPresentationHaptic();
            [toast setupInterfaceWithText:text progress:0 withStop:NO isStatus:YES isSuccess:success withWait:NO];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:^{ [toast hideWithDelay:duration]; }];
        }];
    }];
}
- (void)showText:(NSString *)text {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            [toast setupInterfaceWithText:text progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:^{ [toast hideWithDelay:2.5]; }];
        }];
    }];
}
- (void)showToast:(NSString *)text {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            [toast setupInterfaceWithText:text progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:YES];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:^{
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC / 2), dispatch_get_main_queue(), ^{
                    toast->_isAnimating = NO;
                    [toast processQueue];
                });
            }];
        }];
    }];
}
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration isSuccess:(BOOL)success {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            toast->_ignoresFullscreenOpacity = YES;
            YTLPresentationHaptic();
            [toast setupInterfaceWithText:text progress:1 withStop:NO isStatus:YES isSuccess:success withWait:NO];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:nil];
            [toast startTimerCountdown:duration];
        }];
    }];
}
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                       actionTitle:(NSString *)title actionCompletion:(dispatch_block_t)completion {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            toast->_ignoresFullscreenOpacity = YES;
            [toast setupInterfaceWithText:text progress:1 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
            toast->_toastLabel.textAlignment = NSTextAlignmentNatural;
            toast->_toastLabel.font = [UIFont monospacedDigitSystemFontOfSize:14 weight:UIFontWeightBold];
            toast->_toastButton.hidden = YES;
            UIAction *action = [UIAction actionWithHandler:^(UIAction *sender) {
                (void)sender;
                if (completion) completion();
                [toast hide];
            }];
            UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
            [button setTitle:title forState:UIControlStateNormal];
            [button setTitleColor:UIColor.whiteColor forState:UIControlStateNormal];
            [button setTitleColor:[UIColor.whiteColor colorWithAlphaComponent:0.7] forState:UIControlStateHighlighted];
            [button addAction:action forControlEvents:UIControlEventTouchUpInside];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
            button.contentEdgeInsets = UIEdgeInsetsMake(6, 12, 6, 12);
#pragma clang diagnostic pop
            button.titleLabel.font = [UIFont systemFontOfSize:13 weight:UIFontWeightBold];
            [button setContentHuggingPriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];
            [button setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisHorizontal];
            [toast->_actionsStack addArrangedSubview:button];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:nil];
            [toast startTimerCountdown:duration];
        }];
    }];
}
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(UIImage *)icon actionCompletion:(dispatch_block_t)completion {
    [self showProgressiveToastWithText:text duration:duration actionIcon:icon ignoresPan:NO actionCompletion:completion];
}
- (void)showProgressiveToastWithText:(NSString *)text duration:(double)duration
                        actionIcon:(UIImage *)icon ignoresPan:(BOOL)ignoresPan
                  actionCompletion:(dispatch_block_t)completion {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            toast->_ignoresFullscreenOpacity = YES;
            toast->_ignoresPanGesture = ignoresPan;
            [toast setupInterfaceWithText:text progress:1 withStop:YES isStatus:NO isSuccess:NO withWait:NO];
            toast->_toastLabel.textAlignment = NSTextAlignmentNatural;
            toast->_toastLabel.font = [UIFont monospacedDigitSystemFontOfSize:14 weight:UIFontWeightBold];
            [toast->_toastButton setImage:icon forState:UIControlStateNormal];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:^{ if (completion) toast.completion = completion; }];
            [toast startTimerCountdown:duration];
        }];
    }];
}
- (void)showDonationReminder:(NSString *)text {
    [self enqueueCommand:^{
        ToastView *toast = self;
        [toast hideWithCompletion:^{
            toast->_ignoresPanGesture = YES;
            [toast setupInterfaceWithText:text progress:1 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
            double bottom, top, scale;
            [toast calculateToastParametersWithKeyboardHeight:0 bottomOffset:&bottom topOffset:&top scale:&scale];
            [toast configureToastAppearanceWithBottomOffset:bottom topOffset:top scale:scale
                width:toast->_widthConstraint.constant alpha:1 animationDuration:0.3 completion:nil];
            [toast startTimerCountdown:10];
        }];
    }];
}
- (void)startTimerCountdown:(double)duration {
    __block double remaining = 1;
    const double step = 0.016 / duration;
    NSTimer *timer = [NSTimer timerWithTimeInterval:0.016 repeats:YES block:^(NSTimer *timer) {
        remaining -= step;
        // FCMP/CSET HI takes this branch for positive and unordered values.
        if (!(remaining <= 0)) [self->_toastProgress setProgress:(float)remaining animated:YES];
        else {
            [self->_toastProgress setProgress:0 animated:YES];
            [timer invalidate];
            [self hide];
        }
    }];
    [NSRunLoop.mainRunLoop addTimer:timer forMode:NSRunLoopCommonModes];
}
- (void)hideAnimatedWithCompletion:(dispatch_block_t)completion {
    [self.layer removeAllAnimations];
    CABasicAnimation *scale = YTLToastAnimation(@"transform.scale", @1, @0.8, 0.3, kCAMediaTimingFunctionEaseIn);
    CABasicAnimation *fade = YTLToastAnimation(@"opacity", @1, @0, 0.3, kCAMediaTimingFunctionEaseIn);
    [CATransaction begin];
    [CATransaction setCompletionBlock:^{
        self->_isAnimating = NO;
        if (completion) completion();
        else { [self cleanup]; [self processQueue]; }
    }];
    [self.layer addAnimation:scale forKey:@"scale"];
    [self.layer addAnimation:fade forKey:@"opacity"];
    self.layer.transform = CATransform3DMakeScale(0.8, 0.8, 1);
    self.layer.opacity = 0;
    [CATransaction commit];
}
- (void)hideImmediately {
    [self cleanup];
    [self processQueue];
}
- (void)hideWithDelay:(double)delay {
    const double nanoseconds = delay * (double)NSEC_PER_SEC;
    // ARM64 FCVTZS saturates overflow and converts NaN to zero.
    const int64_t delta = isnan(nanoseconds) ? 0 :
        nanoseconds >= (double)INT64_MAX ? INT64_MAX :
        nanoseconds <= (double)INT64_MIN ? INT64_MIN : (int64_t)nanoseconds;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, delta), dispatch_get_main_queue(), ^{
        [self hideAnimatedWithCompletion:nil];
    });
}
- (void)hide { [self hideWithDelay:0]; }
- (BOOL)isHidden {
    BOOL hidden = [super isHidden];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 300000000), dispatch_get_main_queue(), ^{
        [[ToastManager sharedManager] updateAllToasts];
    });
    return hidden;
}
- (void)hideWithCompletion:(dispatch_block_t)completion {
    if (!_isAnimating && self.alpha == 0) {
        if (completion) completion();
        return;
    }
    dispatch_async(dispatch_get_main_queue(), ^{ [self hideAnimatedWithCompletion:completion]; });
}
- (BOOL)isLandscape {
    UIWindowScene *scene = (UIWindowScene *)UIApplication.sharedApplication.connectedScenes.allObjects.firstObject;
    return UIInterfaceOrientationIsLandscape(scene.interfaceOrientation);
}
- (BOOL)isFullscreen { return [ToastManager sharedManager].isFullscreen; }
- (BOOL)isPinnedTop { return [ToastManager sharedManager].isPinnedTop; }
- (double)bottomOffset {
    YTToastOffsetController *controller = [ToastManager sharedManager].offsetController;
    return [controller respondsToSelector:@selector(bottomOffset)] ? controller.bottomOffset : 0;
}
- (void)dealloc {
    [self removeObservers];
}
@end
