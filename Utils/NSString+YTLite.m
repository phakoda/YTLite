#import "NSString+YTLite.h"
#import "NSBundle+YTLite.h"

@implementation NSString (YTL)
// 0x211308. An empty translation falls back to the key itself.
- (NSString *)ytl_localized {
    NSString *localized = [[NSBundle ytl_defaultBundle] localizedStringForKey:self value:nil table:nil];
    return localized.length ? localized : self;
}
@end
