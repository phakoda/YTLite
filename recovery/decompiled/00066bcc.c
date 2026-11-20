/* Decompiled from supplied 5.2.2 arm package. VA 0x66bcc. FUN_00066bcc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00066bcc(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  DAT_01226a88 = 1;
  iVar1 = FUN_000d6e94(&PTR____CFConstantStringClassReference_01161cc0);
  if (iVar1 == 0) {
    (*_DAT_01226030)(param_1,param_2);
    _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    _objc_retainAutoreleasedReturnValue();
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)();
  return;
}


