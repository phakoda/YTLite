#pragma once
// Test-only UIKit boundary. Never added to the iOS build include path.
#import <Foundation/Foundation.h>
@class UIDocumentPickerViewController, UIAlertAction, UITextField;
@protocol UIDocumentPickerDelegate <NSObject>
@optional
- (void)documentPicker:(UIDocumentPickerViewController *)picker didPickDocumentsAtURLs:(NSArray<NSURL *> *)urls;
@end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIViewController *presented;
@property(nonatomic) BOOL dismissed;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
typedef NS_ENUM(NSUInteger, UIDocumentPickerMode) { UIDocumentPickerModeImport = 0 };
@interface UIDocumentPickerViewController : UIViewController
@property(nonatomic, weak) id<UIDocumentPickerDelegate> delegate;
@property(nonatomic) BOOL allowsMultipleSelection;
@property(nonatomic, copy) NSArray *types;
@property(nonatomic) UIDocumentPickerMode mode;
- (instancetype)initWithDocumentTypes:(NSArray *)types inMode:(UIDocumentPickerMode)mode;
@end
typedef NS_ENUM(NSInteger, UITextFieldViewMode) { UITextFieldViewModeWhileEditing = 1 };
@interface UITextField : NSObject
@property(nonatomic, copy) NSString *text, *placeholder;
@property(nonatomic) UITextFieldViewMode clearButtonMode;
@end
typedef NS_ENUM(NSInteger, UIAlertControllerStyle) { UIAlertControllerStyleAlert = 1 };
typedef NS_ENUM(NSInteger, UIAlertActionStyle) { UIAlertActionStyleDefault = 0, UIAlertActionStyleCancel = 1 };
@interface UIAlertAction : NSObject
@property(nonatomic, copy) NSString *title;
@property(nonatomic) UIAlertActionStyle style;
@property(nonatomic, copy) void (^handler)(UIAlertAction *);
+ (instancetype)actionWithTitle:(NSString *)title style:(UIAlertActionStyle)style handler:(void (^)(UIAlertAction *))handler;
@end
@interface UIAlertController : UIViewController
@property(nonatomic, copy) NSString *title, *message;
@property(nonatomic) UIAlertControllerStyle style;
@property(nonatomic, strong) NSMutableArray<UITextField *> *textFields;
@property(nonatomic, strong) NSMutableArray<UIAlertAction *> *actions;
+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message preferredStyle:(UIAlertControllerStyle)style;
- (void)addTextFieldWithConfigurationHandler:(void (^)(UITextField *))handler;
- (void)addAction:(UIAlertAction *)action;
@end
