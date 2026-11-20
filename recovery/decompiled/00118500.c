/* Decompiled from supplied 5.2.2 arm package. VA 0x118500. _performSearch: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::_performSearch_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  bool bVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  undefined *puStack_60;
  undefined8 uStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_0118cda8;
  _objc_retain(param_3);
  lVar3 = _objc_msgSend(param_3,PTR_s_length_0114b438);
  bVar2 = lVar3 != 0;
  local_4c = (uint)bVar2;
  *(bool *)(param_1 + (long)_isSearching) = bVar2;
  if (bVar2) {
    _objc_msgSend(param_3,PTR_s_lowercaseString_0114cf58);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_model_0114d100);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_cellsMatchingRecursive__0114d200;
    puStack_78 = PTR___NSConcreteStackBlock_01060660;
    uStack_70 = DAT_00c4c228;
    pcStack_68 = FUN_001186d8;
    puStack_60 = &UNK_010624c0;
    uStack_58 = uVar6;
    _objc_retain(uVar6);
    _objc_msgSend(uVar4,puVar1,&puStack_78);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar7 = *(undefined8 *)(param_1 + (long)_searchResults);
    *(undefined8 *)(param_1 + (long)_searchResults) = uVar5;
    _objc_release(uVar7);
    _objc_release(uVar4);
    _objc_release(uStack_58);
    _objc_release(uVar6);
  }
  else {
    _objc_storeStrong(param_1 + (long)_searchResults,*(undefined8 *)PTR____NSArray0___01060670);
  }
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar6,PTR_s_reloadData_0114d208);
  _objc_release(uVar6);
  _objc_release(param_3);
  CallSupervisor(0x7ec9);
  return;
}


