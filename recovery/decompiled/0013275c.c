/* Decompiled from supplied 5.2.2 arm package. VA 0x13275c. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID TabbarVC::tableView_cellForRowAtIndexPath_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  ID IVar18;
  undefined8 uVar19;
  long lVar20;
  
  DAT_012273f0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,PTR_s_dequeueReusableCellWithIdentifie_0114b8d0,
                &PTR____CFConstantStringClassReference_0118f2c0);
  lVar8 = _objc_retainAutoreleasedReturnValue();
  if (lVar8 == 0) {
    uVar9 = _objc_alloc((&PTR__objc_msgSend_01190100)[lVar8 == 0] +
                        (int)-(DAT_01190110 ^ 0x653b6e73),PTR_YTPTableViewCell_0114ee38);
    lVar8 = _objc_msgSend(uVar9,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,3,
                          &PTR____CFConstantStringClassReference_0118f2c0);
  }
  puVar3 = PTR_s_section_0114af60;
  lVar20 = (long)_sections;
  uVar19 = *(undefined8 *)(param_1 + lVar20);
  uVar9 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
  _objc_msgSend(uVar19,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar9);
  lVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar10 == 0) {
    _objc_retain((&PTR__objc_msgSend_01190120)[lVar10 == 0] + (int)-(DAT_01190130 ^ 0x82aeea18),
                 lVar8);
  }
  else {
    uVar19 = *(undefined8 *)(param_1 + lVar20);
    uVar9 = _objc_msgSend(param_4,puVar3);
    _objc_msgSend(uVar19,puVar1,uVar9);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar4 = PTR_s_row_0114af70;
    uVar19 = _objc_msgSend(param_4,PTR_s_row_0114af70);
    _objc_msgSend(uVar9,puVar1,uVar19);
    uVar19 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar9);
    uVar9 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
    puVar2 = PTR_s_objectForKeyedSubscript__0114ae80;
    _objc_msgSend(uVar19,PTR_s_objectForKeyedSubscript__0114ae80,
                  &PTR____CFConstantStringClassReference_0118f380);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    lVar10 = _objc_msgSend(uVar9,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,3,uVar11);
    _objc_release(lVar8);
    _objc_release(uVar11);
    _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f340);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_isEqualToString__0114ae48;
    iVar7 = FUN_001372c4(uVar9,PTR_s_isEqualToString__0114ae48,
                         &PTR____CFConstantStringClassReference_0118f400);
    _objc_release(uVar9);
    if (iVar7 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f300);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,PTR_s_localizedStringForKey_value_tabl_0114b278,uVar11,0,0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,PTR_s_textLabel_0114b8e0);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,PTR_s_setText__0114b388,uVar16);
      _objc_release(uVar17);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f240);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,PTR_s_switchForKey__0114d3d0,uVar9);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      lVar8 = _objc_msgSend(param_4,puVar3);
      uVar12 = _objc_msgSend(param_4,puVar4);
      _objc_msgSend(uVar11,PTR_s_setTag__0114b858,uVar12 & 0xffff | lVar8 << 0x10);
      _objc_msgSend(lVar10,PTR_s_setAccessoryView__0114d3b0,uVar11);
      _objc_release(uVar11);
    }
    _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f340);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    iVar7 = FUN_00137afc(uVar9,puVar1,&PTR____CFConstantStringClassReference_0118f280);
    _objc_release(uVar9);
    puVar3 = PTR_s_standardUserDefaults_0114afa0;
    if (iVar7 != 0) {
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      puVar4 = PTR_s_objectForKey__0114b238;
      _objc_msgSend(uVar9,PTR_s_objectForKey__0114b238,
                    &PTR____CFConstantStringClassReference_0118f200);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar9);
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar3);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,puVar4,&PTR____CFConstantStringClassReference_0118f1c0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      uVar17 = _objc_msgSend(uVar16,PTR_s_mutableCopy_0114b010);
      _objc_release(uVar16);
      _objc_release(uVar9);
      iVar7 = FUN_0013738c(uVar17,PTR_s_containsObject__0114c848,
                           &PTR____CFConstantStringClassReference_0118f3c0);
      if (iVar7 != 0) {
        _objc_msgSend(uVar17,PTR_s_removeObject__0114cad0,
                      &PTR____CFConstantStringClassReference_0118f3c0);
      }
      _objc_msgSend(param_1,PTR_s_segmentForItems__0114d6a8,uVar17);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar16 = _objc_msgSend(uVar17,PTR_s_indexOfObject__0114b020,uVar11);
      _objc_msgSend(uVar9,PTR_s_setSelectedSegmentIndex__0114d3f0,uVar16);
      _objc_msgSend(uVar9,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                    PTR_s_setSegment__0114d3f8,0x1000);
      puVar6 = PTR_s_contentView_0114b908;
      _objc_msgSend(lVar10,PTR_s_contentView_0114b908);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,PTR_s_addSubview__0114b0a8,uVar9);
      _objc_release(uVar16);
      puVar3 = PTR_s_centerYAnchor_0114b7f8;
      _objc_msgSend(uVar9,PTR_s_centerYAnchor_0114b7f8);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar3 = PTR_s_constraintEqualToAnchor__0114b5a0;
      _objc_msgSend(uVar16,PTR_s_constraintEqualToAnchor__0114b5a0,uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      puVar4 = PTR_s_setActive__0114b5a8;
      _objc_msgSend(uVar15,PTR_s_setActive__0114b5a8,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar5 = PTR_s_centerXAnchor_0114b628;
      _objc_msgSend(uVar9,PTR_s_centerXAnchor_0114b628);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar5);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,puVar3,uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar3 = PTR_s_leadingAnchor_0114b5b8;
      _objc_msgSend(uVar9,PTR_s_leadingAnchor_0114b5b8);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      puVar5 = PTR_s_constraintEqualToAnchor_constant_0114b630;
      _objc_msgSend(0x4034000000000000,uVar16,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar14
                   );
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      puVar3 = PTR_s_trailingAnchor_0114b5c0;
      _objc_msgSend(uVar9,PTR_s_trailingAnchor_0114b5c0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,puVar3);
      uVar14 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(0xc034000000000000,uVar16,puVar5,uVar14);
      uVar15 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar15,puVar4,1);
      _objc_release(uVar15);
      _objc_release(uVar14);
      _objc_release(uVar13);
      _objc_release(uVar16);
      _objc_release(uVar9);
      _objc_release(uVar17);
      _objc_release(uVar11);
    }
    _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f340);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    iVar7 = FUN_00137534(uVar9,puVar1,&PTR____CFConstantStringClassReference_0118f180);
    _objc_release(uVar9);
    if (iVar7 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f240);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,PTR_s_localizedStringForKey_value_tabl_0114b278,uVar11,0,0);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_textLabel_0114b8e0;
      _objc_msgSend(lVar10,PTR_s_textLabel_0114b8e0);
      uVar17 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar17,PTR_s_setText__0114b388,uVar16);
      _objc_release(uVar17);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(lVar10,puVar1);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar9,PTR_s_setAdjustsFontSizeToFitWidth__0114b740,1);
      _objc_release(uVar9);
      _objc_msgSend(uVar19,puVar2,&PTR____CFConstantStringClassReference_0118f240);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,PTR_s_iconImageNamed__0114d6b0,uVar9);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_imageView_0114b720;
      _objc_msgSend(lVar10,PTR_s_imageView_0114b720);
      uVar16 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar16,PTR_s_setImage__0114b8f8,uVar11);
      _objc_release(uVar16);
      _objc_release(uVar11);
      _objc_release(uVar9);
      _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_labelColor_0114aff8);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(lVar10,puVar1);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,PTR_s_setTintColor__0114b000,uVar9);
      _objc_release(uVar11);
      _objc_release(uVar9);
    }
    _objc_retain(lVar10);
    _objc_release(uVar19);
    lVar8 = lVar10;
  }
  _objc_release(lVar8);
  _objc_release(param_4);
  IVar18 = _objc_autoreleaseReturnValue(lVar8);
  return IVar18;
}


