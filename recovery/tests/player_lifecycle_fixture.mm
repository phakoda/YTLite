#import "../source/Hooks/PlayerLifecycleHost.h"
#import "../source/Hooks/PlayerLifecycleHelpers.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
#import "../source/SleepTimer/YTPSleepTimer.h"
#import "../source/Controls/YTPSpeedMaster.h"
#import "../source/Helpers/YTLHelper.h"
#import "../source/Support/YTPDB.h"
#import <objc/runtime.h>
#import <objc/message.h>
#include <math.h>
static NSUInteger checks,originalCalls,sleepCancels,deallocated;
static NSMutableArray *events,*scheduled,*preferenceReads;
static NSMutableDictionary *preferences;
static BOOL wifi,modernCaptions,legacyCaptions,videoConstraintSupported,audioConstraintSupported,loopGetter,loopingGetter,modernShorts,advanceShorts,recordDeallocation;
static NSInteger responseAPI;
static double speedRate=1,dateInterval;
static __weak id lastPlayer,lastSelf,arg1,arg2,arg3;
static SEL lastSelector;
static NSUInteger speedCalls,dateCalls,fullscreenCalls,advanceCalls,captionCalls,videoConstraintCalls,audioConstraintCalls,modernCaptionCalls;
static id selectedCaption,selectedVideoConstraint,selectedAudioConstraint;
static NSInteger captionSource;
static NSArray *languageCodes;
#define CHECK(...) do {checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL line%d: %s; events=%s\n",__LINE__,#__VA_ARGS__,events.description.UTF8String);exit(1);}}while(0)
static void Event(NSString *event){[events addObject:event];}
static void Reset(void){[events removeAllObjects];[scheduled removeAllObjects];[preferenceReads removeAllObjects];originalCalls=sleepCancels=captionCalls=videoConstraintCalls=audioConstraintCalls=speedCalls=dateCalls=fullscreenCalls=advanceCalls=modernCaptionCalls=0;lastSelf=arg1=arg2=arg3=nil;selectedCaption=selectedVideoConstraint=selectedAudioConstraint=nil;captionSource=-99;}
BOOL ytpBool(NSString *key){[preferenceReads addObject:key];Event([@"bool:" stringByAppendingString:key]);return [preferences[key]boolValue];}
NSInteger ytpInt(NSString *key){[preferenceReads addObject:key];Event([@"int:" stringByAppendingString:key]);return [preferences[key]integerValue];}
@implementation UIView @end
@implementation UIViewController @end
@implementation UILabel
- (void)sizeToFit {self.fixtureFits++;Event(@"fit");}
@end
@implementation NSDate (PlayerLifecycleClock)
+ (instancetype)ytlFixtureDateWithTimeIntervalSinceNow:(NSTimeInterval)interval {dateCalls++;dateInterval=interval;return [NSDate dateWithTimeIntervalSinceReferenceDate:12*3600+interval];}
@end
@implementation YTPSleepTimer
+ (instancetype)sharedTimer {static YTPSleepTimer *timer;static dispatch_once_t once;dispatch_once(&once,^{timer=[self new];});return timer;}
- (void)cancelIfPlayerClosed {sleepCancels++;Event(@"cancelSleep");}
@end
@implementation YTPSpeedMaster
+ (double)playbackRateForPlayer:(id)player {lastPlayer=player;Event(@"getRate");return speedRate;}
+ (void)setPlaybackRate:(double)rate forPlayer:(id)player {speedCalls++;speedRate=rate;lastPlayer=player;Event(@"setRate");}
@end
@implementation YTLHelper
+ (BOOL)isConnectedToWiFi {Event(@"wifi");return wifi;}
@end
@implementation YTPDB
+ (NSString *)langCodeForIndex:(NSInteger)index {return languageCodes[index];}
@end
@interface FixtureCaption:NSObject<YTLPlayerCaption>
@property(nonatomic,copy) NSString *languageCode;
@end
@implementation FixtureCaption @end
@interface FixtureAudio:NSObject<YTLPlayerAudioTrack>
@property(nonatomic,copy) NSString *id_p;
@end
@implementation FixtureAudio @end
@interface FixtureFormat:NSObject<YTLPlayerFormat>
@property(nonatomic) int singleDimensionResolution;
@property(nonatomic,copy) NSString *qualityLabel;
@property(nonatomic,strong) id<YTLPlayerAudioTrack> audioTrack;
@end
@implementation FixtureFormat @end
@interface MLAudioFormatConstraint:NSObject<YTLPlayerAudioConstraint>
@property(nonatomic) BOOL DRCEnabled;
@property(nonatomic,strong) id<YTLPlayerAudioTrack> track;
@property(nonatomic,strong) id config;
@property(nonatomic) int reason;
@end
@implementation MLAudioFormatConstraint
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(initWithAudioTrack:audioQualityConfig:formatSelectionReason:DRCEnabled:))return audioConstraintSupported;return [super respondsToSelector:selector];}
- (instancetype)initWithAudioTrack:(id<YTLPlayerAudioTrack>)track audioQualityConfig:(id)config formatSelectionReason:(int)reason DRCEnabled:(BOOL)drc {self.track=track;self.config=config;self.reason=reason;self.DRCEnabled=drc;Event(@"audioInit");return self;}
@end
@interface MLQuickMenuVideoQualitySettingFormatConstraint:NSObject<YTLPlayerVideoConstraint>
@property(nonatomic) int setting;
@property(nonatomic) NSInteger reason;
@property(nonatomic,copy) NSString *label;
@end
@implementation MLQuickMenuVideoQualitySettingFormatConstraint
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(initWithVideoQualitySetting:formatSelectionReason:qualityLabel:))return videoConstraintSupported;return [super respondsToSelector:selector];}
- (instancetype)initWithVideoQualitySetting:(int)setting formatSelectionReason:(NSInteger)reason qualityLabel:(NSString *)label {self.setting=setting;self.reason=reason;self.label=label;Event(@"videoInit");return self;}
@end
@interface FixtureVideo:NSObject<YTLPlayerVideo>
@property(nonatomic,strong) id delegate;
@property(nonatomic) double totalMediaTime;
@property(nonatomic,strong) NSArray *availableCaptionTracks,*selectableVideoFormats,*selectableAudioFormats;
@property(nonatomic,strong) id<YTLPlayerFormat> selectedAudioFormat;
@property(nonatomic,strong) id<YTLPlayerAudioConstraint> audioFormatConstraint;
@end
@implementation FixtureVideo
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(setActiveCaptionTrack:source:))return modernCaptions;if(selector==@selector(setActiveCaptionTrack:))return legacyCaptions;return [super respondsToSelector:selector];}
- (void)setActiveCaptionTrack:(id<YTLPlayerCaption>)track {captionCalls++;selectedCaption=track;Event(@"captionLegacy");}
- (void)setActiveCaptionTrack:(id<YTLPlayerCaption>)track source:(NSInteger)source {captionCalls++;modernCaptionCalls++;selectedCaption=track;captionSource=source;Event(@"captionModern");}
- (void)setVideoFormatConstraint:(id<YTLPlayerVideoConstraint>)constraint {videoConstraintCalls++;selectedVideoConstraint=constraint;Event(@"videoConstraint");}
- (void)setAudioFormatConstraint:(id<YTLPlayerAudioConstraint>)constraint {_audioFormatConstraint=constraint;audioConstraintCalls++;selectedAudioConstraint=constraint;Event(@"audioConstraint");}
@end
@interface FixtureTime:NSObject<YTLPlayerTime>
@property(nonatomic) double time;
@end
@implementation FixtureTime @end
@interface FixtureResponse:NSObject<YTLPlayerResponse,YTLPlayerData,YTLPlayerCaptions,YTLPlayerCaptionList,YTLPlayerDefaultAudioData>
@property(nonatomic,strong) NSArray *captionTracksArray;
@property(nonatomic,copy) NSString *audioTrackId;
@end
@implementation FixtureResponse
- (id<YTLPlayerData>)playerData{return self;}
- (id<YTLPlayerCaptions>)captions{return self;}
- (id<YTLPlayerCaptionList>)playerCaptionsTracklistRenderer{return self;}
- (id<YTLPlayerDefaultAudioData>)ml_defaultAudioTrackData{return self;}
@end
@interface YTWatchViewController:UIViewController @end
@implementation YTWatchViewController @end
@interface FixtureWatchSubclass:YTWatchViewController @end
@implementation FixtureWatchSubclass @end
@interface YTMainAppVideoPlayerOverlayViewController:NSObject<YTLPlayerLoopOverlay>
@property(nonatomic) NSInteger loopMode;
@end
@implementation YTMainAppVideoPlayerOverlayViewController
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(loopMode))return loopGetter;return [super respondsToSelector:selector];}
- (void)setLoopMode:(NSInteger)value {_loopMode=value;Event(@"loopMode");}
@end
@interface YTLocalPlaybackController:NSObject<YTLPlayerLocalPlayback>
@property(nonatomic) BOOL loopingEnabled;
@end
@implementation YTLocalPlaybackController
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(loopingEnabled))return loopingGetter;return [super respondsToSelector:selector];}
- (void)setLoopingEnabled:(BOOL)value {_loopingEnabled=value;Event(@"looping");}
@end
@interface FixtureFullscreen:NSObject<YTLPlayerFullscreenDelegate> @end
@implementation FixtureFullscreen
- (void)showFullScreen {fullscreenCalls++;Event(@"fullscreen");}
@end
@interface FixtureBar:NSObject
@property(nonatomic,strong) UILabel *durationLabel;
@property(nonatomic,copy) NSString *endTimeString;
@end
@implementation FixtureBar @end
@interface YTMainAppVideoPlayerOverlayView:NSObject
@property(nonatomic,strong) FixtureBar *playerBar;
@end
@implementation YTMainAppVideoPlayerOverlayView @end
@interface FixturePlayerView:UIView
@property(nonatomic,strong) id overlayView;
@end
@implementation FixturePlayerView @end
@interface YTShortsPlayerViewController:UIViewController @end
@implementation YTShortsPlayerViewController
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(maybeLoopPlayback))return modernShorts;if(selector==@selector(reelContentViewRequestsAdvanceToNextVideo:))return advanceShorts;return [super respondsToSelector:selector];}
- (id)performSelector:(SEL)selector {CHECK(selector==@selector(reelContentViewRequestsAdvanceToNextVideo:));advanceCalls++;Event(@"advanceWithoutArgument");return nil;}
@end
@interface FixturePanelShorts:YTShortsPlayerViewController
@property(nonatomic) BOOL isEngagementPanelVisible;
@end
@implementation FixturePanelShorts @end
static FixtureVideo *active;
static FixtureResponse *response;
static id overlay;
static BOOL mdx;
static id uiDelegate;
@implementation YTPlayerViewController
- (id<YTLPlayerVideo>)activeVideo {Event(@"activeVideo");return active;}
- (id<YTLPlayerLoopOverlay>)activeVideoPlayerOverlay {Event(@"overlay");return overlay;}
- (BOOL)isMDXActive {Event(@"mdx");return mdx;}
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(playerResponse))return responseAPI==1;if(selector==@selector(contentPlayerResponse))return responseAPI==2;return [super respondsToSelector:selector];}
- (id<YTLPlayerResponse>)playerResponse {CHECK(responseAPI==1);Event(@"playerResponse");return response;}
- (id<YTLPlayerResponse>)contentPlayerResponse {CHECK(responseAPI==2);Event(@"contentResponse");return response;}
- (id)valueForKey:(NSString *)key {CHECK([key isEqual:@"_UIDelegate"]);return uiDelegate;}
- (void)performSelector:(SEL)selector withObject:(id)object afterDelay:(NSTimeInterval)delay {CHECK(object==nil);[scheduled addObject:@{@"selector":NSStringFromSelector(selector),@"delay":@(delay)}];Event([@"schedule:" stringByAppendingString:NSStringFromSelector(selector)]);}
- (void)playbackController:(id)c didActivateVideo:(id)v withPlaybackData:(id)d {originalCalls++;lastSelf=self;lastSelector=_cmd;arg1=c;arg2=v;arg3=d;CHECK(!canRememberLoopMode);Event(@"originalActivation");}
- (void)singleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time {originalCalls++;lastSelf=self;lastSelector=_cmd;arg1=video;arg2=time;Event(@"originalTime");}
- (void)potentiallyMutatedSingleVideo:(id<YTLPlayerVideo>)video currentVideoTimeDidChange:(id<YTLPlayerTime>)time {originalCalls++;lastSelf=self;lastSelector=_cmd;arg1=video;arg2=time;Event(@"originalTime");}
- (void)dealloc {if(recordDeallocation){deallocated++;Event(@"originalDealloc");}}
@end
static FixtureCaption *Caption(NSString *language){FixtureCaption *c=[FixtureCaption new];c.languageCode=language;return c;}
static FixtureFormat *Format(int resolution,NSString *label){FixtureFormat *f=[FixtureFormat new];f.singleDimensionResolution=resolution;f.qualityLabel=label;return f;}
static FixtureFormat *Audio(NSString *identifier){FixtureFormat *f=[FixtureFormat new];FixtureAudio *a=[FixtureAudio new];a.id_p=identifier;f.audioTrack=a;return f;}
static YTPlayerViewController *Player(void){YTPlayerViewController *p=[YTPlayerViewController new];p.parentViewController=[YTWatchViewController new];return p;}
static void SetBaseline(void){[preferences removeAllObjects];preferences[@"autoSpeedIndex"]=@3;active=[FixtureVideo new];response=[FixtureResponse new];responseAPI=1;mdx=NO;modernCaptions=legacyCaptions=videoConstraintSupported=audioConstraintSupported=loopGetter=loopingGetter=YES;modernShorts=NO;advanceShorts=YES;overlay=nil;uiDelegate=[FixtureFullscreen new];speedRate=1;Reset();}
static void TestActivation(void){
    SetBaseline();YTPlayerViewController *p=Player();NSObject *c=[NSObject new],*v=[NSObject new],*d=[NSObject new];
    NSArray *keys=@[@"wiFiQualityIndex",@"autoFullscreen",@"autoSpeedIndex",@"captionsIndex",@"audioTrackIndex",@"rememberLoop"];
    NSArray *selectors=@[@"autoQuality",@"autoFullscreen",@"setAutoSpeed",@"selectCaptions",@"selectAudioTrack",@"restoreLoopMode"];
    for(NSUInteger mask=0;mask<64;mask++){
        SetBaseline();for(NSUInteger i=0;i<6;i++)preferences[keys[i]]=(mask&(1u<<i))?@1:(i==2?@3:@0);canRememberLoopMode=YES;Reset();
        [p playbackController:c didActivateVideo:v withPlaybackData:d];CHECK(originalCalls==1&&lastSelf==p&&lastSelector==@selector(playbackController:didActivateVideo:withPlaybackData:));CHECK(arg1==c&&arg2==v&&arg3==d);CHECK(sleepCancels==1&&!canRememberLoopMode);CHECK([events[0]isEqual:@"cancelSleep"]&&[events[1]isEqual:@"originalActivation"]);
        NSUInteger index=0;for(NSUInteger i=0;i<6;i++)if(mask&(1u<<i)){CHECK([scheduled[index][@"selector"]isEqual:selectors[i]]);CHECK([scheduled[index][@"delay"]doubleValue]==(i==5?3:.75));index++;}CHECK(scheduled.count==index);CHECK([preferenceReads containsObject:@"cellQualityIndex"]==!(mask&1));
    }
    SetBaseline();preferences[@"cellQualityIndex"]=@4;[p playbackController:nil didActivateVideo:nil withPlaybackData:nil];CHECK(scheduled.count==1&&[scheduled[0][@"selector"]isEqual:@"autoQuality"]);
    SetBaseline();preferences[@"autoFullscreen"]=@YES;preferences[@"autoSpeedIndex"]=@5;preferences[@"captionsIndex"]=@1;preferences[@"rememberLoop"]=@YES;active.availableCaptionTracks=@[];
    [p playbackController:nil didActivateVideo:nil withPlaybackData:nil];NSArray *tasks=[scheduled copy];[scheduled removeAllObjects];for(NSDictionary *task in tasks)((void(*)(id,SEL))objc_msgSend)(p,NSSelectorFromString(task[@"selector"]));CHECK(fullscreenCalls==1&&speedCalls==1&&speedRate==1.5&&captionCalls==1&&selectedCaption==nil&&canRememberLoopMode);
}
static void TestLoopSpeed(void){
    SetBaseline();YTPlayerViewController *p=Player();YTMainAppVideoPlayerOverlayViewController *o=[YTMainAppVideoPlayerOverlayViewController new];YTLocalPlaybackController *local=[YTLocalPlaybackController new];overlay=o;active.delegate=local;
    for(NSNumber *mode in @[@0,@1,@(-2),@(NSIntegerMax)])for(NSNumber *has in @[@NO,@YES]){preferences[@"loopMode"]=mode;loopGetter=loopingGetter=has.boolValue;o.loopMode=77;local.loopingEnabled=NO;Reset();canRememberLoopMode=NO;[p restoreLoopMode];CHECK(canRememberLoopMode);CHECK(o.loopMode==(has.boolValue?mode.integerValue:77));CHECK(local.loopingEnabled==(has.boolValue&&mode.integerValue!=0));}
    preferences[@"loopMode"]=@0;loopingGetter=YES;local.loopingEnabled=YES;[p restoreLoopMode];CHECK(local.loopingEnabled);overlay=[NSObject new];active.delegate=[NSObject new];Reset();[p restoreLoopMode];CHECK(canRememberLoopMode&&![events containsObject:@"loopMode"]&&![events containsObject:@"looping"]);
    double expected[]={.25,.5,.75,1,1.25,1.5,1.75,2,3,4,5};for(NSUInteger i=0;i<11;i++){preferences[@"autoSpeedIndex"]=@(i);Reset();[p setAutoSpeed];CHECK(speedCalls==1&&speedRate==expected[i]&&lastPlayer==p);}
    for(NSNumber *bad in @[@(-1),@11]){preferences[@"autoSpeedIndex"]=bad;BOOL raised=NO;@try{[p setAutoSpeed];}@catch(NSException *e){raised=[e.name isEqual:NSRangeException];}CHECK(raised);}
    p.parentViewController=[UIViewController new];Reset();[p setAutoSpeed];CHECK(speedCalls==0&&preferenceReads.count==0);p.parentViewController=[FixtureWatchSubclass new];preferences[@"autoSpeedIndex"]=@8;[p setAutoSpeed];CHECK(speedRate==3);[p autoFullscreen];CHECK(fullscreenCalls==1);uiDelegate=nil;[p autoFullscreen];CHECK(fullscreenCalls==1);
}
static void CheckVideoLabel(YTPlayerViewController *p,NSInteger index,NSString *expected){preferences[wifi?@"wiFiQualityIndex":@"cellQualityIndex"]=@(index);Reset();[p autoQuality];MLQuickMenuVideoQualitySettingFormatConstraint *c=selectedVideoConstraint;CHECK(videoConstraintCalls==1&&[c.label isEqual:expected]);CHECK(c.setting==3&&c.reason==2);}
static void TestQuality(void){
    SetBaseline();YTPlayerViewController *p=Player();wifi=YES;[p autoQuality];CHECK(scheduled.count==1&&[scheduled[0][@"selector"]isEqual:@"autoQuality"]&&[scheduled[0][@"delay"]doubleValue]==3);
    NSArray *labels=@[@"2160p60",@"2160p",@"1440p60",@"1440p",@"1080p60",@"1080p",@"720p60",@"720p",@"480p",@"360p",@"240p",@"144p"];
    NSMutableArray *formats=[NSMutableArray arrayWithObject:Format(4320,@"4320p Premium")];for(NSString *label in labels)[formats addObject:Format(label.intValue,label)];active.selectableVideoFormats=formats;
    CheckVideoLabel(p,0,@"144p");CheckVideoLabel(p,1,@"2160p60");for(NSUInteger i=0;i<labels.count;i++)CheckVideoLabel(p,i+2,labels[i]);
    wifi=NO;preferences[@"wiFiQualityIndex"]=@2;CheckVideoLabel(p,10,@"480p");CHECK([preferenceReads containsObject:@"cellQualityIndex"]&&![preferenceReads containsObject:@"wiFiQualityIndex"]);
    active.selectableVideoFormats=@[Format(720,@"720p60"),Format(1440,@"1440p"),Format(1080,@"1080p Premium")];CheckVideoLabel(p,7,@"720p60");
    active.selectableVideoFormats=@[Format(1440,@"1440p"),Format(720,@"720p60")];CheckVideoLabel(p,7,@"1440p");
    videoConstraintSupported=NO;Reset();[p autoQuality];CHECK(videoConstraintCalls==0);videoConstraintSupported=YES;
    for(NSArray *badFormats in @[@[],@[Format(0,@"0p")],@[Format(2160,@"2160p Premium")]]){active.selectableVideoFormats=badFormats;BOOL raised=NO;@try{[p autoQuality];}@catch(NSException *e){raised=[e.name isEqual:NSInvalidArgumentException];}CHECK(raised);}
    active.selectableVideoFormats=formats;preferences[@"cellQualityIndex"]=@14;BOOL raised=NO;@try{[p autoQuality];}@catch(NSException *e){raised=[e.name isEqual:NSRangeException];}CHECK(raised);
    mdx=YES;Reset();[p autoQuality];CHECK(videoConstraintCalls==0&&scheduled.count==0);mdx=NO;active=nil;[p autoQuality];CHECK(videoConstraintCalls==0&&scheduled.count==0);active=[FixtureVideo new];p.parentViewController=[UIViewController new];[p autoQuality];CHECK(scheduled.count==0);
    SetBaseline();p.parentViewController=[YTWatchViewController new];preferences[@"wiFiQualityIndex"]=@1;wifi=YES;[p autoQuality];active.selectableVideoFormats=@[Format(720,@"720p")];NSDictionary *retry=scheduled[0];[scheduled removeAllObjects];((void(*)(id,SEL))objc_msgSend)(p,NSSelectorFromString(retry[@"selector"]));CHECK(videoConstraintCalls==1&&scheduled.count==0);
}
static void TestCaptions(void){
    SetBaseline();YTPlayerViewController *p=Player();preferences[@"captionsIndex"]=@1;[p selectCaptions];CHECK(scheduled.count==1&&[scheduled[0][@"delay"]doubleValue]==1);active.availableCaptionTracks=@[];[p selectCaptions];CHECK(captionCalls==1&&selectedCaption==nil&&captionSource==0);
    for(NSNumber *modern in @[@NO,@YES])for(NSNumber *legacy in @[@NO,@YES]){modernCaptions=modern.boolValue;legacyCaptions=legacy.boolValue;Reset();[p selectCaptions];CHECK(captionCalls==(modern.boolValue||legacy.boolValue));CHECK(modernCaptionCalls==modern.boolValue);}
    modernCaptions=legacyCaptions=YES;FixtureCaption *en=Caption(@"en"),*autoEn=Caption(@"a.en"),*autoEn2=Caption(@"b.en"),*fr=Caption(@"fr");response.captionTracksArray=@[Caption(@".en")];response.audioTrackId=@".en.4";preferences[@"captionsIndex"]=@2;active.availableCaptionTracks=@[autoEn,en,autoEn2,fr];preferences[@"autoGenCaps"]=@YES;Reset();[p selectCaptions];CHECK(selectedCaption==en);
    active.availableCaptionTracks=@[autoEn,autoEn2,fr];Reset();[p selectCaptions];CHECK(selectedCaption==autoEn2);preferences[@"autoGenCaps"]=@NO;Reset();[p selectCaptions];CHECK(captionCalls==0);
    response.audioTrackId=@"";active.availableCaptionTracks=@[en,fr];Reset();[p selectCaptions];CHECK(selectedCaption==en);responseAPI=2;Reset();[p selectCaptions];CHECK(selectedCaption==en&&[events containsObject:@"contentResponse"]);responseAPI=0;Reset();[p selectCaptions];CHECK(captionCalls==0);responseAPI=1;
    preferences[@"captionsIndex"]=@3;preferences[@"customCaption"]=@1;Reset();[p selectCaptions];CHECK(selectedCaption==fr);preferences[@"customCaption"]=@0;preferences[@"autoGenCaps"]=@YES;active.availableCaptionTracks=@[autoEn,autoEn2];Reset();[p selectCaptions];CHECK(selectedCaption==autoEn2);active.availableCaptionTracks=@[autoEn,en];Reset();[p selectCaptions];CHECK(selectedCaption==en);
    response=nil;Reset();[p selectCaptions];CHECK(captionCalls==0);response=[FixtureResponse new];response.captionTracksArray=@[];preferences[@"captionsIndex"]=@2;Reset();[p selectCaptions];CHECK(captionCalls==0);active.availableCaptionTracks=@[];Reset();[p selectCaptions];CHECK(captionCalls==0&&scheduled.count==0);
    for(NSNumber *mode in @[@0,@4]){preferences[@"captionsIndex"]=mode;active.availableCaptionTracks=@[en];Reset();[p selectCaptions];CHECK(captionCalls==0);}
    active.availableCaptionTracks=nil;mdx=YES;Reset();[p selectCaptions];CHECK(scheduled.count==0);mdx=NO;p.parentViewController=[UIViewController new];[p selectCaptions];CHECK(scheduled.count==0);p.parentViewController=[YTWatchViewController new];active=nil;[p selectCaptions];CHECK(scheduled.count==0);
    SetBaseline();preferences[@"captionsIndex"]=@1;[p selectCaptions];NSDictionary *task=scheduled[0];active.availableCaptionTracks=@[];[scheduled removeAllObjects];((void(*)(id,SEL))objc_msgSend)(p,NSSelectorFromString(task[@"selector"]));CHECK(captionCalls==1&&scheduled.count==0);
}
static void TestAudio(void){
    SetBaseline();YTPlayerViewController *p=Player();preferences[@"audioTrackIndex"]=@1;[p selectAudioTrack];CHECK(scheduled.count==1&&[scheduled[0][@"delay"]doubleValue]==3);active.selectableAudioFormats=@[];Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==0);active.selectedAudioFormat=Audio(@"selected");
    FixtureFormat *a=Audio(@".en.4"),*b=Audio(@".fr.4"),*c=Audio(@".en.3"),*d=Audio(@".en.6"),*dub=Audio(@".en.10"),*loose=Audio(@"french"),*fallback=Audio(@".en.9");
    active.selectableAudioFormats=@[a,b,c];for(NSNumber *drc in @[@NO,@YES]){MLAudioFormatConstraint *old=[MLAudioFormatConstraint new];old.DRCEnabled=drc.boolValue;active.audioFormatConstraint=old;Reset();[p selectAudioTrack];MLAudioFormatConstraint *result=selectedAudioConstraint;CHECK(audioConstraintCalls==1&&result.track==b.audioTrack&&result.config==nil&&result.reason==2&&result.DRCEnabled==drc.boolValue);}
    preferences[@"audioTrackIndex"]=@2;preferences[@"customTrack"]=@0;for(NSArray *formats in @[@[a,c,d],@[a,d,c]]){active.selectableAudioFormats=formats;Reset();[p selectAudioTrack];CHECK([(MLAudioFormatConstraint *)selectedAudioConstraint track]==[formats[1]audioTrack]);}
    active.selectableAudioFormats=@[a,loose,fallback];Reset();[p selectAudioTrack];CHECK([(MLAudioFormatConstraint *)selectedAudioConstraint track]==fallback.audioTrack);active.selectableAudioFormats=@[loose];Reset();[p selectAudioTrack];CHECK([(MLAudioFormatConstraint *)selectedAudioConstraint track]==loose.audioTrack);
    active.selectableAudioFormats=@[dub];preferences[@"ignoreAutoDub"]=@YES;Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==0);preferences[@"ignoreAutoDub"]=@NO;Reset();[p selectAudioTrack];CHECK([(MLAudioFormatConstraint *)selectedAudioConstraint track]==dub.audioTrack);
    preferences[@"audioTrackIndex"]=@1;active.selectableAudioFormats=@[];Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==1&&[(MLAudioFormatConstraint *)selectedAudioConstraint track]==nil);
    audioConstraintSupported=NO;preferences[@"captionsIndex"]=@1;active.availableCaptionTracks=@[];Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==0&&captionCalls==1);audioConstraintSupported=YES;
    p.parentViewController=[UIViewController new];Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==1&&captionCalls==0);mdx=YES;Reset();[p selectAudioTrack];CHECK(audioConstraintCalls==0&&scheduled.count==0);mdx=NO;active=nil;[p selectAudioTrack];CHECK(audioConstraintCalls==0&&scheduled.count==0);
    SetBaseline();preferences[@"audioTrackIndex"]=@1;[p selectAudioTrack];NSDictionary *task=scheduled[0];active.selectableAudioFormats=@[a];active.selectedAudioFormat=a;[scheduled removeAllObjects];((void(*)(id,SEL))objc_msgSend)(p,NSSelectorFromString(task[@"selector"]));CHECK(audioConstraintCalls==1&&[(MLAudioFormatConstraint *)selectedAudioConstraint track]==a.audioTrack&&scheduled.count==0);
}
static void TestTimeHelpers(void){
    SetBaseline();YTPlayerViewController *p=Player();FixtureTime *time=[FixtureTime new];active.totalMediaTime=120.9;time.time=1.1;FixturePlayerView *view=[FixturePlayerView new];YTMainAppVideoPlayerOverlayView *o=[YTMainAppVideoPlayerOverlayView new];FixtureBar *bar=[FixtureBar new];bar.durationLabel=[UILabel new];bar.durationLabel.text=@"2:00";o.playerBar=bar;view.overlayView=o;p.view=view;
    addEndTime(p,active,time);CHECK(dateCalls==0&&bar.endTimeString==nil);preferences[@"videoEndTime"]=@YES;speedRate=2;addEndTime(p,active,time);CHECK(dateInterval==60&&[bar.endTimeString isEqual:@"12:01 PM"]&&[bar.durationLabel.text isEqual:@"2:00 • 12:01 PM"]&&bar.durationLabel.fixtureFits==1);addEndTime(p,active,time);CHECK(bar.durationLabel.fixtureFits==1);
    preferences[@"24hrFormat"]=@YES;active.totalMediaTime=122.9;addEndTime(p,active,time);CHECK(dateInterval==61&&[bar.endTimeString isEqual:@"12:01"]&&bar.durationLabel.fixtureFits==1);bar.durationLabel.text=nil;addEndTime(p,active,time);CHECK(bar.durationLabel.text==nil&&bar.durationLabel.fixtureFits==2);view.overlayView=[NSObject new];Reset();addEndTime(p,active,time);CHECK(dateCalls==1&&![events containsObject:@"fit"]);
    active.totalMediaTime=1.5;time.time=-.5;speedRate=1;addEndTime(p,active,time);CHECK(dateInterval==3);active.totalMediaTime=NAN;time.time=0;addEndTime(p,active,time);CHECK(dateInterval==0);
    preferences[@"videoEndTime"]=@NO;preferences[@"shortsPlaybackIndex"]=@1;p.parentViewController=[YTShortsPlayerViewController new];active.totalMediaTime=10.9;time.time=10.1;Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==1);time.time=9.99;Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==0);active.totalMediaTime=.1;time.time=-.9;autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==0);time.time=.1;
    for(NSUInteger mask=0;mask<8;mask++){modernShorts=(mask&1)!=0;advanceShorts=(mask&2)!=0;FixturePanelShorts *parent=[FixturePanelShorts new];parent.isEngagementPanelVisible=(mask&4)!=0;p.parentViewController=parent;Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==(!modernShorts&&advanceShorts&&!parent.isEngagementPanelVisible));}
    modernShorts=NO;advanceShorts=YES;p.parentViewController=[YTShortsPlayerViewController new];double values[][2]={{NAN,0},{INFINITY,INFINITY},{-INFINITY,-INFINITY},{-INFINITY,INFINITY},{INFINITY,-INFINITY}};for(NSUInteger i=0;i<5;i++){time.time=values[i][0];active.totalMediaTime=values[i][1];Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==(i!=0&&i!=3));}
    for(NSNumber *mode in @[@0,@2]){preferences[@"shortsPlaybackIndex"]=mode;Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==0);}preferences[@"shortsPlaybackIndex"]=@1;p.parentViewController=[UIViewController new];Reset();autoSkipShortsLegacy(p,active,time);CHECK(advanceCalls==0);
    preferences[@"videoEndTime"]=@YES;preferences[@"shortsPlaybackIndex"]=@1;p.parentViewController=[YTShortsPlayerViewController new];view.overlayView=o;bar.durationLabel.text=@"duration";time.time=active.totalMediaTime=100;Reset();[p singleVideo:active currentVideoTimeDidChange:time];CHECK(originalCalls==1&&advanceCalls==1&&[events[0]isEqual:@"originalTime"]&&[events indexOfObject:@"fit"]<[events indexOfObject:@"advanceWithoutArgument"]);
    preferences[@"videoEndTime"]=@NO;
    preferences[@"shortsPlaybackIndex"]=@0;SEL selectors[]={@selector(singleVideo:currentVideoTimeDidChange:),@selector(potentiallyMutatedSingleVideo:currentVideoTimeDidChange:)};for(NSUInteger i=0;i<2;i++){Reset();((void(*)(id,SEL,id,id))objc_msgSend)(p,selectors[i],active,time);CHECK(originalCalls==1&&lastSelf==p&&lastSelector==selectors[i]&&arg1==active&&arg2==time);CHECK([events isEqual:@[@"originalTime",@"bool:videoEndTime",@"int:shortsPlaybackIndex"]]);}
}
static void TestDealloc(void){SetBaseline();Reset();recordDeallocation=YES;@autoreleasepool{YTPlayerViewController *p=Player();CHECK(p!=nil);}recordDeallocation=NO;CHECK(deallocated==1&&sleepCancels==1&&[events isEqual:@[@"cancelSleep",@"originalDealloc"]]);}
int main(void){@autoreleasepool{events=[NSMutableArray new];scheduled=[NSMutableArray new];preferenceReads=[NSMutableArray new];preferences=[NSMutableDictionary new];languageCodes=@[@"en",@"fr",@"de"];[NSTimeZone setDefaultTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];NSArray *added=@[@"restoreLoopMode",@"autoFullscreen",@"setAutoSpeed",@"selectCaptions",@"autoQuality",@"selectAudioTrack"];for(NSString *name in added)CHECK(!class_getInstanceMethod(YTPlayerViewController.class,NSSelectorFromString(name)));YTLInstallPlayerLifecycleHooks();for(NSString *name in added)CHECK(class_getInstanceMethod(YTPlayerViewController.class,NSSelectorFromString(name))!=NULL);TestActivation();TestLoopSpeed();TestQuality();TestCaptions();TestAudio();TestTimeHelpers();TestDealloc();printf("PASS: %lu actual PlayerLifecycle checks\n",(unsigned long)checks);}return 0;}
