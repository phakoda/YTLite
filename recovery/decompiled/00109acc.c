/* Decompiled from supplied 5.2.2 arm package. VA 0x109acc. showTranscriptSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showTranscriptSheet_withSender_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined *puStack_230;
  undefined8 uStack_228;
  code *pcStack_220;
  undefined *puStack_218;
  undefined8 uStack_210;
  undefined1 auStack_200 [128];
  undefined8 uStack_180;
  long lStack_178;
  long *plStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  ID IStack_138;
  undefined *puStack_130;
  undefined1 *puStack_128;
  undefined8 uStack_120;
  long lStack_118;
  ID local_110;
  undefined8 uStack_108;
  undefined *puStack_100;
  undefined *puStack_f8;
  uint uStack_ec;
  undefined **local_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR__objc_msgSend_0118aef0;
  local_8c = (uint)(DAT_012271fc == 0);
  local_a0 = &PTR__objc_msgSend_0118af10;
  local_98 = &PTR_LAB_011882f0;
  local_b8 = &PTR_LAB_011882f0;
  ppuStack_b0 = &PTR_LAB_011882f0;
  local_c0 = &PTR_LAB_0118af38;
  local_d8 = &PTR__objc_msgSend_0118af58;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_e8 = &PTR_LAB_0118af70;
  DAT_012271fc = 1;
  IStack_138 = param_4;
  local_110 = param_1;
  _objc_retain(param_4);
  _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_availableCaptionTracks_0114cb80);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_01187a00);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011879c0,0,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_sheetControllerWithMessage_subMe_0114b880,uVar8,0,0,0);
  uStack_108 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar8);
  _objc_release(uVar7);
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  lStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  plStack_170 = (long *)0x0;
  uVar5 = _objc_retain(uVar6);
  puStack_130 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  puStack_128 = auStack_200;
  uStack_120 = uVar6;
  lVar9 = _objc_msgSend(uVar5,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_180,
                        auStack_200,0x10);
  uVar5 = DAT_00c4c228;
  uStack_a4 = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
LAB_0010a37c:
    uVar5 = uStack_120;
    _objc_release(uStack_120);
    uVar6 = uStack_108;
    IVar3 = IStack_138;
    _objc_msgSend(uStack_108,PTR_s_setSourceView__0114b8b8,IStack_138);
    _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_rootViewController_0114b968);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_presentFromViewController_animat_0114b8c0,uVar8,1,0);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(IVar3);
    CallSupervisor(0x268a);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail(0x1a,0x1f,0,0);
    }
    return;
  }
  lStack_118 = *plStack_170;
LAB_0010a148:
  puVar2 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
  puVar1 = PTR_s_addAction__0114b898;
  lVar11 = 0;
  puStack_100 = PTR_s_imageWithName__0114c5b0;
  puStack_f8 = PTR_s_titleForCaption__0114d080;
  uStack_c4 = (uint)(*plStack_170 == lStack_118);
  if (*plStack_170 == lStack_118) goto LAB_0010a218;
  do {
    _objc_enumerationMutation(uStack_120);
LAB_0010a218:
    do {
      uVar10 = *(undefined8 *)(lStack_178 + lVar11 * 8);
      uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_01187980);
      _objc_msgSend(local_110,puStack_f8,uVar10);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_100,
                    &PTR____CFConstantStringClassReference_01187940);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      puStack_230 = PTR___NSConcreteStackBlock_01060660;
      uStack_228 = uVar5;
      pcStack_220 = FUN_0010a480;
      puStack_218 = &DAT_010618c0;
      uStack_210 = uVar10;
      _objc_msgSend(uVar6,puVar2,uVar7,uVar8,0,&puStack_230);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uStack_108,puVar1,uVar6);
      _objc_release(uVar6);
      _objc_release(uVar8);
      _objc_release(uVar7);
      bVar4 = lVar9 + -1 == lVar11;
      uStack_dc = (uint)bVar4;
      if (bVar4) {
        lVar9 = _objc_msgSend(uStack_120,puStack_130,&uStack_180,puStack_128,0x10);
        uStack_ec = (uint)(lVar9 == 0);
        if (lVar9 != 0) goto LAB_0010a148;
        uStack_ec = 1;
        goto LAB_0010a37c;
      }
      lVar11 = lVar11 + 1;
      uStack_c4 = (uint)(*plStack_170 == lStack_118);
    } while (*plStack_170 == lStack_118);
  } while( true );
}


