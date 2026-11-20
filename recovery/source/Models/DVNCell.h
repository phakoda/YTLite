#import <Foundation/Foundation.h>

@class UIImage, UIColor, UIView, DVNTableModel;

// The package's @? encodings establish block storage, not invoke signatures.
// This opaque, unprototyped block type is for retaining/copying ONLY. Before
// invoking these callbacks, callers must recover and use the specific invoke
// prototype. Do not infer void return/no arguments from this storage typedef.
typedef void (^DVNStoredBlock)();

@interface DVNCell : NSObject
@property(nonatomic, strong) NSString *identifier;
@property(nonatomic, readonly) NSString *reuseIdentifier;
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *subtitle;
@property(nonatomic, strong) NSString *detailText;
@property(nonatomic, strong) NSString *key;
@property(nonatomic, strong) NSString *placeholder;
@property(nonatomic, strong) NSArray *titleIndexes;
@property(nonatomic, strong) NSArray *imageIndexes;
@property(nonatomic) double dividerValue;
@property(nonatomic) double minimumValue;
@property(nonatomic) double maximumValue;
@property(nonatomic) NSInteger sliderFormat;
@property(nonatomic) BOOL reloadsCell;
@property(nonatomic) BOOL reloadsTable;
@property(nonatomic) BOOL shouldHideDetail;
@property(nonatomic) NSInteger renderingMode;
@property(nonatomic, strong) UIImage *icon;
@property(nonatomic, strong) UIImage *image;
@property(nonatomic, strong) UIImage *accessoryIcon;
@property(nonatomic) NSInteger type;
@property(nonatomic, strong) UIColor *tintColor;
@property(nonatomic, weak) UIView *sourceView;
@property(nonatomic, strong) DVNTableModel *controllerModel;
@property(nonatomic, strong) NSDictionary *customData;
@property(nonatomic, copy) DVNStoredBlock handler;
@property(nonatomic, copy) DVNStoredBlock selfHandler;
@property(nonatomic, copy) DVNStoredBlock handlerWithCompletion;
@property(nonatomic, copy) DVNStoredBlock subtitleProvider;
@property(nonatomic, copy) DVNStoredBlock titleIndexesProvider;
@property(nonatomic, copy) DVNStoredBlock validationHandler;
@property(nonatomic, strong) NSString *errorText;

+ (instancetype)controllerCellWithModel:(DVNTableModel *)model title:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon;
+ (instancetype)cellWithTitleIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithImageIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle handler:(DVNStoredBlock)handler;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle selfHandler:(DVNStoredBlock)handler;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle type:(NSInteger)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon type:(NSInteger)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes type:(NSInteger)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type handler:(DVNStoredBlock)handler;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(UIImage *)image accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type handler:(DVNStoredBlock)handler;
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider key:(NSString *)key;
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key;
+ (instancetype)textFieldCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle placeholder:(NSString *)placeholder key:(NSString *)key;
+ (instancetype)timePickerWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum format:(NSInteger)format key:(NSString *)key;
+ (instancetype)stepperCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum step:(double)step format:(NSInteger)format key:(NSString *)key;
@end
