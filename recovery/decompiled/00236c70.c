/* Decompiled from supplied 5.2.2 arm package. VA 0x236c70. handlePan: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void YTPSpeedPopupController::handlePan_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined *puVar8;
  double dVar9;
  double in_d1;
  double dVar10;
  
  _objc_retain(param_3);
  puVar1 = PTR_s_view_0114b090;
  _objc_msgSend(param_1,PTR_s_view_0114b090);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_translationInView__0114c898,uVar3);
  dVar10 = in_d1;
  _objc_release(uVar3);
  puVar2 = PTR_s_state_0114c560;
  lVar4 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  if (lVar4 == 2) {
    dVar9 = (double)_objc_msgSend(param_1,PTR_s_bottomConstant_0114e7e8);
    dVar10 = in_d1;
    if (in_d1 <= 0.0) {
      dVar10 = DAT_00c4c258 * in_d1;
    }
    _objc_msgSend(param_1,PTR_s_bottomConstraint_0114e7f0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(dVar10 + dVar9,uVar3,PTR_s_setConstant__0114b920);
    _objc_release(uVar3);
    dVar10 = 1.0;
    if (in_d1 / 200.0 <= 1.0) {
      dVar10 = in_d1 / 200.0;
    }
    if (dVar10 <= 0.0) {
      dVar10 = 0.0;
    }
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((1.0 - dVar10) * DAT_00c4c2f0,uVar3,PTR_s_colorWithAlphaComponent__0114b548);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_setBackgroundColor__0114b550,uVar5);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar3);
    _objc_msgSend(param_1,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_layoutIfNeeded_0114b928);
    _objc_release(uVar3);
LAB_00237068:
    _objc_release(param_3);
    CallSupervisor(0x144e);
    return;
  }
  lVar4 = _objc_msgSend((&PTR_LAB_011d1f68)[lVar4 == 2] + (int)-(DAT_011d1f78 ^ 0xbee489fe),param_3,
                        puVar2);
  puVar8 = (&PTR_LAB_011d1f88)[lVar4 == 3] + (int)-(uRam00000000011d1f98 ^ 0xcc428557);
  if (lVar4 != 3) {
    lVar4 = _objc_msgSend(puVar8,param_3,puVar2);
    puVar8 = (&PTR_LAB_011d1fa0)[lVar4 == 4] + (int)-(uRam00000000011d1fb0 ^ 0x6189ebe7);
    if (lVar4 != 4) goto LAB_00237068;
  }
  _objc_msgSend(puVar8,param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_velocityInView__0114c880,uVar3);
  _objc_release(uVar3);
  uVar7 = (uint)(120.0 < in_d1);
  if (_UNK_00c4c518 < dVar10) {
    uVar7 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00236e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011d1fb8)[uVar7] + (int)-(uRam00000000011d1fc8 ^ 0x4303fdff)))();
  return;
}


