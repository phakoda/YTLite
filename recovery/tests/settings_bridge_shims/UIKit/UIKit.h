#pragma once
#import <Foundation/Foundation.h>
@class UIColor, UIImage, UIView, UIViewController, UINavigationController, UICollectionView;
@class UISearchBar, UIPickerView, UITextField, UIBarButtonItem, UISegmentedControl, UISlider, UIStepper;
@protocol UISearchBarDelegate @end
@protocol UIPickerViewDelegate @end
@protocol UIPickerViewDataSource @end
@protocol UITextFieldDelegate @end
@interface UIColor : NSObject
+ (UIColor *)labelColor;
@end
@interface UIView : NSObject
@property(nonatomic, copy) NSString *accessibilityIdentifier;
@property(nonatomic, strong) UIColor *tintColor;
- (void)layoutSubviews;
@end
@interface UIButton : UIView @end
@interface UICollectionView : UIView @end
@interface UIViewController : NSObject
@property(nonatomic, strong) UIViewController *parentViewController;
@property(nonatomic, strong) UINavigationController *navigationController;
@property(nonatomic, copy) NSString *title;
@end
@interface UINavigationController : UIViewController
- (void)pushViewController:(UIViewController *)controller animated:(BOOL)animated;
@end
@interface UITableViewController : UIViewController @end
@interface NSIndexPath (SettingsBridgeUIKit)
@property(nonatomic, readonly) NSInteger section;
@property(nonatomic, readonly) NSInteger row;
@end
