/* Decompiled from supplied 5.2.2 arm package. VA 0xbcd7c. FUN_000bcd7c */

void FUN_000bcd7c(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 auStack_150 [2];
  undefined8 auStack_140 [2];
  undefined *puStack_130;
  undefined8 uStack_128;
  code *pcStack_120;
  undefined *puStack_118;
  undefined8 uStack_110;
  undefined *puStack_100;
  undefined **ppuStack_f8;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  undefined8 *puStack_e0;
  undefined8 uStack_d8;
  undefined8 *puStack_d0;
  undefined8 uStack_c8;
  long local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **ppuStack_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_01182538;
  local_7c = (uint)(DAT_01226f28 == 0);
  local_90 = &PTR_LAB_01182558;
  ppuStack_88 = &PTR_LAB_01175340;
  local_a8 = &PTR_LAB_01182578;
  ppuStack_a0 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  DAT_01226f28 = 1;
  ppuStack_f8 = &puStack_130;
  puStack_e0 = auStack_140;
  puStack_d0 = auStack_150;
  local_c0 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___UIAction_0114ec40;
  puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_localizedStringForKey_value_tabl_0114b278;
  _objc_msgSend(uVar8,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_01171c70,0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_tabbar_0114c390);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_actionWithTitle_image_identifier_0114c3b8;
  _objc_msgSend(puVar3,PTR_s_actionWithTitle_image_identifier_0114c3b8,uVar9,uVar10,0,
                &PTR___NSConcreteGlobalBlock_01061a60);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar3 = PTR_s_addObject__0114b3a0;
  uStack_d8 = uVar11;
  _objc_msgSend(uVar7,PTR_s_addObject__0114b3a0,uVar11);
  puVar5 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2,&PTR____CFConstantStringClassReference_01171c30,0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_link_0114c3c0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar5,puVar4,uVar9,uVar10,0,&PTR___NSConcreteGlobalBlock_01061a80);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puStack_100 = puVar3;
  uStack_e8 = uVar11;
  uStack_c8 = uVar7;
  _objc_msgSend(uVar7,puVar3,uVar11);
  puVar3 = PTR__OBJC_CLASS___UIAction_0114ec40;
  puStack_f0 = puVar1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,puVar2,&PTR____CFConstantStringClassReference_01171bf0,0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_moon_0114c3d0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puStack_130 = PTR___NSConcreteStackBlock_01060660;
  uStack_128 = DAT_00c4c230;
  pcStack_120 = FUN_000be768;
  puStack_118 = &DAT_01061aa0;
  uStack_110 = *(undefined8 *)(local_c0 + 0x20);
  _objc_msgSend(puVar3,puVar4,uVar8,uVar9,0,ppuStack_f8);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_integerForKey__0114b3a8;
  lVar12 = _objc_msgSend(uVar7,PTR_s_integerForKey__0114b3a8,
                         &PTR____CFConstantStringClassReference_01171bb0);
  uStack_94 = (uint)(lVar12 == 2);
  if (lVar12 != 2) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    lVar12 = _objc_msgSend(uVar8,puVar3,&PTR____CFConstantStringClassReference_01171bb0);
    _objc_release(uVar8);
    _objc_release(uVar7);
    uStack_ac = (uint)(lVar12 == 3);
                    /* WARNING: Could not recover jumptable at 0x000bd6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_a8[uStack_ac] + (int)-(uRam0000000001182588 ^ 0x4b8d4383)))();
    return;
  }
  _objc_release(local_90[uStack_94] + (int)-(DAT_01182568 ^ 0xde436bc5),uVar7);
  uVar7 = uStack_c8;
  _objc_msgSend(uStack_c8,puStack_100,uVar10);
  puVar1 = PTR__OBJC_CLASS___UIAction_0114ec40;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puStack_f0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar2,&PTR____CFConstantStringClassReference_01171b70,0,0);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_sponsorblock_0114c3d8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,puVar4,uVar9,uVar11,0,&PTR___NSConcreteGlobalBlock_01061ac0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar11);
  _objc_release(uVar9);
  _objc_release(uVar8);
  puVar6 = puStack_e0;
  puVar3 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  *puStack_e0 = uVar13;
  puVar1 = PTR_s_arrayWithObjects_count__0114b600;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,puVar6,1);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_menuWithTitle_image_identifier_o_0114c3e0;
  _objc_msgSend(puVar3,PTR_s_menuWithTitle_image_identifier_o_0114c3e0,&cf___,0,
                &PTR____CFConstantStringClassReference_01171b30,1,uVar8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar8);
  _objc_msgSend(PTR__OBJC_CLASS___UIMenu_0114ed00,puVar2,&cf___,0,
                &PTR____CFConstantStringClassReference_01171af0,1,uVar7);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar6 = puStack_d0;
  puVar2 = PTR__OBJC_CLASS___UIMenu_0114ed00;
  *puStack_d0 = uVar9;
  puVar6[1] = uVar8;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar6,2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar2,PTR_s_menuWithTitle_children__0114c3e8,&cf___,uVar11);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar11);
  _objc_release(uVar8);
  _objc_release(uVar9);
  _objc_release(uVar13);
  _objc_release(uVar10);
  _objc_release(uStack_e8);
  _objc_release(uStack_d8);
  _objc_release(uVar7);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_70) {
    _objc_autoreleaseReturnValue(uVar14);
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


