/* Decompiled from supplied 5.2.2 arm package. VA 0x1200bc. FUN_001200bc */

undefined1  [16] FUN_001200bc(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puStack_60;
  undefined8 uStack_58;
  code *pcStack_50;
  undefined *puStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  int local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_0118dba8;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_cellForRowAtIndexPath__0114d298,
                *(undefined8 *)(param_1 + 0x28));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setAccessoryView__0114d3b0,0);
  local_2c = FUN_0012b430(*(undefined8 *)(param_1 + 0x30),PTR_s_reloadsTable_0114d4e0);
  if (local_2c != 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_reloadData_0114d208);
  }
  iVar1 = FUN_0012b458(*(undefined8 *)(param_1 + 0x30),PTR_s_reloadsCell_0114d4e8);
  if (iVar1 != 0) {
    puStack_60 = PTR___NSConcreteStackBlock_01060660;
    uStack_58 = DAT_00c4c228;
    pcStack_50 = FUN_00120240;
    puStack_48 = &DAT_01061f70;
    uStack_40 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
    uStack_38 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_60);
    _objc_release(uStack_38);
    _objc_release(uStack_40);
  }
  _objc_release(uVar2);
  CallSupervisor(0xa1d);
  return ZEXT816(0x1f);
}


