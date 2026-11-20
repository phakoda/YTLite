/* Decompiled from supplied 5.2.2 arm package. VA 0x1f4510. statisticsCallback: */

/* Function Stack Size: 0x18 bytes */

void FFMpegHelper::statisticsCallback_(ID param_1,SEL param_2,ID param_3)

{
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *puStack_38;
  ID local_30;
  ID local_28;
  
  _objc_retain(param_3);
  local_50 = PTR___NSConcreteStackBlock_01060660;
  local_48 = DAT_00c4c228;
  local_40 = FUN_001f45b0;
  puStack_38 = &DAT_01061f70;
  local_30 = param_1;
  local_28 = param_3;
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_50);
  _objc_release(local_28);
  _objc_release(param_3);
  CallSupervisor(0x96);
  return;
}


