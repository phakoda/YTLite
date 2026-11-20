/* Decompiled from supplied 5.2.2 arm package. VA 0x6ff6c. FUN_0006ff6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0006ff6c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226b78 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000d8de0(&PTR____CFConstantStringClassReference_011638b0);
  if (iVar1 == 0) {
    (*_DAT_012261f8)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xf88e);
  return ZEXT816(0x1f);
}


