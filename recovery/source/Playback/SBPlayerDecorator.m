#import "SBPlayerDecorator.h"
#import "SBManager.h"
#import "PlaybackHost.h"
#import "../Models/SBSegment.h"
#import "../Models/SBPlayerDecorationData.h"
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <objc/runtime.h>
#import <math.h>

@protocol YTLDecorationPlayerBar <NSObject>
- (UILabel *)durationLabel;
- (void)setSbTimeString:(NSString *)string;
@end
@protocol YTLDecorationOverlay <NSObject>
- (id<YTLDecorationPlayerBar>)playerBar;
@end
@protocol YTLDecorationRootView <NSObject>
- (id<YTLDecorationOverlay>)overlayView;
@end
@protocol YTLDecorationController <NSObject>
- (id)parentViewController;
- (id<YTLDecorationRootView>)view;
- (NSString *)contentVideoID;
- (double)currentVideoTotalMediaTime;
- (BOOL)isFullscreen;
@end
@interface UIView (YTLDecorationHost)
- (id<YTLDecorationController>)_viewControllerForAncestor;
@end

static NSUserDefaults *YTLDecorationPreferences(void) {
    return [(Class<YTLPlaybackPreferences>)NSClassFromString(@"YTLUserDefaults") standardUserDefaults];
}

static UIColor *YTLDecorationColor(NSString *key) {
    NSData *data = [YTLDecorationPreferences() objectForKey:key];
    return [NSKeyedUnarchiver unarchivedObjectOfClass:UIColor.class fromData:data error:NULL];
}

@implementation SBPlayerDecorator

// 0x19b714..0x19c5fc. The implementation uses the FIRST object argument as the
// player; the second argument is unused. All nonzero category modes contribute
// duration, including manual skipping. Overlapping intervals are not merged.
+ (void)addDurationWithoutSegments:(id<YTLDecorationController>)player videoController:(id)unusedController {
    (void)unusedController;
    if (![[player parentViewController] isKindOfClass:NSClassFromString(@"YTWatchViewController")]) return;
    if (![player contentVideoID] || [player currentVideoTotalMediaTime] == 0.0) return;
    NSArray<SBSegment *> *segments = [[SBManager sharedManager].segments objectForKey:[player contentVideoID]];
    if (!segments) return;

    double skipped = 0.0;
    for (SBSegment *segment in segments) {
        NSString *key = [NSString stringWithFormat:@"sb_%@", segment.category];
        if ([YTLDecorationPreferences() integerForKey:key] != 0 &&
            ![segment.category isEqualToString:@"poi_highlight"]) {
            skipped += segment.end - segment.start;
        }
    }
    double total = [player currentVideoTotalMediaTime];
    if (![[[player view] overlayView] isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayView")]) return;
    double remaining = total - skipped;
    id<YTLDecorationOverlay> overlay = [[player view] overlayView];
    if (remaining == total) {
        [[overlay playerBar] setSbTimeString:nil];
        return;
    }

    NSDateComponentsFormatter *formatter = [NSDateComponentsFormatter new];
    formatter.unitsStyle = NSDateComponentsFormatterUnitsStylePositional;
    formatter.zeroFormattingBehavior = NSDateComponentsFormatterZeroFormattingBehaviorPad;
    formatter.allowedUnits = remaining < 3600.0 ? (NSCalendarUnitMinute | NSCalendarUnitSecond) :
        (NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond);
    NSString *formatted = [formatter stringFromTimeInterval:remaining];
    UILabel *label = [[overlay playerBar] durationLabel];
    [[overlay playerBar] setSbTimeString:formatted];
    if (![label.text containsString:formatted]) {
        label.text = [label.text stringByAppendingString:[NSString stringWithFormat:@" (%@)", formatted]];
        [label sizeToFit];
    }
}

// 0x19c600. The original checks for `fullscreen` but then calls `isFullscreen`.
+ (BOOL)shouldDrawRoundedForBarView:(UIView *)barView {
    if (![[barView _viewControllerForAncestor]
            isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")]) return NO;
    id<YTLDecorationController> overlay = [barView _viewControllerForAncestor];
    if (![[overlay parentViewController] isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) return NO;
    id<YTLDecorationController> player = [overlay parentViewController];
    if (![[player parentViewController] isKindOfClass:NSClassFromString(@"YTWatchViewController")]) return NO;
    id<YTLDecorationController> watch = [player parentViewController];
    if (![watch respondsToSelector:NSSelectorFromString(@"fullscreen")]) return NO;
    return [watch isFullscreen];
}

// 0x19ce04. An empty, nonnil segment array still creates a decoration object.
+ (SBPlayerDecorationData *)_decorationDataForBarView:(UIView *)barView {
    if (![YTLDecorationPreferences() boolForKey:@"sponsorBlock"]) return nil;
    if (![[barView _viewControllerForAncestor]
            isKindOfClass:NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController")]) return nil;
    id<YTLDecorationController> overlay = [barView _viewControllerForAncestor];
    if (![[overlay parentViewController] isKindOfClass:NSClassFromString(@"YTPlayerViewController")]) return nil;
    id<YTLDecorationController> player = [overlay parentViewController];
    NSArray<SBSegment *> *segments = [[SBManager sharedManager].segments objectForKey:[player contentVideoID]];
    if (!segments) return nil;
    SBPlayerDecorationData *data = [SBPlayerDecorationData new];
    data.barView = barView;
    data.playerBarWidth = barView.superview.bounds.size.width;
    data.mediaDuration = [player currentVideoTotalMediaTime];
    data.segments = segments;
    return data;
}

// 0x19d6c0.
+ (void)drawSegmentsDecorationView:(UIView *)barView {
    SBPlayerDecorationData *data = [self _decorationDataForBarView:barView];
    if (data) [self _drawSegmentsForData:data];
}

// 0x19d77c. The private gradient view replaces only barView, not the scale or
// duration collected by the decoration-data factory.
+ (void)drawSegmentsOnActiveDecorationView:(UIView *)barView {
    SBPlayerDecorationData *data = [self _decorationDataForBarView:barView];
    if (data) {
        if (class_getInstanceVariable(barView.class, "_brandGradient")) {
            UIView *gradient = [barView valueForKey:@"_brandGradient"];
            if (gradient) data.barView = gradient;
        }
        [self _drawSegmentsForData:data];
    }
}

// 0x19db58..0x19ee34. This method was mostly absent from the old pseudocode;
// the source follows the actual instructions and verified two-entry branch
// tables in tools/verify_playback_tables.py. Geometry uses LAYER bounds, while
// horizontal position comes from the VIEW's frame. There is no layer cleanup.
+ (void)_drawSegmentsForData:(SBPlayerDecorationData *)data {
    UIView *bar = data.barView;
    double fullWidth = data.playerBarWidth;
    double duration = data.mediaDuration;
    double height = bar.layer.bounds.size.height;
    double width = bar.layer.bounds.size.width;
    double left = bar.frame.origin.x;
    NSUInteger rounding = 0;
    if (class_getInstanceVariable(data.barView.class, "_playedProgressRoundedCorners")) {
        rounding = [[data.barView valueForKey:@"_playedProgressRoundedCorners"] unsignedIntegerValue];
    }
    NSMutableSet<NSString *> *drawn = [NSMutableSet set];
    double right = width + left;
    for (SBSegment *segment in data.segments) {
        NSString *modeKey = [NSString stringWithFormat:@"sb_%@", segment.category];
        if ([YTLDecorationPreferences() integerForKey:modeKey] == 0) continue;
        NSString *colorKey = [NSString stringWithFormat:@"sb_%@_color", segment.category];
        UIColor *color = YTLDecorationColor(colorKey);
        double markerStart = fullWidth * (segment.start / duration);
        double markerWidth = fullWidth * ((segment.end - segment.start) / duration);
        if ([segment.category isEqualToString:@"poi_highlight"]) markerWidth = 10.0;
        double markerEnd = markerStart + markerWidth;
        if (!(markerEnd > left && markerStart < right)) continue;

        double clippedLeft = left < markerStart ? markerStart : left;
        double clippedRight = right < markerEnd ? right : markerEnd;
        double relativeLeft = clippedLeft - left;
        double relativeRight = clippedRight - left;
        CALayer *layer = [CALayer layer];
        layer.frame = CGRectMake(relativeLeft, 0, clippedRight - clippedLeft, height);
        layer.backgroundColor = color.CGColor;
        layer.zPosition = 999.0;
        if (rounding != 0 && !(relativeRight < width - 0.5 && relativeLeft > 0.5)) {
            UIRectCorner corners = 0;
            if (!(relativeLeft > 0.5)) corners |= UIRectCornerTopLeft | UIRectCornerBottomLeft;
            if (!(relativeRight < width - 0.5)) corners |= UIRectCornerTopRight | UIRectCornerBottomRight;
            double halfWidth = layer.bounds.size.width * 0.5;
            double radius = halfWidth > (double)rounding ? (double)rounding : halfWidth;
            UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:layer.bounds
                byRoundingCorners:corners cornerRadii:CGSizeMake(radius, radius)];
            CAShapeLayer *mask = [CAShapeLayer layer];
            mask.frame = layer.bounds;
            mask.path = path.CGPath;
            layer.mask = mask;
        }
        NSString *uuid = segment.uuid;
        if (![drawn containsObject:uuid]) {
            [bar.layer addSublayer:layer];
            [drawn addObject:uuid];
        }
    }
}

// 0x19ee38, once block 0x19fe84. The empty current-ID set is subtracted BEFORE
// drawing, so all previously cached layers are removed on every valid redraw.
// The cache still matters within a call: repeated UUIDs update the same layer.
+ (void)drawSegments:(UIView *)barView layer:(CALayer *)layer playerVC:(id<YTLDecorationController>)player {
    static NSMutableDictionary<NSString *, CALayer *> *layers;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ layers = [NSMutableDictionary dictionary]; });
    if (!layer || CGRectIsEmpty(layer.bounds) || !barView.window) return;
    if (!([player currentVideoTotalMediaTime] > 0.0)) return;

    NSMutableSet<NSString *> *current = [NSMutableSet set];
    NSMutableSet<NSString *> *obsolete = [NSMutableSet setWithArray:layers.allKeys];
    [obsolete minusSet:current];
    for (NSString *uuid in obsolete) {
        [layers[uuid] removeFromSuperlayer];
        [layers removeObjectForKey:uuid];
    }

    NSArray<SBSegment *> *segments = [[SBManager sharedManager].segments objectForKey:[player contentVideoID]];
    if (!segments) return;
    double fullWidth = barView.layer.bounds.size.width;
    if (!(fullWidth > 0.0)) return;
    for (SBSegment *segment in segments) {
        NSString *modeKey = [NSString stringWithFormat:@"sb_%@", segment.category];
        NSString *colorKey = [NSString stringWithFormat:@"sb_%@_color", segment.category];
        if ([YTLDecorationPreferences() integerForKey:modeKey] == 0) continue;
        UIColor *color = YTLDecorationColor(colorKey);
        double markerStart = fullWidth * (segment.start / [player currentVideoTotalMediaTime]);
        double markerWidth = fullWidth * ((segment.end - segment.start) / [player currentVideoTotalMediaTime]);
        if ([segment.category isEqualToString:@"poi_highlight"]) markerWidth = 10.0;
        if (isnan(markerStart) || !(markerWidth > 0.0)) continue;
        NSString *uuid = segment.uuid;
        [current addObject:uuid];
        CALayer *marker = layers[uuid];
        if (isnan(markerWidth)) continue;
        if (marker) {
            marker.frame = CGRectMake(markerStart, 0, markerWidth, 2.0);
            marker.backgroundColor = color.CGColor;
        } else {
            marker = [CALayer layer];
            marker.frame = CGRectMake(markerStart, 0, markerWidth, 2.0);
            marker.backgroundColor = color.CGColor;
            [layer addSublayer:marker];
            layers[uuid] = marker;
        }
    }
}

// 0x19fedc..0x1a1110. Only the first eligible chapter view receives each UUID.
// Subsequent calls append new layers; this method does not own their cleanup.
+ (void)drawSegmentableSegments:(UIView *)barView playerBar:(id)playerBar playerVC:(id<YTLDecorationController>)player {
    if (!class_getInstanceVariable([playerBar class], "_segmentViews")) return;
    NSArray<SBSegment *> *segments = [[SBManager sharedManager].segments objectForKey:[player contentVideoID]];
    if (!segments) return;
    NSMutableSet<NSString *> *drawn = [NSMutableSet set];
    NSArray<UIView *> *views = [playerBar valueForKey:@"_segmentViews"];
    double duration = [player currentVideoTotalMediaTime];
    double fullWidth = barView.bounds.size.width;
    // fmin models FMINNM's numeric result when only one operand is NaN.
    if (fmin(duration, fullWidth) <= 0.0) return;
    for (SBSegment *segment in segments) {
        NSString *modeKey = [NSString stringWithFormat:@"sb_%@", segment.category];
        NSString *colorKey = [NSString stringWithFormat:@"sb_%@_color", segment.category];
        if ([YTLDecorationPreferences() integerForKey:modeKey] == 0) continue;
        UIColor *color = YTLDecorationColor(colorKey);
        double start = segment.start;
        double end = segment.end;
        double secondStart = segment.start;
        BOOL highlight = [segment.category isEqualToString:@"poi_highlight"];
        double markerStart = fullWidth * (start / duration);
        double markerWidth = highlight ? 10.0 : fullWidth * ((end - secondStart) / duration);
        double markerEnd = markerStart + markerWidth;
        for (UIView *view in views) {
            if (!view.window || CGRectIsEmpty(view.bounds) || isnan(view.frame.origin.x)) continue;
            if (isnan(view.frame.origin.y)) continue;
            double height = view.layer.bounds.size.height;
            double width = view.layer.bounds.size.width;
            double left = view.frame.origin.x;
            if (isnan(width) || isnan(height) || !(fmin(width, height) > 0.0) || !(markerEnd > left)) continue;
            double right = left + width;
            if (!(markerStart < right)) continue;
            double clippedLeft = left < markerStart ? markerStart : left;
            double clippedRight = right < markerEnd ? right : markerEnd;
            double clippedWidth = clippedRight - clippedLeft;
            if (isnan(clippedWidth)) continue;
            double relativeX = clippedLeft - left;
            if (isnan(relativeX) || !(clippedWidth > 0.0)) continue;
            NSString *uuid = segment.uuid;
            if ([drawn containsObject:uuid]) continue;
            CALayer *marker = [CALayer layer];
            marker.frame = CGRectMake(relativeX, 0, clippedWidth, height);
            marker.backgroundColor = color.CGColor;
            [view.layer addSublayer:marker];
            [drawn addObject:uuid];
        }
    }
}

@end
