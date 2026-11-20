#import <Foundation/Foundation.h>

/// Checks own method sets, ABI encodings, property attributes, and optional
/// ivar layouts against the package. Returns the number of assertions checked.
FOUNDATION_EXPORT NSUInteger YTLAuditMetadata(NSString *metadataPath, NSArray<NSString *> *classNames, NSString *ivarPath);
