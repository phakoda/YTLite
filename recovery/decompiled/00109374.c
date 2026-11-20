/* Decompiled from supplied 5.2.2 arm package. VA 0x109374. hasCaptions: */

/* Function Stack Size: 0x18 bytes */

bool DownloadMenuHelper::hasCaptions_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined1 auStack_240 [128];
  undefined8 uStack_1c0;
  undefined8 *puStack_1b8;
  long *plStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined1 *puStack_178;
  undefined *puStack_170;
  long lStack_168;
  long lStack_160;
  undefined **local_158;
  undefined **local_150;
  undefined **local_140;
  uint uStack_134;
  undefined **local_130;
  undefined **local_128;
  uint uStack_11c;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  undefined **local_d0;
  undefined **ppuStack_c8;
  uint uStack_bc;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **ppuStack_a0;
  int iStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR_LAB_0118adb8;
  local_7c = (uint)(DAT_012271f8 == 0);
  local_90 = &PTR_LAB_0118add8;
  local_88 = &PTR_LAB_011882f0;
  local_a8 = &PTR_LAB_0118adf8;
  ppuStack_a0 = &PTR_LAB_011882f0;
  local_b8 = &PTR_LAB_0118ae10;
  local_d0 = &PTR_LAB_011882f0;
  ppuStack_c8 = &PTR_LAB_011882f0;
  local_d8 = &PTR_LAB_0118ae38;
  local_f0 = &PTR_LAB_0118ae58;
  ppuStack_e8 = &PTR_LAB_011882f0;
  local_100 = &PTR_LAB_0118ae70;
  local_110 = &PTR_LAB_011882f0;
  local_118 = &PTR_LAB_0118ae90;
  local_128 = &PTR_LAB_011882f0;
  local_130 = &PTR_LAB_0118aeb0;
  local_140 = &PTR_LAB_0118aec8;
  local_150 = &PTR_LAB_011882f0;
  local_158 = &PTR_LAB_011882f0;
  DAT_012271f8 = 1;
  _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_availableCaptionTracks_0114cb80);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  iStack_94 = FUN_001140d4(&PTR____CFConstantStringClassReference_01187850);
  if (iStack_94 == 0) {
    uStack_ac = (uint)(lVar7 == 0);
    if (lVar7 != 0) {
      uStack_198 = 0;
      uStack_1a0 = 0;
      uStack_188 = 0;
      uStack_190 = 0;
      puStack_1b8 = (undefined8 *)0x0;
      uStack_1c0 = 0;
      uStack_1a8 = 0;
      plStack_1b0 = (long *)0x0;
      uVar6 = _objc_retain(local_a8[uStack_ac] + (int)-(uRam000000000118ae08 ^ 0xc915f782),lVar7);
      puStack_170 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
      lStack_160 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_1c0,
                                 auStack_240,0x10);
      puVar2 = PTR_s_VSSID_0114d078;
      puVar1 = PTR_s_hasPrefix__0114aea0;
      uStack_bc = (uint)(lStack_160 == 0);
      if (lStack_160 != 0) {
        lStack_168 = *plStack_1b0;
        lStack_160 = lStack_160 + -1;
        bVar3 = *plStack_1b0 == lStack_168;
        uStack_dc = (uint)bVar3;
        puStack_178 = auStack_240;
        if (!bVar3) {
          _objc_enumerationMutation
                    (local_d8[bVar3] + (int)-(uRam000000000118ae48 ^ 0xf1136a5b),lVar7);
        }
        uVar10 = *puStack_1b8;
        _objc_msgSend(uVar10,puVar2);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        uStack_f4 = FUN_00114030(uVar6,puVar1,&PTR____CFConstantStringClassReference_01187810);
        if (uStack_f4 == 0) {
          _objc_msgSend(local_f0[uStack_f4] + (int)-(uRam000000000118ae68 ^ 0x74130b3),uVar10,puVar2
                       );
          uVar8 = _objc_retainAutoreleasedReturnValue();
          uStack_104 = FUN_00113fc8(uVar8,puVar1,&PTR____CFConstantStringClassReference_011877d0);
          if (uStack_104 == 0) {
            _objc_msgSend(uVar10,puVar2);
            uVar10 = _objc_retainAutoreleasedReturnValue();
            uVar4 = FUN_0011411c(uVar10,puVar1,&PTR____CFConstantStringClassReference_01187790);
            _objc_release(uVar10);
            _objc_release(uVar8);
            _objc_release(uVar6);
            uStack_11c = uVar4;
                    /* WARNING: Could not recover jumptable at 0x001098ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            bVar5 = (*(code *)(local_118[uVar4] + (int)-(uRam000000000118aea0 ^ 0xef9988f4)))();
            return bVar5;
          }
          _objc_release(local_100[uStack_104] + (int)-(uRam000000000118ae80 ^ 0x791603c2),uVar8);
        }
        _objc_release(uVar6);
        uStack_134 = (uint)(lStack_160 == 0);
                    /* WARNING: Could not recover jumptable at 0x00109998. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        bVar5 = (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118aec0 ^ 0xa83fce8f)))();
        return bVar5;
      }
      _objc_release(local_b8[uStack_bc] + (int)-(uRam000000000118ae20 ^ 0xb3f641e1),lVar7);
    }
    bVar5 = 0;
  }
  else {
    lVar9 = _objc_msgSend(lVar7,PTR_s_count_0114b840);
    bVar5 = (bool)(lVar9 != 0);
  }
  _objc_release(lVar7);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return bVar5;
}


