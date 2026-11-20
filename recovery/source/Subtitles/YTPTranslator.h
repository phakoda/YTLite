#import <Foundation/Foundation.h>

typedef void (^YTLTranslationCompletion)(NSString *translation, NSError *error);

@interface YTPTranslator : NSObject
+ (void)translateText:(NSString *)text fromLanguage:(NSString *)sourceLanguage toLanguage:(NSString *)targetLanguage completion:(YTLTranslationCompletion)completion;
+ (void)translateSingleText:(NSString *)text fromLanguage:(NSString *)sourceLanguage toLanguage:(NSString *)targetLanguage completion:(YTLTranslationCompletion)completion;
@end
