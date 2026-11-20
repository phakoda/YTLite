/* Decompiled from supplied 5.2.2 arm package. VA 0x1c269c. FUN_001c269c */

undefined1  [16] FUN_001c269c(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x20) + (long)ToastView::_isAnimating) = 0;
  if (*(long *)(param_1 + 0x28) == 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_cleanup_0114de90);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_processQueue_0114dd18);
  }
  else {
    (**(code **)(*(long *)(param_1 + 0x28) + 0x10))();
  }
  CallSupervisor(0xe19b);
  return ZEXT816(0x1f);
}


