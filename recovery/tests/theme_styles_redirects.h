#import <Foundation/Foundation.h>
#import <objc/runtime.h>
FOUNDATION_EXPORT void ThemeFixtureDispatch(dispatch_queue_t queue, dispatch_block_t block);
FOUNDATION_EXPORT NSData *ThemeFixtureData(NSURL *url);
@interface NSData (ThemeFixtureData)
+ (NSData *)themeDataWithContentsOfURL:(NSURL *)url;
@end
#define dispatch_async ThemeFixtureDispatch
#define dataWithContentsOfURL themeDataWithContentsOfURL

#define NSLayoutConstraint ThemeFixtureConstraint
#define NSLayoutAnchor ThemeFixtureAnchor
