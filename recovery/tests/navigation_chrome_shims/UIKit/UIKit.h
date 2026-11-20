#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
@class UIImage,UIView,UIViewController,UIMenu,UIAction,UIMenuElement,UIContextMenuConfiguration,UIContextMenuInteraction,UIFont,UITableView,UITableViewCell,UISwipeActionsConfiguration,UISegmentedControl,UISearchBar,UIBarButtonItem,UISlider,UIStepper,UITextField,UIPickerView,UITapGestureRecognizer;
@protocol UISearchBarDelegate <NSObject> @end
@protocol UIPickerViewDelegate <NSObject> @end
@protocol UIPickerViewDataSource <NSObject> @end
@protocol UITextFieldDelegate <NSObject> @end
@protocol UIContextMenuInteractionDelegate <NSObject>
- (UIContextMenuConfiguration*)contextMenuInteraction:(UIContextMenuInteraction*)interaction configurationForMenuAtLocation:(CGPoint)location;
@end
static const CGFloat UIFontWeightBold=0.4;
#define NSFontAttributeName @"NSFont"
#define NSForegroundColorAttributeName @"NSColor"
enum {UIModalPresentationPageSheet=1};
@interface UIView:NSObject
@property(nonatomic) CGFloat alpha;
@property(nonatomic) BOOL userInteractionEnabled;
@property(nonatomic) CGRect frame;
@property(strong) NSMutableArray *interactions;
- (void)addInteraction:(id)interaction;
- (void)layoutSubviews;
@end
@interface UIImage:NSObject
@property(copy) NSString *name;
@end
@interface UIFont:NSObject @end
@interface UIColor:NSObject
+ (instancetype)labelColor;
@end
@interface UIButton:UIView
@property(strong) NSMutableDictionary *images,*titles;
- (void)setImage:(UIImage*)image forState:(NSUInteger)state;
- (void)setTitle:(NSString*)title forState:(NSUInteger)state;
@end
@interface UIViewController:NSObject
@property(strong) UIViewController *parentViewController;
@property NSInteger modalPresentationStyle;
- (void)viewDidAppear:(BOOL)animated;
- (void)presentViewController:(UIViewController*)controller animated:(BOOL)animated completion:(void(^)(void))completion;
@end
@interface UITableViewController:UIViewController @end
@interface UINavigationBar:NSObject
@property(copy) NSDictionary *titleTextAttributes;
@end
@interface UINavigationController:UIViewController
@property(strong) UIViewController *root;
@property(strong) UINavigationBar *navigationBar;
- (instancetype)initWithRootViewController:(UIViewController*)root;
@end
@interface UIWindow:UIView
@property(strong) UIViewController *rootViewController;
@end
@protocol UIApplicationDelegate <NSObject>
- (UIWindow *)window;
@end
@interface UIApplication:NSObject
+ (instancetype)sharedApplication;
@property(strong) id<UIApplicationDelegate> delegate;
- (void)openURL:(NSURL*)url options:(NSDictionary*)options completionHandler:(void(^)(BOOL))completion;
@end
@interface UIPasteboard:NSObject
+ (instancetype)generalPasteboard;
@property(copy) NSString *string;
@end
@interface UIMenuElement:NSObject @end
@interface UIAction:UIMenuElement
@property(copy) NSString *title;
@property(strong) UIImage *image;
@property(copy) void(^handler)(UIAction*);
+ (instancetype)actionWithTitle:(NSString*)title image:(UIImage*)image identifier:(id)identifier handler:(void(^)(UIAction*))handler;
@end
@interface UIMenu:UIMenuElement
@property(copy) NSString *title,*identifier;
@property NSUInteger options;
@property(copy) NSArray *children;
+ (instancetype)menuWithTitle:(NSString*)title image:(UIImage*)image identifier:(NSString*)identifier options:(NSUInteger)options children:(NSArray*)children;
+ (instancetype)menuWithTitle:(NSString*)title children:(NSArray*)children;
@end
@interface UIContextMenuInteraction:NSObject
@property(weak) id delegate;
- (instancetype)initWithDelegate:(id)delegate;
@end
@interface UIContextMenuConfiguration:NSObject
@property(copy) UIMenu*(^provider)(NSArray<UIMenuElement*>*);
+ (instancetype)configurationWithIdentifier:(id)identifier previewProvider:(id)preview actionProvider:(UIMenu*(^)(NSArray<UIMenuElement*>*))provider;
@end
