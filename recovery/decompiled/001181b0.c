/* Decompiled from supplied 5.2.2 arm package. VA 0x1181b0. _removeSearchFieldCornerRadius: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_removeSearchFieldCornerRadius_(ID param_1,SEL param_2,ID param_3)

{
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  
  _objc_retain(param_3);
  local_48 = PTR___NSConcreteStackBlock_01060660;
  local_40 = DAT_00c4c228;
  local_38 = FUN_0011824c;
  puStack_30 = &DAT_01061420;
  local_28 = param_3;
  _objc_retain(param_3);
  _dispatch_async(PTR___dispatch_main_q_01060760,&local_48);
  _objc_release(local_28);
  _objc_release(param_3);
  CallSupervisor(5);
  return;
}


