/* Decompiled from supplied 5.2.2 arm package. VA 0x8540. FUN_00008540 */

void FUN_00008540(void)

{
  undefined8 uVar1;
  undefined4 uStack_440;
  undefined1 uStack_43c;
  undefined **local_40;
  uint local_34;
  undefined **local_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  local_30 = &PTR_LAB_01151290;
  local_34 = (uint)(DAT_012258a4 == 0);
  local_40 = &PTR_LAB_011510e0;
  DAT_012258a4 = 1;
  uVar1 = _objc_getClass(s_YTPlayerViewController_01150880);
  _MSHookMessageEx(uVar1,PTR_s_playbackController_didActivateVi_0114ad10,FUN_00008c38,0x1225850);
  _MSHookMessageEx(uVar1,PTR_s_seekToTime__0114ad18,FUN_000092b8,0x1225858);
  _MSHookMessageEx(uVar1,PTR_s_seekToTime_seekSource__0114ad20,recovered_hook_00009a00,0x1225860);
  _MSHookMessageEx(uVar1,PTR_s_seekToTime_toleranceBefore_toler_0114ad28,FUN_0000a14c,0x1225868);
  _MSHookMessageEx(uVar1,PTR_s_singleVideo_currentVideoTimeDidC_0114ad30,FUN_0000a89c,0x1225870);
  _MSHookMessageEx(uVar1,PTR_s_potentiallyMutatedSingleVideo_cu_0114ad38,FUN_0000aafc,0x1225878);
  uVar1 = _objc_getClass(s_YTWatchPlaybackController_01150840);
  _MSHookMessageEx(uVar1,PTR_s_playbackControllerDidPlay_0114ad40,FUN_0000ad54,0x1225880);
  _MSHookMessageEx(uVar1,PTR_s_playbackControllerDidPause_0114ad48,FUN_0000af78,&DAT_01225888);
  _MSHookMessageEx(uVar1,PTR_s_playbackControllerDidFinishPlayb_0114ad50,FUN_0000b19c,&DAT_01225890)
  ;
  _MSHookMessageEx(uVar1,PTR_s_clearPlaybackController_0114ad58,FUN_0000b3a0,&DAT_01225898);
  uVar1 = _objc_getClass(s_YTMainAppControlsOverlayView_01150800);
  uStack_440 = (undefined4)DAT_00c4c220;
  uStack_43c = 0;
  FUN_0000ba70(uVar1,PTR_s_handleYTLDiscordTap__0114ad60,FUN_0000b598,&uStack_440);
  CallSupervisor(0xd35b);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1f,0,0,0);
}


