#import "YTPTranslator.h"

@implementation YTPTranslator

// 0x1de550; per-chunk callback 0x1decd8, group completion 0x1dee84.
// The limit is measured in NSString UTF-16 units, not UTF-8 bytes or graphemes.
+ (void)translateText:(NSString *)text fromLanguage:(NSString *)sourceLanguage toLanguage:(NSString *)targetLanguage completion:(YTLTranslationCompletion)completion {
    if (text.length <= 1500) {
        [self translateSingleText:text fromLanguage:sourceLanguage toLanguage:targetLanguage completion:completion];
        return;
    }
    NSMutableArray<NSString *> *chunks = [NSMutableArray array];
    for (NSUInteger offset = 0; offset < text.length;) {
        NSUInteger length = MIN((NSUInteger)1500, text.length - offset);
        NSString *chunk = [text substringWithRange:NSMakeRange(offset, length)];
        if (offset + length < text.length) {
            NSRange period = [chunk rangeOfString:@"." options:NSBackwardsSearch];
            NSRange newline = [chunk rangeOfString:@"\n" options:NSBackwardsSearch];
            NSUInteger periodEnd = period.location == NSNotFound ? 0 : period.location + 1;
            NSUInteger newlineEnd = newline.location == NSNotFound ? 0 : newline.location + 1;
            NSUInteger boundary = MAX(periodEnd, newlineEnd);
            if (boundary != 0 && boundary < length) {
                length = boundary;
                chunk = [text substringWithRange:NSMakeRange(offset, length)];
            }
        }
        [chunks addObject:chunk];
        offset += length;
    }
    NSMutableArray<NSString *> *translations = [NSMutableArray arrayWithCapacity:chunks.count];
    __block NSError *lastError = nil;
    dispatch_group_t group = dispatch_group_create();
    for (NSString *chunk in chunks) {
        dispatch_group_enter(group);
        [self translateSingleText:chunk fromLanguage:sourceLanguage toLanguage:targetLanguage completion:^(NSString *translation, NSError *error) {
            @synchronized (translations) {
                if (error) lastError = error;
                else [translations addObject:translation];
            }
            dispatch_group_leave(group);
        }];
    }
    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        if (lastError) completion(nil, lastError);
        else completion([translations componentsJoinedByString:@""], nil);
    });
    // Results intentionally retain completion order, not input order. This is
    // the packaged behavior; the original callback captures no chunk index.
}

// 0x1defc8, network block 0x1df82c (tail reviewed at 0x1dfb28..0x1dff84).
// Unlike the chunked method, completion runs on the session's callback queue.
+ (void)translateSingleText:(NSString *)text fromLanguage:(NSString *)sourceLanguage toLanguage:(NSString *)targetLanguage completion:(YTLTranslationCompletion)completion {
    NSString *normalized = [[text stringByReplacingOccurrencesOfString:@"№" withString:@"No"]
                            stringByReplacingOccurrencesOfString:@"–" withString:@"-"];
    NSString *escaped = [normalized stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    NSString *address = [NSString stringWithFormat:@"https://translate.googleapis.com/translate_a/single?client=gtx&sl=%@&tl=%@&dt=t&q=%@",
                         sourceLanguage, targetLanguage, escaped];
    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithURL:[NSURL URLWithString:address]
        completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
        if (error) { completion(nil, error); return; }
        NSError *jsonError = nil;
        id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:&jsonError];
        if (jsonError) {
            NSLog(@"JSON Error: %@", jsonError);
            completion(nil, jsonError);
            return;
        }
        NSString *translation = @"";
        if ([json isKindOfClass:[NSArray class]] && [json count] > 0) {
            for (id entry in json[0]) {
                if ([entry isKindOfClass:[NSArray class]] && [entry count] > 0) {
                    translation = [translation stringByAppendingString:entry[0]];
                }
            }
        }
        completion(translation, nil);
    }];
    [task resume];
}
@end
