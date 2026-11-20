/* Decompiled from supplied 5.2.2 arm package. VA 0x23c67c. hideToast */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::hideToast(ID param_1,SEL param_2)

{
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  ID local_40;
  undefined *puStack_38;
  undefined8 local_30;
  code *local_28;
  undefined *puStack_20;
  ID local_18;
  
  puStack_38 = PTR___NSConcreteStackBlock_01060660;
  local_30 = DAT_00c4c228;
  local_28 = FUN_0023c710;
  puStack_20 = &DAT_01061420;
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_0023c724;
  puStack_48 = &DAT_01061940;
  local_40 = param_1;
  local_18 = param_1;
  _objc_msgSend(DAT_00c4c2e0,0x3ff0000000000000,PTR__OBJC_CLASS___UIView_0114ec30,
                PTR_s_animateWithDuration_delay_option_0114c8e8,0x10000,&puStack_38,&local_60);
  return;
}


