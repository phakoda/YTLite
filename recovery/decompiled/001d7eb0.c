/* Decompiled from supplied 5.2.2 arm package. VA 0x1d7eb0. loadView */

/* Function Stack Size: 0x10 bytes */

void SbWhitelistVC::loadView(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double dVar4;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  ID IStack_80;
  undefined *puStack_78;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011b9038;
  local_5c = (uint)(DAT_01227d9c == 0);
  local_68 = &PTR_LAB_011b8c20;
  DAT_01227d9c = 1;
  puStack_78 = PTR_SbWhitelistVC_0114f118;
  IStack_80 = param_1;
  _objc_msgSendSuper2(&IStack_80,PTR_s_loadView_0114d118);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011b8060,0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_setTitle__0114afc0,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_s_tableView_0114d120;
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  dVar4 = (double)_objc_msgSend(uVar2,PTR_s_contentInset_0114e080);
  _objc_release(uVar2);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(dVar4 + 15.0,in_d1,in_d2,in_d3,uVar2,PTR_s_setContentInset__0114b810);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithDynamicProvider__0114c558,
                &PTR___NSConcreteGlobalBlock_01062d20);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setBackgroundColor__0114b550,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  uVar2 = _objc_msgSend(uVar2,PTR_s_initWithBarButtonSystemItem_targ_0114d2c0,0x18,param_1,
                        PTR_s_closeButtonTapped_0114d2b8);
  _objc_msgSend(param_1,PTR_s_navigationItem_0114d2c8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setRightBarButtonItem__0114d2d8,uVar2);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x9764);
  return;
}


