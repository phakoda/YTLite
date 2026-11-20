#import <UIKit/UIKit.h>

@interface TranslatorVC : UITableViewController {
    UITableView *_tableView;
    UIButton *_translateButton;
    UITextView *_textView;
    NSString *_sourceText;
    NSInteger _langIndex;
    NSArray *_sections;
    NSArray *_type;
    NSArray *_translation;
    NSArray *_translate;
}
- (instancetype)initWithText:(NSString *)text;
- (void)closeButtonTapped;
- (UIButton *)menuButtonWithTitle:(NSString *)title array:(NSArray *)array;
- (UIImage *)systemImage:(NSString *)name withSize:(double)size;
- (BOOL)isRTL;
- (void)translateText;
@end
