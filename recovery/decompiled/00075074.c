/* Decompiled from supplied 5.2.2 arm package. VA 0x75074. FUN_00075074 */

undefined1  [16] FUN_00075074(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  puVar1 = PTR_s__viewControllerForAncestor_0114ade0;
  DAT_01226ba8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117bdb0)[DAT_01226890 == 0] +
                                  (int)-(DAT_0117bdc0 ^ 0x1f546635),
                                  s_YTMainAppVideoPlayerOverlayViewC_011646a0);
  }
  lVar2 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar3 = FUN_000db114(uVar4,PTR_s_isKindOfClass__0114ad70,lVar2);
  if (iVar3 == 0) {
    _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uVar4 = uVar5;
  }
  _objc_msgSend(uVar4,PTR_s_parentViewController_0114ad68);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,PTR_s_showDownloadSheet_withSender__0114c780,uVar5,
                param_3);
  _objc_release(param_3);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0x14ae);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}


