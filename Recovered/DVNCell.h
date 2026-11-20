#import <Foundation/Foundation.h>

@class UIImage, UIColor, UIView, DVNTableModel, DVNCell;

typedef void (^DVNCellHandler)(void);
typedef void (^DVNCellSelfHandler)(DVNCell *cell);
typedef void (^DVNCellCompletionHandler)(void (^completion)(void));
typedef NSString * (^DVNCellSubtitleProvider)(void);
typedef NSArray * (^DVNCellTitleIndexesProvider)(void);
typedef NSString * (^DVNCellValidationHandler)(NSString *text);

// Names below describe the recovered numeric values; the original enum names
// are not present in the package. Values are retained without renumbering.
typedef NS_ENUM(NSInteger, DVNCellType) {
    DVNCellTypeSwitch = 0,
    DVNCellTypeSegmented = 1,
    DVNCellTypeIndexed = 2,
    DVNCellTypeSelection = 3,
    DVNCellTypeController = 4,
    DVNCellTypeAction = 5,
    DVNCellTypeSlider = 6,
    DVNCellTypeTimePicker = 7,
    DVNCellTypeColor = 8,
    DVNCellTypeStepper = 9,
    DVNCellTypeTextField = 10,
    DVNCellTypeTextEditor = 11,
    DVNCellTypeMenu = 12,
};

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
@property(nonatomic) DVNCellType type;
@property(nonatomic, strong) UIColor *tintColor;
@property(nonatomic, weak) UIView *sourceView;
@property(nonatomic, strong) DVNTableModel *controllerModel;
@property(nonatomic, strong) NSDictionary *customData;
@property(nonatomic, copy) DVNCellHandler handler;
@property(nonatomic, copy) DVNCellSelfHandler selfHandler;
@property(nonatomic, copy) DVNCellCompletionHandler handlerWithCompletion;
@property(nonatomic, copy) DVNCellSubtitleProvider subtitleProvider;
@property(nonatomic, copy) DVNCellTitleIndexesProvider titleIndexesProvider;
@property(nonatomic, copy) DVNCellValidationHandler validationHandler;
@property(nonatomic, strong) NSString *errorText;

+ (instancetype)controllerCellWithModel:(DVNTableModel *)model title:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon;
+ (instancetype)cellWithTitleIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithImageIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle handler:(DVNCellHandler)handler;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle selfHandler:(DVNCellSelfHandler)handler;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle type:(DVNCellType)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon type:(DVNCellType)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes type:(DVNCellType)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessory type:(DVNCellType)type key:(NSString *)key;
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessory type:(DVNCellType)type handler:(DVNCellHandler)handler;
// Despite its selector, the image factory stores its last argument in selfHandler.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(UIImage *)image accessoryIcon:(UIImage *)accessory type:(DVNCellType)type handler:(DVNCellSelfHandler)handler;
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider key:(NSString *)key;
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key;
+ (instancetype)textFieldCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle placeholder:(NSString *)placeholder key:(NSString *)key;
+ (instancetype)timePickerWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum format:(NSInteger)format key:(NSString *)key;
+ (instancetype)stepperCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum step:(double)step format:(NSInteger)format key:(NSString *)key;
@end
