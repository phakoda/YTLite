/* Decompiled from supplied 5.2.2 arm package. VA 0x11bd9c. tableView:titleForHeaderInSection: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::tableView_titleForHeaderInSection_
             (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ID IVar3;
  SEL extraout_x1;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),PTR_s_sections_0114d240);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_objectAtIndexedSubscript__0114aeb0,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_header_0114d148);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar2);
    _objc_release(uVar1);
    param_2 = extraout_x1;
  }
  else {
    uVar4 = 0;
  }
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4,param_2);
  return IVar3;
}


