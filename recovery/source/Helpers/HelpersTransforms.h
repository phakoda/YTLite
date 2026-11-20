#pragma once
#import <Foundation/Foundation.h>
#include <math.h>

static inline unsigned long long YTLDownloadDurationSeconds(unsigned long long milliseconds) {
    // The original uses UCVTF / FDIV / FCVTPU, not truncating FCVTZU.
    return (unsigned long long)ceil((double)milliseconds / 1000.0);
}

static inline BOOL YTLIsSinglePathComponent(NSString *component) {
    return component.length > 0 && ![component isEqualToString:@"."] &&
        ![component isEqualToString:@".."] &&
        [component rangeOfCharacterFromSet:[NSCharacterSet characterSetWithCharactersInString:@"/\\\0"]].location == NSNotFound;
}

static inline NSString *YTLDownloadSanitizedTitle(NSString *title, NSCharacterSet *illegal) {
    return [[title componentsSeparatedByCharactersInSet:illegal] componentsJoinedByString:@""];
}

static inline NSURL *YTLDownloadDirectory(NSString *videoID) {
    if (!YTLIsSinglePathComponent(videoID)) return nil;
    return [[NSURL fileURLWithPath:NSTemporaryDirectory() isDirectory:YES]
        URLByAppendingPathComponent:videoID isDirectory:YES];
}

static inline NSURL *YTLDownloadImageURL(NSURL *url) {
    NSString *absolute = url.absoluteString;
    if ([absolute containsString:@"c-fcrop"]) {
        NSRange crop = [absolute rangeOfString:@"c-fcrop"];
        if (crop.location == NSNotFound) return nil;
        NSString *suffix = [absolute substringFromIndex:crop.location];
        return [NSURL URLWithString:[absolute stringByReplacingOccurrencesOfString:suffix withString:@"nd-v1"]];
    }
    return url;
}

static inline BOOL YTLReachabilityFlagsAreWiFi(BOOL readSucceeded, uint32_t flags) {
    return readSucceeded && (flags & 0x40002U) == 2;
}
