/* Decompiled from supplied 5.2.2 arm package. VA 0x116764. loadView */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::loadView(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID local_60;
  undefined *puStack_58;
  int local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cc28;
  puStack_58 = PTR_DVNTableViewController_0114f0a8;
  local_60 = param_1;
  _objc_msgSendSuper2(&local_60,PTR_s_loadView_0114d118);
  puVar1 = PTR_s_model_0114d100;
  _objc_msgSend(param_1,PTR_s_model_0114d100);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_title_0114c7f0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_setTitle__0114afc0,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar4);
  puVar2 = PTR_s_tableView_0114d120;
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setSeparatorStyle__0114b8c8,0);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,0,0x4034000000000000,0,uVar4,PTR_s_setContentInset__0114b810);
  _objc_release(uVar4);
  _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,0x3ff0000000000000,
                PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithRed_green_blue_alpha__0114c5f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTPMedia_0114eae0,PTR_s_adaptiveBackgroundColor_0114c410);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setBackgroundColor__0114b550,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(param_1,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001258b8(uVar4,PTR_s_showsThanksHeart_0114d128);
  _objc_release(uVar4);
  if (iVar3 != 0) {
    local_4c = iVar3;
    _objc_msgSend(param_1,PTR_s_setupThanksHeart_0114d130);
  }
  CallSupervisor(0xeb82);
  return;
}


