/* Decompiled from supplied 5.2.2 arm package. VA 0x23973c. makePresetButton: */

/* Function Stack Size: 0x18 bytes */

ID YTPSpeedControlView::makePresetButton_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  float fVar7;
  
  puVar2 = PTR__OBJC_CLASS___UIButton_0114ec38;
  puVar1 = PTR_s_buttonWithType__0114b6a0;
  DAT_012284d0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar2 = PTR_s_floatValue_0114c768;
  fVar7 = (float)_objc_msgSend(param_3,PTR_s_floatValue_0114c768);
  thunk_FUN_0023aef0((double)fVar7,puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d2100);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTitle_forState__0114b6a8,uVar4,0);
  _objc_release(uVar4);
  puVar1 = PTR_s_labelColor_0114aff8;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTitleColor_forState__0114b6b0,uVar4,0);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s_presetTapped__0114e880,0x40);
  _objc_msgSend(0x4028000000000000,*(undefined8 *)PTR__UIFontWeightMedium_01060570,
                PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize_weight__0114d330);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_titleLabel_0114b6d8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setFont__0114b5e8,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c258,uVar4,PTR_s_colorWithAlphaComponent__0114b548);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setBackgroundColor__0114b550,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_layer_0114ae60);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4030000000000000,uVar4,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar4);
  fVar7 = (float)_objc_msgSend(param_3,puVar2);
  _objc_release(param_3);
  _objc_msgSend(uVar3,PTR_s_setTag__0114b858,(long)(fVar7 * 100.0));
  _objc_msgSend(uVar3,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  _objc_msgSend(uVar3,PTR_s_heightAnchor_0114b638);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4040000000000000,uVar4,PTR_s_constraintEqualToConstant__0114b640);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setActive__0114b5a8,1);
  _objc_release(uVar5);
  _objc_release(uVar4);
  IVar6 = _objc_autoreleaseReturnValue(uVar3);
  return IVar6;
}


