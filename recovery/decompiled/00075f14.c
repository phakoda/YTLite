/* Decompiled from supplied 5.2.2 arm package. VA 0x75f14. FUN_00075f14 */

undefined1  [16] FUN_00075f14(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  undefined1 auVar9 [16];
  
  DAT_01226bb8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117bef0)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117bf00 ^ 0x7dce4994),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164920);
  }
  lVar8 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  puVar1 = PTR_s_isKindOfClass__0114ad70;
  iVar3 = FUN_000db74c(uVar5,PTR_s_isKindOfClass__0114ad70,lVar8);
  if (iVar3 == 0) {
    _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    uVar5 = uVar6;
  }
  _objc_msgSend(uVar5,PTR_s_parentViewController_0114ad68);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226898 == 0) {
    DAT_01226898 = _objc_getClass((&PTR_LAB_0117bf30)[DAT_01226898 == 0] +
                                  (int)-(uRam000000000117bf40 ^ 0x50fa04af),
                                  s_YTPlayerViewController_011649a0);
  }
  lVar8 = DAT_01226898;
  _objc_retainAutorelease(DAT_01226898);
  uVar4 = FUN_000db67c(uVar6,puVar1,lVar8);
  puVar2 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  if (uVar4 != 0) {
    uVar4 = FUN_000db6e4(uVar6,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0);
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_0117bf68)[uVar4] + (int)-(uRam000000000117bf78 ^ 0x6204af88),uVar6,
                    puVar2);
      lVar8 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00076f88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar9 = (*(code *)((&PTR_LAB_0117bf98)[lVar8 == 0] +
                         (int)-(uRam000000000117bfa8 ^ 0x34850606)))();
      return auVar9;
    }
    uVar7 = FUN_000db5f4(uVar6,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
                    /* WARNING: Could not recover jumptable at 0x00076f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar9 = (*(code *)((&PTR_LAB_0117bf80)[uVar7 & 0xffffffff] +
                       (int)-(uRam000000000117bf90 ^ 0x29716a49)))();
    return auVar9;
  }
  _objc_release((&PTR_LAB_0117bf50)[uVar4] + (int)-(uRam000000000117bf60 ^ 0xb799602),uVar6);
  _objc_release(uVar5);
  _objc_release(param_3);
  CallSupervisor(0xf993);
  auVar9._8_8_ = 0x1f;
  auVar9._0_8_ = 0x1a;
  return auVar9;
}


