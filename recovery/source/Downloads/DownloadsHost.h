#pragma once
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Narrow declarations of host-owned contracts. No replacement classes are defined here.
@interface NSBundle (YTPDownloadsHost)
+ (NSBundle *)ytl_defaultBundle;
- (UIImage *)imageWithName:(NSString *)name;
- (UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color;
@end
@protocol YTPDownloadsPreferences <NSObject>
+ (BOOL)boolForKey:(id)key;
+ (long long)integerForKey:(id)key;
+ (double)floatForKey:(id)key;
@end
@protocol YTPDownloadsPageStyle <NSObject>
- (id)responderRoot;
- (long long)pageStyle;
@end
static inline Class<YTPDownloadsPreferences> YTPDownloadsDefaults(void) {
    return (Class<YTPDownloadsPreferences>)NSClassFromString(@"YTLUserDefaults");
}
static inline NSString *YTPDownloadsLocalized(NSString *key) {
    return [[NSBundle ytl_defaultBundle] localizedStringForKey:key value:nil table:nil];
}

// Shared local-only preferences; downloads do not require account activation.
#import "../Runtime/YTLFeaturePolicy.h"
