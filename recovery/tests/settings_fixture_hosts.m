#import "settings_fixture_hosts.h"
#import <objc/runtime.h>

NSUInteger SettingsChecks;
NSMutableArray<NSDictionary *> *SettingsEvents;
NSString *SettingsFixtureRoot;
SettingsMemoryDefaults *SettingsDefaults;
BOOL SettingsAuthenticated,SettingsLocked,SettingsImportSuccess;
UIViewController *SettingsLastLogin,*SettingsLastDevices;
NSUInteger SettingsLoginCalls,SettingsDeviceCalls,SettingsLogoutCalls,SettingsAuthChecks,SettingsLockChecks;
NSUInteger SettingsResetCalls,SettingsImportCalls;
UIView *SettingsExportView;
YTAlertView *SettingsLastAlert;
YTDefaultSheetController *SettingsLastSheet;
static NSMutableArray<NSDictionary *> *pending;

void SettingsCheck(BOOL condition,const char *expression,const char *file,int line) {
    SettingsChecks++;
    if(!condition){fprintf(stderr,"FAIL %s:%d: %s\n",file,line,expression);exit(1);}
}
void SettingsRecord(NSString *kind,id value) {
    if(!SettingsEvents)SettingsEvents=[NSMutableArray array];
    [SettingsEvents addObject:@{@"kind":kind,@"value":value?:NSNull.null}];
}
id SettingsLastEvent(NSString *kind) {
    for(NSDictionary *event in SettingsEvents.reverseObjectEnumerator)if([event[@"kind"] isEqual:kind])return event[@"value"];
    return nil;
}
NSUInteger SettingsEventCount(NSString *kind) {
    NSUInteger count=0;for(NSDictionary *event in SettingsEvents)if([event[@"kind"]isEqual:kind])count++;return count;
}
void SettingsResetEvents(void) { [SettingsEvents removeAllObjects]; }
void SettingsFixtureDispatchAsync(dispatch_queue_t queue,dispatch_block_t block) {
    SC(block!=nil);if(!pending)pending=[NSMutableArray array];
    [pending addObject:@{@"main":@(queue==dispatch_get_main_queue()),@"block":[block copy]}];
}
void SettingsFixtureDispatchAfter(dispatch_time_t when,dispatch_queue_t queue,dispatch_block_t block) {
    SettingsRecord(@"dispatchAfter",@(when));SettingsFixtureDispatchAsync(queue,block);
}
NSUInteger SettingsPending(void) { return pending.count; }
void SettingsDrainOne(void) {
    SC(pending.count>0);NSDictionary *entry=pending.firstObject;[pending removeObjectAtIndex:0];
    SettingsRecord(@"executingMainQueue",entry[@"main"]);((dispatch_block_t)entry[@"block"])();
}
void SettingsDrain(void) { NSUInteger guard=0;while(pending.count){SC(++guard<1000);SettingsDrainOne();} }
static NSString *fixturePath(NSString *component) {
    SC(SettingsFixtureRoot.length>0);
    NSString *path=[SettingsFixtureRoot stringByAppendingPathComponent:component];
    SC([path.stringByStandardizingPath hasPrefix:[SettingsFixtureRoot stringByAppendingString:@"/"]]);return path;
}
NSArray *SettingsFixtureSearchPaths(NSSearchPathDirectory directory,NSSearchPathDomainMask domain,BOOL expand) {
    SC(directory==NSCachesDirectory && domain==NSUserDomainMask && expand);return @[fixturePath(@"cache")];
}
NSString *SettingsFixtureTemporaryDirectory(void) { return fixturePath(@"tmp"); }
@implementation SettingsFixtureTask
- (void)resume { self.resumed=YES; }
@end
@implementation SettingsFixtureSession
+ (instancetype)sharedSession { static SettingsFixtureSession *session;if(!session)session=[self new];return session; }
- (SettingsFixtureTask *)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData *,NSURLResponse *,NSError *))handler {
    self.url=url;self.handler=handler;self.task=[SettingsFixtureTask new];return self.task;
}
@end
@implementation SettingsMemoryDefaults
- (instancetype)init { self=[super init];if(self)_values=[NSMutableDictionary dictionary];return self; }
- (id)objectForKey:(NSString *)key { return self.values[key]; }
- (NSString *)stringForKey:(NSString *)key { return [self objectForKey:key]; }
- (void)setObject:(id)object forKey:(NSString *)key { if(object)self.values[key]=object;else[self.values removeObjectForKey:key]; }
- (BOOL)boolForKey:(NSString *)key { return [[self objectForKey:key]boolValue]; }
- (void)setBool:(BOOL)value forKey:(NSString *)key { [self setObject:@(value) forKey:key]; }
- (NSInteger)integerForKey:(NSString *)key { return [[self objectForKey:key]integerValue]; }
- (void)setInteger:(NSInteger)value forKey:(NSString *)key { [self setObject:@(value) forKey:key]; }
- (float)floatForKey:(NSString *)key { return [[self objectForKey:key]floatValue]; }
- (void)setFloat:(float)value forKey:(NSString *)key { self.lastFloat=value;[self setObject:@(value) forKey:key]; }
- (void)removeObjectForKey:(NSString *)key { [self.values removeObjectForKey:key]; }
- (id)valueForKey:(NSString *)key { return [self objectForKey:key]; }
- (void)setValue:(id)value forKey:(NSString *)key { [self setObject:value forKey:key]; }
- (BOOL)synchronize { self.synchronizations++;return NO; }
- (NSString *)sbPrivateUserID { self.privateIDCalls++;return @"fixture-private"; }
- (NSString *)sbPublicUserID:(NSString *)input { self.publicIDCalls++;self.lastPublicIDInput=input;return @"fixture-public"; }
@end
// Class frontends only; no instance of NSUserDefaults/YTLUserDefaults is ever
// initialized. All instance messages go to SettingsMemoryDefaults (NSObject).
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation YTLUserDefaults
+ (YTLUserDefaults *)standardUserDefaults { return (id)SettingsDefaults; }
+ (void)importYtlSettings:(void (^)(BOOL))completion { SettingsImportCalls++;completion(SettingsImportSuccess); }
+ (void)exportYtlSettings:(UIView *)view { SettingsExportView=view; }
+ (void)resetUserDefaults { SettingsResetCalls++; }
@end
#pragma clang diagnostic pop
@implementation NSString (YTLRecoveredSettingsLocalization)
- (NSString *)ytl_localized { return [self isEqual:@"Preferences"]?@"Preferences(%@)":[@"L:" stringByAppendingString:self]; }
@end
@implementation NSBundle (YTLRecoveredSettingsBundle)
+ (NSBundle *)ytl_defaultBundle { return NSBundle.mainBundle; }
@end
@implementation NSBundle (YTLRecoveredSettingsImages)
- (UIImage *)originalImageWithName:(NSString *)name { SettingsRecord(@"originalImage",name);return [UIImage systemImageNamed:name]; }
@end
@interface YTPMedia : NSObject <YTLSettingsMedia> @end
@implementation YTPMedia
+ (UIColor *)adaptiveBackgroundColor { return [UIColor colorWithRed:0.1 green:0.2 blue:0.3 alpha:1]; }
+ (UIImage *)imageWithName:(NSString *)name { SettingsRecord(@"mediaImage",name);return [UIImage systemImageNamed:name]; }
@end
@implementation ABCSwitch
- (void)setOn:(BOOL)on animated:(BOOL)animated userGenerated:(BOOL)userGenerated {
    _on=on;SettingsRecord(@"switchSet",@[@(on),@(animated),@(userGenerated)]);
    if(userGenerated)[self sendActionsForControlEvents:UIControlEventValueChanged];
}
- (void)prepareHapticFeedback { SettingsRecord(@"haptic",@"prepare"); }
- (void)releaseHapticFeedback { SettingsRecord(@"haptic",@"release"); }
- (void)fireHapticFeedback { SettingsRecord(@"haptic",@"fire"); }
@end
@implementation YTQTMButton
+ (instancetype)iconButton { return [self new]; }
- (void)enableNewTouchFeedback { SettingsRecord(@"touchFeedback",@YES); }
@end
@implementation UIColorWell
- (void)styleRequestedColorPickerPresentation { SettingsRecord(@"colorPicker",@YES); }
@end
@implementation SettingsFixtureHeader
- (void)hideRightNavigationButtons { SettingsRecord(@"hideHeaderButtons",@YES); }
- (void)updateHeaderWithButtonsToDisplay:(NSArray *)buttons { self.buttons=buttons;SettingsRecord(@"headerButtons",buttons); }
@end
@implementation YTHeaderContentComboViewController
- (instancetype)init { self=[super init];if(self)_headerViewController=[SettingsFixtureHeader new];return self; }
- (void)refreshPivotBar { SettingsRecord(@"refreshPivotBar",@YES); }
@end
@implementation YTWrapperFlatViewController
- (instancetype)initWithParentResponder:(id)responder { self=[super init];if(self){_recoveredResponder=responder;_headerViewController=[SettingsFixtureHeader new];}return self; }
@end
@implementation YTWrapperSplitViewController @end
@implementation YTAlertView
- (instancetype)init { self=[super init];if(self){_actions=[NSMutableArray array];_actionTitles=[NSMutableArray array];}return self; }
+ (instancetype)dialog { SettingsLastAlert=[self new];return SettingsLastAlert; }
+ (instancetype)infoDialog { return [self dialog]; }
+ (instancetype)confirmationDialogWithAction:(void (^)(void))action actionTitle:(NSString *)title cancelTitle:(NSString *)cancel {
    YTAlertView *view=[self dialog];view.confirmation=action;view.actionTitle=title;view.cancelTitle=cancel;return view;
}
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action { [_actionTitles addObject:title];[_actions addObject:action?[action copy]:NSNull.null]; }
- (CGRect)frameForDialog { return CGRectMake(0,0,320,200); }
- (void)show { self.shown=YES; }
@end
@interface SettingsSheetHeader : UIView
@property(nonatomic,strong) UILabel *subtitleLabel;
@end
@implementation SettingsSheetHeader
- (instancetype)init { self=[super init];if(self)_subtitleLabel=[UILabel new];return self; }
@end
@implementation YTDefaultSheetController
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent {
    SC(delegate==nil && parent==nil);YTDefaultSheetController *sheet=[self new];sheet.message=message;sheet.subMessage=subMessage;
    sheet.actions=[NSMutableArray array];sheet.headerView=[SettingsSheetHeader new];SettingsLastSheet=sheet;return sheet;
}
- (void)addAction:(id)action { [self.actions addObject:action]; }
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion {
    SC(completion==nil);self.presentedFrom=controller;self.animated=animated;
}
@end
@implementation YTActionSheetAction
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(YTActionSheetAction *))handler {
    SC(secondary==nil && identifier==nil);YTActionSheetAction *action=[self new];action.title=title;action.iconImage=icon;action.handler=handler;return action;
}
@end
@interface ToastManager : NSObject <YTLSettingsToast> @end
@implementation ToastManager
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success { SettingsRecord(@"toast",@{@"text":text,@"success":@(success)}); }
@end
@interface DVNMediaPicker : NSObject <YTLSettingsMediaPicker> @end
@implementation DVNMediaPicker
+ (instancetype)sharedPicker { static DVNMediaPicker *picker;if(!picker)picker=[self new];return picker; }
- (void)presentImagePickerForVC:(UIViewController *)controller { SettingsRecord(@"imagePicker",controller); }
@end
BOOL dvnCheck(void) { SettingsAuthChecks++;return SettingsAuthenticated; }
BOOL dvnLocked(void) { SettingsLockChecks++;return SettingsLocked; }
void DVNPatreonLogin(UIViewController *controller) { SettingsLoginCalls++;SettingsLastLogin=controller; }
void DVNPatreonOpenDevices(UIViewController *controller) { SettingsDeviceCalls++;SettingsLastDevices=controller; }
void DVNPatreonLogout(void) { SettingsLogoutCalls++; }
