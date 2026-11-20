#pragma once
#import <Foundation/Foundation.h>
#include <sys/socket.h>
typedef const struct PresentationFixtureReachability *SCNetworkReachabilityRef;
typedef uint32_t SCNetworkReachabilityFlags;
FOUNDATION_EXPORT SCNetworkReachabilityRef SCNetworkReachabilityCreateWithAddress(CFAllocatorRef allocator,const struct sockaddr *address);
FOUNDATION_EXPORT Boolean SCNetworkReachabilityGetFlags(SCNetworkReachabilityRef reference,SCNetworkReachabilityFlags *flags);
