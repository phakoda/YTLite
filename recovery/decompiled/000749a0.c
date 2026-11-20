/* Decompiled from supplied 5.2.2 arm package. VA 0x749a0. FUN_000749a0 */

undefined1  [16] FUN_000749a0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined1 auVar5 [16];
  
  _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_resetAutoHideTimer_0114c748);
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_parentViewController_0114ad68);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  dVar4 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,PTR_s_playbackRateForPlayer__0114b970,
                                uVar3);
  if (dVar4 < 5.0) {
    _objc_msgSend((double)(float)(dVar4 + 0.25),PTR_YTPSpeedMaster_0114eca0,
                  PTR_s_setPlaybackRate_forPlayer__0114c750,uVar3);
  }
  _objc_release(uVar3);
  _objc_release(uVar1);
  CallSupervisor(0xe330);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


