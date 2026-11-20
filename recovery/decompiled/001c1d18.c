/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1d18. startTimerCountdown: */

/* Function Stack Size: 0x18 bytes */

void ToastView::startTimerCountdown_(ID param_1,SEL param_2,double param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  ID local_58;
  undefined8 *puStack_50;
  double local_48;
  undefined8 local_40;
  undefined8 *puStack_38;
  undefined8 local_30;
  undefined8 local_28;
  
  puStack_50 = &local_40;
  local_40 = 0;
  local_30 = DAT_00c4c3d0;
  local_28 = 0x3ff0000000000000;
  local_48 = DAT_00c4c3d8 / param_3;
  local_78 = PTR___NSConcreteStackBlock_01060660;
  local_70 = DAT_00c4c228;
  local_68 = FUN_001c1e4c;
  puStack_60 = &DAT_01062c20;
  local_58 = param_1;
  puStack_38 = puStack_50;
  _objc_msgSend(DAT_00c4c3d8,PTR__OBJC_CLASS___NSTimer_0114ef70,
                PTR_s_timerWithTimeInterval_repeats_bl_0114de78,1,&local_78);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSRunLoop_0114ef78,PTR_s_mainRunLoop_0114de80);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_addTimer_forMode__0114de88,uVar1,
                *(undefined8 *)PTR__NSRunLoopCommonModes_01060390);
  _objc_release(uVar2);
  _objc_release(uVar1);
  __Block_object_dispose(&local_40,8);
  return;
}


