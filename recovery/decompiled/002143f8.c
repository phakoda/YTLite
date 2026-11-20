/* Decompiled from supplied 5.2.2 arm package. VA 0x2143f8. secondsForDate: */

/* Function Stack Size: 0x18 bytes */

double YTPSleepTimer::secondsForDate_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  
  puVar2 = PTR__OBJC_CLASS___NSCalendar_0114f010;
  puVar1 = PTR_s_currentCalendar_0114e448;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_components_fromDate__0114e450;
  _objc_msgSend(uVar3,PTR_s_components_fromDate__0114e450,0x60,param_3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(uVar3,puVar1,0x1c,uVar4);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(uVar5,PTR_s_hour_0114e458);
  _objc_msgSend(uVar6,PTR_s_setHour__0114e460,uVar7);
  uVar7 = _objc_msgSend(uVar5,PTR_s_minute_0114e468);
  _objc_msgSend(uVar6,PTR_s_setMinute__0114e470,uVar7);
  _objc_msgSend(uVar6,PTR_s_setSecond__0114e478,0);
  _objc_msgSend(uVar3,PTR_s_dateFromComponents__0114e480,uVar6);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_timeIntervalSinceDate__0114e488;
  dVar9 = (double)_objc_msgSend(uVar7,PTR_s_timeIntervalSinceDate__0114e488,uVar4);
  if (dVar9 <= 0.0) {
    _objc_msgSend(DAT_00c4c240,uVar7,PTR_s_dateByAddingTimeInterval__0114e490);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    uVar7 = uVar8;
  }
  dVar9 = (double)_objc_msgSend(uVar7,puVar1,uVar4);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  return dVar9;
}


