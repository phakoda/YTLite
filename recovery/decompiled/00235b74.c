/* Decompiled from supplied 5.2.2 arm package. VA 0x235b74. speedController */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedPopupController::speedController(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID IVar2;
  
  uVar1 = _objc_alloc_init(PTR_YTPSpeedPopupController_0114ed70);
  _objc_msgSend(uVar1,PTR_s_setModalPresentationStyle__0114b958,6);
  _objc_msgSend(uVar1,PTR_s_setModalTransitionStyle__0114e7e0,2);
  IVar2 = _objc_autoreleaseReturnValue(uVar1);
  return IVar2;
}


