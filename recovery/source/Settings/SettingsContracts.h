#import <UIKit/UIKit.h>
#import "../Models/DVNCell.h"
#import "../Models/DVNSection.h"
#import "../Models/DVNTableModel.h"
#import "../../../Utils/YTLUserDefaults.h"

// Implemented by the host localization utility. This declaration does not
// introduce a replacement localization path or silently substitute a key.
@interface NSString (YTLRecoveredSettingsLocalization)
- (NSString *)ytl_localized;
@end

// Narrow declarations for host-owned APIs. Implementations remain in YouTube
// or the corresponding recovered class; no fallback objects are fabricated.
@protocol YTLSettingsMedia <NSObject>
+ (UIColor *)adaptiveBackgroundColor;
+ (UIImage *)imageWithName:(NSString *)name;
@end

@interface YTLSettingsHostHeader : UIViewController
- (void)hideRightNavigationButtons;
- (void)refreshPivotBar;
- (void)updateHeaderWithButtonsToDisplay:(NSArray *)buttons;
@end

@interface YTLSettingsHostWrapper : UIViewController
- (instancetype)initWithParentResponder:(id)responder;
@property(nonatomic, strong) UIViewController *content;
@property(nonatomic, strong) UIViewController *secondViewController;
@property(nonatomic, readonly) YTLSettingsHostHeader *headerViewController;
@end

@interface YTLSettingsHostSwitch : UIControl
@property(nonatomic, strong) UIColor *onTintColor;
@property(nonatomic, strong) UIColor *offTrackColor;
@property(nonatomic, getter=isOn) BOOL on;
- (void)setOn:(BOOL)on animated:(BOOL)animated userGenerated:(BOOL)userGenerated;
- (void)prepareHapticFeedback;
- (void)releaseHapticFeedback;
- (void)fireHapticFeedback;
@end

@interface YTLSettingsHostButton : UIButton
+ (instancetype)iconButton;
- (void)enableNewTouchFeedback;
@end

@interface YTLSettingsHostAlert : UIView
+ (instancetype)dialog;
+ (instancetype)infoDialog;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *subtitle;
@property(nonatomic, strong) UIView *customContentView;
- (void)addTitle:(NSString *)title withAction:(void (^)(void))action;
- (CGRect)frameForDialog;
- (void)show;
@end

// UIColorWell and UIButton's menu APIs are messaged unconditionally by the
// original. Dynamic lookup preserves that behavior on its iOS 13 deployment
// target without falsely declaring the whole recovered controller iOS 14-only.
@interface YTLSettingsHostColorWell : UIControl
@property(nonatomic, copy) NSString *title;
@property(nonatomic) BOOL supportsAlpha;
@property(nonatomic, strong) UIColor *selectedColor;
- (void)styleRequestedColorPickerPresentation;
@end

@protocol YTLSettingsButtonMenu <NSObject>
- (void)setMenu:(UIMenu *)menu;
- (void)setShowsMenuAsPrimaryAction:(BOOL)primary;
@end

@protocol YTLSettingsToast <NSObject>
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success;
@end

// DVNStoredBlock is storage-only. These are the recovered invoke signatures:
// 0x11fc5c, 0x11fcc4, 0x11ff68, 0x11d478, 0x118cc8, 0x124338.
typedef void (^YTLSettingsHandler)(void);
typedef void (^YTLSettingsCellHandler)(DVNCell *cell);
typedef void (^YTLSettingsCompletionHandler)(void (^completion)(void));
typedef NSString *(^YTLSettingsSubtitleProvider)(void);
typedef NSArray *(^YTLSettingsTitlesProvider)(void);
typedef NSString *(^YTLSettingsValidationHandler)(NSString *text);

@interface NSBundle (YTLRecoveredSettingsBundle)
+ (NSBundle *)ytl_defaultBundle;
@end

@interface NSBundle (YTLRecoveredSettingsImages)
- (UIImage *)originalImageWithName:(NSString *)name;
@end

@interface YTLSettingsHostAlert (YTLRecoveredSettingsConfirmation)
+ (instancetype)confirmationDialogWithAction:(void (^)(void))action
                                actionTitle:(NSString *)actionTitle
                                cancelTitle:(NSString *)cancelTitle;
@end

@protocol YTLSettingsMediaPicker <NSObject>
+ (instancetype)sharedPicker;
- (void)presentImagePickerForVC:(UIViewController *)controller;
@end

@interface YTLSettingsHostSheet : NSObject
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage
                                  delegate:(id)delegate parentResponder:(id)parentResponder;
@property(nonatomic, strong) UIView *sourceView;
- (void)addAction:(id)action;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end

@class YTActionSheetAction;
@protocol YTLSettingsSheetAction <NSObject>
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)iconImage
            secondaryIconImage:(UIImage *)secondaryIconImage accessibilityIdentifier:(NSString *)identifier
                       handler:(void (^)(YTActionSheetAction *))handler;
@end

// Account-service entry points were removed from this local-only build.
