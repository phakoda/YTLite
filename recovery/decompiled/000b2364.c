/* Decompiled from supplied 5.2.2 arm package. VA 0xb2364. FUN_000b2364 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b2364(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  DAT_01226e94 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000e879c(&PTR____CFConstantStringClassReference_0116fef0);
  if (iVar1 == 0) {
    (*_DAT_01226730)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xeb70);
  return ZEXT816(0x1f);
}


