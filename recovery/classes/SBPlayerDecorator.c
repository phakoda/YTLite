// Decompiled implementation evidence for SBPlayerDecorator. Not compilable source.

// +[SBPlayerDecorator addDurationWithoutSegments:videoController:], 0x19b714
/* Decompiled from supplied 5.2.2 arm package. VA 0x19b714. addDurationWithoutSegments:videoController: */

/* Function Stack Size: 0x20 bytes */

void SBPlayerDecorator::addDurationWithoutSegments_videoController_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puVar5;
  double dVar6;
  undefined1 auStack_280 [136];
  undefined1 *puStack_1f8;
  undefined **local_1d0;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b8;
  undefined **ppuStack_1b0;
  undefined **local_1a0;
  undefined **ppuStack_198;
  undefined **local_188;
  undefined **local_178;
  undefined **local_168;
  undefined **local_158;
  undefined **ppuStack_150;
  undefined **local_140;
  undefined **ppuStack_138;
  undefined **local_128;
  undefined **ppuStack_120;
  undefined **local_110;
  undefined **local_108;
  undefined **ppuStack_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  uint local_9c;
  undefined **local_98;
  long local_90;
  
  local_90 = *(long *)PTR____stack_chk_guard_01060708;
  local_98 = &PTR_LAB_011ac5c0;
  local_9c = (uint)(DAT_012278d0 == 0);
  local_b0 = &PTR_LAB_011ac5e0;
  local_c0 = &PTR_LAB_011ac5f8;
  local_d0 = &PTR_LAB_011ac610;
  local_e0 = &PTR_LAB_011ac628;
  local_f0 = &PTR_LAB_011ac640;
  local_a8 = &PTR_LAB_011ac130;
  local_108 = &PTR_LAB_011ac130;
  ppuStack_100 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011ac668;
  local_128 = &PTR_LAB_011ac688;
  ppuStack_120 = &PTR_LAB_011ac130;
  local_140 = &PTR_LAB_011ac6a8;
  ppuStack_138 = &PTR_LAB_011ac130;
  local_158 = &PTR_LAB_011ac6c8;
  ppuStack_150 = &PTR_LAB_011ac130;
  local_168 = &PTR__objc_msgSend_011ac6e0;
  local_178 = &PTR_LAB_011ac6f8;
  local_188 = &PTR_LAB_011ac710;
  local_1a0 = &PTR__objc_msgSend_011ac730;
  ppuStack_198 = &PTR_LAB_011ac130;
  local_1b8 = &PTR_LAB_011ac130;
  ppuStack_1b0 = &PTR_LAB_011ac130;
  local_1c8 = &PTR_LAB_011ac130;
  ppuStack_1c0 = &PTR_LAB_011ac130;
  local_1d0 = &PTR_LAB_011ac130;
  DAT_012278d0 = 1;
  puStack_1f8 = auStack_280;
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,@selector(parentViewController));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _NSClassFromString(@"YTWatchViewController");
  uVar1 = FUN_001a12bc(uVar2,@selector(isKindOfClass:),uVar3);
  _objc_release(uVar2);
  puVar5 = local_b0[uVar1] + (int)-(DAT_011ac5f0 ^ 0x48e096fa);
  uStack_b4 = uVar1;
  if (uVar1 != 0) {
    _objc_msgSend(param_3,@selector(contentVideoID));
    lVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_c4 = (uint)(lVar4 == 0);
    puVar5 = local_c0[uStack_c4] + (int)-(uRam00000000011ac608 ^ 0x1ff2f22d);
    if (lVar4 != 0) {
      dVar6 = (double)_objc_msgSend(param_3,@selector(currentVideoTotalMediaTime));
      _objc_release(lVar4);
      uStack_d4 = (uint)(dVar6 == 0.0);
                    /* WARNING: Could not recover jumptable at 0x0019be60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(local_d0[uStack_d4] + (int)-(uRam00000000011ac620 ^ 0x2745c139)))();
      return;
    }
    uStack_c4 = 1;
  }
  _objc_release(puVar5,param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_90) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// +[SBPlayerDecorator shouldDrawRoundedForBarView:], 0x19c600
/* Decompiled from supplied 5.2.2 arm package. VA 0x19c600. shouldDrawRoundedForBarView: */

/* Function Stack Size: 0x18 bytes */

bool SBPlayerDecorator::shouldDrawRoundedForBarView_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_012278d4 = 1;
  uVar6 = _objc_retain(param_3);
  puVar1 = @selector(_viewControllerForAncestor);
  _objc_msgSend(uVar6,@selector(_viewControllerForAncestor));
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController");
  puVar2 = @selector(isKindOfClass:);
  uVar3 = FUN_001a1720(uVar6,@selector(isKindOfClass:),uVar7);
  _objc_release(uVar6);
  if (uVar3 == 0) {
    bVar5 = 0;
  }
  else {
    _objc_msgSend((&PTR_LAB_011ac790)[uVar3] + (int)-(uRam00000000011ac7a0 ^ 0x1df4e042),param_3,
                  puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(parentViewController);
    _objc_msgSend(uVar6,@selector(parentViewController));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = _NSClassFromString(@"YTPlayerViewController");
    uVar3 = FUN_001a17a8(uVar7,puVar2,uVar8);
    _objc_release(uVar7);
    if (uVar3 == 0) {
      bVar5 = 0;
    }
    else {
      _objc_msgSend((&PTR_LAB_011ac7a8)[uVar3] + (int)-(uRam00000000011ac7b8 ^ 0xd4387563),uVar6,
                    puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar1);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_getClass(s_YTWatchViewController_011ab9b0);
      uVar3 = FUN_001a1830(uVar8,puVar2,uVar9);
      _objc_release(uVar8);
      if (uVar3 == 0) {
        bVar5 = 0;
      }
      else {
        _objc_msgSend((&PTR_LAB_011ac7c0)[uVar3] + (int)-(uRam00000000011ac7d0 ^ 0xd6d85d10),uVar7,
                      puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        iVar4 = FUN_001a18a0(uVar8,@selector(respondsToSelector:),@selector(fullscreen));
        if (iVar4 == 0) {
          bVar5 = 0;
        }
        else {
          bVar5 = FUN_001a1858(uVar8,@selector(isFullscreen));
        }
        _objc_release(uVar8);
      }
      _objc_release(uVar7);
    }
    _objc_release(uVar6);
  }
  _objc_release(param_3);
  return bVar5;
}



// +[SBPlayerDecorator _decorationDataForBarView:], 0x19ce04
/* Decompiled from supplied 5.2.2 arm package. VA 0x19ce04. _decorationDataForBarView: */

/* Function Stack Size: 0x18 bytes */

ID SBPlayerDecorator::_decorationDataForBarView_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  ID IVar11;
  undefined8 in_d2;
  
  DAT_012278d8 = 1;
  _objc_retain(param_3);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001a1a50(uVar5,@selector(boolForKey:),
                       @"sponsorBlock");
  _objc_release(uVar5);
  puVar1 = @selector(_viewControllerForAncestor);
  uVar5 = 0;
  if (iVar3 != 0) {
    _objc_msgSend(param_3,@selector(_viewControllerForAncestor));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _NSClassFromString(@"YTMainAppVideoPlayerOverlayViewController");
    puVar2 = @selector(isKindOfClass:);
    uVar4 = FUN_001a1908(uVar5,@selector(isKindOfClass:),uVar6);
    _objc_release(uVar5);
    uVar5 = 0;
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_011ac848)[uVar4] + (int)-(uRam00000000011ac858 ^ 0x2115012f),param_3,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puVar1 = @selector(parentViewController);
      _objc_msgSend(uVar6,@selector(parentViewController));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      uVar7 = _NSClassFromString(@"YTPlayerViewController");
      uVar4 = FUN_001a1b78(uVar5,puVar2,uVar7);
      _objc_release(uVar5);
      if (uVar4 == 0) {
        uVar5 = 0;
      }
      else {
        _objc_msgSend((&PTR_LAB_011ac860)[uVar4] + (int)-(uRam00000000011ac870 ^ 0xae4747a7),uVar6,
                      puVar1);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(PTR_SBManager_0114eee8,@selector(sharedManager));
        uVar5 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar5,@selector(segments));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,@selector(contentVideoID));
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,@selector(objectForKey:),uVar9);
        lVar10 = _objc_retainAutoreleasedReturnValue();
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_release(uVar5);
        if (lVar10 == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = _objc_msgSend(PTR_SBPlayerDecorationData_0114eef8,@selector(new));
          _objc_msgSend(uVar5,@selector(setBarView:),param_3);
          _objc_msgSend(param_3,@selector(superview));
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_msgSend(uVar8,@selector(bounds));
          _objc_msgSend(in_d2,uVar5,@selector(setPlayerBarWidth:));
          _objc_release(uVar8);
          _objc_msgSend(uVar7,@selector(currentVideoTotalMediaTime));
          _objc_msgSend(uVar5,@selector(setMediaDuration:));
          _objc_msgSend(uVar5,@selector(setSegments:),lVar10);
        }
        _objc_release(lVar10);
        _objc_release(uVar7);
      }
      _objc_release(uVar6);
    }
  }
  _objc_release(param_3);
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
  return IVar11;
}



// +[SBPlayerDecorator drawSegmentsDecorationView:], 0x19d6c0
/* Decompiled from supplied 5.2.2 arm package. VA 0x19d6c0. drawSegmentsDecorationView: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorator::drawSegmentsDecorationView_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  _objc_msgSend(param_1,@selector(_decorationDataForBarView:));
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    _objc_msgSend(param_1,@selector(_drawSegmentsForData:),lVar1);
  }
  _objc_release(lVar1);
  CallSupervisor(0x9fa5);
  return;
}



// +[SBPlayerDecorator drawSegmentsOnActiveDecorationView:], 0x19d77c
/* Decompiled from supplied 5.2.2 arm package. VA 0x19d77c. drawSegmentsOnActiveDecorationView: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorator::drawSegmentsOnActiveDecorationView_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_012278e0 = 1;
  _objc_retain(param_3);
  _objc_msgSend(param_1,@selector(_decorationDataForBarView:),param_3);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 != 0) {
    uVar2 = _objc_msgSend(param_3,@selector(class));
    lVar3 = _class_getInstanceVariable(uVar2,s__brandGradient_011abc9d);
    if (lVar3 != 0) {
      _objc_msgSend(param_3,@selector(valueForKey:),
                    @"_brandGradient");
      lVar3 = _objc_retainAutoreleasedReturnValue();
      if (lVar3 != 0) {
        _objc_msgSend(lVar1,@selector(setBarView:),lVar3);
      }
      _objc_release(lVar3);
    }
    _objc_msgSend(param_1,@selector(_drawSegmentsForData:),lVar1);
  }
  _objc_release(lVar1);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}



// +[SBPlayerDecorator _drawSegmentsForData:], 0x19db58
/* Decompiled from supplied 5.2.2 arm package. VA 0x19db58. _drawSegmentsForData: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorator::_drawSegmentsForData_(ID param_1,SEL param_2,ID param_3)

{
                    /* WARNING: Could not recover jumptable at 0x0019dca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011ac948)[DAT_012278e4 == 0] + (int)-(DAT_011ac958 ^ 0xfac15052)))();
  return;
}



// +[SBPlayerDecorator drawSegments:layer:playerVC:], 0x19ee38
/* Decompiled from supplied 5.2.2 arm package. VA 0x19ee38. drawSegments:layer:playerVC: */

/* Function Stack Size: 0x28 bytes */

void SBPlayerDecorator::drawSegments_layer_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined1 auStack_400 [368];
  ID local_290;
  undefined1 *puStack_268;
  undefined **local_250;
  undefined **ppuStack_248;
  undefined **local_238;
  undefined **local_228;
  undefined **local_220;
  undefined **ppuStack_218;
  undefined **local_210;
  undefined **ppuStack_208;
  undefined **local_1f8;
  undefined **local_1e8;
  undefined **local_1d8;
  undefined **local_1c8;
  undefined **ppuStack_1c0;
  undefined **local_1b0;
  undefined **local_1a8;
  undefined **ppuStack_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_170;
  undefined **local_160;
  undefined **local_150;
  undefined **ppuStack_148;
  undefined **local_138;
  undefined **local_130;
  undefined **local_128;
  undefined **local_120;
  undefined **local_110;
  undefined **local_100;
  undefined **local_f0;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  uint local_9c;
  undefined **local_98;
  undefined8 local_90;
  
  local_90 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_98 = &PTR_LAB_011aca98;
  local_9c = (uint)(DAT_012278e8 == 0);
  local_b0 = &PTR_LAB_011acab8;
  local_d0 = &PTR_LAB_011acae0;
  local_e0 = &PTR_LAB_011acaf8;
  local_f0 = &PTR_LAB_011acb10;
  local_100 = &PTR_LAB_011acb28;
  local_a8 = &PTR_LAB_011ac130;
  local_c8 = &PTR_LAB_011ac130;
  ppuStack_c0 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011acb40;
  local_120 = &PTR_LAB_011ac130;
  local_128 = &PTR_LAB_011ac130;
  local_130 = &PTR_LAB_011ac130;
  local_138 = &PTR_LAB_011acb70;
  local_150 = &PTR_LAB_011acb90;
  ppuStack_148 = &PTR_LAB_011ac130;
  local_160 = &PTR_LAB_011acba8;
  local_170 = &PTR_LAB_011acbc0;
  local_180 = &PTR_LAB_011acbd8;
  local_190 = &PTR_LAB_011acbf0;
  local_1a8 = &PTR_LAB_011ac130;
  ppuStack_1a0 = &PTR_LAB_011ac130;
  local_1b0 = &PTR_LAB_011acc18;
  local_1c8 = &PTR_LAB_011acc38;
  ppuStack_1c0 = &PTR_LAB_011ac130;
  local_1d8 = &PTR_LAB_011acc50;
  local_1e8 = &PTR_LAB_011acc68;
  local_1f8 = &PTR_LAB_011acc80;
  local_210 = &PTR_LAB_011ac130;
  ppuStack_208 = &PTR_LAB_011ac130;
  local_220 = &PTR_LAB_011ac130;
  ppuStack_218 = &PTR_LAB_011ac130;
  local_228 = &PTR_LAB_011accb8;
  local_238 = &PTR_LAB_011accd0;
  local_250 = &PTR_LAB_011ac130;
  ppuStack_248 = &PTR_LAB_011ac130;
  DAT_012278e8 = 1;
  puStack_268 = auStack_400;
  local_290 = param_5;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(local_290);
  uStack_b4 = (uint)(lRam00000000012278c8 == -1);
  if (lRam00000000012278c8 != -1) {
    _dispatch_once(local_b0[uStack_b4] + (int)-(uRam00000000011acac8 ^ 0xec94ae09),0x12278c8,
                   &PTR___NSConcreteGlobalBlock_010628a0);
    uStack_d4 = (uint)(param_4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0019f2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_d0[param_4 == 0] + (int)-(uRam00000000011acaf0 ^ 0x243ae6a4)))();
    return;
  }
  uStack_d4 = (uint)(param_4 == 0);
                    /* WARNING: Could not recover jumptable at 0x0019f2e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_d0[param_4 == 0] + (int)-(uRam00000000011acaf0 ^ 0x243ae6a4)))();
  return;
}



// +[SBPlayerDecorator drawSegmentableSegments:playerBar:playerVC:], 0x19fedc
/* Decompiled from supplied 5.2.2 arm package. VA 0x19fedc. drawSegmentableSegments:playerBar:playerVC: */

/* Function Stack Size: 0x28 bytes */

void SBPlayerDecorator::drawSegmentableSegments_playerBar_playerVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  undefined8 in_d2;
  undefined1 auStack_530 [192];
  undefined1 auStack_470 [128];
  undefined8 uStack_3f0;
  undefined8 uStack_3e8;
  long *plStack_3e0;
  undefined8 uStack_3d8;
  undefined8 uStack_3d0;
  undefined8 uStack_3c8;
  undefined8 uStack_3c0;
  undefined8 uStack_3b8;
  ID IStack_3b0;
  ID IStack_3a8;
  ID IStack_3a0;
  undefined1 *puStack_398;
  undefined *puStack_390;
  undefined *puStack_388;
  undefined *puStack_380;
  undefined *puStack_378;
  undefined *puStack_370;
  undefined *puStack_368;
  long lStack_360;
  long lStack_348;
  undefined *puStack_340;
  undefined *puStack_338;
  undefined8 *puStack_330;
  undefined *puStack_320;
  undefined *puStack_318;
  undefined8 uStack_300;
  long lStack_2e8;
  undefined1 *puStack_2e0;
  undefined *puStack_2b0;
  undefined8 uStack_288;
  undefined *puStack_280;
  undefined **local_278;
  undefined **local_270;
  undefined **ppuStack_268;
  undefined **local_258;
  undefined **local_248;
  undefined **ppuStack_240;
  undefined **local_230;
  undefined **local_220;
  undefined **local_218;
  undefined **ppuStack_210;
  undefined **local_200;
  undefined **local_1f0;
  undefined **local_1e0;
  undefined **local_1d0;
  undefined **local_1c0;
  undefined **local_1b0;
  undefined **local_1a0;
  undefined **local_190;
  undefined **local_180;
  undefined **local_178;
  undefined **local_168;
  undefined **local_160;
  undefined **local_158;
  undefined **local_148;
  undefined **local_138;
  undefined **local_130;
  uint uStack_124;
  undefined **local_120;
  undefined **local_118;
  undefined **local_110;
  uint uStack_104;
  undefined **local_100;
  uint uStack_f4;
  undefined **local_f0;
  uint uStack_e4;
  undefined **local_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  uint local_bc;
  undefined **local_b8;
  long local_b0;
  
  local_b0 = *(long *)PTR____stack_chk_guard_01060708;
  local_b8 = &PTR_LAB_011accf8;
  local_bc = (uint)(DAT_012278f0 == 0);
  local_d0 = &PTR_LAB_011acd18;
  local_e0 = &PTR_LAB_011acd30;
  local_f0 = &PTR_LAB_011acd48;
  local_100 = &PTR_LAB_011acd60;
  local_c8 = &PTR_LAB_011ac130;
  local_110 = &PTR_LAB_011ac130;
  local_118 = &PTR_LAB_011ac130;
  local_120 = &PTR__objc_msgSend_011acd88;
  local_130 = &PTR_LAB_011ac130;
  local_138 = &PTR_LAB_011acda8;
  local_148 = &PTR_LAB_011acdc0;
  local_158 = &PTR_LAB_011ac130;
  local_160 = &PTR_LAB_011ac130;
  local_168 = &PTR_LAB_011acde8;
  local_178 = &PTR_LAB_011ac130;
  local_180 = &PTR_LAB_011ace08;
  local_190 = &PTR__objc_msgSend_011ace20;
  local_1a0 = &PTR__objc_msgSend_011ace38;
  local_1b0 = &PTR___Block_object_assign_011ace50;
  local_1c0 = &PTR___Block_object_assign_011ace68;
  local_1d0 = &PTR___Block_object_assign_011ace80;
  local_1e0 = &PTR___Block_object_assign_011ace98;
  local_1f0 = &PTR_LAB_011aceb0;
  local_200 = &PTR__objc_msgSend_011acec8;
  local_218 = &PTR_LAB_011ac130;
  ppuStack_210 = &PTR_LAB_011ac130;
  local_220 = &PTR__objc_msgSend_011acef0;
  local_230 = &PTR_LAB_011acf08;
  local_248 = &PTR_LAB_011acf28;
  ppuStack_240 = &PTR_LAB_011ac130;
  local_258 = &PTR_LAB_011acf40;
  local_270 = &PTR_LAB_011ac130;
  ppuStack_268 = &PTR_LAB_011ac130;
  local_278 = &PTR_LAB_011ac130;
  DAT_012278f0 = 1;
  puStack_398 = auStack_470;
  puStack_2e0 = auStack_530;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  puStack_388 = @selector(class);
  uVar1 = _objc_msgSend(param_4);
  lVar2 = _class_getInstanceVariable(uVar1,s__segmentViews_011ac01a);
  uStack_d4 = (uint)(lVar2 == 0);
  if (lVar2 != 0) {
    _objc_msgSend(PTR_SBManager_0114eee8,@selector(sharedManager));
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,@selector(segments));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_5,@selector(contentVideoID));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_390 = @selector(objectForKey:);
    _objc_msgSend(uVar3,@selector(objectForKey:),uVar4);
    lVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_release(uVar3);
    _objc_release(uVar1);
    uStack_e4 = (uint)(lVar2 == 0);
    lStack_360 = lVar2;
    if (lVar2 != 0) {
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableSet_0114eee0,@selector(set));
      uStack_300 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_4,@selector(valueForKey:),
                    @"_segmentViews");
      uStack_288 = _objc_retainAutoreleasedReturnValue();
      uVar1 = _objc_msgSend(param_5,@selector(currentVideoTotalMediaTime));
      puStack_280 = @selector(bounds);
      _objc_msgSend(param_3);
      dVar5 = (double)NEON_fminnm(uVar1,in_d2);
      uStack_f4 = (uint)(dVar5 <= 0.0);
      if (0.0 < dVar5) {
        uStack_3c8 = 0;
        uStack_3d0 = 0;
        uStack_3b8 = 0;
        uStack_3c0 = 0;
        uStack_3e8 = 0;
        uStack_3f0 = 0;
        uStack_3d8 = 0;
        plStack_3e0 = (long *)0x0;
        IStack_3b0 = param_5;
        IStack_3a8 = param_4;
        IStack_3a0 = param_3;
        uVar1 = _objc_retain(local_f0[uStack_f4] + (int)-(DAT_011acd58 ^ 0xc7a1112b),lStack_360);
        puStack_2b0 = @selector(countByEnumeratingWithState:objects:count:);
        lStack_2e8 = _objc_msgSend(uVar1,@selector(countByEnumeratingWithState:objects:count:),&uStack_3f0
                                   ,puStack_398,0x10);
        uStack_104 = (uint)(lStack_2e8 == 0);
        if (lStack_2e8 != 0) {
          lStack_348 = *plStack_3e0;
          puStack_320 = @selector(standardUserDefaults);
          puStack_318 = @selector(category);
          puStack_340 = @selector(integerForKey:);
          puStack_338 = @selector(stringWithFormat:);
          puStack_370 = @selector(start);
          puStack_368 = @selector(unarchivedObjectOfClass:fromData:error:);
          puStack_380 = @selector(isEqualToString:);
          puStack_378 = @selector(end);
          uStack_124 = (uint)(*plStack_3e0 == lStack_348);
          puStack_330 = &uStack_3f0;
                    /* WARNING: Could not recover jumptable at 0x001a0778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(local_120[uStack_124] + (int)-(uRam00000000011acd98 ^ 0xf57be3d2)))();
          return;
        }
        _objc_release(local_100[uStack_104] + (int)-(uRam00000000011acd70 ^ 0xd4e7b3d3),lStack_360);
        param_3 = IStack_3a0;
        param_4 = IStack_3a8;
        param_5 = IStack_3b0;
      }
      _objc_release(uStack_288);
      _objc_release(uStack_300);
    }
    _objc_release(lStack_360);
  }
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x1894);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_b0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


