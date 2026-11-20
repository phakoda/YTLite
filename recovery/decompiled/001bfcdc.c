/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfcdc. cleanup */

/* Function Stack Size: 0x10 bytes */

void ToastView::cleanup(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  _objc_msgSend(param_1,PTR_s_layer_0114ae60);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_removeAllAnimations_0114dd60);
  _objc_release(uVar1);
  lVar2 = (long)_progressTimer;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_invalidate_0114de10);
  uVar1 = *(undefined8 *)(param_1 + lVar2);
  *(undefined8 *)(param_1 + lVar2) = 0;
  _objc_release(uVar1);
  *(undefined1 *)(param_1 + (long)_ignoresPanGesture) = 0;
  *(undefined1 *)(param_1 + (long)_ignoresFullscreenOpacity) = 0;
  _objc_msgSend(param_1,PTR_s_removeFromSuperview_0114b708);
  _objc_msgSend(param_1,PTR_s_removeObservers_0114de18);
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_unregisterToast__0114de20,param_1);
  _objc_release(uVar1);
  CallSupervisor(0x1a38);
  return;
}


