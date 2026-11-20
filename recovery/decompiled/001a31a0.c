/* Decompiled from supplied 5.2.2 arm package. VA 0x1a31a0. sharedPicker */

/* Function Stack Size: 0x10 bytes */

ID DVNMediaPicker::sharedPicker(ID param_1,SEL param_2)

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
  
  local_18 = &PTR_LAB_011ae790;
  local_48 = PTR___NSConcreteGlobalBlock_01060658;
  local_40 = DAT_00c4c2a8;
  local_38 = FUN_001a3254;
  puStack_30 = &DAT_01062880;
  local_1c = (uint)(DAT_01227928 == -1);
  local_28 = param_1;
  if (DAT_01227928 != -1) {
    _dispatch_once((&PTR_LAB_011ae790)[local_1c] + (int)-(DAT_011ae7a0 ^ 0xa9705364),&DAT_01227928,
                   &local_48);
    param_2 = extraout_x1;
  }
  IVar1 = (*(code *)PTR__objc_retainAutoreleaseReturnValue_01061040)(DAT_01227930,param_2);
  return IVar1;
}


