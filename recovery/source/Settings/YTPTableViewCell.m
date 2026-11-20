#import "YTPTableViewCell.h"

@implementation YTPTableViewCell
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)identifier {
    self = [super initWithStyle:style reuseIdentifier:identifier];
    if (self) {
        self.backgroundColor = UIColor.secondarySystemGroupedBackgroundColor;
        self.textLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleBody];
        self.textLabel.adjustsFontForContentSizeCategory = YES;
        self.textLabel.textAlignment = NSTextAlignmentNatural;
        self.textLabel.textColor = UIColor.labelColor;
        self.textLabel.numberOfLines = 0;
        self.detailTextLabel.font = [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline];
        self.detailTextLabel.adjustsFontForContentSizeCategory = YES;
        self.detailTextLabel.textColor = UIColor.secondaryLabelColor;
        self.detailTextLabel.numberOfLines = 0;
    }
    return self;
}
@end
