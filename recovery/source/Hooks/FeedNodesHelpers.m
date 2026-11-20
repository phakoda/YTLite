#import "FeedNodesHelpers.h"
#import "../Runtime/YTLFeaturePolicy.h"

NSString *getAdString(NSString *description) {
    NSArray<NSString *> *identifiers = @[
        @"brand_promo", @"brand_video_shelf", @"carousel_footered_layout", @"carousel_headered_layout",
        @"eml.expandable_metadata", @"feed_ad_metadata", @"full_width_portrait_image_layout",
        @"full_width_square_image_layout", @"landscape_image_wide_button_layout", @"post_shelf",
        @"product_carousel", @"product_engagement_panel", @"product_item", @"shopping_carousel",
        @"shopping_item_card_list", @"statement_banner", @"square_image_layout", @"text_image_button_layout",
        @"text_search_ad", @"video_display_full_layout", @"video_display_full_buttoned_layout",
        @"grid_ads", @"grid_ads_image_layout"
    ];
    for (NSString *identifier in identifiers) {
        if ([description containsString:identifier]) return identifier;
    }
    return nil;
}

BOOL isShorts(NSString *description, id controller) {
    if (!ytpBool(@"hideShorts")) return NO;
    if (![description containsString:@"shorts_shelf"] &&
        ![description containsString:@"shorts_video_cell"] &&
        ![description containsString:@"history-shorts-shelf-item"] &&
        ![description containsString:@"#shorts"]) return NO;
    if ([description containsString:@"history*"]) return NO;
    if ([controller isKindOfClass:NSClassFromString(@"YTSectionListViewController")] &&
        [[controller valueForKey:@"_browseId"] isEqualToString:@"FEsubscriptions"])
        return !ytpBool(@"keepSubsShorts");
    return YES;
}

NSString *innertubeName(NSString *description) {
    if (!description) return nil;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"(Innertube-Resources|main): ([^)]+)\\)"
                                                                          options:0 error:nil];
    NSTextCheckingResult *match = [regex firstMatchInString:description options:0 range:NSMakeRange(0, description.length)];
    if (match.numberOfRanges > 2) return [description substringWithRange:[match rangeAtIndex:2]];
    return nil;
}
