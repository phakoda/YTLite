/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0d7c. FUN_001c0d7c */

undefined1  [16] FUN_001c0d7c(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *puStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28;
  
  local_60 = PTR___NSConcreteStackBlock_01060660;
  local_58 = DAT_00c4c228;
  local_50 = FUN_001c0e20;
  puStack_48 = &DAT_01062b60;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_40 = uVar1;
  local_38 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  local_28 = *(undefined1 *)(param_1 + 0x38);
  local_30 = *(undefined8 *)(param_1 + 0x30);
  _objc_msgSend(uVar1,PTR_s_hideWithCompletion__0114de40,&local_60);
  _objc_release(local_38);
  CallSupervisor(0xe8df);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


