#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#define NSLayoutConstraint WelcomeFixtureConstraint
#define NSLayoutAnchor WelcomeFixtureAnchor
#define UITableViewAutomaticDimension -1.0
#define UIFontWeightLight -0.4
typedef struct {CGFloat top,left,bottom,right;} UIEdgeInsets;
static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat a,CGFloat b,CGFloat c,CGFloat d){return (UIEdgeInsets){a,b,c,d};}
enum { UIBarMetricsDefault=0, UITableViewStyleInsetGrouped=2, UITableViewCellStyleSubtitle=3, UITableViewCellSeparatorStyleNone=0,
UIViewAutoresizingFlexibleWidth=2,UIViewAutoresizingFlexibleHeight=16,UIBlurEffectStyleLight=1,UIBlurEffectStyleDark=2,UIBlurEffectStyleProminent=4,
UILayoutConstraintAxisVertical=1,UILayoutConstraintAxisHorizontal=0,UIStackViewAlignmentCenter=3,UIStackViewDistributionFillEqually=1,UIStackViewDistributionFillProportionally=2,
UIButtonTypeCustom=0,UIButtonTypeSystem=1,UIControlStateNormal=0,UIControlStateHighlighted=1,UIControlEventTouchUpInside=64,
UIImageRenderingModeAlwaysTemplate=2,UIViewContentModeScaleAspectFit=1,UISemanticContentAttributeForceLeftToRight=3,UIImpactFeedbackStyleMedium=1,NSTextAlignmentCenter=1};
@class UIView,UIImage,UITableView,UITableViewCell;
@class NSLayoutAnchor;
@interface NSLayoutConstraint:NSObject
@property(strong) NSLayoutAnchor *firstAnchor,*secondAnchor;
@property CGFloat constant;
+ (void)activateConstraints:(NSArray *)constraints;
@end
@interface NSLayoutAnchor:NSObject
@property(weak) id owner;
@property(copy) NSString *kind;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor;
- (NSLayoutConstraint *)constraintEqualToAnchor:(NSLayoutAnchor *)anchor constant:(CGFloat)value;
- (NSLayoutConstraint *)constraintEqualToConstant:(CGFloat)value;
@end
@interface UIColor:NSObject
@property CGFloat white,alpha;
+ (instancetype)whiteColor; + (instancetype)clearColor;
+ (instancetype)colorWithWhite:(CGFloat)white alpha:(CGFloat)alpha;
- (instancetype)colorWithAlphaComponent:(CGFloat)alpha;
@end
@interface UIFont:NSObject
@property CGFloat pointSize,weight;
@property BOOL bold,monospaced;
+ (instancetype)boldSystemFontOfSize:(CGFloat)size;
+ (instancetype)systemFontOfSize:(CGFloat)size;
+ (instancetype)monospacedDigitSystemFontOfSize:(CGFloat)size weight:(CGFloat)weight;
@end
@interface UIView:NSObject
@property CGRect frame,bounds;
@property UIEdgeInsets safeAreaInsets;
@property CGFloat alpha;
@property CGAffineTransform transform;
@property NSUInteger autoresizingMask;
@property BOOL translatesAutoresizingMaskIntoConstraints,userInteractionEnabled,clipsToBounds;
@property NSInteger contentMode,semanticContentAttribute,tag;
@property(strong) UIColor *backgroundColor,*tintColor;
@property(strong) CALayer *layer;
@property(strong) NSMutableArray<UIView *> *subviews;
@property(weak) UIView *superview;
@property NSInteger layoutCount;
@property(readonly) NSLayoutAnchor *centerXAnchor,*centerYAnchor,*widthAnchor,*heightAnchor,*leadingAnchor,*trailingAnchor,*topAnchor,*bottomAnchor;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addSubview:(UIView *)view;
- (void)bringSubviewToFront:(UIView *)view;
- (void)sendSubviewToBack:(UIView *)view;
- (void)removeFromSuperview;
- (void)layoutIfNeeded;
+ (void)animateWithDuration:(double)duration delay:(double)delay usingSpringWithDamping:(CGFloat)damping initialSpringVelocity:(CGFloat)velocity options:(NSUInteger)options animations:(void (^)(void))animations completion:(void (^)(BOOL))completion;
@end
@interface UIImage:NSObject
@property(copy) NSString *name;
@property(strong) NSBundle *bundle;
@property(strong) id traits;
@property NSInteger renderingMode;
@property BOOL system;
@property CGSize size;
+ (instancetype)systemImageNamed:(NSString *)name;
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(id)traits;
- (UIImage *)imageWithRenderingMode:(NSInteger)mode;
@end
@interface UIImageView:UIView
@property(strong) UIImage *image;
- (instancetype)initWithImage:(UIImage *)image;
@end
@interface UILabel:UIView
@property(copy) NSString *text;
@property(strong) UIColor *textColor;
@property(strong) UIFont *font;
@property NSInteger numberOfLines,textAlignment;
@property BOOL adjustsFontSizeToFitWidth;
@end
@interface UIStackView:UIView
@property NSInteger axis,alignment,distribution;
@property CGFloat spacing;
@property(strong) NSMutableArray *arrangedSubviews;
- (instancetype)initWithArrangedSubviews:(NSArray *)views;
- (void)addArrangedSubview:(UIView *)view;
@end
@interface UIBlurEffect:NSObject
@property NSInteger style;
+ (instancetype)effectWithStyle:(NSInteger)style;
@end
@interface UIVisualEffectView:UIView
@property(strong) UIBlurEffect *effect;
@property(strong) UIView *contentView;
- (instancetype)initWithEffect:(UIBlurEffect *)effect;
@end
@interface UIButton:UIView
@property NSInteger type;
@property(strong) UILabel *titleLabel;
@property(strong) UIImageView *imageView;
@property(strong) NSMutableDictionary *titles,*titleColors;
@property(weak) id target;
@property SEL action;
@property NSUInteger events;
@property UIEdgeInsets imageEdgeInsets;
+ (instancetype)buttonWithType:(NSInteger)type;
- (void)setTitle:(NSString *)title forState:(NSUInteger)state;
- (void)setTitleColor:(UIColor *)color forState:(NSUInteger)state;
- (void)setImage:(UIImage *)image forState:(NSUInteger)state;
- (void)addTarget:(id)target action:(SEL)action forControlEvents:(NSUInteger)events;
@end
@protocol UITableViewDataSource <NSObject>
- (NSInteger)numberOfSectionsInTableView:(UITableView *)table;
- (NSInteger)tableView:(UITableView *)table numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)table cellForRowAtIndexPath:(NSIndexPath *)path;
@end
@protocol UITableViewDelegate <NSObject>
- (CGFloat)tableView:(UITableView *)table heightForRowAtIndexPath:(NSIndexPath *)path;
- (BOOL)tableView:(UITableView *)table shouldHighlightRowAtIndexPath:(NSIndexPath *)path;
- (void)tableView:(UITableView *)table willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)path;
@end
@interface UITableView:UIView
@property NSInteger style,separatorStyle;
@property(weak) id<UITableViewDataSource> dataSource;
@property(weak) id<UITableViewDelegate> delegate;
@property(strong) UIColor *separatorColor;
@property(strong) UIView *tableHeaderView;
@property(strong) UITableViewCell *reusable;
@property UIEdgeInsets contentInset;
- (instancetype)initWithFrame:(CGRect)frame style:(NSInteger)style;
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;
@end
@interface UITableViewCell:UIView
@property NSInteger style;
@property(copy) NSString *reuseIdentifier;
@property(strong) UILabel *textLabel,*detailTextLabel;
@property(strong) UIImageView *imageView;
- (instancetype)initWithStyle:(NSInteger)style reuseIdentifier:(NSString *)identifier;
@end
@interface NSIndexPath (WelcomeFixture)
@property(readonly) NSInteger row,section;
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;
@end
@interface UINavigationBar:NSObject
@property BOOL translucent;
@property(strong) UIImage *shadowImage,*backgroundImage;
@property NSInteger metrics;
- (void)setBackgroundImage:(UIImage *)image forBarMetrics:(NSInteger)metrics;
@end
@interface UINavigationController:NSObject
@property(strong) UINavigationBar *navigationBar;
@end
@interface UIViewController:NSObject
@property(strong) UIView *view;
@property(strong) UINavigationController *navigationController;
@property BOOL dismissed,animated;
@property NSInteger superViewDidLoad;
- (void)viewDidLoad;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UIWindow:UIView @end
@protocol UIApplicationDelegate <NSObject>
@property(strong) UIWindow *window;
@end
@interface UIApplication:NSObject
@property(strong) id<UIApplicationDelegate> delegate;
@property BOOL canOpen;
@property(strong) NSMutableArray *openedURLs;
@property(strong) NSURL *queriedURL;
+ (instancetype)sharedApplication;
- (BOOL)canOpenURL:(NSURL *)url;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@interface UIPasteboard:NSObject
@property(copy) NSString *string;
+ (instancetype)generalPasteboard;
@end
@interface UIImpactFeedbackGenerator:NSObject
@property NSInteger style;
- (instancetype)initWithStyle:(NSInteger)style;
- (void)prepare;
- (void)impactOccurred;
@end
@interface UIGraphicsImageRendererContext:NSObject
@property CGContextRef CGContext;
@end
@interface UIGraphicsImageRenderer:NSObject
@property CGSize size;
- (instancetype)initWithSize:(CGSize)size;
- (UIImage *)imageWithActions:(void (^)(UIGraphicsImageRendererContext *))actions;
@end
