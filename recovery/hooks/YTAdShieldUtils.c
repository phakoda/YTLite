// Decompiled hook evidence for YTAdShieldUtils. This is not compilable Logos source.

// +[YTAdShieldUtils spamSignalsDictionary], original IMP slot 0x01226058
/* Decompiled from supplied 5.2.2 arm package. VA 0x66f14. FUN_00066f14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066f14(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a9c = 1;
  iVar1 = FUN_000d6efc(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226058)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_retain(*(undefined8 *)PTR____NSDictionary0___01060678);
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTAdShieldUtils spamSignalsDictionaryWithoutIDFA], original IMP slot 0x01226060
/* Decompiled from supplied 5.2.2 arm package. VA 0x6707c. FUN_0006707c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006707c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226aa0 = 1;
  iVar1 = FUN_000d6f20(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226060)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_retain(*(undefined8 *)PTR____NSDictionary0___01060678);
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


