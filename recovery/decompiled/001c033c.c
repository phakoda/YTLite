/* Decompiled from supplied 5.2.2 arm package. VA 0x1c033c. updateText:progress: */

/* Function Stack Size: 0x1c bytes */

void ToastView::updateText_progress_(ID param_1,SEL param_2,ID param_3,float param_4)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),PTR_s_setText__0114b388);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                PTR_s_setProgress_animated__0114dd28,1);
  CallSupervisor(0x1a9b);
  return;
}


