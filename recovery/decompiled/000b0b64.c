/* Decompiled from supplied 5.2.2 arm package. VA 0xb0b64. FUN_000b0b64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b0b64(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  DAT_01226e74 = 1;
  uVar1 = FUN_000e8444(&PTR____CFConstantStringClassReference_0116fa00);
  (*_DAT_012266f0)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff),param_4);
  CallSupervisor(0xddf8);
  return ZEXT816(0x1f);
}


