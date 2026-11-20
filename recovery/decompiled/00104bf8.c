/* Decompiled from supplied 5.2.2 arm package. VA 0x104bf8. getEnglishAudioTrack: */

/* Function Stack Size: 0x18 bytes */

ID DownloadMenuHelper::getEnglishAudioTrack_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  undefined *puVar11;
  long lVar12;
  undefined1 auStack_1e0 [128];
  undefined8 uStack_160;
  long lStack_158;
  long *plStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined *puStack_118;
  undefined1 *puStack_110;
  ID local_108;
  long lStack_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  undefined **ppuStack_d8;
  int iStack_cc;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  undefined **ppuStack_a0;
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118a620;
  local_7c = (uint)(DAT_01227198 == 0);
  local_90 = &PTR_LAB_0118a640;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_011882f0;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b0 = &PTR_LAB_0118a668;
  local_c8 = &PTR_LAB_0118a688;
  ppuStack_c0 = &PTR_LAB_011882f0;
  local_e0 = &PTR_LAB_0118a6a8;
  ppuStack_d8 = &PTR_LAB_011882f0;
  local_f0 = &PTR_LAB_0118a6c0;
  DAT_01227198 = 1;
  local_108 = param_3;
  _objc_retain(param_3);
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  lStack_158 = 0;
  uStack_160 = 0;
  uStack_148 = 0;
  plStack_150 = (long *)0x0;
  uVar6 = _objc_retain();
  puVar11 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
  lVar7 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_160,
                        auStack_1e0,0x10);
  uVar6 = 0;
  uStack_94 = (uint)(lVar7 == 0);
  if (lVar7 == 0) {
LAB_00104fa8:
    IVar10 = local_108;
    _objc_release(local_108);
    _objc_release(IVar10);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar6);
    return IVar10;
  }
  puStack_118 = puVar11;
  lStack_100 = *plStack_150;
  puStack_110 = auStack_1e0;
LAB_00104dd8:
  puVar3 = PTR_s_id_p_0114cc10;
  puVar2 = PTR_s_audioTrack_0114cbf8;
  puVar1 = PTR_s_hasPrefix__0114aea0;
  lVar12 = 0;
  uStack_b4 = (uint)(*plStack_150 == lStack_100);
  puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a678 ^ 0x9e028712);
  if (*plStack_150 == lStack_100) goto LAB_00104e24;
  do {
    _objc_enumerationMutation(puVar11,local_108);
LAB_00104e24:
    do {
      uVar6 = *(undefined8 *)(lStack_158 + lVar12 * 8);
      _objc_msgSend(uVar6,puVar2);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar8,puVar3);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      iVar5 = FUN_00112b1c(uVar9,puVar1,&PTR____CFConstantStringClassReference_01186fc0);
      _objc_release(uVar9);
      _objc_release(uVar8);
      iStack_cc = iVar5;
      if (iVar5 != 0) {
        _objc_msgSend(uVar6,PTR_s_itag_0114d010);
        _objc_retain(uVar6);
        goto LAB_00104fa8;
      }
      bVar4 = lVar7 + -1 == lVar12;
      uStack_e4 = (uint)bVar4;
      if (bVar4) {
        lVar7 = _objc_msgSend(local_108,puStack_118,&uStack_160,puStack_110,0x10);
        uVar6 = 0;
        uStack_f4 = (uint)(lVar7 == 0);
        if (lVar7 == 0) goto LAB_00104fa8;
        goto LAB_00104dd8;
      }
      lVar12 = lVar12 + 1;
      uStack_b4 = (uint)(*plStack_150 == lStack_100);
      puVar11 = local_b0[uStack_b4] + (int)-(uRam000000000118a678 ^ 0x9e028712);
    } while (*plStack_150 == lStack_100);
  } while( true );
}


