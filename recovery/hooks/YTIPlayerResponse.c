// Decompiled hook evidence for YTIPlayerResponse. This is not compilable Logos source.

// -[YTIPlayerResponse isMonetized], original IMP slot 0x01226020
/* Decompiled from supplied 5.2.2 arm package. VA 0x668fc. FUN_000668fc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000668fc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226a80 = 1;
  iVar1 = FUN_000d6e2c(@"noAds");
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00066a44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*_DAT_01226020)(param_1,param_2);
    return uVar2;
  }
  return 0;
}



// -[YTIPlayerResponse playerAdsArray], original IMP slot 0x01226028
/* Decompiled from supplied 5.2.2 arm package. VA 0x66a5c. FUN_00066a5c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066a5c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a84 = 1;
  iVar1 = FUN_000d6e70(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226028)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// -[YTIPlayerResponse adSlotsArray], original IMP slot 0x01226030
/* Decompiled from supplied 5.2.2 arm package. VA 0x66bcc. FUN_00066bcc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066bcc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a88 = 1;
  iVar1 = FUN_000d6e94(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226030)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// -[YTIPlayerResponse auxiliaryUi], original IMP slot 0x01226038
/* Decompiled from supplied 5.2.2 arm package. VA 0x66d40. FUN_00066d40 */

undefined8 FUN_00066d40(void)

{
  return 0;
}



// -[YTIPlayerResponse setHasAuxiliaryUi:], original IMP slot 0x01226040
/* Decompiled from supplied 5.2.2 arm package. VA 0x66d48. FUN_00066d48 */

undefined1  [16] FUN_00066d48(undefined8 param_1,undefined8 param_2)

{
  (*DAT_01226040)(param_1,param_2,0);
  CallSupervisor(0x7e93);
  return ZEXT816(0x1f);
}



// -[YTIPlayerResponse setAuxiliaryUi:], original IMP slot 0x01226048
/* Decompiled from supplied 5.2.2 arm package. VA 0x66d80. FUN_00066d80 */

undefined1  [16] FUN_00066d80(undefined8 param_1,undefined8 param_2)

{
  (*DAT_01226048)(param_1,param_2,0);
  CallSupervisor(0xa4e1);
  return ZEXT816(0x1f);
}


