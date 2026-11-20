#import "../source/Runtime/UIViewController+DVNPatreonContext.h"
@implementation UIWindow @end
@implementation UIView @end
@implementation UIViewController @end
int main(void) {@autoreleasepool {
    UIViewController *controller=[UIViewController new];
    if([controller presentationAnchorForWebAuthenticationSession:nil]!=nil)return 1;
    controller.view=[UIView new];
    if([controller presentationAnchorForWebAuthenticationSession:nil]!=nil)return 1;
    controller.view.window=[UIWindow new];
    if([controller presentationAnchorForWebAuthenticationSession:(id)[NSObject new]]!=controller.view.window)return 1;
    UIWindow *next=[UIWindow new];controller.view.window=next;
    if([controller presentationAnchorForWebAuthenticationSession:nil]!=next)return 1;
    puts("PASS: 4 actual category-anchor checks");
}return 0;}
