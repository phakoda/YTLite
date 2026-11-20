/* Decompiled from supplied 5.2.2 arm package. VA 0x4e9e4. FUN_0004e9e4 */

undefined1  [16] FUN_0004e9e4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  (*DAT_01225f50)();
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setIsPinnedTop__0114c338,param_3);
  _objc_release(uVar1);
  CallSupervisor(0xba91);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


