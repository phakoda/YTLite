#pragma once
#import <UIKit/UIKit.h>

@interface DVNSheetPresenter : NSObject
+ (void)presentCustomHeightViewController:(UIViewController *)controller
                      fromViewController:(UIViewController *)presenter;
+ (void)presentHalfScreenViewController:(UIViewController *)controller
                    fromViewController:(UIViewController *)presenter;
+ (void)presentViewController:(UIViewController *)controller
          fromViewController:(UIViewController *)presenter withHeight:(double)height;
@end
