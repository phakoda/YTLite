#import <Foundation/Foundation.h>

@class UIView, UIDocumentPickerViewController;
typedef void (^YTLPreferencesImportCompletion)(BOOL success);
typedef void (^YTLPreferencesPickerCompletion)(NSURL * _Nullable url);

NS_ASSUME_NONNULL_BEGIN

@interface YTLUserDefaults : NSUserDefaults

@property (class, readonly, strong) YTLUserDefaults *standardUserDefaults;
@property (nonatomic, copy, nullable) YTLPreferencesPickerCompletion prefsPickerCompletion;

- (void)reset;
- (void)registerDefaults;
- (nullable NSData *)colorForSegment:(NSString *)segment;
- (nullable NSString *)sbPrivateUserID;
- (NSString *)sbPublicUserID:(nullable NSString *)privateUserID;
- (void)presentDocumentPicker:(YTLPreferencesPickerCompletion)completion;
- (void)documentPicker:(UIDocumentPickerViewController *)controller didPickDocumentAtURL:(NSURL *)url;

+ (void)resetUserDefaults;
+ (void)importYtlSettings:(YTLPreferencesImportCompletion)completion;
+ (void)exportYtlSettings:(UIView *)sourceView;

+ (BOOL)boolForKey:(NSString *)key;
+ (NSInteger)integerForKey:(NSString *)key;
+ (double)floatForKey:(NSString *)key;
+ (void)setBool:(BOOL)value forKey:(NSString *)key;
+ (void)setInteger:(NSInteger)value forKey:(NSString *)key;
+ (void)setFloat:(double)value forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
