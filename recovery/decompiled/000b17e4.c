/* Decompiled from supplied 5.2.2 arm package. VA 0xb17e4. FUN_000b17e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b17e4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e80 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e86e8(&PTR____CFConstantStringClassReference_0116fc70);
  if (iVar1 == 0) {
    (*_DAT_01226708)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


