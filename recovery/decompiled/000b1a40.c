/* Decompiled from supplied 5.2.2 arm package. VA 0xb1a40. FUN_000b1a40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b1a40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e84 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e870c(&PTR____CFConstantStringClassReference_0116fcf0);
  if (iVar1 == 0) {
    (*_DAT_01226710)(param_1,param_2,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


