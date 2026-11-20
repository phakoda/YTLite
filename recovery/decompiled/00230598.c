/* Decompiled from supplied 5.2.2 arm package. VA 0x230598. createOverlayButton:accessibilityLabel:buttonLabel:icon:selector: */

/* Function Stack Size: 0x38 bytes */

ID YTLHelper::createOverlayButton_accessibilityLabel_buttonLabel_icon_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,SEL param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_0122840c = 1;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar4 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0d40);
  _objc_msgSend(uVar4,PTR_s_iconButton_0114d220);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setAccessibilityLabel__0114e7a8,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar4,PTR_s_enableNewTouchFeedback_0114d228);
  if (param_6 == 0) {
    _objc_msgSend(uVar4,PTR_s_setTitle_forState__0114b6a8,param_5,0);
    _objc_msgSend(uVar4,PTR_s_titleLabel_0114b6d8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setAdjustsFontSizeToFitWidth__0114b740,1);
  }
  else {
    _objc_msgSend(param_6,PTR_s_imageWithRenderingMode__0114b850,2);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setImage_forState__0114adf0,uVar5,0);
  }
  _objc_release(uVar5);
  puVar1 = PTR_s_whiteColor_0114b080;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setTintColor__0114b000,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  _objc_msgSend(uVar4,PTR_s_addTarget_action_forControlEvent_0114b830,param_3,param_7,0x40);
  _objc_release(param_3);
  _objc_msgSend(uVar4,PTR_s_widthAnchor_0114b648);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_constraintEqualToConstant__0114b640;
  _objc_msgSend(0x4038000000000000,uVar5,PTR_s_constraintEqualToConstant__0114b640);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_setActive__0114b5a8;
  _objc_msgSend(uVar6,PTR_s_setActive__0114b5a8,1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,PTR_s_heightAnchor_0114b638);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4042000000000000,uVar5,puVar3);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,puVar2,1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar2 = PTR_s_touchFeedbackView_0114c910;
  _objc_msgSend(uVar4,PTR_s_touchFeedbackView_0114c910);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setForceCircularTouchFeedback__0114e7b0,1);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,0xc018000000000000,0,0xc018000000000000,uVar5,
                PTR_s_setTouchFeedbackInsets__0114e7b8);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setCustomTouchFeedbackColor__0114c918,uVar5);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_6);
  _objc_release(param_5);
  IVar7 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar7;
}


