/* Decompiled from supplied 5.2.2 arm package. VA 0x75e88. FUN_00075e88 */

undefined1  [16] FUN_00075e88(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  
  puVar2 = PTR_YTPSleepTimer_0114eaf0;
  puVar1 = PTR_s_sharedTimer_0114aed8;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_showOptions__0114aee0,param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  CallSupervisor(0x4d72);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


