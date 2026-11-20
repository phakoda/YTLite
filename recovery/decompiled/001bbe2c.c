/* Decompiled from supplied 5.2.2 arm package. VA 0x1bbe2c. processQueue */

/* Function Stack Size: 0x10 bytes */

void ToastView::processQueue(ID param_1,SEL param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = (long)_isAnimating;
  if (*(char *)(param_1 + lVar2) == '\0') {
    lVar3 = (long)_commandQueue;
    lVar1 = _objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_count_0114b840);
    if (lVar1 != 0) {
      *(undefined1 *)(param_1 + lVar2) = 1;
      _objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_firstObject_0114b748);
      lVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_removeObjectAtIndex__0114cdd0,0);
      (**(code **)(lVar2 + 0x10))(lVar2);
      _objc_release(lVar2);
    }
  }
  CallSupervisor(0x97bc);
  return;
}


