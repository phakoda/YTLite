/* Decompiled from supplied 5.2.2 arm package. VA 0xb9d64. FUN_000b9d64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b9d64(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226ef4 = 1;
  iVar1 = FUN_000eae48(&PTR____CFConstantStringClassReference_01171160);
  if (iVar1 == 0) {
    (*_DAT_012267d8)(param_1,param_2);
    DAT_0115cd38 = 1;
  }
  CallSupervisor(0xb423);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


