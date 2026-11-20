/* Decompiled from supplied 5.2.2 arm package. VA 0x77788. FUN_00077788 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00077788(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  
  DAT_01226bc0 = 1;
  uVar1 = FUN_000db9d4(&PTR____CFConstantStringClassReference_01164c20);
  (*_DAT_01226238)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0x800);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


