// Decompiled hook evidence for YTReelWatchHeaderView. This is not compilable Logos source.

// -[YTReelWatchHeaderView setChannelBarElementRenderer:], original IMP slot 0x01226700
/* Decompiled from supplied 5.2.2 arm package. VA 0xb1574. FUN_000b1574 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b1574(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e7c = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e86c4(@"hideShortsChannelName");
  if (iVar1 == 0) {
    (*_DAT_01226700)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xf0b5);
  return ZEXT816(0x1f);
}



// -[YTReelWatchHeaderView setHeaderRenderer:], original IMP slot 0x01226708
/* Decompiled from supplied 5.2.2 arm package. VA 0xb17e4. FUN_000b17e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b17e4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e80 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e86e8(@"hideShortsDescription");
  if (iVar1 == 0) {
    (*_DAT_01226708)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTReelWatchHeaderView setShortsVideoTitleElementRenderer:], original IMP slot 0x01226710
/* Decompiled from supplied 5.2.2 arm package. VA 0xb1a40. FUN_000b1a40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b1a40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e84 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e870c(@"hideShortsDescription");
  if (iVar1 == 0) {
    (*_DAT_01226710)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTReelWatchHeaderView setSoundMetadataElementRenderer:], original IMP slot 0x01226718
/* Decompiled from supplied 5.2.2 arm package. VA 0xb1c98. FUN_000b1c98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b1c98(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e88 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e8730(@"hideShortsAudioTrack");
  if (iVar1 == 0) {
    (*_DAT_01226718)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// -[YTReelWatchHeaderView setActionElement:], original IMP slot 0x01226720
/* Decompiled from supplied 5.2.2 arm package. VA 0xb1edc. FUN_000b1edc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b1edc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226e8c = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e8754(@"hideShortsPromoCards");
  if (iVar1 == 0) {
    (*_DAT_01226720)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xe5fe);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTReelWatchHeaderView setBadgeRenderer:], original IMP slot 0x01226728
/* Decompiled from supplied 5.2.2 arm package. VA 0xb2140. FUN_000b2140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b2140(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226e90 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e8778(@"hideShortsThanks");
  if (iVar1 == 0) {
    (*_DAT_01226728)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x5b55);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}



// -[YTReelWatchHeaderView setMultiFormatLinkElementRenderer:], original IMP slot 0x01226730
/* Decompiled from supplied 5.2.2 arm package. VA 0xb2364. FUN_000b2364 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b2364(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e94 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e879c(@"hideShortsSource");
  if (iVar1 == 0) {
    (*_DAT_01226730)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xeb70);
  return ZEXT816(0x1f);
}


