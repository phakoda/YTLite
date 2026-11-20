/* Decompiled from supplied 5.2.2 arm package. VA 0x11a490. highlightRowAtIndexPath: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::highlightRowAtIndexPath_(ID param_1,SEL param_2,ID param_3)

{
  dispatch_time_t dVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  ID local_38;
  
  _objc_retain(param_3);
  dVar1 = _dispatch_time(0,350000000);
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_0011a538;
  puStack_48 = &DAT_01061f70;
  local_40 = param_1;
  local_38 = param_3;
  _objc_retain(param_3);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&local_60);
  _objc_release(local_38);
  _objc_release(param_3);
  return;
}


