/* Decompiled from supplied 5.2.2 arm package. VA 0x23c1e0. prepareForPresentation */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::prepareForPresentation(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,PTR_s_layer_0114ae60);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeAllAnimations_0114dd60);
  _objc_release(uVar1);
  _objc_msgSend(param_1,PTR_s_removeFromSuperview_0114b708);
  _objc_msgSend(0,param_1,PTR_s_setAlpha__0114b698);
  CallSupervisor(0x36d);
  return;
}


