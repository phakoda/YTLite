/* Decompiled from supplied 5.2.2 arm package. VA 0x4b50c. _addEndTime */

undefined1  [16] _addEndTime(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined **ppuVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
  DAT_012269d8 = 1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  _objc_retain(param_3);
  iVar4 = FUN_000d00d4(&PTR____CFConstantStringClassReference_0115de20);
  if (iVar4 != 0) {
    dVar15 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,PTR_s_playbackRateForPlayer__0114b970
                                   ,param_1);
    dVar16 = (double)_objc_msgSend(param_2,PTR_s_totalMediaTime_0114b978);
    dVar17 = (double)_objc_msgSend(param_3,PTR_s_time_0114adc0);
    _objc_msgSend((double)((long)dVar16 - (long)dVar17) / dVar15,PTR__OBJC_CLASS___NSDate_0114ebb8,
                  PTR_s_dateWithTimeIntervalSinceNow__0114b980);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar7 = _objc_alloc_init(PTR__OBJC_CLASS___NSDateFormatter_0114eca8);
    uVar8 = _objc_alloc(PTR__OBJC_CLASS___NSLocale_0114ecb0);
    uVar8 = _objc_msgSend(uVar8,PTR_s_initWithLocaleIdentifier__0114b988,
                          &PTR____CFConstantStringClassReference_0115dde0);
    _objc_msgSend(uVar7,PTR_s_setLocale__0114b990,uVar8);
    _objc_release(uVar8);
    iVar4 = FUN_000d0220(&PTR____CFConstantStringClassReference_0115dda0);
    ppuVar1 = &PTR____CFConstantStringClassReference_0115dd60;
    if (iVar4 == 0) {
      ppuVar1 = &PTR____CFConstantStringClassReference_0115dd20;
    }
    _objc_msgSend(uVar7,PTR_s_setDateFormat__0114b998,ppuVar1);
    _objc_msgSend(uVar7,PTR_s_stringFromDate__0114b9a0,uVar6);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_overlayView_0114b9a8;
    _objc_msgSend(uVar9,PTR_s_overlayView_0114b9a8);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    if (DAT_01226838 == 0) {
      DAT_01226838 = _objc_getClass((&PTR_LAB_0117a0a0)[DAT_01226838 == 0] +
                                    (int)-(uRam000000000117a0b0 ^ 0x92156058),
                                    s_YTMainAppVideoPlayerOverlayView_0115dc30);
    }
    lVar3 = DAT_01226838;
    _objc_retainAutorelease(DAT_01226838);
    uVar5 = FUN_000d00fc(uVar10,PTR_s_isKindOfClass__0114ad70,lVar3);
    _objc_release(uVar10);
    if (uVar5 != 0) {
      _objc_msgSend((&PTR_LAB_0117a0c0)[uVar5] + (int)-(uRam000000000117a0d0 ^ 0x55aafe96),uVar9,
                    puVar2);
      uVar10 = _objc_retainAutoreleasedReturnValue();
      puVar2 = PTR_s_playerBar_0114b9b0;
      _objc_msgSend(uVar10,PTR_s_playerBar_0114b9b0);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,PTR_s_durationLabel_0114b368);
      uVar12 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar11);
      _objc_msgSend(uVar10,puVar2);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar11,PTR_s_setEndTimeString__0114b9b8,uVar8);
      _objc_release(uVar11);
      puVar2 = PTR_s_text_0114b370;
      _objc_msgSend(uVar12,PTR_s_text_0114b370);
      uVar11 = _objc_retainAutoreleasedReturnValue();
      uVar5 = FUN_000d0388(uVar11,PTR_s_containsString__0114af08,uVar8);
      _objc_release(uVar11);
      if (uVar5 == 0) {
        _objc_msgSend((&PTR_LAB_0117a0d8)[uVar5] + (int)-(uRam000000000117a0e8 ^ 0xc7b4ccf0),uVar12,
                      puVar2);
        uVar11 = _objc_retainAutoreleasedReturnValue();
        thunk_FUN_000d0038(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                           &PTR____CFConstantStringClassReference_0115dce0,uVar8);
        uVar13 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar11,PTR_s_stringByAppendingString__0114b380,uVar13);
        uVar14 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,PTR_s_setText__0114b388,uVar14);
        _objc_release(uVar14);
        _objc_release(uVar13);
        _objc_release(uVar11);
        _objc_msgSend(uVar12,PTR_s_sizeToFit_0114b390);
      }
      _objc_release(uVar12);
      _objc_release(uVar10);
    }
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
  }
  _objc_release(param_3);
  _objc_release(param_2);
  _objc_release(param_1);
  CallSupervisor(0xba35);
  return ZEXT816(0x1f);
}


