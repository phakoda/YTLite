#import "YTPAPIHelper.h"
@implementation YTPAPIHelper
// 0x1ca6dc and completion 0x1cb938, closed extraction 0x1cc6fc–0x1cc948.
+ (void)fetchChannelImageWithChannelID:(NSString *)channelID completion:(void (^)(NSURL *url))completion {
    NSString *endpoint = @"https://youtubei.googleapis.com/youtubei/v1/browse?key=AIzaSyA8eiZmM1FaDVjRy-df2KTyQ_vz_yYM39w";
    NSDictionary *body = @{@"context": @{@"client": @{@"clientName": @"WEB", @"clientVersion": @"2.20240201.10.00"}}, @"browseId": channelID};
    NSError *error = nil;
    NSData *data = [NSJSONSerialization dataWithJSONObject:body options:0 error:&error];
    if (error) {
        NSLog(@"YTP --- Serialization issue: %@", error.localizedDescription);
        completion(nil);
        return;
    }
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:endpoint]];
    request.HTTPMethod = @"POST";
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    request.HTTPBody = data;
    NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData *responseData, NSURLResponse *response, NSError *requestError) {
        (void)response;
        if (requestError) {
            NSLog(@"YTP --- Request failed: %@", requestError.localizedDescription);
            completion(nil);
            return;
        }
        NSError *parseError = nil;
        id json = [NSJSONSerialization JSONObjectWithData:responseData options:0 error:&parseError];
        if (parseError) {
            NSLog(@"YTP --- Failed to fetch: %@", parseError.localizedDescription);
            completion(nil);
            return;
        }
        // No cardinality/type guards in the original; index 1 is deliberate.
        NSString *urlString = json[@"header"][@"pageHeaderRenderer"][@"content"][@"pageHeaderViewModel"]
            [@"image"][@"decoratedAvatarViewModel"][@"avatar"][@"avatarViewModel"][@"image"][@"sources"][1][@"url"];
        if (!urlString) NSLog(@"YTP --- Pfp not found");
        completion(urlString ? [NSURL URLWithString:urlString] : nil);
    }];
    [task resume];
}
@end
