#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,sheetLookups,actionLookups,reads,downloads,viewerNews;
static BOOL watching,sheetClassNil,actionClassNil,sheetResultNil,viewerInitNil,navInitNil;
static NSMutableArray *trace;
static NSURL *capturedURL,*readURL,*downloadURL;
static BOOL downloadFlag;
static NSData *bytes;
static UIImage *decodedImage,*imageArgument;
static id builtViewer,builtNavigation;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
Class FirstImagesClassLookup(const char *name){
    if(!strcmp(name,"YTDefaultSheetController")){++sheetLookups;Event(@"class.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if(!strcmp(name,"YTActionSheetAction")){++actionLookups;Event(@"class.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    return objc_getClass(name);
}
Class FirstImagesStringLookup(NSString *name){
    if([name isEqual:@"YTDefaultSheetController"]){++sheetLookups;Event(@"string.sheet");return sheetClassNil?Nil:YTDefaultSheetController.class;}
    if([name isEqual:@"YTActionSheetAction"]){++actionLookups;Event(@"string.action");return actionClassNil?Nil:YTActionSheetAction.class;}
    return NSClassFromString(name);
}
@interface ImageNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) BOOL noModern,noLegacy;
@end
@implementation ImageNode
- (void)event:(NSString *)s{Event([NSString stringWithFormat:@"%@.%@",self.tag,s]);}
- (BOOL)respondsToSelector:(SEL)s{if(s==@selector(playerResponse)){[self event:@"supportsModern"];return !self.noModern;}if(s==@selector(contentPlayerResponse)){[self event:@"supportsLegacy"];return !self.noLegacy;}return [super respondsToSelector:s];}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"legacy"];return [super contentPlayerResponse];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)videoDetails{[self event:@"details"];return [super videoDetails];}
- (id)thumbnail{[self event:@"thumbnail"];return [super thumbnail];}
- (NSArray *)thumbnailsArray{[self event:@"thumbnails"];return [super thumbnailsArray];}
- (id)URL{[self event:@"URL"];return [super URL];}
@end
static ImageNode *Node(NSString *name){ImageNode *n=[ImageNode new];n.tag=name;return n;}
@interface ImagesBundle : NSBundle @end
@implementation ImagesBundle
- (NSString *)localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table{Event([@"localize." stringByAppendingString:key]);Check(value==nil&&table==nil,@"localization ancillary arguments");return key;}
@end
@interface ImagePresenter : UIViewController
@property(nonatomic,copy) NSString *tag;
@end
@implementation ImagePresenter
- (void)presentViewController:(UIViewController *)vc animated:(BOOL)animated completion:(void (^)(void))completion{Event([self.tag stringByAppendingString:@".present"]);Check(animated&&completion==nil,@"viewer presentation flags");self.presented=vc;}
@end
@interface ImageWindow : UIWindow @end
@implementation ImageWindow
- (UIViewController *)rootViewController{Event(@"app.root");return [super rootViewController];}
@end
@interface ImageDelegate : DownloadsAppDelegate @end
@implementation ImageDelegate
- (UIWindow *)window{Event(@"app.window");return [super window];}
@end
@interface ImageApp : UIApplication @end
@implementation ImageApp
- (id)delegate{Event(@"app.delegate");return [super delegate];}
@end
// Test declarations match the isolated downloads doubles, not production ivars.
@interface DVNImageViewController : UIViewController
@property(nonatomic,strong) UIImage *fullImage;
@end
@implementation DVNImageViewController (ImagesConstruction)
+ (instancetype)new{++viewerNews;Event(@"viewer.new");return [super new];}
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"viewer.alloc");return [super allocWithZone:zone];}
- (instancetype)init{Event(@"viewer.init");if(viewerInitNil)return nil;self=[super init];builtViewer=self;return self;}
@end
@implementation UINavigationController (ImagesConstruction)
+ (instancetype)allocWithZone:(NSZone *)zone{Event(@"nav.alloc");return [super allocWithZone:zone];}
@end
static ImagesBundle *bundle;
static ImageApp *app;
static IMP oldURL,oldRead,oldDecode,oldFullImage,oldNav,oldStyle,oldApp,oldPipeline,oldBundle,oldIcon,oldSheet,oldAction,oldAdd,oldSource,oldPresent;
static id URL(id cls,SEL sel,NSString *value){Event(@"URL.create");id result=((id(*)(id,SEL,id))oldURL)(cls,sel,value);capturedURL=result;return result;}
static id Read(id cls,SEL sel,NSURL *url){(void)cls;(void)sel;Event(@"data.read");++reads;readURL=url;return bytes;}
static id Decode(id cls,SEL sel,NSData *data){(void)cls;(void)sel;Event(@"image.decode");Check(data==bytes,@"raw NSData result forwarded");return decodedImage;}
static void FullImage(id self,SEL sel,UIImage *image){Event(@"viewer.image");imageArgument=image;((void(*)(id,SEL,id))oldFullImage)(self,sel,image);}
static id Navigation(id self,SEL sel,id root){Event(@"nav.init");Check(root==builtViewer,@"viewer passed to navigation initializer");if(navInitNil)return nil;id n=((id(*)(id,SEL,id))oldNav)(self,sel,root);builtNavigation=n;return n;}
static void NavigationStyle(id self,SEL sel,UIModalPresentationStyle style){Event(@"nav.style");Check(style==2,@"original form sheet style numeric value");((void(*)(id,SEL,UIModalPresentationStyle))oldStyle)(self,sel,style);}
static id App(id cls,SEL sel){(void)cls;(void)sel;Event(@"app.shared");return app;}
static void Pipeline(id cls,SEL sel,NSURL *url,BOOL download){(void)cls;(void)sel;Event(@"pipeline");++downloads;downloadURL=url;downloadFlag=download;}
static id Bundle(id cls,SEL sel){(void)cls;(void)sel;Event(@"bundle");return bundle;}
static id Icon(id cls,SEL sel,NSString *name){(void)cls;(void)sel;Event([@"icon." stringByAppendingString:name]);UIImage *image=[UIImage new];image.name=name;return image;}
static id Sheet(id cls,SEL sel,id parent){Event(@"sheet");Check(parent==nil,@"nil parent responder");return sheetResultNil?nil:((id(*)(id,SEL,id))oldSheet)(cls,sel,parent);}
static id Action(id cls,SEL sel,id title,id icon,long long style,id handler){Event(@"action");Check(style==0&&handler!=nil,@"action style and callback");return ((id(*)(id,SEL,id,id,long long,id))oldAction)(cls,sel,title,icon,style,handler);}
static void Add(id self,SEL sel,id action){Event(@"sheet.add");((void(*)(id,SEL,id))oldAdd)(self,sel,action);}
static void Source(id self,SEL sel,id sender){Event(@"sheet.source");((void(*)(id,SEL,id))oldSource)(self,sel,sender);}
static void Present(id self,SEL sel,id root,BOOL animated,id completion){Event(@"sheet.present");Check(root==[ToastView toastWindow].rootViewController&&animated&&completion==nil,@"sheet uses toast root and original flags");((void(*)(id,SEL,id,BOOL,id))oldPresent)(self,sel,root,animated,completion);}
static void Begin(void){watching=NO;[trace removeAllObjects];DownloadsLastSheet=nil;reads=downloads=viewerNews=0;capturedURL=readURL=downloadURL=nil;builtViewer=builtNavigation=nil;imageArgument=nil;watching=YES;}
static BOOL Show(DownloadMenuHelper *h,id player,id source){BOOL threw=NO;@try{[h showImagesSheet:player withSender:source];}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];if(!threw)Check(NO,@"unexpected exception");}return threw;}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray new];bundle=[ImagesBundle new];app=[ImageApp new];ImageDelegate *delegate=[ImageDelegate new];ImageWindow *window=[ImageWindow new];ImagePresenter *presenter=[ImagePresenter new];presenter.tag=@"viewerRoot";window.rootViewController=presenter;delegate.window=window;app.delegate=delegate;
    ImagePresenter *toastPresenter=[ImagePresenter new];toastPresenter.tag=@"toastRoot";[ToastView toastWindow].rootViewController=toastPresenter;
    oldURL=method_setImplementation(class_getClassMethod(NSURL.class,@selector(URLWithString:)),(IMP)URL);
    oldRead=method_setImplementation(class_getClassMethod(NSData.class,@selector(dataWithContentsOfURL:)),(IMP)Read);
    oldDecode=method_setImplementation(class_getClassMethod(UIImage.class,@selector(imageWithData:)),(IMP)Decode);
    oldFullImage=method_setImplementation(class_getInstanceMethod(DVNImageViewController.class,@selector(setFullImage:)),(IMP)FullImage);
    oldNav=method_setImplementation(class_getInstanceMethod(UINavigationController.class,@selector(initWithRootViewController:)),(IMP)Navigation);
    oldStyle=method_setImplementation(class_getInstanceMethod(UIViewController.class,@selector(setModalPresentationStyle:)),(IMP)NavigationStyle);
    oldApp=method_setImplementation(class_getClassMethod(UIApplication.class,@selector(sharedApplication)),(IMP)App);
    oldPipeline=method_setImplementation(class_getClassMethod(NSClassFromString(@"YTLHelper"),@selector(downloadImageFromURL:download:)),(IMP)Pipeline);
    oldBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    oldIcon=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Icon);
    oldSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),(IMP)Sheet);
    oldAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),(IMP)Action);
    oldAdd=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(addAction:)),(IMP)Add);
    oldSource=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),(IMP)Source);
    oldPresent=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),(IMP)Present);
    ImageNode *player=Node(@"player"),*response=Node(@"response"),*data=Node(@"data"),*details=Node(@"details"),*thumbnail=Node(@"thumbnail"),*first=Node(@"first"),*last=Node(@"last");
    player.playerResponse=response;player.contentPlayerResponse=response;response.playerData=data;data.videoDetails=details;details.thumbnail=thumbnail;thumbnail.thumbnailsArray=@[first,last];first.URL=@"https://fixture.invalid/first";last.URL=@"https://fixture.invalid/last";
    DownloadMenuHelper *helper=[DownloadMenuHelper new];UIView *source=[UIView new];
    player.noModern=player.noLegacy=YES;Begin();Check(!Show(helper,player,source),@"unsupported player silent return");watching=NO;Equal(trace,(@[@"player.supportsModern",@"player.supportsLegacy"]),@"unsupported selector order");Check(!sheetLookups&&!actionLookups,@"unsupported player skips caches");player.noModern=player.noLegacy=NO;
    player.playerResponse=nil;Begin();Check(!Show(helper,player,source),@"nil modern response silent return");watching=NO;Equal(trace,(@[@"player.supportsModern",@"player.response"]),@"nil modern response does not fall back");player.playerResponse=response;
    sheetClassNil=actionClassNil=YES;
    for(NSUInteger attempt=0;attempt<2;++attempt){NSUInteger sl=sheetLookups,al=actionLookups;Begin();Check(!Show(helper,player,source),@"nil sheet and actions still evaluate arguments");watching=NO;Check(sheetLookups==sl+1&&actionLookups==al+3,@"nil class lookups retried for each use");Check(DownloadsLastSheet==nil&&reads==0&&downloads==0,@"nil sheet never performs image work");}
    sheetClassNil=NO;NSUInteger sl=sheetLookups,al=actionLookups;Begin();Check(Show(helper,player,source),@"nil action passed to nonnil sheet preserves collection exception");watching=NO;Check(sheetLookups==sl+1&&actionLookups==al+1,@"sheet succeeds once while failed action retries");
    actionClassNil=NO;al=actionLookups;Begin();Check(!Show(helper,player,source),@"valid thumbnail sheet");watching=NO;Check(actionLookups==al+1,@"first resolved action class cached for all three actions");Check(![trace containsObject:@"string.action"]&&![trace containsObject:@"string.sheet"],@"class caches use objc_getClass");
    Check([trace indexOfObject:@"class.action"]<[trace indexOfObject:@"bundle"],@"action class lookup precedes localization");
    NSArray *prefix=@[@"player.supportsModern",@"player.response",@"response.data",@"data.details",@"details.thumbnail",@"thumbnail.thumbnails",@"last.URL",@"URL.create",@"sheet",@"class.action"];
    Check(trace.count>=prefix.count,@"full prefix available");if(trace.count>=prefix.count)Equal([trace subarrayWithRange:NSMakeRange(0,prefix.count)],prefix,@"thumbnail retrieval and construction order");
    Equal([DownloadsLastSheet.actions valueForKey:@"title"],(@[@"DownloadThumbnail",@"ShowThumbnail",@"CopyThumbnail"]),@"action order and localized keys");Equal([DownloadsLastSheet.actions valueForKeyPath:@"icon.name"],(@[@"image",@"show_image",@"image_library"]),@"thumbnail icons");Check(DownloadsLastSheet.source==source,@"source identity");Check(reads==0&&downloads==0,@"thumbnail work waits for action selection");
    NSArray *actions=[DownloadsLastSheet.actions copy];NSURL *chosen=capturedURL;last.URL=@"https://fixture.invalid/changed";thumbnail.thumbnailsArray=@[first];
    for(NSUInteger index=0;index<3;index+=2){Begin();((YTActionSheetAction *)actions[index]).handler();watching=NO;Check(downloads==1&&downloadURL==chosen&&downloadFlag==(index==0),@"download and copy forward captured URL identity with separate flags");Equal(trace,(@[@"pipeline"]),@"download and copy use helper without direct IO");}
    for(NSUInteger hasData=0;hasData<2;++hasData)for(NSUInteger hasImage=0;hasImage<2;++hasImage){bytes=hasData?[@"synthetic image bytes" dataUsingEncoding:NSUTF8StringEncoding]:nil;decodedImage=hasImage?[UIImage new]:nil;Begin();((YTActionSheetAction *)actions[1]).handler();watching=NO;
        Equal(trace,(@[@"viewer.alloc",@"viewer.init",@"data.read",@"image.decode",@"viewer.image",@"nav.alloc",@"nav.init",@"nav.style",@"app.shared",@"app.delegate",@"app.window",@"app.root",@"viewerRoot.present"]),@"viewer construction, synchronous decode and presenter getter order");
        Check(reads==1&&readURL==chosen&&viewerNews==0,@"viewer alloc/init and captured URL");Check(imageArgument==decodedImage&&[builtViewer fullImage]==decodedImage,@"decoder result forwarded including nil");Check(presenter.presented==builtNavigation&&[(UINavigationController *)builtNavigation root]==builtViewer,@"navigation wraps viewer and uses app root");
    }
    viewerInitNil=YES;Begin();((YTActionSheetAction *)actions[1]).handler();watching=NO;Check(builtViewer==nil&&reads==1&&builtNavigation!=nil,@"nil viewer initializer still reads and constructs navigation");Check(![trace containsObject:@"viewer.image"],@"nil viewer ignores image setter");viewerInitNil=NO;
    navInitNil=YES;Begin();((YTActionSheetAction *)actions[1]).handler();watching=NO;Check(reads==1&&builtNavigation==nil&&presenter.presented==nil,@"nil navigation result forwarded to presenter");Check(![trace containsObject:@"nav.style"],@"nil navigation skips actual setter dispatch");navInitNil=NO;
    sl=sheetLookups;al=actionLookups;Begin();Check(!Show(helper,player,source),@"repeat sheet");watching=NO;Check(sl==sheetLookups&&al==actionLookups,@"successful class caches survive method calls");
    player.noModern=YES;Begin();Check(!Show(helper,player,nil),@"legacy response supported");watching=NO;Check([trace containsObject:@"player.legacy"]&&DownloadsLastSheet.source==nil,@"legacy path and nil sender");player.noModern=NO;
    // Empty thumbnails preserve nil URL through all action closures. Read is synthetic.
    thumbnail.thumbnailsArray=@[];Begin();Check(!Show(helper,player,source),@"empty thumbnail array still builds actions");watching=NO;Check(capturedURL==nil&&DownloadsLastSheet.actions.count==3,@"nil URL accepted during sheet creation");NSArray *emptyActions=[DownloadsLastSheet.actions copy];
    for(NSUInteger index=0;index<3;++index){Begin();((YTActionSheetAction *)emptyActions[index]).handler();watching=NO;Check(index==1?(reads==1&&readURL==nil):(downloads==1&&downloadURL==nil),@"nil URL forwarded to selected action");}
    sheetResultNil=YES;Begin();Check(!Show(helper,player,source),@"nil sheet factory result still evaluates three actions");watching=NO;Check(DownloadsLastSheet==nil&&[[trace filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF == %@",@"action"]] count]==3,@"nil sheet preserves action creation");sheetResultNil=NO;
    // All three closures own the converted URL until the last action is released.
    __weak NSURL *weakURL;NSMutableArray *ownedActions;
    @autoreleasepool {
        last.URL=@"https://fixture.invalid/lifetime";thumbnail.thumbnailsArray=@[last];
        Begin();Check(!Show(helper,player,source),@"lifetime sheet created");watching=NO;
        weakURL=capturedURL;capturedURL=nil;ownedActions=[DownloadsLastSheet.actions mutableCopy];DownloadsLastSheet=nil;
    }
    Check(weakURL!=nil,@"actions retain converted URL");
    [ownedActions removeObjectAtIndex:0];[ownedActions removeObjectAtIndex:0];
    Check(weakURL!=nil,@"remaining action retains URL independently");
    [ownedActions removeAllObjects];Check(weakURL==nil,@"last action release relinquishes URL");
    // Restore replaced methods before leaving the synthetic process.
    method_setImplementation(class_getClassMethod(NSURL.class,@selector(URLWithString:)),oldURL);
    method_setImplementation(class_getClassMethod(NSData.class,@selector(dataWithContentsOfURL:)),oldRead);
    method_setImplementation(class_getClassMethod(UIImage.class,@selector(imageWithData:)),oldDecode);
    method_setImplementation(class_getInstanceMethod(DVNImageViewController.class,@selector(setFullImage:)),oldFullImage);
    method_setImplementation(class_getInstanceMethod(UINavigationController.class,@selector(initWithRootViewController:)),oldNav);
    method_setImplementation(class_getInstanceMethod(UIViewController.class,@selector(setModalPresentationStyle:)),oldStyle);
    method_setImplementation(class_getClassMethod(UIApplication.class,@selector(sharedApplication)),oldApp);
    method_setImplementation(class_getClassMethod(NSClassFromString(@"YTLHelper"),@selector(downloadImageFromURL:download:)),oldPipeline);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),oldBundle);
    method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),oldIcon);
    method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithParentResponder:)),oldSheet);
    method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),oldAction);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(addAction:)),oldAdd);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),oldSource);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),oldPresent);
    printf("%s First_menu_images: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
