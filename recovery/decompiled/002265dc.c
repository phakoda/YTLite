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
  _objc_msgSend(param_3,PTR_s_activeVideo_0114c788);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_getClass(s_YTActivePlaybackRateModel_011cead0);
  uVar3 = _objc_msgSend(uVar3,PTR_s_alloc_0114d2b0);
  uVar3 = _objc_msgSend((float)dVar1,uVar3,PTR_s_initWithRate__0114e700);
  _objc_msgSend(uVar2,PTR_s_setActivePlaybackRateModel__0114e708,uVar3);
  _objc_release(uVar3);
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(dVar1,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_postNotificationName_object__0114b3e8,
                &PTR____CFConstantStringClassReference_011ceb10,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x7d2e);
  return;
}


