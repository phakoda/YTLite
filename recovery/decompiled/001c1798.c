/* Decompiled from supplied 5.2.2 arm package. VA 0x1c1798. FUN_001c1798 */

undefined1  [16] FUN_001c1798(long param_1)

{
  undefined8 uVar1;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28;
  
  local_70 = PTR___NSConcreteStackBlock_01060660;
  local_68 = DAT_00c4c228;
  local_60 = FUN_001c1864;
  puStack_58 = &DAT_01062bf0;
  local_28 = *(undefined1 *)(param_1 + 0x48);
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_50 = uVar1;
  local_48 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  local_40 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  local_38 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_30 = *(undefined8 *)(param_1 + 0x40);
  _objc_msgSend(uVar1,PTR_s_hideWithCompletion__0114de40,&local_70);
  _objc_release(local_38);
  _objc_release(local_40);
  _objc_release(local_48);
  CallSupervisor(0xda9c);
  return ZEXT816(0x1f);
}


