#pragma once
#import <UIKit/UIKit.h>
@protocol WKNavigationDelegate <NSObject> @end
@interface WKNavigation : NSObject @end
@interface WKWebView : UIView
@property(nonatomic,weak) id<WKNavigationDelegate> navigationDelegate;
@property(nonatomic,strong) UIScrollView *scrollView;
@property(nonatomic,strong) NSURLRequest *recoveredRequest;
- (WKNavigation *)loadRequest:(NSURLRequest *)request;
@end
