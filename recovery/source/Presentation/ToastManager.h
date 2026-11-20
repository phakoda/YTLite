#pragma once
#import <Foundation/Foundation.h>
@class ToastView, YTToastOffsetController;

@interface ToastManager : NSObject {
    BOOL _isPinnedTop;
    BOOL _isFullscreen;
    NSMutableArray *_toasts;
    YTToastOffsetController *_offsetController;
}
@property(nonatomic, strong) NSMutableArray *toasts;
@property(nonatomic, strong) YTToastOffsetController *offsetController;
@property(nonatomic) BOOL isPinnedTop;
@property(nonatomic) BOOL isFullscreen;
+ (instancetype)sharedManager;
+ (void)showMessageWithText:(NSString *)text isSuccess:(BOOL)success;
- (instancetype)init;
- (void)registerToast:(ToastView *)toast;
- (void)unregisterToast:(ToastView *)toast;
- (void)updateAllToasts;
@end
