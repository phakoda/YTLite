/* Decompiled from supplied 5.2.2 arm package. VA 0x119004. searchBarTextDidBeginEditing: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::searchBarTextDidBeginEditing_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = PTR_s_searchTextField_0114d1a8;
  DAT_01227284 = 1;
  uVar2 = _objc_retain(param_3);
  _objc_msgSend(uVar2,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setRightViewMode__0114d218,3);
  _objc_release(uVar2);
  uVar2 = _NSClassFromString(&PTR____CFConstantStringClassReference_0118b9f0);
  _objc_msgSend(uVar2,PTR_s_iconButton_0114d220);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_enableNewTouchFeedback_0114d228);
  _objc_msgSend(PTR__OBJC_CLASS___UIImage_0114ebf8,PTR_s_systemImageNamed__0114b718,
                &PTR____CFConstantStringClassReference_0118b9b0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setImage_forState__0114adf0,uVar3,0);
  _objc_release(uVar3);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_tintColor_0114d1b8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_msgSend(uVar2,PTR_s_addTarget_action_forControlEvent_0114b830,param_1,
                PTR_s__searchClearTapped__0114d230,0x40);
  _objc_msgSend(param_3,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setRightView__0114d238,uVar2);
  _objc_release(uVar3);
  _objc_msgSend(param_1,PTR_s__removeSearchFieldCornerRadius__0114d1c0,param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  CallSupervisor(0x2cbe);
  return;
}


