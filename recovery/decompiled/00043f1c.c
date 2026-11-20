/* Decompiled from supplied 5.2.2 arm package. VA 0x43f1c. FUN_00043f1c */

undefined1  [16] FUN_00043f1c(long param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *puStack_88;
  undefined8 local_80;
  undefined *local_78;
  undefined8 local_70;
  code *local_68;
  undefined *puStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  puVar3 = PTR__OBJC_CLASS___UIView_0114ec30;
  puVar2 = PTR___NSConcreteStackBlock_01060660;
  uVar1 = DAT_00c4c228;
  local_78 = PTR___NSConcreteStackBlock_01060660;
  local_70 = DAT_00c4c228;
  local_68 = FUN_00044024;
  puStack_60 = &DAT_01061910;
  local_58 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
  local_50 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  uStack_48 = *(undefined8 *)(param_1 + 0x30);
  local_a0 = puVar2;
  local_98 = uVar1;
  local_90 = FUN_00044170;
  puStack_88 = &DAT_01061940;
  local_80 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
  _objc_msgSend(0x3fe0000000000000,0x4000000000000000,0x3ff0000000000000,0x402e000000000000,puVar3,
                PTR_s_animateWithDuration_delay_usingS_0114b930,0,&local_78,&local_a0);
  _objc_release(local_80);
  _objc_release(local_50);
  _objc_release(local_58);
  CallSupervisor(0xe3b5);
  return ZEXT816(0x1f);
}


