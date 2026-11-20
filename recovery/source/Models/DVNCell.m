#import "DVNCell.h"

@implementation DVNCell

// -[DVNCell init], 0x18f954.
- (instancetype)init {
    self = [super init];
    if (self) _reuseIdentifier = [[NSUUID UUID] UUIDString];
    return self;
}

// 0x18fa30. Factories allocate the concrete class, not self.
+ (instancetype)controllerCellWithModel:(DVNTableModel *)model title:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.controllerModel = model; cell.title = title; cell.subtitle = subtitle;
    cell.icon = icon; cell.type = 4;
    return cell;
}

// 0x18fb20.
+ (instancetype)cellWithTitleIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.titleIndexes = indexes; cell.key = key; cell.type = 1;
    return cell;
}

// 0x18fbb8.
+ (instancetype)cellWithImageIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.imageIndexes = indexes; cell.key = key; cell.type = 1;
    return cell;
}

// 0x18fc50.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle handler:(DVNStoredBlock)handler {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.handler = handler; cell.type = 5;
    return cell;
}

// 0x18fd10.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle selfHandler:(DVNStoredBlock)handler {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.selfHandler = handler; cell.type = 5;
    return cell;
}

// 0x18fdd0.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle type:(NSInteger)type key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.type = type; cell.key = key;
    return cell;
}

// 0x18fe9c.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon type:(NSInteger)type key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.icon = icon; cell.type = type; cell.key = key;
    return cell;
}

// 0x18ff90.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle imageIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.imageIndexes = indexes; cell.type = 2; cell.key = key;
    return cell;
}

// 0x190080.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.titleIndexes = indexes; cell.type = 2; cell.key = key;
    return cell;
}

// 0x190170.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle titleIndexes:(NSArray *)indexes type:(NSInteger)type key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.titleIndexes = indexes; cell.type = type; cell.key = key;
    return cell;
}

// 0x190264.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.icon = icon; cell.accessoryIcon = accessoryIcon;
    cell.type = type; cell.key = key;
    return cell;
}

// 0x190388.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle icon:(UIImage *)icon accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type handler:(DVNStoredBlock)handler {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.icon = icon; cell.accessoryIcon = accessoryIcon;
    cell.type = type; cell.handler = handler;
    return cell;
}

// 0x1904ac. Unlike the icon factory, this stores its argument in selfHandler.
+ (instancetype)cellWithTitle:(NSString *)title subtitle:(NSString *)subtitle image:(UIImage *)image accessoryIcon:(UIImage *)accessoryIcon type:(NSInteger)type handler:(DVNStoredBlock)handler {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.image = image; cell.renderingMode = 1;
    cell.accessoryIcon = accessoryIcon; cell.type = type; cell.selfHandler = handler;
    return cell;
}

// 0x1905e4. This forwarding factory does dispatch to self.
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider key:(NSString *)key {
    return [self sliderCellWithMinimum:minimum maximum:maximum divider:divider format:0 key:key];
}

// 0x1905f8.
+ (instancetype)sliderCellWithMinimum:(double)minimum maximum:(double)maximum divider:(double)divider format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.minimumValue = minimum; cell.maximumValue = maximum; cell.dividerValue = divider;
    cell.sliderFormat = format; cell.type = 6; cell.key = key;
    return cell;
}

// 0x1906d8.
+ (instancetype)textFieldCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle placeholder:(NSString *)placeholder key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.placeholder = placeholder; cell.type = 10; cell.key = key;
    return cell;
}

// 0x1907c8.
+ (instancetype)timePickerWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.minimumValue = minimum; cell.maximumValue = maximum;
    cell.sliderFormat = format; cell.type = 7; cell.key = key;
    return cell;
}

// 0x1908e0.
+ (instancetype)stepperCellWithTitle:(NSString *)title subtitle:(NSString *)subtitle minimum:(double)minimum maximum:(double)maximum step:(double)step format:(NSInteger)format key:(NSString *)key {
    DVNCell *cell = [[DVNCell alloc] init];
    cell.title = title; cell.subtitle = subtitle; cell.minimumValue = minimum; cell.maximumValue = maximum;
    cell.dividerValue = step; cell.sliderFormat = format; cell.type = 9; cell.key = key;
    return cell;
}

// Accessors 0x190a18..0x190fac and .cxx_destruct 0x190fe0 are synthesized.
@end
