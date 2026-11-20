#pragma once
#import <UIKit/UIKit.h>

@interface DVNLongPressDelegate : NSObject <UIGestureRecognizerDelegate>
@property(nonatomic, weak) UIView *view;
@property(nonatomic) NSInteger mode;
- (BOOL)isTouchInSpeedZone:(CGPoint)point;
- (BOOL)gestureRecognizer:(UIGestureRecognizer *)recognizer shouldReceiveTouch:(UITouch *)touch;
@end
