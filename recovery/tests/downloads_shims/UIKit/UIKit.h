#pragma once
// TEST ONLY: isolated UIKit boundary doubles. Never on an iOS include path.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UIColor, UIWindow, UIViewController, UITraitCollection, UIPopoverPresentationController;
FOUNDATION_EXPORT NSString * const NSForegroundColorAttributeName;
FOUNDATION_EXPORT NSString * const NSFontAttributeName;
FOUNDATION_EXPORT NSString * const NSBaselineOffsetAttributeName;
FOUNDATION_EXPORT NSString * const UIActivityTypeAssignToContact;
FOUNDATION_EXPORT NSString * const UIActivityTypePrint;
typedef NS_OPTIONS(NSUInteger, UIPopoverArrowDirection) { UIPopoverArrowDirectionUp = 1 };
typedef NS_ENUM(NSInteger, UIModalPresentationStyle) { UIModalPresentationFullScreen = 0, UIModalPresentationFormSheet = 2 };
typedef NS_OPTIONS(NSUInteger, UIControlState) { UIControlStateNormal = 0 };
@interface UITraitCollection : NSObject @end
@interface UIColor : NSObject
@property(nonatomic) CGFloat red, green, blue, alpha;
@property(nonatomic) BOOL cannotDecode;
@property(nonatomic,copy) UIColor *(^provider)(UITraitCollection *);
+ (UIColor *)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a;
+ (UIColor *)colorWithDynamicProvider:(UIColor *(^)(UITraitCollection *))provider;
+ (UIColor *)blackColor;
+ (UIColor *)whiteColor;
+ (UIColor *)redColor;
- (BOOL)getRed:(CGFloat *)r green:(CGFloat *)g blue:(CGFloat *)b alpha:(CGFloat *)a;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *name;
@property(nonatomic,strong) UIColor *tint;
@property(nonatomic,strong) NSData *data;
@property(nonatomic) BOOL flipsForRightToLeftLayoutDirection;
+ (UIImage *)imageWithData:(NSData *)data;
+ (UIImage *)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits;
@end
@interface UIFont : NSObject
@property(nonatomic) CGFloat pointSize;
+ (UIFont *)systemFontOfSize:(CGFloat)size;
@end
@interface UIView : NSObject
@property(nonatomic) CGRect bounds;
@end
@interface UIButton : UIView
@property(nonatomic,strong) NSAttributedString *currentAttributedTitle;
- (void)setAttributedTitle:(NSAttributedString *)title forState:(UIControlState)state;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIViewController *presented;
@property(nonatomic,strong) UIPopoverPresentationController *popoverPresentationController;
@property(nonatomic) UIModalPresentationStyle modalPresentationStyle;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UINavigationController : UIViewController
@property(nonatomic,strong) UIViewController *root;
- (instancetype)initWithRootViewController:(UIViewController *)root;
@end
@interface UIWindow : UIView
@property(nonatomic,strong) UIViewController *rootViewController;
@end
@interface UIApplication : NSObject
@property(nonatomic,strong) id delegate;
@property(nonatomic,strong) NSURL *openedURL;
@property(nonatomic,strong) NSDictionary *openedOptions;
@property(nonatomic) BOOL openResult;
+ (UIApplication *)sharedApplication;
- (void)openURL:(NSURL *)url options:(NSDictionary *)options completionHandler:(void (^)(BOOL))completion;
@end
@interface UIPasteboard : NSObject
@property(nonatomic,copy) NSString *string;
+ (UIPasteboard *)generalPasteboard;
@end
@interface UIPopoverPresentationController : NSObject
@property(nonatomic,strong) UIView *sourceView;
@property(nonatomic) CGRect sourceRect;
@property(nonatomic) UIPopoverArrowDirection permittedArrowDirections;
@end
@interface UIActivityViewController : UIViewController
@property(nonatomic,strong) NSArray *items;
@property(nonatomic,copy) NSArray *excludedActivityTypes;
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities;
@end
