/* Decompiled from supplied 5.2.2 arm package. VA 0xb2140. FUN_000b2140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b2140(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auVar2 [16];
  
  DAT_01226e90 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e8778(&PTR____CFConstantStringClassReference_0116fe70);
  if (iVar1 == 0) {
    (*_DAT_01226728)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0x5b55);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


