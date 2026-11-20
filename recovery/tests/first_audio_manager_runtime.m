#import "downloads_doubles.h"
#import "../source/Downloads/AudioManager.h"
#import <objc/runtime.h>
#undef NSLog
static NSUInteger checks,failures,allocations;
static BOOL watch,sessionNil,bundleNil,pathNil,urlNil,playerNil,categoryReturn,clearPlayerError;
static NSMutableArray *trace,*logs;
static NSError *categoryError,*playerError,*incomingPlayerError;
static NSURL *testURL;
static id assignedPlayer,expectedDelegate;
static NSArray *getterValues;
static NSUInteger getterIndex;
static void (^onDelegate)(void),(^onPlaying)(void),(^onStop)(void);
static void Event(NSString *s){if(watch)[trace addObject:s];}
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id a,id b,NSString *label){Check(a==b||[a isEqual:b],[NSString stringWithFormat:@"%@: %@ versus %@",label,a,b]);}
void FirstAudioLog(NSString *format,...){va_list args;va_start(args,format);NSString *line=[[NSString alloc]initWithFormat:format arguments:args];va_end(args);Event(@"log");[logs addObject:line];}
@interface AudioProbe : AudioManager @end
@implementation AudioProbe
- (void)setAudioPlayer:(AVAudioPlayer *)player{Event(@"manager.set");assignedPlayer=player;[super setAudioPlayer:player];}
- (AVAudioPlayer *)audioPlayer{Event(@"manager.get");if(getterValues){id p=getterValues[MIN(getterIndex++,getterValues.count-1)];return p==NSNull.null?nil:p;}return [super audioPlayer];}
@end
@interface FirstAudioPlayer : AVAudioPlayer @end
@implementation FirstAudioPlayer
- (instancetype)initWithContentsOfURL:(NSURL *)url error:(NSError **)error{
 Event(@"player.init");Check(url==testURL,@"URL factory result forwarded by identity");Check(error!=NULL,@"player receives error pointer");incomingPlayerError=error?*error:nil;
 if(error&&(playerError||clearPlayerError))*error=playerError;
 if(playerNil)return nil;
 return [super initWithContentsOfURL:url error:error];
}
- (void)setDelegate:(id<AVAudioPlayerDelegate>)delegate{Event(@"delegate");Check((id)delegate==expectedDelegate||expectedDelegate==nil,@"delegate is initialized manager");[super setDelegate:delegate];if(onDelegate)onDelegate();}
- (BOOL)prepareToPlay{Event(@"prepare");return [super prepareToPlay];}
- (BOOL)isPlaying{Event(@"isPlaying");BOOL value=[super isPlaying];if(onPlaying)onPlaying();return value;}
- (BOOL)play{Event(@"play");return [super play];}
- (void)stop{Event(@"stop");[super stop];if(onStop)onStop();}
- (void)setCurrentTime:(double)value{Event(@"time");[super setCurrentTime:value];}
@end
@implementation AVAudioPlayer (FirstAudioAllocation)
+ (instancetype)allocWithZone:(struct _NSZone *)zone{Event(@"player.alloc");++allocations;id result=[super allocWithZone:zone];object_setClass(result,FirstAudioPlayer.class);return result;}
+ (instancetype)new{Event(@"player.new");return [super new];}
@end
static IMP oldSession,oldBundle,oldPath,oldURL;
static id Session(id cls,SEL sel){Event(@"session");return sessionNil?nil:((id(*)(id,SEL))oldSession)(cls,sel);}
static BOOL SetCategory(id self,SEL sel,id category,NSUInteger options,NSError **error){(void)self;(void)sel;Event(@"category");Check(category==AVAudioSessionCategoryPlayback&&options==1,@"playback category and mixing option");Check(error&&*error==nil,@"category error initially nil");if(error)*error=categoryError;return categoryReturn;}
static id Bundle(id cls,SEL sel){Event(@"bundle");return bundleNil?nil:((id(*)(id,SEL))oldBundle)(cls,sel);}
static id Path(id self,SEL sel,id name,id type){Event(@"path");Equal(name,@"SponsorAudio",@"resource name");Equal(type,@"m4a",@"resource extension");return pathNil?nil:((id(*)(id,SEL,id,id))oldPath)(self,sel,name,type);}
static id URL(id cls,SEL sel,id path){(void)cls;(void)sel;Event(@"url");Check((path==nil)==(bundleNil||pathNil),@"path result forwarded even nil");return urlNil?nil:testURL;}
static IMP Swap(Class cls,SEL sel,IMP imp,BOOL isClass){Method m=isClass?class_getClassMethod(cls,sel):class_getInstanceMethod(cls,sel);Check(m!=NULL,@"fixture selector exists");IMP old=method_getImplementation(m);Class target=isClass?object_getClass(cls):cls;if(class_addMethod(target,sel,imp,method_getTypeEncoding(m)))return old;return method_setImplementation(m,imp);}
static void Begin(void){watch=NO;[trace removeAllObjects];[logs removeAllObjects];incomingPlayerError=nil;assignedPlayer=nil;getterValues=nil;getterIndex=0;onDelegate=nil;onPlaying=nil;onStop=nil;expectedDelegate=nil;watch=YES;}
static AudioProbe *Construct(void){AudioProbe *p=[[AudioProbe alloc]init];watch=NO;return p;}
static void Playback(AudioProbe *manager,BOOL stop){watch=NO;[trace removeAllObjects];getterIndex=0;watch=YES;if(stop)[manager stopAudio];else [manager playAudio];watch=NO;}
int main(int argc,const char **argv){@autoreleasepool{
 DownloadsInstallDoubles();DownloadsFixtureRoot=@"/fixture";trace=[NSMutableArray new];logs=[NSMutableArray new];categoryReturn=YES;testURL=[NSURL fileURLWithPath:@"/fixture/audio.m4a"];
 oldSession=Swap(AVAudioSession.class,@selector(sharedInstance),(IMP)Session,YES);Swap(AVAudioSession.class,@selector(setCategory:withOptions:error:),(IMP)SetCategory,NO);
 oldBundle=Swap(NSBundle.class,@selector(ytl_defaultBundle),(IMP)Bundle,YES);oldPath=Swap(object_getClass([NSBundle ytl_defaultBundle]),@selector(pathForResource:ofType:),(IMP)Path,NO);
 oldURL=Swap(NSURL.class,@selector(fileURLWithPath:),(IMP)URL,YES);
 if(argc>1){
  BOOL failed=!strcmp(argv[1],"nil-singleton");if(failed)playerError=[NSError errorWithDomain:@"fixture" code:1 userInfo:nil];
  Begin();Class cls=!strcmp(argv[1],"subclass-singleton")?AudioProbe.class:AudioManager.class;AudioManager *first=[cls sharedInstance];watch=NO;NSUInteger count=allocations;
  Check(failed?first==nil:[first class]==cls,@"singleton uses receiving class and preserves nil init");playerError=nil;
  for(NSUInteger i=0;i<16;++i){Check([AudioManager sharedInstance]==first&&[AudioProbe sharedInstance]==first,@"shared singleton reused across classes");}
  Check(allocations==count&&count==1,@"singleton initialization runs once including failure");
 }else{
  Begin();AudioProbe *manager=Construct();
  Equal(trace,(@[@"session",@"category",@"bundle",@"path",@"url",@"player.alloc",@"player.init",@"manager.set",@"manager.get",@"delegate",@"manager.get",@"prepare"]),@"URL precedes allocation and delegate/prepare use fresh property reads");
  Check(manager&&manager.audioPlayer.delegate==manager&&manager.audioPlayer.prepareCount==1,@"initialized player prepared and delegated");
  Check(logs.count==0&&incomingPlayerError==nil,@"normal init has no error");
  // Category BOOL is ignored; only NSError content decides the later failure.
  NSError *category=[NSError errorWithDomain:@"category" code:1 userInfo:@{NSLocalizedDescriptionKey:@"category failed"}],*player=[NSError errorWithDomain:@"player" code:2 userInfo:@{NSLocalizedDescriptionKey:@"player failed"}];
  for(NSUInteger ce=0;ce<2;++ce)for(NSUInteger pe=0;pe<2;++pe)for(NSUInteger clear=0;clear<2;++clear)for(NSUInteger result=0;result<2;++result){
   categoryError=ce?category:nil;playerError=pe?player:nil;clearPlayerError=clear;categoryReturn=result;Begin();AudioProbe *got=Construct();NSError *finalError=pe?player:clear?nil:ce?category:nil;
   Check((got==nil)==(finalError!=nil),@"NSError content decides init failure independently of BOOL");Check(incomingPlayerError==categoryError,@"category error passed into player initialization");
   Check(assignedPlayer!=nil,@"player setter invoked before error decision");
   NSMutableArray *wanted=[NSMutableArray array];if(ce)[wanted addObject:@"DVN --- Unable to set category: category failed"];if(finalError)[wanted addObject:[@"DVN --- Unable to init player: " stringByAppendingString:finalError.localizedDescription]];Equal(logs,wanted,@"exact error logs and ordering");
   Check(([trace containsObject:@"prepare"])==(finalError==nil),@"error path skips prepare");if(finalError){NSUInteger setter=[trace indexOfObject:@"manager.set"];Check(setter!=NSNotFound&&setter<[trace indexOfObject:@"log" inRange:NSMakeRange(setter,trace.count-setter)],@"setter before player error log");}
  }
  categoryError=playerError=nil;clearPlayerError=NO;categoryReturn=YES;
  for(NSUInteger sn=0;sn<2;++sn)for(NSUInteger bn=0;bn<2;++bn)for(NSUInteger pn=0;pn<2;++pn)for(NSUInteger un=0;un<2;++un)for(NSUInteger playerN=0;playerN<2;++playerN){sessionNil=sn;bundleNil=bn;pathNil=pn;urlNil=un;playerNil=playerN;NSURL *saved=testURL;if(un)testURL=nil;Begin();AudioProbe *got=Construct();testURL=saved;
   Check(got!=nil,@"nil host results without NSError do not fail manager init");Check((assignedPlayer==nil)==playerN,@"nil initialized player assigned");Check([trace containsObject:@"url"]&&[trace containsObject:@"player.init"],@"nil path and URL forwarded without guards");
  }
  sessionNil=bundleNil=pathNil=urlNil=playerNil=NO;
  Begin();manager=Construct();AVAudioPlayer *one=manager.audioPlayer;Begin();AudioProbe *other=Construct();AVAudioPlayer *two=other.audioPlayer;Begin();AudioProbe *third=Construct();AVAudioPlayer *three=third.audioPlayer;
  // The delegate can replace the current player before prepare is sent.
  getterValues=@[one,two];getterIndex=0;expectedDelegate=nil;watch=YES;[trace removeAllObjects];AudioProbe *replaced=[[AudioProbe alloc]init];watch=NO;Check(replaced!=nil&&two.prepareCount==2&&one.delegate==replaced,@"delegate and prepare target separate getter results");
  getterValues=nil;Begin();manager=Construct();
  for(NSUInteger playing=0;playing<2;++playing){one.playing=playing;getterValues=@[one,two];NSUInteger plays=two.playCount;Playback(manager,NO);Equal(trace,playing?(@[@"manager.get",@"isPlaying"]):(@[@"manager.get",@"isPlaying",@"manager.get",@"play"]),@"play gate and fresh getter");Check(two.playCount==plays+!playing,@"play targets fresh property value");}
  for(NSUInteger playing=0;playing<2;++playing){one.playing=playing;two.currentTime=9;three.currentTime=7;getterValues=@[one,two,three];NSUInteger stops=two.stopCount;Playback(manager,YES);Equal(trace,playing?(@[@"manager.get",@"isPlaying",@"manager.get",@"stop",@"manager.get",@"time"]):(@[@"manager.get",@"isPlaying"]),@"stop gate and three independent getters");Check(two.stopCount==stops+playing&&two.currentTime==9&&three.currentTime==(playing?0:7),@"stop and rewind use separate current players");}
  getterValues=@[NSNull.null,two];NSUInteger plays=two.playCount;Playback(manager,NO);Check(two.playCount==plays+1,@"nil first player means not playing; next getter still used");getterValues=@[NSNull.null,two,three];NSUInteger stops=two.stopCount;Playback(manager,YES);Check(two.stopCount==stops,@"nil first player skips stop and rewind");
  getterValues=nil;watch=YES;[trace removeAllObjects];[manager audioPlayerDidFinishPlaying:one successfully:NO];[manager audioPlayerDidFinishPlaying:nil successfully:YES];watch=NO;Check(trace.count==0,@"finish callback has no retained application behavior");
  // Exercise the actual synthesized strong setter/getter and ARC destructor.
  assignedPlayer=nil;AudioManager *owner=[AudioManager alloc];__weak AVAudioPlayer *weakPlayer;@autoreleasepool{AVAudioPlayer *p=[AVAudioPlayer alloc];weakPlayer=p;owner.audioPlayer=p;}Check(weakPlayer!=nil&&owner.audioPlayer==weakPlayer,@"strong property retains exact object");owner.audioPlayer=nil;Check(weakPlayer==nil,@"setter releases previous player");
  @autoreleasepool{AVAudioPlayer *p=[AVAudioPlayer alloc];weakPlayer=p;owner.audioPlayer=p;}owner=nil;Check(weakPlayer==nil,@"destructor releases owned player");
 }
 printf("%s First_audio_manager: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
