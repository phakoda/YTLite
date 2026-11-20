#pragma once
// Host-only UIKit boundary. Production compiles with the real iOS SDK.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint TranslatorFixtureConstraint
#define NSLayoutAnchor TranslatorFixtureAnchor
@class UIView, UIColor, UIImage, UITraitCollection, UIMenu;
typedef CGFloat UIFontWeight;
extern const UIFontWeight UIFontWeightSemibold;
extern NSString *const UIFontTextStyleBody;
extern NSString *const NSForegroundColorAttributeName;
extern const CGFloat UITableViewAutomaticDimension;
typedef NSInteger UITableViewStyle, UITableViewCellStyle, UIButtonType, UIControlState, UIMenuElementState, UIUserInterfaceStyle, UIBarButtonSystemItem, UIViewContentMode, NSTextAlignment, UISemanticContentAttribute, UIUserInterfaceLayoutDirection, UITableViewCellSeparatorStyle, UITableViewRowAnimation;
typedef NSUInteger UIControlEvents, UIDataDetectorTypes;
enum { UITableViewStyleInsetGrouped=2, UITableViewCellStyleSubtitle=3, UIButtonTypeSystem=1, UIControlStateNormal=0, UIUserInterfaceStyleDark=2, UIBarButtonSystemItemClose=24, UIViewContentModeScaleAspectFit=1, NSTextAlignmentNatural=4, NSTextAlignmentCenter=1, UISemanticContentAttributeForceLeftToRight=3, UISemanticContentAttributeForceRightToLeft=4, UIUserInterfaceLayoutDirectionRightToLeft=1, UITableViewCellSeparatorStyleNone=0, UITableViewRowAnimationNone=5, UIControlEventTouchUpInside=64, UIDataDetectorTypeLink=2, UIMenuElementStateOn=1, UIMenuElementStateOff=0 };
@interface NSLayoutConstraint : NSObject
@property(nonatomic,strong) id firstAnchor,secondAnchor;
@property CGFloat constant;
+ (void)activateConstraints:(NSArray *)constraints;
@end
@interface NSLayoutAnchor : NSObject
@property(nonatomic,weak) UIView *owner;
@property(nonatomic,copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
@end
@interface UIView : NSObject
@property CGRect frame,bounds;
@property BOOL translatesAutoresizingMaskIntoConstraints,clipsToBounds;
@property UIViewContentMode contentMode;
@property UISemanticContentAttribute semanticContentAttribute;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) UIColor *backgroundColor,*tintColor;
@property(nonatomic,strong) NSMutableArray<UIView *> *subviews;
@property(nonatomic,readonly) NSLayoutAnchor *heightAnchor,*widthAnchor,*leadingAnchor,*trailingAnchor,*topAnchor,*bottomAnchor;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
+ (UIUserInterfaceLayoutDirection)userInterfaceLayoutDirectionForSemanticContentAttribute:(UISemanticContentAttribute)value;
@end
@interface UIColor : NSObject { CGColorRef _color; }
@property(nonatomic,readonly) CGColorRef CGColor;
@property(nonatomic,copy) NSString *name;
@property CGFloat red,green,blue,alpha;
@property(nonatomic,copy) UIColor *(^provider)(UITraitCollection *);
+ (instancetype)labelColor; + (instancetype)secondaryLabelColor;
+ (instancetype)whiteColor; + (instancetype)blackColor;
+ (instancetype)systemBackgroundColor; + (instancetype)clearColor;
+ (instancetype)systemGrayColor; + (instancetype)systemRedColor;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (instancetype)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
@end
@interface UITraitCollection : NSObject
@property UIUserInterfaceStyle userInterfaceStyle;
@end
@interface UIFont : NSObject
@property CGFloat pointSize;
@property UIFontWeight weight;
@property(nonatomic,copy) NSString *kind,*style;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
+ (instancetype)systemFontOfSize:(CGFloat)size;
+ (instancetype)boldSystemFontOfSize:(CGFloat)size;
+ (instancetype)italicSystemFontOfSize:(CGFloat)size;
+ (instancetype)preferredFontForTextStyle:(NSString *)style;
@end
@interface UILabel : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property NSTextAlignment textAlignment;
@property NSInteger numberOfLines;
@end
@interface UITextView : UIView
@property(nonatomic,copy) NSString *text;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property BOOL editable,selectable;
@property UIDataDetectorTypes dataDetectorTypes;
@property(nonatomic,copy) NSDictionary *linkTextAttributes;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *name;
+ (instancetype)systemImageNamed:(NSString *)name;
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
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) NSArray<UIAction *> *children;
+ (instancetype)menuWithTitle:(NSString *)title children:(NSArray *)children;
@end
@interface UIButton : UIView
@property(nonatomic,strong) UIImage *image;
@property(nonatomic,strong) UIMenu *menu;
@property(nonatomic) BOOL showsMenuAsPrimaryAction,enabled,sizedToFit;
@property UIButtonType type;
@property(nonatomic,strong) UILabel *titleLabel;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,strong) UIColor *titleColor;
@property(nonatomic,weak) id target;
@property SEL action;
@property UIControlEvents events;
+ (instancetype)buttonWithType:(UIButtonType)type;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;
- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(UIControlEvents)events;
- (void)sizeToFit;
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
- (void)viewDidLoad;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UITableViewCell : UIView
@property(nonatomic,strong) UILabel *textLabel;
@property(nonatomic,strong) UIView *contentView,*accessoryView;
@property(nonatomic,copy) NSString *reuseIdentifier;
@property UITableViewCellStyle style;
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier;
@end
@interface UITableView : UIView
@property UITableViewCellSeparatorStyle separatorStyle;
@property(nonatomic,strong) UITableViewCell *reusable;
@property(nonatomic,copy) NSString *dequeuedIdentifier;
@property(nonatomic,strong) NSIndexPath *deselected;
@property BOOL deselectAnimated;
@property(nonatomic,copy) NSIndexSet *reloadedSections;
@property UITableViewRowAnimation animation;
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;
@end
@interface UITableViewController : UIViewController
@property(nonatomic,strong) UITableView *tableView;
@property UITableViewStyle style;
@property(nonatomic,copy) NSString *fixtureHeader;
@property NSInteger headerSection;
@property(nonatomic,weak) UITableView *headerTable;
- (instancetype)initWithStyle:(UITableViewStyle)style;
- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)path;
- (NSInteger)numberOfSectionsInTableView:(UITableView *)table;
- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)table cellForRowAtIndexPath:(NSIndexPath *)path;
- (BOOL)tableView:(UITableView *)table shouldHighlightRowAtIndexPath:(NSIndexPath *)path;
- (void)tableView:(UITableView *)table didSelectRowAtIndexPath:(NSIndexPath *)path;
@end
@interface UITableViewHeaderFooterView : UIView
@property(nonatomic,strong) UILabel *textLabel;
@end
@interface NSIndexPath (TranslatorFixtureTable)
@property(nonatomic,readonly) NSInteger row,section;
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;
@end
