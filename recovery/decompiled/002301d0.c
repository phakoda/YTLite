/* Decompiled from supplied 5.2.2 arm package. VA 0x2301d0. createYTQTMButton:accessibilityLabel:buttonLabel:icon:size:selector: */

/* Function Stack Size: 0x48 bytes */

ID YTLHelper::createYTQTMButton_accessibilityLabel_buttonLabel_icon_size_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,CGSize param_7,
             SEL param_8)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  DAT_01228408 = 1;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar3 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0ce0);
  _objc_msgSend(uVar3,PTR_s_iconButton_0114d220);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setAccessibilityLabel__0114e7a8,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar3,PTR_s_enableNewTouchFeedback_0114d228);
  if (param_6 == 0) {
    _objc_msgSend(uVar3,PTR_s_setTitle_forState__0114b6a8,param_5,0);
    _objc_msgSend(uVar3,PTR_s_titleLabel_0114b6d8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setAdjustsFontSizeToFitWidth__0114b740,1);
    _objc_release(uVar4);
  }
  else {
    _objc_msgSend(uVar3,PTR_s_setImage_forState__0114adf0,param_6,0);
  }
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  _objc_msgSend(uVar3,PTR_s_addTarget_action_forControlEvent_0114b830,param_3,param_8,0x40);
  _objc_release(param_3);
  _objc_msgSend(uVar3,PTR_s_widthAnchor_0114b648);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_constraintEqualToConstant__0114b640;
  _objc_msgSend(param_7.field0_0x0,uVar4,PTR_s_constraintEqualToConstant__0114b640);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_setActive__0114b5a8;
  _objc_msgSend(uVar5,PTR_s_setActive__0114b5a8,1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_heightAnchor_0114b638);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_7.field1_0x8,uVar4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar1,1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_6);
  _objc_release(param_5);
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}


