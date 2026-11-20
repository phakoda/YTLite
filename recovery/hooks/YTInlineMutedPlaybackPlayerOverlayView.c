// Decompiled hook evidence for YTInlineMutedPlaybackPlayerOverlayView. This is not compilable Logos source.

// -[YTInlineMutedPlaybackPlayerOverlayView audioControlUIStyle], original IMP slot 0x012262c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ea70. FUN_0007ea70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007ea70(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c0c = 1;
  uVar1 = FUN_000dd0f4(@"downloadManager");
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd0d0((&PTR_LAB_0117cbf8)[uVar1] + (int)-(uRam000000000117cc08 ^ 0xafc24f26),
                           @"sponsorBlock"), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007ed48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262c8)(param_1,param_2);
    return uVar3;
  }
  return 2;
}



// -[YTInlineMutedPlaybackPlayerOverlayView scrubbingUIStyle], original IMP slot 0x012262d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x7ed60. FUN_0007ed60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0007ed60(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c10 = 1;
  uVar1 = FUN_000dd118(@"downloadManager");
  if ((uVar1 == 0) &&
     (iVar2 = FUN_000dd13c((&PTR_LAB_0117cc50)[uVar1] + (int)-(DAT_0117cc60 ^ 0x318955a3),
                           @"sponsorBlock"), iVar2 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x0007f04c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*_DAT_012262d0)(param_1,param_2);
    return uVar3;
  }
  return 2;
}



// -[YTInlineMutedPlaybackPlayerOverlayView updateAudioControlUIStyle:], original IMP slot 0x012262d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x7f064. FUN_0007f064 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f064(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c14 = 1;
  uVar1 = FUN_000dd160(@"downloadManager");
  if (uVar1 == 0) {
    iVar2 = FUN_000dd184((&PTR_LAB_0117cca8)[uVar1] + (int)-(DAT_0117ccb8 ^ 0x15bba134),
                         @"sponsorBlock");
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262d8)(param_1,param_2,uVar3);
  CallSupervisor(0x251d);
  return ZEXT816(0x1f);
}



// -[YTInlineMutedPlaybackPlayerOverlayView resetWithAudioControlUIStyle:], original IMP slot 0x012262e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x7f34c. FUN_0007f34c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f34c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  DAT_01226c18 = 1;
  uVar1 = FUN_000dd1a8(@"downloadManager");
  if (uVar1 == 0) {
    iVar2 = FUN_000dd1cc((&PTR_LAB_0117cce8)[uVar1] + (int)-(uRam000000000117ccf8 ^ 0x73a6d9f),
                         @"sponsorBlock");
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262e0)(param_1,param_2,uVar3);
  CallSupervisor(0x5bd);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}



// -[YTInlineMutedPlaybackPlayerOverlayView setAudioControlUIStyle:], original IMP slot 0x012262e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x7f64c. FUN_0007f64c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007f64c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226c1c = 1;
  uVar1 = FUN_000dd214(@"downloadManager");
  if (uVar1 == 0) {
    iVar2 = FUN_000dd1f0((&PTR__MSHookMessageEx_0117cd28)[uVar1] + (int)-(DAT_0117cd38 ^ 0x8e269bb7)
                         ,@"sponsorBlock");
    uVar3 = 2;
    if (iVar2 == 0) {
      uVar3 = param_3;
    }
  }
  else {
    uVar3 = 2;
  }
  (*_DAT_012262e8)(param_1,param_2,uVar3);
  CallSupervisor(0xb392);
  return ZEXT816(0x1f);
}


