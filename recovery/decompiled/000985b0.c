/* Decompiled from supplied 5.2.2 arm package. VA 0x985b0. FUN_000985b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000985b0(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined1 auVar2 [16];
  
  DAT_01226db8 = 1;
  uVar1 = FUN_000e32b0(&PTR____CFConstantStringClassReference_0116aec0);
  (*_DAT_012265b0)(param_1,param_2,uVar1 | param_3);
  CallSupervisor(0x4454);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


