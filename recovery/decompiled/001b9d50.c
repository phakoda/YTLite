/* Decompiled from supplied 5.2.2 arm package. VA 0x1b9d50. initialize */

/* Function Stack Size: 0x10 bytes */

void ToastView::initialize(ID param_1,SEL param_2)

{
  ID IVar1;
  
  IVar1 = _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_class_0114ae88);
  if (IVar1 == param_1) {
    _objc_msgSend(param_1,PTR_s_toastWindow_0114b960);
    _objc_unsafeClaimAutoreleasedReturnValue();
  }
  CallSupervisor(0xed57);
  return;
}


