#pragma once
#import <UIKit/UIKit.h>

// Narrow message contracts, not implementations of YouTube host classes.
@protocol YTLControlsNode <NSObject>
- (id<YTLControlsNode>)responderRoot;
- (id<YTLControlsNode>)appView;
- (id<YTLControlsNode>)watchLayerView;
- (id<YTLControlsNode>)watchViewController;
- (id<YTLControlsNode>)watchCollectionView;
- (id<YTLControlsNode>)_viewControllerForAncestor;
- (id<YTLControlsNode>)playerViewController;
- (id<YTLControlsNode>)parentViewController;
- (id<YTLControlsNode>)parentResponder;
- (id<YTLControlsNode>)activeVideo;
- (id<YTLControlsNode>)activePlaybackRateModel;
- (id<YTLControlsNode>)videoFreeZoomOverlayController;
- (id<YTLControlsNode>)node;
- (id<YTLControlsNode>)delegate;
- (id)elementEntry;
- (UIView *)view;
- (float)playbackRate;
- (void)setPlaybackRate:(float)rate;
- (float)activeRate;
- (void)setActivePlaybackRateModel:(id)model;
- (double)minFreeZoomFactor;
- (double)videoZoomFactor;
- (BOOL)isSnappedToFillByDefault;
- (double)currentVideoTotalMediaTime;
- (double)currentVideoMediaTime;
- (id<YTLControlsNode>)slimStatusBarView;
- (id<YTLControlsNode>)pivotBarViewController;
- (void)slimStatusBarDisplayStatusDidChange;
- (void)pausePlayback;
@end

@protocol YTLControlsRateModel <NSObject>
+ (instancetype)alloc;
- (instancetype)initWithRate:(float)rate;
@end

@interface UIView (YTLControlsHost)
- (id<YTLControlsNode>)_viewControllerForAncestor;
@end

static inline id<YTLControlsNode> YTLControlsRoot(void) {
    return [(id<YTLControlsNode>)[UIApplication sharedApplication].delegate responderRoot];
}

static inline id<YTLControlsNode> YTLControlsPlayer(void) {
    id<YTLControlsNode> root = YTLControlsRoot();
    if (![NSStringFromClass([(id)root class]) hasPrefix:@"YTAppViewController"]) return nil;
    return [[[[root appView] watchLayerView] _viewControllerForAncestor] playerViewController];
}
