/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0f78. showProgressiveToastWithText:duration:actionTitle:actionCompletion: */

/* Function Stack Size: 0x30 bytes */

void ToastView::showProgressiveToastWithText_duration_actionTitle_actionCompletion_
               (ID param_1,SEL param_2,ID param_3,double param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined *local_98;
  undefined8 local_90;
  code *local_88;
  undefined *puStack_80;
  ID local_78;
  ID local_70;
  ID local_68;
  ID local_60;
  double local_58;
  
  _objc_retain(param_3);
  _objc_retain(param_5);
  _objc_retain(param_6);
  puVar1 = PTR_s_enqueueCommand__0114de48;
  local_98 = PTR___NSConcreteStackBlock_01060660;
  local_90 = DAT_00c4c228;
  local_88 = FUN_001c108c;
  puStack_80 = &DAT_01062bc0;
  local_78 = param_1;
  local_70 = param_3;
  local_68 = param_5;
  local_60 = param_6;
  local_58 = param_4;
  _objc_retain(param_5);
  _objc_retain(param_6);
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_98);
  _objc_release(local_68);
  _objc_release(local_60);
  _objc_release(local_70);
  _objc_release(param_5);
  _objc_release(param_6);
  _objc_release(param_3);
  CallSupervisor(0x5499);
  return;
}


