// Decompiled hook evidence for YTAnnotationsViewController. This is not compilable Logos source.

// -[YTAnnotationsViewController loadFeaturedChannelWatermark], original IMP slot 0x012264e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x8f754. FUN_0008f754 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0008f754(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226d4c = 1;
  iVar1 = FUN_000e0da8(@"noWatermarks");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008f900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_012264e8)(param_1,param_2);
    return;
  }
  return;
}


