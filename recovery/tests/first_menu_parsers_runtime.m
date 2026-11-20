#import "downloads_doubles.h"
#import "../source/Downloads/DownloadMenuHelper.h"
static NSUInteger checks,failures;
static NSMutableArray *trace;
static void Check(BOOL ok,NSString *label){++checks;if(!ok){++failures;fprintf(stderr,"FAIL %s\n",label.UTF8String);}}
static void Equal(id actual,id expected,NSString *label){Check(actual==expected||[actual isEqual:expected],[NSString stringWithFormat:@"%@: %@ versus %@",label,actual,expected]);}
@interface ParserArray : NSObject
@property(nonatomic,strong) NSArray *values;
@property(nonatomic,copy) NSString *label;
@end
@interface ParserString : NSObject
@property(nonatomic,copy) NSString *value;
@property(nonatomic,copy) NSString *label;
@end
static ParserString *String(NSString *value,NSString *label){ParserString *s=[ParserString new];s.value=value;s.label=label;return s;}
@implementation ParserArray
- (id)firstObject{[trace addObject:[self.label stringByAppendingString:@".first"]];return self.values.firstObject;}
- (id)objectAtIndexedSubscript:(NSUInteger)index{[trace addObject:[NSString stringWithFormat:@"%@.index:%lu",self.label,(unsigned long)index]];return self.values[index];}
@end
@implementation ParserString
- (NSString *)description{return self.value;}
- (NSRange)rangeOfString:(NSString *)separator{[trace addObject:[NSString stringWithFormat:@"%@.range:%@",self.label,separator]];return [self.value rangeOfString:separator];}
- (id)substringFromIndex:(NSUInteger)index{[trace addObject:[NSString stringWithFormat:@"%@.substring:%lu",self.label,(unsigned long)index]];return String([self.value substringFromIndex:index],[self.label stringByAppendingString:@".tail"]);}
- (id)componentsSeparatedByString:(NSString *)separator{
    [trace addObject:[NSString stringWithFormat:@"%@.split:%@",self.label,separator]];
    NSMutableArray *values=[NSMutableArray array];NSUInteger index=0;
    for(NSString *part in [self.value componentsSeparatedByString:separator])
        [values addObject:String(part,[NSString stringWithFormat:@"%@.%lu",self.label,(unsigned long)index++])];
    ParserArray *result=[ParserArray new];result.values=values;result.label=[self.label stringByAppendingString:@".parts"];return result;
}
- (NSInteger)integerValue{[trace addObject:[self.label stringByAppendingString:@".integer"]];return self.value.integerValue;}
@end
static void Quality(DownloadMenuHelper *menu,id input,long long expected){
    @try{Check([menu getResoForQuality:input]==expected,[NSString stringWithFormat:@"quality %@ -> %lld",input,expected]);}
    @catch(NSException *error){Check(NO,[NSString stringWithFormat:@"quality unexpectedly raised %@",error.name]);}
}
static void Mime(DownloadMenuHelper *menu,id input,id expected){
    @try{Equal([menu detailForMimeType:input],expected==NSNull.null?nil:expected,[NSString stringWithFormat:@"MIME %@",input]);}
    @catch(NSException *error){Check(NO,[NSString stringWithFormat:@"MIME unexpectedly raised %@ for %@",error.name,input]);}
}
int main(void){@autoreleasepool{
    DownloadsInstallDoubles();trace=[NSMutableArray array];DownloadMenuHelper *menu=[DownloadMenuHelper new];
    NSArray *qualities=@[@[@"",@0],@[@"144p",@144],@[@"1080p60",@1080],@[@"2160p HDR",@2160],
        @[@"p1080",@0],@[@"abc",@0],@[@"72x",@72],@[@" 1080p",@1080],@[@"+144p",@144],
        @[@"-144p",@(-144)],@[@"\t+2160p",@2160],@[@"1080.5p",@1080],@[@"1080P60",@1080],
        @[@"1p2p3",@1],@[@"9223372036854775807p",@(LLONG_MAX)],@[@"-9223372036854775808p",@(LLONG_MIN)],
        @[@"4294967297p",@4294967297LL],@[@"0x100p",@0],@[@"\n  144p",@0]];
    for(NSArray *row in qualities)Quality(menu,row[0],[row[1] longLongValue]);Quality(menu,nil,0);
    // A selector-only boundary records the binary's split/index/integer sequence.
    Quality(menu,String(@"+720p60",@"quality"),720);
    Equal(trace,(@[@"quality.split:p",@"quality.parts.index:0",@"quality.0.integer"]),@"quality selector sequence with no length guard");
    NSArray *mimes=@[
        @[@"video/mp4; codecs=\"avc1.640028\"",@"mp4 • avc1"],
        @[@"video/webm; codecs=\"VP9.00\"",@"webm • VP9"],
        @[@"audio/mp4; codecs=\"mp4a.40.2\"",@"mp4 • mp4a"],
        @[@"video/mp4; codecs=\"avc1\"",@"mp4 • avc1"],
        @[@"video/mp4; codecs=\"avc1\"junk.2",@"mp4 • avc1"],
        @[@"video/foo/bar; codecs=\"vp9\"",@"foo/bar • vp9"],
        @[@"prefix;video/mp4; codecs=\"vp9\"",@"mp4 • vp9"],
        @[@"video/mp4; codecs=\"\"",@"mp4 • "],
        @[@"video/; codecs=\"vp9\"",@" • vp9"],
        @[@"video/mp4; codecs=\"avc1",@"mp4 • avc1"],
        @[@"video/mp4; codecs=\"vp9, opus\"",@"mp4 • vp9, opus"],
        @[@"video/mp4; codecs=\".bad\"",@"mp4 • "],
        @[@"video/mp4; codecs=\"vp9\"; codecs=\"avc1\"",@"mp4 • vp9"],
        @[@"video/mp4; codecs=\" VP9 \"",@"mp4 •  VP9 "],
        @[@"video/mp4 codecs=\"avc1\"",@"mp4 codecs=\"avc1\" • avc1"],
        @[@"",NSNull.null],@[@"broken",NSNull.null],@[@"video/mp4",NSNull.null],
        @[@"video/mp4; CODECS=\"vp9\"",NSNull.null],@[@"broken; codecs=\"vp9\"",NSNull.null]];
    for(NSArray *row in mimes)Mime(menu,row[0],row[1]);Mime(menu,nil,nil);
    [trace removeAllObjects];Mime(menu,String(@"v/mp4; codecs=\"avc1.4\"",@"mime"),@"mp4 • avc1");
    Equal(trace,(@[@"mime.range:/",@"mime.substring:2",@"mime.tail.split:;",@"mime.tail.parts.first",
        @"mime.range:codecs=\"",@"mime.substring:15",@"mime.tail.split:\"",@"mime.tail.parts.first",
        @"mime.tail.0.split:.",@"mime.tail.0.parts.first"]),@"MIME selector sequence and substring offsets");
    [trace removeAllObjects];Mime(menu,String(@"broken",@"mime"),nil);
    Equal(trace,(@[@"mime.range:/",@"mime.range:codecs=\""]),@"missing container still looks for codec");
    [trace removeAllObjects];Mime(menu,String(@"v/mp4",@"mime"),nil);
    Equal(trace,(@[@"mime.range:/",@"mime.substring:2",@"mime.tail.split:;",@"mime.tail.parts.first",@"mime.range:codecs=\""]),@"missing codec returns nil after container extraction");
    printf("%s First_menu_parsers: %lu assertions, %lu failures\n",failures?"FAIL":"PASS",(unsigned long)checks,(unsigned long)failures);return failures?1:0;
}}
