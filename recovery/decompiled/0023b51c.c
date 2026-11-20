/* Decompiled from supplied 5.2.2 arm package. VA 0x23b51c. FUN_0023b51c */

undefined1  [16] FUN_0023b51c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_012284f0;
  DAT_012284f0 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0xa52a);
  return ZEXT816(0x1f);
}


