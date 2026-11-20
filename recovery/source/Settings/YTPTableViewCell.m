#import "YTPTableViewCell.h"
#import <QuartzCore/QuartzCore.h>

@implementation YTPTableViewCell
// 0x1153f4. Raw dispatch table 0x118b518 yields false -> 0x115470,
// true -> 0x1154c0. The animation invoke at 0x11558c captures self strongly.
- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];
    if (selected) {
        self.layer.borderWidth = 1;
        self.layer.borderColor = [UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:0.5].CGColor;
    } else {
        [UIView animateWithDuration:0.5 animations:^{
            self.layer.borderColor = UIColor.clearColor.CGColor;
        }];
    }
}

// 0x115638. Double constants: 0xc4c2e0=.3, 0xc4c2f8=.9, 0xc4c258=.15.
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier {
    self = [super initWithStyle:style reuseIdentifier:identifier];
    if (self) {
        [self setValue:@0.3 forKey:@"_selectionFadeDuration"];
        self.backgroundColor = UIColor.clearColor;
        self.selectedBackgroundView = [UIView new];
        self.selectedBackgroundView.backgroundColor = [UIColor colorWithRed:0.75 green:0.5 blue:0.9 alpha:0.15];
        self.textLabel.font = [UIFont systemFontOfSize:UIScreen.mainScreen.scale == 3.0 ? 16 : 14];
        self.textLabel.adjustsFontSizeToFitWidth = YES;
        self.detailTextLabel.textColor = UIColor.secondaryLabelColor;
        self.detailTextLabel.font = [UIFont systemFontOfSize:12];
        self.detailTextLabel.numberOfLines = 0;
    }
    return self;
}
@end
