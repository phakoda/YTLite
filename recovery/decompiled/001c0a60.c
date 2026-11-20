/* Decompiled from supplied 5.2.2 arm package. VA 0x1c0a60. FUN_001c0a60 */

undefined1  [16] FUN_001c0a60(long param_1)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *puStack_38;
  undefined8 local_30;
  undefined8 local_28;
  
  local_50 = PTR___NSConcreteStackBlock_01060660;
  local_48 = DAT_00c4c228;
  local_40 = FUN_001c0af0;
  puStack_38 = &DAT_01061f70;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_30 = uVar1;
  local_28 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  _objc_msgSend(uVar1,PTR_s_hideWithCompletion__0114de40,&local_50);
  _objc_release(local_28);
  CallSupervisor(0x3ee);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


