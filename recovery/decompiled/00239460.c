/* Decompiled from supplied 5.2.2 arm package. VA 0x239460. makeStepButton: */

/* Function Stack Size: 0x18 bytes */

ID YTPSpeedControlView::makeStepButton_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ID IVar9;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  puVar2 = PTR__OBJC_CLASS___UIButton_0114ec38;
  puVar1 = PTR_s_buttonWithType__0114b6a0;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,PTR_s_setImage_forState__0114adf0,uVar4,0);
  _objc_release(uVar4);
  puVar1 = PTR_s_labelColor_0114aff8;
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTintColor__0114b000,uVar4);
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
  _objc_msgSend(0x4034000000000000,uVar4,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  puVar2 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar3,PTR_s_widthAnchor_0114b648);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_constraintEqualToConstant__0114b640;
  _objc_msgSend(0x4044000000000000,uVar4,PTR_s_constraintEqualToConstant__0114b640);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  local_78 = uVar5;
  _objc_msgSend(uVar3,PTR_s_heightAnchor_0114b638);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4044000000000000,uVar6,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  local_70 = uVar7;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_78,
                2);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_activateConstraints__0114b650,uVar8);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,PTR_s_addSubview__0114b0a8,uVar3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar9 = _objc_autoreleaseReturnValue(uVar3);
    return IVar9;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


