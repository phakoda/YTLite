/* Decompiled from supplied 5.2.2 arm package. VA 0x121fa8. textFieldShouldReturn: */

/* Function Stack Size: 0x18 bytes */

bool DVNTableViewController::textFieldShouldReturn_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  
  FUN_0012c848(param_3,PTR_s_resignFirstResponder_0114d1e0);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_reloadData_0114d208);
  _objc_release(uVar1);
  return 1;
}


