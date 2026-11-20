/* Decompiled from supplied 5.2.2 arm package. VA 0x10a9c4. showCaptionsSheet:withSender: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::showCaptionsSheet_withSender_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined8 uVar12;
  long lVar13;
  undefined *puStack_290;
  undefined8 uStack_288;
  code *pcStack_280;
  undefined *puStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  ID IStack_260;
  undefined8 uStack_258;
  undefined1 auStack_250 [128];
  undefined8 uStack_1d0;
  long lStack_1c8;
  long *plStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  long lStack_190;
  ID IStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  long lStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ID local_150;
  ID local_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined *puStack_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_0118aff0;
  local_8c = (uint)(DAT_01227208 == 0);
  local_a0 = &PTR_LAB_0118b010;
  local_b0 = &PTR_LAB_0118b028;
  local_c0 = &PTR_LAB_0118b040;
  local_d0 = &PTR_LAB_0118b058;
  local_98 = &PTR_LAB_011882f0;
  local_e8 = &PTR_LAB_011882f0;
  ppuStack_e0 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_0118b080;
  local_108 = &PTR_LAB_0118b0a0;
  ppuStack_100 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_0118b0b8;
  local_128 = &PTR_LAB_011882f0;
  DAT_01227208 = 1;
  puStack_178 = auStack_250;
  local_150 = param_1;
  local_148 = param_4;
  _objc_retain(param_3);
  _objc_retain(local_148);
  puVar11 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_a4 = FUN_0011478c(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar10 = local_a0[uStack_a4] + (int)-(DAT_0118b020 ^ 0xce93a321);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_001145a4(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar10 = local_b0[uStack_b4] + (int)-(uRam000000000118b038 ^ 0x72dd04c);
    puVar11 = puVar2;
    if (uStack_b4 == 0) goto LAB_0010b500;
  }
  _objc_msgSend(puVar10,param_3,puVar11);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  uStack_c4 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    lStack_190 = lVar5;
    _objc_msgSend(lVar5,PTR_s_videoID_0114c960);
    uStack_158 = _objc_retainAutoreleasedReturnValue();
    IStack_188 = param_3;
    _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_availableCaptionTracks_0114cb80);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(local_150,PTR_s_captionsForDownloading__0114d098,uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    _objc_release(uVar6);
    uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_01187c80);
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_01187c40,0,0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_sheetControllerWithMessage_subMe_0114b880,uVar9,0,0,0);
    uStack_160 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar9);
    _objc_release(uVar7);
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_198 = 0;
    uStack_1a0 = 0;
    lStack_1c8 = 0;
    uStack_1d0 = 0;
    uStack_1b8 = 0;
    plStack_1c0 = (long *)0x0;
    uVar6 = _objc_retain(uVar8);
    puStack_180 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    uStack_170 = uVar8;
    lVar5 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1d0,
                          puStack_178,0x10);
    IVar3 = local_150;
    uVar7 = uStack_170;
    puVar10 = PTR_s_addAction__0114b898;
    uVar6 = DAT_00c4c228;
    uStack_d4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      lStack_168 = *plStack_1c0;
      lVar13 = 0;
      puStack_130 = PTR_s_titleForCaption__0114d080;
      puStack_138 = PTR_s_imageWithName__0114c5b0;
      puStack_140 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
      uStack_f4 = (uint)(*plStack_1c0 == lStack_168);
      if (*plStack_1c0 == lStack_168) goto LAB_0010b298;
      do {
        _objc_enumerationMutation(uStack_170);
LAB_0010b298:
        do {
          uVar12 = *(undefined8 *)(lStack_1c8 + lVar13 * 8);
          uVar7 = _NSClassFromString(&PTR____CFConstantStringClassReference_01187c00);
          _objc_msgSend(IVar3,puStack_130,uVar12);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_138,
                        &PTR____CFConstantStringClassReference_01187bc0);
          uVar9 = _objc_retainAutoreleasedReturnValue();
          puStack_290 = PTR___NSConcreteStackBlock_01060660;
          uStack_288 = uVar6;
          pcStack_280 = FUN_0010b56c;
          puStack_278 = &UNK_01062430;
          uStack_270 = uVar12;
          uStack_268 = _objc_retain(uStack_158);
          IStack_260 = IVar3;
          uStack_258 = _objc_retain(local_148);
          _objc_msgSend(uVar7,puStack_140,uVar8,uVar9,0,&puStack_290);
          uVar7 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uStack_160,puVar10,uVar7);
          _objc_release(uVar7);
          _objc_release(uVar9);
          _objc_release(uVar8);
          _objc_release(uStack_258);
          _objc_release(uStack_268);
          bVar4 = lVar5 + -1 == lVar13;
          uStack_10c = (uint)bVar4;
          if (bVar4) {
            lVar5 = _objc_msgSend(uStack_170,puStack_180,&uStack_1d0,puStack_178,0x10);
            uStack_11c = (uint)(lVar5 == 0);
                    /* WARNING: Could not recover jumptable at 0x0010b294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)(local_118[uStack_11c] + (int)-(uRam000000000118b0c8 ^ 0xe8c2702c)))();
            return;
          }
          lVar13 = lVar13 + 1;
          uStack_f4 = (uint)(*plStack_1c0 == lStack_168);
          uStack_10c = 0;
        } while (*plStack_1c0 == lStack_168);
      } while( true );
    }
    _objc_release(uStack_170);
    uVar6 = uStack_160;
    _objc_msgSend(uStack_160,PTR_s_setSourceView__0114b8b8,local_148);
    _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_rootViewController_0114b968);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_presentFromViewController_animat_0114b8c0,uVar9,1,0);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar7);
    _objc_release(uStack_158);
    _objc_release(lStack_190);
    param_3 = IStack_188;
  }
LAB_0010b500:
  _objc_release(local_148);
  _objc_release(param_3);
  CallSupervisor(0xb3d);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


