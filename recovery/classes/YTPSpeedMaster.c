// Decompiled implementation evidence for YTPSpeedMaster. Not compilable source.

// -[YTPSpeedMaster manageSpeedMaster:playerOverlayVC:], 0x223960
/* Decompiled from supplied 5.2.2 arm package. VA 0x223960. manageSpeedMaster:playerOverlayVC: */

/* Function Stack Size: 0x20 bytes */

void YTPSpeedMaster::manageSpeedMaster_playerOverlayVC_
               (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *puVar9;
  float fVar10;
  undefined8 uVar11;
  double dVar12;
  double dVar13;
  
  DAT_01228330 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_storeStrong(param_1 + 0x58,param_4);
  uVar5 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(integerForKey:),
                        @"speedIndex");
  *(undefined8 *)(param_1 + 0x10) = uVar5;
  _objc_msgSend(param_1,@selector(speedArray));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar8 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar5;
  _objc_release(uVar8);
  *(undefined8 *)(param_1 + 0x18) = 0x3fd0000000000000;
  dVar13 = 5.0;
  uVar5 = 0x4014000000000000;
  if (*(long *)(param_1 + 0x10) != 2) {
    uVar5 = 0x4024000000000000;
  }
  *(undefined8 *)(param_1 + 0x20) = uVar5;
  *(undefined8 *)(param_1 + 0x28) = 0x3fa999999999999a;
  _objc_msgSend(@"Toast.PlaybackSpeed",@selector(ytl_localized));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar8 = _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(floatForKey:),
                        @"playbackRate");
  puVar3 = @selector(state);
  lVar6 = _objc_msgSend(param_3,@selector(state));
  if (lVar6 == 1) {
    _objc_msgSend(param_3,@selector(view));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(param_3,@selector(locationInView:),uVar7);
    *(undefined8 *)(param_1 + 0x38) = uVar11;
    *(double *)(param_1 + 0x40) = dVar13;
    _objc_release(uVar7);
    uVar7 = _objc_msgSend(param_1,@selector(currentPlaybackRate));
    *(undefined8 *)(param_1 + 0x30) = uVar7;
    uVar7 = _objc_msgSend(uVar8,param_1,@selector(nearestIndexForRate:));
    *(undefined8 *)(param_1 + 0x50) = uVar7;
    *(undefined8 *)(param_1 + 0x48) = uVar8;
    _objc_msgSend(uVar8,param_1,@selector(setPlaybackRate:));
    _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar11 = FUN_00227144(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                          @"compactToast");
    _objc_msgSend(uVar8,uVar7,@selector(showPlayerToastWithText:value:style:isCompact:),uVar5,1,uVar11);
LAB_00224f28:
    _objc_release(uVar7);
    _objc_release(uVar5);
    _objc_release(param_4);
    _objc_release(param_3);
    CallSupervisor(0xd182);
    return;
  }
  lVar6 = _objc_msgSend((&PTR_LAB_011cedd0)[lVar6 == 1] + (int)-(uRam00000000011cede0 ^ 0x923025ba),
                        param_3,puVar3);
  puVar9 = (&PTR_LAB_011cedf0)[lVar6 == 2] + (int)-(uRam00000000011cee00 ^ 0xe4551dbd);
  if (lVar6 == 2) {
    uVar4 = FUN_00226b14(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                         @"adjustByFinger");
    puVar9 = (&PTR_LAB_011cee08)[uVar4] + (int)-(uRam00000000011cee18 ^ 0x1d264659);
    if (uVar4 != 0) {
      _objc_msgSend(param_3,@selector(view));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,@selector(locationInView:),uVar8);
      _objc_release(uVar8);
      dVar13 = *(double *)(param_1 + 0x40) - dVar13;
      if (*(long *)(param_1 + 0x10) == 2) {
        dVar12 = *(double *)(&UNK_00c4c4f0 + (ulong)(0.0 < dVar13) * 8);
        lVar6 = _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(count));
        uVar1 = *(long *)(param_1 + 0x50) + (long)(dVar13 * dVar12);
        uVar2 = lVar6 - 1U;
        if ((long)uVar1 <= (long)(lVar6 - 1U)) {
          uVar2 = uVar1;
        }
        _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(objectAtIndexedSubscript:),
                      uVar2 & ((long)uVar2 >> 0x3f ^ 0xffffffffffffffffU));
        uVar8 = _objc_retainAutoreleasedReturnValue();
        fVar10 = (float)_objc_msgSend(uVar8,@selector(floatValue));
        _objc_msgSend((double)fVar10,param_1,@selector(setPlaybackRate:));
        _objc_release(uVar8);
      }
      else {
        dVar12 = *(double *)(param_1 + 0x48) +
                 *(double *)(&DAT_00c4c500 + (ulong)(ABS(dVar13) < 40.0) * 8) * dVar13;
        dVar13 = *(double *)(param_1 + 0x20);
        if (dVar12 <= *(double *)(param_1 + 0x20)) {
          dVar13 = dVar12;
        }
        if (dVar13 <= *(double *)(param_1 + 0x18)) {
          dVar13 = *(double *)(param_1 + 0x18);
        }
        _objc_msgSend(*(double *)(param_1 + 0x28) *
                      (double)(long)(dVar13 / *(double *)(param_1 + 0x28)),param_1,
                      @selector(setPlaybackRate:));
      }
      _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_1,@selector(currentPlaybackRate));
      _objc_msgSend(uVar7,@selector(updateToastText:value:),uVar5);
      goto LAB_00224f28;
    }
  }
  lVar6 = _objc_msgSend(puVar9,param_3,puVar3);
  puVar9 = (&PTR_LAB_011cee50)[lVar6 == 2] + (int)-(uRam00000000011cee60 ^ 0xe7136b1f);
  if (lVar6 == 2) {
    uVar4 = FUN_00226d7c(PTR_YTLUserDefaults_0114ead8,@selector(boolForKey:),
                         @"adjustByFinger");
    puVar9 = (&PTR_LAB_011cee68)[uVar4] + (int)-(uRam00000000011cee78 ^ 0x49f50396);
    if (uVar4 != 0) {
      _objc_msgSend(param_3,@selector(view));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(param_3,@selector(locationInView:),uVar8);
      _objc_release(uVar8);
      dVar12 = *(double *)(param_1 + 0x40);
      lVar6 = _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(count));
      uVar1 = *(long *)(param_1 + 0x50) + (long)((dVar12 - dVar13) / 30.0);
      uVar2 = lVar6 - 1U;
      if ((long)uVar1 <= (long)(lVar6 - 1U)) {
        uVar2 = uVar1;
      }
      _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(objectAtIndexedSubscript:),
                    uVar2 & ((long)uVar2 >> 0x3f ^ 0xffffffffffffffffU));
      uVar8 = _objc_retainAutoreleasedReturnValue();
      fVar10 = (float)_objc_msgSend(uVar8,@selector(floatValue));
      _objc_release(uVar8);
      _objc_msgSend((double)fVar10,param_1,@selector(setPlaybackRate:));
      _objc_msgSend(PTR_PlayerToast_0114eda8,@selector(sharedToast));
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend((double)fVar10,uVar7,@selector(updateToastText:value:),uVar5);
      goto LAB_00224f28;
    }
  }
  lVar6 = _objc_msgSend(puVar9,param_3,puVar3);
                    /* WARNING: Could not recover jumptable at 0x002249d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011cee88)[lVar6 == 3] + (int)-(uRam00000000011cee98 ^ 0xfb30699f)))();
  return;
}



// -[YTPSpeedMaster speedArray], 0x2250cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2250cc. speedArray */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::speedArray(ID param_1,SEL param_2)

{
  double dVar1;
  double dVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ID IVar17;
  char *pcVar18;
  double dVar19;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  long local_90;
  
  puVar3 = @selector(numberWithDouble:);
  local_90 = *(long *)PTR____stack_chk_guard_01060708;
  if (*(long *)(param_1 + 0x10) == 2) {
    _objc_msgSend(0x3fd0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  @selector(numberWithDouble:));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_e8 = uVar6;
    _objc_msgSend(0x3fe0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_e0 = uVar7;
    _objc_msgSend(0x3fe8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uStack_d8 = uVar8;
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uStack_d0 = uVar9;
    _objc_msgSend(0x3ff4000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_c8 = uVar10;
    _objc_msgSend(0x3ff8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uStack_c0 = uVar11;
    _objc_msgSend(0x3ffc000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uStack_b8 = uVar12;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    uStack_b0 = uVar13;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar14 = _objc_retainAutoreleasedReturnValue();
    uStack_a8 = uVar14;
    _objc_msgSend(0x4010000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar15 = _objc_retainAutoreleasedReturnValue();
    uStack_a0 = uVar15;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar16 = _objc_retainAutoreleasedReturnValue();
    uStack_98 = uVar16;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_e8,0xb);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar16);
    _objc_release(uVar15);
    _objc_release(uVar14);
    _objc_release(uVar13);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar4 = @selector(numberWithDouble:);
    puVar3 = @selector(addObject:);
    dVar2 = _UNK_00c4c4e0;
    dVar1 = DAT_00c4c260;
    dVar19 = 0.25;
    pcVar18 = "ex limits [%i -> %i]\n";
    do {
      _objc_msgSend(pcVar18,(double)(long)(dVar19 * 100.0) / 100.0,
                    PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar3,uVar6);
      _objc_release(uVar6);
      dVar19 = dVar19 + dVar1;
      pcVar18 = (&PTR_LAB_011cef10)[dVar2 < dVar19] + (int)-(uRam00000000011cef20 ^ 0x2e6f010a);
    } while (dVar19 <= dVar2);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_90) {
    IVar17 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
    return IVar17;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}



// -[YTPSpeedMaster nearestIndexForRate:], 0x22545c
/* Decompiled from supplied 5.2.2 arm package. VA 0x22545c. nearestIndexForRate: */

/* Function Stack Size: 0x18 bytes */

long_long YTPSpeedMaster::nearestIndexForRate_(ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  double dVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined **ppuVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  float fVar12;
  double dVar13;
  
  puVar2 = @selector(count);
  lVar5 = _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(count));
  puVar3 = @selector(floatValue);
  puVar1 = @selector(objectAtIndexedSubscript:);
  uVar10 = 2;
  if (lVar5 != 0) {
    uVar9 = 0;
    ppuVar8 = &@selector(setLoopMode:);
    dVar13 = 1.7976931348623157e+308;
    uVar11 = 2;
    do {
      _objc_msgSend(ppuVar8,*(undefined8 *)(param_1 + 8),puVar1,uVar9);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      fVar12 = (float)_objc_msgSend(uVar6,puVar3);
      _objc_release(uVar6);
      uVar10 = uVar9;
      dVar4 = ABS((double)fVar12 - param_3);
      if (dVar13 <= ABS((double)fVar12 - param_3)) {
        uVar10 = uVar11;
        dVar4 = dVar13;
      }
      dVar13 = dVar4;
      uVar9 = uVar9 + 1;
      uVar7 = _objc_msgSend(*(undefined8 *)(param_1 + 8),puVar2);
      ppuVar8 = (undefined **)
                ((&PTR_LAB_011cef48)[uVar9 < uVar7] + (int)-(uRam00000000011cef58 ^ 0x2a6d782b));
      uVar11 = uVar10;
    } while (uVar9 < uVar7);
  }
  return uVar10;
}



// -[YTPSpeedMaster currentPlaybackRate], 0x225900
/* Decompiled from supplied 5.2.2 arm package. VA 0x225900. currentPlaybackRate */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedMaster::currentPlaybackRate(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float fVar6;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x58),@selector(parentViewController));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(activeVideo));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(playbackRate);
  uVar2 = FUN_00227594(uVar4,@selector(respondsToSelector:),@selector(playbackRate));
  if (uVar2 == 0) {
    _objc_msgSend(uVar4,@selector(activePlaybackRateModel));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    fVar6 = (float)_objc_msgSend(uVar5,@selector(activeRate));
    _objc_release(uVar5);
  }
  else {
    fVar6 = (float)_objc_msgSend((&PTR_LAB_011cefa0)[uVar2] + (int)-(DAT_011cefb0 ^ 0xe74c8c2e),
                                 uVar4,puVar1);
  }
  _objc_release(uVar4);
  _objc_release(uVar3);
  return (double)fVar6;
}



// -[YTPSpeedMaster setPlaybackRate:], 0x225a20
/* Decompiled from supplied 5.2.2 arm package. VA 0x225a20. setPlaybackRate: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedMaster::setPlaybackRate_(ID param_1,SEL param_2,double param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01228350 = 1;
  _objc_retain(param_1);
  _objc_sync_enter();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x58),@selector(parentViewController));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(activeVideo));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_0022767c(uVar3,@selector(respondsToSelector:),@selector(playbackRate));
  if (uVar1 == 0) {
    uVar4 = _objc_getClass((&PTR_LAB_011cefe8)[uVar1] + (int)-(DAT_011ceff8 ^ 0x7592061d),
                           s_YTActivePlaybackRateModel_011ce990);
    uVar4 = _objc_msgSend(uVar4,@selector(alloc));
    uVar4 = _objc_msgSend((float)param_3,uVar4,@selector(initWithRate:));
    _objc_msgSend(uVar3,@selector(setActivePlaybackRateModel:),uVar4);
    _objc_release(uVar4);
  }
  else {
    _objc_msgSend((float)param_3,uVar3,@selector(setPlaybackRate:));
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,@selector(postNotificationName:object:),
                @"YTPSpeedDidChange",uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_sync_exit(param_1);
  _objc_release(param_1);
  return;
}



// -[YTPSpeedMaster .cxx_destruct], 0x226a10
/* Decompiled from supplied 5.2.2 arm package. VA 0x226a10. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedMaster::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x58,0);
  _objc_storeStrong(param_1 + 8,0);
  return;
}



// +[YTPSpeedMaster sharedMaster], 0x223868
/* Decompiled from supplied 5.2.2 arm package. VA 0x223868. sharedMaster */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::sharedMaster(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR__objc_msgSend_011ced88;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_0022391c;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01228320 == -1);
  local_28 = param_1;
  if (DAT_01228320 != -1) {
    _dispatch_once((&PTR__objc_msgSend_011ced88)[local_1c] + (int)-(DAT_011ced98 ^ 0x1482774f),
                   &DAT_01228320,&local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01228318,param_2);
  return IVar1;
}



// +[YTPSpeedMaster getPlayerIfAvailable], 0x2255cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2255cc. getPlayerIfAvailable */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::getPlayerIfAvailable(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  
  DAT_01228348 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,@selector(sharedApplication));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(delegate));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(uVar3,@selector(responderRoot));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(class));
  _NSStringFromClass();
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar1 = FUN_0022752c(uVar4,@selector(hasPrefix:),
                       @"YTAppViewController");
  _objc_release(uVar4);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    _objc_msgSend(uVar2,@selector(appView));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(watchLayerView));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(_viewControllerForAncestor));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_msgSend(uVar6,@selector(playerViewController));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar6);
  }
  _objc_release(uVar2);
  _objc_release(uVar3);
  IVar7 = _objc_autoreleaseReturnValue(uVar4);
  return IVar7;
}



// +[YTPSpeedMaster currentPlaybackRate], 0x225f20
/* Decompiled from supplied 5.2.2 arm package. VA 0x225f20. currentPlaybackRate */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedMaster::currentPlaybackRate(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  float fVar6;
  double dVar7;
  
  _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
  lVar3 = _objc_retainAutoreleasedReturnValue();
  if (lVar3 == 0) {
    dVar7 = 1.0;
  }
  else {
    _objc_msgSend(lVar3,@selector(activeVideo));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = @selector(playbackRate);
    uVar2 = FUN_00227844(uVar4,@selector(respondsToSelector:),@selector(playbackRate));
    if (uVar2 == 0) {
      _objc_msgSend(uVar4,@selector(activePlaybackRateModel));
      uVar5 = _objc_retainAutoreleasedReturnValue();
      fVar6 = (float)_objc_msgSend(uVar5,@selector(activeRate));
      _objc_release(uVar5);
    }
    else {
      fVar6 = (float)_objc_msgSend((&PTR_LAB_011cf030)[uVar2] +
                                   (int)-(uRam00000000011cf040 ^ 0x49ff9fb6),uVar4,puVar1);
    }
    dVar7 = (double)fVar6;
    _objc_release(uVar4);
  }
  _objc_release(lVar3);
  return dVar7;
}



// +[YTPSpeedMaster playbackRateForPlayer:], 0x22608c
/* Decompiled from supplied 5.2.2 arm package. VA 0x22608c. playbackRateForPlayer: */

/* Function Stack Size: 0x18 bytes */

double YTPSpeedMaster::playbackRateForPlayer_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  float fVar5;
  
  _objc_retain(param_3);
  if (param_3 == 0) {
    _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
    param_3 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(param_3,@selector(activeVideo));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(playbackRate);
  uVar2 = FUN_0022792c(uVar3,@selector(respondsToSelector:),@selector(playbackRate));
  if (uVar2 == 0) {
    _objc_msgSend(uVar3,@selector(activePlaybackRateModel));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    fVar5 = (float)_objc_msgSend(uVar4,@selector(activeRate));
    _objc_release(uVar4);
  }
  else {
    fVar5 = (float)_objc_msgSend((&PTR_LAB_011cf080)[uVar2] +
                                 (int)-(uRam00000000011cf090 ^ 0x56026800),uVar3,puVar1);
  }
  _objc_release(uVar3);
  _objc_release(param_3);
  return (double)fVar5;
}



// +[YTPSpeedMaster setPlaybackRate:forPlayer:], 0x226204
/* Decompiled from supplied 5.2.2 arm package. VA 0x226204. setPlaybackRate:forPlayer: */

/* Function Stack Size: 0x20 bytes */

void YTPSpeedMaster::setPlaybackRate_forPlayer_(ID param_1,SEL param_2,double param_3,ID param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_0122835c = 1;
  _objc_retain(param_4);
  if (param_4 == 0) {
    _objc_msgSend(param_1,@selector(getPlayerIfAvailable));
    param_4 = _objc_retainAutoreleasedReturnValue();
    if (param_4 == 0) goto LAB_002265ac;
  }
  _objc_msgSend(param_4,@selector(activeVideo));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00227a74(uVar3,@selector(respondsToSelector:),@selector(playbackRate));
  puVar1 = @selector(_applyPendingRateForPlayer:);
  if (iVar2 == 0) {
    DAT_011ce3e0 = param_3;
    _objc_msgSend(PTR__OBJC_CLASS___NSObject_0114ebc0,
                  @selector(cancelPreviousPerformRequestsWithTarget:selector:object:),param_1,
                  @selector(_applyPendingRateForPlayer:),param_4);
    _objc_msgSend(DAT_00c4c260,param_1,@selector(performSelector:withObject:afterDelay:),puVar1,
                  param_4);
  }
  else {
    _objc_msgSend((float)param_3,uVar3,@selector(setPlaybackRate:));
    _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,@selector(postNotificationName:object:),
                  @"YTPSpeedDidChange",uVar5);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(uVar3);
  _objc_release(param_4);
LAB_002265ac:
  CallSupervisor(0x5f34);
  return;
}



// +[YTPSpeedMaster _applyPendingRateForPlayer:], 0x2265dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x2265dc. _applyPendingRateForPlayer: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedMaster::_applyPendingRateForPlayer_(ID param_1,SEL param_2,ID param_3)

{
  double dVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  dVar1 = DAT_011ce3e0;
  DAT_01228360 = 1;
  _objc_msgSend(param_3,@selector(activeVideo));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_getClass(s_YTActivePlaybackRateModel_011cead0);
  uVar3 = _objc_msgSend(uVar3,@selector(alloc));
  uVar3 = _objc_msgSend((float)dVar1,uVar3,@selector(initWithRate:));
  _objc_msgSend(uVar2,@selector(setActivePlaybackRateModel:),uVar3);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,@selector(defaultCenter));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(dVar1,PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithDouble:));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(postNotificationName:object:),
                @"YTPSpeedDidChange",uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x7d2e);
  return;
}


