// Decompiled hook evidence for YTHotConfig. This is not compilable Logos source.

// -[YTHotConfig enablePlayerBarForVerticalVideoWhenControlsHiddenInFullscreen], original IMP slot 0x012266c8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb07d4. FUN_000b07d4 */

void FUN_000b07d4(void)

{
  DAT_01226e60 = 1;
  FUN_000e83fc(@"shortsProgress");
  return;
}



// -[YTHotConfig isPromptForLocalNetworkPermissionsEnabled], original IMP slot 0x012266d0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb093c. FUN_000b093c */

undefined8 FUN_000b093c(void)

{
  return 0;
}



// -[YTHotConfig clientInfraClientConfigIosEnableFillingEncodedHacksInnertubeContext], original IMP slot 0x012266d8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0944. FUN_000b0944 */

undefined8 FUN_000b0944(void)

{
  return 0;
}



// -[YTHotConfig enableShortsVideoQualityPicker], original IMP slot 0x012266e0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb094c. FUN_000b094c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000b094c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226e6c = 1;
  iVar1 = FUN_000e8420(@"shortsForceQuality");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000b0b44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_012266e0)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


