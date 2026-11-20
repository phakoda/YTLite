// TEST-ONLY declarations. iOS builds use Apple's UIKit, never this directory.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class UIPopoverPresentationController;

typedef CGFloat UIFontWeight;
extern const UIFontWeight UIFontWeightSemibold;
@interface UIFont : NSObject
@property(nonatomic) CGFloat pointSize;
@property(nonatomic) UIFontWeight recoveredTestWeight;
+ (instancetype)systemFontOfSize:(CGFloat)size weight:(UIFontWeight)weight;
@end
@interface UIView : NSObject
@property(nonatomic) CGRect bounds;
@end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIPopoverPresentationController *popoverPresentationController;
@property(nonatomic, strong) UIViewController *recoveredPresentedController;
@property(nonatomic) BOOL recoveredPresentedAnimated;
@property(nonatomic, copy) void (^recoveredOnPresentation)(UIViewController *controller);
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@class UITraitCollection, UIColor;
typedef NS_ENUM(NSInteger, UIImageRenderingMode) {
    UIImageRenderingModeAutomatic = 0, UIImageRenderingModeAlwaysOriginal = 1, UIImageRenderingModeAlwaysTemplate = 2
};
@interface UIImage : NSObject
@property(nonatomic) UIImageRenderingMode renderingMode;
@property(nonatomic, copy) NSString *accessibilityIdentifier;
@property(nonatomic, copy) NSString *recoveredName;
@property(nonatomic, strong) NSBundle *recoveredBundle;
@property(nonatomic, strong) UIColor *recoveredTint;
@property(nonatomic, strong) NSArray *recoveredOperations;
+ (instancetype)imageNamed:(NSString *)name inBundle:(NSBundle *)bundle compatibleWithTraitCollection:(UITraitCollection *)traits;
- (UIImage *)imageWithRenderingMode:(UIImageRenderingMode)mode;
- (UIImage *)imageWithTintColor:(UIColor *)color;
@end
@interface UIColor : NSObject <NSSecureCoding>
@property(nonatomic) CGFloat recoveredRed;
@property(nonatomic) CGFloat recoveredGreen;
@property(nonatomic) CGFloat recoveredBlue;
@property(nonatomic) CGFloat recoveredAlpha;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
+ (instancetype)redColor;
@end

typedef NS_ENUM(NSInteger, UIDocumentPickerMode) { UIDocumentPickerModeImport = 0 };
typedef NS_OPTIONS(NSUInteger, UIPopoverArrowDirection) { UIPopoverArrowDirectionUp = 1 };
@protocol UIDocumentPickerDelegate <NSObject> @end
@interface UIDocumentPickerViewController : UIViewController
@property(nonatomic, weak) id<UIDocumentPickerDelegate> delegate;
@property(nonatomic) BOOL allowsMultipleSelection;
@property(nonatomic, strong) NSArray *recoveredDocumentTypes;
@property(nonatomic) UIDocumentPickerMode recoveredMode;
- (instancetype)initWithDocumentTypes:(NSArray *)types inMode:(UIDocumentPickerMode)mode;
@end
@interface UIPopoverPresentationController : NSObject
@property(nonatomic, strong) UIView *sourceView;
@property(nonatomic) CGRect sourceRect;
@property(nonatomic) UIPopoverArrowDirection permittedArrowDirections;
@end
typedef NSString *UIActivityType;
extern const UIActivityType UIActivityTypeAssignToContact;
extern const UIActivityType UIActivityTypePrint;
@interface UIActivityViewController : UIViewController
@property(nonatomic, strong) NSArray *excludedActivityTypes;
@property(nonatomic, strong) NSArray *recoveredActivityItems;
@property(nonatomic, strong) NSArray *recoveredApplicationActivities;
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities;
@end
