/* Decompiled from supplied 5.2.2 arm package. VA 0x2300f8. createYTQTMButton:accessibilityLabel:buttonLabel:icon:selector: */

/* Function Stack Size: 0x38 bytes */

ID YTLHelper::createYTQTMButton_accessibilityLabel_buttonLabel_icon_selector_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,SEL param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_s_class_0114ae88;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_msgSend(param_1,puVar1);
  _objc_msgSend(0x4044000000000000,0x4044000000000000,uVar2,
                PTR_s_createYTQTMButton_accessibilityL_0114c908,param_3,param_4,param_5,param_6,
                param_7);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


