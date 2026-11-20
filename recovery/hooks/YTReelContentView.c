// Decompiled hook evidence for YTReelContentView. This is not compilable Logos source.

// -[YTReelContentView setPlaybackView:], original IMP slot 0x01226748
/* Decompiled from supplied 5.2.2 arm package. VA 0xb3ef0. FUN_000b3ef0 */

void FUN_000b3ef0(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  DAT_01226ea4 = 1;
  (*DAT_01226748)(param_1);
  uVar3 = 0x3ff0000000000000;
  if (DAT_0115cd38 == '\0') {
    uVar3 = 0;
  }
  _objc_msgSend(param_1,@selector(playbackOverlay));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,uVar1,@selector(setAlpha:));
  _objc_release(uVar1);
  uVar2 = FUN_000e9194(@"shortsOnlyMode");
                    /* WARNING: Could not recover jumptable at 0x000b4200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181900)[uVar2 & 0xffffffff] + (int)-(DAT_01181910 ^ 0x65a85f33)))();
  return;
}



// -[YTReelContentView reelSpeedmaster:], original IMP slot None
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
  puVar1 = @selector(delegate);
  _objc_msgSend(uVar3,@selector(delegate));
  lVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,@selector(locationInView:),param_1);
  if (lVar4 != 0) {
    uVar2 = FUN_000e93bc(lVar4,@selector(isTouchInSpeedZone:));
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_01181960)[uVar2] + (int)-(uRam0000000001181970 ^ 0xbce6d1c9),param_1,
                    puVar1);
      uVar3 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,@selector(player));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar3);
      puVar1 = @selector(state);
      lVar6 = _objc_msgSend(param_3,@selector(state));
      if (lVar6 == 1) {
        _objc_msgSend(0x4000000000000000,PTR_YTPSpeedMaster_0114eca0,
                      @selector(setPlaybackRate:forPlayer:),uVar5);
        _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
        uVar3 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,@selector(ytl_defaultBundle));
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,@selector(localizedStringForKey:value:table:),
                      @"Toast.PlaybackSpeed",0,0);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = FUN_000e9460(@"compactToast");
        _objc_msgSend(0x4000000000000000,uVar3,@selector(showPlayerToastWithText:value:style:isCompact:),uVar8
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
      _objc_msgSend(puVar10,PTR_PlayerToast_0114eda8,@selector(sharedToast));
      uVar3 = _objc_retainAutoreleasedReturnValue();
      dVar11 = (double)_objc_msgSend(uVar3,@selector(alpha));
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



// -[YTReelContentView dealloc], original IMP slot 0x01226750
/* Decompiled from supplied 5.2.2 arm package. VA 0xb4f94. FUN_000b4f94 */

void FUN_000b4f94(void)

{
  undefined8 uVar1;
  double dVar2;
  
  DAT_01226eac = 1;
  _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
  uVar1 = _objc_retainAutoreleasedReturnValue();
  dVar2 = (double)_objc_msgSend(uVar1,@selector(alpha));
  _objc_release(uVar1);
                    /* WARNING: Could not recover jumptable at 0x000b5294. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181a10)[dVar2 == 1.0] + (int)-(DAT_01181a20 ^ 0x76043541)))();
  return;
}



// -[YTReelContentView turnShortsOnlyModeOff:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0xb5410. FUN_000b5410 */

undefined1  [16] FUN_000b5410(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  DAT_01226eb0 = 1;
  lVar1 = _objc_msgSend(param_3,@selector(state));
  if (lVar1 == 1) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(setBool:forKey:),0,
                  @"shortsOnlyMode");
    _objc_release(uVar2);
    _dispatch_async(PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01062090);
    _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(delegate));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,@selector(window));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar3);
    _objc_release(uVar2);
    _objc_msgSend(uVar4,@selector(rootViewController));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(0x3ff0000000000000,uVar2,@selector(performSelector:withObject:afterDelay:),
                  @selector(showPivotBar),0);
    _objc_release(uVar2);
    _objc_release(uVar4);
  }
  CallSupervisor(0x3c1b);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


