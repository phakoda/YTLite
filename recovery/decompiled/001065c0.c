/* Decompiled from supplied 5.2.2 arm package. VA 0x1065c0. FUN_001065c0 */

undefined1  [16] FUN_001065c0(long param_1,long param_2)

{
  undefined1 auVar1 [16];
  
  _objc_retain(*(undefined8 *)(param_2 + 0x20));
  _objc_retain(*(undefined8 *)(param_2 + 0x28));
  _objc_retain(*(undefined8 *)(param_2 + 0x30));
  _objc_retain(*(undefined8 *)(param_2 + 0x38));
  _objc_retain(*(undefined8 *)(param_2 + 0x40));
  _objc_retain(*(undefined8 *)(param_2 + 0x48));
  _objc_retain(*(undefined8 *)(param_2 + 0x50));
  _objc_retain(*(undefined8 *)(param_2 + 0x58));
  __Block_object_assign((void *)(param_1 + 0x60),*(void **)(param_2 + 0x60),8);
  __Block_object_assign((void *)(param_1 + 0x68),*(void **)(param_2 + 0x68),8);
  CallSupervisor(0x210f);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


