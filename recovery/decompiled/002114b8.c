/* Decompiled from supplied 5.2.2 arm package. VA 0x2114b8. FUN_002114b8 */

undefined1  [16] FUN_002114b8(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_012280e0;
  DAT_012280e0 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0xefc1);
  return ZEXT816(0x1f);
}


