/* Decompiled from supplied 5.2.2 arm package. VA 0x21fae4. setupNavbar */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::setupNavbar(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined1 auStack_190 [32];
  undefined1 auStack_170 [48];
  undefined1 auStack_140 [48];
  undefined *puStack_110;
  undefined *puStack_108;
  code *pcStack_100;
  undefined *puStack_f8;
  ID IStack_f0;
  undefined **ppuStack_e0;
  undefined **ppuStack_d8;
  undefined *puStack_d0;
  undefined *puStack_c8;
  undefined8 uStack_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  long local_78;
  
  puVar1 = PTR_s_navigationController_0114afe8;
  local_78 = *(long *)PTR____stack_chk_guard_01060708;
  local_80 = &PTR_LAB_011ce2f8;
  local_84 = (uint)(DAT_012282b4 == 0);
  local_90 = &PTR_LAB_011ce2a0;
  DAT_012282b4 = 1;
  ppuStack_e0 = &puStack_110;
  puStack_b8 = auStack_140;
  puStack_a8 = auStack_170;
  puStack_98 = auStack_190;
  ppuStack_d8 = ppuStack_e0;
  puStack_b0 = puStack_b8;
  puStack_a0 = puStack_a8;
  _objc_msgSend(param_1,PTR_s_navigationController_0114afe8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_navigationBar_0114b7a8;
  _objc_msgSend(uVar11,PTR_s_navigationBar_0114b7a8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,PTR_s_setTranslucent__0114b7b0,1);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_msgSend(param_1,puVar1);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_new_0114b030;
  uVar13 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_new_0114b030);
  _objc_msgSend(uVar12,PTR_s_setBackgroundImage_forBarMetrics_0114b7b8,uVar13,0);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar2);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,puVar3);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,PTR_s_setShadowImage__0114b7c0,uVar11);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  puVar1 = PTR_BlurButton_0114f018;
  puVar4 = PTR_s_systemImageNamed__0114b718;
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,
                &PTR____CFConstantStringClassReference_011ce280);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puStack_c8 = PTR_s_createButtonWithImage_target_act_0114e618;
  _objc_msgSend(puVar1,PTR_s_createButtonWithImage_target_act_0114e618,uVar12,param_1,
                PTR_s_closeButtonTapped__0114e610,0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puStack_d0 = PTR_s_initWithCustomView__0114e620;
  uStack_c0 = _objc_msgSend(uVar11,PTR_s_initWithCustomView__0114e620,uVar13);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  puVar2 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_localizedStringForKey_value_tabl_0114b278;
  _objc_msgSend(uVar11,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011ce240,0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                &PTR____CFConstantStringClassReference_011ce1c0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_actionWithTitle_image_identifier_0114c3b8;
  puVar1 = DAT_00c4c228;
  puStack_110 = PTR___NSConcreteStackBlock_01060660;
  puStack_108 = DAT_00c4c228;
  pcStack_100 = FUN_002206f8;
  puStack_f8 = &DAT_01061780;
  IStack_f0 = param_1;
  _objc_msgSend(puVar6,PTR_s_actionWithTitle_image_identifier_0114c3b8,uVar12,uVar13,0,ppuStack_d8);
  ppuStack_d8 = (undefined **)_objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,&PTR____CFConstantStringClassReference_011ce140,0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                &PTR____CFConstantStringClassReference_011ce200);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  ppuVar7 = ppuStack_e0;
  ppuStack_e0[-6] = PTR___NSConcreteStackBlock_01060660;
  ppuVar7[-5] = puVar1;
  ppuVar7[-4] = FUN_00220798;
  ppuVar7[-3] = &DAT_01061780;
  ppuVar7[-2] = (undefined *)param_1;
  _objc_msgSend(puVar6,puVar5,uVar12,uVar13,0,puStack_b8);
  puStack_b8 = (undefined1 *)_objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar6 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar3,&PTR____CFConstantStringClassReference_011ce100,0,0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                &PTR____CFConstantStringClassReference_011ce0c0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar9 = puStack_a8;
  puVar8 = puStack_b0;
  *(undefined **)(puStack_b0 + -0x30) = PTR___NSConcreteStackBlock_01060660;
  *(undefined **)(puVar8 + -0x28) = puVar1;
  *(code **)(puVar8 + -0x20) = FUN_002207ec;
  *(undefined **)(puVar8 + -0x18) = &DAT_01061780;
  *(ID *)(puVar8 + -0x10) = param_1;
  _objc_msgSend(puVar6,puVar5,uVar12,uVar13,0,puVar9);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  uVar11 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  puVar2 = PTR_BlurButton_0114f018;
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,puVar4,
                &PTR____CFConstantStringClassReference_011ce180);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar10 = puStack_98;
  puVar9 = puStack_a0;
  puVar8 = puStack_b8;
  puVar1 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  *(undefined8 *)(puStack_a0 + -0x20) = uVar14;
  *(undefined1 **)(puVar9 + -0x18) = puVar8;
  ppuVar7 = ppuStack_d8;
  *(undefined ***)(puVar9 + -0x10) = ppuStack_d8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,puVar10,3)
  ;
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_menuWithTitle_children__0114c3e8,&cf___,uVar13);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,puStack_c8,uVar12,0,0,uVar15);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  uVar17 = _objc_msgSend(uVar11,puStack_d0,uVar16);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar13);
  _objc_release(uVar12);
  puVar1 = PTR_s_navigationItem_0114d2c8;
  _objc_msgSend(param_1,PTR_s_navigationItem_0114d2c8);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  uVar11 = uStack_c0;
  _objc_msgSend(uVar12,PTR_s_setLeftBarButtonItem__0114d2d0,uStack_c0);
  _objc_release(uVar12);
  _objc_msgSend(param_1,puVar1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar12,PTR_s_setRightBarButtonItem__0114d2d8,uVar17);
  _objc_release(uVar12);
  _objc_release(uVar17);
  _objc_release(uVar14);
  _objc_release(puVar8);
  _objc_release(ppuVar7);
  _objc_release(uVar11);
  CallSupervisor(0x7cf0);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_78) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


