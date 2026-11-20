/* Decompiled from supplied 5.2.2 arm package. VA 0x1c00c8. FUN_001c00c8 */

undefined1  [16] FUN_001c00c8(long param_1)

{
  undefined8 uVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined1 local_24;
  
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c0180;
  puStack_48 = &DAT_01062b00;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_40 = uVar1;
  local_38 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  local_28 = *(undefined4 *)(param_1 + 0x38);
  local_24 = *(undefined1 *)(param_1 + 0x3c);
  local_30 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  _objc_msgSend(uVar1,PTR_s_hideWithCompletion__0114de40,&local_60);
  _objc_release(local_30);
  _objc_release(local_38);
  CallSupervisor(0xd827);
  return ZEXT816(0x1f);
}


