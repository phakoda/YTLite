#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface DVNSupportersVC : UIViewController <WKNavigationDelegate> {
    WKWebView *_webView;
    UIActivityIndicatorView *_activityIndicator;
}
@end
