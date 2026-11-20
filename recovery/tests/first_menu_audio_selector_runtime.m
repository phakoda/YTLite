#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import "../source/Downloads/YTPMedia.h"
#undef objc_getClass
#undef NSClassFromString
static NSUInteger checks,failures,arrayIndex,lookupCalls,callbacks;
static BOOL watching,lookupNil,probeComparator,allowException;
static NSMutableArray *trace,*selected;
static void (^onLookup)(void);
static UIImage *icon;
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
@interface SelectorNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSArray *drcValues,*itagValues;
@property(nonatomic,strong) id nameObject;
@property(nonatomic,copy) void (^onName)(void);
@property(nonatomic) NSUInteger drcReads,itagReads;
@end
@implementation SelectorNode
- (void)event:(NSString *)key{Event([NSString stringWithFormat:@"%@.%@",self.tag,key]);}
- (int)itag{[self event:@"itag"];return self.itagValues?[self.itagValues[MIN(self.itagReads++,self.itagValues.count-1)] intValue]:[super itag];}
- (BOOL)isDrc{[self event:@"drc"];return self.drcValues?[self.drcValues[MIN(self.drcReads++,self.drcValues.count-1)] boolValue]:[super isDrc];}
- (id)audioTrack{[self event:@"track"];return [super audioTrack];}
- (NSString *)displayName{[self event:@"name"];if(self.onName)self.onName();return self.nameObject?:[super displayName];}
- (NSString *)mimeType{[self event:@"mime"];return [super mimeType];}
@end
static SelectorNode *Node(NSString *tag,int itag,BOOL drc,NSString *name){
    SelectorNode *n=[SelectorNode new];n.tag=tag;n.itag=itag;n.isDrc=drc;
    SelectorNode *t=[SelectorNode new];t.tag=[tag stringByAppendingString:@"Track"];t.displayName=name;n.audioTrack=t;return n;
}
Class FirstSelectorClassLookup(const char *name){
    if(strcmp(name,"YTActionSheetAction"))return objc_getClass(name);
    ++lookupCalls;Event(@"class:action");if(onLookup)onLookup();return lookupNil?Nil:YTActionSheetAction.class;
}
Class FirstSelectorStringLookup(NSString *name){
    if([name isEqual:@"YTActionSheetAction"]){++lookupCalls;Event(@"stringClass:action");if(onLookup)onLookup();return lookupNil?Nil:YTActionSheetAction.class;}
    if([name isEqual:@"YTDefaultSheetController"])Event(@"class:sheet");
    return NSClassFromString(name);
}
// A name probe allows the actual comparator's signed return to be inspected.
@interface CompareName : NSObject
@property(nonatomic) NSComparisonResult result;
@property(nonatomic,strong) id wanted;
@end
@implementation CompareName
- (NSComparisonResult)compare:(id)other{Event(@"compare");Check(other==self.wanted,@"comparator forwards right name identity");return self.result;}
@end
static void InspectComparator(NSComparator NS_NOESCAPE comparator){
    SelectorNode *a=Node(@"left",140,NO,nil),*b=Node(@"right",140,NO,nil);
    CompareName *left=[CompareName new],*right=[CompareName new];left.wanted=right;
    [(SelectorNode *)a.audioTrack setNameObject:left];[(SelectorNode *)b.audioTrack setNameObject:right];
    long long results[]={LLONG_MIN,-17,-1,0,1,23,LLONG_MAX};
    for(NSUInteger i=0;i<7;++i){left.result=results[i];NSUInteger start=trace.count;Check(comparator(a,b)==results[i],@"full signed comparison result retained");
        Equal([trace subarrayWithRange:NSMakeRange(start,trace.count-start)],(@[@"left.track",@"leftTrack.name",@"right.track",@"rightTrack.name",@"compare"]),@"comparator left then right getters");}
    // The left name object is held, not copied, across the right-name getter.
    NSMutableString *mutable=[NSMutableString stringWithString:@"A"];[(SelectorNode *)a.audioTrack setNameObject:mutable];[(SelectorNode *)b.audioTrack setNameObject:@"M"];
    [(SelectorNode *)b.audioTrack setOnName:^{[mutable setString:@"Z"];}];Check(comparator(a,b)>0,@"left name remains the same mutable object");
    [(SelectorNode *)b.audioTrack setOnName:nil];a.audioTrack=nil;Check(comparator(a,b)==0,@"nil left track sends compare to nil");
}
@interface SelectorArray : NSMutableArray
@property(nonatomic,strong) NSMutableArray *backing;
@property(nonatomic) NSUInteger index;
@end
@implementation SelectorArray
- (instancetype)init{if((self=[super init]))_backing=[[NSMutableArray alloc]init];return self;}
- (NSUInteger)count{return self.backing.count;}
- (id)objectAtIndex:(NSUInteger)i{return [self.backing objectAtIndex:i];}
- (void)insertObject:(id)o atIndex:(NSUInteger)i{[self.backing insertObject:o atIndex:i];}
- (void)removeObjectAtIndex:(NSUInteger)i{[self.backing removeObjectAtIndex:i];}
- (void)replaceObjectAtIndex:(NSUInteger)i withObject:(id)o{[self.backing replaceObjectAtIndex:i withObject:o];}
- (void)addObject:(id)o{Event([NSString stringWithFormat:@"array%lu.add",(unsigned long)self.index]);[self.backing addObject:o];}
- (void)sortUsingComparator:(NSComparator NS_NOESCAPE)comparator{Event(@"sort");if(probeComparator)InspectComparator(comparator);[self.backing sortUsingComparator:comparator];}
@end
static IMP originalArray,originalImage,originalAction,originalSheet,originalAdd,originalSource,originalPresent,originalBundle,originalWindow;
static id MakeArray(id cls,SEL sel){
    if(!watching||arrayIndex>=2)return ((id(*)(id,SEL))originalArray)(cls,sel);
    SelectorArray *a=[SelectorArray new];a.index=arrayIndex++;Event([NSString stringWithFormat:@"array%lu.create",(unsigned long)a.index]);return a;
}
static id Image(id cls,SEL sel,NSString *name){(void)cls;(void)sel;Event(@"image");Equal(name,@"localization",@"localization icon name");return icon;}
static id Action(id cls,SEL sel,NSString *title,id image,long long style,void(^handler)(void)){
    Event(@"action");Check(image==icon&&style==0&&handler!=nil,@"action icon, style and handler");return ((id(*)(id,SEL,id,id,long long,id))originalAction)(cls,sel,title,image,style,handler);
}
static id Sheet(id cls,SEL sel,NSString *message,id sub,id delegate,id parent){
    Event(@"sheet");Equal(message,@"SelectAudioTrack",@"selector localized message");Check(!sub&&!delegate&&!parent,@"nil sheet auxiliary arguments");return ((id(*)(id,SEL,id,id,id,id))originalSheet)(cls,sel,message,sub,delegate,parent);
}
static void Add(id self,SEL sel,id action){Event(@"sheet.add");((void(*)(id,SEL,id))originalAdd)(self,sel,action);}
static void Source(id self,SEL sel,id sender){Event(@"source");((void(*)(id,SEL,id))originalSource)(self,sel,sender);}
static void Present(id self,SEL sel,id root,BOOL animated,id completion){Event(@"present");Check(animated&&!completion,@"animated presentation with nil completion");((void(*)(id,SEL,id,BOOL,id))originalPresent)(self,sel,root,animated,completion);}
static id Bundle(id cls,SEL sel){Event(@"bundle");return ((id(*)(id,SEL))originalBundle)(cls,sel);}
static id Window(id cls,SEL sel){Event(@"window");return ((id(*)(id,SEL))originalWindow)(cls,sel);}
static void Begin(void){watching=NO;[trace removeAllObjects];[selected removeAllObjects];DownloadsLastSheet=nil;arrayIndex=callbacks=0;probeComparator=NO;watching=YES;}
static void Show(DownloadMenuHelper *h,NSArray *formats,id sender){
    @try { [h showAudioTrackSelector:formats sender:sender playerVC:[NSObject new] completion:^(id f){++callbacks;[selected addObject:f?:NSNull.null];}]; }
    @catch(NSException *e){if(allowException)@throw;Check(NO,[@"unexpected selector exception: " stringByAppendingString:e.name]);}
}
static NSArray *Chosen(YTDefaultSheetController *sheet){watching=NO;for(YTActionSheetAction *a in sheet.actions)a.handler();return [selected copy];}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[[NSMutableArray alloc]init];selected=[[NSMutableArray alloc]init];icon=[UIImage new];
    originalArray=method_setImplementation(class_getClassMethod(NSMutableArray.class,@selector(array)),(IMP)MakeArray);
    originalImage=method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),(IMP)Image);
    originalAction=method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),(IMP)Action);
    originalSheet=method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:)),(IMP)Sheet);
    originalAdd=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(addAction:)),(IMP)Add);
    originalSource=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),(IMP)Source);
    originalPresent=method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),(IMP)Present);
    originalBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    originalWindow=method_setImplementation(class_getClassMethod(ToastView.class,@selector(toastWindow)),(IMP)Window);
    DownloadMenuHelper *h=[DownloadMenuHelper new];id sender=[NSObject new];
    Begin();Show(h,nil,sender);watching=NO;Check(lookupCalls==0,@"empty menu does not resolve action class");Check(DownloadsLastSheet.actions.count==0&&callbacks==0,@"empty menu presented without callback");
    SelectorNode *f=Node(@"f",140,NO,@"Before");lookupNil=YES;allowException=YES;Begin();BOOL threw=NO;
    @try{Show(h,@[f],sender);}@catch(NSException *e){threw=[e.name isEqual:NSInvalidArgumentException];}watching=NO;
    Check(threw,@"nil action class retains original nil insertion exception");Check(lookupCalls==1,@"failed class lookup performed once");
    allowException=NO;lookupNil=NO;__weak SelectorNode *track=f.audioTrack;onLookup=^{track.displayName=@"AfterLookup";};Begin();Show(h,@[f],sender);watching=NO;
    Check(lookupCalls==2,@"nil lookup retried");Equal(DownloadsLastSheet.actions.firstObject.title,@"AfterLookup",@"resolve action class before reading label");
    Equal(trace,(@[@"array0.create",@"f.itag",@"f.drc",@"array0.add",@"sort",@"array1.create",@"class:action",@"f.track",@"fTrack.name",@"image",@"action",@"array1.add",@"class:sheet",@"bundle",@"sheet",@"sheet.add",@"source",@"window",@"present"]),@"selector construction and presentation sequence");
    Check(DownloadsLastSheet.source==sender&&DownloadsLastSheet.presenter==[ToastView toastWindow].rootViewController,@"source and toast-root identity");
    Check(callbacks==0,@"selection callback deferred until action");Equal(Chosen(DownloadsLastSheet),(@[f]),@"selected format identity");DownloadsLastSheet.actions.firstObject.handler();Check(callbacks==2,@"selection callback can be invoked repeatedly");
    onLookup=nil;lookupNil=YES; // A cached successful class must remain usable.
    for(NSUInteger mode=0;mode<5;++mode){
        SelectorNode *a=Node(@"a",140,mode!=0,@"Zulu"),*b=Node(@"b",140,mode!=0,@"Alpha"),*skip=Node(@"skip",139,NO,@"Skip");
        if(mode==2){a.drcValues=@[@YES,@NO];b.drcValues=@[@YES,@YES];}
        if(mode==3){a.itagValues=@[@139,@140];a.isDrc=YES;b.itag=999;}
        if(mode==4){a.itag=999;b.itag=139;}
        Begin();probeComparator=mode==0;Show(h,@[a,skip,b],sender);watching=NO;
        NSArray *wanted=mode==2?@[b]:mode==3?@[a]:mode==4?@[]:@[b,a];
        Equal(Chosen(DownloadsLastSheet),wanted,@"non-DRC primary list or fresh DRC fallback, sorted by name");Check(lookupCalls==2,@"action class remains cached across actions and invocations");
        Check(![trace containsObject:@"skip.drc"]&&![trace containsObject:@"a.mime"],@"itag short circuit and no MIME filtering");
        NSUInteger aReads=[[trace filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF == %@",@"a.itag"]] count];
        Check(aReads==(mode==0?1:2),@"fallback re-enumerates original input only if primary is empty");
    }
    // A non-DRC match suppresses every DRC format regardless of name or order.
    SelectorNode *normal=Node(@"normal",140,NO,@"Z"),*drc=Node(@"drc",140,YES,@"A");Begin();Show(h,@[drc,normal,drc],sender);watching=NO;Equal(Chosen(DownloadsLastSheet),(@[normal]),@"primary match suppresses DRC fallback entirely");
    // Duplicates remain separate actions and both invoke the original object.
    Begin();Show(h,@[normal,normal],sender);watching=NO;Equal(Chosen(DownloadsLastSheet),(@[normal,normal]),@"duplicate formats preserved");
    // A nil track still produces a nil-title action when sorting one item.
    normal.audioTrack=nil;Begin();Show(h,@[normal],nil);watching=NO;Check(DownloadsLastSheet.actions.firstObject.title==nil&&DownloadsLastSheet.source==nil,@"nil name and sender forwarded");Equal(Chosen(DownloadsLastSheet),(@[normal]),@"nil track format stays selectable");
    // Action blocks retain their format after the input list leaves scope.
    __weak SelectorNode *weakFormat;
    @autoreleasepool{SelectorNode *temporary=Node(@"temporary",140,NO,@"Temporary");weakFormat=temporary;Begin();Show(h,@[temporary],sender);watching=NO;}
    Check(weakFormat!=nil,@"deferred action retains selected format");Chosen(DownloadsLastSheet);Check(selected.firstObject==weakFormat,@"retained object forwarded after input lifetime");
    [selected removeAllObjects];DownloadsLastSheet=nil;Check(weakFormat==nil,@"format released with action and result");
    method_setImplementation(class_getClassMethod(NSMutableArray.class,@selector(array)),originalArray);
    method_setImplementation(class_getClassMethod(YTPMedia.class,@selector(imageWithName:)),originalImage);
    method_setImplementation(class_getClassMethod(YTActionSheetAction.class,@selector(actionWithTitle:iconImage:style:handler:)),originalAction);
    method_setImplementation(class_getClassMethod(YTDefaultSheetController.class,@selector(sheetControllerWithMessage:subMessage:delegate:parentResponder:)),originalSheet);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(addAction:)),originalAdd);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(setSourceView:)),originalSource);
    method_setImplementation(class_getInstanceMethod(YTDefaultSheetController.class,@selector(presentFromViewController:animated:completion:)),originalPresent);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),originalBundle);
    method_setImplementation(class_getClassMethod(ToastView.class,@selector(toastWindow)),originalWindow);
    printf("%s First_menu_audio_selector: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
