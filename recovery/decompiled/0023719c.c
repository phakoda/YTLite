/* Decompiled from supplied 5.2.2 arm package. VA 0x23719c. gestureRecognizer:shouldReceiveTouch: */

/* Function Stack Size: 0x20 bytes */

bool YTPSpeedPopupController::gestureRecognizer_shouldReceiveTouch_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(param_4,PTR_s_view_0114b090);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(lVar2);
  return (bool)(lVar2 == lVar3);
}


