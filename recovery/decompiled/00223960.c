/* Decompiled from supplied 5.2.2 arm package. VA 0x223960. manageSpeedMaster:playerOverlayVC: */

/* Function Stack Size: 0x20 bytes */

void YTPSpeedMaster::manageSpeedMaster_playerOverlayVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  float fVar10;
  undefined8 uVar11;
  double dVar12;
  double dVar13;
  
  DAT_01228330 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_storeStrong(param_1 + 0x58,param_4);
  uVar5 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_integerForKey__0114b3a8,
                        &PTR____CFConstantStringClassReference_011ce890);
  *(undefined8 *)(param_1 + 0x10) = uVar5;
  _objc_msgSend(param_1,PTR_s_speedArray_0114e6d8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar8 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar5;
  _objc_release(uVar8);
  *(undefined8 *)(param_1 + 0x18) = 0x3fd0000000000000;
  dVar13 = 5.0;
  uVar5 = 0x4014000000000000;
  if (*(long *)(param_1 + 0x10) != 2) {
    uVar5 = 0x4024000000000000;
  }
  *(undefined8 *)(param_1 + 0x20) = uVar5;
  *(undefined8 *)(param_1 + 0x28) = 0x3fa999999999999a;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ce850,PTR_s_ytl_localized_0114d190);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_floatForKey__0114c308,
                        &PTR____CFConstantStringClassReference_011ce810);
  puVar3 = PTR_s_state_0114c560;
  lVar6 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  if (lVar6 == 1) {
    _objc_msgSend(param_3,PTR_s_view_0114b090);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(param_3,PTR_s_locationInView__0114c978,uVar7);
    *(undefined8 *)(param_1 + 0x38) = uVar11;
    *(double *)(param_1 + 0x40) = dVar13;
    _objc_release(uVar7);
    uVar7 = _objc_msgSend(param_1,PTR_s_currentPlaybackRate_0114c6c0);
    *(undefined8 *)(param_1 + 0x30) = uVar7;
    uVar7 = _objc_msgSend(uVar8,param_1,PTR_s_nearestIndexForRate__0114e6e0);
    *(undefined8 *)(param_1 + 0x50) = uVar7;
    *(undefined8 *)(param_1 + 0x48) = uVar8;
    _objc_msgSend(uVar8,param_1,PTR_s_setPlaybackRate__0114c758);
    _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar11 = FUN_00227144(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                          &PTR____CFConstantStringClassReference_011ce7d0);
    _objc_msgSend(uVar8,uVar7,PTR_s_showPlayerToastWithText_value_st_0114c9c8,uVar5,1,uVar11);
LAB_00224f28:
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(param_4);
    _objc_release(param_3);
    CallSupervisor(0xd182);
    return;
  }
  lVar6 = _objc_msgSend((&PTR_LAB_011cedd0)[lVar6 == 1] + (int)-(uRam00000000011cede0 ^ 0x923025ba),
                        param_3,puVar3);
  puVar9 = (&PTR_LAB_011cedf0)[lVar6 == 2] + (int)-(uRam00000000011cee00 ^ 0xe4551dbd);
  if (lVar6 == 2) {
    uVar4 = FUN_00226b14(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                         &PTR____CFConstantStringClassReference_011ce790);
    puVar9 = (&PTR_LAB_011cee08)[uVar4] + (int)-(uRam00000000011cee18 ^ 0x1d264659);
    if (uVar4 != 0) {
      _objc_msgSend(param_3,PTR_s_view_0114b090);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,PTR_s_locationInView__0114c978,uVar8);
      _objc_release(uVar8);
      dVar13 = *(double *)(param_1 + 0x40) - dVar13;
      if (*(long *)(param_1 + 0x10) == 2) {
        dVar12 = *(double *)(&UNK_00c4c4f0 + (ulong)(0.0 < dVar13) * 8);
        lVar6 = _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_count_0114b840);
        uVar1 = *(long *)(param_1 + 0x50) + (long)(dVar13 * dVar12);
        uVar2 = lVar6 - 1U;
        if ((long)uVar1 <= (long)(lVar6 - 1U)) {
          uVar2 = uVar1;
        }
        _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_objectAtIndexedSubscript__0114aeb0,
                      uVar2 & ((long)uVar2 >> 0x3f ^ 0xffffffffffffffffU));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        fVar10 = (float)_objc_msgSend(uVar8,PTR_s_floatValue_0114c768);
        _objc_msgSend((double)fVar10,param_1,PTR_s_setPlaybackRate__0114c758);
        _objc_release(uVar8);
      }
      else {
        dVar12 = *(double *)(param_1 + 0x48) +
                 *(double *)(&DAT_00c4c500 + (ulong)(ABS(dVar13) < 40.0) * 8) * dVar13;
        dVar13 = *(double *)(param_1 + 0x20);
        if (dVar12 <= *(double *)(param_1 + 0x20)) {
          dVar13 = dVar12;
        }
        if (dVar13 <= *(double *)(param_1 + 0x18)) {
          dVar13 = *(double *)(param_1 + 0x18);
        }
        _objc_msgSend(*(double *)(param_1 + 0x28) *
                      (double)(long)(dVar13 / *(double *)(param_1 + 0x28)),param_1,
                      PTR_s_setPlaybackRate__0114c758);
      }
      _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,PTR_s_currentPlaybackRate_0114c6c0);
      _objc_msgSend(uVar7,PTR_s_updateToastText_value__0114c9d0,uVar5);
      goto LAB_00224f28;
    }
  }
  lVar6 = _objc_msgSend(puVar9,param_3,puVar3);
  puVar9 = (&PTR_LAB_011cee50)[lVar6 == 2] + (int)-(uRam00000000011cee60 ^ 0xe7136b1f);
  if (lVar6 == 2) {
    uVar4 = FUN_00226d7c(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                         &PTR____CFConstantStringClassReference_011ce790);
    puVar9 = (&PTR_LAB_011cee68)[uVar4] + (int)-(uRam00000000011cee78 ^ 0x49f50396);
    if (uVar4 != 0) {
      _objc_msgSend(param_3,PTR_s_view_0114b090);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,PTR_s_locationInView__0114c978,uVar8);
      _objc_release(uVar8);
      dVar12 = *(double *)(param_1 + 0x40);
      lVar6 = _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_count_0114b840);
      uVar1 = *(long *)(param_1 + 0x50) + (long)((dVar12 - dVar13) / 30.0);
      uVar2 = lVar6 - 1U;
      if ((long)uVar1 <= (long)(lVar6 - 1U)) {
        uVar2 = uVar1;
      }
      _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_objectAtIndexedSubscript__0114aeb0,
                    uVar2 & ((long)uVar2 >> 0x3f ^ 0xffffffffffffffffU));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      fVar10 = (float)_objc_msgSend(uVar8,PTR_s_floatValue_0114c768);
      _objc_release(uVar8);
      _objc_msgSend((double)fVar10,param_1,PTR_s_setPlaybackRate__0114c758);
      _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend((double)fVar10,uVar7,PTR_s_updateToastText_value__0114c9d0,uVar5);
      goto LAB_00224f28;
    }
  }
  lVar6 = _objc_msgSend(puVar9,param_3,puVar3);
                    /* WARNING: Could not recover jumptable at 0x002249d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cee88)[lVar6 == 3] + (int)-(uRam00000000011cee98 ^ 0xfb30699f)))();
  return;
}


