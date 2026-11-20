/* Decompiled from supplied 5.2.2 arm package. VA 0x7d568. FUN_0007d568 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0007d568(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_01226bf0 = 1;
  _objc_retain(param_3);
  iVar1 = FUN_000dcb48(&PTR____CFConstantStringClassReference_01165eb0);
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_oledForColor__0114c528,param_3);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    param_3 = uVar2;
  }
  (*_DAT_01226290)(param_1,param_2,param_3);
  _objc_release(param_3);
  CallSupervisor(0x682d);
  return ZEXT816(0x1f);
}


