// Decompiled hook evidence for YTLocalPlaybackController. This is not compilable Logos source.

// -[YTLocalPlaybackController createAdsPlaybackCoordinator], original IMP slot 0x01226088
/* Decompiled from supplied 5.2.2 arm package. VA 0x6775c. FUN_0006775c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006775c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ab4 = 1;
  iVar1 = FUN_000d6fd4(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226088)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


