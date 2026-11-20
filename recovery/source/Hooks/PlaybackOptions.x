#import "PlaybackOptionsHost.h"
#import "FeedNodesHelpers.h"
#import "../Runtime/YTLFeaturePolicy.h"
#import "../Controls/YTPSpeedMaster.h"
#import "../../../Utils/YTLUserDefaults.h"
#import <objc/runtime.h>
#include <math.h>

static char PlaybackOptionsRedesignedKey;
%group YTLPlaybackOptions
%hook YTWatchNextResultsViewController
- (void)setVisibleSections:(NSUInteger)sections {
    %orig(ytpBool(@"noRelatedWatchNexts") ? 1 : sections);
}
%end
%hook YTFullscreenEngagementOverlayView
- (void)setExpanded:(BOOL)expanded {
    %orig;
    if ([self.superview isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayView")]) {
        id<YTLPlaybackOptionsControls> controls = [(id<YTLPlaybackOptionsOverlay>)self.superview controlsOverlayView];
        if ((ytpBool(@"downloadManager") && ytpInt(@"ytlButtonIndex") != 0) || ytpBool(@"ytlMuteButton") || ytpBool(@"ytlLockButton"))
            [controls ytlButtons].alpha = expanded ? 0 : [controls isOverlayVisible];
        if (ytpBool(@"speedControls"))
            [controls speedControls].alpha = expanded ? 0 : [controls isOverlayVisible];
    }
}
%end
%hook YTPlaylistVideoCell
- (void)setCanReorder:(BOOL)value { %orig(YES); }
%end
%hook YTVideoFreeZoomOverlayController
- (void)freeZoomViewDidZoom:(double)zoom isTwoFingerZoom:(BOOL)twoFinger {
    if (class_getInstanceVariable([self class], "_snappedZoomFactor") && ytpBool(@"noFreeZoom")) {
        double snapped = [[self valueForKey:@"_snappedZoomFactor"] doubleValue];
        double current = [self videoZoomFactor];
        if (zoom > 1.0) {
            if (current > snapped) zoom = 1.0;
            else if (current * zoom > snapped) zoom = snapped / current;
        }
    }
    %orig(zoom, twoFinger);
}
%end
%hook YTWatchCinematicContainerController
- (BOOL)isCinematicLightingAvailable { return ytpBool(@"disableAmbientMode") ? NO : %orig; }
%end
%hook YTCreatorEndscreenView
- (void)setHidden:(BOOL)value { %orig(value | ytpBool(@"endScreenCards")); }
%end
%hook YTFullscreenActionsView
- (BOOL)enabled { return !ytpBool(@"noFullscreenActions"); }
- (void)setEnabled:(BOOL)value { %orig(value & !ytpBool(@"noFullscreenActions")); }
- (void)layoutSubviews {
    %orig;
    if (ytpBool(@"noMoreVideos") && class_getInstanceVariable([self class], "_elementView")) {
        UIView *element = [self valueForKey:@"_elementView"];
        if (element.subviews.count >= 2) {
            UIView *target = element.subviews[1];
            id<YTLPlaybackOptionsNode> node = [target keepalive_node];
            if (node.subnodes.count == 2) {
                id<YTLPlaybackOptionsNode> image = node.subnodes.lastObject.subnodes.lastObject;
                if ([image isKindOfClass:NSClassFromString(@"ASNetworkImageNode")] && [image.URL.absoluteString containsString:@"i.ytimg.com/vi/"])
                    target.alpha = 0;
            }
        }
    }
}
%end
%hook YTFullscreenEngagementOverlayController
- (void)setRelatedVideosVisible:(BOOL)value { %orig(value & !ytpBool(@"noRelatedVids")); }
%end
%hook YTAnnotationsViewController
- (void)loadFeaturedChannelWatermark { if (!ytpBool(@"noWatermarks")) %orig; }
%end
%hook YTWatchFloatingMiniplayerViewController
- (void)updateMiniBarPlayerStateFromRenderer { if (!ytpBool(@"miniplayer")) %orig; }
%end
%hook YTPlaybackConfig
- (void)setStartPlayback:(BOOL)value { %orig(value & !ytpBool(@"disableAutoplay")); }
%end
%hook YTPlayabilityResolutionUserActionUIController
- (void)showConfirmAlert {
    if (ytpBool(@"noContentWarning")) [self confirmAlertDidPressConfirm];
    else %orig;
}
%end
%hook YTVideoQualitySwitchOriginalController
%new
- (YTVideoQualitySwitchRedesignedController *)redesignedController { return objc_getAssociatedObject(self, &PlaybackOptionsRedesignedKey); }
%new
- (void)setRedesignedController:(YTVideoQualitySwitchRedesignedController *)controller {
    objc_setAssociatedObject(self, &PlaybackOptionsRedesignedKey, controller, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
- (void)setUserSelectableFormats:(NSArray *)formats {
    if (![self redesignedController])
        [self setRedesignedController:[[NSClassFromString(@"YTVideoQualitySwitchRedesignedController") alloc] initWithServiceRegistryScope:nil parentResponder:nil]];
    [[self redesignedController] setValue:[self valueForKey:@"_video"] forKey:@"_video"];
    if ([[self redesignedController] respondsToSelector:@selector(addRestrictedFormats:)])
        formats = [[self redesignedController] addRestrictedFormats:formats];
    %orig(formats);
}
- (void)dealloc { [self setRedesignedController:nil]; %orig; }
%end
%hook YTSegmentableInlinePlayerBarView
- (void)didMoveToWindow {
    %orig;
    if (ytpBool(@"dontSnapToChapter")) [self setEnableSnapToChapter:NO];
}
%end
%hook YTBrandGradientImageProcessor
- (void)willDrawInContext:(CGContextRef)context drawParameters:(id<YTLPlaybackOptionsDrawParameters>)parameters {
    NSData *mainData = [[YTLUserDefaults standardUserDefaults] objectForKey:@"progressMainColor"];
    NSData *gradientData = [[YTLUserDefaults standardUserDefaults] objectForKey:@"progressGradientColor"];
    UIColor *mainColor = [NSKeyedUnarchiver unarchivedObjectOfClass:[UIColor class] fromData:mainData error:nil];
    UIColor *gradientColor = [NSKeyedUnarchiver unarchivedObjectOfClass:[UIColor class] fromData:gradientData error:nil];
    CGRect clip = CGContextGetClipBoundingBox(context);
    CGRect rect = CGRectIntersection([parameters drawRect], clip);
    if (rect.size.height > 30 && fabs(rect.size.width - rect.size.height) < 1) { %orig; return; }
    if (ytpInt(@"progressBarIndex") == 1) {
        CGContextSetFillColorWithColor(context, mainColor.CGColor);
        CGContextFillRect(context, rect);
    } else if (ytpInt(@"progressBarIndex") == 2 && gradientColor) {
        CGContextSaveGState(context);
        CGContextClipToRect(context, rect);
        CGRect drawRect = [parameters drawRect];
        CGColorSpaceRef space = CGColorSpaceCreateDeviceRGB();
        NSArray *colors = @[(__bridge id)mainColor.CGColor, (__bridge id)gradientColor.CGColor];
        CGFloat locations[] = {0, 1};
        CGGradientRef gradient = CGGradientCreateWithColors(space, (__bridge CFArrayRef)colors, locations);
        CGContextDrawLinearGradient(context, gradient, CGPointMake(CGRectGetMinX(drawRect), CGRectGetMidY(drawRect)), CGPointMake(CGRectGetMaxX(drawRect), CGRectGetMidY(drawRect)), 0);
        CGGradientRelease(gradient);
        CGColorSpaceRelease(space);
        CGContextRestoreGState(context);
    } else %orig;
}
%end
%hook YTVerticalPanGestureRecognier
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture {
    UIView *view = [self verticalPanGestureRecognizerDelegate];
    if ([view isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayView")]) {
        view = [self verticalPanGestureRecognizerDelegate];
        CGFloat x = [gesture locationInView:view].x;
        CGFloat width = view.bounds.size.width;
        double edge = [[YTLUserDefaults standardUserDefaults] floatForKey:@"gestWideness"];
        BOOL left = x <= edge ? ytpInt(@"leftGestureIndex") != 0 : NO;
        BOOL right = x >= width - edge ? ytpInt(@"rightGestureIndex") != 0 : NO;
        if (left | right) return NO;
    }
    return %orig;
}
%end
%hook YTExitFullscreenController
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)gesture {
    UIView *view = [self fullscreenExitGestureRecognizer].view;
    if ([view isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayView")]) {
        CGFloat x = [gesture locationInView:view].x;
        CGFloat width = view.bounds.size.width;
        double edge = [[YTLUserDefaults standardUserDefaults] floatForKey:@"gestWideness"];
        BOOL left = x <= edge ? ytpInt(@"leftGestureIndex") != 0 : NO;
        BOOL right = x >= width - edge ? ytpInt(@"rightGestureIndex") != 0 : NO;
        if (left | right) return NO;
    }
    return %orig;
}
%end
%hook YTMenuItemVisibilityHandler
- (BOOL)shouldShowServiceItemRenderer:(id<YTLPlaybackOptionsRenderer>)renderer {
    if (ytpBool(@"removePlayNext") && renderer.icon.iconType == 251) return NO;
    return %orig;
}
%end
%hook YTDefaultSheetController
- (void)addAction:(id<YTLPlaybackOptionsAction>)action {
    NSDictionary *hidden = @{
        @"yt_outline_download_24pt": @(ytpBool(@"removeDownloadMenu")),
        @"yt_outline_clock_24pt": @(ytpBool(@"removeWatchLaterMenu")),
        @"youtube_outline/bookmark_24pt": @(ytpBool(@"removeSaveToPlaylistMenu")),
        @"yt_outline_share_24pt": @(ytpBool(@"removeShareMenu")),
        @"yt_outline_slash_circle_left_24pt": @(ytpBool(@"removeNotInterestedMenu")),
        @"youtube_outline/person_circle_slash_24pt": @(ytpBool(@"removeDontRecommendMenu")),
        @"yt_outline_flag_24pt": @(ytpBool(@"removeReportMenu")),
        @"yt_outline_message_bubble_alert_24pt": @(ytpBool(@"removeFeedbackMenu")),
        @"yt_outline_list_queue_next_24pt": @(ytpBool(@"removePlayNext")),
        @"yt_outline_youtube_shorts_plus_24pt": @(ytpBool(@"removeRemixMenu")),
        @"yt_outline_youtube_music_24pt": @(ytpBool(@"removeYTMMenu")),
        @"youtube_outline_experimental/download_24pt": @(ytpBool(@"removeDownloadMenu")),
        @"youtube_outline_experimental/clock_24pt": @(ytpBool(@"removeWatchLaterMenu")),
        @"youtube_outline_experimental/bookmark_24pt": @(ytpBool(@"removeSaveToPlaylistMenu")),
        @"youtube_outline_experimental/share_24pt": @(ytpBool(@"removeShareMenu")),
        @"youtube_outline_experimental/circle_slash_24pt": @(ytpBool(@"removeNotInterestedMenu")),
        @"youtube_outline_experimental/person_circle_slash_24pt": @(ytpBool(@"removeDontRecommendMenu")),
        @"youtube_outline_experimental/flag_24pt": @(ytpBool(@"removeReportMenu")),
        @"youtube_outline_experimental/alert_bubble_24pt": @(ytpBool(@"removeFeedbackMenu")),
        @"youtube_outline_experimental/queue_next_24pt": @(ytpBool(@"removePlayNext")),
        @"youtube_outline_experimental/remix_24pt": @(ytpBool(@"removeRemixMenu")),
        @"youtube_outline_experimental/youtube_music_24pt": @(ytpBool(@"removeYTMMenu"))
    };
    NSString *name = innertubeName([[action iconImage] description]);
    if ([action button] && name.length == 0) name = innertubeName([[[action button] currentImage] description]);
    if (![hidden[name] boolValue]) %orig;
}
%end
%hook YTYouThereController
- (BOOL)shouldShowYouTherePrompt { return NO; }
%end
%hook YTSpeedmasterController
- (void)speedmasterDidLongPressWithRecognizer:(UILongPressGestureRecognizer *)gesture {
    if (ytpInt(@"speedIndex") != 0) {
        if (ytpInt(@"speedIndex") == 1) %orig;
        else {
            id delegate = [self valueForKey:@"_delegate"];
            if ([delegate isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")])
                [[YTPSpeedMaster sharedMaster] manageSpeedMaster:gesture playerOverlayVC:delegate];
        }
    }
}
%end
%hook YTHUDMessageView
- (instancetype)initWithMessage:(id)message dismissHandler:(id)handler {
    if (ytpBool(@"noHudMsgs")) return nil;
    return %orig;
}
%end
%end
void YTLInstallPlaybackOptionsHooks(void) {
    objc_property_attribute_t attributes[] = {
        {"T", "@\"YTVideoQualitySwitchRedesignedController\""}, {"&", ""}, {"N", ""}
    };
    class_addProperty(NSClassFromString(@"YTVideoQualitySwitchOriginalController"), "redesignedController", attributes, 3);
    %init(YTLPlaybackOptions);
}
