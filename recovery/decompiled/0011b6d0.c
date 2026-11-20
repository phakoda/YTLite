/* Decompiled from supplied 5.2.2 arm package. VA 0x11b6d0. setupThanksHeart */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::setupThanksHeart(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 auStack_b0 [16];
  undefined *puStack_a0;
  undefined8 uStack_98;
  undefined1 *puStack_90;
  undefined1 *puStack_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  puStack_90 = (undefined1 *)&puStack_a0;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_0118d3a0;
  local_74 = (uint)(DAT_012272c8 == 0);
  local_80 = &PTR__objc_msgSend_0118c130;
  DAT_012272c8 = 1;
  puStack_88 = auStack_b0;
  uVar4 = _objc_alloc_init(PTR__OBJC_CLASS___UILabel_0114ec00);
  _objc_msgSend(uVar4,PTR_s_setTextAlignment__0114b5f8,1);
  _objc_msgSend(uVar4,PTR_s_setText__0114b388,&PTR____CFConstantStringClassReference_0118bc70);
  _objc_msgSend(DAT_00c4c360,PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize__0114b660);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setFont__0114b5e8,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(uVar4,PTR_s_setTranslatesAutoresizingMaskInt_0114b590,0);
  _objc_msgSend(uVar4,PTR_s_sizeToFit_0114b390);
  puVar2 = PTR_s_tableView_0114d120;
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_addSubview__0114b0a8,uVar4);
  _objc_release(uVar5);
  _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,PTR_s_animationWithKeyPath__0114d2f0,
                &PTR____CFConstantStringClassReference_0118bc30);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_numberWithDouble__0114c310;
  _objc_msgSend(DAT_00c4c368,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setFromValue__0114d2f8,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setToValue__0114d300,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(uVar5,PTR_s_setAutoreverses__0114d308,1);
  _objc_msgSend(0x7f800000,uVar5,PTR_s_setRepeatCount__0114d310);
  _objc_msgSend(0x3fe0000000000000,uVar5,PTR_s_setDuration__0114d318);
  _objc_msgSend(uVar4,PTR_s_layer_0114ae60);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_addAnimation_forKey__0114d320,uVar5,
                &PTR____CFConstantStringClassReference_0118bbf0);
  _objc_release(uVar6);
  puVar1 = PTR_s_centerXAnchor_0114b628;
  puStack_a0 = PTR__OBJC_CLASS___NSLayoutConstraint_0114ec20;
  _objc_msgSend(uVar4,PTR_s_centerXAnchor_0114b628);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uStack_98 = uVar6;
  _objc_msgSend(param_1,puVar2);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_constraintEqualToAnchor__0114b5a0,uVar8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_90;
  *(undefined8 *)(puStack_90 + -0x10) = uVar6;
  _objc_msgSend(uVar4,PTR_s_bottomAnchor_0114b5b0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,PTR_s_topAnchor_0114b598);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0xc02e000000000000,uVar9,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar11);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  *(undefined8 *)(puVar3 + -8) = uVar12;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,puStack_88
                ,2);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puStack_a0,PTR_s_activateConstraints__0114b650,uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar6);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uStack_98);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0xaa45);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


