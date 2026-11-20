// Decompiled hook evidence for YTIClientMdxGlobalConfig. This is not compilable Logos source.

// -[YTIClientMdxGlobalConfig enableSkippableAd], original IMP slot 0x01226050
/* Decompiled from supplied 5.2.2 arm package. VA 0x66db8. FUN_00066db8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00066db8(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a98 = 1;
  iVar1 = FUN_000d6ed8(@"noAds");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00066efc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226050)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


