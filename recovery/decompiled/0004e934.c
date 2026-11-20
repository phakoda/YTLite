/* Decompiled from supplied 5.2.2 arm package. VA 0x4e934. FUN_0004e934 */

undefined1  [16] FUN_0004e934(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  (*DAT_01225f48)();
  puVar1 = PTR_s_sharedManager_0114c320;
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setOffsetController__0114c328,param_1);
  _objc_release(uVar2);
  _objc_msgSend(PTR_ToastManager_0114ecd0,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_updateAllToasts_0114c330);
  _objc_release(uVar2);
  CallSupervisor(0x8509);
  return ZEXT816(0x1f);
}


