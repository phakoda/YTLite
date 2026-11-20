// Decompiled implementation evidence for BlurButton. Not compilable source.

// -[BlurButton setHighlighted:], 0x223460
/* Decompiled from supplied 5.2.2 arm package. VA 0x223460. setHighlighted: */

/* Function Stack Size: 0x14 bytes */

void BlurButton::setHighlighted_(ID param_1,SEL param_2,bool param_3)

{
  undefined8 uVar1;
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_BlurButton_0114f148;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,@selector(setHighlighted:));
  uVar1 = 0x3fd0000000000000;
  if (param_3 == 0) {
    uVar1 = 0x3ff0000000000000;
  }
  _objc_msgSend(uVar1,*(undefined8 *)(param_1 + (long)_buttonImageView),@selector(setAlpha:));
  return;
}



// -[BlurButton .cxx_destruct], 0x2234cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2234cc. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void BlurButton::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_buttonImageView,0);
  CallSupervisor(0xb57);
  return;
}



// +[BlurButton createButtonWithImage:target:action:menu:], 0x22311c
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
  puVar1 = @selector(buttonWithType:);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  lVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(setFrame:);
  _objc_msgSend(0,0,0x403c000000000000,0x403c000000000000,lVar3,@selector(setFrame:));
  _objc_msgSend(PTR__OBJC_CLASS___UIBlurEffect_0114ebe0,@selector(effectWithStyle:),0x10);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_alloc(PTR__OBJC_CLASS___UIVisualEffectView_0114ebd8);
  uVar5 = _objc_msgSend(uVar5,@selector(initWithEffect:),uVar4);
  _objc_msgSend(lVar3,@selector(bounds));
  _objc_msgSend(uVar5,puVar1);
  _objc_msgSend(uVar5,@selector(layer));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x402c000000000000,uVar6,@selector(setCornerRadius:));
  _objc_release(uVar6);
  _objc_msgSend(uVar5,@selector(setClipsToBounds:),1);
  _objc_msgSend(uVar5,@selector(setUserInteractionEnabled:),0);
  puVar1 = @selector(addSubview:);
  _objc_msgSend(lVar3,@selector(addSubview:),uVar5);
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  uVar6 = _objc_msgSend(0,0,0x4032000000000000,0x4032000000000000,uVar6,
                        @selector(initWithFrame:));
  _objc_msgSend(uVar5,@selector(center));
  _objc_msgSend(uVar6,@selector(setCenter:));
  _objc_msgSend(uVar6,@selector(setContentMode:),4);
  _objc_msgSend(uVar6,@selector(setImage:),param_3);
  _objc_release(param_3);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(whiteColor));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,@selector(setTintColor:),uVar7);
  _objc_release(uVar7);
  _objc_msgSend(uVar5,@selector(contentView));
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1,uVar6);
  _objc_release(uVar7);
  _objc_storeStrong(lVar3 + _buttonImageView,uVar6);
  if (param_6 == 0) {
    _objc_msgSend(lVar3,@selector(addTarget:action:forControlEvents:),param_4,param_5,0x40);
  }
  else {
    _objc_msgSend(lVar3,@selector(setMenu:),param_6);
    _objc_msgSend(lVar3,@selector(setShowsMenuAsPrimaryAction:),1);
  }
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(param_6);
  _objc_release(param_4);
  IVar8 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(lVar3);
  return IVar8;
}


