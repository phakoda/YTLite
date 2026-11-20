#pragma once
#import <UIKit/UIKit.h>

// Declarations of real YouTube host classes. These are never implemented here.
@interface YTAssetLoader : NSObject
- (instancetype)initWithBundle:(NSBundle *)bundle;
- (UIImage *)imageNamed:(NSString *)name;
@end
@interface YTQTMButtonTouchFeedbackView : UIView
@property(nonatomic) BOOL forceCircularTouchFeedback;
@property(nonatomic) UIEdgeInsets touchFeedbackInsets;
@property(nonatomic, strong) UIColor *customTouchFeedbackColor;
@end
@interface YTQTMButton : UIButton
+ (instancetype)iconButton;
- (void)enableNewTouchFeedback;
- (YTQTMButtonTouchFeedbackView *)touchFeedbackView;
@end
@interface YTUIUtils : NSObject
+ (UIViewController *)topViewControllerForPresenting;
@end
@interface YTActionSheetAction : NSObject
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)icon
             secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier
                        handler:(dispatch_block_t)handler;
@end
@interface YTDefaultSheetController : NSObject
+ (instancetype)sheetControllerWithMessage:(NSString *)message delegate:(id)delegate parentResponder:(id)parent;
- (void)addAction:(YTActionSheetAction *)action;
- (void)setSourceView:(UIView *)view;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(dispatch_block_t)completion;
@end
@interface YTUIResources : NSObject
+ (UIImage *)actionsheetShareImage;
@end
@interface UIViewController (YTLHelperHostRoot)
- (UIViewController *)pivotBarViewController;
@end
