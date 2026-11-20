/* Decompiled from supplied 5.2.2 arm package. VA 0x11ca5c. _cellForIndexPath: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellForIndexPath_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  undefined8 uVar7;
  
  puVar2 = PTR_s_sections_0114d240;
  puVar1 = PTR_s_row_0114af70;
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    uVar3 = *(undefined8 *)(param_1 + (long)_model);
    _objc_retain(param_3);
    _objc_msgSend(uVar3,puVar2);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,PTR_s_section_0114af60);
    puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
    _objc_msgSend(uVar7,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar3);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s__cellsForSection__0114d248,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,PTR_s_row_0114af70);
    _objc_release(param_3);
    _objc_msgSend(uVar5,puVar1,uVar3);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar7);
  }
  else {
    uVar7 = *(undefined8 *)(param_1 + (long)_searchResults);
    uVar3 = _objc_retain(param_3);
    uVar3 = _objc_msgSend(uVar3,puVar1);
    _objc_release(param_3);
    _objc_msgSend(uVar7,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar3);
    uVar3 = _objc_retainAutoreleasedReturnValue();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return IVar6;
}


