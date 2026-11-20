#import "DVNSupportersVC.h"
#import "SettingsContracts.h"

@implementation DVNSupportersVC
// 0x191f84. Web view bottom is the view's bottom, unlike its other safe-area edges.
- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = [@"SpecialThanks" ytl_localized];
    _webView = [WKWebView new];
    _webView.translatesAutoresizingMaskIntoConstraints = NO;
    _webView.navigationDelegate = self;
    _webView.opaque = NO;
    _webView.backgroundColor = UIColor.systemBackgroundColor;
    _webView.scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentAutomatic;
    [self.view addSubview:_webView];
    [NSLayoutConstraint activateConstraints:@[
        [_webView.topAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.topAnchor],
        [_webView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor],
        [_webView.leadingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.leadingAnchor],
        [_webView.trailingAnchor constraintEqualToAnchor:self.view.safeAreaLayoutGuide.trailingAnchor]
    ]];
    _activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
    _activityIndicator.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:_activityIndicator];
    [NSLayoutConstraint activateConstraints:@[
        [_activityIndicator.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [_activityIndicator.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor]
    ]];
    [_webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"https://dvntm.com/patreon/specialthanks"]]];
}

// 0x192ac0.
- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation {
    (void)webView; (void)navigation;
    [_activityIndicator startAnimating];
}

// 0x192b00.
- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    (void)webView; (void)navigation;
    [_activityIndicator stopAnimating];
}

// 0x192b40. A failure adds a new label; the original does not remove prior labels.
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error {
    (void)webView; (void)navigation;
    [_activityIndicator stopAnimating];
    UILabel *label = [UILabel new];
    label.text = error.localizedDescription;
    label.textColor = UIColor.secondaryLabelColor;
    label.textAlignment = NSTextAlignmentCenter;
    label.numberOfLines = 0;
    label.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:label];
    [NSLayoutConstraint activateConstraints:@[
        [label.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor],
        [label.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor],
        [label.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:32],
        [label.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-32]
    ]];
}
// ARC synthesizes the original .cxx_destruct (0x192fa4) for the two strong ivars.
@end
