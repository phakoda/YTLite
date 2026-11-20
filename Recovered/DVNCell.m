#import "DVNCell.h"

@implementation DVNCell

// -[DVNCell init], VA 0x18f954. reuseIdentifier has no setter in the package.
- (instancetype)init {
    self = [super init];
    if (self) _reuseIdentifier = NSUUID.UUID.UUIDString;
    return self;
}

// Factory assignments and their order follow recovery/classes/DVNCell.c.
// They deliberately allocate DVNCell rather than a possibly overridden self.
+ (instancetype)controllerCellWithModel:(DVNTableModel *)model title:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon {
    DVNCell *cell = [DVNCell new];
    cell.controllerModel = model;
    cell.title = title;
    cell.subtitle = subtitle;
    cell.icon = icon;
    cell.type = DVNCellTypeController;
    return cell;
}

+ (instancetype)cellWithTitleIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.titleIndexes = indexes;
    cell.key = key;
    cell.type = DVNCellTypeSegmented;
    return cell;
}

+ (instancetype)cellWithImageIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.imageIndexes = indexes;
    cell.key = key;
    cell.type = DVNCellTypeSegmented;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle handler:(DVNCellHandler)handler {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.handler = handler;
    cell.type = DVNCellTypeAction;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle selfHandler:(DVNCellSelfHandler)handler {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.selfHandler = handler;
    cell.type = DVNCellTypeAction;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle type:(DVNCellType)type key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.type = type;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon type:(DVNCellType)type key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.icon = icon;
    cell.type = type;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.imageIndexes = indexes;
    cell.type = DVNCellTypeIndexed;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.titleIndexes = indexes;
    cell.type = DVNCellTypeIndexed;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes type:(DVNCellType)type key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.titleIndexes = indexes;
    cell.type = type;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessory type:(DVNCellType)type key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.icon = icon;
    cell.accessoryIcon = accessory;
    cell.type = type;
    cell.key = key;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessory type:(DVNCellType)type handler:(DVNCellHandler)handler {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.icon = icon;
    cell.accessoryIcon = accessory;
    cell.type = type;
    cell.handler = handler;
    return cell;
}

+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(UIImage *)image accessoryIcon:(UIImage *)accessory type:(DVNCellType)type handler:(DVNCellSelfHandler)handler {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.image = image;
    cell.renderingMode = 1;
    cell.accessoryIcon = accessory;
    cell.type = type;
    cell.selfHandler = handler;
    return cell;
}

+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider key:(NSString *)key {
    // VA 0x1905e4 is a forwarding factory, unlike the allocating factories.
    return [self sliderCellWithMinimum:minimum maximum:maximum divider:divider format:0 key:key];
}

+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.minimumValue = minimum;
    cell.maximumValue = maximum;
    cell.dividerValue = divider;
    cell.sliderFormat = format;
    cell.type = DVNCellTypeSlider;
    cell.key = key;
    return cell;
}

+ (instancetype)textFieldCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle placeholder:(NSString *)placeholder key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.placeholder = placeholder;
    cell.type = DVNCellTypeTextField;
    cell.key = key;
    return cell;
}

+ (instancetype)timePickerWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.minimumValue = minimum;
    cell.maximumValue = maximum;
    cell.sliderFormat = format;
    cell.type = DVNCellTypeTimePicker;
    cell.key = key;
    return cell;
}

+ (instancetype)stepperCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum step:(double)step format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [DVNCell new];
    cell.title = title;
    cell.subtitle = subtitle;
    cell.minimumValue = minimum;
    cell.maximumValue = maximum;
    cell.dividerValue = step;
    cell.sliderFormat = format;
    cell.type = DVNCellTypeStepper;
    cell.key = key;
    return cell;
}

@end
