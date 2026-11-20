#pragma once
#import <Foundation/Foundation.h>
@class UIView, CALayer, SBPlayerDecorationData;

@interface SBPlayerDecorator : NSObject
+ (void)addDurationWithoutSegments:(id)player videoController:(id)unusedController;
+ (BOOL)shouldDrawRoundedForBarView:(UIView *)barView;
+ (SBPlayerDecorationData *)_decorationDataForBarView:(UIView *)barView;
+ (void)drawSegmentsDecorationView:(UIView *)barView;
+ (void)drawSegmentsOnActiveDecorationView:(UIView *)barView;
+ (void)_drawSegmentsForData:(SBPlayerDecorationData *)data;
+ (void)drawSegments:(UIView *)barView layer:(CALayer *)layer playerVC:(id)player;
+ (void)drawSegmentableSegments:(UIView *)barView playerBar:(id)playerBar playerVC:(id)player;
@end
