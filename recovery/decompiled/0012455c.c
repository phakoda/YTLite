/* Decompiled from supplied 5.2.2 arm package. VA 0x12455c. FUN_0012455c */

undefined1  [16] FUN_0012455c(long param_1)

{
  undefined8 uVar1;
  
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_tableView_0114d120);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_reloadData_0114d208);
  _objc_release(uVar1);
  CallSupervisor(0xba66);
  return ZEXT816(0x1f);
}


