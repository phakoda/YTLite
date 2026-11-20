/* Decompiled from supplied 5.2.2 arm package. VA 0x671e4. FUN_000671e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000671e4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226aa4 = 1;
  iVar1 = FUN_000d6f44(&PTR____CFConstantStringClassReference_01161e00);
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


