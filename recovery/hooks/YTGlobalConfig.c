// Decompiled hook evidence for YTGlobalConfig. This is not compilable Logos source.

// -[YTGlobalConfig shouldBlockUpgradeDialog], original IMP slot 0x01226018
/* Decompiled from supplied 5.2.2 arm package. VA 0x667a0. FUN_000667a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000667a0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a7c = 1;
  iVar1 = FUN_000d6e08(@"noAds");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000668e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226018)(param_1,param_2);
    return uVar2;
  }
  return 1;
}


