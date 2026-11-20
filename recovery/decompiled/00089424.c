/* Decompiled from supplied 5.2.2 arm package. VA 0x89424. FUN_00089424 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00089424(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226cf4 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000df548(&PTR____CFConstantStringClassReference_011680c0);
  if (iVar1 == 0) {
    (*_DAT_01226458)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x2924);
  return ZEXT816(0x1f);
}


