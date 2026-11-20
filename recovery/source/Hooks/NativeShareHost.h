#pragma once
#import <UIKit/UIKit.h>
@interface GPBMessage : NSObject
+ (instancetype)deserializeFromString:(NSString *)string;
+ (instancetype)parseFromData:(NSData *)data error:(NSError **)error;
@end
@interface GPBUnknownField : NSObject
@property(nonatomic,readonly) NSData *lengthDelimited;
@end
@interface GPBUnknownFields : NSObject
- (instancetype)initFromMessage:(GPBMessage *)message;
- (NSUInteger)count;
- (NSArray<GPBUnknownField *> *)fields:(int32_t)fieldNumber;
@end
@interface YTUIUtils : NSObject
+ (UIViewController *)topViewControllerForPresenting;
@end
@protocol YTLNativeShareContext <NSObject>
- (UIView *)fromView;
@end
@protocol YTLNativeShareCommandContext <NSObject>
- (id<YTLNativeShareContext>)context;
@end
@interface ELMPBShowActionSheetCommand : GPBMessage
- (void)executeWithCommandContext:(id<YTLNativeShareCommandContext>)context handler:(id)handler;
@end
@interface YTShareEntityEndpointCommandHandler : NSObject
- (void)executeWithCommand:(id)command entry:(id)entry fromView:(UIView *)view sender:(id)sender;
@end
FOUNDATION_EXPORT void YTLInstallNativeShareHooks(void);
