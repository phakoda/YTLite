#pragma once
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "settings_fixture_redirects.h"
#import "../source/Settings/SettingsContracts.h"
#import "../source/Settings/DVNTableViewController.h"
#import "../source/Settings/DVNSupportersVC.h"

extern NSUInteger SettingsChecks;
extern CGFloat SettingsMeasuredFooterHeight;
extern NSMutableArray<NSDictionary *> *SettingsEvents;
extern NSString *SettingsFixtureRoot;
void SettingsCheck(BOOL condition,const char *expression,const char *file,int line);
#define SC(...) SettingsCheck((__VA_ARGS__),#__VA_ARGS__,__FILE__,__LINE__)
void SettingsDrain(void);
void SettingsDrainOne(void);
NSUInteger SettingsPending(void);
void SettingsResetEvents(void);
id SettingsLastEvent(NSString *kind);
NSUInteger SettingsEventCount(NSString *kind);
extern BOOL SettingsAuthenticated,SettingsLocked,SettingsImportSuccess;
extern UIViewController *SettingsLastLogin,*SettingsLastDevices;
extern NSUInteger SettingsLoginCalls,SettingsDeviceCalls,SettingsLogoutCalls,SettingsAuthChecks,SettingsLockChecks;
extern NSUInteger SettingsResetCalls,SettingsImportCalls;
extern UIView *SettingsExportView;

@interface SettingsMemoryDefaults : NSObject
@property(nonatomic,strong) NSMutableDictionary *values;
@property(nonatomic) NSUInteger synchronizations,publicIDCalls,privateIDCalls;
@property(nonatomic) float lastFloat;
@property(nonatomic,copy) NSString *lastPublicIDInput;
- (id)objectForKey:(NSString *)key;
- (NSString *)stringForKey:(NSString *)key;
- (void)setObject:(id)object forKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key; - (void)setBool:(BOOL)value forKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key; - (void)setInteger:(NSInteger)value forKey:(NSString *)key;
- (float)floatForKey:(NSString *)key; - (void)setFloat:(float)value forKey:(NSString *)key;
- (void)removeObjectForKey:(NSString *)key;
- (BOOL)synchronize;
- (NSString *)sbPrivateUserID;
- (NSString *)sbPublicUserID:(NSString *)input;
@end
extern SettingsMemoryDefaults *SettingsDefaults;

@interface ABCSwitch : UIControl
@property(nonatomic,strong) UIColor *onTintColor,*offTrackColor;
@property(nonatomic,getter=isOn) BOOL on;
- (void)setOn:(BOOL)on animated:(BOOL)animated userGenerated:(BOOL)userGenerated;
- (void)prepareHapticFeedback; - (void)releaseHapticFeedback; - (void)fireHapticFeedback;
@end
@interface YTQTMButton : UIButton
+ (instancetype)iconButton; - (void)enableNewTouchFeedback;
@end
@interface UIColorWell : UIControl
@property(nonatomic,copy) NSString *title;
@property(nonatomic) BOOL supportsAlpha;
@property(nonatomic,strong) UIColor *selectedColor;
- (void)styleRequestedColorPickerPresentation;
@end
@interface SettingsFixtureHeader : UIViewController
@property(nonatomic,strong) NSArray *buttons;
- (void)hideRightNavigationButtons;
- (void)updateHeaderWithButtonsToDisplay:(NSArray *)buttons;
@end
@interface YTHeaderContentComboViewController : UIViewController
@property(nonatomic,strong) SettingsFixtureHeader *headerViewController;
- (void)refreshPivotBar;
@end
@interface YTWrapperFlatViewController : UIViewController
@property(nonatomic,strong) UIViewController *content;
@property(nonatomic,strong) SettingsFixtureHeader *headerViewController;
@property(nonatomic,weak) id recoveredResponder;
- (instancetype)initWithParentResponder:(id)responder;
@end
@interface YTWrapperSplitViewController : YTWrapperFlatViewController
@property(nonatomic,strong) UIViewController *secondViewController;
@end
@interface YTAlertView : UIView
@property(nonatomic,copy) NSString *title,*subtitle;
@property(nonatomic,strong) UIView *customContentView;
@property(nonatomic,strong) NSMutableArray *actionTitles,*actions;
@property(nonatomic,copy) void (^confirmation)(void);
@property(nonatomic,copy) NSString *actionTitle,*cancelTitle;
@property(nonatomic) BOOL shown;
+ (instancetype)dialog; + (instancetype)infoDialog;
+ (instancetype)confirmationDialogWithAction:(void (^)(void))action actionTitle:(NSString *)title cancelTitle:(NSString *)cancel;
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action;
- (CGRect)frameForDialog;
- (void)show;
@end
extern YTAlertView *SettingsLastAlert;
@interface YTActionSheetAction : NSObject
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UIImage *iconImage;
@property(nonatomic,copy) void (^handler)(YTActionSheetAction *);
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(YTActionSheetAction *))handler;
@end
@interface YTDefaultSheetController : NSObject
@property(nonatomic,copy) NSString *message,*subMessage;
@property(nonatomic,strong) UIView *sourceView;
@property(nonatomic,strong) UIViewController *presentedFrom;
@property(nonatomic,strong) NSMutableArray<YTActionSheetAction *> *actions;
@property(nonatomic,strong) UIView *headerView;
@property(nonatomic) BOOL animated;
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent;
- (void)addAction:(id)action;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
extern YTDefaultSheetController *SettingsLastSheet;

// Protocol declarations used for invoking implemented methods from tests.
// No implementations are introduced by these categories.
@interface DVNTableViewController (SettingsFixtureSignatures)
- (NSInteger)numberOfSectionsInTableView:(UITableView *)table;
- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView *)table heightForRowAtIndexPath:(NSIndexPath *)path;
- (CGFloat)tableView:(UITableView *)table heightForFooterInSection:(NSInteger)section;
- (NSString *)tableView:(UITableView *)table titleForHeaderInSection:(NSInteger)section;
- (NSString *)tableView:(UITableView *)table titleForFooterInSection:(NSInteger)section;
- (void)tableView:(UITableView *)table willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section;
- (void)tableView:(UITableView *)table willDisplayFooterView:(UIView *)view forSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)table cellForRowAtIndexPath:(NSIndexPath *)path;
- (void)tableView:(UITableView *)table didSelectRowAtIndexPath:(NSIndexPath *)path;
- (BOOL)tableView:(UITableView *)table canEditRowAtIndexPath:(NSIndexPath *)path;
- (BOOL)tableView:(UITableView *)table canMoveRowAtIndexPath:(NSIndexPath *)path;
- (NSIndexPath *)tableView:(UITableView *)table targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)source toProposedIndexPath:(NSIndexPath *)proposed;
- (void)tableView:(UITableView *)table moveRowAtIndexPath:(NSIndexPath *)source toIndexPath:(NSIndexPath *)destination;
- (UITableViewCellEditingStyle)tableView:(UITableView *)table editingStyleForRowAtIndexPath:(NSIndexPath *)path;
- (void)tableView:(UITableView *)table commitEditingStyle:(UITableViewCellEditingStyle)style forRowAtIndexPath:(NSIndexPath *)path;
- (UIView *)pickerView:(UIPickerView *)picker viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView *)view;
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)picker;
- (NSInteger)pickerView:(UIPickerView *)picker numberOfRowsInComponent:(NSInteger)component;
- (void)pickerView:(UIPickerView *)picker didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
- (BOOL)textFieldShouldReturn:(UITextField *)text;
- (void)searchBar:(UISearchBar *)bar textDidChange:(NSString *)text;
- (void)searchBarSearchButtonClicked:(UISearchBar *)bar;
- (void)searchBarCancelButtonClicked:(UISearchBar *)bar;
- (void)searchBarTextDidBeginEditing:(UISearchBar *)bar;
- (void)searchBarTextDidEndEditing:(UISearchBar *)bar;
@end
@interface DVNSupportersVC (SettingsFixtureSignatures)
- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation;
- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation;
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error;
@end
