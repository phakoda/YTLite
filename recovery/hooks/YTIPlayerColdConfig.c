// Decompiled hook evidence for YTIPlayerColdConfig. This is not compilable Logos source.

// -[YTIPlayerColdConfig iosDisablePlaybackLockScreenController], original IMP slot 0x01226410
/* Decompiled from supplied 5.2.2 arm package. VA 0x881bc. FUN_000881bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000881bc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ccc = 1;
  iVar1 = FUN_000df308(@"ytlLockButton");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0008837c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226410)(param_1,param_2);
    return uVar2;
  }
  return 0;
}


