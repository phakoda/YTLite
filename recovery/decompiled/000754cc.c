/* Decompiled from supplied 5.2.2 arm package. VA 0x754cc. FUN_000754cc */

undefined1  [16] FUN_000754cc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined **ppuVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 auVar10 [16];
  
  puVar2 = PTR_s__viewControllerForAncestor_0114ade0;
  DAT_01226bac = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117be10)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117be20 ^ 0x76153877),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164700);
  }
  lVar3 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar4 = FUN_000db2c4(uVar6,PTR_s_isKindOfClass__0114ad70,lVar3);
  if (iVar4 == 0) {
    _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
    uVar6 = uVar7;
  }
  _objc_msgSend(uVar6,PTR_s_parentViewController_0114ad68);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_activeVideo_0114c788);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  uVar5 = FUN_000db1fc(uVar8,PTR_s_isMuted_0114c790);
  _objc_msgSend(uVar8,PTR_s_setMuted__0114c798,uVar5 ^ 1);
  ppuVar1 = &PTR_s_volumeOn_0114c6f0;
  if (uVar5 == 0) {
    ppuVar1 = &PTR_s_volumeOff_0114c7a0;
  }
  _objc_msgSend(PTR_YTPMedia_0114eae0,*ppuVar1);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_setImage_forState__0114adf0,uVar9,0);
  _objc_release(param_3);
  _objc_release(uVar9);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  CallSupervisor(0x5ad5);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


