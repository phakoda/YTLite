#import <UIKit/UIKit.h>

@interface WelcomeVC : UIViewController <UITableViewDataSource, UITableViewDelegate> {
    UITableView *_tableView;
    NSArray *_settingsData;
}
- (void)thanksButtonTapped;
- (void)contactsButtonTapped:(UIButton *)sender;
- (UIImage *)imageNamed:(NSString *)name;
- (void)showAlertWithTitle:(NSString *)title imageName:(NSString *)name;
- (UIImage *)cellImageWithName:(NSString *)name;
@end
