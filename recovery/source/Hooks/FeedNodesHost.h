#import <UIKit/UIKit.h>

@interface ASDisplayNode : NSObject
@property(nonatomic, strong) id controller;
@property(nonatomic, copy) NSString *accessibilityIdentifier;
@property(nonatomic, strong) NSHashTable *supernodes;
@property(nonatomic) CGRect frame;
- (void)setYogaChildren:(NSArray *)children;
@end
@interface ASDisplayNode (YTLRecoveredFeedProperties)
@property(nonatomic, strong) NSString *copiedComment;
@property(nonatomic, strong) NSURL *copiedURL;
@end
@interface ELMNodeController : NSObject
@property(nonatomic, strong) id owningComponent;
@end
@interface ASTextNode : ASDisplayNode
@property(nonatomic, strong) NSAttributedString *attributedText;
@end
@interface ELMExpandableTextNode : ASDisplayNode
@property(nonatomic, strong) ASDisplayNode *currentTextNode;
@end
@interface YTSectionListViewController : UIViewController
@end
FOUNDATION_EXPORT void YTLInstallFeedNodesHooks(void);
