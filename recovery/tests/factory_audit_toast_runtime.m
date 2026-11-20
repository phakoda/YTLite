#import "../source/Presentation/ToastManager.h"
#import "../source/Presentation/ToastView.h"
#import <objc/runtime.h>
static NSUInteger checks,subclassAllocations,subclassInitializers;
#define CHECK(...) do{checks++;if(!(__VA_ARGS__)){fprintf(stderr,"FAIL %d: %s\n",__LINE__,#__VA_ARGS__);exit(1);}}while(0)
// Unused presentation boundary required to link the complete production source.
@implementation UIView @end
@implementation UIVisualEffectView @end
@implementation ToastView @end
@interface FactoryAuditToastManager : ToastManager @end
@implementation FactoryAuditToastManager
+ (instancetype)alloc {subclassAllocations++;return [super alloc];}
- (instancetype)init {subclassInitializers++;return [super init];}
@end
@interface FactoryAuditOtherToastManager : ToastManager @end
@implementation FactoryAuditOtherToastManager @end
int main(int argc,const char *argv[]){@autoreleasepool{
    CHECK(argc==2);BOOL subclassFirst=!strcmp(argv[1],"subclass-first");
    ToastManager *manager=subclassFirst?[FactoryAuditToastManager sharedManager]:[ToastManager sharedManager];
    CHECK(object_getClass(manager)==ToastManager.class);
    CHECK(subclassAllocations==0&&subclassInitializers==0);
    CHECK([manager.toasts isKindOfClass:NSMutableArray.class]&&manager.toasts.count==0);
    CHECK(!manager.offsetController&&!manager.isFullscreen&&!manager.isPinnedTop);
    CHECK([ToastManager sharedManager]==manager);
    CHECK([FactoryAuditToastManager sharedManager]==manager);
    CHECK([FactoryAuditOtherToastManager sharedManager]==manager);
    CHECK(subclassAllocations==0&&subclassInitializers==0);
    printf("FACTORY_TOAST_RUNTIME_PASS %lu assertions mode=%s; whole ToastManager.m\n",(unsigned long)checks,argv[1]);
}return 0;}
