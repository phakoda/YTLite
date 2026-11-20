/* Decompiled from supplied 5.2.2 arm package. VA 0x10c720. getCaptionsUrlSheet:sender:completion: */

/* Function Stack Size: 0x28 bytes */

void DownloadMenuHelper::getCaptionsUrlSheet_sender_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined8 uVar11;
  long lVar12;
  undefined *puStack_2a0;
  undefined8 uStack_298;
  code *pcStack_290;
  undefined *puStack_288;
  undefined8 uStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined1 auStack_260 [128];
  undefined8 uStack_1e0;
  long lStack_1d8;
  long *plStack_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  long lStack_198;
  ID IStack_190;
  ID IStack_188;
  undefined *puStack_180;
  undefined1 *puStack_178;
  undefined8 uStack_170;
  long lStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  ID IStack_150;
  ID local_148;
  undefined *puStack_140;
  undefined *puStack_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  uint uStack_114;
  undefined **local_110;
  undefined **ppuStack_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **ppuStack_d0;
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
  local_88 = &PTR_LAB_0118b2a0;
  local_8c = (uint)(DAT_0122721c == 0);
  local_a0 = &PTR_LAB_0118b2c0;
  local_b0 = &PTR_LAB_0118b2d8;
  local_c0 = &PTR_LAB_0118b2f0;
  local_98 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118b310;
  ppuStack_d0 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_011882f0;
  ppuStack_e8 = &PTR_LAB_011882f0;
  local_f8 = &PTR_LAB_0118b338;
  local_110 = &PTR_LAB_0118b358;
  ppuStack_108 = &PTR_LAB_011882f0;
  local_120 = &PTR_LAB_0118b370;
  local_130 = &PTR_LAB_011882f0;
  DAT_0122721c = 1;
  puStack_178 = auStack_260;
  local_148 = param_1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puVar10 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uStack_a4 = FUN_00114f38(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0)
  ;
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar9 = local_a0[uStack_a4] + (int)-(DAT_0118b2d0 ^ 0x9e0e7da9);
  if (uStack_a4 == 0) {
    uStack_b4 = FUN_00115000(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar9 = local_b0[uStack_b4] + (int)-(uRam000000000118b2e8 ^ 0x23c74c4e);
    puVar10 = puVar2;
    if (uStack_b4 != 0) goto LAB_0010cd24;
  }
  else {
LAB_0010cd24:
    _objc_msgSend(puVar9,param_3,puVar10);
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    if (lVar4 != 0) {
      lStack_198 = lVar4;
      IStack_190 = param_4;
      IStack_150 = param_5;
      _objc_msgSend(lVar4,PTR_s_videoID_0114c960);
      uStack_158 = _objc_retainAutoreleasedReturnValue();
      IStack_188 = param_3;
      _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_availableCaptionTracks_0114cb80);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(local_148,PTR_s_captionsForDownloading__0114d098,uVar6);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar6);
      _objc_release(uVar5);
      uVar5 = _NSClassFromString(&PTR____CFConstantStringClassReference_01188170);
      _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_localizedStringForKey_value_tabl_0114b278,
                    &PTR____CFConstantStringClassReference_01188130,0,0);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_sheetControllerWithMessage_subMe_0114b880,uVar8,0,0,0);
      uStack_160 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar8);
      _objc_release(uVar6);
      uStack_1b8 = 0;
      uStack_1c0 = 0;
      uStack_1a8 = 0;
      uStack_1b0 = 0;
      lStack_1d8 = 0;
      uStack_1e0 = 0;
      uStack_1c8 = 0;
      plStack_1d0 = (long *)0x0;
      uVar5 = _objc_retain(uVar7);
      puStack_180 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
      uStack_170 = uVar7;
      lVar4 = _objc_msgSend(uVar5,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1e0,
                            puStack_178,0x10);
      uVar6 = uStack_170;
      puVar1 = PTR_s_actionWithTitle_iconImage_style__0114c5c0;
      puVar9 = PTR_s_addAction__0114b898;
      uVar5 = DAT_00c4c228;
      uStack_dc = (uint)(lVar4 == 0);
      if (lVar4 != 0) {
        lStack_168 = *plStack_1d0;
        lVar12 = 0;
        puStack_138 = PTR_s_titleForCaption__0114d080;
        puStack_140 = PTR_s_imageWithName__0114c5b0;
        uStack_fc = (uint)(*plStack_1d0 == lStack_168);
        if (*plStack_1d0 == lStack_168) goto LAB_0010cfbc;
        do {
          _objc_enumerationMutation(uStack_170);
LAB_0010cfbc:
          do {
            uVar11 = *(undefined8 *)(lStack_1d8 + lVar12 * 8);
            uVar6 = _NSClassFromString(&PTR____CFConstantStringClassReference_011880f0);
            _objc_msgSend(local_148,puStack_138,uVar11);
            uVar7 = _objc_retainAutoreleasedReturnValue();
            _objc_msgSend(PTR_YTPMedia_0114eae0,puStack_140,
                          &PTR____CFConstantStringClassReference_011880b0);
            uVar8 = _objc_retainAutoreleasedReturnValue();
            puStack_2a0 = PTR___NSConcreteStackBlock_01060660;
            uStack_298 = uVar5;
            pcStack_290 = FUN_0010d304;
            puStack_288 = &DAT_01062490;
            uStack_280 = uVar11;
            uStack_278 = _objc_retain(uStack_158);
            uStack_270 = _objc_retain(IStack_150);
            _objc_msgSend(uVar6,puVar1,uVar7,uVar8,0,&puStack_2a0);
            uVar6 = _objc_retainAutoreleasedReturnValue();
            _objc_msgSend(uStack_160,puVar9,uVar6);
            _objc_release(uVar6);
            _objc_release(uVar8);
            _objc_release(uVar7);
            _objc_release(uStack_270);
            _objc_release(uStack_278);
            bVar3 = lVar4 + -1 == lVar12;
            uStack_114 = (uint)bVar3;
            if (bVar3) {
              lVar4 = _objc_msgSend(uStack_170,puStack_180,&uStack_1e0,puStack_178,0x10);
              uStack_124 = (uint)(lVar4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0010d1a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(local_120[uStack_124] + (int)-(DAT_0118b380 ^ 0x38915086)))();
              return;
            }
            lVar12 = lVar12 + 1;
            uStack_fc = (uint)(*plStack_1d0 == lStack_168);
            uStack_114 = 0;
          } while (*plStack_1d0 == lStack_168);
        } while( true );
      }
      _objc_release(uStack_170);
      uVar5 = uStack_160;
      param_4 = IStack_190;
      _objc_msgSend(uStack_160,PTR_s_setSourceView__0114b8b8,IStack_190);
      _objc_msgSend(PTR_ToastView_0114ec98,PTR_s_toastWindow_0114b960);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,PTR_s_rootViewController_0114b968);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_presentFromViewController_animat_0114b8c0,uVar8,1,0);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar5);
      _objc_release(uVar6);
      _objc_release(uStack_158);
      _objc_release(lStack_198);
      param_3 = IStack_188;
      param_5 = IStack_150;
      goto LAB_0010d294;
    }
  }
  (**(code **)(param_5 + 0x10))(param_5,0);
LAB_0010d294:
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x9c11);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


