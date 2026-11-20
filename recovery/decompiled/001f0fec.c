/* Decompiled from supplied 5.2.2 arm package. VA 0x1f0fec. dismissController */

/* Function Stack Size: 0x10 bytes */

void PseudoDetentController::dismissController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,PTR_s_presentedViewController_0114e1e8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,0);
  _objc_release(uVar1);
  CallSupervisor(0xd1bb);
  return;
}


