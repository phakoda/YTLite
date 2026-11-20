#import <Foundation/Foundation.h>
@class UIImage, UIColor;

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (YTLite)

// Packaged bundle lookup, including the recovered libroot path resolver.
@property (class, nonatomic, readonly) NSBundle *ytl_defaultBundle;
- (nullable UIImage *)imageWithName:(NSString *)name;
- (nullable UIImage *)originalImageWithName:(NSString *)name;
- (nullable UIImage *)imageWithName:(NSString *)name tintColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
