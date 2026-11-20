/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0740. showText: */

/* Function Stack Size: 0x18 bytes */

void ToastView::showText_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  puVar1 = PTR_s_enqueueCommand__0114de48;
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c07f0;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  CallSupervisor(0x6ee6);
  return;
}


