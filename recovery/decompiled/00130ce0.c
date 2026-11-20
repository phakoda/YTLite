/* Decompiled from supplied 5.2.2 arm package. VA 0x130ce0. loadView */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

void TabbarVC::loadView(ID param_1,SEL param_2)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IStack_70;
  undefined *puStack_68;
  undefined **local_60;
  uint uStack_54;
  undefined **local_50;
  undefined **ppuStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR__objc_msgSend_0118fe80;
  local_3c = (uint)(DAT_012273d0 == 0);
  local_50 = &PTR_LAB_0118fea0;
  ppuStack_48 = &PTR_LAB_0118faf0;
  local_60 = &PTR_LAB_0118faf0;
  DAT_012273d0 = 1;
  puStack_68 = PTR_TabbarVC_0114f0b0;
  IStack_70 = param_1;
  _objc_msgSendSuper2(&IStack_70,PTR_s_loadView_0114d118);
  _objc_msgSend(param_1,PTR_s_initTabs_0114d690);
  bVar1 = *(char *)(param_1 + (long)__isSettings) == '\0';
  uStack_54 = (uint)bVar1;
  if (bVar1) {
    _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_localizedStringForKey_value_tabl_0114b278,
                  &PTR____CFConstantStringClassReference_0118ec90,0,0);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_setTitle__0114afc0,uVar3);
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
  }
  CallSupervisor(0x938a);
  return;
}


