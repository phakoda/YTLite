/* Decompiled from supplied 5.2.2 arm package. VA 0xb43a8. FUN_000b43a8 */

undefined1  [16] FUN_000b43a8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  double dVar11;
  undefined1 auVar12 [16];
  
  DAT_01226ea8 = 1;
  uVar3 = _objc_retain(param_3);
  puVar1 = PTR_s_delegate_0114b530;
  _objc_msgSend(uVar3,PTR_s_delegate_0114b530);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_locationInView__0114c978,param_1);
  if (lVar4 != 0) {
    uVar2 = FUN_000e93bc(lVar4,PTR_s_isTouchInSpeedZone__0114cca0);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_01181960)[uVar2] + (int)-(uRam0000000001181970 ^ 0xbce6d1c9),param_1,
                    puVar1);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_player_0114c920);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar3);
      puVar1 = PTR_s_state_0114c560;
      lVar6 = _objc_msgSend(param_3,PTR_s_state_0114c560);
      if (lVar6 == 1) {
        _objc_msgSend(0x4000000000000000,PTR_YTPSpeedMaster_0114eca0,
                      PTR_s_setPlaybackRate_forPlayer__0114c750,uVar5);
        _objc_msgSend(PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,PTR_s_localizedStringForKey_value_tabl_0114b278,
                      &PTR____CFConstantStringClassReference_01170500,0,0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = FUN_000e9460(&PTR____CFConstantStringClassReference_011704c0);
        _objc_msgSend(0x4000000000000000,uVar3,PTR_s_showPlayerToastWithText_value_st_0114c9c8,uVar8
                      ,1,uVar9);
        _objc_release(uVar8);
        _objc_release(uVar7);
        _objc_release(uVar3);
      }
      lVar6 = _objc_msgSend(param_3,puVar1);
      puVar10 = (&PTR_LAB_01181998)[lVar6 == 3] + (int)-(uRam00000000011819a8 ^ 0xa5421865);
      if (lVar6 != 3) {
        lVar6 = _objc_msgSend(puVar10,param_3,puVar1);
        puVar10 = (&PTR_LAB_011819b0)[lVar6 == 4] + (int)-(uRam00000000011819c0 ^ 0x4c221d71);
        if (lVar6 != 4) {
          _objc_release(uVar5);
          goto LAB_000b4f14;
        }
      }
      _objc_msgSend(puVar10,PTR_PlayerToast_0114eda8,PTR_s_sharedToast_0114c9c0);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      dVar11 = (double)_objc_msgSend(uVar3,PTR_s_alpha_0114c9d8);
      _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x000b4e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar12 = (*(code *)((&PTR_LAB_011819c8)[dVar11 == 0.0] +
                          (int)-(uRam00000000011819d8 ^ 0xb52ede8c)))();
      return auVar12;
    }
  }
LAB_000b4f14:
  _objc_release(lVar4);
  _objc_release(param_3);
  CallSupervisor(0x1507);
  auVar12._8_8_ = 0x1f;
  auVar12._0_8_ = 0x1a;
  return auVar12;
}


