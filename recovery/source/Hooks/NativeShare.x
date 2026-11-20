/* YouTube Native Share - An iOS Tweak to replace YouTube's share sheet and remove source identifiers.
 * Copyright (C) 2024 YouTube Native Share Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#import "NativeShareHost.h"

static NSString *YTLNativeShareMatch(NSString *description, NSString *pattern) {
    NSRegularExpression *regex=[NSRegularExpression regularExpressionWithPattern:pattern options:0 error:nil];
    NSTextCheckingResult *match=[regex firstMatchInString:description options:0 range:NSMakeRange(0,description.length)];
    return match ? [description substringWithRange:[match rangeAtIndex:1]] : nil;
}
static NSString *YTLNativeShareField(GPBUnknownFields *fields, int32_t number, NSString *format) {
    NSArray<GPBUnknownField *> *matches=[fields fields:number];
    if (matches.count!=1) return nil;
    NSString *identifier=[[NSString alloc] initWithData:matches.firstObject.lengthDelimited encoding:NSUTF8StringEncoding];
    return [NSString stringWithFormat:format,identifier];
}
static NSString *YTLNativeSharePlaylist(NSString *identifier) {
    if (![identifier hasPrefix:@"PL"] && ![identifier hasPrefix:@"FL"]) identifier=[identifier stringByAppendingString:@"&playnext=1"];
    return [@"https://youtube.com/playlist?list=" stringByAppendingString:identifier];
}
static BOOL YTLPresentNativeShare(NSString *serialized, UIView *fromView) {
    GPBMessage *message=[%c(GPBMessage) deserializeFromString:serialized];
    if (!message) return NO;
    GPBUnknownFields *fields=[[%c(GPBUnknownFields) alloc] initFromMessage:message];
    NSString *url=nil;
    if (!fields || fields.count==0) {
        NSString *description=message.description;
        const NSInteger numbers[]={3,6,2,1};
        NSArray<NSString *> *formats=@[@"https://youtube.com/channel/%@",@"https://youtube.com/post/%@",@"https://youtube.com/playlist?list=%@",@"https://youtube.com/watch?v=%@"];
        for (NSUInteger i=0;i<4;i++) {
            NSString *identifier=YTLNativeShareMatch(description,[NSString stringWithFormat:@"\\b%ld: \"([^\"]+)\"",(long)numbers[i]]);
            if (identifier) {
                if (numbers[i]==2 && ![identifier hasPrefix:@"PL"] && ![identifier hasPrefix:@"FL"]) identifier=[identifier stringByAppendingString:@"&playnext=1"];
                url=[NSString stringWithFormat:formats[i],identifier];
                break;
            }
        }
    } else {
        NSArray<GPBUnknownField *> *clips=[fields fields:8];
        if (clips.count==1) {
            GPBMessage *clip=[%c(GPBMessage) parseFromData:clips.firstObject.lengthDelimited error:nil];
            GPBUnknownFields *clipFields=[[%c(GPBUnknownFields) alloc] initFromMessage:clip];
            url=YTLNativeShareField(clipFields,1,@"https://youtube.com/clip/%@");
        }
        if (!url) url=YTLNativeShareField(fields,3,@"https://youtube.com/channel/%@");
        if (!url) url=YTLNativeShareField(fields,6,@"https://youtube.com/post/%@");
        if (!url) {
            NSString *playlist=YTLNativeShareField(fields,2,@"%@");
            if (playlist) url=YTLNativeSharePlaylist(playlist);
        }
        if (!url) {
            NSString *format=[fields fields:10].count ? @"https://youtube.com/shorts/%@" : @"https://youtube.com/watch?v=%@";
            url=YTLNativeShareField(fields,1,format);
        }
    }
    if (!url) return NO;
    UIActivityViewController *activity=[[UIActivityViewController alloc] initWithActivityItems:@[url] applicationActivities:nil];
    activity.excludedActivityTypes=@[UIActivityTypeAssignToContact,UIActivityTypePrint];
    UIViewController *presenter=[%c(YTUIUtils) topViewControllerForPresenting];
    if (activity.popoverPresentationController) {
        if (fromView) {
            activity.popoverPresentationController.sourceView=fromView;
            activity.popoverPresentationController.sourceRect=[fromView convertRect:fromView.bounds toView:presenter.view];
        } else {
            activity.popoverPresentationController.sourceView=presenter.view;
            CGFloat width=UIScreen.mainScreen.bounds.size.width;
            CGFloat height=UIScreen.mainScreen.bounds.size.height;
            activity.popoverPresentationController.sourceRect=CGRectMake(width*0.5,height,0,0);
        }
    }
    [presenter presentViewController:activity animated:YES completion:nil];
    return YES;
}
%group YTLNativeShare
%hook ELMPBShowActionSheetCommand
- (void)executeWithCommandContext:(id<YTLNativeShareCommandContext>)context handler:(id)handler {
    if (![[[NSUserDefaults alloc] initWithSuiteName:@"com.dvntm.ytlite"] boolForKey:@"nativeShare"]) { %orig; return; }
    NSString *serialized=YTLNativeShareMatch(self.description,@"serialized_share_entity: \"([^\"]+)\"");
    if (!serialized) { %orig; return; }
    UIView *view=nil;
    if ([context.context respondsToSelector:@selector(fromView)]) view=context.context.fromView;
    if (!YTLPresentNativeShare(serialized,view)) %orig;
}
%end
%hook YTShareEntityEndpointCommandHandler
- (void)executeWithCommand:(id)command entry:(id)entry fromView:(UIView *)view sender:(id)sender {
    if (![[[NSUserDefaults alloc] initWithSuiteName:@"com.dvntm.ytlite"] boolForKey:@"nativeShare"]) { %orig; return; }
    NSString *serialized=YTLNativeShareMatch([command description],@"serialized_share_entity: \"([^\"]+)\"");
    if (!serialized || !YTLPresentNativeShare(serialized,view)) %orig;
}
%end
%end
void YTLInstallNativeShareHooks(void) { %init(YTLNativeShare); }
