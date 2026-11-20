/* Decompiled from supplied 5.2.2 arm package. VA 0x18d94c. init */

/* Function Stack Size: 0x10 bytes */

ID DVNSection::init(ID param_1,SEL param_2)

{
  ID IVar1;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011a9358;
  puStack_38 = PTR_DVNSection_0114f0c0;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_init_0114d960);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_storeStrong(IVar1 + 0x28,*(undefined8 *)PTR____NSArray0___01060670);
  }
  return IVar1;
}


