#import <Foundation/Foundation.h>
#import "../source/Runtime/YTLHookEntrypoints.h"
#import "../source/Runtime/YTLSideloadEntrypoint.h"
#include <stdlib.h>
#include <string.h>
static unsigned calls[64], count;
static dispatch_block_t pending;
static dispatch_queue_t pendingQueue;
static unsigned schedules;
static BOOL SideloadEnabled(void) {const char *value=getenv("YTL_TEST_SIDELOAD");return value && strcmp(value,"1")==0;}
void YTLInstallCompatibilityVersionHooks(void) {calls[count++]=1;}
void YTLInstallSettingsBridgeHooks(void) {calls[count++]=2;}
BOOL YTLPrepareSideloadCompatibility(void) {calls[count++]=3;return SideloadEnabled();}
void YTLInstallSponsorPlaybackHooks(void) {calls[count++]=4;}
void YTLInstallPlayerBarsSponsorHooks(void) {calls[count++]=5;}
void YTLScheduleWelcome(void) {calls[count++]=6;}
void YTLInstallRemoteControlsEarlyHooks(void) {calls[count++]=7;}
void YTLInstallGeneralInterfaceEarlyHooks(void) {calls[count++]=8;}
void YTLInstallNavigationChromeEarlyHooks(void) {calls[count++]=9;}
void YTLInstallStartupLifecycleEarlyHooks(void) {calls[count++]=10;}
void YTLInstallConfigurationEarlyHooks(void) {calls[count++]=11;}
void YTLInstallNativeShareHooks(void) {calls[count++]=12;}
void YTLInstallNavigationChromeRendererHook(void) {calls[count++]=13;}
void YTLInstallDiscordLifecycleHooks(void) {calls[count++]=14;}
void YTLInstallStartupLifecycleMainHooks(void) {calls[count++]=15;}
void YTLInstallGeneralInterfaceHooks(void) {calls[count++]=16;}
void YTLInstallMediaPolicyHooks(void) {calls[count++]=17;}
void YTLInstallFeedFilteringHooks(void) {calls[count++]=18;}
void YTLInstallThemeStylesHooks(void) {calls[count++]=19;}
void YTLInstallMediaServicesHooks(void) {calls[count++]=20;}
void YTLInstallPlaybackOptionsHooks(void) {calls[count++]=21;}
void YTLInstallPlayerControlsHooks(void) {calls[count++]=22;}
void YTLInstallPlayerOverlayHooks(void) {calls[count++]=23;}
void YTLInstallShortsInterfaceHooks(void) {calls[count++]=24;}
void YTLInstallConfigurationHooks(void) {calls[count++]=25;}
void YTLInstallPlayerBarsAppearanceHooks(void) {calls[count++]=26;}
void YTLInstallNavigationChromeHooks(void) {calls[count++]=27;}
void YTLInstallFeedNodesHooks(void) {calls[count++]=28;}
void YTLInstallShortsPlaybackHooks(void) {calls[count++]=29;}
void YTLInstallPlayerLifecycleHooks(void) {calls[count++]=30;}
void YTLInstallRemoteControlsMainHooks(void) {calls[count++]=31;}
void YTLInstallImageGesturesHooks(void) {calls[count++]=32;}
void YTLFinalizePrimaryStartup(void) {calls[count++]=33;}
void YTLInstallSideloadMetadataCompatibilityHooks(void) {calls[count++]=100;}
void HookEntrypointsDispatchAsync(dispatch_queue_t queue,dispatch_block_t block) {schedules++;pendingQueue=queue;pending=[block copy];}
int main(void) {@autoreleasepool {
    if(count!=13 || schedules!=1 || !pending || pendingQueue!=dispatch_get_main_queue()) {
        fprintf(stderr,"Immediate registration or main-queue scheduling differs\n");return 1;
    }
    for(unsigned i=0;i<13;i++)if(calls[i]!=i+1)return 1;
    pending();pending=nil;
    if(count!=33u+(unsigned)SideloadEnabled()){fprintf(stderr,"Deferred registrations omitted\n");return 1;}
    unsigned index=13;
    for(unsigned tag=14;tag<=33;tag++) {
        if(tag==15 && SideloadEnabled() && calls[index++]!=100)return 1;
        if(calls[index++]!=tag){fprintf(stderr,"Hook order differs at tag %u\n",tag);return 1;}
    }
    if(index!=count)return 1;
    printf("Hook entrypoints: immediate/deferred order and final defaults verified, sideload=%d\n",SideloadEnabled());
}return 0;}
