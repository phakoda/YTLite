/* Decompiled from supplied 5.2.2 arm package. VA 0x8e340. FUN_0008e340 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008e340(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  
  DAT_01226d34 = 1;
  uVar1 = FUN_000e0878(&PTR____CFConstantStringClassReference_01169030);
  (*_DAT_012264b8)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0xa510);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


