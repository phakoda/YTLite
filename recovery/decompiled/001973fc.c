/* Decompiled from supplied 5.2.2 arm package. VA 0x1973fc. FUN_001973fc */

undefined1  [16] FUN_001973fc(long param_1)

{
  undefined1 auVar1 [16];
  
  _objc_destroyWeak(param_1 + 0x30);
  _objc_release(*(undefined8 *)(param_1 + 0x28));
  _objc_release(*(undefined8 *)(param_1 + 0x20));
  CallSupervisor(0xe0ac);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


