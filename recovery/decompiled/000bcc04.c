/* Decompiled from supplied 5.2.2 arm package. VA 0xbcc04. FUN_000bcc04 */

undefined1  [16] FUN_000bcc04(void)

{
  undefined8 uVar1;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_updateAllToasts_0114c330);
  _objc_release(uVar1);
  CallSupervisor(0x656a);
  return ZEXT816(0x1f);
}


