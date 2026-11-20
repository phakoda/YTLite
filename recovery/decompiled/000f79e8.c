/* Decompiled from supplied 5.2.2 arm package. VA 0xf79e8. FUN_000f79e8 */

undefined1  [16] FUN_000f79e8(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38;
  
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  uVar1 = *(undefined8 *)(param_1 + 0x68);
  local_a0 = PTR___NSConcreteStackBlock_01060660;
  local_98 = DAT_00c4c228;
  local_90 = FUN_000f7b34;
  puStack_88 = &DAT_010620f0;
  local_38 = *(undefined1 *)(param_1 + 0x70);
  _objc_retain(uVar2);
  local_80 = uVar2;
  local_78 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  local_70 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  local_68 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  local_60 = _objc_retain(*(undefined8 *)(param_1 + 0x40));
  local_58 = _objc_retain(*(undefined8 *)(param_1 + 0x48));
  local_50 = _objc_retain(*(undefined8 *)(param_1 + 0x50));
  local_48 = _objc_retain(*(undefined8 *)(param_1 + 0x58));
  local_40 = _objc_retain(*(undefined8 *)(param_1 + 0x60));
  _objc_msgSend(uVar2,PTR_s_checkSpaceAvailabilityForMedia_c_0114ced0,uVar1,&local_a0);
  _objc_release(local_40);
  _objc_release(local_48);
  _objc_release(local_50);
  _objc_release(local_58);
  _objc_release(local_60);
  _objc_release(local_68);
  _objc_release(local_70);
  _objc_release(local_78);
  _objc_release(local_80);
  CallSupervisor(0x340c);
  return ZEXT816(0x1f);
}


