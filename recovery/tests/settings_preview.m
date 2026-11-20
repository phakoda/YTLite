#import <UIKit/UIKit.h>
#import "../source/Settings/DVNTableViewController.h"

extern void YTLRunContentLayoutTests(NSMutableArray *, UIWindow *);

// This app uses the production table/model classes. YouTube-owned boundaries
// are absent; English labels below isolate UIKit geometry from localization.
@interface NSString (SettingsPreviewLocalization)
- (NSString *)ytl_localized;
@end
@implementation NSString (SettingsPreviewLocalization)
- (NSString *)ytl_localized { return self; }
@end
@interface SettingsPreviewDelegate : UIResponder <UIApplicationDelegate>
@property(nonatomic,strong) UIWindow *window;
@end
@implementation SettingsPreviewDelegate
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)options {
    NSUserDefaults *defaults = NSUserDefaults.standardUserDefaults;
    [defaults registerDefaults:@{@"rememberPlaybackSpeed":@YES,@"dontEatMyContent":@YES,@"rate":@1.75}];
    DVNTableModel *model = [DVNTableModel modelWithTitle:@"Player" sections:@[
        [DVNSection sectionWithHeader:@"Playback" footer:@"Your selected speed is remembered when you open another video." cells:@[
            [DVNCell cellWithTitle:@"Default playback speed" subtitle:nil titleIndexes:@[@"1×",@"1.5×",@"1.75×",@"2×"] type:3 key:@"defaultRate"],
            [DVNCell cellWithTitle:@"Remember playback speed" subtitle:@"Use the last speed you selected for the next video." type:0 key:@"rememberPlaybackSpeed"],
            [DVNCell sliderCellWithMinimum:0.25 maximum:5 divider:0.25 format:1 key:@"rate"]
        ] identifier:@"playback"],
        [DVNSection sectionWithHeader:@"Don’t Eat My Content" footer:@"Keep wide videos clear of the notch and Dynamic Island. Pinch to zoom still fills the screen." cells:@[
            [DVNCell cellWithTitle:@"Protect video from the notch" subtitle:nil type:0 key:@"dontEatMyContent"],
            [DVNCell cellWithTitle:@"Apply to all aspect ratios" subtitle:nil type:0 key:@"dontEatMyContentAllVideos"]
        ] identifier:@"notch"],
        [DVNSection sectionWithHeader:@"Preferred captions" footer:nil cells:@[
            [DVNCell cellWithTitleIndexes:@[@"Default",@"Off",@"Original",@"Custom"] key:@"captionsIndex"]
        ] identifier:@"captions"]
    ]];
    model.supportsSearching = YES;
    DVNTableViewController *table = [[DVNTableViewController alloc] initWithModel:model defaults:defaults];
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:table];
    [self.window makeKeyAndVisible];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2*NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [table.tableView layoutIfNeeded];
        NSMutableArray *errors = [NSMutableArray array];
        [table.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:2 inSection:0] atScrollPosition:UITableViewScrollPositionMiddle animated:NO];
        [table.tableView layoutIfNeeded];
        UITableViewCell *sliderCell = [table.tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:2 inSection:0]];
        UISlider *slider;
        for (UIView *view in sliderCell.contentView.subviews) if ([view isKindOfClass:UISlider.class]) slider=(id)view;
        if (!slider || CGRectIntersectsRect(slider.frame, sliderCell.detailTextLabel.frame)) [errors addObject:@"Slider overlaps value label"];
        for (UITableViewCell *cell in table.tableView.visibleCells) {
            if (CGRectGetHeight(cell.frame)<44) [errors addObject:@"Row smaller than touch target"];
            if (cell.textLabel.text.length && cell.textLabel.textAlignment!=NSTextAlignmentNatural) [errors addObject:@"Label alignment"];
            if (cell.textLabel.text.length && cell.accessoryView) {
                CGRect label=[cell.textLabel convertRect:cell.textLabel.bounds toView:cell];
                if (CGRectIntersectsRect(label,cell.accessoryView.frame)) [errors addObject:@"Label overlaps control"];
            }
        }
        [table.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:1 inSection:0] atScrollPosition:UITableViewScrollPositionMiddle animated:NO];
        [table.tableView layoutIfNeeded];
        UISwitch *control=(id)[table.tableView cellForRowAtIndexPath:[NSIndexPath indexPathForRow:1 inSection:0]].accessoryView;
        BOOL before=control.isOn;
        [table tableView:table.tableView didSelectRowAtIndexPath:[NSIndexPath indexPathForRow:1 inSection:0]];
        if ([defaults boolForKey:@"rememberPlaybackSpeed"]==before) [errors addObject:@"Tapping switch row did not save"];
        [control setOn:before]; [table toggleSwitch:control];
        YTLRunContentLayoutTests(errors, self.window);
        [table.tableView setContentOffset:CGPointMake(0,-table.tableView.adjustedContentInset.top) animated:NO];
        NSDictionary *report=@{@"errors":errors,@"visibleRows":@(table.tableView.visibleCells.count),@"actualUIKit":@YES};
        NSData *data=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
        NSString *path=[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES).firstObject stringByAppendingPathComponent:@"layout-report.json"];
        [data writeToFile:path atomically:YES];
    });
    return YES;
}
@end
int main(int argc,char **argv) { @autoreleasepool { return UIApplicationMain(argc,argv,nil,NSStringFromClass(SettingsPreviewDelegate.class)); } }
