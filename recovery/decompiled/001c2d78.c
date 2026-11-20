/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2d78. dealloc */

/* Function Stack Size: 0x10 bytes */

void ToastView::dealloc(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  _objc_msgSend(param_1,PTR_s_removeObservers_0114de18);
  puStack_28 = PTR_ToastView_0114f0e8;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_dealloc_0114d678);
  CallSupervisor(0xb073);
  return;
}


