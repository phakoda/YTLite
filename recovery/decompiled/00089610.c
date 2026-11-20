/* Decompiled from supplied 5.2.2 arm package. VA 0x89610. FUN_00089610 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00089610(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226cf8 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000df56c(&PTR____CFConstantStringClassReference_01168140);
  if (iVar1 == 0) {
    (*_DAT_01226460)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xbce4);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


