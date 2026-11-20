/* Decompiled from supplied 5.2.2 arm package. VA 0x235c0c. viewDidAppear: */

/* Function Stack Size: 0x14 bytes */

void YTPSpeedPopupController::viewDidAppear_(ID param_1,SEL param_2,bool param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  ID local_40;
  undefined *puStack_38;
  
  puStack_38 = PTR_YTPSpeedPopupController_0114f158;
  local_40 = param_1;
  _objc_msgSendSuper2(&local_40,PTR_s_viewDidAppear__0114b138,param_3);
  uVar2 = _objc_msgSend(param_1,PTR_s_bottomConstant_0114e7e8);
  _objc_msgSend(param_1,PTR_s_bottomConstraint_0114e7f0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,uVar1,PTR_s_setConstant__0114b920);
  _objc_release(uVar1);
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_00235d04;
  puStack_50 = &DAT_01061420;
  local_48 = param_1;
  _objc_msgSend(DAT_00c4c300,0,DAT_00c4c250,0x3fe0000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                PTR_s_animateWithDuration_delay_usingS_0114b930,0x20000,&local_68,0);
  return;
}


