#pragma once
// Test-only UIKit boundary. Production is compiled separately with Apple's SDK.
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
@class UIGestureRecognizer;
@interface UIImage : NSObject @end
@interface UIColor : NSObject
@property(nonatomic, strong) NSArray *components;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;
@end
@interface UIView : NSObject
@property(nonatomic) CGRect frame;
@property(nonatomic) BOOL userInteractionEnabled;
@property(nonatomic, strong) NSMutableArray *gestures;
- (instancetype)initWithFrame:(CGRect)frame;
- (void)addGestureRecognizer:(UIGestureRecognizer *)gesture;
@end
@interface UILabel : UIView
@property(nonatomic, strong) NSAttributedString *attributedText;
@property(nonatomic) NSUInteger fits;
- (void)sizeToFit;
@end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIView *view;
@end
@interface UIWindow : UIView
@property(nonatomic, strong) UIViewController *rootViewController;
@end
@interface UIApplication : NSObject
@property(nonatomic, strong) id delegate;
+ (instancetype)sharedApplication;
@end
typedef NS_ENUM(NSInteger, UIGestureRecognizerState) { UIGestureRecognizerStatePossible, UIGestureRecognizerStateBegan, UIGestureRecognizerStateChanged, UIGestureRecognizerStateEnded };
@interface UIGestureRecognizer : NSObject
@property(nonatomic) UIGestureRecognizerState state;
@property(nonatomic, weak) id target;
@property(nonatomic) SEL action;
- (void)removeTarget:(id)target action:(SEL)action;
- (void)addTarget:(id)target action:(SEL)action;
@end
@interface UITapGestureRecognizer : UIGestureRecognizer
@property(nonatomic) NSUInteger numberOfTapsRequired;
@end
typedef NS_ENUM(NSInteger, UIDatePickerMode) { UIDatePickerModeTime = 0 };
typedef NS_ENUM(NSInteger, UIDatePickerStyle) { UIDatePickerStyleWheels = 1 };
@interface UIDatePicker : UIView
@property(nonatomic) UIDatePickerMode datePickerMode;
@property(nonatomic) UIDatePickerStyle preferredDatePickerStyle;
@property(nonatomic, strong) NSLocale *locale;
@property(nonatomic, strong) NSDate *date;
@end
@interface NSTextAttachment : NSObject
@property(nonatomic, strong) UIImage *image;
@property(nonatomic) CGRect bounds;
@end
@interface NSAttributedString (SleepTestAttachment)
+ (instancetype)attributedStringWithAttachment:(NSTextAttachment *)attachment;
@end
