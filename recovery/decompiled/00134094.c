/* Decompiled from supplied 5.2.2 arm package. VA 0x134094. switchForKey: */

/* Function Stack Size: 0x18 bytes */

ID TabbarVC::switchForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  
  DAT_01227400 = 1;
  _objc_retain(param_3);
  _NSClassFromString(&PTR____CFConstantStringClassReference_0118f5e0);
  uVar1 = _objc_alloc_init();
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_tintColor_0114d1b8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setOnTintColor__0114d3d8,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_grayColor_0114d3b8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3fe0000000000000,uVar2,PTR_s_colorWithAlphaComponent__0114b548);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setOffTrackColor__0114d538,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = FUN_001380dc(uVar2,PTR_s_boolForKey__0114ada8,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar1,PTR_s_setOn__0114d540,uVar3);
  _objc_release(uVar2);
  _objc_msgSend(uVar1,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_toggleSwitch__0114d548,0x1000);
  IVar4 = _objc_autoreleaseReturnValue(uVar1);
  return IVar4;
}


