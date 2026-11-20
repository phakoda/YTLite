/* Decompiled from supplied 5.2.2 arm package. VA 0x66a5c. FUN_00066a5c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066a5c(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a84 = 1;
  iVar1 = FUN_000d6e70(&PTR____CFConstantStringClassReference_01161c70);
  if (iVar1 == 0) {
    (*_DAT_01226028)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


