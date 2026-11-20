// Decompiled hook evidence for YTReelPlayerViewController. This is not compilable Logos source.

// -[YTReelPlayerViewController playbackControllerDidFinishPlaybackAndWillTransitionInternallyToNextPlayback:], original IMP slot 0x012265f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x9fcb4. FUN_0009fcb4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0009fcb4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  
  DAT_01226ddc = 1;
  uVar1 = FUN_000e5044(param_1,@selector(respondsToSelector:),@selector(maybeLoopPlayback));
  if (uVar1 != 0) {
    (*_DAT_012265f8)(param_1,param_2,param_3);
    lVar2 = _ytpInt(@"shortsPlaybackIndex");
                    /* WARNING: Could not recover jumptable at 0x0009ff90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar3 = (*(code *)((&PTR_LAB_0117fdd0)[lVar2 == 2] + (int)-(uRam000000000117fde0 ^ 0x89ae18ff))
             )();
    return auVar3;
  }
  lVar2 = _ytpInt((&PTR_LAB_0117fdb8)[uVar1] + (int)-(DAT_0117fdc8 ^ 0x13846f42),
                  @"shortsPlaybackIndex");
  if (lVar2 != 2) {
    (*_DAT_012265f8)(param_1,param_2,param_3);
  }
  CallSupervisor(0x9c8e);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}



// -[YTReelPlayerViewController maybeLoopPlayback], original IMP slot 0x01226600
/* Decompiled from supplied 5.2.2 arm package. VA 0x9ffd0. FUN_0009ffd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0009ffd0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01226de0 = 1;
  lVar2 = _ytpInt(@"shortsPlaybackIndex");
  if ((lVar2 == 1) &&
     (iVar1 = FUN_000e50ac(param_1,@selector(respondsToSelector:),
                           @selector(reelContentViewRequestsAdvanceToNextVideo:)), iVar1 != 0)) {
    uVar3 = _objc_msgSend(param_1,@selector(class));
    lVar2 = _class_getInstanceVariable(uVar3,s__isEngagementPanelVisible_0116c4c0);
                    /* WARNING: Could not recover jumptable at 0x000a05e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar4 = (*(code *)((&PTR_LAB_0117fe60)[lVar2 == 0] + (int)-(DAT_0117fe70 ^ 0xe2cb3780)))();
    return auVar4;
  }
  (*_DAT_01226600)(param_1,param_2);
  CallSupervisor(0x25c6);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}



// -[YTReelPlayerViewController playbackControllerDidActivateVideo:withPlayerResponse:], original IMP slot 0x01226608
/* Decompiled from supplied 5.2.2 arm package. VA 0xa0670. FUN_000a0670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000a0670(undefined8 param_1)

{
  ulong uVar1;
  
  DAT_01226de4 = 1;
  (*_DAT_01226608)(param_1);
  uVar1 = FUN_000e5178(@"restrictShortsPortion");
                    /* WARNING: Could not recover jumptable at 0x000a1000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117fed0)[uVar1 & 0xffffffff] + (int)-(uRam000000000117fee0 ^ 0x74185b84)))()
  ;
  return;
}



// -[YTReelPlayerViewController autoQuality], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xa1240. FUN_000a1240 */

void FUN_000a1240(undefined8 param_1)

{
  long lVar1;
  undefined1 auStack_540 [192];
  undefined1 auStack_480 [144];
  undefined1 auStack_3f0 [256];
  undefined1 *puStack_2f0;
  undefined1 *puStack_2d0;
  undefined1 *puStack_2c8;
  undefined **local_298;
  undefined **local_290;
  undefined **ppuStack_288;
  undefined **local_278;
  undefined **ppuStack_270;
  undefined **local_260;
  undefined **local_258;
  undefined **ppuStack_250;
  undefined **local_240;
  undefined **local_230;
  undefined **local_228;
  undefined **ppuStack_220;
  undefined **local_210;
  undefined **local_200;
  undefined **local_1f0;
  undefined **ppuStack_1e8;
  undefined **local_1d8;
  undefined **local_1d0;
  undefined **ppuStack_1c8;
  undefined **local_1b8;
  undefined **local_1a8;
  undefined **local_198;
  undefined **local_188;
  undefined **ppuStack_180;
  undefined **local_170;
  undefined **local_168;
  undefined **ppuStack_160;
  undefined **local_150;
  undefined **local_140;
  undefined **local_130;
  undefined **local_120;
  undefined **local_118;
  undefined **local_108;
  undefined **local_f8;
  undefined **ppuStack_f0;
  undefined **local_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  undefined **local_c0;
  undefined **local_b0;
  undefined **local_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  undefined8 local_70;
  
  local_70 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0117ff80;
  local_7c = (uint)(DAT_01226de8 == 0);
  local_90 = &PTR_LAB_0117ffa0;
  local_a0 = &PTR__sel_registerName_0117ffb8;
  local_b0 = &PTR_LAB_0117ffd0;
  local_c0 = &PTR__objc_getClass_0117ffe8;
  local_88 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01175340;
  ppuStack_d0 = &PTR_LAB_01175340;
  local_e0 = &PTR_LAB_01180010;
  local_f8 = &PTR_LAB_01180030;
  ppuStack_f0 = &PTR_LAB_01175340;
  local_108 = &PTR_LAB_01180048;
  local_118 = &PTR_LAB_01175340;
  local_120 = &PTR__objc_getClass_01180068;
  local_130 = &PTR_LAB_01180080;
  local_140 = &PTR_LAB_01180098;
  local_150 = &PTR_LAB_011800b0;
  local_168 = &PTR_LAB_01175340;
  ppuStack_160 = &PTR_LAB_01175340;
  local_170 = &PTR_LAB_011800d8;
  local_188 = &PTR_LAB_011800f8;
  ppuStack_180 = &PTR_LAB_01175340;
  local_198 = &PTR_LAB_01180110;
  local_1a8 = &PTR_FUN_01180128;
  local_1b8 = &PTR_LAB_01180140;
  local_1d0 = &PTR_LAB_01175340;
  ppuStack_1c8 = &PTR_LAB_01175340;
  local_1d8 = &PTR_LAB_01180168;
  local_1f0 = &PTR_LAB_01180188;
  ppuStack_1e8 = &PTR_LAB_01175340;
  local_200 = &PTR__objc_getClass_011801a0;
  local_210 = &PTR__objc_getClass_011801b8;
  local_228 = &PTR_LAB_01175340;
  ppuStack_220 = &PTR_LAB_01175340;
  local_230 = &PTR_LAB_011801e0;
  local_240 = &PTR_LAB_011801f8;
  local_258 = &PTR_LAB_01175340;
  ppuStack_250 = &PTR_LAB_01175340;
  local_260 = &PTR_LAB_01180220;
  local_278 = &PTR_LAB_01180240;
  ppuStack_270 = &PTR_LAB_01175340;
  local_290 = &PTR_LAB_01175340;
  ppuStack_288 = &PTR_LAB_01175340;
  local_298 = &PTR_LAB_01175340;
  DAT_01226de8 = 1;
  puStack_2c8 = auStack_3f0;
  puStack_2d0 = auStack_480;
  puStack_2f0 = auStack_540;
  _objc_msgSend(param_1,@selector(videoQualityController));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  uStack_94 = (uint)(lVar1 == 0);
                    /* WARNING: Could not recover jumptable at 0x000a20f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_90[uStack_94] + (int)-(DAT_0117ffb0 ^ 0xb5ce1937)))();
  return;
}



// -[YTReelPlayerViewController shouldEnablePlayerBar], original IMP slot 0x01226610
/* Decompiled from supplied 5.2.2 arm package. VA 0xa2e8c. FUN_000a2e8c */

uint FUN_000a2e8c(void)

{
  uint uVar1;
  
  DAT_01226dec = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTReelPlayerViewController shouldAlwaysEnablePlayerBar], original IMP slot 0x01226618
/* Decompiled from supplied 5.2.2 arm package. VA 0xa2ff0. FUN_000a2ff0 */

uint FUN_000a2ff0(void)

{
  uint uVar1;
  
  DAT_01226df0 = 1;
  uVar1 = _ytpBool(@"shortsProgress");
  return uVar1 & 1;
}



// -[YTReelPlayerViewController shouldEnablePlayerBarOnlyOnPause], original IMP slot 0x01226620
/* Decompiled from supplied 5.2.2 arm package. VA 0xa3154. FUN_000a3154 */

uint FUN_000a3154(void)

{
  uint uVar1;
  
  DAT_01226df4 = 1;
  uVar1 = FUN_000e58dc(@"shortsProgress");
  return uVar1 ^ 1;
}


