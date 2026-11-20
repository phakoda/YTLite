/* Decompiled from supplied 5.2.2 arm package. VA 0x66f14. FUN_00066f14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066f14(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a9c = 1;
  iVar1 = FUN_000d6efc(&PTR____CFConstantStringClassReference_01161d60);
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


