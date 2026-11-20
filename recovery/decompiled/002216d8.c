/* Decompiled from supplied 5.2.2 arm package. VA 0x2216d8. closeButtonTapped */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::closeButtonTapped(ID param_1,SEL param_2)

{
  _objc_msgSend(param_1,PTR_s_hapticFeedback_0114e628);
  _objc_msgSend(param_1,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,0);
  CallSupervisor(0x31f6);
  return;
}


