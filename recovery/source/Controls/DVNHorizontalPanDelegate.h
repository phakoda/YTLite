#pragma once
#import <UIKit/UIKit.h>

@interface DVNHorizontalPanDelegate : NSObject <UIGestureRecognizerDelegate>
- (BOOL)gestureRecognizerShouldBegin:(UIGestureRecognizer *)recognizer;
@end
