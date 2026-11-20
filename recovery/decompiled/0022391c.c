/* Decompiled from supplied 5.2.2 arm package. VA 0x22391c. FUN_0022391c */

undefined1  [16] FUN_0022391c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01228318;
  DAT_01228318 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0x58c6);
  return ZEXT816(0x1f);
}


