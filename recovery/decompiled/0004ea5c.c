/* Decompiled from supplied 5.2.2 arm package. VA 0x4ea5c. FUN_0004ea5c */

undefined1  [16] FUN_0004ea5c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  (*DAT_01225f58)();
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setIsFullscreen__0114c340,param_3);
  _objc_release(uVar1);
  CallSupervisor(0x9a8f);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


