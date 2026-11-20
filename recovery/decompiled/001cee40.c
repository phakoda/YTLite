/* Decompiled from supplied 5.2.2 arm package. VA 0x1cee40. FUN_001cee40 */

undefined1  [16] FUN_001cee40(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  uVar2 = _objc_alloc_init(*(undefined8 *)(param_1 + 0x20));
  uVar1 = DAT_01227d20;
  DAT_01227d20 = uVar2;
  _objc_release(uVar1);
  CallSupervisor(0x979);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


