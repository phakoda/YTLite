/* Decompiled from supplied 5.2.2 arm package. VA 0xb1edc. FUN_000b1edc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b1edc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226e8c = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e8754(&PTR____CFConstantStringClassReference_0116fdf0);
  if (iVar1 == 0) {
    (*_DAT_01226720)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xe5fe);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


