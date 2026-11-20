/* Decompiled from supplied 5.2.2 arm package. VA 0x22eb5c. askForAction: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::askForAction_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined1 auStack_120 [48];
  undefined *puStack_f0;
  undefined *puStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  undefined *puStack_d0;
  undefined8 uStack_c8;
  undefined1 auStack_c0 [8];
  undefined **ppuStack_b8;
  undefined **ppuStack_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined *local_98;
  undefined *puStack_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  
  local_78 = &PTR_LAB_011d1730;
  local_7c = (uint)(DAT_012283dc == 0);
  local_88 = &PTR__objc_msgSend_011d0fe0;
  DAT_012283dc = 1;
  ppuStack_b8 = &puStack_f0;
  puStack_a8 = auStack_120;
  ppuStack_b0 = ppuStack_b8;
  local_98 = (undefined *)param_1;
  puStack_90 = (undefined *)param_3;
  _objc_retain(param_3);
  uVar8 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0bc0);
  puVar2 = PTR_s_ytl_defaultBundle_0114ae50;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_localizedStringForKey_value_tabl_0114b278;
  _objc_msgSend(uVar9,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011d0b80,0,0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_sheetControllerWithMessage_deleg_0114e798,uVar10,0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar10);
  _objc_release(uVar9);
  uVar9 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0b40);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3,&PTR____CFConstantStringClassReference_011d0ac0,0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar7 = local_98;
  _objc_msgSend(local_98,PTR_s_imageNamed__0114b800,&PTR____CFConstantStringClassReference_011d0b00)
  ;
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar1 = DAT_00c4c228;
  puStack_f0 = PTR___NSConcreteStackBlock_01060660;
  puStack_e8 = DAT_00c4c228;
  pcStack_e0 = FUN_0022f6ac;
  puStack_d8 = &DAT_01061c60;
  puStack_d0 = puVar7;
  puStack_a0 = auStack_c0;
  uStack_c8 = _objc_retain(puStack_90);
  puVar4 = PTR_s_actionWithTitle_iconImage_second_0114b890;
  _objc_msgSend(uVar9,PTR_s_actionWithTitle_iconImage_second_0114b890,uVar11,uVar12,0,0,ppuStack_b8)
  ;
  uVar9 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_addAction__0114b898;
  _objc_msgSend(uVar8,PTR_s_addAction__0114b898,uVar9);
  _objc_release(uVar9);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  uVar9 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0b40);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,puVar2);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,puVar3,&PTR____CFConstantStringClassReference_011d0a80,0,0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar12 = _NSClassFromString(&PTR____CFConstantStringClassReference_011d0a40);
  _objc_msgSend(uVar12,PTR_s_actionsheetShareImage_0114e7a0);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  ppuVar6 = ppuStack_b0;
  ppuStack_b0[-6] = PTR___NSConcreteStackBlock_01060660;
  ppuVar6[-5] = puVar1;
  ppuVar6[-4] = FUN_0022f6e8;
  ppuVar6[-3] = &DAT_01061c60;
  puVar1 = puStack_90;
  ppuVar6[-2] = puVar7;
  ppuVar6[-1] = puVar1;
  _objc_retain(puVar1);
  _objc_msgSend(uVar9,puVar4,uVar11,uVar12,0,0,puStack_a8);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,puVar5,uVar9);
  _objc_release(uVar9);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_delegate_0114b530);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar10,PTR_s_window_0114b3b0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,PTR_s_rootViewController_0114b968);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_msgSend(uVar12,PTR_s_pivotBarViewController_0114e390);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_view_0114b090);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar8,PTR_s_setSourceView__0114b8b8,uVar10);
  _objc_release(uVar10);
  _objc_release(uVar9);
  _objc_msgSend(uVar8,PTR_s_presentFromViewController_animat_0114b8c0,uVar12,1,0);
  _objc_release(uVar12);
  _objc_release(ppuVar6[-1]);
  _objc_release(*(undefined8 *)(puStack_a0 + -8));
  _objc_release(puVar1);
  _objc_release(uVar8);
  CallSupervisor(0x9c4b);
  return;
}


