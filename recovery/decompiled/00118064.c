/* Decompiled from supplied 5.2.2 arm package. VA 0x118064. traitCollectionDidChange: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::traitCollectionDidChange_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  ID local_50;
  undefined *puStack_48;
  int local_3c;
  undefined **local_38;
  
  puVar1 = PTR_s_traitCollectionDidChange__0114d1d0;
  local_38 = &PTR_LAB_0118cd10;
  puStack_48 = PTR_DVNTableViewController_0114f0a8;
  local_50 = param_1;
  _objc_retain(param_3);
  _objc_msgSendSuper2(&local_50,puVar1,param_3);
  _objc_msgSend(param_1,PTR_s_traitCollection_0114c858);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_00126bf8(uVar3,PTR_s_hasDifferentColorAppearanceCompa_0114d1d8,param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  if (iVar2 != 0) {
    local_3c = iVar2;
    _objc_msgSend(param_1,PTR_s__removeSearchFieldCornerRadius__0114d1c0,
                  *(undefined8 *)(param_1 + (long)_searchBar));
  }
  CallSupervisor(0x11d4);
  return;
}


