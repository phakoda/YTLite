#import <UIKit/UIKit.h>

@protocol YTLWelcomeSheet <NSObject>
+ (instancetype)sheetControllerWithMessage:(NSString *)message subMessage:(NSString *)subMessage delegate:(id)delegate parentResponder:(id)parent;
- (id)valueForKey:(NSString *)key;
- (void)addAction:(id)action;
- (void)setSourceView:(UIView *)view;
- (void)presentFromViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
@end
@protocol YTLWelcomeAction <NSObject>
+ (instancetype)actionWithTitle:(NSString *)title iconImage:(UIImage *)image secondaryIconImage:(UIImage *)secondary accessibilityIdentifier:(NSString *)identifier handler:(void (^)(void))handler;
@end
@protocol YTLWelcomeSheetHeader <NSObject>
- (id)valueForKey:(NSString *)key;
- (void)showHeaderDivider;
@end
