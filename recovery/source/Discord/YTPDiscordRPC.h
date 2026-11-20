#import <Foundation/Foundation.h>
@class RPCMedia;

@interface YTPDiscordRPC : NSObject {
    NSString *_currentVideoID;
    NSDate *_lastSendDate;
}
@property(nonatomic, strong) RPCMedia *media;
@property(nonatomic, copy) NSString *serverURL;
+ (instancetype)sharedPresence;
+ (void)checkLocalNetworkPermission:(void (^)(BOOL permitted, BOOL serverAvailable))completion;
- (void)startIfPossible;
- (void)startRPC;
- (void)updateTime;
- (void)updateState;
- (void)clearPlayback;
- (NSDictionary *)buildBody;
- (void)sendBody;
- (void)_send:(NSDictionary *)body;
- (void)showAlertWithMessage:(NSString *)message showSettingsButton:(BOOL)showSettingsButton;
@end
