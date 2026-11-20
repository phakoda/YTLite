/* Decompiled from supplied 5.2.2 arm package. VA 0xa9d84. FUN_000a9d84 */

undefined1  [16] FUN_000a9d84(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  _objc_msgSend(PTR_YTPSleepTimer_0114eaf0,PTR_s_sharedTimer_0114aed8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_cancelIfPlayerClosed_0114cb40);
  _objc_release(uVar1);
  (*DAT_01226650)(param_1,param_2);
  CallSupervisor(0x4c39);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


