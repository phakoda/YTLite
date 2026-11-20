#pragma once
// Host-only declarations needed to parse the production ToastView header.
// The fixture supplies ToastView; these UIKit types are never instantiated.
#import <UIKit/UIKit.h>
@interface UIVisualEffectView : UIView @end
@class UILabel, UIProgressView, UIImageView, UIStackView, UIActivityIndicatorView;
@class NSLayoutConstraint, UIPanGestureRecognizer, UILongPressGestureRecognizer;
