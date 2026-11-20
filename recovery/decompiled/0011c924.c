/* Decompiled from supplied 5.2.2 arm package. VA 0x11c924. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long DVNTableViewController::tableView_numberOfRowsInSection_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long_long lVar4;
  
  if (*(char *)(param_1 + (long)_isSearching) != '\0') {
    lVar4 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_searchResults),PTR_s_count_0114b840);
    return lVar4;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),PTR_s_sections_0114d240);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_objectAtIndexedSubscript__0114aeb0,param_4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s__cellsForSection__0114d248,uVar2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  lVar4 = _objc_msgSend(uVar3,PTR_s_count_0114b840);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return lVar4;
}


