#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
#import <objc/runtime.h>
static NSUInteger checks,failures;
static NSMutableArray *trace;
static BOOL watching;
static void (^onPreference)(void),(^onBundle)(void);
static void Event(NSString *s){if(watching)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
@interface CaptionNode : DownloadsNode
@property(nonatomic,copy) NSString *tag;
@property(nonatomic,strong) NSArray *identifierValues;
@property(nonatomic,strong) NSString *nameObject;
@property(nonatomic) NSUInteger identifierReads;
@property(nonatomic,copy) void (^onIdentifier)(void);
@end
@implementation CaptionNode
- (void)event:(NSString *)key{Event([NSString stringWithFormat:@"%@.%@",self.tag,key]);}
- (id)activeVideo{[self event:@"active"];return [super activeVideo];}
- (NSArray *)availableCaptionTracks{[self event:@"tracks"];return [super availableCaptionTracks];}
- (NSString *)VSSID{[self event:@"id"];if(self.onIdentifier)self.onIdentifier();if(!self.identifierValues)return [super VSSID];id value=self.identifierValues[MIN(self.identifierReads++,self.identifierValues.count-1)];return value==NSNull.null?nil:value;}
- (NSString *)displayName{[self event:@"name"];return self.nameObject?:[super displayName];}
@end
static CaptionNode *Node(NSString *tag,id identifier){CaptionNode *n=[CaptionNode new];n.tag=tag;n.VSSID=identifier==NSNull.null?nil:identifier;n.displayName=@"English";return n;}
static IMP originalPreference,originalBundle;
static BOOL Preference(id cls,SEL sel,NSString *key){Event([@"preference:" stringByAppendingString:key]);if(onPreference)onPreference();return ((BOOL(*)(id,SEL,id))originalPreference)(cls,sel,key);}
static id Bundle(id cls,SEL sel){Event(@"bundle");if(onBundle)onBundle();return ((id(*)(id,SEL))originalBundle)(cls,sel);}
static void Begin(void){watching=NO;[trace removeAllObjects];watching=YES;}
// Count-only input distinguishes zero from full-width nonzero in the auto branch.
@interface CaptionCountArray : NSArray
@property(nonatomic) NSUInteger reportedCount;
@end
@implementation CaptionCountArray
- (NSUInteger)count{Event(@"count");return self.reportedCount;}
- (id)objectAtIndex:(NSUInteger)i{(void)i;[NSException raise:@"UnexpectedEnumeration" format:@"Auto branch must only query count"];return nil;}
@end
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[[NSMutableArray alloc]init];
    originalPreference=method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),(IMP)Preference);
    originalBundle=method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),(IMP)Bundle);
    DownloadMenuHelper *h=[DownloadMenuHelper new];CaptionNode *player=Node(@"player",nil),*active=Node(@"active",nil);player.activeVideo=active;
    NSArray *identifiers=@[NSNull.null,@"",@"en",@"t.",@"t.en",@"a.",@"a.en",@"ta.",@"ta.en",@"T.en",@"A.en",@"TA.en",@" t.en"];
    for(id identifier in identifiers)for(NSUInteger autoCaps=0;autoCaps<2;++autoCaps){
        CaptionNode *track=Node(@"track",identifier);NSArray *tracks=@[track];active.availableCaptionTracks=tracks;
        DownloadsPreferences[@"addAutoCaps"]=@(autoCaps);BOOL manual=identifier==NSNull.null||!([identifier hasPrefix:@"t."]||[identifier hasPrefix:@"a."]||[identifier hasPrefix:@"ta."]);
        NSUInteger reads=identifier!=NSNull.null&&[identifier hasPrefix:@"t."]?1:identifier!=NSNull.null&&[identifier hasPrefix:@"a."]?2:3;
        Begin();BOOL has=[h hasCaptions:player];watching=NO;Check(has==(autoCaps||manual),@"caption availability prefix matrix");
        NSMutableArray *wanted=[[NSMutableArray alloc]initWithArray:@[@"player.active",@"active.tracks",@"preference:addAutoCaps"]];if(!autoCaps)for(NSUInteger i=0;i<reads;++i)[wanted addObject:@"track.id"];
        Equal(trace,wanted,@"availability preference before short-circuit identifier reads");
        Begin();NSArray *result=[h captionsForDownloading:tracks];watching=NO;
        if(autoCaps)Check(result==tracks,@"auto-enabled filter returns original input identity");else if(manual){Equal(result,tracks,@"manual track preserved");Check(result!=tracks&&[result isKindOfClass:NSMutableArray.class],@"manual filter returns its mutable working array");}else Check(result==nil,@"no original tracks returns nil");
        wanted=[[NSMutableArray alloc]init];for(NSUInteger i=0;i<reads;++i)[wanted addObject:@"track.id"];[wanted addObject:@"preference:addAutoCaps"];
        Equal(trace,wanted,@"filter still evaluates IDs before auto-caption preference");
        Begin();NSString *title=[h titleForCaption:track];watching=NO;
        BOOL translated=identifier!=NSNull.null&&[identifier hasPrefix:@"t."],translatedAuto=identifier!=NSNull.null&&[identifier hasPrefix:@"ta."];
        Equal(title,translated?@"English (Translated)":translatedAuto?@"English (TranslatedAutoGen)":@"English",@"caption label prefix matrix");
        wanted=[[NSMutableArray alloc]initWithArray:translated?@[@"track.id",@"track.name",@"bundle"]:@[@"track.id",@"track.id",@"track.name"]];if(translatedAuto)[wanted addObject:@"bundle"];
        Equal(trace,wanted,@"title branch reads and name-before-localization");
    }
    // Empty and nil inputs preserve each method's distinct result contract.
    for(NSUInteger autoCaps=0;autoCaps<2;++autoCaps){
        DownloadsPreferences[@"addAutoCaps"]=@(autoCaps);for(id list in @[NSNull.null,@[]]){
            NSArray *tracks=list==NSNull.null?nil:list;active.availableCaptionTracks=tracks;Begin();Check(![h hasCaptions:player],@"nil or empty tracks unavailable");watching=NO;
            Begin();NSArray *result=[h captionsForDownloading:tracks];watching=NO;Check(result==(autoCaps?tracks:nil),@"empty/nil filtering identity");
        }
    }
    CaptionCountArray *counted=[CaptionCountArray new];active.availableCaptionTracks=counted;DownloadsPreferences[@"addAutoCaps"]=@YES;
    for(NSNumber *count in @[@0,@1,@(0x100000000ULL),@(ULLONG_MAX)]){counted.reportedCount=count.unsignedLongLongValue;Begin();Check([h hasCaptions:player]==(count.unsignedLongLongValue!=0),@"full-width count truth test");watching=NO;Equal(trace,(@[@"player.active",@"active.tracks",@"preference:addAutoCaps",@"count"]),@"automatic captions bypass enumeration");}
    // A matching original track stops availability scanning immediately.
    CaptionNode *first=Node(@"first",@"manual"),*last=Node(@"last",@"ta.en");active.availableCaptionTracks=@[first,last];DownloadsPreferences[@"addAutoCaps"]=@NO;
    Begin();Check([h hasCaptions:player],@"first original caption found");watching=NO;Check(![trace containsObject:@"last.id"],@"availability returns at first original caption");
    // Separate identifier getters can observe new values at each prefix check.
    first.identifierValues=@[@"a.en",@"t.en",@"manual"];first.identifierReads=0;active.availableCaptionTracks=@[first];
    Begin();Check([h hasCaptions:player],@"availability uses three independent ID values");watching=NO;Check(first.identifierReads==3,@"three availability getter calls");
    first.identifierReads=0;Begin();Equal([h captionsForDownloading:@[first]],(@[first]),@"filter uses three independent ID values");watching=NO;
    first.identifierValues=@[@"manual",@"ta.en"];first.identifierReads=0;Begin();Equal([h titleForCaption:first],@"English (TranslatedAutoGen)",@"title second ID getter can change prefix");watching=NO;
    first.identifierValues=nil;
    // A preference read can replace the player's tracks, but the original list is used.
    active.availableCaptionTracks=@[first];__weak CaptionNode *weakActive=active;onPreference=^{weakActive.availableCaptionTracks=@[];};
    Begin();Check([h hasCaptions:player],@"track list retained before preference-side mutation");watching=NO;onPreference=nil;
    // Filtering reads the preference after identifier-side changes, even when true initially.
    NSArray *input=@[first,last];DownloadsPreferences[@"addAutoCaps"]=@YES;first.onIdentifier=^{DownloadsPreferences[@"addAutoCaps"]=@NO;};
    Begin();NSArray *filtered=[h captionsForDownloading:input];watching=NO;Equal(filtered,(@[first]),@"identifier changes preference before result selection");Check(filtered!=input,@"changed preference selects working array");first.onIdentifier=nil;
    DownloadsPreferences[@"addAutoCaps"]=@NO;first.onIdentifier=^{DownloadsPreferences[@"addAutoCaps"]=@YES;};Begin();Check([h captionsForDownloading:input]==input,@"late enabled preference returns original array");watching=NO;first.onIdentifier=nil;
    // Duplicate original tracks retain order and identity in the working result.
    DownloadsPreferences[@"addAutoCaps"]=@NO;Begin();Equal([h captionsForDownloading:@[last,first,first]],(@[first,first]),@"duplicate originals preserved in input order");watching=NO;
    // Name getter precedes localization; the object is retained without copying.
    NSMutableString *name=[NSMutableString stringWithString:@"Before"];last.nameObject=name;onBundle=^{[name setString:@"After"];};Begin();Equal([h titleForCaption:last],@"After (TranslatedAutoGen)",@"mutable title object survives through localization");watching=NO;onBundle=nil;
    first.nameObject=name;Begin();Check([h titleForCaption:first]==name,@"plain title returns original name identity");watching=NO;
    last.nameObject=nil;last.displayName=nil;Begin();Equal([h titleForCaption:last],@"(null) (TranslatedAutoGen)",@"nil translated display name uses Foundation formatting");watching=NO;
    Begin();Check([h titleForCaption:nil]==nil,@"nil caption title remains nil");watching=NO;Check(trace.count==0,@"nil caption does not localize");
    method_setImplementation(class_getClassMethod(YTLUserDefaults.class,@selector(boolForKey:)),originalPreference);
    method_setImplementation(class_getClassMethod(NSBundle.class,@selector(ytl_defaultBundle)),originalBundle);
    printf("%s First_menu_captions: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
