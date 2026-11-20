/* Decompiled from supplied 5.2.2 arm package. VA 0x223868. sharedMaster */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::sharedMaster(ID param_1,SEL param_2)

{
  ID IVar1;
  SEL extraout_x1;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *puStack_30;
  ID local_28;
  uint local_1c;
  undefined **local_18;
  
  local_18 = &PTR__objc_msgSend_011ced88;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_0022391c;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01228320 == -1);
  local_28 = param_1;
  if (DAT_01228320 != -1) {
    _dispatch_once((&PTR__objc_msgSend_011ced88)[local_1c] + (int)-(DAT_011ced98 ^ 0x1482774f),
                   &DAT_01228320,&local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01228318,param_2);
  return IVar1;
}


