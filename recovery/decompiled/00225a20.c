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
  _objc_msgSend(*(undefined8 *)(param_1 + 0x58),PTR_s_parentViewController_0114ad68);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_activeVideo_0114c788);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_0022767c(uVar3,PTR_s_respondsToSelector__0114af58,PTR_s_playbackRate_0114e6e8);
  if (uVar1 == 0) {
    uVar4 = _objc_getClass((&PTR_LAB_011cefe8)[uVar1] + (int)-(DAT_011ceff8 ^ 0x7592061d),
                           s_YTActivePlaybackRateModel_011ce990);
    uVar4 = _objc_msgSend(uVar4,PTR_s_alloc_0114d2b0);
    uVar4 = _objc_msgSend((float)param_3,uVar4,PTR_s_initWithRate__0114e700);
    _objc_msgSend(uVar3,PTR_s_setActivePlaybackRateModel__0114e708,uVar4);
    _objc_release(uVar4);
  }
  else {
    _objc_msgSend((float)param_3,uVar3,PTR_s_setPlaybackRate__0114c758);
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_postNotificationName_object__0114b3e8,
                &PTR____CFConstantStringClassReference_011ce9d0,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_sync_exit(param_1);
  _objc_release(param_1);
  return;
}


