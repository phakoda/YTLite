/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2444. gestureRecognizer:shouldReceiveTouch: */

/* Function Stack Size: 0x20 bytes */

bool DVNLongPressDelegate::gestureRecognizer_shouldReceiveTouch_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 in_d1;
  
  puVar1 = PTR_s_view_0114b090;
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(param_4,PTR_s_locationInView__0114c978,uVar3);
  _objc_release(param_4);
  _objc_release(uVar3);
  bVar2 = FUN_001f264c(uVar4,in_d1,param_1,PTR_s_isTouchInSpeedZone__0114cca0);
  return bVar2;
}


