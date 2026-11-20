/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2b1c. isLandscape */

/* Function Stack Size: 0x10 bytes */

bool ToastView::isLandscape(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_connectedScenes_0114dcc8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_allObjects_0114cac0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_firstObject_0114b748);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  lVar5 = _objc_msgSend(uVar4,PTR_s_interfaceOrientation_0114dea0);
  _objc_release(uVar4);
  return (bool)(lVar5 - 3U < 2);
}


