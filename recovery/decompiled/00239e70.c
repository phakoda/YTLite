/* Decompiled from supplied 5.2.2 arm package. VA 0x239e70. updateLabel: */

/* Function Stack Size: 0x14 bytes */

void YTPSpeedControlView::updateLabel_(ID param_1,SEL param_2,float param_3)

{
  undefined8 uVar1;
  
  DAT_012284e8 = 1;
  thunk_FUN_0023b3fc((double)param_3,PTR__OBJC_CLASS___NSString_0114eb38,
                     PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d2150);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_valueLabel),PTR_s_setText__0114b388,uVar1);
  _objc_release(uVar1);
  _objc_msgSend((double)param_3,PTR_YTPSpeedMaster_0114eca0,
                PTR_s_setPlaybackRate_forPlayer__0114c750,0);
  CallSupervisor(0x4b38);
  return;
}


