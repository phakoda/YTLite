/* Decompiled from supplied 5.2.2 arm package. VA 0x88710. FUN_00088710 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00088710(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226cd8 = 1;
  iVar1 = FUN_000df374(&PTR____CFConstantStringClassReference_01167e60);
  if (iVar1 == 0) {
    (*_DAT_01226428)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


