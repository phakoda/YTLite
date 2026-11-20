/* Decompiled from supplied 5.2.2 arm package. VA 0x1253b8. _reloadSections */

/* Function Stack Size: 0x10 bytes */

void DVNTableViewController::_reloadSections(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_reloadData_0114d208);
  _objc_release(uVar1);
  return;
}


