#pragma once
// SETTINGS FIXTURE ONLY. Production sources compile against Apple's iOS SDK.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>

// Avoid duplicate runtime class names from macOS CoreAutoLayout.
#define NSLayoutConstraint SettingsFixtureLayoutConstraint
#define NSLayoutAnchor SettingsFixtureLayoutAnchor

typedef CGFloat UIFontWeight;
extern const UIFontWeight UIFontWeightSemibold, UIFontWeightLight, UIFontWeightRegular;
extern const CGFloat UITableViewAutomaticDimension;
extern const CGSize UILayoutFittingCompressedSize;
extern NSAttributedStringKey const NSFontAttributeName, NSForegroundColorAttributeName;
typedef NS_ENUM(NSInteger, NSTextAlignment) { NSTextAlignmentLeft,NSTextAlignmentCenter,NSTextAlignmentRight,NSTextAlignmentJustified,NSTextAlignmentNatural };
typedef NS_ENUM(NSInteger, NSLineBreakMode) { NSLineBreakByWordWrapping,NSLineBreakByCharWrapping,NSLineBreakByClipping,NSLineBreakByTruncatingHead,NSLineBreakByTruncatingTail,NSLineBreakByTruncatingMiddle };
typedef NS_OPTIONS(NSUInteger, NSStringDrawingOptions) { NSStringDrawingUsesLineFragmentOrigin=1 };
typedef struct { CGFloat top,left,bottom,right; } UIEdgeInsets;
static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat t,CGFloat l,CGFloat b,CGFloat r) { return (UIEdgeInsets){t,l,b,r}; }
typedef NS_ENUM(NSInteger, UITableViewStyle) { UITableViewStylePlain,UITableViewStyleGrouped };
typedef NS_ENUM(NSInteger, UITableViewCellStyle) { UITableViewCellStyleDefault,UITableViewCellStyleSubtitle,UITableViewCellStyleValue1,UITableViewCellStyleValue2 };
typedef NS_ENUM(NSInteger, UITableViewCellSeparatorStyle) { UITableViewCellSeparatorStyleNone,UITableViewCellSeparatorStyleSingleLine };
typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) { UITableViewCellAccessoryNone,UITableViewCellAccessoryDisclosureIndicator };
typedef NS_ENUM(NSInteger, UITableViewCellEditingStyle) { UITableViewCellEditingStyleNone,UITableViewCellEditingStyleDelete,UITableViewCellEditingStyleInsert };
typedef NS_ENUM(NSInteger, UITableViewScrollPosition) { UITableViewScrollPositionNone,UITableViewScrollPositionTop,UITableViewScrollPositionMiddle,UITableViewScrollPositionBottom };
typedef NS_ENUM(NSInteger, UITableViewRowAnimation) { UITableViewRowAnimationFade,UITableViewRowAnimationRight,UITableViewRowAnimationLeft,UITableViewRowAnimationTop,UITableViewRowAnimationBottom,UITableViewRowAnimationNone,UITableViewRowAnimationMiddle,UITableViewRowAnimationAutomatic=100 };
typedef NS_ENUM(NSInteger, UIBarButtonItemStyle) { UIBarButtonItemStylePlain,UIBarButtonItemStyleDone=2 };
typedef NSInteger UIBarButtonSystemItem;
typedef NS_ENUM(NSInteger, UIImageRenderingMode) { UIImageRenderingModeAutomatic,UIImageRenderingModeAlwaysOriginal,UIImageRenderingModeAlwaysTemplate };
typedef NS_ENUM(NSInteger, UIUserInterfaceLayoutDirection) { UIUserInterfaceLayoutDirectionLeftToRight,UIUserInterfaceLayoutDirectionRightToLeft };
typedef NS_ENUM(NSInteger, UISemanticContentAttribute) { UISemanticContentAttributeUnspecified,UISemanticContentAttributePlayback,UISemanticContentAttributeSpatial,UISemanticContentAttributeForceLeftToRight,UISemanticContentAttributeForceRightToLeft };
typedef NS_ENUM(NSInteger, UIViewContentMode) { UIViewContentModeScaleToFill,UIViewContentModeScaleAspectFit };
typedef NS_ENUM(NSInteger, UIActivityIndicatorViewStyle) { UIActivityIndicatorViewStyleMedium=100 };
typedef NS_ENUM(NSInteger, UIScrollViewContentInsetAdjustmentBehavior) { UIScrollViewContentInsetAdjustmentAutomatic,UIScrollViewContentInsetAdjustmentScrollableAxes,UIScrollViewContentInsetAdjustmentNever };
typedef NS_ENUM(NSInteger, UITextFieldViewMode) { UITextFieldViewModeNever,UITextFieldViewModeWhileEditing,UITextFieldViewModeUnlessEditing,UITextFieldViewModeAlways };
typedef NS_ENUM(NSInteger, UITextBorderStyle) { UITextBorderStyleNone };
typedef NS_ENUM(NSInteger, UIKeyboardType) { UIKeyboardTypeDefault };
typedef NS_ENUM(NSInteger, UIReturnKeyType) { UIReturnKeyDefault,UIReturnKeyDone=9 };
typedef NS_OPTIONS(NSUInteger, UIControlState) { UIControlStateNormal=0,UIControlStateSelected=4 };
typedef NS_OPTIONS(NSUInteger, UIControlEvents) { UIControlEventTouchUpInside=1UL<<6,UIControlEventValueChanged=1UL<<12,UIControlEventEditingChanged=1UL<<17 };
typedef NS_ENUM(NSInteger, UIButtonType) { UIButtonTypeCustom,UIButtonTypeSystem };
typedef NS_ENUM(NSInteger, UIMenuElementState) { UIMenuElementStateOff,UIMenuElementStateOn,UIMenuElementStateMixed };
@class UIColor,UIFont,UIView,UIViewController,UINavigationController,UITableView,UITableViewCell,UIImage,UIImageView,UILabel,UITextField,UIMenu,UIAction,UIBarButtonItem,UILayoutGuide,NSLayoutAnchor,NSLayoutConstraint,UITraitCollection;
@interface UIFont : NSObject
@property(nonatomic) CGFloat pointSize;
@property(nonatomic) UIFontWeight recoveredTestWeight;
+ (instancetype)systemFontOfSize:(CGFloat)size;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
@end
@interface UIColor : NSObject <NSSecureCoding> { CGColorRef _color; }
@property(nonatomic,readonly) CGColorRef CGColor;
@property(nonatomic) CGFloat recoveredRed,recoveredGreen,recoveredBlue,recoveredAlpha;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (instancetype)clearColor; + (instancetype)labelColor; + (instancetype)secondaryLabelColor;
+ (instancetype)grayColor; + (instancetype)blackColor; + (instancetype)whiteColor;
+ (instancetype)systemBackgroundColor; + (instancetype)systemRedColor; + (instancetype)redColor;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
- (void)setFill;
@end
@interface NSLayoutConstraint : NSObject
@property(nonatomic) BOOL active;
@property(nonatomic,strong) id firstAnchor,secondAnchor;
@property(nonatomic) CGFloat constant;
+ (void)activateConstraints:(NSArray *)constraints;
@end
@interface NSLayoutAnchor : NSObject
@property(nonatomic,weak) id owner;
@property(nonatomic,copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)constant;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)constant;
@end
@interface UILayoutGuide : NSObject
@property(nonatomic,readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*centerXAnchor,*centerYAnchor,*heightAnchor;
@end
@interface UIView : NSObject
@property(nonatomic) CGRect frame,bounds;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) UIColor *backgroundColor,*tintColor;
@property(nonatomic) BOOL translatesAutoresizingMaskIntoConstraints,clipsToBounds,opaque,userInteractionEnabled;
@property(nonatomic) NSInteger tag;
@property(nonatomic) UISemanticContentAttribute semanticContentAttribute;
@property(nonatomic) UIViewContentMode contentMode;
@property(nonatomic,readonly) NSArray<UIView *> *subviews;
@property(nonatomic,weak) UIView *superview;
@property(nonatomic,readonly) UILayoutGuide *safeAreaLayoutGuide,*layoutMarginsGuide;
@property(nonatomic,readonly) NSLayoutAnchor *topAnchor,*bottomAnchor,*leadingAnchor,*trailingAnchor,*centerXAnchor,*centerYAnchor,*heightAnchor;
@property(nonatomic) NSUInteger recoveredLayoutCalls,recoveredSizeToFitCalls,recoveredResignCalls;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
- (void)layoutSubviews; - (void)sizeToFit; - (BOOL)resignFirstResponder;
- (CGSize)systemLayoutSizeFittingSize:(CGSize)size;
+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations;
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)attribute;
@end
@interface UILabel : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,copy) NSAttributedString *attributedText;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property(nonatomic) NSTextAlignment textAlignment;
@property(nonatomic) NSLineBreakMode lineBreakMode;
@property(nonatomic) NSInteger numberOfLines;
@property(nonatomic) BOOL adjustsFontSizeToFitWidth;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *recoveredName;
@property(nonatomic) UIImageRenderingMode renderingMode;
@property(nonatomic) CGSize size;
+ (instancetype)systemImageNamed:(NSString *)name;
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits;
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode;
@end
@interface UIImageView : UIView
@property(nonatomic,strong) UIImage *image;
- (instancetype)initWithImage:(UIImage *)image;
@end
@interface NSTextAttachment : NSObject
@property(nonatomic,strong) UIImage *image;
@property(nonatomic) CGRect bounds;
@end
@interface NSAttributedString (SettingsFixtureAttachment)
+ (instancetype)attributedStringWithAttachment:(NSTextAttachment *)attachment;
@end
@interface NSString (SettingsFixtureDrawing)
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options attributes:(NSDictionary *)attributes context:(id)context;
@end
@interface UIGraphicsImageRendererContext : NSObject
@property(nonatomic) CGContextRef CGContext;
@end
@interface UIGraphicsImageRenderer : NSObject
@property(nonatomic) CGSize recoveredSize;
- (instancetype)initWithSize:(CGSize)size;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions;
@end
@interface UIScreen : NSObject
@property(nonatomic) CGRect bounds;
@property(nonatomic) CGFloat scale;
+ (instancetype)mainScreen;
@end
@interface UITraitCollection : NSObject
@property(nonatomic) BOOL recoveredDifferentAppearance;
- (BOOL)hasDifferentColorAppearanceComparedToTraitCollection:(UITraitCollection *)other;
@end
@interface UINavigationItem : NSObject
@property(nonatomic,strong) UIBarButtonItem *leftBarButtonItem,*rightBarButtonItem;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIView *view;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,weak) UIViewController *parentViewController;
@property(nonatomic,strong) UINavigationController *navigationController;
@property(nonatomic,strong) UINavigationItem *navigationItem;
@property(nonatomic,strong) UITraitCollection *traitCollection;
@property(nonatomic,readonly) BOOL recoveredLoaded;
- (void)loadView; - (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated; - (void)viewDidAppear:(BOOL)animated;
- (void)traitCollectionDidChange:(UITraitCollection *)traits;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UINavigationController : UIViewController
@property(nonatomic,strong) UIViewController *recoveredPushedController;
@property(nonatomic) BOOL recoveredPushAnimated;
- (void)pushViewController:(UIViewController *)controller animated:(BOOL)animated;
@end
@interface UIScrollView : UIView
@property(nonatomic) UIScrollViewContentInsetAdjustmentBehavior contentInsetAdjustmentBehavior;
@property(nonatomic) UIEdgeInsets contentInset;
@end
@protocol UITableViewDataSource <NSObject> @end
@protocol UITableViewDelegate <NSObject> @end
@interface UITableView : UIScrollView
@property(nonatomic) UITableViewCellSeparatorStyle separatorStyle;
@property(nonatomic,strong) UIView *tableHeaderView,*tableFooterView;
@property(nonatomic) BOOL allowsSelectionDuringEditing;
@property(nonatomic,strong) NSMutableDictionary *recoveredCells;
@property(nonatomic) NSUInteger recoveredReloads;
@property(nonatomic) BOOL recoveredEditing;
@property(nonatomic,strong) NSArray *recoveredReloadedRows;
@property(nonatomic,strong) NSIndexSet *recoveredReloadedSections;
@property(nonatomic) UITableViewRowAnimation recoveredAnimation;
@property(nonatomic,strong) NSIndexPath *recoveredScrolled,*recoveredDeselected,*recoveredMoveSource,*recoveredMoveDestination;
@property(nonatomic) UITableViewScrollPosition recoveredScrollPosition;
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)reloadData;
- (void)reloadRowsAtIndexPaths:(NSArray *)paths withRowAnimation:(UITableViewRowAnimation)animation;
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)scrollToRowAtIndexPath:(NSIndexPath *)path atScrollPosition:(UITableViewScrollPosition)position animated:(BOOL)animated;
- (void)deselectRowAtIndexPath:(NSIndexPath *)path animated:(BOOL)animated;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (void)moveRowAtIndexPath:(NSIndexPath *)source toIndexPath:(NSIndexPath *)destination;
@end
@interface UITableViewController : UIViewController <UITableViewDelegate,UITableViewDataSource>
@property(nonatomic,strong) UITableView *tableView;
@property(nonatomic) UITableViewStyle recoveredStyle;
- (instancetype)initWithStyle:(UITableViewStyle)style;
@end
@interface UITableViewCell : UIView
@property(nonatomic,strong) UILabel *textLabel,*detailTextLabel;
@property(nonatomic,strong) UIImageView *imageView;
@property(nonatomic,strong) UIView *contentView,*selectedBackgroundView,*accessoryView;
@property(nonatomic,copy) NSString *reuseIdentifier;
@property(nonatomic) UITableViewCellStyle recoveredStyle;
@property(nonatomic) UITableViewCellAccessoryType accessoryType;
@property(nonatomic) BOOL recoveredSelected,recoveredSelectionAnimated;
@property(nonatomic) double recoveredSelectionFade;
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier;
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;
@end
@interface UITableViewHeaderFooterView : UIView
@property(nonatomic,strong) UILabel *textLabel;
@end
@interface NSIndexPath (SettingsFixtureTable)
@property(nonatomic,readonly) NSInteger row,section;
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;
@end
@interface UIControl : UIView
@property(nonatomic,strong) NSMutableArray *recoveredTargets;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events;
- (void)sendActionsForControlEvents:(UIControlEvents)events;
@end
@interface UISegmentedControl : UIControl
@property(nonatomic) NSInteger selectedSegmentIndex;
@property(nonatomic,readonly) NSInteger numberOfSegments;
@property(nonatomic,strong) NSMutableArray *recoveredItems;
@property(nonatomic,strong) NSMutableDictionary *recoveredAttributes;
- (instancetype)initWithItems:(NSArray *)items;
- (void)setTitleTextAttributes:(NSDictionary *)attributes forState:(UIControlState)state;
- (void)insertSegmentWithImage:(UIImage *)image atIndex:(NSUInteger)index animated:(BOOL)animated;
@end
@interface UISlider : UIControl
@property(nonatomic) float value,minimumValue,maximumValue;
@property(nonatomic,strong) UIImage *recoveredThumb;
- (void)setThumbImage:(UIImage *)image forState:(UIControlState)state;
@end
@interface UIStepper : UIControl
@property(nonatomic) double value,minimumValue,maximumValue,stepValue;
@end
@protocol UIPickerViewDelegate <NSObject> @end
@protocol UIPickerViewDataSource <NSObject> @end
@interface UIPickerView : UIView
@property(nonatomic,weak) id<UIPickerViewDelegate> delegate;
@property(nonatomic,weak) id<UIPickerViewDataSource> dataSource;
@property(nonatomic) NSInteger recoveredSelectedRow,recoveredSelectedComponent;
@property(nonatomic) BOOL recoveredSelectedAnimated;
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated;
@end
@protocol UITextFieldDelegate <NSObject> @end
@interface UITextField : UIControl
@property(nonatomic,copy) NSString *text,*placeholder;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property(nonatomic,weak) id<UITextFieldDelegate> delegate;
@property(nonatomic) UIKeyboardType keyboardType;
@property(nonatomic) UIReturnKeyType returnKeyType;
@property(nonatomic) UITextBorderStyle borderStyle;
@property(nonatomic) NSTextAlignment textAlignment;
@property(nonatomic) UITextFieldViewMode clearButtonMode,rightViewMode;
@property(nonatomic) BOOL enablesReturnKeyAutomatically;
@property(nonatomic,strong) UIView *rightView;
@end
@interface UITextView : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,strong) UIColor *textColor;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic) BOOL editable,scrollEnabled;
@property(nonatomic) NSTextAlignment textAlignment;
@end
@protocol UISearchBarDelegate <NSObject> @end
@interface UISearchBar : UIView
@property(nonatomic,weak) id<UISearchBarDelegate> delegate;
@property(nonatomic,copy) NSString *text,*placeholder;
@property(nonatomic) UIReturnKeyType returnKeyType;
@property(nonatomic,strong) UIImage *backgroundImage;
@property(nonatomic,strong) UITextField *searchTextField;
@end
@interface UIButton : UIControl
@property(nonatomic,strong) UILabel *titleLabel;
@property(nonatomic,strong) UIMenu *menu;
@property(nonatomic) BOOL showsMenuAsPrimaryAction;
@property(nonatomic,copy) NSString *recoveredTitle;
@property(nonatomic,strong) UIColor *recoveredTitleColor;
@property(nonatomic,strong) UIImage *recoveredImage;
+ (instancetype)buttonWithType:(UIButtonType)type;
- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
@end
@interface UIBarButtonItem : NSObject
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,weak) id target;
@property(nonatomic) SEL action;
@property(nonatomic) NSInteger recoveredStyle,recoveredSystemItem;
- (instancetype)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action;
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)item target:(id)target action:(SEL)action;
@end
@interface UIAction : NSObject
@property(nonatomic,copy) NSString *title;
@property(nonatomic) UIMenuElementState state;
@property(nonatomic,copy) void (^recoveredHandler)(UIAction *);
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler;
@end
@interface UIMenu : NSObject
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) NSArray *children;
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children;
@end
@interface UIActivityIndicatorView : UIView
@property(nonatomic,strong) UIColor *color;
@property(nonatomic) BOOL recoveredAnimating;
@property(nonatomic) UIActivityIndicatorViewStyle recoveredStyle;
- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style;
- (void)startAnimating;
- (void)stopAnimating;
@end
@interface UIPasteboard : NSObject
@property(nonatomic,copy) NSString *string;
+ (instancetype)generalPasteboard;
@end
@interface UIApplication : NSObject
@property(nonatomic) BOOL recoveredCanOpen;
@property(nonatomic,strong) NSMutableArray *recoveredURLs;
@property(nonatomic,strong) NSURL *recoveredCanOpenURL;
+ (instancetype)sharedApplication;
- (BOOL)canOpenURL:(NSURL *)url;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@protocol UIDocumentPickerDelegate <NSObject> @end
@interface UIDocumentPickerViewController : UIViewController @end
FOUNDATION_EXPORT void SettingsRecord(NSString *kind, id value);
