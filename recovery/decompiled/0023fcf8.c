/* Decompiled from supplied 5.2.2 arm package. VA 0x23fcf8. init */

/* Function Stack Size: 0x10 bytes */

ID CustomHUD::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011d2b60;
  puStack_38 = PTR_CustomHUD_0114f170;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,PTR_s_init_0114d960);
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_msgSend(PTR__OBJC_CLASS___MPVolumeController_0114f040,PTR_s_new_0114b030);
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}


