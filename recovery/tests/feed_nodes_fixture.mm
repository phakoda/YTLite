#import <objc/runtime.h>
#import "../source/Hooks/FeedNodesHost.h"
#import "../source/Hooks/FeedNodesHelpers.h"
#import "../source/Runtime/YTLFeaturePolicy.h"
static NSUInteger checks, frameCalls, yogaCalls, deaths;
static NSArray *lastChildren;
static CGRect lastFrame;
static NSMutableDictionary *prefs;
#define CHECK(v) do { checks++; if(!(v)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#v);exit(1);} }while(0)
BOOL ytpBool(NSString *key) {return [prefs[key] boolValue];}
NSInteger ytpInt(NSString *key) {return [prefs[key] integerValue];}
@implementation UIViewController @end
@implementation ASDisplayNode
- (void)setYogaChildren:(NSArray *)children { yogaCalls++;lastChildren=children; }
- (void)setFrame:(CGRect)value {frameCalls++;lastFrame=value;_frame=value;}
- (void)dealloc { deaths++; }
@end
@implementation ELMNodeController @end
@implementation ASTextNode @end
@implementation ELMExpandableTextNode @end
@interface YTSectionListViewController ()
@property(nonatomic, copy) NSString *browseId;
@end
@implementation YTSectionListViewController @end
@interface NamedNode : ASDisplayNode
@property(nonatomic,copy) NSString *fixtureDescription;
@end
@implementation NamedNode
- (NSString *)description {return self.fixtureDescription;}
@end
@interface NoAttributeText : ASTextNode @end
@implementation NoAttributeText
- (BOOL)respondsToSelector:(SEL)selector {if(selector==@selector(attributedText))return NO;return [super respondsToSelector:selector];}
- (NSAttributedString *)attributedText {CHECK(NO);return nil;}
@end
static ASDisplayNode *node(NSString *name) {ASDisplayNode *n=[ASDisplayNode new];n.accessibilityIdentifier=name;return n;}
static NamedNode *container(NSString *name) {NamedNode *n=[NamedNode new];n.fixtureDescription=name;n.copiedComment=@"old";return n;}
static void checkProperties(void) {
    for(NSString *name in @[@"copiedComment",@"copiedURL"]) {
        objc_property_t property=class_getProperty([ASDisplayNode class],name.UTF8String);CHECK(property!=NULL);
        const char *expected=[name isEqual:@"copiedComment"]?"T@\"NSString\",&,N":"T@\"NSURL\",&,N";
        CHECK(strcmp(property_getAttributes(property),expected)==0);
    }
    ASDisplayNode *n=[ASDisplayNode new];CHECK(n.copiedComment==nil);CHECK(n.copiedURL==nil);
    __weak id retainedText,retainedURL;
    @autoreleasepool {
        NSMutableString *text=[NSMutableString stringWithString:@"before"];retainedText=text;n.copiedComment=text;
        [text appendString:@" after"];CHECK([n.copiedComment isEqual:@"before after"]);CHECK(n.copiedComment==text);
        NSURL *url=[NSURL URLWithString:@"https://example.invalid/image"];retainedURL=url;n.copiedURL=url;CHECK(n.copiedURL==url);
    }
    CHECK(retainedText!=nil);CHECK(retainedURL!=nil);n.copiedComment=nil;n.copiedURL=nil;CHECK(retainedText==nil);CHECK(retainedURL==nil);
}
static void checkYoga(void) {
    ASDisplayNode *owner=[ASDisplayNode new];NSArray *input=@[node(@"id.reel_like_button")];
    [owner setYogaChildren:input];CHECK(lastChildren==input);
    ELMNodeController *controller=[ELMNodeController new];owner.controller=controller;controller.owningComponent=@"unrelated";
    [owner setYogaChildren:input];CHECK(lastChildren==input);
    NSArray *ids=@[@"id.reel_like_button",@"id.reel_dislike_button",@"id.reel_comment_button",@"id.reel_share_button",@"id.reel_remix_button",@"id.reel_pivot_button"];
    NSArray *keys=@[@"shortsNoLike",@"shortsNoDislike",@"shortsNoComment",@"shortsNoShare",@"shortsNoRemix",@"shortsNoAudioButton"];
    for(NSString *component in @[@"shorts_action_bar.eml",@"reel_action_bar.eml"]) {
        controller.owningComponent=component;owner=[ASDisplayNode new];owner.controller=controller;
        NSMutableArray *nodes=[NSMutableArray array];for(NSString *identifier in ids)[nodes addObject:node(identifier)];[nodes addObject:node(@"ordinary")];
        for(NSUInteger mask=0;mask<64;mask++) {
            for(NSUInteger i=0;i<6;i++)prefs[keys[i]]=@((mask>>i)&1);
            NSUInteger calls=yogaCalls;[owner setYogaChildren:nodes];CHECK(yogaCalls==calls+1);CHECK(lastChildren!=nodes);CHECK(![lastChildren isKindOfClass:[NSMutableArray class]]);
            NSUInteger offset=0;for(NSUInteger i=0;i<6;i++)if(!((mask>>i)&1)){CHECK(lastChildren[offset]==nodes[i]);offset++;}
            CHECK(lastChildren[offset]==nodes[6]);CHECK(lastChildren.count==offset+1);CHECK(nodes.count==7);
        }
        prefs[@"shortsNoLike"]=@YES;[owner setYogaChildren:nodes];NSArray *filtered=lastChildren;
        prefs[@"shortsNoLike"]=@NO;[owner setYogaChildren:filtered];CHECK([lastChildren containsObject:nodes[0]]);
        ASDisplayNode *replacement=node(ids[0]);[owner setYogaChildren:@[replacement]];CHECK(lastChildren[0]==replacement);CHECK(![lastChildren containsObject:nodes[0]]);
    }
    [prefs removeAllObjects];
    controller.owningComponent=@"shorts_action_bar.eml";owner=[ASDisplayNode new];owner.controller=controller;
    ASDisplayNode *unknown=node(nil);[owner setYogaChildren:@[unknown]];CHECK(lastChildren.count==1);
    [owner setYogaChildren:@[unknown]];CHECK(lastChildren.count==2);CHECK(lastChildren[0]==unknown);CHECK(lastChildren[1]==unknown);
    __weak ASDisplayNode *weakOwner;__weak ASDisplayNode *weakChild;
    NSUInteger before=deaths;
    @autoreleasepool {ASDisplayNode *temporary=[ASDisplayNode new];temporary.controller=controller;ASDisplayNode *child=node(@"weak-key-test");weakOwner=temporary;weakChild=child;[temporary setYogaChildren:@[child]];lastChildren=nil;}
    CHECK(weakOwner==nil);CHECK(weakChild==nil);CHECK(deaths>=before+2);
}
static void checkText(void) {
    CGRect frame=CGRectMake(-12,34,567,89);
    for(NSUInteger mode=0;mode<4;mode++) {
        prefs[@"commentManager"]=@(mode&1);prefs[@"postManager"]=@((mode>>1)&1);
        ASTextNode *text=[ASTextNode new];text.accessibilityIdentifier=@"id.comment.content.label";text.attributedText=[[NSAttributedString alloc]initWithString:@"hello 😀"];
        NamedNode *comment=container(@"prefix id.ui.comment_cell suffix"),*other=container(@"unrelated");
        text.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[text.supernodes addObject:other];[text.supernodes addObject:comment];
        NSUInteger calls=frameCalls;[text setFrame:frame];CHECK(frameCalls==calls+1);CHECK(CGRectEqualToRect(lastFrame,frame));CHECK([comment.copiedComment isEqual:mode&1?@"hello 😀":@"old"]);CHECK([other.copiedComment isEqual:@"old"]);
        ELMExpandableTextNode *post=[ELMExpandableTextNode new];post.currentTextNode=text;NamedNode *postContainer=container(@"id.ui.backstage.original_post");post.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[post.supernodes addObject:postContainer];
        [post setFrame:frame];CHECK([postContainer.copiedComment isEqual:mode&2?@"hello 😀":@"old"]);
        text.accessibilityIdentifier=@"unrelated";comment.copiedComment=@"old";[text setFrame:frame];CHECK([comment.copiedComment isEqual:@"old"]);
        post.currentTextNode=[ASDisplayNode new];postContainer.copiedComment=@"old";[post setFrame:frame];CHECK([postContainer.copiedComment isEqual:@"old"]);
    }
    prefs[@"commentManager"]=@YES;prefs[@"postManager"]=@YES;
    for(ASTextNode *text in @[[ASTextNode new],[NoAttributeText new]]) {
        text.accessibilityIdentifier=@"id.comment.content.label";NamedNode *target=container(@"id.ui.comment_cell");text.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[text.supernodes addObject:target];[text setFrame:frame];CHECK([target.copiedComment isEqual:@"old"]);
        ELMExpandableTextNode *post=[ELMExpandableTextNode new];post.currentTextNode=text;NamedNode *postTarget=container(@"id.ui.backstage.original_post");post.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[post.supernodes addObject:postTarget];[post setFrame:frame];CHECK([postTarget.copiedComment isEqual:@"old"]);
    }
    ASTextNode *empty=[ASTextNode new];empty.accessibilityIdentifier=@"id.comment.content.label";empty.attributedText=[[NSAttributedString alloc]initWithString:@""];NamedNode *target=container(@"id.ui.comment_cell");empty.supernodes=[NSHashTable hashTableWithOptions:NSPointerFunctionsStrongMemory];[empty.supernodes addObject:target];[empty setFrame:frame];CHECK([target.copiedComment isEqual:@""]);
}
static void checkHelpers(void) {
    NSArray *ads=@[@"brand_promo",@"brand_video_shelf",@"carousel_footered_layout",@"carousel_headered_layout",@"eml.expandable_metadata",@"feed_ad_metadata",@"full_width_portrait_image_layout",@"full_width_square_image_layout",@"landscape_image_wide_button_layout",@"post_shelf",@"product_carousel",@"product_engagement_panel",@"product_item",@"shopping_carousel",@"shopping_item_card_list",@"statement_banner",@"square_image_layout",@"text_image_button_layout",@"text_search_ad",@"video_display_full_layout",@"video_display_full_buttoned_layout",@"grid_ads",@"grid_ads_image_layout"];
    CHECK(getAdString(nil)==nil);CHECK(getAdString(@"regular video")==nil);
    for(NSString *ad in ads)CHECK([getAdString([@"prefix " stringByAppendingString:ad]) isEqual:[ad isEqual:@"grid_ads_image_layout"]?@"grid_ads":ad]);
    CHECK([getAdString(@"grid_ads brand_promo") isEqual:@"brand_promo"]);
    YTSectionListViewController *controller=[YTSectionListViewController new];
    for(NSUInteger mask=0;mask<4;mask++) {
        prefs[@"hideShorts"]=@(mask&1);prefs[@"keepSubsShorts"]=@((mask>>1)&1);
        for(NSString *marker in @[@"shorts_shelf",@"shorts_video_cell",@"history-shorts-shelf-item",@"#shorts"]) {
            CHECK(isShorts(marker,nil)==(BOOL)(mask&1));CHECK(!isShorts([@"history* " stringByAppendingString:marker],nil));
            controller.browseId=@"FEsubscriptions";CHECK(isShorts(marker,controller)==(BOOL)((mask&1)&&!(mask&2)));
            controller.browseId=@"FEwhat_to_watch";CHECK(isShorts(marker,controller)==(BOOL)(mask&1));
        }
        CHECK(!isShorts(nil,controller));CHECK(!isShorts(@"ordinary",controller));
    }
    CHECK(innertubeName(nil)==nil);CHECK(innertubeName(@"none")==nil);CHECK([innertubeName(@"😀 (main: example.eml) tail") isEqual:@"example.eml"]);
    CHECK([innertubeName(@"(Innertube-Resources: one) (main: two)") isEqual:@"one"]);CHECK(innertubeName(@"main: )")==nil);CHECK(innertubeName(@"main: unfinished")==nil);
}
int main(void) {@autoreleasepool {prefs=[NSMutableDictionary dictionary];CHECK(class_getProperty([ASDisplayNode class],"copiedComment")==NULL);YTLInstallFeedNodesHooks();checkProperties();checkYoga();checkText();checkHelpers();printf("PASS: %lu actual FeedNodes checks\n",(unsigned long)checks);}return 0;}
