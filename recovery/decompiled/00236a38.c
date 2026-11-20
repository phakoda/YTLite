/* Decompiled from supplied 5.2.2 arm package. VA 0x236a38. dismiss */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedPopupController::dismiss(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  double in_d3;
  undefined *local_90;
  undefined8 local_88;
  code *local_80;
  undefined *puStack_78;
  ID local_70;
  undefined *puStack_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  ID local_48;
  
  _objc_msgSend(param_1,PTR_s_speedView_0114e808);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_bounds_0114b568);
  _objc_msgSend(param_1,PTR_s_bottomConstraint_0114e7f0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(in_d3 + 50.0,uVar2,PTR_s_setConstant__0114b920);
  _objc_release(uVar2);
  _objc_release(uVar1);
  puStack_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_00236b84;
  puStack_50 = &DAT_01061420;
  local_90 = PTR___NSConcreteStackBlock_01060660;
  local_88 = DAT_00c4c228;
  local_80 = FUN_00236c30;
  puStack_78 = &DAT_01061940;
  local_70 = param_1;
  local_48 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0,0x3ff0000000000000,
                *(double *)(param_1 + (long)_dismissVelocity) / DAT_00c4c4a0,
                PTR__OBJC_CLASS___UIView_0114ec30,PTR_s_animateWithDuration_delay_usingS_0114b930,
                0x10000,&puStack_68,&local_90);
  CallSupervisor(0x2f6a);
  return;
}


