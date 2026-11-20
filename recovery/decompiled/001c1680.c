/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1680. showProgressiveToastWithText:duration:actionIcon:ignoresPan:actionCompletion: */

/* Function Stack Size: 0x34 bytes */

void ToastView::showProgressiveToastWithText_duration_actionIcon_ignoresPan_actionCompletion_
               (ID param_1,SEL param_2,ID param_3,double param_4,ID param_5,bool param_6,ID param_7,
               undefined4 param_8)

{
  undefined *puVar1;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  ID local_80;
  ID local_78;
  ID local_70;
  ID local_68;
  double local_60;
  undefined1 local_58;
  
  _objc_retain(param_3);
  _objc_retain(param_5);
  _objc_retain(param_7);
  puVar1 = PTR_s_enqueueCommand__0114de48;
  local_a0 = PTR___NSConcreteStackBlock_01060660;
  local_98 = DAT_00c4c228;
  local_90 = FUN_001c1798;
  puStack_88 = &DAT_01062bf0;
  local_58 = (undefined1)param_6;
  local_80 = param_1;
  local_78 = param_3;
  local_70 = param_5;
  local_68 = param_7;
  local_60 = param_4;
  _objc_retain();
  _objc_retain(param_5);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_a0);
  _objc_release(local_68);
  _objc_release(local_70);
  _objc_release(local_78);
  _objc_release(param_7);
  _objc_release(param_5);
  _objc_release(param_3);
  CallSupervisor(0xa46c);
  return;
}


