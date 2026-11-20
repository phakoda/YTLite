#import "YTPDB.h"

@implementation YTPDB

// Literal arrays are generated from CFString flags, decoded bytes, and original
// stack-array order, including UTF-16 entries outside the __cfstring section.
#include "YTPDBStrings.inc"

// 0x2104c4. Keep an unrecognized localization's original identifier in the list.
+ (NSArray *)supportedLanguages {
    NSMutableArray *names = [[[NSBundle mainBundle] localizations] mutableCopy];
    for (NSUInteger index = 0; index < names.count; index++) {
        NSString *display = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:names[index]];
        if (display) names[index] = display;
    }
    names = [[[NSOrderedSet orderedSetWithArray:names] array] mutableCopy];
    [names sortUsingSelector:@selector(localizedCaseInsensitiveCompare:)];
    return [names copy];
}

// 0x21079c. First localization wins when display names collide; an unmapped
// display name is not inserted. Negative and out-of-range indexes return nil.
+ (NSString *)langCodeForIndex:(NSInteger)index {
    NSArray *names = [self supportedLanguages];
    NSArray *localizations = [[NSBundle mainBundle] localizations];
    NSMutableDictionary *codesByDisplayName = [NSMutableDictionary dictionary];
    for (NSString *code in localizations) {
        NSString *display = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:code];
        if (display && !codesByDisplayName[display]) codesByDisplayName[display] = code;
    }
    if (index < 0 || (NSUInteger)index >= names.count) return nil;
    return codesByDisplayName[names[(NSUInteger)index]];
}

// 0x210c88.
+ (NSUInteger)indexOfPreferredLanguage {
    NSArray *names = [self supportedLanguages];
    NSString *preferred = [[[NSBundle mainBundle] preferredLocalizations] firstObject];
    NSString *display = [[NSLocale currentLocale] displayNameForKey:NSLocaleIdentifier value:preferred];
    if (!display) return 0;
    NSUInteger index = [names indexOfObject:display];
    return index == NSNotFound ? 0 : index;
}
@end
