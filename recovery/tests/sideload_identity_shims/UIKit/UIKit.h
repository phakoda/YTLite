#pragma once
#import <Foundation/Foundation.h>
@class UIImage, UIColor;
@interface UIViewController:NSObject
- (void)viewDidAppear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
@end
@interface UIDevice:NSObject
+ (instancetype)currentDevice;
@end
