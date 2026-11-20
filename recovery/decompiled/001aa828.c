/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa828. FUN_001aa828 */

undefined1  [16] FUN_001aa828(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01227988;
  DAT_01227988 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0xf5b8);
  return ZEXT816(0x1f);
}


