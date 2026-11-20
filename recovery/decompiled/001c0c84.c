/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0c84. FUN_001c0c84 */

undefined1  [16] FUN_001c0c84(long param_1)

{
  undefined1 auVar1 [16];
  
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_isAnimating) = 0;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_processQueue_0114dd18);
  CallSupervisor(0xd30f);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


