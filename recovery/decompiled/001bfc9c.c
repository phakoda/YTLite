/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfc9c. keyboardWillHide: */

/* Function Stack Size: 0x18 bytes */

void ToastView::keyboardWillHide_(ID param_1,SEL param_2,ID param_3)

{
  *(undefined8 *)(param_1 + (long)_keyboardHeight) = 0;
  _objc_msgSend(param_1,PTR_s_updateLayout_0114ddb0);
  CallSupervisor(0xcd51);
  return;
}


