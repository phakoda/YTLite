/* Decompiled from supplied 5.2.2 arm package. VA 0x7fc40. FUN_0007fc40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007fc40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226c24 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000dd280(&PTR____CFConstantStringClassReference_01166700);
  if (iVar1 == 0) {
    (*_DAT_012262f8)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x97b9);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


