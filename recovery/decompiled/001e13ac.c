/* Decompiled from supplied 5.2.2 arm package. VA 0x1e13ac. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::viewDidLoad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IStack_80;
  undefined *puStack_78;
  undefined **local_70;
  int iStack_64;
  undefined **local_60;
  undefined **ppuStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ba778;
  local_4c = (uint)(DAT_01227e28 == 0);
  local_60 = &PTR_LAB_011ba798;
  ppuStack_58 = &PTR_LAB_011ba600;
  local_70 = &PTR_LAB_011ba600;
  DAT_01227e28 = 1;
  puStack_78 = PTR_TranslatorVC_0114f120;
  IStack_80 = param_1;
  _objc_msgSendSuper2(&IStack_80,PTR_s_viewDidLoad_0114b070);
  puVar2 = PTR_s_ytl_localized_0114d190;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ba190,PTR_s_ytl_localized_0114d190);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_setTitle__0114afc0,uVar4);
  _objc_release(uVar4);
  puVar1 = PTR_s_tableView_0114d120;
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setSeparatorStyle__0114b8c8,0);
  _objc_release(uVar4);
  _objc_msgSend(0x3fe8000000000000,0x3fe0000000000000,DAT_00c4c2f8,0x3ff0000000000000,
                PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithRed_green_blue_alpha__0114c5f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setTintColor__0114b000,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIBarButtonItem_0114ee18);
  uVar4 = _objc_msgSend(uVar4,PTR_s_initWithBarButtonSystemItem_targ_0114d2c0,0x18,param_1,
                        PTR_s_closeButtonTapped_0114d2b8);
  _objc_msgSend(param_1,PTR_s_navigationItem_0114d2c8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_setRightBarButtonItem__0114d2d8,uVar4);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  iVar3 = FUN_001e4b08(uVar4,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_011ba150);
  _objc_release(uVar4);
  iStack_64 = iVar3;
  if (iVar3 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithDynamicProvider__0114c558,
                  &PTR___NSConcreteGlobalBlock_01062e00);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setBackgroundColor__0114b550,uVar4);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ba110,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_textView),PTR_s_setText__0114b388,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(param_1,PTR_s_translateText_0114e0d0);
  CallSupervisor(0x31a9);
  return;
}


