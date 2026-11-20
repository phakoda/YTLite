/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4204. FUN_001f4204 */

undefined1  [16] FUN_001f4204(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01227fa8;
  DAT_01227fa8 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0xe2d2);
  return ZEXT816(0x1f);
}


