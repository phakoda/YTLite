/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0ccc. showProgressiveToastWithText:duration:isSuccess: */

/* Function Stack Size: 0x24 bytes */

void ToastView::showProgressiveToastWithText_duration_isSuccess_
               (ID param_1,SEL param_2,ID param_3,double param_4,bool param_5)

{
  undefined *puVar1;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *puStack_68;
  ID local_60;
  ID local_58;
  double local_50;
  undefined1 local_48;
  
  _objc_retain(param_3);
  puVar1 = PTR_s_enqueueCommand__0114de48;
  local_80 = PTR___NSConcreteStackBlock_01060660;
  local_78 = DAT_00c4c228;
  local_70 = FUN_001c0d7c;
  puStack_68 = &DAT_01062b60;
  local_48 = (undefined1)param_5;
  local_60 = param_1;
  local_58 = param_3;
  local_50 = param_4;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_80);
  _objc_release(local_58);
  _objc_release(param_3);
  return;
}


