/* Decompiled from supplied 5.2.2 arm package. VA 0x88b14. FUN_00088b14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00088b14(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226ce0 = 1;
  iVar1 = FUN_000df3bc(&PTR____CFConstantStringClassReference_01167f20);
  if (iVar1 == 0) {
    (*_DAT_01226438)(param_1,param_2);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    uVar2 = 0;
  }
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


