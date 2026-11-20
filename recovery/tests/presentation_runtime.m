#import "presentation_test_support.h"
#import "../source/Presentation/BlurButton.h"
#import "../source/Presentation/CustomHUD.h"
#import "../source/Presentation/DVNImageViewController.h"
#import "../source/Presentation/DVNSheetPresenter.h"
#import "../source/Presentation/PseudoDetentController.h"
#import "../source/Presentation/PseudoDetentTransitioningDelegate.h"
#import "../source/Presentation/PlayerToast.h"
#import "../source/Presentation/ToastWindow.h"
#import "../source/Presentation/PresentationGeometry.h"
#import "../source/Presentation/PresentationHost.h"
#import <objc/message.h>
#include <pthread.h>

NSUInteger PresentationAssertions;
static NSMutableDictionary<NSString *,NSNumber *> *suiteCounts;
void PCheck(BOOL condition,NSString *message) {
    PresentationAssertions++;
    if(!condition){fprintf(stderr,"PRESENTATION/HELPERS TEST FAILED: %s\n",message.UTF8String);exit(3);}
}
void PEqual(id actual,id expected,NSString *message) {
    PCheck(actual==expected || [actual isEqual:expected],[NSString stringWithFormat:@"%@: %@ != %@",message,actual,expected]);
}
void PNear(double actual,double expected,NSString *message) {
    PCheck(isfinite(actual) && fabs(actual-expected)<=1e-6*MAX(1,fabs(expected)),
           [NSString stringWithFormat:@"%@: %.12g != %.12g",message,actual,expected]);
}
NSDictionary *PLast(NSString *kind) { return PresentationEventsOfKind(kind).lastObject[@"value"]; }
void PSettle(void) {
    for(NSUInteger i=0;i<3;i++){PresentationDrainMain();PresentationCompleteAnimations(YES);PresentationAdvanceTime(0);}
}
void PClearToasts(void) {
    PSettle();
    for(ToastView *toast in [[ToastManager sharedManager].toasts copy])[toast hideImmediately];
    PSettle();
    [ToastManager sharedManager].isFullscreen=NO;[ToastManager sharedManager].isPinnedTop=NO;
    [ToastManager sharedManager].offsetController=nil;
    [PresentationEvents removeAllObjects];
}
NSURL *PFile(NSString *relative) {
    NSString *path=[[PresentationFixtureRoot stringByAppendingPathComponent:relative] stringByStandardizingPath];
    PCheck([path hasPrefix:[PresentationFixtureRoot stringByAppendingString:@"/"]],@"fixture URL stays inside owned TMPDIR");
    return [NSURL fileURLWithPath:path];
}
void PWrite(NSURL *url,NSString *text) {
    PCheck([url.path hasPrefix:[PresentationFixtureRoot stringByAppendingString:@"/"]],@"synthetic file write containment");
    NSError *error=nil;
    [NSFileManager.defaultManager createDirectoryAtURL:url.URLByDeletingLastPathComponent withIntermediateDirectories:YES attributes:nil error:&error];
    PCheck(!error,@"synthetic parent directory");
    PCheck([[text dataUsingEncoding:NSUTF8StringEncoding] writeToURL:url options:NSDataWritingAtomic error:&error] && !error,@"synthetic text bytes, never real media");
}
BOOL PExists(NSURL *url) { return [NSFileManager.defaultManager fileExistsAtPath:url.path]; }
static void CheckRect(CGRect actual,CGRect expected,NSString *name) {
    PNear(actual.origin.x,expected.origin.x,[name stringByAppendingString:@" x"]);
    PNear(actual.origin.y,expected.origin.y,[name stringByAppendingString:@" y"]);
    PNear(actual.size.width,expected.size.width,[name stringByAppendingString:@" width"]);
    PNear(actual.size.height,expected.size.height,[name stringByAppendingString:@" height"]);
}
static NSLayoutConstraint *Constraint(UIView *view,NSString *kind,NSInteger relation) {
    for(NSLayoutConstraint *c in view.fixtureConstraints)
        if(c.firstAnchor.owner==view && [c.firstAnchor.kind isEqual:kind] && c.fixtureRelation==relation)return c;
    return nil;
}
static void *BackgroundEntry(void *context) {
    @autoreleasepool { dispatch_block_t block=(__bridge dispatch_block_t)context;block(); }
    return NULL;
}
static void Background(dispatch_block_t block) {
    dispatch_block_t copied=[block copy];pthread_t thread;
    PCheck(pthread_create(&thread,NULL,BackgroundEntry,(__bridge void *)copied)==0,@"fixture background thread starts");
    PCheck(pthread_join(thread,NULL)==0,@"fixture background thread joins before shared state inspection");
}
@interface PresentationActionTarget : NSObject
@property(nonatomic) NSUInteger calls;
- (void)fire:(id)sender;
@end
@implementation PresentationActionTarget
- (void)fire:(id)sender { PCheck(sender!=nil,@"button callback sender");_calls++; }
@end
@interface YTActionSheetDialogViewController : UIViewController @end
@implementation YTActionSheetDialogViewController @end
@interface YTBottomSheetController : UIViewController @end
@implementation YTBottomSheetController @end
@interface WelcomeVC : UIViewController @end
@implementation WelcomeVC @end
@interface YTTouchForwardingView : UIView @end
@implementation YTTouchForwardingView @end

// Inherited +initialize must install aliases for each concrete subclass.
@interface PresentationAliasToastWindow : ToastWindow @end
@implementation PresentationAliasToastWindow
- (BOOL)shouldAffectStatusBarAppearance { return YES; }
- (BOOL)canBecomeKeyWindow { return YES; }
@end
@interface PresentationAliasToastGrandchild : PresentationAliasToastWindow @end
@implementation PresentationAliasToastGrandchild
- (BOOL)shouldAffectStatusBarAppearance { return NO; }
- (BOOL)canBecomeKeyWindow { return NO; }
@end
@interface PresentationExistingAliasToastWindow : ToastWindow
- (BOOL)_canAffectStatusBarAppearance;
@end
@implementation PresentationExistingAliasToastWindow
- (BOOL)shouldAffectStatusBarAppearance { return YES; }
- (BOOL)canBecomeKeyWindow { return YES; }
- (BOOL)_canAffectStatusBarAppearance { return NO; }
- (BOOL)_canBecomeKeyWindow { return NO; }
@end
static BOOL OwnsMethod(Class cls,SEL selector) {
    unsigned int count=0;Method *methods=class_copyMethodList(cls,&count);BOOL found=NO;
    for(unsigned int i=0;i<count;i++)if(sel_isEqual(method_getName(methods[i]),selector)){found=YES;break;}
    free(methods);return found;
}
static void TestToastWindowInitialization(void) {
    SEL status=NSSelectorFromString(@"_canAffectStatusBarAppearance"),key=@selector(_canBecomeKeyWindow);
    ToastWindow *subclass=[PresentationAliasToastWindow new];Class cls=object_getClass(subclass);
    PCheck(OwnsMethod(cls,status)&&OwnsMethod(cls,key),@"inherited initialize adds both aliases directly to subclass");
    PCheck(((BOOL(*)(id,SEL))objc_msgSend)(subclass,status)&&[subclass _canBecomeKeyWindow],@"subclass aliases use overriding public implementations");
    for(NSArray *pair in @[@[NSStringFromSelector(status),@"shouldAffectStatusBarAppearance"],@[NSStringFromSelector(key),@"canBecomeKeyWindow"]]) {
        Method alias=class_getInstanceMethod(cls,NSSelectorFromString(pair[0]));
        Method public=class_getInstanceMethod(cls,NSSelectorFromString(pair[1]));
        PCheck(method_getImplementation(alias)==method_getImplementation(public),@"subclass alias shares exact public IMP");
        PCheck(strcmp(method_getTypeEncoding(alias),method_getTypeEncoding(public))==0,@"subclass alias copies original type encoding");
    }
    ToastWindow *grandchild=[PresentationAliasToastGrandchild new];Class child=object_getClass(grandchild);
    PCheck(OwnsMethod(child,status)&&OwnsMethod(child,key),@"grandchild receives its own aliases despite inherited aliases");
    PCheck(!((BOOL(*)(id,SEL))objc_msgSend)(grandchild,status)&&![grandchild _canBecomeKeyWindow],@"grandchild aliases follow its overriding public methods");
    Class existing=objc_getClass("PresentationExistingAliasToastWindow");
    IMP oldStatus=class_getMethodImplementation(existing,status),oldKey=class_getMethodImplementation(existing,key);
    ToastWindow *duplicate=[[existing alloc]init];
    PCheck(method_getImplementation(class_getInstanceMethod(existing,status))==oldStatus&&method_getImplementation(class_getInstanceMethod(existing,key))==oldKey,@"duplicate class_addMethod attempts preserve existing subclass aliases");
    PCheck(duplicate.shouldAffectStatusBarAppearance&&duplicate.canBecomeKeyWindow,@"duplicate fixture public overrides differ from its aliases");
    PCheck(!((BOOL(*)(id,SEL))objc_msgSend)(duplicate,status)&&![duplicate _canBecomeKeyWindow],@"existing aliases are not replaced by public overrides");
    Class base=ToastWindow.class;
    PCheck(method_getImplementation(class_getInstanceMethod(base,key))!=method_getImplementation(class_getInstanceMethod(base,@selector(canBecomeKeyWindow))),@"base duplicate key alias attempt preserves its compiled private method");
}

static void TestBlurAndHUD(void) {
    PresentationActionTarget *target=[PresentationActionTarget new];
    UIImage *image=[UIImage systemImageNamed:@"xmark"];
    BlurButton *button=[BlurButton createButtonWithImage:image target:target action:@selector(fire:) menu:nil];
    CheckRect(button.frame,CGRectMake(0,0,28,28),@"BlurButton frame");
    UIVisualEffectView *blur=(UIVisualEffectView *)button.subviews.firstObject;
    PNear(blur.layer.cornerRadius,14,@"BlurButton radius");PCheck(blur.effect.fixtureStyle==16,@"BlurButton material 16");
    PCheck(blur.clipsToBounds&&!blur.userInteractionEnabled,@"blur neither leaks corners nor intercepts touches");
    UIImageView *icon=PGet(button,@"_buttonImageView");PCheck(icon.image==image,@"button retains supplied image");
    PNear(icon.frame.size.width,18,@"button image width");PNear(icon.frame.size.height,18,@"button image height");
    PNear(icon.center.x,14,@"button icon center x");PNear(icon.center.y,14,@"button icon center y");
    [button setHighlighted:YES];PCheck(button.isHighlighted,@"highlight calls super");PNear(icon.alpha,.25,@"highlight opacity");
    [button setHighlighted:NO];PNear(icon.alpha,1,@"normal opacity");
    [button sendActionsForControlEvents:UIControlEventTouchUpInside];PCheck(target.calls==1,@"target selector forwarded");
    UIMenu *menu=[UIMenu menuWithTitle:@"fixture" children:@[]];
    BlurButton *menuButton=[BlurButton createButtonWithImage:image target:target action:@selector(fire:) menu:menu];
    PCheck(menuButton.menu==menu && menuButton.showsMenuAsPrimaryAction,@"menu ownership and primary presentation");
    PCheck(menuButton.fixtureTargets.count==0,@"menu does not also register target/action");
    __weak PresentationActionTarget *weakTarget;
    @autoreleasepool{PresentationActionTarget *ephemeral=[PresentationActionTarget new];weakTarget=ephemeral;
        [button addTarget:ephemeral action:@selector(fire:) forControlEvents:UIControlEventTouchUpInside];}
    PCheck(!weakTarget,@"UIButton target ownership remains weak in fixture");

    CustomHUD *hud=[CustomHUD new];PCheck(hud.controller!=nil,@"private volume controller allocated");
    hud.volumeLevel=.625f;PNear(hud.volumeLevel,.625,@"float volume getter/setter");
    PEqual(hud.volumeAudioCategory,@"Audio/Video",@"volume audio category forwarding");
    PCheck(hud.windowSceneForVolumeDisplay==UIApplication.sharedApplication.connectedScenes.anyObject,@"volume display scene");
    [hud addToController];PCheck([MPVolumeHUDController.sharedInstance.fixtureDisplays containsObject:hud],@"HUD display registered");
    [hud removeFromController];PCheck(![MPVolumeHUDController.sharedInstance.fixtureDisplays containsObject:hud],@"HUD display unregistered");
}

static void TestSheets(void) {
    UIViewController *presenter=UIApplication.sharedApplication.delegate.window.rootViewController;
    PresentationSheetController *content=[PresentationSheetController new];content._sections=@[@[@1,@2],@[@3]];
    UINavigationController *navigation=[[UINavigationController alloc]initWithRootViewController:content];
    PresentationNativeDetents=YES;
    [DVNSheetPresenter presentCustomHeightViewController:navigation fromViewController:presenter];
    UISheetPresentationController *sheet=navigation.sheetPresentationController;
    PCheck(navigation.modalPresentationStyle==UIModalPresentationPageSheet,@"native sheet style");
    PNear(sheet.detents.firstObject.fixtureHeight,275,@"custom sheet 25+2*40+3*50+20");
    PEqual(sheet.detents.firstObject.identifier,@"dvntm",@"native detent identifier");
    PCheck(sheet.prefersGrabberVisible,@"native sheet grabber");PNear(sheet.preferredCornerRadius,15,@"native sheet corner radius");
    [DVNSheetPresenter presentHalfScreenViewController:navigation fromViewController:presenter];
    PNear(navigation.sheetPresentationController.detents.firstObject.fixtureHeight,422,@"native half height");
    [DVNSheetPresenter presentViewController:navigation fromViewController:presenter withHeight:321];
    PNear(navigation.sheetPresentationController.detents.firstObject.fixtureHeight,321,@"explicit native height");
    for(NSUInteger sectionCount=0;sectionCount<5;sectionCount++) {
        NSMutableArray *sections=[NSMutableArray new];NSUInteger rows=0;
        for(NSUInteger i=0;i<sectionCount;i++){NSMutableArray *section=[NSMutableArray new];for(NSUInteger j=0;j<i+1;j++)[section addObject:@(j)];rows+=section.count;[sections addObject:section];}
        content._sections=sections;[DVNSheetPresenter presentCustomHeightViewController:navigation fromViewController:presenter];
        PNear(navigation.sheetPresentationController.detents.firstObject.fixtureHeight,45+40*sectionCount+50*rows,@"native section/row counts");
    }
    PresentationNativeDetents=NO;
    [DVNSheetPresenter presentHalfScreenViewController:navigation fromViewController:presenter];
    PCheck(navigation.modalPresentationStyle==UIModalPresentationCustom,@"iOS14 fallback style");
    PseudoDetentController *halfController=(id)navigation.presentationController;
    PCheck(halfController!=nil,@"local delegate constructs presentation controller before release");
    PNear(halfController.heightCalculator(CGSizeMake(390,844)),422,@"half fallback portrait");
    PNear(halfController.heightCalculator(CGSizeMake(844,390)),390,@"half fallback landscape full height");
    [DVNSheetPresenter presentViewController:navigation fromViewController:presenter withHeight:267];
    PseudoDetentController *controller=(id)navigation.presentationController;
    PNear(controller.heightCalculator(CGSizeMake(390,844)),267,@"explicit fallback portrait");
    PNear(controller.heightCalculator(CGSizeMake(844,390)),390,@"explicit fallback landscape");
    PCheck([controller isKindOfClass:PseudoDetentController.class],@"transition delegate returns real reconstructed presentation controller");
    CheckRect(controller.frameOfPresentedViewInContainerView,CGRectMake(0,577,390,267),@"fallback bottom frame");
    controller.heightCalculator=nil;controller.customHeight=200;
    CheckRect(controller.frameOfPresentedViewInContainerView,CGRectMake(0,644,390,200),@"customHeight fallback when block absent");
    [controller containerViewWillLayoutSubviews];
    PCheck(controller.fixtureLayoutCalls==1,@"layout calls presentation super");
    CheckRect(navigation.view.frame,CGRectMake(0,644,390,200),@"presented view frame applied");
    [controller presentationTransitionWillBegin];PNear(controller.dimmingView.alpha,0,@"nil coordinator leaves presentation alpha unchanged");
    PCheck(controller.dimmingView.superview==controller.containerView,@"dimming ownership");
    PNear(navigation.view.layer.cornerRadius,15,@"fallback corner radius");
    PCheck(navigation.view.layer.maskedCorners==3,@"only top corners rounded");
    [controller dismissController];PCheck(navigation.fixtureDismissals>0,@"dimming tap dismiss target");
    PresentationTransition *transition=[PresentationTransition new];navigation.transitionCoordinator=transition;
    [controller presentationTransitionWillBegin];PNear(controller.dimmingView.alpha,1,@"coordinated presentation fade");
    [controller dismissalTransitionWillBegin];PNear(controller.dimmingView.alpha,0,@"dismiss fade");
    transition.cancelled=YES;transition.fixtureCompletion(transition);
    PCheck(controller.dimmingView.superview==nil,@"original completion removes shield even after cancellation");PNear(controller.dimmingView.alpha,0,@"cancelled dismissal does not restore alpha");
    transition.cancelled=NO;[controller dismissalTransitionWillBegin];transition.fixtureCompletion(transition);
    PCheck(controller.dimmingView.superview==nil,@"completed dismissal removes shield");
    transition.fixtureCompletion=nil;navigation.transitionCoordinator=nil;
    [controller presentationTransitionWillBegin];[controller dismissalTransitionWillBegin];
    PCheck(controller.dimmingView.superview==controller.containerView,@"nil coordinator leaves existing dimming hierarchy unchanged");
    UIViewController *temporary=[UIViewController new];
    @autoreleasepool {
        [DVNSheetPresenter presentViewController:temporary fromViewController:presenter withHeight:100];
        PCheck([temporary.presentationController isKindOfClass:PseudoDetentController.class],@"temporary local delegate participates synchronously in presentation");
        presenter.presentedViewController=nil;temporary.presentationController=nil;
        [PresentationEvents removeAllObjects];
    }
    PCheck(temporary.transitioningDelegate==nil,@"weak delegate released after presentation despite live controller");
    PresentationNativeDetents=YES;presenter.presentedViewController=nil;
}

static void TestImageViewer(void) {
    UIImage *image=[UIImage systemImageNamed:@"fixture-image"];image.size=CGSizeMake(400,200);
    DVNImageViewController *viewer=[DVNImageViewController new];viewer.fullImage=image;
    UINavigationController *navigation=[[UINavigationController alloc]initWithRootViewController:viewer];
    (void)viewer.view;
    PCheck(viewer.fixtureViewDidLoad==1,@"image viewer calls super once");
    PCheck(navigation.navigationBar.translucent,@"transparent navigation bar");
    UIScrollView *scroll=PGet(viewer,@"_scrollView");UIImageView *imageView=PGet(viewer,@"_imageView");
    PCheck(scroll.delegate==viewer,@"viewer is weak scroll delegate");
    PNear(scroll.minimumZoomScale,1,@"min zoom");PNear(scroll.maximumZoomScale,3,@"max zoom");
    PNear(scroll.decelerationRate,.499,@"deceleration is original normal rate / 2");
    PCheck(!scroll.showsHorizontalScrollIndicator&&!scroll.showsVerticalScrollIndicator,@"image indicators suppressed");
    PCheck([viewer viewForZoomingInScrollView:scroll]==imageView,@"zoom view identity");
    PCheck(imageView.image==image&&imageView.contentMode==UIViewContentModeScaleAspectFit,@"full image retained and aspect fitted");
    PCheck(scroll.gestureRecognizers.count==1&&[(UITapGestureRecognizer *)scroll.gestureRecognizers.firstObject numberOfTapsRequired]==2,@"double-tap recognizer");
    scroll.frame=CGRectMake(0,0,300,500);scroll.contentSize=CGSizeMake(300,500);imageView.frame=CGRectMake(0,0,300,500);
    [viewer adjustScrollViewInsets];PNear(scroll.contentInset.top,0,@"unzoomed letterbox does not gain a second inset");
    scroll.contentSize=CGSizeMake(900,1500);imageView.frame=CGRectMake(0,0,900,1500);
    [viewer adjustScrollViewInsets];PNear(scroll.contentInset.top,-500,@"zoomed vertical inset formula");
    PNear(scroll.contentInset.bottom,-500,@"zoomed vertical inset symmetric");
    image.size=CGSizeMake(200,400);scroll.contentSize=CGSizeMake(900,1500);
    [viewer adjustScrollViewInsets];PNear(scroll.contentInset.left,-75,@"portrait horizontal inset formula");
    PNear(scroll.contentInset.right,-75,@"horizontal inset symmetric");
    image.size=CGSizeZero;[viewer adjustScrollViewInsets];PNear(scroll.contentInset.top,0,@"zero-size image chooses horizontal inset branch");
    PCheck(isnan(scroll.contentInset.left)&&isnan(scroll.contentInset.right),@"original zero-size arithmetic forwards NaN horizontal insets");image.size=CGSizeMake(400,200);
    for(NSUInteger content=100;content<=900;content+=100) for(NSUInteger fitted=50;fitted<=450;fitted+=100) {
        scroll.contentSize=CGSizeMake(content,content);scroll.frame=CGRectMake(0,0,300,500);
        [viewer adjustHorizontalInsetsWithImageWidth:fitted];
        PNear(scroll.contentInset.left,-((double)content-fitted)/2+(fitted<300?(300.0-fitted)/2:0),@"horizontal inset grid");
        [viewer adjustVerticalInsetsWithImageHeight:fitted];
        PNear(scroll.contentInset.top,-((double)content-fitted)/2+(fitted<500?(500.0-fitted)/2:0),@"vertical inset grid");
    }
    scroll.contentSize=CGSizeMake(900,1500);[viewer viewDidLayoutSubviews];
    PNear(scroll.contentOffset.x,300,@"layout horizontally centers content");PNear(scroll.contentOffset.y,500,@"layout vertically centers content");
    UITapGestureRecognizer *tap=(id)scroll.gestureRecognizers.firstObject;tap.fixtureLocation=CGPointMake(160,200);
    scroll.zoomScale=1;[viewer handleDoubleTap:tap];
    CheckRect(scroll.fixtureZoomRect,CGRectMake(110,200-500.0/6,100,500.0/3),@"double tap zoom rect");
    PCheck(scroll.fixtureZoomAnimated,@"double tap animates");[viewer handleDoubleTap:tap];PNear(scroll.zoomScale,1,@"second double tap returns to minimum");
    [viewer scrollViewDidZoom:scroll];[viewer scrollViewWillBeginZooming:scroll withView:imageView];
    [viewer scrollViewDidEndZooming:scroll withView:imageView atScale:2];
    UIButton *more=(id)viewer.navigationItem.rightBarButtonItem.customView;PCheck(more.menu.children.count==3,@"three viewer actions");
    PEqual([more.menu.children valueForKey:@"title"],(@[@"SaveToPhotos",@"Share",@"Copy"]),@"viewer menu order");
    more.menu.children[2].fixtureHandler(more.menu.children[2]);PCheck(UIPasteboard.generalPasteboard.image==image,@"copy uses fixture pasteboard");
    more.menu.children[0].fixtureHandler(more.menu.children[0]);PCheck(PLast(@"photos.UIImage")== (id)image,@"save invokes UIImage Photos boundary");
    more.menu.children[1].fixtureHandler(more.menu.children[1]);
    UIActivityViewController *activity=(id)viewer.presentedViewController;
    PEqual(activity.fixtureItems,@[image],@"share owns full image");PEqual(activity.excludedActivityTypes,(@[UIActivityTypeAssignToContact,UIActivityTypePrint]),@"viewer share exclusions");
    PCheck(activity.popoverPresentationController.sourceView==viewer.view,@"viewer popover anchor");
    [viewer closeButtonTapped];PCheck(viewer.fixtureDismissals==1,@"viewer close dismisses");
    __weak DVNImageViewController *weakViewer;
    UIMenu *retainedMenu;
    @autoreleasepool {
        DVNImageViewController *temporary=[DVNImageViewController new];temporary.fullImage=image;(void)temporary.view;
        retainedMenu=[(UIButton *)temporary.navigationItem.rightBarButtonItem.customView menu];weakViewer=temporary;
        PresentationResetEvents();
    }
    PCheck(weakViewer!=nil,@"original menu blocks retain image controller");
    PCheck(retainedMenu.children.count==3,@"retained menu keeps all three actions");
    // Break only the fixture's navbar/menu ownership cycle before releasing it.
    weakViewer.navigationItem.rightBarButtonItem=nil;
    retainedMenu.children[2].fixtureHandler(retainedMenu.children[2]);
    PCheck(UIPasteboard.generalPasteboard.image==image,@"retained controller supplies copy action image");
    retainedMenu=nil;PresentationResetEvents();
    PCheck(weakViewer==nil,@"controller releases after final menu reference");
}

static void TestToastGeometryAndLayout(void) {
    ToastManager *manager=[ToastManager sharedManager];PCheck(manager==[ToastManager sharedManager],@"manager singleton");
    ToastWindow *window=[ToastView toastWindow];PCheck(window==[ToastView toastWindow],@"toast window singleton");
    YTToastOffsetController *offset=[YTToastOffsetController new];manager.offsetController=offset;
    UIView *source=window.rootViewController.view;source.safeAreaInsets=UIEdgeInsetsMake(44,0,34,0);
    NSMutableArray<ToastView *> *toasts=[NSMutableArray new];for(NSUInteger i=0;i<4;i++)[toasts addObject:[ToastView new]];
    const double widths[]={375,390},goodHeights[]={0,20,60},keyboards[]={0,250},offsets[]={0,49};
    for(NSUInteger count=1;count<=4;count++) {
        manager.toasts=[[toasts subarrayWithRange:NSMakeRange(0,count)] mutableCopy];
        for(NSUInteger index=0;index<count;index++)for(NSUInteger w=0;w<2;w++)for(NSUInteger g=0;g<3;g++)for(NSUInteger k=0;k<2;k++)for(NSUInteger o=0;o<2;o++) {
            ToastView *toast=toasts[index];UIScreen.mainScreen.bounds=CGRectMake(0,0,widths[w],844);
            PSet(toast,@"_goodHeight",@(goodHeights[g]));PSet(offset,@"fixtureBottom",@(offsets[o]));
            double bottom=0,top=0,scale=0;
            [toast calculateToastParametersWithKeyboardHeight:keyboards[k] bottomOffset:&bottom topOffset:&top scale:&scale];
            double stack=0,expectedScale=1;
            if(count>1){if(index==count-1)stack=count==2?5:10;else if(index==count-2){stack=count==2?0:5;expectedScale=.95;}else expectedScale=.9;}
            double base=keyboards[k]>0?goodHeights[g]+keyboards[k]+15:
                offsets[o]+(widths[w]!=375&&offsets[o]==0?30:0)+(goodHeights[g]>0?goodHeights[g]-30:0)+15;
            PNear(bottom,base+stack,@"stack/keyboard/device bottom geometry");PNear(top,59+stack,@"stack top geometry");PNear(scale,expectedScale,@"stack scale geometry");
        }
    }
    UIScreen.mainScreen.bounds=CGRectMake(0,0,390,844);manager.toasts=[NSMutableArray new];manager.offsetController=nil;
    ToastView *toast=toasts.firstObject;
    UIWindowScene *scene=(id)UIApplication.sharedApplication.connectedScenes.anyObject;
    for(NSUInteger pad=0;pad<2;pad++)for(NSUInteger landscape=0;landscape<2;landscape++) {
        PSet(toast,@"_isiPad",@(pad));scene.interfaceOrientation=landscape?UIInterfaceOrientationLandscapeLeft:UIInterfaceOrientationPortrait;
        [toast setupInterfaceWithText:@"layout" progress:.4 withStop:YES isStatus:YES isSuccess:YES withWait:NO];
        PNear([PGet(toast,@"_widthConstraint") constant],390*(pad?(landscape?.3:.5):(landscape?.5:.95)),@"device/orientation width");
        PNear([PGet(toast,@"_heightConstraint") constant],45,@"minimum toast height");
        PCheck([PGet(toast,@"_heightConstraint") fixtureRelation]==1,@"toast height is minimum, not fixed");
    }
    scene.interfaceOrientation=UIInterfaceOrientationPortrait;PSet(toast,@"_isiPad",@NO);
    [toast setupInterfaceWithText:@"layout" progress:.4 withStop:YES isStatus:YES isSuccess:YES withWait:NO];
    UILabel *label=PGet(toast,@"_toastLabel");UIImageView *icon=PGet(toast,@"_toastIcon");UIButton *stop=PGet(toast,@"_toastButton");
    PNear(toast.layer.cornerRadius,22.5,@"toast corner radius");PNear(toast.layer.borderWidth,1,@"toast border");
    PNear(label.font.pointSize,15,@"toast font size");PCheck(label.font.fixtureMonospaced&&label.numberOfLines==0,@"multiline monospaced digits");
    PNear(Constraint(icon,@"width",0).constant,24,@"toast status icon dimension");
    PNear(Constraint(stop,@"width",0).constant,24,@"toast stop dimension");
    PNear(Constraint(PGet(toast,@"_activityIndicator"),@"width",0).constant,30,@"toast activity dimension");
    PEqual(icon.image.fixtureName,@"checkmark.circle",@"success symbol");
    [toast updateText:@"updated" progress:.625 animated:NO];PEqual(label.text,@"updated",@"progress text callback");
    PNear([(UIProgressView *)PGet(toast,@"_toastProgress") progress],.625,@"progress callback value");PCheck(![PGet(toast,@"_toastProgress") fixtureAnimated],@"explicit progress animation flag");
    [toast updateText:@"animated" progress:.5];PCheck([PGet(toast,@"_toastProgress") fixtureAnimated],@"default progress animation");
    manager.isPinnedTop=YES;[toast updateLayout];PCheck([PGet(toast,@"_topConstraint") active]&&![PGet(toast,@"_bottomConstraint") active],@"pinned top exclusivity");
    manager.isPinnedTop=NO;[toast updateLayout];PCheck(![PGet(toast,@"_topConstraint") active]&&[PGet(toast,@"_bottomConstraint") active],@"bottom pin exclusivity");
    manager.isFullscreen=YES;[toast updateLayout];PCheck(toast.isHidden,@"ordinary toast hidden fullscreen");
    PSet(toast,@"_ignoresFullscreenOpacity",@YES);
    [toast configureToastAppearanceWithBottomOffset:10 topOffset:20 scale:.9 width:300 alpha:1 animationDuration:.3 completion:nil];
    PCheck(toast.isHidden,@"alpha configuration preserves prior hidden state");PNear(toast.transform.a,.9,@"configured scale");PNear(toast.alpha,1,@"configured alpha");
    NSNotification *keyboard=[NSNotification notificationWithName:UIKeyboardWillShowNotification object:nil userInfo:@{UIKeyboardFrameEndUserInfoKey:[NSValue valueWithCGRect:CGRectMake(0,600,390,244)]}];
    [toast keyboardWillShow:keyboard];PNear([PGet(toast,@"_keyboardHeight") doubleValue],244,@"keyboard converted height");
    [toast keyboardWillHide:keyboard];PNear([PGet(toast,@"_keyboardHeight") doubleValue],0,@"keyboard hide clears height");
    [NSNotificationCenter.defaultCenter postNotificationName:@"GOODHeightDidChangeNotification" object:nil userInfo:@{@"height":@77}];
    PNear([PGet(toast,@"_goodHeight") doubleValue],77,@"registered height observer");
    [toast removeObservers];[NSNotificationCenter.defaultCenter postNotificationName:@"GOODHeightDidChangeNotification" object:nil userInfo:@{@"height":@88}];
    PNear([PGet(toast,@"_goodHeight") doubleValue],77,@"observer removal");
    [manager registerToast:toast];PCheck(manager.toasts.count==1,@"duplicate registration prevented");
    PClearToasts();
}

static void TestToastQueuedOwnership(void) {
    for(NSUInteger kind=0;kind<8;kind++) {
        __weak ToastView *queued;
        @autoreleasepool {
            ToastView *temporary=[ToastView new];queued=temporary;
            PSet(temporary,@"_isAnimating",@YES);
            switch(kind) {
                case 0:[temporary showProgressWithText:@"queued" progress:.1 withStop:NO stopCompletion:nil];break;
                case 1:[temporary showMessageWithText:@"queued" isSuccess:YES duration:1];break;
                case 2:[temporary showText:@"queued"];break;
                case 3:[temporary showToast:@"queued"];break;
                case 4:[temporary showProgressiveToastWithText:@"queued" duration:1 isSuccess:YES];break;
                case 5:[temporary showProgressiveToastWithText:@"queued" duration:1 actionTitle:@"Action" actionCompletion:nil];break;
                case 6:[temporary showProgressiveToastWithText:@"queued" duration:1 actionIcon:nil ignoresPan:NO actionCompletion:nil];break;
                case 7:[temporary showDonationReminder:@"queued"];break;
            }
        }
        PCheck(queued!=nil,@"original queued command strongly owns its toast while waiting");
        // Fixture teardown: abandon the unexecuted command to break its queue cycle.
        @autoreleasepool { [PGet(queued,@"_commandQueue") removeAllObjects]; }
        PCheck(queued==nil,@"removing final queued command releases its captured toast");
    }
}
static void TestToastQueueAndWindow(void) {
    TestToastQueuedOwnership();
    ToastView *toast=[ToastView new];NSMutableArray *order=[NSMutableArray new];
    NSUInteger pending=PresentationMainQueue.count;
    Background(^{[toast processQueue];});
    PCheck(PresentationMainQueue.count==pending,@"empty processQueue preserves caller thread without dispatch");
    __block BOOL commandOnMain=YES;
    Background(^{[toast enqueueCommand:^{commandOnMain=NSThread.isMainThread;[order addObject:@0];}];});
    PCheck(order.count==1&&!commandOnMain,@"original enqueue executes command synchronously on caller thread");
    PEqual(order,@[@0],@"background command consumed immediately");
    [toast hideAnimatedWithCompletion:nil];PSettle();[order removeAllObjects];
    [toast enqueueCommand:^{[order addObject:@1];}];[toast enqueueCommand:^{[order addObject:@2];}];
    PEqual(order,@[@1],@"commands pause while gate is set");
    PSet(toast,@"_isAnimating",@NO);[toast processQueue];PEqual(order,(@[@1,@2]),@"commands remain FIFO");
    [toast hideImmediately];PSettle();
    PCheck([PGet(toast,@"_isAnimating") boolValue],@"hideImmediately does not reset queue gate");
    [toast hideAnimatedWithCompletion:nil];PSettle();
    __block NSUInteger stops=0;
    [toast showProgressWithText:@"Downloading" progress:.1 withStop:YES stopCompletion:^{stops++;}];
    PSettle();PEqual([PGet(toast,@"_toastLabel") text],@"Downloading",@"progress show pipeline runs");
    PCheck(toast.completion!=nil,@"stop completion installed after reveal");
    [toast cancelButtonTapped];PSettle();PCheck(stops==1,@"stop completion invoked once per tap");
    PCheck(toast.superview==nil && ![[ToastManager sharedManager].toasts containsObject:toast],@"cancel hides and unregisters");
    PCheck(toast.completion!=nil,@"original cleanup preserves operation callback");
    [toast showToast:@"Wait"];PSettle();PCheck([PGet(toast,@"_activityIndicator") fixtureAnimating],@"wait toast starts spinner");
    [toast showMessageWithText:@"Complete" isSuccess:YES duration:1];PSettle();
    PresentationAdvanceTime(.5);PSettle();PEqual([PGet(toast,@"_toastLabel") text],@"Complete",@"wait queue transitions to result");
    PresentationAdvanceTime(1);PSettle();PCheck(toast.superview==nil,@"status duration triggers hide");
    [toast showText:@"Text"];PSettle();PEqual([PGet(toast,@"_toastLabel") text],@"Text",@"text-only presentation");
    PresentationAdvanceTime(2.5);PSettle();PCheck(toast.superview==nil,@"text default 2.5 second dismissal");
    [toast showProgressiveToastWithText:@"Timed" duration:.16 isSuccess:YES];PSettle();
    PNear([(UIProgressView *)PGet(toast,@"_toastProgress") progress],1,@"countdown begins full");
    PresentationFixtureTimer *countdown=PresentationFixtureRunLoop.mainRunLoop.timers.lastObject;
    PNear(countdown.timeInterval,.016,@"run loop owns countdown 16ms timer");
    PCheck(PGet(toast,@"_progressTimer")==nil&&countdown.valid,@"countdown timer is not stored in progressTimer ivar");
    PresentationFireTimers(5);PNear([(UIProgressView *)PGet(toast,@"_toastProgress") progress],.5,@"timer decreases normalized progress");
    PresentationFireTimers(6);PSettle();PCheck(toast.superview==nil,@"countdown exhausted hides");
    PCheck(!countdown.valid&&![PresentationFixtureRunLoop.mainRunLoop.timers containsObject:countdown],@"exhausted callback invalidates its run-loop timer");
    __block NSUInteger actionCalls=0;
    [toast showProgressiveToastWithText:@"Undo fixture" duration:10 actionTitle:@"Undo" actionCompletion:^{actionCalls++;}];PSettle();
    UIStackView *stack=PGet(toast,@"_actionsStack");UIButton *action=(id)stack.arrangedSubviews.lastObject;
    PEqual(action.fixtureTitle,@"Undo",@"titled toast action");PNear(action.contentEdgeInsets.left,12,@"action horizontal inset");
    [action sendActionsForControlEvents:UIControlEventTouchUpInside];PSettle();PCheck(actionCalls==1&&toast.superview==nil,@"titled action callback then hide");
    UIImage *actionImage=[UIImage systemImageNamed:@"pause"];
    NSUInteger gesturesBefore=toast.gestureRecognizers.count;
    [toast showProgressiveToastWithText:@"Persistent" duration:10 actionIcon:actionImage ignoresPan:YES actionCompletion:^{actionCalls++;}];PSettle();
    PCheck(toast.gestureRecognizers.count==gesturesBefore+1,@"ignoresPan adds tap while preserving existing recognizers");
    [toast cancelButtonTapped];PSettle();PCheck(actionCalls==2&&toast.superview!=nil,@"persistent icon action does not dismiss");
    UILongPressGestureRecognizer *longPress=[UILongPressGestureRecognizer new];longPress.state=UIGestureRecognizerStateBegan;
    [toast handleLongPress:longPress];PSettle();PCheck(toast.superview==nil,@"long press remains force-dismiss escape");
    [toast showProgressiveToastWithText:@"Icon" duration:10 actionIcon:actionImage actionCompletion:^{actionCalls++;}];PSettle();
    [toast cancelButtonTapped];PSettle();PCheck(actionCalls==3&&toast.superview==nil,@"ordinary icon overload dismisses");
    [toast showDonationReminder:@"Reminder"];PSettle();PCheck([PGet(toast,@"_ignoresPanGesture") boolValue],@"reminder suppresses pan");
    PresentationFireTimers(625);PresentationFireTimers(1);PSettle();PCheck(toast.superview==nil,@"reminder ten-second countdown");
    [toast setupInterfaceWithText:@"Old" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];toast.alpha=1;
    [toast hideWithDelay:1];[toast setupInterfaceWithText:@"New" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
    PresentationAdvanceTime(1);PSettle();PCheck(toast.superview==nil,@"original delayed hide acts on current reused toast without generation check");
    [toast setupInterfaceWithText:@"Zero duration" progress:1 withStop:NO isStatus:NO isSuccess:NO withWait:NO];
    [toast startTimerCountdown:0];PSettle();PCheck(toast.superview!=nil,@"zero duration still registers a run-loop timer");
    PresentationFireTimers(1);PSettle();PCheck(toast.superview==nil,@"zero duration hides on first timer tick");
    [toast setupInterfaceWithText:@"Pan" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];toast.alpha=1;
    UIPanGestureRecognizer *pan=[UIPanGestureRecognizer new];pan.state=UIGestureRecognizerStateChanged;pan.fixtureTranslation=CGPointMake(0,-70);
    [toast handlePanGesture:pan];CABasicAnimation *fade=(id)toast.layer.fixtureAnimations[@"panOpacity"];
    PNear([fade.toValue doubleValue],.25,@"pan dismissal opacity threshold");
    pan.state=UIGestureRecognizerStateEnded;[toast handlePanGesture:pan];PSettle();PCheck(toast.superview==nil,@"pan over sixty dismisses");
    [toast setupInterfaceWithText:@"First" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];toast.alpha=1;
    ToastView *second=[ToastView new];[second setupInterfaceWithText:@"Second" progress:0 withStop:NO isStatus:NO isSuccess:NO withWait:NO];second.alpha=1;
    [second handleTap];PEqual([ToastManager sharedManager].toasts,(@[second,toast]),@"tap rotates toast stack");PSettle();
    PCheck(toast.superview.subviews.lastObject==toast,@"tap raises next toast");
    ToastWindow *window=[ToastView toastWindow];PNear(window.windowLevel,1999,@"window level below system alert");
    PCheck(!window.canBecomeKeyWindow&&![window _canBecomeKeyWindow]&&![window shouldAffectStatusBarAppearance]&&![window _windowControlsStatusBarOrientation],@"overlay never owns key/status bar");
    PCheck([window respondsToSelector:NSSelectorFromString(@"_canAffectStatusBarAppearance")],@"runtime status selector alias");
    PCheck(!((BOOL(*)(id,SEL))objc_msgSend)(window,NSSelectorFromString(@"_canAffectStatusBarAppearance")),@"runtime status alias returns false");
    [window makeKeyAndVisible];PCheck(!window.isKeyWindow&&window.fixtureResignCalls>0,@"key restoration");
    PCheck(window.appKeyWindow==UIApplication.sharedApplication.delegate.window,@"application key window preserved");
    UIApplication.sharedApplication.delegate.window.fixtureKeyWindow=NO;
    PCheck(window.appKeyWindow==nil,@"overlay is never substituted when no application window is key");
    UIApplication.sharedApplication.delegate.window.fixtureKeyWindow=YES;
    PClearToasts();window.hidden=NO;
    PCheck([window hitTest:CGPointMake(10,10) withEvent:nil]==nil,@"bare overlay background passes through");
    toast.frame=CGRectMake(20,20,200,45);[window.rootViewController.view addSubview:toast];toast.alpha=1;toast.hidden=NO;
    PCheck([window hitTest:CGPointMake(25,25) withEvent:nil]!=nil,@"toast descendants receive touches");[toast removeFromSuperview];
    for(Class cls in @[YTActionSheetDialogViewController.class,YTBottomSheetController.class,WelcomeVC.class]) {
        UIViewController *controller=[cls new];controller.view.frame=CGRectMake(0,0,100,100);[window.rootViewController.view addSubview:controller.view];
        PCheck([window hitTest:CGPointMake(10,10) withEvent:nil]==controller.view,@"verified host controller touch allowlist");[controller.view removeFromSuperview];
    }
    YTTouchForwardingView *forward=[[YTTouchForwardingView alloc]initWithFrame:CGRectMake(0,0,100,100)];
    [window.rootViewController.view addSubview:forward];PCheck([window hitTest:CGPointMake(10,10) withEvent:nil]==forward,@"host forwarding view touch allowlist");[forward removeFromSuperview];
    __weak ToastView *weakToast;
    @autoreleasepool{ToastView *temporary=[ToastView new];weakToast=temporary;[temporary startTimerCountdown:5];}
    PCheck(weakToast!=nil,@"run-loop timer strongly retains ToastView");
    [PresentationFixtureRunLoop.mainRunLoop.timers.lastObject invalidate];
    PCheck(weakToast==nil,@"invalidating final run-loop timer releases its captured toast");
    PClearToasts();
}

@interface RoundingPlayerToast : PlayerToast
@property double capturedLabel,capturedIcon,capturedValue,capturedProgress;
@end
@implementation RoundingPlayerToast
- (void)setProgress:(double)value { self.capturedProgress=value; }
- (void)setValue:(double)value forEventWithStyle:(long long)style { self.capturedValue=value; }
- (NSString *)subLabelForVal:(double)value style:(long long)style { self.capturedLabel=value;return [super subLabelForVal:value style:style]; }
- (UIImage *)imgForVal:(double)value { self.capturedIcon=value;return nil; }
@end
static long NativePercentage(double value) {
    long result;double scaled=value*100.0;
    __asm__ volatile("fcvtas %x0, %d1" : "=r"(result) : "w"(scaled));
    return result;
}
static BOOL PlayerSameFP(double actual,double expected) {
    if(isnan(expected))return isnan(actual);
    return actual==expected && (expected!=0 || !!signbit(actual)==!!signbit(expected));
}
static void TestPlayerRounding(void) {
    RoundingPlayerToast *toast=[RoundingPlayerToast new];PSet(toast,@"_style",@2);
    const double values[]={.125,-.125,.005,-.005,.124999999,.125000001,0.0,-0.0,NAN,INFINITY,-INFINITY,0x1p63/100.0,-0x1p63/100.0,0x1.fffffffffffffp1023};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(*values);i++) {
        [toast updateToastText:@"Round" value:values[i]];double expected=(double)NativePercentage(values[i]);
        PCheck(PlayerSameFP(toast.capturedLabel,expected),@"percentage FCVTAS passed to sublabel");
        PCheck(PlayerSameFP(toast.capturedIcon,expected),@"percentage FCVTAS passed to icon");
        PCheck(PlayerSameFP(toast.capturedValue,values[i]),@"original unrounded event value preserved");
        PCheck(PlayerSameFP(toast.capturedProgress,values[i]),@"original unrounded progress preserved");
    }
    [toast updateToastText:@"Round" value:.125];PEqual([PGet(toast,@"_toastSubLabel") text],@"13%",@"positive half rounds away");
    [toast updateToastText:@"Round" value:-.125];PEqual([PGet(toast,@"_toastSubLabel") text],@"-13%",@"negative half rounds away");
}
static void TestPlayerSpeedBoxing(PlayerToast *toast) {
    const double values[]={1.234567890123,1.0000000596046448,1.0000001192092896,
        -1.234567890123,16777217.0,0.0,-0.0,NAN,INFINITY,-INFINITY,
        0x1.fffffffffffffp1023,0x1p-149,0x1p-150};
    for(NSUInteger i=0;i<sizeof(values)/sizeof(*values);i++) {
        float narrowed;
        // Original 0x23de6c narrows before NSNumber numberWithFloat:.
        __asm__ volatile("fcvt %s0, %d1" : "=w"(narrowed) : "w"(values[i]));
        NSNumber *boxed=[NSNumber numberWithFloat:narrowed];
        NSString *expected=[NSString stringWithFormat:@"%@×",boxed];
        PEqual([toast subLabelForVal:values[i] style:1],expected,@"speed label preserves original float boxing");
    }
    PEqual([toast subLabelForVal:1.0000000596046448 style:1],@"1×",@"float half-ULP loss before boxing is preserved");
}
static void TestPlayer(void) {
    TestPlayerRounding();
    TestPlayerSpeedBoxing([PlayerToast new]);
    PlayerToast *toast=[PlayerToast sharedToast];PCheck(toast==[PlayerToast sharedToast],@"player toast singleton");
    for(NSNumber *compact in @[@NO,@YES]) {
        [toast showPlayerToastWithText:@"Volume" value:50 style:2 isCompact:compact.boolValue];
        PNear(Constraint(toast,@"height",0).constant,compact.boolValue?30:50,@"player toast height");
        PNear(Constraint(toast,@"width",1).constant,compact.boolValue?100:200,@"player toast minimum width");
        PNear([PGet(toast,@"_toastView") layer].cornerRadius,compact.boolValue?15:25,@"player corner radius");
        PEqual([PGet(toast,@"_toastLabel") text],compact.boolValue?nil:@"Volume",@"compact hides primary text");
        PNear(Constraint(PGet(toast,@"_toastImage"),@"width",0).constant,compact.boolValue?15:25,@"player image dimensions");
        PNear(Constraint(PGet(toast,@"_toastImage"),@"centerX",0).constant,compact.boolValue?20:35,@"player image center");
    }
    PNear(toast.layer.shadowOpacity,.2,@"player shadow float constant");
    PNear(toast.layer.shadowRadius,12,@"player shadow radius");
    NSArray *vectors=@[
        @[@0,@0,@"sun.min"],@[@0,@33.3,@"sun.min"],@[@0,@33.35,NSNull.null],@[@0,@33.4,@"sun.mid"],
        @[@0,@66.6,@"sun.mid"],@[@0,@66.65,NSNull.null],@[@0,@66.7,@"sun.max"],@[@0,@100,@"sun.max"],@[@0,@101,NSNull.null],
        @[@1,@.25,@"speed.slow"],@[@1,@.94,@"speed.slow"],@[@1,@1,@"speed.reg"],@[@1,@1.04,@"speed.reg"],@[@1,@1.1,@"speed.fast"],
        @[@2,@0,@"vol.off"],@[@2,@.5,NSNull.null],@[@2,@1,@"vol.low"],@[@2,@33.3,@"vol.low"],@[@2,@33.4,@"vol.mid"],
        @[@2,@66.7,@"vol.max"],@[@2,@100,@"vol.max"],@[@2,@-1,NSNull.null],@[@3,@50,NSNull.null]];
    for(NSArray *vector in vectors){PSet(toast,@"_style",vector[0]);PEqual([toast imgForVal:[vector[1] doubleValue]].fixtureName,vector[2]==NSNull.null?nil:vector[2],@"decoded player asset thresholds");}
    PEqual([toast subLabelForVal:1.25 style:1],@"1.25×",@"UTF16 speed multiplication sign");
    PEqual([toast subLabelForVal:32.9 style:2],@"32%",@"non-speed percent truncation");
    UIView *progress=PGet(toast,@"_toastProgress");progress.bounds=CGRectMake(0,0,100,4);
    for(NSNumber *value in @[@(-1),@0,@.25,@1,@2]) {
        [toast setProgress:value.doubleValue];PNear([PGet(toast,@"_progressLayer") frame].size.width,MAX(0,MIN(1,value.doubleValue))*100,@"progress clamping");
    }
    [toast setProgress:NAN];PNear([PGet(toast,@"_progressLayer") frame].size.width,0,@"nonfinite layer progress guard");
    [toast setValue:.5 forEventWithStyle:0];PNear(UIScreen.mainScreen.brightness,.5,@"brightness write");
    NSUInteger writes=UIScreen.mainScreen.fixtureBrightnessWrites;
    [toast setValue:0 forEventWithStyle:0];[toast setValue:-.5 forEventWithStyle:0];
    PCheck(UIScreen.mainScreen.fixtureBrightnessWrites==writes+1,@"brightness lower limit is written once");
    [toast setValue:.7 forEventWithStyle:0];[toast setValue:0 forEventWithStyle:0];PCheck(UIScreen.mainScreen.fixtureBrightnessWrites==writes+3,@"positive brightness resets lower-limit latch");
    [toast setValue:.75 forEventWithStyle:2];CustomHUD *hud=PGet(toast,@"_volumeHUD");PNear(hud.volumeLevel,.75,@"player volume event");
    PCheck([MPVolumeHUDController.sharedInstance.fixtureDisplays containsObject:hud],@"volume event suppresses stock display through HUD registration");
    [toast showPlayerToastWithText:@"Brightness" value:50 style:0 isCompact:NO];
    [toast updateToastText:@"Updated" value:.75];PEqual([PGet(toast,@"_toastLabel") text],@"Updated",@"player updates primary label");
    PEqual([PGet(toast,@"_toastSubLabel") text],@"75%",@"player update percent conversion");
    PEqual([PGet(toast,@"_toastImage") image].fixtureName,@"sun.max",@"player update swaps image");
    [toast setupSubForStyle:1];PNear([PGet(toast,@"_toastSubLabel") alpha],1,@"speed sublabel visible");PNear(progress.alpha,0,@"speed progress hidden");
    [toast hideToast];PresentationCompleteAnimations(YES);PCheck(toast.superview==nil,@"player hide removes view");
    PCheck(![MPVolumeHUDController.sharedInstance.fixtureDisplays containsObject:hud],@"player hide unregisters HUD");
    [toast showPlayerToastWithText:@"Old" value:1 style:1 isCompact:YES];[toast hideToast];
    [toast showPlayerToastWithText:@"New" value:1.5 style:1 isCompact:YES];PresentationCompleteAnimations(YES);
    PCheck(toast.superview==nil,@"original successful stale completion removes a newer player presentation");
    [toast hideToast];PresentationCompleteAnimations(YES);[toast clearConstraints];
    PCheck([PGet(toast,@"_activeConstraints") count]==0,@"player constraints deactivate and clear");
}

static void RunSuite(NSString *name,void (*body)(void)) {
    NSUInteger start=PresentationAssertions;body();PSettle();suiteCounts[name]=@(PresentationAssertions-start);
    printf("PASS %s: %lu assertions\n",name.UTF8String,(unsigned long)(PresentationAssertions-start));fflush(stdout);
}
int main(void) {
    @autoreleasepool {
        PresentationInitialize();suiteCounts=[NSMutableDictionary new];
        PCheck(NSThread.isMainThread,@"fixture runs on main thread");
        PCheck([NSTemporaryDirectory() hasPrefix:PresentationFixtureRoot],@"Foundation temp path is isolated");
        UIWindowScene *scene=[UIWindowScene new];scene.activationState=UISceneActivationStateForegroundActive;scene.interfaceOrientation=UIInterfaceOrientationPortrait;
        UIWindow *window=[[UIWindow alloc]initWithWindowScene:scene];window.frame=UIScreen.mainScreen.bounds;window.rootViewController=[UIViewController new];window.fixtureKeyWindow=YES;
        PresentationAppDelegate *delegate=[PresentationAppDelegate new];delegate.window=window;UIApplication.sharedApplication.delegate=delegate;
        UIApplication.sharedApplication.connectedScenes=[NSSet setWithObject:scene];
        UIApplication.sharedApplication.windows=@[window];
        // Original once initialization is permanent, including a no-scene result.
        // Dedicated constructor fixtures cover no-scene first use separately.
        __block ToastWindow *firstWindow;
        Background(^{firstWindow=[ToastView toastWindow];});
        PCheck(firstWindow!=nil,@"first use with active scene constructs overlay on caller thread");
        PCheck(PresentationMainQueue.count==1,@"window construction defers only makeKeyAndVisible");
        PresentationDrainMain();
        PCheck([ToastView toastWindow]==firstWindow,@"once-created overlay is reused");
        RunSuite(@"ToastWindow_subclass_initialize_aliases",TestToastWindowInitialization);
        RunSuite(@"BlurButton_CustomHUD",TestBlurAndHUD);
        RunSuite(@"Sheets_transition_ownership",TestSheets);
        RunSuite(@"ImageViewer_zoom_menu_ownership",TestImageViewer);
        RunSuite(@"Toast_geometry_layout_observers",TestToastGeometryAndLayout);
        RunSuite(@"Toast_queue_timer_window",TestToastQueueAndWindow);
        RunSuite(@"PlayerToast_state",TestPlayer);
        RunSuite(@"YTLHelper_callbacks_media_fixtures",PRunHelpers);
        PClearToasts();
        NSURL *output=PFile(@"runtime-report.json");
        // Include the final successful report-write assertion in the same total
        // printed below, so machine-readable and console counts agree.
        NSDictionary *report=@{@"passed":@YES,@"assertions":@(PresentationAssertions+1),@"suites":suiteCounts,
            @"originalCodeExecuted":@NO,@"realNetwork":@NO,@"realPhotosOrUserMedia":@NO,
            @"UI":@"host boundary doubles, not device validation"};
        NSData *json=[NSJSONSerialization dataWithJSONObject:report options:NSJSONWritingPrettyPrinted error:nil];
        PCheck([json writeToURL:output atomically:YES],@"runtime report stored in owned scratch");
        printf("PRESENTATION_HELPERS_RUNTIME_PASS %lu assertions\n",(unsigned long)PresentationAssertions);
    }
    return 0;
}
