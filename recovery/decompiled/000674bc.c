/* Decompiled from supplied 5.2.2 arm package. VA 0x674bc. FUN_000674bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000674bc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auVar3 [16];
  
  DAT_01226aac = 1;
  _objc_retain(param_3);
  iVar2 = FUN_000d6f8c(&PTR____CFConstantStringClassReference_01161ea0);
  uVar1 = 0;
  if (iVar2 == 0) {
    uVar1 = param_3;
  }
  (*_DAT_01226078)(param_1,param_2,uVar1);
  _objc_release(param_3);
  CallSupervisor(0xe347);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


