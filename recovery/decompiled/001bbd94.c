/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbd94. enqueueCommand: */

/* Function Stack Size: 0x18 bytes */

void ToastView::enqueueCommand_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + (long)_commandQueue);
  uVar1 = _objc_msgSend(param_3,PTR_s_copy_0114b058,param_3,param_4);
  uVar2 = _objc_retainBlock();
  _objc_msgSend(uVar3,PTR_s_addObject__0114b3a0,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  _objc_msgSend(param_1,PTR_s_processQueue_0114dd18);
  CallSupervisor(0x567c);
  return;
}


