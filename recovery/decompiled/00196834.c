/* Decompiled from supplied 5.2.2 arm package. VA 0x196834. handleSkipSegment: */

/* Function Stack Size: 0x18 bytes */

void SBPlaybackController::handleSkipSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  
  DAT_01227840 = 1;
  uVar3 = _objc_retain(param_3);
  uVar5 = *(undefined8 *)(param_1 + 0x18);
  _objc_msgSend(uVar3,PTR_s_uuid_0114dac8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_addObject__0114b3a0,uVar3);
  _objc_release(uVar3);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_YTLUserDefaults_0114ead8;
  _objc_msgSend(param_3,PTR_s_category_0114dad0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00199078(puVar2,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011aa1a0,uVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  lVar4 = _objc_msgSend(puVar1,PTR_s_integerForKey__0114b3a8,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar3);
  uVar3 = _objc_loadWeakRetained(param_1 + 8);
  uVar5 = _objc_msgSend(uVar3,PTR_s_currentVideoMediaTime_0114dab0);
  _objc_release(uVar3);
  if (lVar4 < 2) {
    if (lVar4 == 1) {
      uVar3 = _objc_msgSend(param_3,PTR_s_end_0114dae0);
      uVar5 = _objc_msgSend(param_3,PTR_s_start_0114b410);
      _objc_msgSend(uVar3,uVar5,param_1,PTR_s_seekToTime_forSegment_undoTime_a_0114daf8,param_3,1);
    }
  }
  else if (lVar4 == 2) {
    uVar3 = _objc_msgSend(param_3,PTR_s_end_0114dae0);
    _objc_msgSend(uVar5,uVar3,param_1,PTR_s_showSkipPromptToast_timeBeforeSk_0114db00,param_3);
  }
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


