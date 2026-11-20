#import "YTPMedia.h"
#import "DownloadsHost.h"
#import <math.h>
// Every icon name below is taken directly from recovery/classes/YTPMedia.c.
@implementation YTPMedia
@synthesize cairo = _cairo;
// 0x1aa774, singleton invoke 0x1aa828.
+ (instancetype)sharedMedia {
    static YTPMedia *media;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ media = [[self alloc] init]; });
    return media;
}
// 0x1aa86c; -1 is the missing-host sentinel, not dark/light mode.
+ (long long)pageStyle {
    id<YTPDownloadsPageStyle> delegate = (id)[UIApplication sharedApplication].delegate;
    if ([delegate respondsToSelector:@selector(responderRoot)]) {
        id<YTPDownloadsPageStyle> root = [delegate responderRoot];
        if ([root respondsToSelector:@selector(pageStyle)]) return [[delegate responderRoot] pageStyle];
    }
    return -1;
}
// 0x1aa9f0 / invoke 0x1aaba4. The preference is captured at creation, not re-read on resolution.
+ (UIColor *)adaptiveBackgroundColor {
    BOOL oled = [YTPDownloadsDefaults() boolForKey:@"oledTheme"];
    return [UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) {
        (void)traits;
        if ([self pageStyle] == 1) {
            return oled ? [UIColor blackColor] : [UIColor colorWithRed:0.059 green:0.059 blue:0.059 alpha:1.0];
        }
        return [UIColor whiteColor];
    }];
}
// 0x1aacd4, raw loop 0x1aae00–0x1aaf44, invoke 0x1aafcc.
// Two neutral grays (0.059, 0.129), strict <0.001 comparison, opaque alpha.
+ (UIColor *)oledForColor:(UIColor *)color {
    if ([self pageStyle] != 1) return color;
    CGFloat red, green, blue, alpha;
    if (![color getRed:&red green:&green blue:&blue alpha:&alpha]) return color;
    const double grays[] = {0.059, 0.129};
    for (NSUInteger i = 0; i < 2; ++i) {
        if (fabs(red - grays[i]) < 0.001 && fabs(green - grays[i]) < 0.001 &&
            fabs(blue - grays[i]) < 0.001 && fabs(alpha - 1.0) < 0.001) {
            return [UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) {
                (void)traits;
                return [self pageStyle] == 1 ? [UIColor blackColor] : [UIColor whiteColor];
            }];
        }
    }
    return color;
}
// 0x1ab020. No fallback for absent cairo assets and no nil substitution.
+ (UIImage *)imageWithName:(NSString *)name {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? [name stringByAppendingString:@"_cairo"] : name];
}
// 0x1ab254
+ (UIImage *)historyTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEhistory_cairo" : @"FEhistory"];
}
// 0x1ab508
+ (UIImage *)historyTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEhistory_cairo_selected" : @"FEhistory_selected"];
}
// 0x1ab8b8
+ (UIImage *)watchLaterTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"VLWL_cairo" : @"VLWL"];
}
// 0x1abadc
+ (UIImage *)watchLaterTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"VLWL_cairo_selected" : @"VLWL_selected"];
}
// 0x1abdf8
+ (UIImage *)postsTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEpost_home_cairo" : @"FEpost_home"];
}
// 0x1ac0f4
+ (UIImage *)postsTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEpost_home_cairo_selected" : @"FEpost_home_selected"];
}
// 0x1ac4f0
+ (UIImage *)hypeTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEhype_leaderboard_cairo" : @"FEhype_leaderboard"];
}
// 0x1ac8a8
+ (UIImage *)hypeTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEhype_leaderboard_cairo_selected" : @"FEhype_leaderboard_selected"];
}
// 0x1acd54
+ (UIImage *)musicTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_cairo" : @"UC-9-kyTW8ZkZNDHQJ6FgpwQ"];
}
// 0x1ad1c0
+ (UIImage *)musicTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_cairo_selected" : @"UC-9-kyTW8ZkZNDHQJ6FgpwQ_selected"];
}
// 0x1ad724
+ (UIImage *)liveTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UC4R8DWoMoI7CAwX8_LjQHig_cairo" : @"UC4R8DWoMoI7CAwX8_LjQHig"];
}
// 0x1adb88
+ (UIImage *)liveTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UC4R8DWoMoI7CAwX8_LjQHig_cairo_selected" : @"UC4R8DWoMoI7CAwX8_LjQHig_selected"];
}
// 0x1ae0d0
+ (UIImage *)gamingTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UCOpNcN46UbXVtpKMrmU4Abg_cairo" : @"UCOpNcN46UbXVtpKMrmU4Abg"];
}
// 0x1ae530
+ (UIImage *)gamingTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UCOpNcN46UbXVtpKMrmU4Abg_cairo_selected" : @"UCOpNcN46UbXVtpKMrmU4Abg_selected"];
}
// 0x1aeaa4
+ (UIImage *)sportsTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UCEgdi0XIXXZ-qJOFPf4JSKw_cairo" : @"UCEgdi0XIXXZ-qJOFPf4JSKw"];
}
// 0x1aef00
+ (UIImage *)sportsTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"UCEgdi0XIXXZ-qJOFPf4JSKw_cairo_selected" : @"UCEgdi0XIXXZ-qJOFPf4JSKw_selected"];
}
// 0x1af460
+ (UIImage *)notificationsTab {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEnotifications_inbox_cairo" : @"FEnotifications_inbox"];
}
// 0x1af858
+ (UIImage *)notificationsTabSelected {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEnotifications_inbox_cairo_selected" : @"FEnotifications_inbox_selected"];
}
// 0x1afd64
+ (UIImage *)ytPlus {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"ytl_cairo" : @"ytl_outline"];
}
// 0x1affe0
+ (UIImage *)ytPlusShorts {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"ytl_cairo" : @"ytl_icon" tintColor:[UIColor whiteColor]];
}
// 0x1b025c
+ (UIImage *)sponsorblock {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"sponsorblock_cairo" : @"sponsorblock"];
}
// 0x1b0558
+ (UIImage *)lock {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"lock_cairo" : @"lock"];
}
// 0x1b0770
+ (UIImage *)volumeOff {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"vol_off_cairo" : @"vol_off"];
}
// 0x1b09f0
+ (UIImage *)volumeOn {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"vol_on_cairo" : @"vol_on"];
}
// 0x1b0c4c
+ (UIImage *)moon {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"sleep" : @"moon"];
}
// 0x1b0e28
+ (UIImage *)downloading {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"downloading_cairo" : @"downloading"];
}
// 0x1b110c
+ (UIImage *)credits {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"credits_cairo" : @"credits"];
}
// 0x1b137c
+ (UIImage *)donor {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"donor_cairo" : @"donor"];
}
// 0x1b15c0
+ (UIImage *)feed {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"feed_cairo" : @"feed"];
}
// 0x1b17e8
+ (UIImage *)FEshorts {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEshorts_cairo" : @"FEshorts"];
}
// 0x1b1a78
+ (UIImage *)interface {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"interface_cairo" : @"interface"];
}
// 0x1b1d30
+ (UIImage *)libs {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"libs_cairo" : @"libs"];
}
// 0x1b1f50
+ (UIImage *)localization {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"localization_cairo" : @"localization"];
}
// 0x1b2264
+ (UIImage *)navbar {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"navbar_cairo" : @"navbar"];
}
// 0x1b24bc
+ (UIImage *)open_new {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"open_new_cairo" : @"open_new"];
}
// 0x1b2758
+ (UIImage *)player {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"player_cairo" : @"player"];
}
// 0x1b29ac
+ (UIImage *)support {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"support_cairo" : @"support"];
}
// 0x1b2c1c
+ (UIImage *)tabbar {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"tabbar_cairo" : @"tabbar"];
}
// 0x1b2e80
+ (UIImage *)ytl_settings {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"ytl_settings_cairo" : @"ytl_settings"];
}
// 0x1b3188
+ (UIImage *)captions {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"captions_cairo" : @"captions"];
}
// 0x1b3424
+ (UIImage *)FElibrary {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FElibrary_cairo" : @"FElibrary"];
}
// 0x1b36cc
+ (UIImage *)FEsubscriptions {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEsubscriptions_cairo" : @"FEsubscriptions"];
}
// 0x1b3a3c
+ (UIImage *)FEuploads {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEuploads_cairo" : @"FEuploads"];
}
// 0x1b3cf8
+ (UIImage *)FEwhat_to_watch {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"FEwhat_to_watch_cairo" : @"FEwhat_to_watch"];
}
// 0x1b404c
+ (UIImage *)link {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"link_cairo" : @"link"];
}
// 0x1b4280
+ (UIImage *)x_prefs {
    return [[NSBundle ytl_defaultBundle] imageWithName:@"x_prefs"];
}
// 0x1b43cc
+ (UIImage *)box_checkmark {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"box_checkmark_cairo" : @"box_checkmark"];
}
// 0x1b46f8
+ (UIImage *)box_empty {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"box_empty_cairo" : @"box_empty"];
}
// 0x1b49a8
+ (UIImage *)copy {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"copy_cairo" : @"copy"];
}
// 0x1b4bcc
+ (UIImage *)image_library {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"image_library_cairo" : @"image_library"];
}
// 0x1b4eec
+ (UIImage *)image {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"image_cairo" : @"image"];
}
// 0x1b5130
+ (UIImage *)message {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"message_cairo" : @"message"];
}
// 0x1b53a4
+ (UIImage *)music {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"music_cairo" : @"music"];
}
// 0x1b55d8
+ (UIImage *)play_circle {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"play_circle_cairo" : @"play_circle"];
}
// 0x1b58ac
+ (UIImage *)show_image {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"show_image_cairo" : @"show_image"];
}
// 0x1b5b7c
+ (UIImage *)star_half {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"star_half_cairo" : @"star_half"];
}
// 0x1b5e28
+ (UIImage *)youtube_logo {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"youtube_logo_cairo" : @"youtube_logo"];
}
// 0x1b6130
+ (UIImage *)check {
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    return [[NSBundle ytl_defaultBundle] imageWithName:cairo ? @"check_cairo" : @"check"];
}
// 0x1b636c
+ (UIImage *)empty {
    return [[NSBundle ytl_defaultBundle] imageWithName:@"empty"];
}
// 0x1b64a4
+ (UIImage *)adaptiveDiscord {
    BOOL enabled = [YTPDownloadsDefaults() boolForKey:@"discordRPC"];
    BOOL cairo = [YTPMedia sharedMedia].isCairo;
    NSString *name = enabled ? (cairo ? @"discord_fill_cairo" : @"discord_fill")
                             : (cairo ? @"discord_cairo" : @"discord");
    return [[NSBundle ytl_defaultBundle] imageWithName:name];
}
// 0x1b6a04. Numeric string comparison; absent version behaves like compare returning zero.
- (void)setCairo:(BOOL)cairo {
    NSString *version = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
    _cairo = [version compare:@"20.12.4" options:NSNumericSearch] == NSOrderedAscending ? NO : cairo;
}
// 0x1b6d3c
- (BOOL)isCairo { return _cairo; }
@end
