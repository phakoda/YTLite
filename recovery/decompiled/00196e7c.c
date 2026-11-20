/* Decompiled from supplied 5.2.2 arm package. VA 0x196e7c. seekToTime:forSegment:undoTime:attempts: */

/* Function Stack Size: 0x2c bytes */

void SBPlaybackController::seekToTime_forSegment_undoTime_attempts_
               (ID param_1,SEL param_2,double param_3,ID param_4,double param_5,int param_6)

{
  undefined8 uVar1;
  dispatch_time_t dVar2;
  undefined *puStack_b8;
  undefined8 uStack_b0;
  code *pcStack_a8;
  undefined *puStack_a0;
  ID IStack_98;
  ID IStack_90;
  undefined1 auStack_88 [8];
  double dStack_80;
  double dStack_78;
  int iStack_70;
  undefined1 auStack_68 [12];
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011aae48;
  _objc_retain(param_4);
  local_5c = (uint)((int)param_6 < 1);
  if (0 < (int)param_6) {
    uVar1 = _objc_loadWeakRetained
                      (local_58[local_5c] + (int)-(DAT_011aae58 ^ 0xc904f157),param_1 + 8);
    _objc_msgSend(param_3,uVar1,PTR_s_seekToTime__0114ad18);
    _objc_release(uVar1);
    _objc_initWeak(auStack_68,param_1);
    dVar2 = _dispatch_time(0,300000000);
    puStack_b8 = PTR___NSConcreteStackBlock_01060660;
    uStack_b0 = DAT_00c4c228;
    pcStack_a8 = FUN_00197000;
    puStack_a0 = &UNK_01062820;
    _objc_copyWeak(auStack_88,auStack_68);
    IStack_98 = param_1;
    _objc_retain(param_4);
    IStack_90 = param_4;
    dStack_80 = param_3;
    dStack_78 = param_5;
    iStack_70 = param_6;
    _dispatch_after(dVar2,PTR___dispatch_main_q_01060760,&puStack_b8);
    _objc_release(IStack_90);
    _objc_destroyWeak(auStack_88);
    _objc_destroyWeak(auStack_68);
  }
  _objc_release(param_4);
  CallSupervisor(0x9b5d);
  return;
}


