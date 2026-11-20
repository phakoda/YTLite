#import <Foundation/Foundation.h>

@interface YTPDB : NSObject
+ (NSArray *)thanks;
+ (NSArray *)clip;
+ (NSArray *)report;
+ (NSArray *)hype;
+ (NSArray *)stopAds;
+ (NSArray *)supportedLanguages;
+ (NSString *)langCodeForIndex:(NSInteger)index;
+ (NSUInteger)indexOfPreferredLanguage;
@end
