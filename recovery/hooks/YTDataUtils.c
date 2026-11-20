// Decompiled hook evidence for YTDataUtils. This is not compilable Logos source.

// +[YTDataUtils spamSignalsDictionary], original IMP slot 0x01226068
/* Decompiled from supplied 5.2.2 arm package. VA 0x671e4. FUN_000671e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000671e4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226aa4 = 1;
  iVar1 = FUN_000d6f44(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226068)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_retain(*(undefined8 *)PTR____NSDictionary0___01060678);
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}



// +[YTDataUtils spamSignalsDictionaryWithoutIDFA], original IMP slot 0x01226070
/* Decompiled from supplied 5.2.2 arm package. VA 0x67350. FUN_00067350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00067350(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226aa8 = 1;
  iVar1 = FUN_000d6f68(@"noAds");
  if (iVar1 == 0) {
    (*_DAT_01226070)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_retain(*(undefined8 *)PTR____NSDictionary0___01060678);
  }
  _objc_autoreleaseReturnValue();
  return;
}


