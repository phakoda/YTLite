/* Decompiled from supplied 5.2.2 arm package. VA 0x1c9bd0. init */

/* Function Stack Size: 0x10 bytes */

ID ToastManager::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4e80;
  puStack_38 = PTR_ToastManager_0114f0f8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_init_0114d960);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 0x10);
    *(undefined8 *)(IVar1 + 0x10) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}


