#pragma once
#import <UIKit/UIKit.h>

// Shared first-launch state used by the packaged bootstrap and hooks.
FOUNDATION_EXPORT BOOL isYTPFirstTime;
FOUNDATION_EXPORT NSDictionary *(*orig_infoDictionary)(NSBundle *bundle, SEL selector);
FOUNDATION_EXPORT NSDictionary *replaceInfoDict(NSBundle *bundle, SEL selector);
FOUNDATION_EXPORT void YTLInstallBundleInfoHook(void);

@interface InitWorkaround : UIViewController
@property(nonatomic, copy) dispatch_block_t completion;
@end
