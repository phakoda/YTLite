#pragma once
#import "presentation_doubles.h"
#import "../source/Presentation/ToastView.h"
#import "../source/Presentation/ToastManager.h"
#include <math.h>

FOUNDATION_EXPORT NSUInteger PresentationAssertions;
FOUNDATION_EXPORT void PCheck(BOOL condition,NSString *message);
FOUNDATION_EXPORT void PEqual(id actual,id expected,NSString *message);
FOUNDATION_EXPORT void PNear(double actual,double expected,NSString *message);
FOUNDATION_EXPORT void PSettle(void);
FOUNDATION_EXPORT void PClearToasts(void);
FOUNDATION_EXPORT void PRunHelpers(void);
FOUNDATION_EXPORT NSURL *PFile(NSString *relative);
FOUNDATION_EXPORT void PWrite(NSURL *url,NSString *text);
FOUNDATION_EXPORT BOOL PExists(NSURL *url);
FOUNDATION_EXPORT NSDictionary *PLast(NSString *kind);

static inline id PGet(id object,NSString *key) { return [object valueForKey:key]; }
static inline void PSet(id object,NSString *key,id value) { [object setValue:value forKey:key]; }
