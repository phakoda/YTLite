/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2760. hideImmediately */

/* Function Stack Size: 0x10 bytes */

void ToastView::hideImmediately(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
  _objc_msgSend(param_1,PTR_s_processQueue_0114dd18);
  CallSupervisor(0xe053);
  return;
}


