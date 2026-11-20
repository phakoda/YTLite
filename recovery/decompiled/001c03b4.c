/* Decompiled from supplied 5.2.2 arm package. VA 0x1c03b4. updateText:progress:animated: */

/* Function Stack Size: 0x20 bytes */

void ToastView::updateText_progress_animated_
               (ID param_1,SEL param_2,ID param_3,float param_4,bool param_5)

{
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastLabel),PTR_s_setText__0114b388);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_toastProgress),
                PTR_s_setProgress_animated__0114dd28,param_5);
  CallSupervisor(0x51b3);
  return;
}


