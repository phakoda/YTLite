#import "YTPPlayerHelper.h"
#import "../Controls/ControlsHost.h"
#import <objc/runtime.h>

@protocol YTLNavigationCommand <NSObject>
+ (id)watchNavigationEndpointWithVideoID:(id)videoID;
@end
@protocol YTLNavigationEvent <NSObject>
+ (id<YTLNavigationEvent>)eventWithCommand:(id)command fromView:(UIView *)view
    entry:(id)entry sendClick:(BOOL)click firstResponder:(id)responder;
- (void)send;
@end

static NSString *YTLVideoInputString(id value) {
    if ([value isKindOfClass:[NSString class]]) return value;
    if ([value isKindOfClass:[NSURL class]]) return [value absoluteString];
    return nil;
}
static id YTLWatchCommand(id videoID) {
    return [(Class<YTLNavigationCommand>)NSClassFromString(@"YTICommand") watchNavigationEndpointWithVideoID:videoID];
}
static void YTLSendWatchCommand(id command, UIView *view, id entry, id responder) {
    Class<YTLNavigationEvent> factory = (Class<YTLNavigationEvent>)NSClassFromString(@"YTCommandResponderEvent");
    [[factory eventWithCommand:command fromView:view entry:entry sendClick:NO firstResponder:responder] send];
}

@implementation YTPPlayerHelper
// 0x1f2660: this helper extracts thumbnail /vi/<id>/ paths, not arbitrary
// watch URLs. Keep the original first-match regex rather than guessing IDs.
+ (NSString *)getVideoID:(id)value {
    NSString *text = YTLVideoInputString(value);
    if (!text) return nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"/vi/([^/]+)/" options:0 error:NULL];
    NSTextCheckingResult *match = [regex firstMatchInString:text options:0 range:NSMakeRange(0, text.length)];
    return match.numberOfRanges >= 2 ? [text substringWithRange:[match rangeAtIndex:1]] : nil;
}
// 0x1f2a1c: fallback to the YouTube URL handler, preserving NSURL input rules.
+ (void)openVideoWithID:(id)videoID {
    NSString *text = YTLVideoInputString(videoID);
    if (!text.length) return;
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"vnd.youtube://%@", text]];
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:nil];
}
// 0x1f2dfc: prefer the host's command responder chain when its context exists.
+ (void)openVideoWithID:(id)videoID handler:(id)handler {
    id<YTLControlsNode> node = [(id<YTLControlsNode>)[handler valueForKey:@"_controller"] node];
    if (!class_getInstanceVariable([handler class], "_context")) {
        [self openVideoWithID:videoID];
        return;
    }
    id<YTLControlsNode> context = [handler valueForKey:@"_context"];
    if (![(id)[context parentResponder] isKindOfClass:NSClassFromString(@"YTElementsCellController")]) {
        [self openVideoWithID:videoID];
        return;
    }
    id<YTLControlsNode> parent = [context parentResponder];
    id command = YTLWatchCommand(videoID);
    if (!command) [self openVideoWithID:videoID];
    else YTLSendWatchCommand(command, [node view], [parent elementEntry], parent);
}
// 0x1f3740: the controller is both entry and first responder on this path.
+ (void)openVideoWithID:(id)videoID viewController:(UIViewController *)controller {
    id command = YTLWatchCommand(videoID);
    if (!command) [self openVideoWithID:videoID];
    else YTLSendWatchCommand(command, controller.view, controller, controller);
}
@end
