/* Decompiled from supplied 5.2.2 arm package. VA 0x1163f8. initWithModel:defaults: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::initWithModel_defaults_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  ID IVar2;
  long lVar3;
  undefined8 uVar4;
  ID IStack_a0;
  undefined *puStack_98;
  undefined **local_88;
  undefined **ppuStack_80;
  uint uStack_74;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cbc8;
  local_4c = (uint)(DAT_0122724c == 0);
  local_60 = &PTR_LAB_0118cbe8;
  local_70 = &PTR_LAB_0118cc00;
  local_58 = &PTR__objc_msgSend_0118c130;
  local_88 = &PTR__objc_msgSend_0118c130;
  ppuStack_80 = &PTR__objc_msgSend_0118c130;
  DAT_0122724c = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  puStack_98 = PTR_DVNTableViewController_0114f0a8;
  IStack_a0 = param_1;
  IVar2 = _objc_msgSendSuper2(&IStack_a0,PTR_s_initWithStyle__0114b790,1);
  uStack_64 = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    _objc_msgSend(IVar2,PTR_s_setModel__0114d0f0,param_3);
    _objc_msgSend(IVar2,PTR_s_setDefaults__0114d0f8,param_4);
    puVar1 = PTR_s_model_0114d100;
    _objc_msgSend(IVar2,PTR_s_model_0114d100);
    lVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    uStack_74 = (uint)(lVar3 == 0);
    if (lVar3 != 0) {
      _objc_msgSend(local_70[uStack_74] + (int)-(uRam000000000118cc10 ^ 0x8ed99e01),IVar2,puVar1);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_setSelfViewController__0114d108,IVar2);
      _objc_release(uVar4);
    }
    _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_addObserver_selector_name_object_0114c6d0,IVar2,
                  PTR_s__reloadSections_0114d110,&PTR____CFConstantStringClassReference_0118b870,0);
    _objc_release(uVar4);
  }
  _objc_release(param_4);
  _objc_release(param_3);
  return IVar2;
}


