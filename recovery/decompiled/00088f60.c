/* Decompiled from supplied 5.2.2 arm package. VA 0x88f60. FUN_00088f60 */

undefined1  [16] FUN_00088f60(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  puVar2 = PTR_YTPSpeedMaster_0114eca0;
  puVar1 = PTR_s_sharedMaster_0114c940;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s_delegate_0114b530);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_manageSpeedMaster_playerOverlayV_0114c948,param_3,uVar4);
  _objc_release(param_3);
  _objc_release(uVar4);
  _objc_release(uVar3);
  CallSupervisor(0xa2ba);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


