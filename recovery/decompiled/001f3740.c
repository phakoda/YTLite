/* Decompiled from supplied 5.2.2 arm package. VA 0x1f3740. openVideoWithID:viewController: */

/* Function Stack Size: 0x20 bytes */

void YTPPlayerHelper::openVideoWithID_viewController_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  DAT_01227fa4 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  uVar1 = _objc_getClass(s_YTICommand_011bda23);
  _objc_msgSend(uVar1,PTR_s_watchNavigationEndpointWithVideo_0114e248,param_3);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) {
    _objc_msgSend(param_1,PTR_s_openVideoWithID__0114e240,param_3);
  }
  else {
    uVar1 = _objc_getClass((&PTR_LAB_011bdd48)[lVar2 == 0] +
                           (int)-(uRam00000000011bdd58 ^ 0x3073c2d7),
                           s_YTCommandResponderEvent_011bda00);
    _objc_msgSend(param_4,PTR_s_view_0114b090);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_eventWithCommand_fromView_entry__0114e258,lVar2,uVar3,param_4,0,
                  param_4);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    _objc_msgSend(uVar1,PTR_s_send_0114e260);
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0xb65b);
  return;
}


