#pragma once
// Isolated test-only UIKit contract. Production uses the iOS SDK.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint WhitelistConstraint
#define NSLayoutAnchor WhitelistAnchor
@class UIView, UIColor, UIImage, UITraitCollection, UIMenu;
typedef CGFloat UIFontWeight;
extern const UIFontWeight UIFontWeightLight;
typedef NSInteger UITableViewStyle, UITableViewCellStyle, UIImageRenderingMode, UIButtonType, UIControlState, UIMenuElementState, UIMenuOptions, UIContextualActionStyle, UIUserInterfaceStyle, UIBarButtonSystemItem, UIViewContentMode, NSTextAlignment;
enum { UITableViewStyleGrouped=1, UITableViewCellStyleValue2=3, UIImageRenderingModeAlwaysTemplate=2, UIButtonTypeSystem=1, UIControlStateNormal=0, UIMenuOptionsDisplayInline=1, UIContextualActionStyleDestructive=1, UIUserInterfaceStyleDark=2, UIBarButtonSystemItemClose=24, UIViewContentModeScaleAspectFit=1, NSTextAlignmentNatural=4 };
typedef struct { CGFloat top,left,bottom,right; } UIEdgeInsets;
@interface NSLayoutConstraint : NSObject
@property(nonatomic,strong) id firstAnchor, secondAnchor;
@property CGFloat constant;
+ (void)activateConstraints:(NSArray *)constraints;
@end
@interface NSLayoutAnchor : NSObject
@property(nonatomic,weak) UIView *owner;
@property(nonatomic,copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
@end
@interface UIView : NSObject
@property CGRect frame,bounds;
@property NSInteger tag;
@property BOOL translatesAutoresizingMaskIntoConstraints,clipsToBounds;
@property UIViewContentMode contentMode;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,strong) NSMutableArray<UIView *> *subviews;
@property(nonatomic,readonly) NSLayoutAnchor *heightAnchor,*widthAnchor,*trailingAnchor,*centerYAnchor;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
- (UIView *)viewWithTag:(NSInteger)tag;
@end
@interface UIColor : NSObject { CGColorRef _color; }
@property(nonatomic,readonly) CGColorRef CGColor;
@property(nonatomic,copy) NSString *name;
@property CGFloat alpha;
@property(nonatomic,copy) UIColor *(^provider)(UITraitCollection *);
+ (instancetype)labelColor;
+ (instancetype)whiteColor;
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
@end
@interface UITraitCollection : NSObject
@property UIUserInterfaceStyle userInterfaceStyle;
@end
@interface UIFont : NSObject
@property CGFloat pointSize;
@property UIFontWeight weight;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
@end
@interface UILabel : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property NSTextAlignment textAlignment;
@property NSInteger numberOfLines;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *name;
@property(nonatomic,strong) NSBundle *bundle;
@property(nonatomic,strong) NSData *data;
@property UIImageRenderingMode renderingMode;
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits;
+ (instancetype)systemImageNamed:(NSString *)name;
+ (instancetype)imageWithData:(NSData *)data;
- (instancetype)imageWithRenderingMode:(UIImageRenderingMode)mode;
@end
@interface UIImageView : UIView
@property(nonatomic,strong) UIImage *image;
- (instancetype)initWithImage:(UIImage *)image;
@end
@interface UIGraphicsImageRendererContext : NSObject
@property CGContextRef CGContext;
@end
@interface UIGraphicsImageRenderer : NSObject
@property CGSize size;
- (instancetype)initWithSize:(CGSize)size;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions;
@end
@interface UIAction : NSObject
@property(nonatomic,copy) NSString *title,*identifier;
@property(nonatomic,strong) UIImage *image;
@property UIMenuElementState state;
@property(nonatomic,copy) void (^handler)(UIAction *);
+ (instancetype)actionWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier handler:(void (^)(UIAction *))handler;
@end
@interface UIMenu : NSObject
@property(nonatomic,copy) NSString *title,*identifier;
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,strong) NSArray *children;
@property UIMenuOptions options;
+ (instancetype)menuWithTitle:(NSString *)title image:(UIImage *)image identifier:(NSString *)identifier options:(UIMenuOptions)options children:(NSArray *)children;
@end
@interface UIButton : UIView
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,strong) UIMenu *menu;
@property BOOL showsMenuAsPrimaryAction;
@property UIButtonType type;
+ (instancetype)buttonWithType:(UIButtonType)type;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
@end
@interface UIBarButtonItem : NSObject
@property UIBarButtonSystemItem systemItem;
@property(nonatomic,weak) id target;
@property SEL action;
- (instancetype)initWithBarButtonSystemItem:(UIBarButtonSystemItem)item target:(id)target action:(SEL)action;
@end
@interface UINavigationItem : NSObject
@property(nonatomic,strong) UIBarButtonItem *rightBarButtonItem;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIView *view;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UINavigationItem *navigationItem;
@property BOOL loaded,dismissed,dismissAnimated;
- (void)loadView;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UITableViewCell : UIView
@property(nonatomic,strong) UILabel *textLabel;
@property(nonatomic,strong) UIImageView *imageView;
@property(nonatomic,copy) NSString *reuseIdentifier;
@property UITableViewCellStyle style;
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier;
@end
@interface UITableView : UIView
@property UIEdgeInsets contentInset;
@property NSUInteger reloads;
@property(nonatomic,strong) UITableViewCell *reusable;
@property(nonatomic,copy) NSString *dequeuedIdentifier;
@property(nonatomic,strong) NSIndexPath *deselected;
@property BOOL deselectAnimated;
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
- (void)reloadData;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
@end
@interface UITableViewController : UIViewController
@property(nonatomic,strong) UITableView *tableView;
@property UITableViewStyle style;
- (instancetype)initWithStyle:(UITableViewStyle)style;
@end
@interface UITableViewHeaderFooterView : UIView
@property(nonatomic,strong) UILabel *textLabel;
@property(nonatomic,strong) UIView *contentView;
@end
@interface NSIndexPath (WhitelistTable)
@property(nonatomic,readonly) NSInteger row,section;
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) NSMutableArray *urls;
@property(nonatomic,strong) NSDictionary *lastOptions;
@property BOOL hadCompletion;
+ (instancetype)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@interface UIContextualAction : NSObject
@property UIContextualActionStyle style;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,copy) void (^handler)(UIContextualAction *, UIView *, void (^)(BOOL));
+ (instancetype)contextualActionWithStyle:(UIContextualActionStyle)style title:(NSString *)title handler:(void (^)(UIContextualAction *, UIView *, void (^)(BOOL)))handler;
@end
@interface UISwipeActionsConfiguration : NSObject
@property(nonatomic,strong) NSArray<UIContextualAction *> *actions;
@property BOOL performsFirstActionWithFullSwipe;
+ (instancetype)configurationWithActions:(NSArray *)actions;
@end
// Canonical superclass declarations only need these names in this fixture.
@protocol UISearchBarDelegate <NSObject> @end
@protocol UIPickerViewDelegate <NSObject> @end
@protocol UIPickerViewDataSource <NSObject> @end
@protocol UITextFieldDelegate <NSObject> @end
@class UISearchBar, UISegmentedControl, UISlider, UIStepper, UIPickerView, UITextField, UIDocumentPickerViewController;
