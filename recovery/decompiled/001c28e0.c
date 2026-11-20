/* Decompiled from supplied 5.2.2 arm package. VA 0x1c28e0. FUN_001c28e0 */

undefined1  [16] FUN_001c28e0(void)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_updateAllToasts_0114c330);
  _objc_release(uVar1);
  CallSupervisor(0xa1b4);
  return ZEXT816(0x1f);
}


