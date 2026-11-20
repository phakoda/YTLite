#pragma once
#import <Foundation/Foundation.h>
@interface UIViewController : NSObject
@property(nonatomic,strong) UIViewController *presented;
@property(nonatomic,copy) void (^dismissCompletion)(void);
@property BOOL presentAnimated,dismissAnimated,appearedAnimated;
- (void)viewDidAppear:(BOOL)animated;
- (void)presentViewController:(UIViewController *)controller animated:(BOOL)animated completion:(void (^)(void))completion;
- (void)dismissViewControllerAnimated:(BOOL)animated completion:(void (^)(void))completion;
@end
