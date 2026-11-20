/* Decompiled from supplied 5.2.2 arm package. VA 0x217570. hideSlimBarWithStyle: */

/* Function Stack Size: 0x18 bytes */

void YTPSleepTimer::hideSlimBarWithStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  ID IVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStack_1f0 [128];
  undefined8 uStack_170;
  undefined8 *puStack_168;
  long *plStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  unsigned_long_long uStack_130;
  ID IStack_128;
  undefined1 *puStack_120;
  undefined *puStack_118;
  undefined8 uStack_110;
  undefined **local_108;
  uint uStack_fc;
  undefined **local_f8;
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
  uint uStack_94;
  undefined **local_90;
  undefined **local_88;
  uint local_7c;
  undefined **local_78;
  long local_70;
  
  local_70 = *(long *)PTR____stack_chk_guard_01060708;
  local_78 = &PTR__objc_msgSend_011ccc80;
  local_7c = (uint)(DAT_012281d8 == 0);
  local_90 = &PTR_LAB_011ccca0;
  local_a0 = &PTR_LAB_011cccb8;
  local_88 = &PTR_LAB_011cbe30;
  local_b8 = &PTR_LAB_011cbe30;
  ppuStack_b0 = &PTR_LAB_011cbe30;
  local_c0 = &PTR_LAB_011ccce0;
  local_d8 = &PTR_LAB_011ccd00;
  ppuStack_d0 = &PTR_LAB_011cbe30;
  local_e8 = &PTR_setVolumeLevel__011ccd18;
  local_f8 = &PTR_LAB_011ccd30;
  local_108 = &PTR_LAB_011cbe30;
  DAT_012281d8 = 1;
  _objc_msgSend(param_1,PTR_s_barsForStyle__0114e528,param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _objc_msgSend(uVar4,PTR_s_count_0114b840);
  uStack_94 = (uint)(lVar5 == 0);
  if (lVar5 != 0) {
    uStack_148 = 0;
    uStack_150 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    puStack_168 = (undefined8 *)0x0;
    uStack_170 = 0;
    uStack_158 = 0;
    plStack_160 = (long *)0x0;
    uStack_130 = param_3;
    IStack_128 = param_1;
    uVar6 = _objc_retain(uVar4);
    puStack_118 = PTR_s_countByEnumeratingWithState_obje_0114b4e8;
    lVar5 = _objc_msgSend(uVar6,PTR_s_countByEnumeratingWithState_obje_0114b4e8,&uStack_170,
                          auStack_1f0,0x10);
    puVar2 = PTR_s_setDismissing__0114e4f8;
    puVar1 = PTR_s_setDisplayed__0114e4f0;
    uStack_a4 = (uint)(lVar5 == 0);
    if (lVar5 != 0) {
      uStack_c4 = (uint)(*plStack_160 == *plStack_160);
      puStack_120 = auStack_1f0;
      uStack_110 = uVar4;
      if (*plStack_160 != *plStack_160) {
        _objc_enumerationMutation
                  (local_c0[uStack_c4] + (int)-(uRam00000000011cccf0 ^ 0x5af5c60f),uVar4);
      }
      uVar4 = *puStack_168;
      _objc_msgSend(uVar4,puVar1,0);
      _objc_msgSend(uVar4,puVar2,1);
      uStack_dc = (uint)(lVar5 == 1);
                    /* WARNING: Could not recover jumptable at 0x00217b3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d8[uStack_dc] + (int)-(uRam00000000011ccd10 ^ 0xf8e2017c)))();
      return;
    }
    _objc_release(local_a0[uStack_a4] + (int)-(uRam00000000011cccc8 ^ 0xf5406681),uVar4);
    IVar3 = IStack_128;
    _objc_msgSend(IStack_128,PTR_s_slimBarVisibilityChange__0114e540,uStack_130);
    _objc_msgSend(IVar3,PTR_s_finishTimerAndCleanup_0114e440);
    uStack_fc = FUN_0021a7ac(IVar3,PTR_s_pausePlayback_0114e548);
    if (uStack_fc != 0) {
      uVar6 = _objc_getClass(local_f8[uStack_fc] + (int)-(uRam00000000011ccd40 ^ 0x53aef9c3),
                             s_YTAlertView_011cbd19);
      _objc_msgSend(uVar6,PTR_s_infoDialog_0114b270);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_ytl_localized_0114d190;
      _objc_msgSend(&PTR____CFConstantStringClassReference_011cbd90,PTR_s_ytl_localized_0114d190);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setTitle__0114afc0,uVar7);
      _objc_release(uVar7);
      _objc_msgSend(&PTR____CFConstantStringClassReference_011cbd50,puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_setSubtitle__0114b280,uVar7);
      _objc_release(uVar7);
      _objc_msgSend(uVar6,PTR_s_show_0114b288);
      _objc_release(uVar6);
    }
  }
  _objc_release(uVar4);
  CallSupervisor(0xaaeb);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_70) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


