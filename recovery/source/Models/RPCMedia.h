#import <Foundation/Foundation.h>

@interface RPCMedia : NSObject
@property(nonatomic, copy) NSString *videoID;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *author;
@property(nonatomic) BOOL isPaused;
@property(nonatomic) double totalTime;
@property(nonatomic) double currentTime;
@property(nonatomic, copy) NSString *thumbnailURL;
+ (instancetype)mediaWithPlayer:(id)player;
@end
