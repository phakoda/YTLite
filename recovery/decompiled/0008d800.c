/* Decompiled from supplied 5.2.2 arm package. VA 0x8d800. FUN_0008d800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0008d800(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  
  DAT_01226d2c = 1;
  uVar1 = FUN_000e05a0(&PTR____CFConstantStringClassReference_01168e60);
  (*_DAT_012264a8)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff));
  CallSupervisor(0x17be);
  return ZEXT816(0x1f);
}


