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
    _objc_msgSend(param_1,PTR_s_getPlayerIfAvailable_0114c838);
    param_4 = _objc_retainAutoreleasedReturnValue();
    if (param_4 == 0) goto LAB_002265ac;
  }
  _objc_msgSend(param_4,PTR_s_activeVideo_0114c788);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00227a74(uVar3,PTR_s_respondsToSelector__0114af58,PTR_s_playbackRate_0114e6e8);
  puVar1 = PTR_s__applyPendingRateForPlayer__0114e710;
  if (iVar2 == 0) {
    DAT_011ce3e0 = param_3;
    _objc_msgSend(PTR__OBJC_CLASS___NSObject_0114ebc0,
                  PTR_s_cancelPreviousPerformRequestsWit_0114e718,param_1,
                  PTR_s__applyPendingRateForPlayer__0114e710,param_4);
    _objc_msgSend(DAT_00c4c260,param_1,PTR_s_performSelector_withObject_after_0114cb48,puVar1,
                  param_4);
  }
  else {
    _objc_msgSend((float)param_3,uVar3,PTR_s_setPlaybackRate__0114c758);
    _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_3,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_postNotificationName_object__0114b3e8,
                  &PTR____CFConstantStringClassReference_011cea50,uVar5);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(uVar3);
  _objc_release(param_4);
LAB_002265ac:
  CallSupervisor(0x5f34);
  return;
}


