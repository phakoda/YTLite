/* Decompiled from supplied 5.2.2 arm package. VA 0x121118. _cellForTag: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellForTag_(ID param_1,SEL param_2,long_long param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ID IVar6;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),PTR_s_sections_0114d240);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_objectAtIndexedSubscript__0114aeb0;
    _objc_msgSend(uVar3,PTR_s_objectAtIndexedSubscript__0114aeb0,(long)param_3 >> 0x10);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s__cellsForSection__0114d248,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar1,param_3 & 0xffff);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  else {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_searchResults),
                  PTR_s_objectAtIndexedSubscript__0114aeb0,param_3 & 0xffff);
    uVar2 = _objc_retainAutoreleasedReturnValue();
  }
  IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar6;
}


