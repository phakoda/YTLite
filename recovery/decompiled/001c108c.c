/* Decompiled from supplied 5.2.2 arm package. VA 0x1c108c. FUN_001c108c */

undefined1  [16] FUN_001c108c(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined *local_68;
  undefined8 local_60;
  code *local_58;
  undefined *puStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  
  local_68 = PTR___NSConcreteStackBlock_01060660;
  local_60 = DAT_00c4c228;
  local_58 = FUN_001c1150;
  puStack_50 = &DAT_01062bc0;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_48 = uVar1;
  local_40 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  local_30 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_38 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  local_28 = *(undefined8 *)(param_1 + 0x40);
  _objc_msgSend(uVar1,PTR_s_hideWithCompletion__0114de40,&local_68);
  _objc_release(local_38);
  _objc_release(local_30);
  _objc_release(local_40);
  CallSupervisor(0xfc34);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


