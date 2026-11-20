// Decompiled hook evidence for YTPersonalizedSuggestionsCacheProvider. This is not compilable Logos source.

// -[YTPersonalizedSuggestionsCacheProvider activeCache], original IMP slot 0x01226200
/* Decompiled from supplied 5.2.2 arm package. VA 0x70184. FUN_00070184 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00070184(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226b7c = 1;
  iVar1 = FUN_000d8e04(@"noSearchHistory");
  if (iVar1 == 0) {
    (*_DAT_01226200)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


