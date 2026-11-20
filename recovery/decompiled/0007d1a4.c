/* Decompiled from supplied 5.2.2 arm package. VA 0x7d1a4. FUN_0007d1a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0007d1a4(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226be4 = 1;
  iVar1 = FUN_000dca60(&PTR____CFConstantStringClassReference_01165df0);
  if (iVar1 == 0) {
    (*_DAT_01226280)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(param_1,PTR_s_blackPure_0114c850);
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


