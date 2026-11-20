/* Decompiled from supplied 5.2.2 arm package. VA 0x1bee14. configureToastAppearanceWithBottomOffset:topOffset:scale:width:animationDuration: */

/* Function Stack Size: 0x38 bytes */

void ToastView::configureToastAppearanceWithBottomOffset_topOffset_scale_width_animationDuration_
               (ID param_1,SEL param_2,double param_3,double param_4,double param_5,double param_6,
               double param_7)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  ID IStack_60;
  double dStack_58;
  uint local_4c;
  undefined **local_48;
  
  puVar1 = PTR_s_setConstant__0114b920;
  local_48 = &PTR_LAB_011b4358;
  _objc_msgSend(-param_3,*(undefined8 *)(param_1 + (long)_bottomConstraint),
                PTR_s_setConstant__0114b920);
  _objc_msgSend(param_6,*(undefined8 *)(param_1 + (long)_widthConstraint),puVar1);
  _objc_msgSend(param_4,*(undefined8 *)(param_1 + (long)_topConstraint),puVar1);
  bVar2 = *(char *)(param_1 + (long)_ignoresFullscreenOpacity) == '\0';
  local_4c = (uint)bVar2;
  if (bVar2) {
    uVar3 = FUN_001c61e4(param_1,PTR_s_isFullscreen_0114c730);
    _objc_msgSend(param_1,PTR_s_setHidden__0114bfc0,uVar3);
  }
  puStack_80 = PTR___NSConcreteStackBlock_01060660;
  uStack_78 = DAT_00c4c228;
  pcStack_70 = FUN_001befa0;
  puStack_68 = &DAT_01061810;
  IStack_60 = param_1;
  dStack_58 = param_5;
  _objc_msgSend(param_7,0,0x3ff0000000000000,0x402e000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                PTR_s_animateWithDuration_delay_usingS_0114b930,0,&puStack_80,0);
  CallSupervisor(0xa031);
  return;
}


