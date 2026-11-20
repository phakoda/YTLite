#import "SBManager.h"
#import "../Models/SBSegment.h"
#import <dispatch/dispatch.h>

@implementation SBManager

// 0x199848 and once block 0x1998fc. The first receiver determines allocation.
+ (instancetype)sharedManager {
    static SBManager *manager;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ manager = [[self alloc] init]; });
    return manager;
}

// -[SBManager init], 0x199940.
- (instancetype)init {
    self = [super init];
    if (self) {
        NSArray *categories = @[@"sponsor", @"intro", @"outro", @"interaction", @"selfpromo",
                                @"music_offtopic", @"preview", @"poi_highlight", @"filler"];
        NSData *json = [NSJSONSerialization dataWithJSONObject:categories options:0 error:NULL];
        NSString *text = [[NSString alloc] initWithData:json encoding:NSUTF8StringEncoding];
        _categories = [text stringByAddingPercentEncodingWithAllowedCharacters:
                       [NSCharacterSet URLQueryAllowedCharacterSet]];
        self.segments = [NSMutableDictionary dictionary];
    }
    return self;
}

// 0x19a168; completion 0x19a7c8. The previously truncated loop was checked
// against 0x19afc0..0x19b1cc. Invalid segments are omitted without reordering.
- (void)getSegmentsForID:(NSString *)videoID {
    if (videoID.length == 0) return;
    self.segments[videoID] = nil;
    NSString *urlString = [NSString stringWithFormat:
        @"https://sponsor.ajay.app/api/skipSegments?videoID=%@&categories=%@", videoID, _categories];
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:urlString]];
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:
        ^(NSData *data, NSURLResponse *response, NSError *error) {
        (void)response;
        if (!data || error) {
            NSLog(@"YTP --- Error fetching segments: %@", error);
            return;
        }
        id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];
        if (![json isKindOfClass:[NSArray class]]) {
            NSLog(@"YTP --- Unexpected JSON format for SB");
            return;
        }
        NSMutableArray<SBSegment *> *segments = [NSMutableArray array];
        for (id dictionary in json) {
            SBSegment *segment = [SBSegment segmentWithDictionary:dictionary];
            if (segment) [segments addObject:segment];
        }
        @synchronized (self.segments) {
            self.segments[videoID] = segments;
        }
    }] resume];
}

@end
