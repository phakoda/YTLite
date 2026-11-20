// Decompiled hook evidence for YTPlayabilityResolutionUserActionUIController. This is not compilable Logos source.

// -[YTPlayabilityResolutionUserActionUIController showConfirmAlert], original IMP slot 0x01226510
/* Decompiled from supplied 5.2.2 arm package. VA 0x90048. FUN_00090048 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00090048(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226d60 = 1;
  iVar1 = FUN_000e0e7c(@"noContentWarning");
  if (iVar1 == 0) {
    (*_DAT_01226510)(param_1,param_2);
  }
  else {
    _objc_msgSend(param_1,@selector(confirmAlertDidPressConfirm));
  }
  CallSupervisor(0xc753);
  return ZEXT816(0x1f);
}


