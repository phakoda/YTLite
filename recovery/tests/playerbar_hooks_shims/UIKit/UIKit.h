#pragma once
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
@class UIViewController,UIColor,UIImage;
typedef struct {CGFloat top,left,bottom,right;} UIEdgeInsets;
@interface UIView : NSObject
@property(nonatomic) CGRect frame,bounds;
@property UIEdgeInsets safeAreaInsets;
@property(nonatomic,strong) UIView *superview;
@property(nonatomic,strong) CALayer *layer;
@property(nonatomic,strong) UIColor *backgroundColor;
@property(nonatomic,strong) UIViewController *ancestor;
- (void)layoutSubviews;
@end
@interface UILabel : UIView
@property(nonatomic,copy) NSString *text;
@property NSUInteger fits;
- (void)sizeToFit;
@end
@interface UIViewController : NSObject
@property(nonatomic,strong) UIViewController *parentViewController;
@property(nonatomic,strong) id parentResponder;
@end
@interface UIColor : NSObject<NSSecureCoding> {CGColorRef _cgColor;}
@property(nonatomic,copy) NSString *name;
@property(nonatomic,readonly) CGColorRef CGColor;
+ (instancetype)named:(NSString *)name;
@end
@interface UIImage : NSObject
@property(nonatomic,copy) NSString *name;
@property(nonatomic,strong) UIColor *tint;
@end
@interface UISlider : UIView @end
@interface UIScreen : NSObject
@property CGRect bounds;
+ (instancetype)mainScreen;
@end
@interface UIGestureRecognizer : NSObject
@property CGPoint point;
@property(nonatomic,strong) UIView *locationView;
- (CGPoint)locationInView:(UIView *)view;
@end
@class UIDocumentPickerViewController;
