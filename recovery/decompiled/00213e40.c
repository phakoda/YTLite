/* Decompiled from supplied 5.2.2 arm package. VA 0x213e40. FUN_00213e40 */

undefined1  [16] FUN_00213e40(long param_1)

{
  long lVar1;
  
  if (*(long *)(*(long *)(param_1 + 0x20) + 8) != 0) {
    _objc_msgSend(*(long *)(param_1 + 0x20),PTR_s_getPlayerIfAvailable_0114c838);
    lVar1 = _objc_retainAutoreleasedReturnValue();
    if (lVar1 != 0) {
      _objc_msgSend((float)*(double *)(param_1 + 0x28),lVar1,PTR_s_setVolume__0114e430);
    }
    _objc_release(lVar1);
  }
  CallSupervisor(0x48cd);
  return ZEXT816(0x1f);
}


