// Decompiled hook evidence for YTAccountScopedAdsInnerTubeContextDecorator. This is not compilable Logos source.

// -[YTAccountScopedAdsInnerTubeContextDecorator decorateContext:], original IMP slot 0x01226080
/* Decompiled from supplied 5.2.2 arm package. VA 0x6760c. FUN_0006760c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0006760c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  
  DAT_01226ab0 = 1;
  _objc_retain(param_3);
  iVar2 = FUN_000d6fb0(@"noAds");
  uVar1 = 0;
  if (iVar2 == 0) {
    uVar1 = param_3;
  }
  (*_DAT_01226080)(param_1,param_2,uVar1);
  _objc_release(param_3);
  CallSupervisor(0x258d);
  return ZEXT816(0x1f);
}


