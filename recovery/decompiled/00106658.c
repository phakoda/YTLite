/* Decompiled from supplied 5.2.2 arm package. VA 0x106658. FUN_00106658 */

undefined1  [16] FUN_00106658(long param_1)

{
  __Block_object_dispose(*(void **)(param_1 + 0x68),8);
  __Block_object_dispose(*(void **)(param_1 + 0x60),8);
  _objc_release(*(undefined8 *)(param_1 + 0x58));
  _objc_release(*(undefined8 *)(param_1 + 0x50));
  _objc_release(*(undefined8 *)(param_1 + 0x48));
  _objc_release(*(undefined8 *)(param_1 + 0x40));
  _objc_release(*(undefined8 *)(param_1 + 0x38));
  _objc_release(*(undefined8 *)(param_1 + 0x30));
  _objc_release(*(undefined8 *)(param_1 + 0x28));
  _objc_release(*(undefined8 *)(param_1 + 0x20));
  CallSupervisor(0x9578);
  return ZEXT816(0x1f);
}


