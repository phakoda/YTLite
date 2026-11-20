/* Decompiled from supplied 5.2.2 arm package. VA 0x759c4. FUN_000759c4 */

undefined1  [16] FUN_000759c4(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  DAT_01226bb0 = 1;
  _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226890 == 0) {
    DAT_01226890 = _objc_getClass((&PTR_LAB_0117be70)[DAT_01226890 == 0] +
                                  (int)-(uRam000000000117be80 ^ 0xc2037588),
                                  s_YTMainAppVideoPlayerOverlayViewC_01164760);
  }
  lVar5 = DAT_01226890;
  _objc_retainAutorelease(DAT_01226890);
  iVar2 = FUN_000db30c(uVar3,PTR_s_isKindOfClass__0114ad70,lVar5);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,PTR_s_eventsDelegate_0114c740);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    uVar3 = uVar4;
  }
  puVar1 = PTR_s_lockModeStateEntityController_0114c7a8;
  _objc_msgSend(uVar3,PTR_s_lockModeStateEntityController_0114c7a8);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar5 != 0) {
    _objc_msgSend(uVar3,PTR_s_lockModeDidRequestShowFullscreen_0114c7b0);
    _objc_msgSend(uVar3,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setLockModeActive__0114c7b8,1);
    _objc_release(uVar4);
  }
  _objc_release(uVar3);
  CallSupervisor(0x2738);
  return ZEXT816(0x1f);
}


