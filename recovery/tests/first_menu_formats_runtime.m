#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,failures,arrayIndex;
static NSMutableArray *trace;
static BOOL watch,recordFactories;
static void (^firstArray)(void);
static BOOL probeComparator,sawComparator;
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
static void Event(NSString *s){if(watch)[trace addObject:s];}
@interface FormatNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic) BOOL noModern,noLegacy;
@property(nonatomic,strong) NSArray *mimeSequence,*itagSequence,*trackSequence;
@property(nonatomic) NSUInteger mimeReads,itagReads,trackReads;
@end
@implementation FormatNode
- (void)event:(NSString *)selector{Event([NSString stringWithFormat:@"%@.%@",self.tag,selector]);}
- (BOOL)respondsToSelector:(SEL)selector{
    if(selector==@selector(playerResponse)){[self event:@"supportsModern"];return !self.noModern;}
    if(selector==@selector(contentPlayerResponse)){[self event:@"supportsLegacy"];return !self.noLegacy;}
    return [super respondsToSelector:selector];
}
- (id)playerResponse{[self event:@"response"];return [super playerResponse];}
- (id)contentPlayerResponse{[self event:@"legacy"];return [super contentPlayerResponse];}
- (id)playerData{[self event:@"data"];return [super playerData];}
- (id)streamingData{[self event:@"stream"];return [super streamingData];}
- (NSArray *)adaptiveFormatsArray{[self event:@"formats"];return [super adaptiveFormatsArray];}
- (NSString *)qualityLabel{[self event:@"quality"];recordFactories=NO;return [super qualityLabel];}
- (NSString *)mimeType{[self event:@"mime"];recordFactories=NO;return self.mimeSequence?self.mimeSequence[MIN(self.mimeReads++,self.mimeSequence.count-1)]:[super mimeType];}
- (unsigned long long)contentLength{[self event:@"size"];return [super contentLength];}
- (int)itag{[self event:@"itag"];return self.itagSequence?[self.itagSequence[MIN(self.itagReads++,self.itagSequence.count-1)] intValue]:[super itag];}
- (id)audioTrack{[self event:@"track"];id value=self.trackSequence?self.trackSequence[MIN(self.trackReads++,self.trackSequence.count-1)]:[super audioTrack];return value==NSNull.null?nil:value;}
- (BOOL)audioIsDefault{[self event:@"default"];return [super audioIsDefault];}
- (BOOL)isDrc{[self event:@"drc"];return [super isDrc];}
- (NSString *)id_p{[self event:@"id"];return [super id_p];}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (id)selectedAudioFormat{[self event:@"selected"];return [super selectedAudioFormat];}
- (id)formatStream{[self event:@"format"];return [super formatStream];}
@end
static FormatNode *Node(NSString *tag){FormatNode *n=[FormatNode new];n.tag=tag;return n;}
static FormatNode *Format(NSString *tag,NSString *mime,long long quality,unsigned long long size){FormatNode *n=Node(tag);n.mimeType=mime;n.qualityLabel=[NSString stringWithFormat:@"%lldp",quality];n.contentLength=size;return n;}
static FormatNode *Player(NSArray *formats){FormatNode *p=Node(@"player"),*r=Node(@"response"),*d=Node(@"data"),*s=Node(@"stream");p.playerResponse=r;p.contentPlayerResponse=r;r.playerData=d;d.streamingData=s;s.adaptiveFormatsArray=formats;return p;}
// The factory boundary records work-array operations without replacing filtering.
@interface FormatArray : NSMutableArray
@property(nonatomic,strong) NSMutableArray *backing;
@property(nonatomic) NSUInteger index;
@end
@implementation FormatArray
- (instancetype)init{if((self=[super init]))_backing=[[NSMutableArray alloc]init];return self;}
- (NSUInteger)count{Event([NSString stringWithFormat:@"array%lu.count",(unsigned long)self.index]);return self.backing.count;}
- (id)objectAtIndex:(NSUInteger)i{return [self.backing objectAtIndex:i];}
- (void)insertObject:(id)object atIndex:(NSUInteger)i{[self.backing insertObject:object atIndex:i];}
- (void)removeObjectAtIndex:(NSUInteger)i{[self.backing removeObjectAtIndex:i];}
- (void)replaceObjectAtIndex:(NSUInteger)i withObject:(id)object{[self.backing replaceObjectAtIndex:i withObject:object];}
- (void)addObject:(id)object{Event([NSString stringWithFormat:@"array%lu.add",(unsigned long)self.index]);[self.backing addObject:object];}
- (void)addObjectsFromArray:(NSArray *)objects{Event([NSString stringWithFormat:@"array%lu.extend",(unsigned long)self.index]);if([objects isKindOfClass:FormatArray.class])objects=[(FormatArray *)objects backing];[self.backing addObjectsFromArray:objects];}
- (void)sortUsingComparator:(NSComparator NS_NOESCAPE)comparator{
    Event([NSString stringWithFormat:@"array%lu.sort",(unsigned long)self.index]);sawComparator=YES;
    if(probeComparator){
        unsigned long long lengths[]={0,1,0x100000001ULL,0x7fffffffffffffffULL,0x8000000000000000ULL,0xffffffffffffffffULL};
        for(NSUInteger a=0;a<6;++a)for(NSUInteger b=0;b<6;++b){
            FormatNode *left=Format(@"left",nil,0,lengths[a]),*right=Format(@"right",nil,0,lengths[b]);
            NSUInteger start=trace.count;NSComparisonResult order=comparator(left,right);
            Check(order==((long long)lengths[a]>(long long)lengths[b]?-1:1),@"signed full-width sort including nonzero tie");
            Equal([trace subarrayWithRange:NSMakeRange(start,trace.count-start)],(@[@"left.size",@"right.size"]),@"comparator getter order");
        }
    }
    [self.backing sortUsingComparator:comparator];
}
- (id)copyWithZone:(NSZone *)zone{Event([NSString stringWithFormat:@"array%lu.copy",(unsigned long)self.index]);return [self.backing copyWithZone:zone];}
@end
static IMP originalArray,originalPreference;
static id MakeArray(id cls,SEL selector){
    if(!watch||!recordFactories)return ((id(*)(id,SEL))originalArray)(cls,selector);
    FormatArray *a=[FormatArray new];a.index=arrayIndex++;Event([NSString stringWithFormat:@"array%lu.create",(unsigned long)a.index]);
    if(a.index==0&&firstArray)firstArray();return a;
}
static BOOL Preference(id cls,SEL selector,id key){Event([@"preference:" stringByAppendingString:key]);return ((BOOL(*)(id,SEL,id))originalPreference)(cls,selector,key);}
static void Begin(void){watch=NO;[trace removeAllObjects];arrayIndex=0;sawComparator=NO;probeComparator=NO;firstArray=nil;recordFactories=YES;watch=YES;}
static NSArray *Get(DownloadMenuHelper *h,id player,BOOL audio,BOOL shorts){return audio?[h getAudioFormatsArray:player]:[h getVideoFormatsArray:player isShorts:shorts];}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[[NSMutableArray alloc]init];DownloadMenuHelper *h=[DownloadMenuHelper new];
    originalArray=method_setImplementation(class_getClassMethod(NSMutableArray.class,@selector(array)),(IMP)MakeArray);
    originalPreference=method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),(IMP)Preference);
    for(NSUInteger audio=0;audio<2;++audio){
        FormatNode *f=Format(@"f",audio?@"audio/mp4":@"video/mp4",720,5),*p=Player(@[f]);
        FormatNode *stream=[[(FormatNode *)p.playerResponse playerData] streamingData];
        Begin();probeComparator=YES;firstArray=^{stream.adaptiveFormatsArray=@[];};NSArray *result=Get(h,p,audio,NO);watch=NO;
        Equal(result,(@[f]),@"format reference read before working-array factory effects");
        NSArray *prefix=@[@"player.supportsModern",@"player.response",@"response.data",@"data.stream",@"stream.formats",@"array0.create"];
        Check(trace.count>=prefix.count,@"filter setup trace present");if(trace.count>=prefix.count)Equal([trace subarrayWithRange:NSMakeRange(0,prefix.count)],prefix,@"response and format getters precede work arrays");
        Check(arrayIndex==(audio?1:3),@"working-array factories before format iteration");Check(![result isKindOfClass:NSMutableArray.class],@"immutable output");
        Check(sawComparator,@"sort receives comparator");
        for(NSUInteger mode=0;mode<5;++mode){
            p=Player(@[]);p.noModern=mode==1||mode==2;p.noLegacy=mode==2;
            if(mode==3)p.playerResponse=nil;if(mode==4)[(FormatNode *)p.playerResponse setPlayerData:nil];
            Begin();result=Get(h,p,audio,NO);watch=NO;
            Check((result==nil)==(mode==2||mode==3),@"response compatibility and nil handling");
            Check(arrayIndex==((mode==2||mode==3)?0:(audio?1:3)),@"nil response returns before array creation");
            if(mode==1)Equal([trace subarrayWithRange:NSMakeRange(0,3)],(@[@"player.supportsModern",@"player.supportsLegacy",@"player.legacy"]),@"legacy selector chosen only when modern unsupported");
            if(mode==3)Equal(trace,(@[@"player.supportsModern",@"player.response"]),@"nil modern response does not try legacy");
        }
    }
    // Boundary matrix, including all ranges and MP4 suppression of WebM fallback.
    long long resolutions[]={LLONG_MIN,-1,0,143,144,720,1080,1081,2160,LLONG_MAX};
    for(NSString *mime in @[@"video/mp4",@"video/mp4extra",@"video/webm",@"Video/mp4",@"audio/mp4"])
    for(NSUInteger q=0;q<10;++q)for(NSUInteger shorts=0;shorts<2;++shorts)for(NSUInteger mp4=0;mp4<2;++mp4){
        FormatNode *f=Format(@"f",mime,resolutions[q],20),*base=Format(@"base",@"video/mp4",144,10);
        FormatNode *p=Player(mp4?@[f,base]:@[f]);Begin();NSArray *result=[h getVideoFormatsArray:p isShorts:shorts];watch=NO;
        BOOL eligible=([mime hasPrefix:@"video/mp4"]&&q>=4&&q<=6)||([mime isEqual:@"video/webm"]&&!shorts&&q>=4&&(!mp4||q>=7));
        Check([result containsObject:f]==eligible,@"video eligibility matrix");Check(result.count==(mp4?1:0)+(eligible?1:0),@"video exact membership count");
        if(mp4&&eligible)Equal(result,(@[f,base]),@"video descending size");
    }
    // Both MIME getters run, but an accepted MP4 skips the WebM insertion arms.
    FormatNode *f=Format(@"f",nil,720,1);f.mimeSequence=@[@"video/mp4",@"video/webm"];FormatNode *p=Player(@[f]);
    Begin();Equal([h getVideoFormatsArray:p isShorts:NO],(@[f]),@"changing MIME getters preserve selected item");watch=NO;
    Check(f.mimeReads==2,@"video performs two MIME reads");Check(![trace containsObject:@"array2.add"],@"accepted MP4 skips fallback-array insertion");
    for(NSString *mime in @[@"audio/mp4",@"audio/mp4extra",@"audio/webm",@"Audio/mp4",@""]){
        f=Format(@"f",mime,0,1);p=Player(@[f]);Begin();NSArray *r=[h getAudioFormatsArray:p];watch=NO;
        Check(r.count==([mime hasPrefix:@"audio/mp4"]?1:0),@"audio MIME prefix filter");
    }
    // Best audio preserves first acceptable format and independent getter reads.
    for(NSNumber *itag in @[@139,@140,@999])for(NSUInteger track=0;track<4;++track)for(NSUInteger drc=0;drc<2;++drc)for(NSUInteger prefer=0;prefer<2;++prefer){
        f=Format(@"f",@"audio/mp4",0,1);f.itag=itag.intValue;f.isDrc=drc;
        FormatNode *t=Node(@"track");t.audioIsDefault=track==2;f.audioTrack=track?t:nil;
        if(track==3)f.trackSequence=@[t,NSNull.null];
        FormatNode *fallback=Node(@"fallback"),*active=Node(@"active"),*selected=Node(@"selected");p=Node(@"player");p.activeVideo=active;active.selectedAudioFormat=selected;selected.formatStream=fallback;
        DownloadsPreferences[@"preferDrc"]=@(prefer);Begin();id r=[h getBestAudioFormat:@[f] playerVC:p];watch=NO;
        BOOL accepted=itag.intValue!=999;Check(r==(accepted?f:fallback),@"best audio ignores DRC preference result");
        NSMutableArray *wanted=[[NSMutableArray alloc]initWithArray:@[@"f.mime",@"f.itag"]];
        if(itag.intValue!=140)[wanted addObject:@"f.itag"];
        if(accepted){[wanted addObject:@"f.track"];if(track){[wanted addObject:@"f.track"];if(track!=3)[wanted addObject:@"track.default"];}if(track!=2){[wanted addObject:@"f.drc"];if(drc)[wanted addObject:@"preference:preferDrc"];}}
        else [wanted addObjectsFromArray:@[@"player.active",@"active.selected",@"selected.format"]];
        Equal(trace,wanted,@"best audio getter and preference sequence");
    }
    f=Format(@"f",@"audio/mp4",0,1);f.itagSequence=@[@999,@139];Begin();Check([h getBestAudioFormat:@[f] playerVC:nil]==f,@"second itag read can select changed value");watch=NO;
    FormatNode *rejected=Format(@"skip",@"audio/webm",0,1);Begin();Check([h getBestAudioFormat:@[rejected,f] playerVC:nil]==f,@"skip non-MP4 before acceptable audio");watch=NO;Check(![trace containsObject:@"skip.itag"],@"non-MP4 never reads itag");
    for(NSUInteger mode=0;mode<2;++mode){
        for(NSString *identifier in @[@"en.4",@"en.4-dubbed",@"en.40",@"en.3",@"EN.4",@""]){
            FormatNode *t=Node(@"track");t.id_p=identifier;t.audioIsDefault=[identifier isEqual:@"en.4"];
            f=Format(@"f",@"irrelevant",0,1);f.itag=999;f.audioTrack=t;
            Begin();id r=mode?[h getEnglishAudioTrack:@[f]]:[h getDefaultAudioTrack:@[f]];watch=NO;
            BOOL wanted=mode?[identifier hasPrefix:@"en.4"]:t.audioIsDefault;Check(r==(wanted?f:nil),@"track selection ignores MIME and itag value");
            NSMutableArray *events=[[NSMutableArray alloc]initWithArray:@[@"f.track",mode?@"track.id":@"track.default"]];if(wanted)[events addObject:@"f.itag"];
            Equal(trace,events,@"track selector ordering with ignored itag call");
        }
        Begin();Check((mode?[h getEnglishAudioTrack:nil]:[h getDefaultAudioTrack:nil])==nil,@"nil track list");watch=NO;
    }
    method_setImplementation(class_getClassMethod(NSMutableArray.class,@selector(array)),originalArray);
    method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),originalPreference);
    printf("%s First_menu_formats: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
