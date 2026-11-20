#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,failures,managerCalls,creates,fileWrites,urlWrites;
static NSMutableArray *trace;
static BOOL watching,existsFlag,directoryFlag,creationResult,creationError;
static NSString *rootPath;
static NSURL *writtenURL;
static BOOL writeResult;
static dispatch_block_t pending;
static NSData *readResult;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
void FirstThumbnailDispatch(dispatch_queue_t queue,dispatch_block_t block){Event(@"enqueue");Check(queue==dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0),@"default global queue");pending=[block copy];}
NSString *FirstThumbnailTemporaryDirectory(void){Event(@"temporary");return rootPath;}
@interface ThumbnailNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,copy) void (^onURL)(void);
@end
@implementation ThumbnailNode
- (void)event:(NSString *)key{Event([NSString stringWithFormat:@"%@.%@",self.tag,key]);}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (NSString *)videoID{[self event:@"id"];return [super videoID];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (id)thumbnail{[self event:@"thumbnail"];return [super thumbnail];}
- (NSArray *)thumbnailsArray{[self event:@"thumbnails"];return [super thumbnailsArray];}
- (id)URL{[self event:@"URL"];if(self.onURL)self.onURL();return [super URL];}
@end
@interface ThumbnailData : NSData
@property(nonatomic,strong) NSData *backing;
@end
@implementation ThumbnailData
- (NSUInteger)length{return self.backing.length;}
- (const void *)bytes{return self.backing.bytes;}
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)atomic{(void)path;(void)atomic;++fileWrites;Event(@"writeFile");return NO;}
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomic{
    ++urlWrites;Event(@"writeURL");writtenURL=url;Check(atomic,@"atomic thumbnail write");
    Check([url.path hasPrefix:[rootPath stringByAppendingString:@"/"]],@"thumbnail write confined to fixture root");
    writeResult=[self.backing writeToURL:url atomically:atomic];return writeResult;
}
@end
@interface ThumbnailManager : NSFileManager
@property(nonatomic,copy) NSString *tag;
@end
@implementation ThumbnailManager
- (BOOL)fileExistsAtPath:(NSString *)path isDirectory:(BOOL *)directory{
    Event([self.tag stringByAppendingString:@".exists"]);Equal(path,rootPath,@"check temporary directory itself");Check(directory!=NULL&&!*directory,@"directory flag initialized to NO");*directory=directoryFlag;return existsFlag;
}
- (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)intermediates attributes:(NSDictionary *)attributes error:(NSError *__autoreleasing *)error{
    ++creates;Event([self.tag stringByAppendingString:@".create"]);Equal(path,rootPath,@"only temporary root created");Check(intermediates&&attributes==nil&&error!=NULL,@"directory creation arguments");
    if(error)*error=creationError?[NSError errorWithDomain:@"fixture" code:1 userInfo:@{NSLocalizedDescriptionKey:@"fixture creation error"}]:nil;return creationResult;
}
@end
static ThumbnailManager *checker,*creator;
static IMP originalManager,originalRead;
static id Manager(id cls,SEL selector){(void)cls;(void)selector;Event(@"manager");return managerCalls++?creator:checker;}
static id Read(id cls,SEL selector,NSURL *url){(void)cls;(void)selector;Event(@"read");Equal(url,[NSURL URLWithString:@"https://fixture.invalid/last"],@"last thumbnail URL selected");return readResult;}
static ThumbnailNode *Node(NSString *tag){ThumbnailNode *n=[ThumbnailNode new];n.tag=tag;return n;}
static void Reset(void){[trace removeAllObjects];managerCalls=creates=fileWrites=urlWrites=0;writtenURL=nil;writeResult=NO;pending=nil;watching=YES;}
int main(int argc,const char **argv){@autoreleasepool{
    if(argc!=2)return 2;rootPath=[NSString stringWithUTF8String:argv[1]];Check([rootPath containsString:@"/.recovery-work/first-menu-thumbnail/"],@"fixture root scope");
    NSFileManager *realManager=[NSFileManager defaultManager];[realManager removeItemAtPath:[rootPath stringByAppendingPathComponent:@"at-callback"] error:nil];[realManager createDirectoryAtPath:rootPath withIntermediateDirectories:YES attributes:nil error:nil];
    trace=[NSMutableArray new];checker=[ThumbnailManager new];checker.tag=@"checkManager";creator=[ThumbnailManager new];creator.tag=@"createManager";
    originalManager=method_setImplementation(class_getClassMethod(NSFileManager.class,@selector(defaultManager)),(IMP)Manager);
    originalRead=method_setImplementation(class_getClassMethod(NSData.class,@selector(dataWithContentsOfURL:)),(IMP)Read);
    ThumbnailNode *player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details"),*thumbnail=Node(@"thumbnail"),*last=Node(@"last"),*first=Node(@"first");
    player.playerResponse=response;response.playerData=data;data.videoDetails=details;details.thumbnail=thumbnail;thumbnail.thumbnailsArray=@[first,last];first.URL=@"https://fixture.invalid/wrong";last.URL=@"https://fixture.invalid/last";
    __weak ThumbnailNode *weakResponse=response;last.onURL=^{weakResponse.videoID=@"too-late";};
    ThumbnailData *bytes=[ThumbnailData new];bytes.backing=[@"thumbnail bytes" dataUsingEncoding:NSUTF8StringEncoding];DownloadMenuHelper *h=[DownloadMenuHelper new];
    for(NSUInteger mode=0;mode<8;++mode){
        existsFlag=(mode&1)!=0;directoryFlag=(mode&2)!=0;creationError=(mode&4)!=0;creationResult=!creationError;readResult=bytes;response.videoID=@"before-queue";
        Reset();[h getThumbnail:player];Equal(trace,(@[@"player.response",@"enqueue"]),@"thumbnail work is deferred");Check(pending!=nil,@"queued callback retained");
        response.videoID=@"at-callback";[trace removeAllObjects];dispatch_block_t callback=pending;pending=nil;callback();watching=NO;
        BOOL shouldCreate=!(existsFlag&&directoryFlag);
        Equal([trace subarrayWithRange:NSMakeRange(0,8)],(@[@"response.id",@"response.data",@"data.details",@"details.thumbnail",@"thumbnail.thumbnails",@"last.URL",@"read",@"temporary"]),@"video ID and temporary-path timing");
        Check(managerCalls==(shouldCreate?2:1),@"fresh manager for directory creation");Check(creates==(shouldCreate?1:0),@"directory existence conjunction");Check(!fileWrites&&urlWrites==1,@"URL write selector used exactly once");
        Equal(writtenURL.path,[rootPath stringByAppendingPathComponent:@"at-callback/thumbnail.webp"],@"destination uses ID captured before URL getter");Check(!writeResult,@"missing video subdirectory is not created by thumbnail code");
        Check([trace containsObject:@"createManager.create"]==shouldCreate,@"creation uses the second manager");
    }
    // A nil read stops before any temporary-directory or file operation.
    readResult=nil;Reset();[h getThumbnail:player];pending();watching=NO;Check(!managerCalls&&!creates&&!urlWrites&&!fileWrites,@"nil bytes stop filesystem work");Check(![trace containsObject:@"temporary"],@"nil bytes skip temporary lookup");
    // Successful bytes are saved when another component has made the parent.
    method_setImplementation(class_getClassMethod(NSFileManager.class,@selector(defaultManager)),originalManager);
    NSString *videoDirectory=[rootPath stringByAppendingPathComponent:@"at-callback"];[realManager createDirectoryAtPath:videoDirectory withIntermediateDirectories:YES attributes:nil error:nil];
    method_setImplementation(class_getClassMethod(NSFileManager.class,@selector(defaultManager)),(IMP)Manager);
    existsFlag=directoryFlag=YES;readResult=bytes;response.videoID=@"at-callback";Reset();[h getThumbnail:player];pending();watching=NO;Check(writeResult,@"thumbnail saved with existing video parent");
    Equal([NSData dataWithContentsOfFile:[videoDirectory stringByAppendingPathComponent:@"thumbnail.webp"]],bytes.backing,@"saved thumbnail bytes preserved");
    player.playerResponse=nil;Reset();[h getThumbnail:player];watching=NO;Check(pending==nil,@"nil response does not enqueue");Equal(trace,(@[@"player.response"]),@"nil response exits immediately");
    method_setImplementation(class_getClassMethod(NSFileManager.class,@selector(defaultManager)),originalManager);
    method_setImplementation(class_getClassMethod(NSData.class,@selector(dataWithContentsOfURL:)),originalRead);
    [realManager removeItemAtPath:videoDirectory error:nil];pending=nil;
    printf("%s First_menu_thumbnail: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
