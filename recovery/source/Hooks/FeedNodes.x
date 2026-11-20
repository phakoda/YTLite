#import "FeedNodesHost.h"
#import "../Runtime/YTLFeaturePolicy.h"

static NSMapTable<ASDisplayNode *, NSArray *> *YTLUnfilteredYogaChildren;

%group YTLFeedNodes
%hook ASDisplayNode
%property(nonatomic, retain) NSString *copiedComment;
%property(nonatomic, retain) NSURL *copiedURL;

- (void)setYogaChildren:(NSArray *)children {
    if (![self.controller isKindOfClass:%c(ELMNodeController)]) { %orig; return; }
    ELMNodeController *controller = self.controller;
    if (![[controller.owningComponent description] containsString:@"shorts_action_bar.eml"] &&
        ![[[(ELMNodeController *)self.controller owningComponent] description] containsString:@"reel_action_bar.eml"]) {
        %orig;
        return;
    }
    static dispatch_once_t once;
    dispatch_once(&once, ^{ YTLUnfilteredYogaChildren = [NSMapTable weakToStrongObjectsMapTable]; });
    NSDictionary *preferences = @{
        @"id.reel_like_button": @"shortsNoLike",
        @"id.reel_dislike_button": @"shortsNoDislike",
        @"id.reel_comment_button": @"shortsNoComment",
        @"id.reel_share_button": @"shortsNoShare",
        @"id.reel_remix_button": @"shortsNoRemix",
        @"id.reel_pivot_button": @"shortsNoAudioButton"
    };
    NSArray *cached = [YTLUnfilteredYogaChildren objectForKey:self];
    NSMutableArray *merged = [children mutableCopy];
    for (ASDisplayNode *cachedNode in cached) {
        NSString *identifier = cachedNode.accessibilityIdentifier;
        BOOL found = NO;
        for (ASDisplayNode *node in merged) {
            if ([node.accessibilityIdentifier isEqualToString:identifier]) { found = YES; break; }
        }
        if (!found) [merged addObject:cachedNode];
    }
    [YTLUnfilteredYogaChildren setObject:[merged copy] forKey:self];
    [merged filterUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(ASDisplayNode *node, NSDictionary *bindings) {
        NSString *key = preferences[node.accessibilityIdentifier];
        return key ? !ytpBool(key) : YES;
    }]];
    %orig([merged copy]);
}

- (void)dealloc {
    [YTLUnfilteredYogaChildren removeObjectForKey:self];
    %orig;
}

- (void)setFrame:(CGRect)frame {
    %orig;
    if (ytpBool(@"commentManager") &&
        [[self valueForKey:@"_accessibilityIdentifier"] isEqualToString:@"id.comment.content.label"] &&
        [self isKindOfClass:NSClassFromString(@"ASTextNode")]) {
        ASTextNode *textNode = (ASTextNode *)self;
        NSString *text = nil;
        if ([textNode respondsToSelector:@selector(attributedText)] && textNode.attributedText)
            text = textNode.attributedText.string;
        for (ASDisplayNode *container in self.supernodes.allObjects) {
            if ([container.description containsString:@"id.ui.comment_cell"] && text) {
                container.copiedComment = text;
                break;
            }
        }
    }
    if (ytpBool(@"postManager") && [self isKindOfClass:NSClassFromString(@"ELMExpandableTextNode")]) {
        ELMExpandableTextNode *expandable = (ELMExpandableTextNode *)self;
        if ([expandable.currentTextNode isKindOfClass:NSClassFromString(@"ASTextNode")]) {
            ASTextNode *textNode = (ASTextNode *)expandable.currentTextNode;
            NSString *text = nil;
            if ([textNode respondsToSelector:@selector(attributedText)] && textNode.attributedText)
                text = textNode.attributedText.string;
            for (ASDisplayNode *container in self.supernodes.allObjects) {
                if ([container.description containsString:@"id.ui.backstage.original_post"] && text) {
                    container.copiedComment = text;
                    break;
                }
            }
        }
    }
}
%end
%end
void YTLInstallFeedNodesHooks(void) { %init(YTLFeedNodes); }
