/* Decompiled from supplied 5.2.2 arm package. VA 0x1bff34. handleLongPress: */

/* Function Stack Size: 0x18 bytes */

void ToastView::handleLongPress_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  if (lVar1 == 1) {
    _objc_msgSend(param_1,PTR_s_hide_0114d0a0);
  }
  CallSupervisor(0xf280);
  return;
}


