/* Decompiled from supplied 5.2.2 arm package. VA 0x11a538. FUN_0011a538 */

undefined1  [16] FUN_0011a538(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  undefined *local_58;
  undefined8 local_50;
  code *local_48;
  undefined *puStack_40;
  undefined8 local_38;
  
  puVar1 = PTR_s_tableView_0114d120;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_tableView_0114d120);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_cellForRowAtIndexPath__0114d298,*(undefined8 *)(param_1 + 0x28));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_tintColor_0114d1b8);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c2b8,uVar5,PTR_s_colorWithAlphaComponent__0114b548);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(uVar3);
  _objc_msgSend(uVar4,PTR_s_setBackgroundColor__0114b550,uVar6);
  puVar2 = PTR__OBJC_CLASS___UIView_0114ec30;
  puVar1 = PTR_s_animateWithDuration_animations__0114cc88;
  local_58 = PTR___NSConcreteStackBlock_01060660;
  local_50 = DAT_00c4c228;
  local_48 = FUN_0011a6a8;
  puStack_40 = &DAT_01061420;
  local_38 = uVar4;
  _objc_retain(uVar4);
  _objc_msgSend(0x3ff0000000000000,puVar2,puVar1,&local_58);
  _objc_release(local_38);
  _objc_release(uVar4);
  _objc_release(uVar6);
  CallSupervisor(0xc0f2);
  auVar7._8_8_ = 0x1f;
  auVar7._0_8_ = 0x1a;
  return auVar7;
}


