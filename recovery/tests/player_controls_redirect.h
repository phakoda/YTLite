#import <Foundation/Foundation.h>
void ControlsFixtureDispatch(dispatch_queue_t queue, dispatch_block_t block);
@interface NSData (ControlsFixture)
+ (instancetype)controlsFixtureDataWithContentsOfURL:(NSURL *)url;
@end
#define dispatch_async ControlsFixtureDispatch
#define dataWithContentsOfURL controlsFixtureDataWithContentsOfURL
