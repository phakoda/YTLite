/* Decompiled from supplied 5.2.2 arm package. VA 0x1c27b0. hideWithDelay: */

/* Function Stack Size: 0x18 bytes */

void ToastView::hideWithDelay_(ID param_1,SEL param_2,double param_3)

{
  dispatch_time_t dVar1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  
  dVar1 = _dispatch_time(0,(long)(param_3 * DAT_00c4c268));
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_001c282c;
  puStack_30 = &DAT_01061420;
  local_28 = param_1;
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&local_48);
  return;
}


