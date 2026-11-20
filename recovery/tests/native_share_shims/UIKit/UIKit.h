#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@interface UIView : NSObject
@property(nonatomic) CGRect bounds;
- (CGRect)convertRect:(CGRect)rect toView:(UIView *)view;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIView *view;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@interface UIPopoverPresentationController : NSObject
@property(nonatomic,strong) UIView *sourceView;
@property(nonatomic) CGRect sourceRect;
@end
FOUNDATION_EXPORT NSString *const UIActivityTypeAssignToContact;
FOUNDATION_EXPORT NSString *const UIActivityTypePrint;
@interface UIActivityViewController : UIViewController
- (instancetype)initWithActivityItems:(NSArray *)items applicationActivities:(NSArray *)activities;
@property(nonatomic,copy) NSArray *excludedActivityTypes;
@property(nonatomic,strong) UIPopoverPresentationController *popoverPresentationController;
@end
@interface UIScreen : NSObject
+ (instancetype)mainScreen;
@property(nonatomic) CGRect bounds;
@end
