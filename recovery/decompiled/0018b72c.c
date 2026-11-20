/* Decompiled from supplied 5.2.2 arm package. VA 0x18b72c. init */

/* Function Stack Size: 0x10 bytes */

ID DVNTableModel::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID local_60;
  undefined *puStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011a8d58;
  puStack_58 = PTR_DVNTableModel_0114f0b8;
  local_60 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_60,PTR_s_init_0114d960);
  local_4c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    _objc_storeStrong(IVar2 + 0x48,*(undefined8 *)PTR____NSArray0___01060670);
    puVar1 = PTR_s_systemFontOfSize_weight__0114d330;
    uVar5 = *(undefined8 *)PTR__UIFontWeightSemibold_01060580;
    _objc_msgSend(0x402c000000000000,uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,
                  PTR_s_systemFontOfSize_weight__0114d330);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar2 + 0x28);
    *(undefined8 *)(IVar2 + 0x28) = uVar3;
    _objc_release(uVar4);
    _objc_msgSend(0x402a000000000000,uVar5,PTR__OBJC_CLASS___UIFont_0114ec08,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar2 + 0x30);
    *(undefined8 *)(IVar2 + 0x30) = uVar3;
    _objc_release(uVar4);
    *(undefined8 *)(IVar2 + 0x40) = 1;
    *(undefined8 *)(IVar2 + 0x38) = 1;
  }
  return IVar2;
}


