/* Decompiled from supplied 5.2.2 arm package. VA 0x21b54c. FUN_0021b54c */

undefined1  [16] FUN_0021b54c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01228230;
  DAT_01228230 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0x2b28);
  return ZEXT816(0x1f);
}


