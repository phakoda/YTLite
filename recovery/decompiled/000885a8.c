/* Decompiled from supplied 5.2.2 arm package. VA 0x885a8. FUN_000885a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000885a8(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  DAT_01226cd4 = 1;
  uVar1 = FUN_000df350(&PTR____CFConstantStringClassReference_01167de0);
  (*_DAT_01226420)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff),param_4);
  CallSupervisor(0x5688);
  return ZEXT816(0x1f);
}


