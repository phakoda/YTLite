/* Decompiled from supplied 5.2.2 arm package. VA 0x124fbc. FUN_00124fbc */

undefined1  [16] FUN_00124fbc(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_s_defaults_0114d278;
  if (*(long *)(param_1 + 0x30) != 0x7fffffffffffffff) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_defaults_0114d278);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setInteger_forKey__0114c2d8,*(undefined8 *)(param_1 + 0x30),
                  *(undefined8 *)(param_1 + 0x28));
    _objc_release(uVar2);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    FUN_0012e728(uVar2,PTR_s_synchronize_0114c2c0);
    _objc_release(uVar2);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_tableView_0114d120);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_reloadData_0114d208);
    _objc_release(uVar2);
  }
  CallSupervisor(0x9cb3);
  return ZEXT816(0x1f);
}


