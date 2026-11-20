#import "FeedFilteringHost.h"
#import "FeedNodesHelpers.h"
#import "../Runtime/YTLFeaturePolicy.h"

static NSData *YTLFeedDividerData;

// Original 0xbf774, also called by the global predicate at 0xbf76c.
static BOOL YTLFeedProductCommand(id<YTLFeedCommand> command) {
    return ytpBool(@"noAds") && [command respondsToSelector:@selector(yt_showEngagementPanelEndpoint)] &&
        [[[[command yt_showEngagementPanelEndpoint] identifier] tag] isEqualToString:@"PAproduct_list"];
}
static BOOL YTLFeedCommunityPost(NSString *description) {
    return [description containsString:@"post_base_wrapper.eml"] ||
        [description containsString:@"image_post_root.eml"] ||
        [description containsString:@"images_post_root.eml"] ||
        [description containsString:@"images_post_root_slim.eml"] ||
        [description containsString:@"text_post_root.eml"] ||
        [description containsString:@"post_base_wrapper_slim.eml"];
}
// Original shelf-item predicate 0xc73e0 deliberately has fewer conditions than the section predicate.
static BOOL YTLFeedRemoveShelfItem(id item) {
    NSString *description = [item description];
    if (YTLFeedCommunityPost(description) && ![description containsString:@"FEpost_home"] && ytpBool(@"hideCommunityPosts")) return YES;
    if (([description containsString:@"news_shelf_inline_playback"] || [description containsString:@"horizontal_shelf.eml"]) && ytpBool(@"hideHorizontalFeeds")) return YES;
    if ([description containsString:@"yt_outline_radar_live_24pt"] && ytpBool(@"hideLiveInFeed")) return YES;
    if ([description containsString:@"&list="] && ytpBool(@"hideMixPlaylists")) return YES;
    if (([description containsString:@"horizontal_gaming_shelf.eml"] || [description containsString:@".com/playables/"]) && ytpBool(@"hidePlayables")) return YES;
    return NO;
}
static BOOL YTLFeedRemoveSection(id section, YTInnerTubeCollectionViewController *controller) {
    if ([section isKindOfClass:%c(YTIItemSectionRenderer)]) {
        YTIItemSectionRenderer *itemSection = section;
        id<YTLFeedElement> element = [[itemSection.contentsArray firstObject] elementRenderer];
        if (ytpBool(@"noAds") && [element respondsToSelector:@selector(hasCompatibilityOptions)] &&
            [element hasCompatibilityOptions] && [[element compatibilityOptions] hasAdLoggingData]) return YES;
        if (itemSection.contentsArray.count > 1) {
            NSString *secondAd = getAdString([[itemSection.contentsArray[1] elementRenderer] description]);
            BOOL noAds = ytpBool(@"noAds");
            if (secondAd && noAds) return YES;
        }
        NSString *description = [element description];
        NSString *ad = getAdString(description);
        BOOL noAds = ytpBool(@"noAds");
        if (ad && noAds) return YES;
        if (YTLFeedCommunityPost(description) && ![description containsString:@"FEpost_home"] && ytpBool(@"hideCommunityPosts")) return YES;
        if (([description containsString:@"news_shelf_inline_playback"] || [description containsString:@"horizontal_shelf.eml"]) &&
            [description containsString:@"FEwhat_to_watch"] && ytpBool(@"hideHorizontalFeeds")) return YES;
        if ([description containsString:@"yt_outline_radar_live_24pt"] &&
            ([description containsString:@"_live.jpg?"] || [description containsString:@"immersive_live_header.eml"] || [description containsString:@"live_frame.jpg?"]) &&
            [description containsString:@"FEwhat_to_watch"] && ytpBool(@"hideLiveInFeed")) return YES;
        if (([description containsString:@"mix-watch"] || [description containsString:@"home_vertical_feed_prominence_group_key"]) &&
            [description containsString:@"&list="] && ytpBool(@"hideMixPlaylists")) return YES;
        if (([description containsString:@"comment-item-section"] || [description containsString:@"spacing_cell.eml"]) && ytpBool(@"hideInlineComment")) return YES;
        if (([description containsString:@"community_guidelines.eml"] || [description containsString:@"channel_guidelines_entry_banner.eml"]) && ytpBool(@"hideGuidelines")) return YES;
        if ([description containsString:@"chips_shelf.eml"] && ![description containsString:@"video_lockup"] &&
            ![description containsString:@"shorts_video"] && ytpBool(@"hideMoreTopicsChip")) return YES;
        if (([description containsString:@"horizontal_gaming_shelf.eml"] || [description containsString:@".com/playables/"]) && ytpBool(@"hidePlayables")) return YES;
        return isShorts(description, [controller delegate]);
    }
    if ([section isKindOfClass:%c(YTIShelfRenderer)]) {
        NSMutableArray *items = [[[(YTIShelfRenderer *)section content] horizontalListRenderer] itemsArray];
        NSIndexSet *indexes = [items indexesOfObjectsPassingTest:^BOOL(id item, NSUInteger index, BOOL *stop) {
            return YTLFeedRemoveShelfItem(item);
        }];
        if (indexes.count) [items removeObjectsAtIndexes:indexes];
        return isShorts([section description], [controller delegate]);
    }
    return NO;
}
// The mapping snapshots objects before removal; removeObject: removes equal duplicates as well.
static void YTLFeedRemoveMappedChildren(NSMutableArray *children, NSArray<NSString *> *keys) {
    NSMutableArray *mapping = [NSMutableArray array];
    for (NSUInteger index = 0; index < keys.count; index++)
        [mapping addObject:@{@"bool":keys[index], @"element":children[index]}];
    for (NSDictionary *entry in mapping)
        if (ytpBool(entry[@"bool"])) [children removeObject:entry[@"element"]];
}
static BOOL YTLFeedRemoveMetapanelChild(id<YTLFeedNode> node) {
    if ([[[[node controller] children] description] containsString:@"shorts_video_title_item.eml"]) return ytpBool(@"shortsNoDescription");
    if ([[[[node controller] children] description] containsString:@"participation_composer.eml"]) return ytpBool(@"shortsNoCommentBar");
    if ([[[[node controller] children] description] containsString:@"reel_multi_format_link.eml"]) return ytpBool(@"shortsNoSource");
    if ([[[[node controller] children] description] containsString:@"reel_sound_metadata.eml"]) return ytpBool(@"shortsNoAudio");
    if (node.yogaChildren.count == 1 && [[node.yogaChildren description] containsString:@"id.elements.components.suggested_action"])
        return ytpBool(@"shortsNoSuggestion");
    if (node.yogaChildren.count == 2) {
        id<YTLFeedNode> first = node.yogaChildren[0];
        if (ytpBool(@"shortsNoTitle") && [[first.yogaChildren description] containsString:@"decorated-avatar-id"]) return YES;
    }
    return NO;
}

%group YTLFeedFiltering
%hook YTWatchNextResponseViewController
- (void)loadWithModel:(id<YTLFeedWatchModel>)model {
    id<YTLFeedCommand> command = model.onUiReady;
    if ([command respondsToSelector:@selector(yt_commandExecutorCommand)]) {
        NSMutableArray *commands = [[command yt_commandExecutorCommand] commandsArray];
        NSIndexSet *indexes = [commands indexesOfObjectsPassingTest:^BOOL(id object, NSUInteger index, BOOL *stop) {
            return YTLFeedProductCommand(object);
        }];
        [commands removeObjectsAtIndexes:indexes];
    }
    if (YTLFeedProductCommand(command)) model.onUiReady = nil;
    %orig(model);
}
%end
%hook YTIElementRenderer
- (NSData *)elementData {
    if ([[self description] containsString:@"cell_divider"]) {
        if (!YTLFeedDividerData) YTLFeedDividerData = %orig;
        return YTLFeedDividerData;
    }
    if (YTLFeedDividerData && [self respondsToSelector:@selector(hasCompatibilityOptions)] &&
        [self hasCompatibilityOptions] && [[self compatibilityOptions] hasAdLoggingData]) return YTLFeedDividerData;
    return %orig;
}
%end
%hook YTInnerTubeCollectionViewController
- (void)addSectionsFromArray:(NSArray *)sections {
    NSMutableArray *filtered = [sections mutableCopy];
    NSIndexSet *indexes = [filtered indexesOfObjectsPassingTest:^BOOL(id section, NSUInteger index, BOOL *stop) {
        return YTLFeedRemoveSection(section, self);
    }];
    [filtered removeObjectsAtIndexes:indexes];
    %orig([filtered copy]);
}
%end
%hook YTICommand
- (id<YTLFeedEndpoint>)yt_showEngagementPanelEndpoint {
    id<YTLFeedEndpoint> endpoint = %orig;
    return [[endpoint description] containsString:@"mealbar_promo"] ? nil : endpoint;
}
%end
%hook YTICommandWrapperPromoRenderer
- (void)setHasPromoType:(BOOL)value { %orig(NO); }
- (void)setPromoType:(int32_t)value { %orig(0); }
- (void)setHasPromoCommand:(BOOL)value { %orig(NO); }
- (void)setPromoCommand:(id)value { %orig(nil); }
- (void)setHasWatchPageTriggerCondition:(BOOL)value { %orig(NO); }
- (void)setWatchPageTriggerCondition:(int32_t)value { %orig(0); }
- (NSMutableArray *)clientFrequencyCapConfigsArray { return [NSMutableArray array]; }
- (NSUInteger)clientFrequencyCapConfigsArray_Count { return 0; }
%end
%hook YTIPromoMessageSupportedRenderers
- (uint32_t)rendererOneOfCase { return 0; }
- (void)setHasCommandWrapperPromoRenderer:(BOOL)value { %orig(NO); }
- (void)setCommandWrapperPromoRenderer:(id)value { %orig(nil); }
- (void)setHasUpsellDialogRenderer:(BOOL)value { %orig(NO); }
- (void)setUpsellDialogRenderer:(id)value { %orig(nil); }
%end
%hook YTCommerceEventGroupHandler
- (void)addEventHandlers {}
%end
%hook YTInterstitialPromoEventGroupHandler
- (void)addEventHandlers {}
%end
%hook YTPromosheetEventGroupHandler
- (void)addEventHandlers {}
%end
%hook YTPromoThrottleController
- (BOOL)canShowThrottledPromo { return NO; }
- (BOOL)canShowThrottledPromoWithFrequencyCap:(id)cap { return NO; }
- (BOOL)canShowThrottledPromoWithFrequencyCaps:(id)caps { return NO; }
%end
%hook YTIShowFullscreenInterstitialCommand
- (BOOL)shouldThrottleInterstitial {
    if ([self hasModalClientThrottlingRules]) [[self modalClientThrottlingRules] setThrottledAfterRecentSignIn:YES];
    return %orig;
}
%end
%hook YTSurveyController
- (void)showSurveyWithRenderer:(id)renderer surveyParentResponder:(id)responder {}
%end
%hook YTPersonalizedSuggestionsCacheProvider
- (id)activeCache { return ytpBool(@"noSearchHistory") ? nil : %orig; }
%end
%hook ELMComponent
- (id<YTLFeedNode>)node {
    if ([[self description] containsString:@"default_product_sticker.eml"] && ytpBool(@"shortsNoProducts")) {
        id<YTLFeedNode> node = %orig;
        node.yogaChildren = @[];
        return node;
    }
    if ([[self description] containsString:@"shorts_action_bar.eml"] || [[self description] containsString:@"reel_action_bar.eml"]) {
        id<YTLFeedNode> node = %orig;
        NSMutableArray *children = [node.yogaChildren mutableCopy];
        if (children.count == 5) YTLFeedRemoveMappedChildren(children, @[@"shortsNoLike", @"shortsNoDislike", @"shortsNoComment", @"shortsNoShare", @"shortsNoRemix"]);
        node.yogaChildren = [children copy];
        return node;
    }
    if ([[self description] containsString:@"shorts_paused_state.eml"]) {
        id<YTLFeedNode> node = %orig;
        NSMutableArray *children = [node.yogaChildren mutableCopy];
        if (children.count == 3) YTLFeedRemoveMappedChildren(children, @[@"carouselNoSub", @"carouselNoLive", @"carouselNoShopping"]);
        if (children.count == 4) YTLFeedRemoveMappedChildren(children, @[@"carouselNoSub", @"carouselNoLive", @"carouselNoTrends", @"carouselNoShopping"]);
        node.yogaChildren = [children copy];
        return node;
    }
    BOOL metapanel = [[self description] containsString:@"reel_metapanel.eml"];
    id<YTLFeedNode> node = %orig;
    if (metapanel) {
        NSMutableArray *children = [NSMutableArray array];
        NSIndexSet *indexes = [node.yogaChildren indexesOfObjectsPassingTest:^BOOL(id<YTLFeedNode> child, NSUInteger index, BOOL *stop) {
            return YTLFeedRemoveMetapanelChild(child);
        }];
        [node.yogaChildren enumerateObjectsUsingBlock:^(id child, NSUInteger index, BOOL *stop) {
            if (![indexes containsIndex:index]) [children addObject:child];
        }];
        node.yogaChildren = [children copy];
    }
    return node;
}
%end
%end
void YTLInstallFeedFilteringHooks(void) { %init(YTLFeedFiltering); }
