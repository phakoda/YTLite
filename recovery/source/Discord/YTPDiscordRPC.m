#import "YTPDiscordRPC.h"
#import "../Models/RPCMedia.h"
#import "../../../Utils/YTLUserDefaults.h"
#import "../../../Utils/NSString+YTLite.h"
#import <UIKit/UIKit.h>

@protocol YTLDiscordAlert <NSObject>
+ (instancetype)dialog;
- (void)setTitle:(NSString *)title;
- (void)setSubtitle:(NSString *)subtitle;
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action;
- (void)show;
@end

@implementation YTPDiscordRPC
@synthesize media = _media, serverURL = _serverURL;

+ (instancetype)sharedPresence {
    static YTPDiscordRPC *presence;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ presence = [[self alloc] init]; });
    return presence;
}

+ (void)checkLocalNetworkPermission:(void (^)(BOOL, BOOL))completion {
    NSURL *url = [NSURL URLWithString:[YTPDiscordRPC sharedPresence].serverURL];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    request.timeoutInterval = 3.0;
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:
      ^(NSData *data, NSURLResponse *response, NSError *error) {
        BOOL permitted = YES;
        BOOL serverAvailable = YES;
        if (error) {
            if (error.code == -1009) {
                permitted = NO;
                serverAvailable = NO;
            } else {
                serverAvailable = error.code != -1004;
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{ completion(permitted, serverAvailable); });
    }] resume];
}

- (void)setServerURL:(NSString *)serverURL {
    NSString *address = serverURL;
    if ([address hasPrefix:@"https://"]) {
        address = [@"http://" stringByAppendingString:[address substringFromIndex:8]];
    } else if (![address hasPrefix:@"http://"]) {
        address = [@"http://" stringByAppendingString:address];
    }
    NSURLComponents *components = [NSURLComponents componentsWithString:address];
    if (!components.port) components.port = @5001;
    if (!components.path || components.path.length == 0 || [components.path isEqualToString:@"/"]) {
        components.path = @"/update";
    }
    _serverURL = components.URL.absoluteString;
}

- (void)startIfPossible {
    YTLUserDefaults *defaults = [YTLUserDefaults standardUserDefaults];
    if (![defaults boolForKey:@"discordRPC"]) return;
    NSString *address = [defaults stringForKey:@"rpcAddress"];
    if (!address) {
        [self showAlertWithMessage:@"RPC.MissingServerAddress" showSettingsButton:NO];
        return;
    }
    // The package probes the singleton's existing URL before assigning this address.
    [YTPDiscordRPC checkLocalNetworkPermission:^(BOOL permitted, BOOL serverAvailable) {
        if (permitted && serverAvailable) {
            self.serverURL = address;
            [self startRPC];
        } else if (!permitted) {
            [self showAlertWithMessage:@"RPC.LocalPermissionRequired" showSettingsButton:YES];
        } else if (!serverAvailable && ![defaults boolForKey:@"rpcNoServerAlerts"]) {
            [self showAlertWithMessage:@"RPC.DesktopServerRequired" showSettingsButton:NO];
        }
    }];
}

- (void)startRPC {
    if (!self.media || [self.media.videoID isEqualToString:_currentVideoID]) return;
    _currentVideoID = self.media.videoID;
    _lastSendDate = nil;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        if ([self.media.videoID isEqualToString:self->_currentVideoID]) {
            self.media.isPaused = NO;
            [self sendBody];
        }
    });
}

- (void)updateTime {
    if (self.media && [self.media.videoID isEqualToString:_currentVideoID]) [self sendBody];
}

- (void)updateState {
    if (self.media && [self.media.videoID isEqualToString:_currentVideoID]) [self sendBody];
}

- (void)clearPlayback {
    if (!self.media) return;
    self.media = nil;
    _currentVideoID = nil;
    _lastSendDate = nil;
    [self _send:@{@"state": @"stopped"}];
}

- (NSDictionary *)buildBody {
    if (!self.media) return nil;
    return @{@"title": self.media.title ?: @"",
             @"channel": self.media.author ?: @"",
             @"video_id": self.media.videoID ?: @"",
             @"thumbnail_url": self.media.thumbnailURL ?: @"",
             @"current_time": @(self.media.currentTime),
             @"total_time": @(self.media.totalTime),
             @"state": self.media.isPaused ? @"paused" : @"playing"};
}

- (void)sendBody {
    NSDictionary *body = [self buildBody];
    if (!body) return;
    NSDate *now = [NSDate date];
    if (_lastSendDate && [now timeIntervalSinceDate:_lastSendDate] < 1.0) return;
    _lastSendDate = now;
    [self _send:body];
}

- (void)_send:(NSDictionary *)body {
    NSURL *url = [NSURL URLWithString:self.serverURL];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    request.HTTPMethod = @"POST";
    request.timeoutInterval = 5.0;
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    request.HTTPBody = [NSJSONSerialization dataWithJSONObject:body options:0 error:NULL];
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:
      ^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) NSLog(@"DVN --- Error: %@", error.localizedDescription);
    }] resume];
}

- (void)showAlertWithMessage:(NSString *)message showSettingsButton:(BOOL)showSettingsButton {
    id<YTLDiscordAlert> dialog = [(Class<YTLDiscordAlert>)NSClassFromString(@"YTAlertView") dialog];
    [dialog setTitle:[@"YouTube Plus Discord RPC" ytl_localized]];
    [dialog setSubtitle:[message ytl_localized]];
    if (showSettingsButton) {
        [dialog addTitle:[@"RPC.OpenSettings" ytl_localized] withAction:^{
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]
                                               options:@{} completionHandler:nil];
        }];
    }
    [dialog addTitle:@"OK" withAction:nil];
    [dialog show];
}
@end
