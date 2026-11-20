#pragma once
#import <Foundation/Foundation.h>
@class UIColor;
enum {UIControlStateNormal=0};
@interface UIImage : NSObject @end
@interface UIView : NSObject @end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIViewController *parentViewController;
@end
@interface UIButton : UIView
@property(nonatomic,strong) UIImage *fixtureImage;
@property(nonatomic) NSUInteger fixtureState;
- (void)setImage:(UIImage *)image forState:(NSUInteger)state;
@end
