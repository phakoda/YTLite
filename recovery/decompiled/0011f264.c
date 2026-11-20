/* Decompiled from supplied 5.2.2 arm package. VA 0x11f264. tableView:didSelectRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

void DVNTableViewController::tableView_didSelectRowAtIndexPath_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auStack_2a0 [64];
  undefined1 auStack_260 [48];
  undefined1 *puStack_230;
  undefined1 *puStack_228;
  ID IStack_220;
  undefined **local_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **ppuStack_1f0;
  undefined **local_1e0;
  undefined **ppuStack_1d8;
  undefined **local_1c8;
  undefined **local_1c0;
  undefined **ppuStack_1b8;
  undefined **local_1a8;
  undefined **local_198;
  undefined **ppuStack_190;
  undefined **local_180;
  undefined **ppuStack_178;
  undefined **local_170;
  undefined **ppuStack_168;
  undefined **local_158;
  undefined **local_148;
  undefined **ppuStack_140;
  uint uStack_134;
  undefined **local_130;
  undefined **ppuStack_128;
  undefined **local_120;
  undefined **ppuStack_118;
  uint uStack_10c;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
  undefined **ppuStack_f0;
  uint uStack_e4;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  int iStack_b4;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  
  local_70 = &PTR_LAB_0118d970;
  local_74 = (uint)(DAT_012272f4 == 0);
  local_88 = &PTR_LAB_0118d990;
  local_a0 = &PTR_LAB_0118d9b0;
  local_b0 = &PTR_LAB_0118d9c8;
  local_80 = &PTR__objc_msgSend_0118c130;
  local_98 = &PTR__objc_msgSend_0118c130;
  local_c8 = &PTR__objc_msgSend_0118c130;
  ppuStack_c0 = &PTR__objc_msgSend_0118c130;
  local_d0 = &PTR_LAB_0118d9f0;
  local_e0 = &PTR_LAB_0118da08;
  local_f8 = &PTR_LAB_0118da28;
  ppuStack_f0 = &PTR__objc_msgSend_0118c130;
  local_108 = &PTR_LAB_0118da40;
  local_120 = &PTR__objc_msgSend_0118c130;
  ppuStack_118 = &PTR__objc_msgSend_0118c130;
  local_130 = &PTR_LAB_0118da70;
  ppuStack_128 = &PTR__objc_msgSend_0118c130;
  local_148 = &PTR_LAB_0118da90;
  ppuStack_140 = &PTR__objc_msgSend_0118c130;
  local_158 = &PTR_LAB_0118daa8;
  local_170 = &PTR__objc_msgSend_0118c130;
  ppuStack_168 = &PTR__objc_msgSend_0118c130;
  local_180 = &PTR_LAB_0118dad8;
  ppuStack_178 = &PTR__objc_msgSend_0118c130;
  local_198 = &PTR_LAB_0118daf8;
  ppuStack_190 = &PTR__objc_msgSend_0118c130;
  local_1a8 = &PTR_LAB_0118db10;
  local_1c0 = &PTR__objc_msgSend_0118c130;
  ppuStack_1b8 = &PTR__objc_msgSend_0118c130;
  local_1c8 = &PTR_LAB_0118db38;
  local_1e0 = &PTR_LAB_0118db58;
  ppuStack_1d8 = &PTR__objc_msgSend_0118c130;
  local_1f8 = &PTR_LAB_0118db78;
  ppuStack_1f0 = &PTR__objc_msgSend_0118c130;
  local_210 = &PTR__objc_msgSend_0118c130;
  ppuStack_208 = &PTR__objc_msgSend_0118c130;
  local_218 = &PTR__objc_msgSend_0118c130;
  DAT_012272f4 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_msgSend(param_1,PTR_s__cellForIndexPath__0114d370,param_4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_type_0114b050;
  bVar3 = *(char *)(param_1 + (long)_isSearching) == '\0';
  uStack_8c = (uint)bVar3;
  if (!bVar3) {
    FUN_0012b348(*(undefined8 *)(param_1 + (long)_searchBar),PTR_s_resignFirstResponder_0114d1e0);
    _objc_msgSend(param_3,PTR_s_deselectRowAtIndexPath_animated__0114d480,param_4,1);
    _objc_msgSend(param_1,PTR_s_navigateToCell__0114d2a8,uVar5);
    _objc_release(uVar5);
    _objc_release(param_4);
    _objc_release(param_3);
    CallSupervisor(0x2b24);
    return;
  }
  puStack_230 = auStack_2a0;
  puStack_228 = auStack_260;
  lVar6 = _objc_msgSend(uVar5,PTR_s_type_0114b050);
  uStack_a4 = (uint)(lVar6 == 0);
  if (lVar6 == 0) {
    _objc_msgSend(param_3,PTR_s_cellForRowAtIndexPath__0114d298,param_4);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_accessoryView_0114d3c0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_getClass(s_ABCSwitch_0118bdb2);
    iStack_b4 = FUN_0012af98(uVar9,PTR_s_isKindOfClass__0114ad70,uVar7);
    if (iStack_b4 != 0) {
      _objc_msgSend(uVar9,PTR_s_prepareHapticFeedback_0114d488);
      uVar4 = FUN_0012adc8(uVar9,PTR_s_isOn_0114d490);
      _objc_msgSend(uVar9,PTR_s_setOn_animated_userGenerated__0114d498,uVar4 ^ 1,1,1);
      _objc_msgSend(uVar9,PTR_s_releaseHapticFeedback_0114d4a0);
      _objc_msgSend(uVar9,PTR_s_fireHapticFeedback_0114d4a8);
    }
    _objc_release(uVar9);
    _objc_release(uVar8);
  }
  lVar6 = _objc_msgSend(uVar5,puVar1);
  uStack_d4 = (uint)(lVar6 == 3);
  IStack_220 = param_3;
  if (lVar6 == 3) {
    _objc_msgSend(uVar5,PTR_s_subtitle_0114d1e8);
    lVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    uStack_e4 = (uint)(lVar6 == 0);
                    /* WARNING: Could not recover jumptable at 0x0011f7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_e0[uStack_e4] + (int)-(uRam000000000118da18 ^ 0xa25f9202)))();
    return;
  }
  lVar6 = _objc_msgSend(local_d0[uStack_d4] + (int)-(uRam000000000118da00 ^ 0x526baf00),uVar5,puVar1
                       );
  uStack_fc = (uint)(lVar6 == 8);
  if (lVar6 == 8) {
    _objc_msgSend(param_3,PTR_s_cellForRowAtIndexPath__0114d298,param_4);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,PTR_s_accessoryView_0114d3c0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_styleRequestedColorPickerPresent_0114d4b0;
    uStack_10c = FUN_0012b320(uVar9,PTR_s_respondsToSelector__0114af58,
                              PTR_s_styleRequestedColorPickerPresent_0114d4b0);
    if (uStack_10c == 0) {
      _objc_msgSend(uVar9,PTR_s_performSelector__0114b268,PTR_s_invokeColorPicker__0114d4b8);
    }
    else {
      _objc_msgSend(local_108[uStack_10c] + (int)-(uRam000000000118da50 ^ 0x684dc1b5),uVar9,puVar2);
    }
    _objc_release(uVar9);
    _objc_release(uVar8);
  }
  lVar6 = _objc_msgSend(uVar5,puVar1);
  uStack_134 = (uint)(lVar6 == 0xb);
                    /* WARNING: Could not recover jumptable at 0x0011f9ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_130[uStack_134] + (int)-(uRam000000000118da80 ^ 0x5928dc12)))();
  return;
}


