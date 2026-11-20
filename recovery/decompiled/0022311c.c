/* Decompiled from supplied 5.2.2 arm package. VA 0x22311c. createButtonWithImage:target:action:menu: */

/* Function Stack Size: 0x30 bytes */

ID BlurButton::createButtonWithImage_target_action_menu_
             (ID param_1,SEL param_2,ID param_3,ID param_4,SEL param_5,ID param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ID IVar8;
  
  _objc_retain(param_4);
  _objc_retain(param_6);
  puVar2 = PTR_BlurButton_0114f018;
  puVar1 = PTR_s_buttonWithType__0114b6a0;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_setFrame__0114b570;
  _objc_msgSend(0,0,0x403c000000000000,0x403c000000000000,lVar3,PTR_s_setFrame__0114b570);
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,PTR_s_effectWithStyle__0114b558,0x10);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  uVar5 = _objc_msgSend(uVar5,PTR_s_initWithEffect__0114b560,uVar4);
  _objc_msgSend(lVar3,PTR_s_bounds_0114b568);
  _objc_msgSend(uVar5,puVar1);
  _objc_msgSend(uVar5,PTR_s_layer_0114ae60);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x402c000000000000,uVar6,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar6);
  _objc_msgSend(uVar5,PTR_s_setClipsToBounds__0114b900,1);
  _objc_msgSend(uVar5,PTR_s_setUserInteractionEnabled__0114b820,0);
  puVar1 = PTR_s_addSubview__0114b0a8;
  _objc_msgSend(lVar3,PTR_s_addSubview__0114b0a8,uVar5);
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  uVar6 = _objc_msgSend(0,0,0x4032000000000000,0x4032000000000000,uVar6,
                        PTR_s_initWithFrame__0114b770);
  _objc_msgSend(uVar5,PTR_s_center_0114b098);
  _objc_msgSend(uVar6,PTR_s_setCenter__0114b0a0);
  _objc_msgSend(uVar6,PTR_s_setContentMode__0114b728,4);
  _objc_msgSend(uVar6,PTR_s_setImage__0114b8f8,param_3);
  _objc_release(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_setTintColor__0114b000,uVar7);
  _objc_release(uVar7);
  _objc_msgSend(uVar5,PTR_s_contentView_0114b908);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1,uVar6);
  _objc_release(uVar7);
  _objc_storeStrong(lVar3 + _buttonImageView,uVar6);
  if (param_6 == 0) {
    _objc_msgSend(lVar3,PTR_s_addTarget_action_forControlEvent_0114b830,param_4,param_5,0x40);
  }
  else {
    _objc_msgSend(lVar3,PTR_s_setMenu__0114d658,param_6);
    _objc_msgSend(lVar3,PTR_s_setShowsMenuAsPrimaryAction__0114d660,1);
  }
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_6);
  _objc_release(param_4);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(lVar3);
  return IVar8;
}


