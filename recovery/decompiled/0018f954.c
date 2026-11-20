/* Decompiled from supplied 5.2.2 arm package. VA 0x18f954. init */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011a9740;
  puStack_38 = PTR_DVNCell_0114f0c8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_init_0114d960);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSUUID_0114eec0,PTR_s_UUID_0114d9b8);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_UUIDString_0114b480);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar3;
    _objc_release(uVar4);
    _objc_release(uVar2);
  }
  return IVar1;
}


