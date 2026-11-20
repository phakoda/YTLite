#import "CompatibilityVersionHost.h"
#import "../../../Utils/NSBundle+YTLite.h"
#import "../SleepTimer/YTPSleepTimer.h"
#import "../Helpers/YTPPlayerHelper.h"
#import <objc/runtime.h>

%group YTLCompatibilityVersion
%hook YTIIcon
- (int)iconType {
    // The package calls the original separately for every comparison.
    if (%orig==1154) return 65;
    if (%orig==1155) return 66;
    if (%orig==1157) return 776;
    if (%orig==1161) return 734;
    if (%orig==1162) return 44;
    if (%orig==1160) return 60;
    if (%orig==1156) return 355;
    return %orig;
}
%end
%hook QTMIcon
+ (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color {
    if ([name isEqualToString:@"youtube_outline/moon_z_24pt"]) return [[NSBundle ytl_defaultBundle] imageWithName:@"moon" tintColor:color];
    return %orig;
}
%end
%hook YTELMResourceLoader
- (UIImage *)imageWithName:(NSString *)name color:(UIColor *)color bundleId:(NSString *)bundleID {
    if ([name isEqualToString:@"ic_shorts_like_outline_32dp"]) name=@"ic_shorts_thumb_up_filled_style_c";
    if ([name isEqualToString:@"ic_shorts_like_fill_32dp"]) name=@"ic_shorts_thumb_up_colored_style_c";
    if ([name isEqualToString:@"ic_shorts_dislike_outline_32dp"]) name=@"ic_shorts_thumb_down_filled_style_c";
    if ([name isEqualToString:@"ic_shorts_dislike_fill_32dp"]) name=@"ic_shorts_thumb_down_colored_style_c";
    if ([name isEqualToString:@"ic_shorts_comment_outline_32dp"]) name=@"ic_shorts_comment_filled_style_c";
    if ([name isEqualToString:@"ic_shorts_share_outline_32dp"]) name=@"ic_shorts_share_filled_style_c";
    if ([name isEqualToString:@"ic_shorts_remix_outline_32dp"]) name=@"ic_remix_filled";
    if ([name isEqualToString:@"youtube_shorts_24_cairo"]) name=@"youtube_shorts_24";
    return %orig(name,color,bundleID);
}
%end
%hook YTWatchFloatingMiniplayerWithControlsOverlayView
- (void)layoutSubviews { %orig; self.layer.cornerRadius=12; self.layer.masksToBounds=YES; }
%end
%hook YTVersionUtils
+ (NSString *)appVersion { return @"20.21.6"; }
%end
%hook YTSettingsCell
- (void)setDetailText:(NSString *)text {
    if ([text isEqualToString:@"20.21.6"]) text=NSBundle.mainBundle.infoDictionary[@"CFBundleShortVersionString"];
    %orig(text);
}
%end
%hook ELMTouchCommandPropertiesHandler
- (void)handleTap {
    if (!class_getInstanceVariable(self.class,"_controller")) { %orig; return; }
    id<YTLVersionController> controller=[self valueForKey:@"_controller"];
    id<YTLVersionNode> node=controller.node;
    NSString *identifier=[(NSObject *)node valueForKey:@"_accessibilityIdentifier"];
    if ([identifier hasPrefix:@"id.elements.components.overflow_menu_item_"]) {
        if ([node.subnodes[0] isKindOfClass:%c(ASNetworkImageNode)]) {
            ASNetworkImageNode *imageNode=node.subnodes[0];
            if ([imageNode.image.accessibilityIdentifier isEqualToString:@"ytp_moon_image"]) {
                if ([node.closestViewController isKindOfClass:%c(YTActionSheetDialogViewController)]) [node.closestViewController dismissViewControllerAnimated:YES completion:nil];
                [[YTPSleepTimer sharedTimer] showOptions:nil];
                return;
            }
        }
    }
    if ([identifier isEqualToString:@"eml.vwc"]) {
        id<YTLVersionNode> parent=node.yogaParent;
        if ([parent isKindOfClass:%c(YTVideoWithContextNode)] && [parent.parentResponder isKindOfClass:%c(YTCellController)]) {
            YTCellController *cell=parent.parentResponder;
            NSString *description=[cell.entry description];
            if ([description containsString:@"https://i.ytimg.com/vi/"]) {
                [YTPPlayerHelper openVideoWithID:[YTPPlayerHelper getVideoID:description] handler:self];
                return;
            }
        }
    }
    %orig;
}
%end
%end

void YTLInstallCompatibilityVersionHooks(void) {
    NSString *version=[NSBundle.mainBundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
    if ([version compare:@"20.21.6" options:NSNumericSearch]==NSOrderedAscending) {
        %init(YTLCompatibilityVersion);
    }
}
