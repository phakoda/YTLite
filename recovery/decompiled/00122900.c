/* Decompiled from supplied 5.2.2 arm package. VA 0x122900. sliderWithKey:min:max: */

/* Function Stack Size: 0x28 bytes */

ID DVNTableViewController::sliderWithKey_min_max_
             (ID param_1,SEL param_2,ID param_3,double param_4,double param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  undefined4 uVar8;
  
  puVar1 = PTR__OBJC_CLASS___UISlider_0114ee50;
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_tintColor_0114d1b8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend((float)param_4,uVar2,PTR_s_setMinimumValue__0114d598);
  _objc_msgSend((float)param_5,uVar2,PTR_s_setMaximumValue__0114d5a0);
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(uVar3,PTR_s_floatForKey__0114c308,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar8,uVar2,PTR_s_setValue__0114d560);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIGraphicsImageRenderer_0114ec88);
  uVar3 = _objc_msgSend(0x4028000000000000,0x402e000000000000,uVar3,PTR_s_initWithSize__0114b938);
  _objc_msgSend(uVar3,PTR_s_imageWithActions__0114b950,&PTR___NSConcreteGlobalBlock_01062530);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setThumbImage_forState__0114d5b0,uVar4,0);
  _objc_msgSend(uVar2,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_sliderValueChanged__0114d5b8,0x1000);
  _objc_msgSend(uVar2,PTR_s_heightAnchor_0114b638);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x403e000000000000,uVar5,PTR_s_constraintEqualToConstant__0114b640);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setActive__0114b5a8,1);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}


