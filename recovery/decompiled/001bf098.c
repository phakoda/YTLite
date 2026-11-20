/* Decompiled from supplied 5.2.2 arm package. VA 0x1bf098. configureToastAppearanceWithBottomOffset:topOffset:scale:width:alpha:animationDuration:completion: */

/* Function Stack Size: 0x48 bytes */

void ToastView::
     configureToastAppearanceWithBottomOffset_topOffset_scale_width_alpha_animationDuration_completion_
               (ID param_1,SEL param_2,double param_3,double param_4,double param_5,double param_6,
               double param_7,double param_8,ID param_9,undefined4 param_10)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined *puStack_a8;
  ID local_a0;
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *puStack_80;
  ID local_78;
  double local_70;
  double dStack_68;
  
  _objc_retain(param_9,param_2,param_9,param_10);
  puVar1 = PTR_s_setConstant__0114b920;
  _objc_msgSend(-param_3,*(undefined8 *)(param_1 + (long)_bottomConstraint),
                PTR_s_setConstant__0114b920);
  _objc_msgSend(param_6,*(undefined8 *)(param_1 + (long)_widthConstraint),puVar1);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_topConstraint),puVar1);
  puVar2 = PTR__OBJC_CLASS___UIView_0114ec30;
  puVar1 = PTR_s_animateWithDuration_delay_usingS_0114b930;
  local_98 = PTR___NSConcreteStackBlock_01060660;
  local_90 = DAT_00c4c228;
  local_88 = FUN_001bf1f4;
  puStack_80 = &DAT_01062a70;
  local_c0 = PTR___NSConcreteStackBlock_01060660;
  local_b8 = DAT_00c4c228;
  local_b0 = FUN_001bf2e4;
  puStack_a8 = &DAT_01062aa0;
  local_a0 = param_9;
  local_78 = param_1;
  local_70 = param_7;
  dStack_68 = param_5;
  _objc_retain(param_9);
  _objc_msgSend(param_8,0,0x3ff0000000000000,0x402e000000000000,puVar2,puVar1,0,&local_98,&local_c0)
  ;
  _objc_release(local_a0);
  _objc_release(param_9);
  return;
}


